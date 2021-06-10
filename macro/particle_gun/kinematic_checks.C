
{
  DrawingTools draw("output/particle_gun/output_pg_antimu_06101546.root");
  DataSample mc("output/particle_gun/output_pg_antimu_06101546.root");
  
  draw.SetTitleX("Antimuon reco momentum");
  TCanvas selmu_mom_accum4;
  draw.Draw(default,"selmu_mom",20,0,7000,"topology","accum_level[][0]>4");
  
  draw.SetTitleX("Antimuon reco costheta");
  TCanvas selmu_costheta_accum4;
  draw.Draw(default,"selmu_costheta",20,-1,1,"topology","accum_level[][0]>4");
}
