{
  DrawingTools draw("output/test.root");
  DataSample mc("output/test.root");

  draw.DumpPOT(mc);
  draw.DumpCuts(mc);
  
  TCanvas effpur_cc1pi;
  draw.DrawEffPurVSCut(mc, 1, "topology==1", "");
}
