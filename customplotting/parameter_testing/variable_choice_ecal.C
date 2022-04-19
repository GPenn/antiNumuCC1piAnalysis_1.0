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
    
    // =============== ECal variable choice ===============
    
    const char *ecalvarchoices[3] = {"ECal high-level", "ECal low-level"};
    
    TH1F* ECal_musel_mu = new TH1F("ECal_musel_mu","#mu^{+} identified as #mu^{+}",3,0,3);
    TH1F* ECal_musel_pi = new TH1F("ECal_musel_pi","#pi^{+} identified as #mu^{+}",3,0,3);
    TH1F* ECal_musel_p = new TH1F("ECal_musel_p","p identified as #mu^{+}",3,0,3);
    TH1F* ECal_musel_e = new TH1F("ECal_musel_e","e^{+} identified as #mu^{+}",3,0,3);
    TH1F* ECal_pisel_mu = new TH1F("ECal_pisel_mu","#mu^{+} identified as #pi^{+}",3,0,3);
    TH1F* ECal_pisel_pi = new TH1F("ECal_pisel_pi","#pi^{+} identified as #pi^{+}",3,0,3);
    TH1F* ECal_pisel_p = new TH1F("ECal_pisel_p","p identified as #pi^{+}",3,0,3);
    TH1F* ECal_pisel_e = new TH1F("ECal_pisel_e","e^{+} identified as #pi^{+}",3,0,3);
    TH1F* ECal_psel_mu = new TH1F("ECal_psel_mu","#mu^{+} identified as p",3,0,3);
    TH1F* ECal_psel_pi = new TH1F("ECal_psel_pi","#pi^{+} identified as p",3,0,3);
    TH1F* ECal_psel_p = new TH1F("ECal_psel_p","p identified as p",3,0,3);
    TH1F* ECal_psel_e = new TH1F("ECal_psel_e","e^{+} identified as p",3,0,3);
    TH1F* ECal_esel_mu = new TH1F("ECal_esel_mu","#mu^{+} identified as e^{+}",3,0,3);
    TH1F* ECal_esel_pi = new TH1F("ECal_esel_pi","#pi^{+} identified as e^{+}",3,0,3);
    TH1F* ECal_esel_p = new TH1F("ECal_esel_p","p identified as e^{+}",3,0,3);
    TH1F* ECal_esel_e = new TH1F("ECal_esel_e","e^{+} identified as e^{+}",3,0,3);
    
    TH1F* ECal_musel_mu_diff = new TH1F("ECal_musel_mu_diff","#mu^{+} identified as #mu^{+}",3,0,3);
    TH1F* ECal_musel_pi_diff = new TH1F("ECal_musel_pi_diff","#pi^{+} identified as #mu^{+}",3,0,3);
    TH1F* ECal_musel_p_diff = new TH1F("ECal_musel_p_diff","p identified as #mu^{+}",3,0,3);
    TH1F* ECal_musel_e_diff = new TH1F("ECal_musel_e_diff","e^{+} identified as #mu^{+}",3,0,3);
    TH1F* ECal_pisel_mu_diff = new TH1F("ECal_pisel_mu_diff","#mu^{+} identified as #pi^{+}",3,0,3);
    TH1F* ECal_pisel_pi_diff = new TH1F("ECal_pisel_pi_diff","#pi^{+} identified as #pi^{+}",3,0,3);
    TH1F* ECal_pisel_p_diff = new TH1F("ECal_pisel_p_diff","p identified as #pi^{+}",3,0,3);
    TH1F* ECal_pisel_e_diff = new TH1F("ECal_pisel_e_diff","e^{+} identified as #pi^{+}",3,0,3);
    TH1F* ECal_psel_mu_diff = new TH1F("ECal_psel_mu_diff","#mu^{+} identified as p",3,0,3);
    TH1F* ECal_psel_pi_diff = new TH1F("ECal_psel_pi_diff","#pi^{+} identified as p",3,0,3);
    TH1F* ECal_psel_p_diff = new TH1F("ECal_psel_p_diff","p identified as p",3,0,3);
    TH1F* ECal_psel_e_diff = new TH1F("ECal_psel_e_diff","e^{+} identified as p",3,0,3);
    TH1F* ECal_esel_mu_diff = new TH1F("ECal_esel_mu_diff","#mu^{+} identified as e^{+}",3,0,3);
    TH1F* ECal_esel_pi_diff = new TH1F("ECal_esel_pi_diff","#pi^{+} identified as e^{+}",3,0,3);
    TH1F* ECal_esel_p_diff = new TH1F("ECal_esel_p_diff","p identified as e^{+}",3,0,3);
    TH1F* ECal_esel_e_diff = new TH1F("ECal_esel_e_diff","e^{+} identified as e^{+}",3,0,3);
    
    ECal_musel_mu->SetFillColor( kBlue);
    ECal_musel_pi->SetFillColor( kRed); //ECal_musel_pi->SetFillStyle(3305);
    ECal_musel_p->SetFillColor( kGreen); //ECal_musel_p->SetFillStyle(3305);
    ECal_musel_e->SetFillColor( kMagenta); //ECal_musel_e->SetFillStyle(3305);
    ECal_pisel_mu->SetFillColor( kBlue); //ECal_pisel_mu->SetFillStyle(3345);
    ECal_pisel_pi->SetFillColor( kRed); 
    ECal_pisel_p->SetFillColor( kGreen+1); //ECal_pisel_p->SetFillStyle(3345);
    ECal_pisel_e->SetFillColor( kMagenta+1); //ECal_pisel_e->SetFillStyle(3345);
    ECal_psel_mu->SetFillColor( kBlue+1); //ECal_psel_mu->SetFillStyle(3354);
    ECal_psel_pi->SetFillColor( kRed+1); //ECal_psel_pi->SetFillStyle(3354);
    ECal_psel_p->SetFillColor( kGreen); 
    ECal_psel_e->SetFillColor( kMagenta+2); //ECal_psel_e->SetFillStyle(3354);
    ECal_esel_mu->SetFillColor( kBlue+2); //ECal_esel_mu->SetFillStyle(3144);
    ECal_esel_pi->SetFillColor( kRed+2); //ECal_esel_pi->SetFillStyle(3144);
    ECal_esel_p->SetFillColor( kGreen+2); //ECal_esel_p->SetFillStyle(3144);
    ECal_esel_e->SetFillColor( kMagenta);
    
    ECal_musel_mu_diff->SetFillColor( kBlue);
    ECal_musel_pi_diff->SetFillColor( kRed); //ECal_musel_pi_diff->SetFillStyle(3305);
    ECal_musel_p_diff->SetFillColor( kGreen); //ECal_musel_p_diff->SetFillStyle(3305);
    ECal_musel_e_diff->SetFillColor( kMagenta); //ECal_musel_e_diff->SetFillStyle(3305);
    ECal_pisel_mu_diff->SetFillColor( kBlue); //ECal_pisel_mu_diff->SetFillStyle(3345);
    ECal_pisel_pi_diff->SetFillColor( kRed);
    ECal_pisel_p_diff->SetFillColor( kGreen+1); //ECal_pisel_p_diff->SetFillStyle(3345);
    ECal_pisel_e_diff->SetFillColor( kMagenta+1); //ECal_pisel_e_diff->SetFillStyle(3345);
    ECal_psel_mu_diff->SetFillColor( kBlue+1); //ECal_psel_mu_diff->SetFillStyle(3354);
    ECal_psel_pi_diff->SetFillColor( kRed+1); //ECal_psel_pi_diff->SetFillStyle(3354);
    ECal_psel_p_diff->SetFillColor( kGreen);
    ECal_psel_e_diff->SetFillColor( kMagenta+2); //ECal_psel_e_diff->SetFillStyle(3354);
    ECal_esel_mu_diff->SetFillColor( kBlue+2); //ECal_esel_mu_diff->SetFillStyle(3144);
    ECal_esel_pi_diff->SetFillColor( kRed+2); //ECal_esel_pi->SetFillStyle(3144);
    ECal_esel_p_diff->SetFillColor( kGreen+2); //ECal_esel_p->SetFillStyle(3144);
    ECal_esel_e_diff->SetFillColor( kMagenta);
    
    /*ECal_musel_mu->SetBarOffset(bar_offset + (bar_width*0)); ECal_musel_mu->SetBarWidth(bar_width);
    ECal_musel_pi->SetBarOffset(bar_offset + (bar_width*1)); ECal_musel_pi->SetBarWidth(bar_width);
    ECal_musel_p->SetBarOffset(bar_offset + (bar_width*2)); ECal_musel_p->SetBarWidth(bar_width);
    ECal_musel_e->SetBarOffset(bar_offset + (bar_width*3)); ECal_musel_e->SetBarWidth(bar_width);
    ECal_pisel_mu->SetBarOffset(bar_offset + (bar_width*4)); ECal_pisel_mu->SetBarWidth(bar_width);
    ECal_pisel_pi->SetBarOffset(bar_offset + (bar_width*5)); ECal_pisel_pi->SetBarWidth(bar_width);
    ECal_pisel_p->SetBarOffset(bar_offset + (bar_width*6)); ECal_pisel_p->SetBarWidth(bar_width);
    ECal_pisel_e->SetBarOffset(bar_offset + (bar_width*7)); ECal_pisel_e->SetBarWidth(bar_width);
    ECal_psel_mu->SetBarOffset(bar_offset + (bar_width*8)); ECal_psel_mu->SetBarWidth(bar_width);
    ECal_psel_pi->SetBarOffset(bar_offset + (bar_width*9)); ECal_psel_pi->SetBarWidth(bar_width);
    ECal_psel_p->SetBarOffset(bar_offset + (bar_width*10)); ECal_psel_p->SetBarWidth(bar_width);
    ECal_psel_e->SetBarOffset(bar_offset + (bar_width*11)); ECal_psel_e->SetBarWidth(bar_width);
    ECal_esel_mu->SetBarOffset(bar_offset + (bar_width*12)); ECal_esel_mu->SetBarWidth(bar_width);
    ECal_esel_pi->SetBarOffset(bar_offset + (bar_width*13)); ECal_esel_pi->SetBarWidth(bar_width);
    ECal_esel_p->SetBarOffset(bar_offset + (bar_width*14)); ECal_esel_p->SetBarWidth(bar_width);
    ECal_esel_e->SetBarOffset(bar_offset + (bar_width*15)); ECal_esel_e->SetBarWidth(bar_width);*/
    
    ECal_musel_mu->SetBarOffset(bar_offset_sig + (bar_width_sig*0)); ECal_musel_mu->SetBarWidth(bar_width_sig);
    ECal_pisel_pi->SetBarOffset(bar_offset_sig + (bar_width_sig*1)); ECal_pisel_pi->SetBarWidth(bar_width_sig);
    ECal_psel_p->SetBarOffset(bar_offset_sig + (bar_width_sig*2)); ECal_psel_p->SetBarWidth(bar_width_sig);
    ECal_esel_e->SetBarOffset(bar_offset_sig + (bar_width_sig*3)); ECal_esel_e->SetBarWidth(bar_width_sig);
    
    ECal_musel_mu_diff->SetBarOffset(bar_offset_sig + (bar_width_sig*0)); ECal_musel_mu_diff->SetBarWidth(bar_width_sig);
    ECal_pisel_pi_diff->SetBarOffset(bar_offset_sig + (bar_width_sig*1)); ECal_pisel_pi_diff->SetBarWidth(bar_width_sig);
    ECal_psel_p_diff->SetBarOffset(bar_offset_sig + (bar_width_sig*2)); ECal_psel_p_diff->SetBarWidth(bar_width_sig);
    ECal_esel_e_diff->SetBarOffset(bar_offset_sig + (bar_width_sig*3)); ECal_esel_e_diff->SetBarWidth(bar_width_sig);
    
    ECal_pisel_mu->SetBarOffset(bar_offset_bkg + (bar_width_bkg*0)); ECal_pisel_mu->SetBarWidth(bar_width_bkg);
    ECal_psel_mu->SetBarOffset(bar_offset_bkg + (bar_width_bkg*1)); ECal_psel_mu->SetBarWidth(bar_width_bkg);
    ECal_esel_mu->SetBarOffset(bar_offset_bkg + (bar_width_bkg*2)); ECal_esel_mu->SetBarWidth(bar_width_bkg);
    ECal_musel_pi->SetBarOffset(bar_offset_bkg + (bar_width_bkg*3)); ECal_musel_pi->SetBarWidth(bar_width_bkg);
    ECal_psel_pi->SetBarOffset(bar_offset_bkg + (bar_width_bkg*4)); ECal_psel_pi->SetBarWidth(bar_width_bkg);
    ECal_esel_pi->SetBarOffset(bar_offset_bkg + (bar_width_bkg*5)); ECal_esel_pi->SetBarWidth(bar_width_bkg);
    ECal_musel_p->SetBarOffset(bar_offset_bkg + (bar_width_bkg*6)); ECal_musel_p->SetBarWidth(bar_width_bkg);
    ECal_pisel_p->SetBarOffset(bar_offset_bkg + (bar_width_bkg*7)); ECal_pisel_p->SetBarWidth(bar_width_bkg);
    ECal_esel_p->SetBarOffset(bar_offset_bkg + (bar_width_bkg*8)); ECal_esel_p->SetBarWidth(bar_width_bkg);
    ECal_musel_e->SetBarOffset(bar_offset_bkg + (bar_width_bkg*9)); ECal_musel_e->SetBarWidth(bar_width_bkg);
    ECal_pisel_e->SetBarOffset(bar_offset_bkg + (bar_width_bkg*10)); ECal_pisel_e->SetBarWidth(bar_width_bkg);
    ECal_psel_e->SetBarOffset(bar_offset_bkg + (bar_width_bkg*11)); ECal_psel_e->SetBarWidth(bar_width_bkg);
    
    ECal_pisel_mu_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*0)); ECal_pisel_mu_diff->SetBarWidth(bar_width_bkg);
    ECal_psel_mu_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*1)); ECal_psel_mu_diff->SetBarWidth(bar_width_bkg);
    ECal_esel_mu_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*2)); ECal_esel_mu_diff->SetBarWidth(bar_width_bkg);
    ECal_musel_pi_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*3)); ECal_musel_pi_diff->SetBarWidth(bar_width_bkg);
    ECal_psel_pi_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*4)); ECal_psel_pi_diff->SetBarWidth(bar_width_bkg);
    ECal_esel_pi_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*5)); ECal_esel_pi_diff->SetBarWidth(bar_width_bkg);
    ECal_musel_p_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*6)); ECal_musel_p_diff->SetBarWidth(bar_width_bkg);
    ECal_pisel_p_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*7)); ECal_pisel_p_diff->SetBarWidth(bar_width_bkg);
    ECal_esel_p_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*8)); ECal_esel_p_diff->SetBarWidth(bar_width_bkg);
    ECal_musel_e_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*9)); ECal_musel_e_diff->SetBarWidth(bar_width_bkg);
    ECal_pisel_e_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*10)); ECal_pisel_e_diff->SetBarWidth(bar_width_bkg);
    ECal_psel_e_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*11)); ECal_psel_e_diff->SetBarWidth(bar_width_bkg);
    
    ECal_musel_mu->Fill(ecalvarchoices[0],0.93881);
    ECal_musel_pi->Fill(ecalvarchoices[0],0.342958); 
    ECal_musel_p->Fill(ecalvarchoices[0],0.0251867);
    ECal_musel_e->Fill(ecalvarchoices[0],0.01268);
    ECal_pisel_mu->Fill(ecalvarchoices[0],0.0522809);
    ECal_pisel_pi->Fill(ecalvarchoices[0],0.621063);
    ECal_pisel_p->Fill(ecalvarchoices[0],0.0415053);
    ECal_pisel_e->Fill(ecalvarchoices[0],0.0136154);
    ECal_psel_mu->Fill(ecalvarchoices[0],0.00586693);
    ECal_psel_pi->Fill(ecalvarchoices[0],0.0232439);
    ECal_psel_p->Fill(ecalvarchoices[0],0.881275);
    ECal_psel_e->Fill(ecalvarchoices[0],0.0324425);
    ECal_esel_mu->Fill(ecalvarchoices[0],0.00304211);
    ECal_esel_pi->Fill(ecalvarchoices[0],0.0127345);
    ECal_esel_p->Fill(ecalvarchoices[0],0.0520329);
    ECal_esel_e->Fill(ecalvarchoices[0],0.941262);
    
    ECal_musel_mu->Fill(ecalvarchoices[1],0.937883);
    ECal_musel_pi->Fill(ecalvarchoices[1],0.344191); 
    ECal_musel_p->Fill(ecalvarchoices[1],0.0454985);
    ECal_musel_e->Fill(ecalvarchoices[1],0.0396733);
    ECal_pisel_mu->Fill(ecalvarchoices[1],0.0581912);
    ECal_pisel_pi->Fill(ecalvarchoices[1],0.639788);
    ECal_pisel_p->Fill(ecalvarchoices[1],0.0703568);
    ECal_pisel_e->Fill(ecalvarchoices[1],0.273883);
    ECal_psel_mu->Fill(ecalvarchoices[1],0.00359259);
    ECal_psel_pi->Fill(ecalvarchoices[1],0.0123579);
    ECal_psel_p->Fill(ecalvarchoices[1],0.872182);
    ECal_psel_e->Fill(ecalvarchoices[1],0.134031);
    ECal_esel_mu->Fill(ecalvarchoices[1],0.000333184);
    ECal_esel_pi->Fill(ecalvarchoices[1],0.00366288);
    ECal_esel_p->Fill(ecalvarchoices[1],0.0119624);
    ECal_esel_e->Fill(ecalvarchoices[1],0.552413);
    
    //TCanvas* canvas_ECal_choices = new TCanvas("canvas_ECal_choices","",200,10,1000,800);
    TCanvas* canvas_ECal_choices_sig = new TCanvas("canvas_ECal_choices_sig","",200,10,2000,800);
    canvas_ECal_choices_sig->Divide(2,1,0.005,0.005);
    canvas_ECal_choices_sig->cd(1);
    ECal_musel_mu->GetYaxis()->SetRangeUser(0, 1);
    ECal_musel_mu->GetXaxis()->SetRangeUser(0, 3);
    ECal_musel_mu->GetYaxis()->SetTitle("Efficiency");
    ECal_musel_mu->GetYaxis()->SetLabelSize(0.025);
    ECal_musel_mu->GetYaxis()->SetTitleSize(0.025);
    ECal_musel_mu->GetYaxis()->SetTitleOffset(1.2);
    
    ECal_musel_mu->Draw("B");
    ECal_pisel_pi->Draw("B same");
    ECal_psel_p->Draw("B same");
    ECal_esel_e->Draw("B same");
    
    //canvas_ECal_choices->BuildLegend();
    //canvas_ECal_choices_sig->cd(1)->BuildLegend();
    TLegend *legend_sig = new TLegend(0.55,0.65,0.76,0.82);
    legend_sig->AddEntry(ECal_musel_mu,"#mu^{+} identified as #mu^{+}","f");
    legend_sig->AddEntry(ECal_pisel_pi,"#pi^{+} identified as #pi^{+}","f");
    legend_sig->AddEntry(ECal_psel_p,"p identified as p","f");
    legend_sig->AddEntry(ECal_esel_e,"e^{+} identified as e^{+}","f");
    legend_sig->Draw();
    
    //TCanvas* canvas_ECal_choices_bkg = new TCanvas("canvas_ECal_choices_bkg","",200,10,1000,800);
    TCanvas* canvas_ECal_choices_bkg = new TCanvas("canvas_ECal_choices_bkg","",200,10,2000,800);
    canvas_ECal_choices_bkg->Divide(2,1,0.005,0.005);
    canvas_ECal_choices_bkg->cd(1);
    ECal_pisel_mu->GetYaxis()->SetRangeUser(0, 0.5);
    ECal_pisel_mu->GetXaxis()->SetRangeUser(0, 3);
    ECal_pisel_mu->GetYaxis()->SetTitle("Efficiency");
    ECal_pisel_mu->GetYaxis()->SetLabelSize(0.025);
    ECal_pisel_mu->GetYaxis()->SetTitleSize(0.025);
    ECal_pisel_mu->GetYaxis()->SetTitleOffset(1.4);
    
    ECal_pisel_mu->Draw("B");
    ECal_psel_mu->Draw("B same");
    ECal_esel_mu->Draw("B same");
    ECal_musel_pi->Draw("B same");
    ECal_psel_pi->Draw("B same");
    ECal_esel_pi->Draw("B same");
    ECal_musel_p->Draw("B same");
    ECal_pisel_p->Draw("B same");
    ECal_esel_p->Draw("B same");
    ECal_musel_e->Draw("B same");
    ECal_pisel_e->Draw("B same");
    ECal_psel_e->Draw("B same");

    //canvas_ECal_choices_bkg->BuildLegend();
    //canvas_ECal_choices_bkg->cd(1)->BuildLegend();
    TLegend *legend_bkg = new TLegend(0.55,0.65,0.76,0.82);
    legend_bkg->AddEntry(ECal_pisel_mu,"#mu^{+} identified as #pi^{+}","f");
    legend_bkg->AddEntry(ECal_psel_mu,"#mu^{+} identified as p","f");
    legend_bkg->AddEntry(ECal_esel_mu,"#mu^{+} identified as e^{+}","f");
    legend_bkg->AddEntry(ECal_musel_pi,"#pi^{+} identified as #mu^{+}","f");
    legend_bkg->AddEntry(ECal_psel_pi,"#pi^{+} identified as p","f");
    legend_bkg->AddEntry(ECal_esel_pi,"#pi^{+} identified as e^{+}","f");
    legend_bkg->AddEntry(ECal_musel_p,"p identified as #mu^{+}","f");
    legend_bkg->AddEntry(ECal_pisel_p,"p identified as #pi^{+}","f");
    legend_bkg->AddEntry(ECal_esel_p,"p identified as e^{+}","f");
    legend_bkg->AddEntry(ECal_musel_e,"e^{+} identified as #mu^{+}","f");
    legend_bkg->AddEntry(ECal_pisel_e,"e^{+} identified as #pi^{+}","f");
    legend_bkg->AddEntry(ECal_psel_e,"e^{+} identified as p","f");
    legend_bkg->Draw();
    
    ECal_musel_mu_diff->Fill(ecalvarchoices[0], ECal_musel_mu->GetBinContent(1)-ECal_musel_mu->GetBinContent(2) );
    ECal_musel_pi_diff->Fill(ecalvarchoices[0], ECal_musel_pi->GetBinContent(1)-ECal_musel_pi->GetBinContent(2) ); 
    ECal_musel_p_diff->Fill(ecalvarchoices[0], ECal_musel_p->GetBinContent(1)-ECal_musel_p->GetBinContent(2) );
    ECal_musel_e_diff->Fill(ecalvarchoices[0], ECal_musel_e->GetBinContent(1)-ECal_musel_e->GetBinContent(2) );
    ECal_pisel_mu_diff->Fill(ecalvarchoices[0], ECal_pisel_mu->GetBinContent(1)-ECal_pisel_mu->GetBinContent(2) );
    ECal_pisel_pi_diff->Fill(ecalvarchoices[0], ECal_pisel_pi->GetBinContent(1)-ECal_pisel_pi->GetBinContent(2) );
    ECal_pisel_p_diff->Fill(ecalvarchoices[0], ECal_pisel_p->GetBinContent(1)-ECal_pisel_p->GetBinContent(2) );
    ECal_pisel_e_diff->Fill(ecalvarchoices[0], ECal_pisel_e->GetBinContent(1)-ECal_pisel_e->GetBinContent(2) );
    ECal_psel_mu_diff->Fill(ecalvarchoices[0], ECal_psel_mu->GetBinContent(1)-ECal_psel_mu->GetBinContent(2) );
    ECal_psel_pi_diff->Fill(ecalvarchoices[0], ECal_psel_pi->GetBinContent(1)-ECal_psel_pi->GetBinContent(2) );
    ECal_psel_p_diff->Fill(ecalvarchoices[0], ECal_psel_p->GetBinContent(1)-ECal_psel_p->GetBinContent(2) );
    ECal_psel_e_diff->Fill(ecalvarchoices[0], ECal_psel_e->GetBinContent(1)-ECal_psel_e->GetBinContent(2) );
    ECal_esel_mu_diff->Fill(ecalvarchoices[0], ECal_esel_mu->GetBinContent(1)-ECal_esel_mu->GetBinContent(2) );
    ECal_esel_pi_diff->Fill(ecalvarchoices[0], ECal_esel_pi->GetBinContent(1)-ECal_esel_pi->GetBinContent(2) );
    ECal_esel_p_diff->Fill(ecalvarchoices[0], ECal_esel_p->GetBinContent(1)-ECal_esel_p->GetBinContent(2) );
    ECal_esel_e_diff->Fill(ecalvarchoices[0], ECal_esel_e->GetBinContent(1)-ECal_esel_e->GetBinContent(2) );
    
    ECal_musel_mu_diff->Fill(ecalvarchoices[1], ECal_musel_mu->GetBinContent(2)-ECal_musel_mu->GetBinContent(2) );
    ECal_musel_pi_diff->Fill(ecalvarchoices[1], ECal_musel_pi->GetBinContent(2)-ECal_musel_pi->GetBinContent(2) ); 
    ECal_musel_p_diff->Fill(ecalvarchoices[1], ECal_musel_p->GetBinContent(2)-ECal_musel_p->GetBinContent(2) );
    ECal_musel_e_diff->Fill(ecalvarchoices[1], ECal_musel_e->GetBinContent(2)-ECal_musel_e->GetBinContent(2) );
    ECal_pisel_mu_diff->Fill(ecalvarchoices[1], ECal_pisel_mu->GetBinContent(2)-ECal_pisel_mu->GetBinContent(2) );
    ECal_pisel_pi_diff->Fill(ecalvarchoices[1], ECal_pisel_pi->GetBinContent(2)-ECal_pisel_pi->GetBinContent(2) );
    ECal_pisel_p_diff->Fill(ecalvarchoices[1], ECal_pisel_p->GetBinContent(2)-ECal_pisel_p->GetBinContent(2) );
    ECal_pisel_e_diff->Fill(ecalvarchoices[1], ECal_pisel_e->GetBinContent(2)-ECal_pisel_e->GetBinContent(2) );
    ECal_psel_mu_diff->Fill(ecalvarchoices[1], ECal_psel_mu->GetBinContent(2)-ECal_psel_mu->GetBinContent(2) );
    ECal_psel_pi_diff->Fill(ecalvarchoices[1], ECal_psel_pi->GetBinContent(2)-ECal_psel_pi->GetBinContent(2) );
    ECal_psel_p_diff->Fill(ecalvarchoices[1], ECal_psel_p->GetBinContent(2)-ECal_psel_p->GetBinContent(2) );
    ECal_psel_e_diff->Fill(ecalvarchoices[1], ECal_psel_e->GetBinContent(2)-ECal_psel_e->GetBinContent(2) );
    ECal_esel_mu_diff->Fill(ecalvarchoices[1], ECal_esel_mu->GetBinContent(2)-ECal_esel_mu->GetBinContent(2) );
    ECal_esel_pi_diff->Fill(ecalvarchoices[1], ECal_esel_pi->GetBinContent(2)-ECal_esel_pi->GetBinContent(2) );
    ECal_esel_p_diff->Fill(ecalvarchoices[1], ECal_esel_p->GetBinContent(2)-ECal_esel_p->GetBinContent(2) );
    ECal_esel_e_diff->Fill(ecalvarchoices[1], ECal_esel_e->GetBinContent(2)-ECal_esel_e->GetBinContent(2) );
    
    //TCanvas* canvas_ECal_choices_diff = new TCanvas("canvas_ECal_choices_diff","",200,10,1000,800);
    canvas_ECal_choices_sig->cd(2);
    ECal_musel_mu_diff->GetYaxis()->SetRangeUser(-1.0, 1.0);
    ECal_musel_mu_diff->GetXaxis()->SetRangeUser(0, 1);
    ECal_musel_mu_diff->GetYaxis()->SetTitle("Difference in efficiency");
    ECal_musel_mu_diff->GetYaxis()->SetLabelSize(0.025);
    ECal_musel_mu_diff->GetYaxis()->SetTitleSize(0.025);
    ECal_musel_mu_diff->GetYaxis()->SetTitleOffset(1.6);
    
    ECal_musel_mu_diff->Draw("B");
    ECal_pisel_pi_diff->Draw("B same");
    ECal_psel_p_diff->Draw("B same");
    ECal_esel_e_diff->Draw("B same");
    
    //canvas_ECal_choices_diff->BuildLegend();
    
    //TCanvas* canvas_ECal_choices_bkg_diff = new TCanvas("canvas_ECal_choices_bkg_diff","",200,10,1000,800);
    canvas_ECal_choices_bkg->cd(2);
    ECal_pisel_mu_diff->GetYaxis()->SetRangeUser(-1.0, 1.0);
    ECal_pisel_mu_diff->GetXaxis()->SetRangeUser(0, 1);
    ECal_pisel_mu_diff->GetYaxis()->SetTitle("Difference in efficiency");
    ECal_pisel_mu_diff->GetYaxis()->SetLabelSize(0.025);
    ECal_pisel_mu_diff->GetYaxis()->SetTitleSize(0.025);
    ECal_pisel_mu_diff->GetYaxis()->SetTitleOffset(1.5);
    
    ECal_pisel_mu_diff->Draw("B");
    ECal_psel_mu_diff->Draw("B same");
    ECal_esel_mu_diff->Draw("B same");
    ECal_musel_pi_diff->Draw("B same");
    ECal_psel_pi_diff->Draw("B same");
    ECal_esel_pi_diff->Draw("B same");
    ECal_musel_p_diff->Draw("B same");
    ECal_pisel_p_diff->Draw("B same");
    ECal_esel_p_diff->Draw("B same");
    ECal_musel_e_diff->Draw("B same");
    ECal_pisel_e_diff->Draw("B same");
    ECal_psel_e_diff->Draw("B same");
    
    //canvas_ECal_choices_bkg_diff->BuildLegend();

}
