{
    TFile *file_existing_selection_kinlimited = new TFile("../existing_selection/output/existing_selection_kinlimited.root");
    //file_existing_selection_kinlimited.ls();
    TGraph* exsel_kinlimited_eff = (TGraph*)file_existing_selection_kinlimited.Get("graph_eff_vs_recomom");
    TGraph* exsel_kinlimited_pur = (TGraph*)file_existing_selection_kinlimited.Get("graph_pur_vs_recomom");
    TGraph* exsel_kinlimited_effpur = (TGraph*)file_existing_selection_kinlimited.Get("graph_effpur_vs_recomom");
    TGraph* exsel_kinlimited_signif = (TGraph*)file_existing_selection_kinlimited.Get("graph_signif_vs_recomom");
    
    TFile *file_improved_selection_kinlimited = new TFile("../existing_selection_noposmult/output/improved_selection_kinlimited.root");
    //file_improved_selection_kinlimited.ls();
    TGraph* impsel_kinlimited_eff = (TGraph*)file_improved_selection_kinlimited.Get("graph_eff_vs_recomom");
    TGraph* impsel_kinlimited_pur = (TGraph*)file_improved_selection_kinlimited.Get("graph_pur_vs_recomom");
    TGraph* impsel_kinlimited_effpur = (TGraph*)file_improved_selection_kinlimited.Get("graph_effpur_vs_recomom");
    TGraph* impsel_kinlimited_signif = (TGraph*)file_improved_selection_kinlimited.Get("graph_signif_vs_recomom");
    
    TFile *file_nomuonrej_selection_kinlimited = new TFile("../existing_selection_noposmult/output/nomuonrejection_kinlimited.root");
    //file_nomuonrej_selection_kinlimited.ls();
    TGraph* nomuonrej_kinlimited_eff = (TGraph*)file_nomuonrej_selection_kinlimited.Get("graph_eff_vs_recomom");
    TGraph* nomuonrej_kinlimited_pur = (TGraph*)file_nomuonrej_selection_kinlimited.Get("graph_pur_vs_recomom");
    TGraph* nomuonrej_kinlimited_effpur = (TGraph*)file_nomuonrej_selection_kinlimited.Get("graph_effpur_vs_recomom");
    TGraph* nomuonrej_kinlimited_signif = (TGraph*)file_nomuonrej_selection_kinlimited.Get("graph_signif_vs_recomom");
    
    TFile *file_muonrej_selection_kinlimited = new TFile("../existing_selection_noposmult/output/muonrejection_kinlimited.root");
    //file_muonrej_selection_kinlimited.ls();
    TGraph* muonrej_kinlimited_eff = (TGraph*)file_muonrej_selection_kinlimited.Get("graph_eff_vs_recomom");
    TGraph* muonrej_kinlimited_pur = (TGraph*)file_muonrej_selection_kinlimited.Get("graph_pur_vs_recomom");
    TGraph* muonrej_kinlimited_effpur = (TGraph*)file_muonrej_selection_kinlimited.Get("graph_effpur_vs_recomom");
    TGraph* muonrej_kinlimited_signif = (TGraph*)file_muonrej_selection_kinlimited.Get("graph_signif_vs_recomom");
    
    exsel_kinlimited_eff->SetTitle("Existing selection");
    exsel_kinlimited_pur->SetTitle("Existing selection");
    exsel_kinlimited_effpur->SetTitle("Existing selection");
    exsel_kinlimited_signif->SetTitle("Existing selection");
    impsel_kinlimited_eff->SetTitle("Improved selection");
    impsel_kinlimited_pur->SetTitle("Improved selection");
    impsel_kinlimited_effpur->SetTitle("Improved selection");
    impsel_kinlimited_signif->SetTitle("Improved selection");
    nomuonrej_kinlimited_eff->SetTitle("BDT selection (no #mu^{-} rejection)");
    nomuonrej_kinlimited_pur->SetTitle("BDT selection (no #mu^{-} rejection)");
    nomuonrej_kinlimited_effpur->SetTitle("BDT selection (no #mu^{-} rejection)");
    nomuonrej_kinlimited_signif->SetTitle("BDT selection (no #mu^{-} rejection)");
    muonrej_kinlimited_eff->SetTitle("BDT selection (full)");
    muonrej_kinlimited_pur->SetTitle("BDT selection (full)");
    muonrej_kinlimited_effpur->SetTitle("BDT selection (full)");
    muonrej_kinlimited_signif->SetTitle("BDT selection (full)");
    
    exsel_kinlimited_eff->GetYaxis()->SetRangeUser(0.0, 1.0);
    exsel_kinlimited_pur->GetYaxis()->SetRangeUser(0.0, 1.0);
    exsel_kinlimited_effpur->GetYaxis()->SetRangeUser(0.0, 1.0);
    //exsel_kinlimited_signif->GetYaxis()->SetRangeUser(0.0, 1.0);
    exsel_kinlimited_eff->GetYaxis()->SetTitle("#bar{#nu}_{#mu} selection efficiency");
    exsel_kinlimited_pur->GetYaxis()->SetTitle("#bar{#nu}_{#mu} selection purity");
    exsel_kinlimited_effpur->GetYaxis()->SetTitle("#bar{#nu}_{#mu} selection efficiency*purity");
    exsel_kinlimited_signif->GetYaxis()->SetTitle("#bar{#nu}_{#mu} selection significance");
    exsel_kinlimited_eff->GetXaxis()->SetTitle("Antimuon candidate reconstructed momentum (MeV/c)");
    exsel_kinlimited_pur->GetXaxis()->SetTitle("Antimuon candidate reconstructed momentum (MeV/c)");
    exsel_kinlimited_effpur->GetXaxis()->SetTitle("Antimuon candidate reconstructed momentum (MeV/c)");
    exsel_kinlimited_signif->GetXaxis()->SetTitle("Antimuon candidate reconstructed momentum (MeV/c)");  
    
    /*impsel_kinlimited_eff->SetLineStyle(kDashed);
    impsel_kinlimited_pur->SetLineStyle(kDashed);
    impsel_kinlimited_effpur->SetLineStyle(kDashed);
    impsel_kinlimited_signif->SetLineStyle(kDashed);
    nomuonrej_kinlimited_eff->SetLineStyle(10);
    nomuonrej_kinlimited_pur->SetLineStyle(10);
    nomuonrej_kinlimited_effpur->SetLineStyle(10);
    nomuonrej_kinlimited_signif->SetLineStyle(10);
    muonrej_kinlimited_eff->SetLineStyle(kDotted);
    muonrej_kinlimited_pur->SetLineStyle(kDotted);
    muonrej_kinlimited_effpur->SetLineStyle(kDotted);
    muonrej_kinlimited_signif->SetLineStyle(kDotted);*/
    
    exsel_kinlimited_eff->SetLineColor(kBlack);
    exsel_kinlimited_pur->SetLineColor(kBlack);
    exsel_kinlimited_effpur->SetLineColor(kBlack);
    exsel_kinlimited_signif->SetLineColor(kBlack);
    impsel_kinlimited_eff->SetLineColor(kRed+1);
    impsel_kinlimited_pur->SetLineColor(kRed+1);
    impsel_kinlimited_effpur->SetLineColor(kRed+1);
    impsel_kinlimited_signif->SetLineColor(kRed+1);
    nomuonrej_kinlimited_eff->SetLineColor(kYellow+1);
    nomuonrej_kinlimited_pur->SetLineColor(kYellow+1);
    nomuonrej_kinlimited_effpur->SetLineColor(kYellow+1);
    nomuonrej_kinlimited_signif->SetLineColor(kYellow+1);
    muonrej_kinlimited_eff->SetLineColor(kGreen+1);
    muonrej_kinlimited_pur->SetLineColor(kGreen+1);
    muonrej_kinlimited_effpur->SetLineColor(kGreen+1);
    muonrej_kinlimited_signif->SetLineColor(kGreen+1);
    
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
    
    TCanvas* canvas_effpur_kinlimited = new TCanvas("canvas_effpur_kinlimited","canvas_effpur_kinlimited",200,10,1000,600);
    
    exsel_kinlimited_effpur->Draw("AL");
    impsel_kinlimited_effpur->Draw("L same");
    nomuonrej_kinlimited_effpur->Draw("L same");
    muonrej_kinlimited_effpur->Draw("L same");
    
    TCanvas* canvas_signif_kinlimited = new TCanvas("canvas_signif_kinlimited","canvas_signif_kinlimited",200,10,1000,600);
    
    exsel_kinlimited_signif->Draw("AL");
    impsel_kinlimited_signif->Draw("L same");
    nomuonrej_kinlimited_signif->Draw("L same");
    muonrej_kinlimited_signif->Draw("L same");
    
    canvas_eff_kinlimited->BuildLegend();
    canvas_pur_kinlimited->BuildLegend();
    canvas_effpur_kinlimited->BuildLegend();
    canvas_signif_kinlimited->BuildLegend();
    
    TFile *file_existing_selection_kinfull = new TFile("../existing_selection/output/existing_selection_kinfull.root");
    //file_existing_selection_kinfull.ls();
    TGraph* exsel_kinfull_eff = (TGraph*)file_existing_selection_kinfull.Get("graph_eff_vs_recomom");
    TGraph* exsel_kinfull_pur = (TGraph*)file_existing_selection_kinfull.Get("graph_pur_vs_recomom");
    TGraph* exsel_kinfull_effpur = (TGraph*)file_existing_selection_kinfull.Get("graph_effpur_vs_recomom");
    TGraph* exsel_kinfull_signif = (TGraph*)file_existing_selection_kinfull.Get("graph_signif_vs_recomom");
    
    TFile *file_improved_selection_kinfull = new TFile("../existing_selection_noposmult/output/improved_selection_kinfull.root");
    //file_improved_selection_kinfull.ls();
    TGraph* impsel_kinfull_eff = (TGraph*)file_improved_selection_kinfull.Get("graph_eff_vs_recomom");
    TGraph* impsel_kinfull_pur = (TGraph*)file_improved_selection_kinfull.Get("graph_pur_vs_recomom");
    TGraph* impsel_kinfull_effpur = (TGraph*)file_improved_selection_kinfull.Get("graph_effpur_vs_recomom");
    TGraph* impsel_kinfull_signif = (TGraph*)file_improved_selection_kinfull.Get("graph_signif_vs_recomom");
    
    TFile *file_nomuonrej_selection_kinfull = new TFile("../existing_selection_noposmult/output/nomuonrejection_kinfull.root");
    //file_nomuonrej_selection_kinfull.ls();
    TGraph* nomuonrej_kinfull_eff = (TGraph*)file_nomuonrej_selection_kinfull.Get("graph_eff_vs_recomom");
    TGraph* nomuonrej_kinfull_pur = (TGraph*)file_nomuonrej_selection_kinfull.Get("graph_pur_vs_recomom");
    TGraph* nomuonrej_kinfull_effpur = (TGraph*)file_nomuonrej_selection_kinfull.Get("graph_effpur_vs_recomom");
    TGraph* nomuonrej_kinfull_signif = (TGraph*)file_nomuonrej_selection_kinfull.Get("graph_signif_vs_recomom");
    
    TFile *file_muonrej_selection_kinfull = new TFile("../existing_selection_noposmult/output/muonrejection_kinfull.root");
    //file_muonrej_selection_kinfull.ls();
    TGraph* muonrej_kinfull_eff = (TGraph*)file_muonrej_selection_kinfull.Get("graph_eff_vs_recomom");
    TGraph* muonrej_kinfull_pur = (TGraph*)file_muonrej_selection_kinfull.Get("graph_pur_vs_recomom");
    TGraph* muonrej_kinfull_effpur = (TGraph*)file_muonrej_selection_kinfull.Get("graph_effpur_vs_recomom");
    TGraph* muonrej_kinfull_signif = (TGraph*)file_muonrej_selection_kinfull.Get("graph_signif_vs_recomom");
    
    exsel_kinfull_eff->SetTitle("Existing selection");
    exsel_kinfull_pur->SetTitle("Existing selection");
    exsel_kinfull_effpur->SetTitle("Existing selection");
    exsel_kinfull_signif->SetTitle("Existing selection");
    impsel_kinfull_eff->SetTitle("Improved selection");
    impsel_kinfull_pur->SetTitle("Improved selection");
    impsel_kinfull_effpur->SetTitle("Improved selection");
    impsel_kinfull_signif->SetTitle("Improved selection");
    nomuonrej_kinfull_eff->SetTitle("BDT selection (no #mu^{-} rejection)");
    nomuonrej_kinfull_pur->SetTitle("BDT selection (no #mu^{-} rejection)");
    nomuonrej_kinfull_effpur->SetTitle("BDT selection (no #mu^{-} rejection)");
    nomuonrej_kinfull_signif->SetTitle("BDT selection (no #mu^{-} rejection)");
    muonrej_kinfull_eff->SetTitle("BDT selection (full)");
    muonrej_kinfull_pur->SetTitle("BDT selection (full)");
    muonrej_kinfull_effpur->SetTitle("BDT selection (full)");
    muonrej_kinfull_signif->SetTitle("BDT selection (full)");
    
    exsel_kinfull_eff->GetYaxis()->SetRangeUser(0.0, 1.0);
    exsel_kinfull_pur->GetYaxis()->SetRangeUser(0.0, 1.0);
    exsel_kinfull_effpur->GetYaxis()->SetRangeUser(0.0, 1.0);
    //exsel_kinfull_signif->GetYaxis()->SetRangeUser(0.0, 1.0);
    exsel_kinfull_eff->GetYaxis()->SetTitle("#bar{#nu}_{#mu} selection efficiency");
    exsel_kinfull_pur->GetYaxis()->SetTitle("#bar{#nu}_{#mu} selection purity");
    exsel_kinfull_effpur->GetYaxis()->SetTitle("#bar{#nu}_{#mu} selection efficiency*purity");
    exsel_kinfull_signif->GetYaxis()->SetTitle("#bar{#nu}_{#mu} selection significance");
    exsel_kinfull_eff->GetXaxis()->SetTitle("Antimuon candidate reconstructed momentum (MeV/c)");
    exsel_kinfull_pur->GetXaxis()->SetTitle("Antimuon candidate reconstructed momentum (MeV/c)");
    exsel_kinfull_effpur->GetXaxis()->SetTitle("Antimuon candidate reconstructed momentum (MeV/c)");
    exsel_kinfull_signif->GetXaxis()->SetTitle("Antimuon candidate reconstructed momentum (MeV/c)");  
    
    impsel_kinfull_eff->SetLineStyle(kDashed);
    impsel_kinfull_pur->SetLineStyle(kDashed);
    impsel_kinfull_effpur->SetLineStyle(kDashed);
    impsel_kinfull_signif->SetLineStyle(kDashed);
    nomuonrej_kinfull_eff->SetLineStyle(10);
    nomuonrej_kinfull_pur->SetLineStyle(10);
    nomuonrej_kinfull_effpur->SetLineStyle(10);
    nomuonrej_kinfull_signif->SetLineStyle(10);
    muonrej_kinfull_eff->SetLineStyle(kDotted);
    muonrej_kinfull_pur->SetLineStyle(kDotted);
    muonrej_kinfull_effpur->SetLineStyle(kDotted);
    muonrej_kinfull_signif->SetLineStyle(kDotted);
    
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
    
    TCanvas* canvas_effpur_kinfull = new TCanvas("canvas_effpur_kinfull","canvas_effpur_kinfull",200,10,1000,600);
    
    exsel_kinfull_effpur->Draw("AL");
    impsel_kinfull_effpur->Draw("L same");
    nomuonrej_kinfull_effpur->Draw("L same");
    muonrej_kinfull_effpur->Draw("L same");
    
    TCanvas* canvas_signif_kinfull = new TCanvas("canvas_signif_kinfull","canvas_signif_kinfull",200,10,1000,600);
    
    exsel_kinfull_signif->Draw("AL");
    impsel_kinfull_signif->Draw("L same");
    nomuonrej_kinfull_signif->Draw("L same");
    muonrej_kinfull_signif->Draw("L same");
    
    canvas_eff_kinfull->BuildLegend();
    canvas_pur_kinfull->BuildLegend();
    canvas_effpur_kinfull->BuildLegend();
    canvas_signif_kinfull->BuildLegend();
}
