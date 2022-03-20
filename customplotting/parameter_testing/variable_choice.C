{
    gStyle->SetTitleYOffset(1.5);
    
    Float_t refvalue_cc1pi_mu, refvalue_cc1pi_pi, refvalue_pg_mu, refvalue_pg_pi, refvalue_pg_p, refvalue_pg_e;
    
    // =============== TPC2 variable choice ===============
    
    const Int_t nx = 3;
    const char *tpc2varchoices[nx] = {"TPC2 dE/dx","TPC2 pulls","TPC2 likelihoods"};
    
    refvalue_cc1pi_mu = 33.3699;
    TH1F* TPC2_cc1pi_mu = new TH1F("TPC2_cc1pi_mu","test",3,0,3);
    TPC2_cc1pi_mu->Fill(tpc2varchoices[0],33.3699/refvalue_cc1pi_mu);
    TPC2_cc1pi_mu->Fill(tpc2varchoices[1],33.7904/refvalue_cc1pi_mu);
    TPC2_cc1pi_mu->Fill(tpc2varchoices[2],33.9678/refvalue_cc1pi_mu);
    TPC2_cc1pi_mu->SetLineColor( kBlue);
    
    refvalue_cc1pi_pi = 36.7011;
    TH1F* TPC2_cc1pi_pi = new TH1F("TPC2_cc1pi_pi","test",3,0,3);
    TPC2_cc1pi_pi->Fill(tpc2varchoices[0],36.7011/refvalue_cc1pi_pi);
    TPC2_cc1pi_pi->Fill(tpc2varchoices[1],37.3834/refvalue_cc1pi_pi);
    TPC2_cc1pi_pi->Fill(tpc2varchoices[2],38.2774/refvalue_cc1pi_pi);
    TPC2_cc1pi_pi->SetLineColor( kRed);
    
    refvalue_pg_mu = 210.16;
    TH1F* TPC2_pg_mu = new TH1F("TPC2_pg_mu","test",3,0,3);
    TPC2_pg_mu->Fill(tpc2varchoices[0],210.16/refvalue_pg_mu);
    TPC2_pg_mu->Fill(tpc2varchoices[1],213.597/refvalue_pg_mu);
    TPC2_pg_mu->Fill(tpc2varchoices[2],214.249/refvalue_pg_mu);
    TPC2_pg_mu->SetLineColor( kBlue);
    
    refvalue_pg_pi = 157.581;
    TH1F* TPC2_pg_pi = new TH1F("TPC2_pg_pi","test",3,0,3);
    TPC2_pg_pi->Fill(tpc2varchoices[0],157.581/refvalue_pg_pi);
    TPC2_pg_pi->Fill(tpc2varchoices[1],160.974/refvalue_pg_pi);
    TPC2_pg_pi->Fill(tpc2varchoices[2],161.309/refvalue_pg_pi);
    TPC2_pg_pi->SetLineColor( kRed);
    
    refvalue_pg_p = 187.364;
    TH1F* TPC2_pg_p = new TH1F("TPC2_pg_p","test",3,0,3);
    TPC2_pg_p->Fill(tpc2varchoices[0],187.364/refvalue_pg_p);
    TPC2_pg_p->Fill(tpc2varchoices[1],193.76/refvalue_pg_p);
    TPC2_pg_p->Fill(tpc2varchoices[2],195.318/refvalue_pg_p);
    TPC2_pg_p->SetLineColor( kGreen);
    
    refvalue_pg_e = 223.002;
    TH1F* TPC2_pg_e = new TH1F("TPC2_pg_e","test",3,0,3);
    TPC2_pg_e->Fill(tpc2varchoices[0],223.002/refvalue_pg_e);
    TPC2_pg_e->Fill(tpc2varchoices[1],227.148/refvalue_pg_e);
    TPC2_pg_e->Fill(tpc2varchoices[2],226.972/refvalue_pg_e);
    TPC2_pg_e->SetLineColor( kMagenta);
    
    TCanvas* canvas_TPC2_choices = new TCanvas("canvas_TPC2_choices","",200,10,1000,800);
    TPC2_cc1pi_mu->Draw("B");
    TPC2_cc1pi_pi->Draw("B same");
    TPC2_pg_mu->Draw("B same");
    TPC2_pg_pi->Draw("B same");
    TPC2_pg_p->Draw("B same");
    TPC2_pg_e->Draw("B same");
    
    canvas_TPC2_choices->BuildLegend();
    
    /*TCanvas* canvas_treedepth = new TCanvas("canvas_treedepth","",200,10,1000,400);
    canvas_treedepth->Divide(2,1,0.005,0.005);
    canvas_treedepth->cd(1);
    
    treedepth_cc1pi_mu->GetYaxis()->SetRangeUser(0.97, 1.02);
    treedepth_cc1pi_mu->GetXaxis()->SetTitle("Maximum tree depth"); treedepth_cc1pi_mu->GetYaxis()->SetTitle("Optimal selection significance");
    
    treedepth_cc1pi_mu->Draw("AL*");
    treedepth_cc1pi_pi->Draw("L* same");
    canvas_treedepth->cd(1)->BuildLegend();
    
    canvas_treedepth->cd(2);
    treedepth_pg_mu->GetYaxis()->SetRangeUser(0.97, 1.02);
    treedepth_pg_mu->GetXaxis()->SetTitle("Maximum tree depth"); treedepth_pg_mu->GetYaxis()->SetTitle("Optimal selection significance");
    treedepth_pg_mu->Draw("AL*");
    treedepth_pg_pi->Draw("L* same");
    treedepth_pg_p->Draw("L* same");
    treedepth_pg_e->Draw("L* same");
    canvas_treedepth->cd(2)->BuildLegend();*/
  
}
