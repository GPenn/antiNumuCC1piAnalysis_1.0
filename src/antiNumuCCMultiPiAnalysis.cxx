#include "antiNumuCCMultiPiAnalysis.hxx"
#include "antiNumuCCMultiPiSelection.hxx"
#include "antiNumuCCMultiPiFGD2Selection.hxx"
#include "antiNumuCCMultiTrackSelection.hxx"
#include "antiNumuCCMultiTrackFGD2Selection.hxx"

//constructor
//********************************************************************
antiNumuCCMultiPiAnalysis::antiNumuCCMultiPiAnalysis(AnalysisAlgorithm* ana) : baseTrackerAnalysis(ana) {
//********************************************************************

  // Add the package version
  ND::versioning().AddPackage("antiNumuCCMultiPiAnalysis", anaUtils::GetSoftwareVersionFromPath((std::string)getenv("ANTINUMUCCMULTIPIANALYSISROOT")));

  // Create a antiNumuCCAnalysis passing this analysis to the constructor. In that way the same managers are used
  _antiNumuCCAnalysis = new antiNumuCCAnalysis(this);
  
  // Create a numuCCMultiPiAnalysis passing this analysis to the constructor. In that way the same managers are used
  _numuCCMultiPiAnalysis = new numuCCMultiPiAnalysis(this);

  // Use the antiNumuCCAnalysis (in practice that means that the same box and event will be used for the antiNumuCCAnalysis as for this analysis)
  UseAnalysis(_antiNumuCCAnalysis);
  UseAnalysis(_numuCCMultiPiAnalysis);
}

//********************************************************************
bool antiNumuCCMultiPiAnalysis::Initialize() {
//********************************************************************

  // Initialize the baseAnalysis instead of numuCCAnalysis
  // since we do not want to call and overload numu categories
  if(!baseTrackerAnalysis::Initialize()) return false;

  // Minimum accum level to save event into the output tree
  SetMinAccumCutLevelToSave(ND::params().GetParameterI("antiNumuCCMultiPiAnalysis.MinAccumLevelToSave"));

  // which analysis: FGD1, FGD2 or FGDs
  _whichFGD = ND::params().GetParameterI("antiNumuCCMultiPiAnalysis.Selections.whichFGD");
  if (_whichFGD == 3) {
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "WARNING: only for events with accum_level > 6 the vars in the output microtree will surely refer to the muon candidate in that FGD" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
  }
  
  
  

  // CC-multi-pi or CC-multi-track
   _runMultiTrack = ND::params().GetParameterI("antiNumuCCMultiPiAnalysis.Selections.RunMultiTrack");
  
  // Define antinu categories (different legend from numuCC)
  // for FGD2 same categories with prefix "fgd2", i,e, "fgd2reaction" etc.)
  anaUtils::AddStandardAntiNumuCategories();
  anaUtils::AddStandardAntiNumuCategories("fgd2");
  //TODO: add categories

  _numuCCMultiPiAnalysis->SetStoreAllTruePrimaryPions((bool)ND::params().GetParameterI("antiNumuCCMultiPiAnalysis.MicroTrees.StoreAllTruePrimaryPions"));
  
  return true;
}

//********************************************************************
void antiNumuCCMultiPiAnalysis::DefineSelections(){
//********************************************************************
  
  // FGD1 antineutrino analysis:
  if(_whichFGD==1 || _whichFGD==3){
    // ---- Inclusive CC ----
    if(!_runMultiTrack)
      sel().AddSelection("kTrackerAntiNumuCCMultiPi",    "antiNumu FGD1 CC Multiple Pion selection",  new antiNumuCCMultiPiSelection(false));
    // ---- CC Multi Pion Samples ----
    else
      sel().AddSelection("kTrackerAntiNumuCCMultiTrack", "antiNumu FGD1 CC Multiple Track selection", new antiNumuCCMultiTrackSelection(false));
  }
  // FGD2 antineutrino analysis:
  if (_whichFGD==2 || _whichFGD==3){
    // ---- CC Inclusive ----
    if(!_runMultiTrack)
      sel().AddSelection("kTrackerAntiNumuCCMultiPiFGD2",  "antiNumu FGD2 CC Multiple Pion selection",  new antiNumuCCMultiPiFGD2Selection(false));
    // ---- CC Multi Track Samples ----
    else
      sel().AddSelection("kTrackerAntiNumuMultiTrackFGD2", "antiNumu FGD2 CC Multiple Track selection", new antiNumuCCMultiTrackFGD2Selection(false));
  }

  
}

//********************************************************************
void antiNumuCCMultiPiAnalysis::DefineMicroTrees(bool addBase){
//********************************************************************

  // -------- Add variables to the analysis tree ----------------------

  if(_runMultiTrack){
    _antiNumuCCAnalysis->DefineMicroTrees(addBase);
  }
  else{
    _numuCCMultiPiAnalysis->DefineMicroTrees(addBase); 
  }
  
  baseTrackerAnalysis::AddEffCounters();
  
  
}

//********************************************************************
void antiNumuCCMultiPiAnalysis::DefineTruthTree(){
//********************************************************************

  if(_runMultiTrack){
    _antiNumuCCAnalysis->DefineTruthTree();
  }
  else{
    _numuCCMultiPiAnalysis->DefineTruthTree();
  }
}

//********************************************************************
void antiNumuCCMultiPiAnalysis::FillMicroTrees(bool addBase){
//********************************************************************
  
  if(_runMultiTrack){
    _antiNumuCCAnalysis->FillMicroTrees(addBase);
  }
  else{
    _numuCCMultiPiAnalysis->FillMicroTrees(addBase); 
  }
  
  baseTrackerAnalysis::FillEffCounters();
  
}

//********************************************************************
void antiNumuCCMultiPiAnalysis::FillToyVarsInMicroTrees(bool addBase){
//********************************************************************
 
  if(_runMultiTrack){
    _antiNumuCCAnalysis->FillToyVarsInMicroTrees(addBase);
  }
  else{
    _numuCCMultiPiAnalysis->FillToyVarsInMicroTrees(addBase); 
  }
  
}

//********************************************************************
bool antiNumuCCMultiPiAnalysis::CheckFillTruthTree(const AnaTrueVertex& vtx){
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
void antiNumuCCMultiPiAnalysis::FillTruthTree(const AnaTrueVertex& vtx){
//********************************************************************

  _antiNumuCCAnalysis->FillTruthTree(vtx);
  
  if (!_runMultiTrack){
    _numuCCMultiPiAnalysis->FillTruePionInfo(vtx); 
  }
}

//********************************************************************
void antiNumuCCMultiPiAnalysis::FillCategories(){
//********************************************************************

  _antiNumuCCAnalysis->FillCategories();

}

