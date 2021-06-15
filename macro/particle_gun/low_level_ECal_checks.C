{
  DrawingTools draw("output/particle_gun/localglobaltest1.root");
  DataSample mc("output/particle_gun/localglobaltest1.root");
  
  draw.SetTitleX("selmu_ecal_circularity");
  TCanvas selmu_ecal_circularity;
  draw.Draw(default,"selmu_ecal_circularity",20,-10,10,"particle","accum_level[][0]>4");
}
