{
    gStyle->SetTitleYOffset(1.5);
    
    Float_t refvalue_cc1pi_mu, refvalue_cc1pi_pi, refvalue_pg_mu, refvalue_pg_pi, refvalue_pg_p, refvalue_pg_e;
    
    // =============== Tree depth ===============
    
    refvalue_pg_mu = 0.932088;
    TGraph* treedepth_pg_mu = new TGraph();
    treedepth_pg_mu->SetTitle("#mu^{+} identified as #mu^{+}");
    treedepth_pg_mu->SetPoint(0, 2.0, 0.93135);
    treedepth_pg_mu->SetPoint(1, 3.0, 0.932088);
    treedepth_pg_mu->SetPoint(2, 4.0, 0.931205);
    treedepth_pg_mu->SetPoint(3, 5.0, 0.930452);
    treedepth_pg_mu->SetLineColor( kBlue); treedepth_pg_mu->SetMarkerColor( kBlue); treedepth_pg_mu->SetFillColor( kWhite);
    
    refvalue_pg_pi = 0.617709;
    TGraph* treedepth_pg_pi = new TGraph();
    treedepth_pg_pi->SetTitle("#pi^{+} identified as #pi^{+}");
    treedepth_pg_pi->SetPoint(0, 2.0, 0.614114);
    treedepth_pg_pi->SetPoint(1, 3.0, 0.617709);
    treedepth_pg_pi->SetPoint(2, 4.0, 0.620858);
    treedepth_pg_pi->SetPoint(3, 5.0, 0.622244);
    treedepth_pg_pi->SetLineColor( kRed); treedepth_pg_pi->SetMarkerColor( kRed); treedepth_pg_pi->SetFillColor( kWhite); 
    
    refvalue_pg_p = 0.911146;
    TGraph* treedepth_pg_p = new TGraph();
    treedepth_pg_p->SetTitle("p identified as p");
    treedepth_pg_p->SetPoint(0, 2.0, 0.90501);
    treedepth_pg_p->SetPoint(1, 3.0, 0.911146);
    treedepth_pg_p->SetPoint(2, 4.0, 0.913739);
    treedepth_pg_p->SetPoint(3, 5.0, 0.914362);
    treedepth_pg_p->SetLineColor( kGreen); treedepth_pg_p->SetMarkerColor( kGreen); treedepth_pg_p->SetFillColor( kWhite); 
    
    refvalue_pg_e = 0.603816;
    TGraph* treedepth_pg_e = new TGraph();
    treedepth_pg_e->SetTitle("e^{+} identified as e^{+}");
    treedepth_pg_e->SetPoint(0, 2.0, 0.579659);
    treedepth_pg_e->SetPoint(1, 3.0, 0.603816);
    treedepth_pg_e->SetPoint(2, 4.0, 0.627854);
    treedepth_pg_e->SetPoint(3, 5.0, 0.645301);
    treedepth_pg_e->SetLineColor( kMagenta); treedepth_pg_e->SetMarkerColor( kMagenta); treedepth_pg_e->SetFillColor( kWhite); 
    
    TGraph* treedepth_pg_diff_mu = new TGraph();
    treedepth_pg_diff_mu->SetPoint(0, 2.0, 0.93135-refvalue_pg_mu);
    treedepth_pg_diff_mu->SetPoint(1, 3.0, 0.932088-refvalue_pg_mu);
    treedepth_pg_diff_mu->SetPoint(2, 4.0, 0.931205-refvalue_pg_mu);
    treedepth_pg_diff_mu->SetPoint(3, 5.0, 0.930452-refvalue_pg_mu);
    treedepth_pg_diff_mu->SetLineColor( kBlue); treedepth_pg_diff_mu->SetMarkerColor( kBlue); treedepth_pg_diff_mu->SetFillColor( kWhite);
    
    TGraph* treedepth_pg_diff_pi = new TGraph();
    treedepth_pg_diff_pi->SetPoint(0, 2.0, 0.614114-refvalue_pg_pi);
    treedepth_pg_diff_pi->SetPoint(1, 3.0, 0.617709-refvalue_pg_pi);
    treedepth_pg_diff_pi->SetPoint(2, 4.0, 0.620858-refvalue_pg_pi);
    treedepth_pg_diff_pi->SetPoint(3, 5.0, 0.622244-refvalue_pg_pi);
    treedepth_pg_diff_pi->SetLineColor( kRed); treedepth_pg_diff_pi->SetMarkerColor( kRed); treedepth_pg_diff_pi->SetFillColor( kWhite); 
    
    TGraph* treedepth_pg_diff_p = new TGraph();
    treedepth_pg_diff_p->SetPoint(0, 2.0, 0.90501-refvalue_pg_p);
    treedepth_pg_diff_p->SetPoint(1, 3.0, 0.911146-refvalue_pg_p);
    treedepth_pg_diff_p->SetPoint(2, 4.0, 0.913739-refvalue_pg_p);
    treedepth_pg_diff_p->SetPoint(3, 5.0, 0.914362-refvalue_pg_p);
    treedepth_pg_diff_p->SetLineColor( kGreen); treedepth_pg_diff_p->SetMarkerColor( kGreen); treedepth_pg_diff_p->SetFillColor( kWhite); 
    
    TGraph* treedepth_pg_diff_e = new TGraph();
    treedepth_pg_diff_e->SetPoint(0, 2.0, 0.579659-refvalue_pg_e);
    treedepth_pg_diff_e->SetPoint(1, 3.0, 0.603816-refvalue_pg_e);
    treedepth_pg_diff_e->SetPoint(2, 4.0, 0.627854-refvalue_pg_e);
    treedepth_pg_diff_e->SetPoint(3, 5.0, 0.645301-refvalue_pg_e);
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
    
    refvalue_pg_mu = 0.931205;
    refvalue_pg_pi = 0.620858;
    refvalue_pg_p = 0.913739;
    refvalue_pg_e = 0.627854;
    
    TGraph* treenumber_pg_mu = new TGraph();
    treenumber_pg_mu->SetTitle("#mu^{+} identified as #mu^{+}");
    treenumber_pg_mu->SetPoint(0, 500.0, 0.932451);
    treenumber_pg_mu->SetPoint(1, 750.0, 0.931668);
    treenumber_pg_mu->SetPoint(2, 1000.0, 0.931205);
    treenumber_pg_mu->SetPoint(3, 1100.0, 0.931292);
    treenumber_pg_mu->SetPoint(4, 1200.0, 0.931364);
    treenumber_pg_mu->SetPoint(5, 1300.0, 0.930437);
    treenumber_pg_mu->SetPoint(6, 1400.0, 0.929973);
    treenumber_pg_mu->SetPoint(7, 1500.0, 0.929191);
    treenumber_pg_mu->SetPoint(8, 2000.0, 0.92754);
    treenumber_pg_mu->SetPoint(9, 2500.0, 0.92499);
    treenumber_pg_mu->SetLineColor( kBlue); treenumber_pg_mu->SetMarkerColor( kBlue); treenumber_pg_mu->SetFillColor( kWhite);
    
    TGraph* treenumber_pg_pi = new TGraph();
    treenumber_pg_pi->SetTitle("#pi^{+} identified as #pi^{+}");
    treenumber_pg_pi->SetPoint(0, 500.0, 0.618975);
    treenumber_pg_pi->SetPoint(1, 750.0, 0.620088);
    treenumber_pg_pi->SetPoint(2, 1000.0, 0.620858);
    treenumber_pg_pi->SetPoint(3, 1100.0, 0.620721);
    treenumber_pg_pi->SetPoint(4, 1200.0, 0.620789);
    treenumber_pg_pi->SetPoint(5, 1300.0, 0.622552);
    treenumber_pg_pi->SetPoint(6, 1400.0, 0.622381);
    treenumber_pg_pi->SetPoint(7, 1500.0, 0.623134);
    treenumber_pg_pi->SetPoint(8, 2000.0, 0.626472);
    treenumber_pg_pi->SetPoint(9, 2500.0, 0.629211);
    treenumber_pg_pi->SetLineColor( kRed); treenumber_pg_pi->SetMarkerColor( kRed); treenumber_pg_pi->SetFillColor( kWhite);
    
    TGraph* treenumber_pg_p = new TGraph();
    treenumber_pg_p->SetTitle("p identified as p");
    treenumber_pg_p->SetPoint(0, 500.0, 0.908744);
    treenumber_pg_p->SetPoint(1, 750.0, 0.911873);
    treenumber_pg_p->SetPoint(2, 1000.0, 0.913739);
    treenumber_pg_p->SetPoint(3, 1100.0, 0.914465);
    treenumber_pg_p->SetPoint(4, 1200.0, 0.914483);
    treenumber_pg_p->SetPoint(5, 1300.0, 0.915382);
    treenumber_pg_p->SetPoint(6, 1400.0, 0.915537);
    treenumber_pg_p->SetPoint(7, 1500.0, 0.916142);
    treenumber_pg_p->SetPoint(8, 2000.0, 0.915969);
    treenumber_pg_p->SetPoint(9, 2500.0, 0.916799);
    treenumber_pg_p->SetLineColor( kGreen); treenumber_pg_p->SetMarkerColor( kGreen); treenumber_pg_p->SetFillColor( kWhite); 
    
    TGraph* treenumber_pg_e = new TGraph();
    treenumber_pg_e->SetTitle("e^{+} identified as e^{+}");
    treenumber_pg_e->SetPoint(0, 500.0, 0.573779);
    treenumber_pg_e->SetPoint(1, 750.0, 0.606578);
    treenumber_pg_e->SetPoint(2, 1000.0, 0.627854);
    treenumber_pg_e->SetPoint(3, 1100.0, 0.624633);
    treenumber_pg_e->SetPoint(4, 1200.0, 0.635486);
    treenumber_pg_e->SetPoint(5, 1300.0, 0.644157);
    treenumber_pg_e->SetPoint(6, 1400.0, 0.640178);
    treenumber_pg_e->SetPoint(7, 1500.0, 0.64637);
    treenumber_pg_e->SetPoint(8, 2000.0, 0.654328);
    treenumber_pg_e->SetPoint(9, 2500.0, 0.656125);
    treenumber_pg_e->SetLineColor( kMagenta); treenumber_pg_e->SetMarkerColor( kMagenta); treenumber_pg_e->SetFillColor( kWhite); 
    
    TGraph* treenumber_pg_diff_mu = new TGraph();
    treenumber_pg_diff_mu->SetPoint(0, 500.0, 0.932451-refvalue_pg_mu);
    treenumber_pg_diff_mu->SetPoint(1, 750.0, 0.931668-refvalue_pg_mu);
    treenumber_pg_diff_mu->SetPoint(2, 1000.0, 0.931205-refvalue_pg_mu);
    treenumber_pg_diff_mu->SetPoint(3, 1100.0, 0.931292-refvalue_pg_mu);
    treenumber_pg_diff_mu->SetPoint(4, 1200.0, 0.931364-refvalue_pg_mu);
    treenumber_pg_diff_mu->SetPoint(5, 1300.0, 0.930437-refvalue_pg_mu);
    treenumber_pg_diff_mu->SetPoint(6, 1400.0, 0.929973-refvalue_pg_mu);
    treenumber_pg_diff_mu->SetPoint(7, 1500.0, 0.929191-refvalue_pg_mu);
    treenumber_pg_diff_mu->SetPoint(8, 2000.0, 0.92754-refvalue_pg_mu);
    treenumber_pg_diff_mu->SetPoint(9, 2500.0, 0.92499-refvalue_pg_mu);
    treenumber_pg_diff_mu->SetLineColor( kBlue); treenumber_pg_diff_mu->SetMarkerColor( kBlue); treenumber_pg_diff_mu->SetFillColor( kWhite);
    
    TGraph* treenumber_pg_diff_pi = new TGraph();
    treenumber_pg_diff_pi->SetPoint(0, 500.0, 0.618975-refvalue_pg_pi);
    treenumber_pg_diff_pi->SetPoint(1, 750.0, 0.620088-refvalue_pg_pi);
    treenumber_pg_diff_pi->SetPoint(2, 1000.0, 0.620858-refvalue_pg_pi);
    treenumber_pg_diff_pi->SetPoint(3, 1100.0, 0.620721-refvalue_pg_pi);
    treenumber_pg_diff_pi->SetPoint(4, 1200.0, 0.620789-refvalue_pg_pi);
    treenumber_pg_diff_pi->SetPoint(5, 1300.0, 0.622552-refvalue_pg_pi);
    treenumber_pg_diff_pi->SetPoint(6, 1400.0, 0.622381-refvalue_pg_pi);
    treenumber_pg_diff_pi->SetPoint(7, 1500.0, 0.623134-refvalue_pg_pi);
    treenumber_pg_diff_pi->SetPoint(8, 2000.0, 0.626472-refvalue_pg_pi);
    treenumber_pg_diff_pi->SetPoint(9, 2500.0, 0.629211-refvalue_pg_pi);
    treenumber_pg_diff_pi->SetLineColor( kRed); treenumber_pg_diff_pi->SetMarkerColor( kRed); treenumber_pg_diff_pi->SetFillColor( kWhite);
    
    TGraph* treenumber_pg_diff_p = new TGraph();
    treenumber_pg_diff_p->SetPoint(0, 500.0, 0.908744-refvalue_pg_p);
    treenumber_pg_diff_p->SetPoint(1, 750.0, 0.911873-refvalue_pg_p);
    treenumber_pg_diff_p->SetPoint(2, 1000.0, 0.913739-refvalue_pg_p);
    treenumber_pg_diff_p->SetPoint(3, 1100.0, 0.914465-refvalue_pg_p);
    treenumber_pg_diff_p->SetPoint(4, 1200.0, 0.914483-refvalue_pg_p);
    treenumber_pg_diff_p->SetPoint(5, 1300.0, 0.915382-refvalue_pg_p);
    treenumber_pg_diff_p->SetPoint(6, 1400.0, 0.915537-refvalue_pg_p);
    treenumber_pg_diff_p->SetPoint(7, 1500.0, 0.916142-refvalue_pg_p);
    treenumber_pg_diff_p->SetPoint(8, 2000.0, 0.915969-refvalue_pg_p);
    treenumber_pg_diff_p->SetPoint(9, 2500.0, 0.916799-refvalue_pg_p);
    treenumber_pg_diff_p->SetLineColor( kGreen); treenumber_pg_diff_p->SetMarkerColor( kGreen); treenumber_pg_diff_p->SetFillColor( kWhite); 
    
    TGraph* treenumber_pg_diff_e = new TGraph();
    treenumber_pg_diff_e->SetPoint(0, 500.0, 0.573779-refvalue_pg_e);
    treenumber_pg_diff_e->SetPoint(1, 750.0, 0.606578-refvalue_pg_e);
    treenumber_pg_diff_e->SetPoint(2, 1000.0, 0.627854-refvalue_pg_e);
    treenumber_pg_diff_e->SetPoint(3, 1100.0, 0.624633-refvalue_pg_e);
    treenumber_pg_diff_e->SetPoint(4, 1200.0, 0.635486-refvalue_pg_e);
    treenumber_pg_diff_e->SetPoint(5, 1300.0, 0.644157-refvalue_pg_e);
    treenumber_pg_diff_e->SetPoint(6, 1400.0, 0.640178-refvalue_pg_e);
    treenumber_pg_diff_e->SetPoint(7, 1500.0, 0.64637-refvalue_pg_e);
    treenumber_pg_diff_e->SetPoint(8, 2000.0, 0.654328-refvalue_pg_e);
    treenumber_pg_diff_e->SetPoint(9, 2500.0, 0.656125-refvalue_pg_e);
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
    treenumber_pg_diff_mu->GetYaxis()->SetRangeUser(-0.06, 0.03);
    treenumber_pg_diff_mu->GetXaxis()->SetTitle("Number of trees"); treenumber_pg_diff_mu->GetYaxis()->SetTitle("Difference in efficiency");
    treenumber_pg_diff_mu->Draw("AL*");
    treenumber_pg_diff_pi->Draw("L* same");
    treenumber_pg_diff_p->Draw("L* same");
    treenumber_pg_diff_e->Draw("L* same");
    
    // =============== Shrinkage ===============
    
    refvalue_pg_mu = 0.929191;
    refvalue_pg_pi = 0.623134;
    refvalue_pg_p = 0.916142;
    refvalue_pg_e = 0.64637;
    
    TGraph* shrinkage_pg_mu = new TGraph();
    shrinkage_pg_mu->SetTitle("#mu^{+} identified as #mu^{+}");
    shrinkage_pg_mu->SetPoint(0, 0.1, 0.934377);
    shrinkage_pg_mu->SetPoint(1, 0.3, 0.934247);
    shrinkage_pg_mu->SetPoint(2, 0.5, 0.933421);
    shrinkage_pg_mu->SetPoint(3, 0.7, 0.93177);
    shrinkage_pg_mu->SetPoint(4, 0.9, 0.930205);
    shrinkage_pg_mu->SetLineColor( kBlue); shrinkage_pg_mu->SetMarkerColor( kBlue); shrinkage_pg_mu->SetFillColor( kWhite);
    
    TGraph* shrinkage_pg_pi = new TGraph();
    shrinkage_pg_pi->SetTitle("#pi^{+} identified as #pi^{+}");
    shrinkage_pg_pi->SetPoint(0, 0.1, 0.615946);
    shrinkage_pg_pi->SetPoint(1, 0.3, 0.616254);
    shrinkage_pg_pi->SetPoint(2, 0.5, 0.617931);
    shrinkage_pg_pi->SetPoint(3, 0.7, 0.619454);
    shrinkage_pg_pi->SetPoint(4, 0.9, 0.623648);
    shrinkage_pg_pi->SetLineColor( kRed); shrinkage_pg_pi->SetMarkerColor( kRed); shrinkage_pg_pi->SetFillColor( kWhite);
    
    TGraph* shrinkage_pg_p = new TGraph();
    shrinkage_pg_p->SetTitle("p identified as p");
    shrinkage_pg_p->SetPoint(0, 0.1, 0.891837);
    shrinkage_pg_p->SetPoint(1, 0.3, 0.910351);
    shrinkage_pg_p->SetPoint(2, 0.5, 0.913722);
    shrinkage_pg_p->SetPoint(3, 0.7, 0.914552);
    shrinkage_pg_p->SetPoint(4, 0.9, 0.915555);
    shrinkage_pg_p->SetLineColor( kGreen); shrinkage_pg_p->SetMarkerColor( kGreen); shrinkage_pg_p->SetFillColor( kWhite); 
    
    TGraph* shrinkage_pg_e = new TGraph();
    shrinkage_pg_e->SetTitle("e^{+} identified as e^{+}");
    shrinkage_pg_e->SetPoint(0, 0.1, 0.438055);
    shrinkage_pg_e->SetPoint(1, 0.3, 0.583727);
    shrinkage_pg_e->SetPoint(2, 0.5, 0.619837);
    shrinkage_pg_e->SetPoint(3, 0.7, 0.635471);
    shrinkage_pg_e->SetPoint(4, 0.9, 0.637416);
    shrinkage_pg_e->SetLineColor( kMagenta); shrinkage_pg_e->SetMarkerColor( kMagenta); shrinkage_pg_e->SetFillColor( kWhite); 
    
    TGraph* shrinkage_pg_diff_mu = new TGraph();
    shrinkage_pg_diff_mu->SetPoint(0, 0.1, 0.934377-refvalue_pg_mu);
    shrinkage_pg_diff_mu->SetPoint(1, 0.3, 0.934247-refvalue_pg_mu);
    shrinkage_pg_diff_mu->SetPoint(2, 0.5, 0.933421-refvalue_pg_mu);
    shrinkage_pg_diff_mu->SetPoint(3, 0.7, 0.93177-refvalue_pg_mu);
    shrinkage_pg_diff_mu->SetPoint(4, 0.9, 0.930205-refvalue_pg_mu);
    shrinkage_pg_diff_mu->SetLineColor( kBlue); shrinkage_pg_diff_mu->SetMarkerColor( kBlue); shrinkage_pg_diff_mu->SetFillColor( kWhite);
    
    TGraph* shrinkage_pg_diff_pi = new TGraph();
    shrinkage_pg_diff_pi->SetPoint(0, 0.1, 0.615946-refvalue_pg_pi);
    shrinkage_pg_diff_pi->SetPoint(1, 0.3, 0.616254-refvalue_pg_pi);
    shrinkage_pg_diff_pi->SetPoint(2, 0.5, 0.617931-refvalue_pg_pi);
    shrinkage_pg_diff_pi->SetPoint(3, 0.7, 0.619454-refvalue_pg_pi);
    shrinkage_pg_diff_pi->SetPoint(4, 0.9, 0.623648-refvalue_pg_pi);
    shrinkage_pg_diff_pi->SetLineColor( kRed); shrinkage_pg_diff_pi->SetMarkerColor( kRed); shrinkage_pg_diff_pi->SetFillColor( kWhite);
    
    TGraph* shrinkage_pg_diff_p = new TGraph();
    shrinkage_pg_diff_p->SetPoint(0, 0.1, 0.891837-refvalue_pg_p);
    shrinkage_pg_diff_p->SetPoint(1, 0.3, 0.910351-refvalue_pg_p);
    shrinkage_pg_diff_p->SetPoint(2, 0.5, 0.913722-refvalue_pg_p);
    shrinkage_pg_diff_p->SetPoint(3, 0.7, 0.914552-refvalue_pg_p);
    shrinkage_pg_diff_p->SetPoint(4, 0.9, 0.915555-refvalue_pg_p);
    shrinkage_pg_diff_p->SetLineColor( kGreen); shrinkage_pg_diff_p->SetMarkerColor( kGreen); shrinkage_pg_diff_p->SetFillColor( kWhite); 
    
    TGraph* shrinkage_pg_diff_e = new TGraph();
    shrinkage_pg_diff_e->SetPoint(0, 0.1, 0.438055-refvalue_pg_e);
    shrinkage_pg_diff_e->SetPoint(1, 0.3, 0.583727-refvalue_pg_e);
    shrinkage_pg_diff_e->SetPoint(2, 0.5, 0.619837-refvalue_pg_e);
    shrinkage_pg_diff_e->SetPoint(3, 0.7, 0.635471-refvalue_pg_e);
    shrinkage_pg_diff_e->SetPoint(4, 0.9, 0.637416-refvalue_pg_e);
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
    shrinkage_pg_diff_mu->GetYaxis()->SetRangeUser(-0.5, 0.5);
    shrinkage_pg_diff_mu->GetXaxis()->SetTitle("Shrinkage"); shrinkage_pg_diff_mu->GetYaxis()->SetTitle("Difference in efficiency");
    shrinkage_pg_diff_mu->Draw("AL*");
    shrinkage_pg_diff_pi->Draw("L* same");
    shrinkage_pg_diff_p->Draw("L* same");
    shrinkage_pg_diff_e->Draw("L* same");
    
    // =============== Shrinkage (extra) ===============
    /*
    TGraph* shrinkage_extra_pg_mu = new TGraph();
    shrinkage_extra_pg_mu->SetTitle("#mu^{+} identified as #mu^{+}");
    shrinkage_extra_pg_mu->SetPoint(0, 0.1, 0.);
    shrinkage_extra_pg_mu->SetPoint(1, 0.3, 0.);
    shrinkage_extra_pg_mu->SetPoint(2, 0.5, 0.);
    shrinkage_extra_pg_mu->SetPoint(3, 0.7, 0.);
    shrinkage_extra_pg_mu->SetPoint(4, 0.9, 0.);
    shrinkage_extra_pg_mu->SetLineColor( kBlue); shrinkage_extra_pg_mu->SetMarkerColor( kBlue); shrinkage_extra_pg_mu->SetFillColor( kWhite);
    
    TGraph* shrinkage_extra_pg_pi = new TGraph();
    shrinkage_extra_pg_pi->SetTitle("#pi^{+} identified as #pi^{+}");
    shrinkage_extra_pg_pi->SetPoint(0, 0.1, 0.);
    shrinkage_extra_pg_pi->SetPoint(1, 0.3, 0.);
    shrinkage_extra_pg_pi->SetPoint(2, 0.5, 0.);
    shrinkage_extra_pg_pi->SetPoint(3, 0.7, 0.);
    shrinkage_extra_pg_pi->SetPoint(4, 0.9, 0.);
    shrinkage_extra_pg_pi->SetLineColor( kRed); shrinkage_extra_pg_pi->SetMarkerColor( kRed); shrinkage_extra_pg_pi->SetFillColor( kWhite);
    
    TGraph* shrinkage_extra_pg_p = new TGraph();
    shrinkage_extra_pg_p->SetTitle("p identified as p");
    shrinkage_extra_pg_p->SetPoint(0, 0.1, 0.);
    shrinkage_extra_pg_p->SetPoint(1, 0.3, 0.);
    shrinkage_extra_pg_p->SetPoint(2, 0.5, 0.);
    shrinkage_extra_pg_p->SetPoint(3, 0.7, 0.);
    shrinkage_extra_pg_p->SetPoint(4, 0.9, 0.);
    shrinkage_extra_pg_p->SetLineColor( kGreen); shrinkage_extra_pg_p->SetMarkerColor( kGreen); shrinkage_extra_pg_p->SetFillColor( kWhite); 
    
    TGraph* shrinkage_extra_pg_e = new TGraph();
    shrinkage_extra_pg_e->SetTitle("e^{+} identified as e^{+}");
    shrinkage_extra_pg_e->SetPoint(0, 0.1, 0.);
    shrinkage_extra_pg_e->SetPoint(1, 0.3, 0.);
    shrinkage_extra_pg_e->SetPoint(2, 0.5, 0.);
    shrinkage_extra_pg_e->SetPoint(3, 0.7, 0.);
    shrinkage_extra_pg_e->SetPoint(4, 0.9, 0.);
    shrinkage_extra_pg_e->SetLineColor( kMagenta); shrinkage_extra_pg_e->SetMarkerColor( kMagenta); shrinkage_extra_pg_e->SetFillColor( kWhite); 
    
    TGraph* shrinkage_extra_pg_diff_mu = new TGraph();
    shrinkage_extra_pg_diff_mu->SetPoint(0, 0.1, 0.-refvalue_pg_mu);
    shrinkage_extra_pg_diff_mu->SetPoint(1, 0.3, 0.-refvalue_pg_mu);
    shrinkage_extra_pg_diff_mu->SetPoint(2, 0.5, 0.-refvalue_pg_mu);
    shrinkage_extra_pg_diff_mu->SetPoint(3, 0.7, 0.-refvalue_pg_mu);
    shrinkage_extra_pg_diff_mu->SetPoint(4, 0.9, 0.-refvalue_pg_mu);
    shrinkage_extra_pg_diff_mu->SetLineColor( kBlue); shrinkage_extra_pg_diff_mu->SetMarkerColor( kBlue); shrinkage_extra_pg_diff_mu->SetFillColor( kWhite);
    
    TGraph* shrinkage_extra_pg_diff_pi = new TGraph();
    shrinkage_extra_pg_diff_pi->SetPoint(0, 0.1, 0.-refvalue_pg_pi);
    shrinkage_extra_pg_diff_pi->SetPoint(1, 0.3, 0.-refvalue_pg_pi);
    shrinkage_extra_pg_diff_pi->SetPoint(2, 0.5, 0.-refvalue_pg_pi);
    shrinkage_extra_pg_diff_pi->SetPoint(3, 0.7, 0.-refvalue_pg_pi);
    shrinkage_extra_pg_diff_pi->SetPoint(4, 0.9, 0.-refvalue_pg_pi);
    shrinkage_extra_pg_diff_pi->SetLineColor( kRed); shrinkage_extra_pg_diff_pi->SetMarkerColor( kRed); shrinkage_extra_pg_diff_pi->SetFillColor( kWhite);
    
    TGraph* shrinkage_extra_pg_diff_p = new TGraph();
    shrinkage_extra_pg_diff_p->SetPoint(0, 0.1, 0.-refvalue_pg_p);
    shrinkage_extra_pg_diff_p->SetPoint(1, 0.3, 0.-refvalue_pg_p);
    shrinkage_extra_pg_diff_p->SetPoint(2, 0.5, 0.-refvalue_pg_p);
    shrinkage_extra_pg_diff_p->SetPoint(3, 0.7, 0.-refvalue_pg_p);
    shrinkage_extra_pg_diff_p->SetPoint(4, 0.9, 0.-refvalue_pg_p);
    shrinkage_extra_pg_diff_p->SetLineColor( kGreen); shrinkage_extra_pg_diff_p->SetMarkerColor( kGreen); shrinkage_extra_pg_diff_p->SetFillColor( kWhite); 
    
    TGraph* shrinkage_extra_pg_diff_e = new TGraph();
    shrinkage_extra_pg_diff_e->SetPoint(0, 0.1, 0.-refvalue_pg_e);
    shrinkage_extra_pg_diff_e->SetPoint(1, 0.3, 0.-refvalue_pg_e);
    shrinkage_extra_pg_diff_e->SetPoint(2, 0.5, 0.-refvalue_pg_e);
    shrinkage_extra_pg_diff_e->SetPoint(3, 0.7, 0.-refvalue_pg_e);
    shrinkage_extra_pg_diff_e->SetPoint(4, 0.9, 0.-refvalue_pg_e);
    shrinkage_extra_pg_diff_e->SetLineColor( kMagenta); shrinkage_extra_pg_diff_e->SetMarkerColor( kMagenta); shrinkage_extra_pg_diff_e->SetFillColor( kWhite); 
    
    TCanvas* canvas_shrinkage_extra = new TCanvas("canvas_shrinkage_extra","",200,10,1000,400);
    canvas_shrinkage_extra->Divide(2,1,0.005,0.005);
    
    canvas_shrinkage_extra->cd(1);  
    shrinkage_extra_pg_mu->GetYaxis()->SetRangeUser(0, 1);
    shrinkage_extra_pg_mu->GetYaxis()->SetTitleOffset(1.2);
    shrinkage_extra_pg_mu->GetXaxis()->SetTitle("Shrinkage"); shrinkage_extra_pg_mu->GetYaxis()->SetTitle("Efficiency");
    shrinkage_extra_pg_mu->Draw("AL*");
    shrinkage_extra_pg_pi->Draw("L* same");
    shrinkage_extra_pg_p->Draw("L* same");
    shrinkage_extra_pg_e->Draw("L* same");
    canvas_shrinkage_extra->cd(1)->BuildLegend();
    
    canvas_shrinkage_extra->cd(2);  
    shrinkage_extra_pg_diff_mu->GetYaxis()->SetRangeUser(-0.15, 0.04);
    shrinkage_extra_pg_diff_mu->GetXaxis()->SetTitle("Shrinkage"); shrinkage_extra_pg_diff_mu->GetYaxis()->SetTitle("Difference in efficiency");
    shrinkage_extra_pg_diff_mu->Draw("AL*");
    shrinkage_extra_pg_diff_pi->Draw("L* same");
    shrinkage_extra_pg_diff_p->Draw("L* same");
    shrinkage_extra_pg_diff_e->Draw("L* same");*/
    
    // =============== Bagged ===============
    
    TGraph* bagged_pg_mu = new TGraph();
    bagged_pg_mu->SetTitle("#mu^{+} identified as #mu^{+}");
    bagged_pg_mu->SetPoint(0, 0.1, 0.826918);
    bagged_pg_mu->SetPoint(1, 0.3, 0.923324);
    bagged_pg_mu->SetPoint(2, 0.5, 0.923759);
    bagged_pg_mu->SetPoint(3, 0.7, 0.923846);
    bagged_pg_mu->SetPoint(4, 0.9, 0.922817);
    bagged_pg_mu->SetLineColor( kBlue); bagged_pg_mu->SetMarkerColor( kBlue); bagged_pg_mu->SetFillColor( kWhite);
    
    TGraph* bagged_pg_pi = new TGraph();
    bagged_pg_pi->SetTitle("#pi^{+} identified as #pi^{+}");
    bagged_pg_pi->SetPoint(0, 0.1, 0.568859);
    bagged_pg_pi->SetPoint(1, 0.3, 0.618222);
    bagged_pg_pi->SetPoint(2, 0.5, 0.622946);
    bagged_pg_pi->SetPoint(3, 0.7, 0.62565);
    bagged_pg_pi->SetPoint(4, 0.9, 0.629638);
    bagged_pg_pi->SetLineColor( kRed); bagged_pg_pi->SetMarkerColor( kRed); bagged_pg_pi->SetFillColor( kWhite);
    
    TGraph* bagged_pg_p = new TGraph();
    bagged_pg_p->SetTitle("p identified as p");
    bagged_pg_p->SetPoint(0, 0.1, 0.853374);
    bagged_pg_p->SetPoint(1, 0.3, 0.909141);
    bagged_pg_p->SetPoint(2, 0.5, 0.914414);
    bagged_pg_p->SetPoint(3, 0.7, 0.911873);
    bagged_pg_p->SetPoint(4, 0.9, 0.912564);
    bagged_pg_p->SetLineColor( kGreen); bagged_pg_p->SetMarkerColor( kGreen); bagged_pg_p->SetFillColor( kWhite); 
    
    TGraph* bagged_pg_e = new TGraph();
    bagged_pg_e->SetTitle("e^{+} identified as e^{+}");
    bagged_pg_e->SetPoint(0, 0.1, 0.32637);
    bagged_pg_e->SetPoint(1, 0.3, 0.64098);
    bagged_pg_e->SetPoint(2, 0.5, 0.618679);
    bagged_pg_e->SetPoint(3, 0.7, 0.622168);
    bagged_pg_e->SetPoint(4, 0.9, 0.626741);
    bagged_pg_e->SetLineColor( kMagenta); bagged_pg_e->SetMarkerColor( kMagenta); bagged_pg_e->SetFillColor( kWhite); 
    
    TGraph* bagged_pg_diff_mu = new TGraph();
    bagged_pg_diff_mu->SetPoint(0, 0.1, 0.826918-refvalue_pg_mu);
    bagged_pg_diff_mu->SetPoint(1, 0.3, 0.923324-refvalue_pg_mu);
    bagged_pg_diff_mu->SetPoint(2, 0.5, 0.923759-refvalue_pg_mu);
    bagged_pg_diff_mu->SetPoint(3, 0.7, 0.923846-refvalue_pg_mu);
    bagged_pg_diff_mu->SetPoint(4, 0.9, 0.922817-refvalue_pg_mu);
    bagged_pg_diff_mu->SetLineColor( kBlue); bagged_pg_diff_mu->SetMarkerColor( kBlue); bagged_pg_diff_mu->SetFillColor( kWhite);
    
    TGraph* bagged_pg_diff_pi = new TGraph();
    bagged_pg_diff_pi->SetPoint(0, 0.1, 0.568859-refvalue_pg_pi);
    bagged_pg_diff_pi->SetPoint(1, 0.3, 0.618222-refvalue_pg_pi);
    bagged_pg_diff_pi->SetPoint(2, 0.5, 0.622946-refvalue_pg_pi);
    bagged_pg_diff_pi->SetPoint(3, 0.7, 0.62565-refvalue_pg_pi);
    bagged_pg_diff_pi->SetPoint(4, 0.9, 0.629638-refvalue_pg_pi);
    bagged_pg_diff_pi->SetLineColor( kRed); bagged_pg_diff_pi->SetMarkerColor( kRed); bagged_pg_diff_pi->SetFillColor( kWhite);
    
    TGraph* bagged_pg_diff_p = new TGraph();
    bagged_pg_diff_p->SetPoint(0, 0.1, 0.853374-refvalue_pg_p);
    bagged_pg_diff_p->SetPoint(1, 0.3, 0.909141-refvalue_pg_p);
    bagged_pg_diff_p->SetPoint(2, 0.5, 0.914414-refvalue_pg_p);
    bagged_pg_diff_p->SetPoint(3, 0.7, 0.911873-refvalue_pg_p);
    bagged_pg_diff_p->SetPoint(4, 0.9, 0.912564-refvalue_pg_p);
    bagged_pg_diff_p->SetLineColor( kGreen); bagged_pg_diff_p->SetMarkerColor( kGreen); bagged_pg_diff_p->SetFillColor( kWhite); 
    
    TGraph* bagged_pg_diff_e = new TGraph();
    bagged_pg_diff_e->SetPoint(0, 0.1, 0.32637-refvalue_pg_e);
    bagged_pg_diff_e->SetPoint(1, 0.3, 0.64098-refvalue_pg_e);
    bagged_pg_diff_e->SetPoint(2, 0.5, 0.618679-refvalue_pg_e);
    bagged_pg_diff_e->SetPoint(3, 0.7, 0.622168-refvalue_pg_e);
    bagged_pg_diff_e->SetPoint(4, 0.9, 0.626741-refvalue_pg_e);
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
    bagged_pg_diff_mu->GetYaxis()->SetRangeUser(-0.25, 0.05);
    bagged_pg_diff_mu->GetXaxis()->SetTitle("BaggedSampleFraction"); bagged_pg_diff_mu->GetYaxis()->SetTitle("Difference in efficiency");
    bagged_pg_diff_mu->Draw("AL*");
    bagged_pg_diff_pi->Draw("L* same");
    bagged_pg_diff_p->Draw("L* same");
    bagged_pg_diff_e->Draw("L* same");
    
    // =============== Random Forests ===============
    
    TGraph* randomforests_pg_mu = new TGraph();
    randomforests_pg_mu->SetTitle("#mu^{+} identified as #mu^{+}");
    randomforests_pg_mu->SetPoint(0, 2, 0.932103);
    randomforests_pg_mu->SetPoint(1, 3, 0.931306);
    randomforests_pg_mu->SetPoint(2, 4, 0.930814);
    randomforests_pg_mu->SetPoint(3, 6, 0.930118);
    randomforests_pg_mu->SetPoint(4, 8, 0.930785);
    randomforests_pg_mu->SetPoint(5, 10, 0.93006);
    randomforests_pg_mu->SetPoint(6, 12, 0.929887);
    randomforests_pg_mu->SetLineColor( kBlue); randomforests_pg_mu->SetMarkerColor( kBlue); randomforests_pg_mu->SetFillColor( kWhite);
    
    TGraph* randomforests_pg_pi = new TGraph();
    randomforests_pg_pi->SetTitle("#pi^{+} identified as #pi^{+}");
    randomforests_pg_pi->SetPoint(0, 2, 0.618547);
    randomforests_pg_pi->SetPoint(1, 3, 0.621098);
    randomforests_pg_pi->SetPoint(2, 4, 0.619899);
    randomforests_pg_pi->SetPoint(3, 6, 0.622587);
    randomforests_pg_pi->SetPoint(4, 8, 0.624059);
    randomforests_pg_pi->SetPoint(5, 10, 0.61942);
    randomforests_pg_pi->SetPoint(6, 12, 0.621525);
    randomforests_pg_pi->SetLineColor( kRed); randomforests_pg_pi->SetMarkerColor( kRed); randomforests_pg_pi->SetFillColor( kWhite);
    
    TGraph* randomforests_pg_p = new TGraph();
    randomforests_pg_p->SetTitle("p identified as p");
    randomforests_pg_p->SetPoint(0, 2, 0.916315);
    randomforests_pg_p->SetPoint(1, 3, 0.916021);
    randomforests_pg_p->SetPoint(2, 4, 0.916436);
    randomforests_pg_p->SetPoint(3, 6, 0.915122);
    randomforests_pg_p->SetPoint(4, 8, 0.915122);
    randomforests_pg_p->SetPoint(5, 10, 0.918182);
    randomforests_pg_p->SetPoint(6, 12, 0.913549);
    randomforests_pg_p->SetLineColor( kGreen); randomforests_pg_p->SetMarkerColor( kGreen); randomforests_pg_p->SetFillColor( kWhite); 
    
    TGraph* randomforests_pg_e = new TGraph();
    randomforests_pg_e->SetTitle("e^{+} identified as e^{+}");
    randomforests_pg_e->SetPoint(0, 2, 0.65899);
    randomforests_pg_e->SetPoint(1, 3, 0.66242);
    randomforests_pg_e->SetPoint(2, 4, 0.661589);
    randomforests_pg_e->SetPoint(3, 6, 0.651611);
    randomforests_pg_e->SetPoint(4, 8, 0.636793);
    randomforests_pg_e->SetPoint(5, 10, 0.650557);
    randomforests_pg_e->SetPoint(6, 12, 0.639302);
    randomforests_pg_e->SetLineColor( kMagenta); randomforests_pg_e->SetMarkerColor( kMagenta); randomforests_pg_e->SetFillColor( kWhite); 
    
    TGraph* randomforests_pg_diff_mu = new TGraph();
    randomforests_pg_diff_mu->SetPoint(0, 2, 0.932103-refvalue_pg_mu);
    randomforests_pg_diff_mu->SetPoint(1, 3, 0.931306-refvalue_pg_mu);
    randomforests_pg_diff_mu->SetPoint(2, 4, 0.930814-refvalue_pg_mu);
    randomforests_pg_diff_mu->SetPoint(3, 6, 0.930118-refvalue_pg_mu);
    randomforests_pg_diff_mu->SetPoint(4, 8, 0.930785-refvalue_pg_mu);
    randomforests_pg_diff_mu->SetPoint(5, 10, 0.93006-refvalue_pg_mu);
    randomforests_pg_diff_mu->SetPoint(6, 12, 0.929887-refvalue_pg_mu);
    randomforests_pg_diff_mu->SetLineColor( kBlue); randomforests_pg_diff_mu->SetMarkerColor( kBlue); randomforests_pg_diff_mu->SetFillColor( kWhite);
    
    TGraph* randomforests_pg_diff_pi = new TGraph();
    randomforests_pg_diff_pi->SetPoint(0, 2, 0.618547-refvalue_pg_pi);
    randomforests_pg_diff_pi->SetPoint(1, 3, 0.621098-refvalue_pg_pi);
    randomforests_pg_diff_pi->SetPoint(2, 4, 0.619899-refvalue_pg_pi);
    randomforests_pg_diff_pi->SetPoint(3, 6, 0.622587-refvalue_pg_pi);
    randomforests_pg_diff_pi->SetPoint(4, 8, 0.624059-refvalue_pg_pi);
    randomforests_pg_diff_pi->SetPoint(5, 10, 0.61942-refvalue_pg_pi);
    randomforests_pg_diff_pi->SetPoint(6, 12, 0.621525-refvalue_pg_pi);
    randomforests_pg_diff_pi->SetLineColor( kRed); randomforests_pg_diff_pi->SetMarkerColor( kRed); randomforests_pg_diff_pi->SetFillColor( kWhite);
    
    TGraph* randomforests_pg_diff_p = new TGraph();
    randomforests_pg_diff_p->SetPoint(0, 2, 0.916315-refvalue_pg_p);
    randomforests_pg_diff_p->SetPoint(1, 3, 0.916021-refvalue_pg_p); 
    randomforests_pg_diff_p->SetPoint(2, 4, 0.916436-refvalue_pg_p);
    randomforests_pg_diff_p->SetPoint(3, 6, 0.915122-refvalue_pg_p);
    randomforests_pg_diff_p->SetPoint(4, 8, 0.915122-refvalue_pg_p);
    randomforests_pg_diff_p->SetPoint(5, 10, 0.918182-refvalue_pg_p);
    randomforests_pg_diff_p->SetPoint(6, 12, 0.913549-refvalue_pg_p);
    randomforests_pg_diff_p->SetLineColor( kGreen); randomforests_pg_diff_p->SetMarkerColor( kGreen); randomforests_pg_diff_p->SetFillColor( kWhite); 
    
    TGraph* randomforests_pg_diff_e = new TGraph();
    randomforests_pg_diff_e->SetPoint(0, 2, 0.65899-refvalue_pg_e);
    randomforests_pg_diff_e->SetPoint(1, 3, 0.66242-refvalue_pg_e);
    randomforests_pg_diff_e->SetPoint(2, 4, 0.661589-refvalue_pg_e);
    randomforests_pg_diff_e->SetPoint(3, 6, 0.651611-refvalue_pg_e);
    randomforests_pg_diff_e->SetPoint(4, 8, 0.636793-refvalue_pg_e);
    randomforests_pg_diff_e->SetPoint(5, 10, 0.650557-refvalue_pg_e);
    randomforests_pg_diff_e->SetPoint(6, 12, 0.639302-refvalue_pg_e);
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
    randomforests_pg_diff_mu->GetYaxis()->SetRangeUser(-0.015, 0.03);
    randomforests_pg_diff_mu->GetXaxis()->SetTitle("Random forests NVars"); randomforests_pg_diff_mu->GetYaxis()->SetTitle("Difference in efficiency");
    randomforests_pg_diff_mu->Draw("AL*");
    randomforests_pg_diff_pi->Draw("L* same");
    randomforests_pg_diff_p->Draw("L* same");
    randomforests_pg_diff_e->Draw("L* same");
    
    
}
