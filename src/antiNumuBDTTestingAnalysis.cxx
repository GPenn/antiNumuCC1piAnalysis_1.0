#include "antiNumuBDTTestingAnalysis.hxx"
#include "antiNumuBDTTestingSelection.hxx"

//constructor
//********************************************************************
antiNumuBDTTestingAnalysis::antiNumuBDTTestingAnalysis(AnalysisAlgorithm* ana) : baseTrackerAnalysis(ana) {
//********************************************************************

  // Add the package version
  ND::versioning().AddPackage("antiNumuCC1piAnalysis", anaUtils::GetSoftwareVersionFromPath((std::string)getenv("ANTINUMUCC1PIANALYSISROOT")));

  // Create a antiNumuCCAnalysis passing this analysis to the constructor. In that way the same managers are used
  //_antiNumuCCAnalysis = new antiNumuCCAnalysis(this);
  
  // Create a numuCCMultiPiAnalysis passing this analysis to the constructor. In that way the same managers are used
  //_numuCCMultiPiAnalysis = new numuCCMultiPiAnalysis(this);
  
  // Create a antiNumuCCMultiPiAnalysis passing this analysis to the constructor. In that way the same managers are used
  //_antiNumuCCMultiPiAnalysis = new antiNumuCCMultiPiAnalysis(this);

  _antiNumuCC1piAnalysis = new antiNumuCC1piAnalysis(this);
  
  // Use the antiNumuCCAnalysis (in practice that means that the same box and event will be used for the antiNumuCCAnalysis as for this analysis)
  //UseAnalysis(_antiNumuCCAnalysis);
  //UseAnalysis(_numuCCMultiPiAnalysis);
  UseAnalysis(_antiNumuCC1piAnalysis);
}

//********************************************************************
bool antiNumuBDTTestingAnalysis::Initialize() {
//********************************************************************

  // Initialize the baseAnalysis instead of numuCCAnalysis
  // since we do not want to call and overload numu categories
  if(!baseTrackerAnalysis::Initialize()) return false;

  // Minimum accum level to save event into the output tree
  SetMinAccumCutLevelToSave(4);

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
  
  myBDTPIDmanager = new BDTPIDmanager();
  
  return true;
}

