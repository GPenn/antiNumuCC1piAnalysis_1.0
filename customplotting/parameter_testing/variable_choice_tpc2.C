{
    gStyle->SetTitleYOffset(1.7);
    gStyle->SetOptStat(0);
    //gStyle->SetLabelSize(0.025);
    //gStyle->SetTitleSize(0.025);
    
    //Float_t refvalue_cc1pi_mu, refvalue_cc1pi_pi, refvalue_pg_mu, refvalue_pg_pi, refvalue_pg_p, refvalue_pg_e;
    
    Float_t bar_width_sig = 0.2;
    Float_t bar_offset_sig = 0.5 - bar_width_sig*2;
    
    Float_t bar_width_bkg = 0.0625;
    Float_t bar_offset_bkg = 0.5 - bar_width_bkg*6;
    
    // =============== TPC2 variable choice ===============
    
    const char *tpc2varchoices[3] = {"TPC2 dE/dx","TPC2 pulls","TPC2 likelihoods"};
    
    TH1F* TPC2_musel_mu = new TH1F("TPC2_musel_mu","#mu^{+} identified as #mu^{+}",3,0,3);
    TH1F* TPC2_musel_pi = new TH1F("TPC2_musel_pi","#pi^{+} identified as #mu^{+}",3,0,3);
    TH1F* TPC2_musel_p = new TH1F("TPC2_musel_p","p identified as #mu^{+}",3,0,3);
    TH1F* TPC2_musel_e = new TH1F("TPC2_musel_e","e^{+} identified as #mu^{+}",3,0,3);
    TH1F* TPC2_pisel_mu = new TH1F("TPC2_pisel_mu","#mu^{+} identified as #pi^{+}",3,0,3);
    TH1F* TPC2_pisel_pi = new TH1F("TPC2_pisel_pi","#pi^{+} identified as #pi^{+}",3,0,3);
    TH1F* TPC2_pisel_p = new TH1F("TPC2_pisel_p","p identified as #pi^{+}",3,0,3);
    TH1F* TPC2_pisel_e = new TH1F("TPC2_pisel_e","e^{+} identified as #pi^{+}",3,0,3);
    TH1F* TPC2_psel_mu = new TH1F("TPC2_psel_mu","#mu^{+} identified as p",3,0,3);
    TH1F* TPC2_psel_pi = new TH1F("TPC2_psel_pi","#pi^{+} identified as p",3,0,3);
    TH1F* TPC2_psel_p = new TH1F("TPC2_psel_p","p identified as p",3,0,3);
    TH1F* TPC2_psel_e = new TH1F("TPC2_psel_e","e^{+} identified as p",3,0,3);
    TH1F* TPC2_esel_mu = new TH1F("TPC2_esel_mu","#mu^{+} identified as e^{+}",3,0,3);
    TH1F* TPC2_esel_pi = new TH1F("TPC2_esel_pi","#pi^{+} identified as e^{+}",3,0,3);
    TH1F* TPC2_esel_p = new TH1F("TPC2_esel_p","p identified as e^{+}",3,0,3);
    TH1F* TPC2_esel_e = new TH1F("TPC2_esel_e","e^{+} identified as e^{+}",3,0,3);
    
    TH1F* TPC2_musel_mu_diff = new TH1F("TPC2_musel_mu_diff","#mu^{+} identified as #mu^{+}",3,0,3);
    TH1F* TPC2_musel_pi_diff = new TH1F("TPC2_musel_pi_diff","#pi^{+} identified as #mu^{+}",3,0,3);
    TH1F* TPC2_musel_p_diff = new TH1F("TPC2_musel_p_diff","p identified as #mu^{+}",3,0,3);
    TH1F* TPC2_musel_e_diff = new TH1F("TPC2_musel_e_diff","e^{+} identified as #mu^{+}",3,0,3);
    TH1F* TPC2_pisel_mu_diff = new TH1F("TPC2_pisel_mu_diff","#mu^{+} identified as #pi^{+}",3,0,3);
    TH1F* TPC2_pisel_pi_diff = new TH1F("TPC2_pisel_pi_diff","#pi^{+} identified as #pi^{+}",3,0,3);
    TH1F* TPC2_pisel_p_diff = new TH1F("TPC2_pisel_p_diff","p identified as #pi^{+}",3,0,3);
    TH1F* TPC2_pisel_e_diff = new TH1F("TPC2_pisel_e_diff","e^{+} identified as #pi^{+}",3,0,3);
    TH1F* TPC2_psel_mu_diff = new TH1F("TPC2_psel_mu_diff","#mu^{+} identified as p",3,0,3);
    TH1F* TPC2_psel_pi_diff = new TH1F("TPC2_psel_pi_diff","#pi^{+} identified as p",3,0,3);
    TH1F* TPC2_psel_p_diff = new TH1F("TPC2_psel_p_diff","p identified as p",3,0,3);
    TH1F* TPC2_psel_e_diff = new TH1F("TPC2_psel_e_diff","e^{+} identified as p",3,0,3);
    TH1F* TPC2_esel_mu_diff = new TH1F("TPC2_esel_mu_diff","#mu^{+} identified as e^{+}",3,0,3);
    TH1F* TPC2_esel_pi_diff = new TH1F("TPC2_esel_pi_diff","#pi^{+} identified as e^{+}",3,0,3);
    TH1F* TPC2_esel_p_diff = new TH1F("TPC2_esel_p_diff","p identified as e^{+}",3,0,3);
    TH1F* TPC2_esel_e_diff = new TH1F("TPC2_esel_e_diff","e^{+} identified as e^{+}",3,0,3);
    
    TPC2_musel_mu->SetFillColor( kBlue);
    TPC2_musel_pi->SetFillColor( kRed); //TPC2_musel_pi->SetFillStyle(3305);
    TPC2_musel_p->SetFillColor( kGreen); //TPC2_musel_p->SetFillStyle(3305);
    TPC2_musel_e->SetFillColor( kMagenta); //TPC2_musel_e->SetFillStyle(3305);
    TPC2_pisel_mu->SetFillColor( kBlue); //TPC2_pisel_mu->SetFillStyle(3345);
    TPC2_pisel_pi->SetFillColor( kRed); 
    TPC2_pisel_p->SetFillColor( kGreen+1); //TPC2_pisel_p->SetFillStyle(3345);
    TPC2_pisel_e->SetFillColor( kMagenta+1); //TPC2_pisel_e->SetFillStyle(3345);
    TPC2_psel_mu->SetFillColor( kBlue+1); //TPC2_psel_mu->SetFillStyle(3354);
    TPC2_psel_pi->SetFillColor( kRed+1); //TPC2_psel_pi->SetFillStyle(3354);
    TPC2_psel_p->SetFillColor( kGreen); 
    TPC2_psel_e->SetFillColor( kMagenta+2); //TPC2_psel_e->SetFillStyle(3354);
    TPC2_esel_mu->SetFillColor( kBlue+2); //TPC2_esel_mu->SetFillStyle(3144);
    TPC2_esel_pi->SetFillColor( kRed+2); //TPC2_esel_pi->SetFillStyle(3144);
    TPC2_esel_p->SetFillColor( kGreen+2); //TPC2_esel_p->SetFillStyle(3144);
    TPC2_esel_e->SetFillColor( kMagenta);
    
    TPC2_musel_mu_diff->SetFillColor( kBlue);
    TPC2_musel_pi_diff->SetFillColor( kRed); //TPC2_musel_pi_diff->SetFillStyle(3305);
    TPC2_musel_p_diff->SetFillColor( kGreen); //TPC2_musel_p_diff->SetFillStyle(3305);
    TPC2_musel_e_diff->SetFillColor( kMagenta); //TPC2_musel_e_diff->SetFillStyle(3305);
    TPC2_pisel_mu_diff->SetFillColor( kBlue); //TPC2_pisel_mu_diff->SetFillStyle(3345);
    TPC2_pisel_pi_diff->SetFillColor( kRed);
    TPC2_pisel_p_diff->SetFillColor( kGreen+1); //TPC2_pisel_p_diff->SetFillStyle(3345);
    TPC2_pisel_e_diff->SetFillColor( kMagenta+1); //TPC2_pisel_e_diff->SetFillStyle(3345);
    TPC2_psel_mu_diff->SetFillColor( kBlue+1); //TPC2_psel_mu_diff->SetFillStyle(3354);
    TPC2_psel_pi_diff->SetFillColor( kRed+1); //TPC2_psel_pi_diff->SetFillStyle(3354);
    TPC2_psel_p_diff->SetFillColor( kGreen);
    TPC2_psel_e_diff->SetFillColor( kMagenta+2); //TPC2_psel_e_diff->SetFillStyle(3354);
    TPC2_esel_mu_diff->SetFillColor( kBlue+2); //TPC2_esel_mu_diff->SetFillStyle(3144);
    TPC2_esel_pi_diff->SetFillColor( kRed+2); //TPC2_esel_pi->SetFillStyle(3144);
    TPC2_esel_p_diff->SetFillColor( kGreen+2); //TPC2_esel_p->SetFillStyle(3144);
    TPC2_esel_e_diff->SetFillColor( kMagenta);
    
    /*TPC2_musel_mu->SetBarOffset(bar_offset + (bar_width*0)); TPC2_musel_mu->SetBarWidth(bar_width);
    TPC2_musel_pi->SetBarOffset(bar_offset + (bar_width*1)); TPC2_musel_pi->SetBarWidth(bar_width);
    TPC2_musel_p->SetBarOffset(bar_offset + (bar_width*2)); TPC2_musel_p->SetBarWidth(bar_width);
    TPC2_musel_e->SetBarOffset(bar_offset + (bar_width*3)); TPC2_musel_e->SetBarWidth(bar_width);
    TPC2_pisel_mu->SetBarOffset(bar_offset + (bar_width*4)); TPC2_pisel_mu->SetBarWidth(bar_width);
    TPC2_pisel_pi->SetBarOffset(bar_offset + (bar_width*5)); TPC2_pisel_pi->SetBarWidth(bar_width);
    TPC2_pisel_p->SetBarOffset(bar_offset + (bar_width*6)); TPC2_pisel_p->SetBarWidth(bar_width);
    TPC2_pisel_e->SetBarOffset(bar_offset + (bar_width*7)); TPC2_pisel_e->SetBarWidth(bar_width);
    TPC2_psel_mu->SetBarOffset(bar_offset + (bar_width*8)); TPC2_psel_mu->SetBarWidth(bar_width);
    TPC2_psel_pi->SetBarOffset(bar_offset + (bar_width*9)); TPC2_psel_pi->SetBarWidth(bar_width);
    TPC2_psel_p->SetBarOffset(bar_offset + (bar_width*10)); TPC2_psel_p->SetBarWidth(bar_width);
    TPC2_psel_e->SetBarOffset(bar_offset + (bar_width*11)); TPC2_psel_e->SetBarWidth(bar_width);
    TPC2_esel_mu->SetBarOffset(bar_offset + (bar_width*12)); TPC2_esel_mu->SetBarWidth(bar_width);
    TPC2_esel_pi->SetBarOffset(bar_offset + (bar_width*13)); TPC2_esel_pi->SetBarWidth(bar_width);
    TPC2_esel_p->SetBarOffset(bar_offset + (bar_width*14)); TPC2_esel_p->SetBarWidth(bar_width);
    TPC2_esel_e->SetBarOffset(bar_offset + (bar_width*15)); TPC2_esel_e->SetBarWidth(bar_width);*/
    
    TPC2_musel_mu->SetBarOffset(bar_offset_sig + (bar_width_sig*0)); TPC2_musel_mu->SetBarWidth(bar_width_sig);
    TPC2_pisel_pi->SetBarOffset(bar_offset_sig + (bar_width_sig*1)); TPC2_pisel_pi->SetBarWidth(bar_width_sig);
    TPC2_psel_p->SetBarOffset(bar_offset_sig + (bar_width_sig*2)); TPC2_psel_p->SetBarWidth(bar_width_sig);
    TPC2_esel_e->SetBarOffset(bar_offset_sig + (bar_width_sig*3)); TPC2_esel_e->SetBarWidth(bar_width_sig);
    
    TPC2_musel_mu_diff->SetBarOffset(bar_offset_sig + (bar_width_sig*0)); TPC2_musel_mu_diff->SetBarWidth(bar_width_sig);
    TPC2_pisel_pi_diff->SetBarOffset(bar_offset_sig + (bar_width_sig*1)); TPC2_pisel_pi_diff->SetBarWidth(bar_width_sig);
    TPC2_psel_p_diff->SetBarOffset(bar_offset_sig + (bar_width_sig*2)); TPC2_psel_p_diff->SetBarWidth(bar_width_sig);
    TPC2_esel_e_diff->SetBarOffset(bar_offset_sig + (bar_width_sig*3)); TPC2_esel_e_diff->SetBarWidth(bar_width_sig);
    
    TPC2_pisel_mu->SetBarOffset(bar_offset_bkg + (bar_width_bkg*0)); TPC2_pisel_mu->SetBarWidth(bar_width_bkg);
    TPC2_psel_mu->SetBarOffset(bar_offset_bkg + (bar_width_bkg*1)); TPC2_psel_mu->SetBarWidth(bar_width_bkg);
    TPC2_esel_mu->SetBarOffset(bar_offset_bkg + (bar_width_bkg*2)); TPC2_esel_mu->SetBarWidth(bar_width_bkg);
    TPC2_musel_pi->SetBarOffset(bar_offset_bkg + (bar_width_bkg*3)); TPC2_musel_pi->SetBarWidth(bar_width_bkg);
    TPC2_psel_pi->SetBarOffset(bar_offset_bkg + (bar_width_bkg*4)); TPC2_psel_pi->SetBarWidth(bar_width_bkg);
    TPC2_esel_pi->SetBarOffset(bar_offset_bkg + (bar_width_bkg*5)); TPC2_esel_pi->SetBarWidth(bar_width_bkg);
    TPC2_musel_p->SetBarOffset(bar_offset_bkg + (bar_width_bkg*6)); TPC2_musel_p->SetBarWidth(bar_width_bkg);
    TPC2_pisel_p->SetBarOffset(bar_offset_bkg + (bar_width_bkg*7)); TPC2_pisel_p->SetBarWidth(bar_width_bkg);
    TPC2_esel_p->SetBarOffset(bar_offset_bkg + (bar_width_bkg*8)); TPC2_esel_p->SetBarWidth(bar_width_bkg);
    TPC2_musel_e->SetBarOffset(bar_offset_bkg + (bar_width_bkg*9)); TPC2_musel_e->SetBarWidth(bar_width_bkg);
    TPC2_pisel_e->SetBarOffset(bar_offset_bkg + (bar_width_bkg*10)); TPC2_pisel_e->SetBarWidth(bar_width_bkg);
    TPC2_psel_e->SetBarOffset(bar_offset_bkg + (bar_width_bkg*11)); TPC2_psel_e->SetBarWidth(bar_width_bkg);
    
    TPC2_pisel_mu_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*0)); TPC2_pisel_mu_diff->SetBarWidth(bar_width_bkg);
    TPC2_psel_mu_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*1)); TPC2_psel_mu_diff->SetBarWidth(bar_width_bkg);
    TPC2_esel_mu_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*2)); TPC2_esel_mu_diff->SetBarWidth(bar_width_bkg);
    TPC2_musel_pi_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*3)); TPC2_musel_pi_diff->SetBarWidth(bar_width_bkg);
    TPC2_psel_pi_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*4)); TPC2_psel_pi_diff->SetBarWidth(bar_width_bkg);
    TPC2_esel_pi_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*5)); TPC2_esel_pi_diff->SetBarWidth(bar_width_bkg);
    TPC2_musel_p_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*6)); TPC2_musel_p_diff->SetBarWidth(bar_width_bkg);
    TPC2_pisel_p_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*7)); TPC2_pisel_p_diff->SetBarWidth(bar_width_bkg);
    TPC2_esel_p_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*8)); TPC2_esel_p_diff->SetBarWidth(bar_width_bkg);
    TPC2_musel_e_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*9)); TPC2_musel_e_diff->SetBarWidth(bar_width_bkg);
    TPC2_pisel_e_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*10)); TPC2_pisel_e_diff->SetBarWidth(bar_width_bkg);
    TPC2_psel_e_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*11)); TPC2_psel_e_diff->SetBarWidth(bar_width_bkg);
    
    TPC2_musel_mu->Fill(tpc2varchoices[0],0.927221);
    TPC2_musel_pi->Fill(tpc2varchoices[0],0.356497); 
    TPC2_musel_p->Fill(tpc2varchoices[0],0.020381);
    TPC2_musel_e->Fill(tpc2varchoices[0],0.0626578);
    TPC2_pisel_mu->Fill(tpc2varchoices[0],0.0625371);
    TPC2_pisel_pi->Fill(tpc2varchoices[0],0.599565);
    TPC2_pisel_p->Fill(tpc2varchoices[0],0.0503907);
    TPC2_pisel_e->Fill(tpc2varchoices[0],0.102242);
    TPC2_psel_mu->Fill(tpc2varchoices[0],0.00970578);
    TPC2_psel_pi->Fill(tpc2varchoices[0],0.0422087);
    TPC2_psel_p->Fill(tpc2varchoices[0],0.919807);
    TPC2_psel_e->Fill(tpc2varchoices[0],0.166548);
    TPC2_esel_mu->Fill(tpc2varchoices[0],0.000535991);
    TPC2_esel_pi->Fill(tpc2varchoices[0],0.00172874);
    TPC2_esel_p->Fill(tpc2varchoices[0],0.00942124);
    TPC2_esel_e->Fill(tpc2varchoices[0],0.668552);
    
    TPC2_musel_mu->Fill(tpc2varchoices[1],0.92738);
    TPC2_musel_pi->Fill(tpc2varchoices[1],0.344259); 
    TPC2_musel_p->Fill(tpc2varchoices[1],0.0201908);
    TPC2_musel_e->Fill(tpc2varchoices[1],0.0453898);
    TPC2_pisel_mu->Fill(tpc2varchoices[1],0.0643479);
    TPC2_pisel_pi->Fill(tpc2varchoices[1],0.626951);
    TPC2_pisel_p->Fill(tpc2varchoices[1],0.0418511);
    TPC2_pisel_e->Fill(tpc2varchoices[1],0.0938233);
    TPC2_psel_mu->Fill(tpc2varchoices[1],0.00783706);
    TPC2_psel_pi->Fill(tpc2varchoices[1],0.0271806);
    TPC2_psel_p->Fill(tpc2varchoices[1],0.927794);
    TPC2_psel_e->Fill(tpc2varchoices[1],0.160653);
    TPC2_esel_mu->Fill(tpc2varchoices[1],0.000434587);
    TPC2_esel_pi->Fill(tpc2varchoices[1],0.00160893);
    TPC2_esel_p->Fill(tpc2varchoices[1],0.0101646);
    TPC2_esel_e->Fill(tpc2varchoices[1],0.700134);
    
    TPC2_musel_mu->Fill(tpc2varchoices[2],0.927323);
    TPC2_musel_pi->Fill(tpc2varchoices[2],0.341521); 
    TPC2_musel_p->Fill(tpc2varchoices[2],0.0206057);
    TPC2_musel_e->Fill(tpc2varchoices[2],0.0335115);
    TPC2_pisel_mu->Fill(tpc2varchoices[2],0.0635512);
    TPC2_pisel_pi->Fill(tpc2varchoices[2],0.620533);
    TPC2_pisel_p->Fill(tpc2varchoices[2],0.0552137);
    TPC2_pisel_e->Fill(tpc2varchoices[2],0.105805);
    TPC2_psel_mu->Fill(tpc2varchoices[2],0.0086338);
    TPC2_psel_pi->Fill(tpc2varchoices[2],0.0347973);
    TPC2_psel_p->Fill(tpc2varchoices[2],0.914932);
    TPC2_psel_e->Fill(tpc2varchoices[2],0.179822);
    TPC2_esel_mu->Fill(tpc2varchoices[2],0.000492532);
    TPC2_esel_pi->Fill(tpc2varchoices[2],0.00314939);
    TPC2_esel_p->Fill(tpc2varchoices[2],0.00924837);
    TPC2_esel_e->Fill(tpc2varchoices[2],0.680861);
    
    //TCanvas* canvas_TPC2_choices = new TCanvas("canvas_TPC2_choices","",200,10,1000,800);
    TCanvas* canvas_TPC2_choices_sig = new TCanvas("canvas_TPC2_choices_sig","",200,10,2000,800);
    canvas_TPC2_choices_sig->Divide(2,1,0.005,0.005);
    canvas_TPC2_choices_sig->cd(1);
    TPC2_musel_mu->GetYaxis()->SetRangeUser(0, 1);
    TPC2_musel_mu->GetXaxis()->SetRangeUser(0, 4);
    TPC2_musel_mu->GetYaxis()->SetTitle("Efficiency");
    TPC2_musel_mu->GetYaxis()->SetLabelSize(0.025);
    TPC2_musel_mu->GetYaxis()->SetTitleSize(0.025);
    TPC2_musel_mu->GetYaxis()->SetTitleOffset(1.2);
    
    TPC2_musel_mu->Draw("B");
    TPC2_pisel_pi->Draw("B same");
    TPC2_psel_p->Draw("B same");
    TPC2_esel_e->Draw("B same");
    
    //canvas_TPC2_choices->BuildLegend();
    //canvas_TPC2_choices_sig->cd(1)->BuildLegend();
    TLegend *legend_sig = new TLegend(0.55,0.65,0.76,0.82);
    legend_sig->AddEntry(TPC2_musel_mu,"#mu^{+} identified as #mu^{+}","f");
    legend_sig->AddEntry(TPC2_pisel_pi,"#pi^{+} identified as #pi^{+}","f");
    legend_sig->AddEntry(TPC2_psel_p,"p identified as p","f");
    legend_sig->AddEntry(TPC2_esel_e,"e^{+} identified as e^{+}","f");
    legend_sig->Draw();
    
    //TCanvas* canvas_TPC2_choices_bkg = new TCanvas("canvas_TPC2_choices_bkg","",200,10,1000,800);
    TCanvas* canvas_TPC2_choices_bkg = new TCanvas("canvas_TPC2_choices_bkg","",200,10,2000,800);
    canvas_TPC2_choices_bkg->Divide(2,1,0.005,0.005);
    canvas_TPC2_choices_bkg->cd(1);
    TPC2_pisel_mu->GetYaxis()->SetRangeUser(0, 0.5);
    TPC2_pisel_mu->GetXaxis()->SetRangeUser(0, 4);
    TPC2_pisel_mu->GetYaxis()->SetTitle("Efficiency");
    TPC2_pisel_mu->GetYaxis()->SetLabelSize(0.025);
    TPC2_pisel_mu->GetYaxis()->SetTitleSize(0.025);
    TPC2_pisel_mu->GetYaxis()->SetTitleOffset(1.4);
    
    TPC2_pisel_mu->Draw("B");
    TPC2_psel_mu->Draw("B same");
    TPC2_esel_mu->Draw("B same");
    TPC2_musel_pi->Draw("B same");
    TPC2_psel_pi->Draw("B same");
    TPC2_esel_pi->Draw("B same");
    TPC2_musel_p->Draw("B same");
    TPC2_pisel_p->Draw("B same");
    TPC2_esel_p->Draw("B same");
    TPC2_musel_e->Draw("B same");
    TPC2_pisel_e->Draw("B same");
    TPC2_psel_e->Draw("B same");

    //canvas_TPC2_choices_bkg->BuildLegend();
    //canvas_TPC2_choices_bkg->cd(1)->BuildLegend();
    TLegend *legend_bkg = new TLegend(0.55,0.65,0.76,0.82);
    legend_bkg->AddEntry(TPC2_pisel_mu,"#mu^{+} identified as #pi^{+}","f");
    legend_bkg->AddEntry(TPC2_psel_mu,"#mu^{+} identified as p","f");
    legend_bkg->AddEntry(TPC2_esel_mu,"#mu^{+} identified as e^{+}","f");
    legend_bkg->AddEntry(TPC2_musel_pi,"#pi^{+} identified as #mu^{+}","f");
    legend_bkg->AddEntry(TPC2_psel_pi,"#pi^{+} identified as p","f");
    legend_bkg->AddEntry(TPC2_esel_pi,"#pi^{+} identified as e^{+}","f");
    legend_bkg->AddEntry(TPC2_musel_p,"p identified as #mu^{+}","f");
    legend_bkg->AddEntry(TPC2_pisel_p,"p identified as #pi^{+}","f");
    legend_bkg->AddEntry(TPC2_esel_p,"p identified as e^{+}","f");
    legend_bkg->AddEntry(TPC2_musel_e,"e^{+} identified as #mu^{+}","f");
    legend_bkg->AddEntry(TPC2_pisel_e,"e^{+} identified as #pi^{+}","f");
    legend_bkg->AddEntry(TPC2_psel_e,"e^{+} identified as p","f");
    legend_bkg->Draw();
    
    TPC2_musel_mu_diff->Fill(tpc2varchoices[0], TPC2_musel_mu->GetBinContent(1)-TPC2_musel_mu->GetBinContent(1) );
    TPC2_musel_pi_diff->Fill(tpc2varchoices[0], TPC2_musel_pi->GetBinContent(1)-TPC2_musel_pi->GetBinContent(1) ); 
    TPC2_musel_p_diff->Fill(tpc2varchoices[0], TPC2_musel_p->GetBinContent(1)-TPC2_musel_p->GetBinContent(1) );
    TPC2_musel_e_diff->Fill(tpc2varchoices[0], TPC2_musel_e->GetBinContent(1)-TPC2_musel_e->GetBinContent(1) );
    TPC2_pisel_mu_diff->Fill(tpc2varchoices[0], TPC2_pisel_mu->GetBinContent(1)-TPC2_pisel_mu->GetBinContent(1) );
    TPC2_pisel_pi_diff->Fill(tpc2varchoices[0], TPC2_pisel_pi->GetBinContent(1)-TPC2_pisel_pi->GetBinContent(1) );
    TPC2_pisel_p_diff->Fill(tpc2varchoices[0], TPC2_pisel_p->GetBinContent(1)-TPC2_pisel_p->GetBinContent(1) );
    TPC2_pisel_e_diff->Fill(tpc2varchoices[0], TPC2_pisel_e->GetBinContent(1)-TPC2_pisel_e->GetBinContent(1) );
    TPC2_psel_mu_diff->Fill(tpc2varchoices[0], TPC2_psel_mu->GetBinContent(1)-TPC2_psel_mu->GetBinContent(1) );
    TPC2_psel_pi_diff->Fill(tpc2varchoices[0], TPC2_psel_pi->GetBinContent(1)-TPC2_psel_pi->GetBinContent(1) );
    TPC2_psel_p_diff->Fill(tpc2varchoices[0], TPC2_psel_p->GetBinContent(1)-TPC2_psel_p->GetBinContent(1) );
    TPC2_psel_e_diff->Fill(tpc2varchoices[0], TPC2_psel_e->GetBinContent(1)-TPC2_psel_e->GetBinContent(1) );
    TPC2_esel_mu_diff->Fill(tpc2varchoices[0], TPC2_esel_mu->GetBinContent(1)-TPC2_esel_mu->GetBinContent(1) );
    TPC2_esel_pi_diff->Fill(tpc2varchoices[0], TPC2_esel_pi->GetBinContent(1)-TPC2_esel_pi->GetBinContent(1) );
    TPC2_esel_p_diff->Fill(tpc2varchoices[0], TPC2_esel_p->GetBinContent(1)-TPC2_esel_p->GetBinContent(1) );
    TPC2_esel_e_diff->Fill(tpc2varchoices[0], TPC2_esel_e->GetBinContent(1)-TPC2_esel_e->GetBinContent(1) );
    
    TPC2_musel_mu_diff->Fill(tpc2varchoices[1], TPC2_musel_mu->GetBinContent(2)-TPC2_musel_mu->GetBinContent(1) );
    TPC2_musel_pi_diff->Fill(tpc2varchoices[1], TPC2_musel_pi->GetBinContent(2)-TPC2_musel_pi->GetBinContent(1) ); 
    TPC2_musel_p_diff->Fill(tpc2varchoices[1], TPC2_musel_p->GetBinContent(2)-TPC2_musel_p->GetBinContent(1) );
    TPC2_musel_e_diff->Fill(tpc2varchoices[1], TPC2_musel_e->GetBinContent(2)-TPC2_musel_e->GetBinContent(1) );
    TPC2_pisel_mu_diff->Fill(tpc2varchoices[1], TPC2_pisel_mu->GetBinContent(2)-TPC2_pisel_mu->GetBinContent(1) );
    TPC2_pisel_pi_diff->Fill(tpc2varchoices[1], TPC2_pisel_pi->GetBinContent(2)-TPC2_pisel_pi->GetBinContent(1) );
    TPC2_pisel_p_diff->Fill(tpc2varchoices[1], TPC2_pisel_p->GetBinContent(2)-TPC2_pisel_p->GetBinContent(1) );
    TPC2_pisel_e_diff->Fill(tpc2varchoices[1], TPC2_pisel_e->GetBinContent(2)-TPC2_pisel_e->GetBinContent(1) );
    TPC2_psel_mu_diff->Fill(tpc2varchoices[1], TPC2_psel_mu->GetBinContent(2)-TPC2_psel_mu->GetBinContent(1) );
    TPC2_psel_pi_diff->Fill(tpc2varchoices[1], TPC2_psel_pi->GetBinContent(2)-TPC2_psel_pi->GetBinContent(1) );
    TPC2_psel_p_diff->Fill(tpc2varchoices[1], TPC2_psel_p->GetBinContent(2)-TPC2_psel_p->GetBinContent(1) );
    TPC2_psel_e_diff->Fill(tpc2varchoices[1], TPC2_psel_e->GetBinContent(2)-TPC2_psel_e->GetBinContent(1) );
    TPC2_esel_mu_diff->Fill(tpc2varchoices[1], TPC2_esel_mu->GetBinContent(2)-TPC2_esel_mu->GetBinContent(1) );
    TPC2_esel_pi_diff->Fill(tpc2varchoices[1], TPC2_esel_pi->GetBinContent(2)-TPC2_esel_pi->GetBinContent(1) );
    TPC2_esel_p_diff->Fill(tpc2varchoices[1], TPC2_esel_p->GetBinContent(2)-TPC2_esel_p->GetBinContent(1) );
    TPC2_esel_e_diff->Fill(tpc2varchoices[1], TPC2_esel_e->GetBinContent(2)-TPC2_esel_e->GetBinContent(1) );
    
    TPC2_musel_mu_diff->Fill(tpc2varchoices[2], TPC2_musel_mu->GetBinContent(3)-TPC2_musel_mu->GetBinContent(1) );
    TPC2_musel_pi_diff->Fill(tpc2varchoices[2], TPC2_musel_pi->GetBinContent(3)-TPC2_musel_pi->GetBinContent(1) ); 
    TPC2_musel_p_diff->Fill(tpc2varchoices[2], TPC2_musel_p->GetBinContent(3)-TPC2_musel_p->GetBinContent(1) );
    TPC2_musel_e_diff->Fill(tpc2varchoices[2], TPC2_musel_e->GetBinContent(3)-TPC2_musel_e->GetBinContent(1) );
    TPC2_pisel_mu_diff->Fill(tpc2varchoices[2], TPC2_pisel_mu->GetBinContent(3)-TPC2_pisel_mu->GetBinContent(1) );
    TPC2_pisel_pi_diff->Fill(tpc2varchoices[2], TPC2_pisel_pi->GetBinContent(3)-TPC2_pisel_pi->GetBinContent(1) );
    TPC2_pisel_p_diff->Fill(tpc2varchoices[2], TPC2_pisel_p->GetBinContent(3)-TPC2_pisel_p->GetBinContent(1) );
    TPC2_pisel_e_diff->Fill(tpc2varchoices[2], TPC2_pisel_e->GetBinContent(3)-TPC2_pisel_e->GetBinContent(1) );
    TPC2_psel_mu_diff->Fill(tpc2varchoices[2], TPC2_psel_mu->GetBinContent(3)-TPC2_psel_mu->GetBinContent(1) );
    TPC2_psel_pi_diff->Fill(tpc2varchoices[2], TPC2_psel_pi->GetBinContent(3)-TPC2_psel_pi->GetBinContent(1) );
    TPC2_psel_p_diff->Fill(tpc2varchoices[2], TPC2_psel_p->GetBinContent(3)-TPC2_psel_p->GetBinContent(1) );
    TPC2_psel_e_diff->Fill(tpc2varchoices[2], TPC2_psel_e->GetBinContent(3)-TPC2_psel_e->GetBinContent(1) );
    TPC2_esel_mu_diff->Fill(tpc2varchoices[2], TPC2_esel_mu->GetBinContent(3)-TPC2_esel_mu->GetBinContent(1) );
    TPC2_esel_pi_diff->Fill(tpc2varchoices[2], TPC2_esel_pi->GetBinContent(3)-TPC2_esel_pi->GetBinContent(1) );
    TPC2_esel_p_diff->Fill(tpc2varchoices[2], TPC2_esel_p->GetBinContent(3)-TPC2_esel_p->GetBinContent(1) );
    TPC2_esel_e_diff->Fill(tpc2varchoices[2], TPC2_esel_e->GetBinContent(3)-TPC2_esel_e->GetBinContent(1) );
    
    //TCanvas* canvas_TPC2_choices_diff = new TCanvas("canvas_TPC2_choices_diff","",200,10,1000,800);
    canvas_TPC2_choices_sig->cd(2);
    TPC2_musel_mu_diff->GetYaxis()->SetRangeUser(-0.15, 0.02);
    TPC2_musel_mu_diff->GetXaxis()->SetRangeUser(0, 2);
    TPC2_musel_mu_diff->GetYaxis()->SetTitle("Difference in efficiency");
    TPC2_musel_mu_diff->GetYaxis()->SetLabelSize(0.025);
    TPC2_musel_mu_diff->GetYaxis()->SetTitleSize(0.025);
    TPC2_musel_mu_diff->GetYaxis()->SetTitleOffset(1.6);
    
    TPC2_musel_mu_diff->Draw("B");
    TPC2_pisel_pi_diff->Draw("B same");
    TPC2_psel_p_diff->Draw("B same");
    TPC2_esel_e_diff->Draw("B same");
    
    //canvas_TPC2_choices_diff->BuildLegend();
    
    //TCanvas* canvas_TPC2_choices_bkg_diff = new TCanvas("canvas_TPC2_choices_bkg_diff","",200,10,1000,800);
    canvas_TPC2_choices_bkg->cd(2);
    TPC2_pisel_mu_diff->GetYaxis()->SetRangeUser(-0.1, 0.1);
    TPC2_pisel_mu_diff->GetXaxis()->SetRangeUser(1, 3);
    TPC2_pisel_mu_diff->GetYaxis()->SetTitle("Difference in efficiency");
    TPC2_pisel_mu_diff->GetYaxis()->SetLabelSize(0.025);
    TPC2_pisel_mu_diff->GetYaxis()->SetTitleSize(0.025);
    TPC2_pisel_mu_diff->GetYaxis()->SetTitleOffset(1.5);
    
    TPC2_pisel_mu_diff->Draw("B");
    TPC2_psel_mu_diff->Draw("B same");
    TPC2_esel_mu_diff->Draw("B same");
    TPC2_musel_pi_diff->Draw("B same");
    TPC2_psel_pi_diff->Draw("B same");
    TPC2_esel_pi_diff->Draw("B same");
    TPC2_musel_p_diff->Draw("B same");
    TPC2_pisel_p_diff->Draw("B same");
    TPC2_esel_p_diff->Draw("B same");
    TPC2_musel_e_diff->Draw("B same");
    TPC2_pisel_e_diff->Draw("B same");
    TPC2_psel_e_diff->Draw("B same");
    
    //canvas_TPC2_choices_bkg_diff->BuildLegend();

}
