
{
  DrawingTools draw("output/output_p6T_run5_ecalbestsegtest.root");
  DataSample mc("output/output_p6T_run5_ecalbestsegtest.root");

  draw.DumpPOT(mc);
  
  TCanvas selmu_mom_0;
  draw.Draw(default,"selmu_mom[0]",50,0,5000,"topology","accum_level[][1]>4");
  
  TCanvas selmu_mom_1;
  draw.Draw(default,"selmu_mom[1]",50,0,5000,"topology","accum_level[][1]>4");
  
}
