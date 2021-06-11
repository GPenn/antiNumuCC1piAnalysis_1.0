#include "antiNumuCC1piSelection.hxx"
#include "antiNumuCCMultiPiSelection.hxx"
#include "baseSelection.hxx"
#include "CutUtils.hxx"
#include "EventBoxUtils.hxx"
#include "SubDetId.hxx"
#include "SystId.hxx"
#include "VersioningUtils.hxx"
#include "SystematicUtils.hxx"
#include "SystematicTuning.hxx"
#include "DataClasses.hxx"
#include "trackerSelectionUtils.hxx"



//********************************************************************
antiNumuCC1piSelection::antiNumuCC1piSelection(bool forceBreak): SelectionBase(forceBreak,EventBoxId::kEventBoxTracker) {
  //********************************************************************
  //_antiNumuCCSelection.Initialize();
  //_numuCCMultiPiSelection.Initialize(); 
  _antiNumuCCMultiPiSelection.Initialize(); 
  //_useECalPiZeroInfo = (bool)ND::params().GetParameterI("psycheSelections.antinumuCCMultiPi.UseECalPiZeroInfo");
  //_numuCCMultiPiSelection.SetUseECalPiZeroInfo(_useECalPiZeroInfo);
}

//********************************************************************
void antiNumuCC1piSelection::DefineSteps(){
  //********************************************************************

  // Copy all steps from the antiNumuCCSelection
  //CopySteps(_antiNumuCCMultiPiSelection);
  
  // Cuts must be added in the right order
  // last "true" means the step sequence is broken if cut is not passed (default is "false")
  AddStep(StepBase::kCut,    "event quality",      new EventQualityCut(),           true);
  AddStep(StepBase::kCut,    "> 0 tracks ",        new TotalMultiplicityCut(),      true);  
  AddStep(StepBase::kAction, "find leading tracks",new FindLeadingTracksAction_antinu());  
  AddStep(StepBase::kAction, "find vertex",        new FindVertexAction());  
  AddStep(StepBase::kAction, "fill summary",       new FillSummaryAction_antinu());  
  AddStep(StepBase::kCut,    "quality+fiducial",   new TrackQualityFiducialCut(),   true);
  AddStep(StepBase::kCut,    "pos_mult",           new PositiveMultiplicityCut());  
  AddStep(StepBase::kAction, "find veto track",    new FindVetoTrackAction());
  AddStep(StepBase::kCut,    "veto",               new ExternalVetoCut());
  AddStep(StepBase::kAction, "find oofv track",    new FindOOFVTrackAction());
  AddStep(StepBase::kCut,    "External FGD1",      new ExternalFGD1lastlayersCut());
  //AddStep(StepBase::kCut,    "Antimu PID loop",      new AntiMuonPIDCut_Loop());
  AddStep(StepBase::kCut,    "Antimu PID",         new AntiMuonPIDCut());
  
  AddStep(StepBase::kAction, "find_pions",                new FindPionsAction_antinuCCMultiPi());
  AddStep(StepBase::kAction, "find_protons",              new FindProtonsAction());
  AddStep(StepBase::kAction, "fill_summary antinu_pion",  new FillSummaryAction_antinuCCMultiPi());

  //Add a split to the trunk with 3 branches.
  AddSplit(3);

  //First branch is for CC-0pi
  AddStep(0, StepBase::kCut, "CC-0pi",        new NoPionCut());
  AddStep(0, StepBase::kCut, "ECal Pi0 veto", new EcalPi0VetoCut());
  
  //AddStep(0, StepBase::kCut, "Muon with ECal segments", new MuonWithECalSegmentsCut());
  AddStep(0, StepBase::kCut, "ECal Muon PID EMEnergy/Length", new MuonECalEMEnergyLengthCut());
  AddStep(0, StepBase::kCut, "ECal Muon PID MipPion", new MuonECalMipPionCut());

  //Second branch is for CC-1pi
  AddStep(1, StepBase::kCut, "CC1pi TPC PID",        new OnePionCut(false));
  AddStep(1, StepBase::kCut, "ECal Pi0 veto", new EcalPi0VetoCut());
  
  AddStep(1, StepBase::kCut, "ECal muon PID", new OptimisedMuonECalPIDCut());
  AddStep(1, StepBase::kCut, "ECal pion PID", new OptimisedPionECalPIDCut());
  
  //AddSplit(2,1);
  //CC1pi with muon candidate ECal segment
  //AddStep(1, StepBase::kCut, "Muon with ECal segments", new MuonWithECalSegmentsCut());
  //AddStep(1, StepBase::kCut, "ECal Muon E/L", new MuonECalEMEnergyLengthCut());
  //AddStep(1, StepBase::kCut, "ECal Muon MipPion", new MuonECalMipPionCut());
  //AddStep(1, StepBase::kCut, "ECal Pion E/L", new PionECalEMEnergyLengthCut());
  
  //CC1pi without muon candidate ECal segment
  //AddStep(1, 1, StepBase::kCut, "Muon without ECal segments", new MuonWithoutECalSegmentsCut());
  
  //Third branch is for CC-Other
  AddStep(2, StepBase::kCut, "CC-Other", new OthersCut());
  
  //AddStep(2, StepBase::kCut, "Muon with ECal segments", new MuonWithECalSegmentsCut());
  AddStep(2, StepBase::kCut, "ECal Muon PID EMEnergy/Length", new MuonECalEMEnergyLengthCut());
  AddStep(2, StepBase::kCut, "ECal Muon PID MipPion", new MuonECalMipPionCut());

  // Set the branch aliases to the branches
  SetBranchAlias(0,"CC-0pi",  0);
  //SetBranchAlias(1,"CC-1pi",  1);
  SetBranchAlias(1, "CC-1pi with ECal",  1);
  SetBranchAlias(2,"CC-Other",2);
  //SetBranchAlias(3, "CC-1pi without ECal",  1,1);

  // By default the preselection correspond to cuts 0-2
  SetPreSelectionAccumLevel(2);

  // Step and Cut numbers needed by CheckRedoSelection
  _MuonPIDCutIndex     = GetCutNumber("Antimu PID loop");
  _FindPionsStepIndex  = GetStepNumber("find_pions");

}

