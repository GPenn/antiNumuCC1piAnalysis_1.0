{
  DrawingTools draw("output/output_p6T_run7_all.root");
  DataSample mc("output/output_p6T_run7_all.root");

  draw.DumpPOT(mc);
  
  TCanvas sig_bkg_bothsegs;
  draw.Draw(default,"topology==1",2,-0.5,1.5,"topology","accum_level[][1]>7&&selmu_necals==1&&HMNT_NEcalSegments==1");
  
  TCanvas sig_bkg_museg;
  draw.Draw(default,"topology==1",2,-0.5,1.5,"topology","accum_level[][1]>7&&selmu_necals==1&&HMNT_NEcalSegments==0");
  
  TCanvas sig_bkg_piseg;
  draw.Draw(default,"topology==1",2,-0.5,1.5,"topology","accum_level[][1]>7&&selmu_necals==0&&HMNT_NEcalSegments==1");
  
  TCanvas sig_bkg_nosegs;
  draw.Draw(default,"topology==1",2,-0.5,1.5,"topology","accum_level[][1]>7&&selmu_necals==0&&HMNT_NEcalSegments==0");
}
