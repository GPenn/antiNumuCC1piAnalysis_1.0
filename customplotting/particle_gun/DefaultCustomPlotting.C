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
   
   
   TString parameter = "treenumber";
   
   
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntries();
   
   std::cout << "Total entries to process: " << nentries << std::endl << std::endl;
   
   std::time_t time_start = std::time(0);
   
   Int_t variable_bins = 50;
   
   TH1F *recomom_antimu = new TH1F("recomom_antimu", "#mu^{+};Reconstructed momentum (MeV/c);Entries/50 MeV/c", 32, 0.0, 1600.0);
   TH1F *recomom_piplus = new TH1F("recomom_piplus", "#pi^{+}", 32, 0.0, 1600.0);
   TH1F *recomom_proton = new TH1F("recomom_proton", "p", 32, 0.0, 1600.0);
   TH1F *recomom_positron = new TH1F("recomom_positron", "e^{+}", 32, 0.0, 1600.0);
   
   TH1F *recomom_antimu2 = new TH1F("recomom_antimu2", "#mu^{+};Reconstructed momentum (MeV/c);Entries/50 MeV/c", 50, 0.0, 2500.0);
   TH1F *recomom_piplus2 = new TH1F("recomom_piplus2", "#pi^{+}", 50, 0.0, 2500.0);
   TH1F *recomom_proton2 = new TH1F("recomom_proton2", "p", 50, 0.0, 2500.0);
   TH1F *recomom_positron2 = new TH1F("recomom_positron2", "e^{+}", 50, 0.0, 2500.0);
   
   TH1F *truemom_antimu = new TH1F("truemom_antimu", "#mu^{+};True momentum (MeV/c);Entries/50 MeV/c", 42, 0.0, 2100.0);
   TH1F *truemom_piplus = new TH1F("truemom_piplus", "#pi^{+}", 42, 0.0, 2100.0);
   TH1F *truemom_proton = new TH1F("truemom_proton", "p", 42, 0.0, 2100.0);
   TH1F *truemom_positron = new TH1F("truemom_positron", "e^{+}", 42, 0.0, 2100.0);
   
   TH1F *truemom_antimu2 = new TH1F("truemom_antimu2", "#mu^{+};True momentum (MeV/c);Entries/50 MeV/c", 42, 0.0, 2100.0);
   TH1F *truemom_piplus2 = new TH1F("truemom_piplus2", "#pi^{+}", 42, 0.0, 2100.0);
   TH1F *truemom_proton2 = new TH1F("truemom_proton2", "p", 42, 0.0, 2100.0);
   TH1F *truemom_positron2 = new TH1F("truemom_positron2", "e^{+}", 42, 0.0, 2100.0);
   
   TH1F *theta_antimu = new TH1F("theta_antimu", "#mu^{+};Reconstructed angle w.r.t. detector Z-axis (rad);Entries/0.05 rad", 24, 0.0, 1.2);
   TH1F *theta_piplus = new TH1F("theta_piplus", "#pi^{+}", 24, 0.0, 1.2);
   TH1F *theta_proton = new TH1F("theta_proton", "p", 24, 0.0, 1.2);
   TH1F *theta_positron = new TH1F("theta_positron", "e^{+}", 24, 0.0, 1.2);
   
   TH1F *EMEnergy_antimu = new TH1F("EMEnergy_antimu", "#mu^{+};Reconstructed ECal EM energy (MeV);Entries/50 MeV", 50, 0.0, 2500);
   TH1F *EMEnergy_piplus = new TH1F("EMEnergy_piplus", "#pi^{+}", 50, 0.0, 2500);
   TH1F *EMEnergy_proton = new TH1F("EMEnergy_proton", "p", 50, 0.0, 2500);
   TH1F *EMEnergy_positron = new TH1F("EMEnergy_positron", "e^{+}", 50, 0.0, 2500);
   
   TH1F *EbyL_antimu = new TH1F("EbyL_antimu", "#mu^{+};ECal EM energy/ECal segment length (MeV/mm);Entries/10 MeV/mm", 40, 0.0, 4);
   TH1F *EbyL_piplus = new TH1F("EbyL_piplus", "#pi^{+}", 40, 0.0, 4);
   TH1F *EbyL_proton = new TH1F("EbyL_proton", "p", 40, 0.0, 4);
   TH1F *EbyL_positron = new TH1F("EbyL_positron", "e^{+}", 40, 0.0, 4);
   
   TH1F *circularity_antimu = new TH1F("circularity_antimu", "#mu^{+};ECal circularity variable (dimensionless);Entries", 50, 0.0, 1.0);
   TH1F *circularity_piplus = new TH1F("circularity_piplus", "#pi^{+}", 50, 0.0, 1.0);
   TH1F *circularity_proton = new TH1F("circularity_proton", "p", 50, 0.0, 1.0);
   TH1F *circularity_positron = new TH1F("circularity_positron", "e^{+}", 50, 0.0, 1.0);
   
   TH1F *fbr_antimu = new TH1F("fbr_antimu", "#mu^{+};ECal FrontBackRatio variable (dimensionless);Entries", 50, 0.0, 10.0);
   TH1F *fbr_piplus = new TH1F("fbr_piplus", "#pi^{+}", 50, 0.0, 10.0);
   TH1F *fbr_proton = new TH1F("fbr_proton", "p", 50, 0.0, 10.0);
   TH1F *fbr_positron = new TH1F("fbr_positron", "e^{+}", 50, 0.0, 10.0);
   
   TH1F *tmr_antimu = new TH1F("tmr_antimu", "#mu^{+};ECal TruncatedMaxRatio variable (dimensionless);Entries", 50, 0.0, 1.0);
   TH1F *tmr_piplus = new TH1F("tmr_piplus", "#pi^{+}", 50, 0.0, 1.0);
   TH1F *tmr_proton = new TH1F("tmr_proton", "p", 50, 0.0, 1.0);
   TH1F *tmr_positron = new TH1F("tmr_positron", "e^{+}", 50, 0.0, 1.0);
   
   TH1F *qrms_antimu = new TH1F("qrms_antimu", "#mu^{+};ECal QRMS variable (dimensionless);Entries", 30, 0.0, 3.0);
   TH1F *qrms_piplus = new TH1F("qrms_piplus", "#pi^{+}", 30, 0.0, 3.0);
   TH1F *qrms_proton = new TH1F("qrms_proton", "p", 30, 0.0, 3.0);
   TH1F *qrms_positron = new TH1F("qrms_positron", "e^{+}", 30, 0.0, 3.0);
   
   TH1F *mipem_antimu = new TH1F("mipem_antimu", "#mu^{+};ECal MipEm variable (dimensionless);Entries", 60, -50.0, 70.0);
   TH1F *mipem_piplus = new TH1F("mipem_piplus", "#pi^{+}", 60, -50.0, 70.0);
   TH1F *mipem_proton = new TH1F("mipem_proton", "p", 60, -50.0, 70.0);
   TH1F *mipem_positron = new TH1F("mipem_positron", "e^{+}", 60, -50.0, 70.0);
   
   TH1F *emhip_antimu = new TH1F("emhip_antimu", "#mu^{+};ECal EmHip variable (dimensionless);Entries", 40, -40.0, 40.0);
   TH1F *emhip_piplus = new TH1F("emhip_piplus", "#pi^{+}", 40, -40.0, 40.0);
   TH1F *emhip_proton = new TH1F("emhip_proton", "p", 40, -40.0, 40.0);
   TH1F *emhip_positron = new TH1F("emhip_positron", "e^{+}", 40, -40.0, 40.0);
   
   TH1F *mippion_antimu = new TH1F("mippion_antimu", "#mu^{+};ECal MipPion variable (dimensionless);Entries", 50, -30.0, 70.0);
   TH1F *mippion_piplus = new TH1F("mippion_piplus", "#pi^{+}", 50, -30.0, 70.0);
   TH1F *mippion_proton = new TH1F("mippion_proton", "p", 50, -30.0, 70.0);
   TH1F *mippion_positron = new TH1F("mippion_positron", "e^{+}", 50, -30.0, 70.0);
   
   TH1F *tpc2dedx_antimu = new TH1F("tpc2dedx_antimu", "#mu^{+};TPC2 dE/dx truncated mean (arb. units);Entries", 50, 0.0, 2000.0);
   TH1F *tpc2dedx_piplus = new TH1F("tpc2dedx_piplus", "#pi^{+}", 50, 0.0, 2000.0);
   TH1F *tpc2dedx_proton = new TH1F("tpc2dedx_proton", "p", 50, 0.0, 2000.0);
   TH1F *tpc2dedx_positron = new TH1F("tpc2dedx_positron", "e^{+}", 50, 0.0, 2000.0);
   
   TH1F *tpc3dedx_antimu = new TH1F("tpc3dedx_antimu", "#mu^{+};TPC3 dE/dx truncated mean (arb. units);Entries", 50, 0.0, 2000.0);
   TH1F *tpc3dedx_piplus = new TH1F("tpc3dedx_piplus", "#pi^{+}", 50, 0.0, 2000.0);
   TH1F *tpc3dedx_proton = new TH1F("tpc3dedx_proton", "p", 50, 0.0, 2000.0);
   TH1F *tpc3dedx_positron = new TH1F("tpc3dedx_positron", "e^{+}", 50, 0.0, 2000.0);

   TH1F *tpc3dedx_gq_antimu = new TH1F("tpc3dedx_gq_antimu", "#mu^{+};TPC3 dE/dx truncated mean with quality check (arb. units);Entries", 50, 0.0, 2000.0);
   TH1F *tpc3dedx_gq_piplus = new TH1F("tpc3dedx_gq_piplus", "#pi^{+}", 50, 0.0, 2000.0);
   TH1F *tpc3dedx_gq_proton = new TH1F("tpc3dedx_gq_proton", "p", 50, 0.0, 2000.0);
   TH1F *tpc3dedx_gq_positron = new TH1F("tpc3dedx_gq_positron", "e^{+}", 50, 0.0, 2000.0);
   
   TH1F *tpclikemu_antimu = new TH1F("tpclikemu_antimu", "#mu^{+};TPC2 muon likelihood;Entries", 50, 0.0, 1.0);
   TH1F *tpclikemu_piplus = new TH1F("tpclikemu_piplus", "#pi^{+}", 50, 0.0, 1.0);
   TH1F *tpclikemu_proton = new TH1F("tpclikemu_proton", "p", 50, 0.0, 1.0);
   TH1F *tpclikemu_positron = new TH1F("tpclikemu_positron", "e^{+}", 50, 0.0, 1.0);
   
   TH1F *tpclikepi_antimu = new TH1F("tpclikepi_antimu", "#mu^{+};TPC2 charged pion likelihood;Entries", 50, 0.0, 1.0);
   TH1F *tpclikepi_piplus = new TH1F("tpclikepi_piplus", "#pi^{+}", 50, 0.0, 1.0);
   TH1F *tpclikepi_proton = new TH1F("tpclikepi_proton", "p", 50, 0.0, 1.0);
   TH1F *tpclikepi_positron = new TH1F("tpclikepi_positron", "e^{+}", 50, 0.0, 1.0);
   
   TH1F *tpclikep_antimu = new TH1F("tpclikep_antimu", "#mu^{+};TPC2 proton likelihood;Entries", 50, 0.0, 1.0);
   TH1F *tpclikep_piplus = new TH1F("tpclikep_piplus", "#pi^{+}", 50, 0.0, 1.0);
   TH1F *tpclikep_proton = new TH1F("tpclikep_proton", "p", 50, 0.0, 1.0);
   TH1F *tpclikep_positron = new TH1F("tpclikep_positron", "e^{+}", 50, 0.0, 1.0);
   
   TH1F *tpclikee_antimu = new TH1F("tpclikee_antimu", "#mu^{+};TPC2 electron likelihood;Entries", 50, 0.0, 1.0);
   TH1F *tpclikee_piplus = new TH1F("tpclikee_piplus", "#pi^{+}", 50, 0.0, 1.0);
   TH1F *tpclikee_proton = new TH1F("tpclikee_proton", "p", 50, 0.0, 1.0);
   TH1F *tpclikee_positron = new TH1F("tpclikee_positron", "e^{+}", 50, 0.0, 1.0);
   
   TH1F *tpc2pullmu_antimu = new TH1F("tpc2pullmu_antimu", "#mu^{+};TPC2 muon pull;Entries", 50, -10.0, 40.0);
   TH1F *tpc2pullmu_piplus = new TH1F("tpc2pullmu_piplus", "#pi^{+}", 50, -10.0, 40.0);
   TH1F *tpc2pullmu_proton = new TH1F("tpc2pullmu_proton", "p", 50, -10.0, 40.0);
   TH1F *tpc2pullmu_positron = new TH1F("tpc2pullmu_positron", "e^{+}", 50, -10.0, 40.0);
   
   TH1F *tpc2pullpi_antimu = new TH1F("tpc2pullpi_antimu", "#mu^{+};TPC2 charged pion pull;Entries", 50, -10.0, 40.0);
   TH1F *tpc2pullpi_piplus = new TH1F("tpc2pullpi_piplus", "#pi^{+}", 50, -10.0, 40.0);
   TH1F *tpc2pullpi_proton = new TH1F("tpc2pullpi_proton", "p", 50, -10.0, 40.0);
   TH1F *tpc2pullpi_positron = new TH1F("tpc2pullpi_positron", "e^{+}", 50, -10.0, 40.0);
   
   TH1F *tpc2pullp_antimu = new TH1F("tpc2pullp_antimu", "#mu^{+};TPC2 proton pull;Entries", 50, -40.0, 20.0);
   TH1F *tpc2pullp_piplus = new TH1F("tpc2pullp_piplus", "#pi^{+}", 50, -40.0, 20.0);
   TH1F *tpc2pullp_proton = new TH1F("tpc2pullp_proton", "p", 50, -40.0, 20.0);
   TH1F *tpc2pullp_positron = new TH1F("tpc2pullp_positron", "e^{+}", 50, -40.0, 20.0);
   
   TH1F *tpc2pulle_antimu = new TH1F("tpc2pulle_antimu", "#mu^{+};TPC2 electron pull;Entries", 50, -20.0, 30.0);
   TH1F *tpc2pulle_piplus = new TH1F("tpc2pulle_piplus", "#pi^{+}", 50, -20.0, 30.0);
   TH1F *tpc2pulle_proton = new TH1F("tpc2pulle_proton", "p", 50, -20.0, 30.0);
   TH1F *tpc2pulle_positron = new TH1F("tpc2pulle_positron", "e^{+}", 50, -20.0, 30.0);
   
   TH1F *tpc3pullmu_antimu = new TH1F("tpc3pullmu_antimu", "#mu^{+};TPC3 muon pull;Entries", 50, -10.0, 30.0);
   TH1F *tpc3pullmu_piplus = new TH1F("tpc3pullmu_piplus", "#pi^{+}", 50, -10.0, 30.0);
   TH1F *tpc3pullmu_proton = new TH1F("tpc3pullmu_proton", "p", 50, -10.0, 30.0);
   TH1F *tpc3pullmu_positron = new TH1F("tpc3pullmu_positron", "e^{+}", 50, -10.0, 30.0);
   
   TH1F *tpc3pullpi_antimu = new TH1F("tpc3pullpi_antimu", "#mu^{+};TPC3 charged pion pull;Entries", 50, -10.0, 40.0);
   TH1F *tpc3pullpi_piplus = new TH1F("tpc3pullpi_piplus", "#pi^{+}", 50, -10.0, 40.0);
   TH1F *tpc3pullpi_proton = new TH1F("tpc3pullpi_proton", "p", 50, -10.0, 40.0);
   TH1F *tpc3pullpi_positron = new TH1F("tpc3pullpi_positron", "e^{+}", 50, -10.0, 40.0);
   
   TH1F *tpc3pullp_antimu = new TH1F("tpc3pullp_antimu", "#mu^{+};TPC3 proton pull;Entries", 50, -40.0, 20.0);
   TH1F *tpc3pullp_piplus = new TH1F("tpc3pullp_piplus", "#pi^{+}", 50, -40.0, 20.0);
   TH1F *tpc3pullp_proton = new TH1F("tpc3pullp_proton", "p", 50, -40.0, 20.0);
   TH1F *tpc3pullp_positron = new TH1F("tpc3pullp_positron", "e^{+}", 50, -40.0, 20.0);
   
   TH1F *tpc3pulle_antimu = new TH1F("tpc3pulle_antimu", "#mu^{+};TPC3 electron pull;Entries", 50, -10.0, 20.0);
   TH1F *tpc3pulle_piplus = new TH1F("tpc3pulle_piplus", "#pi^{+}", 50, -10.0, 20.0);
   TH1F *tpc3pulle_proton = new TH1F("tpc3pulle_proton", "p", 50, -10.0, 20.0);
   TH1F *tpc3pulle_positron = new TH1F("tpc3pulle_positron", "e^{+}", 50, -10.0, 20.0);
   
   TH1F *tpc3pullmu_gq_antimu = new TH1F("tpc3pullmu_gq_antimu", "#mu^{+};TPC3 muon pull with quality check;Entries", 50, -10.0, 30.0);
   TH1F *tpc3pullmu_gq_piplus = new TH1F("tpc3pullmu_gq_piplus", "#pi^{+}", 50, -10.0, 30.0);
   TH1F *tpc3pullmu_gq_proton = new TH1F("tpc3pullmu_gq_proton", "p", 50, -10.0, 30.0);
   TH1F *tpc3pullmu_gq_positron = new TH1F("tpc3pullmu_gq_positron", "e^{+}", 50, -10.0, 30.0);
   
   TH1F *tpc3pullpi_gq_antimu = new TH1F("tpc3pullpi_gq_antimu", "#mu^{+};TPC3 charged pion pull with quality check;Entries", 50, -10.0, 40.0);
   TH1F *tpc3pullpi_gq_piplus = new TH1F("tpc3pullpi_gq_piplus", "#pi^{+}", 50, -10.0, 40.0);
   TH1F *tpc3pullpi_gq_proton = new TH1F("tpc3pullpi_gq_proton", "p", 50, -10.0, 40.0);
   TH1F *tpc3pullpi_gq_positron = new TH1F("tpc3pullpi_gq_positron", "e^{+}", 50, -10.0, 40.0);
   
   TH1F *tpc3pullp_gq_antimu = new TH1F("tpc3pullp_gq_antimu", "#mu^{+};TPC3 proton pull with quality check;Entries", 50, -40.0, 20.0);
   TH1F *tpc3pullp_gq_piplus = new TH1F("tpc3pullp_gq_piplus", "#pi^{+}", 50, -40.0, 20.0);
   TH1F *tpc3pullp_gq_proton = new TH1F("tpc3pullp_gq_proton", "p", 50, -40.0, 20.0);
   TH1F *tpc3pullp_gq_positron = new TH1F("tpc3pullp_gq_positron", "e^{+}", 50, -40.0, 20.0);
   
   TH1F *tpc3pulle_gq_antimu = new TH1F("tpc3pulle_gq_antimu", "#mu^{+};TPC3 electron pull with quality check;Entries", 50, -10.0, 20.0);
   TH1F *tpc3pulle_gq_piplus = new TH1F("tpc3pulle_gq_piplus", "#pi^{+}", 50, -10.0, 20.0);
   TH1F *tpc3pulle_gq_proton = new TH1F("tpc3pulle_gq_proton", "p", 50, -10.0, 20.0);
   TH1F *tpc3pulle_gq_positron = new TH1F("tpc3pulle_gq_positron", "e^{+}", 50, -10.0, 20.0);
   
   TH1F *ntpcs_antimu = new TH1F("ntpcs_antimu", "#mu^{+};Number of TPC segments;Entries", 2, 0.5, 2.5);
   TH1F *ntpcs_piplus = new TH1F("ntpcs_piplus", "#pi^{+}", 2, 0.5, 2.5);
   TH1F *ntpcs_proton = new TH1F("ntpcs_proton", "p", 2, 0.5, 2.5);
   TH1F *ntpcs_positron = new TH1F("ntpcs_positron", "e^{+}", 2, 0.5, 2.5);
   
   TH1F *fgd1EbyL_antimu = new TH1F("fgd1EbyL_antimu", "#mu^{+};FGD1 energy/length (MeV/mm);Entries", 50, 0.0, 1.0);
   TH1F *fgd1EbyL_piplus = new TH1F("fgd1EbyL_piplus", "#pi^{+}", 50, 0.0, 1.0);
   TH1F *fgd1EbyL_proton = new TH1F("fgd1EbyL_proton", "p", 50, 0.0, 1.0);
   TH1F *fgd1EbyL_positron = new TH1F("fgd1EbyL_positron", "e^{+}", 50, 0.0, 1.0);
   
   TH1F *fgd2EbyL_antimu = new TH1F("fgd2EbyL_antimu", "#mu^{+};FGD2 energy/length (MeV/mm);Entries", 30, 0.0, 0.6);
   TH1F *fgd2EbyL_piplus = new TH1F("fgd2EbyL_piplus", "#pi^{+}", 30, 0.0, 0.6);
   TH1F *fgd2EbyL_proton = new TH1F("fgd2EbyL_proton", "p", 30, 0.0, 0.6);
   TH1F *fgd2EbyL_positron = new TH1F("fgd2EbyL_positron", "e^{+}", 30, 0.0, 0.6);
   
   TH1F *nsmrds_antimu = new TH1F("nsmrds_antimu", "#mu^{+};Number of SMRD segments;Entries", 3, -0.5, 2.5);
   TH1F *nsmrds_piplus = new TH1F("nsmrds_piplus", "#pi^{+}", 3, -0.5, 2.5);
   TH1F *nsmrds_proton = new TH1F("nsmrds_proton", "p", 3, -0.5, 2.5);
   TH1F *nsmrds_positron = new TH1F("nsmrds_positron", "e^{+}", 3, -0.5, 2.5);
   
   
   TH1F *recomom_antimu_weighted = new TH1F("recomom_antimu_weighted", "#mu^{+};Reconstructed momentum (MeV/c);Weighted entries/50 MeV/c", 32, 0.0, 1600.0);
   TH1F *recomom_piplus_weighted = new TH1F("recomom_piplus_weighted", "#pi^{+}", 32, 0.0, 1600.0);
   TH1F *recomom_proton_weighted = new TH1F("recomom_proton_weighted", "p", 32, 0.0, 1600.0);
   TH1F *recomom_positron_weighted = new TH1F("recomom_positron_weighted", "e^{+}", 32, 0.0, 1600.0);
   
   TH1F *theta_antimu_weighted = new TH1F("theta_antimu_weighted", "#mu^{+};Reconstructed angle w.r.t. detector Z-axis (rad);Weighted entries/0.05 rad", 24, 0.0, 1.2);
   TH1F *theta_piplus_weighted = new TH1F("theta_piplus_weighted", "#pi^{+}", 24, 0.0, 1.2);
   TH1F *theta_proton_weighted = new TH1F("theta_proton_weighted", "p", 24, 0.0, 1.2);
   TH1F *theta_positron_weighted = new TH1F("theta_positron_weighted", "e^{+}", 24, 0.0, 1.2);
   
   TH1F *EMEnergy_antimu_weighted = new TH1F("EMEnergy_antimu_weighted", "#mu^{+};Reconstructed ECal EM energy (MeV);Weighted entries/50 MeV", 50, 0.0, 2500);
   TH1F *EMEnergy_piplus_weighted = new TH1F("EMEnergy_piplus_weighted", "#pi^{+}", 50, 0.0, 2500);
   TH1F *EMEnergy_proton_weighted = new TH1F("EMEnergy_proton_weighted", "p", 50, 0.0, 2500);
   TH1F *EMEnergy_positron_weighted = new TH1F("EMEnergy_positron_weighted", "e^{+}", 50, 0.0, 2500);
   
   TH1F *EbyL_antimu_weighted = new TH1F("EbyL_antimu_weighted", "#mu^{+};ECal EM energy/ECal segment length (MeV/mm);Weighted entries/10 MeV/mm", 40, 0.0, 4);
   TH1F *EbyL_piplus_weighted = new TH1F("EbyL_piplus_weighted", "#pi^{+}", 40, 0.0, 4);
   TH1F *EbyL_proton_weighted = new TH1F("EbyL_proton_weighted", "p", 40, 0.0, 4);
   TH1F *EbyL_positron_weighted = new TH1F("EbyL_positron_weighted", "e^{+}", 40, 0.0, 4);
   
   TH1F *circularity_antimu_weighted = new TH1F("circularity_antimu_weighted", "#mu^{+};ECal circularity variable (dimensionless);Weighted entries", 50, 0.0, 1.0);
   TH1F *circularity_piplus_weighted = new TH1F("circularity_piplus_weighted", "#pi^{+}", 50, 0.0, 1.0);
   TH1F *circularity_proton_weighted = new TH1F("circularity_proton_weighted", "p", 50, 0.0, 1.0);
   TH1F *circularity_positron_weighted = new TH1F("circularity_positron_weighted", "e^{+}", 50, 0.0, 1.0);
   
   TH1F *fbr_antimu_weighted = new TH1F("fbr_antimu_weighted", "#mu^{+};ECal FrontBackRatio variable (dimensionless);Weighted entries", 50, 0.0, 10.0);
   TH1F *fbr_piplus_weighted = new TH1F("fbr_piplus_weighted", "#pi^{+}", 50, 0.0, 10.0);
   TH1F *fbr_proton_weighted = new TH1F("fbr_proton_weighted", "p", 50, 0.0, 10.0);
   TH1F *fbr_positron_weighted = new TH1F("fbr_positron_weighted", "e^{+}", 50, 0.0, 10.0);
   
   TH1F *tmr_antimu_weighted = new TH1F("tmr_antimu_weighted", "#mu^{+};ECal TruncatedMaxRatio variable (dimensionless);Weighted entries", 50, 0.0, 1.0);
   TH1F *tmr_piplus_weighted = new TH1F("tmr_piplus_weighted", "#pi^{+}", 50, 0.0, 1.0);
   TH1F *tmr_proton_weighted = new TH1F("tmr_proton_weighted", "p", 50, 0.0, 1.0);
   TH1F *tmr_positron_weighted = new TH1F("tmr_positron_weighted", "e^{+}", 50, 0.0, 1.0);
   
   TH1F *qrms_antimu_weighted = new TH1F("qrms_antimu_weighted", "#mu^{+};ECal QRMS variable (dimensionless);Weighted entries", 30, 0.0, 3.0);
   TH1F *qrms_piplus_weighted = new TH1F("qrms_piplus_weighted", "#pi^{+}", 30, 0.0, 3.0);
   TH1F *qrms_proton_weighted = new TH1F("qrms_proton_weighted", "p", 30, 0.0, 3.0);
   TH1F *qrms_positron_weighted = new TH1F("qrms_positron_weighted", "e^{+}", 30, 0.0, 3.0);
   
   TH1F *mipem_antimu_weighted = new TH1F("mipem_antimu_weighted", "#mu^{+};ECal MipEm variable (dimensionless);Weighted entries", 60, -50.0, 70.0);
   TH1F *mipem_piplus_weighted = new TH1F("mipem_piplus_weighted", "#pi^{+}", 60, -50.0, 70.0);
   TH1F *mipem_proton_weighted = new TH1F("mipem_proton_weighted", "p", 60, -50.0, 70.0);
   TH1F *mipem_positron_weighted = new TH1F("mipem_positron_weighted", "e^{+}", 60, -50.0, 70.0);
   
   TH1F *emhip_antimu_weighted = new TH1F("emhip_antimu_weighted", "#mu^{+};ECal EmHip variable (dimensionless);Weighted entries", 40, -40.0, 40.0);
   TH1F *emhip_piplus_weighted = new TH1F("emhip_piplus_weighted", "#pi^{+}", 40, -40.0, 40.0);
   TH1F *emhip_proton_weighted = new TH1F("emhip_proton_weighted", "p", 40, -40.0, 40.0);
   TH1F *emhip_positron_weighted = new TH1F("emhip_positron_weighted", "e^{+}", 40, -40.0, 40.0);
   
   TH1F *mippion_antimu_weighted = new TH1F("mippion_antimu_weighted", "#mu^{+};ECal MipPion variable (dimensionless);Weighted entries", 50, -30.0, 70.0);
   TH1F *mippion_piplus_weighted = new TH1F("mippion_piplus_weighted", "#pi^{+}", 50, -30.0, 70.0);
   TH1F *mippion_proton_weighted = new TH1F("mippion_proton_weighted", "p", 50, -30.0, 70.0);
   TH1F *mippion_positron_weighted = new TH1F("mippion_positron_weighted", "e^{+}", 50, -30.0, 70.0);
   
   TH1F *tpc2dedx_antimu_weighted = new TH1F("tpc2dedx_antimu_weighted", "#mu^{+};TPC2 dE/dx truncated mean (arb. units);Weighted entries", 50, 0.0, 2000.0);
   TH1F *tpc2dedx_piplus_weighted = new TH1F("tpc2dedx_piplus_weighted", "#pi^{+}", 50, 0.0, 2000.0);
   TH1F *tpc2dedx_proton_weighted = new TH1F("tpc2dedx_proton_weighted", "p", 50, 0.0, 2000.0);
   TH1F *tpc2dedx_positron_weighted = new TH1F("tpc2dedx_positron_weighted", "e^{+}", 50, 0.0, 2000.0);
   
   TH1F *tpc3dedx_antimu_weighted = new TH1F("tpc3dedx_antimu_weighted", "#mu^{+};TPC3 dE/dx truncated mean (arb. units);Weighted entries", 50, 0.0, 2000.0);
   TH1F *tpc3dedx_piplus_weighted = new TH1F("tpc3dedx_piplus_weighted", "#pi^{+}", 50, 0.0, 2000.0);
   TH1F *tpc3dedx_proton_weighted = new TH1F("tpc3dedx_proton_weighted", "p", 50, 0.0, 2000.0);
   TH1F *tpc3dedx_positron_weighted = new TH1F("tpc3dedx_positron_weighted", "e^{+}", 50, 0.0, 2000.0);
   
   TH1F *tpc3dedx_gq_antimu_weighted = new TH1F("tpc3dedx_gq_antimu_weighted", "#mu^{+};TPC3 dE/dx truncated mean with quality check (arb. units);Weighted entries", 50, 0.0, 2000.0);
   TH1F *tpc3dedx_gq_piplus_weighted = new TH1F("tpc3dedx_gq_piplus_weighted", "#pi^{+}", 50, 0.0, 2000.0);
   TH1F *tpc3dedx_gq_proton_weighted = new TH1F("tpc3dedx_gq_proton_weighted", "p", 50, 0.0, 2000.0);
   TH1F *tpc3dedx_gq_positron_weighted = new TH1F("tpc3dedx_gq_positron_weighted", "e^{+}", 50, 0.0, 2000.0);
   
   TH1F *tpclikemu_antimu_weighted = new TH1F("tpclikemu_antimu_weighted", "#mu^{+};TPC2 muon likelihood;Weighted entries", 50, 0.0, 1.0);
   TH1F *tpclikemu_piplus_weighted = new TH1F("tpclikemu_piplus_weighted", "#pi^{+}", 50, 0.0, 1.0);
   TH1F *tpclikemu_proton_weighted = new TH1F("tpclikemu_proton_weighted", "p", 50, 0.0, 1.0);
   TH1F *tpclikemu_positron_weighted = new TH1F("tpclikemu_positron_weighted", "e^{+}", 50, 0.0, 1.0);
   
   TH1F *tpclikepi_antimu_weighted = new TH1F("tpclikepi_antimu_weighted", "#mu^{+};TPC2 charged pion likelihood;Weighted entries", 50, 0.0, 1.0);
   TH1F *tpclikepi_piplus_weighted = new TH1F("tpclikepi_piplus_weighted", "#pi^{+}", 50, 0.0, 1.0);
   TH1F *tpclikepi_proton_weighted = new TH1F("tpclikepi_proton_weighted", "p", 50, 0.0, 1.0);
   TH1F *tpclikepi_positron_weighted = new TH1F("tpclikepi_positron_weighted", "e^{+}", 50, 0.0, 1.0);
   
   TH1F *tpclikep_antimu_weighted = new TH1F("tpclikep_antimu_weighted", "#mu^{+};TPC2 proton likelihood;Weighted entries", 50, 0.0, 1.0);
   TH1F *tpclikep_piplus_weighted = new TH1F("tpclikep_piplus_weighted", "#pi^{+}", 50, 0.0, 1.0);
   TH1F *tpclikep_proton_weighted = new TH1F("tpclikep_proton_weighted", "p", 50, 0.0, 1.0);
   TH1F *tpclikep_positron_weighted = new TH1F("tpclikep_positron_weighted", "e^{+}", 50, 0.0, 1.0);
   
   TH1F *tpclikee_antimu_weighted = new TH1F("tpclikee_antimu_weighted", "#mu^{+};TPC2 electron likelihood;Weighted entries", 50, 0.0, 1.0);
   TH1F *tpclikee_piplus_weighted = new TH1F("tpclikee_piplus_weighted", "#pi^{+}", 50, 0.0, 1.0);
   TH1F *tpclikee_proton_weighted = new TH1F("tpclikee_proton_weighted", "p", 50, 0.0, 1.0);
   TH1F *tpclikee_positron_weighted = new TH1F("tpclikee_positron_weighted", "e^{+}", 50, 0.0, 1.0);
   
   TH1F *tpc2pullmu_antimu_weighted = new TH1F("tpc2pullmu_antimu_weighted", "#mu^{+};TPC2 muon pull;Weighted entries", 50, -10.0, 40.0);
   TH1F *tpc2pullmu_piplus_weighted = new TH1F("tpc2pullmu_piplus_weighted", "#pi^{+}", 50, -10.0, 40.0);
   TH1F *tpc2pullmu_proton_weighted = new TH1F("tpc2pullmu_proton_weighted", "p", 50, -10.0, 40.0);
   TH1F *tpc2pullmu_positron_weighted = new TH1F("tpc2pullmu_positron_weighted", "e^{+}", 50, -10.0, 40.0);
   
   TH1F *tpc2pullpi_antimu_weighted = new TH1F("tpc2pullpi_antimu_weighted", "#mu^{+};TPC2 charged pion pull;Weighted entries", 50, -10.0, 40.0);
   TH1F *tpc2pullpi_piplus_weighted = new TH1F("tpc2pullpi_piplus_weighted", "#pi^{+}", 50, -10.0, 40.0);
   TH1F *tpc2pullpi_proton_weighted = new TH1F("tpc2pullpi_proton_weighted", "p", 50, -10.0, 40.0);
   TH1F *tpc2pullpi_positron_weighted = new TH1F("tpc2pullpi_positron_weighted", "e^{+}", 50, -10.0, 40.0);
   
   TH1F *tpc2pullp_antimu_weighted = new TH1F("tpc2pullp_antimu_weighted", "#mu^{+};TPC2 proton pull;Weighted entries", 50, -40.0, 20.0);
   TH1F *tpc2pullp_piplus_weighted = new TH1F("tpc2pullp_piplus_weighted", "#pi^{+}", 50, -40.0, 20.0);
   TH1F *tpc2pullp_proton_weighted = new TH1F("tpc2pullp_proton_weighted", "p", 50, -40.0, 20.0);
   TH1F *tpc2pullp_positron_weighted = new TH1F("tpc2pullp_positron_weighted", "e^{+}", 50, -40.0, 20.0);
   
   TH1F *tpc2pulle_antimu_weighted = new TH1F("tpc2pulle_antimu_weighted", "#mu^{+};TPC2 electron pull;Weighted entries", 50, -20.0, 30.0);
   TH1F *tpc2pulle_piplus_weighted = new TH1F("tpc2pulle_piplus_weighted", "#pi^{+}", 50, -20.0, 30.0);
   TH1F *tpc2pulle_proton_weighted = new TH1F("tpc2pulle_proton_weighted", "p", 50, -20.0, 30.0);
   TH1F *tpc2pulle_positron_weighted = new TH1F("tpc2pulle_positron_weighted", "e^{+}", 50, -20.0, 30.0);
   
   TH1F *tpc3pullmu_antimu_weighted = new TH1F("tpc3pullmu_antimu_weighted", "#mu^{+};TPC3 muon pull;Weighted entries", 50, -10.0, 30.0);
   TH1F *tpc3pullmu_piplus_weighted = new TH1F("tpc3pullmu_piplus_weighted", "#pi^{+}", 50, -10.0, 30.0);
   TH1F *tpc3pullmu_proton_weighted = new TH1F("tpc3pullmu_proton_weighted", "p", 50, -10.0, 30.0);
   TH1F *tpc3pullmu_positron_weighted = new TH1F("tpc3pullmu_positron_weighted", "e^{+}", 50, -10.0, 30.0);
   
   TH1F *tpc3pullpi_antimu_weighted = new TH1F("tpc3pullpi_antimu_weighted", "#mu^{+};TPC3 charged pion pull;Weighted entries", 50, -10.0, 40.0);
   TH1F *tpc3pullpi_piplus_weighted = new TH1F("tpc3pullpi_piplus_weighted", "#pi^{+}", 50, -10.0, 40.0);
   TH1F *tpc3pullpi_proton_weighted = new TH1F("tpc3pullpi_proton_weighted", "p", 50, -10.0, 40.0);
   TH1F *tpc3pullpi_positron_weighted = new TH1F("tpc3pullpi_positron_weighted", "e^{+}", 50, -10.0, 40.0);
   
   TH1F *tpc3pullp_antimu_weighted = new TH1F("tpc3pullp_antimu_weighted", "#mu^{+};TPC3 proton pull;Weighted entries", 50, -40.0, 20.0);
   TH1F *tpc3pullp_piplus_weighted = new TH1F("tpc3pullp_piplus_weighted", "#pi^{+}", 50, -40.0, 20.0);
   TH1F *tpc3pullp_proton_weighted = new TH1F("tpc3pullp_proton_weighted", "p", 50, -40.0, 20.0);
   TH1F *tpc3pullp_positron_weighted = new TH1F("tpc3pullp_positron_weighted", "e^{+}", 50, -40.0, 20.0);
   
   TH1F *tpc3pulle_antimu_weighted = new TH1F("tpc3pulle_antimu_weighted", "#mu^{+};TPC3 electron pull;Weighted entries", 50, -10.0, 20.0);
   TH1F *tpc3pulle_piplus_weighted = new TH1F("tpc3pulle_piplus_weighted", "#pi^{+}", 50, -10.0, 20.0);
   TH1F *tpc3pulle_proton_weighted = new TH1F("tpc3pulle_proton_weighted", "p", 50, -10.0, 20.0);
   TH1F *tpc3pulle_positron_weighted = new TH1F("tpc3pulle_positron_weighted", "e^{+}", 50, -10.0, 20.0);
   
   TH1F *tpc3pullmu_gq_antimu_weighted = new TH1F("tpc3pullmu_gq_antimu_weighted", "#mu^{+};TPC3 muon pull with quality check;Weighted entries", 50, -10.0, 30.0);
   TH1F *tpc3pullmu_gq_piplus_weighted = new TH1F("tpc3pullmu_gq_piplus_weighted", "#pi^{+}", 50, -10.0, 30.0);
   TH1F *tpc3pullmu_gq_proton_weighted = new TH1F("tpc3pullmu_gq_proton_weighted", "p", 50, -10.0, 30.0);
   TH1F *tpc3pullmu_gq_positron_weighted = new TH1F("tpc3pullmu_gq_positron_weighted", "e^{+}", 50, -10.0, 30.0);
   
   TH1F *tpc3pullpi_gq_antimu_weighted = new TH1F("tpc3pullpi_gq_antimu_weighted", "#mu^{+};TPC3 charged pion pull with quality check;Weighted entries", 50, -10.0, 40.0);
   TH1F *tpc3pullpi_gq_piplus_weighted = new TH1F("tpc3pullpi_gq_piplus_weighted", "#pi^{+}", 50, -10.0, 40.0);
   TH1F *tpc3pullpi_gq_proton_weighted = new TH1F("tpc3pullpi_gq_proton_weighted", "p", 50, -10.0, 40.0);
   TH1F *tpc3pullpi_gq_positron_weighted = new TH1F("tpc3pullpi_gq_positron_weighted", "e^{+}", 50, -10.0, 40.0);
   
   TH1F *tpc3pullp_gq_antimu_weighted = new TH1F("tpc3pullp_gq_antimu_weighted", "#mu^{+};TPC3 proton pull with quality check;Weighted entries", 50, -40.0, 20.0);
   TH1F *tpc3pullp_gq_piplus_weighted = new TH1F("tpc3pullp_gq_piplus_weighted", "#pi^{+}", 50, -40.0, 20.0);
   TH1F *tpc3pullp_gq_proton_weighted = new TH1F("tpc3pullp_gq_proton_weighted", "p", 50, -40.0, 20.0);
   TH1F *tpc3pullp_gq_positron_weighted = new TH1F("tpc3pullp_gq_positron_weighted", "e^{+}", 50, -40.0, 20.0);
   
   TH1F *tpc3pulle_gq_antimu_weighted = new TH1F("tpc3pulle_gq_antimu_weighted", "#mu^{+};TPC3 electron pull with quality check;Weighted entries", 50, -10.0, 20.0);
   TH1F *tpc3pulle_gq_piplus_weighted = new TH1F("tpc3pulle_gq_piplus_weighted", "#pi^{+}", 50, -10.0, 20.0);
   TH1F *tpc3pulle_gq_proton_weighted = new TH1F("tpc3pulle_gq_proton_weighted", "p", 50, -10.0, 20.0);
   TH1F *tpc3pulle_gq_positron_weighted = new TH1F("tpc3pulle_gq_positron_weighted", "e^{+}", 50, -10.0, 20.0);
   
   TH1F *ntpcs_antimu_weighted = new TH1F("ntpcs_antimu_weighted", "#mu^{+};Number of TPC segments;Weighted entries", 2, 0.5, 2.5);
   TH1F *ntpcs_piplus_weighted = new TH1F("ntpcs_piplus_weighted", "#pi^{+}", 2, 0.5, 2.5);
   TH1F *ntpcs_proton_weighted = new TH1F("ntpcs_proton_weighted", "p", 2, 0.5, 2.5);
   TH1F *ntpcs_positron_weighted = new TH1F("ntpcs_positron_weighted", "e^{+}", 2, 0.5, 2.5);
   
   TH1F *fgd1EbyL_antimu_weighted = new TH1F("fgd1EbyL_antimu_weighted", "#mu^{+};FGD1 energy/length (MeV/mm);Weighted entries", 50, 0.0, 1.0);
   TH1F *fgd1EbyL_piplus_weighted = new TH1F("fgd1EbyL_piplus_weighted", "#pi^{+}", 50, 0.0, 1.0);
   TH1F *fgd1EbyL_proton_weighted = new TH1F("fgd1EbyL_proton_weighted", "p", 50, 0.0, 1.0);
   TH1F *fgd1EbyL_positron_weighted = new TH1F("fgd1EbyL_positron_weighted", "e^{+}", 50, 0.0, 1.0);
   
   TH1F *fgd2EbyL_antimu_weighted = new TH1F("fgd2EbyL_antimu_weighted", "#mu^{+};FGD2 energy/length (MeV/mm);Weighted entries", 30, 0.0, 0.6);
   TH1F *fgd2EbyL_piplus_weighted = new TH1F("fgd2EbyL_piplus_weighted", "#pi^{+}", 30, 0.0, 0.6);
   TH1F *fgd2EbyL_proton_weighted = new TH1F("fgd2EbyL_proton_weighted", "p", 30, 0.0, 0.6);
   TH1F *fgd2EbyL_positron_weighted = new TH1F("fgd2EbyL_positron_weighted", "e^{+}", 30, 0.0, 0.6);
   
   TH1F *nsmrds_antimu_weighted = new TH1F("nsmrds_antimu_weighted", "#mu^{+};Number of SMRD segments;Weighted entries", 3, -0.5, 2.5);
   TH1F *nsmrds_piplus_weighted = new TH1F("nsmrds_piplus_weighted", "#pi^{+}", 3, -0.5, 2.5);
   TH1F *nsmrds_proton_weighted = new TH1F("nsmrds_proton_weighted", "p", 3, -0.5, 2.5);
   TH1F *nsmrds_positron_weighted = new TH1F("nsmrds_positron_weighted", "e^{+}", 3, -0.5, 2.5);
   
   
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
   
   Int_t musel_nAntimu_test1 = 0;
   Int_t pisel_nPiplus_test1 = 0;
   Int_t psel_nProton_test1 = 0;
   Int_t esel_nPositron_test1 = 0;
   
   Int_t musel_nAntimu_test2 = 0;
   Int_t pisel_nPiplus_test2 = 0;
   Int_t psel_nProton_test2 = 0;
   Int_t esel_nPositron_test2 = 0;
   
   Int_t musel_nAntimu_test3 = 0;
   Int_t pisel_nPiplus_test3 = 0;
   Int_t psel_nProton_test3 = 0;
   Int_t esel_nPositron_test3 = 0;
   
   Int_t musel_nAntimu_test4 = 0;
   Int_t pisel_nPiplus_test4 = 0;
   Int_t psel_nProton_test4 = 0;
   Int_t esel_nPositron_test4 = 0;
   
   Int_t musel_nAntimu_test5 = 0;
   Int_t pisel_nPiplus_test5 = 0;
   Int_t psel_nProton_test5 = 0;
   Int_t esel_nPositron_test5 = 0;
   
   TH1F *bdt_mulike_antimu = new TH1F("bdt_mulike_antimu", "#mu^{+};BDT #mu-like output;Entries", 20, 0.0, 1.0);
   TH1F *bdt_mulike_piplus = new TH1F("bdt_mulike_piplus", "#pi^{+}", 20, 0.0, 1.0);
   TH1F *bdt_mulike_proton = new TH1F("bdt_mulike_proton", "p", 20, 0.0, 1.0);
   TH1F *bdt_mulike_positron = new TH1F("bdt_mulike_positron", "e^{+}", 20, 0.0, 1.0);
   
   TH1F *bdt_pilike_antimu = new TH1F("bdt_pilike_antimu", "#mu^{+};BDT #pi-like output;Entries", 20, 0.0, 1.0);
   TH1F *bdt_pilike_piplus = new TH1F("bdt_pilike_piplus", "#pi^{+}", 20, 0.0, 1.0);
   TH1F *bdt_pilike_proton = new TH1F("bdt_pilike_proton", "p", 20, 0.0, 1.0);
   TH1F *bdt_pilike_positron = new TH1F("bdt_pilike_positron", "e^{+}", 20, 0.0, 1.0);
   
   TH1F *bdt_plike_antimu = new TH1F("bdt_plike_antimu", "#mu^{+};BDT proton-like output;Entries", 20, 0.0, 1.0);
   TH1F *bdt_plike_piplus = new TH1F("bdt_plike_piplus", "#pi^{+}", 20, 0.0, 1.0);
   TH1F *bdt_plike_proton = new TH1F("bdt_plike_proton", "p", 20, 0.0, 1.0);
   TH1F *bdt_plike_positron = new TH1F("bdt_plike_positron", "e^{+}", 20, 0.0, 1.0);
   
   TH1F *bdt_elike_antimu = new TH1F("bdt_elike_antimu", "#mu^{+};BDT e-like output;Entries", 20, 0.0, 1.0);
   TH1F *bdt_elike_piplus = new TH1F("bdt_elike_piplus", "#pi^{+}", 20, 0.0, 1.0);
   TH1F *bdt_elike_proton = new TH1F("bdt_elike_proton", "p", 20, 0.0, 1.0);
   TH1F *bdt_elike_positron = new TH1F("bdt_elike_positron", "e^{+}", 20, 0.0, 1.0);
   
   Int_t optimisation_nbins = 50;
   
   TH1F *opt_mulike_sig = new TH1F("opt_mulike_sig", "Mu-like (true antimu)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_mulike_bkg = new TH1F("opt_mulike_bkg", "Mu-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   
   TH1F *opt_pilike_sig = new TH1F("opt_pilike_sig", "Pi-like (true pi+)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_pilike_bkg = new TH1F("opt_pilike_bkg", "Pi-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   
   TH1F *opt_plike_sig = new TH1F("opt_plike_sig", "Proton-like (true protons)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_plike_bkg = new TH1F("opt_plike_bkg", "Proton-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   
   TH1F *opt_elike_sig = new TH1F("opt_elike_sig", "Electron-like (true positrons)", optimisation_nbins, 0.0, 1.0);
   TH1F *opt_elike_bkg = new TH1F("opt_elike_bkg", "Electron-like (backgrounds)", optimisation_nbins, 0.0, 1.0);

   
   
   TH1F *tpc_mulike_sig = new TH1F("tpc_mulike_sig", "Mu-like (true antimu)", optimisation_nbins, 0.0, 1.0);
   TH1F *tpc_mulike_bkg = new TH1F("tpc_mulike_bkg", "Mu-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   
   TH1F *tpc_pilike_sig = new TH1F("tpc_pilike_sig", "Pi-like (true pi+)", optimisation_nbins, 0.0, 1.0);
   TH1F *tpc_pilike_bkg = new TH1F("tpc_pilike_bkg", "Pi-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   
   TH1F *tpc_plike_sig = new TH1F("tpc_plike_sig", "Proton-like (true protons)", optimisation_nbins, 0.0, 1.0);
   TH1F *tpc_plike_bkg = new TH1F("tpc_plike_bkg", "Proton-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   
   TH1F *tpc_elike_sig = new TH1F("tpc_elike_sig", "Electron-like (true positrons)", optimisation_nbins, 0.0, 1.0);
   TH1F *tpc_elike_bkg = new TH1F("tpc_elike_bkg", "Electron-like (backgrounds)", optimisation_nbins, 0.0, 1.0);
   
   
   
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
   
   Int_t antinumu_primary_pid_sig = 0;
   Int_t antinumu_primary_pid_bkg = 0;
   Int_t antinumu_improved_pid_sig = 0;
   Int_t antinumu_improved_pid_bkg = 0;
   Int_t antinumu_pion_pid_sig = 0;
   Int_t antinumu_pion_pid_bkg = 0;
   Int_t antinumu_improved_pion_pid_sig = 0;
   Int_t antinumu_improved_pion_pid_bkg = 0;
   Int_t antinue_primary_pid_sig = 0;
   Int_t antinue_primary_pid_bkg = 0;
   
   TGraph* ks_test_bdt_mulike_pilike_train = new TGraph();
   ks_test_bdt_mulike_pilike_train->SetTitle("BDT mu-like and pi-like outputs for KS (training sample appropriate cuts)");
   TGraph* ks_test_bdt_plike_elike_train = new TGraph();
   ks_test_bdt_plike_elike_train->SetTitle("BDT p-like and e-like outputs for KS (training sample appropriate cuts)");
   
   TGraph* ks_test_bdt_mulike_pilike_test = new TGraph();
   ks_test_bdt_mulike_pilike_test->SetTitle("BDT mu-like and pi-like outputs for KS (testing sample appropriate cuts)");
   TGraph* ks_test_bdt_plike_elike_test = new TGraph();
   ks_test_bdt_plike_elike_test->SetTitle("BDT p-like and e-like outputs for KS (testing sample appropriate cuts)");

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
   
   // ============= Prepare momentum weighting histogram =============
   
   TH1F *weighting_hist_antimu = new TH1F("weighting_hist_antimu", "Reco momentum for weighting", 150, 0, 1500);
   TH1F *weighting_hist_piplus = new TH1F("weighting_hist_piplus", "Reco momentum for weighting", 150, 0, 1500);
   TH1F *weighting_hist_proton = new TH1F("weighting_hist_proton", "Reco momentum for weighting", 150, 0, 1500);
   TH1F *weighting_hist_positron = new TH1F("weighting_hist_positron", "Reco momentum for weighting", 150, 0, 1500);
   
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
   
        fChain->GetEntry(jentry);

        // Cut on accum_level etc. N.B. make sure these cuts are the same as below
        if (accum_level[0][1] <= 4) continue; // Set accum_level
        if (selmu_mom[0] > 1500.0) continue;
        if (selmu_mom[0] < 200.0) continue;
        if ((particle == 2212) && (selmu_mom[0] < 300.0)) continue;
        if (selmu_det_theta > 1.0472) continue;
        if (selmu_necals > 1) continue;
        
        if ((particle == -13)&&(particle_pg == -13)) weighting_hist_antimu->Fill(selmu_mom[0]);
        if ((particle == 211)&&(particle_pg == 211)) weighting_hist_piplus->Fill(selmu_mom[0]);
        if ((particle == 2212)&&(particle_pg == 2212)) weighting_hist_proton->Fill(selmu_mom[0]);
        if ((particle == -11)&&(particle_pg == -11)) weighting_hist_positron->Fill(selmu_mom[0]);

    }
   
   
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      fChain->GetEntry(jentry);

      // Cut on accum_level etc
      if (accum_level[0][1] <= 4) continue; // Set accum_level
      
      
      // ============= Fill histograms for input variable plotting =============
      
      if ((accum_level[0][1] > 4) && (selmu_necals < 2)){
         
         if ((particle == -13)&&(particle_pg == -13))
         {
            recomom_antimu2->Fill(selmu_mom[0]);
            truemom_antimu2->Fill(selmu_truemom);
         }
         if ((particle == 211)&&(particle_pg == 211))
         {
            recomom_piplus2->Fill(selmu_mom[0]);
            truemom_piplus2->Fill(selmu_truemom);
         }
         if ((particle == 2212)&&(particle_pg == 2212))
         {
            recomom_proton2->Fill(selmu_mom[0]);
            truemom_proton2->Fill(selmu_truemom);
         }
         if ((particle == -11)&&(particle_pg == -11))
         {
            recomom_positron2->Fill(selmu_mom[0]);
            truemom_positron2->Fill(selmu_truemom);
         }
      }
      
      if ((accum_level[0][1] > 4) && (selmu_necals < 2) && (selmu_mom[0] > 200.0) && (selmu_mom[0] < 1500.0) && (selmu_det_theta < 1.0472)){
         
         if ((particle == -13)&&(particle_pg == -13))
         {
            ks_test_bdt_mulike_pilike_train->AddPoint(selmu_bdt_pid_mu, selmu_bdt_pid_pi);
            ks_test_bdt_plike_elike_train->AddPoint(selmu_bdt_pid_p, selmu_bdt_pid_e);
            
            // Calculate event weight based on reco mom histogram:
            Int_t weight_bin = floor(selmu_mom[0]/10) + 1;
            Float_t inv_weight = weighting_hist_antimu->GetBinContent(weight_bin);
            Float_t weight;
            if (inv_weight > 0) {weight = 1/inv_weight;}
            else                {weight = 0;}
            
            recomom_antimu->Fill(selmu_mom[0]);
            truemom_antimu->Fill(selmu_truemom);
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
            if (selmu_tpc_nnodes[1]>18)
            {
               tpc3dedx_gq_antimu->Fill(selmu_tpc_dedx[1]);
               tpc3pullmu_gq_antimu->Fill(selmu_tpc_pullmu[1]);
               tpc3pullpi_gq_antimu->Fill(selmu_tpc_pullpi[1]);
               tpc3pullp_gq_antimu->Fill(selmu_tpc_pullp[1]);
               tpc3pulle_gq_antimu->Fill(selmu_tpc_pullele[1]);
            }
            
            recomom_antimu_weighted->Fill(selmu_mom[0], weight);
            theta_antimu_weighted->Fill(selmu_det_theta, weight);
            EMEnergy_antimu_weighted->Fill(selmu_ecal_bestseg_EMenergy, weight);
            EbyL_antimu_weighted->Fill(selmu_ecal_bestseg_EbyL, weight);
            circularity_antimu_weighted->Fill(selmu_ecal_circularity, weight);
            fbr_antimu_weighted->Fill(selmu_ecal_fbr, weight);
            tmr_antimu_weighted->Fill(selmu_ecal_tmr, weight);
            qrms_antimu_weighted->Fill(selmu_ecal_qrms, weight);
            mipem_antimu_weighted->Fill(selmu_ecal_mipem[0], weight);
            emhip_antimu_weighted->Fill(selmu_ecal_emhip[0], weight);
            mippion_antimu_weighted->Fill(selmu_ecal_mippion[0], weight);
            tpc2dedx_antimu_weighted->Fill(selmu_tpc_dedx[0], weight);
            tpc3dedx_antimu_weighted->Fill(selmu_tpc_dedx[1], weight);
            tpclikemu_antimu_weighted->Fill(selmu_tpc_like_mu, weight);
            tpclikepi_antimu_weighted->Fill(selmu_tpc_like_pi, weight);
            tpclikep_antimu_weighted->Fill(selmu_tpc_like_p, weight);
            tpclikee_antimu_weighted->Fill(selmu_tpc_like_e, weight);
            tpc2pullmu_antimu_weighted->Fill(selmu_tpc_pullmu[0], weight);
            tpc2pullpi_antimu_weighted->Fill(selmu_tpc_pullpi[0], weight);
            tpc2pullp_antimu_weighted->Fill(selmu_tpc_pullp[0], weight);
            tpc2pulle_antimu_weighted->Fill(selmu_tpc_pullele[0], weight);
            tpc3pullmu_antimu_weighted->Fill(selmu_tpc_pullmu[1], weight);
            tpc3pullpi_antimu_weighted->Fill(selmu_tpc_pullpi[1], weight);
            tpc3pullp_antimu_weighted->Fill(selmu_tpc_pullp[1], weight);
            tpc3pulle_antimu_weighted->Fill(selmu_tpc_pullele[1], weight);
            ntpcs_antimu_weighted->Fill(selmu_ntpcs, weight);
            fgd1EbyL_antimu_weighted->Fill(selmu_fgd1_EbyL, weight);
            fgd2EbyL_antimu_weighted->Fill(selmu_fgd2_EbyL, weight);
            nsmrds_antimu_weighted->Fill(selmu_nsmrds, weight);
            if (selmu_tpc_nnodes[1]>18)
            {
               tpc3dedx_gq_antimu_weighted->Fill(selmu_tpc_dedx[1], weight);
               tpc3pullmu_gq_antimu_weighted->Fill(selmu_tpc_pullmu[1], weight);
               tpc3pullpi_gq_antimu_weighted->Fill(selmu_tpc_pullpi[1], weight);
               tpc3pullp_gq_antimu_weighted->Fill(selmu_tpc_pullp[1], weight);
               tpc3pulle_gq_antimu_weighted->Fill(selmu_tpc_pullele[1], weight);
            }
            
         }
         else if ((particle == 211)&&(particle_pg == 211))
         {
            ks_test_bdt_mulike_pilike_train->AddPoint(selmu_bdt_pid_mu, selmu_bdt_pid_pi);
            ks_test_bdt_plike_elike_train->AddPoint(selmu_bdt_pid_p, selmu_bdt_pid_e);
            
            // Calculate event weight based on reco mom histogram:
            Int_t weight_bin = floor(selmu_mom[0]/10) + 1;
            Float_t inv_weight = weighting_hist_piplus->GetBinContent(weight_bin);
            Float_t weight;
            if (inv_weight > 0) {weight = 1/inv_weight;}
            else                {weight = 0;}
            
            recomom_piplus->Fill(selmu_mom[0]);
            truemom_piplus->Fill(selmu_truemom);
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
            if (selmu_tpc_nnodes[1]>18)
            {
               tpc3dedx_gq_piplus->Fill(selmu_tpc_dedx[1]);
               tpc3pullmu_gq_piplus->Fill(selmu_tpc_pullmu[1]);
               tpc3pullpi_gq_piplus->Fill(selmu_tpc_pullpi[1]);
               tpc3pullp_gq_piplus->Fill(selmu_tpc_pullp[1]);
               tpc3pulle_gq_piplus->Fill(selmu_tpc_pullele[1]);
            }
            
            recomom_piplus_weighted->Fill(selmu_mom[0], weight);
            theta_piplus_weighted->Fill(selmu_det_theta, weight);
            EMEnergy_piplus_weighted->Fill(selmu_ecal_bestseg_EMenergy, weight);
            EbyL_piplus_weighted->Fill(selmu_ecal_bestseg_EbyL, weight);
            circularity_piplus_weighted->Fill(selmu_ecal_circularity, weight);
            fbr_piplus_weighted->Fill(selmu_ecal_fbr, weight);
            tmr_piplus_weighted->Fill(selmu_ecal_tmr, weight);
            qrms_piplus_weighted->Fill(selmu_ecal_qrms, weight);
            mipem_piplus_weighted->Fill(selmu_ecal_mipem[0], weight);
            emhip_piplus_weighted->Fill(selmu_ecal_emhip[0], weight);
            mippion_piplus_weighted->Fill(selmu_ecal_mippion[0], weight);
            tpc2dedx_piplus_weighted->Fill(selmu_tpc_dedx[0], weight);
            tpc3dedx_piplus_weighted->Fill(selmu_tpc_dedx[1], weight);
            tpclikemu_piplus_weighted->Fill(selmu_tpc_like_mu, weight);
            tpclikepi_piplus_weighted->Fill(selmu_tpc_like_pi, weight);
            tpclikep_piplus_weighted->Fill(selmu_tpc_like_p, weight);
            tpclikee_piplus_weighted->Fill(selmu_tpc_like_e, weight);
            tpc2pullmu_piplus_weighted->Fill(selmu_tpc_pullmu[0], weight);
            tpc2pullpi_piplus_weighted->Fill(selmu_tpc_pullpi[0], weight);
            tpc2pullp_piplus_weighted->Fill(selmu_tpc_pullp[0], weight);
            tpc2pulle_piplus_weighted->Fill(selmu_tpc_pullele[0], weight);
            tpc3pullmu_piplus_weighted->Fill(selmu_tpc_pullmu[1], weight);
            tpc3pullpi_piplus_weighted->Fill(selmu_tpc_pullpi[1], weight);
            tpc3pullp_piplus_weighted->Fill(selmu_tpc_pullp[1], weight);
            tpc3pulle_piplus_weighted->Fill(selmu_tpc_pullele[1], weight);
            ntpcs_piplus_weighted->Fill(selmu_ntpcs, weight);
            fgd1EbyL_piplus_weighted->Fill(selmu_fgd1_EbyL, weight);
            fgd2EbyL_piplus_weighted->Fill(selmu_fgd2_EbyL, weight);
            nsmrds_piplus_weighted->Fill(selmu_nsmrds, weight);
            if (selmu_tpc_nnodes[1]>18)
            {
               tpc3dedx_gq_piplus_weighted->Fill(selmu_tpc_dedx[1], weight);
               tpc3pullmu_gq_piplus_weighted->Fill(selmu_tpc_pullmu[1], weight);
               tpc3pullpi_gq_piplus_weighted->Fill(selmu_tpc_pullpi[1], weight);
               tpc3pullp_gq_piplus_weighted->Fill(selmu_tpc_pullp[1], weight);
               tpc3pulle_gq_piplus_weighted->Fill(selmu_tpc_pullele[1], weight);
            }
         }
         else if ((particle == 2212)&&(particle_pg == 2212)&&(selmu_mom[0] > 600.0))
         {
            ks_test_bdt_mulike_pilike_train->AddPoint(selmu_bdt_pid_mu, selmu_bdt_pid_pi);
            ks_test_bdt_plike_elike_train->AddPoint(selmu_bdt_pid_p, selmu_bdt_pid_e);
            
            // Calculate event weight based on reco mom histogram:
            Int_t weight_bin = floor(selmu_mom[0]/10) + 1;
            Float_t inv_weight = weighting_hist_proton->GetBinContent(weight_bin);
            Float_t weight;
            if (inv_weight > 0) {weight = 1/inv_weight;}
            else                {weight = 0;}
            
            recomom_proton->Fill(selmu_mom[0]);
            truemom_proton->Fill(selmu_truemom);
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
            if (selmu_tpc_nnodes[1]>18)
            {
               tpc3dedx_gq_proton->Fill(selmu_tpc_dedx[1]);
               tpc3pullmu_gq_proton->Fill(selmu_tpc_pullmu[1]);
               tpc3pullpi_gq_proton->Fill(selmu_tpc_pullpi[1]);
               tpc3pullp_gq_proton->Fill(selmu_tpc_pullp[1]);
               tpc3pulle_gq_proton->Fill(selmu_tpc_pullele[1]);
            }
            
            recomom_proton_weighted->Fill(selmu_mom[0], weight*1.08333);
            theta_proton_weighted->Fill(selmu_det_theta, weight*1.08333);
            EMEnergy_proton_weighted->Fill(selmu_ecal_bestseg_EMenergy, weight*1.08333);
            EbyL_proton_weighted->Fill(selmu_ecal_bestseg_EbyL, weight*1.08333);
            circularity_proton_weighted->Fill(selmu_ecal_circularity, weight*1.08333);
            fbr_proton_weighted->Fill(selmu_ecal_fbr, weight*1.08333);
            tmr_proton_weighted->Fill(selmu_ecal_tmr, weight*1.08333);
            qrms_proton_weighted->Fill(selmu_ecal_qrms, weight);
            mipem_proton_weighted->Fill(selmu_ecal_mipem[0], weight*1.08333);
            emhip_proton_weighted->Fill(selmu_ecal_emhip[0], weight*1.08333);
            mippion_proton_weighted->Fill(selmu_ecal_mippion[0], weight*1.08333);
            tpc2dedx_proton_weighted->Fill(selmu_tpc_dedx[0], weight*1.08333);
            tpc3dedx_proton_weighted->Fill(selmu_tpc_dedx[1], weight*1.08333);
            tpclikemu_proton_weighted->Fill(selmu_tpc_like_mu, weight*1.08333);
            tpclikepi_proton_weighted->Fill(selmu_tpc_like_pi, weight*1.08333);
            tpclikep_proton_weighted->Fill(selmu_tpc_like_p, weight*1.08333);
            tpclikee_proton_weighted->Fill(selmu_tpc_like_e, weight*1.08333);
            tpc2pullmu_proton_weighted->Fill(selmu_tpc_pullmu[0], weight*1.08333);
            tpc2pullpi_proton_weighted->Fill(selmu_tpc_pullpi[0], weight*1.08333);
            tpc2pullp_proton_weighted->Fill(selmu_tpc_pullp[0], weight*1.08333);
            tpc2pulle_proton_weighted->Fill(selmu_tpc_pullele[0], weight*1.08333);
            tpc3pullmu_proton_weighted->Fill(selmu_tpc_pullmu[1], weight*1.08333);
            tpc3pullpi_proton_weighted->Fill(selmu_tpc_pullpi[1], weight*1.08333);
            tpc3pullp_proton_weighted->Fill(selmu_tpc_pullp[1], weight*1.08333);
            tpc3pulle_proton_weighted->Fill(selmu_tpc_pullele[1], weight*1.08333);
            ntpcs_proton_weighted->Fill(selmu_ntpcs, weight*1.08333);
            fgd1EbyL_proton_weighted->Fill(selmu_fgd1_EbyL, weight*1.08333);
            fgd2EbyL_proton_weighted->Fill(selmu_fgd2_EbyL, weight*1.08333);
            nsmrds_proton_weighted->Fill(selmu_nsmrds, weight*1.08333);
            if (selmu_tpc_nnodes[1]>18)
            {
               tpc3dedx_gq_proton_weighted->Fill(selmu_tpc_dedx[1], weight*1.08333);
               tpc3pullmu_gq_proton_weighted->Fill(selmu_tpc_pullmu[1], weight*1.08333);
               tpc3pullpi_gq_proton_weighted->Fill(selmu_tpc_pullpi[1], weight*1.08333);
               tpc3pullp_gq_proton_weighted->Fill(selmu_tpc_pullp[1], weight*1.08333);
               tpc3pulle_gq_proton_weighted->Fill(selmu_tpc_pullele[1], weight*1.08333);
            }
         }
         else if ((particle == -11)&&(particle_pg == -11))
         {
            ks_test_bdt_mulike_pilike_train->AddPoint(selmu_bdt_pid_mu, selmu_bdt_pid_pi);
            ks_test_bdt_plike_elike_train->AddPoint(selmu_bdt_pid_p, selmu_bdt_pid_e);
            
            Int_t weight_bin = floor(selmu_mom[0]/10) + 1;
            Float_t inv_weight = weighting_hist_positron->GetBinContent(weight_bin);
            Float_t weight;
            if (inv_weight > 0) {weight = 1/inv_weight;}
            else                {weight = 0;}
            
            recomom_positron->Fill(selmu_mom[0]);
            truemom_positron->Fill(selmu_truemom);
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
            if (selmu_tpc_nnodes[1]>18)
            {
               tpc3dedx_gq_positron->Fill(selmu_tpc_dedx[1]);
               tpc3pullmu_gq_positron->Fill(selmu_tpc_pullmu[1]);
               tpc3pullpi_gq_positron->Fill(selmu_tpc_pullpi[1]);
               tpc3pullp_gq_positron->Fill(selmu_tpc_pullp[1]);
               tpc3pulle_gq_positron->Fill(selmu_tpc_pullele[1]);
            }
            
            recomom_positron_weighted->Fill(selmu_mom[0], weight);
            theta_positron_weighted->Fill(selmu_det_theta, weight);
            EMEnergy_positron_weighted->Fill(selmu_ecal_bestseg_EMenergy, weight);
            EbyL_positron_weighted->Fill(selmu_ecal_bestseg_EbyL, weight);
            circularity_positron_weighted->Fill(selmu_ecal_circularity, weight);
            fbr_positron_weighted->Fill(selmu_ecal_fbr, weight);
            tmr_positron_weighted->Fill(selmu_ecal_tmr, weight);
            qrms_positron_weighted->Fill(selmu_ecal_qrms, weight);
            mipem_positron_weighted->Fill(selmu_ecal_mipem[0], weight);
            emhip_positron_weighted->Fill(selmu_ecal_emhip[0], weight);
            mippion_positron_weighted->Fill(selmu_ecal_mippion[0], weight);
            tpc2dedx_positron_weighted->Fill(selmu_tpc_dedx[0], weight);
            tpc3dedx_positron_weighted->Fill(selmu_tpc_dedx[1], weight);
            tpclikemu_positron_weighted->Fill(selmu_tpc_like_mu, weight);
            tpclikepi_positron_weighted->Fill(selmu_tpc_like_pi, weight);
            tpclikep_positron_weighted->Fill(selmu_tpc_like_p, weight);
            tpclikee_positron_weighted->Fill(selmu_tpc_like_e, weight);
            tpc2pullmu_positron_weighted->Fill(selmu_tpc_pullmu[0], weight);
            tpc2pullpi_positron_weighted->Fill(selmu_tpc_pullpi[0], weight);
            tpc2pullp_positron_weighted->Fill(selmu_tpc_pullp[0], weight);
            tpc2pulle_positron_weighted->Fill(selmu_tpc_pullele[0], weight);
            tpc3pullmu_positron_weighted->Fill(selmu_tpc_pullmu[1], weight);
            tpc3pullpi_positron_weighted->Fill(selmu_tpc_pullpi[1], weight);
            tpc3pullp_positron_weighted->Fill(selmu_tpc_pullp[1], weight);
            tpc3pulle_positron_weighted->Fill(selmu_tpc_pullele[1], weight);
            ntpcs_positron_weighted->Fill(selmu_ntpcs, weight);
            fgd1EbyL_positron_weighted->Fill(selmu_fgd1_EbyL, weight);
            fgd2EbyL_positron_weighted->Fill(selmu_fgd2_EbyL, weight);
            nsmrds_positron_weighted->Fill(selmu_nsmrds, weight);
            if (selmu_tpc_nnodes[1]>18)
            {
               tpc3dedx_gq_positron_weighted->Fill(selmu_tpc_dedx[1], weight);
               tpc3pullmu_gq_positron_weighted->Fill(selmu_tpc_pullmu[1], weight);
               tpc3pullpi_gq_positron_weighted->Fill(selmu_tpc_pullpi[1], weight);
               tpc3pullp_gq_positron_weighted->Fill(selmu_tpc_pullp[1], weight);
               tpc3pulle_gq_positron_weighted->Fill(selmu_tpc_pullele[1], weight);
            }
         }
      }
      
      
      // ============= Fill histograms to find optimal cuts =============
      
      if ((accum_level[0][1] > 4) && (selmu_necals < 2) && (selmu_mom[0] > 200.0) && (selmu_mom[0] < 1500.0) && (selmu_det_theta < 1.0472)){ 
         
         if ((particle == -13)&&(particle_pg == -13))
         {
            ks_test_bdt_mulike_pilike_test->AddPoint(selmu_bdt_pid_mu, selmu_bdt_pid_pi);
            ks_test_bdt_plike_elike_test->AddPoint(selmu_bdt_pid_p, selmu_bdt_pid_e);
            
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
            
            bdt_mulike_antimu->Fill(selmu_bdt_pid_mu);
            bdt_pilike_antimu->Fill(selmu_bdt_pid_pi);
            bdt_plike_antimu->Fill(selmu_bdt_pid_p);
            bdt_elike_antimu->Fill(selmu_bdt_pid_e);
            
            tpc_mulike_sig->Fill(selmu_tpc_like_mu);
            tpc_pilike_bkg->Fill(selmu_tpc_like_pi);
            tpc_plike_bkg->Fill(selmu_tpc_like_p);
            tpc_elike_bkg->Fill(selmu_tpc_like_e);
         }
         else if ((particle == 211)&&(particle_pg == 211))
         {
            ks_test_bdt_mulike_pilike_test->AddPoint(selmu_bdt_pid_mu, selmu_bdt_pid_pi);
            ks_test_bdt_plike_elike_test->AddPoint(selmu_bdt_pid_p, selmu_bdt_pid_e);
            
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
            
            bdt_mulike_piplus->Fill(selmu_bdt_pid_mu);
            bdt_pilike_piplus->Fill(selmu_bdt_pid_pi);
            bdt_plike_piplus->Fill(selmu_bdt_pid_p);
            bdt_elike_piplus->Fill(selmu_bdt_pid_e);
            
            tpc_mulike_bkg->Fill(selmu_tpc_like_mu);
            tpc_pilike_sig->Fill(selmu_tpc_like_pi);
            tpc_plike_bkg->Fill(selmu_tpc_like_p);
            tpc_elike_bkg->Fill(selmu_tpc_like_e);
         }
         else if ((particle == 2212)&&(particle_pg == 2212))
         {
            ks_test_bdt_mulike_pilike_test->AddPoint(selmu_bdt_pid_mu, selmu_bdt_pid_pi);
            ks_test_bdt_plike_elike_test->AddPoint(selmu_bdt_pid_p, selmu_bdt_pid_e);
            
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

            bdt_mulike_proton->Fill(selmu_bdt_pid_mu);
            bdt_pilike_proton->Fill(selmu_bdt_pid_pi);
            bdt_plike_proton->Fill(selmu_bdt_pid_p);
            bdt_elike_proton->Fill(selmu_bdt_pid_e);
            
            tpc_mulike_bkg->Fill(selmu_tpc_like_mu);
            tpc_pilike_bkg->Fill(selmu_tpc_like_pi);
            tpc_plike_sig->Fill(selmu_tpc_like_p);
            tpc_elike_bkg->Fill(selmu_tpc_like_e);
         }
         else if ((particle == -11)&&(particle_pg == -11))
         {
            ks_test_bdt_mulike_pilike_test->AddPoint(selmu_bdt_pid_mu, selmu_bdt_pid_pi);
            ks_test_bdt_plike_elike_test->AddPoint(selmu_bdt_pid_p, selmu_bdt_pid_e);
            
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
            
            bdt_mulike_positron->Fill(selmu_bdt_pid_mu);
            bdt_pilike_positron->Fill(selmu_bdt_pid_pi);
            bdt_plike_positron->Fill(selmu_bdt_pid_p);
            bdt_elike_positron->Fill(selmu_bdt_pid_e);
            
            tpc_mulike_bkg->Fill(selmu_tpc_like_mu);
            tpc_pilike_bkg->Fill(selmu_tpc_like_pi);
            tpc_plike_bkg->Fill(selmu_tpc_like_p);
            tpc_elike_sig->Fill(selmu_tpc_like_e);
         }
         
         // Fill counters for new performance testing
         
         if ((selmu_bdt_pid_mu > selmu_bdt_pid_pi) && (selmu_bdt_pid_mu > selmu_bdt_pid_p) && (selmu_bdt_pid_mu > selmu_bdt_pid_e))
         {
            if ((particle == -13)&&(particle_pg == -13)) musel_nAntimu++;
            if ((particle == 211)&&(particle_pg == 211)) musel_nPiplus++;
            if ((particle == 2212)&&(particle_pg == 2212)) musel_nProton++;
            if ((particle == -11)&&(particle_pg == -11)) musel_nPositron++;
         }
         
         if ((selmu_bdt_pid_pi > selmu_bdt_pid_mu) && (selmu_bdt_pid_pi > selmu_bdt_pid_p) && (selmu_bdt_pid_pi > selmu_bdt_pid_e))
         {
            if ((particle == -13)&&(particle_pg == -13)) pisel_nAntimu++;
            if ((particle == 211)&&(particle_pg == 211)) pisel_nPiplus++;
            if ((particle == 2212)&&(particle_pg == 2212)) pisel_nProton++;
            if ((particle == -11)&&(particle_pg == -11)) pisel_nPositron++;
         }
         
         if ((selmu_bdt_pid_p > selmu_bdt_pid_mu) && (selmu_bdt_pid_p > selmu_bdt_pid_pi) && (selmu_bdt_pid_p > selmu_bdt_pid_e))
         {
            if ((particle == -13)&&(particle_pg == -13)) psel_nAntimu++;
            if ((particle == 211)&&(particle_pg == 211)) psel_nPiplus++;
            if ((particle == 2212)&&(particle_pg == 2212)) psel_nProton++;
            if ((particle == -11)&&(particle_pg == -11)) psel_nPositron++;
         }
         
         if ((selmu_bdt_pid_e > selmu_bdt_pid_mu) && (selmu_bdt_pid_e > selmu_bdt_pid_pi) && (selmu_bdt_pid_e > selmu_bdt_pid_p))
         {
            if ((particle == -13)&&(particle_pg == -13)) esel_nAntimu++;
            if ((particle == 211)&&(particle_pg == 211)) esel_nPiplus++;
            if ((particle == 2212)&&(particle_pg == 2212)) esel_nProton++;
            if ((particle == -11)&&(particle_pg == -11)) esel_nPositron++;
         }
         
         
         if ((selmu_bdt_pid_mu_test1 > selmu_bdt_pid_pi_test1) && (selmu_bdt_pid_mu_test1 > selmu_bdt_pid_p_test1) && (selmu_bdt_pid_mu_test1 > selmu_bdt_pid_e_test1) && (particle == -13)&&(particle_pg == -13)) musel_nAntimu_test1++;
         if ((selmu_bdt_pid_pi_test1 > selmu_bdt_pid_mu_test1) && (selmu_bdt_pid_pi_test1 > selmu_bdt_pid_p_test1) && (selmu_bdt_pid_pi_test1 > selmu_bdt_pid_e_test1) && (particle == 211)&&(particle_pg == 211)) pisel_nPiplus_test1++;
         if ((selmu_bdt_pid_p_test1 > selmu_bdt_pid_mu_test1) && (selmu_bdt_pid_p_test1 > selmu_bdt_pid_pi_test1) && (selmu_bdt_pid_p_test1 > selmu_bdt_pid_e_test1) && (particle == 2212)&&(particle_pg == 2212)) psel_nProton_test1++;
         if ((selmu_bdt_pid_e_test1 > selmu_bdt_pid_mu_test1) && (selmu_bdt_pid_e_test1 > selmu_bdt_pid_pi_test1) && (selmu_bdt_pid_e_test1 > selmu_bdt_pid_p_test1) && (particle == -11)&&(particle_pg == -11)) esel_nPositron_test1++;
                
         if ((selmu_bdt_pid_mu_test2 > selmu_bdt_pid_pi_test2) && (selmu_bdt_pid_mu_test2 > selmu_bdt_pid_p_test2) && (selmu_bdt_pid_mu_test2 > selmu_bdt_pid_e_test2) && (particle == -13)&&(particle_pg == -13)) musel_nAntimu_test2++;
         if ((selmu_bdt_pid_pi_test2 > selmu_bdt_pid_mu_test2) && (selmu_bdt_pid_pi_test2 > selmu_bdt_pid_p_test2) && (selmu_bdt_pid_pi_test2 > selmu_bdt_pid_e_test2) && (particle == 211)&&(particle_pg == 211)) pisel_nPiplus_test2++;
         if ((selmu_bdt_pid_p_test2 > selmu_bdt_pid_mu_test2) && (selmu_bdt_pid_p_test2 > selmu_bdt_pid_pi_test2) && (selmu_bdt_pid_p_test2 > selmu_bdt_pid_e_test2) && (particle == 2212)&&(particle_pg == 2212)) psel_nProton_test2++;
         if ((selmu_bdt_pid_e_test2 > selmu_bdt_pid_mu_test2) && (selmu_bdt_pid_e_test2 > selmu_bdt_pid_pi_test2) && (selmu_bdt_pid_e_test2 > selmu_bdt_pid_p_test2) && (particle == -11)&&(particle_pg == -11)) esel_nPositron_test2++;
         
         if ((selmu_bdt_pid_mu_test3 > selmu_bdt_pid_pi_test3) && (selmu_bdt_pid_mu_test3 > selmu_bdt_pid_p_test3) && (selmu_bdt_pid_mu_test3 > selmu_bdt_pid_e_test3) && (particle == -13)&&(particle_pg == -13)) musel_nAntimu_test3++;
         if ((selmu_bdt_pid_pi_test3 > selmu_bdt_pid_mu_test3) && (selmu_bdt_pid_pi_test3 > selmu_bdt_pid_p_test3) && (selmu_bdt_pid_pi_test3 > selmu_bdt_pid_e_test3) && (particle == 211)&&(particle_pg == 211)) pisel_nPiplus_test3++;
         if ((selmu_bdt_pid_p_test3 > selmu_bdt_pid_mu_test3) && (selmu_bdt_pid_p_test3 > selmu_bdt_pid_pi_test3) && (selmu_bdt_pid_p_test3 > selmu_bdt_pid_e_test3) && (particle == 2212)&&(particle_pg == 2212)) psel_nProton_test3++;
         if ((selmu_bdt_pid_e_test3 > selmu_bdt_pid_mu_test3) && (selmu_bdt_pid_e_test3 > selmu_bdt_pid_pi_test3) && (selmu_bdt_pid_e_test3 > selmu_bdt_pid_p_test3) && (particle == -11)&&(particle_pg == -11)) esel_nPositron_test3++;
         
         if ((selmu_bdt_pid_mu_test4 > selmu_bdt_pid_pi_test4) && (selmu_bdt_pid_mu_test4 > selmu_bdt_pid_p_test4) && (selmu_bdt_pid_mu_test4 > selmu_bdt_pid_e_test4) && (particle == -13)&&(particle_pg == -13)) musel_nAntimu_test4++;
         if ((selmu_bdt_pid_pi_test4 > selmu_bdt_pid_mu_test4) && (selmu_bdt_pid_pi_test4 > selmu_bdt_pid_p_test4) && (selmu_bdt_pid_pi_test4 > selmu_bdt_pid_e_test4) && (particle == 211)&&(particle_pg == 211)) pisel_nPiplus_test4++;
         if ((selmu_bdt_pid_p_test4 > selmu_bdt_pid_mu_test4) && (selmu_bdt_pid_p_test4 > selmu_bdt_pid_pi_test4) && (selmu_bdt_pid_p_test4 > selmu_bdt_pid_e_test4) && (particle == 2212)&&(particle_pg == 2212)) psel_nProton_test4++;
         if ((selmu_bdt_pid_e_test4 > selmu_bdt_pid_mu_test4) && (selmu_bdt_pid_e_test4 > selmu_bdt_pid_pi_test4) && (selmu_bdt_pid_e_test4 > selmu_bdt_pid_p_test4) && (particle == -11)&&(particle_pg == -11)) esel_nPositron_test4++;
         
         if ((selmu_bdt_pid_mu_test5 > selmu_bdt_pid_pi_test5) && (selmu_bdt_pid_mu_test5 > selmu_bdt_pid_p_test5) && (selmu_bdt_pid_mu_test5 > selmu_bdt_pid_e_test5) && (particle == -13)&&(particle_pg == -13)) musel_nAntimu_test5++;
         if ((selmu_bdt_pid_pi_test5 > selmu_bdt_pid_mu_test5) && (selmu_bdt_pid_pi_test5 > selmu_bdt_pid_p_test5) && (selmu_bdt_pid_pi_test5 > selmu_bdt_pid_e_test5) && (particle == 211)&&(particle_pg == 211)) pisel_nPiplus_test5++;
         if ((selmu_bdt_pid_p_test5 > selmu_bdt_pid_mu_test5) && (selmu_bdt_pid_p_test5 > selmu_bdt_pid_pi_test5) && (selmu_bdt_pid_p_test5 > selmu_bdt_pid_e_test5) && (particle == 2212)&&(particle_pg == 2212)) psel_nProton_test5++;
         if ((selmu_bdt_pid_e_test5 > selmu_bdt_pid_mu_test5) && (selmu_bdt_pid_e_test5 > selmu_bdt_pid_pi_test5) && (selmu_bdt_pid_e_test5 > selmu_bdt_pid_p_test5) && (particle == -11)&&(particle_pg == -11)) esel_nPositron_test5++;
         
         //corr_weighting_mulike->Fill(selmu_bdt_pid_mu, selmu_bdt_pid_unweighted_mu);
         //corr_weighting_pilike->Fill(selmu_bdt_pid_pi, selmu_bdt_pid_unweighted_pi);
         //corr_weighting_plike->Fill(selmu_bdt_pid_p, selmu_bdt_pid_unweighted_p);
         //corr_weighting_elike->Fill(selmu_bdt_pid_e, selmu_bdt_pid_unweighted_e);
         
         //corr_mulikediff_recomom->Fill(selmu_mom[0], selmu_bdt_pid_mu-selmu_bdt_pid_unweighted_mu);
         //corr_pilikediff_recomom->Fill(selmu_mom[0], selmu_bdt_pid_pi-selmu_bdt_pid_unweighted_pi);
         //corr_plikediff_recomom->Fill(selmu_mom[0], selmu_bdt_pid_p-selmu_bdt_pid_unweighted_p);
         //corr_elikediff_recomom->Fill(selmu_mom[0], selmu_bdt_pid_e-selmu_bdt_pid_unweighted_e);
         
         // Fill variables for existing PID (ROC points)
      
         if (((selmu_tpc_like_mu+selmu_tpc_like_pi)/(1-selmu_tpc_like_p) > 0.9 || selmu_mom[0] > 500.0 ) && (selmu_tpc_like_mu>0.1))
         {
            if ((particle == -13) && (particle_pg == -13)) {antinumu_primary_pid_sig++;}
            if ((particle == 211) && (particle_pg == 211)) {antinumu_primary_pid_bkg++;}
            if ((particle == 2212) && (particle_pg == 2212)) {antinumu_primary_pid_bkg++;}
            if ((particle == -11) && (particle_pg == -11)) {antinumu_primary_pid_bkg++;}

            if (selmu_ecal_bestseg_EbyL < 0.8)
            {
               if ((particle == -13) && (particle_pg == -13)) {antinumu_improved_pid_sig++;}
               if ((particle == 211) && (particle_pg == 211)) {antinumu_improved_pid_bkg++;}
               if ((particle == 2212) && (particle_pg == 2212)) {antinumu_improved_pid_bkg++;}
               if ((particle == -11) && (particle_pg == -11)) {antinumu_improved_pid_bkg++;}
            }
         }
         
         
         
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
                     if ((particle == -13) && (particle_pg == -13)) {antinue_primary_pid_bkg++;}
                     if ((particle == 211) && (particle_pg == 211)) {antinue_primary_pid_bkg++;}
                     if ((particle == 2212) && (particle_pg == 2212)) {antinue_primary_pid_bkg++;}
                     if ((particle == -11) && (particle_pg == -11)) {antinue_primary_pid_sig++;}
                  }
               }
            }
         }
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
   canvas_ptheta->cd(1)->BuildLegend();
   
   
   TCanvas* canvas_recomom = new TCanvas("canvas_recomom","Reconstructed momentum (MeV/c)",200,10,1000,600);
   recomom_antimu->Draw();
   recomom_piplus->Draw("same");
   recomom_proton->Draw("same");
   recomom_positron->Draw("same");
   canvas_recomom->BuildLegend();
   canvas_recomom->Write();
   
   // Reco momentum (before cuts)
   
   recomom_antimu2->GetYaxis()->SetRangeUser(0.0, 7500.0);
  
   SetHistParticleStyle(recomom_antimu2, "antimu");
   SetHistParticleStyle(recomom_piplus2, "piplus");
   SetHistParticleStyle(recomom_proton2, "proton");
   SetHistParticleStyle(recomom_positron2, "positron");
   
   TCanvas* canvas_recomom2 = new TCanvas("canvas_recomom2","Reconstructed momentum (MeV/c)",200,10,1000,600);
   
   recomom_antimu2->Draw();
   recomom_piplus2->Draw("same");
   recomom_proton2->Draw("same");
   recomom_positron2->Draw("same");

   canvas_recomom2->BuildLegend();
   canvas_recomom2->Write();
   
   // True momentum
   
   truemom_antimu->GetYaxis()->SetRangeUser(0.0, 6000.0);
  
   SetHistParticleStyle(truemom_antimu, "antimu");
   SetHistParticleStyle(truemom_piplus, "piplus");
   SetHistParticleStyle(truemom_proton, "proton");
   SetHistParticleStyle(truemom_positron, "positron");
   
   TCanvas* canvas_truemom = new TCanvas("canvas_truemom","True momentum (MeV/c)",200,10,1000,600);
   
   truemom_antimu->Draw();
   truemom_piplus->Draw("same");
   truemom_proton->Draw("same");
   truemom_positron->Draw("same");

   canvas_truemom->BuildLegend();
   canvas_truemom->Write();
   
   // True momentum (before cuts)
   
   truemom_antimu2->GetYaxis()->SetRangeUser(0.0, 6000.0);
  
   SetHistParticleStyle(truemom_antimu2, "antimu");
   SetHistParticleStyle(truemom_piplus2, "piplus");
   SetHistParticleStyle(truemom_proton2, "proton");
   SetHistParticleStyle(truemom_positron2, "positron");
   
   TCanvas* canvas_truemom2 = new TCanvas("canvas_truemom2","True momentum (MeV/c)",200,10,1000,600);
   
   truemom_antimu2->Draw();
   truemom_piplus2->Draw("same");
   truemom_proton2->Draw("same");
   truemom_positron2->Draw("same");

   canvas_truemom2->BuildLegend();
   canvas_truemom2->Write();
   
   // Combined momentum canvases
   
   TCanvas* canvas_mom1 = new TCanvas("canvas_mom1","",200,10,1500,600);
   canvas_mom1->Divide(2,1,0.005,0.005);
   canvas_mom1->cd(1);
   recomom_antimu->Draw();
   recomom_piplus->Draw("same");
   recomom_proton->Draw("same");
   recomom_positron->Draw("same");
   canvas_mom1->cd(1)->BuildLegend();
   canvas_mom1->cd(2);
   truemom_antimu->Draw();
   truemom_piplus->Draw("same");
   truemom_proton->Draw("same");
   truemom_positron->Draw("same");
   canvas_mom1->Write();
   
   TCanvas* canvas_mom2 = new TCanvas("canvas_mom2","",200,10,1500,600);
   canvas_mom2->Divide(2,1,0.005,0.005);
   canvas_mom2->cd(1);
   recomom_antimu2->Draw();
   recomom_piplus2->Draw("same");
   recomom_proton2->Draw("same");
   recomom_positron2->Draw("same");
   canvas_mom2->cd(1)->BuildLegend();
   canvas_mom2->cd(2);
   truemom_antimu2->Draw();
   truemom_piplus2->Draw("same");
   truemom_proton2->Draw("same");
   truemom_positron2->Draw("same");
   canvas_mom2->Write();
   
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
   
   TCanvas* canvas_tpcdedx = new TCanvas("canvas_tpcdedx","",200,10,1000,800);
   canvas_tpcdedx->Divide(2,2,0.005,0.005);
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
   //canvas_tpcdedx->Write();
   
   // TPC3 dE/dx GQ
   
   //TCanvas* canvas_tpc3dedx = new TCanvas("canvas_tpc3dedx","",200,10,1000,600);
   canvas_tpcdedx->cd(3);
   
   //tpc3dedx_antimu->GetYaxis()->SetRangeUser(0.0, 7000.0);
  
   SetHistParticleStyle(tpc3dedx_gq_antimu, "antimu");
   SetHistParticleStyle(tpc3dedx_gq_piplus, "piplus");
   SetHistParticleStyle(tpc3dedx_gq_proton, "proton");
   SetHistParticleStyle(tpc3dedx_gq_positron, "positron");
   
   tpc3dedx_gq_antimu->Draw();
   tpc3dedx_gq_piplus->Draw("same");
   tpc3dedx_gq_proton->Draw("same");
   tpc3dedx_gq_positron->Draw("same");
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
   tpc2pullmu_antimu->GetYaxis()->SetTitleOffset(1.6);
  
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
   tpc2pullpi_antimu->GetYaxis()->SetTitleOffset(1.6);
  
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
   tpc2pullp_antimu->GetYaxis()->SetTitleOffset(1.6);
  
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
   tpc2pulle_antimu->GetYaxis()->SetTitleOffset(1.6);
  
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
   tpc3pullmu_antimu->GetYaxis()->SetTitleOffset(1.6);
  
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
   tpc3pullpi_antimu->GetYaxis()->SetTitleOffset(1.6);
  
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
   tpc3pullp_antimu->GetYaxis()->SetTitleOffset(1.6);
  
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
   tpc3pulle_antimu->GetYaxis()->SetTitleOffset(1.6);
  
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
   
   // TPC3 mu pull GQ
   
   TCanvas* canvas_tpc3pulls_gq = new TCanvas("canvas_tpc3pulls_gq","",200,10,1000,800);
   canvas_tpc3pulls_gq->Divide(2,2,0.005,0.005);
   canvas_tpc3pulls_gq->cd(1);
   
   //tpc3pullmu_gq_antimu->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpc3pullmu_gq_antimu->GetYaxis()->SetTitleOffset(1.6);
  
   SetHistParticleStyle(tpc3pullmu_gq_antimu, "antimu");
   SetHistParticleStyle(tpc3pullmu_gq_piplus, "piplus");
   SetHistParticleStyle(tpc3pullmu_gq_proton, "proton");
   SetHistParticleStyle(tpc3pullmu_gq_positron, "positron");
   
   tpc3pullmu_gq_antimu->Draw();
   tpc3pullmu_gq_piplus->Draw("same");
   tpc3pullmu_gq_proton->Draw("same");
   tpc3pullmu_gq_positron->Draw("same");
   //canvas_tpc3pulls_gq->cd(1)->SetLogy();

   
   // TPC3 pi pull GQ
   
   canvas_tpc3pulls_gq->cd(2);
   
   //tpc3pullpi_gq_antimu->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpc3pullpi_gq_antimu->GetYaxis()->SetTitleOffset(1.6);
  
   SetHistParticleStyle(tpc3pullpi_gq_antimu, "antimu");
   SetHistParticleStyle(tpc3pullpi_gq_piplus, "piplus");
   SetHistParticleStyle(tpc3pullpi_gq_proton, "proton");
   SetHistParticleStyle(tpc3pullpi_gq_positron, "positron");
   
   tpc3pullpi_gq_antimu->Draw();
   tpc3pullpi_gq_piplus->Draw("same");
   tpc3pullpi_gq_proton->Draw("same");
   tpc3pullpi_gq_positron->Draw("same");
   //canvas_tpc3pulls_gq->cd(2)->SetLogy();
   
   
   // TPC3 p pull GQ
  
   canvas_tpc3pulls_gq->cd(3);
   
   //tpc3pullp_gq_antimu->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpc3pullp_gq_antimu->GetYaxis()->SetTitleOffset(1.6);
  
   SetHistParticleStyle(tpc3pullp_gq_antimu, "antimu");
   SetHistParticleStyle(tpc3pullp_gq_piplus, "piplus");
   SetHistParticleStyle(tpc3pullp_gq_proton, "proton");
   SetHistParticleStyle(tpc3pullp_gq_positron, "positron");
   
   tpc3pullp_gq_antimu->Draw();
   tpc3pullp_gq_piplus->Draw("same");
   tpc3pullp_gq_proton->Draw("same");
   tpc3pullp_gq_positron->Draw("same");
   //canvas_tpc3pulls_gq->cd(3)->SetLogy();
   
   // TPC3 e pull GQ
   
   canvas_tpc3pulls_gq->cd(4);
   
   //tpc3pulle_gq_antimu->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpc3pulle_gq_antimu->GetYaxis()->SetTitleOffset(1.6);
  
   SetHistParticleStyle(tpc3pulle_gq_antimu, "antimu");
   SetHistParticleStyle(tpc3pulle_gq_piplus, "piplus");
   SetHistParticleStyle(tpc3pulle_gq_proton, "proton");
   SetHistParticleStyle(tpc3pulle_gq_positron, "positron");
   
   tpc3pulle_gq_antimu->Draw();
   tpc3pulle_gq_piplus->Draw("same");
   tpc3pulle_gq_proton->Draw("same");
   tpc3pulle_gq_positron->Draw("same");
   //canvas_tpc3pulls_gq->cd(4)->SetLogy();
   
   canvas_tpc3pulls_gq->cd(1)->BuildLegend();
   canvas_tpc3pulls_gq->Write();
   
   // nTPCs
   
   TCanvas* canvas_ntpcs = new TCanvas("canvas_ntpcs","",200,10,500,400);
   
   ntpcs_antimu->GetYaxis()->SetRangeUser(0.0, 60000.0);
  
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
   
   // ============= Plot weighted input variables =============
   
   // Reco momentum
   
   //TCanvas* canvas_weighted_recomom = new TCanvas("canvas_weighted_recomom","Reconstructed momentum (MeV/c)",200,10,1000,600);
   
   TCanvas* canvas_weighted_ptheta = new TCanvas("canvas_weighted_ptheta","",200,10,1000,400);
   canvas_weighted_ptheta->Divide(2,1,0.005,0.005);
   canvas_weighted_ptheta->cd(1);
   
   recomom_antimu_weighted->GetYaxis()->SetRangeUser(0.0, 8.0);
   recomom_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(recomom_antimu_weighted, "antimu");
   SetHistParticleStyle(recomom_piplus_weighted, "piplus");
   SetHistParticleStyle(recomom_proton_weighted, "proton");
   SetHistParticleStyle(recomom_positron_weighted, "positron");
   
   recomom_antimu_weighted->Draw();
   recomom_piplus_weighted->Draw("same");
   recomom_proton_weighted->Draw("same");
   recomom_positron_weighted->Draw("same");
   //canvas_weighted_recomom->BuildLegend();
   //canvas_weighted_recomom->Write();
   canvas_weighted_ptheta->cd(1)->BuildLegend();
   
   // Reco theta
   
   //TCanvas* canvas_weighted_theta = new TCanvas("canvas_weighted_theta","Reconstructed angle w.r.t. detector Z-axis (rad)",200,10,1000,600);
   canvas_weighted_ptheta->cd(2);
   
   //theta_antimu_weighted->GetYaxis()->SetRangeUser(0.0, 5000.0);
   theta_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(theta_antimu_weighted, "antimu");
   SetHistParticleStyle(theta_piplus_weighted, "piplus");
   SetHistParticleStyle(theta_proton_weighted, "proton");
   SetHistParticleStyle(theta_positron_weighted, "positron");
   
   theta_antimu_weighted->Draw();
   theta_piplus_weighted->Draw("same");
   theta_proton_weighted->Draw("same");
   theta_positron_weighted->Draw("same");
   //canvas_weighted_theta->BuildLegend();
   //canvas_weighted_theta->Write();
   canvas_weighted_ptheta->Write();
   
   // ECal EM energy
   
   //TCanvas* canvas_weighted_EMEnergy = new TCanvas("canvas_weighted_EMEnergy","",200,10,1000,600);
   
   TCanvas* canvas_weighted_EandEbyL = new TCanvas("canvas_weighted_EandEbyL","",200,10,1000,400);
   canvas_weighted_EandEbyL->Divide(2,1,0.005,0.005);
   canvas_weighted_EandEbyL->cd(1);
   
   //EMEnergy_antimu_weighted->GetYaxis()->SetRangeUser(0.0, 7000.0);
   EMEnergy_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(EMEnergy_antimu_weighted, "antimu");
   SetHistParticleStyle(EMEnergy_piplus_weighted, "piplus");
   SetHistParticleStyle(EMEnergy_proton_weighted, "proton");
   SetHistParticleStyle(EMEnergy_positron_weighted, "positron");
   
   EMEnergy_antimu_weighted->Draw();
   EMEnergy_piplus_weighted->Draw("same");
   EMEnergy_proton_weighted->Draw("same");
   EMEnergy_positron_weighted->Draw("same");
   //canvas_weighted_EMEnergy->BuildLegend();
   //canvas_weighted_EMEnergy->Write();
   canvas_weighted_EandEbyL->cd(1)->BuildLegend();
   
   // ECal E/L
   
   //TCanvas* canvas_weighted_EbyL = new TCanvas("canvas_weighted_EbyL","",200,10,1000,600);
   canvas_weighted_EandEbyL->cd(2);
   
   //EbyL_antimu_weighted->GetYaxis()->SetRangeUser(0.0, 7000.0);
   EbyL_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(EbyL_antimu_weighted, "antimu");
   SetHistParticleStyle(EbyL_piplus_weighted, "piplus");
   SetHistParticleStyle(EbyL_proton_weighted, "proton");
   SetHistParticleStyle(EbyL_positron_weighted, "positron");
   
   EbyL_antimu_weighted->Draw();
   EbyL_piplus_weighted->Draw("same");
   EbyL_proton_weighted->Draw("same");
   EbyL_positron_weighted->Draw("same");
   //canvas_weighted_EbyL->BuildLegend();
   //canvas_weighted_EbyL->Write();
   canvas_weighted_EandEbyL->Write();
   
   // ECal circularity
   
   //TCanvas* canvas_weighted_circularity = new TCanvas("canvas_weighted_circularity","",200,10,1000,600);
   
   TCanvas* canvas_weighted_ecallowlevel = new TCanvas("canvas_weighted_ecallowlevel","",200,10,1000,800);
   canvas_weighted_ecallowlevel->Divide(2,2,0.005,0.005);
   canvas_weighted_ecallowlevel->cd(1);
   
   //circularity_antimu_weighted->GetYaxis()->SetRangeUser(0.0, 7000.0);
   circularity_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(circularity_antimu_weighted, "antimu");
   SetHistParticleStyle(circularity_piplus_weighted, "piplus");
   SetHistParticleStyle(circularity_proton_weighted, "proton");
   SetHistParticleStyle(circularity_positron_weighted, "positron");
   
   circularity_antimu_weighted->Draw();
   circularity_piplus_weighted->Draw("same");
   circularity_proton_weighted->Draw("same");
   circularity_positron_weighted->Draw("same");
   //canvas_weighted_circularity->BuildLegend();
   //canvas_weighted_circularity->Write();
   canvas_weighted_ecallowlevel->cd(1)->BuildLegend();
   
   // ECal FBR
   
   //TCanvas* canvas_weighted_fbr = new TCanvas("canvas_weighted_fbr","",200,10,1000,600);
   canvas_weighted_ecallowlevel->cd(2);
   
   //fbr_antimu_weighted->GetYaxis()->SetRangeUser(0.0, 20000.0);
   fbr_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(fbr_antimu_weighted, "antimu");
   SetHistParticleStyle(fbr_piplus_weighted, "piplus");
   SetHistParticleStyle(fbr_proton_weighted, "proton");
   SetHistParticleStyle(fbr_positron_weighted, "positron");
   
   fbr_antimu_weighted->Draw();
   fbr_piplus_weighted->Draw("same");
   fbr_proton_weighted->Draw("same");
   fbr_positron_weighted->Draw("same");
   //canvas_weighted_fbr->BuildLegend();
   //canvas_weighted_fbr->Write();
   
   // ECal TMR
   
   //TCanvas* canvas_weighted_tmr = new TCanvas("canvas_weighted_tmr","",200,10,1000,600);
   
   canvas_weighted_ecallowlevel->cd(3);
   
   //tmr_antimu_weighted->GetYaxis()->SetRangeUser(0.0, 6500.0);
   tmr_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tmr_antimu_weighted, "antimu");
   SetHistParticleStyle(tmr_piplus_weighted, "piplus");
   SetHistParticleStyle(tmr_proton_weighted, "proton");
   SetHistParticleStyle(tmr_positron_weighted, "positron");
   
   tmr_antimu_weighted->Draw();
   tmr_piplus_weighted->Draw("same");
   tmr_proton_weighted->Draw("same");
   tmr_positron_weighted->Draw("same");
   //canvas_weighted_tmr->BuildLegend();
   //canvas_weighted_tmr->Write();
   
   // ECal QRMS
   
   //TCanvas* canvas_weighted_qrms = new TCanvas("canvas_weighted_qrms","",200,10,1000,600);
   
   canvas_weighted_ecallowlevel->cd(4);
   
   //qrms_antimu_weighted->GetYaxis()->SetRangeUser(0.0, 7000.0);
   qrms_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(qrms_antimu_weighted, "antimu");
   SetHistParticleStyle(qrms_piplus_weighted, "piplus");
   SetHistParticleStyle(qrms_proton_weighted, "proton");
   SetHistParticleStyle(qrms_positron_weighted, "positron");
   
   qrms_antimu_weighted->Draw();
   qrms_piplus_weighted->Draw("same");
   qrms_proton_weighted->Draw("same");
   qrms_positron_weighted->Draw("same");
   //canvas_weighted_qrms->BuildLegend();
   //canvas_weighted_qrms->Write();
   canvas_weighted_ecallowlevel->Write();
   
   // ECal MipEm
   
   //TCanvas* canvas_weighted_mipem = new TCanvas("canvas_weighted_mipem","",200,10,1000,600);
   
   TCanvas* canvas_weighted_ecalhighlevel = new TCanvas("canvas_weighted_ecalhighlevel","",200,10,1000,800);
   canvas_weighted_ecalhighlevel->Divide(2,2,0.005,0.005);
   canvas_weighted_ecalhighlevel->cd(1);
   
   //mipem_antimu_weighted->GetYaxis()->SetRangeUser(0.0, 7000.0);
   mipem_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(mipem_antimu_weighted, "antimu");
   SetHistParticleStyle(mipem_piplus_weighted, "piplus");
   SetHistParticleStyle(mipem_proton_weighted, "proton");
   SetHistParticleStyle(mipem_positron_weighted, "positron");
   
   mipem_antimu_weighted->Draw();
   mipem_piplus_weighted->Draw("same");
   mipem_proton_weighted->Draw("same");
   mipem_positron_weighted->Draw("same");
   //canvas_weighted_mipem->BuildLegend();
   //canvas_weighted_mipem->Write();
   canvas_weighted_ecalhighlevel->cd(1)->BuildLegend();
   
   // ECal EmHip
   
   //TCanvas* canvas_weighted_emhip = new TCanvas("canvas_weighted_emhip","",200,10,1000,600);
   
   canvas_weighted_ecalhighlevel->cd(2);
   
   //emhip_antimu_weighted->GetYaxis()->SetRangeUser(0.0, 7000.0);
   emhip_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(emhip_antimu_weighted, "antimu");
   SetHistParticleStyle(emhip_piplus_weighted, "piplus");
   SetHistParticleStyle(emhip_proton_weighted, "proton");
   SetHistParticleStyle(emhip_positron_weighted, "positron");
   
   emhip_antimu_weighted->Draw();
   emhip_piplus_weighted->Draw("same");
   emhip_proton_weighted->Draw("same");
   emhip_positron_weighted->Draw("same");
   //canvas_weighted_emhip->BuildLegend();
   //canvas_weighted_emhip->Write();
   
   // ECal MipPion
   
   //TCanvas* canvas_weighted_mippion = new TCanvas("canvas_weighted_mippion","",200,10,1000,600);
   
   canvas_weighted_ecalhighlevel->cd(3);
   
   //mippion_antimu_weighted->GetYaxis()->SetRangeUser(0.0, 7000.0);
   mippion_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(mippion_antimu_weighted, "antimu");
   SetHistParticleStyle(mippion_piplus_weighted, "piplus");
   SetHistParticleStyle(mippion_proton_weighted, "proton");
   SetHistParticleStyle(mippion_positron_weighted, "positron");
   
   mippion_antimu_weighted->Draw();
   mippion_piplus_weighted->Draw("same");
   mippion_proton_weighted->Draw("same");
   mippion_positron_weighted->Draw("same");
   //canvas_weighted_mippion->BuildLegend();
   //canvas_weighted_mippion->Write();
   
   canvas_weighted_ecalhighlevel->Write();
   
   // TPC2 dE/dx
   
   //TCanvas* canvas_weighted_tpc2dedx = new TCanvas("canvas_weighted_tpc2dedx","",200,10,1000,600);
   
   TCanvas* canvas_weighted_tpcdedx = new TCanvas("canvas_weighted_tpcdedx","",200,10,1000,800);
   canvas_weighted_tpcdedx->Divide(2,2,0.005,0.005);
   canvas_weighted_tpcdedx->cd(1);
   
   //tpc2dedx_antimu_weighted->GetYaxis()->SetRangeUser(0.0, 7000.0);
   tpc2dedx_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpc2dedx_antimu_weighted, "antimu");
   SetHistParticleStyle(tpc2dedx_piplus_weighted, "piplus");
   SetHistParticleStyle(tpc2dedx_proton_weighted, "proton");
   SetHistParticleStyle(tpc2dedx_positron_weighted, "positron");
   
   tpc2dedx_antimu_weighted->Draw();
   tpc2dedx_piplus_weighted->Draw("same");
   tpc2dedx_proton_weighted->Draw("same");
   tpc2dedx_positron_weighted->Draw("same");
   //canvas_weighted_tpc2dedx->BuildLegend();
   //canvas_weighted_tpc2dedx->Write();
   canvas_weighted_tpcdedx->cd(1)->BuildLegend();
   
   // TPC3 dE/dx
   
   //TCanvas* canvas_weighted_tpc3dedx = new TCanvas("canvas_weighted_tpc3dedx","",200,10,1000,600);
   canvas_weighted_tpcdedx->cd(2);
   
   //tpc3dedx_antimu_weighted->GetYaxis()->SetRangeUser(0.0, 7000.0);
   tpc3dedx_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpc3dedx_antimu_weighted, "antimu");
   SetHistParticleStyle(tpc3dedx_piplus_weighted, "piplus");
   SetHistParticleStyle(tpc3dedx_proton_weighted, "proton");
   SetHistParticleStyle(tpc3dedx_positron_weighted, "positron");
   
   tpc3dedx_antimu_weighted->Draw();
   tpc3dedx_piplus_weighted->Draw("same");
   tpc3dedx_proton_weighted->Draw("same");
   tpc3dedx_positron_weighted->Draw("same");
   //canvas_weighted_tpc3dedx->BuildLegend();
   //canvas_weighted_tpc3dedx->Write();
   //canvas_weighted_tpcdedx->Write();
   
   // TPC3 dE/dx GQ
   
   canvas_weighted_tpcdedx->cd(3);
   
   tpc3dedx_gq_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpc3dedx_gq_antimu_weighted, "antimu");
   SetHistParticleStyle(tpc3dedx_gq_piplus_weighted, "piplus");
   SetHistParticleStyle(tpc3dedx_gq_proton_weighted, "proton");
   SetHistParticleStyle(tpc3dedx_gq_positron_weighted, "positron");
   
   tpc3dedx_gq_antimu_weighted->Draw();
   tpc3dedx_gq_piplus_weighted->Draw("same");
   tpc3dedx_gq_proton_weighted->Draw("same");
   tpc3dedx_gq_positron_weighted->Draw("same");
   canvas_weighted_tpcdedx->Write();
   
   // TPC mu-like
   
   TCanvas* canvas_weighted_tpclikelihoods = new TCanvas("canvas_weighted_tpclikelihoods","",200,10,1000,800);
   canvas_weighted_tpclikelihoods->Divide(2,2,0.005,0.005);
   canvas_weighted_tpclikelihoods->cd(1);
   
   //TCanvas* canvas_weighted_tpclikemu = new TCanvas("canvas_weighted_tpclikemu","",200,10,1000,600);
   
   //tpclikemu_antimu_weighted->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpclikemu_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpclikemu_antimu_weighted, "antimu");
   SetHistParticleStyle(tpclikemu_piplus_weighted, "piplus");
   SetHistParticleStyle(tpclikemu_proton_weighted, "proton");
   SetHistParticleStyle(tpclikemu_positron_weighted, "positron");
   
   tpclikemu_antimu_weighted->Draw();
   tpclikemu_piplus_weighted->Draw("same");
   tpclikemu_proton_weighted->Draw("same");
   tpclikemu_positron_weighted->Draw("same");
   canvas_weighted_tpclikelihoods->cd(1)->SetLogy();
   //canvas_weighted_tpclikemu->BuildLegend();
   //canvas_weighted_tpclikemu->Write();
   
   // TPC pi-like
   
   //TCanvas* canvas_weighted_tpclikepi = new TCanvas("canvas_weighted_tpclikepi","",200,10,1000,600);
   canvas_weighted_tpclikelihoods->cd(2);
   
   //tpclikepi_antimu_weighted->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpclikepi_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpclikepi_antimu_weighted, "antimu");
   SetHistParticleStyle(tpclikepi_piplus_weighted, "piplus");
   SetHistParticleStyle(tpclikepi_proton_weighted, "proton");
   SetHistParticleStyle(tpclikepi_positron_weighted, "positron");
   
   tpclikepi_antimu_weighted->Draw();
   tpclikepi_piplus_weighted->Draw("same");
   tpclikepi_proton_weighted->Draw("same");
   tpclikepi_positron_weighted->Draw("same");
   canvas_weighted_tpclikelihoods->cd(2)->SetLogy();
   //canvas_weighted_tpclikepi->BuildLegend();
   //canvas_weighted_tpclikepi->Write();
   
   // TPC p-like
   
   //TCanvas* canvas_weighted_tpclikep = new TCanvas("canvas_weighted_tpclikep","",200,10,1000,600);
   canvas_weighted_tpclikelihoods->cd(3);
   
   //tpclikep_antimu_weighted->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpclikep_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpclikep_antimu_weighted, "antimu");
   SetHistParticleStyle(tpclikep_piplus_weighted, "piplus");
   SetHistParticleStyle(tpclikep_proton_weighted, "proton");
   SetHistParticleStyle(tpclikep_positron_weighted, "positron");
   
   tpclikep_antimu_weighted->Draw();
   tpclikep_piplus_weighted->Draw("same");
   tpclikep_proton_weighted->Draw("same");
   tpclikep_positron_weighted->Draw("same");
   canvas_weighted_tpclikelihoods->cd(3)->SetLogy();
   //canvas_weighted_tpclikep->BuildLegend();
   //canvas_weighted_tpclikep->Write();
   
   // TPC e-like
   
   //TCanvas* canvas_weighted_tpclikee = new TCanvas("canvas_weighted_tpclikee","",200,10,1000,600);
   canvas_weighted_tpclikelihoods->cd(4);
   
   //tpclikee_antimu_weighted->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpclikee_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpclikee_antimu_weighted, "antimu");
   SetHistParticleStyle(tpclikee_piplus_weighted, "piplus");
   SetHistParticleStyle(tpclikee_proton_weighted, "proton");
   SetHistParticleStyle(tpclikee_positron_weighted, "positron");
   
   tpclikee_antimu_weighted->Draw();
   tpclikee_piplus_weighted->Draw("same");
   tpclikee_proton_weighted->Draw("same");
   tpclikee_positron_weighted->Draw("same");
   canvas_weighted_tpclikelihoods->cd(4)->SetLogy();
   //canvas_weighted_tpclikee->BuildLegend();
   //canvas_weighted_tpclikee->Write();
   
   canvas_weighted_tpclikelihoods->cd(1)->BuildLegend();
   canvas_weighted_tpclikelihoods->Write();
   
   // TPC2 mu pull
   
   TCanvas* canvas_weighted_tpc2pulls = new TCanvas("canvas_weighted_tpc2pulls","",200,10,1000,800);
   canvas_weighted_tpc2pulls->Divide(2,2,0.005,0.005);
   canvas_weighted_tpc2pulls->cd(1);
   
   //tpc2pullmu_antimu_weighted->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpc2pullmu_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpc2pullmu_antimu_weighted, "antimu");
   SetHistParticleStyle(tpc2pullmu_piplus_weighted, "piplus");
   SetHistParticleStyle(tpc2pullmu_proton_weighted, "proton");
   SetHistParticleStyle(tpc2pullmu_positron_weighted, "positron");
   
   tpc2pullmu_antimu_weighted->Draw();
   tpc2pullmu_piplus_weighted->Draw("same");
   tpc2pullmu_proton_weighted->Draw("same");
   tpc2pullmu_positron_weighted->Draw("same");
   //canvas_weighted_tpc2pulls->cd(1)->SetLogy();

   
   // TPC2 pi pull
   
   canvas_weighted_tpc2pulls->cd(2);
   
   //tpc2pullpi_antimu_weighted->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpc2pullpi_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpc2pullpi_antimu_weighted, "antimu");
   SetHistParticleStyle(tpc2pullpi_piplus_weighted, "piplus");
   SetHistParticleStyle(tpc2pullpi_proton_weighted, "proton");
   SetHistParticleStyle(tpc2pullpi_positron_weighted, "positron");
   
   tpc2pullpi_antimu_weighted->Draw();
   tpc2pullpi_piplus_weighted->Draw("same");
   tpc2pullpi_proton_weighted->Draw("same");
   tpc2pullpi_positron_weighted->Draw("same");
   //canvas_weighted_tpc2pulls->cd(2)->SetLogy();
   
   
   // TPC2 p pull
  
   canvas_weighted_tpc2pulls->cd(3);
   
   //tpc2pullp_antimu_weighted->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpc2pullp_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpc2pullp_antimu_weighted, "antimu");
   SetHistParticleStyle(tpc2pullp_piplus_weighted, "piplus");
   SetHistParticleStyle(tpc2pullp_proton_weighted, "proton");
   SetHistParticleStyle(tpc2pullp_positron_weighted, "positron");
   
   tpc2pullp_antimu_weighted->Draw();
   tpc2pullp_piplus_weighted->Draw("same");
   tpc2pullp_proton_weighted->Draw("same");
   tpc2pullp_positron_weighted->Draw("same");
   //canvas_weighted_tpc2pulls->cd(3)->SetLogy();
   
   // TPC2 e pull
   
   canvas_weighted_tpc2pulls->cd(4);
   
   //tpc2pulle_antimu_weighted->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpc2pulle_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpc2pulle_antimu_weighted, "antimu");
   SetHistParticleStyle(tpc2pulle_piplus_weighted, "piplus");
   SetHistParticleStyle(tpc2pulle_proton_weighted, "proton");
   SetHistParticleStyle(tpc2pulle_positron_weighted, "positron");
   
   tpc2pulle_antimu_weighted->Draw();
   tpc2pulle_piplus_weighted->Draw("same");
   tpc2pulle_proton_weighted->Draw("same");
   tpc2pulle_positron_weighted->Draw("same");
   //canvas_weighted_tpc2pulls->cd(4)->SetLogy();
   
   canvas_weighted_tpc2pulls->cd(1)->BuildLegend();
   canvas_weighted_tpc2pulls->Write();
   
   // TPC3 mu pull
   
   TCanvas* canvas_weighted_tpc3pulls = new TCanvas("canvas_weighted_tpc3pulls","",200,10,1000,800);
   canvas_weighted_tpc3pulls->Divide(2,2,0.005,0.005);
   canvas_weighted_tpc3pulls->cd(1);
   
   //tpc3pullmu_antimu_weighted->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpc3pullmu_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpc3pullmu_antimu_weighted, "antimu");
   SetHistParticleStyle(tpc3pullmu_piplus_weighted, "piplus");
   SetHistParticleStyle(tpc3pullmu_proton_weighted, "proton");
   SetHistParticleStyle(tpc3pullmu_positron_weighted, "positron");
   
   tpc3pullmu_antimu_weighted->Draw();
   tpc3pullmu_piplus_weighted->Draw("same");
   tpc3pullmu_proton_weighted->Draw("same");
   tpc3pullmu_positron_weighted->Draw("same");
   //canvas_weighted_tpc3pulls->cd(1)->SetLogy();

   
   // TPC3 pi pull
   
   canvas_weighted_tpc3pulls->cd(2);
   
   //tpc3pullpi_antimu_weighted->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpc3pullpi_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpc3pullpi_antimu_weighted, "antimu");
   SetHistParticleStyle(tpc3pullpi_piplus_weighted, "piplus");
   SetHistParticleStyle(tpc3pullpi_proton_weighted, "proton");
   SetHistParticleStyle(tpc3pullpi_positron_weighted, "positron");
   
   tpc3pullpi_antimu_weighted->Draw();
   tpc3pullpi_piplus_weighted->Draw("same");
   tpc3pullpi_proton_weighted->Draw("same");
   tpc3pullpi_positron_weighted->Draw("same");
   //canvas_weighted_tpc3pulls->cd(2)->SetLogy();
   
   
   // TPC3 p pull
  
   canvas_weighted_tpc3pulls->cd(3);
   
   //tpc3pullp_antimu_weighted->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpc3pullp_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpc3pullp_antimu_weighted, "antimu");
   SetHistParticleStyle(tpc3pullp_piplus_weighted, "piplus");
   SetHistParticleStyle(tpc3pullp_proton_weighted, "proton");
   SetHistParticleStyle(tpc3pullp_positron_weighted, "positron");
   
   tpc3pullp_antimu_weighted->Draw();
   tpc3pullp_piplus_weighted->Draw("same");
   tpc3pullp_proton_weighted->Draw("same");
   tpc3pullp_positron_weighted->Draw("same");
   //canvas_weighted_tpc3pulls->cd(3)->SetLogy();
   
   // TPC3 e pull
   
   canvas_weighted_tpc3pulls->cd(4);
   
   //tpc3pulle_antimu_weighted->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpc3pulle_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpc3pulle_antimu_weighted, "antimu");
   SetHistParticleStyle(tpc3pulle_piplus_weighted, "piplus");
   SetHistParticleStyle(tpc3pulle_proton_weighted, "proton");
   SetHistParticleStyle(tpc3pulle_positron_weighted, "positron");
   
   tpc3pulle_antimu_weighted->Draw();
   tpc3pulle_piplus_weighted->Draw("same");
   tpc3pulle_proton_weighted->Draw("same");
   tpc3pulle_positron_weighted->Draw("same");
   //canvas_weighted_tpc3pulls->cd(4)->SetLogy();
   
   canvas_weighted_tpc3pulls->cd(1)->BuildLegend();
   canvas_weighted_tpc3pulls->Write();
   
   // TPC3 mu pull GQ
   
   TCanvas* canvas_weighted_tpc3pulls_gq = new TCanvas("canvas_weighted_tpc3pulls_gq","",200,10,1000,800);
   canvas_weighted_tpc3pulls_gq->Divide(2,2,0.005,0.005);
   canvas_weighted_tpc3pulls_gq->cd(1);
   
   //tpc3pullmu_gq_antimu_weighted->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpc3pullmu_gq_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpc3pullmu_gq_antimu_weighted, "antimu");
   SetHistParticleStyle(tpc3pullmu_gq_piplus_weighted, "piplus");
   SetHistParticleStyle(tpc3pullmu_gq_proton_weighted, "proton");
   SetHistParticleStyle(tpc3pullmu_gq_positron_weighted, "positron");
   
   tpc3pullmu_gq_antimu_weighted->Draw();
   tpc3pullmu_gq_piplus_weighted->Draw("same");
   tpc3pullmu_gq_proton_weighted->Draw("same");
   tpc3pullmu_gq_positron_weighted->Draw("same");
   //canvas_weighted_tpc3pulls_gq->cd(1)->SetLogy();

   
   // TPC3 pi pull GQ
   
   canvas_weighted_tpc3pulls_gq->cd(2);
   
   //tpc3pullpi_gq_antimu_weighted->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpc3pullpi_gq_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpc3pullpi_gq_antimu_weighted, "antimu");
   SetHistParticleStyle(tpc3pullpi_gq_piplus_weighted, "piplus");
   SetHistParticleStyle(tpc3pullpi_gq_proton_weighted, "proton");
   SetHistParticleStyle(tpc3pullpi_gq_positron_weighted, "positron");
   
   tpc3pullpi_gq_antimu_weighted->Draw();
   tpc3pullpi_gq_piplus_weighted->Draw("same");
   tpc3pullpi_gq_proton_weighted->Draw("same");
   tpc3pullpi_gq_positron_weighted->Draw("same");
   //canvas_weighted_tpc3pulls_gq->cd(2)->SetLogy();
   
   // TPC3 p pull GQ
  
   canvas_weighted_tpc3pulls_gq->cd(3);
   
   //tpc3pullp_gq_antimu_weighted->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpc3pullp_gq_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpc3pullp_gq_antimu_weighted, "antimu");
   SetHistParticleStyle(tpc3pullp_gq_piplus_weighted, "piplus");
   SetHistParticleStyle(tpc3pullp_gq_proton_weighted, "proton");
   SetHistParticleStyle(tpc3pullp_gq_positron_weighted, "positron");
   
   tpc3pullp_gq_antimu_weighted->Draw();
   tpc3pullp_gq_piplus_weighted->Draw("same");
   tpc3pullp_gq_proton_weighted->Draw("same");
   tpc3pullp_gq_positron_weighted->Draw("same");
   //canvas_weighted_tpc3pulls_gq->cd(3)->SetLogy();
   
   // TPC3 e pull GQ
   
   canvas_weighted_tpc3pulls_gq->cd(4);
   
   //tpc3pulle_gq_antimu_weighted->GetYaxis()->SetRangeUser(1.0, 120000.0);
   tpc3pulle_gq_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(tpc3pulle_gq_antimu_weighted, "antimu");
   SetHistParticleStyle(tpc3pulle_gq_piplus_weighted, "piplus");
   SetHistParticleStyle(tpc3pulle_gq_proton_weighted, "proton");
   SetHistParticleStyle(tpc3pulle_gq_positron_weighted, "positron");
   
   tpc3pulle_gq_antimu_weighted->Draw();
   tpc3pulle_gq_piplus_weighted->Draw("same");
   tpc3pulle_gq_proton_weighted->Draw("same");
   tpc3pulle_gq_positron_weighted->Draw("same");
   //canvas_weighted_tpc3pulls_gq->cd(4)->SetLogy();
   
   canvas_weighted_tpc3pulls_gq->cd(1)->BuildLegend();
   canvas_weighted_tpc3pulls_gq->Write();
   
   // nTPCs
   
   TCanvas* canvas_weighted_ntpcs = new TCanvas("canvas_weighted_ntpcs","",200,10,500,400);
   
   //ntpcs_antimu_weighted->GetYaxis()->SetRangeUser(0.0, 60000.0);
   ntpcs_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(ntpcs_antimu_weighted, "antimu");
   SetHistParticleStyle(ntpcs_piplus_weighted, "piplus");
   SetHistParticleStyle(ntpcs_proton_weighted, "proton");
   SetHistParticleStyle(ntpcs_positron_weighted, "positron");
   
   ntpcs_antimu_weighted->Draw();
   ntpcs_piplus_weighted->Draw("same");
   ntpcs_proton_weighted->Draw("same");
   ntpcs_positron_weighted->Draw("same");
   canvas_weighted_ntpcs->BuildLegend();
   canvas_weighted_ntpcs->Write();
   
   // FGD1 E/L
   
   //TCanvas* canvas_weighted_fgd1EbyL = new TCanvas("canvas_weighted_fgd1EbyL","",200,10,1000,600);
   TCanvas* canvas_weighted_fgdEbyLs = new TCanvas("canvas_weighted_fgdEbyLs","",200,10,1000,400);
   canvas_weighted_fgdEbyLs->Divide(2,1,0.005,0.005);
   canvas_weighted_fgdEbyLs->cd(1);
   
   //fgd1EbyL_antimu_weighted->GetYaxis()->SetRangeUser(0.0, 7000.0);
   fgd1EbyL_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(fgd1EbyL_antimu_weighted, "antimu");
   SetHistParticleStyle(fgd1EbyL_piplus_weighted, "piplus");
   SetHistParticleStyle(fgd1EbyL_proton_weighted, "proton");
   SetHistParticleStyle(fgd1EbyL_positron_weighted, "positron");
   
   fgd1EbyL_antimu_weighted->Draw();
   fgd1EbyL_piplus_weighted->Draw("same");
   fgd1EbyL_proton_weighted->Draw("same");
   fgd1EbyL_positron_weighted->Draw("same");
   //canvas_weighted_fgd1EbyL->BuildLegend();
   //canvas_weighted_fgd1EbyL->Write();
   canvas_weighted_fgdEbyLs->cd(1)->BuildLegend();
   
   // FGD2 E/L
   
   //TCanvas* canvas_weighted_fgd2EbyL = new TCanvas("canvas_weighted_fgd2EbyL","",200,10,1000,600);
   canvas_weighted_fgdEbyLs->cd(2);
   
   //fgd2EbyL_antimu_weighted->GetYaxis()->SetRangeUser(0.0, 7000.0);
   fgd2EbyL_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
   
   SetHistParticleStyle(fgd2EbyL_antimu_weighted, "antimu");
   SetHistParticleStyle(fgd2EbyL_piplus_weighted, "piplus");
   SetHistParticleStyle(fgd2EbyL_proton_weighted, "proton");
   SetHistParticleStyle(fgd2EbyL_positron_weighted, "positron");
   
   fgd2EbyL_antimu_weighted->Draw();
   fgd2EbyL_piplus_weighted->Draw("same");
   fgd2EbyL_proton_weighted->Draw("same");
   fgd2EbyL_positron_weighted->Draw("same");
   //canvas_weighted_fgd2EbyL->BuildLegend();
   //canvas_weighted_fgd2EbyL->Write();
   canvas_weighted_fgdEbyLs->Write();
   
   // nSMRDs
   
   TCanvas* canvas_weighted_nsmrds = new TCanvas("canvas_weighted_nsmrds","",200,10,500,400);
   
   //nsmrds_antimu_weighted->GetYaxis()->SetRangeUser(0.0, 80000.0);
   nsmrds_antimu_weighted->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(nsmrds_antimu_weighted, "antimu");
   SetHistParticleStyle(nsmrds_piplus_weighted, "piplus");
   SetHistParticleStyle(nsmrds_proton_weighted, "proton");
   SetHistParticleStyle(nsmrds_positron_weighted, "positron");
   
   nsmrds_antimu_weighted->Draw();
   nsmrds_piplus_weighted->Draw("same");
   nsmrds_proton_weighted->Draw("same");
   nsmrds_positron_weighted->Draw("same");
   canvas_weighted_nsmrds->BuildLegend();
   canvas_weighted_nsmrds->Write();
   
   // ============= Plot BDT output variables =============
   
   // BDT mu-like
   
   TCanvas* canvas_bdtoutputs = new TCanvas("canvas_bdtoutputs","",200,10,1000,800);
   canvas_bdtoutputs->Divide(2,2,0.005,0.005);
   canvas_bdtoutputs->cd(1);
   
   bdt_mulike_antimu->GetYaxis()->SetRangeUser(1.0, 120000.0);
   bdt_mulike_antimu->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(bdt_mulike_antimu, "antimu");
   SetHistParticleStyle(bdt_mulike_piplus, "piplus");
   SetHistParticleStyle(bdt_mulike_proton, "proton");
   SetHistParticleStyle(bdt_mulike_positron, "positron");
   
   bdt_mulike_antimu->Draw();
   bdt_mulike_piplus->Draw("same");
   bdt_mulike_proton->Draw("same");
   bdt_mulike_positron->Draw("same");
   canvas_bdtoutputs->cd(1)->SetLogy();
   
   // BDT pi-like
   
   canvas_bdtoutputs->cd(2);
   
   bdt_pilike_antimu->GetYaxis()->SetRangeUser(1.0, 120000.0);
   bdt_pilike_antimu->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(bdt_pilike_antimu, "antimu");
   SetHistParticleStyle(bdt_pilike_piplus, "piplus");
   SetHistParticleStyle(bdt_pilike_proton, "proton");
   SetHistParticleStyle(bdt_pilike_positron, "positron");
   
   bdt_pilike_antimu->Draw();
   bdt_pilike_piplus->Draw("same");
   bdt_pilike_proton->Draw("same");
   bdt_pilike_positron->Draw("same");
   canvas_bdtoutputs->cd(2)->SetLogy();
   
   // BDT p-like
   
   canvas_bdtoutputs->cd(3);
   
   bdt_plike_antimu->GetYaxis()->SetRangeUser(1.0, 120000.0);
   bdt_plike_antimu->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(bdt_plike_antimu, "antimu");
   SetHistParticleStyle(bdt_plike_piplus, "piplus");
   SetHistParticleStyle(bdt_plike_proton, "proton");
   SetHistParticleStyle(bdt_plike_positron, "positron");
   
   bdt_plike_antimu->Draw();
   bdt_plike_piplus->Draw("same");
   bdt_plike_proton->Draw("same");
   bdt_plike_positron->Draw("same");
   canvas_bdtoutputs->cd(3)->SetLogy();
   
   // BDT e-like
   
   canvas_bdtoutputs->cd(4);
   
   bdt_elike_antimu->GetYaxis()->SetRangeUser(1.0, 120000.0);
   bdt_elike_antimu->GetYaxis()->SetTitleOffset(1.2);
  
   SetHistParticleStyle(bdt_elike_antimu, "antimu");
   SetHistParticleStyle(bdt_elike_piplus, "piplus");
   SetHistParticleStyle(bdt_elike_proton, "proton");
   SetHistParticleStyle(bdt_elike_positron, "positron");
   
   bdt_elike_antimu->Draw();
   bdt_elike_piplus->Draw("same");
   bdt_elike_proton->Draw("same");
   bdt_elike_positron->Draw("same");
   canvas_bdtoutputs->cd(4)->SetLogy();
   
   canvas_bdtoutputs->cd(1)->BuildLegend();
   canvas_bdtoutputs->Write();
   
   // ============= Find optimal cuts =============
   
   std::cout << "DEBUG: Preselection mu+: " << presel_nAntimu << std::endl;
   std::cout << "DEBUG: Preselection pi+: " << presel_nPiplus << std::endl;
   std::cout << "DEBUG: Preselection p: " << presel_nProton << std::endl;
   std::cout << "DEBUG: Preselection e+: " << presel_nPositron << std::endl;
   
   Int_t musel_nAntimu_ref = 64118;
   Int_t musel_nPiplus_ref = 18803;
   Int_t musel_nProton_ref = 1128;
   Int_t musel_nPositron_ref = 924;
   Int_t pisel_nAntimu_ref = 4143;
   Int_t pisel_nPiplus_ref = 37078;
   Int_t pisel_nProton_ref = 2130;
   Int_t pisel_nPositron_ref = 888;
   Int_t psel_nAntimu_ref = 503;
   Int_t psel_nPiplus_ref = 1713;
   Int_t psel_nProton_ref = 51974;
   Int_t psel_nPositron_ref = 2739;
   Int_t esel_nAntimu_ref = 267;
   Int_t esel_nPiplus_ref = 830;
   Int_t esel_nProton_ref = 2616;
   Int_t esel_nPositron_ref = 62799;
   
   std::cout << std::endl << "=========== Mu-like optimisation ===========" << std::endl << std::endl;
   
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
   
   /*std::cout << "DEBUG: mu+: " << musel_nAntimu << std::endl;
   std::cout << "DEBUG: pi+: " << musel_nPiplus << std::endl;
   std::cout << "DEBUG: p: " << musel_nProton << std::endl;
   std::cout << "DEBUG: e+: " << musel_nPositron << std::endl;*/
   std::cout << "mu+ efficiency: " <<  (Float_t)musel_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)musel_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)musel_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)musel_nPositron/presel_nPositron << std::endl;
   
   std::cout << "n-1 mu+ efficiency diff:" << (Float_t)(musel_nAntimu-musel_nAntimu_ref)/presel_nAntimu << std::endl;
   std::cout << "n-1 mu+ efficiency diff error:" << sqrt(abs(musel_nAntimu-musel_nAntimu_ref))/presel_nAntimu << std::endl;
   
   graph_opt_mu->Draw("AC");
   canvas_opt_mu->Write();
   TCanvas* canvas_effpur_mu = new TCanvas("effpur_mulike","Optimisation efficiency and purity curves (mu-like)",200,10,1000,600);
   //graph_opt_pur_mu->Draw("AC");
   //graph_opt_eff_mu->Draw("C* same");
   graph_opt_effpur_mu->Draw("AC");
   canvas_effpur_mu->Write();
   
   std::cout << std::endl << "=========== Pi-like optimisation ===========" << std::endl << std::endl;
   
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
   
   /*std::cout << "DEBUG: mu+: " << pisel_nAntimu << std::endl;
   std::cout << "DEBUG: pi+: " << pisel_nPiplus << std::endl;
   std::cout << "DEBUG: p: " << pisel_nProton << std::endl;
   std::cout << "DEBUG: e+: " << pisel_nPositron << std::endl;*/
   std::cout << "mu+ efficiency: " << (Float_t)pisel_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)pisel_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)pisel_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)pisel_nPositron/presel_nPositron << std::endl;
   
   std::cout << "n-1 pi+ efficiency diff:" << (Float_t)(pisel_nPiplus-pisel_nPiplus_ref)/presel_nPiplus << std::endl;
   std::cout << "n-1 pi+ efficiency diff error:" << sqrt(abs(pisel_nPiplus-pisel_nPiplus_ref))/presel_nPiplus << std::endl;
   
   graph_opt_pi->Draw("AC");
   canvas_opt_pi->Write();
   TCanvas* canvas_effpur_pi = new TCanvas("effpur_pilike","Optimisation efficiency and purity curves (pi-like)",200,10,1000,600);
   //graph_opt_pur_pi->Draw("AC");
   //graph_opt_eff_pi->Draw("C* same");
   graph_opt_effpur_pi->Draw("AC");
   canvas_effpur_pi->Write();
   
   std::cout << std::endl << "=========== Proton-like optimisation ===========" << std::endl << std::endl;
   
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
   
   /*std::cout << "DEBUG: mu+: " << psel_nAntimu << std::endl;
   std::cout << "DEBUG: pi+: " << psel_nPiplus << std::endl;
   std::cout << "DEBUG: p: " << psel_nProton << std::endl;
   std::cout << "DEBUG: e+: " << psel_nPositron << std::endl;*/
   
   std::cout << "mu+ efficiency: " << (Float_t)psel_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)psel_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)psel_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)psel_nPositron/presel_nPositron << std::endl;
   
   std::cout << "n-1 p efficiency diff:" << (Float_t)(psel_nProton-psel_nProton_ref)/presel_nProton << std::endl;
   std::cout << "n-1 p efficiency diff error:" << sqrt(abs(psel_nProton-psel_nProton_ref))/presel_nProton << std::endl;
   
   graph_opt_p->Draw("AC");
   canvas_opt_p->Write();
   TCanvas* canvas_effpur_p = new TCanvas("effpur_plike","Optimisation efficiency and purity curves (p-like)",200,10,1000,600);
   //graph_opt_pur_p->Draw("AC");
   //graph_opt_eff_p->Draw("C* same");
   graph_opt_effpur_p->Draw("AC");
   canvas_effpur_p->Write();
   
   std::cout << std::endl << "=========== Electron-like optimisation ===========" << std::endl << std::endl;
   
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
   
   /*std::cout << "DEBUG: mu+: " << esel_nAntimu << std::endl;
   std::cout << "DEBUG: pi+: " << esel_nPiplus << std::endl;
   std::cout << "DEBUG: p: " << esel_nProton << std::endl;
   std::cout << "DEBUG: e+: " << esel_nPositron << std::endl;*/
   
   std::cout << "mu+ efficiency: " << (Float_t)esel_nAntimu/presel_nAntimu << std::endl;
   std::cout << "pi+ efficiency: " << (Float_t)esel_nPiplus/presel_nPiplus << std::endl;
   std::cout << "p efficiency: " << (Float_t)esel_nProton/presel_nProton << std::endl;
   std::cout << "e+ efficiency: " << (Float_t)esel_nPositron/presel_nPositron << std::endl;
   
   std::cout << "n-1 e efficiency diff:" << (Float_t)(esel_nPositron-esel_nPositron_ref)/presel_nPositron << std::endl;
   std::cout << "n-1 e efficiency diff error:" << sqrt(abs(esel_nPositron-esel_nPositron_ref))/presel_nPositron << std::endl;
   
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
      
      //std::cout << "Optimal mu-like significance = " << GetOptSignificanceValues(opt_mulike_sig_test1, opt_mulike_bkg_test1, optimisation_nbins) << std::endl;
      //std::cout << "Optimal pi-like significance = " << GetOptSignificanceValues(opt_pilike_sig_test1, opt_pilike_bkg_test1, optimisation_nbins) << std::endl;
      //std::cout << "Optimal p-like significance = " << GetOptSignificanceValues(opt_plike_sig_test1, opt_plike_bkg_test1, optimisation_nbins) << std::endl;
      //std::cout << "Optimal e-like significance = " << GetOptSignificanceValues(opt_elike_sig_test1, opt_elike_bkg_test1, optimisation_nbins) << std::endl;
      std::cout << "mu+ efficiency: " << (Float_t)musel_nAntimu_test1/presel_nAntimu << std::endl;
      std::cout << "pi+ efficiency: " << (Float_t)pisel_nPiplus_test1/presel_nPiplus << std::endl;
      std::cout << "p efficiency: " << (Float_t)psel_nProton_test1/presel_nProton << std::endl;
      std::cout << "e+ efficiency: " << (Float_t)esel_nPositron_test1/presel_nPositron << std::endl;
      
      // Point 2

      if (parameter == "treedepth") std::cout << "Tree depth 3:" << std::endl;
      if (parameter == "treenumber") std::cout << "1000 trees:" << std::endl;
      if (parameter == "shrinkage") std::cout << "Shrinkage 0.3:" << std::endl;
      if (parameter == "bagged") std::cout << "Bagged 0.3:" << std::endl;
      if (parameter == "randomforests") std::cout << "NVars 6:" << std::endl;
      
      //std::cout << "Optimal mu-like significance = " << GetOptSignificanceValues(opt_mulike_sig_test2, opt_mulike_bkg_test2, optimisation_nbins) << std::endl;
      //std::cout << "Optimal pi-like significance = " << GetOptSignificanceValues(opt_pilike_sig_test2, opt_pilike_bkg_test2, optimisation_nbins) << std::endl;
      //std::cout << "Optimal p-like significance = " << GetOptSignificanceValues(opt_plike_sig_test2, opt_plike_bkg_test2, optimisation_nbins) << std::endl;
      //std::cout << "Optimal e-like significance = " << GetOptSignificanceValues(opt_elike_sig_test2, opt_elike_bkg_test2, optimisation_nbins) << std::endl;
      std::cout << "mu+ efficiency: " << (Float_t)musel_nAntimu_test2/presel_nAntimu << std::endl;
      std::cout << "pi+ efficiency: " << (Float_t)pisel_nPiplus_test2/presel_nPiplus << std::endl;
      std::cout << "p efficiency: " << (Float_t)psel_nProton_test2/presel_nProton << std::endl;
      std::cout << "e+ efficiency: " << (Float_t)esel_nPositron_test2/presel_nPositron << std::endl;
      
      // Point 3
      
      if (parameter == "treedepth") std::cout << "Tree depth 4:" << std::endl;
      if (parameter == "treenumber") std::cout << "1500 trees:" << std::endl;
      if (parameter == "shrinkage") std::cout << "Shrinkage 0.5:" << std::endl;
      if (parameter == "bagged") std::cout << "Bagged 0.5:" << std::endl;
      if (parameter == "randomforests") std::cout << "NVars 8:" << std::endl;
      
      //std::cout << "Optimal mu-like significance = " << GetOptSignificanceValues(opt_mulike_sig_test3, opt_mulike_bkg_test3, optimisation_nbins) << std::endl;
      //std::cout << "Optimal pi-like significance = " << GetOptSignificanceValues(opt_pilike_sig_test3, opt_pilike_bkg_test3, optimisation_nbins) << std::endl;
      //std::cout << "Optimal p-like significance = " << GetOptSignificanceValues(opt_plike_sig_test3, opt_plike_bkg_test3, optimisation_nbins) << std::endl;
      //std::cout << "Optimal e-like significance = " << GetOptSignificanceValues(opt_elike_sig_test3, opt_elike_bkg_test3, optimisation_nbins) << std::endl;
      std::cout << "mu+ efficiency: " << (Float_t)musel_nAntimu_test3/presel_nAntimu << std::endl;
      std::cout << "pi+ efficiency: " << (Float_t)pisel_nPiplus_test3/presel_nPiplus << std::endl;
      std::cout << "p efficiency: " << (Float_t)psel_nProton_test3/presel_nProton << std::endl;
      std::cout << "e+ efficiency: " << (Float_t)esel_nPositron_test3/presel_nPositron << std::endl;
      
      // Point 4

      if (parameter == "treedepth") std::cout << "Tree depth 5:" << std::endl;
      if (parameter == "treenumber") std::cout << "2000 trees:" << std::endl;
      if (parameter == "shrinkage") std::cout << "Shrinkage 0.7:" << std::endl;
      if (parameter == "bagged") std::cout << "Bagged 0.7:" << std::endl;
      if (parameter == "randomforests") std::cout << "NVars 10:" << std::endl;
      
      //std::cout << "Optimal mu-like significance = " << GetOptSignificanceValues(opt_mulike_sig_test4, opt_mulike_bkg_test4, optimisation_nbins) << std::endl;
      //std::cout << "Optimal pi-like significance = " << GetOptSignificanceValues(opt_pilike_sig_test4, opt_pilike_bkg_test4, optimisation_nbins) << std::endl;
      //std::cout << "Optimal p-like significance = " << GetOptSignificanceValues(opt_plike_sig_test4, opt_plike_bkg_test4, optimisation_nbins) << std::endl;
      //std::cout << "Optimal e-like significance = " << GetOptSignificanceValues(opt_elike_sig_test4, opt_elike_bkg_test4, optimisation_nbins) << std::endl;
      std::cout << "mu+ efficiency: " << (Float_t)musel_nAntimu_test4/presel_nAntimu << std::endl;
      std::cout << "pi+ efficiency: " << (Float_t)pisel_nPiplus_test4/presel_nPiplus << std::endl;
      std::cout << "p efficiency: " << (Float_t)psel_nProton_test4/presel_nProton << std::endl;
      std::cout << "e+ efficiency: " << (Float_t)esel_nPositron_test4/presel_nPositron << std::endl;
      
      // Point 5
      
      if (parameter != "treedepth")
      {
         if (parameter == "treenumber") std::cout << "2500 trees:" << std::endl;
         if (parameter == "shrinkage") std::cout << "Shrinkage 0.9:" << std::endl;
         if (parameter == "bagged") std::cout << "Bagged 0.9:" << std::endl;
         if (parameter == "randomforests") std::cout << "NVars 12:" << std::endl;
         
         //std::cout << "Optimal mu-like significance = " << GetOptSignificanceValues(opt_mulike_sig_test5, opt_mulike_bkg_test5, optimisation_nbins) << std::endl;
         //std::cout << "Optimal pi-like significance = " << GetOptSignificanceValues(opt_pilike_sig_test5, opt_pilike_bkg_test5, optimisation_nbins) << std::endl;
         //std::cout << "Optimal p-like significance = " << GetOptSignificanceValues(opt_plike_sig_test5, opt_plike_bkg_test5, optimisation_nbins) << std::endl;
         //std::cout << "Optimal e-like significance = " << GetOptSignificanceValues(opt_elike_sig_test5, opt_elike_bkg_test5, optimisation_nbins) << std::endl;
         std::cout << "mu+ efficiency: " << (Float_t)musel_nAntimu_test5/presel_nAntimu << std::endl;
         std::cout << "pi+ efficiency: " << (Float_t)pisel_nPiplus_test5/presel_nPiplus << std::endl;
         std::cout << "p efficiency: " << (Float_t)psel_nProton_test5/presel_nProton << std::endl;
         std::cout << "e+ efficiency: " << (Float_t)esel_nPositron_test5/presel_nPositron << std::endl;
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
   
   
   // ROC curves
   
   TGraph* roc_purvseff_mulike = new TGraph();
   roc_purvseff_mulike->SetTitle("BDT #mu-like output");
   
   for (Int_t cut = 0; cut <= optimisation_nbins; cut++)
   {
      Float_t efficiency = opt_mulike_sig->Integral(cut,optimisation_nbins+1)/opt_mulike_sig->GetEntries();
      Float_t purity = opt_mulike_sig->Integral(cut,optimisation_nbins+1)/(opt_mulike_sig->Integral(cut,optimisation_nbins+1) + opt_mulike_bkg->Integral(cut,optimisation_nbins+1));
      roc_purvseff_mulike->SetPoint(cut, efficiency, purity);
   }
   roc_purvseff_mulike->SetLineColor( kBlue);
   roc_purvseff_mulike->SetFillColor( kWhite);
   roc_purvseff_mulike->SetLineWidth(2);
   roc_purvseff_mulike->Write();
   
   TGraph* roc_purvseff_pilike = new TGraph();
   roc_purvseff_pilike->SetTitle("BDT #pi-like output");
   
   for (Int_t cut = 0; cut <= optimisation_nbins; cut++)
   {
      Float_t efficiency = opt_pilike_sig->Integral(cut,optimisation_nbins+1)/opt_pilike_sig->GetEntries();
      Float_t purity = opt_pilike_sig->Integral(cut,optimisation_nbins+1)/(opt_pilike_sig->Integral(cut,optimisation_nbins+1) + opt_pilike_bkg->Integral(cut,optimisation_nbins+1));
      roc_purvseff_pilike->SetPoint(cut, efficiency, purity);
   }
   roc_purvseff_pilike->SetLineColor( kRed);
   roc_purvseff_pilike->SetFillColor( kWhite);
   roc_purvseff_pilike->SetLineWidth(2);
   roc_purvseff_pilike->Write();
   
   TGraph* roc_purvseff_plike = new TGraph();
   roc_purvseff_plike->SetTitle("BDT p-like output");
   
   for (Int_t cut = 0; cut <= optimisation_nbins; cut++)
   {
      Float_t efficiency = opt_plike_sig->Integral(cut,optimisation_nbins+1)/opt_plike_sig->GetEntries();
      Float_t purity = opt_plike_sig->Integral(cut,optimisation_nbins+1)/(opt_plike_sig->Integral(cut,optimisation_nbins+1) + opt_plike_bkg->Integral(cut,optimisation_nbins+1));
      roc_purvseff_plike->SetPoint(cut, efficiency, purity);
   }
   roc_purvseff_plike->SetLineColor( kGreen);
   roc_purvseff_plike->SetFillColor( kWhite);
   roc_purvseff_plike->SetLineWidth(2);
   roc_purvseff_plike->Write();
   
   TGraph* roc_purvseff_elike = new TGraph();
   roc_purvseff_elike->SetTitle("BDT e-like output");
   
   for (Int_t cut = 0; cut <= optimisation_nbins; cut++)
   {
      Float_t efficiency = opt_elike_sig->Integral(cut,optimisation_nbins+1)/opt_elike_sig->GetEntries();
      Float_t purity = opt_elike_sig->Integral(cut,optimisation_nbins+1)/(opt_elike_sig->Integral(cut,optimisation_nbins+1) + opt_elike_bkg->Integral(cut,optimisation_nbins+1));
      roc_purvseff_elike->SetPoint(cut, efficiency, purity);
   }
   roc_purvseff_elike->SetLineColor( kMagenta);
   roc_purvseff_elike->SetFillColor( kWhite);
   roc_purvseff_elike->SetLineWidth(2);
   roc_purvseff_elike->Write();
   
   TGraph* roc_tpc_purvseff_mulike = new TGraph();
   roc_tpc_purvseff_mulike->SetTitle("TPC #mu likelihood");
   
   for (Int_t cut = 0; cut <= optimisation_nbins; cut++)
   {
      Float_t efficiency = tpc_mulike_sig->Integral(cut,optimisation_nbins+1)/tpc_mulike_sig->GetEntries();
      Float_t purity = tpc_mulike_sig->Integral(cut,optimisation_nbins+1)/(tpc_mulike_sig->Integral(cut,optimisation_nbins+1) + tpc_mulike_bkg->Integral(cut,optimisation_nbins+1));
      roc_tpc_purvseff_mulike->SetPoint(cut, efficiency, purity);
   }
   roc_tpc_purvseff_mulike->SetLineColor( kBlue);
   roc_tpc_purvseff_mulike->SetLineStyle( kDashed);
   roc_tpc_purvseff_mulike->SetFillColor( kWhite);
   roc_tpc_purvseff_mulike->SetLineWidth(2);
   roc_tpc_purvseff_mulike->Write();
   tpc_mulike_sig->Write();
   tpc_mulike_bkg->Write();
   
   TGraph* roc_tpc_purvseff_pilike = new TGraph();
   roc_tpc_purvseff_pilike->SetTitle("TPC #pi likelihood");
   
   for (Int_t cut = 0; cut <= optimisation_nbins; cut++)
   {
      Float_t efficiency = tpc_pilike_sig->Integral(cut,optimisation_nbins+1)/tpc_pilike_sig->GetEntries();
      Float_t purity = tpc_pilike_sig->Integral(cut,optimisation_nbins+1)/(tpc_pilike_sig->Integral(cut,optimisation_nbins+1) + tpc_pilike_bkg->Integral(cut,optimisation_nbins+1));
      roc_tpc_purvseff_pilike->SetPoint(cut, efficiency, purity);
   }
   roc_tpc_purvseff_pilike->SetLineColor( kRed);
   roc_tpc_purvseff_pilike->SetLineStyle( kDashed);
   roc_tpc_purvseff_pilike->SetFillColor( kWhite);
   roc_tpc_purvseff_pilike->SetLineWidth(2);
   roc_tpc_purvseff_pilike->Write();
   tpc_pilike_sig->Write();
   tpc_pilike_bkg->Write();
   
   TGraph* roc_tpc_purvseff_plike = new TGraph();
   roc_tpc_purvseff_plike->SetTitle("TPC p likelihood");
   
   for (Int_t cut = 0; cut <= optimisation_nbins; cut++)
   {
      Float_t efficiency = tpc_plike_sig->Integral(cut,optimisation_nbins+1)/tpc_plike_sig->GetEntries();
      Float_t purity = tpc_plike_sig->Integral(cut,optimisation_nbins+1)/(tpc_plike_sig->Integral(cut,optimisation_nbins+1) + tpc_plike_bkg->Integral(cut,optimisation_nbins+1));
      roc_tpc_purvseff_plike->SetPoint(cut, efficiency, purity);
   }
   roc_tpc_purvseff_plike->SetLineColor( kGreen);
   roc_tpc_purvseff_plike->SetLineStyle( kDashed);
   roc_tpc_purvseff_plike->SetFillColor( kWhite);
   roc_tpc_purvseff_plike->SetLineWidth(2);
   roc_tpc_purvseff_plike->Write();
   tpc_plike_sig->Write();
   tpc_plike_bkg->Write();
   //std::cout << "DEBUG: tpc_plike_sig->GetEntries() = " << tpc_plike_sig->GetEntries() << std::endl;
   //std::cout << "DEBUG: tpc_plike_sig->Integral(-1,optimisation_nbins+1) = " << tpc_plike_sig->Integral(-1,optimisation_nbins+1) << std::endl;
   
   TGraph* roc_tpc_purvseff_elike = new TGraph();
   roc_tpc_purvseff_elike->SetTitle("TPC e likelihood");
   
   for (Int_t cut = 0; cut <= optimisation_nbins; cut++)
   {
      Float_t efficiency = tpc_elike_sig->Integral(cut,optimisation_nbins+1)/tpc_elike_sig->GetEntries();
      Float_t purity = tpc_elike_sig->Integral(cut,optimisation_nbins+1)/(tpc_elike_sig->Integral(cut,optimisation_nbins+1) + tpc_elike_bkg->Integral(cut,optimisation_nbins+1));
      roc_tpc_purvseff_elike->SetPoint(cut, efficiency, purity);
   }
   roc_tpc_purvseff_elike->SetLineColor( kMagenta);
   roc_tpc_purvseff_elike->SetLineStyle( kDashed);
   roc_tpc_purvseff_elike->SetFillColor( kWhite);
   roc_tpc_purvseff_elike->SetLineWidth(2);
   roc_tpc_purvseff_elike->Write();
   tpc_elike_sig->Write();
   tpc_elike_bkg->Write();
   
   TGraph* roc_antinumu_primary_pid = new TGraph();
   roc_antinumu_primary_pid->SetTitle("#bar{#nu}_{#mu} selection primary PID");
   roc_antinumu_primary_pid->SetPoint(0, (Float_t) antinumu_primary_pid_sig/presel_nAntimu, (Float_t) antinumu_primary_pid_sig/(antinumu_primary_pid_sig+antinumu_primary_pid_bkg));
   roc_antinumu_primary_pid->SetMarkerStyle(22);
   roc_antinumu_primary_pid->SetMarkerSize(1.7);
   roc_antinumu_primary_pid->SetMarkerColor(kBlue);
   roc_antinumu_primary_pid->SetFillColor( kWhite);
   roc_antinumu_primary_pid->SetLineColor( kWhite);
   roc_antinumu_primary_pid->SetLineWidth(22);
   std::cout << "DEBUG: antinumu primary PID efficiency = " << (Float_t) antinumu_primary_pid_sig/presel_nAntimu << std::endl;
   std::cout << "DEBUG: antinumu primary PID purity = " << (Float_t) antinumu_primary_pid_sig/(antinumu_primary_pid_sig+antinumu_primary_pid_bkg) << std::endl;
   
   TGraph* roc_antinumu_improved_pid = new TGraph();
   roc_antinumu_improved_pid->SetTitle("#bar{#nu}_{#mu} selection primary PID + ECal cut");
   roc_antinumu_improved_pid->SetPoint(0, (Float_t) antinumu_improved_pid_sig/presel_nAntimu, (Float_t) antinumu_improved_pid_sig/(antinumu_improved_pid_sig+antinumu_improved_pid_bkg));
   roc_antinumu_improved_pid->SetMarkerStyle(29);
   roc_antinumu_improved_pid->SetMarkerSize(1.7);
   roc_antinumu_improved_pid->SetMarkerColor(kBlue);
   roc_antinumu_improved_pid->SetFillColor( kWhite);
   roc_antinumu_improved_pid->SetLineColor( kWhite);
   roc_antinumu_improved_pid->SetLineWidth(2);
   std::cout << "DEBUG: antinumu improved PID efficiency = " << (Float_t) antinumu_improved_pid_sig/presel_nAntimu << std::endl;
   std::cout << "DEBUG: antinumu improved PID purity = " << (Float_t) antinumu_improved_pid_sig/(antinumu_improved_pid_sig+antinumu_improved_pid_bkg) << std::endl;
   
   TGraph* roc_antinue_primary_pid = new TGraph();
   roc_antinue_primary_pid->SetTitle("#bar{#nu}_{e} selection primary PID");
   roc_antinue_primary_pid->SetPoint(0, (Float_t) antinue_primary_pid_sig/presel_nPositron, (Float_t) antinue_primary_pid_sig/(antinue_primary_pid_sig+antinue_primary_pid_bkg));
   roc_antinue_primary_pid->SetMarkerStyle(22);
   roc_antinue_primary_pid->SetMarkerSize(1.7);
   roc_antinue_primary_pid->SetMarkerColor(kMagenta);
   roc_antinue_primary_pid->SetFillColor( kWhite);
   roc_antinue_primary_pid->SetLineColor( kWhite);
   roc_antinue_primary_pid->SetLineWidth(2);
   std::cout << "DEBUG: antinue primary PID efficiency = " << (Float_t) antinue_primary_pid_sig/presel_nPositron << std::endl;
   std::cout << "DEBUG: antinue primary PID purity = " << (Float_t) antinue_primary_pid_sig/(antinue_primary_pid_sig+antinue_primary_pid_bkg) << std::endl;
   
   TCanvas* canvas_roc_mu = new TCanvas("canvas_roc_mu","mu-like ROC curves",200,10,1000,600);
   roc_purvseff_mulike->Draw();
   roc_purvseff_mulike->GetXaxis()->SetLimits(0.0,1.1);
   roc_purvseff_mulike->GetXaxis()->SetTitle("Efficiency");
   roc_purvseff_mulike->GetYaxis()->SetLimits(0.0,1.1);
   roc_purvseff_mulike->GetYaxis()->SetTitle("Purity");
   roc_purvseff_mulike->GetYaxis()->SetTitleOffset(0.9);
   roc_purvseff_mulike->Draw();
   roc_tpc_purvseff_mulike->Draw("same");
   roc_antinumu_primary_pid->Draw("P same");
   roc_antinumu_improved_pid->Draw("P same");
   canvas_roc_mu->BuildLegend();
   canvas_roc_mu->Write();
   
   TCanvas* canvas_roc_pi = new TCanvas("canvas_roc_pi","pi-like ROC curves",200,10,1000,600);
   roc_purvseff_pilike->Draw();
   roc_purvseff_pilike->GetXaxis()->SetLimits(0.0,1.1);
   roc_purvseff_pilike->GetXaxis()->SetTitle("Efficiency");
   roc_purvseff_pilike->GetYaxis()->SetLimits(0.0,1.1);
   roc_purvseff_pilike->GetYaxis()->SetTitle("Purity");
   roc_purvseff_pilike->GetYaxis()->SetTitleOffset(0.9);
   roc_purvseff_pilike->Draw();
   roc_tpc_purvseff_pilike->Draw("same");
   canvas_roc_pi->BuildLegend();
   canvas_roc_pi->Write();
   
   TCanvas* canvas_roc_p = new TCanvas("canvas_roc_p","p-like ROC curves",200,10,1000,600);
   roc_purvseff_plike->Draw();
   roc_purvseff_plike->GetXaxis()->SetLimits(0.0,1.1);
   roc_purvseff_plike->GetXaxis()->SetTitle("Efficiency");
   roc_purvseff_plike->GetYaxis()->SetLimits(0.0,1.1);
   roc_purvseff_plike->GetYaxis()->SetTitle("Purity");
   roc_purvseff_plike->GetYaxis()->SetTitleOffset(0.9);
   roc_purvseff_plike->Draw();
   roc_tpc_purvseff_plike->Draw("same");
   canvas_roc_p->BuildLegend();
   canvas_roc_p->Write();
   
   TCanvas* canvas_roc_e = new TCanvas("canvas_roc_e","e-like ROC curves",200,10,1000,600);
   roc_purvseff_elike->Draw();
   roc_purvseff_elike->GetXaxis()->SetLimits(0.0,1.1);
   roc_purvseff_elike->GetXaxis()->SetTitle("Efficiency");
   roc_purvseff_elike->GetYaxis()->SetLimits(0.0,1.1);
   roc_purvseff_elike->GetYaxis()->SetTitle("Purity");
   roc_purvseff_elike->GetYaxis()->SetTitleOffset(0.9);
   roc_purvseff_elike->Draw();
   roc_tpc_purvseff_elike->Draw("same");
   roc_antinue_primary_pid->Draw("P same");
   canvas_roc_e->BuildLegend();
   canvas_roc_e->Write();
   
   TCanvas* canvas_roc_bdtall = new TCanvas("canvas_roc_bdtall","BDT output ROC curves",200,10,1000,600);
   roc_purvseff_mulike->Draw();
   roc_purvseff_pilike->Draw("same");
   roc_purvseff_plike->Draw("same");
   roc_purvseff_elike->Draw("same");
   canvas_roc_bdtall->BuildLegend();
   canvas_roc_bdtall->Write();
   
   // Save TGraphs for KS tests
   
   ks_test_bdt_mulike_pilike_train->Write();
   ks_test_bdt_plike_elike_train->Write();
   
   ks_test_bdt_mulike_pilike_test->Write();
   ks_test_bdt_plike_elike_test->Write();
      
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