//********************************************************************
void antiNumuCC1piSelection::DefineDetectorFV(){
  //********************************************************************

  // The detector in which the selection is applied
  SetDetectorFV(SubDetId::kFGD1);
  
}

//********************************************************************
bool antiNumuCC1piSelection::FillEventSummary(AnaEventC& event, Int_t allCutsPassed[]){
  //********************************************************************

  //taken from numuCCMultiPi
  //CC0pi
  if(allCutsPassed[0]){
    static_cast<AnaEventSummaryB*>(event.Summary)->EventSample = SampleId::kFGD1AntiNuMuCC0Pi;
  }  
  //CC1pi
  else if (allCutsPassed[1]){
    static_cast<AnaEventSummaryB*>(event.Summary)->EventSample = SampleId::kFGD1AntiNuMuCC1Pi;
  }
  //CCOther
  else if (allCutsPassed[2]){
    static_cast<AnaEventSummaryB*>(event.Summary)->EventSample = SampleId::kFGD1AntiNuMuCCOther;
  }

  // otherwise kUnassigned is used from the EventSummary constructor
  return (static_cast<AnaEventSummaryB*>(event.Summary)->EventSample != SampleId::kUnassigned);
}

//*********************************************************************
bool FillSummaryAction_antinuCC1pi::Apply(AnaEventC& event, ToyBoxB& boxB) const{
  //*********************************************************************

  // Cast the ToyBox to the appropriate type
  ToyBoxCCMultiPi& box = *static_cast<ToyBoxCCMultiPi*>(&boxB); 

  if (!box.HMPtrack) return true;
 
  static_cast<AnaEventSummaryB*>(event.Summary)->LeptonCandidate[SampleId::kFGD1AntiNuMuCC0Pi]   = box.HMPtrack;
  static_cast<AnaEventSummaryB*>(event.Summary)->LeptonCandidate[SampleId::kFGD1AntiNuMuCC1Pi]   = box.HMPtrack;
  static_cast<AnaEventSummaryB*>(event.Summary)->LeptonCandidate[SampleId::kFGD1AntiNuMuCCOther] = box.HMPtrack;

 
  
  // Fill pion candidates: for CC0pi for consistency
  static_cast<AnaEventSummaryB*>(event.Summary)->PionCandidate[SampleId::kFGD1AntiNuMuCC0Pi]   = 
    box.pionBox.GetHMPion(static_cast<AnaEventSummaryB*>(event.Summary)->PionMomentum[SampleId::kFGD1AntiNuMuCC0Pi], 
        static_cast<AnaEventSummaryB*>(event.Summary)->PionDirection[SampleId::kFGD1AntiNuMuCC0Pi]);
  
  static_cast<AnaEventSummaryB*>(event.Summary)->PionCandidate[SampleId::kFGD1AntiNuMuCC1Pi]   = 
    box.pionBox.GetHMPion(static_cast<AnaEventSummaryB*>(event.Summary)->PionMomentum[SampleId::kFGD1AntiNuMuCC1Pi], 
        static_cast<AnaEventSummaryB*>(event.Summary)->PionDirection[SampleId::kFGD1AntiNuMuCC1Pi]);
  
  static_cast<AnaEventSummaryB*>(event.Summary)->PionCandidate[SampleId::kFGD1AntiNuMuCCOther] = 
    box.pionBox.GetHMPion(static_cast<AnaEventSummaryB*>(event.Summary)->PionMomentum[SampleId::kFGD1AntiNuMuCCOther], 
        static_cast<AnaEventSummaryB*>(event.Summary)->PionDirection[SampleId::kFGD1AntiNuMuCCOther]);

  // Fill proton candidates
  static_cast<AnaEventSummaryB*>(event.Summary)->ProtonCandidate[SampleId::kFGD1AntiNuMuCC0Pi]   = 
    box.pionBox.GetHMProton(static_cast<AnaEventSummaryB*>(event.Summary)->ProtonMomentum[SampleId::kFGD1AntiNuMuCC0Pi], 
        static_cast<AnaEventSummaryB*>(event.Summary)->ProtonDirection[SampleId::kFGD1AntiNuMuCC0Pi]);
  
  static_cast<AnaEventSummaryB*>(event.Summary)->ProtonCandidate[SampleId::kFGD1AntiNuMuCC1Pi]   = 
    box.pionBox.GetHMProton(static_cast<AnaEventSummaryB*>(event.Summary)->ProtonMomentum[SampleId::kFGD1AntiNuMuCC1Pi], 
        static_cast<AnaEventSummaryB*>(event.Summary)->ProtonDirection[SampleId::kFGD1AntiNuMuCC1Pi]);

  
  static_cast<AnaEventSummaryB*>(event.Summary)->ProtonCandidate[SampleId::kFGD1AntiNuMuCCOther] = 
    box.pionBox.GetHMProton(static_cast<AnaEventSummaryB*>(event.Summary)->ProtonMomentum[SampleId::kFGD1AntiNuMuCCOther], 
        static_cast<AnaEventSummaryB*>(event.Summary)->ProtonDirection[SampleId::kFGD1AntiNuMuCCOther]);

  
  
  for (int i = 0; i < 4; ++i){
    static_cast<AnaEventSummaryB*>(event.Summary)->VertexPosition[SampleId::kFGD1AntiNuMuCC0Pi][i]   = box.HMPtrack->PositionStart[i];
    static_cast<AnaEventSummaryB*>(event.Summary)->VertexPosition[SampleId::kFGD1AntiNuMuCC1Pi][i]   = box.HMPtrack->PositionStart[i];
    static_cast<AnaEventSummaryB*>(event.Summary)->VertexPosition[SampleId::kFGD1AntiNuMuCCOther][i] = box.HMPtrack->PositionStart[i];
  }
  
  if (box.HMPtrack->GetTrueParticle()){
    static_cast<AnaEventSummaryB*>(event.Summary)->TrueVertex[SampleId::kFGD1AntiNuMuCC0Pi]   = box.HMPtrack->GetTrueParticle()->TrueVertex;
    static_cast<AnaEventSummaryB*>(event.Summary)->TrueVertex[SampleId::kFGD1AntiNuMuCC1Pi]   = box.HMPtrack->GetTrueParticle()->TrueVertex;
    static_cast<AnaEventSummaryB*>(event.Summary)->TrueVertex[SampleId::kFGD1AntiNuMuCCOther] = box.HMPtrack->GetTrueParticle()->TrueVertex;
  }
  
  static_cast<AnaEventSummaryB*>(event.Summary)->SelPionTopo[SampleId::kFGD1AntiNuMuCC0Pi]   = box.pionBox.GetPionTopo();
  static_cast<AnaEventSummaryB*>(event.Summary)->SelPionTopo[SampleId::kFGD1AntiNuMuCC1Pi]   = box.pionBox.GetPionTopo();
  static_cast<AnaEventSummaryB*>(event.Summary)->SelPionTopo[SampleId::kFGD1AntiNuMuCCOther] = box.pionBox.GetPionTopo();

  static_cast<AnaEventSummaryB*>(event.Summary)->SelProtonTopo[SampleId::kFGD1AntiNuMuCC0Pi]   = box.pionBox.GetProtonTopo();
  static_cast<AnaEventSummaryB*>(event.Summary)->SelProtonTopo[SampleId::kFGD1AntiNuMuCC1Pi]   = box.pionBox.GetProtonTopo();
  static_cast<AnaEventSummaryB*>(event.Summary)->SelProtonTopo[SampleId::kFGD1AntiNuMuCCOther] = box.pionBox.GetProtonTopo(); 
  
  
  return true;
}

