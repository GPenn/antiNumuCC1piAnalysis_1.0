{
    TGraph* treedepth_cc1pi_mu = new TGraph();
    treedepth_cc1pi_mu->SetTitle(" ;Maximum tree depth;Optimal selection significance;");
    treedepth_cc1pi_mu->SetPoint(0, 2.0, 33.4749);
    treedepth_cc1pi_mu->SetPoint(1, 3.0, 34.1666);
    treedepth_cc1pi_mu->SetPoint(2, 4.0, 34.0363);
    treedepth_cc1pi_mu->SetPoint(3, 5.0, 34.2227);
    TCanvas* canvas_treedepth = new TCanvas("treedepth","",200,10,1000,600);
    treedepth_cc1pi_mu->Draw("AL*");
}
