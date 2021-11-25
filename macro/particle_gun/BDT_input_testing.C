{
  DrawingTools draw("output/particle_gun/particlegun_allpositive_bdttest.root");
  DataSample mc("output/particle_gun/particlegun_allpositive_bdttest.root");
  
  draw.SetTitleX("Reco momentum");
  TCanvas mom;
  draw.Draw(default,"selmu_mom[0]",50,0,1500,"particle","accum_level[][0]>5");
  
  draw.SetTitleX("Theta");
  TCanvas theta;
  draw.Draw(default,"selmu_det_theta",50,0,1.0472,"particle","accum_level[][0]>5");
  
  draw.SetTitleX("costheta");
  TCanvas costheta;
  draw.Draw(default,"TMath::Cos(selmu_det_theta)",50,-1,1,"particle","accum_level[][0]>5");
  
  draw.SetTitleX("ECal EMEnergy");
  TCanvas emenergy;
  draw.Draw(default,"selmu_ecal_bestseg_EMenergy",50,0,2500,"particle","accum_level[][0]>5");
  
  draw.SetTitleX("ECal E/L");
  TCanvas ebyl;
  draw.Draw(default,"selmu_ecal_bestseg_EbyL",50,0,4,"particle","accum_level[][0]>5");
  
  draw.SetTitleX("ECal Circularity");
  TCanvas circularity;
  draw.Draw(default,"selmu_ecal_circularity",50,0,1,"particle","accum_level[][0]>5");
  
  draw.SetTitleX("ECal FBR");
  TCanvas fbr;
  draw.Draw(default,"selmu_ecal_fbr",50,0,20,"particle","accum_level[][0]>5");
  
  draw.SetTitleX("ECal TMR");
  TCanvas tmr;
  draw.Draw(default,"selmu_ecal_tmr",50,0,1,"particle","accum_level[][0]>5");
  
  draw.SetTitleX("ECal QRMS");
  TCanvas qrms;
  draw.Draw(default,"selmu_ecal_qrms",50,0,3,"particle","accum_level[][0]>5");
  
  draw.SetTitleX("TPC2 dE/dx");
  TCanvas tpc2dedx;
  draw.Draw(default,"selmu_tpc_dedx[0]",50,0,2000,"particle","accum_level[][0]>5");
  
  draw.SetTitleX("TPC3 dE/dx");
  TCanvas tpc3dedx;
  draw.Draw(default,"selmu_tpc_dedx[1]",50,0,2000,"particle","accum_level[][0]>5");
  
  draw.SetTitleX("TPC mu-like");
  TCanvas tpclikemu;
  draw.Draw(default,"selmu_tpc_like_mu",50,0,1,"particle","accum_level[][0]>5");
  
  draw.SetTitleX("TPC pi-like");
  TCanvas tpclikepi;
  draw.Draw(default,"selmu_tpc_like_pi",50,0,1,"particle","accum_level[][0]>5");
  
  draw.SetTitleX("TPC p-like");
  TCanvas tpclikep;
  draw.Draw(default,"selmu_tpc_like_p",50,0,1,"particle","accum_level[][0]>5");
  
  draw.SetTitleX("TPC e-like");
  TCanvas tpclikee;
  draw.Draw(default,"selmu_tpc_like_e",50,0,1,"particle","accum_level[][0]>5");
  
  draw.SetTitleX("FGD1 mu pull");
  TCanvas fgd1pullmu;
  draw.Draw(default,"selmu_fgd1_pull_mu",50,-30,60,"particle","accum_level[][0]>5");
  
  draw.SetTitleX("FGD1 pi pull");
  TCanvas fgd1pullpi;
  draw.Draw(default,"selmu_fgd1_pull_pi",50,-30,60,"particle","accum_level[][0]>5");
  
  draw.SetTitleX("FGD1 p pull");
  TCanvas fgd1pullp;
  draw.Draw(default,"selmu_fgd1_pull_p",50,-30,60,"particle","accum_level[][0]>5");
  
  draw.SetTitleX("FGD1 energy");
  TCanvas fgd1energy;
  draw.Draw(default,"selmu_fgd1_energy",50,0,2500,"particle","accum_level[][0]>5");
  
  draw.SetTitleX("FGD1 length");
  TCanvas fgd1length;
  draw.Draw(default,"selmu_fgd1_length",50,0,1000,"particle","accum_level[][0]>5");
  
  draw.SetTitleX("FGD1 energy/length");
  TCanvas fgd1EbyL;
  draw.Draw(default,"selmu_fgd1_energy/selmu_fgd1_length",50,0,5,"particle","accum_level[][0]>5");
  
  draw.SetTitleX("FGD2 mu pull");
  TCanvas fgd2pullmu;
  draw.Draw(default,"selmu_fgd2_pull_mu",50,-30,60,"particle","accum_level[][0]>5");
  
  draw.SetTitleX("FGD2 pi pull");
  TCanvas fgd2pullpi;
  draw.Draw(default,"selmu_fgd2_pull_pi",50,-30,60,"particle","accum_level[][0]>5");
  
  draw.SetTitleX("FGD2 p pull");
  TCanvas fgd2pullp;
  draw.Draw(default,"selmu_fgd2_pull_p",50,-30,60,"particle","accum_level[][0]>5");
  
  draw.SetTitleX("FGD2 energy");
  TCanvas fgd2energy;
  draw.Draw(default,"selmu_fgd2_energy",50,0,2500,"particle","accum_level[][0]>5");
  
  draw.SetTitleX("FGD2 length");
  TCanvas fgd2length;
  draw.Draw(default,"selmu_fgd2_length",50,0,1000,"particle","accum_level[][0]>5");
  
  draw.SetTitleX("FGD2 energy/length");
  TCanvas fgd2EbyL;
  draw.Draw(default,"selmu_fgd2_energy/selmu_fgd2_length",50,0,5,"particle","accum_level[][0]>5");
}
