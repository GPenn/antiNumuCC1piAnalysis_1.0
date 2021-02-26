#include "antiNumuCC1piAnalysis.hxx"
#include "antiNumuCC1piSelection.hxx"

//constructor
//********************************************************************
antiNumuCC1piAnalysis::antiNumuCC1piAnalysis(AnalysisAlgorithm* ana) : baseTrackerAnalysis(ana) {
//********************************************************************

  // Add the package version
  ND::versioning().AddPackage("antiNumuCC1piAnalysis", anaUtils::GetSoftwareVersionFromPath((std::string)getenv("ANTINUMUCC1PIANALYSISROOT")));

  // Create a antiNumuCCAnalysis passing this analysis to the constructor. In that way the same managers are used
  //_antiNumuCCAnalysis = new antiNumuCCAnalysis(this);
  
  // Create a numuCCMultiPiAnalysis passing this analysis to the constructor. In that way the same managers are used
  //_numuCCMultiPiAnalysis = new numuCCMultiPiAnalysis(this);
  
  // Create a antiNumuCCMultiPiAnalysis passing this analysis to the constructor. In that way the same managers are used
  _antiNumuCCMultiPiAnalysis = new antiNumuCCMultiPiAnalysis(this);

  // Use the antiNumuCCAnalysis (in practice that means that the same box and event will be used for the antiNumuCCAnalysis as for this analysis)
  //UseAnalysis(_antiNumuCCAnalysis);
  //UseAnalysis(_numuCCMultiPiAnalysis);
  UseAnalysis(_antiNumuCCMultiPiAnalysis);
}

//********************************************************************
bool antiNumuCC1piAnalysis::Initialize() {
//********************************************************************

  // Initialize the baseAnalysis instead of numuCCAnalysis
  // since we do not want to call and overload numu categories
  if(!baseTrackerAnalysis::Initialize()) return false;

  // Minimum accum level to save event into the output tree
  SetMinAccumCutLevelToSave(ND::params().GetParameterI("antiNumuCC1piAnalysis.MinAccumLevelToSave"));

  // which analysis: FGD1, FGD2 or FGDs
  _whichFGD = ND::params().GetParameterI("antiNumuCC1piAnalysis.Selections.whichFGD");
  if (_whichFGD == 3) {
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "WARNING: only for events with accum_level > 6 the vars in the output microtree will surely refer to the muon candidate in that FGD" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
  }
  
  
  

  // CC-multi-pi or CC-multi-track
   _runMultiTrack = ND::params().GetParameterI("antiNumuCC1piAnalysis.Selections.RunMultiTrack");
  
  // Define antinu categories (different legend from numuCC)
  // for FGD2 same categories with prefix "fgd2", i,e, "fgd2reaction" etc.)
  anaUtils::AddStandardAntiNumuCategories();
  anaUtils::AddStandardAntiNumuCategories("fgd2");
  //TODO: add categories

  // Note to self: figure out how best to integrate this
  //_numuCCMultiPiAnalysis->SetStoreAllTruePrimaryPions((bool)ND::params().GetParameterI("antiNumuCCMultiPiAnalysis.MicroTrees.StoreAllTruePrimaryPions"));
  
  return true;
}

//********************************************************************
void antiNumuCC1piAnalysis::DefineSelections(){
//********************************************************************
  
  // FGD1 antineutrino analysis:
  //if(_whichFGD==1 || _whichFGD==3){
    // ---- Inclusive CC ----
    //if(!_runMultiTrack)
      sel().AddSelection("kTrackerAntiNumuCC1pi",    "antiNumu FGD1 CC 1 Pion selection",  new antiNumuCC1piSelection(false));
    // ---- CC Multi Pion Samples ----
    //else
      //sel().AddSelection("kTrackerAntiNumuCCMultiTrack", "antiNumu FGD1 CC Multiple Track selection", new antiNumuCCMultiTrackSelection(false));
  //}
  // FGD2 antineutrino analysis:
  //if (_whichFGD==2 || _whichFGD==3){
    // ---- CC Inclusive ----
    //if(!_runMultiTrack)
      //sel().AddSelection("kTrackerAntiNumuCCMultiPiFGD2",  "antiNumu FGD2 CC Multiple Pion selection",  new antiNumuCCMultiPiFGD2Selection(false));
    // ---- CC Multi Track Samples ----
    //else
      //sel().AddSelection("kTrackerAntiNumuMultiTrackFGD2", "antiNumu FGD2 CC Multiple Track selection", new antiNumuCCMultiTrackFGD2Selection(false));
  //}

  
}

