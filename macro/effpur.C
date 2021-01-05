{
  DrawingTools draw("output/test.root");
  DataSample mc("output/test.root");

  draw.DumpPOT(mc);
  
  TCanvas effpur_cc1pi;
  draw.DrawEffPurVSCut(mc, 1, "topology==1", "");
}
