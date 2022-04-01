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
   gStyle->SetTitleYOffset(1.6);
   gStyle->SetTitleXOffset(1.2);
   
   
   TString parameter = "randomforests";
   
   
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
   
   TH1F *tmr_antimu = new TH1F("tmr_antimu", "Antimuon;ECal TruncatedMaxRatio variable (dimensionless);Entries", 50, 0.0, 1.0);
   TH1F *tmr_piplus = new TH1F("tmr_piplus", "Pi+", 50, 0.0, 1.0);
   TH1F *tmr_proton = new TH1F("tmr_proton", "Proton", 50, 0.0, 1.0);
   TH1F *tmr_positron = new TH1F("tmr_positron", "Positron", 50, 0.0, 1.0);
   
   TH1F *qrms_antimu = new TH1F("qrms_antimu", "Antimuon;ECal QRMS variable (dimensionless);Entries", 30, 0.0, 3.0);
   TH1F *qrms_piplus = new TH1F("qrms_piplus", "Pi+", 30, 0.0, 3.0);
   TH1F *qrms_proton = new TH1F("qrms_proton", "Proton", 30, 0.0, 3.0);
   TH1F *qrms_positron = new TH1F("qrms_positron", "Positron", 30, 0.0, 3.0);
   
   TH1F *mipem_antimu = new TH1F("mipem_antimu", "Antimuon;ECal MipEm variable (dimensionless);Entries", 60, -50.0, 70.0);
   TH1F *mipem_piplus = new TH1F("mipem_piplus", "Pi+", 60, -50.0, 70.0);
   TH1F *mipem_proton = new TH1F("mipem_proton", "Proton", 60, -50.0, 70.0);
   TH1F *mipem_positron = new TH1F("mipem_positron", "Positron", 60, -50.0, 70.0);
   
   TH1F *emhip_antimu = new TH1F("emhip_antimu", "Antimuon;ECal EmHip variable (dimensionless);Entries", 40, -40.0, 40.0);
   TH1F *emhip_piplus = new TH1F("emhip_piplus", "Pi+", 40, -40.0, 40.0);
   TH1F *emhip_proton = new TH1F("emhip_proton", "Proton", 40, -40.0, 40.0);
   TH1F *emhip_positron = new TH1F("emhip_positron", "Positron", 40, -40.0, 40.0);
   
   TH1F *mippion_antimu = new TH1F("mippion_antimu", "Antimuon;ECal MipPion variable (dimensionless);Entries", 50, -30.0, 70.0);
   TH1F *mippion_piplus = new TH1F("mippion_piplus", "Pi+", 50, -30.0, 70.0);
   TH1F *mippion_proton = new TH1F("mippion_proton", "Proton", 50, -30.0, 70.0);
   TH1F *mippion_positron = new TH1F("mippion_positron", "Positron", 50, -30.0, 70.0);
   
   TH1F *tpc2dedx_antimu = new TH1F("tpc2dedx_antimu", "Antimuon;TPC2 dE/dx truncated mean (arb. units);Entries", 50, 0.0, 2000.0);
   TH1F *tpc2dedx_piplus = new TH1F("tpc2dedx_piplus", "Pi+", 50, 0.0, 2000.0);
   TH1F *tpc2dedx_proton = new TH1F("tpc2dedx_proton", "Proton", 50, 0.0, 2000.0);
   TH1F *tpc2dedx_positron = new TH1F("tpc2dedx_positron", "Positron", 50, 0.0, 2000.0);
   
   TH1F *tpc3dedx_antimu = new TH1F("tpc3dedx_antimu", "Antimuon;TPC3 dE/dx truncated mean (arb. units);Entries", 50, 0.0, 2000.0);
   TH1F *tpc3dedx_piplus = new TH1F("tpc3dedx_piplus", "Pi+", 50, 0.0, 2000.0);
   TH1F *tpc3dedx_proton = new TH1F("tpc3dedx_proton", "Proton", 50, 0.0, 2000.0);
   TH1F *tpc3dedx_positron = new TH1F("tpc3dedx_positron", "Positron", 50, 0.0, 2000.0);
   
   TH1F *tpclikemu_antimu = new TH1F("tpclikemu_antimu", "Antimuon;TPC2 muon likelihood;Entries", 50, 0.0, 1.0);
   TH1F *tpclikemu_piplus = new TH1F("tpclikemu_piplus", "Pi+", 50, 0.0, 1.0);
   TH1F *tpclikemu_proton = new TH1F("tpclikemu_proton", "Proton", 50, 0.0, 1.0);
   TH1F *tpclikemu_positron = new TH1F("tpclikemu_positron", "Positron", 50, 0.0, 1.0);
   
   TH1F *tpclikepi_antimu = new TH1F("tpclikepi_antimu", "Antimuon;TPC2 charged pion likelihood;Entries", 50, 0.0, 1.0);
   TH1F *tpclikepi_piplus = new TH1F("tpclikepi_piplus", "Pi+", 50, 0.0, 1.0);
   TH1F *tpclikepi_proton = new TH1F("tpclikepi_proton", "Proton", 50, 0.0, 1.0);
   TH1F *tpclikepi_positron = new TH1F("tpclikepi_positron", "Positron", 50, 0.0, 1.0);
   
   TH1F *tpclikep_antimu = new TH1F("tpclikep_antimu", "Antimuon;TPC2 proton likelihood;Entries", 50, 0.0, 1.0);
   TH1F *tpclikep_piplus = new TH1F("tpclikep_piplus", "Pi+", 50, 0.0, 1.0);
   TH1F *tpclikep_proton = new TH1F("tpclikep_proton", "Proton", 50, 0.0, 1.0);
   TH1F *tpclikep_positron = new TH1F("tpclikep_positron", "Positron", 50, 0.0, 1.0);
   
   TH1F *tpclikee_antimu = new TH1F("tpclikee_antimu", "Antimuon;TPC2 electron likelihood;Entries", 50, 0.0, 1.0);
   TH1F *tpclikee_piplus = new TH1F("tpclikee_piplus", "Pi+", 50, 0.0, 1.0);
   TH1F *tpclikee_proton = new TH1F("tpclikee_proton", "Proton", 50, 0.0, 1.0);
   TH1F *tpclikee_positron = new TH1F("tpclikee_positron", "Positron", 50, 0.0, 1.0);
   
   TH1F *tpc2pullmu_antimu = new TH1F("tpc2pullmu_antimu", "Antimuon;TPC2 muon pull;Entries", 50, -10.0, 40.0);
   TH1F *tpc2pullmu_piplus = new TH1F("tpc2pullmu_piplus", "Pi+", 50, -10.0, 40.0);
   TH1F *tpc2pullmu_proton = new TH1F("tpc2pullmu_proton", "Proton", 50, -10.0, 40.0);
   TH1F *tpc2pullmu_positron = new TH1F("tpc2pullmu_positron", "Positron", 50, -10.0, 40.0);
   
   TH1F *tpc2pullpi_antimu = new TH1F("tpc2pullpi_antimu", "Antimuon;TPC2 charged pion pull;Entries", 50, -10.0, 40.0);
   TH1F *tpc2pullpi_piplus = new TH1F("tpc2pullpi_piplus", "Pi+", 50, -10.0, 40.0);
   TH1F *tpc2pullpi_proton = new TH1F("tpc2pullpi_proton", "Proton", 50, -10.0, 40.0);
   TH1F *tpc2pullpi_positron = new TH1F("tpc2pullpi_positron", "Positron", 50, -10.0, 40.0);
   
   TH1F *tpc2pullp_antimu = new TH1F("tpc2pullp_antimu", "Antimuon;TPC2 proton pull;Entries", 50, -40.0, 20.0);
   TH1F *tpc2pullp_piplus = new TH1F("tpc2pullp_piplus", "Pi+", 50, -40.0, 20.0);
   TH1F *tpc2pullp_proton = new TH1F("tpc2pullp_proton", "Proton", 50, -40.0, 20.0);
   TH1F *tpc2pullp_positron = new TH1F("tpc2pullp_positron", "Positron", 50, -40.0, 20.0);
   
   TH1F *tpc2pulle_antimu = new TH1F("tpc2pulle_antimu", "Antimuon;TPC2 electron pull;Entries", 50, -20.0, 30.0);
   TH1F *tpc2pulle_piplus = new TH1F("tpc2pulle_piplus", "Pi+", 50, -20.0, 30.0);
   TH1F *tpc2pulle_proton = new TH1F("tpc2pulle_proton", "Proton", 50, -20.0, 30.0);
   TH1F *tpc2pulle_positron = new TH1F("tpc2pulle_positron", "Positron", 50, -20.0, 30.0);
   
   TH1F *tpc3pullmu_antimu = new TH1F("tpc3pullmu_antimu", "Antimuon;TPC3 muon pull;Entries", 50, -10.0, 30.0);
   TH1F *tpc3pullmu_piplus = new TH1F("tpc3pullmu_piplus", "Pi+", 50, -10.0, 30.0);
   TH1F *tpc3pullmu_proton = new TH1F("tpc3pullmu_proton", "Proton", 50, -10.0, 30.0);
   TH1F *tpc3pullmu_positron = new TH1F("tpc3pullmu_positron", "Positron", 50, -10.0, 30.0);
   
   TH1F *tpc3pullpi_antimu = new TH1F("tpc3pullpi_antimu", "Antimuon;TPC3 charged pion pull;Entries", 50, -10.0, 40.0);
   TH1F *tpc3pullpi_piplus = new TH1F("tpc3pullpi_piplus", "Pi+", 50, -10.0, 40.0);
   TH1F *tpc3pullpi_proton = new TH1F("tpc3pullpi_proton", "Proton", 50, -10.0, 40.0);
   TH1F *tpc3pullpi_positron = new TH1F("tpc3pullpi_positron", "Positron", 50, -10.0, 40.0);
   
   TH1F *tpc3pullp_antimu = new TH1F("tpc3pullp_antimu", "Antimuon;TPC3 proton pull;Entries", 50, -40.0, 20.0);
   TH1F *tpc3pullp_piplus = new TH1F("tpc3pullp_piplus", "Pi+", 50, -40.0, 20.0);
   TH1F *tpc3pullp_proton = new TH1F("tpc3pullp_proton", "Proton", 50, -40.0, 20.0);
   TH1F *tpc3pullp_positron = new TH1F("tpc3pullp_positron", "Positron", 50, -40.0, 20.0);
   
   TH1F *tpc3pulle_antimu = new TH1F("tpc3pulle_antimu", "Antimuon;TPC3 electron pull;Entries", 50, -10.0, 20.0);
   TH1F *tpc3pulle_piplus = new TH1F("tpc3pulle_piplus", "Pi+", 50, -10.0, 20.0);
   TH1F *tpc3pulle_proton = new TH1F("tpc3pulle_proton", "Proton", 50, -10.0, 20.0);
   TH1F *tpc3pulle_positron = new TH1F("tpc3pulle_positron", "Positron", 50, -10.0, 20.0);
   
   TH1F *ntpcs_antimu = new TH1F("ntpcs_antimu", "Antimuon;Number of TPC segments;Entries", 2, 0, 2);
   TH1F *ntpcs_piplus = new TH1F("ntpcs_piplus", "Pi+", 2, 0, 2);
   TH1F *ntpcs_proton = new TH1F("ntpcs_proton", "Proton", 2, 0, 2);
   TH1F *ntpcs_positron = new TH1F("ntpcs_positron", "Positron", 2, 0, 2);
   
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
   
   Int_t presel_nAntimu = 0;
   Int_t presel_nPiplus = 0;
   Int_t presel_nProton = 0;
   Int_t presel_nPositron = 0;
   
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
   
   
   
   TH1F *opt_mulike_sig_test1 = new TH1F("opt_mulike_sig_test1", "Mu-like (true antimu)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_mulike_bkg_test1 = new TH1F("opt_mulike_bkg_test1", "Mu-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_pilike_sig_test1 = new TH1F("opt_pilike_sig_test1", "Pi-like (true pi+)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_pilike_bkg_test1 = new TH1F("opt_pilike_bkg_test1", "Pi-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_plike_sig_test1 = new TH1F("opt_plike_sig_test1", "Proton-like (true protons)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_plike_bkg_test1 = new TH1F("opt_plike_bkg_test1", "Proton-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_elike_sig_test1 = new TH1F("opt_elike_sig_test1", "Electron-like (true positrons)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_elike_bkg_test1 = new TH1F("opt_elike_bkg_test1", "Electron-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   
   TH1F *opt_mulike_sig_test2 = new TH1F("opt_mulike_sig_test2", "Mu-like (true antimu)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_mulike_bkg_test2 = new TH1F("opt_mulike_bkg_test2", "Mu-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_pilike_sig_test2 = new TH1F("opt_pilike_sig_test2", "Pi-like (true pi+)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_pilike_bkg_test2 = new TH1F("opt_pilike_bkg_test2", "Pi-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_plike_sig_test2 = new TH1F("opt_plike_sig_test2", "Proton-like (true protons)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_plike_bkg_test2 = new TH1F("opt_plike_bkg_test2", "Proton-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_elike_sig_test2 = new TH1F("opt_elike_sig_test2", "Electron-like (true positrons)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_elike_bkg_test2 = new TH1F("opt_elike_bkg_test2", "Electron-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   
   TH1F *opt_mulike_sig_test3 = new TH1F("opt_mulike_sig_test3", "Mu-like (true antimu)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_mulike_bkg_test3 = new TH1F("opt_mulike_bkg_test3", "Mu-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_pilike_sig_test3 = new TH1F("opt_pilike_sig_test3", "Pi-like (true pi+)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_pilike_bkg_test3 = new TH1F("opt_pilike_bkg_test3", "Pi-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_plike_sig_test3 = new TH1F("opt_plike_sig_test3", "Proton-like (true protons)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_plike_bkg_test3 = new TH1F("opt_plike_bkg_test3", "Proton-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_elike_sig_test3 = new TH1F("opt_elike_sig_test3", "Electron-like (true positrons)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_elike_bkg_test3 = new TH1F("opt_elike_bkg_test3", "Electron-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   
   TH1F *opt_mulike_sig_test4 = new TH1F("opt_mulike_sig_test4", "Mu-like (true antimu)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_mulike_bkg_test4 = new TH1F("opt_mulike_bkg_test4", "Mu-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_pilike_sig_test4 = new TH1F("opt_pilike_sig_test4", "Pi-like (true pi+)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_pilike_bkg_test4 = new TH1F("opt_pilike_bkg_test4", "Pi-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_plike_sig_test4 = new TH1F("opt_plike_sig_test4", "Proton-like (true protons)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_plike_bkg_test4 = new TH1F("opt_plike_bkg_test4", "Proton-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_elike_sig_test4 = new TH1F("opt_elike_sig_test4", "Electron-like (true positrons)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_elike_bkg_test4 = new TH1F("opt_elike_bkg_test4", "Electron-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   
   TH1F *opt_mulike_sig_test5 = new TH1F("opt_mulike_sig_test5", "Mu-like (true antimu)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_mulike_bkg_test5 = new TH1F("opt_mulike_bkg_test5", "Mu-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_pilike_sig_test5 = new TH1F("opt_pilike_sig_test5", "Pi-like (true pi+)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_pilike_bkg_test5 = new TH1F("opt_pilike_bkg_test5", "Pi-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_plike_sig_test5 = new TH1F("opt_plike_sig_test5", "Proton-like (true protons)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_plike_bkg_test5 = new TH1F("opt_plike_bkg_test5", "Proton-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_elike_sig_test5 = new TH1F("opt_elike_sig_test5", "Electron-like (true positrons)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_elike_bkg_test5 = new TH1F("opt_elike_bkg_test5", "Electron-like (backgrounds)", optimisation_nbins, 0.0, 1.0);

   /*Int_t correlation_nbins = 40;
   
   TH2F *corr_weighting_mulike = new TH2F("corr_weighting_mulike", 
                                          "Correlation: mom weighted vs unweighted, mu-like;Mom-weighted BDT mu-like output;Unweighted BDT mu-like output", 
                                          correlation_nbins, 0.0, 1.0, correlation_nbins, 0.0, 1.0);
   TH2F *corr_weighting_pilike = new TH2F("corr_weighting_pilike", 
                                          "Correlation: mom weighted vs unweighted, pi-like;Mom-weighted BDT pi-like output;Unweighted BDT pi-like output",
                                          correlation_nbins, 0.0, 1.0, correlation_nbins, 0.0, 1.0);
   TH2F *corr_weighting_plike = new TH2F("corr_weighting_plike", 
                                         "Correlation: mom weighted vs unweighted, proton-like;Mom-weighted BDT p-like output;Unweighted BDT p-like output", 
                                         correlation_nbins, 0.0, 1.0, correlation_nbins, 0.0, 1.0);
   TH2F *corr_weighting_elike = new TH2F("corr_weighting_elike", 
                                         "Correlation: mom weighted vs unweighted, e-like;Mom-weighted BDT e-like output;Unweighted BDT e-like output", 
                                         correlation_nbins, 0.0, 1.0, correlation_nbins, 0.0, 1.0);
   
   TH2F *corr_mulikediff_recomom = new TH2F("corr_mulikediff_recomom", 
                                            "Correlation: mu-like disagreement vs reco mom;Reco momentum;BDT mu-like disagreement (weighted - unweighted)", 
                                            correlation_nbins, 200.0, 1500.0, correlation_nbins, -1.0, 1.0);
   TH2F *corr_pilikediff_recomom = new TH2F("corr_pilikediff_recomom", 
                                            "Correlation: pi-like disagreement vs reco mom;Reco momentum;BDT pi-like disagreement (weighted - unweighted)", 
                                            correlation_nbins, 200.0, 1500.0, correlation_nbins, -1.0, 1.0);
   TH2F *corr_plikediff_recomom = new TH2F("corr_plikediff_recomom", 
                                           "Correlation: proton-like disagreement vs reco mom;Reco momentum;BDT p-like disagreement (weighted - unweighted)", 
                                            correlation_nbins, 200.0, 1500.0, correlation_nbins, -1.0, 1.0);
   TH2F *corr_elikediff_recomom = new TH2F("corr_elikediff_recomom", 
                                           "Correlation: e-like disagreement vs reco mom;Reco momentum;BDT e-like disagreement (weighted - unweighted)", 
                                            correlation_nbins, 200.0, 1500.0, correlation_nbins, -1.0, 1.0);*/
   
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      fChain->GetEntry(jentry);

      // Cut on accum_level etc
      if (accum_level[0][1] <= 4) continue; // Set accum_level
      
      
      // ============= Fill histograms for input variable plotting =============
      
      if ((accum_level[0][1] > 5) && (selmu_necals < 2)){
         
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
            tpc2pullmu_antimu->Fill(selmu_tpc_pullmu[0]);
            tpc2pullpi_antimu->Fill(selmu_tpc_pullpi[0]);
            tpc2pullp_antimu->Fill(selmu_tpc_pullp[0]);
            tpc2pulle_antimu->Fill(selmu_tpc_pullele[0]);
            tpc3pullmu_antimu->Fill(selmu_tpc_pullmu[1]);
            tpc3pullpi_antimu->Fill(selmu_tpc_pullpi[1]);
            tpc3pullp_antimu->Fill(selmu_tpc_pullp[1]);
            tpc3pulle_antimu->Fill(selmu_tpc_pullele[1]);
            ntpcs_antimu->Fill(selmu_ntpcs);
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
            tpc2pullmu_piplus->Fill(selmu_tpc_pullmu[0]);
            tpc2pullpi_piplus->Fill(selmu_tpc_pullpi[0]);
            tpc2pullp_piplus->Fill(selmu_tpc_pullp[0]);
            tpc2pulle_piplus->Fill(selmu_tpc_pullele[0]);
            tpc3pullmu_piplus->Fill(selmu_tpc_pullmu[1]);
            tpc3pullpi_piplus->Fill(selmu_tpc_pullpi[1]);
            tpc3pullp_piplus->Fill(selmu_tpc_pullp[1]);
            tpc3pulle_piplus->Fill(selmu_tpc_pullele[1]);
            ntpcs_piplus->Fill(selmu_ntpcs);
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
            tpc2pullmu_proton->Fill(selmu_tpc_pullmu[0]);
            tpc2pullpi_proton->Fill(selmu_tpc_pullpi[0]);
            tpc2pullp_proton->Fill(selmu_tpc_pullp[0]);
            tpc2pulle_proton->Fill(selmu_tpc_pullele[0]);
            tpc3pullmu_proton->Fill(selmu_tpc_pullmu[1]);
            tpc3pullpi_proton->Fill(selmu_tpc_pullpi[1]);
            tpc3pullp_proton->Fill(selmu_tpc_pullp[1]);
            tpc3pulle_proton->Fill(selmu_tpc_pullele[1]);
            ntpcs_proton->Fill(selmu_ntpcs);
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
            tpc2pullmu_positron->Fill(selmu_tpc_pullmu[0]);
            tpc2pullpi_positron->Fill(selmu_tpc_pullpi[0]);
            tpc2pullp_positron->Fill(selmu_tpc_pullp[0]);
            tpc2pulle_positron->Fill(selmu_tpc_pullele[0]);
            tpc3pullmu_positron->Fill(selmu_tpc_pullmu[1]);
            tpc3pullpi_positron->Fill(selmu_tpc_pullpi[1]);
            tpc3pullp_positron->Fill(selmu_tpc_pullp[1]);
            tpc3pulle_positron->Fill(selmu_tpc_pullele[1]);
            ntpcs_positron->Fill(selmu_ntpcs);
            fgd1EbyL_positron->Fill(selmu_fgd1_EbyL);
            fgd2EbyL_positron->Fill(selmu_fgd2_EbyL);
            nsmrds_positron->Fill(selmu_nsmrds);
         }
      }
      
      
      // ============= Fill histograms to find optimal cuts =============
      
      if (accum_level[0][1] > 5){
         
         if (particle == -13)
         {
            presel_nAntimu++;
            
            opt_mulike_sig->Fill(selmu_bdt_pid_mu);
            opt_pilike_bkg->Fill(selmu_bdt_pid_pi);
            opt_plike_bkg->Fill(selmu_bdt_pid_p);
            opt_elike_bkg->Fill(selmu_bdt_pid_e);
            
            opt_mulike_sig_test1->Fill(selmu_bdt_pid_mu_test1);
            opt_pilike_bkg_test1->Fill(selmu_bdt_pid_pi_test1);
            opt_plike_bkg_test1->Fill(selmu_bdt_pid_p_test1);
            opt_elike_bkg_test1->Fill(selmu_bdt_pid_e_test1);
            
            opt_mulike_sig_test2->Fill(selmu_bdt_pid_mu_test2);
            opt_pilike_bkg_test2->Fill(selmu_bdt_pid_pi_test2);
            opt_plike_bkg_test2->Fill(selmu_bdt_pid_p_test2);
            opt_elike_bkg_test2->Fill(selmu_bdt_pid_e_test2);
            
            opt_mulike_sig_test3->Fill(selmu_bdt_pid_mu_test3);
            opt_pilike_bkg_test3->Fill(selmu_bdt_pid_pi_test3);
            opt_plike_bkg_test3->Fill(selmu_bdt_pid_p_test3);
            opt_elike_bkg_test3->Fill(selmu_bdt_pid_e_test3);
            
            opt_mulike_sig_test4->Fill(selmu_bdt_pid_mu_test4);
            opt_pilike_bkg_test4->Fill(selmu_bdt_pid_pi_test4);
            opt_plike_bkg_test4->Fill(selmu_bdt_pid_p_test4);
            opt_elike_bkg_test4->Fill(selmu_bdt_pid_e_test4);
            
            opt_mulike_sig_test5->Fill(selmu_bdt_pid_mu_test5);
            opt_pilike_bkg_test5->Fill(selmu_bdt_pid_pi_test5);
            opt_plike_bkg_test5->Fill(selmu_bdt_pid_p_test5);
            opt_elike_bkg_test5->Fill(selmu_bdt_pid_e_test5);
            
         }
         else if (particle == 211)
         {
            presel_nPiplus++;
            
            opt_mulike_bkg->Fill(selmu_bdt_pid_mu);
            opt_pilike_sig->Fill(selmu_bdt_pid_pi);
            opt_plike_bkg->Fill(selmu_bdt_pid_p);
            opt_elike_bkg->Fill(selmu_bdt_pid_e);
            
            opt_mulike_bkg_test1->Fill(selmu_bdt_pid_mu_test1);
            opt_pilike_sig_test1->Fill(selmu_bdt_pid_pi_test1);
            opt_plike_bkg_test1->Fill(selmu_bdt_pid_p_test1);
            opt_elike_bkg_test1->Fill(selmu_bdt_pid_e_test1);
            
            opt_mulike_bkg_test2->Fill(selmu_bdt_pid_mu_test2);
            opt_pilike_sig_test2->Fill(selmu_bdt_pid_pi_test2);
            opt_plike_bkg_test2->Fill(selmu_bdt_pid_p_test2);
            opt_elike_bkg_test2->Fill(selmu_bdt_pid_e_test2);
            
            opt_mulike_bkg_test3->Fill(selmu_bdt_pid_mu_test3);
            opt_pilike_sig_test3->Fill(selmu_bdt_pid_pi_test3);
            opt_plike_bkg_test3->Fill(selmu_bdt_pid_p_test3);
            opt_elike_bkg_test3->Fill(selmu_bdt_pid_e_test3);
            
            opt_mulike_bkg_test4->Fill(selmu_bdt_pid_mu_test4);
            opt_pilike_sig_test4->Fill(selmu_bdt_pid_pi_test4);
            opt_plike_bkg_test4->Fill(selmu_bdt_pid_p_test4);
            opt_elike_bkg_test4->Fill(selmu_bdt_pid_e_test4);
            
            opt_mulike_bkg_test5->Fill(selmu_bdt_pid_mu_test5);
            opt_pilike_sig_test5->Fill(selmu_bdt_pid_pi_test5);
            opt_plike_bkg_test5->Fill(selmu_bdt_pid_p_test5);
            opt_elike_bkg_test5->Fill(selmu_bdt_pid_e_test5);
         }
         else if (particle == 2212)
         {
            presel_nProton++;
            
            opt_mulike_bkg->Fill(selmu_bdt_pid_mu);
            opt_pilike_bkg->Fill(selmu_bdt_pid_pi);
            opt_plike_sig->Fill(selmu_bdt_pid_p);
            opt_elike_bkg->Fill(selmu_bdt_pid_e);
            
            opt_mulike_bkg_test1->Fill(selmu_bdt_pid_mu_test1);
            opt_pilike_bkg_test1->Fill(selmu_bdt_pid_pi_test1);
            opt_plike_sig_test1->Fill(selmu_bdt_pid_p_test1);
            opt_elike_bkg_test1->Fill(selmu_bdt_pid_e_test1);
            
            opt_mulike_bkg_test2->Fill(selmu_bdt_pid_mu_test2);
            opt_pilike_bkg_test2->Fill(selmu_bdt_pid_pi_test2);
            opt_plike_sig_test2->Fill(selmu_bdt_pid_p_test2);
            opt_elike_bkg_test2->Fill(selmu_bdt_pid_e_test2);
            
            opt_mulike_bkg_test3->Fill(selmu_bdt_pid_mu_test3);
            opt_pilike_bkg_test3->Fill(selmu_bdt_pid_pi_test3);
            opt_plike_sig_test3->Fill(selmu_bdt_pid_p_test3);
            opt_elike_bkg_test3->Fill(selmu_bdt_pid_e_test3);
            
            opt_mulike_bkg_test4->Fill(selmu_bdt_pid_mu_test4);
            opt_pilike_bkg_test4->Fill(selmu_bdt_pid_pi_test4);
            opt_plike_sig_test4->Fill(selmu_bdt_pid_p_test4);
            opt_elike_bkg_test4->Fill(selmu_bdt_pid_e_test4);
            
            opt_mulike_bkg_test5->Fill(selmu_bdt_pid_mu_test5);
            opt_pilike_bkg_test5->Fill(selmu_bdt_pid_pi_test5);
            opt_plike_sig_test5->Fill(selmu_bdt_pid_p_test5);
            opt_elike_bkg_test5->Fill(selmu_bdt_pid_e_test5);


         }
         else if (particle == -11)
         {
            presel_nPositron++;
            
            opt_mulike_bkg->Fill(selmu_bdt_pid_mu);
            opt_pilike_bkg->Fill(selmu_bdt_pid_pi);
            opt_plike_bkg->Fill(selmu_bdt_pid_p);
            opt_elike_sig->Fill(selmu_bdt_pid_e);
            
            opt_mulike_bkg_test1->Fill(selmu_bdt_pid_mu_test1);
            opt_pilike_bkg_test1->Fill(selmu_bdt_pid_pi_test1);
            opt_plike_bkg_test1->Fill(selmu_bdt_pid_p_test1);
            opt_elike_sig_test1->Fill(selmu_bdt_pid_e_test1);
            
            opt_mulike_bkg_test2->Fill(selmu_bdt_pid_mu_test2);
            opt_pilike_bkg_test2->Fill(selmu_bdt_pid_pi_test2);
            opt_plike_bkg_test2->Fill(selmu_bdt_pid_p_test2);
            opt_elike_sig_test2->Fill(selmu_bdt_pid_e_test2);
            
            opt_mulike_bkg_test3->Fill(selmu_bdt_pid_mu_test3);
            opt_pilike_bkg_test3->Fill(selmu_bdt_pid_pi_test3);
            opt_plike_bkg_test3->Fill(selmu_bdt_pid_p_test3);
            opt_elike_sig_test3->Fill(selmu_bdt_pid_e_test3);
            
            opt_mulike_bkg_test4->Fill(selmu_bdt_pid_mu_test4);
            opt_pilike_bkg_test4->Fill(selmu_bdt_pid_pi_test4);
            opt_plike_bkg_test4->Fill(selmu_bdt_pid_p_test4);
            opt_elike_sig_test4->Fill(selmu_bdt_pid_e_test4);
            
            opt_mulike_bkg_test5->Fill(selmu_bdt_pid_mu_test5);
            opt_pilike_bkg_test5->Fill(selmu_bdt_pid_pi_test5);
            opt_plike_bkg_test5->Fill(selmu_bdt_pid_p_test5);
            opt_elike_sig_test5->Fill(selmu_bdt_pid_e_test5);
            
            
         }
         
         // Fill counters for new performance testing
         
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
                
         
         //corr_weighting_mulike->Fill(selmu_bdt_pid_mu, selmu_bdt_pid_unweighted_mu);
         //corr_weighting_pilike->Fill(selmu_bdt_pid_pi, selmu_bdt_pid_unweighted_pi);
         //corr_weighting_plike->Fill(selmu_bdt_pid_p, selmu_bdt_pid_unweighted_p);
         //corr_weighting_elike->Fill(selmu_bdt_pid_e, selmu_bdt_pid_unweighted_e);
         
         //corr_mulikediff_recomom->Fill(selmu_mom[0], selmu_bdt_pid_mu-selmu_bdt_pid_unweighted_mu);
         //corr_pilikediff_recomom->Fill(selmu_mom[0], selmu_bdt_pid_pi-selmu_bdt_pid_unweighted_pi);
         //corr_plikediff_recomom->Fill(selmu_mom[0], selmu_bdt_pid_p-selmu_bdt_pid_unweighted_p);
         //corr_elikediff_recomom->Fill(selmu_mom[0], selmu_bdt_pid_e-selmu_bdt_pid_unweighted_e);
      }
      
      
      
      
      // ============= Fill variables to test existing cuts =============
      
      /*if (accum_level[0][0] > 6){
         
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
      }*/
      
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
   
   //TCanvas* canvas_recomom = new TCanvas("canvas_recomom","Reconstructed momentum (MeV/c)",200,10,1000,600);
   
   TCanvas* canvas_ptheta = new TCanvas("canvas_ptheta","",200,10,1000,400);
   canvas_ptheta->Divide(2,1,0.005,0.005);
   canvas_ptheta->cd(1);
   
   recomom_antimu->GetYaxis()->SetRangeUser(0.0, 6000.0);
  
   SetHistParticleStyle(recomom_antimu, "antimu");
   SetHistParticleStyle(recomom_piplus, "piplus");
   SetHistParticleStyle(recomom_proton, "proton");
   SetHistParticleStyle(recomom_positron, "positron");
   
   recomom_antimu->Draw();
   recomom_piplus->Draw("same");
   recomom_proton->Draw("same");
   recomom_positron->Draw("same");
   //canvas_recomom->BuildLegend();
   //canvas_recomom->Write();
   canvas_ptheta->cd(1)->BuildLegend();
   
   // Reco theta
   
   //TCanvas* canvas_theta = new TCanvas("canvas_theta","Reconstructed angle w.r.t. detector Z-axis (rad)",200,10,1000,600);
   canvas_ptheta->cd(2);
   
   theta_antimu->GetYaxis()->SetRangeUser(0.0, 5000.0);
  
   SetHistParticleStyle(theta_antimu, "antimu");
   SetHistParticleStyle(theta_piplus, "piplus");
   SetHistParticleStyle(theta_proton, "proton");
   SetHistParticleStyle(theta_positron, "positron");
   
   theta_antimu->Draw();
   theta_piplus->Draw("same");
   theta_proton->Draw("same");
   theta_positron->Draw("same");
   //canvas_theta->BuildLegend();
   //canvas_theta->Write();
   canvas_ptheta->Write();
   
   // ECal EM energy
   
   //TCanvas* canvas_EMEnergy = new TCanvas("canvas_EMEnergy","",200,10,1000,600);
   
   TCanvas* canvas_EandEbyL = new TCanvas("canvas_EandEbyL","",200,10,1000,400);
   canvas_EandEbyL->Divide(2,1,0.005,0.005);
   canvas_EandEbyL->cd(1);
   
   //EMEnergy_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(EMEnergy_antimu, "antimu");
   SetHistParticleStyle(EMEnergy_piplus, "piplus");
   SetHistParticleStyle(EMEnergy_proton, "proton");
   SetHistParticleStyle(EMEnergy_positron, "positron");
   
   EMEnergy_antimu->Draw();
   EMEnergy_piplus->Draw("same");
   EMEnergy_proton->Draw("same");
   EMEnergy_positron->Draw("same");
   //canvas_EMEnergy->BuildLegend();
   //canvas_EMEnergy->Write();
   canvas_EandEbyL->cd(1)->BuildLegend();
   
   // ECal E/L
   
   //TCanvas* canvas_EbyL = new TCanvas("canvas_EbyL","",200,10,1000,600);
   canvas_EandEbyL->cd(2);
   
   //EbyL_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(EbyL_antimu, "antimu");
   SetHistParticleStyle(EbyL_piplus, "piplus");
   SetHistParticleStyle(EbyL_proton, "proton");
   SetHistParticleStyle(EbyL_positron, "positron");
   
   EbyL_antimu->Draw();
   EbyL_piplus->Draw("same");
   EbyL_proton->Draw("same");
   EbyL_positron->Draw("same");
   //canvas_EbyL->BuildLegend();
   //canvas_EbyL->Write();
   canvas_EandEbyL->Write();
   
   // ECal circularity
   
   //TCanvas* canvas_circularity = new TCanvas("canvas_circularity","",200,10,1000,600);
   
   TCanvas* canvas_ecallowlevel = new TCanvas("canvas_ecallowlevel","",200,10,1000,800);
   canvas_ecallowlevel->Divide(2,2,0.005,0.005);
   canvas_ecallowlevel->cd(1);
   
   //circularity_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(circularity_antimu, "antimu");
   SetHistParticleStyle(circularity_piplus, "piplus");
   SetHistParticleStyle(circularity_proton, "proton");
   SetHistParticleStyle(circularity_positron, "positron");
   
   circularity_antimu->Draw();
   circularity_piplus->Draw("same");
   circularity_proton->Draw("same");
   circularity_positron->Draw("same");
   //canvas_circularity->BuildLegend();
   //canvas_circularity->Write();
   canvas_ecallowlevel->cd(1)->BuildLegend();
   
   // ECal FBR
   
   //TCanvas* canvas_fbr = new TCanvas("canvas_fbr","",200,10,1000,600);
   canvas_ecallowlevel->cd(2);
   
   fbr_antimu->GetYaxis()->SetRangeUser(0.0, 20000.0);
  
   SetHistParticleStyle(fbr_antimu, "antimu");
   SetHistParticleStyle(fbr_piplus, "piplus");
   SetHistParticleStyle(fbr_proton, "proton");
   SetHistParticleStyle(fbr_positron, "positron");
   
   fbr_antimu->Draw();
   fbr_piplus->Draw("same");
   fbr_proton->Draw("same");
   fbr_positron->Draw("same");
   //canvas_fbr->BuildLegend();
   //canvas_fbr->Write();
   
   // ECal TMR
   
   //TCanvas* canvas_tmr = new TCanvas("canvas_tmr","",200,10,1000,600);
   
   canvas_ecallowlevel->cd(3);
   
   tmr_antimu->GetYaxis()->SetRangeUser(0.0, 6500.0);
  
   SetHistParticleStyle(tmr_antimu, "antimu");
   SetHistParticleStyle(tmr_piplus, "piplus");
   SetHistParticleStyle(tmr_proton, "proton");
   SetHistParticleStyle(tmr_positron, "positron");
   
   tmr_antimu->Draw();
   tmr_piplus->Draw("same");
   tmr_proton->Draw("same");
   tmr_positron->Draw("same");
   //canvas_tmr->BuildLegend();
   //canvas_tmr->Write();
   
   // ECal QRMS
   
   //TCanvas* canvas_qrms = new TCanvas("canvas_qrms","",200,10,1000,600);
   
   canvas_ecallowlevel->cd(4);
   
   //qrms_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(qrms_antimu, "antimu");
   SetHistParticleStyle(qrms_piplus, "piplus");
   SetHistParticleStyle(qrms_proton, "proton");
   SetHistParticleStyle(qrms_positron, "positron");
   
   qrms_antimu->Draw();
   qrms_piplus->Draw("same");
   qrms_proton->Draw("same");
   qrms_positron->Draw("same");
   //canvas_qrms->BuildLegend();
   //canvas_qrms->Write();
   canvas_ecallowlevel->Write();
   
   // ECal MipEm
   
   //TCanvas* canvas_mipem = new TCanvas("canvas_mipem","",200,10,1000,600);
   
   TCanvas* canvas_ecalhighlevel = new TCanvas("canvas_ecalhighlevel","",200,10,1000,800);
   canvas_ecalhighlevel->Divide(2,2,0.005,0.005);
   canvas_ecalhighlevel->cd(1);
   
   //mipem_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(mipem_antimu, "antimu");
   SetHistParticleStyle(mipem_piplus, "piplus");
   SetHistParticleStyle(mipem_proton, "proton");
   SetHistParticleStyle(mipem_positron, "positron");
   
   mipem_antimu->Draw();
   mipem_piplus->Draw("same");
   mipem_proton->Draw("same");
   mipem_positron->Draw("same");
   //canvas_mipem->BuildLegend();
   //canvas_mipem->Write();
   canvas_ecalhighlevel->cd(1)->BuildLegend();
   
   // ECal EmHip
   
   //TCanvas* canvas_emhip = new TCanvas("canvas_emhip","",200,10,1000,600);
   
   canvas_ecalhighlevel->cd(2);
   
   //emhip_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(emhip_antimu, "antimu");
   SetHistParticleStyle(emhip_piplus, "piplus");
   SetHistParticleStyle(emhip_proton, "proton");
   SetHistParticleStyle(emhip_positron, "positron");
   
   emhip_antimu->Draw();
   emhip_piplus->Draw("same");
   emhip_proton->Draw("same");
   emhip_positron->Draw("same");
   //canvas_emhip->BuildLegend();
   //canvas_emhip->Write();
   
   // ECal MipPion
   
   //TCanvas* canvas_mippion = new TCanvas("canvas_mippion","",200,10,1000,600);
   
   canvas_ecalhighlevel->cd(3);
   
   //mippion_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(mippion_antimu, "antimu");
   SetHistParticleStyle(mippion_piplus, "piplus");
   SetHistParticleStyle(mippion_proton, "proton");
   SetHistParticleStyle(mippion_positron, "positron");
   
   mippion_antimu->Draw();
   mippion_piplus->Draw("same");
   mippion_proton->Draw("same");
   mippion_positron->Draw("same");
   //canvas_mippion->BuildLegend();
   //canvas_mippion->Write();
   
   canvas_ecalhighlevel->Write();
   
   // TPC2 dE/dx
   
   //TCanvas* canvas_tpc2dedx = new TCanvas("canvas_tpc2dedx","",200,10,1000,600);
   
   TCanvas* canvas_tpcdedx = new TCanvas("canvas_tpcdedx","",200,10,1000,400);
   canvas_tpcdedx->Divide(2,1,0.005,0.005);
   canvas_tpcdedx->cd(1);
   
   //tpc2dedx_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(tpc2dedx_antimu, "antimu");
   SetHistParticleStyle(tpc2dedx_piplus, "piplus");
   SetHistParticleStyle(tpc2dedx_proton, "proton");
   SetHistParticleStyle(tpc2dedx_positron, "positron");
   
   tpc2dedx_antimu->Draw();
   tpc2dedx_piplus->Draw("same");
   tpc2dedx_proton->Draw("same");
   tpc2dedx_positron->Draw("same");
   //canvas_tpc2dedx->BuildLegend();
   //canvas_tpc2dedx->Write();
   canvas_tpcdedx->cd(1)->BuildLegend();
   
   // TPC3 dE/dx
   
   //TCanvas* canvas_tpc3dedx = new TCanvas("canvas_tpc3dedx","",200,10,1000,600);
   canvas_tpcdedx->cd(2);
   
   //tpc3dedx_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(tpc3dedx_antimu, "antimu");
   SetHistParticleStyle(tpc3dedx_piplus, "piplus");
   SetHistParticleStyle(tpc3dedx_proton, "proton");
   SetHistParticleStyle(tpc3dedx_positron, "positron");
   
   tpc3dedx_antimu->Draw();
   tpc3dedx_piplus->Draw("same");
   tpc3dedx_proton->Draw("same");
   tpc3dedx_positron->Draw("same");
   //canvas_tpc3dedx->BuildLegend();
   //canvas_tpc3dedx->Write();
   canvas_tpcdedx->Write();
   
   // TPC mu-like
   
   TCanvas* canvas_tpclikelihoods = new TCanvas("canvas_tpclikelihoods","",200,10,1000,800);
   canvas_tpclikelihoods->Divide(2,2,0.005,0.005);
   canvas_tpclikelihoods->cd(1);
   
   //TCanvas* canvas_tpclikemu = new TCanvas("canvas_tpclikemu","",200,10,1000,600);
   
   tpclikemu_antimu->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpclikemu_antimu->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpclikemu_antimu, "antimu");
   SetHistParticleStyle(tpclikemu_piplus, "piplus");
   SetHistParticleStyle(tpclikemu_proton, "proton");
   SetHistParticleStyle(tpclikemu_positron, "positron");
   
   tpclikemu_antimu->Draw();
   tpclikemu_piplus->Draw("same");
   tpclikemu_proton->Draw("same");
   tpclikemu_positron->Draw("same");
   canvas_tpclikelihoods->cd(1)->SetLogy();
   //canvas_tpclikemu->BuildLegend();
   //canvas_tpclikemu->Write();
   
   // TPC pi-like
   
   //TCanvas* canvas_tpclikepi = new TCanvas("canvas_tpclikepi","",200,10,1000,600);
   canvas_tpclikelihoods->cd(2);
   
   tpclikepi_antimu->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpclikepi_antimu->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpclikepi_antimu, "antimu");
   SetHistParticleStyle(tpclikepi_piplus, "piplus");
   SetHistParticleStyle(tpclikepi_proton, "proton");
   SetHistParticleStyle(tpclikepi_positron, "positron");
   
   tpclikepi_antimu->Draw();
   tpclikepi_piplus->Draw("same");
   tpclikepi_proton->Draw("same");
   tpclikepi_positron->Draw("same");
   canvas_tpclikelihoods->cd(2)->SetLogy();
   //canvas_tpclikepi->BuildLegend();
   //canvas_tpclikepi->Write();
   
   // TPC p-like
   
   //TCanvas* canvas_tpclikep = new TCanvas("canvas_tpclikep","",200,10,1000,600);
   canvas_tpclikelihoods->cd(3);
   
   tpclikep_antimu->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpclikep_antimu->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpclikep_antimu, "antimu");
   SetHistParticleStyle(tpclikep_piplus, "piplus");
   SetHistParticleStyle(tpclikep_proton, "proton");
   SetHistParticleStyle(tpclikep_positron, "positron");
   
   tpclikep_antimu->Draw();
   tpclikep_piplus->Draw("same");
   tpclikep_proton->Draw("same");
   tpclikep_positron->Draw("same");
   canvas_tpclikelihoods->cd(3)->SetLogy();
   //canvas_tpclikep->BuildLegend();
   //canvas_tpclikep->Write();
   
   // TPC e-like
   
   //TCanvas* canvas_tpclikee = new TCanvas("canvas_tpclikee","",200,10,1000,600);
   canvas_tpclikelihoods->cd(4);
   
   tpclikee_antimu->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpclikee_antimu->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpclikee_antimu, "antimu");
   SetHistParticleStyle(tpclikee_piplus, "piplus");
   SetHistParticleStyle(tpclikee_proton, "proton");
   SetHistParticleStyle(tpclikee_positron, "positron");
   
   tpclikee_antimu->Draw();
   tpclikee_piplus->Draw("same");
   tpclikee_proton->Draw("same");
   tpclikee_positron->Draw("same");
   canvas_tpclikelihoods->cd(4)->SetLogy();
   //canvas_tpclikee->BuildLegend();
   //canvas_tpclikee->Write();
   
   canvas_tpclikelihoods->cd(1)->BuildLegend();
   canvas_tpclikelihoods->Write();
   
   // TPC2 mu pull
   
   TCanvas* canvas_tpc2pulls = new TCanvas("canvas_tpc2pulls","",200,10,1000,800);
   canvas_tpc2pulls->Divide(2,2,0.005,0.005);
   canvas_tpc2pulls->cd(1);
   
   //tpc2pullmu_antimu->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpc2pullmu_antimu->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpc2pullmu_antimu, "antimu");
   SetHistParticleStyle(tpc2pullmu_piplus, "piplus");
   SetHistParticleStyle(tpc2pullmu_proton, "proton");
   SetHistParticleStyle(tpc2pullmu_positron, "positron");
   
   tpc2pullmu_antimu->Draw();
   tpc2pullmu_piplus->Draw("same");
   tpc2pullmu_proton->Draw("same");
   tpc2pullmu_positron->Draw("same");
   //canvas_tpc2pulls->cd(1)->SetLogy();

   
   // TPC2 pi pull
   
   canvas_tpc2pulls->cd(2);
   
   //tpc2pullpi_antimu->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpc2pullpi_antimu->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpc2pullpi_antimu, "antimu");
   SetHistParticleStyle(tpc2pullpi_piplus, "piplus");
   SetHistParticleStyle(tpc2pullpi_proton, "proton");
   SetHistParticleStyle(tpc2pullpi_positron, "positron");
   
   tpc2pullpi_antimu->Draw();
   tpc2pullpi_piplus->Draw("same");
   tpc2pullpi_proton->Draw("same");
   tpc2pullpi_positron->Draw("same");
   //canvas_tpc2pulls->cd(2)->SetLogy();
   
   
   // TPC2 p pull
  
   canvas_tpc2pulls->cd(3);
   
   //tpc2pullp_antimu->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpc2pullp_antimu->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpc2pullp_antimu, "antimu");
   SetHistParticleStyle(tpc2pullp_piplus, "piplus");
   SetHistParticleStyle(tpc2pullp_proton, "proton");
   SetHistParticleStyle(tpc2pullp_positron, "positron");
   
   tpc2pullp_antimu->Draw();
   tpc2pullp_piplus->Draw("same");
   tpc2pullp_proton->Draw("same");
   tpc2pullp_positron->Draw("same");
   //canvas_tpc2pulls->cd(3)->SetLogy();
   
   // TPC2 e pull
   
   canvas_tpc2pulls->cd(4);
   
   //tpc2pulle_antimu->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpc2pulle_antimu->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpc2pulle_antimu, "antimu");
   SetHistParticleStyle(tpc2pulle_piplus, "piplus");
   SetHistParticleStyle(tpc2pulle_proton, "proton");
   SetHistParticleStyle(tpc2pulle_positron, "positron");
   
   tpc2pulle_antimu->Draw();
   tpc2pulle_piplus->Draw("same");
   tpc2pulle_proton->Draw("same");
   tpc2pulle_positron->Draw("same");
   //canvas_tpc2pulls->cd(4)->SetLogy();
   
   canvas_tpc2pulls->cd(1)->BuildLegend();
   canvas_tpc2pulls->Write();
   
   // TPC3 mu pull
   
   TCanvas* canvas_tpc3pulls = new TCanvas("canvas_tpc3pulls","",200,10,1000,800);
   canvas_tpc3pulls->Divide(2,2,0.005,0.005);
   canvas_tpc3pulls->cd(1);
   
   //tpc3pullmu_antimu->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpc3pullmu_antimu->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpc3pullmu_antimu, "antimu");
   SetHistParticleStyle(tpc3pullmu_piplus, "piplus");
   SetHistParticleStyle(tpc3pullmu_proton, "proton");
   SetHistParticleStyle(tpc3pullmu_positron, "positron");
   
   tpc3pullmu_antimu->Draw();
   tpc3pullmu_piplus->Draw("same");
   tpc3pullmu_proton->Draw("same");
   tpc3pullmu_positron->Draw("same");
   //canvas_tpc3pulls->cd(1)->SetLogy();

   
   // TPC3 pi pull
   
   canvas_tpc3pulls->cd(2);
   
   //tpc3pullpi_antimu->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpc3pullpi_antimu->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpc3pullpi_antimu, "antimu");
   SetHistParticleStyle(tpc3pullpi_piplus, "piplus");
   SetHistParticleStyle(tpc3pullpi_proton, "proton");
   SetHistParticleStyle(tpc3pullpi_positron, "positron");
   
   tpc3pullpi_antimu->Draw();
   tpc3pullpi_piplus->Draw("same");
   tpc3pullpi_proton->Draw("same");
   tpc3pullpi_positron->Draw("same");
   //canvas_tpc3pulls->cd(2)->SetLogy();
   
   
   // TPC3 p pull
  
   canvas_tpc3pulls->cd(3);
   
   //tpc3pullp_antimu->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpc3pullp_antimu->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpc3pullp_antimu, "antimu");
   SetHistParticleStyle(tpc3pullp_piplus, "piplus");
   SetHistParticleStyle(tpc3pullp_proton, "proton");
   SetHistParticleStyle(tpc3pullp_positron, "positron");
   
   tpc3pullp_antimu->Draw();
   tpc3pullp_piplus->Draw("same");
   tpc3pullp_proton->Draw("same");
   tpc3pullp_positron->Draw("same");
   //canvas_tpc3pulls->cd(3)->SetLogy();
   
   // TPC3 e pull
   
   canvas_tpc3pulls->cd(4);
   
   //tpc3pulle_antimu->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpc3pulle_antimu->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpc3pulle_antimu, "antimu");
   SetHistParticleStyle(tpc3pulle_piplus, "piplus");
   SetHistParticleStyle(tpc3pulle_proton, "proton");
   SetHistParticleStyle(tpc3pulle_positron, "positron");
   
   tpc3pulle_antimu->Draw();
   tpc3pulle_piplus->Draw("same");
   tpc3pulle_proton->Draw("same");
   tpc3pulle_positron->Draw("same");
   //canvas_tpc3pulls->cd(4)->SetLogy();
   
   canvas_tpc3pulls->cd(1)->BuildLegend();
   canvas_tpc3pulls->Write();
   
   // nTPCs
   
   TCanvas* canvas_ntpcs = new TCanvas("canvas_ntpcs","",200,10,500,400);
   
   //ntpcs_antimu->GetYaxis()->SetRangeUser(0.0, 80000.0);
  
   SetHistParticleStyle(ntpcs_antimu, "antimu");
   SetHistParticleStyle(ntpcs_piplus, "piplus");
   SetHistParticleStyle(ntpcs_proton, "proton");
   SetHistParticleStyle(ntpcs_positron, "positron");
   
   ntpcs_antimu->Draw();
   ntpcs_piplus->Draw("same");
   ntpcs_proton->Draw("same");
   ntpcs_positron->Draw("same");
   canvas_ntpcs->BuildLegend();
   canvas_ntpcs->Write();
   
   // FGD1 E/L
   
   //TCanvas* canvas_fgd1EbyL = new TCanvas("canvas_fgd1EbyL","",200,10,1000,600);
   TCanvas* canvas_fgdEbyLs = new TCanvas("canvas_fgdEbyLs","",200,10,1000,400);
   canvas_fgdEbyLs->Divide(2,1,0.005,0.005);
   canvas_fgdEbyLs->cd(1);
   
   //fgd1EbyL_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(fgd1EbyL_antimu, "antimu");
   SetHistParticleStyle(fgd1EbyL_piplus, "piplus");
   SetHistParticleStyle(fgd1EbyL_proton, "proton");
   SetHistParticleStyle(fgd1EbyL_positron, "positron");
   
   fgd1EbyL_antimu->Draw();
   fgd1EbyL_piplus->Draw("same");
   fgd1EbyL_proton->Draw("same");
   fgd1EbyL_positron->Draw("same");
   //canvas_fgd1EbyL->BuildLegend();
   //canvas_fgd1EbyL->Write();
   canvas_fgdEbyLs->cd(1)->BuildLegend();
   
   // FGD2 E/L
   
   //TCanvas* canvas_fgd2EbyL = new TCanvas("canvas_fgd2EbyL","",200,10,1000,600);
   canvas_fgdEbyLs->cd(2);
   
   //fgd2EbyL_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(fgd2EbyL_antimu, "antimu");
   SetHistParticleStyle(fgd2EbyL_piplus, "piplus");
   SetHistParticleStyle(fgd2EbyL_proton, "proton");
   SetHistParticleStyle(fgd2EbyL_positron, "positron");
   
   fgd2EbyL_antimu->Draw();
   fgd2EbyL_piplus->Draw("same");
   fgd2EbyL_proton->Draw("same");
   fgd2EbyL_positron->Draw("same");
   //canvas_fgd2EbyL->BuildLegend();
   //canvas_fgd2EbyL->Write();
   canvas_fgdEbyLs->Write();
   
   // nSMRDs
   
   TCanvas* canvas_nsmrds = new TCanvas("canvas_nsmrds","",200,10,500,400);
   
   nsmrds_antimu->GetYaxis()->SetRangeUser(0.0, 80000.0);
  
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
   
   //std::cout << "Optimal significance = " << optimal_signif_mu << " at cut value of " << optimal_cut_mu << std::endl;
   //std::cout << "Efficiency = " << optimal_eff_mu  << ", purity = " << optimal_pur_mu << ", eff*pur = " << optimal_eff_mu*optimal_pur_mu << std::endl;
   std::cout << "mu+ efficiency: " <<  (Float_t)musel_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)musel_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)musel_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)musel_nPositron/presel_nPositron << std::endl;
   
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
   
   //std::cout << "Optimal significance = " << optimal_signif_pi << " at cut value of " << optimal_cut_pi << std::endl;
   //std::cout << "Efficiency = " << optimal_eff_pi  << ", purity = " << optimal_pur_pi << ", eff*pur = " << optimal_eff_pi*optimal_pur_pi << std::endl;
   //std::cout << std::endl;
   std::cout << "mu+ efficiency: " << (Float_t)pisel_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)pisel_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)pisel_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)pisel_nPositron/presel_nPositron << std::endl;
   
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
   
   //std::cout << "Optimal significance = " << optimal_signif_p << " at cut value of " << optimal_cut_p << std::endl;
   //std::cout << "Efficiency = " << optimal_eff_p  << ", purity = " << optimal_pur_p << ", eff*pur = " << optimal_eff_p*optimal_pur_p << std::endl;
   
   std::cout << "mu+ efficiency: " << (Float_t)psel_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)psel_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)psel_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)psel_nPositron/presel_nPositron << std::endl;
   
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
   
   //std::cout << "Optimal significance = " << optimal_signif_e << " at cut value of " << optimal_cut_e << std::endl;
   //std::cout << "Efficiency = " << optimal_eff_e  << ", purity = " << optimal_pur_e << ", eff*pur = " << optimal_eff_e*optimal_pur_e << std::endl;
   std::cout << "mu+ efficiency: " << (Float_t)esel_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)esel_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)esel_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)esel_nPositron/presel_nPositron << std::endl;
   
   graph_opt_e->Draw("AC");
   canvas_opt_e->Write();
   TCanvas* canvas_effpur_e = new TCanvas("effpur_elike","Optimisation efficiency and purity curves (e-like)",200,10,1000,600);
   //graph_opt_pur_e->Draw("AC");
   //graph_opt_eff_e->Draw("C* same");
   graph_opt_effpur_e->Draw("AC");
   canvas_effpur_e->Write();
   
   
   
   // =============== Parameter testing ===============
   
   std::cout << "=========== Parameter testing ===========" << std::endl << std::endl;
   
   if (parameter) {
   
      // Point 1
      
      if (parameter == "treedepth") std::cout << "Tree depth 2:" << std::endl;
      if (parameter == "treenumber") std::cout << "500 trees:" << std::endl;
      if (parameter == "shrinkage") std::cout << "Shrinkage 0.1:" << std::endl;
      if (parameter == "bagged") std::cout << "Bagged 0.1:" << std::endl;
      if (parameter == "randomforests") std::cout << "NVars 4:" << std::endl;
      
      std::cout << "Optimal mu-like significance = " << GetOptSignificanceValues(opt_mulike_sig_test1, opt_mulike_bkg_test1, optimisation_nbins) << std::endl;
      std::cout << "Optimal pi-like significance = " << GetOptSignificanceValues(opt_pilike_sig_test1, opt_pilike_bkg_test1, optimisation_nbins) << std::endl;
      std::cout << "Optimal p-like significance = " << GetOptSignificanceValues(opt_plike_sig_test1, opt_plike_bkg_test1, optimisation_nbins) << std::endl;
      std::cout << "Optimal e-like significance = " << GetOptSignificanceValues(opt_elike_sig_test1, opt_elike_bkg_test1, optimisation_nbins) << std::endl;
      
      // Point 2

      if (parameter == "treedepth") std::cout << "Tree depth 3:" << std::endl;
      if (parameter == "treenumber") std::cout << "1000 trees:" << std::endl;
      if (parameter == "shrinkage") std::cout << "Shrinkage 0.3:" << std::endl;
      if (parameter == "bagged") std::cout << "Bagged 0.3:" << std::endl;
      if (parameter == "randomforests") std::cout << "NVars 6:" << std::endl;
      
      std::cout << "Optimal mu-like significance = " << GetOptSignificanceValues(opt_mulike_sig_test2, opt_mulike_bkg_test2, optimisation_nbins) << std::endl;
      std::cout << "Optimal pi-like significance = " << GetOptSignificanceValues(opt_pilike_sig_test2, opt_pilike_bkg_test2, optimisation_nbins) << std::endl;
      std::cout << "Optimal p-like significance = " << GetOptSignificanceValues(opt_plike_sig_test2, opt_plike_bkg_test2, optimisation_nbins) << std::endl;
      std::cout << "Optimal e-like significance = " << GetOptSignificanceValues(opt_elike_sig_test2, opt_elike_bkg_test2, optimisation_nbins) << std::endl;
      
      // Point 3
      
      if (parameter == "treedepth") std::cout << "Tree depth 4:" << std::endl;
      if (parameter == "treenumber") std::cout << "1500 trees:" << std::endl;
      if (parameter == "shrinkage") std::cout << "Shrinkage 0.5:" << std::endl;
      if (parameter == "bagged") std::cout << "Bagged 0.5:" << std::endl;
      if (parameter == "randomforests") std::cout << "NVars 8:" << std::endl;
      
      std::cout << "Optimal mu-like significance = " << GetOptSignificanceValues(opt_mulike_sig_test3, opt_mulike_bkg_test3, optimisation_nbins) << std::endl;
      std::cout << "Optimal pi-like significance = " << GetOptSignificanceValues(opt_pilike_sig_test3, opt_pilike_bkg_test3, optimisation_nbins) << std::endl;
      std::cout << "Optimal p-like significance = " << GetOptSignificanceValues(opt_plike_sig_test3, opt_plike_bkg_test3, optimisation_nbins) << std::endl;
      std::cout << "Optimal e-like significance = " << GetOptSignificanceValues(opt_elike_sig_test3, opt_elike_bkg_test3, optimisation_nbins) << std::endl;
      
      // Point 4

      if (parameter == "treedepth") std::cout << "Tree depth 5:" << std::endl;
      if (parameter == "treenumber") std::cout << "2000 trees:" << std::endl;
      if (parameter == "shrinkage") std::cout << "Shrinkage 0.7:" << std::endl;
      if (parameter == "bagged") std::cout << "Bagged 0.7:" << std::endl;
      if (parameter == "randomforests") std::cout << "NVars 10:" << std::endl;
      
      std::cout << "Optimal mu-like significance = " << GetOptSignificanceValues(opt_mulike_sig_test4, opt_mulike_bkg_test4, optimisation_nbins) << std::endl;
      std::cout << "Optimal pi-like significance = " << GetOptSignificanceValues(opt_pilike_sig_test4, opt_pilike_bkg_test4, optimisation_nbins) << std::endl;
      std::cout << "Optimal p-like significance = " << GetOptSignificanceValues(opt_plike_sig_test4, opt_plike_bkg_test4, optimisation_nbins) << std::endl;
      std::cout << "Optimal e-like significance = " << GetOptSignificanceValues(opt_elike_sig_test4, opt_elike_bkg_test4, optimisation_nbins) << std::endl;
      
      // Point 5
      
      if (parameter != "treedepth")
      {
         if (parameter == "treenumber") std::cout << "2500 trees:" << std::endl;
         if (parameter == "shrinkage") std::cout << "Shrinkage 0.9:" << std::endl;
         if (parameter == "bagged") std::cout << "Bagged 0.9:" << std::endl;
         if (parameter == "randomforests") std::cout << "NVars 12:" << std::endl;
         
         std::cout << "Optimal mu-like significance = " << GetOptSignificanceValues(opt_mulike_sig_test5, opt_mulike_bkg_test5, optimisation_nbins) << std::endl;
         std::cout << "Optimal pi-like significance = " << GetOptSignificanceValues(opt_pilike_sig_test5, opt_pilike_bkg_test5, optimisation_nbins) << std::endl;
         std::cout << "Optimal p-like significance = " << GetOptSignificanceValues(opt_plike_sig_test5, opt_plike_bkg_test5, optimisation_nbins) << std::endl;
         std::cout << "Optimal e-like significance = " << GetOptSignificanceValues(opt_elike_sig_test5, opt_elike_bkg_test5, optimisation_nbins) << std::endl;
      }
         
         
      
   }
   
   
   
   
   // ============= Correlation plots =============
   /*
   
   //TCanvas* canvas_corr_weighting_mulike = new TCanvas("canvas_corr_weighting_mulike","",200,10,1000,1000);
   //corr_weighting_mulike->Draw("colz");
   //canvas_corr_weighting_mulike->Write();
   corr_weighting_mulike->Write();
   corr_weighting_pilike->Write();
   corr_weighting_plike->Write();
   corr_weighting_elike->Write();
   
   corr_mulikediff_recomom->Write();
   corr_pilikediff_recomom->Write();
   corr_plikediff_recomom->Write();
   corr_elikediff_recomom->Write();
      
    */
   
   // ============= Test existing cuts =============
   /*
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
      
   */
   
   
      
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
