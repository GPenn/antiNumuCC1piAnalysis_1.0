{
  DrawingTools draw("output/particle_gun/particlegun_antimu_bdttest.root");
  DataSample mc("output/particle_gun/particlegun_antimu_bdttest.root");
  
  draw.SetTitleX("BDT mu-like value");
  TCanvas bdt_mu_accum4;
  draw.Draw(default,"selmu_bdt_pid_mu",20,0,1,"particle","(accum_level[][0]>4)&&(particle==-13)");
}