//********************************************************************
void antiNumuBDTTestingAnalysis::DefineSelections(){
//********************************************************************
  
  // FGD1 antineutrino analysis:
  //if(_whichFGD==1 || _whichFGD==3){
    // ---- Inclusive CC ----
    //if(!_runMultiTrack)
      sel().AddSelection("kTrackerAntiNumuBDTTesting",    "antiNumu FGD1 BDT testing",  new antiNumuBDTTestingSelection(false, &(input())));
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
void antiNumuBDTTestingAnalysis::DefineMicroTrees(bool addBase){
//********************************************************************

  // -------- Add variables to the analysis tree ----------------------

  //if(_runMultiTrack){
    //_antiNumuCCAnalysis->DefineMicroTrees(addBase);
  //}
  //else{
    //_numuCCMultiPiAnalysis->DefineMicroTrees(addBase); 
  //}
  
  _antiNumuCC1piAnalysis->DefineMicroTrees(addBase); 
  
  AddVarF(output(),selmu_bdt_pid_mu, "");
  AddVarF(output(),selmu_bdt_pid_pi, "");
  AddVarF(output(),selmu_bdt_pid_p, "");
  AddVarF(output(),selmu_bdt_pid_e, "");
  
  AddVarI(output(), particle_pg, "particle gun compatible main track PDG");
  
  AddVarF(output(),hmnt_bdt_pid_mu, "");
  AddVarF(output(),hmnt_bdt_pid_pi, "");
  AddVarF(output(),hmnt_bdt_pid_p, "");
  AddVarF(output(),hmnt_bdt_pid_e, "");
  
  baseTrackerAnalysis::AddEffCounters();
  
  
}

//********************************************************************
void antiNumuBDTTestingAnalysis::DefineTruthTree(){
//********************************************************************

  //if(_runMultiTrack){
    //_antiNumuCCAnalysis->DefineTruthTree();
  //}
  //else{
    //_numuCCMultiPiAnalysis->DefineTruthTree();
  //}
  
  _antiNumuCC1piAnalysis->DefineTruthTree();
  
  AddVarI(output(), particle_pg, "particle gun compatible main track PDG");
  AddVarF(output(), pg_trueparticle_mom, "particle gun true particle momentum");
  AddVarF(output(), pg_trueparticle_costheta, "particle gun true particle costheta");
}

//********************************************************************
void antiNumuBDTTestingAnalysis::FillMicroTrees(bool addBase){
//********************************************************************
  
  //if(_runMultiTrack){
    //_antiNumuCCAnalysis->FillMicroTrees(addBase);
  //}
  //else{
   // _numuCCMultiPiAnalysis->FillMicroTrees(addBase); 
  //}
  
  _antiNumuCC1piAnalysis->FillMicroTrees(addBase); 
  
  if (mybox().MainTrack  ) 
  {
    std::vector<Float_t> BDT_PID_results = myBDTPIDmanager->GetBDTPIDVars(mybox().MainTrack, mybox().MainTrackLocalECalSegment);
    
    output().FillVar(selmu_bdt_pid_mu, BDT_PID_results[0]);
    output().FillVar(selmu_bdt_pid_pi, BDT_PID_results[1]);
    output().FillVar(selmu_bdt_pid_p, BDT_PID_results[2]);
    output().FillVar(selmu_bdt_pid_e, BDT_PID_results[3]);
    
    output().FillVar(particle_pg, mybox().MainTrack->GetTrueParticle()->PDG);
    
    if (mybox().HMNtrack)
    {
      BDT_PID_results = myBDTPIDmanager->GetBDTPIDVars(mybox().HMNtrack, mybox().HMNTLocalECalSegment);
    
      output().FillVar(hmnt_bdt_pid_mu, BDT_PID_results[0]);
      output().FillVar(hmnt_bdt_pid_pi, BDT_PID_results[1]);
      output().FillVar(hmnt_bdt_pid_p, BDT_PID_results[2]);
      output().FillVar(hmnt_bdt_pid_e, BDT_PID_results[3]);
    }
  }
  
  baseTrackerAnalysis::FillEffCounters();
    
}

//********************************************************************
void antiNumuBDTTestingAnalysis::FillToyVarsInMicroTrees(bool addBase){
//********************************************************************
 
  //if(_runMultiTrack){
    //_antiNumuCCAnalysis->FillToyVarsInMicroTrees(addBase);
  //}
  //else{
    //_numuCCMultiPiAnalysis->FillToyVarsInMicroTrees(addBase); 
  //}
  
  _antiNumuCC1piAnalysis->FillToyVarsInMicroTrees(addBase); 
  
}

//********************************************************************
bool antiNumuBDTTestingAnalysis::CheckFillTruthTree(const AnaTrueVertex& vtx){
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
  
  // When using particle gun input I want to save truth info for all events:
  bool particleGunMode = true;

  return (antiNumuCCinFV || topoCCinFV || particleGunMode);  
}

//********************************************************************
void antiNumuBDTTestingAnalysis::FillTruthTree(const AnaTrueVertex& vtx){
//********************************************************************

  //_antiNumuCCAnalysis->FillTruthTree(vtx);
  
  //if (!_runMultiTrack){
    //_numuCCMultiPiAnalysis->FillTruePionInfo(vtx); 
  //}
  
  _antiNumuCC1piAnalysis->FillTruthTree(vtx);
  
  output().FillVar(particle_pg, vtx.TrueParticles[0]->PDG);
  
  TVector3 muDirVec = anaUtils::ArrayToTVector3(vtx.TrueParticles[0]->Direction);
  Float_t muDirCostheta = muDirVec[2];
  
  output().FillVar(pg_trueparticle_mom, vtx.TrueParticles[0]->Momentum);
  output().FillVar(pg_trueparticle_costheta, muDirCostheta);
  
}

//********************************************************************
void antiNumuBDTTestingAnalysis::FillCategories(){
//********************************************************************

  _antiNumuCC1piAnalysis->FillCategories();

}