//*********************************************************************
bool FindPionsAction_antinuCC1pi::Apply(AnaEventC& event, ToyBoxB& box) const{
  //*********************************************************************

  // Slightly different filling w.r.t. the one of numuCCmultipi, so keep it 
  
  ToyBoxCCMultiPi* ccmultipibox = static_cast<ToyBoxCCMultiPi*>(&box);

  pionSelParams.refTrack = ccmultipibox->MainTrack;
  
  ccmultipibox->pionBox.Detector = (SubDetId::SubDetEnum)box.DetectorFV;
  
  // Fill the info
  cutUtils::FillPionInfo(event, ccmultipibox->pionBox, pionSelParams);

  
  int nnegpions        = ccmultipibox->pionBox.nNegativePionTPCtracks;
  int npospions        = ccmultipibox->pionBox.nPositivePionTPCtracks;
  int nisofgdpions     = ccmultipibox->pionBox.nIsoFGDPiontracks;
  int nmichelelectrons = ccmultipibox->pionBox.nMichelElectrons;
  int npi0             = ccmultipibox->pionBox.nPosPi0TPCtracks + ccmultipibox->pionBox.nElPi0TPCtracks;
  
  int pionFGD = 0;//nmichelelectrons;
  if (!nmichelelectrons && nisofgdpions == 1) pionFGD = 1;

  ccmultipibox->pionBox.nPosPions   = npospions + nmichelelectrons;
  ccmultipibox->pionBox.nNegPions   = nnegpions + pionFGD;
  ccmultipibox->pionBox.nOtherPions = ccmultipibox->pionBox.nPosPions+npi0;

  return true;
}

