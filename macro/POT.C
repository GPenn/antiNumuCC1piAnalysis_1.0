{
    #include <sstream>;
    
    // Initialise DrawingTools
    DrawingTools drawingtools("/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/oaAnalysis_prod6Trun5_1.root");
  
    // Set up MC DataSample
    DataSample MC("/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/oaAnalysis_prod6Trun5_1.root");
    //drawingtools.DumpPOT(MC);
    
    // Add Run 5 MC POT info
    for (int i = 2; i <= 112; i++)
    {
        std::stringstream filename;
        filename << "/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/oaAnalysis_prod6Trun5_" << i << ".root";
        MC.AddHeader(filename.str());
    }
    //drawingtools.DumpPOT(MC);
    
    // Add Run 6 MC POT info
    for (int i = 1; i <= 54; i++)
    {
        std::stringstream filename;
        filename << "/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/oaAnalysis_prod6Trun6_" << i << ".root";
        MC.AddHeader(filename.str());
    }
    //drawingtools.DumpPOT(MC);
    
    // Add Run 7 MC POT info
    for (int i = 1; i <= 67; i++)
    {
        std::stringstream filename;
        filename << "/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/oaAnalysis_prod6Trun7_" << i << ".root";
        MC.AddHeader(filename.str());
    }
    //drawingtools.DumpPOT(MC);
    
    // Add Run 9 MC POT info
    for (int i = 1; i <= 12; i++)
    {
        std::stringstream filename;
        filename << "/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/oaAnalysis_prod6Trun9_" << i << ".root";
        MC.AddHeader(filename.str());
    }
    drawingtools.DumpPOT(MC);
    
    // Set up real data DataSample
    DataSample data("/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/real_data/real_data_run5_all.root");
    data.AddHeader("/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/real_data/real_data_run6_all.root");
    data.AddHeader("/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/real_data/real_data_run7_all.root");
    data.AddHeader("/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/real_data/real_data_run9_all.root");
    
    drawingtools.DumpPOT(data);
    
    // Create experiment for data-MC comparison
    Experiment comparison("comparison", *data, *MC);
    comparison.DumpPOTRatios;
 }
