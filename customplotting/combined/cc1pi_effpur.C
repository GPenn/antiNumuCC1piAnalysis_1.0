{
    TFile *file_existing_selection_kinlimited = new TFile("../existing_selection/output/existing_selection_kinlimited.root");
    //file_existing_selection_kinlimited.ls();
    TGraph* exsel_kinlimited_eff = (TGraph*)file_existing_selection_kinlimited.Get("graph_eff_vs_recomom");
    TGraph* exsel_kinlimited_pur = (TGraph*)file_existing_selection_kinlimited.Get("graph_pur_vs_recomom");
    
    TFile *file_improved_selection_kinlimited = new TFile("../existing_selection_noposmult/output/improved_selection_kinlimited.root");
    //file_improved_selection_kinlimited.ls();
    TGraph* impsel_kinlimited_eff = (TGraph*)file_improved_selection_kinlimited.Get("graph_eff_vs_recomom");
    TGraph* impsel_kinlimited_pur = (TGraph*)file_improved_selection_kinlimited.Get("graph_pur_vs_recomom");
    
    TFile *file_nomuonrej_selection_kinlimited = new TFile("../existing_selection_noposmult/output/nomuonrejection_kinlimited.root");
    //file_nomuonrej_selection_kinlimited.ls();
    TGraph* nomuonrej_kinlimited_eff = (TGraph*)file_nomuonrej_selection_kinlimited.Get("graph_eff_vs_recomom");
    TGraph* nomuonrej_kinlimited_pur = (TGraph*)file_nomuonrej_selection_kinlimited.Get("graph_pur_vs_recomom");
    
    TFile *file_muonrej_selection_kinlimited = new TFile("../existing_selection_noposmult/output/muonrejection_kinlimited.root");
    //file_muonrej_selection_kinlimited.ls();
    TGraph* muonrej_kinlimited_eff = (TGraph*)file_muonrej_selection_kinlimited.Get("graph_eff_vs_recomom");
    TGraph* muonrej_kinlimited_pur = (TGraph*)file_muonrej_selection_kinlimited.Get("graph_pur_vs_recomom");
    
    exsel_kinlimited_eff->SetTitle("Existing selection");
    exsel_kinlimited_pur->SetTitle("Existing selection");
    impsel_kinlimited_eff->SetTitle("Improved selection");
    impsel_kinlimited_pur->SetTitle("Improved selection");
    nomuonrej_kinlimited_eff->SetTitle("BDT selection (no #mu^{-} rejection)");
    nomuonrej_kinlimited_pur->SetTitle("BDT selection (no #mu^{-} rejection)");
    muonrej_kinlimited_eff->SetTitle("BDT selection (full)");
    muonrej_kinlimited_pur->SetTitle("BDT selection (full)");
    
    exsel_kinlimited_eff->GetYaxis()->SetRangeUser(0.0, 1.0);
    exsel_kinlimited_pur->GetYaxis()->SetRangeUser(0.0, 1.0);
    exsel_kinlimited_eff->GetYaxis()->SetTitle("#bar{#nu}_{#mu} selection efficiency");
    exsel_kinlimited_pur->GetYaxis()->SetTitle("#bar{#nu}_{#mu} selection purity");
    exsel_kinlimited_eff->GetXaxis()->SetTitle("Antimuon candidate reconstructed momentum (MeV/c)");
    exsel_kinlimited_pur->GetXaxis()->SetTitle("Antimuon candidate reconstructed momentum (MeV/c)");                                        
    
    impsel_kinlimited_eff->SetLineStyle(kDashed);
    impsel_kinlimited_pur->SetLineStyle(kDashed);
    nomuonrej_kinlimited_eff->SetLineStyle(10);
    nomuonrej_kinlimited_pur->SetLineStyle(10);
    muonrej_kinlimited_eff->SetLineStyle(kDotted);
    muonrej_kinlimited_pur->SetLineStyle(kDotted);
    
    TCanvas* canvas_eff_kinlimited = new TCanvas("canvas_eff_kinlimited","canvas_eff_kinlimited",200,10,1000,600);
    
    exsel_kinlimited_eff->Draw("AL");
    impsel_kinlimited_eff->Draw("L same");
    nomuonrej_kinlimited_eff->Draw("L same");
    muonrej_kinlimited_eff->Draw("L same");
    
    TCanvas* canvas_pur_kinlimited = new TCanvas("canvas_pur_kinlimited","canvas_pur_kinlimited",200,10,1000,600);
    
    exsel_kinlimited_pur->Draw("AL");
    impsel_kinlimited_pur->Draw("L same");
    nomuonrej_kinlimited_pur->Draw("L same");
    muonrej_kinlimited_pur->Draw("L same");
    
    canvas_eff_kinlimited->BuildLegend();
    canvas_pur_kinlimited->BuildLegend();
    
    TFile *file_existing_selection_kinfull = new TFile("../existing_selection/output/existing_selection_kinfull.root");
    //file_existing_selection_kinfull.ls();
    TGraph* exsel_kinfull_eff = (TGraph*)file_existing_selection_kinfull.Get("graph_eff_vs_recomom");
    TGraph* exsel_kinfull_pur = (TGraph*)file_existing_selection_kinfull.Get("graph_pur_vs_recomom");
    
    TFile *file_improved_selection_kinfull = new TFile("../existing_selection_noposmult/output/improved_selection_kinfull.root");
    //file_improved_selection_kinfull.ls();
    TGraph* impsel_kinfull_eff = (TGraph*)file_improved_selection_kinfull.Get("graph_eff_vs_recomom");
    TGraph* impsel_kinfull_pur = (TGraph*)file_improved_selection_kinfull.Get("graph_pur_vs_recomom");
    
    TFile *file_nomuonrej_selection_kinfull = new TFile("../existing_selection_noposmult/output/nomuonrejection_kinfull.root");
    //file_nomuonrej_selection_kinfull.ls();
    TGraph* nomuonrej_kinfull_eff = (TGraph*)file_nomuonrej_selection_kinfull.Get("graph_eff_vs_recomom");
    TGraph* nomuonrej_kinfull_pur = (TGraph*)file_nomuonrej_selection_kinfull.Get("graph_pur_vs_recomom");
    
    TFile *file_muonrej_selection_kinfull = new TFile("../existing_selection_noposmult/output/muonrejection_kinfull.root");
    //file_muonrej_selection_kinfull.ls();
    TGraph* muonrej_kinfull_eff = (TGraph*)file_muonrej_selection_kinfull.Get("graph_eff_vs_recomom");
    TGraph* muonrej_kinfull_pur = (TGraph*)file_muonrej_selection_kinfull.Get("graph_pur_vs_recomom");
    
    exsel_kinfull_eff->SetTitle("Existing selection");
    exsel_kinfull_pur->SetTitle("Existing selection");
    impsel_kinfull_eff->SetTitle("Improved selection");
    impsel_kinfull_pur->SetTitle("Improved selection");
    nomuonrej_kinfull_eff->SetTitle("BDT selection (no #mu^{-} rejection)");
    nomuonrej_kinfull_pur->SetTitle("BDT selection (no #mu^{-} rejection)");
    muonrej_kinfull_eff->SetTitle("BDT selection (full)");
    muonrej_kinfull_pur->SetTitle("BDT selection (full)");
    
    exsel_kinfull_eff->GetYaxis()->SetRangeUser(0.0, 1.0);
    exsel_kinfull_pur->GetYaxis()->SetRangeUser(0.0, 1.0);
    exsel_kinfull_eff->GetYaxis()->SetTitle("#bar{#nu}_{#mu} selection efficiency");
    exsel_kinfull_pur->GetYaxis()->SetTitle("#bar{#nu}_{#mu} selection purity");
    exsel_kinfull_eff->GetXaxis()->SetTitle("Antimuon candidate reconstructed momentum (MeV/c)");
    exsel_kinfull_pur->GetXaxis()->SetTitle("Antimuon candidate reconstructed momentum (MeV/c)");                                        
    
    impsel_kinfull_eff->SetLineStyle(kDashed);
    impsel_kinfull_pur->SetLineStyle(kDashed);
    nomuonrej_kinfull_eff->SetLineStyle(10);
    nomuonrej_kinfull_pur->SetLineStyle(10);
    muonrej_kinfull_eff->SetLineStyle(kDotted);
    muonrej_kinfull_pur->SetLineStyle(kDotted);
    
    TCanvas* canvas_eff_kinfull = new TCanvas("canvas_eff_kinfull","canvas_eff_kinfull",200,10,1000,600);
    
    exsel_kinfull_eff->Draw("AL");
    impsel_kinfull_eff->Draw("L same");
    nomuonrej_kinfull_eff->Draw("L same");
    muonrej_kinfull_eff->Draw("L same");
    
    TCanvas* canvas_pur_kinfull = new TCanvas("canvas_pur_kinfull","canvas_pur_kinfull",200,10,1000,600);
    
    exsel_kinfull_pur->Draw("AL");
    impsel_kinfull_pur->Draw("L same");
    nomuonrej_kinfull_pur->Draw("L same");
    muonrej_kinfull_pur->Draw("L same");
    
    canvas_eff_kinfull->BuildLegend();
    canvas_pur_kinfull->BuildLegend();
}
