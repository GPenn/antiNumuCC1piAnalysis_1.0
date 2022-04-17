{
    gStyle->SetTitleYOffset(1.5);
    
    Float_t refvalue_cc1pi_mu, refvalue_cc1pi_pi, refvalue_pg_mu, refvalue_pg_pi, refvalue_pg_p, refvalue_pg_e;
    
    // =============== Tree depth ===============
    
    refvalue_pg_mu = 0.935462;
    TGraph* treedepth_pg_mu = new TGraph();
    treedepth_pg_mu->SetTitle("#mu^{+} identified as #mu^{+}");
    treedepth_pg_mu->SetPoint(0, 2.0, 0.936651);
    treedepth_pg_mu->SetPoint(1, 3.0, 0.935462);
    treedepth_pg_mu->SetPoint(2, 4.0, 0.932985);
    treedepth_pg_mu->SetPoint(3, 5.0, 0.932188);
    treedepth_pg_mu->SetLineColor( kBlue); treedepth_pg_mu->SetMarkerColor( kBlue); treedepth_pg_mu->SetFillColor( kWhite);
    
    refvalue_pg_pi = 0.581125;
    TGraph* treedepth_pg_pi = new TGraph();
    treedepth_pg_pi->SetTitle("#pi^{+} identified as #pi^{+}");
    treedepth_pg_pi->SetPoint(0, 2.0, 0.576868);
    treedepth_pg_pi->SetPoint(1, 3.0, 0.581125);
    treedepth_pg_pi->SetPoint(2, 4.0, 0.588093);
    treedepth_pg_pi->SetPoint(3, 5.0, 0.589709);
    treedepth_pg_pi->SetLineColor( kRed); treedepth_pg_pi->SetMarkerColor( kRed); treedepth_pg_pi->SetFillColor( kWhite); 
    
    refvalue_pg_p = 0.915649;
    TGraph* treedepth_pg_p = new TGraph();
    treedepth_pg_p->SetTitle("p identified as p");
    treedepth_pg_p->SetPoint(0, 2.0, 0.911008);
    treedepth_pg_p->SetPoint(1, 3.0, 0.915649);
    treedepth_pg_p->SetPoint(2, 4.0, 0.918464);
    treedepth_pg_p->SetPoint(3, 5.0, 0.919146);
    treedepth_pg_p->SetLineColor( kGreen); treedepth_pg_p->SetMarkerColor( kGreen); treedepth_pg_p->SetFillColor( kWhite); 
    
    refvalue_pg_e = 0.627811;
    TGraph* treedepth_pg_e = new TGraph();
    treedepth_pg_e->SetTitle("e^{+} identified as e^{+}");
    treedepth_pg_e->SetPoint(0, 2.0, 0.590713);
    treedepth_pg_e->SetPoint(1, 3.0, 0.627811);
    treedepth_pg_e->SetPoint(2, 4.0, 0.64741);
    treedepth_pg_e->SetPoint(3, 5.0, 0.641789);
    treedepth_pg_e->SetLineColor( kMagenta); treedepth_pg_e->SetMarkerColor( kMagenta); treedepth_pg_e->SetFillColor( kWhite); 
    
    TGraph* treedepth_pg_diff_mu = new TGraph();
    treedepth_pg_diff_mu->SetTitle("#mu^{+} identified as #mu^{+}");
    treedepth_pg_diff_mu->SetPoint(0, 2.0, 0.936651-refvalue_pg_mu);
    treedepth_pg_diff_mu->SetPoint(1, 3.0, 0.935462-refvalue_pg_mu);
    treedepth_pg_diff_mu->SetPoint(2, 4.0, 0.932985-refvalue_pg_mu);
    treedepth_pg_diff_mu->SetPoint(3, 5.0, 0.932188-refvalue_pg_mu);
    treedepth_pg_diff_mu->SetLineColor( kBlue); treedepth_pg_diff_mu->SetMarkerColor( kBlue); treedepth_pg_diff_mu->SetFillColor( kWhite);
    
    TGraph* treedepth_pg_diff_pi = new TGraph();
    treedepth_pg_diff_pi->SetTitle("#pi^{+} identified as #pi^{+}");
    treedepth_pg_diff_pi->SetPoint(0, 2.0, 0.576868-refvalue_pg_pi);
    treedepth_pg_diff_pi->SetPoint(1, 3.0, 0.581125-refvalue_pg_pi);
    treedepth_pg_diff_pi->SetPoint(2, 4.0, 0.588093-refvalue_pg_pi);
    treedepth_pg_diff_pi->SetPoint(3, 5.0, 0.589709-refvalue_pg_pi);
    treedepth_pg_diff_pi->SetLineColor( kRed); treedepth_pg_diff_pi->SetMarkerColor( kRed); treedepth_pg_diff_pi->SetFillColor( kWhite); 
    
    TGraph* treedepth_pg_diff_p = new TGraph();
    treedepth_pg_diff_p->SetTitle("p identified as p");
    treedepth_pg_diff_p->SetPoint(0, 2.0, 0.911008-refvalue_pg_p);
    treedepth_pg_diff_p->SetPoint(1, 3.0, 0.915649-refvalue_pg_p);
    treedepth_pg_diff_p->SetPoint(2, 4.0, 0.918464-refvalue_pg_p);
    treedepth_pg_diff_p->SetPoint(3, 5.0, 0.919146-refvalue_pg_p);
    treedepth_pg_diff_p->SetLineColor( kGreen); treedepth_pg_diff_p->SetMarkerColor( kGreen); treedepth_pg_diff_p->SetFillColor( kWhite); 
    
    TGraph* treedepth_pg_diff_e = new TGraph();
    treedepth_pg_diff_e->SetTitle("e^{+} identified as e^{+}");
    treedepth_pg_diff_e->SetPoint(0, 2.0, 0.590713-refvalue_pg_e);
    treedepth_pg_diff_e->SetPoint(1, 3.0, 0.627811-refvalue_pg_e);
    treedepth_pg_diff_e->SetPoint(2, 4.0, 0.64741-refvalue_pg_e);
    treedepth_pg_diff_e->SetPoint(3, 5.0, 0.641789-refvalue_pg_e);
    treedepth_pg_diff_e->SetLineColor( kMagenta); treedepth_pg_diff_e->SetMarkerColor( kMagenta); treedepth_pg_diff_e->SetFillColor( kWhite); 
    
    TCanvas* canvas_treedepth = new TCanvas("canvas_treedepth","",200,10,1000,400);
    canvas_treedepth->Divide(2,1,0.005,0.005);
    
    canvas_treedepth->cd(1);   
    treedepth_pg_mu->GetYaxis()->SetRangeUser(0, 1);
    treedepth_pg_mu->GetYaxis()->SetTitleOffset(1.2);
    treedepth_pg_mu->GetXaxis()->SetTitle("Maximum tree depth"); treedepth_pg_mu->GetYaxis()->SetTitle("Efficiency");
    treedepth_pg_mu->Draw("AL*");
    treedepth_pg_pi->Draw("L* same");
    treedepth_pg_p->Draw("L* same");
    treedepth_pg_e->Draw("L* same");
    canvas_treedepth->cd(1)->BuildLegend();
    
    canvas_treedepth->cd(2);   
    treedepth_pg_diff_mu->GetYaxis()->SetRangeUser(-0.04, 0.03);
    treedepth_pg_diff_mu->GetXaxis()->SetTitle("Maximum tree depth"); treedepth_pg_diff_mu->GetYaxis()->SetTitle("Difference in efficiency");
    treedepth_pg_diff_mu->Draw("AL*");
    treedepth_pg_diff_pi->Draw("L* same");
    treedepth_pg_diff_p->Draw("L* same");
    treedepth_pg_diff_e->Draw("L* same");
    
    // =============== Tree number ===============
    
    refvalue_pg_mu = 0.932985;
    refvalue_pg_pi = 0.588093;
    refvalue_pg_p = 0.918464;
    refvalue_pg_e = 0.64741;
    
    TGraph* treenumber_pg_mu = new TGraph();
    treenumber_pg_mu->SetTitle("#mu^{+} selection mu-like cut");
    treenumber_pg_mu->SetPoint(0, 500.0, 0.936174);
    treenumber_pg_mu->SetPoint(1, 1000.0, 0.932711);
    treenumber_pg_mu->SetPoint(2, 1500.0, 0.929409);
    treenumber_pg_mu->SetPoint(3, 2000.0, 0.927221);
    treenumber_pg_mu->SetPoint(4, 2500.0, 0.924295);
    treenumber_pg_mu->SetLineColor( kBlue); treenumber_pg_mu->SetMarkerColor( kBlue); treenumber_pg_mu->SetFillColor( kWhite);
    
    TGraph* treenumber_pg_pi = new TGraph();
    treenumber_pg_pi->SetTitle("#pi^{+} selection pi-like cut");
    treenumber_pg_pi->SetPoint(0, 500.0, 0.584862);
    treenumber_pg_pi->SetPoint(1, 1000.0, 0.592804);
    treenumber_pg_pi->SetPoint(2, 1500.0, 0.597682);
    treenumber_pg_pi->SetPoint(3, 2000.0, 0.599565);
    treenumber_pg_pi->SetPoint(4, 2500.0, 0.60292);
    treenumber_pg_pi->SetLineColor( kRed); treenumber_pg_pi->SetMarkerColor( kRed); treenumber_pg_pi->SetFillColor( kWhite);
    
    TGraph* treenumber_pg_p = new TGraph();
    treenumber_pg_p->SetTitle("p selection p-like cut");
    treenumber_pg_p->SetPoint(0, 500.0, 0.913117);
    treenumber_pg_p->SetPoint(1, 1000.0, 0.917318);
    treenumber_pg_p->SetPoint(2, 1500.0, 0.919098);
    treenumber_pg_p->SetPoint(3, 2000.0, 0.919807);
    treenumber_pg_p->SetPoint(4, 2500.0, 0.920516);
    treenumber_pg_p->SetLineColor( kGreen); treenumber_pg_p->SetMarkerColor( kGreen); treenumber_pg_p->SetFillColor( kWhite); 
    
    TGraph* treenumber_pg_e = new TGraph();
    treenumber_pg_e->SetTitle("e^{+} selection e-like cut");
    treenumber_pg_e->SetPoint(0, 500.0, 0.610646);
    treenumber_pg_e->SetPoint(1, 1000.0, 0.64922);
    treenumber_pg_e->SetPoint(2, 1500.0, 0.667379);
    treenumber_pg_e->SetPoint(3, 2000.0, 0.668552);
    treenumber_pg_e->SetPoint(4, 2500.0, 0.670557);
    treenumber_pg_e->SetLineColor( kMagenta); treenumber_pg_e->SetMarkerColor( kMagenta); treenumber_pg_e->SetFillColor( kWhite); 
    
    TGraph* treenumber_pg_diff_mu = new TGraph();
    treenumber_pg_diff_mu->SetTitle("#mu^{+} selection mu-like cut");
    treenumber_pg_diff_mu->SetPoint(0, 500.0, 0.936174-refvalue_pg_mu);
    treenumber_pg_diff_mu->SetPoint(1, 1000.0, 0.932711-refvalue_pg_mu);
    treenumber_pg_diff_mu->SetPoint(2, 1500.0, 0.929409-refvalue_pg_mu);
    treenumber_pg_diff_mu->SetPoint(3, 2000.0, 0.927221-refvalue_pg_mu);
    treenumber_pg_diff_mu->SetPoint(4, 2500.0, 0.924295-refvalue_pg_mu);
    treenumber_pg_diff_mu->SetLineColor( kBlue); treenumber_pg_diff_mu->SetMarkerColor( kBlue); treenumber_pg_diff_mu->SetFillColor( kWhite);
    
    TGraph* treenumber_pg_diff_pi = new TGraph();
    treenumber_pg_diff_pi->SetTitle("#pi^{+} selection pi-like cut");
    treenumber_pg_diff_pi->SetPoint(0, 500.0, 0.584862-refvalue_pg_pi);
    treenumber_pg_diff_pi->SetPoint(1, 1000.0, 0.592804-refvalue_pg_pi);
    treenumber_pg_diff_pi->SetPoint(2, 1500.0, 0.597682-refvalue_pg_pi);
    treenumber_pg_diff_pi->SetPoint(3, 2000.0, 0.599565-refvalue_pg_pi);
    treenumber_pg_diff_pi->SetPoint(4, 2500.0, 0.60292-refvalue_pg_pi);
    treenumber_pg_diff_pi->SetLineColor( kRed); treenumber_pg_diff_pi->SetMarkerColor( kRed); treenumber_pg_diff_pi->SetFillColor( kWhite);
    
    TGraph* treenumber_pg_diff_p = new TGraph();
    treenumber_pg_diff_p->SetTitle("p selection p-like cut");
    treenumber_pg_diff_p->SetPoint(0, 500.0, 0.913117-refvalue_pg_p);
    treenumber_pg_diff_p->SetPoint(1, 1000.0, 0.917318-refvalue_pg_p);
    treenumber_pg_diff_p->SetPoint(2, 1500.0, 0.919098-refvalue_pg_p);
    treenumber_pg_diff_p->SetPoint(3, 2000.0, 0.919807-refvalue_pg_p);
    treenumber_pg_diff_p->SetPoint(4, 2500.0, 0.920516-refvalue_pg_p);
    treenumber_pg_diff_p->SetLineColor( kGreen); treenumber_pg_diff_p->SetMarkerColor( kGreen); treenumber_pg_diff_p->SetFillColor( kWhite); 
    
    TGraph* treenumber_pg_diff_e = new TGraph();
    treenumber_pg_diff_e->SetTitle("e^{+} selection e-like cut");
    treenumber_pg_diff_e->SetPoint(0, 500.0, 0.610646-refvalue_pg_e);
    treenumber_pg_diff_e->SetPoint(1, 1000.0, 0.64922-refvalue_pg_e);
    treenumber_pg_diff_e->SetPoint(2, 1500.0, 0.667379-refvalue_pg_e);
    treenumber_pg_diff_e->SetPoint(3, 2000.0, 0.668552-refvalue_pg_e);
    treenumber_pg_diff_e->SetPoint(4, 2500.0, 0.670557-refvalue_pg_e);
    treenumber_pg_diff_e->SetLineColor( kMagenta); treenumber_pg_diff_e->SetMarkerColor( kMagenta); treenumber_pg_diff_e->SetFillColor( kWhite); 
    
    TCanvas* canvas_treenumber = new TCanvas("canvas_treenumber","",200,10,1000,400);
    canvas_treenumber->Divide(2,1,0.005,0.005);
    
    canvas_treenumber->cd(1);   
    treenumber_pg_mu->GetYaxis()->SetRangeUser(0, 1);
    treenumber_pg_mu->GetYaxis()->SetTitleOffset(1.2);
    treenumber_pg_mu->GetXaxis()->SetTitle("Number of trees"); treenumber_pg_mu->GetYaxis()->SetTitle("Efficiency");
    treenumber_pg_mu->Draw("AL*");
    treenumber_pg_pi->Draw("L* same");
    treenumber_pg_p->Draw("L* same");
    treenumber_pg_e->Draw("L* same");
    canvas_treenumber->cd(1)->BuildLegend();
    
    canvas_treenumber->cd(2);
    treenumber_pg_diff_mu->GetYaxis()->SetRangeUser(-0.04, 0.08);
    treenumber_pg_diff_mu->GetXaxis()->SetTitle("Number of trees"); treenumber_pg_diff_mu->GetYaxis()->SetTitle("Difference in efficiency");
    treenumber_pg_diff_mu->Draw("AL*");
    treenumber_pg_diff_pi->Draw("L* same");
    treenumber_pg_diff_p->Draw("L* same");
    treenumber_pg_diff_e->Draw("L* same");
    
    // =============== Shrinkage ===============
    
    TGraph* shrinkage_pg_mu = new TGraph();
    shrinkage_pg_mu->SetTitle("#mu^{+} selection mu-like cut");
    shrinkage_pg_mu->SetPoint(0, 0.01, 0.);
    shrinkage_pg_mu->SetPoint(1, 0.02, 0.);
    shrinkage_pg_mu->SetPoint(2, 0.04, 0.);
    shrinkage_pg_mu->SetPoint(3, 0.06, 0.);
    shrinkage_pg_mu->SetPoint(4, 0.08, 0.);
    shrinkage_pg_mu->SetPoint(5, 0.1, 0.938274);
    shrinkage_pg_mu->SetPoint(6, 0.3, 0.938969);
    shrinkage_pg_mu->SetPoint(7, 0.5, 0.937622);
    shrinkage_pg_mu->SetPoint(8, 0.7, 0.935623);
    shrinkage_pg_mu->SetPoint(9, 0.9, 0.933117);
    shrinkage_pg_mu->SetLineColor( kBlue); shrinkage_pg_mu->SetMarkerColor( kBlue); shrinkage_pg_mu->SetFillColor( kWhite);
    
    TGraph* shrinkage_pg_pi = new TGraph();
    shrinkage_pg_pi->SetTitle("#pi^{+} selection pi-like cut");
    shrinkage_pg_pi->SetPoint(0, 0.01, 0.);
    shrinkage_pg_pi->SetPoint(1, 0.02, 0.);
    shrinkage_pg_pi->SetPoint(2, 0.04, 0.);
    shrinkage_pg_pi->SetPoint(3, 0.06, 0.);
    shrinkage_pg_pi->SetPoint(4, 0.08, 0.);
    shrinkage_pg_pi->SetPoint(5, 0.1, 0.580429);
    shrinkage_pg_pi->SetPoint(6, 0.3, 0.578238);
    shrinkage_pg_pi->SetPoint(7, 0.5, 0.584503);
    shrinkage_pg_pi->SetPoint(8, 0.7, 0.58553);
    shrinkage_pg_pi->SetPoint(9, 0.9, 0.589809);
    shrinkage_pg_pi->SetLineColor( kRed); shrinkage_pg_pi->SetMarkerColor( kRed); shrinkage_pg_pi->SetFillColor( kWhite);
    
    TGraph* shrinkage_pg_p = new TGraph();
    shrinkage_pg_p->SetTitle("p selection p-like cut");
    shrinkage_pg_p->SetPoint(0, 0.01, 0.);
    shrinkage_pg_p->SetPoint(1, 0.02, 0.);
    shrinkage_pg_p->SetPoint(2, 0.04, 0.);
    shrinkage_pg_p->SetPoint(3, 0.06, 0.);
    shrinkage_pg_p->SetPoint(4, 0.08, 0.);
    shrinkage_pg_p->SetPoint(5, 0.1, 0.883349);
    shrinkage_pg_p->SetPoint(6, 0.3, 0.909401);
    shrinkage_pg_p->SetPoint(7, 0.5, 0.913117);
    shrinkage_pg_p->SetPoint(8, 0.7, 0.915589);
    shrinkage_pg_p->SetPoint(9, 0.9, 0.91692);
    shrinkage_pg_p->SetLineColor( kGreen); shrinkage_pg_p->SetMarkerColor( kGreen); shrinkage_pg_p->SetFillColor( kWhite); 
    
    TGraph* shrinkage_pg_e = new TGraph();
    shrinkage_pg_e->SetTitle("e^{+} selection e-like cut");
    shrinkage_pg_e->SetPoint(0, 0.01, 0.);
    shrinkage_pg_e->SetPoint(1, 0.02, 0.);
    shrinkage_pg_e->SetPoint(2, 0.04, 0.);
    shrinkage_pg_e->SetPoint(3, 0.06, 0.);
    shrinkage_pg_e->SetPoint(4, 0.08, 0.);
    shrinkage_pg_e->SetPoint(5, 0.1, 0.377001);
    shrinkage_pg_e->SetPoint(6, 0.3, 0.576125);
    shrinkage_pg_e->SetPoint(7, 0.5, 0.625419);
    shrinkage_pg_e->SetPoint(8, 0.7, 0.631878);
    shrinkage_pg_e->SetPoint(9, 0.9, 0.633645);
    shrinkage_pg_e->SetLineColor( kMagenta); shrinkage_pg_e->SetMarkerColor( kMagenta); shrinkage_pg_e->SetFillColor( kWhite); 
    
    TGraph* shrinkage_pg_diff_mu = new TGraph();
    shrinkage_pg_diff_mu->SetTitle("#mu^{+} selection mu-like cut");
    shrinkage_pg_diff_mu->SetPoint(0, 0.01, 0.-refvalue_pg_mu);
    shrinkage_pg_diff_mu->SetPoint(1, 0.02, 0.-refvalue_pg_mu);
    shrinkage_pg_diff_mu->SetPoint(2, 0.04, 0.-refvalue_pg_mu);
    shrinkage_pg_diff_mu->SetPoint(3, 0.06, 0.-refvalue_pg_mu);
    shrinkage_pg_diff_mu->SetPoint(4, 0.08, 0.-refvalue_pg_mu);
    shrinkage_pg_diff_mu->SetPoint(5, 0.1, 0.938274-refvalue_pg_mu);
    shrinkage_pg_diff_mu->SetPoint(6, 0.3, 0.938969-refvalue_pg_mu);
    shrinkage_pg_diff_mu->SetPoint(7, 0.5, 0.937622-refvalue_pg_mu);
    shrinkage_pg_diff_mu->SetPoint(8, 0.7, 0.935623-refvalue_pg_mu);
    shrinkage_pg_diff_mu->SetPoint(9, 0.9, 0.933117-refvalue_pg_mu);
    shrinkage_pg_diff_mu->SetLineColor( kBlue); shrinkage_pg_diff_mu->SetMarkerColor( kBlue); shrinkage_pg_diff_mu->SetFillColor( kWhite);
    
    TGraph* shrinkage_pg_diff_pi = new TGraph();
    shrinkage_pg_diff_pi->SetTitle("#pi^{+} selection pi-like cut");
    shrinkage_pg_diff_pi->SetPoint(0, 0.01, 0.-refvalue_pg_pi);
    shrinkage_pg_diff_pi->SetPoint(1, 0.02, 0.-refvalue_pg_pi);
    shrinkage_pg_diff_pi->SetPoint(2, 0.04, 0.-refvalue_pg_pi);
    shrinkage_pg_diff_pi->SetPoint(3, 0.06, 0.-refvalue_pg_pi);
    shrinkage_pg_diff_pi->SetPoint(4, 0.08, 0.-refvalue_pg_pi);
    shrinkage_pg_diff_pi->SetPoint(5, 0.1, 0.580429-refvalue_pg_pi);
    shrinkage_pg_diff_pi->SetPoint(6, 0.3, 0.578238-refvalue_pg_pi);
    shrinkage_pg_diff_pi->SetPoint(7, 0.5, 0.584503-refvalue_pg_pi);
    shrinkage_pg_diff_pi->SetPoint(8, 0.7, 0.58553-refvalue_pg_pi);
    shrinkage_pg_diff_pi->SetPoint(9, 0.9, 0.589809-refvalue_pg_pi);
    shrinkage_pg_diff_pi->SetLineColor( kRed); shrinkage_pg_diff_pi->SetMarkerColor( kRed); shrinkage_pg_diff_pi->SetFillColor( kWhite);
    
    TGraph* shrinkage_pg_diff_p = new TGraph();
    shrinkage_pg_diff_p->SetTitle("p selection p-like cut");
    shrinkage_pg_diff_p->SetPoint(0, 0.01, 0.-refvalue_pg_p);
    shrinkage_pg_diff_p->SetPoint(1, 0.02, 0.-refvalue_pg_p);
    shrinkage_pg_diff_p->SetPoint(2, 0.04, 0.-refvalue_pg_p);
    shrinkage_pg_diff_p->SetPoint(3, 0.06, 0.-refvalue_pg_p);
    shrinkage_pg_diff_p->SetPoint(4, 0.08, 0.-refvalue_pg_p);
    shrinkage_pg_diff_p->SetPoint(5, 0.1, 0.883349-refvalue_pg_p);
    shrinkage_pg_diff_p->SetPoint(6, 0.3, 0.909401-refvalue_pg_p);
    shrinkage_pg_diff_p->SetPoint(7, 0.5, 0.913117-refvalue_pg_p);
    shrinkage_pg_diff_p->SetPoint(8, 0.7, 0.915589-refvalue_pg_p);
    shrinkage_pg_diff_p->SetPoint(9, 0.9, 0.91692-refvalue_pg_p);
    shrinkage_pg_diff_p->SetLineColor( kGreen); shrinkage_pg_diff_p->SetMarkerColor( kGreen); shrinkage_pg_diff_p->SetFillColor( kWhite); 
    
    TGraph* shrinkage_pg_diff_e = new TGraph();
    shrinkage_pg_diff_e->SetTitle("e^{+} selection e-like cut");
    shrinkage_pg_diff_e->SetPoint(0, 0.01, 0.-refvalue_pg_e);
    shrinkage_pg_diff_e->SetPoint(1, 0.02, 0.-refvalue_pg_e);
    shrinkage_pg_diff_e->SetPoint(2, 0.04, 0.-refvalue_pg_e);
    shrinkage_pg_diff_e->SetPoint(3, 0.06, 0.-refvalue_pg_e);
    shrinkage_pg_diff_e->SetPoint(4, 0.08, 0.-refvalue_pg_e);
    shrinkage_pg_diff_e->SetPoint(5, 0.1, 0.377001-refvalue_pg_e);
    shrinkage_pg_diff_e->SetPoint(6, 0.3, 0.576125-refvalue_pg_e);
    shrinkage_pg_diff_e->SetPoint(7, 0.5, 0.625419-refvalue_pg_e);
    shrinkage_pg_diff_e->SetPoint(8, 0.7, 0.631878-refvalue_pg_e);
    shrinkage_pg_diff_e->SetPoint(9, 0.9, 0.633645-refvalue_pg_e);
    shrinkage_pg_diff_e->SetLineColor( kMagenta); shrinkage_pg_diff_e->SetMarkerColor( kMagenta); shrinkage_pg_diff_e->SetFillColor( kWhite); 
    
    TCanvas* canvas_shrinkage = new TCanvas("canvas_shrinkage","",200,10,1000,400);
    canvas_shrinkage->Divide(2,1,0.005,0.005);
    
    canvas_shrinkage->cd(1);  
    shrinkage_pg_mu->GetYaxis()->SetRangeUser(0, 1);
    shrinkage_pg_mu->GetYaxis()->SetTitleOffset(1.2);
    shrinkage_pg_mu->GetXaxis()->SetTitle("Shrinkage"); shrinkage_pg_mu->GetYaxis()->SetTitle("Efficiency");
    shrinkage_pg_mu->Draw("AL*");
    shrinkage_pg_pi->Draw("L* same");
    shrinkage_pg_p->Draw("L* same");
    shrinkage_pg_e->Draw("L* same");
    canvas_shrinkage->cd(1)->BuildLegend();
    
    canvas_shrinkage->cd(2);  
    shrinkage_pg_diff_mu->GetYaxis()->SetRangeUser(-0.3, 0.04);
    shrinkage_pg_diff_mu->GetXaxis()->SetTitle("Shrinkage"); shrinkage_pg_diff_mu->GetYaxis()->SetTitle("Difference in efficiency");
    shrinkage_pg_diff_mu->Draw("AL*");
    shrinkage_pg_diff_pi->Draw("L* same");
    shrinkage_pg_diff_p->Draw("L* same");
    shrinkage_pg_diff_e->Draw("L* same");
    
    // =============== Bagged ===============
    
    TGraph* bagged_pg_mu = new TGraph();
    bagged_pg_mu->SetTitle("#mu^{+} selection mu-like cut");
    bagged_pg_mu->SetPoint(0, 0.1, 0.833466);
    bagged_pg_mu->SetPoint(1, 0.3, 0.925034);
    bagged_pg_mu->SetPoint(2, 0.5, 0.925671);
    bagged_pg_mu->SetPoint(3, 0.7, 0.928308);
    bagged_pg_mu->SetPoint(4, 0.9, 0.929655);
    bagged_pg_mu->SetLineColor( kBlue); bagged_pg_mu->SetMarkerColor( kBlue); bagged_pg_mu->SetFillColor( kWhite);
    
    TGraph* bagged_pg_pi = new TGraph();
    bagged_pg_pi->SetTitle("#pi^{+} selection pi-like cut");
    bagged_pg_pi->SetPoint(0, 0.1, 0.56713);
    bagged_pg_pi->SetPoint(1, 0.3, 0.596091);
    bagged_pg_pi->SetPoint(2, 0.5, 0.602646);
    bagged_pg_pi->SetPoint(3, 0.7, 0.596176);
    bagged_pg_pi->SetPoint(4, 0.9, 0.597563);
    bagged_pg_pi->SetLineColor( kRed); bagged_pg_pi->SetMarkerColor( kRed); bagged_pg_pi->SetFillColor( kWhite);
    
    TGraph* bagged_pg_p = new TGraph();
    bagged_pg_p->SetTitle("p selection p-like cut");
    bagged_pg_p->SetPoint(0, 0.1, 0.813874);
    bagged_pg_p->SetPoint(1, 0.3, 0.911596);
    bagged_pg_p->SetPoint(2, 0.5, 0.910662);
    bagged_pg_p->SetPoint(3, 0.7, 0.913065);
    bagged_pg_p->SetPoint(4, 0.9, 0.912391);
    bagged_pg_p->SetLineColor( kGreen); bagged_pg_p->SetMarkerColor( kGreen); bagged_pg_p->SetFillColor( kWhite); 
    
    TGraph* bagged_pg_e = new TGraph();
    bagged_pg_e->SetTitle("e^{+} selection e-like cut");
    bagged_pg_e->SetPoint(0, 0.1, 0.274892);
    bagged_pg_e->SetPoint(1, 0.3, 0.63853);
    bagged_pg_e->SetPoint(2, 0.5, 0.607112);
    bagged_pg_e->SetPoint(3, 0.7, 0.600178);
    bagged_pg_e->SetPoint(4, 0.9, 0.650616);
    bagged_pg_e->SetLineColor( kMagenta); bagged_pg_e->SetMarkerColor( kMagenta); bagged_pg_e->SetFillColor( kWhite); 
    
    TGraph* bagged_pg_diff_mu = new TGraph();
    bagged_pg_diff_mu->SetTitle("#mu^{+} selection mu-like cut");
    bagged_pg_diff_mu->SetPoint(0, 0.1, 0.833466-refvalue_pg_mu);
    bagged_pg_diff_mu->SetPoint(1, 0.3, 0.925034-refvalue_pg_mu);
    bagged_pg_diff_mu->SetPoint(2, 0.5, 0.925671-refvalue_pg_mu);
    bagged_pg_diff_mu->SetPoint(3, 0.7, 0.928308-refvalue_pg_mu);
    bagged_pg_diff_mu->SetPoint(4, 0.9, 0.929655-refvalue_pg_mu);
    bagged_pg_diff_mu->SetLineColor( kBlue); bagged_pg_diff_mu->SetMarkerColor( kBlue); bagged_pg_diff_mu->SetFillColor( kWhite);
    
    TGraph* bagged_pg_diff_pi = new TGraph();
    bagged_pg_diff_pi->SetTitle("#pi^{+} selection pi-like cut");
    bagged_pg_diff_pi->SetPoint(0, 0.1, 0.56713-refvalue_pg_pi);
    bagged_pg_diff_pi->SetPoint(1, 0.3, 0.596091-refvalue_pg_pi);
    bagged_pg_diff_pi->SetPoint(2, 0.5, 0.602646-refvalue_pg_pi);
    bagged_pg_diff_pi->SetPoint(3, 0.7, 0.596176-refvalue_pg_pi);
    bagged_pg_diff_pi->SetPoint(4, 0.9, 0.597563-refvalue_pg_pi);
    bagged_pg_diff_pi->SetLineColor( kRed); bagged_pg_diff_pi->SetMarkerColor( kRed); bagged_pg_diff_pi->SetFillColor( kWhite);
    
    TGraph* bagged_pg_diff_p = new TGraph();
    bagged_pg_diff_p->SetTitle("p selection p-like cut");
    bagged_pg_diff_p->SetPoint(0, 0.1, 0.813874-refvalue_pg_p);
    bagged_pg_diff_p->SetPoint(1, 0.3, 0.911596-refvalue_pg_p);
    bagged_pg_diff_p->SetPoint(2, 0.5, 0.910662-refvalue_pg_p);
    bagged_pg_diff_p->SetPoint(3, 0.7, 0.913065-refvalue_pg_p);
    bagged_pg_diff_p->SetPoint(4, 0.9, 0.912391-refvalue_pg_p);
    bagged_pg_diff_p->SetLineColor( kGreen); bagged_pg_diff_p->SetMarkerColor( kGreen); bagged_pg_diff_p->SetFillColor( kWhite); 
    
    TGraph* bagged_pg_diff_e = new TGraph();
    bagged_pg_diff_e->SetTitle("e^{+} selection e-like cut");
    bagged_pg_diff_e->SetPoint(0, 0.1, 0.274892-refvalue_pg_e);
    bagged_pg_diff_e->SetPoint(1, 0.3, 0.63853-refvalue_pg_e);
    bagged_pg_diff_e->SetPoint(2, 0.5, 0.607112-refvalue_pg_e);
    bagged_pg_diff_e->SetPoint(3, 0.7, 0.600178-refvalue_pg_e);
    bagged_pg_diff_e->SetPoint(4, 0.9, 0.650616-refvalue_pg_e);
    bagged_pg_diff_e->SetLineColor( kMagenta); bagged_pg_diff_e->SetMarkerColor( kMagenta); bagged_pg_diff_e->SetFillColor( kWhite); 
    
    TCanvas* canvas_bagged = new TCanvas("canvas_bagged","",200,10,1000,400);
    canvas_bagged->Divide(2,1,0.005,0.005);
    
    canvas_bagged->cd(1);  
    bagged_pg_mu->GetYaxis()->SetRangeUser(0, 1);
    bagged_pg_mu->GetYaxis()->SetTitleOffset(1.2);
    bagged_pg_mu->GetXaxis()->SetTitle("BaggedSampleFraction"); bagged_pg_mu->GetYaxis()->SetTitle("Efficiency");
    bagged_pg_mu->Draw("AL*");
    bagged_pg_pi->Draw("L* same");
    bagged_pg_p->Draw("L* same");
    bagged_pg_e->Draw("L* same");
    canvas_bagged->cd(1)->BuildLegend();
    
    canvas_bagged->cd(2);  
    bagged_pg_diff_mu->GetYaxis()->SetRangeUser(-0.2, 0.1);
    bagged_pg_diff_mu->GetXaxis()->SetTitle("BaggedSampleFraction"); bagged_pg_diff_mu->GetYaxis()->SetTitle("Difference in efficiency");
    bagged_pg_diff_mu->Draw("AL*");
    bagged_pg_diff_pi->Draw("L* same");
    bagged_pg_diff_p->Draw("L* same");
    bagged_pg_diff_e->Draw("L* same");
    
    // =============== Random Forests ===============
    
    TGraph* randomforests_pg_mu = new TGraph();
    randomforests_pg_mu->SetTitle("#mu^{+} selection mu-like cut");
    randomforests_pg_mu->SetPoint(0, 4, 0.935174);
    randomforests_pg_mu->SetPoint(1, 6, 0.93529);
    randomforests_pg_mu->SetPoint(2, 8, 0.933957);
    randomforests_pg_mu->SetPoint(3, 10, 0.93416);
    randomforests_pg_mu->SetPoint(4, 12, 0.934131);
    randomforests_pg_mu->SetLineColor( kBlue); randomforests_pg_mu->SetMarkerColor( kBlue); randomforests_pg_mu->SetFillColor( kWhite);
    
    TGraph* randomforests_pg_pi = new TGraph();
    randomforests_pg_pi->SetTitle("#pi^{+} selection pi-like cut");
    randomforests_pg_pi->SetPoint(0, 4, 0.587259);
    randomforests_pg_pi->SetPoint(1, 6, 0.590716);
    randomforests_pg_pi->SetPoint(2, 8, 0.58933);
    randomforests_pg_pi->SetPoint(3, 10, 0.588868);
    randomforests_pg_pi->SetPoint(4, 12, 0.58921);
    randomforests_pg_pi->SetLineColor( kRed); randomforests_pg_pi->SetMarkerColor( kRed); randomforests_pg_pi->SetFillColor( kWhite);
    
    TGraph* randomforests_pg_p = new TGraph();
    randomforests_pg_p->SetTitle("p selection p-like cut");
    randomforests_pg_p->SetPoint(0, 4, 0.915831);
    randomforests_pg_p->SetPoint(1, 6, 0.914777);
    randomforests_pg_p->SetPoint(2, 8, 0.917076);
    randomforests_pg_p->SetPoint(3, 10, 0.917525);
    randomforests_pg_p->SetPoint(4, 12, 0.917698);
    randomforests_pg_p->SetLineColor( kGreen); randomforests_pg_p->SetMarkerColor( kGreen); randomforests_pg_p->SetFillColor( kWhite); 
    
    TGraph* randomforests_pg_e = new TGraph();
    randomforests_pg_e->SetTitle("e^{+} selection e-like cut");
    randomforests_pg_e->SetPoint(0, 4, 0.667394);
    randomforests_pg_e->SetPoint(1, 6, 0.637045);
    randomforests_pg_e->SetPoint(2, 8, 0.652546);
    randomforests_pg_e->SetPoint(3, 10, 0.652546);
    randomforests_pg_e->SetPoint(4, 12, 0.658233);
    randomforests_pg_e->SetLineColor( kMagenta); randomforests_pg_e->SetMarkerColor( kMagenta); randomforests_pg_e->SetFillColor( kWhite); 
    
    TGraph* randomforests_pg_diff_mu = new TGraph();
    randomforests_pg_diff_mu->SetTitle("#mu^{+} selection mu-like cut");
    randomforests_pg_diff_mu->SetPoint(0, 4, 0.935174-refvalue_pg_mu);
    randomforests_pg_diff_mu->SetPoint(1, 6, 0.93529-refvalue_pg_mu);
    randomforests_pg_diff_mu->SetPoint(2, 8, 0.933957-refvalue_pg_mu);
    randomforests_pg_diff_mu->SetPoint(3, 10, 0.93416-refvalue_pg_mu);
    randomforests_pg_diff_mu->SetPoint(4, 12, 0.934131-refvalue_pg_mu);
    randomforests_pg_diff_mu->SetLineColor( kBlue); randomforests_pg_diff_mu->SetMarkerColor( kBlue); randomforests_pg_diff_mu->SetFillColor( kWhite);
    
    TGraph* randomforests_pg_diff_pi = new TGraph();
    randomforests_pg_diff_pi->SetTitle("#pi^{+} selection pi-like cut");
    randomforests_pg_diff_pi->SetPoint(0, 4, 0.587259-refvalue_pg_pi);
    randomforests_pg_diff_pi->SetPoint(1, 6, 0.590716-refvalue_pg_pi);
    randomforests_pg_diff_pi->SetPoint(2, 8, 0.58933-refvalue_pg_pi);
    randomforests_pg_diff_pi->SetPoint(3, 10, 0.588868-refvalue_pg_pi);
    randomforests_pg_diff_pi->SetPoint(4, 12, 0.58921-refvalue_pg_pi);
    randomforests_pg_diff_pi->SetLineColor( kRed); randomforests_pg_diff_pi->SetMarkerColor( kRed); randomforests_pg_diff_pi->SetFillColor( kWhite);
    
    TGraph* randomforests_pg_diff_p = new TGraph();
    randomforests_pg_diff_p->SetTitle("p selection p-like cut");
    randomforests_pg_diff_p->SetPoint(0, 4, 0.915831-refvalue_pg_p);
    randomforests_pg_diff_p->SetPoint(1, 6, 0.914777-refvalue_pg_p);
    randomforests_pg_diff_p->SetPoint(2, 8, 0.917076-refvalue_pg_p);
    randomforests_pg_diff_p->SetPoint(3, 10, 0.917525-refvalue_pg_p);
    randomforests_pg_diff_p->SetPoint(4, 12, 0.917698-refvalue_pg_p);
    randomforests_pg_diff_p->SetLineColor( kGreen); randomforests_pg_diff_p->SetMarkerColor( kGreen); randomforests_pg_diff_p->SetFillColor( kWhite); 
    
    TGraph* randomforests_pg_diff_e = new TGraph();
    randomforests_pg_diff_e->SetTitle("e^{+} selection e-like cut");
    randomforests_pg_diff_e->SetPoint(0, 4, 0.667394-refvalue_pg_e);
    randomforests_pg_diff_e->SetPoint(1, 6, 0.637045-refvalue_pg_e);
    randomforests_pg_diff_e->SetPoint(2, 8, 0.652546-refvalue_pg_e);
    randomforests_pg_diff_e->SetPoint(3, 10, 0.660772-refvalue_pg_e);
    randomforests_pg_diff_e->SetPoint(4, 12, 0.658233-refvalue_pg_e);
    randomforests_pg_diff_e->SetLineColor( kMagenta); randomforests_pg_diff_e->SetMarkerColor( kMagenta); randomforests_pg_diff_e->SetFillColor( kWhite); 
    
    TCanvas* canvas_randomforests = new TCanvas("canvas_randomforests","",200,10,1000,400);
    canvas_randomforests->Divide(2,1,0.005,0.005);
    
    canvas_randomforests->cd(1);
    randomforests_pg_mu->GetYaxis()->SetRangeUser(0, 1);
    randomforests_pg_mu->GetYaxis()->SetTitleOffset(1.2);
    randomforests_pg_mu->GetXaxis()->SetTitle("Random forests NVars"); randomforests_pg_mu->GetYaxis()->SetTitle("Efficiency");
    randomforests_pg_mu->Draw("AL*");
    randomforests_pg_pi->Draw("L* same");
    randomforests_pg_p->Draw("L* same");
    randomforests_pg_e->Draw("L* same");
    canvas_randomforests->cd(1)->BuildLegend();
    
    canvas_randomforests->cd(2);
    randomforests_pg_diff_mu->GetYaxis()->SetRangeUser(-0.03, 0.05);
    randomforests_pg_diff_mu->GetXaxis()->SetTitle("Random forests NVars"); randomforests_pg_diff_mu->GetYaxis()->SetTitle("Difference in efficiency");
    randomforests_pg_diff_mu->Draw("AL*");
    randomforests_pg_diff_pi->Draw("L* same");
    randomforests_pg_diff_p->Draw("L* same");
    randomforests_pg_diff_e->Draw("L* same");
    
    
}
