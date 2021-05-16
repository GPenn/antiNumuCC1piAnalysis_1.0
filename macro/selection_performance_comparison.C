{
  DrawingTools draw_mod("output/output_p6T_allruns_modified_withoptimised.root");
  DrawingTools draw_ori("output/output_p6T_allruns_standard_withoptimised.root");
  
  DataSample mc_mod("output/output_p6T_allruns_modified_withoptimised.root");
  DataSample mc_ori("output/output_p6T_allruns_standard_withoptimised.root");
  
  TCanvas momentum_comparison;
  draw_ori.SetTitleX("Antimuon candidate true momentum (MeV/c)");
  draw_ori.Draw(default,"selmu_truemom",30,0,6000,"all","accum_level[][1]>8");
  draw_mod.Draw(default,"selmu_truemom",30,0,6000,"all","accum_level[][1]>9", "same");
  
  TCanvas efficiency_comparison;
  draw_ori.SetTitleX("True lepton true momentum (MeV/c)");
  draw_ori.SetTitleY("$\bar{\nu}_\mu$ CC1pi selection efficiency");
  draw_ori.DrawEff(truth,"truemu_truemom",30,0,6000,"accum_level[][1]>8", "topology==1");
  draw_mod.DrawEff(truth,"truemu_truemom",30,0,6000,"accum_level[][1]>9", "topology==1", "same");
  
  //TCanvas muon_vs_pionmom;
  //draw_ori.Draw(default,"selmu_truemom:",30,0,6000,"all","accum_level[][1]>8");
  
}
