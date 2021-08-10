//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jan  7 11:34:26 2021 by ROOT version 5.34/34
// from TTree default/20
// found on file: ../../output/test.root
//////////////////////////////////////////////////////////

#ifndef defaultAntiNumuCC1pi_h
#define defaultAntiNumuCC1pi_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include <iostream>
#include <string>
#include <vector>

class defaultOut {
public :
  defaultOut(std::string outname);

  void Fill() {fDefaultOut->Fill(); };
  
  void Write()
  {
    fDefaultOut->Write();
    
    fOutFile->Close();
  }

   
  Int_t           evt;
  Int_t           topology;
  Int_t           particle;
  Int_t           ntpcposQualityFV;
  Int_t           ntpcnegQualityFV;
  Int_t           NME;
  Int_t           NFGDPi;
  Int_t           NPi0El;
  Int_t           NPi0Pos;
  
  Float_t         selmu_mom;
  Float_t         selmu_theta;
  
  Int_t           selmu_necals;
  Float_t         selmu_ecal_bestseg_EMenergy;
  Float_t         selmu_ecal_bestseg_mippion;
  Float_t         selmu_ecal_bestseg_EbyL;
  Float_t         selmu_ecal_bestseg_EbyP;
  Float_t         selmu_ecal_amr;
  Float_t         selmu_ecal_angle;
  Float_t         selmu_ecal_asymmetry;
  Float_t         selmu_ecal_circularity;
  Float_t         selmu_ecal_fbr;
  Float_t         selmu_ecal_maxratio;
  Float_t         selmu_ecal_meanpos;
  Float_t         selmu_ecal_showerangle;
  Float_t         selmu_ecal_showerwidth;
  Float_t         selmu_ecal_tcr;
  Float_t         selmu_ecal_tmr;
  
  Float_t         selmu_tpc_like_mu;
  Float_t         selmu_tpc_like_e;
  Float_t         selmu_tpc_like_p;
  Float_t         selmu_tpc_like_pi;
  
  Int_t           selmu_has_fgd1seg;
  Float_t         selmu_fgd1_pull_mu;
  Float_t         selmu_fgd1_pull_p;
  Float_t         selmu_fgd1_pull_pi;
  Float_t         selmu_fgd1_pull_no;
  
  Int_t           selmu_has_fgd2seg;
  Float_t         selmu_fgd2_pull_mu;
  Float_t         selmu_fgd2_pull_p;
  Float_t         selmu_fgd2_pull_pi;
  Float_t         selmu_fgd2_pull_no;
  
  Float_t         HMNT_mom;
  
  Int_t           HMNT_NEcalSegments;
  Float_t         HMNT_ecal_bestseg_EMenergy;
  Float_t         HMNT_ecal_bestseg_mippion;
  Float_t         HMNT_ecal_bestseg_EbyL;
  Float_t         HMNT_ecal_bestseg_EbyP;
  
  Float_t         HMNT_tpc_like_mu;
  Float_t         HMNT_tpc_like_e;
  Float_t         HMNT_tpc_like_p;
  Float_t         HMNT_tpc_like_pi;
  
  Int_t           HMNT_has_fgd1seg;
  Float_t         HMNT_fgd1_pull_mu;
  Float_t         HMNT_fgd1_pull_p;
  Float_t         HMNT_fgd1_pull_pi;
  Float_t         HMNT_fgd1_pull_no;
  
  Int_t           HMNT_has_fgd2seg;
  Float_t         HMNT_fgd2_pull_mu;
  Float_t         HMNT_fgd2_pull_p;
  Float_t         HMNT_fgd2_pull_pi;
  Float_t         HMNT_fgd2_pull_no;

protected:

private:
  TFile *fOutFile;
  TTree *fDefaultOut;
  
  // ----------- Signal training tree -----------
  
  TBranch        *foutb_evt;
  TBranch        *foutb_topology;
  TBranch        *foutb_particle;
  TBranch        *foutb_ntpcposQualityFV;
  TBranch        *foutb_ntpcnegQualityFV;
  TBranch        *foutb_NME;
  TBranch        *foutb_NFGDPi;
  TBranch        *foutb_NPi0El;
  TBranch        *foutb_NPi0Pos;
  
  TBranch        *foutb_selmu_mom;
  TBranch        *foutb_selmu_theta;
  
  TBranch        *foutb_selmu_necals;
  TBranch        *foutb_selmu_ecal_bestseg_EMenergy;
  TBranch        *foutb_selmu_ecal_bestseg_mippion;
  TBranch        *foutb_selmu_ecal_bestseg_EbyL;
  TBranch        *foutb_selmu_ecal_bestseg_EbyP;
  TBranch        *foutb_selmu_ecal_amr;
  TBranch        *foutb_selmu_ecal_angle;
  TBranch        *foutb_selmu_ecal_asymmetry;
  TBranch        *foutb_selmu_ecal_circularity;
  TBranch        *foutb_selmu_ecal_fbr;
  TBranch        *foutb_selmu_ecal_maxratio;
  TBranch        *foutb_selmu_ecal_meanpos;
  TBranch        *foutb_selmu_ecal_showerangle;
  TBranch        *foutb_selmu_ecal_showerwidth;
  TBranch        *foutb_selmu_ecal_tcr;
  TBranch        *foutb_selmu_ecal_tmr;
  
  TBranch        *foutb_selmu_tpc_like_mu;
  TBranch        *foutb_selmu_tpc_like_e;
  TBranch        *foutb_selmu_tpc_like_p;
  TBranch        *foutb_selmu_tpc_like_pi;
  
  TBranch        *foutb_selmu_has_fgd1seg;
  TBranch        *foutb_selmu_fgd1_pull_mu;
  TBranch        *foutb_selmu_fgd1_pull_p;
  TBranch        *foutb_selmu_fgd1_pull_pi;
  TBranch        *foutb_selmu_fgd1_pull_no;
  
  TBranch        *foutb_selmu_has_fgd2seg;
  TBranch        *foutb_selmu_fgd2_pull_mu;
  TBranch        *foutb_selmu_fgd2_pull_p;
  TBranch        *foutb_selmu_fgd2_pull_pi;
  TBranch        *foutb_selmu_fgd2_pull_no;
  
  TBranch        *foutb_HMNT_mom;
  
  TBranch        *foutb_HMNT_NEcalSegments;
  TBranch        *foutb_HMNT_ecal_bestseg_EMenergy;
  TBranch        *foutb_HMNT_ecal_bestseg_mippion;
  TBranch        *foutb_HMNT_ecal_bestseg_EbyL;
  TBranch        *foutb_HMNT_ecal_bestseg_EbyP;
  
  TBranch        *foutb_HMNT_tpc_like_mu;
  TBranch        *foutb_HMNT_tpc_like_e;
  TBranch        *foutb_HMNT_tpc_like_p;
  TBranch        *foutb_HMNT_tpc_like_pi;
  
  TBranch        *foutb_HMNT_has_fgd1seg;
  TBranch        *foutb_HMNT_fgd1_pull_mu;
  TBranch        *foutb_HMNT_fgd1_pull_p;
  TBranch        *foutb_HMNT_fgd1_pull_pi;
  TBranch        *foutb_HMNT_fgd1_pull_no;
  
