{
    TFile *file_MC = new TFile("../existing_selection_noposmult/output/MC_for_data_comparison.root");
    //file_existing_selection_kinlimited.ls();
    THStack* bdt_output_selmu_mulike_stack = (THStack*)file_MC.Get("bdt_output_selmu_mulike_stack");
    THStack* bdt_output_selmu_pilike_stack = (THStack*)file_MC.Get("bdt_output_selmu_pilike_stack");
    THStack* bdt_output_selmu_plike_stack = (THStack*)file_MC.Get("bdt_output_selmu_plike_stack");
    THStack* bdt_output_selmu_elike_stack = (THStack*)file_MC.Get("bdt_output_selmu_elike_stack");
    
    THStack* recomom_optsel_stack = (THStack*)file_MC.Get("recomom_optsel_stack");
    
    TFile *file_realdata = new TFile("../real_data/output/data_for_MC_comparison.root");
    //file_improved_selection_kinlimited.ls();
    TH1F* bdt_output_selmu_mulike = (TH1F*)file_realdata.Get("bdt_output_selmu_mulike");
    TH1F* bdt_output_selmu_pilike = (TH1F*)file_realdata.Get("bdt_output_selmu_pilike");
    TH1F* bdt_output_selmu_plike = (TH1F*)file_realdata.Get("bdt_output_selmu_plike");
    TH1F* bdt_output_selmu_elike = (TH1F*)file_realdata.Get("bdt_output_selmu_elike");
    
    TH1F* recomom_optsel_all = (TH1F*)file_realdata.Get("recomom_optsel_all");
    
    
    /*exsel_kinlimited_eff->SetTitle("Existing selection");
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
    optsel_kinlimited_signif->SetTitle("BDT selection (optimised)");*/
    
    /*exsel_kinlimited_eff->GetYaxis()->SetRangeUser(0.0, 1.0);
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
    exsel_kinlimited_signif->GetXaxis()->SetTitle("Antimuon candidate reconstructed momentum (MeV/c)");  */
    
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
    
    TCanvas* canvas_comparison_mulike = new TCanvas("canvas_comparison_mulike","canvas_comparison_mulike",200,10,1000,600);
    
    bdt_output_selmu_mulike_stack->Draw();
    bdt_output_selmu_mulike->Draw("same E1");
    canvas_comparison_mulike->BuildLegend();
    
    TCanvas* canvas_comparison_pilike = new TCanvas("canvas_comparison_pilike","canvas_comparison_pilike",200,10,1000,600);
    
    bdt_output_selmu_pilike_stack->Draw();
    bdt_output_selmu_pilike->Draw("same E1");
    canvas_comparison_pilike->BuildLegend();
    
    TCanvas* canvas_comparison_plike = new TCanvas("canvas_comparison_plike","canvas_comparison_plike",200,10,1000,600);
    
    bdt_output_selmu_plike_stack->Draw();
    bdt_output_selmu_plike->Draw("same E1");
    canvas_comparison_plike->BuildLegend();
    
    TCanvas* canvas_comparison_elike = new TCanvas("canvas_comparison_elike","canvas_comparison_elike",200,10,1000,600);
    
    bdt_output_selmu_elike_stack->Draw();
    bdt_output_selmu_elike->Draw("same E1");
    canvas_comparison_elike->BuildLegend();
    
    TCanvas* canvas_comparison_recomom_optsel = new TCanvas("canvas_comparison_recomom_optsel","canvas_comparison_recomom_optsel",200,10,1000,600);
    
    recomom_optsel_stack->Draw();
    recomom_optsel_all->Draw("same E1");
    canvas_comparison_recomom_optsel->BuildLegend();
}
