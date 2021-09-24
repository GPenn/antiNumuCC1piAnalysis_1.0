{
  DrawingTools draw("output/particle_gun/particlegun_antimu_bdttest.root");
  DataSample mc("output/particle_gun/particlegun_antimu_bdttest.root");
  
  draw.SetTitleX("BDT mu-like value");
  TCanvas bdt_mu_accum4;
  draw.Draw(default,"selmu_bdt_pid_mu",20,0,1,"particle","(accum_level[][0]>4)&&(particle==-13)");
  
  draw.SetTitleX("BDT pi-like value");
  TCanvas bdt_pi_accum4;
  draw.Draw(default,"selmu_bdt_pid_pi",20,0,1,"particle","(accum_level[][0]>4)&&(particle==-13)");
  
  draw.SetTitleX("BDT p-like value");
  TCanvas bdt_p_accum4;
  draw.Draw(default,"selmu_bdt_pid_p",20,0,1,"particle","(accum_level[][0]>4)&&(particle==-13)");
  
  draw.SetTitleX("BDT e-like value");
  TCanvas bdt_e_accum4;
  draw.Draw(default,"selmu_bdt_pid_e",20,0,1,"particle","(accum_level[][0]>4)&&(particle==-13)");
}
