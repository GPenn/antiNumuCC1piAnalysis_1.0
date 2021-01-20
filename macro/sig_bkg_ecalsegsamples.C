{
  DrawingTools draw("output/output_p6T_run7_all.root");
  DataSample mc("output/output_p6T_run7_all.root");

  draw.DumpPOT(mc);
  
  TCanvas sig_bkg_bothsegs;
  draw.Draw(default,"topology==1",-0.5,0,1.5,"topology","accum_level[][1]>7&&selmu_necals==1&&HMNT_NEcalSegments==1");
  
  
}
