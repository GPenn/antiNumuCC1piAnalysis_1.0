#define DefaultCustomPlotting_cxx
#include "DefaultCustomPlotting.h"
#include <TH2.h>
#include <TGraph.h>
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
   
   Int_t counter_all_accum8 = 0, counter_all_accum7 = 0;
   Int_t counter_selmu_antimu = 0, counter_selmu_piplus = 0, counter_selmu_proton = 0, counter_selmu_positron = 0, counter_selmu_mu = 0, counter_selmu_piminus = 0;
   
   
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      fChain->GetEntry(jentry);

      // Cut on accum_level etc
      if (accum_level[0][0] <= 4) continue; // Set accum_level
      
      if (accum_level[0][1] > 7){
         
         counter_all_accum7++;
      }
      
      if (accum_level[0][1] > 8){
         
         counter_all_accum8++;
         
         if (particle == -13)
         {
            counter_selmu_antimu++;
         }
         
         if (particle == 13)
         {
            counter_selmu_mu++;
         }
         
         if (particle == 211)
         {
            counter_selmu_piplus++;
         }
         
         if (particle == -211)
         {
            counter_selmu_piminus++;
         }
         
         if (particle == 2212)
         {
            counter_selmu_proton++;
         }
         
         if (particle == -11)
         {
            counter_selmu_positron++;
         }
         
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
   
   std::cout << std::endl;
   
   std::cout << std::endl << "Events above accum_level 7: " << counter_all_accum7 << std::endl;
   
   std::cout << std::endl << "Events above accum_level 8: " << counter_all_accum8 << std::endl;
   
   std::cout << std::endl << "Antimu candidate true antimu: " << counter_selmu_antimu << " (" << 100*counter_selmu_antimu/counter_all_accum8 << "\%)" std::endl;
   
   std::cout << std::endl << "Antimu candidate true mu: " << counter_selmu_mu << " (" << 100*counter_selmu_mu/counter_all_accum8 << "\%)" std::endl;
   
   std::cout << std::endl << "Antimu candidate true piplus: " << counter_selmu_piplus << " (" << 100*counter_selmu_piplus/counter_all_accum8 << "\%)" std::endl;
   
   std::cout << std::endl << "Antimu candidate true piminus: " << counter_selmu_piminus << " (" << 100*counter_selmu_piminus/counter_all_accum8 << "\%)" std::endl;
   
   std::cout << std::endl << "Antimu candidate true protons: " << counter_selmu_proton << " (" << 100*counter_selmu_proton/counter_all_accum8 << "\%)" std::endl;
   
   std::cout << std::endl << "Antimu candidate true positrons: " << counter_selmu_positron << " (" << 100*counter_selmu_positron/counter_all_accum8 << "\%)" std::endl;
      
   std::cout << std::endl << "All entries processed. Writing output file...\n\n";
   
   defout->Write();
   
}

int main(int argc, char* argv[]) {

  std::string outFileName;

  // Check for command line options
  for (;;) {
    int c = getopt(argc, argv, "o:");
    if (c<0) break;
    switch (c) {
    case 'o':
      outFileName = optarg;
      break;
    }
  } // Closes process options for loop 
  
  // Test for further command line arguments after options
  if (argc<=optind) {
    std::cout << "ERROR: No input file(s)" << std::endl << std::endl;
    return 1;
  }

  // Create file TChain
  TChain* rootFiles = new TChain("default");
  std::cout<<"Number of files to read  = "<<argc-optind<<std::endl;

  std::vector<std::string> files;
  for(int i=optind; i<argc; i++){
    char* f = argv[i];
    files.push_back(f);
    std::cout<<files[i-optind]<<std::endl;
  }
  
  for(std::vector<std::string>::const_iterator f = files.begin(); f != files.end(); ++f){
    // Add files to TChain
    rootFiles->Add(f->c_str());
    std::cout<<"Adding file "<<f->c_str()<<std::endl;
  }
  
  DefaultCustomPlotting *deftree = new DefaultCustomPlotting(rootFiles, outFileName);
  
  deftree->Loop();

  return 0;
}

defaultOut::defaultOut(std::string outname) {
  
  fOutFile = new TFile(outname.c_str(), "RECREATE");
  fOutFile->cd();
  
  // ----------- Output tree -----------
   
  fDefaultOut = new TTree("default", "");

  return;
}

Float_t DefaultCustomPlotting::GetOptSignificanceValues(TH1F* hist_sig, TH1F* hist_bkg, Int_t nbins) {
   
   Float_t optimal_signif = 0;
   Float_t optimal_cut = 0;
   Float_t optimal_pur = 0;
   Float_t optimal_eff = 0;
   
   for (Int_t cut=1; cut <= nbins; cut++)
   {
      Float_t passed_sig = hist_sig->Integral(cut,nbins);
      Float_t passed_bkg = hist_bkg->Integral(cut,nbins);
      
      Float_t significance = passed_sig/sqrt(passed_sig + passed_bkg);
      Float_t purity = passed_sig/(passed_sig+passed_bkg);
      Float_t efficiency = passed_sig/(hist_sig->GetEntries());
      if (passed_sig == 0){significance = 0; purity = 0;}
      
      if (significance > optimal_signif)
      {
         optimal_signif = significance;
         optimal_cut = hist_sig->GetBinLowEdge(cut);
         optimal_pur = purity;
         optimal_eff = efficiency;
      }
      
      //std::cout << "DEBUG: Cut #" << cut << " at " << hist->GetBinLowEdge(cut) 
      //          << " has " << passed_sig << " sig, " << passed_bkg <<" bgk -> significance = " << significance << std::endl;
     
   }
   
   return optimal_signif;
}
