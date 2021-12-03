#define DefaultCustomPlotting_cxx
#include "DefaultCustomPlotting.h"
#include <TH2.h>
#include <TGraph.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>
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
   
   gStyle->SetOptStat(0);
   gStyle->SetTitleYOffset(1.2);
   gStyle->SetTitleXOffset(1.2);
   gStyle->SetLineWidth(2);
   
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntries();
   
   std::cout << "Total entries to process: " << nentries << std::endl << std::endl;
   
   std::time_t time_start = std::time(0);
   
   Int_t variable_bins = 50;
   
   TH1F *recomom_antimu = new TH1F("recomom_antimu", "Antimuon;Reconstructed momentum (MeV/c);Entries/50 MeV/c", variable_bins, 0.0, 2000.0);
   TH1F *recomom_piplus = new TH1F("recomom_piplus", "Pi+", variable_bins, 0.0, 2000.0);
   TH1F *recomom_proton = new TH1F("recomom_proton", "Proton", variable_bins, 0.0, 2000.0);
   TH1F *recomom_positron = new TH1F("recomom_positron", "Positron", variable_bins, 0.0, 2000.0);
   
   
   Int_t recomom_nbins = 25;
   
   Int_t musel_nAntimu = 0;
   Int_t musel_nPiplus = 0;
   Int_t musel_nProton = 0;
   Int_t musel_nPositron = 0;
   TH1F *musel_sig_recomom = new TH1F("musel_sig_recomom", "Mu-like selection signal vs reco momentum", recomom_nbins, 200.0, 1500.0);
   TH1F *musel_bkg_recomom = new TH1F("musel_bkg_recomom", "Mu-like selection bkg vs reco momentum", recomom_nbins, 200.0, 1500.0);
   
   Int_t pisel_nAntimu = 0;
   Int_t pisel_nPiplus = 0;
   Int_t pisel_nProton = 0;
   Int_t pisel_nPositron = 0;
   TH1F *pisel_sig_recomom = new TH1F("pisel_sig_recomom", "Pi-like selection signal vs reco momentum", recomom_nbins, 200.0, 1500.0);
   TH1F *pisel_bkg_recomom = new TH1F("pisel_bkg_recomom", "Pi-like selection bkg vs reco momentum", recomom_nbins, 200.0, 1500.0);
   
   Int_t psel_nAntimu = 0;
   Int_t psel_nPiplus = 0;
   Int_t psel_nProton = 0;
   Int_t psel_nPositron = 0;
   TH1F *psel_sig_recomom = new TH1F("psel_sig_recomom", "P-like selection signal vs reco momentum", recomom_nbins, 200.0, 1500.0);
   TH1F *psel_bkg_recomom = new TH1F("psel_bkg_recomom", "P-like selection bkg vs reco momentum", recomom_nbins, 200.0, 1500.0);
   
   Int_t esel_nAntimu = 0;
   Int_t esel_nPiplus = 0;
   Int_t esel_nProton = 0;
   Int_t esel_nPositron = 0;
   TH1F *esel_sig_recomom = new TH1F("esel_sig_recomom", "E-like selection signal vs reco momentum", recomom_nbins, 200.0, 1500.0);
   TH1F *esel_bkg_recomom = new TH1F("esel_bkg_recomom", "E-like selection bkg vs reco momentum", recomom_nbins, 200.0, 1500.0);
   
   Int_t optimisation_nbins = 50;
   
   TH1F *opt_mulike_sig = new TH1F("opt_mulike_sig", "Mu-like (true antimu)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_mulike_bkg = new TH1F("opt_mulike_bkg", "Mu-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   
   TH1F *opt_pilike_sig = new TH1F("opt_pilike_sig", "Pi-like (true pi+)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_pilike_bkg = new TH1F("opt_pilike_bkg", "Pi-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   
   TH1F *opt_plike_sig = new TH1F("opt_plike_sig", "Proton-like (true protons)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_plike_bkg = new TH1F("opt_plike_bkg", "Proton-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   
   TH1F *opt_elike_sig = new TH1F("opt_elike_sig", "Electron-like (true positrons)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_elike_bkg = new TH1F("opt_elike_bkg", "Electron-like (backgrounds)", optimisation_nbins, 0.0, 1.0);

   
   
   
   
   
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      fChain->GetEntry(jentry);

      // Cut on accum_level etc
      if (accum_level[0][0] <= 4) continue; // Set accum_level
      
      
      // ============= Fill histograms for input variable plotting =============
      
      if ((accum_level[0][0] > 5) && (selmu_necals < 2)){
         
         if ((particle == -13)&&(particle_pg == -13))
         {
            recomom_antimu->Fill(selmu_mom[0]);
         }
         else if ((particle == 211)&&(particle_pg == 211))
         {
            recomom_piplus->Fill(selmu_mom[0]);
         }
         else if ((particle == 2212)&&(particle_pg == 2212))
         {
            recomom_proton->Fill(selmu_mom[0]);
         }
         else if ((particle == -11)&&(particle_pg == -11))
         {
            recomom_positron->Fill(selmu_mom[0]);
         }
      }
      
      
      // ============= Fill histograms to find optimal cuts =============
      
      if (accum_level[0][0] > 5){
         
         if (particle == -13)
         {
            opt_mulike_sig->Fill(selmu_bdt_pid_mu);
            opt_pilike_bkg->Fill(selmu_bdt_pid_pi);
            opt_plike_bkg->Fill(selmu_bdt_pid_p);
            opt_elike_bkg->Fill(selmu_bdt_pid_e);
         }
         else if (particle == 211)
         {
            opt_mulike_bkg->Fill(selmu_bdt_pid_mu);
            opt_pilike_sig->Fill(selmu_bdt_pid_pi);
            opt_plike_bkg->Fill(selmu_bdt_pid_p);
            opt_elike_bkg->Fill(selmu_bdt_pid_e);
         }
         else if (particle == 2212)
         {
            opt_mulike_bkg->Fill(selmu_bdt_pid_mu);
            opt_pilike_bkg->Fill(selmu_bdt_pid_pi);
            opt_plike_sig->Fill(selmu_bdt_pid_p);
            opt_elike_bkg->Fill(selmu_bdt_pid_e);
         }
         else if (particle == -11)
         {
            opt_mulike_bkg->Fill(selmu_bdt_pid_mu);
            opt_pilike_bkg->Fill(selmu_bdt_pid_pi);
            opt_plike_bkg->Fill(selmu_bdt_pid_p);
            opt_elike_sig->Fill(selmu_bdt_pid_e);
         }
      }
      
      
      
      
      // ============= Fill variables to test existing cuts =============
      
      if (accum_level[0][0] > 6){
         
         if (particle == -13) {musel_nAntimu++; musel_sig_recomom->Fill(selmu_mom[0]);}
         if (particle == 211) {musel_nPiplus++; musel_bkg_recomom->Fill(selmu_mom[0]);}
         if (particle == 2212) {musel_nProton++; musel_bkg_recomom->Fill(selmu_mom[0]);}
         if (particle == -11) {musel_nPositron++; musel_bkg_recomom->Fill(selmu_mom[0]);}
      }
      
      if (accum_level[0][1] > 6){
         
         if (particle == -13) {pisel_nAntimu++; pisel_bkg_recomom->Fill(selmu_mom[0]);}
         if (particle == 211) {pisel_nPiplus++; pisel_sig_recomom->Fill(selmu_mom[0]);}
         if (particle == 2212) {pisel_nProton++; pisel_bkg_recomom->Fill(selmu_mom[0]);}
         if (particle == -11) {pisel_nPositron++; pisel_bkg_recomom->Fill(selmu_mom[0]);}
      }
      
      if (accum_level[0][2] > 6){
         
         if (particle == -13) {psel_nAntimu++; psel_bkg_recomom->Fill(selmu_mom[0]);}
         if (particle == 211) {psel_nPiplus++; psel_bkg_recomom->Fill(selmu_mom[0]);}
         if (particle == 2212) {psel_nProton++; psel_sig_recomom->Fill(selmu_mom[0]);}
         if (particle == -11) {psel_nPositron++; psel_bkg_recomom->Fill(selmu_mom[0]);}
      }
      
      if (accum_level[0][3] > 6){
         
         if (particle == -13) {esel_nAntimu++; esel_bkg_recomom->Fill(selmu_mom[0]);}
         if (particle == 211) {esel_nPiplus++; esel_bkg_recomom->Fill(selmu_mom[0]);}
         if (particle == 2212) {esel_nProton++; esel_bkg_recomom->Fill(selmu_mom[0]);}
         if (particle == -11) {esel_nPositron++; esel_sig_recomom->Fill(selmu_mom[0]);}
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
   
   
   
   
   
   
   // ============= Plot input variables =============
   
   TCanvas* canvas_recomom = new TCanvas("canvas_recomom","Reconstructed momentum (MeV/c)",200,10,1000,600);
   
   recomom_antimu->GetYaxis()->SetRangeUser(0.0, 4500.0);
   
   recomom_antimu->SetLineColor( kBlue);
   recomom_antimu->SetFillColorAlpha(kBlue, 0.35);
   recomom_antimu->SetFillStyle( 3006);
   recomom_piplus->SetLineColor( kRed);
   recomom_piplus->SetFillColorAlpha(kRed, 0.35);
   recomom_piplus->SetFillStyle( 3007);
   recomom_proton->SetLineColor( kGreen);
   recomom_proton->SetFillColorAlpha(kGreen, 0.35);
   recomom_proton->SetFillStyle( 3354);
   recomom_positron->SetLineColor( kMagenta);
   recomom_positron->SetFillColorAlpha(kMagenta, 0.35);
   recomom_positron->SetFillStyle( 3345);
   
   
   recomom_antimu->Draw();
   recomom_piplus->Draw("same");
   recomom_proton->Draw("same");
   recomom_positron->Draw("same");
   canvas_recomom->BuildLegend();
          
   canvas_recomom->Write();
   
   
   
   
   
   
   // ============= Find optimal cuts =============
   
   std::cout << "=========== Mu-like optimisation ===========" << std::endl << std::endl;
   
   //std::cout << "DEBUG: Total sig " << opt_mulike_sig->GetEntries() << ", total bkg " << opt_mulike_bkg->GetEntries() << std::endl;
   
   Float_t optimal_signif_mu = 0;
   Float_t optimal_cut_mu = 0;
   Float_t optimal_pur_mu = 0;
   Float_t optimal_eff_mu = 0;
   
   TCanvas* canvas_opt_mu = new TCanvas("opt_mulike","Optimisation signifiance curve (mu-like)",200,10,1000,600);
   TGraph* graph_opt_mu = new TGraph();
   graph_opt_mu->SetTitle(" ;Cut on BDT mu-like output;Antimuon selection significance;");
   TGraph* graph_opt_pur_mu = new TGraph();
   TGraph* graph_opt_eff_mu = new TGraph();
   TGraph* graph_opt_effpur_mu = new TGraph();
   graph_opt_effpur_mu->SetTitle(" ;Cut on BDT mu-like output;Antimuon selection efficiency*purity;");
   
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
   
   graph_opt_mu->Draw("AC");
   canvas_opt_mu->Write();
   TCanvas* canvas_effpur_mu = new TCanvas("effpur_mulike","Optimisation efficiency and purity curves (mu-like)",200,10,1000,600);
   //graph_opt_pur_mu->Draw("AC");
   //graph_opt_eff_mu->Draw("C* same");
   graph_opt_effpur_mu->Draw("AC");
   canvas_effpur_mu->Write();
   
   std::cout << "=========== Pi-like optimisation ===========" << std::endl << std::endl;
   
   //std::cout << "DEBUG: Total sig " << opt_pilike_sig->GetEntries() << ", total bkg " << opt_pilike_bkg->GetEntries() << std::endl;
   
   Float_t optimal_signif_pi = 0;
   Float_t optimal_cut_pi = 0;
   Float_t optimal_pur_pi = 0;
   Float_t optimal_eff_pi = 0;
   
   TCanvas* canvas_opt_pi = new TCanvas("opt_pilike","Optimisation signifiance curve (pi-like)",200,10,1000,600);
   TGraph* graph_opt_pi = new TGraph();
   graph_opt_pi->SetTitle(" ;Cut on BDT pi-like output;Pi+ selection significance;");
   TGraph* graph_opt_pur_pi = new TGraph();
   TGraph* graph_opt_eff_pi = new TGraph();
   TGraph* graph_opt_effpur_pi = new TGraph();
   graph_opt_effpur_pi->SetTitle(" ;Cut on BDT pi-like output;Pi+ selection efficiency*purity;");
   
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
         optimal_cut_pi = opt_pilike_sig->GetBinLowEdge(cut);
         optimal_pur_pi = purity;
         optimal_eff_pi = efficiency;
      }
      
      //std::cout << "DEBUG: Cut #" << cut << " at " << opt_pilike_sig->GetBinLowEdge(cut) 
      //          << " has " << passed_sig << " sig, " << passed_bkg <<" bgk -> significance = " << significance << std::endl;
      
      graph_opt_pi->SetPoint(cut, opt_pilike_sig->GetBinLowEdge(cut), significance);
      graph_opt_pur_pi->SetPoint(cut, opt_pilike_sig->GetBinLowEdge(cut), purity);
      graph_opt_eff_pi->SetPoint(cut, opt_pilike_sig->GetBinLowEdge(cut), efficiency);
      graph_opt_effpur_pi->SetPoint(cut, opt_pilike_sig->GetBinLowEdge(cut), efficiency*purity);
     
   }
   
   std::cout << "Optimal significance = " << optimal_signif_pi << " at cut value of " << optimal_cut_pi << std::endl;
   std::cout << "Efficiency = " << optimal_eff_pi  << ", purity = " << optimal_pur_pi << ", eff*pur = " << optimal_eff_pi*optimal_pur_pi << std::endl;
   
   graph_opt_pi->Draw("AC");
   canvas_opt_pi->Write();
   TCanvas* canvas_effpur_pi = new TCanvas("effpur_pilike","Optimisation efficiency and purity curves (pi-like)",200,10,1000,600);
   //graph_opt_pur_pi->Draw("AC");
   //graph_opt_eff_pi->Draw("C* same");
   graph_opt_effpur_pi->Draw("AC");
   canvas_effpur_pi->Write();
   
   std::cout << "=========== Proton-like optimisation ===========" << std::endl << std::endl;
   
   //std::cout << "DEBUG: Total sig " << opt_plike_sig->GetEntries() << ", total bkg " << opt_plike_bkg->GetEntries() << std::endl;
   
   Float_t optimal_signif_p = 0;
   Float_t optimal_cut_p = 0;
   Float_t optimal_pur_p = 0;
   Float_t optimal_eff_p = 0;
   
   TCanvas* canvas_opt_p = new TCanvas("opt_plike","Optimisation signifiance curve (p-like)",200,10,1000,600);
   TGraph* graph_opt_p = new TGraph();
   graph_opt_p->SetTitle(" ;Cut on BDT p-like output;Proton selection significance;");
   TGraph* graph_opt_pur_p = new TGraph();
   TGraph* graph_opt_eff_p = new TGraph();
   TGraph* graph_opt_effpur_p = new TGraph();
   graph_opt_effpur_p->SetTitle(" ;Cut on BDT p-like output;Proton selection efficiency*purity;");
   
   for (Int_t cut=1; cut <= optimisation_nbins; cut++)
   {
      Float_t passed_sig = opt_plike_sig->Integral(cut,optimisation_nbins);
      Float_t passed_bkg = opt_plike_bkg->Integral(cut,optimisation_nbins);
      
      Float_t significance = passed_sig/sqrt(passed_sig + passed_bkg);
      Float_t purity = passed_sig/(passed_sig+passed_bkg);
      Float_t efficiency = passed_sig/(opt_plike_sig->GetEntries());
      if (passed_sig == 0){significance = 0; purity = 0;}
      
      if (significance > optimal_signif_p)
      {
         optimal_signif_p = significance;
         optimal_cut_p = opt_plike_sig->GetBinLowEdge(cut);
         optimal_pur_p = purity;
         optimal_eff_p = efficiency;
      }
      
      //std::cout << "DEBUG: Cut #" << cut << " at " << opt_plike_sig->GetBinLowEdge(cut) 
      //          << " has " << passed_sig << " sig, " << passed_bkg <<" bgk -> significance = " << significance << std::endl;
      
      graph_opt_p->SetPoint(cut, opt_plike_sig->GetBinLowEdge(cut), significance);
      graph_opt_pur_p->SetPoint(cut, opt_plike_sig->GetBinLowEdge(cut), purity);
      graph_opt_eff_p->SetPoint(cut, opt_plike_sig->GetBinLowEdge(cut), efficiency);
      graph_opt_effpur_p->SetPoint(cut, opt_plike_sig->GetBinLowEdge(cut), efficiency*purity);
     
   }
   
   std::cout << "Optimal significance = " << optimal_signif_p << " at cut value of " << optimal_cut_p << std::endl;
   std::cout << "Efficiency = " << optimal_eff_p  << ", purity = " << optimal_pur_p << ", eff*pur = " << optimal_eff_p*optimal_pur_p << std::endl;
   
   graph_opt_p->Draw("AC");
   canvas_opt_p->Write();
   TCanvas* canvas_effpur_p = new TCanvas("effpur_plike","Optimisation efficiency and purity curves (p-like)",200,10,1000,600);
   //graph_opt_pur_p->Draw("AC");
   //graph_opt_eff_p->Draw("C* same");
   graph_opt_effpur_p->Draw("AC");
   canvas_effpur_p->Write();
   
   std::cout << "=========== Electron-like optimisation ===========" << std::endl << std::endl;
   
   //std::cout << "DEBUG: Total sig " << opt_elike_sig->GetEntries() << ", total bkg " << opt_elike_bkg->GetEntries() << std::endl;
   
   Float_t optimal_signif_e = 0;
   Float_t optimal_cut_e = 0;
   Float_t optimal_pur_e = 0;
   Float_t optimal_eff_e = 0;
   
   TCanvas* canvas_opt_e = new TCanvas("opt_elike","Optimisation signifiance curve (e-like)",200,10,1000,600);
   TGraph* graph_opt_e = new TGraph();
   graph_opt_e->SetTitle(" ;Cut on BDT e-like output;Positron selection significance;");
   TGraph* graph_opt_pur_e = new TGraph();
   TGraph* graph_opt_eff_e = new TGraph();
   TGraph* graph_opt_effpur_e = new TGraph();
   graph_opt_effpur_e->SetTitle(" ;Cut on BDT e-like output;Positron selection efficiency*purity;");
   
   for (Int_t cut=1; cut <= optimisation_nbins; cut++)
   {
      Float_t passed_sig = opt_elike_sig->Integral(cut,optimisation_nbins);
      Float_t passed_bkg = opt_elike_bkg->Integral(cut,optimisation_nbins);
      
      Float_t significance = passed_sig/sqrt(passed_sig + passed_bkg);
      Float_t purity = passed_sig/(passed_sig+passed_bkg);
      Float_t efficiency = passed_sig/(opt_elike_sig->GetEntries());
      if (passed_sig == 0){significance = 0; purity = 0;}
      
      if (significance > optimal_signif_e)
      {
         optimal_signif_e = significance;
         optimal_cut_e = opt_elike_sig->GetBinLowEdge(cut);
         optimal_pur_e = purity;
         optimal_eff_e = efficiency;
      }
      
      //std::cout << "DEBUG: Cut #" << cut << " at " << opt_elike_sig->GetBinLowEdge(cut) 
      //          << " has " << passed_sig << " sig, " << passed_bkg <<" bgk -> significance = " << significance << std::endl;
      
      graph_opt_e->SetPoint(cut, opt_elike_sig->GetBinLowEdge(cut), significance);
      graph_opt_pur_e->SetPoint(cut, opt_elike_sig->GetBinLowEdge(cut), purity);
      graph_opt_eff_e->SetPoint(cut, opt_elike_sig->GetBinLowEdge(cut), efficiency);
      graph_opt_effpur_e->SetPoint(cut, opt_elike_sig->GetBinLowEdge(cut), efficiency*purity);
     
   }
   
   std::cout << "Optimal significance = " << optimal_signif_e << " at cut value of " << optimal_cut_e << std::endl;
   std::cout << "Efficiency = " << optimal_eff_e  << ", purity = " << optimal_pur_e << ", eff*pur = " << optimal_eff_e*optimal_pur_e << std::endl;
   
   graph_opt_e->Draw("AC");
   canvas_opt_e->Write();
   TCanvas* canvas_effpur_e = new TCanvas("effpur_elike","Optimisation efficiency and purity curves (e-like)",200,10,1000,600);
   //graph_opt_pur_e->Draw("AC");
   //graph_opt_eff_e->Draw("C* same");
   graph_opt_effpur_e->Draw("AC");
   canvas_effpur_e->Write();
   
   
   
   
   
   
   
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
   
   TH1F *musel_significance_recomom = new TH1F("musel_significance_recomom", "Mu-like selection significance vs reco momentum", recomom_nbins, 200.0, 1500.0);
   for (Int_t bin=0; bin <= recomom_nbins; bin++)
   {
      Float_t signal = musel_sig_recomom->GetBinContent(bin);
      Float_t background = musel_bkg_recomom->GetBinContent(bin);
      Float_t significance = signal/sqrt(signal+background);
      if (signal == 0) significance = 0;
      musel_significance_recomom->SetBinContent(bin, significance);
   }
   musel_significance_recomom->Write();
   
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
   
   TH1F *pisel_significance_recomom = new TH1F("pisel_significance_recomom", "Pi-like selection significance vs reco momentum", recomom_nbins, 200.0, 1500.0);
   for (Int_t bin=0; bin <= recomom_nbins; bin++)
   {
      Float_t signal = pisel_sig_recomom->GetBinContent(bin);
      Float_t background = pisel_bkg_recomom->GetBinContent(bin);
      Float_t significance = signal/sqrt(signal+background);
      if (signal == 0) significance = 0;
      pisel_significance_recomom->SetBinContent(bin, significance);
   }
   pisel_significance_recomom->Write();
   
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
   
   TH1F *psel_significance_recomom = new TH1F("psel_significance_recomom", "P-like selection significance vs reco momentum", recomom_nbins, 200.0, 1500.0);
   for (Int_t bin=0; bin <= recomom_nbins; bin++)
   {
      Float_t signal = psel_sig_recomom->GetBinContent(bin);
      Float_t background = psel_bkg_recomom->GetBinContent(bin);
      Float_t significance = signal/sqrt(signal+background);
      if (signal == 0) significance = 0;
      psel_significance_recomom->SetBinContent(bin, significance);
   }
   psel_significance_recomom->Write();
   
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
   
   TH1F *esel_significance_recomom = new TH1F("esel_significance_recomom", "E-like selection significance vs reco momentum", recomom_nbins, 200.0, 1500.0);
   for (Int_t bin=0; bin <= recomom_nbins; bin++)
   {
      Float_t signal = esel_sig_recomom->GetBinContent(bin);
      Float_t background = esel_bkg_recomom->GetBinContent(bin);
      Float_t significance = signal/sqrt(signal+background);
      if (signal == 0) significance = 0;
      esel_significance_recomom->SetBinContent(bin, significance);
   }
   esel_significance_recomom->Write();
   
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