//**************************************************
bool antiNumuCC1piSelection::IsRelevantRecObjectForSystematic(const AnaEventC& event, AnaRecObjectC* track, SystId_h systId, Int_t branch) const{
  //**************************************************

  return _antiNumuCCMultiPiSelection.IsRelevantRecObjectForSystematic(event,track,systId,branch);
}

//**************************************************
bool antiNumuCC1piSelection::IsRelevantTrueObjectForSystematic(const AnaEventC& event, AnaTrueObjectC* trueTrack, SystId_h systId, Int_t branch) const{
  //**************************************************

  return _antiNumuCCMultiPiSelection.IsRelevantTrueObjectForSystematic(event,trueTrack,systId,branch);
}

//**************************************************
bool antiNumuCC1piSelection::IsRelevantRecObjectForSystematicInToy(const AnaEventC& event, const ToyBoxB& box, AnaRecObjectC* track, SystId_h systId, Int_t branch) const{
  //**************************************************
  
  return _antiNumuCCMultiPiSelection.IsRelevantRecObjectForSystematicInToy(event,box,track,systId,branch);
  
  /*if (!track) return false;

  const ToyBoxCCMultiPi* ccmultipibox = static_cast<const ToyBoxCCMultiPi*>(&box);
  
  // Apply to all objects,  not fine-tuning
  if (!systTuning::APPLY_SYST_FINE_TUNING) return true;

  // Check inclusive first
  if (_antiNumuCCSelection.IsRelevantSystematic (event, box, systId, branch) && 
      _antiNumuCCSelection.IsRelevantRecObjectForSystematicInToy(event,box,track,systId,branch)) return true;
  
  switch (systId){
    // Fall back through the relevant ones
    // TPC reco
    case SystId::kChargeIDEff:
      // TPC matching
    case SystId::kTpcFgdMatchEff:

      // Use the APPLY_SYST_FINE_TUNING concept as well,  since we worry about the "main" track that defines the topology 
      if (branch == 1){
        // For CC-1pi also the negative Pion in the TPC matters
        if (ccmultipibox->pionBox.nNegativePionTPCtracks == 1 && track==ccmultipibox->pionBox.NegativePionTPCtracks[0]) return true; 
      }
      else if (branch == 2){
        // For CC-Other consider the positive pion when there are no other pions
        if (ccmultipibox->pionBox.nPositivePionTPCtracks == 1 && track==ccmultipibox->pionBox.PositivePionTPCtracks[0] && 
            ccmultipibox->pionBox.nOtherPions == 1 && ccmultipibox->pionBox.nNegPions == 0) return true;  

      }
      // Failed above + 
      // CC0pi explicit false (should have been covered by numuCC if tuning is ON)
      return false;
      break;
      
    default:
      break;
  }
  
  // The rest of the systematics gets tuning from numu multi-pi
  return _numuCCMultiPiSelection.IsRelevantRecObjectForSystematicInToy(event, box, track, systId, branch);
*/
}


