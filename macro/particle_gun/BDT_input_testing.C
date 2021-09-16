{
  DrawingTools draw("output/particle_gun/particlegun_positron.root");
  DataSample mc("output/particle_gun/particlegun_positron.root");
  
  draw.SetTitleX("HMT reco momentum");
  TCanvas selmu_mom_accum4;
  draw.Draw(default,"selmu_mom",150,0,1500,"particle","accum_level[][0]>4");
}
