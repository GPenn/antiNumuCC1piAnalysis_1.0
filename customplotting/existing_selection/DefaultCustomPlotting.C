#define DefaultCustomPlotting_cxx
#include "DefaultCustomPlotting.h"
#include <TH2.h>
#include <TGraph.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <THStack.h>
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
   
   Bool_t limit_kinematics = false;
   Bool_t two_track_only = false;
   
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntries();
   
   std::cout << "Total entries to process: " << nentries << std::endl << std::endl;
   
   std::time_t time_start = std::time(0);
   
   Int_t counter_all_accum8 = 0, counter_all_accum7 = 0;
   Int_t counter_cc1pi = 0, counter_cc0pi = 0, counter_ccother = 0, counter_bkg = 0, counter_oofv = 0;
   Int_t counter_selmu_antimu = 0, counter_selmu_piplus = 0, counter_selmu_proton = 0, counter_selmu_positron = 0, counter_selmu_mu = 0, counter_selmu_piminus = 0, counter_selmu_electron = 0;
   Int_t counter_selpi = 0, counter_selpi_piminus = 0, counter_selpi_mu = 0, counter_selpi_electron = 0, counter_selpi_proton = 0;
   Int_t counter_selmu_antimu_accum5 = 0, counter_selmu_antimu_accum6 = 0, counter_selmu_piplus_accum5 = 0, counter_selmu_piplus_accum6 = 0;
   Int_t counter_beforeprimaryPID_sig = 0, counter_beforeprimaryPID_bkg = 0, counter_afterprimaryPID_sig = 0, counter_afterprimaryPID_bkg = 0;
   Int_t counter_beforesecondaryPID_sig = 0, counter_beforesecondaryPID_bkg = 0, counter_aftersecondaryPID_sig = 0, counter_aftersecondaryPID_bkg = 0;
   
   Int_t recomom_nbins = 8;
   
   TH1F *recomom_all;
   TH1F *recomom_antimu;
   TH1F *recomom_piplus;
   TH1F *recomom_proton;
   
   TH1F *recomom_hmnt_all;
   TH1F *recomom_hmnt_piminus;
   TH1F *recomom_hmnt_mu;
   
   TH1F *recomom_sig_presel;
   TH1F *recomom_sig_sel;
   TH1F *recomom_bkg_sel;
   
   TH1F *recomom_exsel_cc0pi;
   TH1F *recomom_exsel_cc1pi;
   TH1F *recomom_exsel_ccother;
   TH1F *recomom_exsel_bkg;
   TH1F *recomom_exsel_oofv;
   TH1F *recomom_exsel_numubarccbkg;
   TH1F *recomom_exsel_numucc;
   TH1F *recomom_exsel_otherbkg;
   
   TH1F *recopimom_exsel_cc0pi;
   TH1F *recopimom_exsel_cc1pi;
   TH1F *recopimom_exsel_ccother;
   TH1F *recopimom_exsel_bkg;
   TH1F *recopimom_exsel_oofv;
   TH1F *recopimom_exsel_numubarccbkg;
   TH1F *recopimom_exsel_numucc;
   TH1F *recopimom_exsel_otherbkg;
   
   if (limit_kinematics)
   {
      recomom_all = new TH1F("recomom_all", "Events vs reco momentum", recomom_nbins, 200.0, 1500.0);
      recomom_antimu = new TH1F("recomom_antimu", "True antimu vs reco momentum", recomom_nbins, 200.0, 1500.0);
      recomom_piplus = new TH1F("recomom_piplus", "True piplus vs reco momentum", recomom_nbins, 200.0, 1500.0);
      recomom_proton = new TH1F("recomom_proton", "True protons vs reco momentum", recomom_nbins, 200.0, 1500.0);
      
      recomom_hmnt_all = new TH1F("recomom_hmnt_all", "Events vs HMNT reco momentum", recomom_nbins, 200.0, 1500.0);
      recomom_hmnt_piminus = new TH1F("recomom_hmnt_piminus", "True piminus vs HMNT reco momentum", recomom_nbins, 200.0, 1500.0);
      recomom_hmnt_mu = new TH1F("recomom_hmnt_mu", "True mu vs HMNT reco momentum", recomom_nbins, 200.0, 1500.0);
      
      recomom_sig_presel = new TH1F("recomom_sig_presel", "recomom_sig_presel", recomom_nbins, 200.0, 1500.0);
      recomom_sig_sel = new TH1F("recomom_sig_sel", "recomom_sig_sel", recomom_nbins, 200.0, 1500.0);
      recomom_bkg_sel = new TH1F("recomom_bkg_sel", "recomom_bkg_sel", recomom_nbins, 200.0, 1500.0);
      
      recomom_exsel_cc0pi = new TH1F("recomom_exsel_cc0pi", "recomom_exsel_cc0pi", recomom_nbins, 200.0, 1500.0);
      recomom_exsel_cc1pi = new TH1F("recomom_exsel_cc1pi", "recomom_exsel_cc1pi", recomom_nbins, 200.0, 1500.0);
      recomom_exsel_ccother = new TH1F("recomom_exsel_ccother", "recomom_exsel_ccother", recomom_nbins, 200.0, 1500.0);
      recomom_exsel_bkg = new TH1F("recomom_exsel_bkg", "recomom_exsel_bkg", recomom_nbins, 200.0, 1500.0);
      recomom_exsel_oofv = new TH1F("recomom_exsel_oofv", "recomom_exsel_oofv", recomom_nbins, 200.0, 1500.0);
      recomom_exsel_numubarccbkg = new TH1F("recomom_exsel_numubarccbkg", "recomom_exsel_numubarccbkg", recomom_nbins, 200.0, 1500.0);
      recomom_exsel_numucc = new TH1F("recomom_exsel_numucc", "recomom_exsel_numucc", recomom_nbins, 200.0, 1500.0);
      recomom_exsel_otherbkg = new TH1F("recomom_exsel_otherbkg", "recomom_exsel_otherbkg", recomom_nbins, 200.0, 1500.0);
      
      recopimom_exsel_cc0pi = new TH1F("recopimom_exsel_cc0pi", "recopimom_exsel_cc0pi", recomom_nbins, 200.0, 1500.0);
      recopimom_exsel_cc1pi = new TH1F("recopimom_exsel_cc1pi", "recopimom_exsel_cc1pi", recomom_nbins, 200.0, 1500.0);
      recopimom_exsel_ccother = new TH1F("recopimom_exsel_ccother", "recopimom_exsel_ccother", recomom_nbins, 200.0, 1500.0);
      recopimom_exsel_bkg = new TH1F("recopimom_exsel_bkg", "recopimom_exsel_bkg", recomom_nbins, 200.0, 1500.0);
      recopimom_exsel_oofv = new TH1F("recopimom_exsel_oofv", "recopimom_exsel_oofv", recomom_nbins, 200.0, 1500.0);
      recopimom_exsel_numubarccbkg = new TH1F("recopimom_exsel_numubarccbkg", "recopimom_exsel_numubarccbkg", recomom_nbins, 200.0, 1500.0);
      recopimom_exsel_numucc = new TH1F("recopimom_exsel_numucc", "recopimom_exsel_numucc", recomom_nbins, 200.0, 1500.0);
      recopimom_exsel_otherbkg = new TH1F("recopimom_exsel_otherbkg", "recopimom_exsel_otherbkg", recomom_nbins, 200.0, 1500.0);
   }
   else
   {
      recomom_all = new TH1F("recomom_all", "Events vs reco momentum", recomom_nbins, 0.0, 5000.0);
      recomom_antimu = new TH1F("recomom_antimu", "True antimu vs reco momentum", recomom_nbins, 0.0, 5000.0);
      recomom_piplus = new TH1F("recomom_piplus", "True piplus vs reco momentum", recomom_nbins, 0.0, 5000.0);
      recomom_proton = new TH1F("recomom_proton", "True protons vs reco momentum", recomom_nbins, 0.0, 5000.0);
      
      recomom_hmnt_all = new TH1F("recomom_hmnt_all", "Events vs HMNT reco momentum", recomom_nbins, 0.0, 5000.0);
      recomom_hmnt_piminus = new TH1F("recomom_hmnt_piminus", "True piminus vs HMNT reco momentum", recomom_nbins, 0.0, 5000.0);
      recomom_hmnt_mu = new TH1F("recomom_hmnt_mu", "True mu vs HMNT reco momentum", recomom_nbins, 0.0, 5000.0);
      
      recomom_sig_presel = new TH1F("recomom_sig_presel", "recomom_sig_presel", recomom_nbins, 0.0, 5000.0);
      recomom_sig_sel = new TH1F("recomom_sig_sel", "recomom_sig_sel", recomom_nbins, 0.0, 5000.0);
      recomom_bkg_sel = new TH1F("recomom_bkg_sel", "recomom_bkg_sel", recomom_nbins, 0.0, 5000.0);
      
      recomom_exsel_cc0pi = new TH1F("recomom_exsel_cc0pi", "recomom_exsel_cc0pi", recomom_nbins, 200.0, 5000.0);
      recomom_exsel_cc1pi = new TH1F("recomom_exsel_cc1pi", "recomom_exsel_cc1pi", recomom_nbins, 200.0, 5000.0);
      recomom_exsel_ccother = new TH1F("recomom_exsel_ccother", "recomom_exsel_ccother", recomom_nbins, 200.0, 5000.0);
      recomom_exsel_bkg = new TH1F("recomom_exsel_bkg", "recomom_exsel_bkg", recomom_nbins, 200.0, 5000.0);
      recomom_exsel_oofv = new TH1F("recomom_exsel_oofv", "recomom_exsel_oofv", recomom_nbins, 200.0, 5000.0);
      recomom_exsel_numubarccbkg = new TH1F("recomom_exsel_numubarccbkg", "recomom_exsel_numubarccbkg", recomom_nbins, 200.0, 5000.0);
      recomom_exsel_numucc = new TH1F("recomom_exsel_numucc", "recomom_exsel_numucc", recomom_nbins, 200.0, 5000.0);
      recomom_exsel_otherbkg = new TH1F("recomom_exsel_otherbkg", "recomom_exsel_otherbkg", recomom_nbins, 200.0, 5000.0);
      
      recopimom_exsel_cc0pi = new TH1F("recopimom_exsel_cc0pi", "recopimom_exsel_cc0pi", recomom_nbins, 200.0, 5000.0);
      recopimom_exsel_cc1pi = new TH1F("recopimom_exsel_cc1pi", "recopimom_exsel_cc1pi", recomom_nbins, 200.0, 5000.0);
      recopimom_exsel_ccother = new TH1F("recopimom_exsel_ccother", "recopimom_exsel_ccother", recomom_nbins, 200.0, 5000.0);
      recopimom_exsel_bkg = new TH1F("recopimom_exsel_bkg", "recopimom_exsel_bkg", recomom_nbins, 200.0, 5000.0);
      recopimom_exsel_oofv = new TH1F("recopimom_exsel_oofv", "recopimom_exsel_oofv", recomom_nbins, 200.0, 5000.0);
      recopimom_exsel_numubarccbkg = new TH1F("recopimom_exsel_numubarccbkg", "recopimom_exsel_numubarccbkg", recomom_nbins, 200.0, 5000.0);
      recopimom_exsel_numucc = new TH1F("recopimom_exsel_numucc", "recopimom_exsel_numucc", recomom_nbins, 200.0, 5000.0);
      recopimom_exsel_otherbkg = new TH1F("recopimom_exsel_otherbkg", "recopimom_exsel_otherbkg", recomom_nbins, 200.0, 5000.0);
   }
   
   Int_t recomomdiff_nbins = 20;
   TH1F *recomom_diff_sig = new TH1F("recomom_diff_sig", "Signal;#mu^{+} candidate p_{reco} - #pi^{-} candidate p_{reco} (MeV/c); Events", recomomdiff_nbins, -5000.0, 5000.0);
   TH1F *recomom_diff_bkg = new TH1F("recomom_diff_bkg", "Background;#mu^{+} candidate p_{reco} - #pi^{-} candidate p_{reco} (MeV/c); Events", recomomdiff_nbins, -5000.0, 5000.0);
   
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
         
         if (reactionCC==1)   {counter_beforeprimaryPID_sig++;}
         else                 {counter_beforeprimaryPID_bkg++;}
      }
      
      if (accum_level[0][1] > 6){
         
         if (particle == -13)
         {
            counter_selmu_antimu_accum6++;
         }
         
         if (particle == 211)
         {
            counter_selmu_piplus_accum6++;
         }
         
         if (reactionCC==1)   {counter_afterprimaryPID_sig++;}
         else                 {counter_afterprimaryPID_bkg++;}
         
         if (topology==1)   {counter_beforesecondaryPID_sig++;}
         else               {counter_beforesecondaryPID_bkg++;}
      }
      
      if (accum_level[0][1] > 7){
         
         counter_all_accum7++;
      }
      
      if (accum_level[0][1] > 8){
         
         counter_all_accum8++;
         recomom_all->Fill(selmu_mom[0]);
         
         if (topology==1)   {counter_aftersecondaryPID_sig++;}
         else               {counter_aftersecondaryPID_bkg++;}
         
         if (topology == 0)
         {
            counter_cc0pi++;
         }
         
         if (topology == 1)
         {
            counter_cc1pi++;
            recomom_sig_sel->Fill(selmu_mom[0]);
         }
        
         if (topology != 1)
         {
            recomom_bkg_sel->Fill(selmu_mom[0]);
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
         }
         
         if (particle == 13)
         {
            counter_selmu_mu++;
         }
         
         if (particle == 211)
         {
            counter_selmu_piplus++;
            recomom_piplus->Fill(selmu_mom[0]);
         }
         
         if (particle == -211)
         {
            counter_selmu_piminus++;
         }
         
         if (particle == 2212)
         {
            counter_selmu_proton++;
            recomom_proton->Fill(selmu_mom[0]);
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
            recomom_hmnt_all->Fill(HMNT_mom);
            
            if (topology == 1){recomom_diff_sig->Fill(selmu_mom[0] - HMNT_mom);}
            if (topology != 1){recomom_diff_bkg->Fill(selmu_mom[0] - HMNT_mom);}
            
            
            if (HMNT_truepdg == -211)
            {
               counter_selpi_piminus++;
               recomom_hmnt_piminus->Fill(HMNT_mom);
               
            }
            
            if (HMNT_truepdg == 13)
            {
               counter_selpi_mu++;
               recomom_hmnt_mu->Fill(HMNT_mom);
            }
            
            if (HMNT_truepdg == 11)
            {
               counter_selpi_electron++;
            }
            
            if (HMNT_truepdg == 2212)
            {
               counter_selpi_proton++;
            }
            
            if (topology == 0) {recomom_exsel_cc0pi->Fill(selmu_mom[0]); recomom_exsel_numubarccbkg->Fill(selmu_mom[0]);}
            if (topology == 1) recomom_exsel_cc1pi->Fill(selmu_mom[0]);
            if (topology == 2) {recomom_exsel_ccother->Fill(selmu_mom[0]); recomom_exsel_numubarccbkg->Fill(selmu_mom[0]);}
            if (topology == 3) 
            {
               recomom_exsel_bkg->Fill(selmu_mom[0]);
               if (reaction == 5) recomom_exsel_numucc->Fill(selmu_mom[0]);
               else               recomom_exsel_otherbkg->Fill(selmu_mom[0]);
            }
            if (topology == 7) recomom_exsel_oofv->Fill(selmu_mom[0]);
            
            if (topology == 0) {recopimom_exsel_cc0pi->Fill(HMNT_mom); recopimom_exsel_numubarccbkg->Fill(HMNT_mom);}
            if (topology == 1) recopimom_exsel_cc1pi->Fill(HMNT_mom);
            if (topology == 2) {recopimom_exsel_ccother->Fill(HMNT_mom); recopimom_exsel_numubarccbkg->Fill(HMNT_mom);}
            if (topology == 3) 
            {
               recopimom_exsel_bkg->Fill(HMNT_mom);
               if (reaction == 5) recopimom_exsel_numucc->Fill(HMNT_mom);
               else               recopimom_exsel_otherbkg->Fill(HMNT_mom);
            }
            if (topology == 7) recopimom_exsel_oofv->Fill(HMNT_mom);
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
   
   std::cout << std::endl << "counter_beforeprimaryPID_sig: " << counter_beforeprimaryPID_sig << std::endl;
   std::cout << std::endl << "counter_beforeprimaryPID_bkg: " << counter_beforeprimaryPID_bkg << std::endl;
   std::cout << std::endl << "counter_afterprimaryPID_sig: " << counter_afterprimaryPID_sig << std::endl;
   std::cout << std::endl << "counter_afterprimaryPID_bkg: " << counter_afterprimaryPID_bkg << std::endl;
   
   std::cout << std::endl << "Primary PID signal acceptance: " << (float)counter_afterprimaryPID_sig/counter_beforeprimaryPID_sig << std::endl;
   std::cout << std::endl << "Primary PID background acceptance: " << (float)counter_afterprimaryPID_bkg/counter_beforeprimaryPID_bkg << std::endl;
   
   std::cout << std::endl << "counter_beforesecondaryPID_sig: " << counter_beforesecondaryPID_sig << std::endl;
   std::cout << std::endl << "counter_beforesecondaryPID_bkg: " << counter_beforesecondaryPID_bkg << std::endl;
   std::cout << std::endl << "counter_aftersecondaryPID_sig: " << counter_aftersecondaryPID_sig << std::endl;
   std::cout << std::endl << "counter_aftersecondaryPID_bkg: " << counter_aftersecondaryPID_bkg << std::endl;
   
   std::cout << std::endl << "Secondary PID signal acceptance: " << (float)counter_aftersecondaryPID_sig/counter_beforesecondaryPID_sig << std::endl;
   std::cout << std::endl << "Secondary PID background acceptance: " << (float)counter_aftersecondaryPID_bkg/counter_beforesecondaryPID_bkg << std::endl;
   
   std::cout << std::endl << "Events above accum_level 7: " << counter_all_accum7 << std::endl;
   std::cout << std::endl << "Events above accum_level 8: " << counter_all_accum8 << std::endl;
   
   std::cout << std::endl << "Significance: " << (float)counter_cc1pi/sqrt(counter_all_accum8) << std::endl;
   
   std::cout << std::endl << "True CC0pi: " << counter_cc0pi << " (" << 100*(float)counter_cc0pi/counter_all_accum8 << "\%)" << std::endl;
   std::cout << std::endl << "True CC1pi: " << counter_cc1pi << " (" << 100*(float)counter_cc1pi/counter_all_accum8 << "\%)" << std::endl;
   std::cout << std::endl << "True CC-Other: " << counter_ccother << " (" << 100*(float)counter_ccother/counter_all_accum8 << "\%)" << std::endl;
   std::cout << std::endl << "True BKG: " << counter_bkg << " (" << 100*(float)counter_bkg/counter_all_accum8 << "\%)" << std::endl;
   std::cout << std::endl << "True OOFV: " << counter_oofv << " (" << 100*(float)counter_oofv/counter_all_accum8 << "\%)" << std::endl;
   
   std::cout << std::endl << "Antimu candidate true antimu: " << counter_selmu_antimu << " (" << 100*(float)counter_selmu_antimu/counter_all_accum8 << "\%)" << std::endl;
   std::cout << std::endl << "Antimu candidate true mu: " << counter_selmu_mu << " (" << 100*(float)counter_selmu_mu/counter_all_accum8 << "\%)" << std::endl;
   std::cout << std::endl << "Antimu candidate true piplus: " << counter_selmu_piplus << " (" << 100*(float)counter_selmu_piplus/counter_all_accum8 << "\%)" << std::endl;
   std::cout << std::endl << "Antimu candidate true piminus: " << counter_selmu_piminus << " (" << 100*(float)counter_selmu_piminus/counter_all_accum8 << "\%)" << std::endl;
   std::cout << std::endl << "Antimu candidate true protons: " << counter_selmu_proton << " (" << 100*(float)counter_selmu_proton/counter_all_accum8 << "\%)" << std::endl;
   std::cout << std::endl << "Antimu candidate true positrons: " << counter_selmu_positron << " (" << 100*(float)counter_selmu_positron/counter_all_accum8 << "\%)" << std::endl;
   std::cout << std::endl << "Antimu candidate true electrons: " << counter_selmu_electron << " (" << 100*(float)counter_selmu_electron/counter_all_accum8 << "\%)" << std::endl;
   
   std::cout << std::endl << "Pi- candidates: " << counter_selpi << std::endl;
   std::cout << std::endl << "Pi- candidate true piminus: " << counter_selpi_piminus << " (" << 100*(float)counter_selpi_piminus/counter_selpi << "\%)" << std::endl;
   std::cout << std::endl << "Pi- candidate true muons: " << counter_selpi_mu << " (" << 100*(float)counter_selpi_mu/counter_selpi << "\%)" << std::endl;
   std::cout << std::endl << "Pi- candidate true electrons: " << counter_selpi_electron << " (" << 100*(float)counter_selpi_electron/counter_selpi << "\%)" << std::endl;
   std::cout << std::endl << "Pi- candidate true protons: " << counter_selpi_proton << " (" << 100*(float)counter_selpi_proton/counter_selpi << "\%)" << std::endl;
   
   std::cout << std::endl << "Mu/pi ratio before PID: " << (float)counter_selmu_antimu_accum5/counter_selmu_piplus_accum5 << std::endl;
   std::cout << std::endl << "Mu/pi ratio after PID: " << (float)counter_selmu_antimu_accum6/counter_selmu_piplus_accum6 << std::endl;
   
   
   
   TCanvas* canvas_selmu_antimu_purity = new TCanvas("canvas_selmu_antimu_purity","Antimu candidate track purity vs reconstructed momentum",200,10,1000,600);
   TGraph* graph_selmu_antimu_purity = new TGraph();
   graph_selmu_antimu_purity->SetTitle(" ;Antimu candidate reconstructed momentum (MeV/c);Track antimuon purity;");
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
   //graph_selmu_piplus_purity->SetTitle(" ;Antimu candidate reconstructed momentum (MeV/c);Track pi+ contamination;");
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
   //graph_selmu_proton_purity->SetTitle(" ;Antimu candidate reconstructed momentum (MeV/c);Track proton contamination;");
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
   
   recomom_diff_sig->Write();
   recomom_diff_bkg->Write();
   
   graph_selmu_antimu_purity->SetName("graph_selmu_antimu_purity");
   graph_selmu_antimu_purity->Write();
   graph_selmu_piplus_purity->SetName("graph_selmu_piplus_purity");
   graph_selmu_piplus_purity->Write();
   graph_selmu_proton_purity->SetName("graph_selmu_proton_purity");
   graph_selmu_proton_purity->Write();
   
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
   
   // Effpur plots
   
   TCanvas* canvas_effpur_vs_recomom = new TCanvas("canvas_effpur_vs_recomom","canvas_effpur_vs_recomom",200,10,1000,600);
   TGraph* graph_pur_vs_recomom = new TGraph();
   graph_pur_vs_recomom->SetTitle(" ;#mu^{+} candidate reconstructed momentum (MeV/c);Existing #bar{#nu}_{#mu} CC1pi- selection purity, efficiency");
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
   
   Double_t scale_factor = 1/9.91955;
   //Double_t scale_factor = 1/counter_all_accum4;
   
   SetHistParticleStyle(recomom_exsel_cc1pi, "antimu");
   SetHistParticleStyle(recomom_exsel_cc0pi, "proton");
   SetHistParticleStyle(recomom_exsel_ccother, "positron");
   SetHistParticleStyle(recomom_exsel_bkg, "piplus");
   SetHistParticleStyle(recomom_exsel_oofv, "other");
   SetHistParticleStyle(recomom_exsel_numubarccbkg, "proton");
   SetHistParticleStyle(recomom_exsel_numucc, "piplus");
   SetHistParticleStyle(recomom_exsel_otherbkg, "positron");
   
   recomom_exsel_cc0pi->Write();
   recomom_exsel_cc1pi->Write();
   recomom_exsel_ccother->Write();
   recomom_exsel_bkg->Write();
   recomom_exsel_oofv->Write();
   recomom_exsel_numubarccbkg->Write();
   recomom_exsel_numucc->Write();
   recomom_exsel_otherbkg->Write();
   
   recomom_exsel_cc0pi->SetTitle("NEUT MC: #bar{#nu}_{#mu} CC0pi");
   recomom_exsel_cc1pi->SetTitle("NEUT MC: #bar{#nu}_{#mu} CC1pi (signal)");
   recomom_exsel_ccother->SetTitle("NEUT MC: #bar{#nu}_{#mu} CC-Other");
   recomom_exsel_bkg->SetTitle("NEUT MC: non-#bar{#nu}_{#mu}-CC backgrounds");
   recomom_exsel_oofv->SetTitle("NEUT MC: vertex outside FV");
   recomom_exsel_numubarccbkg->SetTitle("NEUT MC: #bar{#nu}_{#mu} CC backgrounds");
   recomom_exsel_numucc->SetTitle("NEUT MC: #nu_{#mu} CC backgrounds");
   recomom_exsel_otherbkg->SetTitle("NEUT MC: other backgrounds");
   
   recomom_exsel_cc0pi->Scale(scale_factor);
   recomom_exsel_cc1pi->Scale(scale_factor);
   recomom_exsel_ccother->Scale(scale_factor);
   recomom_exsel_bkg->Scale(scale_factor);
   recomom_exsel_oofv->Scale(scale_factor);
   recomom_exsel_numubarccbkg->Scale(scale_factor);
   recomom_exsel_numucc->Scale(scale_factor);
   recomom_exsel_otherbkg->Scale(scale_factor);
   
   THStack* recomom_exsel_stack = new THStack("recomom_exsel_stack","recomom_exsel_stack;Antimuon candidate reconstructed momentum (MeV/c);Events");
   recomom_exsel_stack->Add(recomom_exsel_oofv);
   recomom_exsel_stack->Add(recomom_exsel_bkg);
   recomom_exsel_stack->Add(recomom_exsel_ccother);
   recomom_exsel_stack->Add(recomom_exsel_cc0pi);
   recomom_exsel_stack->Add(recomom_exsel_cc1pi);
   recomom_exsel_stack->Write();
   
   THStack* recomom_exsel_stack_altbkg = new THStack("recomom_exsel_stack_altbkg","recomom_exsel_stack_altbkg;Antimuon candidate reconstructed momentum (MeV/c);Events");
   recomom_exsel_stack_altbkg->Add(recomom_exsel_oofv);
   recomom_exsel_stack_altbkg->Add(recomom_exsel_otherbkg);
   recomom_exsel_stack_altbkg->Add(recomom_exsel_numucc);
   recomom_exsel_stack_altbkg->Add(recomom_exsel_numubarccbkg);
   recomom_exsel_stack_altbkg->Add(recomom_exsel_cc1pi);
   recomom_exsel_stack_altbkg->Write();
   
   SetHistParticleStyle(recopimom_exsel_cc1pi, "antimu");
   SetHistParticleStyle(recopimom_exsel_cc0pi, "proton");
   SetHistParticleStyle(recopimom_exsel_ccother, "positron");
   SetHistParticleStyle(recopimom_exsel_bkg, "piplus");
   SetHistParticleStyle(recopimom_exsel_oofv, "other");
   SetHistParticleStyle(recopimom_exsel_numubarccbkg, "proton");
   SetHistParticleStyle(recopimom_exsel_numucc, "piplus");
   SetHistParticleStyle(recopimom_exsel_otherbkg, "positron");
   
   recopimom_exsel_cc0pi->Write();
   recopimom_exsel_cc1pi->Write();
   recopimom_exsel_ccother->Write();
   recopimom_exsel_bkg->Write();
   recopimom_exsel_oofv->Write();
   recopimom_exsel_numubarccbkg->Write();
   recopimom_exsel_numucc->Write();
   recopimom_exsel_otherbkg->Write();
   
   recopimom_exsel_cc0pi->SetTitle("NEUT MC: #bar{#nu}_{#mu} CC0pi");
   recopimom_exsel_cc1pi->SetTitle("NEUT MC: #bar{#nu}_{#mu} CC1pi (signal)");
   recopimom_exsel_ccother->SetTitle("NEUT MC: #bar{#nu}_{#mu} CC-Other");
   recopimom_exsel_bkg->SetTitle("NEUT MC: non-#bar{#nu}_{#mu}-CC backgrounds");
   recopimom_exsel_oofv->SetTitle("NEUT MC: vertex outside FV");
   recopimom_exsel_numubarccbkg->SetTitle("NEUT MC: #bar{#nu}_{#mu} CC backgrounds");
   recopimom_exsel_numucc->SetTitle("NEUT MC: #nu_{#mu} CC backgrounds");
   recopimom_exsel_otherbkg->SetTitle("NEUT MC: other backgrounds");
   
   recopimom_exsel_cc0pi->Scale(scale_factor);
   recopimom_exsel_cc1pi->Scale(scale_factor);
   recopimom_exsel_ccother->Scale(scale_factor);
   recopimom_exsel_bkg->Scale(scale_factor);
   recopimom_exsel_oofv->Scale(scale_factor);
   recopimom_exsel_numubarccbkg->Scale(scale_factor);
   recopimom_exsel_numucc->Scale(scale_factor);
   recopimom_exsel_otherbkg->Scale(scale_factor);
   
   THStack* recopimom_exsel_stack = new THStack("recopimom_exsel_stack","recopimom_exsel_stack;Pion candidate reconstructed momentum (MeV/c);Events");
   recopimom_exsel_stack->Add(recopimom_exsel_oofv);
   recopimom_exsel_stack->Add(recopimom_exsel_bkg);
   recopimom_exsel_stack->Add(recopimom_exsel_ccother);
   recopimom_exsel_stack->Add(recopimom_exsel_cc0pi);
   recopimom_exsel_stack->Add(recopimom_exsel_cc1pi);
   recopimom_exsel_stack->Write();
   
   THStack* recopimom_exsel_stack_altbkg = new THStack("recopimom_exsel_stack_altbkg","recopimom_exsel_stack_altbkg;Pion candidate reconstructed momentum (MeV/c);Events");
   recopimom_exsel_stack_altbkg->Add(recopimom_exsel_oofv);
   recopimom_exsel_stack_altbkg->Add(recopimom_exsel_otherbkg);
   recopimom_exsel_stack_altbkg->Add(recopimom_exsel_numucc);
   recopimom_exsel_stack_altbkg->Add(recopimom_exsel_numubarccbkg);
   recopimom_exsel_stack_altbkg->Add(recopimom_exsel_cc1pi);
   recopimom_exsel_stack_altbkg->Write();
   
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
   
   Bool_t SetFillColors = true;
   
   hist->SetLineWidth(2);
   
   if (particle == "antimu")
   {
      hist->SetLineColor( kBlue);
      if (SetFillColors) {hist->SetFillColor(kBlue-10);}
      //hist->SetFillStyle( 3006);
   }
   
   else if (particle == "piplus")
   {
      hist->SetLineColor( kRed);
      if (SetFillColors) {hist->SetFillColor(kRed-10);}
      //hist->SetFillStyle( 3354);
   }
   
   else if (particle == "proton")
   {
      hist->SetLineColor( kGreen);
      if (SetFillColors) {hist->SetFillColor(kGreen-10);}
      //hist->SetFillStyle( 3003);
   }
   
   else if (particle == "positron")
   {
      hist->SetLineColor( kMagenta);
      if (SetFillColors) {hist->SetFillColor(kMagenta-10);}
      //hist->SetFillStyle( 3345);
   }
   
   else if (particle == "other")
   {
      hist->SetLineColor( kGray+2);
      if (SetFillColors) {hist->SetFillColor(kGray);}
      //hist->SetFillStyle( 3345);
   }
   
   else std::cout << "Error in SetHistParticleStyle: particle type not recognised." << std::endl;
   
   return;
}
