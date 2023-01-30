{
    #include <sstream>;
    
    // Initialise DrawingTools
    DrawingTools drawingtools("/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/oaAnalysis_prod6Trun5_1.root");
  
    // Set up MC DataSamples
    DataSample* MC_run5 = new DataSample("/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/oaAnalysis_prod6Trun5_1.root");
    DataSample* MC_run6 = new DataSample("/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/oaAnalysis_prod6Trun6_1.root");
    DataSample* MC_run7 = new DataSample("/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/oaAnalysis_prod6Trun7_1.root");
    DataSample* MC_run9 = new DataSample("/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/oaAnalysis_prod6Trun9_1.root");
    
    // Add Run 5 MC POT info
    for (int i = 2; i <= 112; i++)
    {
        std::stringstream filename;
        filename << "/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/oaAnalysis_prod6Trun5_" << i << ".root";
        MC_run5->AddHeader(filename.str());
    }
    //drawingtools.DumpPOT(*MC);
    
    // Add Run 6 MC POT info
    for (int i = 2; i <= 54; i++)
    {
        std::stringstream filename;
        filename << "/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/oaAnalysis_prod6Trun6_" << i << ".root";
        MC_run6->AddHeader(filename.str());
    }
    //drawingtools.DumpPOT(*MC);
    
    // Add Run 7 MC POT info
    for (int i = 2; i <= 67; i++)
    {
        std::stringstream filename;
        filename << "/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/oaAnalysis_prod6Trun7_" << i << ".root";
        MC_run7->AddHeader(filename.str());
    }
    //drawingtools.DumpPOT(*MC);
    
    // Add Run 9 MC POT info
    for (int i = 2; i <= 12; i++)
    {
        std::stringstream filename;
        filename << "/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/oaAnalysis_prod6Trun9_" << i << ".root";
        MC_run9->AddHeader(filename.str());
    }
    
    
    // Set up real data DataSamples
    DataSample * data_run5 = new DataSample("/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/real_data/real_data_run5_all.root");
    DataSample * data_run6 = new DataSample("/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/real_data/real_data_run6_all.root");
    DataSample * data_run7 = new DataSample("/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/real_data/real_data_run7_all.root");
    DataSample * data_run9 = new DataSample("/bundle/data/T2K/users/gpenn/highlandBDTtests/final/cc1pi/nomuonrejection/real_data/real_data_run9_all.root");
    
    std::cout << "Run 5: " << std::endl;
    drawingtools.DumpPOT(*MC_run5);
    drawingtools.DumpPOT(*data_run5);
    
    std::cout << "Run 6: " << std::endl;
    drawingtools.DumpPOT(*MC_run6);
    drawingtools.DumpPOT(*data_run6);
    
    std::cout << "Run 7: " << std::endl;
    drawingtools.DumpPOT(*MC_run7);
    drawingtools.DumpPOT(*data_run7);
    
    std::cout << "Run 9: " << std::endl;
    drawingtools.DumpPOT(*MC_run9);
    drawingtools.DumpPOT(*data_run9);
    
 }
