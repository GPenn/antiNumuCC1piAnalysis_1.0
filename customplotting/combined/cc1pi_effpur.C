{
    TCanvas* canvas_eff_kinlimited = new TCanvas("canvas_eff_kinlimited","canvas_eff_kinlimited",200,10,1000,600);
    
    TFile *file_existing_selection_kinlimited = new TFile("../existing_selection/output/existing_selection_kinlimited.root");
    //file_existing_selection_kinlimited.ls();
    
    TGraph* exsel_kinlimited_eff = (TGraph*)file_existing_selection_kinlimited.Get("graph_eff_vs_recomom");
    TGraph* exsel_kinlimited_pur = (TGraph*)file_existing_selection_kinlimited.Get("graph_pur_vs_recomom");
    
    
    
    exsel_kinlimited_eff->SetTitle("Existing selection");
    exsel_kinlimited_pur->SetTitle("Existing selection");
    
    exsel_kinlimited_eff->Draw("AL");
    //training_piplus->Draw("L same");
    //training_proton->Draw("L same");
    //training_positron->Draw("L same");
    
    TCanvas* canvas_pur_kinlimited = new TCanvas("canvas_pur_kinlimited","canvas_pur_kinlimited",200,10,1000,600);
    
    exsel_kinlimited_pur->Draw("AL");
    
    canvas_eff_kinlimited->BuildLegend();
    canvas_pur_kinlimited->BuildLegend();
}
