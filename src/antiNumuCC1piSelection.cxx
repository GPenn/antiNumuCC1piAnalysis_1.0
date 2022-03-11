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
antiNumuCC1piSelection::antiNumuCC1piSelection(bool forceBreak, InputManager* INPUT, BDTPIDmanager *BDTPID) : 
  SelectionBase(forceBreak,EventBoxId::kEventBoxTracker), _input(INPUT) {
  //********************************************************************
  _antiNumuCCSelection.Initialize();
  //_numuCCMultiPiSelection.Initialize(); 
  _antiNumuCCMultiPiSelection.Initialize(); 
  //_useECalPiZeroInfo = (bool)ND::params().GetParameterI("psycheSelections.antinumuCCMultiPi.UseECalPiZeroInfo");
  //_numuCCMultiPiSelection.SetUseECalPiZeroInfo(_useECalPiZeroInfo);
    
  _bdtpid = BDTPID;
}

//********************************************************************
void antiNumuCC1piSelection::DefineSteps(){
  //********************************************************************

  // ======== EXISTING SELECTION ========
  /*
  // Copy all steps from the antiNumuCCSelection
  CopySteps(_antiNumuCCSelection);

  //Pawel - Pions sele
  //Additional actions for the multi-pi selection.
  
  AddStep(StepBase::kAction, "find_pions",                new FindPionsAction_antinuCCMultiPi());
  AddStep(StepBase::kAction, "find_protons",              new FindProtonsAction());
  
  AddStep(StepBase::kAction, "set_vertex_to_box",                 new SetVertexToBoxAction());
  AddStep(StepBase::kAction, "fill_iso_fgd_proton_mom_to_vertex", new FillFgdIsoProtonsKinVertexAction());
  AddStep(StepBase::kAction, "find_iso_fgd_pion_mom_to_vertex",   new FillFgdIsoPionsKinVertexAction());
  
  
  AddStep(StepBase::kAction, "fill_summary antinu_pion",  new FillSummaryAction_antinuCCMultiPi());

  //Add a split to the trunk with 3 branches.
  AddSplit(3);

  //First branch is for CC-0pi
  AddStep(0, StepBase::kCut, "CC-0pi",        new NoPionCut());
  AddStep(0, StepBase::kCut, "ECal Pi0 veto", new EcalPi0VetoCut());

  //Second branch is for CC-1pi
  AddStep(1, StepBase::kCut, "CC-1pi",        new OnePionCut(false));
  AddStep(1, StepBase::kCut, "ECal Pi0 veto", new EcalPi0VetoCut());

  //Third branch is for CC-Other
  AddStep(2, StepBase::kCut, "CC-Other", new OthersCut());
  */
  
  
  // ======== MODIFIED SELECTION ========
  
  // Cuts must be added in the right order
  // last "true" means the step sequence is broken if cut is not passed (default is "false")
  AddStep(StepBase::kCut,    "event quality",      new EventQualityCut(),           true);
  AddStep(StepBase::kCut,    "> 0 tracks ",        new TotalMultiplicityCut(),      true);  
  AddStep(StepBase::kAction, "find leading tracks",new FindLeadingTracksAction_antinu());  
  AddStep(StepBase::kAction, "find vertex",        new FindVertexAction());  
  AddStep(StepBase::kAction, "fill summary",       new FillSummaryAction_antinu());  
  AddStep(StepBase::kCut,    "quality+fiducial",   new TrackQualityFiducialCut(),   true);
  //AddStep(StepBase::kCut,    "pos_mult",           new PositiveMultiplicityCut());  
  AddStep(StepBase::kAction, "find veto track",    new FindVetoTrackAction());
  AddStep(StepBase::kCut,    "veto",               new ExternalVetoCut());
  AddStep(StepBase::kAction, "find oofv track",    new FindOOFVTrackAction());
  AddStep(StepBase::kCut,    "External FGD1",      new ExternalFGD1lastlayersCut());
  
  AddStep(StepBase::kAction, "GetAllTECALReconObjects",            new GetAllTECALReconObjectsAction(_input)); // GetAllTECALReconObjects from the AnaLocalReconBunch
  AddStep(StepBase::kAction, "MatchECalGlobalToLocalObjects",      new MatchECalGlobalToLocalObjectsAction ()); // Match to local reconstruction
  
  //AddStep(StepBase::kCut,    "Antimu PID loop",      new AntiMuonPIDCut_Loop());
  //AddStep(StepBase::kCut,    "Antimu PID",         new AntiMuonPIDCut());
  AddStep(StepBase::kCut,    "Antimu PID loop",      new AntiMuonPIDCut_LoopBDTPID(_bdtpid));
  
  AddStep(StepBase::kAction, "find_pions",                new FindPionsAction_BDTPID(_bdtpid));
  AddStep(StepBase::kAction, "find_protons",              new FindProtonsAction_BDTPID(_bdtpid));
  AddStep(StepBase::kAction, "fill_summary antinu_pion",  new FillSummaryAction_antinuCCMultiPi());

  //Add a split to the trunk with 3 branches.
  AddSplit(3);

  //First branch is for CC-0pi
  //AddStep(0, StepBase::kCut, "Antimu PID",         new AntiMuonPIDCut());
  AddStep(0, StepBase::kCut, "CC-0pi",        new NoPionCut());
  AddStep(0, StepBase::kCut, "ECal Pi0 veto", new EcalPi0VetoCut());
  
  //AddStep(0, StepBase::kCut, "Muon with ECal segments", new MuonWithECalSegmentsCut());
  //AddStep(0, StepBase::kCut, "ECal Muon PID EMEnergy/Length", new MuonECalEMEnergyLengthCut());
  //AddStep(0, StepBase::kCut, "ECal Muon PID MipPion", new MuonECalMipPionCut());
  

  //Second branch is for CC-1pi
  
  // --------------- old version ---------------
  //AddStep(1, StepBase::kCut,    "Antimu PID",         new AntiMuonPIDCut());
  //AddStep(1, StepBase::kCut,    "Antimu PID loop",      new AntiMuonPIDCut_Loop());
  AddStep(1, StepBase::kCut, "CC1pi TPC PID",        new OnePionCut(false));
  AddStep(1, StepBase::kCut, "ECal Pi0 veto", new EcalPi0VetoCut());
  //AddStep(1, StepBase::kCut, "ECal muon PID", new OptimisedMuonECalPIDCut());
  //AddStep(1, StepBase::kCut, "ECal pion PID", new OptimisedPionECalPIDCut());
  AddStep(1, StepBase::kCut, "ECal muon PID", new ReoptimisedMuonECalPIDCut());
  AddStep(1, StepBase::kCut, "ECal pion PID", new ReoptimisedPionECalPIDCut());
  
  //AddSplit(2,1);
  //CC1pi with muon candidate ECal segment
  //AddStep(1, StepBase::kCut, "Muon with ECal segments", new MuonWithECalSegmentsCut());
  //AddStep(1, StepBase::kCut, "ECal Muon E/L", new MuonECalEMEnergyLengthCut());
  //AddStep(1, StepBase::kCut, "ECal Muon MipPion", new MuonECalMipPionCut());
  //AddStep(1, StepBase::kCut, "ECal Pion E/L", new PionECalEMEnergyLengthCut());
  
  //CC1pi without muon candidate ECal segment
  //AddStep(1, 1, StepBase::kCut, "Muon without ECal segments", new MuonWithoutECalSegmentsCut());
  
  // --------------- BDT testing version ---------------
  /*
  AddStep(1, StepBase::kCut, "Main track kinematics for BDT",      new BDTPreselectionKinematicsCut());
  AddStep(1, StepBase::kCut, "1pos1neg TPC tracks",                new TwoTrack1pos1negCut());
  AddStep(1, StepBase::kCut, "HMNT kinematics for BDT",            new BDTPreselectionKinematicsPiCandCut());
  */
  
  //Third branch is for CC-Other
  //AddStep(2, StepBase::kCut, "Antimu PID", new AntiMuonPIDCut());
  AddStep(2, StepBase::kCut, "CC-Other", new OthersCut());
  
  //AddStep(2, StepBase::kCut, "Muon with ECal segments", new MuonWithECalSegmentsCut());
  AddStep(2, StepBase::kCut, "ECal Muon PID EMEnergy/Length", new MuonECalEMEnergyLengthCut());
  AddStep(2, StepBase::kCut, "ECal Muon PID MipPion", new MuonECalMipPionCut());
  

  // Set the branch aliases to the branches
  SetBranchAlias(0,"CC-0pi",  0);
  SetBranchAlias(1,"CC-1pi",  1);
  //SetBranchAlias(1, "CC-1pi with ECal",  1);
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
  
  _antiNumuCCSelection.InitializeEvent(event); 
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
bool MyDummyCut::Apply(AnaEventC& event, ToyBoxB& boxB) const{
  //**************************************************
  return true;
}

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
bool AntiMuonPIDCut_LoopBDTPID::Apply(AnaEventC& event, ToyBoxB& boxB) const{
//**************************************************

  (void)event;
  // Cast the ToyBox to the appropriate type
  ToyBoxAntiCC1Pi& box = *static_cast<ToyBoxAntiCC1Pi*>(&boxB);
  
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
    
    //if (cutUtils::AntiMuonPIDCut(*track)) // If track passes muon PID, set as antimu candidate
    //{
    //  box.MainTrack = track;
    //  NMuonLike++;
    //}
    
    // Check whether the BDT PID is valid
    bool valid_for_BDTPID = false;
    TVector3 DirVec = anaUtils::ArrayToTVector3(track->DirectionStart);
    if ((track->Momentum > 200) && (track->Momentum < 1500) && (TMath::ACos(DirVec[2]) < 1.0472) && (_bdtpidmanager!=NULL)) {valid_for_BDTPID = true;}
    
    // Get BDT PID vars and apply if valid
    if (valid_for_BDTPID) {
      // Find local ECal segment if one exists
      AnaTECALReconObject* localecalsegment = NULL;
      if (track->nECALSegments == 1) 
      {
        AnaECALParticleB* ecalComponent = static_cast<AnaECALParticleB*>(track->ECALSegments[0]);
        for (unsigned int i = 0; i < box.FGD1GoodTPCTrackLocalECalSegments.size(); i++)
        {
          if (ecalComponent->UniqueID == box.FGD1GoodTPCTrackLocalECalSegments[i]->UniqueID)
          {
            localecalsegment = box.FGD1GoodTPCTrackLocalECalSegments[i];
            continue;
          }
        }
      }
      std::vector<Float_t> bdtpidvars = _bdtpidmanager->GetBDTPIDVarsPos(track, localecalsegment);
      
      if ((bdtpidvars[0] > bdtpidvars[1]) && (bdtpidvars[0] > bdtpidvars[2]) && (bdtpidvars[0] > bdtpidvars[3]))
      {
        box.MainTrack = track;
        NMuonLike++;
      }
    }
    
    // If BDT PID is not valid, apply usual TPC cut
    else if (cutUtils::AntiMuonPIDCut(*track)) // If track passes muon PID, set as antimu candidate
    {
      box.MainTrack = track;
      NMuonLike++;
    }
  }
  
  
  if (NMuonLike == 1) return true; // If there is a single antimu-like track, this is now the main track and the cut is passed
  return false; // Otherwise, i.e. if there are no antimu-like tracks, or more than one, the cut is failed
  
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
bool ReoptimisedMuonECalPIDCut::Apply(AnaEventC& event, ToyBoxB& boxB) const{
  //**************************************************

  (void)event;

  // Cast the ToyBox to the appropriate type
  ToyBoxTracker& box = *static_cast<ToyBoxTracker*>(&boxB);
 
  if (box.MainTrack->nECALSegments == 1)
  {
    AnaECALParticle* ECalSeg = static_cast<AnaECALParticle*>( box.MainTrack->ECALSegments[0] );
      
    if ( (ECalSeg->EMEnergy)/(ECalSeg->Length) > 0.88) return false;
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

//**************************************************
bool ReoptimisedPionECalPIDCut::Apply(AnaEventC& event, ToyBoxB& boxB) const{
  //**************************************************

  (void)event;

  // Cast the ToyBox to the appropriate type
  ToyBoxTracker& box = *static_cast<ToyBoxTracker*>(&boxB);
  
  
  if (box.HMNtrack)
  { 
    if (box.HMNtrack->nECALSegments == 1)
    {
      AnaECALParticle* ECalSeg = static_cast<AnaECALParticle*>( box.HMNtrack->ECALSegments[0] );
      
      if ( ECalSeg->PIDMipPion < -0.4) return false;
    }
  }

  return true;

}

//********************************************************************
bool GetAllTECALReconObjectsAction::Apply(AnaEventC& eventC, ToyBoxB& boxB) const{
//********************************************************************

  AnaEventB&           event      = *static_cast<AnaEventB*>(&eventC);
  ToyBoxAntiCC1Pi*     toyBox     = static_cast<ToyBoxAntiCC1Pi*>(&boxB);
  
  AnaLocalReconEvent*  localEvent =  static_cast<AnaLocalReconEvent*>(&event);  // Cast this event to the local variety
  AnaTECALReconObject* anaTECAL   =  NULL;

  //std::cout << "DEBUG: Got " <<localEvent->TECALReconObjects.size() << " TECALRecon objects from event " << event.EventInfo.Event <<std::endl;
  //std::cout << "DEBUG: TECALReconObjects.empty() = " <<localEvent->TECALReconObjects.empty() <<std::endl;
    
  // Loop over TECALReconObjects and save information
  for (unsigned int iObj=0; iObj<localEvent->TECALReconObjects.size(); iObj++){
    anaTECAL = localEvent->TECALReconObjects[iObj];
    toyBox->TECALReconObjects.push_back(anaTECAL);
    //std::cout<<"INFO: Read TECALReconObject with UniqueID:"<<anaTECAL->UniqueID<<" from bunch "<< anaTECAL->Bunch 
    //  << "("<< event.Bunch <<") in event "<< event.EventInfo.Event<<std::endl;
    
  } // End of loop over TECALReconObjects
  
  return true;
}

//********************************************************************
bool MatchECalGlobalToLocalObjectsAction::Apply(AnaEventC& eventC, ToyBoxB& boxB) const{
//********************************************************************

  //if (anaCCPi0Utils::utils().Verbosity())
  //  std::cout << this->Index() << " MatchECalGlobalToLocalObjectsAction" <<std::endl;

  //AnaEventB&       event  = *static_cast<AnaEventB*>(&eventC);
  ToyBoxAntiCC1Pi* toyBox =  static_cast<ToyBoxAntiCC1Pi*>(&boxB);
  EventBoxB* eventBox = eventC.EventBoxes[EventBoxId::kEventBoxTracker];

  if (toyBox->TECALReconObjects.empty()){ // if there are no ECal objects, continue
    //cout << "No ECal Objects" << std::endl; 
    return true;}

  // Pointers to derived types 
  AnaTrackB*        ecalTrack     = NULL;  // the entire track
  AnaECALParticleB* ecalComponent = NULL;  // the first segment (to match with AnaTECALReconObjects via UID)
  
  // Check each local ECal object against main track ECal segment:
  if (toyBox->MainTrack->nECALSegments == 1)
  {
    ecalTrack     = static_cast<AnaTrackB*>(toyBox->MainTrack);
    ecalComponent = static_cast<AnaECALParticleB*>(ecalTrack->ECALSegments[0]);
    for (unsigned int i = 0; i < toyBox->TECALReconObjects.size(); i++){
      if (ecalComponent->UniqueID == toyBox->TECALReconObjects[i]->UniqueID)
        toyBox->MainTrackLocalECalSegment = toyBox->TECALReconObjects[i];
        //std::cout << "Local-global match confirmed for MainTrack." << std::endl;
    }
  }
  
  // Check each local ECal object against HMN track ECal segment:
  if ((toyBox->HMNtrack)&&(toyBox->HMNtrack->nECALSegments == 1))
  {
    ecalTrack     = static_cast<AnaTrackB*>(toyBox->HMNtrack);
    ecalComponent = static_cast<AnaECALParticleB*>(ecalTrack->ECALSegments[0]);
    for (unsigned int i = 0; i < toyBox->TECALReconObjects.size(); i++){
      if (ecalComponent->UniqueID == toyBox->TECALReconObjects[i]->UniqueID)
        toyBox->HMNTLocalECalSegment = toyBox->TECALReconObjects[i];
        //std::cout << "Local-global match confirmed for HMNT." << std::endl;
    }
  }
  
  // Check each local ECal object against each good quality TPC track starting in FGD1FV:
  for (Int_t i = 0; i < eventBox->nRecObjectsInGroup[EventBoxTracker::kTracksWithGoodQualityTPCInFGD1FV]; i++)
  {
    ecalTrack     = static_cast<AnaTrackB*>(eventBox->RecObjectsInGroup[EventBoxTracker::kTracksWithGoodQualityTPCInFGD1FV][i]);
    
    // Only match if the track has exactly one ECal segment
    if (ecalTrack->nECALSegments == 1)
    {
      ecalComponent = static_cast<AnaECALParticleB*>(ecalTrack->ECALSegments[0]);
    
      for (unsigned int j = 0; j < toyBox->TECALReconObjects.size(); j++)
      {
        if (ecalComponent->UniqueID == toyBox->TECALReconObjects[j]->UniqueID)
        toyBox->FGD1GoodTPCTrackLocalECalSegments.push_back(toyBox->TECALReconObjects[j]);
      }
    }
  }
  
  return true;
}

//**************************************************
bool BDTPIDMuLikeCut::Apply(AnaEventC& event, ToyBoxB& boxB) const{
  //**************************************************

  (void)event;
  
  Float_t mulike_cutvalue = 0.621;

  // Cast the ToyBox to the appropriate type
  ToyBoxAntiCC1Pi& box = *static_cast<ToyBoxAntiCC1Pi*>(&boxB);
  
  // Waive cut if muon candidate track has no ECal segments
  //if (!box.MainTrack) return true;
  
  std::vector<Float_t> pidvars = _bdtpidmanager->GetBDTPIDVarsPos(box.MainTrack, box.MainTrackLocalECalSegment);
  Float_t mulike_bdtvalue = pidvars[0];

  if (mulike_bdtvalue > mulike_cutvalue) return true;

  return false;
}

//**************************************************
bool BDTPIDPiLikeCut::Apply(AnaEventC& event, ToyBoxB& boxB) const{
  //**************************************************

  (void)event;
  
  Float_t pilike_cutvalue = 0.490;

  // Cast the ToyBox to the appropriate type
  ToyBoxAntiCC1Pi& box = *static_cast<ToyBoxAntiCC1Pi*>(&boxB);
  
  // Waive cut if muon candidate track has no ECal segments
  //if (!box.MainTrack) return true;
  
  std::vector<Float_t> pidvars = _bdtpidmanager->GetBDTPIDVarsPos(box.MainTrack, box.MainTrackLocalECalSegment);
  Float_t pilike_bdtvalue = pidvars[1];

  if (pilike_bdtvalue > pilike_cutvalue) return true;

  return false;
}

//**************************************************
bool BDTPIDProtonLikeCut::Apply(AnaEventC& event, ToyBoxB& boxB) const{
  //**************************************************

  (void)event;
  
  Float_t plike_cutvalue = 0.648;

  // Cast the ToyBox to the appropriate type
  ToyBoxAntiCC1Pi& box = *static_cast<ToyBoxAntiCC1Pi*>(&boxB);
  
  // Waive cut if muon candidate track has no ECal segments
  //if (!box.MainTrack) return true;
  
  std::vector<Float_t> pidvars = _bdtpidmanager->GetBDTPIDVarsPos(box.MainTrack, box.MainTrackLocalECalSegment);
  Float_t plike_bdtvalue = pidvars[2];

  if (plike_bdtvalue > plike_cutvalue) return true;

  return false;
}

//**************************************************
bool BDTPIDElectronLikeCut::Apply(AnaEventC& event, ToyBoxB& boxB) const{
  //**************************************************

  (void)event;
  
  Float_t elike_cutvalue = 0.791;

  // Cast the ToyBox to the appropriate type
  ToyBoxAntiCC1Pi& box = *static_cast<ToyBoxAntiCC1Pi*>(&boxB);
  
  // Waive cut if muon candidate track has no ECal segments
  //if (!box.MainTrack) return true;
  
  std::vector<Float_t> pidvars = _bdtpidmanager->GetBDTPIDVarsPos(box.MainTrack, box.MainTrackLocalECalSegment);
  Float_t elike_bdtvalue = pidvars[3];

  if (elike_bdtvalue > elike_cutvalue) return true;

  return false;
}

//**************************************************
bool TwoTrack1pos1negCut::Apply(AnaEventC& event, ToyBoxB& boxB) const{
  //**************************************************

  (void)event;

  // Cast the ToyBox to the appropriate type
  ToyBoxTracker& box = *static_cast<ToyBoxTracker*>(&boxB); 

  if (box.nPositiveTPCtracks != 1) return false;
  if (box.nNegativeTPCtracks != 1) return false;

  return true;
}

//*********************************************************************
bool FindPionsAction_BDTPID::Apply(AnaEventC& event, ToyBoxB& box) const{
  //*********************************************************************

  // Slightly different filling w.r.t. the one of numuCCmultipi, so keep it 
  
  ToyBoxAntiCC1Pi* anticc1pibox = static_cast<ToyBoxAntiCC1Pi*>(&box);

  pionSelParams.refTrack = anticc1pibox->MainTrack;
  
  anticc1pibox->pionBox.Detector = (SubDetId::SubDetEnum)box.DetectorFV;
  
  // Fill the info
  BDTPIDUtils::FillPionInfo(event, anticc1pibox->pionBox, pionSelParams, _bdtpidmanager, anticc1pibox);
  
  int nnegpions        = anticc1pibox->pionBox.nNegativePionTPCtracks;
  int npospions        = anticc1pibox->pionBox.nPositivePionTPCtracks;
  int nisofgdpions     = anticc1pibox->pionBox.nIsoFGDPiontracks;
  int nmichelelectrons = anticc1pibox->pionBox.nMichelElectrons;
  int npi0             = anticc1pibox->pionBox.nPosPi0TPCtracks + anticc1pibox->pionBox.nElPi0TPCtracks;
  
  int pionFGD = 0;//nmichelelectrons;
  if (!nmichelelectrons && nisofgdpions == 1) pionFGD = 1;

  anticc1pibox->pionBox.nPosPions   = npospions + nmichelelectrons;
  anticc1pibox->pionBox.nNegPions   = nnegpions + pionFGD;
  anticc1pibox->pionBox.nOtherPions = anticc1pibox->pionBox.nPosPions+npi0;

  return true;
}

//*********************************************************************
bool FindProtonsAction_BDTPID::Apply(AnaEventC& event, ToyBoxB& box) const{
  //*********************************************************************

  ToyBoxAntiCC1Pi* anticc1pibox = static_cast<ToyBoxAntiCC1Pi*>(&box);

  /// For the moment we use only one reference track
  protonSelParams.refTracks[0] = anticc1pibox->MainTrack;
  protonSelParams.nRefTracks = 1;

  anticc1pibox->pionBox.Detector = (SubDetId::SubDetEnum)box.DetectorFV;

  // Fill the info
  BDTPIDUtils::FillProtonInfo(event, anticc1pibox->pionBox, protonSelParams, _bdtpidmanager, anticc1pibox);
  
  return true;
}

//*********************************************************************
void BDTPIDUtils::FillPionInfo(const AnaEventC& event, multipart::MultiParticleBox& pionBox, const multipart::PionSelectionParams& params, 
                               BDTPIDmanager* bdtpidmanager, ToyBoxAntiCC1Pi* anticc1pibox){
//*********************************************************************
  
  EventBoxTracker* EventBox = static_cast<EventBoxTracker*>(event.EventBoxes[EventBoxId::kEventBoxTracker]);
  if (!EventBox){
    std::cout << " BDTPIDUtils::FillPionInfo(): EventBoxTracker not available " << std::endl;  
    exit(1);
  }

  if (!SubDetId::IsFGDDetector(pionBox.Detector)){
    std::cout << " BDTPIDUtils::FillPionInfo(): provided detector " << pionBox.Detector << "is not FGD1 or FGD2" << std::endl;
    exit(1);
  } 

  if (params.useTPCPions) BDTPIDUtils::FindGoodQualityTPCPionInfoInFGDFV(event, params.refTrack, 
      pionBox, params.useOldSecondaryPID, bdtpidmanager, anticc1pibox); 

  if (params.useFGDPions) cutUtils::FindIsoFGDPionInfo(event, pionBox);

  if (params.useME)  pionBox.nMichelElectrons =  EventBox->nFGDMichelElectrons[pionBox.Detector];

  // ECal 
  if (params.useECalPiZeroInfo){

    // Get the most energetic ECal iso object from the event 
    AnaTrackB* track = cutUtils::GetMostEnergeticIsoTrackInECal(event);
    if (track && cutUtils::IsECalShower(*track, 
          params.ECalMostUpstreamLayerHitCut, 
          params.ECalEMEnergyCut, 
          params.ECalPIDMipEmCut)){
      pionBox.ECalPi0Photon  = track; 
    }

  }
  return;

}

//*********************************************************************
void BDTPIDUtils::FillProtonInfo(const AnaEventC& event, multipart::MultiParticleBox& pionBox, const multipart::ProtonSelectionParams& params, 
                                 BDTPIDmanager* bdtpidmanager, ToyBoxAntiCC1Pi* anticc1pibox){
  //*********************************************************************

  EventBoxTracker* EventBox = static_cast<EventBoxTracker*>(event.EventBoxes[EventBoxId::kEventBoxTracker]);
  if (!EventBox){
    std::cout << " BDTPIDUtils::FillProtonInfo(): EventBoxTracker not available " << std::endl;  
    exit(1);
  }

  if (!SubDetId::IsFGDDetector(pionBox.Detector)){
    std::cout << " BDTPIDUtils::FillProtonInfo(): provided detector " << pionBox.Detector << "is not FGD1 or FGD2" << std::endl;
    exit(1);
  } 

  // TPC protons
  BDTPIDUtils::FindGoodQualityTPCProtonsInFGDFV(event, pionBox, params, bdtpidmanager, anticc1pibox); 

  // FGD-iso protons
  cutUtils::FindIsoFGDProtons(event, pionBox, params);

  return;
}

//*********************************************************************
void BDTPIDUtils::FindGoodQualityTPCPionInfoInFGDFV(const AnaEventC& event, const AnaTrackB* reftrack, multipart::MultiParticleBox& pionBox, 
    bool useOldSecondaryPID, BDTPIDmanager* bdtpidmanager, ToyBoxAntiCC1Pi* anticc1pibox){
  //*********************************************************************

  EventBoxTracker::RecObjectGroupEnum groupID;
  if      (pionBox.Detector == SubDetId::kFGD1) groupID = EventBoxTracker::kTracksWithGoodQualityTPCInFGD1FV;
  else if (pionBox.Detector == SubDetId::kFGD2) groupID = EventBoxTracker::kTracksWithGoodQualityTPCInFGD2FV;
  else return;


  return FindGoodQualityTPCPionInfo(event, reftrack, pionBox, groupID, useOldSecondaryPID, bdtpidmanager, anticc1pibox);

}


//*********************************************************************
void BDTPIDUtils::FindGoodQualityTPCPionInfo(const AnaEventC& event, const AnaTrackB* reftrack, multipart::MultiParticleBox& pionBox, 
    EventBoxTracker::RecObjectGroupEnum groupID, 
    bool useOldSecondaryPID, BDTPIDmanager* bdtpidmanager, ToyBoxAntiCC1Pi* anticc1pibox){
  //*********************************************************************

  pionBox.nPositivePionTPCtracks = 0;
  pionBox.nPosPi0TPCtracks       = 0;
  pionBox.nNegativePionTPCtracks = 0;
  pionBox.nElPi0TPCtracks        = 0;

  EventBoxB* EventBox = event.EventBoxes[EventBoxId::kEventBoxTracker];

  // Look for pions in positive tracks 
  for(int i = 0; i < EventBox->nRecObjectsInGroup[groupID]; i++ ) {


    AnaTrackB *ptrack = static_cast<AnaTrackB*>(EventBox->RecObjectsInGroup[groupID][i]);

    if (!ptrack) continue;

    if (reftrack == ptrack ) continue; // Same as the reference track.

    // A track should have a TPC and satisfy quality cut
    if (!cutUtils::TrackQualityCut(*ptrack)){
      continue;
    }
    
    // Check whether the BDT PID is valid
    bool valid_for_BDTPID = false;
    TVector3 DirVec = anaUtils::ArrayToTVector3(ptrack->DirectionStart);
    if ((ptrack->Momentum > 200) && (ptrack->Momentum < 1500) && (TMath::ACos(DirVec[2]) < 1.0472) && (bdtpidmanager!=NULL)) {valid_for_BDTPID = true;}
    
    // Get BDT PID vars
    AnaTECALReconObject* localecalsegment = NULL;
    std::vector<Float_t> bdtpidvars;
    if (valid_for_BDTPID) {
      // Find local ECal segment if one exists
      if (ptrack->nECALSegments == 1) 
      {
         AnaECALParticleB* ecalComponent = static_cast<AnaECALParticleB*>(ptrack->ECALSegments[0]);
        for (unsigned int i = 0; i < anticc1pibox->FGD1GoodTPCTrackLocalECalSegments.size(); i++)
        {
          if (ecalComponent->UniqueID == anticc1pibox->FGD1GoodTPCTrackLocalECalSegments[i]->UniqueID)
          {
            localecalsegment = anticc1pibox->FGD1GoodTPCTrackLocalECalSegments[i];
            //std::cout << "INFO: Found local ECal segment for pion PID." << std::endl;
            continue;
          }
        }
      }
      bdtpidvars = bdtpidmanager->GetBDTPIDVarsPos(ptrack, localecalsegment);
    }

    if (ptrack->Charge>0){
      if (useOldSecondaryPID){
        if (cutUtils::PionPIDCut(*ptrack) ) {
          pionBox.PositivePionTPCtracks[pionBox.nPositivePionTPCtracks++] = ptrack;
        }
        else if (cutUtils::ElectronPIDCut(*ptrack)) {
          pionBox.PosPi0TPCtracks[pionBox.nPosPi0TPCtracks++] = ptrack; 
        }
      }
      else if (valid_for_BDTPID) { // Apply BDT PID if valid
        // For Positive tracks we distinguish pions, electrons and protons.
        double ElLklh = bdtpidvars[1];  
        double ProtonLklh = bdtpidvars[2];  
        double PionLklh = bdtpidvars[3];  
        double norm = ElLklh+ProtonLklh+PionLklh;
        ProtonLklh /= norm; 
        ElLklh /= norm; 
        PionLklh /= norm; 

        if( ProtonLklh > ElLklh && ProtonLklh > PionLklh ) continue; // If the highest probability is a proton continue. 

        // Id associated to the largest of the two probabilities.
        if (PionLklh > ElLklh){
          pionBox.PositivePionTPCtracks[pionBox.nPositivePionTPCtracks++] = ptrack;
        }
        else {
          if (ptrack->Momentum > 900.) continue; // This is mainly protons.
          pionBox.PosPi0TPCtracks[pionBox.nPosPi0TPCtracks++] = ptrack; 
        }
        std::cout << "INFO: BDT pion PID applied!" << std::endl;
      }
      else { // Apply TPC PID if BDT PID not valid
        Float_t PIDLikelihood[4];
        anaUtils::GetPIDLikelihood(*ptrack, PIDLikelihood);

        // For Positive tracks we distinguish pions, electrons and protons.
        double ElLklh = PIDLikelihood[1];  
        double ProtonLklh = PIDLikelihood[2];  
        double PionLklh = PIDLikelihood[3];  
        double norm = ElLklh+ProtonLklh+PionLklh;
        ProtonLklh /= norm; 
        ElLklh /= norm; 
        PionLklh /= norm; 

        if( ProtonLklh > ElLklh && ProtonLklh > PionLklh ) continue; // If the highest probability is a proton continue. 

        // Id associated to the largest of the two probabilities.
        if (PionLklh > ElLklh){
          pionBox.PositivePionTPCtracks[pionBox.nPositivePionTPCtracks++] = ptrack;
        }
        else {
          if (ptrack->Momentum > 900.) continue; // This is mainly protons.
          pionBox.PosPi0TPCtracks[pionBox.nPosPi0TPCtracks++] = ptrack; 
        }
      }
    }
    else{
      if(useOldSecondaryPID) {
        if (cutUtils::PionPIDCut(*ptrack)) {
          pionBox.NegativePionTPCtracks[pionBox.nNegativePionTPCtracks++] = ptrack;
        } 
        else if (cutUtils::ElectronPIDCut(*ptrack)) {
          pionBox.ElPi0TPCtracks[pionBox.nElPi0TPCtracks++] = ptrack; 
        }
      }
      else if (valid_for_BDTPID) { // Apply BDT PID if valid
        // For Negative tracks we distinguish pions and electrons
        double ElLklh = bdtpidvars[1];  
        double PionLklh = bdtpidvars[3];  
        double norm = ElLklh+PionLklh;
        ElLklh /= norm; 
        PionLklh /= norm;

        if( PionLklh > ElLklh ){ // Id associated to the largest of the two probabilities.
          pionBox.NegativePionTPCtracks[pionBox.nNegativePionTPCtracks++] = ptrack;
        }
        else{ 
          pionBox.ElPi0TPCtracks[pionBox.nElPi0TPCtracks++] = ptrack; 
        }
      }
      else { // Apply TPC PID if BDT PID not valid
        // For Negative tracks we distinguish pions and electrons
        Float_t PIDLikelihood[4];
        anaUtils::GetPIDLikelihood(*ptrack, PIDLikelihood);

        double ElLklh = PIDLikelihood[1];  
        double PionLklh = PIDLikelihood[3];  
        double norm = ElLklh+PionLklh;
        ElLklh /= norm; 
        PionLklh /= norm;

        if( PionLklh > 0.8 ){ // Id associated to the largest of the two probabilities.
          pionBox.NegativePionTPCtracks[pionBox.nNegativePionTPCtracks++] = ptrack;
        }
        else{ 
          pionBox.ElPi0TPCtracks[pionBox.nElPi0TPCtracks++] = ptrack; 
        }
      }
    }
  }
}

//**************************************************
void BDTPIDUtils::FindGoodQualityTPCProtonsInFGDFV(const AnaEventC& event, multipart::MultiParticleBox& protonBox, const multipart::ProtonSelectionParams& params, 
                                                   BDTPIDmanager* bdtpidmanager, ToyBoxAntiCC1Pi* anticc1pibox){
  //**************************************************


  EventBoxTracker::RecObjectGroupEnum groupID;
  if      (protonBox.Detector == SubDetId::kFGD1) groupID = EventBoxTracker::kTracksWithGoodQualityTPCInFGD1FV;
  else if (protonBox.Detector == SubDetId::kFGD2) groupID = EventBoxTracker::kTracksWithGoodQualityTPCInFGD2FV;
  else return;


  return BDTPIDUtils::FindGoodQualityTPCProtons(event, protonBox, params, groupID, bdtpidmanager, anticc1pibox);
}


//**************************************************
void BDTPIDUtils::FindGoodQualityTPCProtons(const AnaEventC& event, multipart::MultiParticleBox& protonBox, const multipart::ProtonSelectionParams& params, 
    EventBoxTracker::RecObjectGroupEnum groupID, BDTPIDmanager* bdtpidmanager, ToyBoxAntiCC1Pi* anticc1pibox){
  //**************************************************

  protonBox.nProtonTPCtracks = 0;

  EventBoxB* EventBox = event.EventBoxes[EventBoxId::kEventBoxTracker];

  // Look for protons in positive tracks 
  for(int i = 0; i < EventBox->nRecObjectsInGroup[groupID]; i++ ) {


    AnaTrackB *ptrack = static_cast<AnaTrackB*>(EventBox->RecObjectsInGroup[groupID][i]);

    if (!ptrack) continue;

    if (ptrack->Charge < 1) continue;
    
    // Check whether the BDT PID is valid
    bool valid_for_BDTPID = false;
    TVector3 DirVec = anaUtils::ArrayToTVector3(ptrack->DirectionStart);
    if ((ptrack->Momentum > 200) && (ptrack->Momentum < 1500) && (TMath::ACos(DirVec[2]) < 1.0472) && (bdtpidmanager!=NULL)) {valid_for_BDTPID = true;}

    // Check that at track is not within the reference ones
    bool found = false;
    for (int j = 0; j < params.nRefTracks; j++){
      if (ptrack == params.refTracks[j]){
        found = true;
        break;
      }
    }

    if (found){
      continue;
    }

    if (cutUtils::TPCProtonPIDCut(*ptrack, params.tpcPIDCut)){
      protonBox.ProtonTPCtracks[protonBox.nProtonTPCtracks++] = ptrack;
    }
  }
}
