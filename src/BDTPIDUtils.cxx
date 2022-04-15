#include "BDTPIDUtils.hxx"

//----------------------------------------------------------------------------------------//
BDTPIDmanager::BDTPIDmanager() {
//----------------------------------------------------------------------------------------//  
  
  // Initialise TMVA Reader class
  tmvareader = new TMVA::Reader( "Color" );
  
  // Register BDT input variables
  tmvareader->AddVariable( "mom := selmu_mom",                               &bdt_mom);
  tmvareader->AddVariable( "theta := selmu_theta",                           &bdt_theta);
  tmvareader->AddVariable( "EMenergy := selmu_ecal_bestseg_EMenergy",        &bdt_ecal_EMenergy);
  //tmvareader->AddVariable( "EbyP := selmu_ecal_bestseg_EbyP",        &bdt_ecal_EbyP);
  
  //tmvareader->AddVariable( "fgd1pullmu := selmu_fgd1_pull_mu",               &bdt_fgd1pullmu);
  //tmvareader->AddVariable( "fgd1pullpi := selmu_fgd1_pull_pi",               &bdt_fgd1pullpi);
  //tmvareader->AddVariable( "fgd1pullp := selmu_fgd1_pull_p",                 &bdt_fgd1pullp);
  tmvareader->AddVariable("fgd1EbyL := selmu_fgd1_EbyL",                      &bdt_fgd1_EbyL);
  
  //tmvareader->AddVariable( "fgd2pullmu := selmu_fgd2_pull_mu",               &bdt_fgd2pullmu);
  //tmvareader->AddVariable( "fgd2pullpi := selmu_fgd2_pull_pi",               &bdt_fgd2pullpi);
  //tmvareader->AddVariable( "fgd2pullp := selmu_fgd2_pull_p",                 &bdt_fgd2pullp);
  tmvareader->AddVariable("fgd2EbyL := selmu_fgd2_EbyL",                      &bdt_fgd2_EbyL);
  
  //tmvareader->AddVariable( "tpclikemu := selmu_tpc_like_mu",                 &bdt_tpc_like_mu);
  //tmvareader->AddVariable( "tpclikee := selmu_tpc_like_e",                   &bdt_tpc_like_e);
  //tmvareader->AddVariable( "tpclikep := selmu_tpc_like_p",                   &bdt_tpc_like_p);
  //tmvareader->AddVariable( "tpclikepi := selmu_tpc_like_pi",                 &bdt_tpc_like_pi);
  //tmvareader->AddVariable( "tpcpullmu := selmu_tpc_pullmu",                 &bdt_tpc_pullmu);
  //tmvareader->AddVariable( "tpcpulle := selmu_tpc_pullele",                   &bdt_tpc_pulle);
  //tmvareader->AddVariable( "tpcpullp := selmu_tpc_pullp",                   &bdt_tpc_pullp);
  //tmvareader->AddVariable( "tpcpullpi := selmu_tpc_pullpi",                 &bdt_tpc_pullpi);
  tmvareader->AddVariable( "tpc2dedx := selmu_tpc2_dedx ",                 &bdt_tpc2_dedx);
  
  tmvareader->AddVariable( "tpc3dedx := selmu_tpc3_dedx ",                 &bdt_tpc3_dedx);
  //tmvareader->AddVariable( "tpc3pullmu := selmu_tpc3_pullmu",                 &bdt_tpc3_pullmu);
  //tmvareader->AddVariable( "tpc3pulle := selmu_tpc3_pullele",                   &bdt_tpc3_pulle);
  //tmvareader->AddVariable( "tpc3pullp := selmu_tpc3_pullp",                   &bdt_tpc3_pullp);
  //tmvareader->AddVariable( "tpc3pullpi := selmu_tpc3_pullpi",                 &bdt_tpc3_pullpi);
  //tmvareader->AddVariable( "ntpcs := selmu_ntpcs",                           &bdt_ntpcs);
  
  //tmvareader->AddVariable( "EbyP := selmu_ecal_bestseg_EbyP",                &bdt_ecal_EbyP);
  tmvareader->AddVariable( "EbyL := selmu_ecal_bestseg_EbyL",                 &bdt_ecal_EbyL);
  tmvareader->AddVariable( "circularity := selmu_ecal_circularity",          &bdt_ecal_circularity);
  tmvareader->AddVariable( "fbr := selmu_ecal_fbr",                          &bdt_ecal_fbr);
  tmvareader->AddVariable( "tmr := selmu_ecal_tmr",                          &bdt_ecal_tmr);
  tmvareader->AddVariable( "qrms := selmu_ecal_qrms",                        &bdt_ecal_qrms);
  //tmvareader->AddVariable( "MipEm := selmu_ecal_mipem",                       &bdt_ecal_mipem);
  //tmvareader->AddVariable( "EmHip := selmu_ecal_emhip",                       &bdt_ecal_emhip);
  //tmvareader->AddVariable( "MipPion := selmu_ecal_mippion",                   &bdt_ecal_mippion);
  
  tmvareader->AddVariable( "nsmrds := selmu_nsmrds",                          &bdt_nsmrds);
  
  /*tmvareader->AddVariable( "mom := selmu_mom",                               &bdt_mom);
  tmvareader->AddVariable( "theta := selmu_theta",                           &bdt_theta);
  tmvareader->AddVariable("fgd1EbyL := selmu_fgd1_EbyL",                      &bdt_fgd1_EbyL);
  tmvareader->AddVariable("fgd2EbyL := selmu_fgd2_EbyL",                      &bdt_fgd2_EbyL);
  tmvareader->AddVariable( "tpclikemu := selmu_tpc_like_mu",                 &bdt_tpc_like_mu);
  tmvareader->AddVariable( "tpclikee := selmu_tpc_like_e",                   &bdt_tpc_like_e);
  tmvareader->AddVariable( "tpclikep := selmu_tpc_like_p",                   &bdt_tpc_like_p);
  tmvareader->AddVariable( "tpclikepi := selmu_tpc_like_pi",                 &bdt_tpc_like_pi);
  tmvareader->AddVariable( "ntpcs := selmu_ntpcs",                           &bdt_ntpcs);
  tmvareader->AddVariable( "EMenergy := selmu_ecal_bestseg_EMenergy",        &bdt_ecal_EMenergy);
  tmvareader->AddVariable( "EbyL := selmu_ecal_bestseg_EbyL",                 &bdt_ecal_EbyL);
  tmvareader->AddVariable( "circularity := selmu_ecal_circularity",          &bdt_ecal_circularity);
  tmvareader->AddVariable( "fbr := selmu_ecal_fbr",                          &bdt_ecal_fbr);
  tmvareader->AddVariable( "tmr := selmu_ecal_tmr",                          &bdt_ecal_tmr);
  tmvareader->AddVariable( "qrms := selmu_ecal_qrms",                        &bdt_ecal_qrms);
  tmvareader->AddVariable( "nsmrds := selmu_nsmrds",                          &bdt_nsmrds);*/
  
  // Book the BDTs
  
  tmvareader->BookMVA( "BDTG_tree3", "parameters/weights/BDT_PID_multiclass_BDTG_tree3.weights.xml" );
  //tmvareader->BookMVA( "BDTG_tree2", "parameters/weights/BDT_PID_multiclass_BDTG_tree2.weights.xml" );
  //tmvareader->BookMVA( "BDTG_tree3_noweights", "parameters/weights/BDT_PID_multiclass_BDTG_tree3_noweights.weights.xml" );
  
  //tmvareader->BookMVA( "BDTG_tree2", "parameters/weights/BDT_PID_multiclass_BDTG_tree2.weights.xml" );
  //tmvareader->BookMVA( "BDTG_tree3", "parameters/weights/BDT_PID_multiclass_BDTG_tree3.weights.xml" );
  //tmvareader->BookMVA( "BDTG_tree4", "parameters/weights/BDT_PID_multiclass_BDTG_tree4.weights.xml" );
  //tmvareader->BookMVA( "BDTG_tree5", "parameters/weights/BDT_PID_multiclass_BDTG_tree5.weights.xml" );
  
  //tmvareader->BookMVA( "BDTG_500trees", "parameters/weights/BDT_PID_multiclass_BDTG_500trees.weights.xml" );
  //tmvareader->BookMVA( "BDTG_1000trees", "parameters/weights/BDT_PID_multiclass_BDTG_1000trees.weights.xml" );
  //tmvareader->BookMVA( "BDTG_1500trees", "parameters/weights/BDT_PID_multiclass_BDTG_1500trees.weights.xml" );
  //tmvareader->BookMVA( "BDTG_2000trees", "parameters/weights/BDT_PID_multiclass_BDTG_2000trees.weights.xml" );
  //tmvareader->BookMVA( "BDTG_2500trees", "parameters/weights/BDT_PID_multiclass_BDTG_2500trees.weights.xml" );
  
  //tmvareader->BookMVA( "BDTG_0.1shrinkage", "parameters/weights/BDT_PID_multiclass_BDTG_0.1shrinkage.weights.xml" );
  //tmvareader->BookMVA( "BDTG_0.3shrinkage", "parameters/weights/BDT_PID_multiclass_BDTG_0.3shrinkage.weights.xml" );
  //tmvareader->BookMVA( "BDTG_0.5shrinkage", "parameters/weights/BDT_PID_multiclass_BDTG_0.5shrinkage.weights.xml" );
  //tmvareader->BookMVA( "BDTG_0.7shrinkage", "parameters/weights/BDT_PID_multiclass_BDTG_0.7shrinkage.weights.xml" );
  //tmvareader->BookMVA( "BDTG_0.9shrinkage", "parameters/weights/BDT_PID_multiclass_BDTG_0.9shrinkage.weights.xml" );
  
  tmvareader->BookMVA( "BDTG_0.01shrinkage", "parameters/weights/BDT_PID_multiclass_BDTG_0.01shrinkage.weights.xml" );
  tmvareader->BookMVA( "BDTG_0.02shrinkage", "parameters/weights/BDT_PID_multiclass_BDTG_0.02shrinkage.weights.xml" );
  tmvareader->BookMVA( "BDTG_0.04shrinkage", "parameters/weights/BDT_PID_multiclass_BDTG_0.04shrinkage.weights.xml" );
  tmvareader->BookMVA( "BDTG_0.06shrinkage", "parameters/weights/BDT_PID_multiclass_BDTG_0.06shrinkage.weights.xml" );
  tmvareader->BookMVA( "BDTG_0.08shrinkage", "parameters/weights/BDT_PID_multiclass_BDTG_0.08shrinkage.weights.xml" );
  
  //tmvareader->BookMVA( "BDTG_0.1bagged", "parameters/weights/BDT_PID_multiclass_BDTG_0.1bagged.weights.xml" );
  //tmvareader->BookMVA( "BDTG_0.3bagged", "parameters/weights/BDT_PID_multiclass_BDTG_0.3bagged.weights.xml" );
  //tmvareader->BookMVA( "BDTG_0.5bagged", "parameters/weights/BDT_PID_multiclass_BDTG_0.5bagged.weights.xml" );
  //tmvareader->BookMVA( "BDTG_0.7bagged", "parameters/weights/BDT_PID_multiclass_BDTG_0.7bagged.weights.xml" );
  //tmvareader->BookMVA( "BDTG_0.9bagged", "parameters/weights/BDT_PID_multiclass_BDTG_0.9bagged.weights.xml" );
  
  //tmvareader->BookMVA( "BDTG_4vars", "parameters/weights/BDT_PID_multiclass_BDTG_4vars.weights.xml" );
  //tmvareader->BookMVA( "BDTG_6vars", "parameters/weights/BDT_PID_multiclass_BDTG_6vars.weights.xml" );
  //tmvareader->BookMVA( "BDTG_8vars", "parameters/weights/BDT_PID_multiclass_BDTG_8vars.weights.xml" );
  //tmvareader->BookMVA( "BDTG_10vars", "parameters/weights/BDT_PID_multiclass_BDTG_10vars.weights.xml" );
  //tmvareader->BookMVA( "BDTG_12vars", "parameters/weights/BDT_PID_multiclass_BDTG_12vars.weights.xml" );
  
  //tmvareader->BookMVA( "BDTG_neg_tree3", "parameters/weights/BDT_PID_multiclass_negative_BDTG_tree3.weights.xml" );
  
  //tmvareader->BookMVA( "BDTG_default", "parameters/weights/BDT_PID_multiclass_BDTG_default.weights.xml" );
  //tmvareader->BookMVA( "BDTG_tunedparams", "parameters/weights/BDT_PID_multiclass_BDTG_tunedparams.weights.xml" );
  
  //tmvareader->BookMVA( "BDTG_tpclikelihoods", "parameters/weights/BDT_PID_multiclass_BDTG_tpclikelihoods.weights.xml" );
  //tmvareader->BookMVA( "BDTG_tpcpulls", "parameters/weights/BDT_PID_multiclass_BDTG_tpcpulls.weights.xml" );
  //tmvareader->BookMVA( "BDTG_tpcdedx", "parameters/weights/BDT_PID_multiclass_BDTG_tpcdedx.weights.xml" );
  //tmvareader->BookMVA( "BDTG_ecallowlevel", "parameters/weights/BDT_PID_multiclass_BDTG_ecallowlevel.weights.xml" );
  //tmvareader->BookMVA( "BDTG_ecalEbyP", "parameters/weights/BDT_PID_multiclass_BDTG_ecalEbyP.weights.xml" );
  //tmvareader->BookMVA( "BDTG_ntpcs", "parameters/weights/BDT_PID_multiclass_BDTG_ntpcs.weights.xml" );
  
  //tmvareader->BookMVA( "BDTG_2vars", "parameters/weights/BDT_PID_multiclass_BDTG_2vars.weights.xml" );
  //tmvareader->BookMVA( "BDTG_3vars", "parameters/weights/BDT_PID_multiclass_BDTG_3vars.weights.xml" );
  //tmvareader->BookMVA( "BDTG_4vars_redo", "parameters/weights/BDT_PID_multiclass_BDTG_4vars_redo.weights.xml" );
}

