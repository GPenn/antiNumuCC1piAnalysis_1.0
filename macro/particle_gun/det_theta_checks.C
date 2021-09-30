{
  DrawingTools draw("output/particle_gun/particlegun_allpositive.root");
  DataSample mc("output/particle_gun/particlegun_allpositive.root");
  
  draw.SetTitleX("selmu_det_theta");
  TCanvas selmu_det_theta_accum4;
  draw.Draw(default,"selmu_det_theta",50,0.0,3.14,"particle","accum_level[][0]>4");
}
