{
  DrawingTools draw("output/particle_gun/particlegun_allpositive_bdttest.root");
  DataSample mc("output/particle_gun/particlegun_allpositive_bdttest.root");
  
  TCanvas effpur_mu;
  draw.DrawEffPurVSCut(mc, 0, "particle_pg==-13");
  
  TCanvas effpur_pi;
  draw.DrawEffPurVSCut(mc, 1, "particle_pg==211");
  
  TCanvas effpur_p;
  draw.DrawEffPurVSCut(mc, 2, "particle_pg==2212");
  
  TCanvas effpur_e;
  draw.DrawEffPurVSCut(mc, 3, "particle_pg==-11");

}