//**************************************************
bool  antiNumuCC1piSelection::IsRelevantTrueObjectForSystematicInToy(const AnaEventC& event, const ToyBoxB& box, AnaTrueObjectC* trueObj, SystId_h systId, Int_t branch) const{
  //**************************************************
  
  return _antiNumuCCMultiPiSelection.IsRelevantTrueObjectForSystematicInToy(event,box,trueObj,systId,branch);
  
  /*const ToyBoxCCMultiPi* ccmultipibox = static_cast<const ToyBoxCCMultiPi*>(&box);
  
  AnaTrueParticleB* trueTrack = static_cast<AnaTrueParticleB*>(trueObj);
  if (!trueTrack) return false;
  
  // Apply to all objects,  not fine-tuning
  if (!systTuning::APPLY_SYST_FINE_TUNING) return true;

  // all CC inclusive cases
  // MAIN track mode is taken into account there
  if (_antiNumuCCSelection.IsRelevantSystematic (event, box, systId, branch) && 
      _antiNumuCCSelection.IsRelevantTrueObjectForSystematicInToy(event,box,trueTrack,systId,branch)) return true;

  switch (systId){
    case SystId::kTpcTrackEff:
      
      // Don't consider pions when there are many TPC ones (a conservative check)
      // Cases in which we must loose two or more pions are excluded (0.01*0.01 probability)
      if (ccmultipibox->pionBox.nNegativePionTPCtracks+ccmultipibox->pionBox.nPositivePionTPCtracks > 2 ||
          ccmultipibox->pionBox.nPositivePionTPCtracks > 1) return false; 
      
      // If the are few TPC pions consider them, muons and electrons 
      if (abs(trueTrack->PDG)==211 || abs(trueTrack->PDG)==13 || abs(trueTrack->PDG)==11) return true;  
      
      return false;
      break;
      
    // SI
    case SystId::kSIPion:
      // No Pion SI systematic when there are many pions 
      if (ccmultipibox->pionBox.nOtherPions >1 || ccmultipibox->pionBox.nNegPions > 2 ) return false; 
      return true;
      break;
    
    // Contributors for relevant objects for proton SI
    case SystId::kSIProton:
     
      // Main track is done by numuCC
      // If there are  many pions, i.e. topology cannot change, then do not use
      // the systematic
      if (ccmultipibox->pionBox.nOtherPions >1 || ccmultipibox->pionBox.nNegPions > 2 ) return false; 
      // Otherwise check that a pion contributes to any of the objects in the
      // box
      return cutUtils::numuCCTrkMultiPi::CheckTrueCausesBoxSimple(*trueTrack, ccmultipibox->pionBox);
      break;
    default:
      break;
  }

  // For the rest of the systematic use numuCC multi-pion tuning
  return _numuCCMultiPiSelection.IsRelevantTrueObjectForSystematicInToy(event, box, trueObj, systId, branch);
*/
}

//**************************************************
bool antiNumuCC1piSelection::IsRelevantSystematic(const AnaEventC& event, const ToyBoxB& box, SystId_h systId, Int_t branch) const{
  //**************************************************

  return _antiNumuCCMultiPiSelection.IsRelevantSystematic(event, box, systId, branch);
}

