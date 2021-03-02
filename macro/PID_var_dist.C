{
  DrawingTools draw("output/output_p6T_run5_PIDvartest.root");
  DataSample mc("output/output_p6T_run5_PIDvartest.root");
  
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
  draw.Draw(default,"selmu_tpc_like_pi",50,0,1,"topology","accum_level[][1]>7");
  
  TCanvas selmu_has_fgd1seg;
  draw.SetTitleX("Muon candidate has FGD1 segment");
  draw.Draw(default,"selmu_has_fgd1seg",2,0,2,"topology","accum_level[][1]>7");
  
  TCanvas selmu_fgd1_pull_mu;
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
  draw.Draw(default,"selmu_fgd1_pull_pi",50,-10,40,"topology","accum_level[][1]>7");
  
  TCanvas selmu_has_fgd2seg;
  draw.SetTitleX("Muon candidate has FGD2 segment");
  draw.Draw(default,"selmu_has_fgd2seg",2,0,2,"topology","accum_level[][1]>7");
  
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
  draw.Draw(default,"selmu_fgd2_pull_pi",50,-10,40,"topology","accum_level[][1]>7");*/
  
  TCanvas HMNT_tpc_like_mu;
  draw.SetTitleX("HMNT TPC likelihood - muon");
  draw.Draw(default,"HMNT_tpc_like_mu",50,0,1,"topology","accum_level[][1]>7");
  
  TCanvas HMNT_tpc_like_e;
  draw.SetTitleX("HMNT TPC likelihood - electron");
  draw.Draw(default,"HMNT_tpc_like_e",50,0,1,"topology","accum_level[][1]>7");
  
  TCanvas HMNT_tpc_like_p;
  draw.SetTitleX("HMNT TPC likelihood - proton");
  draw.Draw(default,"HMNT_tpc_like_p",50,0,1,"topology","accum_level[][1]>7");
  
  TCanvas HMNT_tpc_like_pi;
  draw.SetTitleX("HMNT TPC likelihood - pion");
  draw.Draw(default,"HMNT_tpc_like_pi",50,0,1,"topology","accum_level[][1]>7");
  
  TCanvas HMNT_has_fgd1seg;
  draw.SetTitleX("HMNT has FGD1 segment");
  draw.Draw(default,"HMNT_has_fgd1seg",2,0,2,"topology","accum_level[][1]>7");
  
  TCanvas HMNT_fgd1_pull_mu;
  draw.SetTitleX("HMNT FGD1 pull - muon");
  draw.Draw(default,"HMNT_fgd1_pull_mu",50,-10,40,"topology","accum_level[][1]>7");
  
  TCanvas HMNT_fgd1_pull_e;
  draw.SetTitleX("HMNT FGD1 pull - electron");
  draw.Draw(default,"HMNT_fgd1_pull_e",50,-10,40,"topology","accum_level[][1]>7");
  
  TCanvas HMNT_fgd1_pull_p;
  draw.SetTitleX("HMNT FGD1 pull - proton");
  draw.Draw(default,"HMNT_fgd1_pull_p",50,-10,40,"topology","accum_level[][1]>7");
  
  TCanvas HMNT_fgd1_pull_pi;
  draw.SetTitleX("HMNT FGD1 pull - pi");
  draw.Draw(default,"HMNT_fgd1_pull_pi",50,-10,40,"topology","accum_level[][1]>7");
  
  TCanvas HMNT_has_fgd2seg;
  draw.SetTitleX("HMNT has FGD2 segment");
  draw.Draw(default,"HMNT_has_fgd2seg",2,0,2,"topology","accum_level[][1]>7");
  
  TCanvas HMNT_fgd2_pull_mu;
  draw.SetTitleX("HMNT FGD2 pull - muon");
  draw.Draw(default,"HMNT_fgd2_pull_mu",50,-10,40,"topology","accum_level[][1]>7");
  
  TCanvas HMNT_fgd2_pull_e;
  draw.SetTitleX("HMNT FGD2 pull - electron");
  draw.Draw(default,"HMNT_fgd2_pull_e",50,-10,40,"topology","accum_level[][1]>7");
  
  TCanvas HMNT_fgd2_pull_p;
  draw.SetTitleX("HMNT FGD2 pull - proton");
  draw.Draw(default,"HMNT_fgd2_pull_p",50,-10,40,"topology","accum_level[][1]>7");
  
  TCanvas HMNT_fgd2_pull_pi;
  draw.SetTitleX("HMNT FGD2 pull - pi");
  draw.Draw(default,"HMNT_fgd2_pull_pi",50,-10,40,"topology","accum_level[][1]>7");
  
}
