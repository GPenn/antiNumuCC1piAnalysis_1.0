{
    // Initialise DrawingTools
    DrawingTools drawingtools("/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/oaAnalysis_prod6Trun5_1.root");
  
    // Set up MC data sample
    DataSample MC("/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/oaAnalysis_prod6Trun5_1.root");
  
    // Add Run 5 MC POT info
    for (int i = 2; i <= 11s; i++)
    {
        std::string filename = "/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/oaAnalysis_prod6Trun5_";
        filename += i;
        filename += ".root";
        MC.AddHeader(filename);
    }
    
    drawingtools.DumpPOT(MC);
 }
