{
    TFile *file_MC = new TFile("../existing_selection/output/MC_for_data_comparison_exsel.root");
    THStack* recomom_exsel_stack = (THStack*)file_MC.Get("recomom_exsel_stack");
    TH1F* recomom_exsel_cc0pi = (THStack*)file_MC.Get("recomom_exsel_cc0pi");
    TH1F* recomom_exsel_cc1pi = (THStack*)file_MC.Get("recomom_exsel_cc1pi");
    TH1F* recomom_exsel_ccother = (THStack*)file_MC.Get("recomom_exsel_ccother");
    TH1F* recomom_exsel_bkg = (THStack*)file_MC.Get("recomom_exsel_bkg");
    TH1F* recomom_exsel_oofv = (THStack*)file_MC.Get("recomom_exsel_oofv");
    
    TFile *file_realdata = new TFile("../real_data_exsel/output/data_for_MC_comparison.root");
    TH1F* recomom_exsel_all = (TH1F*)file_realdata.Get("recomom_exsel_all");
    
    TCanvas* canvas_comparison_recomom_exsel = new TCanvas("canvas_comparison_recomom_exsel","canvas_comparison_recomom_exsel",200,10,1000,600);
    
    recomom_exsel_stack->Draw("");
    recomom_exsel_stack->SetMaximum(50.0);
    recomom_exsel_stack->Draw("");
    recomom_exsel_all->Draw("same E1");
    //canvas_comparison_recomom_exsel->BuildLegend();
    
    auto legend = new TLegend(0.1,0.7,0.48,0.9);
    //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    legend->AddEntry(recomom_exsel_cc1pi,"Test","f");
    legend->Draw();
}
