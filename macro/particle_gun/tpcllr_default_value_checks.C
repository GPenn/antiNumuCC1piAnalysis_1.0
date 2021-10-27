{
  DrawingTools draw("output/particle_gun/particlegun_allpositive.root");
  DataSample mc("output/particle_gun/particlegun_allpositive.root");
  
  draw.SetTitleX("Main track reco momentum");
  TCanvas selmu_mom_default;
  draw.Draw(default,"selmu_mom[0]",50,0,3000,"particle","(accum_level[][0]>4)&&(selmu_tpc_like_mu<-0.5)");
  TCanvas selmu_mom_nondefault;
  draw.Draw(default,"selmu_mom",50,0,3000,"particle","(accum_level[][0]>4)&&(selmu_tpc_like_mu>-0.5)");
  
  draw.SetTitleX("Main track TPC dE/dx");
  TCanvas selmu_dedx_default;
  draw.Draw(default,"selmu_tpc_dedx",50,0,10000,"particle","(accum_level[][0]>4)&&(selmu_tpc_like_mu<-0.5)");
  TCanvas selmu_dedx_nondefault;
  draw.Draw(default,"selmu_tpc_dedx",50,0,1000,"particle","(accum_level[][0]>4)&&(selmu_tpc_like_mu>-0.5)");
  
  draw.SetTitleX("Main track TPC nhits");
  TCanvas selmu_nhits_default;
  draw.Draw(default,"selmu_tpc_nhits",50,0,100,"particle","(accum_level[][0]>4)&&(selmu_tpc_like_mu<-0.5)");
  TCanvas selmu_nhits_nondefault;
  draw.Draw(default,"selmu_tpc_nhits",50,0,100,"particle","(accum_level[][0]>4)&&(selmu_tpc_like_mu>-0.5)");
}
