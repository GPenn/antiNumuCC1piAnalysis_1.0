{
  DrawingTools draw("output/particle_gun/particlegun_antimu.root");
  DataSample mc("output/particle_gun/particlegun_antimu.root");
  
  TCanvas overall_mom;
  draw.Draw(default,"selmu_truemom",50,0,5000,"particle","(accum_level[][0]>4)");
  TCanvas trueantimu_mom;
  draw.Draw(default,"selmu_truemom",50,0,5000,"particle","(accum_level[][0]>4)&&(particle==-31)");
}
