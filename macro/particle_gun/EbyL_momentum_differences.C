{
  DrawingTools draw("output/particle_gun/particlegun_antimu.root");
  DataSample mc("output/particle_gun/particlegun_antimu.root");
  
  draw.SetTitleX("ECal E/L");
  TCanvas selmu_ecal_EbyL_below500;
  draw.Draw(default,"selmu_ecal_EMenergy[0]/selmu_ecal_length[0]",50,0.0,4.0,"particle","(accum_level[][0]>4)&&(selmu_necals==1)&&(selmu_mom<500.0)");
  
  TCanvas selmu_ecal_EbyL_above1000;
  draw.Draw(default,"selmu_ecal_EMenergy[0]/selmu_ecal_length[0]",50,0.0,4.0,"particle","(accum_level[][0]>4)&&(selmu_necals==1)&&(selmu_mom>1000.0)");
}
