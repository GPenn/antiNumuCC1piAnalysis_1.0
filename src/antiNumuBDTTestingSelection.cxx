#include "antiNumuBDTTestingSelection.hxx"
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
antiNumuBDTTestingSelection::antiNumuBDTTestingSelection(bool forceBreak, InputManager* INPUT) : 
  SelectionBase(forceBreak,EventBoxId::kEventBoxTracker), _input(INPUT) {
  //********************************************************************
  //_antiNumuCCSelection.Initialize();
  //_numuCCMultiPiSelection.Initialize(); 
  _antiNumuCC1piSelection.Initialize(); 
  //_useECalPiZeroInfo = (bool)ND::params().GetParameterI("psycheSelections.antinumuCCMultiPi.UseECalPiZeroInfo");
  //_numuCCMultiPiSelection.SetUseECalPiZeroInfo(_useECalPiZeroInfo);
    
  BDTPIDmanager_sel = new BDTPIDmanager();
}

//********************************************************************
void antiNumuBDTTestingSelection::DefineSteps(){
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
  //AddStep(StepBase::kCut,    "pos_mult",           new PositiveMultiplicityCut());  
  AddStep(StepBase::kAction, "find veto track",    new FindVetoTrackAction());
  AddStep(StepBase::kCut,    "veto",               new ExternalVetoCut());
  AddStep(StepBase::kAction, "find oofv track",    new FindOOFVTrackAction());
  AddStep(StepBase::kCut,    "External FGD1",      new ExternalFGD1lastlayersCut());
  
  AddStep(StepBase::kCut,    "Main track kinematics for BDT",      new BDTPreselectionKinematicsCut());
  
  AddStep(StepBase::kAction, "GetAllTECALReconObjects",            new GetAllTECALReconObjectsAction(_input)); // GetAllTECALReconObjects from the AnaLocalReconBunch
  AddStep(StepBase::kAction, "MatchECalGlobalToLocalObjects",      new MatchECalGlobalToLocalObjectsAction ()); // Match to local reconstruction
  
  //AddStep(StepBase::kCut,    "Antimu PID loop",      new AntiMuonPIDCut_Loop());
  //AddStep(StepBase::kCut,    "Antimu PID",         new AntiMuonPIDCut());
  
  AddStep(StepBase::kAction, "find_pions",                new FindPionsAction_antinuCCMultiPi());
  AddStep(StepBase::kAction, "find_protons",              new FindProtonsAction());
  AddStep(StepBase::kAction, "fill_summary antinu_pion",  new FillSummaryAction_antinuCCMultiPi());
  
  AddSplit(5);
  
  // Mu-like branch
  AddStep(0, StepBase::kCut,    "BDT mu-like PID",      new BDTPIDMuLikeCut(BDTPIDmanager_sel));
  
  // Pi-like branch
  AddStep(1, StepBase::kCut,    "BDT pi-like PID",      new BDTPIDPiLikeCut(BDTPIDmanager_sel));
  
  // Proton-like branch
  AddStep(2, StepBase::kCut,    "BDT p-like PID",       new BDTPIDProtonLikeCut(BDTPIDmanager_sel));
  
  // Electron-like branch
  AddStep(3, StepBase::kCut,    "BDT e-like PID",       new BDTPIDElectronLikeCut(BDTPIDmanager_sel));
  
  // CC1pi branch
  AddStep(4, StepBase::kCut,    "HMNT kinematics for BDT",      new BDTPreselectionKinematicsPiCandCut());
  AddStep(4, StepBase::kCut,    "1pos1neg TPC tracks",          new TwoTrack1pos1negCut());

  // Set the branch aliases to the branches
  SetBranchAlias(0, "Antimuon",  0);
  SetBranchAlias(1, "Pi+",       1);
  SetBranchAlias(2, "Proton",    2);
  SetBranchAlias(3, "Electron",  3);
  SetBranchAlias(4, "CC1pi",     4);

  // By default the preselection correspond to cuts 0-2
  SetPreSelectionAccumLevel(0);

  // Step and Cut numbers needed by CheckRedoSelection
  //_MuonPIDCutIndex     = GetCutNumber("Antimu PID loop");
  _FindPionsStepIndex  = GetStepNumber("find_pions");

}

//********************************************************************
void antiNumuBDTTestingSelection::DefineDetectorFV(){
  //********************************************************************

  // The detector in which the selection is applied
  SetDetectorFV(SubDetId::kFGD1);
  
}

//********************************************************************
bool antiNumuBDTTestingSelection::FillEventSummary(AnaEventC& event, Int_t allCutsPassed[]){
  //********************************************************************

  //taken from numuCCMultiPi
  //CC0pi
  /*if(allCutsPassed[0]){
    static_cast<AnaEventSummaryB*>(event.Summary)->EventSample = SampleId::kFGD1AntiNuMuCC0Pi;
  }  
  //CC1pi
  else if (allCutsPassed[1]){
    static_cast<AnaEventSummaryB*>(event.Summary)->EventSample = SampleId::kFGD1AntiNuMuCC1Pi;
  }
  //CCOther
  else if (allCutsPassed[2]){
    static_cast<AnaEventSummaryB*>(event.Summary)->EventSample = SampleId::kFGD1AntiNuMuCCOther;
  }*/

  // otherwise kUnassigned is used from the EventSummary constructor
  return (static_cast<AnaEventSummaryB*>(event.Summary)->EventSample != SampleId::kUnassigned);
}


//**************************************************
bool antiNumuBDTTestingSelection::IsRelevantRecObjectForSystematic(const AnaEventC& event, AnaRecObjectC* track, SystId_h systId, Int_t branch) const{
  //**************************************************

  return _antiNumuCC1piSelection.IsRelevantRecObjectForSystematic(event,track,systId,branch);
}