//--------------------------------------------------------------------------------------------------//
//std::vector<Float_t> BDTPIDmanager::GetBDTPIDVars(const AnaTrackB& track, const AnaTECALReconObject& localecalsegment) {
std::vector<Float_t> BDTPIDmanager::GetBDTPIDVarsPos(AnaTrackB* track, AnaTECALReconObject* localecalsegment, TString BDTname) {
//--------------------------------------------------------------------------------------------------//
  
  // Set variables to defaults:
  std::vector<Float_t> output = {-1, -1, -1, -1};
  
  bdt_mom = -1.0;
  bdt_theta = -1.0;
  bdt_ecal_EMenergy = -100.0;
  bdt_ecal_EbyP = -1.0;
  
  bdt_fgd1pullmu = -30.0;
  bdt_fgd1pullpi = -30.0;
  bdt_fgd1pullp = -30.0;
  bdt_fgd1_EbyL = -1.0;
  
  bdt_fgd2pullmu = -30.0;
  bdt_fgd2pullpi = -30.0;
  bdt_fgd2pullp = -30.0;
  bdt_fgd2_EbyL = -1.0;
  
  bdt_tpc_like_mu = -0.5;
  bdt_tpc_like_e = -0.5;
  bdt_tpc_like_p = -0.5;
  bdt_tpc_like_pi = -0.5;
  bdt_tpc2_pullmu = -10.0;
  bdt_tpc2_pullpi = -10.0;
  bdt_tpc2_pullp = -40.0;
  bdt_tpc2_pulle = -20.0;
  bdt_tpc2_dedx = -100.0;
  
  bdt_tpc3_pullmu = -10.0;
  bdt_tpc3_pullpi = -10.0;
  bdt_tpc3_pullp = -40.0;
  bdt_tpc3_pulle = -10.0;
  bdt_tpc3_dedx = -100.0;
  
  bdt_ecal_EbyP = -1.0;
  bdt_ecal_EbyL = -1.0;
  bdt_ecal_circularity = -0.5;
  bdt_ecal_fbr = -5.0;
  bdt_ecal_tmr = -0.2;
  bdt_ecal_qrms = -0.1;
  bdt_ecal_mipem = -100.0;
  bdt_ecal_emhip = -100.0;
  bdt_ecal_mippion = -100.0;
  
  bdt_nsmrds = 0;
  bdt_ntpcs = 0;
  
  // Sanity check:
  if (!track) return output;
  //if (track->Momentum < 200) return output;
  
  // Fill kinematic variables:
  //std::cout << "DEBUG: Filling BDT kinematic variables..." << std::endl;
  bdt_mom = track->Momentum;
  TVector3 DirVec = anaUtils::ArrayToTVector3(track->DirectionStart);
  bdt_theta = TMath::ACos(DirVec[2]);
  
  // Fill TPC variables:
  //std::cout << "DEBUG: Filling BDT TPC variables..." << std::endl;
  bdt_ntpcs = track->nTPCSegments;
  bdt_tpc_like_mu = anaUtils::GetPIDLikelihood( *track,0);
  bdt_tpc_like_e  = anaUtils::GetPIDLikelihood( *track,1);
  bdt_tpc_like_p  = anaUtils::GetPIDLikelihood( *track,2);
  bdt_tpc_like_pi = anaUtils::GetPIDLikelihood( *track,3);
  AnaTPCParticle* TPC2Segment = static_cast<AnaTPCParticle*>(anaUtils::GetSegmentInDet( *track, static_cast<SubDetId::SubDetEnum >(3)));
  if (TPC2Segment)
  {
    bdt_tpc2_dedx = TPC2Segment->dEdxMeas;
    bdt_tpc2_pullmu = TPC2Segment->Pullmu;
    bdt_tpc2_pullpi = TPC2Segment->Pullpi;
    bdt_tpc2_pullp = TPC2Segment->Pullp;
    bdt_tpc2_pulle = TPC2Segment->Pullele;
  }
  AnaTPCParticle* TPC3Segment = static_cast<AnaTPCParticle*>(anaUtils::GetSegmentInDet( *track, static_cast<SubDetId::SubDetEnum >(4)));
  if (TPC3Segment)
  {
    bdt_tpc3_dedx = TPC3Segment->dEdxMeas;
    bdt_tpc3_pullmu = TPC3Segment->Pullmu;
    bdt_tpc3_pullpi = TPC3Segment->Pullpi;
    bdt_tpc3_pullp = TPC3Segment->Pullp;
    bdt_tpc3_pulle = TPC3Segment->Pullele;
  }
  // Fill FGD variables:
  //std::cout << "DEBUG: Filling BDT FGD1 variables..." << std::endl;
  AnaFGDParticle* FGD1Segment = static_cast<AnaFGDParticle*>(anaUtils::GetSegmentInDet( *track, static_cast<SubDetId::SubDetEnum >(0)));
  if (FGD1Segment) 
  {
    bdt_fgd1pullmu = FGD1Segment->Pullmu;
    bdt_fgd1pullp  = FGD1Segment->Pullp;
    bdt_fgd1pullpi = FGD1Segment->Pullpi;
    bdt_fgd1_EbyL = FGD1Segment->E / FGD1Segment->Length;
  }
  //std::cout << "DEBUG: Filling BDT FGD2 variables..." << std::endl;
  AnaFGDParticle* FGD2Segment = static_cast<AnaFGDParticle*>(anaUtils::GetSegmentInDet( *track, static_cast<SubDetId::SubDetEnum >(1)));
  if (FGD2Segment) 
  {
    bdt_fgd2pullmu = FGD2Segment->Pullmu;
    bdt_fgd2pullp  = FGD2Segment->Pullp;
    bdt_fgd2pullpi = FGD2Segment->Pullpi;
    bdt_fgd2_EbyL = FGD2Segment->E / FGD2Segment->Length;
  }
  
  // Fill ECal variables:
  //std::cout << "DEBUG: Filling BDT ECal variables..." << std::endl;
  AnaECALParticle* ECALSegment = NULL;
  Int_t ecalsegments = 0;
  
  for (Int_t subdet = 0; subdet<9; subdet++) {
      if (!SubDetId::GetDetectorUsed(track->Detector, static_cast<SubDetId::SubDetEnum >(subdet+6))) continue;
        ECALSegment = static_cast<AnaECALParticle*>(anaUtils::GetSegmentInDet( *track, static_cast<SubDetId::SubDetEnum >(subdet+6)));
      if (!ECALSegment) continue;
      
      ecalsegments++;
  }
  
  if (ECALSegment && (ecalsegments==1))
  {
    bdt_ecal_EMenergy = ECALSegment->EMEnergy;
    bdt_ecal_EbyL = (ECALSegment->EMEnergy)/(ECALSegment->Length);
    bdt_ecal_EbyP = bdt_ecal_EMenergy/bdt_mom;
    bdt_ecal_mipem = ECALSegment->PIDMipEm;
    bdt_ecal_emhip = ECALSegment->PIDEmHip;
    bdt_ecal_mippion = ECALSegment->PIDMipPion;
  }
  //std::cout << "DEBUG: Filling BDT local ECal variables..." << std::endl;
  if (localecalsegment)
  {
    bdt_ecal_circularity = localecalsegment->PIDCircularity;
    bdt_ecal_fbr = localecalsegment->PIDFBR;
    bdt_ecal_qrms = localecalsegment->EMEnergyFitParaQRMS;
    bdt_ecal_tmr = localecalsegment->PIDTruncatedMaxRatio;
  }
  
  bdt_nsmrds = track->nSMRDSegments;
  
  // Call BDT:
  //std::cout << "DEBUG: Evaluating BDT output..." << std::endl;
  output = tmvareader->EvaluateMulticlass( BDTname );
  
  return output;
}

