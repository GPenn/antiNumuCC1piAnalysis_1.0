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
  tmvareader->AddVariable( "EbyP := selmu_ecal_bestseg_EbyP",                &bdt_ecal_EbyP);
  tmvareader->AddVariable( "EbyL := selmu_ecal_bestseg_EbyL",                &bdt_ecal_EbyL);
  tmvareader->AddVariable( "circularity := selmu_ecal_circularity",          &bdt_ecal_circularity);
  tmvareader->AddVariable( "fbr := selmu_ecal_fbr",                          &bdt_ecal_fbr);
  tmvareader->AddVariable( "tmr := selmu_ecal_tmr",                          &bdt_ecal_tmr);
  tmvareader->AddVariable( "qrms := selmu_ecal_qrms",                        &bdt_ecal_qrms);
  tmvareader->AddVariable( "tpclikemu := selmu_tpc_like_mu",                 &bdt_tpc_like_mu);
  tmvareader->AddVariable( "tpclikee := selmu_tpc_like_e",                   &bdt_tpc_like_e);
  tmvareader->AddVariable( "tpclikep := selmu_tpc_like_p",                   &bdt_tpc_like_p);
  tmvareader->AddVariable( "tpclikepi := selmu_tpc_like_pi",                 &bdt_tpc_like_pi);
  tmvareader->AddVariable( "fgd1pullmu := selmu_fgd1_pull_mu",               &bdt_fgd1pullmu);
  tmvareader->AddVariable( "fgd1pullpi := selmu_fgd1_pull_pi",               &bdt_fgd1pullpi);
  tmvareader->AddVariable( "fgd1pullp := selmu_fgd1_pull_p",                 &bdt_fgd1pullp);
  tmvareader->AddVariable( "fgd2pullmu := selmu_fgd2_pull_mu",               &bdt_fgd2pullmu);
  tmvareader->AddVariable( "fgd2pullpi := selmu_fgd2_pull_pi",               &bdt_fgd2pullpi);
  tmvareader->AddVariable( "fgd2pullp := selmu_fgd2_pull_p",                 &bdt_fgd2pullp);
  
  // Book the BDT
  tmvareader->BookMVA( "BDTG", "parameters/BDT_PID_multiclass_BDTG.weights.xml" );
  
}

//--------------------------------------------------------------------------------------------------//
std::vector<Float_t> BDTPIDmanager::GetBDTPIDVars(const AnaTrackB& track, const AnaTECALReconObject& localecalsegment) {
//--------------------------------------------------------------------------------------------------//
  
  // Set variables to defaults:
  std::vector<Float_t> output = {-1, -1, -1, -1};
  
  
  // Sanity check:
  //if (!track) return output;
  //if (track->Momentum < 200) return output;
  
  // Fill kinematic variables:
  bdt_mom = track.Momentum;
  TVector3 DirVec = anaUtils::ArrayToTVector3(track.DirectionStart);
  bdt_theta = TMath::ACos(DirVec[2]);
  
  // Fill TPC variables:
  bdt_tpc_like_mu = anaUtils::GetPIDLikelihood( track,0);
  bdt_tpc_like_e  = anaUtils::GetPIDLikelihood( track,1);
  bdt_tpc_like_p  = anaUtils::GetPIDLikelihood( track,2);
  bdt_tpc_like_pi = anaUtils::GetPIDLikelihood( track,3);
  
  // Fill FGD variables:
  AnaFGDParticle* FGD1Segment = static_cast<AnaFGDParticle*>(anaUtils::GetSegmentInDet( track, static_cast<SubDetId::SubDetEnum >(0)));
  if (FGD1Segment) 
  {
    bdt_fgd1pullmu = FGD1Segment->Pullmu;
    bdt_fgd1pullp  = FGD1Segment->Pullp;
    bdt_fgd1pullpi = FGD1Segment->Pullpi;
  }
  AnaFGDParticle* FGD2Segment = static_cast<AnaFGDParticle*>(anaUtils::GetSegmentInDet( track, static_cast<SubDetId::SubDetEnum >(1)));
  if (FGD2Segment) 
  {
    bdt_fgd2pullmu = FGD2Segment->Pullmu;
    bdt_fgd2pullp  = FGD2Segment->Pullp;
    bdt_fgd2pullpi = FGD2Segment->Pullpi;
  }
  
  // Fill ECal variables:
  AnaECALParticle* ECALSegment = NULL;
  Int_t ecalsegments = 0;
  
  for (Int_t subdet = 0; subdet<9; subdet++) {
      if (!SubDetId::GetDetectorUsed(track.Detector, static_cast<SubDetId::SubDetEnum >(subdet+6))) continue;
        ECALSegment = static_cast<AnaECALParticle*>(anaUtils::GetSegmentInDet( track, static_cast<SubDetId::SubDetEnum >(subdet+6)));
      if (!ECALSegment) continue;
      
      ecalsegments++;
  }
  
  if (ECALSegment && (ecalsegments==1))
  {
    bdt_ecal_EMenergy = ECALSegment->EMEnergy;
    bdt_ecal_EbyL = (ECALSegment->EMEnergy)/(ECALSegment->Length);
    bdt_ecal_EbyP = bdt_ecal_EMenergy/bdt_mom;
  }
  
  if (localecalsegment)
  {
    bdt_ecal_circularity = localecalsegment.PIDCircularity;
    bdt_ecal_fbr = localecalsegment.PIDFBR;
    bdt_ecal_qrms = localecalsegment.EMEnergyFitParaQRMS;
    bdt_ecal_tmr = localecalsegment.PIDTruncatedMaxRatio;
  }
  
  // Call BDT:
  
  
  return output;
}