//**************************************************
bool antiNumuBDTTestingSelection::IsRelevantTrueObjectForSystematic(const AnaEventC& event, AnaTrueObjectC* trueTrack, SystId_h systId, Int_t branch) const{
  //**************************************************

  return _antiNumuCC1piSelection.IsRelevantTrueObjectForSystematic(event,trueTrack,systId,branch);
}

//**************************************************
bool antiNumuBDTTestingSelection::IsRelevantRecObjectForSystematicInToy(const AnaEventC& event, const ToyBoxB& box, AnaRecObjectC* track, SystId_h systId, Int_t branch) const{
  //**************************************************
  
  return _antiNumuCC1piSelection.IsRelevantRecObjectForSystematicInToy(event,box,track,systId,branch);
  
}


//**************************************************
bool  antiNumuBDTTestingSelection::IsRelevantTrueObjectForSystematicInToy(const AnaEventC& event, const ToyBoxB& box, AnaTrueObjectC* trueObj, SystId_h systId, Int_t branch) const{
  //**************************************************
  
  return _antiNumuCC1piSelection.IsRelevantTrueObjectForSystematicInToy(event,box,trueObj,systId,branch);
  
}

//**************************************************
bool antiNumuBDTTestingSelection::IsRelevantSystematic(const AnaEventC& event, const ToyBoxB& box, SystId_h systId, Int_t branch) const{
  //**************************************************

  return _antiNumuCC1piSelection.IsRelevantSystematic(event, box, systId, branch);
}

//**************************************************
Int_t antiNumuBDTTestingSelection::GetRelevantRecObjectGroupsForSystematic(SystId_h systId, Int_t* IDs, Int_t branch) const{
//**************************************************

  return _antiNumuCC1piSelection.GetRelevantRecObjectGroupsForSystematic(systId, IDs, branch);
}

//**************************************************
Int_t antiNumuBDTTestingSelection::GetRelevantTrueObjectGroupsForSystematic(SystId_h systId, Int_t* IDs, Int_t branch) const{
//**************************************************

  return _antiNumuCC1piSelection.GetRelevantTrueObjectGroupsForSystematic(systId, IDs, branch);
}

//**************************************************
void antiNumuBDTTestingSelection::InitializeEvent(AnaEventC& eventC){
  //**************************************************
  
  AnaEventB& event = *static_cast<AnaEventB*>(&eventC); 
  
  //_antiNumuCCSelection.InitializeEvent(event); 
  _antiNumuCC1piSelection.InitializeEvent(event); 

}

//********************************************************************
bool antiNumuBDTTestingSelection::CheckRedoSelection(const AnaEventC& event, const ToyBoxB& PreviousToyBox, Int_t& redoFromStep){
  //********************************************************************

  // Must redo selection if antiNumuCCSelection decides so
  if( _antiNumuCC1piSelection.CheckRedoSelection(event,PreviousToyBox,redoFromStep)) return true;

  // Otherwise selection should not be redone since the number of tracks with TPC and FGD will not be changed by systematics
  return false;
}




// ------------ CUTS ------------

//**************************************************
bool BDTPIDMuLikeCut::Apply(AnaEventC& event, ToyBoxB& boxB) const{
  //**************************************************

  (void)event;
  
  Float_t mulike_cutvalue = 0.621;

  // Cast the ToyBox to the appropriate type
  ToyBoxAntiCC1Pi& box = *static_cast<ToyBoxAntiCC1Pi*>(&boxB);
  
  // Waive cut if muon candidate track has no ECal segments
  //if (!box.MainTrack) return true;
  
  std::vector<Float_t> pidvars = _bdtpidmanager->GetBDTPIDVars(box.MainTrack, box.MainTrackLocalECalSegment);
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
  
  std::vector<Float_t> pidvars = _bdtpidmanager->GetBDTPIDVars(box.MainTrack, box.MainTrackLocalECalSegment);
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
  
  std::vector<Float_t> pidvars = _bdtpidmanager->GetBDTPIDVars(box.MainTrack, box.MainTrackLocalECalSegment);
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
  
  std::vector<Float_t> pidvars = _bdtpidmanager->GetBDTPIDVars(box.MainTrack, box.MainTrackLocalECalSegment);
  Float_t elike_bdtvalue = pidvars[3];

  if (elike_bdtvalue > elike_cutvalue) return true;

  return false;
}

//**************************************************
bool BDTPreselectionKinematicsCut::Apply(AnaEventC& event, ToyBoxB& boxB) const{
  //**************************************************

  (void)event;

  // Cast the ToyBox to the appropriate type
  ToyBoxTracker& box = *static_cast<ToyBoxTracker*>(&boxB); 

  if (box.MainTrack->Momentum < 200.0) return false;
  if (box.MainTrack->Momentum > 1500.0) return false;
  
  TVector3 DirVec = anaUtils::ArrayToTVector3(box.MainTrack->DirectionStart);
  if (TMath::ACos(DirVec[2]) > 1.0472) return false;

  return true;
}

//**************************************************
bool BDTPreselectionKinematicsPiCandCut::Apply(AnaEventC& event, ToyBoxB& boxB) const{
  //**************************************************

  (void)event;

  // Cast the ToyBox to the appropriate type
  ToyBoxTracker& box = *static_cast<ToyBoxTracker*>(&boxB); 

  if (box.HMNtrack->Momentum < 200.0) return false;
  if (box.HMNtrack->Momentum > 1500.0) return false;
  
  TVector3 DirVec = anaUtils::ArrayToTVector3(box.HMNtrack->DirectionStart);
  if (TMath::ACos(DirVec[2]) > 1.0472) return false;

  return true;
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

