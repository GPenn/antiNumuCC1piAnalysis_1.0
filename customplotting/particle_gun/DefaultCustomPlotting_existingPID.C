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
   gStyle->SetTitleYOffset(1.0);
   gStyle->SetTitleXOffset(1.2);
   
   
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntries();
   
   std::cout << "Total entries to process: " << nentries << std::endl << std::endl;
   
   std::time_t time_start = std::time(0);
   
   Int_t presel_nAntimu = 0;
   Int_t presel_nPiplus = 0;
   Int_t presel_nProton = 0;
   Int_t presel_nPositron = 0;
   
   TH1F* presel_recomom_antimu = new TH1F("presel_recomom_antimu", "#mu^{+} identified as #mu^{+}", 13, 200.0, 1500.0);
   TH1F* presel_recomom_piplus = new TH1F("presel_recomom_piplus", "#pi^{+} identified as #pi^{+}", 13, 200.0, 1500.0);
   TH1F* presel_recomom_proton = new TH1F("presel_recomom_proton", "p identified as p", 13, 200.0, 1500.0);
   TH1F* presel_recomom_positron = new TH1F("presel_recomom_positron", "e^{+} identified as e^{+}", 13, 200.0, 1500.0);
   
   TH1F* presel_theta_antimu = new TH1F("presel_theta_antimu", "#mu^{+} identified as #mu^{+}", 13, 0.0, 1.0472);
   TH1F* presel_theta_piplus = new TH1F("presel_theta_piplus", "#pi^{+} identified as #pi^{+}", 13, 0.0, 1.0472);
   TH1F* presel_theta_proton = new TH1F("presel_theta_proton", "p identified as p", 13, 0.0, 1.0472);
   TH1F* presel_theta_positron = new TH1F("presel_theta_positron", "e^{+} identified as e^{+}", 13, 0.0, 1.0472);
   
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
   
   Int_t esel_strict1_nAntimu = 0;
   Int_t esel_strict1_nPiplus = 0;
   Int_t esel_strict1_nProton = 0;
   Int_t esel_strict1_nPositron = 0;
   
   Int_t esel_strict2_nAntimu = 0;
   Int_t esel_strict2_nPiplus = 0;
   Int_t esel_strict2_nProton = 0;
   Int_t esel_strict2_nPositron = 0;
   
   TH1F* musel_recomom_antimu = new TH1F("musel_recomom_antimu", "#mu^{+} identified as #mu^{+}", 13, 200.0, 1500.0);
   TH1F* musel_recomom_piplus = new TH1F("musel_recomom_piplus", "#pi^{+} identified as #mu^{+}", 13, 200.0, 1500.0);
   TH1F* musel_recomom_proton = new TH1F("musel_recomom_proton", "p identified as #mu^{+}", 13, 200.0, 1500.0);
   TH1F* musel_recomom_positron = new TH1F("musel_recomom_positron", "e^{+} identified as #mu^{+}", 13, 200.0, 1500.0);
   TH1F* pisel_recomom_antimu = new TH1F("pisel_recomom_antimu", "#mu^{+} identified as #pi^{+}", 13, 200.0, 1500.0);
   TH1F* pisel_recomom_piplus = new TH1F("pisel_recomom_piplus", "#pi^{+} identified as #pi^{+}", 13, 200.0, 1500.0);
   TH1F* pisel_recomom_proton = new TH1F("pisel_recomom_proton", "p identified as #pi^{+}", 13, 200.0, 1500.0);
   TH1F* pisel_recomom_positron = new TH1F("pisel_recomom_positron", "e^{+} identified as #pi^{+}", 13, 200.0, 1500.0);
   TH1F* psel_recomom_antimu = new TH1F("psel_recomom_antimu", "#mu^{+} identified as p", 13, 200.0, 1500.0);
   TH1F* psel_recomom_piplus = new TH1F("psel_recomom_piplus", "#pi^{+} identified as p", 13, 200.0, 1500.0);
   TH1F* psel_recomom_proton = new TH1F("psel_recomom_proton", "p identified as p", 13, 200.0, 1500.0);
   TH1F* psel_recomom_positron = new TH1F("psel_recomom_positron", "e^{+} identified as p", 13, 200.0, 1500.0);
   TH1F* esel_recomom_antimu = new TH1F("esel_recomom_antimu", "#mu^{+} identified as e^{+}", 13, 200.0, 1500.0);
   TH1F* esel_recomom_piplus = new TH1F("esel_recomom_piplus", "#pi^{+} identified as e^{+}", 13, 200.0, 1500.0);
   TH1F* esel_recomom_proton = new TH1F("esel_recomom_proton", "p identified as e^{+}", 13, 200.0, 1500.0);
   TH1F* esel_recomom_positron = new TH1F("esel_recomom_positron", "e^{+} identified as e^{+}", 13, 200.0, 1500.0);
   
   TH1F* esel_strict1_recomom_antimu = new TH1F("esel_strict1_recomom_antimu", "#mu^{+} identified as e^{+}", 13, 200.0, 1500.0);
   TH1F* esel_strict1_recomom_piplus = new TH1F("esel_strict1_recomom_piplus", "#pi^{+} identified as e^{+}", 13, 200.0, 1500.0);
   TH1F* esel_strict1_recomom_proton = new TH1F("esel_strict1_recomom_proton", "p identified as e^{+}", 13, 200.0, 1500.0);
   TH1F* esel_strict1_recomom_positron = new TH1F("esel_strict1_recomom_positron", "e^{+} identified as e^{+}", 13, 200.0, 1500.0);
   
   TH1F* esel_strict2_recomom_antimu = new TH1F("esel_strict2_recomom_antimu", "#mu^{+} identified as e^{+}", 13, 200.0, 1500.0);
   TH1F* esel_strict2_recomom_piplus = new TH1F("esel_strict2_recomom_piplus", "#pi^{+} identified as e^{+}", 13, 200.0, 1500.0);
   TH1F* esel_strict2_recomom_proton = new TH1F("esel_strict2_recomom_proton", "p identified as e^{+}", 13, 200.0, 1500.0);
   TH1F* esel_strict2_recomom_positron = new TH1F("esel_strict2_recomom_positron", "e^{+} identified as e^{+}", 13, 200.0, 1500.0);
   
   TH1F* musel_theta_antimu = new TH1F("musel_theta_antimu", "#mu^{+} identified as #mu^{+}", 13, 0.0, 1.0472);
   TH1F* musel_theta_piplus = new TH1F("musel_theta_piplus", "#pi^{+} identified as #mu^{+}", 13, 0.0, 1.0472);
   TH1F* musel_theta_proton = new TH1F("musel_theta_proton", "p identified as #mu^{+}", 13, 0.0, 1.0472);
   TH1F* musel_theta_positron = new TH1F("musel_theta_positron", "e^{+} identified as #mu^{+}", 13, 0.0, 1.0472);
   TH1F* pisel_theta_antimu = new TH1F("pisel_theta_antimu", "#mu^{+} identified as #pi^{+}", 13, 0.0, 1.0472);
   TH1F* pisel_theta_piplus = new TH1F("pisel_theta_piplus", "#pi^{+} identified as #pi^{+}", 13, 0.0, 1.0472);
   TH1F* pisel_theta_proton = new TH1F("pisel_theta_proton", "p identified as #pi^{+}", 13, 0.0, 1.0472);
   TH1F* pisel_theta_positron = new TH1F("pisel_theta_positron", "e^{+} identified as #pi^{+}", 13, 0.0, 1.0472);
   TH1F* psel_theta_antimu = new TH1F("psel_theta_antimu", "#mu^{+} identified as p", 13, 0.0, 1.0472);
   TH1F* psel_theta_piplus = new TH1F("psel_theta_piplus", "#pi^{+} identified as p", 13, 0.0, 1.0472);
   TH1F* psel_theta_proton = new TH1F("psel_theta_proton", "p identified as p", 13, 0.0, 1.0472);
   TH1F* psel_theta_positron = new TH1F("psel_theta_positron", "e^{+} identified as p", 13, 0.0, 1.0472);
   TH1F* esel_theta_antimu = new TH1F("esel_theta_antimu", "#mu^{+} identified as e^{+}", 13, 0.0, 1.0472);
   TH1F* esel_theta_piplus = new TH1F("esel_theta_piplus", "#pi^{+} identified as e^{+}", 13, 0.0, 1.0472);
   TH1F* esel_theta_proton = new TH1F("esel_theta_proton", "p identified as e^{+}", 13, 0.0, 1.0472);
   TH1F* esel_theta_positron = new TH1F("esel_theta_positron", "e^{+} identified as e^{+}", 13, 0.0, 1.0472);
   
   // Existing numu selection
   
   Int_t musel_numu_nAntimu = 0;
   Int_t musel_numu_nPiplus = 0;
   Int_t musel_numu_nProton = 0;
   Int_t musel_numu_nPositron = 0;
   Int_t pisel_numu_nAntimu = 0;
   Int_t pisel_numu_nPiplus = 0;
   Int_t pisel_numu_nProton = 0;
   Int_t pisel_numu_nPositron = 0;
   Int_t psel_numu_nAntimu = 0;
   Int_t psel_numu_nPiplus = 0;
   Int_t psel_numu_nProton = 0;
   Int_t psel_numu_nPositron = 0;
   Int_t esel_numu_nAntimu = 0;
   Int_t esel_numu_nPiplus = 0;
   Int_t esel_numu_nProton = 0;
   Int_t esel_numu_nPositron = 0;
   Int_t nosel_numu_nAntimu = 0;
   Int_t nosel_numu_nPiplus = 0;
   Int_t nosel_numu_nProton = 0;
   Int_t nosel_numu_nPositron = 0;
   
   TH1F* musel_numu_recomom_antimu = new TH1F("musel_numu_recomom_antimu", "#mu^{+} identified as #mu^{+}", 13, 200.0, 1500.0);
   TH1F* musel_numu_recomom_piplus = new TH1F("musel_numu_recomom_piplus", "#pi^{+} identified as #mu^{+}", 13, 200.0, 1500.0);
   TH1F* musel_numu_recomom_proton = new TH1F("musel_numu_recomom_proton", "p identified as #mu^{+}", 13, 200.0, 1500.0);
   TH1F* musel_numu_recomom_positron = new TH1F("musel_numu_recomom_positron", "e^{+} identified as #mu^{+}", 13, 200.0, 1500.0);
   TH1F* pisel_numu_recomom_antimu = new TH1F("pisel_numu_recomom_antimu", "#mu^{+} identified as #pi^{+}", 13, 200.0, 1500.0);
   TH1F* pisel_numu_recomom_piplus = new TH1F("pisel_numu_recomom_piplus", "#pi^{+} identified as #pi^{+}", 13, 200.0, 1500.0);
   TH1F* pisel_numu_recomom_proton = new TH1F("pisel_numu_recomom_proton", "p identified as #pi^{+}", 13, 200.0, 1500.0);
   TH1F* pisel_numu_recomom_positron = new TH1F("pisel_numu_recomom_positron", "e^{+} identified as #pi^{+}", 13, 200.0, 1500.0);
   TH1F* psel_numu_recomom_antimu = new TH1F("psel_numu_recomom_antimu", "#mu^{+} identified as p", 13, 200.0, 1500.0);
   TH1F* psel_numu_recomom_piplus = new TH1F("psel_numu_recomom_piplus", "#pi^{+} identified as p", 13, 200.0, 1500.0);
   TH1F* psel_numu_recomom_proton = new TH1F("psel_numu_recomom_proton", "p identified as p", 13, 200.0, 1500.0);
   TH1F* psel_numu_recomom_positron = new TH1F("psel_numu_recomom_positron", "e^{+} identified as p", 13, 200.0, 1500.0);
   TH1F* esel_numu_recomom_antimu = new TH1F("esel_numu_recomom_antimu", "#mu^{+} identified as e^{+}", 13, 200.0, 1500.0);
   TH1F* esel_numu_recomom_piplus = new TH1F("esel_numu_recomom_piplus", "#pi^{+} identified as e^{+}", 13, 200.0, 1500.0);
   TH1F* esel_numu_recomom_proton = new TH1F("esel_numu_recomom_proton", "p identified as e^{+}", 13, 200.0, 1500.0);
   TH1F* esel_numu_recomom_positron = new TH1F("esel_numu_recomom_positron", "e^{+} identified as e^{+}", 13, 200.0, 1500.0);
   
   TH1F* musel_numu_theta_antimu = new TH1F("musel_numu_theta_antimu", "#mu^{+} identified as #mu^{+}", 13, 0.0, 1.0472);
   TH1F* musel_numu_theta_piplus = new TH1F("musel_numu_theta_piplus", "#pi^{+} identified as #mu^{+}", 13, 0.0, 1.0472);
   TH1F* musel_numu_theta_proton = new TH1F("musel_numu_theta_proton", "p identified as #mu^{+}", 13, 0.0, 1.0472);
   TH1F* musel_numu_theta_positron = new TH1F("musel_numu_theta_positron", "e^{+} identified as #mu^{+}", 13, 0.0, 1.0472);
   TH1F* pisel_numu_theta_antimu = new TH1F("pisel_numu_theta_antimu", "#mu^{+} identified as #pi^{+}", 13, 0.0, 1.0472);
   TH1F* pisel_numu_theta_piplus = new TH1F("pisel_numu_theta_piplus", "#pi^{+} identified as #pi^{+}", 13, 0.0, 1.0472);
   TH1F* pisel_numu_theta_proton = new TH1F("pisel_numu_theta_proton", "p identified as #pi^{+}", 13, 0.0, 1.0472);
   TH1F* pisel_numu_theta_positron = new TH1F("pisel_numu_theta_positron", "e^{+} identified as #pi^{+}", 13, 0.0, 1.0472);
   TH1F* psel_numu_theta_antimu = new TH1F("psel_numu_theta_antimu", "#mu^{+} identified as p", 13, 0.0, 1.0472);
   TH1F* psel_numu_theta_piplus = new TH1F("psel_numu_theta_piplus", "#pi^{+} identified as p", 13, 0.0, 1.0472);
   TH1F* psel_numu_theta_proton = new TH1F("psel_numu_theta_proton", "p identified as p", 13, 0.0, 1.0472);
   TH1F* psel_numu_theta_positron = new TH1F("psel_numu_theta_positron", "e^{+} identified as p", 13, 0.0, 1.0472);
   TH1F* esel_numu_theta_antimu = new TH1F("esel_numu_theta_antimu", "#mu^{+} identified as e^{+}", 13, 0.0, 1.0472);
   TH1F* esel_numu_theta_piplus = new TH1F("esel_numu_theta_piplus", "#pi^{+} identified as e^{+}", 13, 0.0, 1.0472);
   TH1F* esel_numu_theta_proton = new TH1F("esel_numu_theta_proton", "p identified as e^{+}", 13, 0.0, 1.0472);
   TH1F* esel_numu_theta_positron = new TH1F("esel_numu_theta_positron", "e^{+} identified as e^{+}", 13, 0.0, 1.0472);
   
   // Existing nue selection
   
   Int_t musel_nue_nAntimu = 0;
   Int_t musel_nue_nPiplus = 0;
   Int_t musel_nue_nProton = 0;
   Int_t musel_nue_nPositron = 0;
   Int_t pisel_nue_nAntimu = 0;
   Int_t pisel_nue_nPiplus = 0;
   Int_t pisel_nue_nProton = 0;
   Int_t pisel_nue_nPositron = 0;
   Int_t psel_nue_nAntimu = 0;
   Int_t psel_nue_nPiplus = 0;
   Int_t psel_nue_nProton = 0;
   Int_t psel_nue_nPositron = 0;
   Int_t esel_nue_nAntimu = 0;
   Int_t esel_nue_nPiplus = 0;
   Int_t esel_nue_nProton = 0;
   Int_t esel_nue_nPositron = 0;
   Int_t nosel_nue_nAntimu = 0;
   Int_t nosel_nue_nPiplus = 0;
   Int_t nosel_nue_nProton = 0;
   Int_t nosel_nue_nPositron = 0;
   
   TH1F* esel_nue_recomom_antimu = new TH1F("esel_nue_recomom_antimu", "#mu^{+} identified as e^{+}", 13, 200.0, 1500.0);
   TH1F* esel_nue_recomom_piplus = new TH1F("esel_nue_recomom_piplus", "#pi^{+} identified as e^{+}", 13, 200.0, 1500.0);
   TH1F* esel_nue_recomom_proton = new TH1F("esel_nue_recomom_proton", "p identified as e^{+}", 13, 200.0, 1500.0);
   TH1F* esel_nue_recomom_positron = new TH1F("esel_nue_recomom_positron", "e^{+} identified as e^{+}", 13, 200.0, 1500.0);
   
   // TPC likelihood PID
   
   Int_t musel_tpc_nAntimu = 0;
   Int_t musel_tpc_nPiplus = 0;
   Int_t musel_tpc_nProton = 0;
   Int_t musel_tpc_nPositron = 0;
   Int_t pisel_tpc_nAntimu = 0;
   Int_t pisel_tpc_nPiplus = 0;
   Int_t pisel_tpc_nProton = 0;
   Int_t pisel_tpc_nPositron = 0;
   Int_t psel_tpc_nAntimu = 0;
   Int_t psel_tpc_nPiplus = 0;
   Int_t psel_tpc_nProton = 0;
   Int_t psel_tpc_nPositron = 0;
   Int_t esel_tpc_nAntimu = 0;
   Int_t esel_tpc_nPiplus = 0;
   Int_t esel_tpc_nProton = 0;
   Int_t esel_tpc_nPositron = 0;
   Int_t nosel_tpc_nAntimu = 0;
   Int_t nosel_tpc_nPiplus = 0;
   Int_t nosel_tpc_nProton = 0;
   Int_t nosel_tpc_nPositron = 0;
   
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      fChain->GetEntry(jentry);

      // Cut on accum_level etc
      if (accum_level[0][1] <= 4) continue; // Set accum_level
      
      
      
      
      // ============= Fill variables for efficiency tests =============
      
      // Preselection:
      
      if ((accum_level[0][1] > 4) && (selmu_necals < 2) && (selmu_mom[0] > 200.0) && (selmu_mom[0] < 1500.0) && (selmu_det_theta < 1.0472)){ 
         
         if (particle == -13)       {presel_nAntimu++; presel_recomom_antimu->Fill(selmu_mom[0]); presel_theta_antimu->Fill(selmu_det_theta);}
         else if (particle == 211)  {presel_nPiplus++; presel_recomom_piplus->Fill(selmu_mom[0]); presel_theta_piplus->Fill(selmu_det_theta);}
         else if (particle == 2212) {presel_nProton++; presel_recomom_proton->Fill(selmu_mom[0]); presel_theta_proton->Fill(selmu_det_theta);}
         else if (particle == -11)  {presel_nPositron++; presel_recomom_positron->Fill(selmu_mom[0]); presel_theta_positron->Fill(selmu_det_theta);}
         
         // BDT selection:
         
         if ((selmu_bdt_pid_mu > selmu_bdt_pid_pi) && (selmu_bdt_pid_mu > selmu_bdt_pid_p) && (selmu_bdt_pid_mu > selmu_bdt_pid_e))
         {
            if (particle == -13) {musel_nAntimu++; musel_recomom_antimu->Fill(selmu_mom[0]); musel_theta_antimu->Fill(selmu_det_theta);}
            if (particle == 211) {musel_nPiplus++; musel_recomom_piplus->Fill(selmu_mom[0]); musel_theta_piplus->Fill(selmu_det_theta);}
            if (particle == 2212) {musel_nProton++; musel_recomom_proton->Fill(selmu_mom[0]); musel_theta_proton->Fill(selmu_det_theta);}
            if (particle == -11) {musel_nPositron++; musel_recomom_positron->Fill(selmu_mom[0]); musel_theta_positron->Fill(selmu_det_theta);}
         }
         
         if ((selmu_bdt_pid_pi > selmu_bdt_pid_mu) && (selmu_bdt_pid_pi > selmu_bdt_pid_p) && (selmu_bdt_pid_pi > selmu_bdt_pid_e))
         {
            if (particle == -13) {pisel_nAntimu++; pisel_recomom_antimu->Fill(selmu_mom[0]); pisel_theta_antimu->Fill(selmu_det_theta);}
            if (particle == 211) {pisel_nPiplus++; pisel_recomom_piplus->Fill(selmu_mom[0]); pisel_theta_piplus->Fill(selmu_det_theta);}
            if (particle == 2212) {pisel_nProton++; pisel_recomom_proton->Fill(selmu_mom[0]); pisel_theta_proton->Fill(selmu_det_theta);}
            if (particle == -11) {pisel_nPositron++; pisel_recomom_positron->Fill(selmu_mom[0]); pisel_theta_positron->Fill(selmu_det_theta);}
         }
         
         if ((selmu_bdt_pid_p > selmu_bdt_pid_mu) && (selmu_bdt_pid_p > selmu_bdt_pid_pi) && (selmu_bdt_pid_p > selmu_bdt_pid_e))
         {
            if (particle == -13) {psel_nAntimu++; psel_recomom_antimu->Fill(selmu_mom[0]); psel_theta_antimu->Fill(selmu_det_theta);}
            if (particle == 211) {psel_nPiplus++; psel_recomom_piplus->Fill(selmu_mom[0]); psel_theta_piplus->Fill(selmu_det_theta);}
            if (particle == 2212) {psel_nProton++; psel_recomom_proton->Fill(selmu_mom[0]); psel_theta_proton->Fill(selmu_det_theta);}
            if (particle == -11) {psel_nPositron++; psel_recomom_positron->Fill(selmu_mom[0]); psel_theta_positron->Fill(selmu_det_theta);}
         }
         
         if ((selmu_bdt_pid_e > selmu_bdt_pid_mu) && (selmu_bdt_pid_e > selmu_bdt_pid_pi) && (selmu_bdt_pid_e > selmu_bdt_pid_p))
         {
            if (particle == -13) {esel_nAntimu++; esel_recomom_antimu->Fill(selmu_mom[0]); esel_theta_antimu->Fill(selmu_det_theta);}
            if (particle == 211) {esel_nPiplus++; esel_recomom_piplus->Fill(selmu_mom[0]); esel_theta_piplus->Fill(selmu_det_theta);}
            if (particle == 2212) {esel_nProton++; esel_recomom_proton->Fill(selmu_mom[0]); esel_theta_proton->Fill(selmu_det_theta);}
            if (particle == -11) {esel_nPositron++; esel_recomom_positron->Fill(selmu_mom[0]); esel_theta_positron->Fill(selmu_det_theta);}
         }
         
         // BDT strict positron cut
         
         if (selmu_bdt_pid_e > 0.8)
         {
            if (particle == -13) {esel_strict1_nAntimu++; esel_strict1_recomom_antimu->Fill(selmu_mom[0]);}
            if (particle == 211) {esel_strict1_nPiplus++; esel_strict1_recomom_piplus->Fill(selmu_mom[0]);}
            if (particle == 2212) {esel_strict1_nProton++; esel_strict1_recomom_proton->Fill(selmu_mom[0]);}
            if (particle == -11) {esel_strict1_nPositron++; esel_strict1_recomom_positron->Fill(selmu_mom[0]);}
         }
         
         if (selmu_bdt_pid_e > 0.9)
         {
            if (particle == -13) {esel_strict2_nAntimu++; esel_strict2_recomom_antimu->Fill(selmu_mom[0]);}
            if (particle == 211) {esel_strict2_nPiplus++; esel_strict2_recomom_piplus->Fill(selmu_mom[0]);}
            if (particle == 2212) {esel_strict2_nProton++; esel_strict2_recomom_proton->Fill(selmu_mom[0]);}
            if (particle == -11) {esel_strict2_nPositron++; esel_strict2_recomom_positron->Fill(selmu_mom[0]);}
         }
         
         // TPC likelihoods:
         
         if ((selmu_tpc_like_mu > selmu_tpc_like_pi) && (selmu_tpc_like_mu > selmu_tpc_like_p) && (selmu_tpc_like_mu > selmu_tpc_like_e))
         {
            if (particle == -13) musel_tpc_nAntimu++;
            if (particle == 211) musel_tpc_nPiplus++;
            if (particle == 2212) musel_tpc_nProton++;
            if (particle == -11) musel_tpc_nPositron++;
         }
         
         if ((selmu_tpc_like_pi > selmu_tpc_like_mu) && (selmu_tpc_like_pi > selmu_tpc_like_p) && (selmu_tpc_like_pi > selmu_tpc_like_e))
         {
            if (particle == -13) pisel_tpc_nAntimu++;
            if (particle == 211) pisel_tpc_nPiplus++;
            if (particle == 2212) pisel_tpc_nProton++;
            if (particle == -11) pisel_tpc_nPositron++;
         }
         
         if ((selmu_tpc_like_p > selmu_tpc_like_mu) && (selmu_tpc_like_p > selmu_tpc_like_pi) && (selmu_tpc_like_p > selmu_tpc_like_e))
         {
            if (particle == -13) psel_tpc_nAntimu++;
            if (particle == 211) psel_tpc_nPiplus++;
            if (particle == 2212) psel_tpc_nProton++;
            if (particle == -11) psel_tpc_nPositron++;
         }
         
         if ((selmu_tpc_like_e > selmu_tpc_like_mu) && (selmu_tpc_like_e > selmu_tpc_like_pi) && (selmu_tpc_like_e > selmu_tpc_like_p))
         {
            if (particle == -13) esel_tpc_nAntimu++;
            if (particle == 211) esel_tpc_nPiplus++;
            if (particle == 2212) esel_tpc_nProton++;
            if (particle == -11) esel_tpc_nPositron++;
         }
         
         // numu selection:
         
         if (((selmu_tpc_like_mu+selmu_tpc_like_pi)/(1-selmu_tpc_like_p) > 0.9 || selmu_mom[0] > 500.0 ) && (selmu_tpc_like_mu>0.1))
         {
            if (particle == -13) {musel_numu_nAntimu++; musel_numu_recomom_antimu->Fill(selmu_mom[0]); musel_numu_theta_antimu->Fill(selmu_det_theta);}
            if (particle == 211) {musel_numu_nPiplus++; musel_numu_recomom_piplus->Fill(selmu_mom[0]); musel_numu_theta_piplus->Fill(selmu_det_theta);}
            if (particle == 2212) {musel_numu_nProton++; musel_numu_recomom_proton->Fill(selmu_mom[0]); musel_numu_theta_proton->Fill(selmu_det_theta);}
            if (particle == -11) {musel_numu_nPositron++; musel_numu_recomom_positron->Fill(selmu_mom[0]); musel_numu_theta_positron->Fill(selmu_det_theta);}
         }
         if ((selmu_tpc_like_pi > selmu_tpc_like_p) && (selmu_tpc_like_pi > selmu_tpc_like_e))
         {
            if (particle == -13) {pisel_numu_nAntimu++; pisel_numu_recomom_antimu->Fill(selmu_mom[0]); pisel_numu_theta_antimu->Fill(selmu_det_theta);}
            if (particle == 211) {pisel_numu_nPiplus++; pisel_numu_recomom_piplus->Fill(selmu_mom[0]); pisel_numu_theta_piplus->Fill(selmu_det_theta);}
            if (particle == 2212) {pisel_numu_nProton++; pisel_numu_recomom_proton->Fill(selmu_mom[0]); pisel_numu_theta_proton->Fill(selmu_det_theta);}
            if (particle == -11) {pisel_numu_nPositron++; pisel_numu_recomom_positron->Fill(selmu_mom[0]); pisel_numu_theta_positron->Fill(selmu_det_theta);}
         }
         else if ((selmu_tpc_like_e > selmu_tpc_like_p) && (selmu_tpc_like_e > selmu_tpc_like_pi) && (selmu_mom[0] < 900.0))
         {
            if (particle == -13) {esel_numu_nAntimu++; esel_numu_recomom_antimu->Fill(selmu_mom[0]); esel_numu_theta_antimu->Fill(selmu_det_theta);}
            if (particle == 211) {esel_numu_nPiplus++; esel_numu_recomom_piplus->Fill(selmu_mom[0]); esel_numu_theta_piplus->Fill(selmu_det_theta);}
            if (particle == 2212) {esel_numu_nProton++; esel_numu_recomom_proton->Fill(selmu_mom[0]); esel_numu_theta_proton->Fill(selmu_det_theta);}
            if (particle == -11) {esel_numu_nPositron++; esel_numu_recomom_positron->Fill(selmu_mom[0]); esel_numu_theta_positron->Fill(selmu_det_theta);}
         }
         else //if ((selmu_bdt_pid_e > selmu_bdt_pid_mu) && (selmu_bdt_pid_e > selmu_bdt_pid_pi) && (selmu_bdt_pid_e > selmu_bdt_pid_p))
         {
            if (particle == -13) {psel_numu_nAntimu++; psel_numu_recomom_antimu->Fill(selmu_mom[0]); psel_numu_theta_antimu->Fill(selmu_det_theta);}
            if (particle == 211) {psel_numu_nPiplus++; psel_numu_recomom_piplus->Fill(selmu_mom[0]); psel_numu_theta_piplus->Fill(selmu_det_theta);}
            if (particle == 2212) {psel_numu_nProton++; psel_numu_recomom_proton->Fill(selmu_mom[0]); psel_numu_theta_proton->Fill(selmu_det_theta);}
            if (particle == -11) {psel_numu_nPositron++; psel_numu_recomom_positron->Fill(selmu_mom[0]); psel_numu_theta_positron->Fill(selmu_det_theta);}
         }
         
         // nue selection
         
         if ( (selmu_tpc_pullele[0] > -2.0) && (selmu_tpc_pullele[0] < 2.5) ) // Relaxed TPC e pull cut
         {
            if ( ((selmu_necals==0) && (selmu_tpc_pullele[0]>-1.0) && (selmu_tpc_pullele[0]<2.0) // No ECal segment
                 && !((selmu_tpc_pullmu[0]>-2.5) && (selmu_tpc_pullmu[0]<2.5)) && !((selmu_tpc_pullpi[0]>-2.5) && (selmu_tpc_pullpi[0]<2.5)))
              || ((selmu_necals>0) && ((selmu_mom[0]>1000 && selmu_ecal_EMenergy[0]>1100) || (selmu_mom[0]<1000 && selmu_ecal_mipem[0]>0))) )  // ECal segment
            {
               if ( (selmu_mom[0]<600) || (selmu_necals>0) || (selmu_tpc_pullele[1]>-3.0 && selmu_tpc_pullele[1]<3.0)  ) // Proton TPC3 PID
               {
                  if ( (selmu_mom[0]<600) || (selmu_necals==0) || (selmu_ecal_EMenergy[0]/selmu_mom[0]>0.65 && selmu_ecal_mipem[0]<0) ) // Proton ECal PID
                  {
                     if (particle == -13) {esel_nue_nAntimu++; esel_nue_recomom_antimu->Fill(selmu_mom[0]);}
                     if (particle == 211) {esel_nue_nPiplus++; esel_nue_recomom_antimu->Fill(selmu_mom[0]);}
                     if (particle == 2212) {esel_nue_nProton++; esel_nue_recomom_antimu->Fill(selmu_mom[0]);}
                     if (particle == -11) {esel_nue_nPositron++; esel_nue_recomom_antimu->Fill(selmu_mom[0]);}
                  }
               }
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
  
   std::cout << "=========== Electron-like ===========" << std::endl << std::endl;
   
   std::cout << "mu+ efficiency: " << (Float_t)esel_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)esel_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)esel_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)esel_nPositron/presel_nPositron << std::endl;
   
   std::cout << "=========== Stricter electron-like (>0.8) ===========" << std::endl << std::endl;
   
   std::cout << "mu+ efficiency: " << (Float_t)esel_strict1_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)esel_strict1_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)esel_strict1_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)esel_strict1_nPositron/presel_nPositron << std::endl;
   
   std::cout << "=========== Stricter electron-like (>0.9) ===========" << std::endl << std::endl;
   
   std::cout << "mu+ efficiency: " << (Float_t)esel_strict2_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)esel_strict2_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)esel_strict2_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)esel_strict2_nPositron/presel_nPositron << std::endl;
   
   // Efficiency vs recomom
   
   TCanvas* canvas_bdt_efficiency_recomom_sig = new TCanvas("canvas_bdt_efficiency_recomom_sig","canvas_bdt_efficiency_recomom_sig",200,10,1000,600);
   
   TGraph* graph_bdt_efficiency_recomom_antimu = new TGraph();
   graph_bdt_efficiency_recomom_antimu->SetTitle("#mu^{+} identified as #mu^{+}");
   for (Int_t bin=1; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(musel_recomom_antimu->GetBinContent(bin))/(presel_recomom_antimu->GetBinContent(bin));
      graph_bdt_efficiency_recomom_antimu->SetPoint(bin-1, presel_recomom_antimu->GetBinCenter(bin), efficiency);
   }
   graph_bdt_efficiency_recomom_antimu->GetYaxis()->SetRangeUser(0.0, 1.0);
   graph_bdt_efficiency_recomom_antimu->SetLineColor( kBlue);
   graph_bdt_efficiency_recomom_antimu->SetFillColor( kWhite);
   graph_bdt_efficiency_recomom_antimu->SetLineWidth(2);
   graph_bdt_efficiency_recomom_antimu->GetYaxis()->SetTitle("Efficiency");
   graph_bdt_efficiency_recomom_antimu->GetXaxis()->SetTitle("Reconstructed momentum (MeV/c)");
   graph_bdt_efficiency_recomom_antimu->Draw("AL");
   
   TGraph* graph_bdt_efficiency_recomom_piplus = new TGraph();
   graph_bdt_efficiency_recomom_piplus->SetTitle("#pi^{+} identified as #pi^{+}");
   for (Int_t bin=1; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(pisel_recomom_piplus->GetBinContent(bin))/(presel_recomom_piplus->GetBinContent(bin));
      graph_bdt_efficiency_recomom_piplus->SetPoint(bin-1, presel_recomom_piplus->GetBinCenter(bin), efficiency);
   }
   graph_bdt_efficiency_recomom_piplus->SetLineColor( kRed);
   graph_bdt_efficiency_recomom_piplus->SetFillColor( kWhite);
   graph_bdt_efficiency_recomom_piplus->SetLineWidth(2);
   graph_bdt_efficiency_recomom_piplus->Draw("L same");
   
   TGraph* graph_bdt_efficiency_recomom_proton = new TGraph();
   graph_bdt_efficiency_recomom_proton->SetTitle("p identified as p");
   for (Int_t bin=2; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(psel_recomom_proton->GetBinContent(bin))/(presel_recomom_proton->GetBinContent(bin));
      graph_bdt_efficiency_recomom_proton->SetPoint(bin-2, presel_recomom_proton->GetBinCenter(bin), efficiency);
   }
   graph_bdt_efficiency_recomom_proton->SetLineColor( kGreen);
   graph_bdt_efficiency_recomom_proton->SetFillColor( kWhite);
   graph_bdt_efficiency_recomom_proton->SetLineWidth(2);
   graph_bdt_efficiency_recomom_proton->Draw("L same");
   
   TGraph* graph_bdt_efficiency_recomom_positron = new TGraph();
   graph_bdt_efficiency_recomom_positron->SetTitle("e^{+} identified as e^{+}");
   for (Int_t bin=1; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(esel_recomom_positron->GetBinContent(bin))/(presel_recomom_positron->GetBinContent(bin));
      graph_bdt_efficiency_recomom_positron->SetPoint(bin-1, presel_recomom_positron->GetBinCenter(bin), efficiency);
   }
   graph_bdt_efficiency_recomom_positron->SetLineColor( kMagenta);
   graph_bdt_efficiency_recomom_positron->SetFillColor( kWhite);
   graph_bdt_efficiency_recomom_positron->SetLineWidth(2);
   graph_bdt_efficiency_recomom_positron->Draw("L same");
   
   canvas_bdt_efficiency_recomom_sig->BuildLegend();
   canvas_bdt_efficiency_recomom_sig->Write();
   
   TCanvas* canvas_bdt_efficiency_recomom_bkg = new TCanvas("canvas_bdt_efficiency_recomom_bkg","canvas_bdt_efficiency_recomom_bkg",200,10,1000,600);
   
   TGraph* graph_bdt_efficiency_recomom_pi_as_mu = new TGraph();
   graph_bdt_efficiency_recomom_pi_as_mu->SetTitle("#pi^{+} identified as #mu^{+}");
   for (Int_t bin=1; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(musel_recomom_piplus->GetBinContent(bin))/(presel_recomom_piplus->GetBinContent(bin));
      graph_bdt_efficiency_recomom_pi_as_mu->SetPoint(bin-1, presel_recomom_piplus->GetBinCenter(bin), efficiency);
   }
   graph_bdt_efficiency_recomom_pi_as_mu->GetYaxis()->SetRangeUser(0.0, 1.0);
   graph_bdt_efficiency_recomom_pi_as_mu->SetLineColor( kRed);
   graph_bdt_efficiency_recomom_pi_as_mu->SetFillColor( kWhite);
   graph_bdt_efficiency_recomom_pi_as_mu->SetLineWidth(2);
   graph_bdt_efficiency_recomom_pi_as_mu->GetYaxis()->SetTitle("Efficiency");
   graph_bdt_efficiency_recomom_pi_as_mu->GetXaxis()->SetTitle("Reconstructed momentum (MeV/c)");
   graph_bdt_efficiency_recomom_pi_as_mu->Draw("AL");
   
   TGraph* graph_bdt_efficiency_recomom_p_as_mu = new TGraph();
   graph_bdt_efficiency_recomom_p_as_mu->SetTitle("p identified as #mu^{+}");
   for (Int_t bin=2; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(musel_recomom_proton->GetBinContent(bin))/(presel_recomom_proton->GetBinContent(bin));
      graph_bdt_efficiency_recomom_p_as_mu->SetPoint(bin-2, presel_recomom_proton->GetBinCenter(bin), efficiency);
   }
   graph_bdt_efficiency_recomom_p_as_mu->SetLineColor( kGreen);
   graph_bdt_efficiency_recomom_p_as_mu->SetFillColor( kWhite);
   graph_bdt_efficiency_recomom_p_as_mu->SetLineWidth(2);
   graph_bdt_efficiency_recomom_p_as_mu->Draw("L same");
   
   TGraph* graph_bdt_efficiency_recomom_e_as_mu = new TGraph();
   graph_bdt_efficiency_recomom_e_as_mu->SetTitle("e^{+} identified as #mu^{+}");
   for (Int_t bin=1; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(musel_recomom_positron->GetBinContent(bin))/(presel_recomom_positron->GetBinContent(bin));
      graph_bdt_efficiency_recomom_e_as_mu->SetPoint(bin-1, presel_recomom_positron->GetBinCenter(bin), efficiency);
   }
   graph_bdt_efficiency_recomom_e_as_mu->SetLineColor( kMagenta);
   graph_bdt_efficiency_recomom_e_as_mu->SetFillColor( kWhite);
   graph_bdt_efficiency_recomom_e_as_mu->SetLineWidth(2);
   graph_bdt_efficiency_recomom_e_as_mu->Draw("L same");
   
   TGraph* graph_bdt_efficiency_recomom_mu_as_pi = new TGraph();
   graph_bdt_efficiency_recomom_mu_as_pi->SetTitle("#mu^{+} identified as #pi^{+}");
   for (Int_t bin=1; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(pisel_recomom_antimu->GetBinContent(bin))/(presel_recomom_antimu->GetBinContent(bin));
      graph_bdt_efficiency_recomom_mu_as_pi->SetPoint(bin-1, presel_recomom_antimu->GetBinCenter(bin), efficiency);
   }
   graph_bdt_efficiency_recomom_mu_as_pi->SetLineColor( kBlue);
   graph_bdt_efficiency_recomom_mu_as_pi->SetFillColor( kWhite);
   graph_bdt_efficiency_recomom_mu_as_pi->SetLineWidth(2);
   graph_bdt_efficiency_recomom_mu_as_pi->Draw("L same");
   
   TGraph* graph_bdt_efficiency_recomom_p_as_pi = new TGraph();
   graph_bdt_efficiency_recomom_p_as_pi->SetTitle("p identified as #pi^{+}");
   for (Int_t bin=2; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(pisel_recomom_proton->GetBinContent(bin))/(presel_recomom_proton->GetBinContent(bin));
      graph_bdt_efficiency_recomom_p_as_pi->SetPoint(bin-2, presel_recomom_proton->GetBinCenter(bin), efficiency);
   }
   graph_bdt_efficiency_recomom_p_as_pi->SetLineColor( kGreen+1);
   graph_bdt_efficiency_recomom_p_as_pi->SetFillColor( kWhite);
   graph_bdt_efficiency_recomom_p_as_pi->SetLineWidth(2);
   graph_bdt_efficiency_recomom_p_as_pi->Draw("L same");
   
   TGraph* graph_bdt_efficiency_recomom_e_as_pi = new TGraph();
   graph_bdt_efficiency_recomom_e_as_pi->SetTitle("e^{+} identified as #pi^{+}");
   for (Int_t bin=1; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(pisel_recomom_positron->GetBinContent(bin))/(presel_recomom_positron->GetBinContent(bin));
      graph_bdt_efficiency_recomom_e_as_pi->SetPoint(bin-1, presel_recomom_positron->GetBinCenter(bin), efficiency);
   }
   graph_bdt_efficiency_recomom_e_as_pi->SetLineColor( kMagenta+1);
   graph_bdt_efficiency_recomom_e_as_pi->SetFillColor( kWhite);
   graph_bdt_efficiency_recomom_e_as_pi->SetLineWidth(2);
   graph_bdt_efficiency_recomom_e_as_pi->Draw("L same");
   
   TGraph* graph_bdt_efficiency_recomom_mu_as_p = new TGraph();
   graph_bdt_efficiency_recomom_mu_as_p->SetTitle("#mu^{+} identified as p");
   for (Int_t bin=1; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(psel_recomom_antimu->GetBinContent(bin))/(presel_recomom_antimu->GetBinContent(bin));
      graph_bdt_efficiency_recomom_mu_as_p->SetPoint(bin-1, presel_recomom_antimu->GetBinCenter(bin), efficiency);
   }
   graph_bdt_efficiency_recomom_mu_as_p->SetLineColor( kBlue+1);
   graph_bdt_efficiency_recomom_mu_as_p->SetFillColor( kWhite);
   graph_bdt_efficiency_recomom_mu_as_p->SetLineWidth(2);
   graph_bdt_efficiency_recomom_mu_as_p->Draw("L same");
   
   TGraph* graph_bdt_efficiency_recomom_pi_as_p = new TGraph();
   graph_bdt_efficiency_recomom_pi_as_p->SetTitle("#pi^{+} identified as p");
   for (Int_t bin=1; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(psel_recomom_piplus->GetBinContent(bin))/(presel_recomom_piplus->GetBinContent(bin));
      graph_bdt_efficiency_recomom_pi_as_p->SetPoint(bin-1, presel_recomom_piplus->GetBinCenter(bin), efficiency);
   }
   graph_bdt_efficiency_recomom_pi_as_p->SetLineColor( kRed+1);
   graph_bdt_efficiency_recomom_pi_as_p->SetFillColor( kWhite);
   graph_bdt_efficiency_recomom_pi_as_p->SetLineWidth(2);
   graph_bdt_efficiency_recomom_pi_as_p->Draw("L same");
   
   TGraph* graph_bdt_efficiency_recomom_e_as_p = new TGraph();
   graph_bdt_efficiency_recomom_e_as_p->SetTitle("e^{+} identified as p");
   for (Int_t bin=1; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(psel_recomom_positron->GetBinContent(bin))/(presel_recomom_positron->GetBinContent(bin));
      graph_bdt_efficiency_recomom_e_as_p->SetPoint(bin-1, presel_recomom_positron->GetBinCenter(bin), efficiency);
   }
   graph_bdt_efficiency_recomom_e_as_p->SetLineColor( kMagenta+2);
   graph_bdt_efficiency_recomom_e_as_p->SetFillColor( kWhite);
   graph_bdt_efficiency_recomom_e_as_p->SetLineWidth(2);
   graph_bdt_efficiency_recomom_e_as_p->Draw("L same");
   
   TGraph* graph_bdt_efficiency_recomom_mu_as_e = new TGraph();
   graph_bdt_efficiency_recomom_mu_as_e->SetTitle("#mu^{+} identified as e^{+}");
   for (Int_t bin=1; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(esel_recomom_antimu->GetBinContent(bin))/(presel_recomom_antimu->GetBinContent(bin));
      graph_bdt_efficiency_recomom_mu_as_e->SetPoint(bin-1, presel_recomom_antimu->GetBinCenter(bin), efficiency);
   }
   graph_bdt_efficiency_recomom_mu_as_e->SetLineColor( kBlue+2);
   graph_bdt_efficiency_recomom_mu_as_e->SetFillColor( kWhite);
   graph_bdt_efficiency_recomom_mu_as_e->SetLineWidth(2);
   graph_bdt_efficiency_recomom_mu_as_e->Draw("L same");
   
   TGraph* graph_bdt_efficiency_recomom_pi_as_e = new TGraph();
   graph_bdt_efficiency_recomom_pi_as_e->SetTitle("#pi^{+} identified as e^{+}");
   for (Int_t bin=1; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(esel_recomom_piplus->GetBinContent(bin))/(presel_recomom_piplus->GetBinContent(bin));
      graph_bdt_efficiency_recomom_pi_as_e->SetPoint(bin-1, presel_recomom_piplus->GetBinCenter(bin), efficiency);
   }
   graph_bdt_efficiency_recomom_pi_as_e->SetLineColor( kRed+2);
   graph_bdt_efficiency_recomom_pi_as_e->SetFillColor( kWhite);
   graph_bdt_efficiency_recomom_pi_as_e->SetLineWidth(2);
   graph_bdt_efficiency_recomom_pi_as_e->Draw("L same");
   
   TGraph* graph_bdt_efficiency_recomom_p_as_e = new TGraph();
   graph_bdt_efficiency_recomom_p_as_e->SetTitle("p identified as e^{+}");
   for (Int_t bin=2; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(esel_recomom_proton->GetBinContent(bin))/(presel_recomom_proton->GetBinContent(bin));
      graph_bdt_efficiency_recomom_p_as_e->SetPoint(bin-2, presel_recomom_proton->GetBinCenter(bin), efficiency);
   }
   graph_bdt_efficiency_recomom_p_as_e->SetLineColor( kGreen+2);
   graph_bdt_efficiency_recomom_p_as_e->SetFillColor( kWhite);
   graph_bdt_efficiency_recomom_p_as_e->SetLineWidth(2);
   graph_bdt_efficiency_recomom_p_as_e->Draw("L same");
   
   canvas_bdt_efficiency_recomom_bkg->BuildLegend();
   canvas_bdt_efficiency_recomom_bkg->Write();
   
   // Efficiency vs theta
   
   TCanvas* canvas_bdt_efficiency_theta_sig = new TCanvas("canvas_bdt_efficiency_theta_sig","canvas_bdt_efficiency_theta_sig",200,10,1000,600);
   
   TGraph* graph_bdt_efficiency_theta_antimu = new TGraph();
   graph_bdt_efficiency_theta_antimu->SetTitle("#mu^{+} identified as #mu^{+}");
   for (Int_t bin=1; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(musel_theta_antimu->GetBinContent(bin))/(presel_theta_antimu->GetBinContent(bin));
      graph_bdt_efficiency_theta_antimu->SetPoint(bin-1, presel_theta_antimu->GetBinCenter(bin), efficiency);
   }
   graph_bdt_efficiency_theta_antimu->GetYaxis()->SetRangeUser(0.0, 1.0);
   graph_bdt_efficiency_theta_antimu->SetLineColor( kBlue);
   graph_bdt_efficiency_theta_antimu->SetFillColor( kWhite);
   graph_bdt_efficiency_theta_antimu->SetLineWidth(2);
   graph_bdt_efficiency_theta_antimu->GetYaxis()->SetTitle("Efficiency");
   graph_bdt_efficiency_theta_antimu->GetXaxis()->SetTitle("Reconstructed angle w.r.t. detector Z-axis (rad)");
   graph_bdt_efficiency_theta_antimu->Draw("AL");
   
   TGraph* graph_bdt_efficiency_theta_piplus = new TGraph();
   graph_bdt_efficiency_theta_piplus->SetTitle("#pi^{+} identified as #pi^{+}");
   for (Int_t bin=1; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(pisel_theta_piplus->GetBinContent(bin))/(presel_theta_piplus->GetBinContent(bin));
      graph_bdt_efficiency_theta_piplus->SetPoint(bin-1, presel_theta_piplus->GetBinCenter(bin), efficiency);
   }
   graph_bdt_efficiency_theta_piplus->GetYaxis()->SetRangeUser(0.0, 1.0);
   graph_bdt_efficiency_theta_piplus->SetLineColor( kRed);
   graph_bdt_efficiency_theta_piplus->SetFillColor( kWhite);
   graph_bdt_efficiency_theta_piplus->SetLineWidth(2);
   graph_bdt_efficiency_theta_piplus->Draw("L same");
   
   TGraph* graph_bdt_efficiency_theta_proton = new TGraph();
   graph_bdt_efficiency_theta_proton->SetTitle("p identified as p");
   for (Int_t bin=1; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(psel_theta_proton->GetBinContent(bin))/(presel_theta_proton->GetBinContent(bin));
      graph_bdt_efficiency_theta_proton->SetPoint(bin-1, presel_theta_proton->GetBinCenter(bin), efficiency);
   }
   graph_bdt_efficiency_theta_proton->GetYaxis()->SetRangeUser(0.0, 1.0);
   graph_bdt_efficiency_theta_proton->SetLineColor( kGreen);
   graph_bdt_efficiency_theta_proton->SetFillColor( kWhite);
   graph_bdt_efficiency_theta_proton->SetLineWidth(2);
   graph_bdt_efficiency_theta_proton->Draw("L same");
   
   TGraph* graph_bdt_efficiency_theta_positron = new TGraph();
   graph_bdt_efficiency_theta_positron->SetTitle("e^{+} identified as e^{+}");
   for (Int_t bin=1; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(esel_theta_positron->GetBinContent(bin))/(presel_theta_positron->GetBinContent(bin));
      graph_bdt_efficiency_theta_positron->SetPoint(bin-1, presel_theta_positron->GetBinCenter(bin), efficiency);
   }
   graph_bdt_efficiency_theta_positron->GetYaxis()->SetRangeUser(0.0, 1.0);
   graph_bdt_efficiency_theta_positron->SetLineColor( kMagenta);
   graph_bdt_efficiency_theta_positron->SetFillColor( kWhite);
   graph_bdt_efficiency_theta_positron->SetLineWidth(2);
   graph_bdt_efficiency_theta_positron->Draw("L same");
   
   canvas_bdt_efficiency_theta_sig->BuildLegend();
   canvas_bdt_efficiency_theta_sig->Write();
   
   std::cout << "================ TPC LLRS ================" << std::endl << std::endl;
   
   std::cout << "=========== Mu-like ===========" << std::endl << std::endl;
   
   std::cout << "mu+ efficiency: " <<  (Float_t)musel_tpc_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)musel_tpc_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)musel_tpc_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)musel_tpc_nPositron/presel_nPositron << std::endl;
   
   std::cout << "=========== Pi-like ===========" << std::endl << std::endl;
   
   std::cout << "mu+ efficiency: " << (Float_t)pisel_tpc_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)pisel_tpc_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)pisel_tpc_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)pisel_tpc_nPositron/presel_nPositron << std::endl;
   
   std::cout << "=========== Proton-like ===========" << std::endl << std::endl;
   
   std::cout << "mu+ efficiency: " << (Float_t)psel_tpc_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)psel_tpc_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)psel_tpc_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)psel_tpc_nPositron/presel_nPositron << std::endl;
  
   std::cout << "=========== Electron-like ===========" << std::endl << std::endl;
   
   std::cout << "mu+ efficiency: " << (Float_t)esel_tpc_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)esel_tpc_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)esel_tpc_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)esel_tpc_nPositron/presel_nPositron << std::endl;
   
   std::cout << "================ NUMU SELECTION ================" << std::endl << std::endl;
   
   std::cout << "=========== Mu-like ===========" << std::endl << std::endl;
   
   std::cout << "mu+ efficiency: " <<  (Float_t)musel_numu_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)musel_numu_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)musel_numu_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)musel_numu_nPositron/presel_nPositron << std::endl;
   
   std::cout << "=========== Pi-like ===========" << std::endl << std::endl;
   
   std::cout << "mu+ efficiency: " << (Float_t)pisel_numu_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)pisel_numu_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)pisel_numu_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)pisel_numu_nPositron/presel_nPositron << std::endl;
   
   std::cout << "=========== Proton-like ===========" << std::endl << std::endl;
   
   std::cout << "mu+ efficiency: " << (Float_t)psel_numu_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)psel_numu_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)psel_numu_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)psel_numu_nPositron/presel_nPositron << std::endl;
  
   std::cout << "=========== Electron-like ===========" << std::endl << std::endl;
   
   std::cout << "mu+ efficiency: " << (Float_t)esel_numu_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)esel_numu_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)esel_numu_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)esel_numu_nPositron/presel_nPositron << std::endl;
   
   // Efficiency vs recomom
   
   TCanvas* canvas_numu_efficiency_recomom_sig = new TCanvas("canvas_numu_efficiency_recomom_sig","canvas_numu_efficiency_recomom_sig",200,10,1000,600);
   
   TGraph* graph_numu_efficiency_recomom_antimu = new TGraph();
   graph_numu_efficiency_recomom_antimu->SetTitle("#mu^{+} identified as #mu^{+}");
   for (Int_t bin=1; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(musel_numu_recomom_antimu->GetBinContent(bin))/(presel_recomom_antimu->GetBinContent(bin));
      graph_numu_efficiency_recomom_antimu->SetPoint(bin-1, presel_recomom_antimu->GetBinCenter(bin), efficiency);
   }
   graph_numu_efficiency_recomom_antimu->GetYaxis()->SetRangeUser(0.0, 1.0);
   graph_numu_efficiency_recomom_antimu->SetLineColor( kBlue);
   graph_numu_efficiency_recomom_antimu->SetFillColor( kWhite);
   graph_numu_efficiency_recomom_antimu->SetLineWidth(2);
   graph_numu_efficiency_recomom_antimu->GetYaxis()->SetTitle("Efficiency");
   graph_numu_efficiency_recomom_antimu->GetXaxis()->SetTitle("Reconstructed momentum (MeV/c)");
   graph_numu_efficiency_recomom_antimu->Draw("AL");
   
   TGraph* graph_numu_efficiency_recomom_piplus = new TGraph();
   graph_numu_efficiency_recomom_piplus->SetTitle("#pi^{+} identified as #pi^{+}");
   for (Int_t bin=1; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(pisel_numu_recomom_piplus->GetBinContent(bin))/(presel_recomom_piplus->GetBinContent(bin));
      graph_numu_efficiency_recomom_piplus->SetPoint(bin-1, presel_recomom_piplus->GetBinCenter(bin), efficiency);
   }
   graph_numu_efficiency_recomom_piplus->GetYaxis()->SetRangeUser(0.0, 1.0);
   graph_numu_efficiency_recomom_piplus->SetLineColor( kRed);
   graph_numu_efficiency_recomom_piplus->SetFillColor( kWhite);
   graph_numu_efficiency_recomom_piplus->SetLineWidth(2);
   graph_numu_efficiency_recomom_piplus->Draw("L same");
   
   TGraph* graph_numu_efficiency_recomom_proton = new TGraph();
   graph_numu_efficiency_recomom_proton->SetTitle("p identified as p");
   for (Int_t bin=2; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(psel_numu_recomom_proton->GetBinContent(bin))/(presel_recomom_proton->GetBinContent(bin));
      graph_numu_efficiency_recomom_proton->SetPoint(bin-2, presel_recomom_proton->GetBinCenter(bin), efficiency);
   }
   graph_numu_efficiency_recomom_proton->GetYaxis()->SetRangeUser(0.0, 1.0);
   graph_numu_efficiency_recomom_proton->SetLineColor( kGreen);
   graph_numu_efficiency_recomom_proton->SetFillColor( kWhite);
   graph_numu_efficiency_recomom_proton->SetLineWidth(2);
   graph_numu_efficiency_recomom_proton->Draw("L same");
   
   TGraph* graph_numu_efficiency_recomom_positron = new TGraph();
   graph_numu_efficiency_recomom_positron->SetTitle("e^{+} identified as e^{+}");
   for (Int_t bin=1; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(esel_numu_recomom_positron->GetBinContent(bin))/(presel_recomom_positron->GetBinContent(bin));
      graph_numu_efficiency_recomom_positron->SetPoint(bin-1, presel_recomom_positron->GetBinCenter(bin), efficiency);
   }
   graph_numu_efficiency_recomom_positron->GetYaxis()->SetRangeUser(0.0, 1.0);
   graph_numu_efficiency_recomom_positron->SetLineColor( kMagenta);
   graph_numu_efficiency_recomom_positron->SetFillColor( kWhite);
   graph_numu_efficiency_recomom_positron->SetLineWidth(2);
   graph_numu_efficiency_recomom_positron->Draw("L same");
   
   canvas_numu_efficiency_recomom_sig->BuildLegend();
   canvas_numu_efficiency_recomom_sig->Write();
   
   // Efficiency vs theta
   
   TCanvas* canvas_numu_efficiency_theta_sig = new TCanvas("canvas_numu_efficiency_theta_sig","canvas_numu_efficiency_theta_sig",200,10,1000,600);
   
   TGraph* graph_numu_efficiency_theta_antimu = new TGraph();
   graph_numu_efficiency_theta_antimu->SetTitle("#mu^{+} identified as #mu^{+}");
   for (Int_t bin=1; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(musel_numu_theta_antimu->GetBinContent(bin))/(presel_theta_antimu->GetBinContent(bin));
      graph_numu_efficiency_theta_antimu->SetPoint(bin-1, presel_theta_antimu->GetBinCenter(bin), efficiency);
   }
   graph_numu_efficiency_theta_antimu->GetYaxis()->SetRangeUser(0.0, 1.0);
   graph_numu_efficiency_theta_antimu->SetLineColor( kBlue);
   graph_numu_efficiency_theta_antimu->SetFillColor( kWhite);
   graph_numu_efficiency_theta_antimu->SetLineWidth(2);
   graph_numu_efficiency_theta_antimu->GetYaxis()->SetTitle("Efficiency");
   graph_numu_efficiency_theta_antimu->GetXaxis()->SetTitle("Reconstructed angle w.r.t. detector Z-axis (rad)");
   graph_numu_efficiency_theta_antimu->Draw("AL");
   
   TGraph* graph_numu_efficiency_theta_piplus = new TGraph();
   graph_numu_efficiency_theta_piplus->SetTitle("#pi^{+} identified as #pi^{+}");
   for (Int_t bin=1; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(pisel_numu_theta_piplus->GetBinContent(bin))/(presel_theta_piplus->GetBinContent(bin));
      graph_numu_efficiency_theta_piplus->SetPoint(bin-1, presel_theta_piplus->GetBinCenter(bin), efficiency);
   }
   graph_numu_efficiency_theta_piplus->GetYaxis()->SetRangeUser(0.0, 1.0);
   graph_numu_efficiency_theta_piplus->SetLineColor( kRed);
   graph_numu_efficiency_theta_piplus->SetFillColor( kWhite);
   graph_numu_efficiency_theta_piplus->SetLineWidth(2);
   graph_numu_efficiency_theta_piplus->Draw("L same");
   
   TGraph* graph_numu_efficiency_theta_proton = new TGraph();
   graph_numu_efficiency_theta_proton->SetTitle("p identified as p");
   for (Int_t bin=1; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(psel_numu_theta_proton->GetBinContent(bin))/(presel_theta_proton->GetBinContent(bin));
      graph_numu_efficiency_theta_proton->SetPoint(bin-1, presel_theta_proton->GetBinCenter(bin), efficiency);
   }
   graph_numu_efficiency_theta_proton->GetYaxis()->SetRangeUser(0.0, 1.0);
   graph_numu_efficiency_theta_proton->SetLineColor( kGreen);
   graph_numu_efficiency_theta_proton->SetFillColor( kWhite);
   graph_numu_efficiency_theta_proton->SetLineWidth(2);
   graph_numu_efficiency_theta_proton->Draw("L same");
   
   TGraph* graph_numu_efficiency_theta_positron = new TGraph();
   graph_numu_efficiency_theta_positron->SetTitle("e^{+} identified as e^{+}");
   for (Int_t bin=1; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(esel_numu_theta_positron->GetBinContent(bin))/(presel_theta_positron->GetBinContent(bin));
      graph_numu_efficiency_theta_positron->SetPoint(bin-1, presel_theta_positron->GetBinCenter(bin), efficiency);
   }
   graph_numu_efficiency_theta_positron->GetYaxis()->SetRangeUser(0.0, 1.0);
   graph_numu_efficiency_theta_positron->SetLineColor( kMagenta);
   graph_numu_efficiency_theta_positron->SetFillColor( kWhite);
   graph_numu_efficiency_theta_positron->SetLineWidth(2);
   graph_numu_efficiency_theta_positron->Draw("L same");
   
   canvas_numu_efficiency_theta_sig->BuildLegend();
   canvas_numu_efficiency_theta_sig->Write();
   
   std::cout << "================ NUE SELECTION ================" << std::endl << std::endl;
   
   std::cout << "mu+ efficiency: " << (Float_t)esel_nue_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)esel_nue_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)esel_nue_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)esel_nue_nPositron/presel_nPositron << std::endl;
   
   
   // Positron efficiency comparison:
   
   TCanvas* canvas_nue_efficiency_recomom_sig = new TCanvas("canvas_nue_efficiency_recomom_sig","canvas_nue_efficiency_recomom_sig",200,10,1000,600);
   
   TGraph* graph_nue_efficiency_recomom_antimu = new TGraph();
   graph_nue_efficiency_recomom_antimu->SetTitle("#mu^{+} identified as e^{+}");
   for (Int_t bin=1; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(esel_nue_recomom_antimu->GetBinContent(bin))/(presel_recomom_antimu->GetBinContent(bin));
      graph_nue_efficiency_recomom_antimu->SetPoint(bin-1, presel_recomom_antimu->GetBinCenter(bin), efficiency);
   }
   graph_nue_efficiency_recomom_antimu->GetYaxis()->SetRangeUser(0.0, 1.0);
   graph_nue_efficiency_recomom_antimu->SetLineColor( kBlue);
   graph_nue_efficiency_recomom_antimu->SetFillColor( kWhite);
   graph_nue_efficiency_recomom_antimu->SetLineWidth(2);
   graph_nue_efficiency_recomom_antimu->GetYaxis()->SetTitle("Efficiency");
   graph_nue_efficiency_recomom_antimu->GetXaxis()->SetTitle("Reconstructed momentum (MeV/c)");
   graph_nue_efficiency_recomom_antimu->Draw("AL");
   
   TGraph* graph_nue_efficiency_recomom_piplus = new TGraph();
   graph_nue_efficiency_recomom_piplus->SetTitle("#pi^{+} identified as e^{+}");
   for (Int_t bin=1; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(esel_nue_recomom_piplus->GetBinContent(bin))/(presel_recomom_piplus->GetBinContent(bin));
      graph_nue_efficiency_recomom_piplus->SetPoint(bin-1, presel_recomom_piplus->GetBinCenter(bin), efficiency);
   }
   graph_nue_efficiency_recomom_piplus->SetLineColor( kRed);
   graph_nue_efficiency_recomom_piplus->SetFillColor( kWhite);
   graph_nue_efficiency_recomom_piplus->SetLineWidth(2);
   graph_nue_efficiency_recomom_piplus->Draw("L same");
   
   TGraph* graph_nue_efficiency_recomom_proton = new TGraph();
   graph_nue_efficiency_recomom_proton->SetTitle("p identified as e^{+}");
   for (Int_t bin=2; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(esel_nue_recomom_proton->GetBinContent(bin))/(presel_recomom_proton->GetBinContent(bin));
      graph_nue_efficiency_recomom_proton->SetPoint(bin-2, presel_recomom_proton->GetBinCenter(bin), efficiency);
   }
   graph_nue_efficiency_recomom_proton->SetLineColor( kGreen);
   graph_nue_efficiency_recomom_proton->SetFillColor( kWhite);
   graph_nue_efficiency_recomom_proton->SetLineWidth(2);
   graph_nue_efficiency_recomom_proton->Draw("L same");
   
   TGraph* graph_nue_efficiency_recomom_positron = new TGraph();
   graph_nue_efficiency_recomom_positron->SetTitle("e^{+} identified as e^{+}");
   for (Int_t bin=1; bin <= 13; bin++)
   {
      Float_t efficiency = (float)(esel_nue_recomom_positron->GetBinContent(bin))/(presel_recomom_positron->GetBinContent(bin));
      graph_nue_efficiency_recomom_positron->SetPoint(bin-1, presel_recomom_positron->GetBinCenter(bin), efficiency);
   }
   graph_nue_efficiency_recomom_positron->SetLineColor( kMagenta);
   graph_nue_efficiency_recomom_positron->SetFillColor( kWhite);
   graph_nue_efficiency_recomom_positron->SetLineWidth(2);
   graph_nue_efficiency_recomom_positron->Draw("L same");
   
   canvas_nue_efficiency_recomom_sig->BuildLegend();
   canvas_nue_efficiency_recomom_sig->Write();
     
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
