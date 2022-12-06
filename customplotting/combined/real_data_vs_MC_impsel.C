{
    TFile *file_MC = new TFile("../existing_selection_noposmult/output/MC_for_data_comparison_impsel.root");
    THStack* recomom_impsel_stack = (THStack*)file_MC.Get("recomom_impsel_stack");
    THStack* recomom_impsel_stack_altbkg = (THStack*)file_MC.Get("recomom_impsel_stack_altbkg");
    TH1F* recomom_impsel_cc0pi = (TH1F*)file_MC.Get("recomom_impsel_cc0pi");
    TH1F* recomom_impsel_cc1pi = (TH1F*)file_MC.Get("recomom_impsel_cc1pi");
    TH1F* recomom_impsel_ccother = (TH1F*)file_MC.Get("recomom_impsel_ccother");
    TH1F* recomom_impsel_bkg = (TH1F*)file_MC.Get("recomom_impsel_bkg");
    TH1F* recomom_impsel_oofv = (TH1F*)file_MC.Get("recomom_impsel_oofv");
    TH1F* recomom_impsel_numubarccbkg = (TH1F*)file_MC.Get("recomom_impsel_numubarccbkg");
    TH1F* recomom_impsel_numucc = (TH1F*)file_MC.Get("recomom_impsel_bkg");
    TH1F* recomom_impsel_otherbkg = (TH1F*)file_MC.Get("recomom_impsel_otherbkg");
    
    THStack* recopimom_impsel_stack = (THStack*)file_MC.Get("recopimom_impsel_stack");
    THStack* recopimom_impsel_stack_altbkg = (THStack*)file_MC.Get("recopimom_impsel_stack_altbkg");
    TH1F* recopimom_impsel_cc0pi = (TH1F*)file_MC.Get("recopimom_impsel_cc0pi");
    TH1F* recopimom_impsel_cc1pi = (TH1F*)file_MC.Get("recopimom_impsel_cc1pi");
    TH1F* recopimom_impsel_ccother = (TH1F*)file_MC.Get("recopimom_impsel_ccother");
    TH1F* recopimom_impsel_bkg = (TH1F*)file_MC.Get("recopimom_impsel_bkg");
    TH1F* recopimom_impsel_oofv = (TH1F*)file_MC.Get("recopimom_impsel_oofv");
    TH1F* recopimom_impsel_numubarccbkg = (TH1F*)file_MC.Get("recopimom_impsel_numubarccbkg");
    TH1F* recopimom_impsel_numucc = (TH1F*)file_MC.Get("recopimom_impsel_bkg");
    TH1F* recopimom_impsel_otherbkg = (TH1F*)file_MC.Get("recopimom_impsel_otherbkg");
    
    TFile *file_realdata = new TFile("../real_data/output/data_for_MC_comparison_impsel.root");
    TH1F* recomom_impsel_all = (TH1F*)file_realdata.Get("recomom_impsel_all");
    TH1F* recopimom_impsel_all = (TH1F*)file_realdata.Get("recopimom_impsel_all");
    
    TCanvas* canvas_comparison_recomom_impsel = new TCanvas("canvas_comparison_recomom_impsel","canvas_comparison_recomom_impsel",200,10,1000,600);
    
    recomom_impsel_stack->Draw("");
    recomom_impsel_stack->SetMaximum(53.0);
    recomom_impsel_stack->Draw("");
    recomom_impsel_all->Draw("same E1");
    //canvas_comparison_recomom_impsel->BuildLegend();
    
    auto legend = new TLegend(0.1,0.7,0.48,0.9);
    legend->AddEntry(recomom_impsel_all,"T2K data (Run 5+6+7+9)","lep");
    legend->AddEntry(recomom_impsel_cc1pi,"NEUT MC: #bar{#nu}_{#mu} CC1pi (signal)","f");
    legend->AddEntry(recomom_impsel_cc0pi,"NEUT MC: #bar{#nu}_{#mu} CC0pi","f");
    legend->AddEntry(recomom_impsel_ccother,"NEUT MC: #bar{#nu}_{#mu} CC-other","f");
    legend->AddEntry(recomom_impsel_bkg,"NEUT MC: non-#bar{#nu}_{#mu}-CC backgrounds","f");
    legend->AddEntry(recomom_impsel_oofv,"NEUT MC: OOFV backgrounds","f");
    legend->Draw();
    
    TCanvas* canvas_comparison_recomom_impsel_altbkg = new TCanvas("canvas_comparison_recomom_impsel_altbkg","canvas_comparison_recomom_impsel_altbkg",200,10,1000,600);
    
    recomom_impsel_stack_altbkg->Draw("");
    recomom_impsel_stack_altbkg->SetMaximum(53.0);
    recomom_impsel_stack_altbkg->Draw("");
    recomom_impsel_all->Draw("same E1");
    //canvas_comparison_recomom_impsel->BuildLegend();
    
    auto legend_altbkg = new TLegend(0.1,0.7,0.48,0.9);
    legend_altbkg->AddEntry(recomom_impsel_all,"T2K data (Run 5+6+7+9)","lep");
    legend_altbkg->AddEntry(recomom_impsel_cc1pi,"NEUT MC: #bar{#nu}_{#mu} CC1pi (signal)","f");
    legend_altbkg->AddEntry(recomom_impsel_numubarccbkg,"NEUT MC: #bar{#nu}_{#mu} CC backgrounds","f");
    legend_altbkg->AddEntry(recomom_impsel_numucc,"NEUT MC: #nu_{#mu} CC backgrounds","f");
    legend_altbkg->AddEntry(recomom_impsel_otherbkg,"NEUT MC: other backgrounds","f");
    legend_altbkg->AddEntry(recomom_impsel_oofv,"NEUT MC: OOFV","f");
    legend_altbkg->Draw();
    
    TCanvas* canvas_comparison_recopimom_impsel_altbkg = new TCanvas("canvas_comparison_recopimom_impsel_altbkg","canvas_comparison_recopimom_impsel_altbkg",200,10,1000,600);
    
    recopimom_impsel_stack_altbkg->Draw("");
    recopimom_impsel_stack_altbkg->SetMaximum(95.0);
    recopimom_impsel_stack_altbkg->Draw("");
    recopimom_impsel_all->Draw("same E1");
    //canvas_comparison_recopimom_impsel->BuildLegend();
    
    auto legend_altbkg = new TLegend(0.1,0.7,0.48,0.9);
    legend_altbkg->AddEntry(recopimom_impsel_all,"T2K data (Run 5+6+7+9)","lep");
    legend_altbkg->AddEntry(recopimom_impsel_cc1pi,"NEUT MC: #bar{#nu}_{#mu} CC1pi (signal)","f");
    legend_altbkg->AddEntry(recopimom_impsel_numubarccbkg,"NEUT MC: #bar{#nu}_{#mu} CC backgrounds","f");
    legend_altbkg->AddEntry(recopimom_impsel_numucc,"NEUT MC: #nu_{#mu} CC backgrounds","f");
    legend_altbkg->AddEntry(recopimom_impsel_otherbkg,"NEUT MC: other backgrounds","f");
    legend_altbkg->AddEntry(recopimom_impsel_oofv,"NEUT MC: OOFV","f");
    legend_altbkg->Draw();
}
