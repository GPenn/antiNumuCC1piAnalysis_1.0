#define DefaultCustomPlotting_cxx
#include "DefaultCustomPlotting.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <ctime> 

void DefaultCustomPlotting::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L DefaultCustomPlotting.C
//      Root > DefaultCustomPlotting t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntries();
   
   std::cout << "Total entries to process: " << nentries << std::endl << std::endl;
   
   std::time_t time_start = std::time(0);
   
   Int_t nAntimu = 0;
   Int_t nPiplus = 0;
   Int_t nProton = 0;
   Int_t nPositron = 0;

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      fChain->GetEntry(jentry);

      // Cut on accum_level etc
      if (accum_level[0][0] <= 4) continue; // Set accum_level
      
      if (accum_level[0][0] > 6){
         
         if (particle_pg == -13) nAntimu++;
         if (particle_pg == 211) nPiplus++;
         if (particle_pg == 2212) nProton++;
         if (particle_pg == -11) nPositron++;
      }
      
      // Code to keep track of completion percentage and estimate time remaining:
         
      Double_t completion = (Double_t)jentry/(Double_t)nentries;
         
      std::time_t time_now = std::time(0);
      std::time_t time_sofar = time_now - time_start;
         
      Long64_t time_total_guess = time_sofar / completion;
      Long64_t time_left_guess = time_total_guess - time_sofar;
            
      if (time_sofar >= 2) {
         std::cout << "Converted " << jentry << " of " << nentries << " entries (" << (Int_t)(completion*100) << "\%). " 
                   << "Time elapsed: " << time_sofar << "s. "
                   << "Estimated time remaining: " << time_left_guess << "s. \r";
      }
   }
   
   std::cout << "True antimu in antimu selection: " << nAntimu << std::endl;
   std::cout << "True piplus in antimu selection: " << nPiplus << std::endl;
   std::cout << "True protons in antimu selection: " << nProton << std::endl;
   std::cout << "True positrons in antimu selection: " << nPositron << std::endl;
   std::cout << "Total signal: " << nAntimu << std::endl;
   Int_t antimuBkg = nPiplus + nProton + nPositron;
   std::cout << "Total background: " << antimuBkg << std::endl;
   Float_t significance = nAntimu/sqrt(nAntimu+antimuBkg);
   std::cout << "Significance: " << significance << std::endl;
   
}
