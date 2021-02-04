{
  DrawingTools draw("output/output_p6T_allruns.root");
  DataSample mc("output/output_p6T_allruns.root");

  draw.DumpPOT(mc);
  
  TCanvas muontrack;
  draw.Draw(default,"particle==-13",2,0,2,"particle","accum_level[][1]>8&&topology==1");
  
  TCanvas piontrack;
  draw.Draw(default,"HMNT_truepdg==211",2,0,2,"topology","accum_level[][1]>8&&topology==1");
  
}
