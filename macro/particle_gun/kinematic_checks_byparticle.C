{
  DrawingTools draw_amu("output/particle_gun/particlegun_antimu.root");
  DataSample mc_amu("output/particle_gun/particlegun_antimu.root");
  
  draw_amu.SetTitleX("Antimu reco momentum");
  draw_amu.SetTitleY("Antimu true momentum");
  TCanvas amu_momcorr_accum4;
  draw_amu.Draw(default,"selmu_mom:selmu_truemom",20,0,7000,20,0,7000, "all", "(accum_level[][0]>4)&&(particle==-13)", "colz");
}