//**************************************************
Int_t antiNumuCC1piSelection::GetRelevantRecObjectGroupsForSystematic(SystId_h systId, Int_t* IDs, Int_t branch) const{
//**************************************************

  return _antiNumuCCMultiPiSelection.GetRelevantRecObjectGroupsForSystematic(systId, IDs, branch);
}

//**************************************************
Int_t antiNumuCC1piSelection::GetRelevantTrueObjectGroupsForSystematic(SystId_h systId, Int_t* IDs, Int_t branch) const{
//**************************************************

  return _antiNumuCCMultiPiSelection.GetRelevantTrueObjectGroupsForSystematic(systId, IDs, branch);
}

//**************************************************
void antiNumuCC1piSelection::InitializeEvent(AnaEventC& eventC){
  //**************************************************
  
  
  
  AnaEventB& event = *static_cast<AnaEventB*>(&eventC); 
  
  //_antiNumuCCSelection.InitializeEvent(event); 
  _antiNumuCCMultiPiSelection.InitializeEvent(event); 
  /*
  boxUtils::FillTracksWithECal(event);
  boxUtils::FillFGDMichelElectrons(event, (SubDetId::SubDetEnum)GetDetectorFV(),
      (bool)ND::params().GetParameterI("psycheSelections.antinumuCCMultiPi.Prod5Cuts"));
  
  boxUtils::FillTrajsInECal(event);*/
}

//********************************************************************
bool antiNumuCC1piSelection::CheckRedoSelection(const AnaEventC& event, const ToyBoxB& PreviousToyBox, Int_t& redoFromStep){
  //********************************************************************

  // Must redo selection if antiNumuCCSelection decides so
  if( _antiNumuCCMultiPiSelection.CheckRedoSelection(event,PreviousToyBox,redoFromStep)) return true;

  // Otherwise selection should not be redone since the number of tracks with TPC and FGD will not be changed by systematics
  return false;
}

// PID cuts:

//**************************************************
bool AntiMuonPIDCut_Loop::Apply(AnaEventC& event, ToyBoxB& boxB) const{
//**************************************************

  (void)event;
  // Cast the ToyBox to the appropriate type
  ToyBoxTracker& box = *static_cast<ToyBoxTracker*>(&boxB); 
  
  // Check that HMPT exists and momentum is positive
  if (!box.HMPtrack) return false;
  if (box.HMPtrack->Momentum < 0.) return false;
  
  // Loop over positive TPC tracks, applying antimu PID
  Int_t NTracks = box.nPositiveTPCtracks;
  Int_t NMuonLike = 0;
  
  AnaTrackB** PosTracksArray = box.PositiveTPCtracks;
  
  for (int i=0; i < NTracks; i++)
  {
    AnaTrackB* track = PosTracksArray[i];
    
    if (track->Momentum < 0.) continue; // Check that track momentum is valid
    
    if (cutUtils::AntiMuonPIDCut(*track)) // If track passes muon PID, set as antimu candidate
    {
      box.MainTrack = track;
      NMuonLike++;
    }
  }
  
  
  if (NMuonLike == 1) return true; // If there is a single antimu-like track, this is now the main track and the cut is passed
  return false; // Otherwise, i.e. if there are no antimu-like tracks, or more than one, the cut is failed
  
  //Old version just applies PID to the HMPT
  //return cutUtils::AntiMuonPIDCut(*(box.HMPtrack));
  
}

//**************************************************
bool MuonWithECalSegmentsCut::Apply(AnaEventC& event, ToyBoxB& boxB) const{
  //**************************************************

  (void)event;

  // Cast the ToyBox to the appropriate type
  ToyBoxTracker& box = *static_cast<ToyBoxTracker*>(&boxB); 

  if (box.MainTrack->nECALSegments > 0) return true;

  return false;

}

//**************************************************
bool MuonWithoutECalSegmentsCut::Apply(AnaEventC& event, ToyBoxB& boxB) const{
  //**************************************************

  (void)event;

  // Cast the ToyBox to the appropriate type
  ToyBoxTracker& box = *static_cast<ToyBoxTracker*>(&boxB); 

  if (box.MainTrack->nECALSegments == 0) return true;

  return false;

}

