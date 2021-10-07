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

#ifndef antiNumuBDTTestingAnalysis_h
#define antiNumuBDTTestingAnalysis_h

#include "TMVA/Tools.h"
#include "TMVA/Reader.h"

#include "antiNumuCCMultiPiAnalysis.hxx"
#include "antiNumuCC1piAnalysis.hxx"
#include "antiNumuBDTTestingSelection.hxx"
#include "NuDirUtils.hxx"

class antiNumuBDTTestingAnalysis: public baseTrackerAnalysis {
 public:
  antiNumuBDTTestingAnalysis(AnalysisAlgorithm* ana=NULL);
  virtual ~antiNumuBDTTestingAnalysis(){}
 
  TMVA::Reader* tmvareader_ana;
  Float_t bdt_mom, bdt_theta;
  Float_t bdt_ecal_EMenergy, bdt_ecal_EbyP, bdt_ecal_EbyL, bdt_ecal_circularity, bdt_ecal_fbr, bdt_ecal_tmr, bdt_ecal_qrms;
  Float_t bdt_tpc_like_mu, bdt_tpc_like_e, bdt_tpc_like_p, bdt_tpc_like_pi;
  Float_t bdt_fgd1pullmu, bdt_fgd1pullp, bdt_fgd1pullpi, bdt_fgd2pullmu, bdt_fgd2pullp, bdt_fgd2pullpi;
 
  void ResetBDTInputVariables();

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
 
  //Copied from numuCCPi0Analysis (necessary to get local event info):
  virtual AnaEventC* MakeEvent(){
    const AnaLocalReconBunch* localBunch = dynamic_cast<const AnaLocalReconBunch*>(&GetBunch());
    if (localBunch)
      return new AnaLocalReconEvent(*static_cast<const AnaSpill*>(&GetSpill()),*localBunch);
    else{
      std::cerr<<"Invalid local event, did you enable UseReconDirTrackerECal = 1 in highlandIO.parameters.dat?\n";
      exit(1);
    }
  }

 
  const ToyBoxAntiCC1Pi& mybox(){return *static_cast<const ToyBoxAntiCC1Pi*>(&box());}

protected:
  
  //antiNumuCCAnalysis*    _antiNumuCCAnalysis;
  //numuCCMultiPiAnalysis* _numuCCMultiPiAnalysis;
 antiNumuCC1PiAnalysis* _antiNumuCC1PiAnalysis;

private:
  Int_t _whichFGD; // 1 for FGD1 analysis, 2 for FGD2, 3 for both
  
  bool _runMultiTrack;  // = true to run the selection for the CC mutli-track analysis 
  
};

#endif
