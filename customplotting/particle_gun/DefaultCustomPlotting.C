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

   
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   gStyle->SetTitleYOffset(1.2);
   gStyle->SetTitleXOffset(1.2);
   
   
   
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntries();
   
   std::cout << "Total entries to process: " << nentries << std::endl << std::endl;
   
   std::time_t time_start = std::time(0);
   
   Int_t variable_bins = 50;
   
   TH1F *recomom_antimu = new TH1F("recomom_antimu", "Antimuon;Reconstructed momentum (MeV/c);Entries/50 MeV/c", 32, 0.0, 1600.0);
   TH1F *recomom_piplus = new TH1F("recomom_piplus", "Pi+", 32, 0.0, 1600.0);
   TH1F *recomom_proton = new TH1F("recomom_proton", "Proton", 32, 0.0, 1600.0);
   TH1F *recomom_positron = new TH1F("recomom_positron", "Positron", 32, 0.0, 1600.0);
   
   TH1F *theta_antimu = new TH1F("theta_antimu", "Antimuon;Reconstructed angle w.r.t. detector Z-axis (rad);Entries/0.05 rad", 24, 0.0, 1.2);
   TH1F *theta_piplus = new TH1F("theta_piplus", "Pi+", 24, 0.0, 1.2);
   TH1F *theta_proton = new TH1F("theta_proton", "Proton", 24, 0.0, 1.2);
   TH1F *theta_positron = new TH1F("theta_positron", "Positron", 24, 0.0, 1.2);
   
   TH1F *EMEnergy_antimu = new TH1F("EMEnergy_antimu", "Antimuon;Reconstructed ECal EM energy (MeV);Entries/50 MeV", 50, 0.0, 2500);
   TH1F *EMEnergy_piplus = new TH1F("EMEnergy_piplus", "Pi+", 50, 0.0, 2500);
   TH1F *EMEnergy_proton = new TH1F("EMEnergy_proton", "Proton", 50, 0.0, 2500);
   TH1F *EMEnergy_positron = new TH1F("EMEnergy_positron", "Positron", 50, 0.0, 2500);
   
   TH1F *EbyL_antimu = new TH1F("EbyL_antimu", "Antimuon;ECal EM energy/ECal segment length (MeV/mm);Entries/10 MeV/mm", 40, 0.0, 4);
   TH1F *EbyL_piplus = new TH1F("EbyL_piplus", "Pi+", 40, 0.0, 4);
   TH1F *EbyL_proton = new TH1F("EbyL_proton", "Proton", 40, 0.0, 4);
   TH1F *EbyL_positron = new TH1F("EbyL_positron", "Positron", 40, 0.0, 4);
   
   TH1F *circularity_antimu = new TH1F("circularity_antimu", "Antimuon;ECal circularity variable (dimensionless);Entries", 50, 0.0, 1.0);
   TH1F *circularity_piplus = new TH1F("circularity_piplus", "Pi+", 50, 0.0, 1.0);
   TH1F *circularity_proton = new TH1F("circularity_proton", "Proton", 50, 0.0, 1.0);
   TH1F *circularity_positron = new TH1F("circularity_positron", "Positron", 50, 0.0, 1.0);
   
   TH1F *fbr_antimu = new TH1F("fbr_antimu", "Antimuon;ECal FrontBackRatio variable (dimensionless);Entries", 50, 0.0, 10.0);
   TH1F *fbr_piplus = new TH1F("fbr_piplus", "Pi+", 50, 0.0, 10.0);
   TH1F *fbr_proton = new TH1F("fbr_proton", "Proton", 50, 0.0, 10.0);
   TH1F *fbr_positron = new TH1F("fbr_positron", "Positron", 50, 0.0, 10.0);
   
   TH1F *tmr_antimu = new TH1F("tmr_antimu", "Antimuon;ECal TransverseMaxRatio variable (dimensionless);Entries", 50, 0.0, 1.0);
   TH1F *tmr_piplus = new TH1F("tmr_piplus", "Pi+", 50, 0.0, 1.0);
   TH1F *tmr_proton = new TH1F("tmr_proton", "Proton", 50, 0.0, 1.0);
   TH1F *tmr_positron = new TH1F("tmr_positron", "Positron", 50, 0.0, 1.0);
   
   TH1F *qrms_antimu = new TH1F("qrms_antimu", "Antimuon;ECal QRMS variable ();Entries/", 30, 0.0, 3.0);
   TH1F *qrms_piplus = new TH1F("qrms_piplus", "Pi+", 30, 0.0, 3.0);
   TH1F *qrms_proton = new TH1F("qrms_proton", "Proton", 30, 0.0, 3.0);
   TH1F *qrms_positron = new TH1F("qrms_positron", "Positron", 30, 0.0, 3.0);
   
   TH1F *mipem_antimu = new TH1F("mipem_antimu", "Antimuon;ECal MipEm variable (dimensionless);Entries", 50, 50.0, 50.0);
   TH1F *mipem_piplus = new TH1F("mipem_piplus", "Pi+", 50, 50.0, 50.0);
   TH1F *mipem_proton = new TH1F("mipem_proton", "Proton", 50, 50.0, 50.0);
   TH1F *mipem_positron = new TH1F("mipem_positron", "Positron", 50, 50.0, 50.0);
   
   TH1F *emhip_antimu = new TH1F("emhip_antimu", "Antimuon;ECal EmHip variable (dimensionless);Entries", 50, 50.0, 50.0);
   TH1F *emhip_piplus = new TH1F("emhip_piplus", "Pi+", 50, 50.0, 50.0);
   TH1F *emhip_proton = new TH1F("emhip_proton", "Proton", 50, 50.0, 50.0);
   TH1F *emhip_positron = new TH1F("emhip_positron", "Positron", 50, 50.0, 50.0);
   
   TH1F *mippion_antimu = new TH1F("mippion_antimu", "Antimuon;ECal MipPion variable (dimensionless);Entries", 50, 50.0, 50.0);
   TH1F *mippion_piplus = new TH1F("mippion_piplus", "Pi+", 50, 50.0, 50.0);
   TH1F *mippion_proton = new TH1F("mippion_proton", "Proton", 50, 50.0, 50.0);
   TH1F *mippion_positron = new TH1F("mippion_positron", "Positron", 50, 50.0, 50.0);
   
   TH1F *tpc2dedx_antimu = new TH1F("tpc2dedx_antimu", "Antimuon;TPC2 dE/dx truncated mean ();Entries/", 50, 0.0, 2000.0);
   TH1F *tpc2dedx_piplus = new TH1F("tpc2dedx_piplus", "Pi+", 50, 0.0, 2000.0);
   TH1F *tpc2dedx_proton = new TH1F("tpc2dedx_proton", "Proton", 50, 0.0, 2000.0);
   TH1F *tpc2dedx_positron = new TH1F("tpc2dedx_positron", "Positron", 50, 0.0, 2000.0);
   
   TH1F *tpc3dedx_antimu = new TH1F("tpc3dedx_antimu", "Antimuon;TPC3 dE/dx truncated mean ();Entries/", 50, 0.0, 2000.0);
   TH1F *tpc3dedx_piplus = new TH1F("tpc3dedx_piplus", "Pi+", 50, 0.0, 2000.0);
   TH1F *tpc3dedx_proton = new TH1F("tpc3dedx_proton", "Proton", 50, 0.0, 2000.0);
   TH1F *tpc3dedx_positron = new TH1F("tpc3dedx_positron", "Positron", 50, 0.0, 2000.0);
   
   TH1F *tpclikemu_antimu = new TH1F("tpclikemu_antimu", "Antimuon;TPC muon likelihood;Entries", 50, 0.0, 1.0);
   TH1F *tpclikemu_piplus = new TH1F("tpclikemu_piplus", "Pi+", 50, 0.0, 1.0);
   TH1F *tpclikemu_proton = new TH1F("tpclikemu_proton", "Proton", 50, 0.0, 1.0);
   TH1F *tpclikemu_positron = new TH1F("tpclikemu_positron", "Positron", 50, 0.0, 1.0);
   
   TH1F *tpclikepi_antimu = new TH1F("tpclikepi_antimu", "Antimuon;TPC charged pion likelihood;Entries", 50, 0.0, 1.0);
   TH1F *tpclikepi_piplus = new TH1F("tpclikepi_piplus", "Pi+", 50, 0.0, 1.0);
   TH1F *tpclikepi_proton = new TH1F("tpclikepi_proton", "Proton", 50, 0.0, 1.0);
   TH1F *tpclikepi_positron = new TH1F("tpclikepi_positron", "Positron", 50, 0.0, 1.0);
   
   TH1F *tpclikep_antimu = new TH1F("tpclikep_antimu", "Antimuon;TPC proton likelihood;Entries", 50, 0.0, 1.0);
   TH1F *tpclikep_piplus = new TH1F("tpclikep_piplus", "Pi+", 50, 0.0, 1.0);
   TH1F *tpclikep_proton = new TH1F("tpclikep_proton", "Proton", 50, 0.0, 1.0);
   TH1F *tpclikep_positron = new TH1F("tpclikep_positron", "Positron", 50, 0.0, 1.0);
   
   TH1F *tpclikee_antimu = new TH1F("tpclikee_antimu", "Antimuon;TPC electron likelihood;Entries", 50, 0.0, 1.0);
   TH1F *tpclikee_piplus = new TH1F("tpclikee_piplus", "Pi+", 50, 0.0, 1.0);
   TH1F *tpclikee_proton = new TH1F("tpclikee_proton", "Proton", 50, 0.0, 1.0);
   TH1F *tpclikee_positron = new TH1F("tpclikee_positron", "Positron", 50, 0.0, 1.0);
   
   TH1F *fgd1EbyL_antimu = new TH1F("fgd1EbyL_antimu", "Antimuon;FGD1 energy/length (MeV/mm);Entries", 50, 0.0, 1.0);
   TH1F *fgd1EbyL_piplus = new TH1F("fgd1EbyL_piplus", "Pi+", 50, 0.0, 1.0);
   TH1F *fgd1EbyL_proton = new TH1F("fgd1EbyL_proton", "Proton", 50, 0.0, 1.0);
   TH1F *fgd1EbyL_positron = new TH1F("fgd1EbyL_positron", "Positron", 50, 0.0, 1.0);
   
   TH1F *fgd2EbyL_antimu = new TH1F("fgd2EbyL_antimu", "Antimuon;FGD2 energy/length (MeV/mm);Entries", 30, 0.0, 0.6);
   TH1F *fgd2EbyL_piplus = new TH1F("fgd2EbyL_piplus", "Pi+", 30, 0.0, 0.6);
   TH1F *fgd2EbyL_proton = new TH1F("fgd2EbyL_proton", "Proton", 30, 0.0, 0.6);
   TH1F *fgd2EbyL_positron = new TH1F("fgd2EbyL_positron", "Positron", 30, 0.0, 0.6);
   
   TH1F *nsmrds_antimu = new TH1F("nsmrds_antimu", "Antimuon;Number of SMRD segments;Entries", 3, -0.5, 2.5);
   TH1F *nsmrds_piplus = new TH1F("nsmrds_piplus", "Pi+", 3, -0.5, 2.5);
   TH1F *nsmrds_proton = new TH1F("nsmrds_proton", "Proton", 3, -0.5, 2.5);
   TH1F *nsmrds_positron = new TH1F("nsmrds_positron", "Positron", 3, -0.5, 2.5);
   
   
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
            theta_antimu->Fill(selmu_det_theta);
            EMEnergy_antimu->Fill(selmu_ecal_bestseg_EMenergy);
            EbyL_antimu->Fill(selmu_ecal_bestseg_EbyL);
            circularity_antimu->Fill(selmu_ecal_circularity);
            fbr_antimu->Fill(selmu_ecal_fbr);
            tmr_antimu->Fill(selmu_ecal_tmr);
            qrms_antimu->Fill(selmu_ecal_qrms);
            mipem_antimu->Fill(selmu_ecal_mipem[0]);
            emhip_antimu->Fill(selmu_ecal_emhip[0]);
            mippion_antimu->Fill(selmu_ecal_mippion[0]);
            tpc2dedx_antimu->Fill(selmu_tpc_dedx[0]);
            tpc3dedx_antimu->Fill(selmu_tpc_dedx[1]);
            tpclikemu_antimu->Fill(selmu_tpc_like_mu);
            tpclikepi_antimu->Fill(selmu_tpc_like_pi);
            tpclikep_antimu->Fill(selmu_tpc_like_p);
            tpclikee_antimu->Fill(selmu_tpc_like_e);
            fgd1EbyL_antimu->Fill(selmu_fgd1_EbyL);
            fgd2EbyL_antimu->Fill(selmu_fgd2_EbyL);
            nsmrds_antimu->Fill(selmu_nsmrds);
         }
         else if ((particle == 211)&&(particle_pg == 211))
         {
            recomom_piplus->Fill(selmu_mom[0]);
            theta_piplus->Fill(selmu_det_theta);
            EMEnergy_piplus->Fill(selmu_ecal_bestseg_EMenergy);
            EbyL_piplus->Fill(selmu_ecal_bestseg_EbyL);
            circularity_piplus->Fill(selmu_ecal_circularity);
            fbr_piplus->Fill(selmu_ecal_fbr);
            tmr_piplus->Fill(selmu_ecal_tmr);
            qrms_piplus->Fill(selmu_ecal_qrms);
            mipem_piplus->Fill(selmu_ecal_mipem[0]);
            emhip_piplus->Fill(selmu_ecal_emhip[0]);
            mippion_piplus->Fill(selmu_ecal_mippion[0]);
            tpc2dedx_piplus->Fill(selmu_tpc_dedx[0]);
            tpc3dedx_piplus->Fill(selmu_tpc_dedx[1]);
            tpclikemu_piplus->Fill(selmu_tpc_like_mu);
            tpclikepi_piplus->Fill(selmu_tpc_like_pi);
            tpclikep_piplus->Fill(selmu_tpc_like_p);
            tpclikee_piplus->Fill(selmu_tpc_like_e);
            fgd1EbyL_piplus->Fill(selmu_fgd1_EbyL);
            fgd2EbyL_piplus->Fill(selmu_fgd2_EbyL);
            nsmrds_piplus->Fill(selmu_nsmrds);
         }
         else if ((particle == 2212)&&(particle_pg == 2212))
         {
            recomom_proton->Fill(selmu_mom[0]);
            theta_proton->Fill(selmu_det_theta);
            EMEnergy_proton->Fill(selmu_ecal_bestseg_EMenergy);
            EbyL_proton->Fill(selmu_ecal_bestseg_EbyL);
            circularity_proton->Fill(selmu_ecal_circularity);
            fbr_proton->Fill(selmu_ecal_fbr);
            tmr_proton->Fill(selmu_ecal_tmr);
            qrms_proton->Fill(selmu_ecal_qrms);
            mipem_proton->Fill(selmu_ecal_mipem[0]);
            emhip_proton->Fill(selmu_ecal_emhip[0]);
            mippion_proton->Fill(selmu_ecal_mippion[0]);
            tpc2dedx_proton->Fill(selmu_tpc_dedx[0]);
            tpc3dedx_proton->Fill(selmu_tpc_dedx[1]);
            tpclikemu_proton->Fill(selmu_tpc_like_mu);
            tpclikepi_proton->Fill(selmu_tpc_like_pi);
            tpclikep_proton->Fill(selmu_tpc_like_p);
            tpclikee_proton->Fill(selmu_tpc_like_e);
            fgd1EbyL_proton->Fill(selmu_fgd1_EbyL);
            fgd2EbyL_proton->Fill(selmu_fgd2_EbyL);
            nsmrds_proton->Fill(selmu_nsmrds);
         }
         else if ((particle == -11)&&(particle_pg == -11))
         {
            recomom_positron->Fill(selmu_mom[0]);
            theta_positron->Fill(selmu_det_theta);
            EMEnergy_positron->Fill(selmu_ecal_bestseg_EMenergy);
            EbyL_positron->Fill(selmu_ecal_bestseg_EbyL);
            circularity_positron->Fill(selmu_ecal_circularity);
            fbr_positron->Fill(selmu_ecal_fbr);
            tmr_positron->Fill(selmu_ecal_tmr);
            qrms_positron->Fill(selmu_ecal_qrms);
            mipem_positron->Fill(selmu_ecal_mipem[0]);
            emhip_positron->Fill(selmu_ecal_emhip[0]);
            mippion_positron->Fill(selmu_ecal_mippion[0]);
            tpc2dedx_positron->Fill(selmu_tpc_dedx[0]);
            tpc3dedx_positron->Fill(selmu_tpc_dedx[1]);
            tpclikemu_positron->Fill(selmu_tpc_like_mu);
            tpclikepi_positron->Fill(selmu_tpc_like_pi);
            tpclikep_positron->Fill(selmu_tpc_like_p);
            tpclikee_positron->Fill(selmu_tpc_like_e);
            fgd1EbyL_positron->Fill(selmu_fgd1_EbyL);
            fgd2EbyL_positron->Fill(selmu_fgd2_EbyL);
            nsmrds_positron->Fill(selmu_nsmrds);
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
   
   // Reco momentum
   
   TCanvas* canvas_recomom = new TCanvas("canvas_recomom","Reconstructed momentum (MeV/c)",200,10,1000,600);
   
   recomom_antimu->GetYaxis()->SetRangeUser(0.0, 6000.0);
  
   SetHistParticleStyle(recomom_antimu, "antimu");
   SetHistParticleStyle(recomom_piplus, "piplus");
   SetHistParticleStyle(recomom_proton, "proton");
   SetHistParticleStyle(recomom_positron, "positron");
   
   recomom_antimu->Draw();
   recomom_piplus->Draw("same");
   recomom_proton->Draw("same");
   recomom_positron->Draw("same");
   canvas_recomom->BuildLegend();
   canvas_recomom->Write();
   
   // Reco theta
   
   TCanvas* canvas_theta = new TCanvas("canvas_theta","Reconstructed angle w.r.t. detector Z-axis (rad)",200,10,1000,600);
   
   theta_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(theta_antimu, "antimu");
   SetHistParticleStyle(theta_piplus, "piplus");
   SetHistParticleStyle(theta_proton, "proton");
   SetHistParticleStyle(theta_positron, "positron");
   
   theta_antimu->Draw();
   theta_piplus->Draw("same");
   theta_proton->Draw("same");
   theta_positron->Draw("same");
   canvas_theta->BuildLegend();
   canvas_theta->Write();
   
   // ECal EM energy
   
   TCanvas* canvas_EMEnergy = new TCanvas("canvas_EMEnergy","",200,10,1000,600);
   
   //EMEnergy_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(EMEnergy_antimu, "antimu");
   SetHistParticleStyle(EMEnergy_piplus, "piplus");
   SetHistParticleStyle(EMEnergy_proton, "proton");
   SetHistParticleStyle(EMEnergy_positron, "positron");
   
   EMEnergy_antimu->Draw();
   EMEnergy_piplus->Draw("same");
   EMEnergy_proton->Draw("same");
   EMEnergy_positron->Draw("same");
   canvas_EMEnergy->BuildLegend();
   canvas_EMEnergy->Write();
   
   // ECal E/L
   
   TCanvas* canvas_EbyL = new TCanvas("canvas_EbyL","",200,10,1000,600);
   
   //EbyL_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(EbyL_antimu, "antimu");
   SetHistParticleStyle(EbyL_piplus, "piplus");
   SetHistParticleStyle(EbyL_proton, "proton");
   SetHistParticleStyle(EbyL_positron, "positron");
   
   EbyL_antimu->Draw();
   EbyL_piplus->Draw("same");
   EbyL_proton->Draw("same");
   EbyL_positron->Draw("same");
   canvas_EbyL->BuildLegend();
   canvas_EbyL->Write();
   
   // ECal circularity
   
   TCanvas* canvas_circularity = new TCanvas("canvas_circularity","",200,10,1000,600);
   
   //circularity_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(circularity_antimu, "antimu");
   SetHistParticleStyle(circularity_piplus, "piplus");
   SetHistParticleStyle(circularity_proton, "proton");
   SetHistParticleStyle(circularity_positron, "positron");
   
   circularity_antimu->Draw();
   circularity_piplus->Draw("same");
   circularity_proton->Draw("same");
   circularity_positron->Draw("same");
   canvas_circularity->BuildLegend();
   canvas_circularity->Write();
   
   // ECal FBR
   
   TCanvas* canvas_fbr = new TCanvas("canvas_fbr","",200,10,1000,600);
   
   fbr_antimu->GetYaxis()->SetRangeUser(0.0, 20000.0);
  
   SetHistParticleStyle(fbr_antimu, "antimu");
   SetHistParticleStyle(fbr_piplus, "piplus");
   SetHistParticleStyle(fbr_proton, "proton");
   SetHistParticleStyle(fbr_positron, "positron");
   
   fbr_antimu->Draw();
   fbr_piplus->Draw("same");
   fbr_proton->Draw("same");
   fbr_positron->Draw("same");
   canvas_fbr->BuildLegend();
   canvas_fbr->Write();
   
   // ECal TMR
   
   TCanvas* canvas_tmr = new TCanvas("canvas_tmr","",200,10,1000,600);
   
   tmr_antimu->GetYaxis()->SetRangeUser(0.0, 6000.0);
  
   SetHistParticleStyle(tmr_antimu, "antimu");
   SetHistParticleStyle(tmr_piplus, "piplus");
   SetHistParticleStyle(tmr_proton, "proton");
   SetHistParticleStyle(tmr_positron, "positron");
   
   tmr_antimu->Draw();
   tmr_piplus->Draw("same");
   tmr_proton->Draw("same");
   tmr_positron->Draw("same");
   canvas_tmr->BuildLegend();
   canvas_tmr->Write();
   
   // ECal QRMS
   
   TCanvas* canvas_qrms = new TCanvas("canvas_qrms","",200,10,1000,600);
   
   //qrms_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(qrms_antimu, "antimu");
   SetHistParticleStyle(qrms_piplus, "piplus");
   SetHistParticleStyle(qrms_proton, "proton");
   SetHistParticleStyle(qrms_positron, "positron");
   
   qrms_antimu->Draw();
   qrms_piplus->Draw("same");
   qrms_proton->Draw("same");
   qrms_positron->Draw("same");
   canvas_qrms->BuildLegend();
   canvas_qrms->Write();
   
   // ECal MipEm
   
   TCanvas* canvas_mipem = new TCanvas("canvas_mipem","",200,10,1000,600);
   
   //mipem_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(mipem_antimu, "antimu");
   SetHistParticleStyle(mipem_piplus, "piplus");
   SetHistParticleStyle(mipem_proton, "proton");
   SetHistParticleStyle(mipem_positron, "positron");
   
   mipem_antimu->Draw();
   mipem_piplus->Draw("same");
   mipem_proton->Draw("same");
   mipem_positron->Draw("same");
   canvas_mipem->BuildLegend();
   canvas_mipem->Write();
   
   // ECal EmHip
   
   TCanvas* canvas_emhip = new TCanvas("canvas_emhip","",200,10,1000,600);
   
   //emhip_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(emhip_antimu, "antimu");
   SetHistParticleStyle(emhip_piplus, "piplus");
   SetHistParticleStyle(emhip_proton, "proton");
   SetHistParticleStyle(emhip_positron, "positron");
   
   emhip_antimu->Draw();
   emhip_piplus->Draw("same");
   emhip_proton->Draw("same");
   emhip_positron->Draw("same");
   canvas_emhip->BuildLegend();
   canvas_emhip->Write();
   
   // ECal MipPion
   
   TCanvas* canvas_mippion = new TCanvas("canvas_mippion","",200,10,1000,600);
   
   //mippion_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(mippion_antimu, "antimu");
   SetHistParticleStyle(mippion_piplus, "piplus");
   SetHistParticleStyle(mippion_proton, "proton");
   SetHistParticleStyle(mippion_positron, "positron");
   
   mippion_antimu->Draw();
   mippion_piplus->Draw("same");
   mippion_proton->Draw("same");
   mippion_positron->Draw("same");
   canvas_mippion->BuildLegend();
   canvas_mippion->Write();
   
   // TPC2 dE/dx
   
   TCanvas* canvas_tpc2dedx = new TCanvas("canvas_tpc2dedx","",200,10,1000,600);
   
   //tpc2dedx_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(tpc2dedx_antimu, "antimu");
   SetHistParticleStyle(tpc2dedx_piplus, "piplus");
   SetHistParticleStyle(tpc2dedx_proton, "proton");
   SetHistParticleStyle(tpc2dedx_positron, "positron");
   
   tpc2dedx_antimu->Draw();
   tpc2dedx_piplus->Draw("same");
   tpc2dedx_proton->Draw("same");
   tpc2dedx_positron->Draw("same");
   canvas_tpc2dedx->BuildLegend();
   canvas_tpc2dedx->Write();
   
   // TPC3 dE/dx
   
   TCanvas* canvas_tpc3dedx = new TCanvas("canvas_tpc3dedx","",200,10,1000,600);
   
   //tpc3dedx_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(tpc3dedx_antimu, "antimu");
   SetHistParticleStyle(tpc3dedx_piplus, "piplus");
   SetHistParticleStyle(tpc3dedx_proton, "proton");
   SetHistParticleStyle(tpc3dedx_positron, "positron");
   
   tpc3dedx_antimu->Draw();
   tpc3dedx_piplus->Draw("same");
   tpc3dedx_proton->Draw("same");
   tpc3dedx_positron->Draw("same");
   canvas_tpc3dedx->BuildLegend();
   canvas_tpc3dedx->Write();
   
   // TPC mu-like
   
   TCanvas* canvas_tpclikemu = new TCanvas("canvas_tpclikemu","",200,10,1000,600);
   
   //tpclikemu_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(tpclikemu_antimu, "antimu");
   SetHistParticleStyle(tpclikemu_piplus, "piplus");
   SetHistParticleStyle(tpclikemu_proton, "proton");
   SetHistParticleStyle(tpclikemu_positron, "positron");
   
   tpclikemu_antimu->Draw();
   tpclikemu_piplus->Draw("same");
   tpclikemu_proton->Draw("same");
   tpclikemu_positron->Draw("same");
   canvas_tpclikemu->BuildLegend();
   canvas_tpclikemu->Write();
   
   // TPC pi-like
   
   TCanvas* canvas_tpclikepi = new TCanvas("canvas_tpclikepi","",200,10,1000,600);
   
   //tpclikepi_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(tpclikepi_antimu, "antimu");
   SetHistParticleStyle(tpclikepi_piplus, "piplus");
   SetHistParticleStyle(tpclikepi_proton, "proton");
   SetHistParticleStyle(tpclikepi_positron, "positron");
   
   tpclikepi_antimu->Draw();
   tpclikepi_piplus->Draw("same");
   tpclikepi_proton->Draw("same");
   tpclikepi_positron->Draw("same");
   canvas_tpclikepi->BuildLegend();
   canvas_tpclikepi->Write();
   
   // TPC p-like
   
   TCanvas* canvas_tpclikep = new TCanvas("canvas_tpclikep","",200,10,1000,600);
   
   //tpclikep_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(tpclikep_antimu, "antimu");
   SetHistParticleStyle(tpclikep_piplus, "piplus");
   SetHistParticleStyle(tpclikep_proton, "proton");
   SetHistParticleStyle(tpclikep_positron, "positron");
   
   tpclikep_antimu->Draw();
   tpclikep_piplus->Draw("same");
   tpclikep_proton->Draw("same");
   tpclikep_positron->Draw("same");
   canvas_tpclikep->BuildLegend();
   canvas_tpclikep->Write();
   
   // TPC e-like
   
   TCanvas* canvas_tpclikee = new TCanvas("canvas_tpclikee","",200,10,1000,600);
   
   //tpclikee_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(tpclikee_antimu, "antimu");
   SetHistParticleStyle(tpclikee_piplus, "piplus");
   SetHistParticleStyle(tpclikee_proton, "proton");
   SetHistParticleStyle(tpclikee_positron, "positron");
   
   tpclikee_antimu->Draw();
   tpclikee_piplus->Draw("same");
   tpclikee_proton->Draw("same");
   tpclikee_positron->Draw("same");
   canvas_tpclikee->BuildLegend();
   canvas_tpclikee->Write();
   
   // FGD1 E/L
   
   TCanvas* canvas_fgd1EbyL = new TCanvas("canvas_fgd1EbyL","",200,10,1000,600);
   
   //fgd1EbyL_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(fgd1EbyL_antimu, "antimu");
   SetHistParticleStyle(fgd1EbyL_piplus, "piplus");
   SetHistParticleStyle(fgd1EbyL_proton, "proton");
   SetHistParticleStyle(fgd1EbyL_positron, "positron");
   
   fgd1EbyL_antimu->Draw();
   fgd1EbyL_piplus->Draw("same");
   fgd1EbyL_proton->Draw("same");
   fgd1EbyL_positron->Draw("same");
   canvas_fgd1EbyL->BuildLegend();
   canvas_fgd1EbyL->Write();
   
   // FGD2 E/L
   
   TCanvas* canvas_fgd2EbyL = new TCanvas("canvas_fgd2EbyL","",200,10,1000,600);
   
   //fgd2EbyL_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(fgd2EbyL_antimu, "antimu");
   SetHistParticleStyle(fgd2EbyL_piplus, "piplus");
   SetHistParticleStyle(fgd2EbyL_proton, "proton");
   SetHistParticleStyle(fgd2EbyL_positron, "positron");
   
   fgd2EbyL_antimu->Draw();
   fgd2EbyL_piplus->Draw("same");
   fgd2EbyL_proton->Draw("same");
   fgd2EbyL_positron->Draw("same");
   canvas_fgd2EbyL->BuildLegend();
   canvas_fgd2EbyL->Write();
   
   // nSMRDs
   
   TCanvas* canvas_nsmrds = new TCanvas("canvas_nsmrds","",200,10,1000,600);
   
   //nsmrds_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(nsmrds_antimu, "antimu");
   SetHistParticleStyle(nsmrds_piplus, "piplus");
   SetHistParticleStyle(nsmrds_proton, "proton");
   SetHistParticleStyle(nsmrds_positron, "positron");
   
   nsmrds_antimu->Draw();
   nsmrds_piplus->Draw("same");
   nsmrds_proton->Draw("same");
   nsmrds_positron->Draw("same");
   canvas_nsmrds->BuildLegend();
   canvas_nsmrds->Write();
   
   
   
   
   
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
