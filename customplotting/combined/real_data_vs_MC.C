{
    TFile *file_MC = new TFile("../existing_selection_noposmult/output/MC_for_data_comparison.root");
    //file_existing_selection_kinlimited.ls();
    THStack* bdt_output_selmu_mulike_stack = (THStack*)file_MC.Get("bdt_output_selmu_mulike_stack");
    THStack* bdt_output_selmu_pilike_stack = (THStack*)file_MC.Get("bdt_output_selmu_pilike_stack");
    THStack* bdt_output_selmu_plike_stack = (THStack*)file_MC.Get("bdt_output_selmu_plike_stack");
    THStack* bdt_output_selmu_elike_stack = (THStack*)file_MC.Get("bdt_output_selmu_elike_stack");
    
    TH1F* recomom_optsel_cc0pi = (TH1F*)file_MC.Get("recomom_optsel_cc0pi");
    TH1F* recomom_optsel_cc1pi = (TH1F*)file_MC.Get("recomom_optsel_cc1pi");
    TH1F* recomom_optsel_ccother = (TH1F*)file_MC.Get("recomom_optsel_ccother");
    TH1F* recomom_optsel_bkg = (TH1F*)file_MC.Get("recomom_optsel_bkg");
    TH1F* recomom_optsel_oofv = (TH1F*)file_MC.Get("recomom_optsel_oofv");
    TH1F* recomom_optsel_numubarccbkg = (TH1F*)file_MC.Get("recomom_optsel_numubarccbkg");
    TH1F* recomom_optsel_numucc = (TH1F*)file_MC.Get("recomom_optsel_bkg");
    TH1F* recomom_optsel_otherbkg = (TH1F*)file_MC.Get("recomom_optsel_otherbkg");
    
    THStack* recomom_optsel_stack = (THStack*)file_MC.Get("recomom_optsel_stack");
    THStack* recomom_optsel_stack_altbkg = (THStack*)file_MC.Get("recomom_optsel_stack_altbkg");
    THStack* recomom_exsel_stack = (THStack*)file_MC.Get("recomom_exsel_stack");
    
    TH1F* recopimom_optsel_cc0pi = (TH1F*)file_MC.Get("recopimom_optsel_cc0pi");
    TH1F* recopimom_optsel_cc1pi = (TH1F*)file_MC.Get("recopimom_optsel_cc1pi");
    TH1F* recopimom_optsel_ccother = (TH1F*)file_MC.Get("recopimom_optsel_ccother");
    TH1F* recopimom_optsel_bkg = (TH1F*)file_MC.Get("recopimom_optsel_bkg");
    TH1F* recopimom_optsel_oofv = (TH1F*)file_MC.Get("recopimom_optsel_oofv");
    TH1F* recopimom_optsel_numubarccbkg = (TH1F*)file_MC.Get("recopimom_optsel_numubarccbkg");
    TH1F* recopimom_optsel_numucc = (TH1F*)file_MC.Get("recopimom_optsel_bkg");
    TH1F* recopimom_optsel_otherbkg = (TH1F*)file_MC.Get("recopimom_optsel_otherbkg");
    
    THStack* recopimom_optsel_stack = (THStack*)file_MC.Get("recopimom_optsel_stack");
    THStack* recopimom_optsel_stack_altbkg = (THStack*)file_MC.Get("recopimom_optsel_stack_altbkg");
    
    TFile *file_realdata = new TFile("../real_data/output/data_for_MC_comparison.root");
    //file_improved_selection_kinlimited.ls();
    TH1F* bdt_output_selmu_mulike = (TH1F*)file_realdata.Get("bdt_output_selmu_mulike");
    TH1F* bdt_output_selmu_pilike = (TH1F*)file_realdata.Get("bdt_output_selmu_pilike");
    TH1F* bdt_output_selmu_plike = (TH1F*)file_realdata.Get("bdt_output_selmu_plike");
    TH1F* bdt_output_selmu_elike = (TH1F*)file_realdata.Get("bdt_output_selmu_elike");
    
    TH1F* recomom_optsel_all = (TH1F*)file_realdata.Get("recomom_optsel_all");
    TH1F* recomom_exsel_all = (TH1F*)file_realdata.Get("recomom_exsel_all");
    TH1F* recopimom_optsel_all = (TH1F*)file_realdata.Get("recopimom_optsel_all");
    
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
    //canvas_comparison_recomom_optsel->BuildLegend();
    
    auto legend = new TLegend(0.1,0.7,0.48,0.9);
    legend->AddEntry(recomom_optsel_all,"T2K data (Run 5+6+7+9)","lep");
    legend->AddEntry(recomom_optsel_cc1pi,"NEUT MC: #bar{#nu}_{#mu} CC1pi (signal)","f");
    legend->AddEntry(recomom_optsel_cc0pi,"NEUT MC: #bar{#nu}_{#mu} CC0pi","f");
    legend->AddEntry(recomom_optsel_ccother,"NEUT MC: #bar{#nu}_{#mu} CC-other","f");
    legend->AddEntry(recomom_optsel_bkg,"NEUT MC: non-#bar{#nu}_{#mu}-CC backgrounds","f");
    legend->AddEntry(recomom_optsel_oofv,"NEUT MC: OOFV","f");
    legend->Draw();
    
    TCanvas* canvas_comparison_recomom_optsel_altbkg = new TCanvas("canvas_comparison_recomom_optsel_altbkg","canvas_comparison_recomom_optsel_altbkg",200,10,1000,600);
    
    recomom_optsel_stack_altbkg->Draw("");
    recomom_optsel_stack_altbkg->SetMaximum(53.0);
    recomom_optsel_stack_altbkg->Draw("");
    recomom_optsel_all->Draw("same E1");
    //canvas_comparison_recomom_optsel->BuildLegend();
    
    auto legend_altbkg = new TLegend(0.1,0.7,0.48,0.9);
    legend_altbkg->AddEntry(recomom_optsel_all,"T2K data (Run 5+6+7+9)","lep");
    legend_altbkg->AddEntry(recomom_optsel_cc1pi,"NEUT MC: #bar{#nu}_{#mu} CC1pi (signal)","f");
    legend_altbkg->AddEntry(recomom_optsel_numubarccbkg,"NEUT MC: #bar{#nu}_{#mu} CC backgrounds","f");
    legend_altbkg->AddEntry(recomom_optsel_numucc,"NEUT MC: #nu_{#mu} CC backgrounds","f");
    legend_altbkg->AddEntry(recomom_optsel_otherbkg,"NEUT MC: other backgrounds","f");
    legend_altbkg->AddEntry(recomom_optsel_oofv,"NEUT MC: OOFV","f");
    legend_altbkg->Draw();
    
    /*TCanvas* canvas_comparison_recomom_exsel = new TCanvas("canvas_comparison_recomom_exsel","canvas_comparison_recomom_exsel",200,10,1000,600);
    
    recomom_exsel_stack->Draw("");
    recomom_exsel_stack->SetMaximum(21.0);
    recomom_exsel_stack->Draw("");
    recomom_exsel_all->Draw("same E1");
    canvas_comparison_recomom_exsel->BuildLegend();*/
    
    TCanvas* canvas_comparison_recopimom_optsel_altbkg = new TCanvas("canvas_comparison_recopimom_optsel_altbkg","canvas_comparison_recopimom_optsel_altbkg",200,10,1000,600);
    
    recopimom_optsel_stack_altbkg->Draw("");
    recopimom_optsel_stack_altbkg->SetMaximum(95.0);
    recopimom_optsel_stack_altbkg->Draw("");
    recopimom_optsel_all->Draw("same E1");
    //canvas_comparison_recopimom_optsel->BuildLegend();
    legend_altbkg->Draw();
}
