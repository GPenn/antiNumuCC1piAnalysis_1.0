{
    TFile *file_trainingsample = new TFile("../particle_gun/output/ks_trainingsample.root");
    TGraph* ks_test_bdt_mulike_pilike_train  = (TGraph*)file_trainingsample.Get("ks_test_bdt_mulike_pilike_train");
    TGraph* ks_test_bdt_plike_elike_train  = (TGraph*)file_trainingsample.Get("ks_test_bdt_plike_elike_train");
    Int_t n_training = ks_test_bdt_mulike_pilike_train->GetN();
    Double_t training_mulike[n_training];
    Double_t training_pilike[n_training];
    Double_t training_plike[n_training];
    Double_t training_elike[n_training];
    
    std::cout << "Reading " << n_training << " points from training sample..." << std::endl;
    
    for (Int_t i=0; i < n_training; i++)
    {
        ks_test_bdt_mulike_pilike_train->GetPoint(i,training_mulike[i],training_pilike[i]);
        std::cout << "DEBUG: training_mulike[" << i << "] = " << training_mulike[i] << std::endl;
    }

    TFile *file_testingsample = new TFile("../particle_gun/output/ks_testingsample.root");
    TGraph* ks_test_bdt_mulike_pilike_test  = (TGraph*)file_testingsample.Get("ks_test_bdt_mulike_pilike_test");
    TGraph* ks_test_bdt_plike_elike_test  = (TGraph*)file_testingsample.Get("ks_test_bdt_plike_elike_test");
    
    
}
