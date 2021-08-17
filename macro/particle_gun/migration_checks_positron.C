{
  DrawingTools draw("output/particle_gun/particlegun_positron.root");
  DataSample mc("output/particle_gun/particlegun_positron.root");
  
  TCanvas overall_mom;
  draw.Draw(default,"selmu_truemom",60,0,3000,"particle","(accum_level[][0]>4)");
  TCanvas truepositron_mom;
  draw.Draw(default,"selmu_truemom",60,0,3000,"particle","(accum_level[][0]>4)&&(particle==-11)");
}
