#define DefaultCustomPlotting_existingPID_cxx
#include "DefaultCustomPlotting_existingPID.h"
#include <TH2.h>
#include <TGraph.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <ctime> 

void DefaultCustomPlotting_existingPID::Loop()
{

   
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   gStyle->SetTitleYOffset(1.6);
   gStyle->SetTitleXOffset(1.2);
   
   
   TString parameter = "treenumber";
   
   
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntries();
   
   std::cout << "Total entries to process: " << nentries << std::endl << std::endl;
   
   std::time_t time_start = std::time(0);
   
   Int_t presel_nAntimu = 0;
   Int_t presel_nPiplus = 0;
   Int_t presel_nProton = 0;
   Int_t presel_nPositron = 0;
   
   // BDT selection
   
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
   
   // Existing CC1pi selection
   
   Int_t musel_cc1pi_nAntimu = 0;
   Int_t musel_cc1pi_nPiplus = 0;
   Int_t musel_cc1pi_nProton = 0;
   Int_t musel_cc1pi_nPositron = 0;
   Int_t pisel_cc1pi_nAntimu = 0;
   Int_t pisel_cc1pi_nPiplus = 0;
   Int_t pisel_cc1pi_nProton = 0;
   Int_t pisel_cc1pi_nPositron = 0;
   Int_t psel_cc1pi_nAntimu = 0;
   Int_t psel_cc1pi_nPiplus = 0;
   Int_t psel_cc1pi_nProton = 0;
   Int_t psel_cc1pi_nPositron = 0;
   Int_t esel_cc1pi_nAntimu = 0;
   Int_t esel_cc1pi_nPiplus = 0;
   Int_t esel_cc1pi_nProton = 0;
   Int_t esel_cc1pi_nPositron = 0;
   Int_t nosel_cc1pi_nAntimu = 0;
   Int_t nosel_cc1pi_nPiplus = 0;
   Int_t nosel_cc1pi_nProton = 0;
   Int_t nosel_cc1pi_nPositron = 0;
   
   
   
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      fChain->GetEntry(jentry);

      // Cut on accum_level etc
      if (accum_level[0][1] <= 4) continue; // Set accum_level
      
      
      
      
      // ============= Fill variables for efficiency tests =============
      
      // Preselection:
      
      if ((accum_level[0][1] > 4) && (selmu_necals < 2) && (selmu_mom[0] > 200.0) && (selmu_mom[0] < 1500.0) && (selmu_det_theta < 1.0472)){ 
         
         if (particle == -13)       presel_nAntimu++;
         else if (particle == 211)  presel_nPiplus++;
         else if (particle == 2212) presel_nProton++;
         else if (particle == -11)  presel_nPositron++;
         
         // BDT selection:
         
         if ((selmu_bdt_pid_mu > selmu_bdt_pid_pi) && (selmu_bdt_pid_mu > selmu_bdt_pid_p) && (selmu_bdt_pid_mu > selmu_bdt_pid_e))
         {
            if (particle == -13) musel_nAntimu++;
            if (particle == 211) musel_nPiplus++;
            if (particle == 2212) musel_nProton++;
            if (particle == -11) musel_nPositron++;
         }
         
         if ((selmu_bdt_pid_pi > selmu_bdt_pid_mu) && (selmu_bdt_pid_pi > selmu_bdt_pid_p) && (selmu_bdt_pid_pi > selmu_bdt_pid_e))
         {
            if (particle == -13) pisel_nAntimu++;
            if (particle == 211) pisel_nPiplus++;
            if (particle == 2212) pisel_nProton++;
            if (particle == -11) pisel_nPositron++;
         }
         
         if ((selmu_bdt_pid_p > selmu_bdt_pid_mu) && (selmu_bdt_pid_p > selmu_bdt_pid_pi) && (selmu_bdt_pid_p > selmu_bdt_pid_e))
         {
            if (particle == -13) psel_nAntimu++;
            if (particle == 211) psel_nPiplus++;
            if (particle == 2212) psel_nProton++;
            if (particle == -11) psel_nPositron++;
         }
         
         if ((selmu_bdt_pid_e > selmu_bdt_pid_mu) && (selmu_bdt_pid_e > selmu_bdt_pid_pi) && (selmu_bdt_pid_e > selmu_bdt_pid_p))
         {
            if (particle == -13) esel_nAntimu++;
            if (particle == 211) esel_nPiplus++;
            if (particle == 2212) esel_nProton++;
            if (particle == -11) esel_nPositron++;
         }
         
         // CC1pi selection:
         
         if (((selmu_tpc_like_mu+selmu_tpc_like_pi)/(1-selmu_tpc_like_p) > 0.9 || selmu_mom[0] > 500.0 ) && (selmu_tpc_like_mu>0.1))
         {
            if (particle == -13) musel_cc1pi_nAntimu++;
            if (particle == 211) musel_cc1pi_nPiplus++;
            if (particle == 2212) musel_cc1pi_nProton++;
            if (particle == -11) musel_cc1pi_nPositron++;
         }
         else if ((selmu_tpc_like_pi > selmu_tpc_like_p) && (selmu_tpc_like_pi > selmu_tpc_like_e))
         {
            if (particle == -13) pisel_cc1pi_nAntimu++;
            if (particle == 211) pisel_cc1pi_nPiplus++;
            if (particle == 2212) pisel_cc1pi_nProton++;
            if (particle == -11) pisel_cc1pi_nPositron++;
         }
         else if ((selmu_tpc_like_e > selmu_tpc_like_p) && (selmu_tpc_like_e > selmu_tpc_like_pi) && (selmu_mom[0] < 900.0))
         {
            if (particle == -13) esel_cc1pi_nAntimu++;
            if (particle == 211) esel_cc1pi_nPiplus++;
            if (particle == 2212) esel_cc1pi_nProton++;
            if (particle == -11) esel_cc1pi_nPositron++;
         }
         else //if ((selmu_bdt_pid_e > selmu_bdt_pid_mu) && (selmu_bdt_pid_e > selmu_bdt_pid_pi) && (selmu_bdt_pid_e > selmu_bdt_pid_p))
         {
            if (particle == -13) psel_cc1pi_nAntimu++;
            if (particle == 211) psel_cc1pi_nPiplus++;
            if (particle == 2212) psel_cc1pi_nProton++;
            if (particle == -11) psel_cc1pi_nPositron++;
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
   
   std::cout << std::endl << std::endl;
   
   
 
   
   std::cout << "DEBUG: Preselection mu+: " << presel_nAntimu << std::endl;
   std::cout << "DEBUG: Preselection pi+: " << presel_nPiplus << std::endl;
   std::cout << "DEBUG: Preselection p: " << presel_nProton << std::endl;
   std::cout << "DEBUG: Preselection e+: " << presel_nPositron << std::endl;
   
   // ============= Find efficiencies =============
   
   std::cout << "================ BDT SELECTION ================" << std::endl << std::endl;
   
   std::cout << "=========== Mu-like ===========" << std::endl << std::endl;
   
   std::cout << "mu+ efficiency: " <<  (Float_t)musel_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)musel_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)musel_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)musel_nPositron/presel_nPositron << std::endl;
   
   std::cout << "=========== Pi-like ===========" << std::endl << std::endl;
   
   std::cout << "mu+ efficiency: " << (Float_t)pisel_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)pisel_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)pisel_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)pisel_nPositron/presel_nPositron << std::endl;
   
   std::cout << "=========== Proton-like ===========" << std::endl << std::endl;
   
   std::cout << "mu+ efficiency: " << (Float_t)psel_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)psel_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)psel_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)psel_nPositron/presel_nPositron << std::endl;
  
   std::cout << "=========== Electron-like optimisation ===========" << std::endl << std::endl;
   
   std::cout << "mu+ efficiency: " << (Float_t)esel_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)esel_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)esel_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)esel_nPositron/presel_nPositron << std::endl;
   
   std::cout << "================ CC1PI SELECTION ================" << std::endl << std::endl;
   
   std::cout << "=========== Mu-like ===========" << std::endl << std::endl;
   
   std::cout << "mu+ efficiency: " <<  (Float_t)musel_cc1pi_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)musel_cc1pi_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)musel_cc1pi_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)musel_cc1pi_nPositron/presel_nPositron << std::endl;
   
   std::cout << "=========== Pi-like ===========" << std::endl << std::endl;
   
   std::cout << "mu+ efficiency: " << (Float_t)pisel_cc1pi_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)pisel_cc1pi_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)pisel_cc1pi_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)pisel_cc1pi_nPositron/presel_nPositron << std::endl;
   
   std::cout << "=========== Proton-like ===========" << std::endl << std::endl;
   
   std::cout << "mu+ efficiency: " << (Float_t)psel_cc1pi_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)psel_cc1pi_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)psel_cc1pi_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)psel_cc1pi_nPositron/presel_nPositron << std::endl;
  
   std::cout << "=========== Electron-like optimisation ===========" << std::endl << std::endl;
   
   std::cout << "mu+ efficiency: " << (Float_t)esel_cc1pi_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)esel_cc1pi_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)esel_cc1pi_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)esel_cc1pi_nPositron/presel_nPositron << std::endl;
     
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
  
  DefaultCustomPlotting_existingPID *deftree = new DefaultCustomPlotting_existingPID(rootFiles, outFileName);
  
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

void DefaultCustomPlotting_existingPID::SetHistParticleStyle(TH1F* hist, std::string particle) {
   
   hist->SetLineWidth(2);
   
   if (particle == "antimu")
   {
      hist->SetLineColor( kBlue);
      //hist->SetFillColorAlpha(kBlue-10, 0.35);
      //hist->SetFillStyle( 3006);
   }
   
   else if (particle == "piplus")
   {
      hist->SetLineColor( kRed);
      //hist->SetFillColorAlpha(kRed, 0.35);
      //hist->SetFillStyle( 3354);
   }
   
   else if (particle == "proton")
   {
      hist->SetLineColor( kGreen);
      //hist->SetFillColorAlpha(kGreen, 0.35);
      //hist->SetFillStyle( 3003);
   }
   
   else if (particle == "positron")
   {
      hist->SetLineColor( kMagenta);
      //hist->SetFillColorAlpha(kMagenta, 0.35);
      //hist->SetFillStyle( 3345);
   }
   
   else std::cout << "Error in SetHistParticleStyle: particle type not recognised." << std::endl;
   
   return;
}

Float_t DefaultCustomPlotting_existingPID::GetOptSignificanceValues(TH1F* hist_sig, TH1F* hist_bkg, Int_t nbins) {
   
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