//--------------------------------------------------------------------------------------------------//
std::vector<Float_t> BDTPIDmanager::GetBDTPIDVarsNeg(AnaTrackB* track, AnaTECALReconObject* localecalsegment, TString BDTname) {
//--------------------------------------------------------------------------------------------------//
  
  // Set variables to defaults:
  std::vector<Float_t> output = {-1, -1, -1};
  
  bdt_mom = -1.0;
  bdt_theta = -1.0;
  bdt_ecal_EMenergy = -100.0;
  
  bdt_fgd1pullmu = -30.0;
  bdt_fgd1pullpi = -30.0;
  bdt_fgd1pullp = -30.0;
  bdt_fgd1_EbyL = -1.0;
  
  bdt_fgd2pullmu = -30.0;
  bdt_fgd2pullpi = -30.0;
  bdt_fgd2pullp = -30.0;
  bdt_fgd2_EbyL = -1.0;
  
  bdt_tpc_like_mu = -0.5;
  bdt_tpc_like_e = -0.5;
  bdt_tpc_like_p = -0.5;
  bdt_tpc_like_pi = -0.5;
  bdt_tpc2_dedx = -100.0;
  bdt_tpc3_dedx = -100.0;
  
  bdt_ecal_EbyP = -1.0;
  bdt_ecal_EbyL = -1.0;
  bdt_ecal_circularity = -0.5;
  bdt_ecal_fbr = -5.0;
  bdt_ecal_tmr = -0.2;
  bdt_ecal_qrms = -0.1;
  bdt_ecal_mipem = -100.0;
  bdt_ecal_emhip = -100.0;
  bdt_ecal_mippion = -100.0;
  
  bdt_nsmrds = 0;
  
  // Sanity check:
  if (!track) return output;
  //if (track->Momentum < 200) return output;
  
  // Fill kinematic variables:
  //std::cout << "DEBUG: Filling BDT kinematic variables..." << std::endl;
  bdt_mom = track->Momentum;
  TVector3 DirVec = anaUtils::ArrayToTVector3(track->DirectionStart);
  bdt_theta = TMath::ACos(DirVec[2]);
  
  // Fill TPC variables:
  //std::cout << "DEBUG: Filling BDT TPC variables..." << std::endl;
  bdt_tpc_like_mu = anaUtils::GetPIDLikelihood( *track,0);
  bdt_tpc_like_e  = anaUtils::GetPIDLikelihood( *track,1);
  bdt_tpc_like_p  = anaUtils::GetPIDLikelihood( *track,2);
  bdt_tpc_like_pi = anaUtils::GetPIDLikelihood( *track,3);
  //bdt_tpc2_dedx = 
  //bdt_tpc3_dedx = 
  
  // Fill FGD variables:
  //std::cout << "DEBUG: Filling BDT FGD1 variables..." << std::endl;
  AnaFGDParticle* FGD1Segment = static_cast<AnaFGDParticle*>(anaUtils::GetSegmentInDet( *track, static_cast<SubDetId::SubDetEnum >(0)));
  if (FGD1Segment) 
  {
    bdt_fgd1pullmu = FGD1Segment->Pullmu;
    bdt_fgd1pullp  = FGD1Segment->Pullp;
    bdt_fgd1pullpi = FGD1Segment->Pullpi;
    bdt_fgd1_EbyL = FGD1Segment->E / FGD1Segment->Length;
  }
  //std::cout << "DEBUG: Filling BDT FGD2 variables..." << std::endl;
  AnaFGDParticle* FGD2Segment = static_cast<AnaFGDParticle*>(anaUtils::GetSegmentInDet( *track, static_cast<SubDetId::SubDetEnum >(1)));
  if (FGD2Segment) 
  {
    bdt_fgd2pullmu = FGD2Segment->Pullmu;
    bdt_fgd2pullp  = FGD2Segment->Pullp;
    bdt_fgd2pullpi = FGD2Segment->Pullpi;
    bdt_fgd2_EbyL = FGD2Segment->E / FGD2Segment->Length;
  }
  
  // Fill ECal variables:
  //std::cout << "DEBUG: Filling BDT ECal variables..." << std::endl;
  AnaECALParticle* ECALSegment = NULL;
  Int_t ecalsegments = 0;
  
  for (Int_t subdet = 0; subdet<9; subdet++) {
      if (!SubDetId::GetDetectorUsed(track->Detector, static_cast<SubDetId::SubDetEnum >(subdet+6))) continue;
        ECALSegment = static_cast<AnaECALParticle*>(anaUtils::GetSegmentInDet( *track, static_cast<SubDetId::SubDetEnum >(subdet+6)));
      if (!ECALSegment) continue;
      
      ecalsegments++;
  }
  
  if (ECALSegment && (ecalsegments==1))
  {
    bdt_ecal_EMenergy = ECALSegment->EMEnergy;
    bdt_ecal_EbyL = (ECALSegment->EMEnergy)/(ECALSegment->Length);
    bdt_ecal_EbyP = bdt_ecal_EMenergy/bdt_mom;
    bdt_ecal_mipem = ECALSegment->PIDMipEm;
    bdt_ecal_emhip = ECALSegment->PIDEmHip;
    bdt_ecal_mippion = ECALSegment->PIDMipPion;
  }
  //std::cout << "DEBUG: Filling BDT local ECal variables..." << std::endl;
  if (localecalsegment)
  {
    bdt_ecal_circularity = localecalsegment->PIDCircularity;
    bdt_ecal_fbr = localecalsegment->PIDFBR;
    bdt_ecal_qrms = localecalsegment->EMEnergyFitParaQRMS;
    bdt_ecal_tmr = localecalsegment->PIDTruncatedMaxRatio;
  }
  
  bdt_nsmrds = track->nSMRDSegments;
  
  // Call BDT:
  //std::cout << "DEBUG: Evaluating BDT output..." << std::endl;
  output = tmvareader->EvaluateMulticlass( BDTname );
  
  return output;
}

