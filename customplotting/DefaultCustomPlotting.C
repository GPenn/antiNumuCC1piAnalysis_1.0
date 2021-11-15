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
   
   Int_t musel_nAntimu = 0;
   Int_t musel_nPiplus = 0;
   Int_t musel_nProton = 0;
   Int_t musel_nPositron = 0;
   
   Int_t pisel_nAntimu = 0;
   Int_t pisel_nPiplus = 0;
   Int_t pisel_nProton = 0;
   Int_t pisel_nPositron = 0;
   
   Int_t psel_nAntimu = 0;
   Int_t psel_nPiplus = 0;
   Int_t psel_nProton = 0;
   Int_t psel_nPositron = 0;
   
   Int_t esel_nAntimu = 0;
   Int_t esel_nPiplus = 0;
   Int_t esel_nProton = 0;
   Int_t esel_nPositron = 0;
   
   Int_t optimisation_nbins = 50;
   
   TH1F *opt_mulike_sig = new TH1F("opt_amu_mulike", "Mu-like (true antimu)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_mulike_bkg = new TH1F("opt_mulike_bkg", "Mu-like (backgrounds)", optimisation_nbins, 0.0, 1.0);

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      fChain->GetEntry(jentry);

      // Cut on accum_level etc
      if (accum_level[0][0] <= 4) continue; // Set accum_level
      
      // ============= Fill histogram to find optimal cuts =============
      
      if (accum_level[0][0] > 5){
         
         if (particle_pg == -13)
         {
            opt_mulike_sig->Fill(selmu_bdt_pid_mu);
         }
         else
         {
            opt_mulike_bkg->Fill(selmu_bdt_pid_mu);
         }
         
      }
      
      // ============= Fill variables to test existing cuts =============
      
      if (accum_level[0][0] > 6){
         
         if (particle_pg == -13) musel_nAntimu++;
         if (particle_pg == 211) musel_nPiplus++;
         if (particle_pg == 2212) musel_nProton++;
         if (particle_pg == -11) musel_nPositron++;
      }
      
      if (accum_level[0][1] > 6){
         
         if (particle_pg == -13) pisel_nAntimu++;
         if (particle_pg == 211) pisel_nPiplus++;
         if (particle_pg == 2212) pisel_nProton++;
         if (particle_pg == -11) pisel_nPositron++;
      }
      
      if (accum_level[0][2] > 6){
         
         if (particle_pg == -13) psel_nAntimu++;
         if (particle_pg == 211) psel_nPiplus++;
         if (particle_pg == 2212) psel_nProton++;
         if (particle_pg == -11) psel_nPositron++;
      }
      
      if (accum_level[0][3] > 6){
         
         if (particle_pg == -13) esel_nAntimu++;
         if (particle_pg == 211) esel_nPiplus++;
         if (particle_pg == 2212) esel_nProton++;
         if (particle_pg == -11) esel_nPositron++;
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
   
   //std::cout << "DEBUG: Total sig " << opt_mulike_sig->GetEntries() << ", total bkg " << opt_mulike_bkg->GetEntries() << std::endl;
   
   Float_t optimal_signif = 0;
   Float_t optimal_cut = 0;
   
   TCanvas *c1 = new TCanvas("c1","Significance",200,10,500,300);
   TGraph* gr = new TGraph();
   
   for (Int_t cut=1; cut <= optimisation_nbins; cut++)
   {
      Int_t passed_sig = opt_mulike_sig->Integral(cut,optimisation_nbins);
      Int_t passed_bkg = opt_mulike_bkg->Integral(cut,optimisation_nbins);
      
      Float_t significance = passed_sig/sqrt(passed_sig + passed_bkg);
      
      if (significance > optimal_signif)
      {
         optimal_signif = significance;
         optimal_cut = opt_mulike_sig->GetBinLowEdge(cut);
      }
      
      //std::cout << "DEBUG: Cut #" << cut << " at " << opt_mulike_sig->GetBinLowEdge(cut) 
      //          << " has " << passed_sig << " sig, " << passed_bkg <<" bgk -> significance = " << significance << std::endl;
      
      gr->SetPoint(cut, opt_mulike_sig->GetBinLowEdge(cut), significance);
     
   }
   
   std::cout << "Optimal significance = " << optimal_signif << " at cut value of " << optimal_cut << std::endl;
   
   
   gr->Draw("AC*");
   c1->Write();
   
   // ============= Test existing cuts =============
   
   std::cout << std::endl << std::endl;
   
   std::cout << "=========== Mu-like selection ===========" << std::endl << std::endl;
   
   std::cout << "True antimu:      " << musel_nAntimu << std::endl;
   std::cout << "True piplus:      " << musel_nPiplus << std::endl;
   std::cout << "True protons:     " << musel_nProton << std::endl;
   std::cout << "True positrons:   " << musel_nPositron << std::endl;
   Int_t musel_Sig = musel_nAntimu;
   std::cout << "Total signal:     " << musel_Sig << std::endl;
   Int_t musel_Bkg = musel_nPiplus + musel_nProton + musel_nPositron;
   std::cout << "Total background: " << musel_Bkg << std::endl;
   Float_t musel_SsqrtSB = musel_Sig/sqrt(musel_Sig+musel_Bkg);
   std::cout << "Purity:           " << musel_Sig/(musel_Sig+musel_Bkg) << std::endl;
   std::cout << "Significance:     " << musel_SsqrtSB << std::endl;
   
   std::cout << std::endl << std::endl;
   
   std::cout << "=========== Pi-like selection ===========" << std::endl << std::endl;
   
   std::cout << "True antimu:      " << pisel_nAntimu << std::endl;
   std::cout << "True piplus:      " << pisel_nPiplus << std::endl;
   std::cout << "True protons:     " << pisel_nProton << std::endl;
   std::cout << "True positrons:   " << pisel_nPositron << std::endl;
   Int_t pisel_Sig = pisel_nPiplus;
   std::cout << "Total signal:     " << pisel_Sig << std::endl;
   Int_t pisel_Bkg = pisel_nAntimu + pisel_nProton + pisel_nPositron;
   std::cout << "Total background: " << pisel_Bkg << std::endl;
   Float_t pisel_SsqrtSB = pisel_Sig/sqrt(pisel_Sig+pisel_Bkg);
   std::cout << "Purity:           " << pisel_Sig/(pisel_Sig+pisel_Bkg) << std::endl;
   std::cout << "Significance:     " << pisel_SsqrtSB << std::endl;
   
   std::cout << std::endl << std::endl;
   
   std::cout << "=========== Proton-like selection ===========" << std::endl << std::endl;
   
   std::cout << "True antimu:      " << psel_nAntimu << std::endl;
   std::cout << "True piplus:      " << psel_nPiplus << std::endl;
   std::cout << "True protons:     " << psel_nProton << std::endl;
   std::cout << "True positrons:   " << psel_nPositron << std::endl;
   Int_t psel_Sig = psel_nProton;
   std::cout << "Total signal:     " << psel_Sig << std::endl;
   Int_t psel_Bkg = psel_nPiplus + psel_nAntimu + psel_nPositron;
   std::cout << "Total background: " << psel_Bkg << std::endl;
   Float_t psel_SsqrtSB = psel_Sig/sqrt(psel_Sig+psel_Bkg);
   std::cout << "Purity:           " << psel_Sig/(psel_Sig+psel_Bkg) << std::endl;
   std::cout << "Significance:     " << psel_SsqrtSB << std::endl;
   
   std::cout << std::endl << std::endl;
   
   std::cout << "=========== Electron-like selection ===========" << std::endl << std::endl;
   
   std::cout << "True antimu:      " << esel_nAntimu << std::endl;
   std::cout << "True piplus:      " << esel_nPiplus << std::endl;
   std::cout << "True protons:     " << esel_nProton << std::endl;
   std::cout << "True positrons:   " << esel_nPositron << std::endl;
   Int_t esel_Sig = esel_nPositron;
   std::cout << "Total signal:     " << esel_Sig << std::endl;
   Int_t esel_Bkg = esel_nPiplus + esel_nAntimu + esel_nProton;
   std::cout << "Total background: " << esel_Bkg << std::endl;
   Float_t esel_SsqrtSB = esel_Sig/sqrt(esel_Sig+esel_Bkg);
   std::cout << "Purity:           " << esel_Sig/(esel_Sig+esel_Bkg) << std::endl;
   std::cout << "Significance:     " << esel_SsqrtSB << std::endl;
   
   std::cout << std::endl << std::endl;
      
      
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
