{
  DrawingTools draw("output/output_p6T_allruns_tpcliketest.root");
  DataSample mc("output/output_p6T_allruns_tpcliketest.root");
  
  TCanvas selmu_tpc_like_mu;
  draw.SetTitleX("Muon candidate TPC likelihood - muon");
  draw.Draw(default,"selmu_tpc_like_mu",50,0,1,"topology","accum_level[][1]>7");
  
  TCanvas selmu_tpc_like_e;
  draw.SetTitleX("Muon candidate TPC likelihood - electron");
  draw.Draw(default,"selmu_tpc_like_e",50,0,1,"topology","accum_level[][1]>7");
  
  TCanvas selmu_tpc_like_p;
  draw.SetTitleX("Muon candidate TPC likelihood - proton");
  draw.Draw(default,"selmu_tpc_like_p",50,0,1,"topology","accum_level[][1]>7");
  
  TCanvas selmu_tpc_like_pi;
  draw.SetTitleX("Muon candidate TPC likelihood - pion");
  draw.Draw(default,"selmu_tpc_like_pi",50,0,1,"topology","accum_level[][1]>7");
}
