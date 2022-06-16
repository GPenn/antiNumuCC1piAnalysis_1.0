{
    TFile *file_existing_selection_kinlimited = new TFile("../existing_selection/output/existing_selection_kinlimited.root");
    //file_existing_selection_kinlimited.ls();
    TGraph* exsel_kinlimited_selmu_antimu = (TGraph*)file_existing_selection_kinlimited.Get("graph_selmu_antimu_purity");
    TGraph* exsel_kinlimited_selmu_piplus = (TGraph*)file_existing_selection_kinlimited.Get("graph_selmu_piplus_purity");
    TGraph* exsel_kinlimited_selmu_proton = (TGraph*)file_existing_selection_kinlimited.Get("graph_selmu_proton_purity");
    
    TFile *file_improved_selection_kinlimited = new TFile("../existing_selection_noposmult/output/improved_selection_kinlimited.root");
    //file_improved_selection_kinlimited.ls();
    TGraph* impsel_kinlimited_selmu_antimu = (TGraph*)file_improved_selection_kinlimited.Get("graph_selmu_antimu_purity");
    TGraph* impsel_kinlimited_selmu_piplus = (TGraph*)file_improved_selection_kinlimited.Get("graph_selmu_piplus_purity");
    TGraph* impsel_kinlimited_selmu_proton = (TGraph*)file_improved_selection_kinlimited.Get("graph_selmu_proton_purity");
    
    TFile *file_nomuonrej_selection_kinlimited = new TFile("../existing_selection_noposmult/output/nomuonrejection_kinlimited.root");
    //file_nomuonrej_selection_kinlimited.ls();
    TGraph* nomuonrej_kinlimited_selmu_antimu = (TGraph*)file_nomuonrej_selection_kinlimited.Get("graph_selmu_antimu_purity");
    TGraph* nomuonrej_kinlimited_selmu_piplus = (TGraph*)file_nomuonrej_selection_kinlimited.Get("graph_selmu_piplus_purity");
    TGraph* nomuonrej_kinlimited_selmu_proton = (TGraph*)file_nomuonrej_selection_kinlimited.Get("graph_selmu_proton_purity");
    
    TFile *file_muonrej_selection_kinlimited = new TFile("../existing_selection_noposmult/output/muonrejection_kinlimited.root");
    //file_muonrej_selection_kinlimited.ls();
    TGraph* muonrej_kinlimited_selmu_antimu = (TGraph*)file_muonrej_selection_kinlimited.Get("graph_selmu_antimu_purity");
    TGraph* muonrej_kinlimited_selmu_piplus = (TGraph*)file_muonrej_selection_kinlimited.Get("graph_selmu_piplus_purity");
    TGraph* muonrej_kinlimited_selmu_proton = (TGraph*)file_muonrej_selection_kinlimited.Get("graph_selmu_proton_purity");
    
    exsel_kinlimited_selmu_antimu->SetTitle("Existing selection");
    exsel_kinlimited_selmu_piplus->SetTitle("Existing selection");
    exsel_kinlimited_selmu_proton->SetTitle("Existing selection");
    impsel_kinlimited_selmu_antimu->SetTitle("Improved selection");
    impsel_kinlimited_selmu_piplus->SetTitle("Improved selection");
    impsel_kinlimited_selmu_proton->SetTitle("Improved selection");
    nomuonrej_kinlimited_selmu_antimu->SetTitle("BDT selection (no #mu^{-} rejection)");
    nomuonrej_kinlimited_selmu_piplus->SetTitle("BDT selection (no #mu^{-} rejection)");
    nomuonrej_kinlimited_selmu_proton->SetTitle("BDT selection (no #mu^{-} rejection)");
    muonrej_kinlimited_selmu_antimu->SetTitle("BDT selection (full)");
    muonrej_kinlimited_selmu_piplus->SetTitle("BDT selection (full)");
    muonrej_kinlimited_selmu_proton->SetTitle("BDT selection (full)");
    
    exsel_kinlimited_selmu_antimu->GetYaxis()->SetRangeUser(0.0, 1.0);
    exsel_kinlimited_selmu_piplus->GetYaxis()->SetRangeUser(0.0, 1.0);
    exsel_kinlimited_selmu_proton->GetYaxis()->SetRangeUser(0.0, 1.0);
    exsel_kinlimited_selmu_antimu->GetYaxis()->SetTitle("#mu^{+} candidate track purity");
    exsel_kinlimited_selmu_piplus->GetYaxis()->SetTitle("#mu^{+} candidate track purity");
    exsel_kinlimited_selmu_proton->GetYaxis()->SetTitle("#mu^{+} candidate track purity");
    exsel_kinlimited_selmu_antimu->GetXaxis()->SetTitle("Reconstructed momentum (MeV/c)");
    exsel_kinlimited_selmu_piplus->GetXaxis()->SetTitle("Reconstructed momentum (MeV/c)");
    exsel_kinlimited_selmu_proton->GetXaxis()->SetTitle("Reconstructed momentum (MeV/c)");
    
    impsel_kinlimited_selmu_antimu->SetLineStyle(kDashed);
    impsel_kinlimited_selmu_piplus->SetLineStyle(kDashed);
    impsel_kinlimited_selmu_proton->SetLineStyle(kDashed);
    nomuonrej_kinlimited_selmu_antimu->SetLineStyle(10);
    nomuonrej_kinlimited_selmu_piplus->SetLineStyle(10);
    nomuonrej_kinlimited_selmu_proton->SetLineStyle(10);
    muonrej_kinlimited_selmu_antimu->SetLineStyle(kDotted);
    muonrej_kinlimited_selmu_piplus->SetLineStyle(kDotted);
    muonrej_kinlimited_selmu_proton->SetLineStyle(kDotted);
    
    TCanvas* canvas_antimu_kinlimited = new TCanvas("canvas_antimu_kinlimited","canvas_antimu_kinlimited",200,10,1000,600);
    
    exsel_kinlimited_selmu_antimu->Draw("AL");
    impsel_kinlimited_selmu_antimu->Draw("L same");
    nomuonrej_kinlimited_selmu_antimu->Draw("L same");
    muonrej_kinlimited_selmu_antimu->Draw("L same");
    
    TCanvas* canvas_piplus_kinlimited = new TCanvas("canvas_piplus_kinlimited","canvas_piplus_kinlimited",200,10,1000,600);
    
    exsel_kinlimited_selmu_piplus->Draw("AL");
    impsel_kinlimited_selmu_piplus->Draw("L same");
    nomuonrej_kinlimited_selmu_piplus->Draw("L same");
    muonrej_kinlimited_selmu_piplus->Draw("L same");
    
    TCanvas* canvas_proton_kinlimited = new TCanvas("canvas_proton_kinlimited","canvas_proton_kinlimited",200,10,1000,600);
    
    exsel_kinlimited_selmu_proton->Draw("AL");
    impsel_kinlimited_selmu_proton->Draw("L same");
    nomuonrej_kinlimited_selmu_proton->Draw("L same");
    muonrej_kinlimited_selmu_proton->Draw("L same");
    
    canvas_antimu_kinlimited->BuildLegend();
    canvas_piplus_kinlimited->BuildLegend();
    canvas_proton_kinlimited->BuildLegend();
}
