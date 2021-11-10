{
  DrawingTools draw("output/particle_gun/particlegun_allpositive_bdttest.root");
  DataSample mc("output/particle_gun/particlegun_allpositive_bdttest.root");
  
  draw.DrawEffPurVSCut(mc, 0, "particle_pg==-13");
  
  draw.DrawEffPurVSCut(mc, 1, "particle_pg==211");
  
  draw.DrawEffPurVSCut(mc, 2, "particle_pg==2212");
  
  draw.DrawEffPurVSCut(mc, 3, "particle_pg==-11");

}
