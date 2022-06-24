{
    TFile *file_existing_selection_kinlimited = new TFile("../existing_selection/output/existing_selection_twotrack.root");
    //file_existing_selection_kinlimited.ls();
    TGraph* exsel_kinlimited_eff = (TGraph*)file_existing_selection_kinlimited.Get("graph_eff_vs_recomom");
    TGraph* exsel_kinlimited_pur = (TGraph*)file_existing_selection_kinlimited.Get("graph_pur_vs_recomom");
    TGraph* exsel_kinlimited_effpur = (TGraph*)file_existing_selection_kinlimited.Get("graph_effpur_vs_recomom");
    TGraph* exsel_kinlimited_signif = (TGraph*)file_existing_selection_kinlimited.Get("graph_signif_vs_recomom");
    
    TFile *file_improved_selection_kinlimited = new TFile("../existing_selection_noposmult/output/improved_selection_twotrack.root");
    //file_improved_selection_kinlimited.ls();
    TGraph* impsel_kinlimited_eff = (TGraph*)file_improved_selection_kinlimited.Get("graph_eff_vs_recomom");
    TGraph* impsel_kinlimited_pur = (TGraph*)file_improved_selection_kinlimited.Get("graph_pur_vs_recomom");
    TGraph* impsel_kinlimited_effpur = (TGraph*)file_improved_selection_kinlimited.Get("graph_effpur_vs_recomom");
    TGraph* impsel_kinlimited_signif = (TGraph*)file_improved_selection_kinlimited.Get("graph_signif_vs_recomom");
    
    TFile *file_nomuonrej_selection_kinlimited = new TFile("../existing_selection_noposmult/output/nomuonrejection_twotrack.root");
    //file_nomuonrej_selection_kinlimited.ls();
    TGraph* nomuonrej_kinlimited_eff = (TGraph*)file_nomuonrej_selection_kinlimited.Get("graph_eff_vs_recomom");
    TGraph* nomuonrej_kinlimited_pur = (TGraph*)file_nomuonrej_selection_kinlimited.Get("graph_pur_vs_recomom");
    TGraph* nomuonrej_kinlimited_effpur = (TGraph*)file_nomuonrej_selection_kinlimited.Get("graph_effpur_vs_recomom");
    TGraph* nomuonrej_kinlimited_signif = (TGraph*)file_nomuonrej_selection_kinlimited.Get("graph_signif_vs_recomom");
    
    TFile *file_muonrej_selection_kinlimited = new TFile("../existing_selection_noposmult/output/muonrejection_twotrack.root");
    //file_muonrej_selection_kinlimited.ls();
    TGraph* muonrej_kinlimited_eff = (TGraph*)file_muonrej_selection_kinlimited.Get("graph_eff_vs_recomom");
    TGraph* muonrej_kinlimited_pur = (TGraph*)file_muonrej_selection_kinlimited.Get("graph_pur_vs_recomom");
    TGraph* muonrej_kinlimited_effpur = (TGraph*)file_muonrej_selection_kinlimited.Get("graph_effpur_vs_recomom");
    TGraph* muonrej_kinlimited_signif = (TGraph*)file_muonrej_selection_kinlimited.Get("graph_signif_vs_recomom");
  
    TGraph* optsel_kinlimited_eff = (TGraph*)file_muonrej_selection_kinlimited.Get("graph_eff_vs_recomom_optsel");
    TGraph* optsel_kinlimited_pur = (TGraph*)file_muonrej_selection_kinlimited.Get("graph_pur_vs_recomom_optsel");
    TGraph* optsel_kinlimited_effpur = (TGraph*)file_muonrej_selection_kinlimited.Get("graph_effpur_vs_recomom_optsel");
    TGraph* optsel_kinlimited_signif = (TGraph*)file_muonrej_selection_kinlimited.Get("graph_signif_vs_recomom_optsel");
    
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
    optsel_kinlimited_eff->SetTitle("BDT selection (optimised)");
    optsel_kinlimited_pur->SetTitle("BDT selection (optimised)");
    optsel_kinlimited_effpur->SetTitle("BDT selection (optimised)");
    optsel_kinlimited_signif->SetTitle("BDT selection (optimised)");
    
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
    muonrej_kinlimited_signif->SetLineStyle(kDotted);
    optsel_kinlimited_eff->SetLineStyle(kDotted);
    optsel_kinlimited_pur->SetLineStyle(kDotted);
    optsel_kinlimited_effpur->SetLineStyle(kDotted);
    optsel_kinlimited_signif->SetLineStyle(kDotted);*/
    
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
    optsel_kinlimited_eff->SetLineColor(kBlue);
    optsel_kinlimited_pur->SetLineColor(kBlue);
    optsel_kinlimited_effpur->SetLineColor(kBlue);
    optsel_kinlimited_signif->SetLineColor(kBlue);
    
    TCanvas* canvas_eff_kinlimited = new TCanvas("canvas_eff_kinlimited","canvas_eff_kinlimited",200,10,1000,600);
    
    exsel_kinlimited_eff->Draw("AL");
    //impsel_kinlimited_eff->Draw("L same");
    nomuonrej_kinlimited_eff->Draw("L same");
    //muonrej_kinlimited_eff->Draw("L same");
    optsel_kinlimited_eff->Draw("L same");
    
    TCanvas* canvas_pur_kinlimited = new TCanvas("canvas_pur_kinlimited","canvas_pur_kinlimited",200,10,1000,600);
    
    exsel_kinlimited_pur->Draw("AL");
    //impsel_kinlimited_pur->Draw("L same");
    nomuonrej_kinlimited_pur->Draw("L same");
    //muonrej_kinlimited_pur->Draw("L same");
    optsel_kinlimited_pur->Draw("L same");
    
    TCanvas* canvas_effpur_kinlimited = new TCanvas("canvas_effpur_kinlimited","canvas_effpur_kinlimited",200,10,1000,600);
    
    exsel_kinlimited_effpur->Draw("AL");
    //impsel_kinlimited_effpur->Draw("L same");
    nomuonrej_kinlimited_effpur->Draw("L same");
    //muonrej_kinlimited_effpur->Draw("L same");
    optsel_kinlimited_effpur->Draw("L same");
    
    TCanvas* canvas_signif_kinlimited = new TCanvas("canvas_signif_kinlimited","canvas_signif_kinlimited",200,10,1000,600);
    
    exsel_kinlimited_signif->Draw("AL");
    //impsel_kinlimited_signif->Draw("L same");
    nomuonrej_kinlimited_signif->Draw("L same");
    //muonrej_kinlimited_signif->Draw("L same");
    optsel_kinlimited_signif->Draw("L same");
    
    canvas_eff_kinlimited->BuildLegend();
    canvas_pur_kinlimited->BuildLegend();
    canvas_effpur_kinlimited->BuildLegend();
    canvas_signif_kinlimited->BuildLegend();
}
