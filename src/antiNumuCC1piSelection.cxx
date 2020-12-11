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
  CopySteps(_antiNumuCCMultiPiSelection);

  // Set the branch aliases to the three branches
  SetBranchAlias(0,"CC-0pi",  0);
  SetBranchAlias(1,"CC-1pi",  1);
  SetBranchAlias(2,"CC-Other",2);

  // By default the preselection correspond to cuts 0-2
  SetPreSelectionAccumLevel(2);

  // Step and Cut numbers needed by CheckRedoSelection
  _MuonPIDCutIndex     = GetCutNumber("muon PID");
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
