// @(#)root/tmva $Id$
/**********************************************************************************

Macro used for developing particle ID BDT for distinguishing mu+, pi+, protons and positrons.

Takes tree_converter output files as input.

Based on the TMVAClassification example.

**********************************************************************************/

#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <ctime> 

#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"


#if not defined(__CINT__) || defined(__MAKECINT__)
// needs to be included when makecint runs (ACLIC)
#include "TMVA/Factory.h"
#include "TMVA/Tools.h"
#endif

using namespace TMVA;

void BDT_PID_multiclass( TString myMethodList = "" )
{
   
   // This loads the library
   TMVA::Tools::Instance();

   // to get access to the GUI and all tmva macros
   TString thisdir = gSystem->DirName(gInterpreter->GetCurrentMacroName());
   gROOT->SetMacroPath(thisdir + ":" + gROOT->GetMacroPath() + ":$ROOTSYS/tmva/test/");
   gROOT->ProcessLine(".L TMVAMultiClassGui.C");

   std::cout << std::endl;
   std::cout << "==> Start BDT_PID_multiclass" << std::endl;

   // --------------------------------------------------------------------------------------------------

   // --- Here the preparation phase begins

   // Create a ROOT output file where TMVA will store ntuples, histograms, etc.
   TString outfileName( "output/BDT_PID_multiclass.root" );
   TFile* outputFile = TFile::Open( outfileName, "RECREATE" );

   
   TMVA::Factory *factory = new TMVA::Factory( "BDT_PID_multiclass", outputFile,
                                               "!V:!Silent:Color:DrawProgressBar:Transformations=I:AnalysisType=multiclass" );

   // Define the input variables that shall be used for the MVA training
   
   // All original candidate inputs:
   /*
   // Kinematic variables
   factory->AddVariable( "mom := selmu_mom",                               "Momentum",          "MeV/c", 'F' );
   factory->AddVariable( "theta := selmu_theta",                       "Angle",             "rad",   'F' );
   factory->AddVariable( "EMenergy := selmu_ecal_bestseg_EMenergy",        "ECal EM energy",    "MeV",   'F' );
   //factory->AddVariable( "EbyP := selmu_ecal_bestseg_EbyP",                "ECal E/p",          "", 'F' );
   
   // Muon candidate FGD variables
   //factory->AddVariable( "fgd1pullmu := selmu_fgd1_pull_mu",               "FGD1 muon pull",         "", 'F' );
   //factory->AddVariable( "fgd1pullpi := selmu_fgd1_pull_pi",               "FGD1 pion pull",         "", 'F' );
   //factory->AddVariable( "fgd1pullp := selmu_fgd1_pull_p",                 "FGD1 proton pull",       "", 'F' );
   //factory->AddVariable( "fgd1energy := selmu_fgd1_energy",                  "FGD1 energy",            "", 'F' );
   //factory->AddVariable( "fgd1length := selmu_fgd1_length",                  "FGD1 length",            "", 'F' );
   factory->AddVariable( "fgd1EbyL := selmu_fgd1_EbyL",                      "FGD1 E/L",               "", 'F' );
   
   //factory->AddVariable( "fgd2pullmu := selmu_fgd2_pull_mu",               "FGD2 muon pull",         "", 'F' );
   //factory->AddVariable( "fgd2pullpi := selmu_fgd2_pull_pi",               "FGD2 pion pull",         "", 'F' );
   //factory->AddVariable( "fgd2pullp := selmu_fgd2_pull_p",                 "FGD2 proton pull",       "", 'F' );
   //factory->AddVariable( "fgd2energy := selmu_fgd2_energy",                  "FGD2 energy",            "", 'F' );
   //factory->AddVariable( "fgd2length := selmu_fgd2_length",                  "FGD2 length",            "", 'F' );
   factory->AddVariable( "fgd2EbyL := selmu_fgd2_EbyL",                      "FGD2 E/L",               "", 'F' );
   
   // Muon candidate TPC variables
   //factory->AddVariable( "tpclikemu := selmu_tpc_like_mu",                 "TPC2 mu-like",    "", 'F' );
   //factory->AddVariable( "tpclikee := selmu_tpc_like_e",                   "TPC2 e-like",     "", 'F' );
   //factory->AddVariable( "tpclikep := selmu_tpc_like_p",                   "TPC2 p-like",     "", 'F' );
   //factory->AddVariable( "tpclikepi := selmu_tpc_like_pi",                 "TPC2 pi-like",    "", 'F' );
   factory->AddVariable( "tpc2pullmu := selmu_tpc2_pullmu",                  "TPC2 mu pull",    "", 'F' );
   factory->AddVariable( "tpc2pulle := selmu_tpc2_pullele",                  "TPC2 e pull",     "", 'F' );
   factory->AddVariable( "tpc2pullp := selmu_tpc2_pullp",                    "TPC2 p pull",     "", 'F' );
   factory->AddVariable( "tpc2pullpi := selmu_tpc2_pullpi",                  "TPC2 pi pull",    "", 'F' );
   //factory->AddVariable( "tpc2dedx := selmu_tpc2_dedx ",                   "TPC2 dE/dx",    "", 'F' );
   
   //factory->AddVariable( "tpc3dedx := selmu_tpc3_dedx ",                   "TPC3 dE/dx",    "", 'F' );
   //factory->AddVariable( "tpc3pullmu := selmu_tpc3_pullmu",                  "TPC3 mu pull",    "", 'F' );
   //factory->AddVariable( "tpc3pulle := selmu_tpc3_pullele",                  "TPC3 e pull",     "", 'F' );
   //factory->AddVariable( "tpc3pullp := selmu_tpc3_pullp",                    "TPC3 p pull",     "", 'F' );
   //factory->AddVariable( "tpc3pullpi := selmu_tpc3_pullpi",                  "TPC3 pi pull",    "", 'F' );
   factory->AddVariable( "tpc3dedx_gq := selmu_tpc3_dedx_gq ",                   "TPC3 dE/dx (GQ)",    "", 'F' );
   //factory->AddVariable( "tpc3pullmu_gq := selmu_tpc3_pullmu_gq",                  "TPC3 mu pull (GQ)",    "", 'F' );
   //factory->AddVariable( "tpc3pulle_gq := selmu_tpc3_pullele_gq",                  "TPC3 e pull (GQ)",     "", 'F' );
   //factory->AddVariable( "tpc3pullp_gq := selmu_tpc3_pullp_gq",                    "TPC3 p pull (GQ)",     "", 'F' );
   //factory->AddVariable( "tpc3pullpi_gq := selmu_tpc3_pullpi_gq",                  "TPC3 pi pull (GQ)",    "", 'F' );
   factory->AddVariable( "ntpcs := selmu_ntpcs ",                          "TPC segments",    "", 'I' );
   
   // Muon candidate ECal variables
   factory->AddVariable( "ecalEbyL := selmu_ecal_bestseg_EbyL",                "ECal E/L",               "MeV/mm", 'F' );
   //factory->AddVariable( "circularity := selmu_ecal_circularity",          "ECal Circularity",       "", 'F' );
   //factory->AddVariable( "fbr := selmu_ecal_fbr",                          "ECal FBR",               "", 'F' );
   //factory->AddVariable( "tmr := selmu_ecal_tmr",                          "ECal TMR",               "", 'F' );
   //factory->AddVariable( "qrms := selmu_ecal_qrms",                        "ECal QRMS",              "", 'F' );
   factory->AddVariable( "MipEm := selmu_ecal_mipem",                      "ECal MipEm",               "", 'F' );
   factory->AddVariable( "EmHip := selmu_ecal_emhip",                      "ECal EmHip",               "", 'F' );
   factory->AddVariable( "MipPion := selmu_ecal_mippion",                  "ECal MipPion",             "", 'F' );
   
   // Muon candidate SMRD variables
   factory->AddVariable( "nsmrds := selmu_nsmrds",               "SMRD segments",         "", 'I' );
   */
   
   // Tuned list:
   factory->AddVariable( "mom := selmu_mom",                               "Momentum",          "MeV/c", 'F' );
   factory->AddVariable( "theta := selmu_theta",                       "Angle",             "rad",   'F' );
   factory->AddVariable( "fgd1EbyL := selmu_fgd1_EbyL",                      "FGD1 E/L",               "", 'F' );
   factory->AddVariable( "fgd2EbyL := selmu_fgd2_EbyL",                      "FGD2 E/L",               "", 'F' );
   factory->AddVariable( "tpc2pullmu := selmu_tpc2_pullmu",                  "TPC2 mu pull",    "", 'F' );
   factory->AddVariable( "tpc2pulle := selmu_tpc2_pullele",                  "TPC2 e pull",     "", 'F' );
   factory->AddVariable( "tpc2pullp := selmu_tpc2_pullp",                    "TPC2 p pull",     "", 'F' );
   factory->AddVariable( "tpc3dedx_gq := selmu_tpc3_dedx_gq ",                   "TPC3 dE/dx (GQ)",    "", 'F' );
   factory->AddVariable( "ntpcs := selmu_ntpcs ",                          "TPC segments",    "", 'I' );
   factory->AddVariable( "EMenergy := selmu_ecal_bestseg_EMenergy",        "ECal EM energy",    "MeV",   'F' );
   factory->AddVariable( "ecalEbyL := selmu_ecal_bestseg_EbyL",                "ECal E/L",               "MeV/mm", 'F' );
   factory->AddVariable( "circularity := selmu_ecal_circularity",          "ECal Circularity",       "", 'F' );
   factory->AddVariable( "fbr := selmu_ecal_fbr",                          "ECal FBR",               "", 'F' );
   factory->AddVariable( "tmr := selmu_ecal_tmr",                          "ECal TMR",               "", 'F' );
   factory->AddVariable( "qrms := selmu_ecal_qrms",                        "ECal QRMS",              "", 'F' );
   factory->AddVariable( "nsmrds := selmu_nsmrds",               "SMRD segments",         "", 'I' );

   // Read training and test data
   // (it is also possible to use ASCII format as input -> see TMVA Users Guide)
   TString fname_mu = "tree_converter/output/particlegun_antimu.root";
   TString fname_pi = "tree_converter/output/particlegun_piplus.root";
   TString fname_p  = "tree_converter/output/particlegun_proton.root";
   TString fname_e  = "tree_converter/output/particlegun_positron.root";
   
   TFile *input_mu = TFile::Open( fname_mu );
   TFile *input_pi = TFile::Open( fname_pi );
   TFile *input_p  = TFile::Open( fname_p );
   TFile *input_e  = TFile::Open( fname_e );
   
   std::cout << "--- BDT_PID_multiclass       : Using input files: " << std::endl 
      << input_mu->GetName() << std::endl 
      << input_pi->GetName() << std::endl 
      << input_p->GetName() << std::endl 
      << input_e->GetName() << std::endl;
   
   // --- Register the input trees
   
   TTree *inputTree_mu = (TTree*)input_mu->Get("default");
   TTree *inputTree_pi = (TTree*)input_pi->Get("default");
   TTree *inputTree_p  = (TTree*)input_p->Get("default");
   TTree *inputTree_e  = (TTree*)input_e->Get("default");
   
   gROOT->cd( outfileName+TString(":/") );
   factory->AddTree    (inputTree_mu,"Muon");
   factory->AddTree    (inputTree_pi,"Pion");
   factory->AddTree    (inputTree_p, "Proton");
   factory->AddTree    (inputTree_e, "Electron");
   
   //Event-by-event weighting:
   factory->SetWeightExpression("selmu_mom_weight", "Muon");
   factory->SetWeightExpression("selmu_mom_weight", "Pion");
   factory->SetWeightExpression("selmu_mom_weight", "Proton");
   factory->SetWeightExpression("selmu_mom_weight", "Electron");
   
   /*Double_t desiredsamplesize = 50000;
   Double_t weight_mu = inputTree_mu->GetEntries() / desiredsamplesize;
   Double_t weight_pi = inputTree_pi->GetEntries() / desiredsamplesize;
   Double_t weight_p  = inputTree_p->GetEntries() / desiredsamplesize;
   Double_t weight_e  = inputTree_e->GetEntries() / desiredsamplesize;*/
   
   // Optional cut to require an ECal segment
   TCut ecalsegcut = "selmu_necals==1";
   
   factory->PrepareTrainingAndTestTree( "", "SplitMode=Random:NormMode=EqualNumEvents:!V" );

   
   
   // ---- Book MVA methods
   
   // Tuned parameters:
   factory->BookMethod( TMVA::Types::kBDT, "BDTG_tuned", "!H:!V:NTrees=1500:BoostType=Grad:Shrinkage=1.0:nCuts=2000:MaxDepth=4");
   
   // Old parameter setups for reference:
   
   //factory->BookMethod( TMVA::Types::kBDT, "BDT-Gini-grid20",
                           //"!H:!V:NTrees=800:MinNodeSize=5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.6:SeparationType=GiniIndex:nCuts=20" );
   //factory->BookMethod( TMVA::Types::kBDT, "BDT-Gini-grid100",
                           //"!H:!V:NTrees=1000:MinNodeSize=5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.6:SeparationType=GiniIndex:nCuts=100" );
   //factory->BookMethod( TMVA::Types::kBDT, "BDT-Gini-nogrid",
   //                        "!H:!V:NTrees=800:MinNodeSize=5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.6:SeparationType=GiniIndex:nCuts=-1" );
   //factory->BookMethod( TMVA::Types::kBDT, "BDT-StatSig",
   //                        "!H:!V:NTrees=800:MinNodeSize=5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.6:SeparationType=SDivSqrtSPlusB:nCuts=20" );
   
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_tree2", "!H:!V:NTrees=1000:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.50:nCuts=2000:MaxDepth=2");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_tree3", "!H:!V:NTrees=1000:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.50:nCuts=2000:MaxDepth=3");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_tree4", "!H:!V:NTrees=1000:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.50:nCuts=2000:MaxDepth=4");
   
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_500trees", "!H:!V:NTrees=500:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.50:nCuts=2000:MaxDepth=3");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_1000trees", "!H:!V:NTrees=1000:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.50:nCuts=2000:MaxDepth=3");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_1500trees", "!H:!V:NTrees=1500:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.50:nCuts=2000:MaxDepth=3");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_2000trees", "!H:!V:NTrees=2000:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.50:nCuts=2000:MaxDepth=3");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_2500trees", "!H:!V:NTrees=2500:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.50:nCuts=2000:MaxDepth=3");
   
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_shrinkage0.1", "!H:!V:NTrees=2500:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.50:nCuts=2000:MaxDepth=3");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_shrinkage0.2", "!H:!V:NTrees=2500:BoostType=Grad:Shrinkage=0.20:UseBaggedBoost:BaggedSampleFraction=0.50:nCuts=2000:MaxDepth=3");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_shrinkage0.3", "!H:!V:NTrees=2500:BoostType=Grad:Shrinkage=0.30:UseBaggedBoost:BaggedSampleFraction=0.50:nCuts=2000:MaxDepth=3");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_shrinkage0.4", "!H:!V:NTrees=2500:BoostType=Grad:Shrinkage=0.40:UseBaggedBoost:BaggedSampleFraction=0.50:nCuts=2000:MaxDepth=3");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_shrinkage0.5", "!H:!V:NTrees=2500:BoostType=Grad:Shrinkage=0.50:UseBaggedBoost:BaggedSampleFraction=0.50:nCuts=2000:MaxDepth=3");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_shrinkage0.6", "!H:!V:NTrees=2500:BoostType=Grad:Shrinkage=0.60:UseBaggedBoost:BaggedSampleFraction=0.50:nCuts=2000:MaxDepth=3");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_shrinkage0.8", "!H:!V:NTrees=2500:BoostType=Grad:Shrinkage=0.80:UseBaggedBoost:BaggedSampleFraction=0.50:nCuts=2000:MaxDepth=3");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_shrinkage1.0", "!H:!V:NTrees=2500:BoostType=Grad:Shrinkage=1.00:UseBaggedBoost:BaggedSampleFraction=0.50:nCuts=2000:MaxDepth=3");
   
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_tree2", "!H:!V:NTrees=1000:BoostType=Grad:Shrinkage=1.0:nCuts=2000:MaxDepth=2");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_tree3", "!H:!V:NTrees=1000:BoostType=Grad:Shrinkage=1.0:nCuts=2000:MaxDepth=3");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_tree4", "!H:!V:NTrees=1000:BoostType=Grad:Shrinkage=1.0:nCuts=2000:MaxDepth=4");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_tree5", "!H:!V:NTrees=1000:BoostType=Grad:Shrinkage=1.0:nCuts=2000:MaxDepth=5");
   
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_500trees", "!H:!V:NTrees=500:BoostType=Grad:Shrinkage=1.0:nCuts=2000:MaxDepth=4");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_1000trees", "!H:!V:NTrees=1000:BoostType=Grad:Shrinkage=1.0:nCuts=2000:MaxDepth=4");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_1500trees", "!H:!V:NTrees=1500:BoostType=Grad:Shrinkage=1.0:nCuts=2000:MaxDepth=4");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_2000trees", "!H:!V:NTrees=2000:BoostType=Grad:Shrinkage=1.0:nCuts=2000:MaxDepth=4");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_2500trees", "!H:!V:NTrees=2500:BoostType=Grad:Shrinkage=1.0:nCuts=2000:MaxDepth=4");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_750trees", "!H:!V:NTrees=750:BoostType=Grad:Shrinkage=1.0:nCuts=2000:MaxDepth=4");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_1100trees", "!H:!V:NTrees=1100:BoostType=Grad:Shrinkage=1.0:nCuts=2000:MaxDepth=4");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_1200trees", "!H:!V:NTrees=1200:BoostType=Grad:Shrinkage=1.0:nCuts=2000:MaxDepth=4");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_1300trees", "!H:!V:NTrees=1300:BoostType=Grad:Shrinkage=1.0:nCuts=2000:MaxDepth=4");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_1400trees", "!H:!V:NTrees=1400:BoostType=Grad:Shrinkage=1.0:nCuts=2000:MaxDepth=4");
   
   /*factory->BookMethod( TMVA::Types::kBDT, "BDTG_0.9shrinkage", "!H:!V:NTrees=1500:BoostType=Grad:Shrinkage=0.9:nCuts=2000:MaxDepth=4");
   factory->BookMethod( TMVA::Types::kBDT, "BDTG_0.7shrinkage", "!H:!V:NTrees=1500:BoostType=Grad:Shrinkage=0.7:nCuts=2000:MaxDepth=4");
   factory->BookMethod( TMVA::Types::kBDT, "BDTG_0.5shrinkage", "!H:!V:NTrees=1500:BoostType=Grad:Shrinkage=0.5:nCuts=2000:MaxDepth=4");
   factory->BookMethod( TMVA::Types::kBDT, "BDTG_0.3shrinkage", "!H:!V:NTrees=1500:BoostType=Grad:Shrinkage=0.3:nCuts=2000:MaxDepth=4");
   factory->BookMethod( TMVA::Types::kBDT, "BDTG_0.1shrinkage", "!H:!V:NTrees=1500:BoostType=Grad:Shrinkage=0.1:nCuts=2000:MaxDepth=4");
   
   factory->BookMethod( TMVA::Types::kBDT, "BDTG_0.9bagged", "!H:!V:NTrees=1500:BoostType=Grad:Shrinkage=1.0:UseBaggedBoost:BaggedSampleFraction=0.90:nCuts=2000:MaxDepth=4");
   factory->BookMethod( TMVA::Types::kBDT, "BDTG_0.7bagged", "!H:!V:NTrees=1500:BoostType=Grad:Shrinkage=1.0:UseBaggedBoost:BaggedSampleFraction=0.70:nCuts=2000:MaxDepth=4");
   factory->BookMethod( TMVA::Types::kBDT, "BDTG_0.5bagged", "!H:!V:NTrees=1500:BoostType=Grad:Shrinkage=1.0:UseBaggedBoost:BaggedSampleFraction=0.50:nCuts=2000:MaxDepth=4");
   factory->BookMethod( TMVA::Types::kBDT, "BDTG_0.3bagged", "!H:!V:NTrees=1500:BoostType=Grad:Shrinkage=1.0:UseBaggedBoost:BaggedSampleFraction=0.30:nCuts=2000:MaxDepth=4");
   factory->BookMethod( TMVA::Types::kBDT, "BDTG_0.1bagged", "!H:!V:NTrees=1500:BoostType=Grad:Shrinkage=1.0:UseBaggedBoost:BaggedSampleFraction=0.10:nCuts=2000:MaxDepth=4");
   
   factory->BookMethod( TMVA::Types::kBDT, "BDTG_2vars", "!H:!V:NTrees=1500:BoostType=Grad:Shrinkage=1.0:UseRandomisedTrees:UseNvars=2:nCuts=2000:MaxDepth=4");
   factory->BookMethod( TMVA::Types::kBDT, "BDTG_3vars", "!H:!V:NTrees=1500:BoostType=Grad:Shrinkage=1.0:UseRandomisedTrees:UseNvars=3:nCuts=2000:MaxDepth=4");
   factory->BookMethod( TMVA::Types::kBDT, "BDTG_4vars", "!H:!V:NTrees=1500:BoostType=Grad:Shrinkage=1.0:UseRandomisedTrees:UseNvars=4:nCuts=2000:MaxDepth=4");
   factory->BookMethod( TMVA::Types::kBDT, "BDTG_6vars", "!H:!V:NTrees=1500:BoostType=Grad:Shrinkage=1.0:UseRandomisedTrees:UseNvars=6:nCuts=2000:MaxDepth=4");
   factory->BookMethod( TMVA::Types::kBDT, "BDTG_8vars", "!H:!V:NTrees=1500:BoostType=Grad:Shrinkage=1.0:UseRandomisedTrees:UseNvars=8:nCuts=2000:MaxDepth=4");
   factory->BookMethod( TMVA::Types::kBDT, "BDTG_10vars", "!H:!V:NTrees=1500:BoostType=Grad:Shrinkage=1.0:UseRandomisedTrees:UseNvars=10:nCuts=2000:MaxDepth=4");
   factory->BookMethod( TMVA::Types::kBDT, "BDTG_12vars", "!H:!V:NTrees=1500:BoostType=Grad:Shrinkage=1.0:UseRandomisedTrees:UseNvars=12:nCuts=2000:MaxDepth=4");*/
   
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_default",     "!H:!V:NTrees=1000:BoostType=Grad:Shrinkage=1.0:nCuts=2000:MaxDepth=3");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_tunedparams", "!H:!V:NTrees=2000:BoostType=Grad:Shrinkage=0.1:nCuts=2000:MaxDepth=4:UseBaggedBoost:BaggedSampleFraction=0.70:UseRandomisedTrees:UseNvars=10");
   
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_tpcpulls", "!H:!V:NTrees=2000:BoostType=Grad:Shrinkage=0.1:nCuts=2000:MaxDepth=4:UseBaggedBoost:BaggedSampleFraction=0.70:UseRandomisedTrees:UseNvars=10");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_tpcdedx", "!H:!V:NTrees=2000:BoostType=Grad:Shrinkage=0.1:nCuts=2000:MaxDepth=4:UseBaggedBoost:BaggedSampleFraction=0.70:UseRandomisedTrees:UseNvars=10");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_ecallowlevel", "!H:!V:NTrees=2000:BoostType=Grad:Shrinkage=0.1:nCuts=2000:MaxDepth=4:UseBaggedBoost:BaggedSampleFraction=0.70:UseRandomisedTrees:UseNvars=10");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_ecalEbyP", "!H:!V:NTrees=2000:BoostType=Grad:Shrinkage=0.1:nCuts=2000:MaxDepth=4:UseBaggedBoost:BaggedSampleFraction=0.70:UseRandomisedTrees:UseNvars=10");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_tpc3pullmu", "!H:!V:NTrees=2000:BoostType=Grad:Shrinkage=0.1:nCuts=2000:MaxDepth=4:UseBaggedBoost:BaggedSampleFraction=0.70:UseRandomisedTrees:UseNvars=10");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_ntpcs", "!H:!V:NTrees=2000:BoostType=Grad:Shrinkage=0.1:nCuts=2000:MaxDepth=4:UseBaggedBoost:BaggedSampleFraction=0.70:UseRandomisedTrees:UseNvars=10");
   
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_tunedparams2", "!H:!V:NTrees=2000:BoostType=Grad:Shrinkage=0.1:nCuts=2000:MaxDepth=4:UseBaggedBoost:BaggedSampleFraction=0.70:UseRandomisedTrees:UseNvars=10");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_minus_nsmrds", "!H:!V:NTrees=2000:BoostType=Grad:Shrinkage=0.1:nCuts=2000:MaxDepth=4:UseBaggedBoost:BaggedSampleFraction=0.70:UseRandomisedTrees:UseNvars=10");
   
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_tunedparams", "!H:!V:NTrees=1500:BoostType=Grad:Shrinkage=1.0:nCuts=2000:MaxDepth=4");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_ecalhighlevel", "!H:!V:NTrees=1500:BoostType=Grad:Shrinkage=1.0:nCuts=2000:MaxDepth=4");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_tunedvars", "!H:!V:NTrees=1500:BoostType=Grad:Shrinkage=1.0:nCuts=2000:MaxDepth=4");
   //factory->BookMethod( TMVA::Types::kBDT, "BDTG_tunedvars_noweights", "!H:!V:NTrees=1500:BoostType=Grad:Shrinkage=1.0:nCuts=2000:MaxDepth=4");
   

   // Train MVAs using the set of training events
   factory->TrainAllMethods();

   // ---- Evaluate all MVAs using the set of test events
   factory->TestAllMethods();

   // ----- Evaluate and compare performance of all configured MVAs
   factory->EvaluateAllMethods();

   // --------------------------------------------------------------
   
   // Save the output
   outputFile->Close();

   std::cout << "==> Wrote root file: " << outputFile->GetName() << std::endl;
   std::cout << "==> BDT_PID_multiclass is done!" << std::endl;
   
   delete factory;
   
   // Launch the GUI for the root macros
   if (!gROOT->IsBatch()) TMVAMultiClassGui( outfileName );
}
