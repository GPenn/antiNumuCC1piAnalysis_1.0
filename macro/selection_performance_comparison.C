{
  DrawingTools draw_mod("output/output_p6T_allruns_modified_withoptimised.root");
  DrawingTools draw_ori("output/output_p6T_allruns_standard_withoptimised.root");
  
  DataSample mc_mod("output/output_p6T_allruns_modified_withoptimised.root");
  DataSample mc_ori("output/output_p6T_allruns_standard_withoptimised.root");
  
  //TCanvas momentum_comparison;
  //draw_ori.SetTitleX("Antimuon candidate true momentum (MeV/c)");
  //draw_ori.Draw(default,"selmu_truemom",30,0,6000,"all","accum_level[][1]>8");
  //draw_mod.Draw(default,"selmu_truemom",30,0,6000,"all","accum_level[][1]>9", "same");
  
  //TCanvas efficiency_comparison;
  //draw_ori.SetTitleX("True lepton true momentum (MeV/c)");
  //draw_ori.SetTitleY("antinumu CC1pi selection efficiency");
  //draw_ori.DrawEff(truth,"truelepton_mom",25,0,1000,"accum_level[][1]>8", "topology==1", "", "", "Original selection");
  //draw_mod.DrawEff(truth,"truelepton_mom",25,0,1000,"accum_level[][1]>9", "topology==1", "same", "", "Modified selection");
  
  TCanvas muon_vs_pionmom_ori;
  draw_ori.Draw(mc_ori,"truelepton_mom:truepi_mom",60,0,6000,60,0,6000,"all","(accum_level[][1]>8)&&(topology==1)", "colz");
  TCanvas muon_vs_pionmom_mod;
  draw_mod.Draw(mc_mod,"truelepton_mom:truepi_mom",60,0,6000,60,0,6000,"all","(accum_level[][1]>9)&&(topology==1)", "colz");
  
}
