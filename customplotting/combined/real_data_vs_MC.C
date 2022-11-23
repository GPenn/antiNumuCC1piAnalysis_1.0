{
    TFile *file_MC = new TFile("../existing_selection_noposmult/output/MC_for_data_comparison.root");
    //file_existing_selection_kinlimited.ls();
    THStack* bdt_output_selmu_mulike_stack = (THStack*)file_MC.Get("bdt_output_selmu_mulike_stack");
    THStack* bdt_output_selmu_pilike_stack = (THStack*)file_MC.Get("bdt_output_selmu_pilike_stack");
    THStack* bdt_output_selmu_plike_stack = (THStack*)file_MC.Get("bdt_output_selmu_plike_stack");
    THStack* bdt_output_selmu_elike_stack = (THStack*)file_MC.Get("bdt_output_selmu_elike_stack");
    
    THStack* recomom_optsel_stack = (THStack*)file_MC.Get("recomom_optsel_stack");
    THStack* recomom_exsel_stack = (THStack*)file_MC.Get("recomom_exsel_stack");
    
    TFile *file_realdata = new TFile("../real_data/output/data_for_MC_comparison.root");
    //file_improved_selection_kinlimited.ls();
    TH1F* bdt_output_selmu_mulike = (TH1F*)file_realdata.Get("bdt_output_selmu_mulike");
    TH1F* bdt_output_selmu_pilike = (TH1F*)file_realdata.Get("bdt_output_selmu_pilike");
    TH1F* bdt_output_selmu_plike = (TH1F*)file_realdata.Get("bdt_output_selmu_plike");
    TH1F* bdt_output_selmu_elike = (TH1F*)file_realdata.Get("bdt_output_selmu_elike");
    
    TH1F* recomom_optsel_all = (TH1F*)file_realdata.Get("recomom_optsel_all");
    TH1F* recomom_exsel_all = (TH1F*)file_realdata.Get("recomom_exsel_all");
    
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
    
    recomom_optsel_stack->Draw("");
    recomom_optsel_stack->SetMaximum(53.0);
    recomom_optsel_stack->Draw("");
    recomom_optsel_all->Draw("same E1");
    canvas_comparison_recomom_optsel->BuildLegend();
    
    TCanvas* canvas_comparison_recomom_exsel = new TCanvas("canvas_comparison_recomom_exsel","canvas_comparison_recomom_exsel",200,10,1000,600);
    
    recomom_exsel_stack->Draw("");
    recomom_exsel_stack->SetMaximum(21.0);
    recomom_exsel_stack->Draw("");
    recomom_exsel_all->Draw("same E1");
    canvas_comparison_recomom_exsel->BuildLegend();
}
