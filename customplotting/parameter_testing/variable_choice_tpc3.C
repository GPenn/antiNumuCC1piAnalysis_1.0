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
    
    // =============== TPC3 variable choice ===============
    
    const char *tpc3varchoices[4] = {"TPC3 dE/dx","TPC3 pulls","TPC3 muon pull", "nTPCs"};
    
    TH1F* TPC3_musel_mu = new TH1F("TPC3_musel_mu","#mu^{+} identified as #mu^{+}",3,0,3);
    TH1F* TPC3_musel_pi = new TH1F("TPC3_musel_pi","#pi^{+} identified as #mu^{+}",3,0,3);
    TH1F* TPC3_musel_p = new TH1F("TPC3_musel_p","p identified as #mu^{+}",3,0,3);
    TH1F* TPC3_musel_e = new TH1F("TPC3_musel_e","e^{+} identified as #mu^{+}",3,0,3);
    TH1F* TPC3_pisel_mu = new TH1F("TPC3_pisel_mu","#mu^{+} identified as #pi^{+}",3,0,3);
    TH1F* TPC3_pisel_pi = new TH1F("TPC3_pisel_pi","#pi^{+} identified as #pi^{+}",3,0,3);
    TH1F* TPC3_pisel_p = new TH1F("TPC3_pisel_p","p identified as #pi^{+}",3,0,3);
    TH1F* TPC3_pisel_e = new TH1F("TPC3_pisel_e","e^{+} identified as #pi^{+}",3,0,3);
    TH1F* TPC3_psel_mu = new TH1F("TPC3_psel_mu","#mu^{+} identified as p",3,0,3);
    TH1F* TPC3_psel_pi = new TH1F("TPC3_psel_pi","#pi^{+} identified as p",3,0,3);
    TH1F* TPC3_psel_p = new TH1F("TPC3_psel_p","p identified as p",3,0,3);
    TH1F* TPC3_psel_e = new TH1F("TPC3_psel_e","e^{+} identified as p",3,0,3);
    TH1F* TPC3_esel_mu = new TH1F("TPC3_esel_mu","#mu^{+} identified as e^{+}",3,0,3);
    TH1F* TPC3_esel_pi = new TH1F("TPC3_esel_pi","#pi^{+} identified as e^{+}",3,0,3);
    TH1F* TPC3_esel_p = new TH1F("TPC3_esel_p","p identified as e^{+}",3,0,3);
    TH1F* TPC3_esel_e = new TH1F("TPC3_esel_e","e^{+} identified as e^{+}",3,0,3);
    
    TH1F* TPC3_musel_mu_diff = new TH1F("TPC3_musel_mu_diff","#mu^{+} identified as #mu^{+}",3,0,3);
    TH1F* TPC3_musel_pi_diff = new TH1F("TPC3_musel_pi_diff","#pi^{+} identified as #mu^{+}",3,0,3);
    TH1F* TPC3_musel_p_diff = new TH1F("TPC3_musel_p_diff","p identified as #mu^{+}",3,0,3);
    TH1F* TPC3_musel_e_diff = new TH1F("TPC3_musel_e_diff","e^{+} identified as #mu^{+}",3,0,3);
    TH1F* TPC3_pisel_mu_diff = new TH1F("TPC3_pisel_mu_diff","#mu^{+} identified as #pi^{+}",3,0,3);
    TH1F* TPC3_pisel_pi_diff = new TH1F("TPC3_pisel_pi_diff","#pi^{+} identified as #pi^{+}",3,0,3);
    TH1F* TPC3_pisel_p_diff = new TH1F("TPC3_pisel_p_diff","p identified as #pi^{+}",3,0,3);
    TH1F* TPC3_pisel_e_diff = new TH1F("TPC3_pisel_e_diff","e^{+} identified as #pi^{+}",3,0,3);
    TH1F* TPC3_psel_mu_diff = new TH1F("TPC3_psel_mu_diff","#mu^{+} identified as p",3,0,3);
    TH1F* TPC3_psel_pi_diff = new TH1F("TPC3_psel_pi_diff","#pi^{+} identified as p",3,0,3);
    TH1F* TPC3_psel_p_diff = new TH1F("TPC3_psel_p_diff","p identified as p",3,0,3);
    TH1F* TPC3_psel_e_diff = new TH1F("TPC3_psel_e_diff","e^{+} identified as p",3,0,3);
    TH1F* TPC3_esel_mu_diff = new TH1F("TPC3_esel_mu_diff","#mu^{+} identified as e^{+}",3,0,3);
    TH1F* TPC3_esel_pi_diff = new TH1F("TPC3_esel_pi_diff","#pi^{+} identified as e^{+}",3,0,3);
    TH1F* TPC3_esel_p_diff = new TH1F("TPC3_esel_p_diff","p identified as e^{+}",3,0,3);
    TH1F* TPC3_esel_e_diff = new TH1F("TPC3_esel_e_diff","e^{+} identified as e^{+}",3,0,3);
    
    TPC3_musel_mu->SetFillColor( kBlue);
    TPC3_musel_pi->SetFillColor( kRed); //TPC3_musel_pi->SetFillStyle(3305);
    TPC3_musel_p->SetFillColor( kGreen); //TPC3_musel_p->SetFillStyle(3305);
    TPC3_musel_e->SetFillColor( kMagenta); //TPC3_musel_e->SetFillStyle(3305);
    TPC3_pisel_mu->SetFillColor( kBlue); //TPC3_pisel_mu->SetFillStyle(3345);
    TPC3_pisel_pi->SetFillColor( kRed); 
    TPC3_pisel_p->SetFillColor( kGreen+1); //TPC3_pisel_p->SetFillStyle(3345);
    TPC3_pisel_e->SetFillColor( kMagenta+1); //TPC3_pisel_e->SetFillStyle(3345);
    TPC3_psel_mu->SetFillColor( kBlue+1); //TPC3_psel_mu->SetFillStyle(3354);
    TPC3_psel_pi->SetFillColor( kRed+1); //TPC3_psel_pi->SetFillStyle(3354);
    TPC3_psel_p->SetFillColor( kGreen); 
    TPC3_psel_e->SetFillColor( kMagenta+2); //TPC3_psel_e->SetFillStyle(3354);
    TPC3_esel_mu->SetFillColor( kBlue+2); //TPC3_esel_mu->SetFillStyle(3144);
    TPC3_esel_pi->SetFillColor( kRed+2); //TPC3_esel_pi->SetFillStyle(3144);
    TPC3_esel_p->SetFillColor( kGreen+2); //TPC3_esel_p->SetFillStyle(3144);
    TPC3_esel_e->SetFillColor( kMagenta);
    
    TPC3_musel_mu_diff->SetFillColor( kBlue);
    TPC3_musel_pi_diff->SetFillColor( kRed); //TPC3_musel_pi_diff->SetFillStyle(3305);
    TPC3_musel_p_diff->SetFillColor( kGreen); //TPC3_musel_p_diff->SetFillStyle(3305);
    TPC3_musel_e_diff->SetFillColor( kMagenta); //TPC3_musel_e_diff->SetFillStyle(3305);
    TPC3_pisel_mu_diff->SetFillColor( kBlue); //TPC3_pisel_mu_diff->SetFillStyle(3345);
    TPC3_pisel_pi_diff->SetFillColor( kRed);
    TPC3_pisel_p_diff->SetFillColor( kGreen+1); //TPC3_pisel_p_diff->SetFillStyle(3345);
    TPC3_pisel_e_diff->SetFillColor( kMagenta+1); //TPC3_pisel_e_diff->SetFillStyle(3345);
    TPC3_psel_mu_diff->SetFillColor( kBlue+1); //TPC3_psel_mu_diff->SetFillStyle(3354);
    TPC3_psel_pi_diff->SetFillColor( kRed+1); //TPC3_psel_pi_diff->SetFillStyle(3354);
    TPC3_psel_p_diff->SetFillColor( kGreen);
    TPC3_psel_e_diff->SetFillColor( kMagenta+2); //TPC3_psel_e_diff->SetFillStyle(3354);
    TPC3_esel_mu_diff->SetFillColor( kBlue+2); //TPC3_esel_mu_diff->SetFillStyle(3144);
    TPC3_esel_pi_diff->SetFillColor( kRed+2); //TPC3_esel_pi->SetFillStyle(3144);
    TPC3_esel_p_diff->SetFillColor( kGreen+2); //TPC3_esel_p->SetFillStyle(3144);
    TPC3_esel_e_diff->SetFillColor( kMagenta);
    
    /*TPC3_musel_mu->SetBarOffset(bar_offset + (bar_width*0)); TPC3_musel_mu->SetBarWidth(bar_width);
    TPC3_musel_pi->SetBarOffset(bar_offset + (bar_width*1)); TPC3_musel_pi->SetBarWidth(bar_width);
    TPC3_musel_p->SetBarOffset(bar_offset + (bar_width*2)); TPC3_musel_p->SetBarWidth(bar_width);
    TPC3_musel_e->SetBarOffset(bar_offset + (bar_width*3)); TPC3_musel_e->SetBarWidth(bar_width);
    TPC3_pisel_mu->SetBarOffset(bar_offset + (bar_width*4)); TPC3_pisel_mu->SetBarWidth(bar_width);
    TPC3_pisel_pi->SetBarOffset(bar_offset + (bar_width*5)); TPC3_pisel_pi->SetBarWidth(bar_width);
    TPC3_pisel_p->SetBarOffset(bar_offset + (bar_width*6)); TPC3_pisel_p->SetBarWidth(bar_width);
    TPC3_pisel_e->SetBarOffset(bar_offset + (bar_width*7)); TPC3_pisel_e->SetBarWidth(bar_width);
    TPC3_psel_mu->SetBarOffset(bar_offset + (bar_width*8)); TPC3_psel_mu->SetBarWidth(bar_width);
    TPC3_psel_pi->SetBarOffset(bar_offset + (bar_width*9)); TPC3_psel_pi->SetBarWidth(bar_width);
    TPC3_psel_p->SetBarOffset(bar_offset + (bar_width*10)); TPC3_psel_p->SetBarWidth(bar_width);
    TPC3_psel_e->SetBarOffset(bar_offset + (bar_width*11)); TPC3_psel_e->SetBarWidth(bar_width);
    TPC3_esel_mu->SetBarOffset(bar_offset + (bar_width*12)); TPC3_esel_mu->SetBarWidth(bar_width);
    TPC3_esel_pi->SetBarOffset(bar_offset + (bar_width*13)); TPC3_esel_pi->SetBarWidth(bar_width);
    TPC3_esel_p->SetBarOffset(bar_offset + (bar_width*14)); TPC3_esel_p->SetBarWidth(bar_width);
    TPC3_esel_e->SetBarOffset(bar_offset + (bar_width*15)); TPC3_esel_e->SetBarWidth(bar_width);*/
    
    TPC3_musel_mu->SetBarOffset(bar_offset_sig + (bar_width_sig*0)); TPC3_musel_mu->SetBarWidth(bar_width_sig);
    TPC3_pisel_pi->SetBarOffset(bar_offset_sig + (bar_width_sig*1)); TPC3_pisel_pi->SetBarWidth(bar_width_sig);
    TPC3_psel_p->SetBarOffset(bar_offset_sig + (bar_width_sig*2)); TPC3_psel_p->SetBarWidth(bar_width_sig);
    TPC3_esel_e->SetBarOffset(bar_offset_sig + (bar_width_sig*3)); TPC3_esel_e->SetBarWidth(bar_width_sig);
    
    TPC3_musel_mu_diff->SetBarOffset(bar_offset_sig + (bar_width_sig*0)); TPC3_musel_mu_diff->SetBarWidth(bar_width_sig);
    TPC3_pisel_pi_diff->SetBarOffset(bar_offset_sig + (bar_width_sig*1)); TPC3_pisel_pi_diff->SetBarWidth(bar_width_sig);
    TPC3_psel_p_diff->SetBarOffset(bar_offset_sig + (bar_width_sig*2)); TPC3_psel_p_diff->SetBarWidth(bar_width_sig);
    TPC3_esel_e_diff->SetBarOffset(bar_offset_sig + (bar_width_sig*3)); TPC3_esel_e_diff->SetBarWidth(bar_width_sig);
    
    TPC3_pisel_mu->SetBarOffset(bar_offset_bkg + (bar_width_bkg*0)); TPC3_pisel_mu->SetBarWidth(bar_width_bkg);
    TPC3_psel_mu->SetBarOffset(bar_offset_bkg + (bar_width_bkg*1)); TPC3_psel_mu->SetBarWidth(bar_width_bkg);
    TPC3_esel_mu->SetBarOffset(bar_offset_bkg + (bar_width_bkg*2)); TPC3_esel_mu->SetBarWidth(bar_width_bkg);
    TPC3_musel_pi->SetBarOffset(bar_offset_bkg + (bar_width_bkg*3)); TPC3_musel_pi->SetBarWidth(bar_width_bkg);
    TPC3_psel_pi->SetBarOffset(bar_offset_bkg + (bar_width_bkg*4)); TPC3_psel_pi->SetBarWidth(bar_width_bkg);
    TPC3_esel_pi->SetBarOffset(bar_offset_bkg + (bar_width_bkg*5)); TPC3_esel_pi->SetBarWidth(bar_width_bkg);
    TPC3_musel_p->SetBarOffset(bar_offset_bkg + (bar_width_bkg*6)); TPC3_musel_p->SetBarWidth(bar_width_bkg);
    TPC3_pisel_p->SetBarOffset(bar_offset_bkg + (bar_width_bkg*7)); TPC3_pisel_p->SetBarWidth(bar_width_bkg);
    TPC3_esel_p->SetBarOffset(bar_offset_bkg + (bar_width_bkg*8)); TPC3_esel_p->SetBarWidth(bar_width_bkg);
    TPC3_musel_e->SetBarOffset(bar_offset_bkg + (bar_width_bkg*9)); TPC3_musel_e->SetBarWidth(bar_width_bkg);
    TPC3_pisel_e->SetBarOffset(bar_offset_bkg + (bar_width_bkg*10)); TPC3_pisel_e->SetBarWidth(bar_width_bkg);
    TPC3_psel_e->SetBarOffset(bar_offset_bkg + (bar_width_bkg*11)); TPC3_psel_e->SetBarWidth(bar_width_bkg);
    
    TPC3_pisel_mu_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*0)); TPC3_pisel_mu_diff->SetBarWidth(bar_width_bkg);
    TPC3_psel_mu_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*1)); TPC3_psel_mu_diff->SetBarWidth(bar_width_bkg);
    TPC3_esel_mu_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*2)); TPC3_esel_mu_diff->SetBarWidth(bar_width_bkg);
    TPC3_musel_pi_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*3)); TPC3_musel_pi_diff->SetBarWidth(bar_width_bkg);
    TPC3_psel_pi_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*4)); TPC3_psel_pi_diff->SetBarWidth(bar_width_bkg);
    TPC3_esel_pi_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*5)); TPC3_esel_pi_diff->SetBarWidth(bar_width_bkg);
    TPC3_musel_p_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*6)); TPC3_musel_p_diff->SetBarWidth(bar_width_bkg);
    TPC3_pisel_p_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*7)); TPC3_pisel_p_diff->SetBarWidth(bar_width_bkg);
    TPC3_esel_p_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*8)); TPC3_esel_p_diff->SetBarWidth(bar_width_bkg);
    TPC3_musel_e_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*9)); TPC3_musel_e_diff->SetBarWidth(bar_width_bkg);
    TPC3_pisel_e_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*10)); TPC3_pisel_e_diff->SetBarWidth(bar_width_bkg);
    TPC3_psel_e_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*11)); TPC3_psel_e_diff->SetBarWidth(bar_width_bkg);
    
    TPC3_musel_mu->Fill(tpc3varchoices[0],0.936612);
    TPC3_musel_pi->Fill(tpc3varchoices[0],0.363204); 
    TPC3_musel_p->Fill(tpc3varchoices[0],0.0277038);
    TPC3_musel_e->Fill(tpc3varchoices[0],0.0397502);
    TPC3_pisel_mu->Fill(tpc3varchoices[0],0.0570192);
    TPC3_pisel_pi->Fill(tpc3varchoices[0],0.609055);
    TPC3_pisel_p->Fill(tpc3varchoices[0],0.0665875);
    TPC3_pisel_e->Fill(tpc3varchoices[0],0.112491);
    TPC3_psel_mu->Fill(tpc3varchoices[0],0.00602183);
    TPC3_psel_pi->Fill(tpc3varchoices[0],0.025825);
    TPC3_psel_p->Fill(tpc3varchoices[0],0.894885);
    TPC3_psel_e->Fill(tpc3varchoices[0],0.232448);
    TPC3_esel_mu->Fill(tpc3varchoices[0],0.000347413);
    TPC3_esel_pi->Fill(tpc3varchoices[0],0.00191554);
    TPC3_esel_p->Fill(tpc3varchoices[0],0.0108236);
    TPC3_esel_e->Fill(tpc3varchoices[0],0.615311);
    
    TPC3_musel_mu->Fill(tpc3varchoices[1],0.939347);
    TPC3_musel_pi->Fill(tpc3varchoices[1],0.372207); 
    TPC3_musel_p->Fill(tpc3varchoices[1],0.0603953);
    TPC3_musel_e->Fill(tpc3varchoices[1],0.0537121);
    TPC3_pisel_mu->Fill(tpc3varchoices[1],0.057106);
    TPC3_pisel_pi->Fill(tpc3varchoices[1],0.61933);
    TPC3_pisel_p->Fill(tpc3varchoices[1],0.779693);
    TPC3_pisel_e->Fill(tpc3varchoices[1],0.762382);
    TPC3_psel_mu->Fill(tpc3varchoices[1],0.00270693);
    TPC3_psel_pi->Fill(tpc3varchoices[1],0.00555507);
    TPC3_psel_p->Fill(tpc3varchoices[1],0.14846);
    TPC3_psel_e->Fill(tpc3varchoices[1],0.002651);
    TPC3_esel_mu->Fill(tpc3varchoices[1],0.000839582);
    TPC3_esel_pi->Fill(tpc3varchoices[1],0.00290814);
    TPC3_esel_p->Fill(tpc3varchoices[1],0.0114514);
    TPC3_esel_e->Fill(tpc3varchoices[1],0.181255);
    
    TPC3_musel_mu->Fill(tpc3varchoices[2],0.939217);
    TPC3_musel_pi->Fill(tpc3varchoices[2],0.370239); 
    TPC3_musel_p->Fill(tpc3varchoices[2],0.0459581);
    TPC3_musel_e->Fill(tpc3varchoices[2],0.0198972);
    TPC3_pisel_mu->Fill(tpc3varchoices[2],0.055948);
    TPC3_pisel_pi->Fill(tpc3varchoices[2],0.610971);
    TPC3_pisel_p->Fill(tpc3varchoices[2],0.267063);
    TPC3_pisel_e->Fill(tpc3varchoices[2],0.043712);
    TPC3_psel_mu->Fill(tpc3varchoices[2],0.00188182);
    TPC3_psel_pi->Fill(tpc3varchoices[2],0.00386591);
    TPC3_psel_p->Fill(tpc3varchoices[2],0.559759);
    TPC3_psel_e->Fill(tpc3varchoices[2],0.0163331);
    TPC3_esel_mu->Fill(tpc3varchoices[2],0.00295301);
    TPC3_esel_pi->Fill(tpc3varchoices[2],0.0149238);
    TPC3_esel_p->Fill(tpc3varchoices[2],0.12722);
    TPC3_esel_e->Fill(tpc3varchoices[2],0.920058);
    
    TPC3_musel_mu->Fill(tpc3varchoices[3],0.943791);
    TPC3_musel_pi->Fill(tpc3varchoices[3],0.357283); 
    TPC3_musel_p->Fill(tpc3varchoices[3],0.0307405);
    TPC3_musel_e->Fill(tpc3varchoices[3],0.0203685);
    TPC3_pisel_mu->Fill(tpc3varchoices[3],0.0486813);
    TPC3_pisel_pi->Fill(tpc3varchoices[3],0.597963);
    TPC3_pisel_p->Fill(tpc3varchoices[3],0.0575112);
    TPC3_pisel_e->Fill(tpc3varchoices[3],0.0183655);
    TPC3_psel_mu->Fill(tpc3varchoices[3],0.005327);
    TPC3_psel_pi->Fill(tpc3varchoices[3],0.0264693);
    TPC3_psel_p->Fill(tpc3varchoices[3],0.860192);
    TPC3_psel_e->Fill(tpc3varchoices[3],0.0385425);
    TPC3_esel_mu->Fill(tpc3varchoices[3],0.00220028);
    TPC3_esel_pi->Fill(tpc3varchoices[3],0.0182847);
    TPC3_esel_p->Fill(tpc3varchoices[3],0.0515565);
    TPC3_esel_e->Fill(tpc3varchoices[3],0.922723);
    
    //TCanvas* canvas_TPC3_choices = new TCanvas("canvas_TPC3_choices","",200,10,1000,800);
    TCanvas* canvas_TPC3_choices_sig = new TCanvas("canvas_TPC3_choices_sig","",200,10,2000,800);
    canvas_TPC3_choices_sig->Divide(2,1,0.005,0.005);
    canvas_TPC3_choices_sig->cd(1);
    TPC3_musel_mu->GetYaxis()->SetRangeUser(0, 1);
    TPC3_musel_mu->GetXaxis()->SetRangeUser(0, 5);
    TPC3_musel_mu->GetYaxis()->SetTitle("Efficiency");
    TPC3_musel_mu->GetYaxis()->SetLabelSize(0.025);
    TPC3_musel_mu->GetYaxis()->SetTitleSize(0.025);
    TPC3_musel_mu->GetYaxis()->SetTitleOffset(1.2);
    
    TPC3_musel_mu->Draw("B");
    TPC3_pisel_pi->Draw("B same");
    TPC3_psel_p->Draw("B same");
    TPC3_esel_e->Draw("B same");
    
    //canvas_TPC3_choices->BuildLegend();
    //canvas_TPC3_choices_sig->cd(1)->BuildLegend();
    TLegend *legend_sig = new TLegend(0.55,0.65,0.76,0.82);
    legend_sig->AddEntry(TPC3_musel_mu,"#mu^{+} identified as #mu^{+}","f");
    legend_sig->AddEntry(TPC3_pisel_pi,"#pi^{+} identified as #pi^{+}","f");
    legend_sig->AddEntry(TPC3_psel_p,"p identified as p","f");
    legend_sig->AddEntry(TPC3_esel_e,"e^{+} identified as e^{+}","f");
    legend_sig->Draw();
    
    //TCanvas* canvas_TPC3_choices_bkg = new TCanvas("canvas_TPC3_choices_bkg","",200,10,1000,800);
    TCanvas* canvas_TPC3_choices_bkg = new TCanvas("canvas_TPC3_choices_bkg","",200,10,2000,800);
    canvas_TPC3_choices_bkg->Divide(2,1,0.005,0.005);
    canvas_TPC3_choices_bkg->cd(1);
    TPC3_pisel_mu->GetYaxis()->SetRangeUser(0, 0.5);
    TPC3_pisel_mu->GetXaxis()->SetRangeUser(0, 5);
    TPC3_pisel_mu->GetYaxis()->SetTitle("Efficiency");
    TPC3_pisel_mu->GetYaxis()->SetLabelSize(0.025);
    TPC3_pisel_mu->GetYaxis()->SetTitleSize(0.025);
    TPC3_pisel_mu->GetYaxis()->SetTitleOffset(1.4);
    
    TPC3_pisel_mu->Draw("B");
    TPC3_psel_mu->Draw("B same");
    TPC3_esel_mu->Draw("B same");
    TPC3_musel_pi->Draw("B same");
    TPC3_psel_pi->Draw("B same");
    TPC3_esel_pi->Draw("B same");
    TPC3_musel_p->Draw("B same");
    TPC3_pisel_p->Draw("B same");
    TPC3_esel_p->Draw("B same");
    TPC3_musel_e->Draw("B same");
    TPC3_pisel_e->Draw("B same");
    TPC3_psel_e->Draw("B same");

    //canvas_TPC3_choices_bkg->BuildLegend();
    //canvas_TPC3_choices_bkg->cd(1)->BuildLegend();
    TLegend *legend_bkg = new TLegend(0.55,0.65,0.76,0.82);
    legend_bkg->AddEntry(TPC3_pisel_mu,"#mu^{+} identified as #pi^{+}","f");
    legend_bkg->AddEntry(TPC3_psel_mu,"#mu^{+} identified as p","f");
    legend_bkg->AddEntry(TPC3_esel_mu,"#mu^{+} identified as e^{+}","f");
    legend_bkg->AddEntry(TPC3_musel_pi,"#pi^{+} identified as #mu^{+}","f");
    legend_bkg->AddEntry(TPC3_psel_pi,"#pi^{+} identified as p","f");
    legend_bkg->AddEntry(TPC3_esel_pi,"#pi^{+} identified as e^{+}","f");
    legend_bkg->AddEntry(TPC3_musel_p,"p identified as #mu^{+}","f");
    legend_bkg->AddEntry(TPC3_pisel_p,"p identified as #pi^{+}","f");
    legend_bkg->AddEntry(TPC3_esel_p,"p identified as e^{+}","f");
    legend_bkg->AddEntry(TPC3_musel_e,"e^{+} identified as #mu^{+}","f");
    legend_bkg->AddEntry(TPC3_pisel_e,"e^{+} identified as #pi^{+}","f");
    legend_bkg->AddEntry(TPC3_psel_e,"e^{+} identified as p","f");
    legend_bkg->Draw();
    
    TPC3_musel_mu_diff->Fill(tpc3varchoices[0], TPC3_musel_mu->GetBinContent(1)-TPC3_musel_mu->GetBinContent(1) );
    TPC3_musel_pi_diff->Fill(tpc3varchoices[0], TPC3_musel_pi->GetBinContent(1)-TPC3_musel_pi->GetBinContent(1) ); 
    TPC3_musel_p_diff->Fill(tpc3varchoices[0], TPC3_musel_p->GetBinContent(1)-TPC3_musel_p->GetBinContent(1) );
    TPC3_musel_e_diff->Fill(tpc3varchoices[0], TPC3_musel_e->GetBinContent(1)-TPC3_musel_e->GetBinContent(1) );
    TPC3_pisel_mu_diff->Fill(tpc3varchoices[0], TPC3_pisel_mu->GetBinContent(1)-TPC3_pisel_mu->GetBinContent(1) );
    TPC3_pisel_pi_diff->Fill(tpc3varchoices[0], TPC3_pisel_pi->GetBinContent(1)-TPC3_pisel_pi->GetBinContent(1) );
    TPC3_pisel_p_diff->Fill(tpc3varchoices[0], TPC3_pisel_p->GetBinContent(1)-TPC3_pisel_p->GetBinContent(1) );
    TPC3_pisel_e_diff->Fill(tpc3varchoices[0], TPC3_pisel_e->GetBinContent(1)-TPC3_pisel_e->GetBinContent(1) );
    TPC3_psel_mu_diff->Fill(tpc3varchoices[0], TPC3_psel_mu->GetBinContent(1)-TPC3_psel_mu->GetBinContent(1) );
    TPC3_psel_pi_diff->Fill(tpc3varchoices[0], TPC3_psel_pi->GetBinContent(1)-TPC3_psel_pi->GetBinContent(1) );
    TPC3_psel_p_diff->Fill(tpc3varchoices[0], TPC3_psel_p->GetBinContent(1)-TPC3_psel_p->GetBinContent(1) );
    TPC3_psel_e_diff->Fill(tpc3varchoices[0], TPC3_psel_e->GetBinContent(1)-TPC3_psel_e->GetBinContent(1) );
    TPC3_esel_mu_diff->Fill(tpc3varchoices[0], TPC3_esel_mu->GetBinContent(1)-TPC3_esel_mu->GetBinContent(1) );
    TPC3_esel_pi_diff->Fill(tpc3varchoices[0], TPC3_esel_pi->GetBinContent(1)-TPC3_esel_pi->GetBinContent(1) );
    TPC3_esel_p_diff->Fill(tpc3varchoices[0], TPC3_esel_p->GetBinContent(1)-TPC3_esel_p->GetBinContent(1) );
    TPC3_esel_e_diff->Fill(tpc3varchoices[0], TPC3_esel_e->GetBinContent(1)-TPC3_esel_e->GetBinContent(1) );
    
    TPC3_musel_mu_diff->Fill(tpc3varchoices[1], TPC3_musel_mu->GetBinContent(2)-TPC3_musel_mu->GetBinContent(1) );
    TPC3_musel_pi_diff->Fill(tpc3varchoices[1], TPC3_musel_pi->GetBinContent(2)-TPC3_musel_pi->GetBinContent(1) ); 
    TPC3_musel_p_diff->Fill(tpc3varchoices[1], TPC3_musel_p->GetBinContent(2)-TPC3_musel_p->GetBinContent(1) );
    TPC3_musel_e_diff->Fill(tpc3varchoices[1], TPC3_musel_e->GetBinContent(2)-TPC3_musel_e->GetBinContent(1) );
    TPC3_pisel_mu_diff->Fill(tpc3varchoices[1], TPC3_pisel_mu->GetBinContent(2)-TPC3_pisel_mu->GetBinContent(1) );
    TPC3_pisel_pi_diff->Fill(tpc3varchoices[1], TPC3_pisel_pi->GetBinContent(2)-TPC3_pisel_pi->GetBinContent(1) );
    TPC3_pisel_p_diff->Fill(tpc3varchoices[1], TPC3_pisel_p->GetBinContent(2)-TPC3_pisel_p->GetBinContent(1) );
    TPC3_pisel_e_diff->Fill(tpc3varchoices[1], TPC3_pisel_e->GetBinContent(2)-TPC3_pisel_e->GetBinContent(1) );
    TPC3_psel_mu_diff->Fill(tpc3varchoices[1], TPC3_psel_mu->GetBinContent(2)-TPC3_psel_mu->GetBinContent(1) );
    TPC3_psel_pi_diff->Fill(tpc3varchoices[1], TPC3_psel_pi->GetBinContent(2)-TPC3_psel_pi->GetBinContent(1) );
    TPC3_psel_p_diff->Fill(tpc3varchoices[1], TPC3_psel_p->GetBinContent(2)-TPC3_psel_p->GetBinContent(1) );
    TPC3_psel_e_diff->Fill(tpc3varchoices[1], TPC3_psel_e->GetBinContent(2)-TPC3_psel_e->GetBinContent(1) );
    TPC3_esel_mu_diff->Fill(tpc3varchoices[1], TPC3_esel_mu->GetBinContent(2)-TPC3_esel_mu->GetBinContent(1) );
    TPC3_esel_pi_diff->Fill(tpc3varchoices[1], TPC3_esel_pi->GetBinContent(2)-TPC3_esel_pi->GetBinContent(1) );
    TPC3_esel_p_diff->Fill(tpc3varchoices[1], TPC3_esel_p->GetBinContent(2)-TPC3_esel_p->GetBinContent(1) );
    TPC3_esel_e_diff->Fill(tpc3varchoices[1], TPC3_esel_e->GetBinContent(2)-TPC3_esel_e->GetBinContent(1) );
    
    TPC3_musel_mu_diff->Fill(tpc3varchoices[2], TPC3_musel_mu->GetBinContent(3)-TPC3_musel_mu->GetBinContent(1) );
    TPC3_musel_pi_diff->Fill(tpc3varchoices[2], TPC3_musel_pi->GetBinContent(3)-TPC3_musel_pi->GetBinContent(1) ); 
    TPC3_musel_p_diff->Fill(tpc3varchoices[2], TPC3_musel_p->GetBinContent(3)-TPC3_musel_p->GetBinContent(1) );
    TPC3_musel_e_diff->Fill(tpc3varchoices[2], TPC3_musel_e->GetBinContent(3)-TPC3_musel_e->GetBinContent(1) );
    TPC3_pisel_mu_diff->Fill(tpc3varchoices[2], TPC3_pisel_mu->GetBinContent(3)-TPC3_pisel_mu->GetBinContent(1) );
    TPC3_pisel_pi_diff->Fill(tpc3varchoices[2], TPC3_pisel_pi->GetBinContent(3)-TPC3_pisel_pi->GetBinContent(1) );
    TPC3_pisel_p_diff->Fill(tpc3varchoices[2], TPC3_pisel_p->GetBinContent(3)-TPC3_pisel_p->GetBinContent(1) );
    TPC3_pisel_e_diff->Fill(tpc3varchoices[2], TPC3_pisel_e->GetBinContent(3)-TPC3_pisel_e->GetBinContent(1) );
    TPC3_psel_mu_diff->Fill(tpc3varchoices[2], TPC3_psel_mu->GetBinContent(3)-TPC3_psel_mu->GetBinContent(1) );
    TPC3_psel_pi_diff->Fill(tpc3varchoices[2], TPC3_psel_pi->GetBinContent(3)-TPC3_psel_pi->GetBinContent(1) );
    TPC3_psel_p_diff->Fill(tpc3varchoices[2], TPC3_psel_p->GetBinContent(3)-TPC3_psel_p->GetBinContent(1) );
    TPC3_psel_e_diff->Fill(tpc3varchoices[2], TPC3_psel_e->GetBinContent(3)-TPC3_psel_e->GetBinContent(1) );
    TPC3_esel_mu_diff->Fill(tpc3varchoices[2], TPC3_esel_mu->GetBinContent(3)-TPC3_esel_mu->GetBinContent(1) );
    TPC3_esel_pi_diff->Fill(tpc3varchoices[2], TPC3_esel_pi->GetBinContent(3)-TPC3_esel_pi->GetBinContent(1) );
    TPC3_esel_p_diff->Fill(tpc3varchoices[2], TPC3_esel_p->GetBinContent(3)-TPC3_esel_p->GetBinContent(1) );
    TPC3_esel_e_diff->Fill(tpc3varchoices[2], TPC3_esel_e->GetBinContent(3)-TPC3_esel_e->GetBinContent(1) );
    
    TPC3_musel_mu_diff->Fill(tpc3varchoices[3], TPC3_musel_mu->GetBinContent(4)-TPC3_musel_mu->GetBinContent(1) );
    TPC3_musel_pi_diff->Fill(tpc3varchoices[3], TPC3_musel_pi->GetBinContent(4)-TPC3_musel_pi->GetBinContent(1) ); 
    TPC3_musel_p_diff->Fill(tpc3varchoices[3], TPC3_musel_p->GetBinContent(4)-TPC3_musel_p->GetBinContent(1) );
    TPC3_musel_e_diff->Fill(tpc3varchoices[3], TPC3_musel_e->GetBinContent(4)-TPC3_musel_e->GetBinContent(1) );
    TPC3_pisel_mu_diff->Fill(tpc3varchoices[3], TPC3_pisel_mu->GetBinContent(4)-TPC3_pisel_mu->GetBinContent(1) );
    TPC3_pisel_pi_diff->Fill(tpc3varchoices[3], TPC3_pisel_pi->GetBinContent(4)-TPC3_pisel_pi->GetBinContent(1) );
    TPC3_pisel_p_diff->Fill(tpc3varchoices[3], TPC3_pisel_p->GetBinContent(4)-TPC3_pisel_p->GetBinContent(1) );
    TPC3_pisel_e_diff->Fill(tpc3varchoices[3], TPC3_pisel_e->GetBinContent(4)-TPC3_pisel_e->GetBinContent(1) );
    TPC3_psel_mu_diff->Fill(tpc3varchoices[3], TPC3_psel_mu->GetBinContent(4)-TPC3_psel_mu->GetBinContent(1) );
    TPC3_psel_pi_diff->Fill(tpc3varchoices[3], TPC3_psel_pi->GetBinContent(4)-TPC3_psel_pi->GetBinContent(1) );
    TPC3_psel_p_diff->Fill(tpc3varchoices[3], TPC3_psel_p->GetBinContent(4)-TPC3_psel_p->GetBinContent(1) );
    TPC3_psel_e_diff->Fill(tpc3varchoices[3], TPC3_psel_e->GetBinContent(4)-TPC3_psel_e->GetBinContent(1) );
    TPC3_esel_mu_diff->Fill(tpc3varchoices[3], TPC3_esel_mu->GetBinContent(4)-TPC3_esel_mu->GetBinContent(1) );
    TPC3_esel_pi_diff->Fill(tpc3varchoices[3], TPC3_esel_pi->GetBinContent(4)-TPC3_esel_pi->GetBinContent(1) );
    TPC3_esel_p_diff->Fill(tpc3varchoices[3], TPC3_esel_p->GetBinContent(4)-TPC3_esel_p->GetBinContent(1) );
    TPC3_esel_e_diff->Fill(tpc3varchoices[3], TPC3_esel_e->GetBinContent(4)-TPC3_esel_e->GetBinContent(1) );
    
    //TCanvas* canvas_TPC3_choices_diff = new TCanvas("canvas_TPC3_choices_diff","",200,10,1000,800);
    canvas_TPC3_choices_sig->cd(2);
    TPC3_musel_mu_diff->GetYaxis()->SetRangeUser(-0.15, 0.02);
    TPC3_musel_mu_diff->GetXaxis()->SetRangeUser(1, 4);
    TPC3_musel_mu_diff->GetYaxis()->SetTitle("Difference in efficiency");
    TPC3_musel_mu_diff->GetYaxis()->SetLabelSize(0.025);
    TPC3_musel_mu_diff->GetYaxis()->SetTitleSize(0.025);
    TPC3_musel_mu_diff->GetYaxis()->SetTitleOffset(1.6);
    
    TPC3_musel_mu_diff->Draw("B");
    TPC3_pisel_pi_diff->Draw("B same");
    TPC3_psel_p_diff->Draw("B same");
    TPC3_esel_e_diff->Draw("B same");
    
    //canvas_TPC3_choices_diff->BuildLegend();
    
    //TCanvas* canvas_TPC3_choices_bkg_diff = new TCanvas("canvas_TPC3_choices_bkg_diff","",200,10,1000,800);
    canvas_TPC3_choices_bkg->cd(2);
    TPC3_pisel_mu_diff->GetYaxis()->SetRangeUser(-0.02, 0.07);
    TPC3_pisel_mu_diff->GetXaxis()->SetRangeUser(1, 4);
    TPC3_pisel_mu_diff->GetYaxis()->SetTitle("Difference in efficiency");
    TPC3_pisel_mu_diff->GetYaxis()->SetLabelSize(0.025);
    TPC3_pisel_mu_diff->GetYaxis()->SetTitleSize(0.025);
    TPC3_pisel_mu_diff->GetYaxis()->SetTitleOffset(1.5);
    
    TPC3_pisel_mu_diff->Draw("B");
    TPC3_psel_mu_diff->Draw("B same");
    TPC3_esel_mu_diff->Draw("B same");
    TPC3_musel_pi_diff->Draw("B same");
    TPC3_psel_pi_diff->Draw("B same");
    TPC3_esel_pi_diff->Draw("B same");
    TPC3_musel_p_diff->Draw("B same");
    TPC3_pisel_p_diff->Draw("B same");
    TPC3_esel_p_diff->Draw("B same");
    TPC3_musel_e_diff->Draw("B same");
    TPC3_pisel_e_diff->Draw("B same");
    TPC3_psel_e_diff->Draw("B same");
    
    //canvas_TPC3_choices_bkg_diff->BuildLegend();

}
