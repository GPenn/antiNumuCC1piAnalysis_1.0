{
  DrawingTools draw("output/output_p6T_run7_all.root");
  DataSample mc("output/output_p6T_run7_all.root");

  draw.DumpPOT(mc);
  
  TCanvas selmu_necals;
  draw.Draw(default,"selmu_necals",5,0,5,"topology","accum_level[][1]>5");
  
  TCanvas selpi_necals;
  draw.Draw(default,"HMNT_NEcalSegments",5,0,5,"topology","accum_level[][1]>5");
}
