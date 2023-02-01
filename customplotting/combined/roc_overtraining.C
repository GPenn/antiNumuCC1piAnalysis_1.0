{
    TRandom *random = new TRandom();
    
    TFile *file_trainingsample = new TFile("../particle_gun/output/ks_trainingsample.root");
    TGraph* roc_purvseff_mulike_train  = (TGraph*)file_trainingsample.Get("roc_purvseff_mulike");
    TGraph* roc_purvseff_pilike_train  = (TGraph*)file_trainingsample.Get("roc_purvseff_pilike");
    TGraph* roc_purvseff_plike_train  = (TGraph*)file_trainingsample.Get("roc_purvseff_plike");
    TGraph* roc_purvseff_elike_train  = (TGraph*)file_trainingsample.Get("roc_purvseff_elike");

    TFile *file_testingsample = new TFile("../particle_gun/output/ks_testingsample.root");
    TGraph* roc_purvseff_mulike_test  = (TGraph*)file_testingsample.Get("roc_purvseff_mulike");
    TGraph* roc_purvseff_pilike_test  = (TGraph*)file_testingsample.Get("roc_purvseff_pilike");
    TGraph* roc_purvseff_plike_test  = (TGraph*)file_testingsample.Get("roc_purvseff_plike");
    TGraph* roc_purvseff_elike_test  = (TGraph*)file_testingsample.Get("roc_purvseff_elike");
    
    TCanvas* roc_comparison_all = new TCanvas("roc_comparison_all","roc_comparison_all",200,10,1000,600);
    
    roc_purvseff_mulike_train->SetLineStyle(kDashed);
    roc_purvseff_pilike_train->SetLineStyle(kDashed);
    roc_purvseff_plike_train->SetLineStyle(kDashed);
    roc_purvseff_elike_train->SetLineStyle(kDashed);
    
    roc_purvseff_mulike_train->SetTitle("BDT #mu-like output (training);Efficiency;Purity");
    
    //roc_purvseff_mulike_train->SetTitle("BDT #mu-like output (training)");
    roc_purvseff_pilike_train->SetTitle("BDT #pi-like output (training)");
    roc_purvseff_plike_train->SetTitle("BDT p-like output (training)");
    roc_purvseff_elike_train->SetTitle("BDT e-like output (training)");
    
    roc_purvseff_mulike_test->SetTitle("BDT #mu-like output (testing)");
    roc_purvseff_pilike_test->SetTitle("BDT #pi-like output (testing)");
    roc_purvseff_plike_test->SetTitle("BDT p-like output (testing)");
    roc_purvseff_elike_test->SetTitle("BDT e-like output (testing)");
    
    roc_purvseff_mulike_train->Draw();
    roc_purvseff_pilike_train->Draw("same");
    roc_purvseff_plike_train->Draw("same");
    roc_purvseff_elike_train->Draw("same");
    
    roc_purvseff_mulike_test->Draw("same");
    roc_purvseff_pilike_test->Draw("same");
    roc_purvseff_plike_test->Draw("same");
    roc_purvseff_elike_test->Draw("same");
    
    roc_purvseff_mulike_train->SetTitle("BDT #mu-like output (training)");
    
    roc_comparison_all->BuildLegend();
}
