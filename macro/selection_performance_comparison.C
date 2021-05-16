{
  DrawingTools draw_mod("output/output_p6T_allruns_modified_withoptimised.root");
  DrawingTools draw_ori("output/output_p6T_allruns_standard_withoptimised.root");
  
  DataSample mc_mod("output/output_p6T_allruns_modified_withoptimised.root");
  DataSample mc_ori("output/output_p6T_allruns_standard_withoptimised.root");
  
  TCanvas momentum_sig_comparison;
  
  draw_ori.SetTitleX("Antimuon candidate true momentum (MeV/c)");
  draw_ori.Draw(default,"selmu_truemom",30,0,6000,"","accum_level[][1]>8", "", "", "Original selection");
  draw_mod.Draw(default,"selmu_truemom",30,0,6000,"","accum_level[][1]>9", "same", "", "Modified selection");
  
}
