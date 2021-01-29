{
  DrawingTools draw("output/output_p6T_allruns.root");
  DataSample mc("output/output_p6T_allruns.root");

  draw.DumpPOT(mc);
  
  TCanvas selmu_necals;
  draw.Draw(default,"selmu_necals",5,0,5,"topology","accum_level[][1]>5&&selmu_necals>0");
  
  TCanvas selmu_necals_multiple;
  draw.Draw(default,"selmu_necals",5,0,5,"topology","accum_level[][1]>5&&selmu_necals>1");
  
  TCanvas selpi_necals;
  draw.Draw(default,"HMNT_NEcalSegments",5,0,5,"topology","accum_level[][1]>5&&HMNT_NEcalSegments>0");
  
  TCanvas selpi_necals_multiple;
  draw.Draw(default,"HMNT_NEcalSegments",5,0,5,"topology","accum_level[][1]>5&&HMNT_NEcalSegments>1");
}
