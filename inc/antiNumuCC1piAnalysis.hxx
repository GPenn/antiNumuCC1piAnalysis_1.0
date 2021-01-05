/*********************************
 * antiNumuCCMultiPiAnalysis - selection of CC antineutrino interactions
 * and dividing them into three categories: 0Pi, 1Pi, Other
 * Author: Pawel Przewlocki, pawel.przewlocki@ncbj.gov.pl
 * Analysis details in technote TN-273.
 * We basically tag a positive muon and count the number of Pi- 
 * by looking at TPC tracks, Michel electrons
 * in FGD and isolated tracks in FGD.
 * Two selections used
 * 1. antiNumuCCMultiPiSelection and antiNumuCCMultiPiFGD2Selection
 * 2. antiNumuCCMultiTrackSelection and antiNumuCCMultiTrackFGD2Selection.
 **************************************/

#ifndef antiNumuCC1piAnalysis_h
#define antiNumuCC1piAnalysis_h

#include "antiNumuCCMultiPiAnalysis.hxx"

class antiNumuCC1piAnalysis: public baseTrackerAnalysis {
 public:
  antiNumuCC1piAnalysis(AnalysisAlgorithm* ana=NULL);
  virtual ~antiNumuCC1piAnalysis(){}

  //---- These are mandatory functions
  void DefineSelections();
  void DefineCorrections(){_antiNumuCCMultiPiAnalysis->DefineCorrections();}
  void DefineMicroTrees(bool addBase=true);
  void DefineTruthTree();

  void FillMicroTrees(bool addBase=true);
  void FillToyVarsInMicroTrees(bool addBase=true);

  bool CheckFillTruthTree(const AnaTrueVertex& vtx);

  using baseTrackerAnalysis::FillTruthTree;
  void FillTruthTree(const AnaTrueVertex& vtx);
  //--------------------

  bool Initialize();
  void FillCategories();
 
  const ToyBoxCCMultiPi& mybox(){return *static_cast<const ToyBoxCCMultiPi*>(&box());}

protected:
  
  //antiNumuCCAnalysis*    _antiNumuCCAnalysis;
  //numuCCMultiPiAnalysis* _numuCCMultiPiAnalysis;
 antiNumuCCMultiPiAnalysis* _antiNumuCCMultiPiAnalysis;

private:
  Int_t _whichFGD; // 1 for FGD1 analysis, 2 for FGD2, 3 for both
  
  bool _runMultiTrack;  // = true to run the selection for the CC mutli-track analysis 
  
};

#endif
