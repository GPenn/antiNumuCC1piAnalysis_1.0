{
  DrawingTools draw("output/particle_gun/bdt_testing_selection_test.root");
  DataSample mc("output/particle_gun/bdt_testing_selection_test.root");
  
  //draw.SetMinY(1);
  //draw.SetLogY(true);
  
  draw.SetTitleX("BDT mu-like value");
  TCanvas bdt_mu_accum4;
  //draw.SetMinY(100);
  draw.Draw(default,"selmu_bdt_pid_mu",20,0,1,"particle","(accum_level[][0]>4)");
  
  draw.SetTitleX("BDT pi-like value");
  TCanvas bdt_pi_accum4;
  //draw.SetMinY(100);
  draw.Draw(default,"selmu_bdt_pid_pi",20,0,1,"particle","(accum_level[][0]>4)");
  
  draw.SetTitleX("BDT p-like value");
  TCanvas bdt_p_accum4;
  //draw.SetMinY(1000);
  draw.Draw(default,"selmu_bdt_pid_p",20,0,1,"particle","(accum_level[][0]>4)");
  
  draw.SetTitleX("BDT e-like value");
  TCanvas bdt_e_accum4;
  //draw.SetMinY(12);
  draw.Draw(default,"selmu_bdt_pid_e",20,0,1,"particle","(accum_level[][0]>4)");
  
  //draw.SetTitleX("BDT outputs sum");
  //TCanvas bdt_sum_accum4;
  //draw.Draw(default,"selmu_bdt_pid_mu+selmu_bdt_pid_pi+selmu_bdt_pid_p+selmu_bdt_pid_e",20,0,1,"particle","(accum_level[][0]>4)");
}
