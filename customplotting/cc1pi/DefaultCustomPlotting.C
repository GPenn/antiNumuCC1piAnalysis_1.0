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
   
   Int_t recomom_nbins = 25;
   
   Int_t optimisation_nbins = 50;
   
   TH1F *opt_mulike_sig = new TH1F("opt_mulike_sig", "Mu-like (true antimu)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_mulike_bkg = new TH1F("opt_mulike_bkg", "Mu-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   
   TH1F *opt_pilike_sig = new TH1F("opt_pilike_sig", "Pi-like (true pi-)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_pilike_bkg = new TH1F("opt_pilike_bkg", "Pi-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   
   TH1F *debug_hmnt_pdg = new TH1F("debug_hmnt_pdg", "Pi-like (true pi-)", 1000, -1000, 0);
   TH1F *debug_hmnt_pid = new TH1F("debug_hmnt_pid", "Pi-like (true pi-)", optimisation_nbins, 0.0, 1.0);


   
   
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      fChain->GetEntry(jentry);

      // Cut on accum_level etc
      if (accum_level[0][0] <= 4) continue; // Set accum_level
      
      
      
      
      // ============= Fill histograms to find optimal cuts =============
      
      if (accum_level[0][1] > 7){
         
         if (particle == -13)
         {
            opt_mulike_sig->Fill(selmu_bdt_pid_mu_cc1pi);
         }
         else
         {
            opt_mulike_bkg->Fill(selmu_bdt_pid_mu_cc1pi);
         }
         
         if (HMNT_truepdg == -211)
         {
            opt_pilike_sig->Fill(hmnt_bdt_pid_pi_cc1pi);
         }
         else
         {
            opt_pilike_bkg->Fill(hmnt_bdt_pid_pi_cc1pi);
         }
         
         debug_hmnt_pdg->Fill(HMNT_truepdg);
         debug_hmnt_pid->Fill(hmnt_bdt_pid_pi_cc1pi);

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
   
   std::cout << std::endl << std::endl;
   
   
   
   
   
   
   
   
   // ============= Find optimal cuts =============
   
   std::cout << "=========== Muon candidate mu-like optimisation ===========" << std::endl << std::endl;
   
   std::cout << "DEBUG: Total sig " << opt_mulike_sig->GetEntries() << ", total bkg " << opt_mulike_bkg->GetEntries() << std::endl;
   
   Float_t optimal_signif_mu = 0;
   Float_t optimal_cut_mu = 0;
   Float_t optimal_pur_mu = 0;
   Float_t optimal_eff_mu = 0;
   
   TCanvas* canvas_opt_mu_cc1pi = new TCanvas("opt_mulike","Optimisation signifiance curve (mu-like)",200,10,500,300);
   TGraph* graph_opt_mu = new TGraph();
   graph_opt_mu->SetTitle(" ;Cut on BDT mu-like output;Antimuon selection significance;");
   TGraph* graph_opt_pur_mu = new TGraph();
   graph_opt_pur_mu->SetTitle(" ;Cut on BDT mu-like output; ;");
   TGraph* graph_opt_eff_mu = new TGraph();
   TGraph* graph_opt_effpur_mu = new TGraph();
   
   for (Int_t cut=1; cut <= optimisation_nbins; cut++)
   {
      Float_t passed_sig = opt_mulike_sig->Integral(cut,optimisation_nbins);
      Float_t passed_bkg = opt_mulike_bkg->Integral(cut,optimisation_nbins);
      
      Float_t significance = passed_sig/sqrt(passed_sig + passed_bkg);
      Float_t purity = passed_sig/(passed_sig+passed_bkg);
      Float_t efficiency = passed_sig/(opt_mulike_sig->GetEntries());
      if (passed_sig == 0){significance = 0; purity = 0;}
      
      if (significance > optimal_signif_mu)
      {
         optimal_signif_mu = significance;
         optimal_cut_mu = opt_mulike_sig->GetBinLowEdge(cut);
         optimal_pur_mu = purity;
         optimal_eff_mu = efficiency;
      }
      
      //std::cout << "DEBUG: Cut #" << cut << " at " << opt_mulike_sig->GetBinLowEdge(cut) 
      //          << " has " << passed_sig << " sig, " << passed_bkg <<" bgk -> significance = " << significance << std::endl;
      
      graph_opt_mu->SetPoint(cut, opt_mulike_sig->GetBinLowEdge(cut), significance);
      graph_opt_pur_mu->SetPoint(cut, opt_mulike_sig->GetBinLowEdge(cut), purity);
      graph_opt_eff_mu->SetPoint(cut, opt_mulike_sig->GetBinLowEdge(cut), efficiency);
      graph_opt_effpur_mu->SetPoint(cut, opt_mulike_sig->GetBinLowEdge(cut), efficiency*purity);
     
   }
   
   std::cout << "Optimal significance = " << optimal_signif_mu << " at cut value of " << optimal_cut_mu << std::endl;
   std::cout << "Efficiency = " << optimal_eff_mu  << ", purity = " << optimal_pur_mu << ", eff*pur = " << optimal_eff_mu*optimal_pur_mu << std::endl;
   
   graph_opt_mu->Draw("AC*");
   canvas_opt_mu_cc1pi->Write();
   TCanvas* canvas_effpur_mu_cc1pi = new TCanvas("effpur_mulike","Optimisation efficiency and purity curves (mu-like)",200,10,500,300);
   graph_opt_pur_mu->Draw("AC*");
   graph_opt_eff_mu->Draw("C* same");
   graph_opt_effpur_mu->Draw("C* same");
   canvas_effpur_mu_cc1pi->Write();
   
   
   
   std::cout << "=========== Pion candidate pi-like optimisation ===========" << std::endl << std::endl;
   
   std::cout << "DEBUG: Total sig " << opt_pilike_sig->GetEntries() << ", total bkg " << opt_pilike_bkg->GetEntries() << std::endl;
   
   Float_t optimal_signif_pi = 0;
   Float_t optimal_cut_pi = 0;
   Float_t optimal_pur_pi = 0;
   Float_t optimal_eff_pi = 0;
   
   TCanvas* canvas_opt_pi_cc1pi = new TCanvas("opt_pilike","Optimisation signifiance curve (pi-like)",200,10,500,300);
   TGraph* graph_opt_pi = new TGraph();
   graph_opt_pi->SetTitle(" ;Cut on BDT pi-like output;Pi- selection significance;");
   TGraph* graph_opt_pur_pi = new TGraph();
   graph_opt_pur_pi->SetTitle(" ;Cut on BDT pi-like output; ;");
   TGraph* graph_opt_eff_pi = new TGraph();
   TGraph* graph_opt_effpur_pi = new TGraph();
   
   for (Int_t cut=1; cut <= optimisation_nbins; cut++)
   {
      Float_t passed_sig = opt_pilike_sig->Integral(cut,optimisation_nbins);
      Float_t passed_bkg = opt_pilike_bkg->Integral(cut,optimisation_nbins);
      
      Float_t significance = passed_sig/sqrt(passed_sig + passed_bkg);
      Float_t purity = passed_sig/(passed_sig+passed_bkg);
      Float_t efficiency = passed_sig/(opt_pilike_sig->GetEntries());
      if (passed_sig == 0){significance = 0; purity = 0;}
      
      if (significance > optimal_signif_pi)
      {
         optimal_signif_pi = significance;
         optimal_cut_pi = opt_mulike_sig->GetBinLowEdge(cut);
         optimal_pur_pi = purity;
         optimal_eff_pi = efficiency;
      }
      
      //std::cout << "DEBUG: Cut #" << cut << " at " << opt_mulike_sig->GetBinLowEdge(cut) 
      //          << " has " << passed_sig << " sig, " << passed_bkg <<" bgk -> significance = " << significance << std::endl;
      
      graph_opt_pi->SetPoint(cut, opt_pilike_sig->GetBinLowEdge(cut), significance);
      graph_opt_pur_pi->SetPoint(cut, opt_pilike_sig->GetBinLowEdge(cut), purity);
      graph_opt_eff_pi->SetPoint(cut, opt_pilike_sig->GetBinLowEdge(cut), efficiency);
      graph_opt_effpur_pi->SetPoint(cut, opt_pilike_sig->GetBinLowEdge(cut), efficiency*purity);
     
   }
   
   std::cout << "Optimal significance = " << optimal_signif_pi << " at cut value of " << optimal_cut_pi << std::endl;
   std::cout << "Efficiency = " << optimal_eff_pi  << ", purity = " << optimal_pur_pi << ", eff*pur = " << optimal_eff_pi*optimal_pur_pi << std::endl;
   
   graph_opt_pi->Draw("AC*");
   canvas_opt_pi_cc1pi->Write();
   TCanvas* canvas_effpur_pi_cc1pi = new TCanvas("effpur_pilike","Optimisation efficiency and purity curves (pi-like)",200,10,500,300);
   graph_opt_pur_pi->Draw("AC*");
   graph_opt_eff_pi->Draw("C* same");
   graph_opt_effpur_pi->Draw("C* same");
   canvas_effpur_pi_cc1pi->Write();
   
   
   debug_hmnt_pdg->Write();
   debug_hmnt_pid->Write();
      
      
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
