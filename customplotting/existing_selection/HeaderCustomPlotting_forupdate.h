//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Feb 24 14:19:14 2022 by ROOT version 5.34/34
// from TTree header/1
// found on file: ../../output/existing_selection/run5/oaAnalysis_prod6Trun5_1.root
//////////////////////////////////////////////////////////

#ifndef HeaderCustomPlotting_forupdate_h
#define HeaderCustomPlotting_forupdate_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "/user/gpenn/nd280software/nd280release_12.31/psycheCore_3.45/inc/Header.hxx"

// Fixed size dimensions of array or collections stored in the TTree if any.

class HeaderCustomPlotting_forupdate {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Header          *POTInfo_v2;

   // List of branches
   TBranch        *b_POTInfo_v2;   //!

   HeaderCustomPlotting_forupdate(TTree *tree=0);
   virtual ~HeaderCustomPlotting_forupdate();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef HeaderCustomPlotting_forupdate_cxx
HeaderCustomPlotting_forupdate::HeaderCustomPlotting_forupdate(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("../../output/existing_selection/run5/oaAnalysis_prod6Trun5_1.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("../../output/existing_selection/run5/oaAnalysis_prod6Trun5_1.root");
      }
      f->GetObject("header",tree);

   }
   Init(tree);
}

HeaderCustomPlotting_forupdate::~HeaderCustomPlotting_forupdate()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t HeaderCustomPlotting_forupdate::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t HeaderCustomPlotting_forupdate::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void HeaderCustomPlotting_forupdate::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   POTInfo_v2 = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("POTInfo_v2", &POTInfo_v2, &b_POTInfo_v2);
   Notify();
}

Bool_t HeaderCustomPlotting_forupdate::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void HeaderCustomPlotting_forupdate::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t HeaderCustomPlotting_forupdate::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef HeaderCustomPlotting_forupdate_cxx
