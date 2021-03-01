{
  DrawingTools draw("output/output_p6T_run5_fgdpulltest.root");
  DataSample mc("output/output_p6T_run5_fgdpulltest.root");
  
  /*TCanvas selmu_tpc_like_mu;
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
  draw.Draw(default,"selmu_tpc_like_pi",50,0,1,"topology","accum_level[][1]>7");*/
  
  /*TCanvas selmu_fgd1_pull_mu;
  draw.SetTitleX("Muon candidate FGD1 pull - muon");
  draw.Draw(default,"selmu_fgd1_pull_mu",50,-10,40,"topology","accum_level[][1]>7");
  
  TCanvas selmu_fgd1_pull_e;
  draw.SetTitleX("Muon candidate FGD1 pull - electron");
  draw.Draw(default,"selmu_fgd1_pull_e",50,-10,40,"topology","accum_level[][1]>7");
  
  TCanvas selmu_fgd1_pull_p;
  draw.SetTitleX("Muon candidate FGD1 pull - proton");
  draw.Draw(default,"selmu_fgd1_pull_p",50,-10,40,"topology","accum_level[][1]>7");
  
  TCanvas selmu_fgd1_pull_pi;
  draw.SetTitleX("Muon candidate FGD1 pull - pi");
  draw.Draw(default,"selmu_fgd1_pull_pi",50,-10,40,"topology","accum_level[][1]>7");*/
  
  TCanvas selmu_fgd2_pull_mu;
  draw.SetTitleX("Muon candidate FGD2 pull - muon");
  draw.Draw(default,"selmu_fgd2_pull_mu",50,-10,40,"topology","accum_level[][1]>7");
  
  TCanvas selmu_fgd2_pull_e;
  draw.SetTitleX("Muon candidate FGD2 pull - electron");
  draw.Draw(default,"selmu_fgd2_pull_e",50,-10,40,"topology","accum_level[][1]>7");
  
  TCanvas selmu_fgd2_pull_p;
  draw.SetTitleX("Muon candidate FGD2 pull - proton");
  draw.Draw(default,"selmu_fgd2_pull_p",50,-10,40,"topology","accum_level[][1]>7");
  
  TCanvas selmu_fgd2_pull_pi;
  draw.SetTitleX("Muon candidate FGD2 pull - pi");
  draw.Draw(default,"selmu_fgd2_pull_pi",50,-10,40,"topology","accum_level[][1]>7");
  
}