  TBranch        *foutb_HMNT_has_fgd2seg;
  TBranch        *foutb_HMNT_fgd2_pull_mu;
  TBranch        *foutb_HMNT_fgd2_pull_p;
  TBranch        *foutb_HMNT_fgd2_pull_pi;
  TBranch        *foutb_HMNT_fgd2_pull_no;
  
};

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class defaultAntiNumuCC1pi {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           NTOYS;
   Int_t           toy_index[1];   //[NTOYS]
   Float_t         toy_weight[1];   //[NTOYS]
   Int_t           entry;
   Int_t           toy_ref;
   Int_t           CCBwdMigrated;
   Int_t           detector;
   Int_t           fgd2CCBwdMigrated;
   Int_t           fgd2detector;
   Int_t           fgd2gparent;
   Int_t           fgd2mectopology;
   Int_t           fgd2nuparent;
   Int_t           fgd2nutype;
   Int_t           fgd2parent;
   Int_t           fgd2particle;
   Int_t           fgd2particle_detector;
   Int_t           fgd2primary;
   Int_t           fgd2reaction;
   Int_t           fgd2reactionCC;
   Int_t           fgd2reactionnofv;
   Int_t           fgd2target;
   Int_t           fgd2topology;
   Int_t           fgd2topology_ccpizero;
   Int_t           fgd2topology_no1pi;
   Int_t           fgd2topology_withpi0;
   Int_t           gparent;
   Int_t           mectopology;
   Int_t           nuparent;
   Int_t           nutype;
   Int_t           parent;
   Int_t           particle;
   Int_t           particle_detector;
   Int_t           primary;
   Int_t           reaction;
   Int_t           reactionCC;
   Int_t           reactionnofv;
   Int_t           target;
   Int_t           topology;
   Int_t           topology_ccpizero;
   Int_t           topology_no1pi;
   Int_t           topology_withpi0;
   Int_t           redo[1];   //[NTOYS]
   Int_t           accum_level[1][3];   //[NTOYS]
   Int_t           cut0[1][3];   //[NTOYS]
   Int_t           cut1[1][3];   //[NTOYS]
   Int_t           cut2[1][3];   //[NTOYS]
   Int_t           cut3[1][3];   //[NTOYS]
   Int_t           cut4[1][3];   //[NTOYS]
   Int_t           cut5[1][3];   //[NTOYS]
   Int_t           cut6[1][3];   //[NTOYS]
   Int_t           cut7[1][3];   //[NTOYS]
   Int_t           cut8[1][3];   //[NTOYS]
   Int_t           cut9[1][3];   //[NTOYS]
   Float_t         weight_syst;
   Float_t         weight_syst_total;
   Float_t         weight_corr;
   Float_t         weight_corr_total;
   Int_t           NWEIGHTSYST;
   Int_t           run;
   Int_t           subrun;
   Int_t           evt;
   Int_t           evt_time;
   Int_t           bunch;
   Int_t           TruthVertexID[1];   //[NTOYS]
   Int_t           RooVtxIndex[1];   //[NTOYS]
   Int_t           RooVtxEntry[1];   //[NTOYS]
   Int_t           RooVtxEntry2;
   Int_t           RooVtxFile;
   Int_t           nu_pdg;
   Float_t         nu_trueE;
   Int_t           nu_truereac;
   Float_t         nu_truedir[3];
   Float_t         true_V;
   Float_t         true_Q2;
   Float_t         true_X;
   Float_t         true_Y;
   Float_t         true_W;
   Int_t           selvtx_det;
   Float_t         selvtx_pos[4];
   Float_t         selvtx_truepos[4];
   Int_t           true_signal[1];   //[NTOYS]
   Int_t           sample[1];   //[NTOYS]
   Int_t           ntpctracks;
   Int_t           ntpcposQualityFV;
   Int_t           ntpcnegQualityFV;
   Int_t           nfgdtracks;
   Int_t           nfgdonlytracks;
   Float_t         selmu_truemom;
   Float_t         selmu_truepos[4];
   Float_t         selmu_trueendpos[4];
   Float_t         selmu_truedir[3];
   Int_t           truelepton_pdg;
   Float_t         truelepton_mom;
   Float_t         truelepton_costheta;
   Float_t         selmu_dir[3];
   Float_t         selmu_enddir[3];
   Float_t         selmu_pos[4];
   Float_t         selmu_endpos[4];
   Int_t           selmu_closest_tpc;
   Int_t           selmu_detectors;
   Int_t           selmu_det;
   Float_t         selmu_mom[1];   //[NTOYS]
   Float_t         selmu_costheta[1];   //[NTOYS]
   Float_t         selmu_nuErecQE[1];   //[NTOYS]
   Float_t         truelepton_nuErecQE;
   Float_t         selmu_amom;
   Float_t         selmu_likemu;
   Float_t         selmu_likemip;
   Float_t         shmn_mom;
   Int_t           selmu_ntpcs;
   Int_t           selmu_tpc_det[2];   //[selmu_ntpcs]
   Int_t           selmu_tpc_nhits[2];   //[selmu_ntpcs]
   Int_t           selmu_tpc_nnodes[2];   //[selmu_ntpcs]
   Float_t         selmu_tpc_charge[2];   //[selmu_ntpcs]
   Float_t         selmu_tpc_mom[2];   //[selmu_ntpcs]
   Float_t         selmu_tpc_bfield_mom[2];   //[selmu_ntpcs]
   Float_t         selmu_tpc_efield_mom[2];   //[selmu_ntpcs]
   Float_t         selmu_tpc_emom[2];   //[selmu_ntpcs]
   Float_t         selmu_tpc_truemom[2];   //[selmu_ntpcs]
   Float_t         selmu_tpc_startpos[2][4];   //[selmu_ntpcs]
   Float_t         selmu_tpc_startdir[2][3];   //[selmu_ntpcs]
   Float_t         selmu_tpc_endpos[2][4];   //[selmu_ntpcs]
   Float_t         selmu_tpc_enddir[2][3];   //[selmu_ntpcs]
   Float_t         selmu_tpc_dedx_raw[2];   //[selmu_ntpcs]
   Float_t         selmu_tpc_dedx_expmu[2];   //[selmu_ntpcs]
   Float_t         selmu_tpc_dedx_exppi[2];   //[selmu_ntpcs]
   Float_t         selmu_tpc_dedx_expele[2];   //[selmu_ntpcs]
   Float_t         selmu_tpc_dedx_expp[2];   //[selmu_ntpcs]
   Float_t         selmu_tpc_dedx_exp_sigmamu[2];   //[selmu_ntpcs]
   Float_t         selmu_tpc_dedx_exp_sigmapi[2];   //[selmu_ntpcs]
   Float_t         selmu_tpc_dedx_exp_sigmaele[2];   //[selmu_ntpcs]
   Float_t         selmu_tpc_dedx_exp_sigmap[2];   //[selmu_ntpcs]
   Float_t         selmu_tpc_pullmu[2];   //[selmu_ntpcs]
   Float_t         selmu_tpc_pullpi[2];   //[selmu_ntpcs]
   Float_t         selmu_tpc_pullele[2];   //[selmu_ntpcs]
   Float_t         selmu_tpc_pullp[2];   //[selmu_ntpcs]
   Float_t         selmu_tpc_dedx[2];   //[selmu_ntpcs]
   Int_t           selmu_nfgds;
   Int_t           selmu_fgd_det[2];   //[selmu_nfgds]
   Float_t         selmu_fgd_x[2];   //[selmu_nfgds]
   Float_t         selmu_fgd_V11[2];   //[selmu_nfgds]
   Float_t         selmu_fgd_V33[2];   //[selmu_nfgds]
   Float_t         selmu_fgd_V55[2];   //[selmu_nfgds]
   Float_t         selmu_fgd_V77[2];   //[selmu_nfgds]
   Float_t         selmu_fgd_VLayer[2];   //[selmu_nfgds]
   Float_t         selmu_fgd_pullmu[2];   //[selmu_nfgds]
   Int_t           selmu_necals;
   Int_t           selmu_ecal_det[1];   //[selmu_necals]
   Int_t           selmu_ecal_nhits[1];   //[selmu_necals]
   Int_t           selmu_ecal_nnodes[1];   //[selmu_necals]
   Float_t         selmu_ecal_length[1];   //[selmu_necals]
   Float_t         selmu_ecal_showerstartpos[1][4];   //[selmu_necals]
   Float_t         selmu_ecal_showerendpos[1][4];   //[selmu_necals]
   Float_t         selmu_ecal_showerstartdir[1][3];   //[selmu_necals]
   Float_t         selmu_ecal_showerenddir[1][3];   //[selmu_necals]
   Float_t         selmu_ecal_EMenergy[1];   //[selmu_necals]
   Float_t         selmu_ecal_edeposit[1];   //[selmu_necals]
   Int_t           selmu_ecal_IsShower[1];   //[selmu_necals]
   Float_t         selmu_ecal_mipem[1];   //[selmu_necals]
   Float_t         selmu_ecal_mippion[1];   //[selmu_necals]
   Float_t         selmu_ecal_emhip[1];   //[selmu_necals]
   Float_t         selmu_ecal_containment[1];   //[selmu_necals]
   Int_t           selmu_ecal_mostupstreamlayerhit[1];   //[selmu_necals]
   Int_t           selmu_nsmrds;
   Int_t           selmu_smrd_det[2];   //[selmu_nsmrds]
   Int_t           selmu_smrd_nhits[2];   //[selmu_nsmrds]
   Int_t           selmu_smrd_nnodes[2];   //[selmu_nsmrds]
   Float_t         selmu_smrd_dir[2][3];   //[selmu_nsmrds]
   Float_t         selmu_smrd_enddir[2][3];   //[selmu_nsmrds]
   Float_t         selmu_smrd_edeposit[2];   //[selmu_nsmrds]
   Int_t           truevtx_mass_component[1];   //[NTOYS]
   Int_t           MuonVertexId;
   Int_t           MuonIndex;
   Float_t         NegPionMom[1][450];   //[NTOYS]
   Float_t         NegPionTheta[1][450];   //[NTOYS]
   Int_t           NNegPion;
   Float_t         NegPionPidLik[2];   //[NNegPion]
   Float_t         NegPionMipPidLik[2];   //[NNegPion]
   Int_t           NegPionTId[2];   //[NNegPion]
   Int_t           NegPionIndex[2];   //[NNegPion]
   Int_t           NegPionParentTId[2];   //[NNegPion]
   Int_t           NegPionGParentTId[2];   //[NNegPion]
   Float_t         NegPionTrueMom[2];   //[NNegPion]
   Float_t         NegPionTrueStartDir[2][3];   //[NNegPion]
   Int_t           NegPionVId[2];   //[NNegPion]
   Float_t         NegPionDir[2][3];   //[NNegPion]
   Float_t         NegPionPosStart[2][3];   //[NNegPion]
   Float_t         NegPionPosEnd[2][3];   //[NNegPion]
   Float_t         PosPionMom[1][465];   //[NTOYS]
   Float_t         PosPionTheta[1][465];   //[NTOYS]
   Int_t           NPosPion;
   Float_t         PosPionPidLik[1];   //[NPosPion]
   Float_t         PosPionMipPidLik[1];   //[NPosPion]
   Int_t           PosPionTId[1];   //[NPosPion]
   Int_t           PosPionIndex[1];   //[NPosPion]
   Int_t           PosPionParentTId[1];   //[NPosPion]
   Int_t           PosPionGParentTId[1];   //[NPosPion]
   Float_t         PosPionTrueMom[1];   //[NPosPion]
   Float_t         PosPionTrueStartDir[1][3];   //[NPosPion]
   Int_t           PosPionVId[1];   //[NPosPion]
   Float_t         PosPionDir[1][3];   //[NPosPion]
   Float_t         PosPionPosStart[1][3];   //[NPosPion]
   Float_t         PosPionPosEnd[1][3];   //[NPosPion]
   Int_t           NPi0El;
   Float_t         Pi0ElMom[3];   //[NPi0El]
   Float_t         Pi0ElPull[3];   //[NPi0El]
   Int_t           Pi0ElTId[3];   //[NPi0El]
   Int_t           Pi0ElIndex[3];   //[NPi0El]
   Int_t           Pi0ElParentTId[3];   //[NPi0El]
   Int_t           Pi0ElGParentTId[3];   //[NPi0El]
   Int_t           Pi0ElVId[3];   //[NPi0El]
   Float_t         Pi0ElDir[3][3];   //[NPi0El]
   Float_t         Pi0ElPosStart[3][3];   //[NPi0El]
   Float_t         Pi0ElPosEnd[3][3];   //[NPi0El]
   Int_t           NPi0Pos;
   Float_t         Pi0PosMom[2];   //[NPi0Pos]
   Float_t         Pi0PosPull[2];   //[NPi0Pos]
   Int_t           Pi0PosTId[2];   //[NPi0Pos]
   Int_t           Pi0PosIndex[2];   //[NPi0Pos]
   Int_t           Pi0PosParentTId[2];   //[NPi0Pos]
   Int_t           Pi0PosGParentTId[2];   //[NPi0Pos]
   Int_t           Pi0PosVId[2];   //[NPi0Pos]
   Float_t         Pi0PosDir[2][3];   //[NPi0Pos]
   Float_t         Pi0PosPosStart[2][3];   //[NPi0Pos]
   Float_t         Pi0PosPosEnd[2][3];   //[NPi0Pos]
   Int_t           NTPCSec;
   Float_t         TPCSecMom[5];   //[NTPCSec]
   Float_t         TPCSecMuPidLik[5];   //[NTPCSec]
   Float_t         TPCSecPiPidLik[5];   //[NTPCSec]
   Float_t         TPCSecPrPidLik[5];   //[NTPCSec]
   Float_t         TPCSecElPidLik[5];   //[NTPCSec]
   Int_t           TPCSecDetectors[5];   //[NTPCSec]
   Int_t           TPCSecQ[5];   //[NTPCSec]
   Int_t           TPCSecTId[5];   //[NTPCSec]
   Int_t           TPCSecIndex[5];   //[NTPCSec]
   Int_t           TPCSecParentTId[5];   //[NTPCSec]
   Int_t           TPCSecGParentTId[5];   //[NTPCSec]
   Float_t         TPCSecDir[5][3];   //[NTPCSec]
   Float_t         TPCSecPosStart[5][3];   //[NTPCSec]
   Float_t         TPCSecPosEnd[5][3];   //[NTPCSec]
   Int_t           NFGDPi;
   Float_t         FGDPiLength[1];   //[NFGDPi]
   Float_t         FGDPiPiPull[1];   //[NFGDPi]
   Float_t         FGDPiAvgTime[1];   //[NFGDPi]
   Float_t         FGDPiDistance[1];   //[NFGDPi]
   Float_t         FGDPiMuonangle[1];   //[NFGDPi]
   Float_t         FGDPiCosTheta[1];   //[NFGDPi]
   Int_t           FGDPiTId[1];   //[NFGDPi]
   Int_t           FGDPiIndex[1];   //[NFGDPi]
   Int_t           FGDPiParentTId[1];   //[NFGDPi]
   Int_t           FGDPiGParentTId[1];   //[NFGDPi]
   Int_t           FGDPiVId[1];   //[NFGDPi]
   Float_t         FGDPiDir[1][3];   //[NFGDPi]
   Float_t         FGDPiPosStart[1][3];   //[NFGDPi]
   Float_t         FGDPiPosEnd[1][3];   //[NFGDPi]
   Float_t         FGDPiTimeIni[1];   //[NFGDPi]
   Float_t         FGDPiTimeEnd[1];   //[NFGDPi]
   Float_t         FGDPiDeltaTimeIniSelMu[1];   //[NFGDPi]
   Float_t         FGDPiDeltaTimeEndSelMu[1];   //[NFGDPi]
   Int_t           NFGDEl;
   Float_t         FGDElLength[3];   //[NFGDEl]
   Float_t         FGDElPiPull[3];   //[NFGDEl]
   Float_t         FGDElAvgTime[3];   //[NFGDEl]
   Int_t           FGDElTId[3];   //[NFGDEl]
   Int_t           FGDElIndex[3];   //[NFGDEl]
   Int_t           FGDElParentTId[3];   //[NFGDEl]
   Int_t           FGDElGParentTId[3];   //[NFGDEl]
   Int_t           FGDElVId[3];   //[NFGDEl]
   Float_t         FGDElTimeIni[3];   //[NFGDEl]
   Float_t         FGDElTimeEnd[3];   //[NFGDEl]
   Float_t         FGDElDeltaTimeIniSelMu[3];   //[NFGDEl]
   Float_t         FGDElDeltaTimeEndSelMu[3];   //[NFGDEl]
   Float_t         FGDElDistance[3];   //[NFGDEl]
   Float_t         FGDElMuonangle[3];   //[NFGDEl]
   Float_t         FGDElCosTheta[3];   //[NFGDEl]
   Float_t         FGDElDir[3][3];   //[NFGDEl]
   Float_t         FGDElPosStart[3][3];   //[NFGDEl]
   Float_t         FGDElPosEnd[3][3];   //[NFGDEl]
   Int_t           NFGDSec;
   Float_t         FGDSecLength[8];   //[NFGDSec]
   Float_t         FGDSecPiPull[8];   //[NFGDSec]
   Float_t         FGDSecAvgTime[8];   //[NFGDSec]
   Int_t           FGDSecContained[8];   //[NFGDSec]
   Int_t           FGDSecTId[8];   //[NFGDSec]
   Int_t           FGDSecIndex[8];   //[NFGDSec]
   Int_t           FGDSecParentTId[8];   //[NFGDSec]
   Int_t           FGDSecGParentTId[8];   //[NFGDSec]
   Float_t         FGDSecTimeIni[8];   //[NFGDSec]
   Float_t         FGDSecTimeEnd[8];   //[NFGDSec]
   Float_t         FGDSecDeltaTimeIniSelMu[8];   //[NFGDSec]
   Float_t         FGDSecDeltaTimeEndSelMu[8];   //[NFGDSec]
   Float_t         FGDSecCosTheta[8];   //[NFGDSec]
   Float_t         FGDSecDir[8][3];   //[NFGDSec]
   Float_t         FGDSecPosStart[8][3];   //[NFGDSec]
   Float_t         FGDSecPosEnd[8][3];   //[NFGDSec]
   Int_t           NME;
   Int_t           MENHits[1];   //[NME]
   Float_t         MERawCharge[1];   //[NME]
   Float_t         MEMinTime[1];   //[NME]
   Float_t         MEMaxTime[1];   //[NME]
   Int_t           NTPC1Track;
   Float_t         TPC1TrackMom[6];   //[NTPC1Track]
   Float_t         TPC1TrackCosTheta[6];   //[NTPC1Track]
   Float_t         TPC1TrackPhi[6];   //[NTPC1Track]
   Int_t           TPC1TrackVId[6];   //[NTPC1Track]
   Int_t           TPC1TrackTId[6];   //[NTPC1Track]
   Int_t           TPC1TrackParentTId[6];   //[NTPC1Track]
   Int_t           TPC1TrackGParentTId[6];   //[NTPC1Track]
   Float_t         TPC1TrackPosStart[6][3];   //[NTPC1Track]
   Float_t         TPC1TrackPosEnd[6][3];   //[NTPC1Track]
   Float_t         truepi_mom;
   Float_t         truepi_costheta;
   Float_t         truepi_dir[3];
   Int_t           truepi_id;
   Int_t           truepi_pdg;
   Float_t         selmu_tpc_like_mu;
   Float_t         selmu_tpc_like_e;
   Float_t         selmu_tpc_like_p;
   Float_t         selmu_tpc_like_pi;
   Int_t           selmu_has_fgd1seg;
   Float_t         selmu_fgd1_pull_mu;
   Float_t         selmu_fgd1_pull_e;
   Float_t         selmu_fgd1_pull_p;
   Float_t         selmu_fgd1_pull_pi;
   Float_t         selmu_fgd1_pull_no;
   Int_t           selmu_has_fgd2seg;
   Float_t         selmu_fgd2_pull_mu;
   Float_t         selmu_fgd2_pull_e;
   Float_t         selmu_fgd2_pull_p;
   Float_t         selmu_fgd2_pull_pi;
   Float_t         selmu_fgd2_pull_no;
   Float_t         selmu_ecal_bestseg_EMenergy;
   Float_t         selmu_ecal_bestseg_mippion;
   Float_t         selmu_ecal_bestseg_EbyL;
   Float_t         selmu_ecal_amr;
   Float_t         selmu_ecal_angle;
   Float_t         selmu_ecal_asymmetry;
   Float_t         selmu_ecal_circularity;
   Float_t         selmu_ecal_fbr;
   Float_t         selmu_ecal_maxratio;
   Float_t         selmu_ecal_meanpos;
   Float_t         selmu_ecal_showerangle;
   Float_t         selmu_ecal_showerwidth;
   Float_t         selmu_ecal_tcr;
   Float_t         selmu_ecal_tmr;
   Float_t         HMNT_mom;
   Float_t         HMNT_costheta;
   Int_t           HMNT_pdg;
   Int_t           HMNT_truepdg;
   Int_t           HMNT_NEcalSegments;
   Float_t         HMNT_ecal_EMenergy;
   Float_t         HMNT_ecal_length;
   Float_t         HMNT_ecal_mippion;
   Float_t         HMNT_ecal_angle;
   Float_t         HMNT_ecal_bestseg_EMenergy;
   Float_t         HMNT_ecal_bestseg_mippion;
   Float_t         HMNT_ecal_bestseg_EbyL;
   Float_t         HMNT_tpc_like_mu;
   Float_t         HMNT_tpc_like_e;
   Float_t         HMNT_tpc_like_p;
   Float_t         HMNT_tpc_like_pi;
   Int_t           HMNT_has_fgd1seg;
   Float_t         HMNT_fgd1_pull_mu;
   Float_t         HMNT_fgd1_pull_e;
   Float_t         HMNT_fgd1_pull_p;
   Float_t         HMNT_fgd1_pull_pi;
   Float_t         HMNT_fgd1_pull_no;
   Int_t           HMNT_has_fgd2seg;
   Float_t         HMNT_fgd2_pull_mu;
   Float_t         HMNT_fgd2_pull_e;
   Float_t         HMNT_fgd2_pull_p;
   Float_t         HMNT_fgd2_pull_pi;
   Float_t         HMNT_fgd2_pull_no;

   // List of branches
   TBranch        *b_NTOYS;   //!
   TBranch        *b_toy_index;   //!
   TBranch        *b_toy_weight;   //!
   TBranch        *b_entry;   //!
   TBranch        *b_toy_ref;   //!
   TBranch        *b_CCBwdMigrated;   //!
   TBranch        *b_detector;   //!
   TBranch        *b_fgd2CCBwdMigrated;   //!
   TBranch        *b_fgd2detector;   //!
   TBranch        *b_fgd2gparent;   //!
   TBranch        *b_fgd2mectopology;   //!
   TBranch        *b_fgd2nuparent;   //!
   TBranch        *b_fgd2nutype;   //!
   TBranch        *b_fgd2parent;   //!
   TBranch        *b_fgd2particle;   //!
   TBranch        *b_fgd2particle_detector;   //!
   TBranch        *b_fgd2primary;   //!
   TBranch        *b_fgd2reaction;   //!
   TBranch        *b_fgd2reactionCC;   //!
   TBranch        *b_fgd2reactionnofv;   //!
   TBranch        *b_fgd2target;   //!
   TBranch        *b_fgd2topology;   //!
   TBranch        *b_fgd2topology_ccpizero;   //!
   TBranch        *b_fgd2topology_no1pi;   //!
   TBranch        *b_fgd2topology_withpi0;   //!
   TBranch        *b_gparent;   //!
   TBranch        *b_mectopology;   //!
   TBranch        *b_nuparent;   //!
   TBranch        *b_nutype;   //!
   TBranch        *b_parent;   //!
   TBranch        *b_particle;   //!
   TBranch        *b_particle_detector;   //!
   TBranch        *b_primary;   //!
   TBranch        *b_reaction;   //!
   TBranch        *b_reactionCC;   //!
   TBranch        *b_reactionnofv;   //!
   TBranch        *b_target;   //!
   TBranch        *b_topology;   //!
   TBranch        *b_topology_ccpizero;   //!
   TBranch        *b_topology_no1pi;   //!
   TBranch        *b_topology_withpi0;   //!
   TBranch        *b_redo;   //!
   TBranch        *b_accum_level;   //!
   TBranch        *b_cut0;   //!
   TBranch        *b_cut1;   //!
   TBranch        *b_cut2;   //!
   TBranch        *b_cut3;   //!
   TBranch        *b_cut4;   //!
   TBranch        *b_cut5;   //!
   TBranch        *b_cut6;   //!
   TBranch        *b_cut7;   //!
   TBranch        *b_cut8;   //!
   TBranch        *b_cut9;   //!
   TBranch        *b_weight_syst;   //!
   TBranch        *b_weight_syst_total;   //!
   TBranch        *b_weight_corr;   //!
   TBranch        *b_weight_corr_total;   //!
   TBranch        *b_NWEIGHTSYST;   //!
   TBranch        *b_run;   //!
   TBranch        *b_subrun;   //!
   TBranch        *b_evt;   //!
   TBranch        *b_evt_time;   //!
   TBranch        *b_bunch;   //!
   TBranch        *b_TruthVertexID;   //!
   TBranch        *b_RooVtxIndex;   //!
   TBranch        *b_RooVtxEntry;   //!
   TBranch        *b_RooVtxEntry2;   //!
   TBranch        *b_RooVtxFile;   //!
   TBranch        *b_nu_pdg;   //!
   TBranch        *b_nu_trueE;   //!
   TBranch        *b_nu_truereac;   //!
   TBranch        *b_nu_truedir;   //!
   TBranch        *b_true_V;   //!
   TBranch        *b_true_Q2;   //!
   TBranch        *b_true_X;   //!
   TBranch        *b_true_Y;   //!
   TBranch        *b_true_W;   //!
   TBranch        *b_selvtx_det;   //!
   TBranch        *b_selvtx_pos;   //!
   TBranch        *b_selvtx_truepos;   //!
   TBranch        *b_true_signal;   //!
   TBranch        *b_sample;   //!
   TBranch        *b_ntpctracks;   //!
   TBranch        *b_ntpcposQualityFV;   //!
   TBranch        *b_ntpcnegQualityFV;   //!
   TBranch        *b_nfgdtracks;   //!
   TBranch        *b_nfgdonlytracks;   //!
   TBranch        *b_selmu_truemom;   //!
   TBranch        *b_selmu_truepos;   //!
   TBranch        *b_selmu_trueendpos;   //!
   TBranch        *b_selmu_truedir;   //!
   TBranch        *b_truelepton_pdg;   //!
   TBranch        *b_truelepton_mom;   //!
   TBranch        *b_truelepton_costheta;   //!
   TBranch        *b_selmu_dir;   //!
   TBranch        *b_selmu_enddir;   //!
   TBranch        *b_selmu_pos;   //!
   TBranch        *b_selmu_endpos;   //!
   TBranch        *b_selmu_closest_tpc;   //!
   TBranch        *b_selmu_detectors;   //!
   TBranch        *b_selmu_det;   //!
   TBranch        *b_selmu_mom;   //!
   TBranch        *b_selmu_costheta;   //!
   TBranch        *b_selmu_nuErecQE;   //!
   TBranch        *b_truelepton_nuErecQE;   //!
   TBranch        *b_selmu_amom;   //!
   TBranch        *b_selmu_likemu;   //!
   TBranch        *b_selmu_likemip;   //!
   TBranch        *b_shmn_mom;   //!
   TBranch        *b_selmu_ntpcs;   //!
   TBranch        *b_selmu_tpc_det;   //!
   TBranch        *b_selmu_tpc_nhits;   //!
   TBranch        *b_selmu_tpc_nnodes;   //!
   TBranch        *b_selmu_tpc_charge;   //!
   TBranch        *b_selmu_tpc_mom;   //!
   TBranch        *b_selmu_tpc_bfield_mom;   //!
   TBranch        *b_selmu_tpc_efield_mom;   //!
   TBranch        *b_selmu_tpc_emom;   //!
   TBranch        *b_selmu_tpc_truemom;   //!
   TBranch        *b_selmu_tpc_startpos;   //!
   TBranch        *b_selmu_tpc_startdir;   //!
   TBranch        *b_selmu_tpc_endpos;   //!
   TBranch        *b_selmu_tpc_enddir;   //!
   TBranch        *b_selmu_tpc_dedx_raw;   //!
   TBranch        *b_selmu_tpc_dedx_expmu;   //!
   TBranch        *b_selmu_tpc_dedx_exppi;   //!
   TBranch        *b_selmu_tpc_dedx_expele;   //!
   TBranch        *b_selmu_tpc_dedx_expp;   //!
   TBranch        *b_selmu_tpc_dedx_exp_sigmamu;   //!
   TBranch        *b_selmu_tpc_dedx_exp_sigmapi;   //!
   TBranch        *b_selmu_tpc_dedx_exp_sigmaele;   //!
   TBranch        *b_selmu_tpc_dedx_exp_sigmap;   //!
   TBranch        *b_selmu_tpc_pullmu;   //!
   TBranch        *b_selmu_tpc_pullpi;   //!
   TBranch        *b_selmu_tpc_pullele;   //!
   TBranch        *b_selmu_tpc_pullp;   //!
   TBranch        *b_selmu_tpc_dedx;   //!
   TBranch        *b_selmu_nfgds;   //!
   TBranch        *b_selmu_fgd_det;   //!
   TBranch        *b_selmu_fgd_x;   //!
   TBranch        *b_selmu_fgd_V11;   //!
   TBranch        *b_selmu_fgd_V33;   //!
   TBranch        *b_selmu_fgd_V55;   //!
   TBranch        *b_selmu_fgd_V77;   //!
   TBranch        *b_selmu_fgd_VLayer;   //!
   TBranch        *b_selmu_fgd_pullmu;   //!
   TBranch        *b_selmu_necals;   //!
   TBranch        *b_selmu_ecal_det;   //!
   TBranch        *b_selmu_ecal_nhits;   //!
   TBranch        *b_selmu_ecal_nnodes;   //!
   TBranch        *b_selmu_ecal_length;   //!
   TBranch        *b_selmu_ecal_showerstartpos;   //!
   TBranch        *b_selmu_ecal_showerendpos;   //!
   TBranch        *b_selmu_ecal_showerstartdir;   //!
   TBranch        *b_selmu_ecal_showerenddir;   //!
   TBranch        *b_selmu_ecal_EMenergy;   //!
   TBranch        *b_selmu_ecal_edeposit;   //!
   TBranch        *b_selmu_ecal_IsShower;   //!
   TBranch        *b_selmu_ecal_mipem;   //!
   TBranch        *b_selmu_ecal_mippion;   //!
   TBranch        *b_selmu_ecal_emhip;   //!
   TBranch        *b_selmu_ecal_containment;   //!
   TBranch        *b_selmu_ecal_mostupstreamlayerhit;   //!
   TBranch        *b_selmu_nsmrds;   //!
   TBranch        *b_selmu_smrd_det;   //!
   TBranch        *b_selmu_smrd_nhits;   //!
   TBranch        *b_selmu_smrd_nnodes;   //!
   TBranch        *b_selmu_smrd_dir;   //!
   TBranch        *b_selmu_smrd_enddir;   //!
   TBranch        *b_selmu_smrd_edeposit;   //!
   TBranch        *b_truevtx_mass_component;   //!
   TBranch        *b_MuonVertexId;   //!
   TBranch        *b_MuonIndex;   //!
   TBranch        *b_NegPionMom;   //!
   TBranch        *b_NegPionTheta;   //!
   TBranch        *b_NNegPion;   //!
   TBranch        *b_NegPionPidLik;   //!
   TBranch        *b_NegPionMipPidLik;   //!
   TBranch        *b_NegPionTId;   //!
   TBranch        *b_NegPionIndex;   //!
   TBranch        *b_NegPionParentTId;   //!
   TBranch        *b_NegPionGParentTId;   //!
   TBranch        *b_NegPionTrueMom;   //!
   TBranch        *b_NegPionTrueStartDir;   //!
   TBranch        *b_NegPionVId;   //!
   TBranch        *b_NegPionDir;   //!
   TBranch        *b_NegPionPosStart;   //!
   TBranch        *b_NegPionPosEnd;   //!
   TBranch        *b_PosPionMom;   //!
   TBranch        *b_PosPionTheta;   //!
   TBranch        *b_NPosPion;   //!
   TBranch        *b_PosPionPidLik;   //!
   TBranch        *b_PosPionMipPidLik;   //!
   TBranch        *b_PosPionTId;   //!
   TBranch        *b_PosPionIndex;   //!
   TBranch        *b_PosPionParentTId;   //!
   TBranch        *b_PosPionGParentTId;   //!
   TBranch        *b_PosPionTrueMom;   //!
   TBranch        *b_PosPionTrueStartDir;   //!
   TBranch        *b_PosPionVId;   //!
   TBranch        *b_PosPionDir;   //!
   TBranch        *b_PosPionPosStart;   //!
   TBranch        *b_PosPionPosEnd;   //!
   TBranch        *b_NPi0El;   //!
   TBranch        *b_Pi0ElMom;   //!
   TBranch        *b_Pi0ElPull;   //!
   TBranch        *b_Pi0ElTId;   //!
   TBranch        *b_Pi0ElIndex;   //!
   TBranch        *b_Pi0ElParentTId;   //!
   TBranch        *b_Pi0ElGParentTId;   //!
   TBranch        *b_Pi0ElVId;   //!
   TBranch        *b_Pi0ElDir;   //!
   TBranch        *b_Pi0ElPosStart;   //!
   TBranch        *b_Pi0ElPosEnd;   //!
   TBranch        *b_NPi0Pos;   //!
   TBranch        *b_Pi0PosMom;   //!
   TBranch        *b_Pi0PosPull;   //!
   TBranch        *b_Pi0PosTId;   //!
   TBranch        *b_Pi0PosIndex;   //!
   TBranch        *b_Pi0PosParentTId;   //!
   TBranch        *b_Pi0PosGParentTId;   //!
   TBranch        *b_Pi0PosVId;   //!
   TBranch        *b_Pi0PosDir;   //!
   TBranch        *b_Pi0PosPosStart;   //!
   TBranch        *b_Pi0PosPosEnd;   //!
   TBranch        *b_NTPCSec;   //!
   TBranch        *b_TPCSecMom;   //!
   TBranch        *b_TPCSecMuPidLik;   //!
   TBranch        *b_TPCSecPiPidLik;   //!
   TBranch        *b_TPCSecPrPidLik;   //!
   TBranch        *b_TPCSecElPidLik;   //!
   TBranch        *b_TPCSecDetectors;   //!
   TBranch        *b_TPCSecQ;   //!
   TBranch        *b_TPCSecTId;   //!
   TBranch        *b_TPCSecIndex;   //!
   TBranch        *b_TPCSecParentTId;   //!
   TBranch        *b_TPCSecGParentTId;   //!
   TBranch        *b_TPCSecDir;   //!
   TBranch        *b_TPCSecPosStart;   //!
   TBranch        *b_TPCSecPosEnd;   //!
   TBranch        *b_NFGDPi;   //!
   TBranch        *b_FGDPiLength;   //!
   TBranch        *b_FGDPiPiPull;   //!
   TBranch        *b_FGDPiAvgTime;   //!
   TBranch        *b_FGDPiDistance;   //!
   TBranch        *b_FGDPiMuonangle;   //!
   TBranch        *b_FGDPiCosTheta;   //!
   TBranch        *b_FGDPiTId;   //!
   TBranch        *b_FGDPiIndex;   //!
   TBranch        *b_FGDPiParentTId;   //!
   TBranch        *b_FGDPiGParentTId;   //!
   TBranch        *b_FGDPiVId;   //!
   TBranch        *b_FGDPiDir;   //!
   TBranch        *b_FGDPiPosStart;   //!
   TBranch        *b_FGDPiPosEnd;   //!
   TBranch        *b_FGDPiTimeIni;   //!
   TBranch        *b_FGDPiTimeEnd;   //!
   TBranch        *b_FGDPiDeltaTimeIniSelMu;   //!
   TBranch        *b_FGDPiDeltaTimeEndSelMu;   //!
   TBranch        *b_NFGDEl;   //!
   TBranch        *b_FGDElLength;   //!
   TBranch        *b_FGDElPiPull;   //!
   TBranch        *b_FGDElAvgTime;   //!
   TBranch        *b_FGDElTId;   //!
   TBranch        *b_FGDElIndex;   //!
   TBranch        *b_FGDElParentTId;   //!
   TBranch        *b_FGDElGParentTId;   //!
   TBranch        *b_FGDElVId;   //!
   TBranch        *b_FGDElTimeIni;   //!
   TBranch        *b_FGDElTimeEnd;   //!
   TBranch        *b_FGDElDeltaTimeIniSelMu;   //!
   TBranch        *b_FGDElDeltaTimeEndSelMu;   //!
   TBranch        *b_FGDElDistance;   //!
   TBranch        *b_FGDElMuonangle;   //!
   TBranch        *b_FGDElCosTheta;   //!
   TBranch        *b_FGDElDir;   //!
   TBranch        *b_FGDElPosStart;   //!
   TBranch        *b_FGDElPosEnd;   //!
   TBranch        *b_NFGDSec;   //!
   TBranch        *b_FGDSecLength;   //!
   TBranch        *b_FGDSecPiPull;   //!
   TBranch        *b_FGDSecAvgTime;   //!
   TBranch        *b_FGDSecContained;   //!
   TBranch        *b_FGDSecTId;   //!
   TBranch        *b_FGDSecIndex;   //!
   TBranch        *b_FGDSecParentTId;   //!
   TBranch        *b_FGDSecGParentTId;   //!
   TBranch        *b_FGDSecTimeIni;   //!
   TBranch        *b_FGDSecTimeEnd;   //!
   TBranch        *b_FGDSecDeltaTimeIniSelMu;   //!
   TBranch        *b_FGDSecDeltaTimeEndSelMu;   //!
   TBranch        *b_FGDSecCosTheta;   //!
   TBranch        *b_FGDSecDir;   //!
   TBranch        *b_FGDSecPosStart;   //!
   TBranch        *b_FGDSecPosEnd;   //!
   TBranch        *b_NME;   //!
   TBranch        *b_MENHits;   //!
   TBranch        *b_MERawCharge;   //!
   TBranch        *b_MEMinTime;   //!
   TBranch        *b_MEMaxTime;   //!
   TBranch        *b_NTPC1Track;   //!
   TBranch        *b_TPC1TrackMom;   //!
   TBranch        *b_TPC1TrackCosTheta;   //!
   TBranch        *b_TPC1TrackPhi;   //!
   TBranch        *b_TPC1TrackVId;   //!
   TBranch        *b_TPC1TrackTId;   //!
   TBranch        *b_TPC1TrackParentTId;   //!
   TBranch        *b_TPC1TrackGParentTId;   //!
   TBranch        *b_TPC1TrackPosStart;   //!
   TBranch        *b_TPC1TrackPosEnd;   //!
   TBranch        *b_truepi_mom;   //!
   TBranch        *b_truepi_costheta;   //!
   TBranch        *b_truepi_dir;   //!
   TBranch        *b_truepi_id;   //!
   TBranch        *b_truepi_pdg;   //!
   TBranch        *b_selmu_tpc_like_mu;   //!
   TBranch        *b_selmu_tpc_like_e;   //!
   TBranch        *b_selmu_tpc_like_p;   //!
   TBranch        *b_selmu_tpc_like_pi;   //!
   TBranch        *b_selmu_has_fgd1seg;   //!
   TBranch        *b_selmu_fgd1_pull_mu;   //!
   TBranch        *b_selmu_fgd1_pull_e;   //!
   TBranch        *b_selmu_fgd1_pull_p;   //!
   TBranch        *b_selmu_fgd1_pull_pi;   //!
   TBranch        *b_selmu_fgd1_pull_no;   //!
   TBranch        *b_selmu_has_fgd2seg;   //!
   TBranch        *b_selmu_fgd2_pull_mu;   //!
   TBranch        *b_selmu_fgd2_pull_e;   //!
   TBranch        *b_selmu_fgd2_pull_p;   //!
   TBranch        *b_selmu_fgd2_pull_pi;   //!
   TBranch        *b_selmu_fgd2_pull_no;   //!
   TBranch        *b_selmu_ecal_bestseg_EMenergy;   //!
   TBranch        *b_selmu_ecal_bestseg_mippion;   //!
   TBranch        *b_selmu_ecal_bestseg_EbyL;   //!
   TBranch        *b_selmu_ecal_amr;   //!
   TBranch        *b_selmu_ecal_angle;   //!
   TBranch        *b_selmu_ecal_asymmetry;   //!
   TBranch        *b_selmu_ecal_circularity;   //!
   TBranch        *b_selmu_ecal_fbr;   //!
   TBranch        *b_selmu_ecal_maxratio;   //!
   TBranch        *b_selmu_ecal_meanpos;   //!
   TBranch        *b_selmu_ecal_showerangle;   //!
   TBranch        *b_selmu_ecal_showerwidth;   //!
   TBranch        *b_selmu_ecal_tcr;   //!
   TBranch        *b_selmu_ecal_tmr;   //!
   TBranch        *b_HMNT_mom;   //!
   TBranch        *b_HMNT_costheta;   //!
   TBranch        *b_HMNT_pdg;   //!
   TBranch        *b_HMNT_truepdg;   //!
   TBranch        *b_HMNT_NEcalSegments;   //!
   TBranch        *b_HMNT_ecal_EMenergy;   //!
   TBranch        *b_HMNT_ecal_length;   //!
   TBranch        *b_HMNT_ecal_mippion;   //!
   TBranch        *b_HMNT_ecal_angle;   //!
   TBranch        *b_HMNT_ecal_bestseg_EMenergy;   //!
   TBranch        *b_HMNT_ecal_bestseg_mippion;   //!
   TBranch        *b_HMNT_ecal_bestseg_EbyL;   //!
   TBranch        *b_HMNT_tpc_like_mu;   //!
   TBranch        *b_HMNT_tpc_like_e;   //!
   TBranch        *b_HMNT_tpc_like_p;   //!
   TBranch        *b_HMNT_tpc_like_pi;   //!
   TBranch        *b_HMNT_has_fgd1seg;   //!
   TBranch        *b_HMNT_fgd1_pull_mu;   //!
   TBranch        *b_HMNT_fgd1_pull_e;   //!
   TBranch        *b_HMNT_fgd1_pull_p;   //!
   TBranch        *b_HMNT_fgd1_pull_pi;   //!
   TBranch        *b_HMNT_fgd1_pull_no;   //!
   TBranch        *b_HMNT_has_fgd2seg;   //!
   TBranch        *b_HMNT_fgd2_pull_mu;   //!
   TBranch        *b_HMNT_fgd2_pull_e;   //!
   TBranch        *b_HMNT_fgd2_pull_p;   //!
   TBranch        *b_HMNT_fgd2_pull_pi;   //!
   TBranch        *b_HMNT_fgd2_pull_no;   //!
  
   defaultAntiNumuCC1pi(TTree *tree=0, std::string outFileName="defaultTest.root");
   virtual ~defaultAntiNumuCC1pi();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   
   defaultOut  *defout;
};

