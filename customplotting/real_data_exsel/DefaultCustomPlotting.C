#define DefaultCustomPlotting_cxx
#include "DefaultCustomPlotting.h"
#include <TH2.h>
#include <TGraph.h>
#include <TGraph2D.h>
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
   
   Bool_t limit_kinematics = true;
   Bool_t two_track_only = true;
   
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   //gStyle->SetTitleYOffset(1.6);
   gStyle->SetTitleXOffset(1.2);
   
   
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntries();
   
   std::cout << "Total entries to process: " << nentries << std::endl << std::endl;
   
   std::time_t time_start = std::time(0);
   
   Int_t counter_all_accum4 = 0, counter_all_accum7 = 0, counter_all_accum6 = 0, counter_selmuecal_accum7 = 0;
   Int_t counter_selpi = 0, counter_selpiecal = 0;
   Int_t counter_noecalinfo = 0;
   Int_t counter_all_accum9 = 0;
   Int_t counter_selpi_accum9 = 0;
   Int_t counter_selmu_bdtvalid = 0;
   Int_t counter_selpi_bdtvalid = 0;
   Int_t counter_all_opt = 0;
   Int_t counter_selpi_opt = 0;
   
   
   Int_t recomom_nbins = 8;
   Double_t recomom_max = 5000.0;
   
   TH1F *recomom_all;
   
   TH1F *recomom_all_accum9;
   
   TH1F *recomom_hmnt_all;

   TH1F *recomom_optsel_all;
   
   TH1F *recomom_exsel_all;
   TH1F *recopimom_exsel_all;
   
   if (limit_kinematics)
   {
      recomom_all = new TH1F("recomom_all", "Events vs reco momentum", recomom_nbins, 200.0, 1500.0);
   
      recomom_all_accum9 = new TH1F("recomom_all_accum9", "Events vs reco momentum", recomom_nbins, 200.0, 1500.0);
      
      recomom_hmnt_all = new TH1F("recomom_hmnt_all", "Events vs HMNT reco momentum", recomom_nbins, 200.0, 1500.0);
      
      recomom_optsel_all = new TH1F("recomom_optsel_all", "Events vs reco momentum", recomom_nbins, 200.0, 1500.0);
      
      recomom_exsel_all = new TH1F("recomom_exsel_all", "Events vs reco momentum", recomom_nbins, 200.0, 1500.0);
      recopimom_exsel_all = new TH1F("recopimom_exsel_all", "Events vs reco momentum", recomom_nbins, 200.0, 1500.0);
   }
   else 
   {
      recomom_all = new TH1F("recomom_all", "Events vs reco momentum", recomom_nbins, 0.0, recomom_max);
   
      recomom_all_accum9 = new TH1F("recomom_all_accum9", "Events vs reco momentum", recomom_nbins, 0.0, recomom_max);
      
      recomom_hmnt_all = new TH1F("recomom_hmnt_all", "Events vs HMNT reco momentum", recomom_nbins, 0.0, recomom_max);
      
      recomom_optsel_all = new TH1F("recomom_optsel_all", "Events vs reco momentum", recomom_nbins, 0.0, recomom_max);
      
      recomom_exsel_all = new TH1F("recomom_exsel_all", "Events vs reco momentum", recomom_nbins, 200.0, recomom_max);
      recopimom_exsel_all = new TH1F("recopimom_exsel_all", "Events vs reco momentum", recomom_nbins, 200.0, recomom_max);
   }
   
   Int_t mippion_nbins = 40;
   
   Int_t mipem_nbins = 40;
   
   Int_t ebyl_nbins = 40;
   
   
   TH2F *selmu_ebyl_vs_mippion = new TH2F("selmu_ebyl_vs_mippion", "selmu_ebyl_vs_mippion;ECal MipPion variable (dimensionless);ECal EM energy/ECal segment length (MeV/mm)",
                                          100, -20, 50.0, 100, 0, 6.0);
   
   TH2F *selpi_ebyl_vs_mippion = new TH2F("selpi_ebyl_vs_mippion", "selpi_ebyl_vs_mippion;ECal MipPion variable (dimensionless);ECal EM energy/ECal segment length (MeV/mm)",
                                          100, -20, 50.0, 100, 0, 6.0);
   
   Int_t bdt_output_nbins = 20;
   
   TH1F* bdt_output_selmu_mulike = new TH1F("bdt_output_selmu_mulike", "#mu^+ candidate BDT mu-like output", bdt_output_nbins, 0.0, 1.0);
   TH1F* bdt_output_selmu_pilike = new TH1F("bdt_output_selmu_pilike", "#mu^+ candidate BDT pi-like output", bdt_output_nbins, 0.0, 1.0);
   TH1F* bdt_output_selmu_plike = new TH1F("bdt_output_selmu_plike", "#mu^+ candidate BDT p-like output", bdt_output_nbins, 0.0, 1.0);
   TH1F* bdt_output_selmu_elike = new TH1F("bdt_output_selmu_elike", "#mu^+ candidate BDT e-like output", bdt_output_nbins, 0.0, 1.0);
   
   TH1F* bdt_output_selpi_mulike = new TH1F("bdt_output_selpi_mulike", "#pi^- candidate BDT mu-like output", bdt_output_nbins, 0.0, 1.0);
   TH1F* bdt_output_selpi_pilike = new TH1F("bdt_output_selpi_pilike", "#pi^- candidate BDT pi-like output", bdt_output_nbins, 0.0, 1.0);
   TH1F* bdt_output_selpi_plike = new TH1F("bdt_output_selpi_plike", "#pi^- candidate BDT p-like output", bdt_output_nbins, 0.0, 1.0);
   TH1F* bdt_output_selpi_elike = new TH1F("bdt_output_selpi_elike", "#pi^- candidate BDT e-like output", bdt_output_nbins, 0.0, 1.0);
   
   
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      fChain->GetEntry(jentry);

      // Cut on accum_level etc
      //if (accum_level[0][0] <= 4) continue; // Set accum_level
      
      if ((limit_kinematics) && !((selmu_mom[0] > 200.0) && (selmu_mom[0] < 1500.0) && (selmu_det_theta < 1.0472) && (HMNT_mom > 200.0) && (HMNT_mom < 1500.0))) continue;
      if ((two_track_only) && !((ntpcposQualityFV==1) && (ntpcnegQualityFV==1))) continue;
      
      
      if (accum_level[0][1] > 4){
         
         counter_all_accum4++;
         bdt_output_selmu_mulike->Fill(selmu_bdt_pid_mu);
         bdt_output_selmu_pilike->Fill(selmu_bdt_pid_pi);
         bdt_output_selmu_plike->Fill(selmu_bdt_pid_p);
         bdt_output_selmu_elike->Fill(selmu_bdt_pid_e);
         
         if (ntpcnegQualityFV == 1)
         {
            bdt_output_selpi_pilike->Fill(hmnt_bdt_pid_pi);
            bdt_output_selpi_mulike->Fill(hmnt_bdt_pid_mu);
            bdt_output_selpi_plike->Fill(hmnt_bdt_pid_p);
            bdt_output_selpi_elike->Fill(hmnt_bdt_pid_e);
         }
         
         if ((selmu_bdt_pid_mu > 0.26) && ((hmnt_bdt_pid_pi > 0.12) || (ntpcnegQualityFV == 0)))
         {
            counter_all_opt++;
            recomom_optsel_all->Fill(selmu_mom[0]);
            
            if (ntpcnegQualityFV == 1)
            {
               counter_selpi_opt++;
            }
         }
      }
      
      
      if (accum_level[0][1] > 6){
         
         counter_all_accum6++;
      }
      
      if (accum_level[0][1] > 7){
         
         counter_all_accum7++;
         recomom_all->Fill(selmu_mom[0]);
        
         
         if (selmu_necals==1)
         {
            counter_selmuecal_accum7++;
            selmu_ebyl_vs_mippion->Fill(selmu_ecal_bestseg_mippion, selmu_ecal_bestseg_EbyL);
         }
         
         
         if (ntpcnegQualityFV == 1)
         {
            counter_selpi++;
            
            if ((selmu_necals==0) && (HMNT_NEcalSegments==0))
            {
               counter_noecalinfo++;
            }
            
            if (HMNT_NEcalSegments==1)
            {
               counter_selpiecal++;
               selpi_ebyl_vs_mippion->Fill(HMNT_ecal_bestseg_mippion, HMNT_ecal_bestseg_EbyL);
            }
         }
      }
      
      if (accum_level[0][1] > 8){
         
         recomom_exsel_all->Fill(selmu_mom[0]);
         if (ntpcnegQualityFV == 1)
         {
            recopimom_exsel_all->Fill(HMNT_mom);
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
   
   std::cout << std::endl << "Events above accum_level 4: " << counter_all_accum4 << std::endl;
   std::cout << std::endl << "Events above accum_level 6: " << counter_all_accum6 << std::endl;
   std::cout << std::endl << "Events above accum_level 7: " << counter_all_accum7 << std::endl;
   
   std::cout << std::endl << "===== BEFORE ECAL CUTS: =====" << std::endl;
   
   std::cout << std::endl << "Pi- candidates: " << counter_selpi << std::endl;
   std::cout << std::endl << "Events without ECal info: " << 100*(float)counter_noecalinfo/counter_all_accum7 << "\%";
   
   std::cout << std::endl << "===== AFTER ECAL CUTS: =====" << std::endl;
   
   std::cout << std::endl << "Events above accum_level 9: " << counter_all_accum9;
   std::cout << std::endl << "Pi- candidates: " << counter_selpi_accum9 << std::endl;
   
   std::cout << std::endl << "===== VALID FOR BDT PID: =====" << std::endl;
   
   std::cout << std::endl << "Antimuon candidates: " << counter_selmu_bdtvalid;
   
   std::cout << std::endl << "===== WITH OPTIMISED BDT CUTS: =====" << std::endl;
   
   std::cout << std::endl << "Events selected: " << counter_all_opt;
   
   std::cout << std::endl << "Pi- candidates: " << counter_selpi_opt << std::endl;
   
   // Correlation plots:
   
   std::cout << std::endl << "Mu+ candidate mippion-E/L correlation: " << selmu_ebyl_vs_mippion->GetCorrelationFactor() << std::endl;
   TCanvas* canvas_selmu_ebyl_vs_mippion = new TCanvas("canvas_selmu_ebyl_vs_mippion","",200,10,1000,800);
   selmu_ebyl_vs_mippion->Draw("colz");
   canvas_selmu_ebyl_vs_mippion->Write();
   
   std::cout << std::endl << "Pi- candidate mippion-E/L correlation: " << selpi_ebyl_vs_mippion->GetCorrelationFactor() << std::endl;
   TCanvas* canvas_selpi_ebyl_vs_mippion = new TCanvas("canvas_selpi_ebyl_vs_mippion","",200,10,1000,800);
   selpi_ebyl_vs_mippion->Draw("colz");
   canvas_selpi_ebyl_vs_mippion->Write();
   
   Double_t scale_factor = 1;
   //Double_t scale_factor = 1/counter_all_accum4;
   
   bdt_output_selmu_mulike->Sumw2();
   bdt_output_selmu_pilike->Sumw2();
   bdt_output_selmu_plike->Sumw2();
   bdt_output_selmu_elike->Sumw2();
   
   bdt_output_selmu_mulike->SetTitle("T2K RHC data (Run 5+6+7+9)");
   bdt_output_selmu_pilike->SetTitle("T2K RHC data (Run 5+6+7+9)");
   bdt_output_selmu_plike->SetTitle("T2K RHC data (Run 5+6+7+9)");
   bdt_output_selmu_elike->SetTitle("T2K RHC data (Run 5+6+7+9)");
   
   bdt_output_selmu_mulike->Scale(scale_factor);
   bdt_output_selmu_pilike->Scale(scale_factor);
   bdt_output_selmu_plike->Scale(scale_factor);
   bdt_output_selmu_elike->Scale(scale_factor);
   
   bdt_output_selmu_mulike->SetMarkerStyle(kFullCircle);
   bdt_output_selmu_pilike->SetMarkerStyle(kFullCircle);
   bdt_output_selmu_plike->SetMarkerStyle(kFullCircle);
   bdt_output_selmu_elike->SetMarkerStyle(kFullCircle);
   bdt_output_selmu_mulike->SetLineWidth(2);
   bdt_output_selmu_pilike->SetLineWidth(2);
   bdt_output_selmu_plike->SetLineWidth(2);
   bdt_output_selmu_elike->SetLineWidth(2);
   bdt_output_selmu_mulike->SetLineColor(kBlack);
   bdt_output_selmu_pilike->SetLineColor(kBlack);
   bdt_output_selmu_plike->SetLineColor(kBlack);
   bdt_output_selmu_elike->SetLineColor(kBlack);
   
   bdt_output_selmu_mulike->Write();
   bdt_output_selmu_pilike->Write();
   bdt_output_selmu_plike->Write();
   bdt_output_selmu_elike->Write();
   
   bdt_output_selpi_mulike->Write();
   bdt_output_selpi_pilike->Write();
   bdt_output_selpi_plike->Write();
   bdt_output_selpi_elike->Write();
   
   recomom_optsel_all->Sumw2();
   recomom_optsel_all->SetTitle("T2K RHC data (Run 5+6+7+9)");
   recomom_optsel_all->Scale(scale_factor);
   recomom_optsel_all->SetMarkerStyle(kFullCircle);
   recomom_optsel_all->SetLineWidth(2);
   recomom_optsel_all->SetLineColor(kBlack);
   recomom_optsel_all->Write();
   
   recomom_exsel_all->Sumw2();
   recomom_exsel_all->SetTitle("T2K RHC data (Run 5+6+7+9)");
   recomom_exsel_all->Scale(scale_factor);
   recomom_exsel_all->SetMarkerStyle(kFullCircle);
   recomom_exsel_all->SetLineWidth(2);
   recomom_exsel_all->SetLineColor(kBlack);
   recomom_exsel_all->Write();
   
   recopimom_exsel_all->Sumw2();
   recopimom_exsel_all->SetTitle("T2K RHC data (Run 5+6+7+9)");
   recopimom_exsel_all->Scale(scale_factor);
   recopimom_exsel_all->SetMarkerStyle(kFullCircle);
   recopimom_exsel_all->SetLineWidth(2);
   recopimom_exsel_all->SetLineColor(kBlack);
   recopimom_exsel_all->Write();
   
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

void DefaultCustomPlotting::SetHistParticleStyle(TH1F* hist, std::string particle) {
   
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