//--------------------------------------------------------------------------------------------------//
bool BDTPIDmanager::GetBDTPIDValidity(AnaTrackB* track) {
//--------------------------------------------------------------------------------------------------//
  if (ignoreBDTvalidity) return true;
  
  TVector3 DirVec = anaUtils::ArrayToTVector3(track->DirectionStart);
  if ((track->Momentum > 200) && (track->Momentum < 1500) && (TMath::ACos(DirVec[2]) < 1.0472)) return true;
  
  else return false;
}

//**************************************************
bool BDTPreselectionKinematicsCut::Apply(AnaEventC& event, ToyBoxB& boxB) const{
  //**************************************************

  (void)event;

  // Cast the ToyBox to the appropriate type
  ToyBoxTracker& box = *static_cast<ToyBoxTracker*>(&boxB); 

  if (box.MainTrack->Momentum < 200.0) return false;
  if (box.MainTrack->Momentum > 1500.0) return false;
  
  TVector3 DirVec = anaUtils::ArrayToTVector3(box.MainTrack->DirectionStart);
  if (TMath::ACos(DirVec[2]) > 1.0472) return false;

  return true;
}

//**************************************************
bool BDTPreselectionKinematicsPiCandCut::Apply(AnaEventC& event, ToyBoxB& boxB) const{
  //**************************************************

  (void)event;

  // Cast the ToyBox to the appropriate type
  ToyBoxTracker& box = *static_cast<ToyBoxTracker*>(&boxB); 
  
  if (!box.HMNtrack) return true;
  
  if (box.HMNtrack->Momentum < 200.0) return false;
  if (box.HMNtrack->Momentum > 1500.0) return false;
  
  TVector3 DirVec = anaUtils::ArrayToTVector3(box.HMNtrack->DirectionStart);
  if (TMath::ACos(DirVec[2]) > 1.0472) return false;

  return true;
}



