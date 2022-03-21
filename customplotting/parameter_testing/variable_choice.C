{
    gStyle->SetTitleYOffset(1.5);
    gStyle->SetOptStat(0);
    gStyle->SetLabelSize(0.025);
    gStyle->SetTitleSize(0.025);
    
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
    TPC2_pg_mu->Draw("B");
    TPC2_pg_pi->Draw("B same");
    TPC2_pg_p->Draw("B same");
    TPC2_pg_e->Draw("B same");
    TPC2_cc1pi_mu->Draw("B same");
    TPC2_cc1pi_pi->Draw("B same");
    
    canvas_TPC2_choices->BuildLegend();
  
}
