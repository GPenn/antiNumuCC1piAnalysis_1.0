#include "BDTPIDUtils.hxx"

std::vector<Float_t> BDTPIDUtils::GetBDTPIDVars(const AnaTrackB& track, const AnaTECALReconObject& localecalsegment)
{
  std::vector<Float_t> output = {-1, -1, -1, -1};
  
  // Sanity check:
  //if (!track) return output;
  //if (track->Momentum < 200) return output;
  
  TMVA::Reader* tmvareader;
  
  // NOTE: Need to add default values
  Float_t bdt_mom, bdt_theta;
  Float_t bdt_ecal_EMenergy, bdt_ecal_EbyP, bdt_ecal_EbyL, bdt_ecal_circularity, bdt_ecal_fbr, bdt_ecal_tmr, bdt_ecal_qrms;
  Float_t bdt_tpc_like_mu, bdt_tpc_like_e, bdt_tpc_like_p, bdt_tpc_like_pi;
  Float_t bdt_fgd1pullmu, bdt_fgd1pullp, bdt_fgd1pullpi, bdt_fgd2pullmu, bdt_fgd2pullp, bdt_fgd2pullpi;
  
  // Initialise TMVA Reader class
  tmvareader = new TMVA::Reader( "Color" );
  
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
  
  tmvareader->BookMVA( "BDTG", "parameters/BDT_PID_multiclass_BDTG.weights.xml" );
  
  // Fill kinematic variables:
  bdt_mom = track.Momentum;
  TVector3 DirVec = anaUtils::ArrayToTVector3(track.DirectionStart);
  bdt_theta = TMath::ACos(DirVec[2]);
  
  // Fill TPC variables:
  bdt_tpc_like_mu = anaUtils::GetPIDLikelihood( track,0);
  bdt_tpc_like_e  = anaUtils::GetPIDLikelihood( track,1);
  bdt_tpc_like_p  = anaUtils::GetPIDLikelihood( track,2);
  bdt_tpc_like_pi = anaUtils::GetPIDLikelihood( track,3);
  
  
  
  return output;
}
