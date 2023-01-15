{
  /*DrawingTools run5("output/output_p6T_run5_all.root");
  DataSample mc_run5("output/output_p6T_run5_all.root");
  run5.DumpPOT(mc_run5);
  
  DrawingTools run6("output/output_p6T_run6_all.root");
  DataSample mc_run6("output/output_p6T_run6_all.root");
  run6.DumpPOT(mc_run6);
  
  DrawingTools run7("output/output_p6T_run7_all.root");
  DataSample mc_run7("output/output_p6T_run7_all.root");
  run7.DumpPOT(mc_run7);
  
  DrawingTools run9("output/output_p6T_run9_all.root");
  DataSample mc_run9("output/output_p6T_run9_all.root");
  run9.DumpPOT(mc_run9);*/
  
    // Initialise DrawingTools
    DrawingTools drawingtools("/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/oaAnalysis_prod6Trun5_1.root");
  
    // Set up MC data sample
    DataSample MC("/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/oaAnalysis_prod6Trun5_1.root");
  
    // Add Run 5 MC POT info
    for (int i = 2; i < 113; i++)
    {
        TString prefix = "/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/oaAnalysis_prod6Trun5_";
        TString suffix = ".root"
        MC.AddHeader(prefix + i + suffix);
    }
    
    drawingtools.DumpPOT(MC);
 }
