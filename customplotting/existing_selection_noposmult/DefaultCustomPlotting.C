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
   
   Int_t counter_all_accum7 = 0, counter_all_accum6 = 0, counter_selmuecal_accum7 = 0;
   Int_t counter_cc1pi = 0, counter_cc0pi = 0, counter_ccother = 0, counter_bkg = 0, counter_oofv = 0;
   Int_t counter_selmu_antimu = 0, counter_selmu_piplus = 0, counter_selmu_proton = 0, counter_selmu_positron = 0, 
         counter_selmu_mu = 0, counter_selmu_piminus = 0, counter_selmu_electron = 0;
   Int_t counter_selpi = 0, counter_selpiecal = 0, counter_selpi_piminus = 0, counter_selpi_mu = 0, counter_selpi_electron = 0, counter_selpi_proton = 0;
   Int_t counter_selmu_antimu_accum4 = 0, counter_selmu_antimu_accum5 = 0, counter_selmu_piplus_accum4 = 0, counter_selmu_piplus_accum5 = 0;
   Int_t counter_noecalinfo = 0;
   Int_t counter_all_accum9 = 0, counter_cc1pi_accum9 = 0, counter_bkg_accum9 = 0;
   Int_t counter_selmu_antimu_accum9 = 0, counter_selmu_piplus_accum9 = 0, counter_selmu_proton_accum9 = 0;
   Int_t counter_selpi_accum9 = 0, counter_selpi_piminus_accum9 = 0, counter_selpi_mu_accum9 = 0;
   Int_t counter_selmu_bdtvalid = 0, counter_selmu_antimu_bdtvalid = 0, counter_selmu_piplus_bdtvalid = 0, counter_selmu_proton_bdtvalid = 0;
   Int_t counter_selpi_bdtvalid = 0, counter_selpi_piminus_bdtvalid = 0, counter_selpi_mu_bdtvalid = 0;
   
   Int_t recomom_nbins = 8;
   Double_t recomom_max = 5000.0;
   
   TH1F *recomom_all;
   TH1F *recomom_antimu;
   TH1F *recomom_piplus;
   TH1F *recomom_proton;
   
   TH1F *recomom_all_accum9;
   TH1F *recomom_antimu_accum9;
   TH1F *recomom_piplus_accum9;
   TH1F *recomom_proton_accum9;
   
   TH1F *recomom_hmnt_all;
   TH1F *recomom_hmnt_piminus;
   TH1F *recomom_hmnt_mu;
   
   TH1F *recomom_sig_presel;
   TH1F *recomom_sig_sel;
   TH1F *recomom_bkg_sel;
   
   TH1F *recomom_optsel_all;
   TH1F *recomom_optsel_antimu;
   TH1F *recomom_optsel_piplus;
   TH1F *recomom_optsel_proton;
   
   TH1F *recomom_optsel_hmnt_all;
   TH1F *recomom_optsel_hmnt_piminus;
   TH1F *recomom_optsel_hmnt_mu;
   
   TH1F *recomom_optsel_sig_sel;
   TH1F *recomom_optsel_bkg_sel;
   
   if (limit_kinematics)
   {
      recomom_all = new TH1F("recomom_all", "Events vs reco momentum", recomom_nbins, 200.0, 1500.0);
      recomom_antimu = new TH1F("recomom_antimu", "True antimu vs reco momentum", recomom_nbins, 200.0, 1500.0);
      recomom_piplus = new TH1F("recomom_piplus", "True piplus vs reco momentum", recomom_nbins, 200.0, 1500.0);
      recomom_proton = new TH1F("recomom_proton", "True protons vs reco momentum", recomom_nbins, 200.0, 1500.0);
   
      recomom_all_accum9 = new TH1F("recomom_all_accum9", "Events vs reco momentum", recomom_nbins, 200.0, 1500.0);
      recomom_antimu_accum9 = new TH1F("recomom_antimu_accum9", "True antimu vs reco momentum", recomom_nbins, 200.0, 1500.0);
      recomom_piplus_accum9 = new TH1F("recomom_piplus_accum9", "True piplus vs reco momentum", recomom_nbins, 200.0, 1500.0);
      recomom_proton_accum9 = new TH1F("recomom_proton_accum9", "True protons vs reco momentum", recomom_nbins, 200.0, 1500.0);
      
      recomom_hmnt_all = new TH1F("recomom_hmnt_all", "Events vs HMNT reco momentum", recomom_nbins, 200.0, 1500.0);
      recomom_hmnt_piminus = new TH1F("recomom_hmnt_piminus", "True piminus vs HMNT reco momentum", recomom_nbins, 200.0, 1500.0);
      recomom_hmnt_mu = new TH1F("recomom_hmnt_mu", "True mu vs HMNT reco momentum", recomom_nbins, 200.0, 1500.0);
      
      recomom_sig_presel = new TH1F("recomom_sig_presel", "recomom_sig_presel", recomom_nbins, 200.0, 1500.0);
      recomom_sig_sel = new TH1F("recomom_sig_sel", "recomom_sig_sel", recomom_nbins, 200.0, 1500.0);
      recomom_bkg_sel = new TH1F("recomom_bkg_sel", "recomom_bkg_sel", recomom_nbins, 200.0, 1500.0);
      
      recomom_optsel_all = new TH1F("recomom_optsel_all", "Events vs reco momentum", recomom_nbins, 200.0, 1500.0);
      recomom_optsel_antimu = new TH1F("recomom_optsel_antimu", "True antimu vs reco momentum", recomom_nbins, 200.0, 1500.0);
      recomom_optsel_piplus = new TH1F("recomom_optsel_piplus", "True piplus vs reco momentum", recomom_nbins, 200.0, 1500.0);
      recomom_optsel_proton = new TH1F("recomom_optsel_proton", "True protons vs reco momentum", recomom_nbins, 200.0, 1500.0);
      
      recomom_optsel_hmnt_all = new TH1F("recomom_optsel_hmnt_all", "Events vs HMNT reco momentum", recomom_nbins, 200.0, 1500.0);
      recomom_optsel_hmnt_piminus = new TH1F("recomom_optsel_hmnt_piminus", "True piminus vs HMNT reco momentum", recomom_nbins, 200.0, 1500.0);
      recomom_optsel_hmnt_mu = new TH1F("recomom_optsel_hmnt_mu", "True mu vs HMNT reco momentum", recomom_nbins, 200.0, 1500.0);
      
      recomom_optsel_sig_sel = new TH1F("recomom_optsel_sig_sel", "recomom_optsel_sig_sel", recomom_nbins, 200.0, 1500.0);
      recomom_optsel_bkg_sel = new TH1F("recomom_optsel_bkg_sel", "recomom_optsel_bkg_sel", recomom_nbins, 200.0, 1500.0);
   }
   else 
   {
      recomom_all = new TH1F("recomom_all", "Events vs reco momentum", recomom_nbins, 0.0, recomom_max);
      recomom_antimu = new TH1F("recomom_antimu", "True antimu vs reco momentum", recomom_nbins, 0.0, recomom_max);
      recomom_piplus = new TH1F("recomom_piplus", "True piplus vs reco momentum", recomom_nbins, 0.0, recomom_max);
      recomom_proton = new TH1F("recomom_proton", "True protons vs reco momentum", recomom_nbins, 0.0, recomom_max);
   
      recomom_all_accum9 = new TH1F("recomom_all_accum9", "Events vs reco momentum", recomom_nbins, 0.0, recomom_max);
      recomom_antimu_accum9 = new TH1F("recomom_antimu_accum9", "True antimu vs reco momentum", recomom_nbins, 0.0, recomom_max);
      recomom_piplus_accum9 = new TH1F("recomom_piplus_accum9", "True piplus vs reco momentum", recomom_nbins, 0.0, recomom_max);
      recomom_proton_accum9 = new TH1F("recomom_proton_accum9", "True protons vs reco momentum", recomom_nbins, 0.0, recomom_max);
      
      recomom_hmnt_all = new TH1F("recomom_hmnt_all", "Events vs HMNT reco momentum", recomom_nbins, 0.0, recomom_max);
      recomom_hmnt_piminus = new TH1F("recomom_hmnt_piminus", "True piminus vs HMNT reco momentum", recomom_nbins, 0.0, recomom_max);
      recomom_hmnt_mu = new TH1F("recomom_hmnt_mu", "True mu vs HMNT reco momentum", recomom_nbins, 0.0, recomom_max);
      
      recomom_sig_presel = new TH1F("recomom_sig_presel", "recomom_sig_presel", recomom_nbins, 0.0, recomom_max);
      recomom_sig_sel = new TH1F("recomom_sig_sel", "recomom_sig_sel", recomom_nbins, 0.0, recomom_max);
      recomom_bkg_sel = new TH1F("recomom_bkg_sel", "recomom_bkg_sel", recomom_nbins, 0.0, recomom_max);
      
      recomom_optsel_all = new TH1F("recomom_optsel_all", "Events vs reco momentum", recomom_nbins, 0.0, recomom_max);
      recomom_optsel_antimu = new TH1F("recomom_optsel_antimu", "True antimu vs reco momentum", recomom_nbins, 0.0, recomom_max);
      recomom_optsel_piplus = new TH1F("recomom_optsel_piplus", "True piplus vs reco momentum", recomom_nbins, 0.0, recomom_max);
      recomom_optsel_proton = new TH1F("recomom_optsel_proton", "True protons vs reco momentum", recomom_nbins, 0.0, recomom_max);
      
      recomom_optsel_hmnt_all = new TH1F("recomom_optsel_hmnt_all", "Events vs HMNT reco momentum", recomom_nbins, 0.0, recomom_max);
      recomom_optsel_hmnt_piminus = new TH1F("recomom_optsel_hmnt_piminus", "True piminus vs HMNT reco momentum", recomom_nbins, 0.0, recomom_max);
      recomom_optsel_hmnt_mu = new TH1F("recomom_optsel_hmnt_mu", "True mu vs HMNT reco momentum", recomom_nbins, 0.0, recomom_max);
      
      recomom_optsel_sig_sel = new TH1F("recomom_optsel_sig_sel", "recomom_optsel_sig_sel", recomom_nbins, 0.0, recomom_max);
      recomom_optsel_bkg_sel = new TH1F("recomom_optsel_bkg_sel", "recomom_optsel_bkg_sel", recomom_nbins, 0.0, recomom_max);
   }
   
   Int_t mippion_nbins = 40;
   TH1F *selmu_mippion_antimu = new TH1F("selmu_mippion_antimu", "#mu^{+};ECal MipPion variable (dimensionless);Entries", mippion_nbins, -30, 50.0);
   TH1F *selmu_mippion_piplus = new TH1F("selmu_mippion_piplus", "#pi^{+}", mippion_nbins, -30, 50.0);
   TH1F *selmu_mippion_proton = new TH1F("selmu_mippion_proton", "p", mippion_nbins, -30, 50.0);
   
   TH1F *selpi_mippion_piminus = new TH1F("selpi_mippion_piminus", "#pi^{-};ECal MipPion variable (dimensionless);Entries", mippion_nbins, -30, 50.0);
   TH1F *selpi_mippion_mu = new TH1F("selpi_mippion_mu", "#mu^{-};ECal MipPion variable (dimensionless);Entries", mippion_nbins, -30, 50.0);
   
   Int_t mipem_nbins = 40;
   TH1F *selmu_mipem_antimu = new TH1F("selmu_mipem_antimu", "#mu^{+};ECal MipEm variable (dimensionless);Entries", mipem_nbins, -30, 50.0);
   TH1F *selmu_mipem_piplus = new TH1F("selmu_mipem_piplus", "#pi^{+}", mipem_nbins, -30, 50.0);
   TH1F *selmu_mipem_proton = new TH1F("selmu_mipem_proton", "p", mipem_nbins, -30, 50.0);
   
   TH1F *selpi_mipem_piminus = new TH1F("selpi_mipem_piminus", "#pi^{-};ECal MipEm variable (dimensionless);Entries", mipem_nbins, -30, 50.0);
   TH1F *selpi_mipem_mu = new TH1F("selpi_mipem_mu", "#mu^{-};ECal MipEm variable (dimensionless);Entries", mipem_nbins, -30, 50.0);
   
   Int_t ebyl_nbins = 40;
   TH1F *selmu_ebyl_antimu = new TH1F("selmu_ebyl_antimu", "#mu^{+};ECal EM energy/ECal segment length (MeV/mm);Entries", ebyl_nbins, 0, 4.0);
   TH1F *selmu_ebyl_piplus = new TH1F("selmu_ebyl_piplus", "#pi^{+}", ebyl_nbins, 0, 4.0);
   TH1F *selmu_ebyl_proton = new TH1F("selmu_ebyl_proton", "p", ebyl_nbins, 0, 4.0);
   
   TH1F *selpi_ebyl_piminus = new TH1F("selpi_ebyl_piminus", "#mu^{-};ECal EM energy/ECal segment length (MeV/mm);Entries", ebyl_nbins, 0, 4.0);
   TH1F *selpi_ebyl_mu = new TH1F("selpi_ebyl_mu", "#pi^{-};ECal EM energy/ECal segment length (MeV/mm);Entries", ebyl_nbins, 0, 4.0);
   
   TH2F *selmu_ebyl_vs_mippion = new TH2F("selmu_ebyl_vs_mippion", "selmu_ebyl_vs_mippion;ECal MipPion variable (dimensionless);ECal EM energy/ECal segment length (MeV/mm)",
                                          100, -20, 50.0, 100, 0, 6.0);
   
   TH2F *selpi_ebyl_vs_mippion = new TH2F("selpi_ebyl_vs_mippion", "selpi_ebyl_vs_mippion;ECal MipPion variable (dimensionless);ECal EM energy/ECal segment length (MeV/mm)",
                                          100, -20, 50.0, 100, 0, 6.0);
   
   Int_t optimisation_nbins = 50;
   
   TH2F *selmu_ebyl_vs_mippion_sig = new TH2F("selmu_ebyl_vs_mippion_sig", "selmu_ebyl_vs_mippion_sig;ECal MipPion variable (dimensionless);ECal EM energy/ECal segment length (MeV/mm)",
                                          optimisation_nbins, -20, 50.0, optimisation_nbins, 0, 4.0);
   TH2F *selmu_ebyl_vs_mippion_bkg = new TH2F("selmu_ebyl_vs_mippion_bkg", "selmu_ebyl_vs_mippion_bkg;ECal MipPion variable (dimensionless);ECal EM energy/ECal segment length (MeV/mm)",
                                          optimisation_nbins, -20, 50.0, optimisation_nbins, 0, 4.0);
   TH2F *selmu_ebyl_vs_mippion_signif = new TH2F("selmu_ebyl_vs_mippion_signif", "selmu_ebyl_vs_mippion_signif;ECal MipPion variable (dimensionless);ECal EM energy/ECal segment length (MeV/mm)",
                                          optimisation_nbins, -20, 50.0, optimisation_nbins, 0, 4.0);
   TH2F *selmu_ebyl_vs_mippion_effpur = new TH2F("selmu_ebyl_vs_mippion_effpur", "selmu_ebyl_vs_mippion_effpur;ECal MipPion variable (dimensionless);ECal EM energy/ECal segment length (MeV/mm)",
                                          optimisation_nbins, -20, 50.0, optimisation_nbins, 0, 4.0);
   TH2F *selpi_ebyl_vs_mippion_sig = new TH2F("selpi_ebyl_vs_mippion_sig", "selpi_ebyl_vs_mippion_sig;ECal MipPion variable (dimensionless);ECal EM energy/ECal segment length (MeV/mm)",
                                          optimisation_nbins, -20, 50.0, optimisation_nbins, 0, 4.0);
   TH2F *selpi_ebyl_vs_mippion_bkg = new TH2F("selpi_ebyl_vs_mippion_bkg", "selpi_ebyl_vs_mippion_bkg;ECal MipPion variable (dimensionless);ECal EM energy/ECal segment length (MeV/mm)",
                                          optimisation_nbins, -20, 50.0, optimisation_nbins, 0, 4.0);
   
   Int_t bdt_optimisation_nbins = 50;
   
   TH2F *bdt_cut_optimisation_sig = new TH2F("bdt_cut_optimisation_sig", "bdt_cut_optimisation_sig;Antimuon candidate BDT mu-like;Pion candidate BDT pi-like",
                                          bdt_optimisation_nbins, 0.0, 1.0, bdt_optimisation_nbins, 0.0, 1.0);
   TH2F *bdt_cut_optimisation_bkg = new TH2F("bdt_cut_optimisation_bkg", "bdt_cut_optimisation_bkg;Antimuon candidate BDT mu-like;Pion candidate BDT pi-like",
                                          bdt_optimisation_nbins, 0.0, 1.0, bdt_optimisation_nbins, 0.0, 1.0);
   TH2F *bdt_cut_optimisation_signif = new TH2F("bdt_cut_optimisation_signif", "bdt_cut_optimisation_signif;Antimuon candidate BDT cut;Pion candidate BDT cut",
                                          bdt_optimisation_nbins, 0.0, 1.0, bdt_optimisation_nbins, 0.0, 1.0);
   Int_t cross_check_sig = 0;
   Int_t cross_check_bkg = 0;
   
   Int_t recomomdiff_nbins = 20;
   TH1F *recomom_diff_sig = new TH1F("recomom_diff_sig", "Signal;#mu^{+} candidate p_{reco} - #pi^{-} candidate p_{reco} (MeV/c); Events", 
                                     recomomdiff_nbins, -recomom_max, recomom_max);
   TH1F *recomom_diff_bkg = new TH1F("recomom_diff_bkg", "Background;#mu^{+} candidate p_{reco} - #pi^{-} candidate p_{reco} (MeV/c); Events", 
                                     recomomdiff_nbins, -recomom_max, recomom_max);
   TH1F *recomom_diff_sig_accum9 = new TH1F("recomom_diff_sig_accum9", "Signal;#mu^{+} candidate p_{reco} - #pi^{-} candidate p_{reco} (MeV/c); Events", 
                                            recomomdiff_nbins, -recomom_max, recomom_max);
   TH1F *recomom_diff_bkg_accum9 = new TH1F("recomom_diff_bkg_accum9", "Background;#mu^{+} candidate p_{reco} - #pi^{-} candidate p_{reco} (MeV/c); Events", 
                                            recomomdiff_nbins, -recomom_max, recomom_max);
   

   
   Int_t recotheta_nbins = 15;
   
   TH1F *recotheta_sig_presel = new TH1F("recotheta_sig_presel", "recotheta_sig_presel", recotheta_nbins, 0.0, 1.3);
   TH1F *recotheta_sig_sel = new TH1F("recotheta_sig_sel", "recotheta_sig_sel", recotheta_nbins, 0.0, 1.3);
   TH1F *recotheta_bkg_sel = new TH1F("recotheta_bkg_sel", "recotheta_bkg_sel", recotheta_nbins, 0.0, 1.3);
   
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      fChain->GetEntry(jentry);

      // Cut on accum_level etc
      //if (accum_level[0][0] <= 4) continue; // Set accum_level
      
      if ((limit_kinematics) && !((selmu_mom[0] > 200.0) && (selmu_mom[0] < 1500.0) && (selmu_det_theta < 1.0472) && (HMNT_mom > 200.0) && (HMNT_mom < 1500.0))) continue;
      if ((two_track_only) && !((ntpcposQualityFV==1) && (ntpcnegQualityFV==1))) continue;
      
      if (accum_level[0][1] > 2){
         
         if (topology == 1)
         {
            recomom_sig_presel->Fill(selmu_mom[0]);
            recotheta_sig_presel->Fill(selmu_det_theta);
         }
      }
      
      if (accum_level[0][1] > 4){
   
         if (particle == -13)
         {
            counter_selmu_antimu_accum4++;
         }
         
         if (particle == 211)
         {
            counter_selmu_piplus_accum4++;
         }
         
         if ((ntpcposQualityFV==1) && (ntpcnegQualityFV==1))
         {
            if (topology == 1)
            {
               bdt_cut_optimisation_sig->Fill(selmu_bdt_pid_mu, hmnt_bdt_pid_pi);
               if ((selmu_bdt_pid_mu > 0.26) && (hmnt_bdt_pid_pi > 0.12)) cross_check_sig++;
            }
            if (topology != 1)
            {
               bdt_cut_optimisation_bkg->Fill(selmu_bdt_pid_mu, hmnt_bdt_pid_pi);
               if ((selmu_bdt_pid_mu > 0.26) && (hmnt_bdt_pid_pi > 0.12)) cross_check_bkg++;
            }
            
         }
         
         if ((selmu_bdt_pid_mu > 0.26) && ((hmnt_bdt_pid_pi > 0.12) || (ntpcnegQualityFV == 0)))
         {
            if (topology == 1)
            {
               recomom_optsel_sig_sel->Fill(selmu_mom[0]);
            }
            if (topology != 1)
            {
               recomom_optsel_bkg_sel->Fill(selmu_mom[0]);
            }
            if (particle == -13)
            {
               recomom_optsel_antimu->Fill(selmu_mom[0]);
            }
            if (particle == 211)
            {
               recomom_optsel_piplus->Fill(selmu_mom[0]);
            }
            if (particle == 2212)
            {
               recomom_optsel_proton->Fill(selmu_mom[0]);
            }
            if (ntpcnegQualityFV == 1)
            {
               recomom_optsel_hmnt_all->Fill(HMNT_mom);
            
               if (HMNT_truepdg == -211)
               {
                  recomom_optsel_hmnt_piminus->Fill(HMNT_mom);
               }
            
               if (HMNT_truepdg == 13)
               {
                  recomom_optsel_hmnt_mu->Fill(HMNT_mom);
               }
            }
         }
      }
      
      if (accum_level[0][1] > 5){
         
         if (particle == -13)
         {
            counter_selmu_antimu_accum5++;
         }
         
         if (particle == 211)
         {
            counter_selmu_piplus_accum5++;
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
            if (particle == -13) {selmu_ebyl_vs_mippion_sig->Fill(selmu_ecal_bestseg_mippion, selmu_ecal_bestseg_EbyL);}
            if (particle != -13) {selmu_ebyl_vs_mippion_bkg->Fill(selmu_ecal_bestseg_mippion, selmu_ecal_bestseg_EbyL);}
         }
         
         if (topology == 0)
         {
            counter_cc0pi++;
         }
         
         if (topology == 1)
         {
            counter_cc1pi++;
         }
         
         if (topology == 2)
         {
            counter_ccother++;
         }
         
         if (topology == 3)
         {
            counter_bkg++;
         }
         
         if (topology == 7)
         {
            counter_oofv++;
         }
         
         if (particle == -13)
         {
            counter_selmu_antimu++;
            recomom_antimu->Fill(selmu_mom[0]);
            if (selmu_necals==1)
            {
               selmu_mippion_antimu->Fill(selmu_ecal_bestseg_mippion);
               selmu_mipem_antimu->Fill(selmu_ecal_mipem[0]);
               selmu_ebyl_antimu->Fill(selmu_ecal_bestseg_EbyL);
            }
         }
         
         if (particle == 13)
         {
            counter_selmu_mu++;
         }
         
         if (particle == 211)
         {
            counter_selmu_piplus++;
            recomom_piplus->Fill(selmu_mom[0]);
            if (selmu_necals==1)
            {
               selmu_mippion_piplus->Fill(selmu_ecal_bestseg_mippion);
               selmu_mipem_piplus->Fill(selmu_ecal_mipem[0]);
               selmu_ebyl_piplus->Fill(selmu_ecal_bestseg_EbyL);
            }
         }
         
         if (particle == -211)
         {
            counter_selmu_piminus++;
         }
         
         if (particle == 2212)
         {
            counter_selmu_proton++;
            recomom_proton->Fill(selmu_mom[0]);
            if (selmu_necals==1)
            {
               selmu_mippion_proton->Fill(selmu_ecal_bestseg_mippion);
               selmu_mipem_proton->Fill(selmu_ecal_mipem[0]);
               selmu_ebyl_proton->Fill(selmu_ecal_bestseg_EbyL);
            }
         }
         
         if (particle == -11)
         {
            counter_selmu_positron++;
         }
         
         if (particle == 11)
         {
            counter_selmu_electron++;
         }
         
         if (ntpcnegQualityFV == 1)
         {
            counter_selpi++;
            
            if (topology == 1){recomom_diff_sig->Fill(selmu_mom[0] - HMNT_mom);}
            if (topology != 1){recomom_diff_bkg->Fill(selmu_mom[0] - HMNT_mom);}
            
            if ((selmu_necals==0) && (HMNT_NEcalSegments==0))
            {
               counter_noecalinfo++;
            }
            
            if (HMNT_NEcalSegments==1)
            {
               counter_selpiecal++;
               selpi_ebyl_vs_mippion->Fill(HMNT_ecal_bestseg_mippion, HMNT_ecal_bestseg_EbyL);
               if (HMNT_truepdg == -211) {selpi_ebyl_vs_mippion_sig->Fill(HMNT_ecal_bestseg_mippion, HMNT_ecal_bestseg_EbyL);}
               if (HMNT_truepdg != -211) {selpi_ebyl_vs_mippion_bkg->Fill(HMNT_ecal_bestseg_mippion, HMNT_ecal_bestseg_EbyL);}
            }
            
            if (HMNT_truepdg == -211)
            {
               counter_selpi_piminus++;
               if (HMNT_NEcalSegments==1)
               {
                  selpi_mippion_piminus->Fill(HMNT_ecal_bestseg_mippion);
                  //selpi_mipem_piminus->Fill(selmu_ecal_mipem[0]);
                  selpi_ebyl_piminus->Fill(HMNT_ecal_bestseg_EbyL);
               }
            }
            
            if (HMNT_truepdg == 13)
            {
               counter_selpi_mu++;
               if (HMNT_NEcalSegments==1)
               {
                  selpi_mippion_mu->Fill(HMNT_ecal_bestseg_mippion);
                  //selmu_mipem_mu->Fill(selmu_ecal_mipem[0]);
                  selpi_ebyl_mu->Fill(HMNT_ecal_bestseg_EbyL);
               }
            }
            
            if (HMNT_truepdg == 11)
            {
               counter_selpi_electron++;
            }
            
            if (HMNT_truepdg == 2212)
            {
               counter_selpi_proton++;
            }
            
            
            
         }

      }
      
      if (accum_level[0][1] > 9){
            
         counter_all_accum9++;
         recomom_all_accum9->Fill(selmu_mom[0]);
            
         if (topology == 1)
         {
            counter_cc1pi_accum9++;
            recomom_sig_sel->Fill(selmu_mom[0]);
            recotheta_sig_sel->Fill(selmu_det_theta);
         }
         if (topology != 1)
         {
            //counter_cc1pi_accum9++;
            recomom_bkg_sel->Fill(selmu_mom[0]);
            recotheta_bkg_sel->Fill(selmu_det_theta);
         }
         if (topology == 3)
         {
            counter_bkg_accum9++;
         }
         if (particle == -13)
         {
            counter_selmu_antimu_accum9++;
            recomom_antimu_accum9->Fill(selmu_mom[0]);
         }
         if (particle == 211)
         {
            counter_selmu_piplus_accum9++;
            recomom_piplus_accum9->Fill(selmu_mom[0]);
         }
         if (particle == 2212)
         {
            counter_selmu_proton_accum9++;
            recomom_proton_accum9->Fill(selmu_mom[0]);
         }
         
         if ((selmu_mom[0] > 200) && (selmu_mom[0] < 1500) && (selmu_det_theta < 1.0472))
         {
            counter_selmu_bdtvalid++;
            if (particle == -13) {counter_selmu_antimu_bdtvalid++;}
            if (particle == 211) {counter_selmu_piplus_bdtvalid++;}
            if (particle == 2212) {counter_selmu_proton_bdtvalid++;}
         }
         
         if (ntpcnegQualityFV == 1)
         {
            counter_selpi_accum9++;
            recomom_hmnt_all->Fill(HMNT_mom);
            
            if (topology == 1){recomom_diff_sig_accum9->Fill(selmu_mom[0] - HMNT_mom);}
            if (topology != 1){recomom_diff_bkg_accum9->Fill(selmu_mom[0] - HMNT_mom);}
            
            if (HMNT_truepdg == -211)
            {
               counter_selpi_piminus_accum9++;
               recomom_hmnt_piminus->Fill(HMNT_mom);
            }
            
            if (HMNT_truepdg == 13)
            {
               counter_selpi_mu_accum9++;
               recomom_hmnt_mu->Fill(HMNT_mom);
            }
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
   
   std::cout << std::endl << "Events above accum_level 6: " << counter_all_accum6 << std::endl;
   std::cout << std::endl << "Events above accum_level 7: " << counter_all_accum7 << std::endl;
   
   std::cout << std::endl << "===== BEFORE ECAL CUTS: =====" << std::endl;
   
   std::cout << std::endl << "Significance: " << (float)counter_cc1pi/sqrt(counter_all_accum7);
   
   std::cout << std::endl << "True CC0pi: " << counter_cc0pi << " (" << 100*(float)counter_cc0pi/counter_all_accum7 << "\%)";
   std::cout << std::endl << "True CC1pi: " << counter_cc1pi << " (" << 100*(float)counter_cc1pi/counter_all_accum7 << "\%)";
   std::cout << std::endl << "True CC-Other: " << counter_ccother << " (" << 100*(float)counter_ccother/counter_all_accum7 << "\%)";
   std::cout << std::endl << "True BKG: " << counter_bkg << " (" << 100*(float)counter_bkg/counter_all_accum7 << "\%)";
   std::cout << std::endl << "True OOFV: " << counter_oofv << " (" << 100*(float)counter_oofv/counter_all_accum7 << "\%)";
   
   std::cout << std::endl << "Antimu candidate true antimu: " << counter_selmu_antimu << " (" << 100*(float)counter_selmu_antimu/counter_all_accum7 << "\%)";
   std::cout << std::endl << "Antimu candidate true mu: " << counter_selmu_mu << " (" << 100*(float)counter_selmu_mu/counter_all_accum7 << "\%)";
   std::cout << std::endl << "Antimu candidate true piplus: " << counter_selmu_piplus << " (" << 100*(float)counter_selmu_piplus/counter_all_accum7 << "\%)";
   std::cout << std::endl << "Antimu candidate true piminus: " << counter_selmu_piminus << " (" << 100*(float)counter_selmu_piminus/counter_all_accum7 << "\%)";
   std::cout << std::endl << "Antimu candidate true protons: " << counter_selmu_proton << " (" << 100*(float)counter_selmu_proton/counter_all_accum7 << "\%)";
   std::cout << std::endl << "Antimu candidate true positrons: " << counter_selmu_positron << " (" << 100*(float)counter_selmu_positron/counter_all_accum7 << "\%)";
   std::cout << std::endl << "Antimu candidate true electrons: " << counter_selmu_electron << " (" << 100*(float)counter_selmu_electron/counter_all_accum7 << "\%)";
   
   std::cout << std::endl << "Pi- candidates: " << counter_selpi << std::endl;
   std::cout << std::endl << "Pi- candidate true piminus: " << counter_selpi_piminus << " (" << 100*(float)counter_selpi_piminus/counter_selpi << "\%)";
   std::cout << std::endl << "Pi- candidate true muons: " << counter_selpi_mu << " (" << 100*(float)counter_selpi_mu/counter_selpi << "\%)";
   std::cout << std::endl << "Pi- candidate true electrons: " << counter_selpi_electron << " (" << 100*(float)counter_selpi_electron/counter_selpi << "\%)";
   std::cout << std::endl << "Pi- candidate true protons: " << counter_selpi_proton << " (" << 100*(float)counter_selpi_proton/counter_selpi << "\%)";
   
   std::cout << std::endl << "Mu/pi ratio before PID: " << (float)counter_selmu_antimu_accum4/counter_selmu_piplus_accum4;
   std::cout << std::endl << "Mu/pi ratio after PID: " << (float)counter_selmu_antimu_accum5/counter_selmu_piplus_accum5;
   
   std::cout << std::endl << "Mu+ candidate ECal efficiency: " << 100*(float)counter_selmuecal_accum7/counter_all_accum7 << "\%";
   std::cout << std::endl << "Pi- candidate ECal efficiency: " << 100*(float)counter_selpiecal/counter_selpi << "\%";
   std::cout << std::endl << "Events without ECal info: " << 100*(float)counter_noecalinfo/counter_all_accum7 << "\%";
   
   std::cout << std::endl << "===== AFTER ECAL CUTS: =====" << std::endl;
   
   std::cout << std::endl << "Significance: " << (float)counter_cc1pi_accum9/sqrt(counter_all_accum9);
   
   std::cout << std::endl << "Events above accum_level 9: " << counter_all_accum9;
   
   std::cout << std::endl << "True CC1pi: " << counter_cc1pi_accum9 << " (" << 100*(float)counter_cc1pi_accum9/counter_all_accum9 << "\%)";
   std::cout << std::endl << "True BKG: " << counter_bkg_accum9 << " (" << 100*(float)counter_bkg_accum9/counter_all_accum9 << "\%)";
   
   std::cout << std::endl << "Antimu candidate true antimu: " << counter_selmu_antimu_accum9 << " (" << 100*(float)counter_selmu_antimu_accum9/counter_all_accum9 << "\%)";
   std::cout << std::endl << "Antimu candidate true piplus: " << counter_selmu_piplus_accum9 << " (" << 100*(float)counter_selmu_piplus_accum9/counter_all_accum9 << "\%)";
   std::cout << std::endl << "Antimu candidate true protons: " << counter_selmu_proton_accum9 << " (" << 100*(float)counter_selmu_proton_accum9/counter_all_accum9 << "\%)";
   
   std::cout << std::endl << "Pi- candidates: " << counter_selpi_accum9 << std::endl;
   std::cout << std::endl << "Pi- candidate true piminus: " << counter_selpi_piminus_accum9 << " (" << 100*(float)counter_selpi_piminus_accum9/counter_selpi_accum9 << "\%)";
   std::cout << std::endl << "Pi- candidate true muons: " << counter_selpi_mu_accum9 << " (" << 100*(float)counter_selpi_mu_accum9/counter_selpi_accum9 << "\%)";
   
   std::cout << std::endl << "===== VALID FOR BDT PID: =====" << std::endl;
   
   std::cout << std::endl << "Antimuon candidates: " << counter_selmu_bdtvalid;
   std::cout << std::endl << "Antimu candidate true antimu: " << counter_selmu_antimu_bdtvalid << " (" << 100*(float)counter_selmu_antimu_bdtvalid/counter_selmu_bdtvalid << "\%)";
   std::cout << std::endl << "Antimu candidate true piplus: " << counter_selmu_piplus_bdtvalid << " (" << 100*(float)counter_selmu_piplus_bdtvalid/counter_selmu_bdtvalid << "\%)";
   std::cout << std::endl << "Antimu candidate true protons: " << counter_selmu_proton_bdtvalid << " (" << 100*(float)counter_selmu_proton_bdtvalid/counter_selmu_bdtvalid << "\%)";
   
   // Track purity plots (before ECal PID)
   
   TCanvas* canvas_selmu_antimu_purity = new TCanvas("canvas_selmu_antimu_purity","Antimu candidate track purity vs reconstructed momentum",200,10,1000,600);
   TGraph* graph_selmu_antimu_purity = new TGraph();
   graph_selmu_antimu_purity->SetTitle("#mu^{+};#mu^{+} candidate reconstructed momentum (MeV/c);#mu^{+} candidate track purity");
   for (Int_t bin=1; bin <= recomom_nbins; bin++)
   {
      Float_t purity = (float)(recomom_antimu->GetBinContent(bin))/(recomom_all->GetBinContent(bin));
      graph_selmu_antimu_purity->SetPoint(bin-1, recomom_all->GetBinCenter(bin), purity);
   }
   graph_selmu_antimu_purity->GetYaxis()->SetRangeUser(0.0, 1.0);
   graph_selmu_antimu_purity->SetLineColor( kBlue);
   graph_selmu_antimu_purity->SetFillColor( kWhite);
   graph_selmu_antimu_purity->SetLineWidth(2);
   graph_selmu_antimu_purity->Draw("AL");
   //canvas_selmu_antimu_purity->Write();
   
   //TCanvas* canvas_selmu_piplus_purity = new TCanvas("canvas_selmu_piplus_purity","Antimu candidate track pi+ contamination vs reconstructed momentum",200,10,1000,600);
   TGraph* graph_selmu_piplus_purity = new TGraph();
   graph_selmu_piplus_purity->SetTitle("#pi^{+}");
   for (Int_t bin=1; bin <= recomom_nbins; bin++)
   {
      Float_t purity = (float)(recomom_piplus->GetBinContent(bin))/(recomom_all->GetBinContent(bin));
      graph_selmu_piplus_purity->SetPoint(bin-1, recomom_all->GetBinCenter(bin), purity);
   }
   graph_selmu_piplus_purity->SetLineColor( kRed);
   graph_selmu_piplus_purity->SetFillColor( kWhite);
   graph_selmu_piplus_purity->SetLineWidth(2);
   graph_selmu_piplus_purity->Draw("L same");
   //canvas_selmu_piplus_purity->Write();
   
   //TCanvas* canvas_selmu_proton_purity = new TCanvas("canvas_selmu_proton_purity","Antimu candidate track proton contamination vs reconstructed momentum",200,10,1000,600);
   TGraph* graph_selmu_proton_purity = new TGraph();
   graph_selmu_proton_purity->SetTitle("p");
   for (Int_t bin=1; bin <= recomom_nbins; bin++)
   {
      Float_t purity = (float)(recomom_proton->GetBinContent(bin))/(recomom_all->GetBinContent(bin));
      graph_selmu_proton_purity->SetPoint(bin-1, recomom_all->GetBinCenter(bin), purity);
   }
   graph_selmu_proton_purity->SetLineColor( kGreen);
   graph_selmu_proton_purity->SetFillColor( kWhite);
   graph_selmu_proton_purity->SetLineWidth(2);
   graph_selmu_proton_purity->Draw("L same");
   //canvas_selmu_proton_purity->Write();
   
   canvas_selmu_antimu_purity->BuildLegend();
   canvas_selmu_antimu_purity->Write();
   
   // Track purity plots (after ECal PID)
   
   TCanvas* canvas_selmu_antimu_purity_accum9 = new TCanvas("canvas_selmu_antimu_purity_accum9","Antimu candidate track purity vs reconstructed momentum",200,10,1000,600);
   TGraph* graph_selmu_antimu_purity_accum9 = new TGraph();
   graph_selmu_antimu_purity_accum9->SetTitle("#mu^{+};#mu^{+} candidate reconstructed momentum (MeV/c);#mu^{+} candidate track purity");
   for (Int_t bin=1; bin <= recomom_nbins; bin++)
   {
      Float_t purity = (float)(recomom_antimu_accum9->GetBinContent(bin))/(recomom_all_accum9->GetBinContent(bin));
      graph_selmu_antimu_purity_accum9->SetPoint(bin-1, recomom_all_accum9->GetBinCenter(bin), purity);
   }
   graph_selmu_antimu_purity_accum9->GetYaxis()->SetRangeUser(0.0, 1.0);
   graph_selmu_antimu_purity_accum9->SetLineColor( kBlue);
   graph_selmu_antimu_purity_accum9->SetFillColor( kWhite);
   graph_selmu_antimu_purity_accum9->SetLineWidth(2);
   graph_selmu_antimu_purity_accum9->Draw("AL");
   
   TGraph* graph_selmu_piplus_purity_accum9 = new TGraph();
   graph_selmu_piplus_purity_accum9->SetTitle("#pi^{+}");
   for (Int_t bin=1; bin <= recomom_nbins; bin++)
   {
      Float_t purity = (float)(recomom_piplus_accum9->GetBinContent(bin))/(recomom_all_accum9->GetBinContent(bin));
      graph_selmu_piplus_purity_accum9->SetPoint(bin-1, recomom_all_accum9->GetBinCenter(bin), purity);
   }
   graph_selmu_piplus_purity_accum9->SetLineColor( kRed);
   graph_selmu_piplus_purity_accum9->SetFillColor( kWhite);
   graph_selmu_piplus_purity_accum9->SetLineWidth(2);
   graph_selmu_piplus_purity_accum9->Draw("L same");
   
   TGraph* graph_selmu_proton_purity_accum9 = new TGraph();
   graph_selmu_proton_purity_accum9->SetTitle("p");
   for (Int_t bin=1; bin <= recomom_nbins; bin++)
   {
      Float_t purity = (float)(recomom_proton_accum9->GetBinContent(bin))/(recomom_all_accum9->GetBinContent(bin));
      graph_selmu_proton_purity_accum9->SetPoint(bin-1, recomom_all_accum9->GetBinCenter(bin), purity);
   }
   graph_selmu_proton_purity_accum9->SetLineColor( kGreen);
   graph_selmu_proton_purity_accum9->SetFillColor( kWhite);
   graph_selmu_proton_purity_accum9->SetLineWidth(2);
   graph_selmu_proton_purity_accum9->Draw("L same");
   
   canvas_selmu_antimu_purity_accum9->BuildLegend();
   canvas_selmu_antimu_purity_accum9->Write();
   
   graph_selmu_antimu_purity_accum9->SetName("graph_selmu_antimu_purity");
   graph_selmu_antimu_purity_accum9->Write();
   graph_selmu_piplus_purity_accum9->SetName("graph_selmu_piplus_purity");
   graph_selmu_piplus_purity_accum9->Write();
   graph_selmu_proton_purity_accum9->SetName("graph_selmu_proton_purity");
   graph_selmu_proton_purity_accum9->Write();
   
   TCanvas* canvas_hmnt_purity = new TCanvas("canvas_hmnt_purity","canvas_hmnt_purity",200,10,1000,600);
   TGraph* graph_hmnt_piminus_purity = new TGraph();
   graph_hmnt_piminus_purity->SetTitle(" ;#pi^{-} candidate reconstructed momentum (MeV/c);Track purity;");
   for (Int_t bin=1; bin <= recomom_nbins; bin++)
   {
      Float_t purity = (float)(recomom_hmnt_piminus->GetBinContent(bin))/(recomom_hmnt_all->GetBinContent(bin));
      graph_hmnt_piminus_purity->SetPoint(bin-1, recomom_hmnt_all->GetBinCenter(bin), purity);
   }
   graph_hmnt_piminus_purity->GetYaxis()->SetRangeUser(0.0, 1.0);
   graph_hmnt_piminus_purity->SetLineColor( kRed);
   graph_hmnt_piminus_purity->SetFillColor( kWhite);
   graph_hmnt_piminus_purity->SetLineWidth(2);
   graph_hmnt_piminus_purity->Draw("AL");
   //canvas_selmu_antimu_purity->Write();
   
   TGraph* graph_hmnt_mu_purity = new TGraph();
   for (Int_t bin=1; bin <= recomom_nbins; bin++)
   {
      Float_t purity = (float)(recomom_hmnt_mu->GetBinContent(bin))/(recomom_hmnt_all->GetBinContent(bin));
      graph_hmnt_mu_purity->SetPoint(bin-1, recomom_hmnt_all->GetBinCenter(bin), purity);
   }
   graph_hmnt_mu_purity->SetLineColor( kBlue);
   graph_hmnt_mu_purity->SetFillColor( kWhite);
   graph_hmnt_mu_purity->SetLineWidth(2);
   graph_hmnt_mu_purity->Draw("L same");
   //canvas_selmu_piplus_purity->Write();

   canvas_hmnt_purity->BuildLegend();
   canvas_hmnt_purity->Write();
   
   graph_hmnt_piminus_purity->SetName("graph_hmnt_piminus_purity");
   graph_hmnt_piminus_purity->Write();
   graph_hmnt_mu_purity->SetName("graph_hmnt_mu_purity");
   graph_hmnt_mu_purity->Write();
   
   // MipPion plots
   
   TCanvas* canvas_mippion = new TCanvas("canvas_mippion","",200,10,1000,400);
   canvas_mippion->Divide(2,1,0.005,0.005);
   canvas_mippion->cd(1);
   SetHistParticleStyle(selmu_mippion_antimu, "antimu");
   SetHistParticleStyle(selmu_mippion_piplus, "piplus");
   SetHistParticleStyle(selmu_mippion_proton, "proton");
   selmu_mippion_antimu->Draw();
   selmu_mippion_piplus->Draw("same");
   selmu_mippion_proton->Draw("same");
   canvas_mippion->cd(1)->BuildLegend();
   
   canvas_mippion->cd(2);
   SetHistParticleStyle(selpi_mippion_mu, "antimu");
   SetHistParticleStyle(selpi_mippion_piminus, "piplus");
   selpi_mippion_piminus->Draw();
   selpi_mippion_mu->Draw("same");
   canvas_mippion->cd(2)->BuildLegend();
   canvas_mippion->Write();
   
   // MipEm plots
   
   TCanvas* canvas_mipem = new TCanvas("canvas_mipem","",200,10,1000,400);
   canvas_mipem->Divide(2,1,0.005,0.005);
   canvas_mipem->cd(1);
   SetHistParticleStyle(selmu_mipem_antimu, "antimu");
   SetHistParticleStyle(selmu_mipem_piplus, "piplus");
   SetHistParticleStyle(selmu_mipem_proton, "proton");
   selmu_mipem_antimu->Draw();
   selmu_mipem_piplus->Draw("same");
   selmu_mipem_proton->Draw("same");
   canvas_mipem->cd(1)->BuildLegend();
   
   canvas_mipem->cd(2);
   SetHistParticleStyle(selpi_mipem_mu, "antimu");
   SetHistParticleStyle(selpi_mipem_piminus, "piplus");
   selpi_mipem_piminus->Draw();
   selpi_mipem_mu->Draw("same");
   canvas_mipem->cd(2)->BuildLegend();
   canvas_mipem->Write();
   
   // E/L plots
   
   TCanvas* canvas_ebyl = new TCanvas("canvas_ebyl","",200,10,1000,400);
   canvas_ebyl->Divide(2,1,0.005,0.005);
   canvas_ebyl->cd(1);
   selmu_ebyl_antimu->GetYaxis()->SetRangeUser(1.0, 5000.0);
   SetHistParticleStyle(selmu_ebyl_antimu, "antimu");
   SetHistParticleStyle(selmu_ebyl_piplus, "piplus");
   SetHistParticleStyle(selmu_ebyl_proton, "proton");
   selmu_ebyl_antimu->Draw();
   selmu_ebyl_piplus->Draw("same");
   selmu_ebyl_proton->Draw("same");
   canvas_ebyl->cd(1)->BuildLegend();
   canvas_ebyl->cd(1)->SetLogy();
   
   canvas_ebyl->cd(2);
   selpi_ebyl_piminus->GetYaxis()->SetRangeUser(1.0, 3000.0);
   SetHistParticleStyle(selpi_ebyl_mu, "antimu");
   SetHistParticleStyle(selpi_ebyl_piminus, "piplus");
   selpi_ebyl_piminus->Draw();
   selpi_ebyl_mu->Draw("same");
   canvas_ebyl->cd(2)->BuildLegend();
   canvas_ebyl->cd(2)->SetLogy();
   canvas_ebyl->Write();
   
   // Correlation plots:
   
   std::cout << std::endl << "Mu+ candidate mippion-E/L correlation: " << selmu_ebyl_vs_mippion->GetCorrelationFactor() << std::endl;
   TCanvas* canvas_selmu_ebyl_vs_mippion = new TCanvas("canvas_selmu_ebyl_vs_mippion","",200,10,1000,800);
   selmu_ebyl_vs_mippion->Draw("colz");
   canvas_selmu_ebyl_vs_mippion->Write();
   
   std::cout << std::endl << "Pi- candidate mippion-E/L correlation: " << selpi_ebyl_vs_mippion->GetCorrelationFactor() << std::endl;
   TCanvas* canvas_selpi_ebyl_vs_mippion = new TCanvas("canvas_selpi_ebyl_vs_mippion","",200,10,1000,800);
   selpi_ebyl_vs_mippion->Draw("colz");
   canvas_selpi_ebyl_vs_mippion->Write();
   
   // Mu candidate optimisation:
   
   Float_t optimal_signif = 0;
   Float_t opt_cut_signif_mippion = 0;
   Float_t opt_cut_signif_ebyl = 0;
   Float_t optimal_effpur = 0;
   Float_t opt_cut_effpur_mippion = 0;
   Float_t opt_cut_effpur_ebyl = 0;
   TGraph2D* graph_selmu_ebyl_vs_mippion_signif = new TGraph2D();
   graph_selmu_ebyl_vs_mippion_signif->SetTitle("graph_selmu_ebyl_vs_mippion_signif; MipPion; E/L; Significance");
   TGraph2D* graph_selmu_ebyl_vs_mippion_effpur = new TGraph2D();
   graph_selmu_ebyl_vs_mippion_effpur->SetTitle("; Cut on ECal MipPion; Cut on ECal E/L; #mu^{+} candidate efficiency*purity");
   Int_t graphpoint = 0;
   for (Int_t cutx=1; cutx <= optimisation_nbins; cutx++)
   {
      for (Int_t cuty=1; cuty <= optimisation_nbins; cuty++)
      {
         Float_t passed_sig = selmu_ebyl_vs_mippion_sig->GetEntries() - selmu_ebyl_vs_mippion_sig->Integral(cutx,optimisation_nbins,cuty,optimisation_nbins);
         Float_t passed_bkg = selmu_ebyl_vs_mippion_bkg->GetEntries() - selmu_ebyl_vs_mippion_bkg->Integral(cutx,optimisation_nbins,cuty,optimisation_nbins);

         Float_t significance = passed_sig/sqrt(passed_sig + passed_bkg);
         Float_t purity = passed_sig/(passed_sig+passed_bkg);
         Float_t efficiency = passed_sig/(selmu_ebyl_vs_mippion_sig->GetEntries());
         if (passed_sig == 0){significance = 0; purity = 0;}
      
         selmu_ebyl_vs_mippion_signif->SetBinContent(cutx, cuty, significance);
         graph_selmu_ebyl_vs_mippion_signif->SetPoint(graphpoint, selmu_ebyl_vs_mippion_sig->ProjectionX()->GetBinLowEdge(cutx), 
                                                                  selmu_ebyl_vs_mippion_sig->ProjectionY()->GetBinLowEdge(cuty), significance);
         graph_selmu_ebyl_vs_mippion_effpur->SetPoint(graphpoint, selmu_ebyl_vs_mippion_sig->ProjectionX()->GetBinLowEdge(cutx), 
                                                                  selmu_ebyl_vs_mippion_sig->ProjectionY()->GetBinLowEdge(cuty), efficiency*purity);
         graphpoint++;
            
         if (significance > optimal_signif)
         {
            optimal_signif = significance;
            opt_cut_signif_mippion = selmu_ebyl_vs_mippion_sig->ProjectionX()->GetBinLowEdge(cutx);
            opt_cut_signif_ebyl = selmu_ebyl_vs_mippion_sig->ProjectionY()->GetBinLowEdge(cuty);
         }
         if (efficiency*purity > optimal_effpur)
         {
            optimal_effpur = efficiency*purity;
            opt_cut_effpur_mippion = selmu_ebyl_vs_mippion_sig->ProjectionX()->GetBinLowEdge(cutx);
            opt_cut_effpur_ebyl = selmu_ebyl_vs_mippion_sig->ProjectionY()->GetBinLowEdge(cuty);
         }
      }
   }
   
   std::cout << "Optimal muon candidate significance = " << optimal_signif << " at cut MipPion = " << opt_cut_signif_mippion << ", E/L = " << opt_cut_signif_ebyl << std::endl;
   std::cout << "Optimal muon candidate eff*pur = " << optimal_effpur << " at cut MipPion = " << opt_cut_effpur_mippion << ", E/L = " << opt_cut_effpur_ebyl << std::endl;
   
   TCanvas* canvas_selmu_ebyl_vs_mippion_signif = new TCanvas("canvas_selmu_ebyl_vs_mippion_signif","",200,10,1000,800);
   //selmu_ebyl_vs_mippion_signif->Draw("colz");
   graph_selmu_ebyl_vs_mippion_signif->Draw("surf1");
   canvas_selmu_ebyl_vs_mippion_signif->Write();
   
   TCanvas* canvas_selmu_ebyl_vs_mippion_effpur = new TCanvas("canvas_selmu_ebyl_vs_mippion_effpur","",200,10,1000,800);
   graph_selmu_ebyl_vs_mippion_effpur->Draw("surf1");
   canvas_selmu_ebyl_vs_mippion_effpur->Write();
   
   // Pi candidate optimisation:
   
   optimal_signif = 0;
   opt_cut_signif_mippion = 0;
   opt_cut_signif_ebyl = 0;
   optimal_effpur = 0;
   opt_cut_effpur_mippion = 0;
   opt_cut_effpur_ebyl = 0;
   TGraph2D* graph_selpi_ebyl_vs_mippion_signif = new TGraph2D();
   graph_selpi_ebyl_vs_mippion_signif->SetTitle("graph_selpi_ebyl_vs_mippion_signif; MipPion; E/L; Significance");
   TGraph2D* graph_selpi_ebyl_vs_mippion_effpur = new TGraph2D();
   graph_selpi_ebyl_vs_mippion_effpur->SetTitle("; Cut on ECal MipPion; Cut on ECal E/L; #pi^{-} candidate efficiency*purity");
   graphpoint = 0;
   for (Int_t cutx=1; cutx <= optimisation_nbins; cutx++)
   {
      for (Int_t cuty=1; cuty <= optimisation_nbins; cuty++)
      {
         Float_t passed_sig = selpi_ebyl_vs_mippion_sig->Integral(cutx,optimisation_nbins,cuty,optimisation_nbins);
         Float_t passed_bkg = selpi_ebyl_vs_mippion_bkg->Integral(cutx,optimisation_nbins,cuty,optimisation_nbins);

         Float_t significance = passed_sig/sqrt(passed_sig + passed_bkg);
         Float_t purity = passed_sig/(passed_sig+passed_bkg);
         Float_t efficiency = passed_sig/(selpi_ebyl_vs_mippion_sig->GetEntries());
         if (passed_sig == 0){significance = 0; purity = 0;}
      
         graph_selpi_ebyl_vs_mippion_signif->SetPoint(graphpoint, selpi_ebyl_vs_mippion_sig->ProjectionX()->GetBinLowEdge(cutx), 
                                                                  selpi_ebyl_vs_mippion_sig->ProjectionY()->GetBinLowEdge(cuty), significance);
         graph_selpi_ebyl_vs_mippion_effpur->SetPoint(graphpoint, selpi_ebyl_vs_mippion_sig->ProjectionX()->GetBinLowEdge(cutx), 
                                                                  selpi_ebyl_vs_mippion_sig->ProjectionY()->GetBinLowEdge(cuty), efficiency*purity);
         graphpoint++;
            
         if (significance > optimal_signif)
         {
            optimal_signif = significance;
            opt_cut_signif_mippion = selpi_ebyl_vs_mippion_sig->ProjectionX()->GetBinLowEdge(cutx);
            opt_cut_signif_ebyl = selpi_ebyl_vs_mippion_sig->ProjectionY()->GetBinLowEdge(cuty);
         }
         if (efficiency*purity > optimal_effpur)
         {
            optimal_effpur = efficiency*purity;
            opt_cut_effpur_mippion = selpi_ebyl_vs_mippion_sig->ProjectionX()->GetBinLowEdge(cutx);
            opt_cut_effpur_ebyl = selpi_ebyl_vs_mippion_sig->ProjectionY()->GetBinLowEdge(cuty);
         }
      }
   }
   
   std::cout << "Optimal pion candidate significance = " << optimal_signif << " at cut MipPion = " << opt_cut_signif_mippion << ", E/L = " << opt_cut_signif_ebyl << std::endl;
   std::cout << "Optimal pion candidate eff*pur = " << optimal_effpur << " at cut MipPion = " << opt_cut_effpur_mippion << ", E/L = " << opt_cut_effpur_ebyl << std::endl;
   
   TCanvas* canvas_selpi_ebyl_vs_mippion_signif = new TCanvas("canvas_selpi_ebyl_vs_mippion_signif","",200,10,1000,800);
   //selpi_ebyl_vs_mippion_signif->Draw("colz");
   graph_selpi_ebyl_vs_mippion_signif->Draw("surf1");
   canvas_selpi_ebyl_vs_mippion_signif->Write();
   
   TCanvas* canvas_selpi_ebyl_vs_mippion_effpur = new TCanvas("canvas_selpi_ebyl_vs_mippion_effpur","",200,10,1000,800);
   graph_selpi_ebyl_vs_mippion_effpur->Draw("surf1");
   canvas_selpi_ebyl_vs_mippion_effpur->Write();
   
   selpi_ebyl_vs_mippion_sig->Write();
   selpi_ebyl_vs_mippion_bkg->Write();
   
   // Momentum difference:
   
   //recomom_diff_sig->Write();
   //recomom_diff_bkg->Write();
   
   //recomom_diff_sig_accum9->Write();
   //recomom_diff_bkg_accum9->Write();
   
   TCanvas* canvas_momdiff = new TCanvas("canvas_momdiff","",200,10,1000,400);
   canvas_momdiff->Divide(2,1,0.005,0.005);
   canvas_momdiff->cd(1);
   SetHistParticleStyle(recomom_diff_sig, "antimu");
   SetHistParticleStyle(recomom_diff_bkg, "piplus");
   recomom_diff_sig->Draw();
   recomom_diff_bkg->Draw("same");
   canvas_momdiff->cd(1)->BuildLegend();
   canvas_momdiff->cd(2);
   SetHistParticleStyle(recomom_diff_sig_accum9, "antimu");
   SetHistParticleStyle(recomom_diff_bkg_accum9, "piplus");
   recomom_diff_sig_accum9->Draw();
   recomom_diff_bkg_accum9->Draw("same");
   canvas_momdiff->Write();
   
   // Effpur plots
   
   TCanvas* canvas_effpur_vs_recomom = new TCanvas("canvas_effpur_vs_recomom","canvas_effpur_vs_recomom",200,10,1000,600);
   TGraph* graph_pur_vs_recomom = new TGraph();
   graph_pur_vs_recomom->SetTitle(" ;#mu^{+} candidate reconstructed momentum (MeV/c);Improved #bar{#nu}_{#mu} CC1pi- selection purity, efficiency");
   TGraph* graph_eff_vs_recomom = new TGraph();
   graph_eff_vs_recomom->SetTitle(" ;#mu^{+} candidate reconstructed momentum (MeV/c);");
   TGraph* graph_effpur_vs_recomom = new TGraph();
   TGraph* graph_signif_vs_recomom = new TGraph();
   
   for (Int_t bin=1; bin <= recomom_nbins; bin++)
   {
      Float_t signal = recomom_sig_sel->GetBinContent(bin);
      Float_t background = recomom_bkg_sel->GetBinContent(bin);
      Float_t sig_presel = recomom_sig_presel->GetBinContent(bin);
      
      Float_t purity = signal/(signal+background);
      Float_t efficiency = signal/sig_presel;
      Float_t significance = signal/sqrt(signal+background);
      if (signal == 0){purity = 0; significance = 0;}

      graph_pur_vs_recomom->SetPoint(bin-1, recomom_sig_sel->GetBinCenter(bin), purity);
      graph_eff_vs_recomom->SetPoint(bin-1, recomom_sig_sel->GetBinCenter(bin), efficiency);
      graph_effpur_vs_recomom->SetPoint(bin-1, recomom_sig_sel->GetBinCenter(bin), efficiency*purity);
      graph_signif_vs_recomom->SetPoint(bin-1, recomom_sig_sel->GetBinCenter(bin), significance);
   }
   
   graph_pur_vs_recomom->GetYaxis()->SetRangeUser(0.0, 1.0);
   graph_pur_vs_recomom->SetLineWidth(2);
   graph_pur_vs_recomom->SetFillColor(kWhite);
   graph_pur_vs_recomom->Draw("AL");
   graph_eff_vs_recomom->SetLineWidth(2);
   graph_eff_vs_recomom->SetLineColor(kRed);
   graph_eff_vs_recomom->SetFillColor(kWhite);
   graph_eff_vs_recomom->Draw("L same");
   canvas_effpur_vs_recomom->BuildLegend();
   canvas_effpur_vs_recomom->Write();
   
   graph_effpur_vs_recomom->SetLineWidth(2);
   graph_effpur_vs_recomom->SetFillColor(kWhite);
   graph_signif_vs_recomom->SetLineWidth(2);
   graph_signif_vs_recomom->SetFillColor(kWhite);
   
   graph_pur_vs_recomom->SetName("graph_pur_vs_recomom");
   graph_eff_vs_recomom->SetName("graph_eff_vs_recomom");
   graph_effpur_vs_recomom->SetName("graph_effpur_vs_recomom");
   graph_signif_vs_recomom->SetName("graph_signif_vs_recomom");
   graph_pur_vs_recomom->Write();
   graph_eff_vs_recomom->Write();
   graph_effpur_vs_recomom->Write();
   graph_signif_vs_recomom->Write();
   
   
   
   TCanvas* canvas_effpur_vs_recotheta = new TCanvas("canvas_effpur_vs_recotheta","canvas_effpur_vs_recotheta",200,10,1000,600);
   TGraph* graph_pur_vs_recotheta = new TGraph();
   graph_pur_vs_recotheta->SetTitle("Purity;#mu^{+} candidate reconstructed angle (degrees);Improved #bar{#nu}_{#mu} CC1pi- selection purity, efficiency");
   TGraph* graph_eff_vs_recotheta = new TGraph();
   graph_eff_vs_recotheta->SetTitle("Efficiency");
   
   for (Int_t bin=1; bin <= recotheta_nbins; bin++)
   {
      Float_t signal = recotheta_sig_sel->GetBinContent(bin);
      Float_t background = recotheta_bkg_sel->GetBinContent(bin);
      Float_t sig_presel = recotheta_sig_presel->GetBinContent(bin);
      
      Float_t purity = signal/(signal+background);
      Float_t efficiency = signal/sig_presel;
      if (signal == 0){purity = 0;}

      graph_pur_vs_recotheta->SetPoint(bin-1, recotheta_sig_sel->GetBinCenter(bin)*57.2958, purity);
      graph_eff_vs_recotheta->SetPoint(bin-1, recotheta_sig_sel->GetBinCenter(bin)*57.2958, efficiency);
   }
   
   graph_pur_vs_recotheta->GetYaxis()->SetRangeUser(0.0, 1.0);
   graph_pur_vs_recotheta->SetLineWidth(2);
   graph_pur_vs_recotheta->SetFillColor(kWhite);
   graph_pur_vs_recotheta->Draw("AL");
   graph_eff_vs_recotheta->SetLineWidth(2);
   graph_eff_vs_recotheta->SetLineColor(kRed);
   graph_eff_vs_recotheta->SetFillColor(kWhite);
   graph_eff_vs_recotheta->Draw("L same");
   canvas_effpur_vs_recotheta->BuildLegend();
   canvas_effpur_vs_recotheta->Write();
   
   // Effpur (optimised BDT selection)
   
   TCanvas* canvas_effpur_vs_recomom_optsel = new TCanvas("canvas_effpur_vs_recomom_optsel","canvas_effpur_vs_recomom_optsel",200,10,1000,600);
   TGraph* graph_pur_vs_recomom_optsel = new TGraph();
   graph_pur_vs_recomom_optsel->SetTitle(" ;#mu^{+} candidate reconstructed momentum (MeV/c);Optimised BDT #bar{#nu}_{#mu} CC1pi- selection purity, efficiency");
   TGraph* graph_eff_vs_recomom_optsel = new TGraph();
   graph_eff_vs_recomom_optsel->SetTitle(" ;#mu^{+} candidate reconstructed momentum (MeV/c);");
   TGraph* graph_effpur_vs_recomom_optsel = new TGraph();
   TGraph* graph_signif_vs_recomom_optsel = new TGraph();
   
   for (Int_t bin=1; bin <= recomom_nbins; bin++)
   {
      Float_t signal = recomom_optsel_sig_sel->GetBinContent(bin);
      Float_t background = recomom_optsel_bkg_sel->GetBinContent(bin);
      Float_t sig_presel = recomom_sig_presel->GetBinContent(bin);
      
      Float_t purity = signal/(signal+background);
      Float_t efficiency = signal/sig_presel;
      Float_t significance = signal/sqrt(signal+background);
      if (signal == 0){purity = 0; significance = 0;}

      graph_pur_vs_recomom_optsel->SetPoint(bin-1, recomom_optsel_sig_sel->GetBinCenter(bin), purity);
      graph_eff_vs_recomom_optsel->SetPoint(bin-1, recomom_optsel_sig_sel->GetBinCenter(bin), efficiency);
      graph_effpur_vs_recomom_optsel->SetPoint(bin-1, recomom_optsel_sig_sel->GetBinCenter(bin), efficiency*purity);
      graph_signif_vs_recomom_optsel->SetPoint(bin-1, recomom_optsel_sig_sel->GetBinCenter(bin), significance);
   }
   
   graph_pur_vs_recomom_optsel->GetYaxis()->SetRangeUser(0.0, 1.0);
   graph_pur_vs_recomom_optsel->SetLineWidth(2);
   graph_pur_vs_recomom_optsel->SetFillColor(kWhite);
   graph_pur_vs_recomom_optsel->Draw("AL");
   graph_eff_vs_recomom_optsel->SetLineWidth(2);
   graph_eff_vs_recomom_optsel->SetLineColor(kRed);
   graph_eff_vs_recomom_optsel->SetFillColor(kWhite);
   graph_eff_vs_recomom_optsel->Draw("L same");
   canvas_effpur_vs_recomom_optsel->BuildLegend();
   canvas_effpur_vs_recomom_optsel->Write();
   
   graph_effpur_vs_recomom_optsel->SetLineWidth(2);
   graph_effpur_vs_recomom_optsel->SetFillColor(kWhite);
   graph_signif_vs_recomom_optsel->SetLineWidth(2);
   graph_signif_vs_recomom_optsel->SetFillColor(kWhite);
   
   graph_pur_vs_recomom_optsel->SetName("graph_pur_vs_recomom_optsel");
   graph_eff_vs_recomom_optsel->SetName("graph_eff_vs_recomom_optsel");
   graph_effpur_vs_recomom_optsel->SetName("graph_effpur_vs_recomom_optsel");
   graph_signif_vs_recomom_optsel->SetName("graph_signif_vs_recomom_optsel");
   graph_pur_vs_recomom_optsel->Write();
   graph_eff_vs_recomom_optsel->Write();
   graph_effpur_vs_recomom_optsel->Write();
   graph_signif_vs_recomom_optsel->Write();
   
   // BDT cuts optimisation
   
   optimal_signif = 0;
   Float_t opt_cut_signif_mu = 0;
   Float_t opt_cut_signif_pi = 0;
   TGraph2D* graph_bdt_cut_optimisation_signif = new TGraph2D();
   graph_bdt_cut_optimisation_signif->SetTitle("graph_bdt_cut_optimisation_signif; Antimuon candidate BDT cut; Pion candidate BDT cut; Significance");
   graphpoint = 0;
   for (Int_t cutx=1; cutx <= bdt_optimisation_nbins; cutx++)
   {
      for (Int_t cuty=1; cuty <= bdt_optimisation_nbins; cuty++)
      {
         Float_t passed_sig = bdt_cut_optimisation_sig->Integral(cutx,bdt_optimisation_nbins,cuty,bdt_optimisation_nbins);
         Float_t passed_bkg = bdt_cut_optimisation_bkg->Integral(cutx,bdt_optimisation_nbins,cuty,bdt_optimisation_nbins);

         Float_t significance = passed_sig/sqrt(passed_sig + passed_bkg);
         if (passed_sig == 0){significance = 0;}
      
         bdt_cut_optimisation_signif->SetBinContent(cutx, cuty, significance);
         graph_bdt_cut_optimisation_signif->SetPoint(graphpoint, bdt_cut_optimisation_sig->ProjectionX()->GetBinLowEdge(cutx), 
                                                                  bdt_cut_optimisation_sig->ProjectionY()->GetBinLowEdge(cuty), significance);
         graphpoint++;
            
         if (significance > optimal_signif)
         {
            optimal_signif = significance;
            opt_cut_signif_mu = bdt_cut_optimisation_sig->ProjectionX()->GetBinLowEdge(cutx);
            opt_cut_signif_pi = bdt_cut_optimisation_sig->ProjectionY()->GetBinLowEdge(cuty);
         }
      }
   }
   
   std::cout << "Optimal CC1pi significance = " << optimal_signif << " at cut BDT mu-like  = " << opt_cut_signif_mu << ", pi-like = " << opt_cut_signif_pi << std::endl;
   // Cross-check:
   std::cout << "Cross-check CC1pi significance = " << cross_check_sig/sqrt(cross_check_sig+cross_check_bkg) << std::endl;
   
   TCanvas* canvas_bdt_cut_optimisation_signif = new TCanvas("canvas_bdt_cut_optimisation_signif","",200,10,1000,800);
   //graph_bdt_cut_optimisation_signif->Draw("surf1");
   graph_bdt_cut_optimisation_signif->Draw("colz");
   canvas_bdt_cut_optimisation_signif->Write();
   
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
