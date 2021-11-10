{
  DrawingTools draw("output/particle_gun/particlegun_allpositive_bdttest.root");
  DataSample mc("output/particle_gun/particlegun_allpositive_bdttest.root");
  
  TCanvas effpur_mu;
  draw.DrawEffPurVSCut(mc, 0, "particle_pg==-13");
  
  TCanvas pur_vs_recomom_mu;
  draw.SetTitleX("Reco momentum (antimu selection)");
  draw.DrawEff(default, "selmu_mom",50,0,5000,"particle_pg==-13","accum_level[][0]>5");
  
  TCanvas effpur_pi;
  draw.DrawEffPurVSCut(mc, 1, "particle_pg==211");
  
  TCanvas pur_vs_recomom_pi;
  draw.SetTitleX("Reco momentum (piplus selection)");
  draw.DrawEff(default, "selmu_mom",50,0,5000,"particle_pg==211","accum_level[][1]>5");
  
  TCanvas effpur_p;
  draw.DrawEffPurVSCut(mc, 2, "particle_pg==2212");
  
  TCanvas pur_vs_recomom_p;
  draw.SetTitleX("Reco momentum (proton selection)");
  draw.DrawEff(default, "selmu_mom",50,0,5000,"particle_pg==2212","accum_level[][2]>5");
  
  TCanvas effpur_e;
  draw.DrawEffPurVSCut(mc, 3, "particle_pg==-11");
  
  TCanvas pur_vs_recomom_e;
  draw.SetTitleX("Reco momentum (electron selection)");
  draw.DrawEff(default, "selmu_mom",50,0,5000,"particle_pg==-11","accum_level[][3]>5");

}