//********************************************************************
void antiNumuCC1piAnalysis::DefineMicroTrees(bool addBase){
//********************************************************************

  // -------- Add variables to the analysis tree ----------------------

  //if(_runMultiTrack){
    //_antiNumuCCAnalysis->DefineMicroTrees(addBase);
  //}
  //else{
    //_numuCCMultiPiAnalysis->DefineMicroTrees(addBase); 
  //}
  
  _antiNumuCCMultiPiAnalysis->DefineMicroTrees(addBase); 
  
  // --- Muon candidate variables
  
  AddVarF(output(),selmu_tpc_like_mu, "");
  AddVarF(output(),selmu_tpc_like_e, "");
  AddVarF(output(),selmu_tpc_like_p, "");
  AddVarF(output(),selmu_tpc_like_pi, "");
  
  AddVarF(output(),selmu_fgd1_pull_mu, "");
  AddVarF(output(),selmu_fgd1_pull_e, "");
  AddVarF(output(),selmu_fgd1_pull_p, "");
  AddVarF(output(),selmu_fgd1_pull_pi, "");
  AddVarF(output(),selmu_fgd1_pull_no, "");
  
  AddVarF(output(),selmu_fgd2_pull_mu, "");
  AddVarF(output(),selmu_fgd2_pull_e, "");
  AddVarF(output(),selmu_fgd2_pull_p, "");
  AddVarF(output(),selmu_fgd2_pull_pi, "");
  AddVarF(output(),selmu_fgd2_pull_no, "");
  
  // --- Highest-momentum negative track variables
    
  AddVarF(output(),HMNT_mom, "");
  AddVarF(output(),HMNT_costheta, "");
  AddVarI(output(),HMNT_pdg, "");
  AddVarI(output(),HMNT_truepdg, "");
  
  AddVarI(output(),HMNT_NEcalSegments, "");
  AddVarF(output(),HMNT_ecal_EMenergy, "");
  AddVarF(output(),HMNT_ecal_length, "");
  AddVarF(output(),HMNT_ecal_mippion, "");
  AddVarF(output(),HMNT_ecal_angle, "");

  
  baseTrackerAnalysis::AddEffCounters();
  
  
}

//********************************************************************
void antiNumuCC1piAnalysis::DefineTruthTree(){
//********************************************************************

  //if(_runMultiTrack){
    //_antiNumuCCAnalysis->DefineTruthTree();
  //}
  //else{
    //_numuCCMultiPiAnalysis->DefineTruthTree();
  //}
  
  _antiNumuCCMultiPiAnalysis->DefineTruthTree();
}

