{
    // =============== Tree depth ===============
    
    TGraph* treedepth_cc1pi_mu = new TGraph();
    treedepth_cc1pi_mu->SetTitle(" ;Maximum tree depth;Optimal selection significance;");
    treedepth_cc1pi_mu->SetPoint(0, 2.0, 33.4749);
    treedepth_cc1pi_mu->SetPoint(1, 3.0, 34.1666);
    treedepth_cc1pi_mu->SetPoint(2, 4.0, 34.0363);
    treedepth_cc1pi_mu->SetPoint(3, 5.0, 34.2227);
    
    TGraph* treedepth_cc1pi_pi = new TGraph();
    treedepth_cc1pi_pi->SetTitle(" ;Maximum tree depth;Optimal selection significance;");
    treedepth_cc1pi_pi->SetPoint(0, 2.0, 35.4578);
    treedepth_cc1pi_pi->SetPoint(1, 3.0, 37.6588);
    treedepth_cc1pi_pi->SetPoint(2, 4.0, 37.9999);
    treedepth_cc1pi_pi->SetPoint(3, 5.0, 38.4385);
    
    TGraph* treedepth_pg_mu = new TGraph();
    treedepth_pg_mu->SetTitle(" ;Maximum tree depth;Optimal selection significance;");
    treedepth_pg_mu->SetPoint(0, 2.0, 213.045);
    treedepth_pg_mu->SetPoint(1, 3.0, 216.102);
    treedepth_pg_mu->SetPoint(2, 4.0, 215.92);
    treedepth_pg_mu->SetPoint(3, 5.0, 216.812);
    
    TGraph* treedepth_pg_pi = new TGraph();
    treedepth_pg_pi->SetTitle(" ;Maximum tree depth;Optimal selection significance;");
    treedepth_pg_pi->SetPoint(0, 2.0, 148.487);
    treedepth_pg_pi->SetPoint(1, 3.0, 151.511);
    treedepth_pg_pi->SetPoint(2, 4.0, 150.04);
    treedepth_pg_pi->SetPoint(3, 5.0, 151.614);
    
    TGraph* treedepth_pg_p = new TGraph();
    treedepth_pg_p->SetTitle(" ;Maximum tree depth;Optimal selection significance;");
    treedepth_pg_p->SetPoint(0, 2.0, 201.171);
    treedepth_pg_p->SetPoint(1, 3.0, 202.493);
    treedepth_pg_p->SetPoint(2, 4.0, 205.948);
    treedepth_pg_p->SetPoint(3, 5.0, 204.806);
    
    TGraph* treedepth_pg_e = new TGraph();
    treedepth_pg_e->SetTitle(" ;Maximum tree depth;Optimal selection significance;");
    treedepth_pg_e->SetPoint(0, 2.0, 219.126);
    treedepth_pg_e->SetPoint(1, 3.0, 188.998);
    treedepth_pg_e->SetPoint(2, 4.0, 189.719);
    treedepth_pg_e->SetPoint(3, 5.0, 189.99);
    
    TCanvas* canvas_treedepth = new TCanvas("canvas_treedepth","",200,10,1000,400);
    canvas_treedepth->Divide(2,1,0.005,0.005);
    canvas_treedepth->cd(1);
    
    treedepth_cc1pi_mu->GetYaxis()->SetRangeUser(30.0, 40.0);
    treedepth_cc1pi_mu->Draw("AL*");
    treedepth_cc1pi_pi->Draw("L* same");
    
    canvas_treedepth->cd(2);
    treedepth_pg_mu->GetYaxis()->SetRangeUser(140.0, 230.0);
    treedepth_pg_mu->Draw("AL*");
    treedepth_pg_pi->Draw("L* same");
    treedepth_pg_p->Draw("L* same");
    treedepth_pg_e->Draw("L* same");
    
    // =============== Tree number ===============
    
    TGraph* treenumber_cc1pi_mu = new TGraph();
    treenumber_cc1pi_mu->SetTitle(" ;Tree number;Optimal selection significance;");
    treenumber_cc1pi_mu->SetPoint(0, 500.0, 31.882);
    treenumber_cc1pi_mu->SetPoint(1, 1000.0, 31.5975);
    treenumber_cc1pi_mu->SetPoint(2, 1500.0, 31.4073);
    treenumber_cc1pi_mu->SetPoint(3, 2000.0, 31.2578);
    treenumber_cc1pi_mu->SetPoint(4, 2500.0, 31.1631);
    
    TGraph* treenumber_cc1pi_pi = new TGraph();
    treenumber_cc1pi_pi->SetTitle(" ;Tree number;Optimal selection significance;");
    treenumber_cc1pi_pi->SetPoint(0, 500.0, 34.7918);
    treenumber_cc1pi_pi->SetPoint(1, 1000.0, 34.8224);
    treenumber_cc1pi_pi->SetPoint(2, 1500.0, 35.0421);
    treenumber_cc1pi_pi->SetPoint(3, 2000.0, 35.0117);
    treenumber_cc1pi_pi->SetPoint(4, 2500.0, 35.0931);
    
    TCanvas* canvas_treenumber = new TCanvas("canvas_treenumber","",200,10,1000,400);
    canvas_treenumber->Divide(2,1,0.005,0.005);
    canvas_treenumber->cd(1);
    
    treenumber_cc1pi_mu->GetYaxis()->SetRangeUser(30.0, 40.0);
    treenumber_cc1pi_mu->Draw("AL*");
    treenumber_cc1pi_pi->Draw("L* same");
    
    //canvas_treenumber->cd(2);
    //treenumber_pg_mu->GetYaxis()->SetRangeUser(140.0, 230.0);
    //treenumber_pg_mu->Draw("AL*");
    //treenumber_pg_pi->Draw("L* same");
    //treenumber_pg_p->Draw("L* same");
    //treenumber_pg_e->Draw("L* same");
    
}