//**************************************************
bool MuonECalEMEnergyLengthCut::Apply(AnaEventC& event, ToyBoxB& boxB) const{
  //**************************************************

  (void)event;

  // Cast the ToyBox to the appropriate type
  ToyBoxTracker& box = *static_cast<ToyBoxTracker*>(&boxB);
  
  // Waive cut if muon candidate track has no ECal segments
  if (box.MainTrack->nECALSegments == 0) return true;
  
  AnaECALParticle* ECalSeg = static_cast<AnaECALParticle*>( box.MainTrack->ECALSegments[0] );

  if ( (ECalSeg->EMEnergy)/(ECalSeg->Length) < 1.0) return true;

  return false;

}

//**************************************************
bool MuonECalMipPionCut::Apply(AnaEventC& event, ToyBoxB& boxB) const{
  //**************************************************

  (void)event;

  // Cast the ToyBox to the appropriate type
  ToyBoxTracker& box = *static_cast<ToyBoxTracker*>(&boxB);
  
  // Waive cut if muon candidate track has no ECal segments
  if (box.MainTrack->nECALSegments == 0) return true;
  
  AnaECALParticle* ECalSeg = static_cast<AnaECALParticle*>( box.MainTrack->ECALSegments[0] );

  if (ECalSeg->PIDMipPion < 0.0) return true;

  return false;
}

//**************************************************
bool PionECalEMEnergyLengthCut::Apply(AnaEventC& event, ToyBoxB& boxB) const{
  //**************************************************

  (void)event;

  // Cast the ToyBox to the appropriate type
  ToyBoxTracker& box = *static_cast<ToyBoxTracker*>(&boxB);
  
  // Waive cut if HMN track does not exist
  if (!box.HMNtrack) return true;
  
  // Waive cut if pion candidate track has no ECal segments
  if (box.HMNtrack->nECALSegments == 0) return true;
  
  AnaECALParticle* ECalSeg = static_cast<AnaECALParticle*>( box.HMNtrack->ECALSegments[0] );

  if ( (ECalSeg->EMEnergy)/(ECalSeg->Length) > 1.0) return true;

  return false;

}

//**************************************************
bool OptimisedMuonECalPIDCut::Apply(AnaEventC& event, ToyBoxB& boxB) const{
  //**************************************************

  (void)event;

  // Cast the ToyBox to the appropriate type
  ToyBoxTracker& box = *static_cast<ToyBoxTracker*>(&boxB);
 
  if ((box.HMNtrack) && (box.HMNtrack->nECALSegments > 0) && (box.MainTrack->nECALSegments > 0)) // Bothseg case
  {
    AnaECALParticle* ECalSeg = static_cast<AnaECALParticle*>( box.MainTrack->ECALSegments[0] );
      
    if ( (ECalSeg->EMEnergy)/(ECalSeg->Length) > 1.1) return false;
    if ( ECalSeg->PIDMipPion > 8.3)                   return false;
  }
    
  else if (box.MainTrack->nECALSegments > 0) // Museg case
  {
    AnaECALParticle* ECalSeg = static_cast<AnaECALParticle*>( box.MainTrack->ECALSegments[0] );
      
    if ( (ECalSeg->EMEnergy)/(ECalSeg->Length) > 1.6) return false;
    if ( ECalSeg->PIDMipPion > 17.0)                  return false;
  }
  

  return true;

}

//**************************************************
bool OptimisedPionECalPIDCut::Apply(AnaEventC& event, ToyBoxB& boxB) const{
  //**************************************************

  (void)event;

  // Cast the ToyBox to the appropriate type
  ToyBoxTracker& box = *static_cast<ToyBoxTracker*>(&boxB);
  
  
  if (box.HMNtrack)
  {
    if ((box.HMNtrack->nECALSegments > 0) && (box.MainTrack->nECALSegments > 0)) // Bothseg case
    {
      AnaECALParticle* ECalSeg = static_cast<AnaECALParticle*>( box.HMNtrack->ECALSegments[0] );
      
      if ( (ECalSeg->EMEnergy)/(ECalSeg->Length) < 0.1) return false;
      if ( ECalSeg->PIDMipPion < -6.0)                  return false;
    }
    
    else if (box.HMNtrack->nECALSegments > 0) // Piseg case
    {
      AnaECALParticle* ECalSeg = static_cast<AnaECALParticle*>( box.HMNtrack->ECALSegments[0] );
      
      if ( (ECalSeg->EMEnergy)/(ECalSeg->Length) < 0.28) return false;
      if ( ECalSeg->PIDMipPion < -0.91)                  return false;
    }
  }

  return true;

}
