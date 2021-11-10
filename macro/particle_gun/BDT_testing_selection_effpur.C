{
  DrawingTools draw("output/particle_gun/particlegun_allpositive_bdttest.root");
  DataSample mc("output/particle_gun/particlegun_allpositive_bdttest.root");
  
  draw.DrawEffPurVSCut(mc,"particle_pg==-13", 0);
  
  draw.DrawEffPurVSCut(mc,"particle_pg==211", 1);
  
  draw.DrawEffPurVSCut(mc,"particle_pg==2212", 2);
  
  draw.DrawEffPurVSCut(mc,"particle_pg==-11", 3);

}
