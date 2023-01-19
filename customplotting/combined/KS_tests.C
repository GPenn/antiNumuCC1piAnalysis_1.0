{
    TRandom *random = new TRandom();
    
    TFile *file_trainingsample = new TFile("../particle_gun/output/ks_trainingsample.root");
    TGraph* ks_test_bdt_mulike_pilike_train  = (TGraph*)file_trainingsample.Get("ks_test_bdt_mulike_pilike_train");
    TGraph* ks_test_bdt_plike_elike_train  = (TGraph*)file_trainingsample.Get("ks_test_bdt_plike_elike_train");
    Int_t n_training = ks_test_bdt_mulike_pilike_train->GetN();
    Double_t training_mulike[n_training];
    Double_t training_pilike[n_training];
    Double_t training_plike[n_training];
    Double_t training_elike[n_training];
    long long training_mulike_ind[n_training];
    long long training_pilike_ind[n_training];
    long long training_plike_ind[n_training];
    long long training_elike_ind[n_training];
    Double_t training_mulike_sorted[n_training];
    Double_t training_pilike_sorted[n_training];
    Double_t training_plike_sorted[n_training];
    Double_t training_elike_sorted[n_training];
    TH1F* training_mulike_debug_hist = new TH1F("training_mulike_debug_hist", "training_mulike_debug_hist", 20, 0.0, 1.0);
    
    std::cout << "Reading " << n_training << " points from training sample..." << std::endl;
    
    for (Int_t i=0; i < n_training; i++)
    {
        ks_test_bdt_mulike_pilike_train->GetPoint(i,training_mulike[i],training_pilike[i]);
        training_mulike[i] = random->Uniform();
        training_mulike_debug_hist->Fill(training_mulike[i]);
        //std::cout << "DEBUG: training_mulike[" << i << "] = " << training_mulike[i] << std::endl;
        ks_test_bdt_plike_elike_train->GetPoint(i,training_plike[i],training_elike[i]);
    }

    TFile *file_testingsample = new TFile("../particle_gun/output/ks_testingsample.root");
    TGraph* ks_test_bdt_mulike_pilike_test  = (TGraph*)file_testingsample.Get("ks_test_bdt_mulike_pilike_test");
    TGraph* ks_test_bdt_plike_elike_test  = (TGraph*)file_testingsample.Get("ks_test_bdt_plike_elike_test");
    Int_t n_testing = ks_test_bdt_mulike_pilike_test->GetN();
    Double_t testing_mulike[n_testing];
    Double_t testing_pilike[n_testing];
    Double_t testing_plike[n_testing];
    Double_t testing_elike[n_testing];
    long long testing_mulike_ind[n_testing];
    long long testing_pilike_ind[n_testing];
    long long testing_plike_ind[n_testing];
    long long testing_elike_ind[n_testing];
    Double_t testing_mulike_sorted[n_testing];
    Double_t testing_pilike_sorted[n_testing];
    Double_t testing_plike_sorted[n_testing];
    Double_t testing_elike_sorted[n_testing];
    TH1F* testing_mulike_debug_hist = new TH1F("testing_mulike_debug_hist", "testing_mulike_debug_hist", 20, 0.0, 1.0);
    
    std::cout << "Reading " << n_testing << " points from testing sample..." << std::endl;
    
    for (Int_t i=0; i < n_testing; i++)
    {
        ks_test_bdt_mulike_pilike_test->GetPoint(i,testing_mulike[i],testing_pilike[i]);
        testing_mulike[i] = random->Uniform();
        testing_mulike_debug_hist->Fill(testing_mulike[i]);
        //std::cout << "DEBUG: testing_mulike[" << i << "] = " << testing_mulike[i] << std::endl;
        ks_test_bdt_plike_elike_test->GetPoint(i,testing_plike[i],testing_elike[i]);
    }
    
    TMath::Sort(n_training,training_mulike,training_mulike_ind,kFALSE);
    for (Int_t i=0; i < n_training; i++)
    {
        //std::cout << "DEBUG: training_mulike[" << i << "] = " << training_mulike[i] << " " << training_mulike_ind[i] << std::endl;
        training_mulike_sorted[i] = training_mulike[training_mulike_ind[i]];
        //std::cout << "DEBUG: training_mulike_sorted[" << i << "] = " << training_mulike_sorted[i] << std::endl;
    }
    TMath::Sort(n_testing,testing_mulike,testing_mulike_ind,kFALSE);
    for (Int_t i=0; i < n_testing; i++)
    {
        //std::cout << "DEBUG: training_mulike[" << i << "] = " << training_mulike[i] << " " << training_mulike_ind[i] << std::endl;
        testing_mulike_sorted[i] = testing_mulike[testing_mulike_ind[i]];
        //std::cout << "DEBUG: testing_mulike_sorted[" << i << "] = " << testing_mulike_sorted[i] << std::endl;
    }

    Double_t ks_result_mulike = TMath::KolmogorovTest(n_training, training_mulike_sorted, n_testing, testing_mulike_sorted, "D");
    std::cout << "Mu-like output KS test result: " << ks_result_mulike << std::endl;
    Double_t ks_result_pilike = TMath::KolmogorovTest(n_training, training_pilike, n_testing, testing_pilike, "D");
    std::cout << "Pi-like output KS test result: " << ks_result_pilike << std::endl;
    Double_t ks_result_plike = TMath::KolmogorovTest(n_training, training_plike, n_testing, testing_plike, "D");
    std::cout << "Proton-like output KS test result: " << ks_result_plike << std::endl;
    Double_t ks_result_elike = TMath::KolmogorovTest(n_training, training_elike, n_testing, testing_elike, "D");
    std::cout << "Electron-like output KS test result: " << ks_result_elike << std::endl;
    
    TCanvas* mulike_debug_canvas = new TCanvas("mulike_debug_canvas","mulike_debug_canvas",200,10,1000,600);
    training_mulike_debug_hist->Draw();
    testing_mulike_debug_hist->Draw("same");
    
    Double_t ks_result_hists = training_mulike_debug_hist->KolmogorovTest(testing_mulike_debug_hist);
    std::cout << "Debug hist KS test result: " << ks_result_plike << std::endl;
}
