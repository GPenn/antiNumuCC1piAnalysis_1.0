{
  DrawingTools draw("/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/oaAnalysis_prod6Trun5_1.root");
  DataSample mc("/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/oaAnalysis_prod6Trun5_1.root");

  draw.DumpPOT(mc);
  
  TCanvas reaction;
  draw.Draw(default,"reaction",10,0,10,"reaction","accum_level[][1]>4");
}