//********************************************************************
void antiNumuCC1piAnalysis::FillMicroTrees(bool addBase){
//********************************************************************
  
  //if(_runMultiTrack){
    //_antiNumuCCAnalysis->FillMicroTrees(addBase);
  //}
  //else{
   // _numuCCMultiPiAnalysis->FillMicroTrees(addBase); 
  //}
  
  _antiNumuCCMultiPiAnalysis->FillMicroTrees(addBase); 
  
  // Fill muon candidate variables
  if (mybox().MainTrack  ) 
  {
    output().FillVar(selmu_tpc_like_mu,      anaUtils::GetPIDLikelihood( *(mybox().MainTrack),0));
    output().FillVar(selmu_tpc_like_e,       anaUtils::GetPIDLikelihood( *(mybox().MainTrack),1));
    output().FillVar(selmu_tpc_like_p,       anaUtils::GetPIDLikelihood( *(mybox().MainTrack),2));
    output().FillVar(selmu_tpc_like_pi,      anaUtils::GetPIDLikelihood( *(mybox().MainTrack),3));
    
    
  }
  
  // Fill HMNT variables
  if (mybox().HMNtrack  ) 
  {
    output().FillVar(HMNT_mom,      mybox().HMNtrack->Momentum);
    //output().FillVar(HMNT_costheta, mybox().HMNtrack->Costheta);
    if (mybox().HMNtrack->GetTrueParticle()  ) 
    { 
      output().FillVar(HMNT_truepdg, mybox().HMNtrack->GetTrueParticle()->PDG);
    }
    
    output().FillVar(HMNT_NEcalSegments,      mybox().HMNtrack->nECALSegments);
    
    if (mybox().HMNtrack->nECALSegments > 0)
    {
      AnaECALParticle* ECalSeg = static_cast<AnaECALParticle*>( mybox().HMNtrack->ECALSegments[0] );
      
      output().FillVar(HMNT_ecal_EMenergy,      ECalSeg->EMEnergy);
      output().FillVar(HMNT_ecal_length,        ECalSeg->Length);
      output().FillVar(HMNT_ecal_mippion,       ECalSeg->PIDMipPion);
      //output().FillVar(HMNT_ecal_angle,         ECalSeg->PID_Angle);
    }
    
  }

  
  baseTrackerAnalysis::FillEffCounters();
    
}

//********************************************************************
void antiNumuCC1piAnalysis::FillToyVarsInMicroTrees(bool addBase){
//********************************************************************
 
  //if(_runMultiTrack){
    //_antiNumuCCAnalysis->FillToyVarsInMicroTrees(addBase);
  //}
  //else{
    //_numuCCMultiPiAnalysis->FillToyVarsInMicroTrees(addBase); 
  //}
  
  _antiNumuCCMultiPiAnalysis->FillToyVarsInMicroTrees(addBase); 
  
}

//********************************************************************
bool antiNumuCC1piAnalysis::CheckFillTruthTree(const AnaTrueVertex& vtx){
//********************************************************************

  SubDetId::SubDetEnum fgdID;
  if (_whichFGD == 1) fgdID = SubDetId::kFGD1;
  if (_whichFGD == 2) fgdID = SubDetId::kFGD2;
  if (_whichFGD == 3) fgdID = SubDetId::kFGD;

  bool IsAntinu = true;

  // GetReactionCC already takes into account the outFV and also
  // the NuWro reaction code for 2p2h in prod5 (that is 70)
  bool antiNumuCCinFV = (anaUtils::GetReactionCC(vtx, fgdID, IsAntinu) == 1);

  // Since our topology definition doesn't consider the reaction code
  // and since a muon pair can be created in the FSI (likely in DIS)
  // in principle we might have a non-CC vertex categorized as CCother
  // (nevertheless I didn't find any)
  int topo = anaUtils::GetTopology(vtx, fgdID, IsAntinu);
  bool topoCCinFV = (topo == 0 || topo == 1 || topo == 2);

  return (antiNumuCCinFV || topoCCinFV);  
}

//********************************************************************
void antiNumuCC1piAnalysis::FillTruthTree(const AnaTrueVertex& vtx){
//********************************************************************

  //_antiNumuCCAnalysis->FillTruthTree(vtx);
  
  //if (!_runMultiTrack){
    //_numuCCMultiPiAnalysis->FillTruePionInfo(vtx); 
  //}
  
  _antiNumuCCMultiPiAnalysis->FillTruthTree(vtx);
}

//********************************************************************
void antiNumuCC1piAnalysis::FillCategories(){
//********************************************************************

  _antiNumuCCMultiPiAnalysis->FillCategories();

}

