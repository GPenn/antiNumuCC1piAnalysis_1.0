
{
  DrawingTools draw("output/output_p6T_run5_ecalbestsegtest.root");
  DataSample mc("output/output_p6T_run5_ecalbestsegtest.root");

  draw.DumpPOT(mc);
  
  TCanvas selmu_mom;
  draw.Draw(default,"selmu_mom[0]",50,0,5000,"topology","accum_level[][1]>4");
 
  TCanvas HMNT_mom;
  draw.Draw(default,"HMNT_mom[0]",50,0,5000,"topology","(accum_level[][1]>4)&&(ntpcnegQualityFV>0)");
}