#endif

#ifdef defaultAntiNumuCC1pi_cxx
defaultAntiNumuCC1pi::defaultAntiNumuCC1pi(TTree *tree, std::string outFileName) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("../../output/test.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("../../output/test.root");
      }
      f->GetObject("default",tree);

   }
   Init(tree);
   
   defout = new defaultOut(outFileName);
}

defaultAntiNumuCC1pi::~defaultAntiNumuCC1pi()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t defaultAntiNumuCC1pi::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t defaultAntiNumuCC1pi::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void defaultAntiNumuCC1pi::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("NTOYS", &NTOYS, &b_NTOYS);
   fChain->SetBranchAddress("toy_index", toy_index, &b_toy_index);
   fChain->SetBranchAddress("toy_weight", toy_weight, &b_toy_weight);
   fChain->SetBranchAddress("entry", &entry, &b_entry);
   fChain->SetBranchAddress("toy_ref", &toy_ref, &b_toy_ref);
   fChain->SetBranchAddress("CCBwdMigrated", &CCBwdMigrated, &b_CCBwdMigrated);
   fChain->SetBranchAddress("detector", &detector, &b_detector);
   fChain->SetBranchAddress("fgd2CCBwdMigrated", &fgd2CCBwdMigrated, &b_fgd2CCBwdMigrated);
   fChain->SetBranchAddress("fgd2detector", &fgd2detector, &b_fgd2detector);
   fChain->SetBranchAddress("fgd2gparent", &fgd2gparent, &b_fgd2gparent);
   fChain->SetBranchAddress("fgd2mectopology", &fgd2mectopology, &b_fgd2mectopology);
   fChain->SetBranchAddress("fgd2nuparent", &fgd2nuparent, &b_fgd2nuparent);
   fChain->SetBranchAddress("fgd2nutype", &fgd2nutype, &b_fgd2nutype);
   fChain->SetBranchAddress("fgd2parent", &fgd2parent, &b_fgd2parent);
   fChain->SetBranchAddress("fgd2particle", &fgd2particle, &b_fgd2particle);
   fChain->SetBranchAddress("fgd2particle_detector", &fgd2particle_detector, &b_fgd2particle_detector);
   fChain->SetBranchAddress("fgd2primary", &fgd2primary, &b_fgd2primary);
   fChain->SetBranchAddress("fgd2reaction", &fgd2reaction, &b_fgd2reaction);
   fChain->SetBranchAddress("fgd2reactionCC", &fgd2reactionCC, &b_fgd2reactionCC);
   fChain->SetBranchAddress("fgd2reactionnofv", &fgd2reactionnofv, &b_fgd2reactionnofv);
   fChain->SetBranchAddress("fgd2target", &fgd2target, &b_fgd2target);
   fChain->SetBranchAddress("fgd2topology", &fgd2topology, &b_fgd2topology);
   fChain->SetBranchAddress("fgd2topology_ccpizero", &fgd2topology_ccpizero, &b_fgd2topology_ccpizero);
   fChain->SetBranchAddress("fgd2topology_no1pi", &fgd2topology_no1pi, &b_fgd2topology_no1pi);
   fChain->SetBranchAddress("fgd2topology_withpi0", &fgd2topology_withpi0, &b_fgd2topology_withpi0);
   fChain->SetBranchAddress("gparent", &gparent, &b_gparent);
   fChain->SetBranchAddress("mectopology", &mectopology, &b_mectopology);
   fChain->SetBranchAddress("nuparent", &nuparent, &b_nuparent);
   fChain->SetBranchAddress("nutype", &nutype, &b_nutype);
   fChain->SetBranchAddress("parent", &parent, &b_parent);
   fChain->SetBranchAddress("particle", &particle, &b_particle);
   fChain->SetBranchAddress("particle_detector", &particle_detector, &b_particle_detector);
   fChain->SetBranchAddress("primary", &primary, &b_primary);
   fChain->SetBranchAddress("reaction", &reaction, &b_reaction);
   fChain->SetBranchAddress("reactionCC", &reactionCC, &b_reactionCC);
   fChain->SetBranchAddress("reactionnofv", &reactionnofv, &b_reactionnofv);
   fChain->SetBranchAddress("target", &target, &b_target);
   fChain->SetBranchAddress("topology", &topology, &b_topology);
   fChain->SetBranchAddress("topology_ccpizero", &topology_ccpizero, &b_topology_ccpizero);
   fChain->SetBranchAddress("topology_no1pi", &topology_no1pi, &b_topology_no1pi);
   fChain->SetBranchAddress("topology_withpi0", &topology_withpi0, &b_topology_withpi0);
   fChain->SetBranchAddress("redo", redo, &b_redo);
   fChain->SetBranchAddress("accum_level", accum_level, &b_accum_level);
   fChain->SetBranchAddress("cut0", cut0, &b_cut0);
   fChain->SetBranchAddress("cut1", cut1, &b_cut1);
   fChain->SetBranchAddress("cut2", cut2, &b_cut2);
   fChain->SetBranchAddress("cut3", cut3, &b_cut3);
   fChain->SetBranchAddress("cut4", cut4, &b_cut4);
   fChain->SetBranchAddress("cut5", cut5, &b_cut5);
   fChain->SetBranchAddress("cut6", cut6, &b_cut6);
   fChain->SetBranchAddress("cut7", cut7, &b_cut7);
   fChain->SetBranchAddress("cut8", cut8, &b_cut8);
   fChain->SetBranchAddress("cut9", cut9, &b_cut9);
   fChain->SetBranchAddress("weight_syst", &weight_syst, &b_weight_syst);
   fChain->SetBranchAddress("weight_syst_total", &weight_syst_total, &b_weight_syst_total);
   fChain->SetBranchAddress("weight_corr", &weight_corr, &b_weight_corr);
   fChain->SetBranchAddress("weight_corr_total", &weight_corr_total, &b_weight_corr_total);
   fChain->SetBranchAddress("NWEIGHTSYST", &NWEIGHTSYST, &b_NWEIGHTSYST);
   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("subrun", &subrun, &b_subrun);
   fChain->SetBranchAddress("evt", &evt, &b_evt);
   fChain->SetBranchAddress("evt_time", &evt_time, &b_evt_time);
   fChain->SetBranchAddress("bunch", &bunch, &b_bunch);
   fChain->SetBranchAddress("TruthVertexID", TruthVertexID, &b_TruthVertexID);
   fChain->SetBranchAddress("RooVtxIndex", RooVtxIndex, &b_RooVtxIndex);
   fChain->SetBranchAddress("RooVtxEntry", RooVtxEntry, &b_RooVtxEntry);
   fChain->SetBranchAddress("RooVtxEntry2", &RooVtxEntry2, &b_RooVtxEntry2);
   fChain->SetBranchAddress("RooVtxFile", &RooVtxFile, &b_RooVtxFile);
   fChain->SetBranchAddress("nu_pdg", &nu_pdg, &b_nu_pdg);
   fChain->SetBranchAddress("nu_trueE", &nu_trueE, &b_nu_trueE);
   fChain->SetBranchAddress("nu_truereac", &nu_truereac, &b_nu_truereac);
   fChain->SetBranchAddress("nu_truedir", nu_truedir, &b_nu_truedir);
   fChain->SetBranchAddress("true_V", &true_V, &b_true_V);
   fChain->SetBranchAddress("true_Q2", &true_Q2, &b_true_Q2);
   fChain->SetBranchAddress("true_X", &true_X, &b_true_X);
   fChain->SetBranchAddress("true_Y", &true_Y, &b_true_Y);
   fChain->SetBranchAddress("true_W", &true_W, &b_true_W);
   fChain->SetBranchAddress("selvtx_det", &selvtx_det, &b_selvtx_det);
   fChain->SetBranchAddress("selvtx_pos", selvtx_pos, &b_selvtx_pos);
   fChain->SetBranchAddress("selvtx_truepos", selvtx_truepos, &b_selvtx_truepos);
   fChain->SetBranchAddress("true_signal", true_signal, &b_true_signal);
   fChain->SetBranchAddress("sample", sample, &b_sample);
   fChain->SetBranchAddress("ntpctracks", &ntpctracks, &b_ntpctracks);
   fChain->SetBranchAddress("ntpcposQualityFV", &ntpcposQualityFV, &b_ntpcposQualityFV);
   fChain->SetBranchAddress("ntpcnegQualityFV", &ntpcnegQualityFV, &b_ntpcnegQualityFV);
   fChain->SetBranchAddress("nfgdtracks", &nfgdtracks, &b_nfgdtracks);
   fChain->SetBranchAddress("nfgdonlytracks", &nfgdonlytracks, &b_nfgdonlytracks);
   fChain->SetBranchAddress("selmu_truemom", &selmu_truemom, &b_selmu_truemom);
   fChain->SetBranchAddress("selmu_truepos", selmu_truepos, &b_selmu_truepos);
   fChain->SetBranchAddress("selmu_trueendpos", selmu_trueendpos, &b_selmu_trueendpos);
   fChain->SetBranchAddress("selmu_truedir", selmu_truedir, &b_selmu_truedir);
   fChain->SetBranchAddress("truelepton_pdg", &truelepton_pdg, &b_truelepton_pdg);
   fChain->SetBranchAddress("truelepton_mom", &truelepton_mom, &b_truelepton_mom);
   fChain->SetBranchAddress("truelepton_costheta", &truelepton_costheta, &b_truelepton_costheta);
   fChain->SetBranchAddress("selmu_dir", selmu_dir, &b_selmu_dir);
   fChain->SetBranchAddress("selmu_enddir", selmu_enddir, &b_selmu_enddir);
   fChain->SetBranchAddress("selmu_pos", selmu_pos, &b_selmu_pos);
   fChain->SetBranchAddress("selmu_endpos", selmu_endpos, &b_selmu_endpos);
   fChain->SetBranchAddress("selmu_closest_tpc", &selmu_closest_tpc, &b_selmu_closest_tpc);
   fChain->SetBranchAddress("selmu_detectors", &selmu_detectors, &b_selmu_detectors);
   fChain->SetBranchAddress("selmu_det", &selmu_det, &b_selmu_det);
   fChain->SetBranchAddress("selmu_mom", selmu_mom, &b_selmu_mom);
   fChain->SetBranchAddress("selmu_costheta", selmu_costheta, &b_selmu_costheta);
   fChain->SetBranchAddress("selmu_nuErecQE", selmu_nuErecQE, &b_selmu_nuErecQE);
   fChain->SetBranchAddress("truelepton_nuErecQE", &truelepton_nuErecQE, &b_truelepton_nuErecQE);
   fChain->SetBranchAddress("selmu_amom", &selmu_amom, &b_selmu_amom);
   fChain->SetBranchAddress("selmu_likemu", &selmu_likemu, &b_selmu_likemu);
   fChain->SetBranchAddress("selmu_likemip", &selmu_likemip, &b_selmu_likemip);
   fChain->SetBranchAddress("shmn_mom", &shmn_mom, &b_shmn_mom);
   fChain->SetBranchAddress("selmu_ntpcs", &selmu_ntpcs, &b_selmu_ntpcs);
   fChain->SetBranchAddress("selmu_tpc_det", selmu_tpc_det, &b_selmu_tpc_det);
   fChain->SetBranchAddress("selmu_tpc_nhits", selmu_tpc_nhits, &b_selmu_tpc_nhits);
   fChain->SetBranchAddress("selmu_tpc_nnodes", selmu_tpc_nnodes, &b_selmu_tpc_nnodes);
   fChain->SetBranchAddress("selmu_tpc_charge", selmu_tpc_charge, &b_selmu_tpc_charge);
   fChain->SetBranchAddress("selmu_tpc_mom", selmu_tpc_mom, &b_selmu_tpc_mom);
   fChain->SetBranchAddress("selmu_tpc_bfield_mom", selmu_tpc_bfield_mom, &b_selmu_tpc_bfield_mom);
   fChain->SetBranchAddress("selmu_tpc_efield_mom", selmu_tpc_efield_mom, &b_selmu_tpc_efield_mom);
   fChain->SetBranchAddress("selmu_tpc_emom", selmu_tpc_emom, &b_selmu_tpc_emom);
   fChain->SetBranchAddress("selmu_tpc_truemom", selmu_tpc_truemom, &b_selmu_tpc_truemom);
   fChain->SetBranchAddress("selmu_tpc_startpos", selmu_tpc_startpos, &b_selmu_tpc_startpos);
   fChain->SetBranchAddress("selmu_tpc_startdir", selmu_tpc_startdir, &b_selmu_tpc_startdir);
   fChain->SetBranchAddress("selmu_tpc_endpos", selmu_tpc_endpos, &b_selmu_tpc_endpos);
   fChain->SetBranchAddress("selmu_tpc_enddir", selmu_tpc_enddir, &b_selmu_tpc_enddir);
   fChain->SetBranchAddress("selmu_tpc_dedx_raw", selmu_tpc_dedx_raw, &b_selmu_tpc_dedx_raw);
   fChain->SetBranchAddress("selmu_tpc_dedx_expmu", selmu_tpc_dedx_expmu, &b_selmu_tpc_dedx_expmu);
   fChain->SetBranchAddress("selmu_tpc_dedx_exppi", selmu_tpc_dedx_exppi, &b_selmu_tpc_dedx_exppi);
   fChain->SetBranchAddress("selmu_tpc_dedx_expele", selmu_tpc_dedx_expele, &b_selmu_tpc_dedx_expele);
   fChain->SetBranchAddress("selmu_tpc_dedx_expp", selmu_tpc_dedx_expp, &b_selmu_tpc_dedx_expp);
   fChain->SetBranchAddress("selmu_tpc_dedx_exp_sigmamu", selmu_tpc_dedx_exp_sigmamu, &b_selmu_tpc_dedx_exp_sigmamu);
   fChain->SetBranchAddress("selmu_tpc_dedx_exp_sigmapi", selmu_tpc_dedx_exp_sigmapi, &b_selmu_tpc_dedx_exp_sigmapi);
   fChain->SetBranchAddress("selmu_tpc_dedx_exp_sigmaele", selmu_tpc_dedx_exp_sigmaele, &b_selmu_tpc_dedx_exp_sigmaele);
   fChain->SetBranchAddress("selmu_tpc_dedx_exp_sigmap", selmu_tpc_dedx_exp_sigmap, &b_selmu_tpc_dedx_exp_sigmap);
   fChain->SetBranchAddress("selmu_tpc_pullmu", selmu_tpc_pullmu, &b_selmu_tpc_pullmu);
   fChain->SetBranchAddress("selmu_tpc_pullpi", selmu_tpc_pullpi, &b_selmu_tpc_pullpi);
   fChain->SetBranchAddress("selmu_tpc_pullele", selmu_tpc_pullele, &b_selmu_tpc_pullele);
   fChain->SetBranchAddress("selmu_tpc_pullp", selmu_tpc_pullp, &b_selmu_tpc_pullp);
   fChain->SetBranchAddress("selmu_tpc_dedx", selmu_tpc_dedx, &b_selmu_tpc_dedx);
   fChain->SetBranchAddress("selmu_nfgds", &selmu_nfgds, &b_selmu_nfgds);
   fChain->SetBranchAddress("selmu_fgd_det", selmu_fgd_det, &b_selmu_fgd_det);
   fChain->SetBranchAddress("selmu_fgd_x", selmu_fgd_x, &b_selmu_fgd_x);
   fChain->SetBranchAddress("selmu_fgd_V11", selmu_fgd_V11, &b_selmu_fgd_V11);
   fChain->SetBranchAddress("selmu_fgd_V33", selmu_fgd_V33, &b_selmu_fgd_V33);
   fChain->SetBranchAddress("selmu_fgd_V55", selmu_fgd_V55, &b_selmu_fgd_V55);
   fChain->SetBranchAddress("selmu_fgd_V77", selmu_fgd_V77, &b_selmu_fgd_V77);
   fChain->SetBranchAddress("selmu_fgd_VLayer", selmu_fgd_VLayer, &b_selmu_fgd_VLayer);
   fChain->SetBranchAddress("selmu_fgd_pullmu", selmu_fgd_pullmu, &b_selmu_fgd_pullmu);
   fChain->SetBranchAddress("selmu_necals", &selmu_necals, &b_selmu_necals);
   fChain->SetBranchAddress("selmu_ecal_det", selmu_ecal_det, &b_selmu_ecal_det);
   fChain->SetBranchAddress("selmu_ecal_nhits", selmu_ecal_nhits, &b_selmu_ecal_nhits);
   fChain->SetBranchAddress("selmu_ecal_nnodes", selmu_ecal_nnodes, &b_selmu_ecal_nnodes);
   fChain->SetBranchAddress("selmu_ecal_length", selmu_ecal_length, &b_selmu_ecal_length);
   fChain->SetBranchAddress("selmu_ecal_showerstartpos", selmu_ecal_showerstartpos, &b_selmu_ecal_showerstartpos);
   fChain->SetBranchAddress("selmu_ecal_showerendpos", selmu_ecal_showerendpos, &b_selmu_ecal_showerendpos);
   fChain->SetBranchAddress("selmu_ecal_showerstartdir", selmu_ecal_showerstartdir, &b_selmu_ecal_showerstartdir);
   fChain->SetBranchAddress("selmu_ecal_showerenddir", selmu_ecal_showerenddir, &b_selmu_ecal_showerenddir);
   fChain->SetBranchAddress("selmu_ecal_EMenergy", selmu_ecal_EMenergy, &b_selmu_ecal_EMenergy);
   fChain->SetBranchAddress("selmu_ecal_edeposit", selmu_ecal_edeposit, &b_selmu_ecal_edeposit);
   fChain->SetBranchAddress("selmu_ecal_IsShower", selmu_ecal_IsShower, &b_selmu_ecal_IsShower);
   fChain->SetBranchAddress("selmu_ecal_mipem", selmu_ecal_mipem, &b_selmu_ecal_mipem);
   fChain->SetBranchAddress("selmu_ecal_mippion", selmu_ecal_mippion, &b_selmu_ecal_mippion);
   fChain->SetBranchAddress("selmu_ecal_emhip", selmu_ecal_emhip, &b_selmu_ecal_emhip);
   fChain->SetBranchAddress("selmu_ecal_containment", selmu_ecal_containment, &b_selmu_ecal_containment);
   fChain->SetBranchAddress("selmu_ecal_mostupstreamlayerhit", selmu_ecal_mostupstreamlayerhit, &b_selmu_ecal_mostupstreamlayerhit);
   fChain->SetBranchAddress("selmu_nsmrds", &selmu_nsmrds, &b_selmu_nsmrds);
   fChain->SetBranchAddress("selmu_smrd_det", selmu_smrd_det, &b_selmu_smrd_det);
   fChain->SetBranchAddress("selmu_smrd_nhits", selmu_smrd_nhits, &b_selmu_smrd_nhits);
   fChain->SetBranchAddress("selmu_smrd_nnodes", selmu_smrd_nnodes, &b_selmu_smrd_nnodes);
   fChain->SetBranchAddress("selmu_smrd_dir", selmu_smrd_dir, &b_selmu_smrd_dir);
   fChain->SetBranchAddress("selmu_smrd_enddir", selmu_smrd_enddir, &b_selmu_smrd_enddir);
   fChain->SetBranchAddress("selmu_smrd_edeposit", selmu_smrd_edeposit, &b_selmu_smrd_edeposit);
   fChain->SetBranchAddress("truevtx_mass_component", truevtx_mass_component, &b_truevtx_mass_component);
   fChain->SetBranchAddress("MuonVertexId", &MuonVertexId, &b_MuonVertexId);
   fChain->SetBranchAddress("MuonIndex", &MuonIndex, &b_MuonIndex);
   fChain->SetBranchAddress("NegPionMom", NegPionMom, &b_NegPionMom);
   fChain->SetBranchAddress("NegPionTheta", NegPionTheta, &b_NegPionTheta);
   fChain->SetBranchAddress("NNegPion", &NNegPion, &b_NNegPion);
   fChain->SetBranchAddress("NegPionPidLik", NegPionPidLik, &b_NegPionPidLik);
   fChain->SetBranchAddress("NegPionMipPidLik", NegPionMipPidLik, &b_NegPionMipPidLik);
   fChain->SetBranchAddress("NegPionTId", NegPionTId, &b_NegPionTId);
   fChain->SetBranchAddress("NegPionIndex", NegPionIndex, &b_NegPionIndex);
   fChain->SetBranchAddress("NegPionParentTId", NegPionParentTId, &b_NegPionParentTId);
   fChain->SetBranchAddress("NegPionGParentTId", NegPionGParentTId, &b_NegPionGParentTId);
   fChain->SetBranchAddress("NegPionTrueMom", NegPionTrueMom, &b_NegPionTrueMom);
   fChain->SetBranchAddress("NegPionTrueStartDir", NegPionTrueStartDir, &b_NegPionTrueStartDir);
   fChain->SetBranchAddress("NegPionVId", NegPionVId, &b_NegPionVId);
   fChain->SetBranchAddress("NegPionDir", NegPionDir, &b_NegPionDir);
   fChain->SetBranchAddress("NegPionPosStart", NegPionPosStart, &b_NegPionPosStart);
   fChain->SetBranchAddress("NegPionPosEnd", NegPionPosEnd, &b_NegPionPosEnd);
   fChain->SetBranchAddress("PosPionMom", PosPionMom, &b_PosPionMom);
   fChain->SetBranchAddress("PosPionTheta", PosPionTheta, &b_PosPionTheta);
   fChain->SetBranchAddress("NPosPion", &NPosPion, &b_NPosPion);
   fChain->SetBranchAddress("PosPionPidLik", PosPionPidLik, &b_PosPionPidLik);
   fChain->SetBranchAddress("PosPionMipPidLik", PosPionMipPidLik, &b_PosPionMipPidLik);
   fChain->SetBranchAddress("PosPionTId", PosPionTId, &b_PosPionTId);
   fChain->SetBranchAddress("PosPionIndex", PosPionIndex, &b_PosPionIndex);
   fChain->SetBranchAddress("PosPionParentTId", PosPionParentTId, &b_PosPionParentTId);
   fChain->SetBranchAddress("PosPionGParentTId", PosPionGParentTId, &b_PosPionGParentTId);
   fChain->SetBranchAddress("PosPionTrueMom", PosPionTrueMom, &b_PosPionTrueMom);
   fChain->SetBranchAddress("PosPionTrueStartDir", PosPionTrueStartDir, &b_PosPionTrueStartDir);
   fChain->SetBranchAddress("PosPionVId", PosPionVId, &b_PosPionVId);
   fChain->SetBranchAddress("PosPionDir", PosPionDir, &b_PosPionDir);
   fChain->SetBranchAddress("PosPionPosStart", PosPionPosStart, &b_PosPionPosStart);
   fChain->SetBranchAddress("PosPionPosEnd", PosPionPosEnd, &b_PosPionPosEnd);
   fChain->SetBranchAddress("NPi0El", &NPi0El, &b_NPi0El);
   fChain->SetBranchAddress("Pi0ElMom", Pi0ElMom, &b_Pi0ElMom);
   fChain->SetBranchAddress("Pi0ElPull", Pi0ElPull, &b_Pi0ElPull);
   fChain->SetBranchAddress("Pi0ElTId", Pi0ElTId, &b_Pi0ElTId);
   fChain->SetBranchAddress("Pi0ElIndex", Pi0ElIndex, &b_Pi0ElIndex);
   fChain->SetBranchAddress("Pi0ElParentTId", Pi0ElParentTId, &b_Pi0ElParentTId);
   fChain->SetBranchAddress("Pi0ElGParentTId", Pi0ElGParentTId, &b_Pi0ElGParentTId);
   fChain->SetBranchAddress("Pi0ElVId", Pi0ElVId, &b_Pi0ElVId);
   fChain->SetBranchAddress("Pi0ElDir", Pi0ElDir, &b_Pi0ElDir);
   fChain->SetBranchAddress("Pi0ElPosStart", Pi0ElPosStart, &b_Pi0ElPosStart);
   fChain->SetBranchAddress("Pi0ElPosEnd", Pi0ElPosEnd, &b_Pi0ElPosEnd);
   fChain->SetBranchAddress("NPi0Pos", &NPi0Pos, &b_NPi0Pos);
   fChain->SetBranchAddress("Pi0PosMom", Pi0PosMom, &b_Pi0PosMom);
   fChain->SetBranchAddress("Pi0PosPull", Pi0PosPull, &b_Pi0PosPull);
   fChain->SetBranchAddress("Pi0PosTId", Pi0PosTId, &b_Pi0PosTId);
   fChain->SetBranchAddress("Pi0PosIndex", Pi0PosIndex, &b_Pi0PosIndex);
   fChain->SetBranchAddress("Pi0PosParentTId", Pi0PosParentTId, &b_Pi0PosParentTId);
   fChain->SetBranchAddress("Pi0PosGParentTId", Pi0PosGParentTId, &b_Pi0PosGParentTId);
   fChain->SetBranchAddress("Pi0PosVId", Pi0PosVId, &b_Pi0PosVId);
   fChain->SetBranchAddress("Pi0PosDir", Pi0PosDir, &b_Pi0PosDir);
   fChain->SetBranchAddress("Pi0PosPosStart", Pi0PosPosStart, &b_Pi0PosPosStart);
   fChain->SetBranchAddress("Pi0PosPosEnd", Pi0PosPosEnd, &b_Pi0PosPosEnd);
   fChain->SetBranchAddress("NTPCSec", &NTPCSec, &b_NTPCSec);
   fChain->SetBranchAddress("TPCSecMom", TPCSecMom, &b_TPCSecMom);
   fChain->SetBranchAddress("TPCSecMuPidLik", TPCSecMuPidLik, &b_TPCSecMuPidLik);
   fChain->SetBranchAddress("TPCSecPiPidLik", TPCSecPiPidLik, &b_TPCSecPiPidLik);
   fChain->SetBranchAddress("TPCSecPrPidLik", TPCSecPrPidLik, &b_TPCSecPrPidLik);
   fChain->SetBranchAddress("TPCSecElPidLik", TPCSecElPidLik, &b_TPCSecElPidLik);
   fChain->SetBranchAddress("TPCSecDetectors", TPCSecDetectors, &b_TPCSecDetectors);
   fChain->SetBranchAddress("TPCSecQ", TPCSecQ, &b_TPCSecQ);
   fChain->SetBranchAddress("TPCSecTId", TPCSecTId, &b_TPCSecTId);
   fChain->SetBranchAddress("TPCSecIndex", TPCSecIndex, &b_TPCSecIndex);
   fChain->SetBranchAddress("TPCSecParentTId", TPCSecParentTId, &b_TPCSecParentTId);
   fChain->SetBranchAddress("TPCSecGParentTId", TPCSecGParentTId, &b_TPCSecGParentTId);
   fChain->SetBranchAddress("TPCSecDir", TPCSecDir, &b_TPCSecDir);
   fChain->SetBranchAddress("TPCSecPosStart", TPCSecPosStart, &b_TPCSecPosStart);
   fChain->SetBranchAddress("TPCSecPosEnd", TPCSecPosEnd, &b_TPCSecPosEnd);
   fChain->SetBranchAddress("NFGDPi", &NFGDPi, &b_NFGDPi);
   fChain->SetBranchAddress("FGDPiLength", FGDPiLength, &b_FGDPiLength);
   fChain->SetBranchAddress("FGDPiPiPull", FGDPiPiPull, &b_FGDPiPiPull);
   fChain->SetBranchAddress("FGDPiAvgTime", FGDPiAvgTime, &b_FGDPiAvgTime);
   fChain->SetBranchAddress("FGDPiDistance", FGDPiDistance, &b_FGDPiDistance);
   fChain->SetBranchAddress("FGDPiMuonangle", FGDPiMuonangle, &b_FGDPiMuonangle);
   fChain->SetBranchAddress("FGDPiCosTheta", FGDPiCosTheta, &b_FGDPiCosTheta);
   fChain->SetBranchAddress("FGDPiTId", FGDPiTId, &b_FGDPiTId);
   fChain->SetBranchAddress("FGDPiIndex", FGDPiIndex, &b_FGDPiIndex);
   fChain->SetBranchAddress("FGDPiParentTId", FGDPiParentTId, &b_FGDPiParentTId);
   fChain->SetBranchAddress("FGDPiGParentTId", FGDPiGParentTId, &b_FGDPiGParentTId);
   fChain->SetBranchAddress("FGDPiVId", FGDPiVId, &b_FGDPiVId);
   fChain->SetBranchAddress("FGDPiDir", FGDPiDir, &b_FGDPiDir);
   fChain->SetBranchAddress("FGDPiPosStart", FGDPiPosStart, &b_FGDPiPosStart);
   fChain->SetBranchAddress("FGDPiPosEnd", FGDPiPosEnd, &b_FGDPiPosEnd);
   fChain->SetBranchAddress("FGDPiTimeIni", FGDPiTimeIni, &b_FGDPiTimeIni);
   fChain->SetBranchAddress("FGDPiTimeEnd", FGDPiTimeEnd, &b_FGDPiTimeEnd);
   fChain->SetBranchAddress("FGDPiDeltaTimeIniSelMu", FGDPiDeltaTimeIniSelMu, &b_FGDPiDeltaTimeIniSelMu);
   fChain->SetBranchAddress("FGDPiDeltaTimeEndSelMu", FGDPiDeltaTimeEndSelMu, &b_FGDPiDeltaTimeEndSelMu);
   fChain->SetBranchAddress("NFGDEl", &NFGDEl, &b_NFGDEl);
   fChain->SetBranchAddress("FGDElLength", FGDElLength, &b_FGDElLength);
   fChain->SetBranchAddress("FGDElPiPull", FGDElPiPull, &b_FGDElPiPull);
   fChain->SetBranchAddress("FGDElAvgTime", FGDElAvgTime, &b_FGDElAvgTime);
   fChain->SetBranchAddress("FGDElTId", FGDElTId, &b_FGDElTId);
   fChain->SetBranchAddress("FGDElIndex", FGDElIndex, &b_FGDElIndex);
   fChain->SetBranchAddress("FGDElParentTId", FGDElParentTId, &b_FGDElParentTId);
   fChain->SetBranchAddress("FGDElGParentTId", FGDElGParentTId, &b_FGDElGParentTId);
   fChain->SetBranchAddress("FGDElVId", FGDElVId, &b_FGDElVId);
   fChain->SetBranchAddress("FGDElTimeIni", FGDElTimeIni, &b_FGDElTimeIni);
   fChain->SetBranchAddress("FGDElTimeEnd", FGDElTimeEnd, &b_FGDElTimeEnd);
   fChain->SetBranchAddress("FGDElDeltaTimeIniSelMu", FGDElDeltaTimeIniSelMu, &b_FGDElDeltaTimeIniSelMu);
   fChain->SetBranchAddress("FGDElDeltaTimeEndSelMu", FGDElDeltaTimeEndSelMu, &b_FGDElDeltaTimeEndSelMu);
   fChain->SetBranchAddress("FGDElDistance", FGDElDistance, &b_FGDElDistance);
   fChain->SetBranchAddress("FGDElMuonangle", FGDElMuonangle, &b_FGDElMuonangle);
   fChain->SetBranchAddress("FGDElCosTheta", FGDElCosTheta, &b_FGDElCosTheta);
   fChain->SetBranchAddress("FGDElDir", FGDElDir, &b_FGDElDir);
   fChain->SetBranchAddress("FGDElPosStart", FGDElPosStart, &b_FGDElPosStart);
   fChain->SetBranchAddress("FGDElPosEnd", FGDElPosEnd, &b_FGDElPosEnd);
   fChain->SetBranchAddress("NFGDSec", &NFGDSec, &b_NFGDSec);
   fChain->SetBranchAddress("FGDSecLength", FGDSecLength, &b_FGDSecLength);
   fChain->SetBranchAddress("FGDSecPiPull", FGDSecPiPull, &b_FGDSecPiPull);
   fChain->SetBranchAddress("FGDSecAvgTime", FGDSecAvgTime, &b_FGDSecAvgTime);
   fChain->SetBranchAddress("FGDSecContained", FGDSecContained, &b_FGDSecContained);
   fChain->SetBranchAddress("FGDSecTId", FGDSecTId, &b_FGDSecTId);
   fChain->SetBranchAddress("FGDSecIndex", FGDSecIndex, &b_FGDSecIndex);
   fChain->SetBranchAddress("FGDSecParentTId", FGDSecParentTId, &b_FGDSecParentTId);
   fChain->SetBranchAddress("FGDSecGParentTId", FGDSecGParentTId, &b_FGDSecGParentTId);
   fChain->SetBranchAddress("FGDSecTimeIni", FGDSecTimeIni, &b_FGDSecTimeIni);
   fChain->SetBranchAddress("FGDSecTimeEnd", FGDSecTimeEnd, &b_FGDSecTimeEnd);
   fChain->SetBranchAddress("FGDSecDeltaTimeIniSelMu", FGDSecDeltaTimeIniSelMu, &b_FGDSecDeltaTimeIniSelMu);
   fChain->SetBranchAddress("FGDSecDeltaTimeEndSelMu", FGDSecDeltaTimeEndSelMu, &b_FGDSecDeltaTimeEndSelMu);
   fChain->SetBranchAddress("FGDSecCosTheta", FGDSecCosTheta, &b_FGDSecCosTheta);
   fChain->SetBranchAddress("FGDSecDir", FGDSecDir, &b_FGDSecDir);
   fChain->SetBranchAddress("FGDSecPosStart", FGDSecPosStart, &b_FGDSecPosStart);
   fChain->SetBranchAddress("FGDSecPosEnd", FGDSecPosEnd, &b_FGDSecPosEnd);
   fChain->SetBranchAddress("NME", &NME, &b_NME);
   fChain->SetBranchAddress("MENHits", MENHits, &b_MENHits);
   fChain->SetBranchAddress("MERawCharge", MERawCharge, &b_MERawCharge);
   fChain->SetBranchAddress("MEMinTime", MEMinTime, &b_MEMinTime);
   fChain->SetBranchAddress("MEMaxTime", MEMaxTime, &b_MEMaxTime);
   fChain->SetBranchAddress("NTPC1Track", &NTPC1Track, &b_NTPC1Track);
   fChain->SetBranchAddress("TPC1TrackMom", TPC1TrackMom, &b_TPC1TrackMom);
   fChain->SetBranchAddress("TPC1TrackCosTheta", TPC1TrackCosTheta, &b_TPC1TrackCosTheta);
   fChain->SetBranchAddress("TPC1TrackPhi", TPC1TrackPhi, &b_TPC1TrackPhi);
   fChain->SetBranchAddress("TPC1TrackVId", TPC1TrackVId, &b_TPC1TrackVId);
   fChain->SetBranchAddress("TPC1TrackTId", TPC1TrackTId, &b_TPC1TrackTId);
   fChain->SetBranchAddress("TPC1TrackParentTId", TPC1TrackParentTId, &b_TPC1TrackParentTId);
   fChain->SetBranchAddress("TPC1TrackGParentTId", TPC1TrackGParentTId, &b_TPC1TrackGParentTId);
   fChain->SetBranchAddress("TPC1TrackPosStart", TPC1TrackPosStart, &b_TPC1TrackPosStart);
   fChain->SetBranchAddress("TPC1TrackPosEnd", TPC1TrackPosEnd, &b_TPC1TrackPosEnd);
   fChain->SetBranchAddress("truepi_mom", &truepi_mom, &b_truepi_mom);
   fChain->SetBranchAddress("truepi_costheta", &truepi_costheta, &b_truepi_costheta);
   fChain->SetBranchAddress("truepi_dir", truepi_dir, &b_truepi_dir);
   fChain->SetBranchAddress("truepi_id", &truepi_id, &b_truepi_id);
   fChain->SetBranchAddress("truepi_pdg", &truepi_pdg, &b_truepi_pdg);
   fChain->SetBranchAddress("selmu_tpc_like_mu", &selmu_tpc_like_mu, &b_selmu_tpc_like_mu);
   fChain->SetBranchAddress("selmu_tpc_like_e", &selmu_tpc_like_e, &b_selmu_tpc_like_e);
   fChain->SetBranchAddress("selmu_tpc_like_p", &selmu_tpc_like_p, &b_selmu_tpc_like_p);
   fChain->SetBranchAddress("selmu_tpc_like_pi", &selmu_tpc_like_pi, &b_selmu_tpc_like_pi);
   fChain->SetBranchAddress("selmu_has_fgd1seg", &selmu_has_fgd1seg, &b_selmu_has_fgd1seg);
   fChain->SetBranchAddress("selmu_fgd1_pull_mu", &selmu_fgd1_pull_mu, &b_selmu_fgd1_pull_mu);
   fChain->SetBranchAddress("selmu_fgd1_pull_e", &selmu_fgd1_pull_e, &b_selmu_fgd1_pull_e);
   fChain->SetBranchAddress("selmu_fgd1_pull_p", &selmu_fgd1_pull_p, &b_selmu_fgd1_pull_p);
   fChain->SetBranchAddress("selmu_fgd1_pull_pi", &selmu_fgd1_pull_pi, &b_selmu_fgd1_pull_pi);
   fChain->SetBranchAddress("selmu_fgd1_pull_no", &selmu_fgd1_pull_no, &b_selmu_fgd1_pull_no);
   fChain->SetBranchAddress("selmu_has_fgd2seg", &selmu_has_fgd2seg, &b_selmu_has_fgd2seg);
   fChain->SetBranchAddress("selmu_fgd2_pull_mu", &selmu_fgd2_pull_mu, &b_selmu_fgd2_pull_mu);
   fChain->SetBranchAddress("selmu_fgd2_pull_e", &selmu_fgd2_pull_e, &b_selmu_fgd2_pull_e);
   fChain->SetBranchAddress("selmu_fgd2_pull_p", &selmu_fgd2_pull_p, &b_selmu_fgd2_pull_p);
   fChain->SetBranchAddress("selmu_fgd2_pull_pi", &selmu_fgd2_pull_pi, &b_selmu_fgd2_pull_pi);
   fChain->SetBranchAddress("selmu_fgd2_pull_no", &selmu_fgd2_pull_no, &b_selmu_fgd2_pull_no);
   fChain->SetBranchAddress("selmu_ecal_bestseg_EMenergy", &selmu_ecal_bestseg_EMenergy, &b_selmu_ecal_bestseg_EMenergy);
   fChain->SetBranchAddress("selmu_ecal_bestseg_mippion", &selmu_ecal_bestseg_mippion, &b_selmu_ecal_bestseg_mippion);
   fChain->SetBranchAddress("selmu_ecal_bestseg_EbyL", &selmu_ecal_bestseg_EbyL, &b_selmu_ecal_bestseg_EbyL);
   fChain->SetBranchAddress("selmu_ecal_amr", &selmu_ecal_amr, &b_selmu_ecal_amr);
   fChain->SetBranchAddress("selmu_ecal_angle", &selmu_ecal_angle, &b_selmu_ecal_angle);
   fChain->SetBranchAddress("selmu_ecal_asymmetry", &selmu_ecal_asymmetry, &b_selmu_ecal_asymmetry);
   fChain->SetBranchAddress("selmu_ecal_circularity", &selmu_ecal_circularity, &b_selmu_ecal_circularity);
   fChain->SetBranchAddress("selmu_ecal_fbr", &selmu_ecal_fbr, &b_selmu_ecal_fbr);
   fChain->SetBranchAddress("selmu_ecal_maxratio", &selmu_ecal_maxratio, &b_selmu_ecal_maxratio);
   fChain->SetBranchAddress("selmu_ecal_meanpos", &selmu_ecal_meanpos, &b_selmu_ecal_meanpos);
   fChain->SetBranchAddress("selmu_ecal_showerangle", &selmu_ecal_showerangle, &b_selmu_ecal_showerangle);
   fChain->SetBranchAddress("selmu_ecal_showerwidth", &selmu_ecal_showerwidth, &b_selmu_ecal_showerwidth);
   fChain->SetBranchAddress("selmu_ecal_tcr", &selmu_ecal_tcr, &b_selmu_ecal_tcr);
   fChain->SetBranchAddress("selmu_ecal_tmr", &selmu_ecal_tmr, &b_selmu_ecal_tmr);
   fChain->SetBranchAddress("HMNT_mom", &HMNT_mom, &b_HMNT_mom);
   fChain->SetBranchAddress("HMNT_costheta", &HMNT_costheta, &b_HMNT_costheta);
   fChain->SetBranchAddress("HMNT_pdg", &HMNT_pdg, &b_HMNT_pdg);
   fChain->SetBranchAddress("HMNT_truepdg", &HMNT_truepdg, &b_HMNT_truepdg);
   fChain->SetBranchAddress("HMNT_NEcalSegments", &HMNT_NEcalSegments, &b_HMNT_NEcalSegments);
   fChain->SetBranchAddress("HMNT_ecal_EMenergy", &HMNT_ecal_EMenergy, &b_HMNT_ecal_EMenergy);
   fChain->SetBranchAddress("HMNT_ecal_length", &HMNT_ecal_length, &b_HMNT_ecal_length);
   fChain->SetBranchAddress("HMNT_ecal_mippion", &HMNT_ecal_mippion, &b_HMNT_ecal_mippion);
   fChain->SetBranchAddress("HMNT_ecal_angle", &HMNT_ecal_angle, &b_HMNT_ecal_angle);
   fChain->SetBranchAddress("HMNT_ecal_bestseg_EMenergy", &HMNT_ecal_bestseg_EMenergy, &b_HMNT_ecal_bestseg_EMenergy);
   fChain->SetBranchAddress("HMNT_ecal_bestseg_mippion", &HMNT_ecal_bestseg_mippion, &b_HMNT_ecal_bestseg_mippion);
   fChain->SetBranchAddress("HMNT_ecal_bestseg_EbyL", &HMNT_ecal_bestseg_EbyL, &b_HMNT_ecal_bestseg_EbyL);
   fChain->SetBranchAddress("HMNT_tpc_like_mu", &HMNT_tpc_like_mu, &b_HMNT_tpc_like_mu);
   fChain->SetBranchAddress("HMNT_tpc_like_e", &HMNT_tpc_like_e, &b_HMNT_tpc_like_e);
   fChain->SetBranchAddress("HMNT_tpc_like_p", &HMNT_tpc_like_p, &b_HMNT_tpc_like_p);
   fChain->SetBranchAddress("HMNT_tpc_like_pi", &HMNT_tpc_like_pi, &b_HMNT_tpc_like_pi);
   fChain->SetBranchAddress("HMNT_has_fgd1seg", &HMNT_has_fgd1seg, &b_HMNT_has_fgd1seg);
   fChain->SetBranchAddress("HMNT_fgd1_pull_mu", &HMNT_fgd1_pull_mu, &b_HMNT_fgd1_pull_mu);
   fChain->SetBranchAddress("HMNT_fgd1_pull_e", &HMNT_fgd1_pull_e, &b_HMNT_fgd1_pull_e);
   fChain->SetBranchAddress("HMNT_fgd1_pull_p", &HMNT_fgd1_pull_p, &b_HMNT_fgd1_pull_p);
   fChain->SetBranchAddress("HMNT_fgd1_pull_pi", &HMNT_fgd1_pull_pi, &b_HMNT_fgd1_pull_pi);
   fChain->SetBranchAddress("HMNT_fgd1_pull_no", &HMNT_fgd1_pull_no, &b_HMNT_fgd1_pull_no);
   fChain->SetBranchAddress("HMNT_has_fgd2seg", &HMNT_has_fgd2seg, &b_HMNT_has_fgd2seg);
   fChain->SetBranchAddress("HMNT_fgd2_pull_mu", &HMNT_fgd2_pull_mu, &b_HMNT_fgd2_pull_mu);
   fChain->SetBranchAddress("HMNT_fgd2_pull_e", &HMNT_fgd2_pull_e, &b_HMNT_fgd2_pull_e);
   fChain->SetBranchAddress("HMNT_fgd2_pull_p", &HMNT_fgd2_pull_p, &b_HMNT_fgd2_pull_p);
   fChain->SetBranchAddress("HMNT_fgd2_pull_pi", &HMNT_fgd2_pull_pi, &b_HMNT_fgd2_pull_pi);
   fChain->SetBranchAddress("HMNT_fgd2_pull_no", &HMNT_fgd2_pull_no, &b_HMNT_fgd2_pull_no);
   Notify();
}

Bool_t defaultAntiNumuCC1pi::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void defaultAntiNumuCC1pi::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t defaultAntiNumuCC1pi::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef defaultAntiNumuCC1pi_cxx
