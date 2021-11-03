{
  DrawingTools draw("output/particle_gun/particlegun_antimu_bdttest.root");
  DataSample mc("output/particle_gun/particlegun_antimu_bdttest.root");
  
  draw.DrawEffPurVSCut(mc,"particle_pg==-13");

}
