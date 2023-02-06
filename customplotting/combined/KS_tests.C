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
    TH1F* training_mulike_debug_hist = new TH1F("training_mulike_debug_hist", "training_mulike_debug_hist", 1000, 0.0, 1.0);
    TH1F* bdt_mulike_antimu_train = (TH1F*)file_trainingsample.Get("bdt_mulike_antimu");
    TH1F* bdt_mulike_piplus_train = (TH1F*)file_trainingsample.Get("bdt_mulike_piplus");
    TH1F* bdt_mulike_proton_train = (TH1F*)file_trainingsample.Get("bdt_mulike_proton");
    TH1F* bdt_mulike_positron_train = (TH1F*)file_trainingsample.Get("bdt_mulike_positron");
    TH1F* bdt_pilike_antimu_train = (TH1F*)file_trainingsample.Get("bdt_pilike_antimu");
    TH1F* bdt_pilike_piplus_train = (TH1F*)file_trainingsample.Get("bdt_pilike_piplus");
    TH1F* bdt_pilike_proton_train = (TH1F*)file_trainingsample.Get("bdt_pilike_proton");
    TH1F* bdt_pilike_positron_train = (TH1F*)file_trainingsample.Get("bdt_pilike_positron");
    TH1F* bdt_plike_antimu_train = (TH1F*)file_trainingsample.Get("bdt_plike_antimu");
    TH1F* bdt_plike_piplus_train = (TH1F*)file_trainingsample.Get("bdt_plike_piplus");
    TH1F* bdt_plike_proton_train = (TH1F*)file_trainingsample.Get("bdt_plike_proton");
    TH1F* bdt_plike_positron_train = (TH1F*)file_trainingsample.Get("bdt_plike_positron");
    TH1F* bdt_elike_antimu_train = (TH1F*)file_trainingsample.Get("bdt_elike_antimu");
    TH1F* bdt_elike_piplus_train = (TH1F*)file_trainingsample.Get("bdt_elike_piplus");
    TH1F* bdt_elike_proton_train = (TH1F*)file_trainingsample.Get("bdt_elike_proton");
    TH1F* bdt_elike_positron_train = (TH1F*)file_trainingsample.Get("bdt_elike_positron");
    
    std::cout << "Reading " << n_training << " points from training sample..." << std::endl;
    
    for (Int_t i=0; i < n_training; i++)
    {
        ks_test_bdt_mulike_pilike_train->GetPoint(i,training_mulike[i],training_pilike[i]);
        //training_mulike[i] = random->Uniform();
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
    TH1F* testing_mulike_debug_hist = new TH1F("testing_mulike_debug_hist", "testing_mulike_debug_hist", 1000, 0.0, 1.0);
    TH1F* bdt_mulike_antimu_test = (TH1F*)file_testingsample.Get("bdt_mulike_antimu");
    TH1F* bdt_mulike_piplus_test = (TH1F*)file_testingsample.Get("bdt_mulike_piplus");
    TH1F* bdt_mulike_proton_test = (TH1F*)file_testingsample.Get("bdt_mulike_proton");
    TH1F* bdt_mulike_positron_test = (TH1F*)file_testingsample.Get("bdt_mulike_positron");
    TH1F* bdt_pilike_antimu_test = (TH1F*)file_testingsample.Get("bdt_pilike_antimu");
    TH1F* bdt_pilike_piplus_test = (TH1F*)file_testingsample.Get("bdt_pilike_piplus");
    TH1F* bdt_pilike_proton_test = (TH1F*)file_testingsample.Get("bdt_pilike_proton");
    TH1F* bdt_pilike_positron_test = (TH1F*)file_testingsample.Get("bdt_pilike_positron");
    TH1F* bdt_plike_antimu_test = (TH1F*)file_testingsample.Get("bdt_plike_antimu");
    TH1F* bdt_plike_piplus_test = (TH1F*)file_testingsample.Get("bdt_plike_piplus");
    TH1F* bdt_plike_proton_test = (TH1F*)file_testingsample.Get("bdt_plike_proton");
    TH1F* bdt_plike_positron_test = (TH1F*)file_testingsample.Get("bdt_plike_positron");
    TH1F* bdt_elike_antimu_test = (TH1F*)file_testingsample.Get("bdt_elike_antimu");
    TH1F* bdt_elike_piplus_test = (TH1F*)file_testingsample.Get("bdt_elike_piplus");
    TH1F* bdt_elike_proton_test = (TH1F*)file_testingsample.Get("bdt_elike_proton");
    TH1F* bdt_elike_positron_test = (TH1F*)file_testingsample.Get("bdt_elike_positron");
    
    std::cout << "Reading " << n_testing << " points from testing sample..." << std::endl;
    
    for (Int_t i=0; i < n_testing; i++)
    {
        ks_test_bdt_mulike_pilike_test->GetPoint(i,testing_mulike[i],testing_pilike[i]);
        //testing_mulike[i] = random->Uniform();
        testing_mulike_debug_hist->Fill(testing_mulike[i]);
        //std::cout << "DEBUG: testing_mulike[" << i << "] = " << testing_mulike[i] << std::endl;
        ks_test_bdt_plike_elike_test->GetPoint(i,testing_plike[i],testing_elike[i]);
    }
    
    TMath::Sort(n_training,training_mulike,training_mulike_ind,kFALSE);
    TMath::Sort(n_training,training_pilike,training_pilike_ind,kFALSE);
    TMath::Sort(n_training,training_plike,training_plike_ind,kFALSE);
    TMath::Sort(n_training,training_elike,training_elike_ind,kFALSE);
    for (Int_t i=0; i < n_training; i++)
    {
        //std::cout << "DEBUG: training_mulike[" << i << "] = " << training_mulike[i] << " " << training_mulike_ind[i] << std::endl;
        training_mulike_sorted[i] = training_mulike[training_mulike_ind[i]];
        //std::cout << "DEBUG: training_mulike_sorted[" << i << "] = " << training_mulike_sorted[i] << std::endl;
        training_pilike_sorted[i] = training_pilike[training_pilike_ind[i]];
        training_plike_sorted[i] = training_plike[training_plike_ind[i]];
        training_elike_sorted[i] = training_elike[training_elike_ind[i]];
    }
    
    TMath::Sort(n_testing,testing_mulike,testing_mulike_ind,kFALSE);
    TMath::Sort(n_testing,testing_pilike,testing_pilike_ind,kFALSE);
    TMath::Sort(n_testing,testing_plike,testing_plike_ind,kFALSE);
    TMath::Sort(n_testing,testing_elike,testing_elike_ind,kFALSE);
    for (Int_t i=0; i < n_testing; i++)
    {
        //std::cout << "DEBUG: training_mulike[" << i << "] = " << training_mulike[i] << " " << training_mulike_ind[i] << std::endl;
        testing_mulike_sorted[i] = testing_mulike[testing_mulike_ind[i]];
        //std::cout << "DEBUG: testing_mulike_sorted[" << i << "] = " << testing_mulike_sorted[i] << std::endl;
        testing_pilike_sorted[i] = testing_pilike[testing_pilike_ind[i]];
        testing_plike_sorted[i] = testing_plike[testing_plike_ind[i]];
        testing_elike_sorted[i] = testing_elike[testing_elike_ind[i]];
    }

    Double_t ks_result_mulike = TMath::KolmogorovTest(n_training, training_mulike_sorted, n_testing, testing_mulike_sorted, "D");
    std::cout << "Mu-like output KS test result: " << ks_result_mulike << std::endl;
    Double_t ks_result_pilike = TMath::KolmogorovTest(n_training, training_pilike_sorted, n_testing, testing_pilike_sorted, "D");
    std::cout << "Pi-like output KS test result: " << ks_result_pilike << std::endl;
    Double_t ks_result_plike = TMath::KolmogorovTest(n_training, training_plike_sorted, n_testing, testing_plike_sorted, "D");
    std::cout << "Proton-like output KS test result: " << ks_result_plike << std::endl;
    Double_t ks_result_elike = TMath::KolmogorovTest(n_training, training_elike_sorted, n_testing, testing_elike_sorted, "D");
    std::cout << "Electron-like output KS test result: " << ks_result_elike << std::endl;
    
    TCanvas* mulike_debug_canvas = new TCanvas("mulike_debug_canvas","mulike_debug_canvas",200,10,1000,600);
    bdt_mulike_antimu_train->Sumw2();
    bdt_mulike_antimu_train->SetLineColor(kRed);
    bdt_mulike_antimu_train->Draw();
    bdt_mulike_antimu_test->Sumw2();
    bdt_mulike_antimu_train->SetLineColor(kBlack);
    bdt_mulike_antimu_test->Draw("same");
    
    Double_t ks_result_hists = training_mulike_debug_hist->KolmogorovTest(testing_mulike_debug_hist, "XD");
    std::cout << "Debug hist KS test result: " << ks_result_hists << std::endl;
    
    Double_t ks_result_bdt_mulike_antimu = bdt_mulike_antimu_train->KolmogorovTest(bdt_mulike_antimu_test, "X");
    std::cout << "bdt_mulike_antimu KS test result: " << ks_result_bdt_mulike_antimu << std::endl;
    Double_t ks_result_bdt_mulike_piplus = bdt_mulike_piplus_train->KolmogorovTest(bdt_mulike_piplus_test, "X");
    std::cout << "bdt_mulike_piplus KS test result: " << ks_result_bdt_mulike_piplus << std::endl;
    Double_t ks_result_bdt_mulike_proton = bdt_mulike_proton_train->KolmogorovTest(bdt_mulike_proton_test, "X");
    std::cout << "bdt_mulike_proton KS test result: " << ks_result_bdt_mulike_proton << std::endl;
    Double_t ks_result_bdt_mulike_positron = bdt_mulike_positron_train->KolmogorovTest(bdt_mulike_positron_test, "X");
    std::cout << "bdt_mulike_positron KS test result: " << ks_result_bdt_mulike_positron << std::endl;
    Double_t ks_result_bdt_pilike_antimu = bdt_pilike_antimu_train->KolmogorovTest(bdt_pilike_antimu_test, "X");
    std::cout << "bdt_pilike_antimu KS test result: " << ks_result_bdt_pilike_antimu << std::endl;
    Double_t ks_result_bdt_pilike_piplus = bdt_pilike_piplus_train->KolmogorovTest(bdt_pilike_piplus_test, "X");
    std::cout << "bdt_pilike_piplus KS test result: " << ks_result_bdt_pilike_piplus << std::endl;
    Double_t ks_result_bdt_pilike_proton = bdt_pilike_proton_train->KolmogorovTest(bdt_pilike_proton_test, "X");
    std::cout << "bdt_pilike_proton KS test result: " << ks_result_bdt_pilike_proton << std::endl;
    Double_t ks_result_bdt_pilike_positron = bdt_pilike_positron_train->KolmogorovTest(bdt_pilike_positron_test, "X");
    std::cout << "bdt_pilike_positron KS test result: " << ks_result_bdt_pilike_positron << std::endl;
    Double_t ks_result_bdt_plike_antimu = bdt_plike_antimu_train->KolmogorovTest(bdt_plike_antimu_test, "X");
    std::cout << "bdt_plike_antimu KS test result: " << ks_result_bdt_plike_antimu << std::endl;
    Double_t ks_result_bdt_plike_piplus = bdt_plike_piplus_train->KolmogorovTest(bdt_plike_piplus_test, "X");
    std::cout << "bdt_plike_piplus KS test result: " << ks_result_bdt_plike_piplus << std::endl;
    Double_t ks_result_bdt_plike_proton = bdt_plike_proton_train->KolmogorovTest(bdt_plike_proton_test, "X");
    std::cout << "bdt_plike_proton KS test result: " << ks_result_bdt_plike_proton << std::endl;
    Double_t ks_result_bdt_plike_positron = bdt_plike_positron_train->KolmogorovTest(bdt_plike_positron_test, "X");
    std::cout << "bdt_plike_positron KS test result: " << ks_result_bdt_plike_positron << std::endl;
    Double_t ks_result_bdt_elike_antimu = bdt_elike_antimu_train->KolmogorovTest(bdt_elike_antimu_test, "X");
    std::cout << "bdt_elike_antimu KS test result: " << ks_result_bdt_elike_antimu << std::endl;
    Double_t ks_result_bdt_elike_piplus = bdt_elike_piplus_train->KolmogorovTest(bdt_elike_piplus_test, "X");
    std::cout << "bdt_elike_piplus KS test result: " << ks_result_bdt_elike_piplus << std::endl;
    Double_t ks_result_bdt_elike_proton = bdt_elike_proton_train->KolmogorovTest(bdt_elike_proton_test, "X");
    std::cout << "bdt_elike_proton KS test result: " << ks_result_bdt_elike_proton << std::endl;
    Double_t ks_result_bdt_elike_positron = bdt_elike_positron_train->KolmogorovTest(bdt_elike_positron_test, "X");
    std::cout << "bdt_elike_positron KS test result: " << ks_result_bdt_elike_positron << std::endl;
    
    Double_t chi2_result_bdt_mulike_antimu = bdt_mulike_antimu_train->Chi2Test(bdt_mulike_antimu_test, "UU");
    std::cout << "bdt_mulike_antimu chi2 test result: " << chi2_result_bdt_mulike_antimu << std::endl;
    Double_t chi2_result_bdt_mulike_piplus = bdt_mulike_piplus_train->Chi2Test(bdt_mulike_piplus_test, "UU");
    std::cout << "bdt_mulike_piplus chi2 test result: " << chi2_result_bdt_mulike_piplus << std::endl;
    Double_t chi2_result_bdt_mulike_proton = bdt_mulike_proton_train->Chi2Test(bdt_mulike_proton_test, "UU");
    std::cout << "bdt_mulike_proton chi2 test result: " << chi2_result_bdt_mulike_proton << std::endl;
    Double_t chi2_result_bdt_mulike_positron = bdt_mulike_positron_train->Chi2Test(bdt_mulike_positron_test, "UU");
    std::cout << "bdt_mulike_positron chi2 test result: " << chi2_result_bdt_mulike_positron << std::endl;
    Double_t chi2_result_bdt_pilike_antimu = bdt_pilike_antimu_train->Chi2Test(bdt_pilike_antimu_test, "UU");
    std::cout << "bdt_pilike_antimu chi2 test result: " << chi2_result_bdt_pilike_antimu << std::endl;
    Double_t chi2_result_bdt_pilike_piplus = bdt_pilike_piplus_train->Chi2Test(bdt_pilike_piplus_test, "UU");
    std::cout << "bdt_pilike_piplus chi2 test result: " << chi2_result_bdt_pilike_piplus << std::endl;
    Double_t chi2_result_bdt_pilike_proton = bdt_pilike_proton_train->Chi2Test(bdt_pilike_proton_test, "UU");
    std::cout << "bdt_pilike_proton chi2 test result: " << chi2_result_bdt_pilike_proton << std::endl;
    Double_t chi2_result_bdt_pilike_positron = bdt_pilike_positron_train->Chi2Test(bdt_pilike_positron_test, "UU");
    std::cout << "bdt_pilike_positron chi2 test result: " << chi2_result_bdt_pilike_positron << std::endl;
    Double_t chi2_result_bdt_plike_antimu = bdt_plike_antimu_train->Chi2Test(bdt_plike_antimu_test, "UU");
    std::cout << "bdt_plike_antimu chi2 test result: " << chi2_result_bdt_plike_antimu << std::endl;
    Double_t chi2_result_bdt_plike_piplus = bdt_plike_piplus_train->Chi2Test(bdt_plike_piplus_test, "UU");
    std::cout << "bdt_plike_piplus chi2 test result: " << chi2_result_bdt_plike_piplus << std::endl;
    Double_t chi2_result_bdt_plike_proton = bdt_plike_proton_train->Chi2Test(bdt_plike_proton_test, "UU");
    std::cout << "bdt_plike_proton chi2 test result: " << chi2_result_bdt_plike_proton << std::endl;
    Double_t chi2_result_bdt_plike_positron = bdt_plike_positron_train->Chi2Test(bdt_plike_positron_test, "UU");
    std::cout << "bdt_plike_positron chi2 test result: " << chi2_result_bdt_plike_positron << std::endl;
    Double_t chi2_result_bdt_elike_antimu = bdt_elike_antimu_train->Chi2Test(bdt_elike_antimu_test, "UU");
    std::cout << "bdt_elike_antimu chi2 test result: " << chi2_result_bdt_elike_antimu << std::endl;
    Double_t chi2_result_bdt_elike_piplus = bdt_elike_piplus_train->Chi2Test(bdt_elike_piplus_test, "UU");
    std::cout << "bdt_elike_piplus chi2 test result: " << chi2_result_bdt_elike_piplus << std::endl;
    Double_t chi2_result_bdt_elike_proton = bdt_elike_proton_train->Chi2Test(bdt_elike_proton_test, "UU");
    std::cout << "bdt_elike_proton chi2 test result: " << chi2_result_bdt_elike_proton << std::endl;
    Double_t chi2_result_bdt_elike_positron = bdt_elike_positron_train->Chi2Test(bdt_elike_positron_test, "UU");
    std::cout << "bdt_elike_positron chi2 test result: " << chi2_result_bdt_elike_positron << std::endl;
    
    TH1F* bdt_mulike_all_train = bdt_mulike_antimu_train->Clone("bdt_mulike_all_train");
    bdt_mulike_all_train->Add(bdt_mulike_piplus_train);
    bdt_mulike_all_train->Add(bdt_mulike_proton_train);
    bdt_mulike_all_train->Add(bdt_mulike_positron_train);
    
    TH1F* bdt_mulike_all_test = bdt_mulike_antimu_test->Clone("bdt_mulike_all_test");
    bdt_mulike_all_test->Add(bdt_mulike_piplus_test);
    bdt_mulike_all_test->Add(bdt_mulike_proton_test);
    bdt_mulike_all_test->Add(bdt_mulike_positron_test);
    
    Double_t ks_result_bdt_mulike = bdt_mulike_all_train->KolmogorovTest(bdt_mulike_all_test, "X");
    std::cout << "bdt_mulike_all KS test result: " << ks_result_bdt_mulike << std::endl;
    Double_t chi2_result_bdt_mulike = bdt_mulike_all_train->Chi2Test(bdt_mulike_all_test, "UU");
    std::cout << "bdt_mulike_all chi2 test result: " << chi2_result_bdt_mulike << std::endl;
    
    TH1F* bdt_pilike_all_train = bdt_pilike_antimu_train->Clone("bdt_pilike_all_train");
    bdt_pilike_all_train->Add(bdt_pilike_piplus_train);
    bdt_pilike_all_train->Add(bdt_pilike_proton_train);
    bdt_pilike_all_train->Add(bdt_pilike_positron_train);
    
    TH1F* bdt_pilike_all_test = bdt_pilike_antimu_test->Clone("bdt_pilike_all_test");
    bdt_pilike_all_test->Add(bdt_pilike_piplus_test);
    bdt_pilike_all_test->Add(bdt_pilike_proton_test);
    bdt_pilike_all_test->Add(bdt_pilike_positron_test);
    
    Double_t ks_result_bdt_pilike = bdt_pilike_all_train->KolmogorovTest(bdt_pilike_all_test, "X");
    std::cout << "bdt_pilike_all KS test result: " << ks_result_bdt_pilike << std::endl;
    Double_t chi2_result_bdt_pilike = bdt_pilike_all_train->Chi2Test(bdt_pilike_all_test, "UU");
    std::cout << "bdt_pilike_all chi2 test result: " << chi2_result_bdt_pilike << std::endl;
    
    TH1F* bdt_plike_all_train = bdt_plike_antimu_train->Clone("bdt_plike_all_train");
    bdt_plike_all_train->Add(bdt_plike_piplus_train);
    bdt_plike_all_train->Add(bdt_plike_proton_train);
    bdt_plike_all_train->Add(bdt_plike_positron_train);
    
    TH1F* bdt_plike_all_test = bdt_plike_antimu_test->Clone("bdt_plike_all_test");
    bdt_plike_all_test->Add(bdt_plike_piplus_test);
    bdt_plike_all_test->Add(bdt_plike_proton_test);
    bdt_plike_all_test->Add(bdt_plike_positron_test);
    
    Double_t ks_result_bdt_plike = bdt_plike_all_train->KolmogorovTest(bdt_plike_all_test, "X");
    std::cout << "bdt_plike_all KS test result: " << ks_result_bdt_plike << std::endl;
    Double_t chi2_result_bdt_plike = bdt_plike_all_train->Chi2Test(bdt_plike_all_test, "UU");
    std::cout << "bdt_plike_all chi2 test result: " << chi2_result_bdt_plike << std::endl;
    
    TH1F* bdt_elike_all_train = bdt_elike_antimu_train->Clone("bdt_elike_all_train");
    bdt_elike_all_train->Add(bdt_elike_piplus_train);
    bdt_elike_all_train->Add(bdt_elike_proton_train);
    bdt_elike_all_train->Add(bdt_elike_positron_train);
    
    TH1F* bdt_elike_all_test = bdt_elike_antimu_test->Clone("bdt_elike_all_test");
    bdt_elike_all_test->Add(bdt_elike_piplus_test);
    bdt_elike_all_test->Add(bdt_elike_proton_test);
    bdt_elike_all_test->Add(bdt_elike_positron_test);
    
    Double_t ks_result_bdt_elike = bdt_elike_all_train->KolmogorovTest(bdt_elike_all_test, "X");
    std::cout << "bdt_elike_all KS test result: " << ks_result_bdt_elike << std::endl;
    Double_t chi2_result_bdt_elike = bdt_elike_all_train->Chi2Test(bdt_elike_all_test, "UU");
    std::cout << "bdt_elike_all chi2 test result: " << chi2_result_bdt_elike << std::endl;
}
