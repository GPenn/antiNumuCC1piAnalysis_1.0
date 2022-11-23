{
    TFile *file_MC = new TFile("../existing_selection/output/MC_for_data_comparison_exsel.root");
    THStack* recomom_exsel_stack = (THStack*)file_MC.Get("recomom_exsel_stack");
    
    TFile *file_realdata = new TFile("../real_data_exsel/output/data_for_MC_comparison.root");
    TH1F* recomom_exsel_all = (TH1F*)file_realdata.Get("recomom_exsel_all");
    
    TCanvas* canvas_comparison_recomom_exsel = new TCanvas("canvas_comparison_recomom_exsel","canvas_comparison_recomom_exsel",200,10,1000,600);
    
    recomom_exsel_stack->Draw("");
    recomom_exsel_stack->SetMaximum(21.0);
    recomom_exsel_stack->Draw("");
    recomom_exsel_all->Draw("same E1");
    canvas_comparison_recomom_exsel->BuildLegend();
}
