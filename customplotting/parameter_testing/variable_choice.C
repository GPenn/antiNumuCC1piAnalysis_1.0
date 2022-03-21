{
    gStyle->SetTitleYOffset(1.7);
    gStyle->SetOptStat(0);
    //gStyle->SetLabelSize(0.025);
    //gStyle->SetTitleSize(0.025);
    
    Float_t refvalue_cc1pi_mu, refvalue_cc1pi_pi, refvalue_pg_mu, refvalue_pg_pi, refvalue_pg_p, refvalue_pg_e;
    
    Float_t bar_width = 0.1;
    Float_t bar_offset = 0.5 - bar_width*3;
    
    // =============== TPC2 variable choice ===============
    
    const char *tpc2varchoices[3] = {"TPC2 dE/dx","TPC2 pulls","TPC2 likelihoods"};
    
    refvalue_pg_mu = 210.16;
    TH1F* TPC2_pg_mu = new TH1F("TPC2_pg_mu","Particle gun selection #mu^{+}",3,0,3);
    TPC2_pg_mu->Fill(tpc2varchoices[0],210.16/refvalue_pg_mu);
    TPC2_pg_mu->Fill(tpc2varchoices[1],213.597/refvalue_pg_mu);
    TPC2_pg_mu->Fill(tpc2varchoices[2],214.249/refvalue_pg_mu);
    TPC2_pg_mu->SetLineColor( kBlue); TPC2_pg_mu->SetFillColor( kBlue);
    TPC2_pg_mu->SetBarWidth(bar_width);
    TPC2_pg_mu->SetBarOffset(bar_offset + (bar_width*0));
    
    refvalue_pg_pi = 157.581;
    TH1F* TPC2_pg_pi = new TH1F("TPC2_pg_pi","Particle gun selection #pi^{+}",3,0,3);
    TPC2_pg_pi->Fill(tpc2varchoices[0],157.581/refvalue_pg_pi);
    TPC2_pg_pi->Fill(tpc2varchoices[1],160.974/refvalue_pg_pi);
    TPC2_pg_pi->Fill(tpc2varchoices[2],161.309/refvalue_pg_pi);
    TPC2_pg_pi->SetLineColor( kRed); TPC2_pg_pi->SetFillColor( kRed);
    TPC2_pg_pi->SetBarWidth(bar_width);
    TPC2_pg_pi->SetBarOffset(bar_offset + (bar_width*1));
    
    refvalue_pg_p = 187.364;
    TH1F* TPC2_pg_p = new TH1F("TPC2_pg_p","Particle gun selection p",3,0,3);
    TPC2_pg_p->Fill(tpc2varchoices[0],187.364/refvalue_pg_p);
    TPC2_pg_p->Fill(tpc2varchoices[1],193.76/refvalue_pg_p);
    TPC2_pg_p->Fill(tpc2varchoices[2],195.318/refvalue_pg_p);
    TPC2_pg_p->SetLineColor( kGreen); TPC2_pg_p->SetFillColor( kGreen);
    TPC2_pg_p->SetBarWidth(bar_width);
    TPC2_pg_p->SetBarOffset(bar_offset + (bar_width*2));
    
    refvalue_pg_e = 223.002;
    TH1F* TPC2_pg_e = new TH1F("TPC2_pg_e","Particle gun selection e^{+}",3,0,3);
    TPC2_pg_e->Fill(tpc2varchoices[0],223.002/refvalue_pg_e);
    TPC2_pg_e->Fill(tpc2varchoices[1],227.148/refvalue_pg_e);
    TPC2_pg_e->Fill(tpc2varchoices[2],226.972/refvalue_pg_e);
    TPC2_pg_e->SetLineColor( kMagenta); TPC2_pg_e->SetFillColor( kMagenta);
    TPC2_pg_e->SetBarWidth(bar_width);
    TPC2_pg_e->SetBarOffset(bar_offset + (bar_width*3));
    
    refvalue_cc1pi_mu = 33.3699;
    TH1F* TPC2_cc1pi_mu = new TH1F("TPC2_cc1pi_mu","CC1pi selection #mu^{+}",3,0,3);
    TPC2_cc1pi_mu->Fill(tpc2varchoices[0],33.3699/refvalue_cc1pi_mu);
    TPC2_cc1pi_mu->Fill(tpc2varchoices[1],33.7904/refvalue_cc1pi_mu);
    TPC2_cc1pi_mu->Fill(tpc2varchoices[2],33.9678/refvalue_cc1pi_mu);
    TPC2_cc1pi_mu->SetLineColor( kBlue + 2); TPC2_cc1pi_mu->SetFillColor( kBlue + 2);
    TPC2_cc1pi_mu->SetBarWidth(bar_width);
    TPC2_cc1pi_mu->SetBarOffset(bar_offset + (bar_width*4));
    
    refvalue_cc1pi_pi = 36.7011;
    TH1F* TPC2_cc1pi_pi = new TH1F("TPC2_cc1pi_pi","CC1pi selection #pi^{-}",3,0,3);
    TPC2_cc1pi_pi->Fill(tpc2varchoices[0],36.7011/refvalue_cc1pi_pi);
    TPC2_cc1pi_pi->Fill(tpc2varchoices[1],37.3834/refvalue_cc1pi_pi);
    TPC2_cc1pi_pi->Fill(tpc2varchoices[2],38.2774/refvalue_cc1pi_pi);
    TPC2_cc1pi_pi->SetLineColor( kRed + 2); TPC2_cc1pi_pi->SetFillColor( kRed + 2);
    TPC2_cc1pi_pi->SetBarWidth(bar_width);
    TPC2_cc1pi_pi->SetBarOffset(bar_offset + (bar_width*5));
    
    TCanvas* canvas_TPC2_choices = new TCanvas("canvas_TPC2_choices","",200,10,1000,800);
    TPC2_pg_mu->GetYaxis()->SetRangeUser(0.995, 1.045);
    TPC2_pg_mu->GetYaxis()->SetTitle("Track ID max significance (relative)");
    TPC2_pg_mu->GetYaxis()->SetLabelSize(0.025);
    TPC2_pg_mu->GetYaxis()->SetTitleSize(0.025);
    TPC2_pg_mu->Draw("B");
    TPC2_pg_pi->Draw("B same");
    TPC2_pg_p->Draw("B same");
    TPC2_pg_e->Draw("B same");
    TPC2_cc1pi_mu->Draw("B same");
    TPC2_cc1pi_pi->Draw("B same");
    
    canvas_TPC2_choices->BuildLegend();
    
    // =============== ECal variable choice ===============
    
    const char *ecalvarchoices[2] = {"ECal high-level", "ECal low-level"};
    
    refvalue_pg_mu = 215.931;
    TH1F* ECal_pg_mu = new TH1F("ECal_pg_mu","Particle gun selection #mu^{+}",3,0,3);
    ECal_pg_mu->Fill(ecalvarchoices[0],215.931/refvalue_pg_mu);
    ECal_pg_mu->Fill(ecalvarchoices[1],217.434/refvalue_pg_mu);
    ECal_pg_mu->SetLineColor( kBlue); ECal_pg_mu->SetFillColor( kBlue);
    ECal_pg_mu->SetBarWidth(bar_width);
    ECal_pg_mu->SetBarOffset(bar_offset + (bar_width*0));
    
    refvalue_pg_pi = 155.64;
    TH1F* ECal_pg_pi = new TH1F("ECal_pg_pi","Particle gun selection #pi^{+}",3,0,3);
    ECal_pg_pi->Fill(ecalvarchoices[0],155.64/refvalue_pg_pi);
    ECal_pg_pi->Fill(ecalvarchoices[1],162.945/refvalue_pg_pi);
    ECal_pg_pi->SetLineColor( kRed); ECal_pg_pi->SetFillColor( kRed);
    ECal_pg_pi->SetBarWidth(bar_width);
    ECal_pg_pi->SetBarOffset(bar_offset + (bar_width*1));
    
    refvalue_pg_p = 194.814;
    TH1F* ECal_pg_p = new TH1F("ECal_pg_p","Particle gun selection p",3,0,3);
    ECal_pg_p->Fill(ecalvarchoices[0],194.814/refvalue_pg_p);
    ECal_pg_p->Fill(ecalvarchoices[1],205.627/refvalue_pg_p);
    ECal_pg_p->SetLineColor( kGreen); ECal_pg_p->SetFillColor( kGreen);
    ECal_pg_p->SetBarWidth(bar_width);
    ECal_pg_p->SetBarOffset(bar_offset + (bar_width*2));
    
    refvalue_pg_e = 189.482;
    TH1F* ECal_pg_e = new TH1F("ECal_pg_e","Particle gun selection e^{+}",3,0,3);
    ECal_pg_e->Fill(ecalvarchoices[0],189.482/refvalue_pg_e);
    ECal_pg_e->Fill(ecalvarchoices[1],234.699/refvalue_pg_e);
    ECal_pg_e->SetLineColor( kMagenta); ECal_pg_e->SetFillColor( kMagenta);
    ECal_pg_e->SetBarWidth(bar_width);
    ECal_pg_e->SetBarOffset(bar_offset + (bar_width*3));
    
    refvalue_cc1pi_mu = 34.1669;
    TH1F* ECal_cc1pi_mu = new TH1F("ECal_cc1pi_mu","CC1pi selection #mu^{+}",3,0,3);
    ECal_cc1pi_mu->Fill(ecalvarchoices[0],34.1669/refvalue_cc1pi_mu);
    ECal_cc1pi_mu->Fill(ecalvarchoices[1],34.3838/refvalue_cc1pi_mu);
    ECal_cc1pi_mu->SetLineColor( kBlue + 2); ECal_cc1pi_mu->SetFillColor( kBlue + 2);
    ECal_cc1pi_mu->SetBarWidth(bar_width);
    ECal_cc1pi_mu->SetBarOffset(bar_offset + (bar_width*4));
    
    refvalue_cc1pi_pi = 37.8601;
    TH1F* ECal_cc1pi_pi = new TH1F("ECal_cc1pi_pi","CC1pi selection #pi^{-}",3,0,3);
    ECal_cc1pi_pi->Fill(ecalvarchoices[0],37.8601/refvalue_cc1pi_pi);
    ECal_cc1pi_pi->Fill(ecalvarchoices[1],39.6111/refvalue_cc1pi_pi);
    ECal_cc1pi_pi->SetLineColor( kRed + 2); ECal_cc1pi_pi->SetFillColor( kRed + 2);
    ECal_cc1pi_pi->SetBarWidth(bar_width);
    ECal_cc1pi_pi->SetBarOffset(bar_offset + (bar_width*5));
    
    TCanvas* canvas_ECal_choices = new TCanvas("canvas_ECal_choices","",200,10,1000,800);
    ECal_pg_mu->GetYaxis()->SetRangeUser(0.995, 1.045);
    ECal_pg_mu->GetYaxis()->SetTitle("Track ID max significance (relative)");
    ECal_pg_mu->GetYaxis()->SetLabelSize(0.025);
    ECal_pg_mu->GetYaxis()->SetTitleSize(0.025);
    ECal_pg_mu->Draw("B");
    ECal_pg_pi->Draw("B same");
    ECal_pg_p->Draw("B same");
    ECal_pg_e->Draw("B same");
    ECal_cc1pi_mu->Draw("B same");
    ECal_cc1pi_pi->Draw("B same");
    
    canvas_ECal_choices->BuildLegend();
    
    // =============== TPC3 variable choice =============== VALUES NEED CHANGING
    
    const char *tpc3varchoices[3] = {"TPC3 dE/dx","TPC3 pulls","TPC3 muon pull", "nTPCs"};
    
    refvalue_pg_mu = 217.434;
    TH1F* TPC3_pg_mu = new TH1F("TPC3_pg_mu","Particle gun selection #mu^{+}",3,0,3);
    TPC3_pg_mu->Fill(tpc3varchoices[0],217.434/refvalue_pg_mu);
    TPC3_pg_mu->Fill(tpc3varchoices[1],215.571/refvalue_pg_mu);
    TPC3_pg_mu->Fill(tpc3varchoices[2],218.447/refvalue_pg_mu);
    TPC3_pg_mu->Fill(tpc3varchoices[3],220.274/refvalue_pg_mu);
    TPC3_pg_mu->SetLineColor( kBlue); TPC3_pg_mu->SetFillColor( kBlue);
    TPC3_pg_mu->SetBarWidth(bar_width);
    TPC3_pg_mu->SetBarOffset(bar_offset + (bar_width*0));
    
    refvalue_pg_pi = 162.945;
    TH1F* TPC3_pg_pi = new TH1F("TPC3_pg_pi","Particle gun selection #pi^{+}",3,0,3);
    TPC3_pg_pi->Fill(tpc3varchoices[0],162.945/refvalue_pg_pi);
    TPC3_pg_pi->Fill(tpc3varchoices[1],120.719/refvalue_pg_pi);
    TPC3_pg_pi->Fill(tpc3varchoices[2],157.713/refvalue_pg_pi);
    TPC3_pg_pi->Fill(tpc3varchoices[3],173.902/refvalue_pg_pi);
    TPC3_pg_pi->SetLineColor( kRed); TPC3_pg_pi->SetFillColor( kRed);
    TPC3_pg_pi->SetBarWidth(bar_width);
    TPC3_pg_pi->SetBarOffset(bar_offset + (bar_width*1));
    
    refvalue_pg_p = 205.627;
    TH1F* TPC3_pg_p = new TH1F("TPC3_pg_p","Particle gun selection p",3,0,3);
    TPC3_pg_p->Fill(tpc3varchoices[0],205.627/refvalue_pg_p);
    TPC3_pg_p->Fill(tpc3varchoices[1],159.92/refvalue_pg_p);
    TPC3_pg_p->Fill(tpc3varchoices[2],212.311/refvalue_pg_p);
    TPC3_pg_p->Fill(tpc3varchoices[3],217.011/refvalue_pg_p);
    TPC3_pg_p->SetLineColor( kGreen); TPC3_pg_p->SetFillColor( kGreen);
    TPC3_pg_p->SetBarWidth(bar_width);
    TPC3_pg_p->SetBarOffset(bar_offset + (bar_width*2));
    
    refvalue_pg_e = 234.699;
    TH1F* TPC3_pg_e = new TH1F("TPC3_pg_e","Particle gun selection e^{+}",3,0,3);
    TPC3_pg_e->Fill(tpc3varchoices[0],234.699/refvalue_pg_e);
    TPC3_pg_e->Fill(tpc3varchoices[1],201.967/refvalue_pg_e);
    TPC3_pg_e->Fill(tpc3varchoices[2],237.307/refvalue_pg_e);
    TPC3_pg_e->Fill(tpc3varchoices[3],241.362/refvalue_pg_e);
    TPC3_pg_e->SetLineColor( kMagenta); TPC3_pg_e->SetFillColor( kMagenta);
    TPC3_pg_e->SetBarWidth(bar_width);
    TPC3_pg_e->SetBarOffset(bar_offset + (bar_width*3));
    
    refvalue_cc1pi_mu = 34.3838;
    TH1F* TPC3_cc1pi_mu = new TH1F("TPC3_cc1pi_mu","CC1pi selection #mu^{+}",3,0,3);
    TPC3_cc1pi_mu->Fill(tpc3varchoices[0],34.3838/refvalue_cc1pi_mu);
    TPC3_cc1pi_mu->Fill(tpc3varchoices[1],34.1836/refvalue_cc1pi_mu);
    TPC3_cc1pi_mu->Fill(tpc3varchoices[2],34.3731/refvalue_cc1pi_mu);
    TPC3_cc1pi_mu->Fill(tpc3varchoices[3],34.691/refvalue_cc1pi_mu);
    TPC3_cc1pi_mu->SetLineColor( kBlue + 2); TPC3_cc1pi_mu->SetFillColor( kBlue + 2);
    TPC3_cc1pi_mu->SetBarWidth(bar_width);
    TPC3_cc1pi_mu->SetBarOffset(bar_offset + (bar_width*4));
    
    refvalue_cc1pi_pi = 39.6111;
    TH1F* TPC3_cc1pi_pi = new TH1F("TPC3_cc1pi_pi","CC1pi selection #pi^{-}",3,0,3);
    TPC3_cc1pi_pi->Fill(tpc3varchoices[0],39.6111/refvalue_cc1pi_pi);
    TPC3_cc1pi_pi->Fill(tpc3varchoices[1],37.6768/refvalue_cc1pi_pi);
    TPC3_cc1pi_pi->Fill(tpc3varchoices[2],38.9833/refvalue_cc1pi_pi);
    TPC3_cc1pi_pi->Fill(tpc3varchoices[3],39.589/refvalue_cc1pi_pi);
    TPC3_cc1pi_pi->SetLineColor( kRed + 2); TPC3_cc1pi_pi->SetFillColor( kRed + 2);
    TPC3_cc1pi_pi->SetBarWidth(bar_width);
    TPC3_cc1pi_pi->SetBarOffset(bar_offset + (bar_width*5));
    
    TCanvas* canvas_TPC3_choices = new TCanvas("canvas_TPC3_choices","",200,10,1000,800);
    TPC3_pg_mu->GetYaxis()->SetRangeUser(0.995, 1.045);
    TPC3_pg_mu->GetYaxis()->SetTitle("Track ID max significance (relative)");
    TPC3_pg_mu->GetYaxis()->SetLabelSize(0.025);
    TPC3_pg_mu->GetYaxis()->SetTitleSize(0.025);
    TPC3_pg_mu->Draw("B");
    TPC3_pg_pi->Draw("B same");
    TPC3_pg_p->Draw("B same");
    TPC3_pg_e->Draw("B same");
    TPC3_cc1pi_mu->Draw("B same");
    TPC3_cc1pi_pi->Draw("B same");
    
    canvas_TPC3_choices->BuildLegend();
  
}
