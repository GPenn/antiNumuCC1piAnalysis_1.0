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
    shrinkage_pg_mu->SetPoint(0, 0.1, 0.932016);
    shrinkage_pg_mu->SetPoint(1, 0.3, 0.934768);
    shrinkage_pg_mu->SetPoint(2, 0.5, 0.934276);
    shrinkage_pg_mu->SetPoint(3, 0.7, 0.933407);
    shrinkage_pg_mu->SetPoint(4, 0.9, 0.931524);
    shrinkage_pg_mu->SetLineColor( kBlue); shrinkage_pg_mu->SetMarkerColor( kBlue); shrinkage_pg_mu->SetFillColor( kWhite);
    
    TGraph* shrinkage_pg_pi = new TGraph();
    shrinkage_pg_pi->SetTitle("#pi^{+} identified as #pi^{+}");
    shrinkage_pg_pi->SetPoint(0, 0.1, 0.620995);
    shrinkage_pg_pi->SetPoint(1, 0.3, 0.615175);
    shrinkage_pg_pi->SetPoint(2, 0.5, 0.614165);
    shrinkage_pg_pi->SetPoint(3, 0.7, 0.61663);
    shrinkage_pg_pi->SetPoint(4, 0.9, 0.618462);
    shrinkage_pg_pi->SetLineColor( kRed); shrinkage_pg_pi->SetMarkerColor( kRed); shrinkage_pg_pi->SetFillColor( kWhite);
    
    TGraph* shrinkage_pg_p = new TGraph();
    shrinkage_pg_p->SetTitle("p identified as p");
    shrinkage_pg_p->SetPoint(0, 0.1, 0.879927);
    shrinkage_pg_p->SetPoint(1, 0.3, 0.904854);
    shrinkage_pg_p->SetPoint(2, 0.5, 0.912391);
    shrinkage_pg_p->SetPoint(3, 0.7, 0.913826);
    shrinkage_pg_p->SetPoint(4, 0.9, 0.916315);
    shrinkage_pg_p->SetLineColor( kGreen); shrinkage_pg_p->SetMarkerColor( kGreen); shrinkage_pg_p->SetFillColor( kWhite); 
    
    TGraph* shrinkage_pg_e = new TGraph();
    shrinkage_pg_e->SetTitle("e^{+} identified as e^{+}");
    shrinkage_pg_e->SetPoint(0, 0.1, 0.372472);
    shrinkage_pg_e->SetPoint(1, 0.3, 0.54971);
    shrinkage_pg_e->SetPoint(2, 0.5, 0.599406);
    shrinkage_pg_e->SetPoint(3, 0.7, 0.62395);
    shrinkage_pg_e->SetPoint(4, 0.9, 0.631314);
    shrinkage_pg_e->SetLineColor( kMagenta); shrinkage_pg_e->SetMarkerColor( kMagenta); shrinkage_pg_e->SetFillColor( kWhite); 
    
    TGraph* shrinkage_pg_diff_mu = new TGraph();
    shrinkage_pg_diff_mu->SetPoint(0, 0.1, 0.932016-refvalue_pg_mu);
    shrinkage_pg_diff_mu->SetPoint(1, 0.3, 0.934768-refvalue_pg_mu);
    shrinkage_pg_diff_mu->SetPoint(2, 0.5, 0.934276-refvalue_pg_mu);
    shrinkage_pg_diff_mu->SetPoint(3, 0.7, 0.933407-refvalue_pg_mu);
    shrinkage_pg_diff_mu->SetPoint(4, 0.9, 0.931524-refvalue_pg_mu);
    shrinkage_pg_diff_mu->SetLineColor( kBlue); shrinkage_pg_diff_mu->SetMarkerColor( kBlue); shrinkage_pg_diff_mu->SetFillColor( kWhite);
    
    TGraph* shrinkage_pg_diff_pi = new TGraph();
    shrinkage_pg_diff_pi->SetPoint(0, 0.1, 0.620995-refvalue_pg_pi);
    shrinkage_pg_diff_pi->SetPoint(1, 0.3, 0.615175-refvalue_pg_pi);
    shrinkage_pg_diff_pi->SetPoint(2, 0.5, 0.614165-refvalue_pg_pi);
    shrinkage_pg_diff_pi->SetPoint(3, 0.7, 0.61663-refvalue_pg_pi);
    shrinkage_pg_diff_pi->SetPoint(4, 0.9, 0.618462-refvalue_pg_pi);
    shrinkage_pg_diff_pi->SetLineColor( kRed); shrinkage_pg_diff_pi->SetMarkerColor( kRed); shrinkage_pg_diff_pi->SetFillColor( kWhite);
    
    TGraph* shrinkage_pg_diff_p = new TGraph();
    shrinkage_pg_diff_p->SetPoint(0, 0.1, 0.879927-refvalue_pg_p);
    shrinkage_pg_diff_p->SetPoint(1, 0.3, 0.904854-refvalue_pg_p);
    shrinkage_pg_diff_p->SetPoint(2, 0.5, 0.912391-refvalue_pg_p);
    shrinkage_pg_diff_p->SetPoint(3, 0.7, 0.913826-refvalue_pg_p);
    shrinkage_pg_diff_p->SetPoint(4, 0.9, 0.916315-refvalue_pg_p);
    shrinkage_pg_diff_p->SetLineColor( kGreen); shrinkage_pg_diff_p->SetMarkerColor( kGreen); shrinkage_pg_diff_p->SetFillColor( kWhite); 
    
    TGraph* shrinkage_pg_diff_e = new TGraph();
    shrinkage_pg_diff_e->SetPoint(0, 0.1, 0.372472-refvalue_pg_e);
    shrinkage_pg_diff_e->SetPoint(1, 0.3, 0.54971-refvalue_pg_e);
    shrinkage_pg_diff_e->SetPoint(2, 0.5, 0.599406-refvalue_pg_e);
    shrinkage_pg_diff_e->SetPoint(3, 0.7, 0.62395-refvalue_pg_e);
    shrinkage_pg_diff_e->SetPoint(4, 0.9, 0.631314-refvalue_pg_e);
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
    bagged_pg_mu->SetPoint(0, 0.1, 0.847576);
    bagged_pg_mu->SetPoint(1, 0.3, 0.92499);
    bagged_pg_mu->SetPoint(2, 0.5, 0.925744);
    bagged_pg_mu->SetPoint(3, 0.7, 0.929148);
    bagged_pg_mu->SetPoint(4, 0.9, 0.927279);
    bagged_pg_mu->SetLineColor( kBlue); bagged_pg_mu->SetMarkerColor( kBlue); bagged_pg_mu->SetFillColor( kWhite);
    
    TGraph* bagged_pg_pi = new TGraph();
    bagged_pg_pi->SetTitle("#pi^{+} identified as #pi^{+}");
    bagged_pg_pi->SetPoint(0, 0.1, 0.393041);
    bagged_pg_pi->SetPoint(1, 0.3, 0.6161);
    bagged_pg_pi->SetPoint(2, 0.5, 0.625394);
    bagged_pg_pi->SetPoint(3, 0.7, 0.619335);
    bagged_pg_pi->SetPoint(4, 0.9, 0.623768);
    bagged_pg_pi->SetLineColor( kRed); bagged_pg_pi->SetMarkerColor( kRed); bagged_pg_pi->SetFillColor( kWhite);
    
    TGraph* bagged_pg_p = new TGraph();
    bagged_pg_p->SetTitle("p identified as p");
    bagged_pg_p->SetPoint(0, 0.1, 0.869192);
    bagged_pg_p->SetPoint(1, 0.3, 0.910593);
    bagged_pg_p->SetPoint(2, 0.5, 0.908311);
    bagged_pg_p->SetPoint(3, 0.7, 0.909539);
    bagged_pg_p->SetPoint(4, 0.9, 0.912201);
    bagged_pg_p->SetLineColor( kGreen); bagged_pg_p->SetMarkerColor( kGreen); bagged_pg_p->SetFillColor( kWhite); 
    
    TGraph* bagged_pg_e = new TGraph();
    bagged_pg_e->SetTitle("e^{+} identified as e^{+}");
    bagged_pg_e->SetPoint(0, 0.1, 0.542836);
    bagged_pg_e->SetPoint(1, 0.3, 0.616154);
    bagged_pg_e->SetPoint(2, 0.5, 0.59853);
    bagged_pg_e->SetPoint(3, 0.7, 0.628107);
    bagged_pg_e->SetPoint(4, 0.9, 0.629829);
    bagged_pg_e->SetLineColor( kMagenta); bagged_pg_e->SetMarkerColor( kMagenta); bagged_pg_e->SetFillColor( kWhite); 
    
    TGraph* bagged_pg_diff_mu = new TGraph();
    bagged_pg_diff_mu->SetPoint(0, 0.1, 0.847576-refvalue_pg_mu);
    bagged_pg_diff_mu->SetPoint(1, 0.3, 0.92499-refvalue_pg_mu);
    bagged_pg_diff_mu->SetPoint(2, 0.5, 0.925744-refvalue_pg_mu);
    bagged_pg_diff_mu->SetPoint(3, 0.7, 0.929148-refvalue_pg_mu);
    bagged_pg_diff_mu->SetPoint(4, 0.9, 0.927279-refvalue_pg_mu);
    bagged_pg_diff_mu->SetLineColor( kBlue); bagged_pg_diff_mu->SetMarkerColor( kBlue); bagged_pg_diff_mu->SetFillColor( kWhite);
    
    TGraph* bagged_pg_diff_pi = new TGraph();
    bagged_pg_diff_pi->SetPoint(0, 0.1, 0.393041-refvalue_pg_pi);
    bagged_pg_diff_pi->SetPoint(1, 0.3, 0.6161-refvalue_pg_pi);
    bagged_pg_diff_pi->SetPoint(2, 0.5, 0.625394-refvalue_pg_pi);
    bagged_pg_diff_pi->SetPoint(3, 0.7, 0.619335-refvalue_pg_pi);
    bagged_pg_diff_pi->SetPoint(4, 0.9, 0.623768-refvalue_pg_pi);
    bagged_pg_diff_pi->SetLineColor( kRed); bagged_pg_diff_pi->SetMarkerColor( kRed); bagged_pg_diff_pi->SetFillColor( kWhite);
    
    TGraph* bagged_pg_diff_p = new TGraph();
    bagged_pg_diff_p->SetPoint(0, 0.1, 0.869192-refvalue_pg_p);
    bagged_pg_diff_p->SetPoint(1, 0.3, 0.910593-refvalue_pg_p);
    bagged_pg_diff_p->SetPoint(2, 0.5, 0.908311-refvalue_pg_p);
    bagged_pg_diff_p->SetPoint(3, 0.7, 0.909539-refvalue_pg_p);
    bagged_pg_diff_p->SetPoint(4, 0.9, 0.912201-refvalue_pg_p);
    bagged_pg_diff_p->SetLineColor( kGreen); bagged_pg_diff_p->SetMarkerColor( kGreen); bagged_pg_diff_p->SetFillColor( kWhite); 
    
    TGraph* bagged_pg_diff_e = new TGraph();
    bagged_pg_diff_e->SetPoint(0, 0.1, 0.542836-refvalue_pg_e);
    bagged_pg_diff_e->SetPoint(1, 0.3, 0.616154-refvalue_pg_e);
    bagged_pg_diff_e->SetPoint(2, 0.5, 0.59853-refvalue_pg_e);
    bagged_pg_diff_e->SetPoint(3, 0.7, 0.628107-refvalue_pg_e);
    bagged_pg_diff_e->SetPoint(4, 0.9, 0.629829-refvalue_pg_e);
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
    randomforests_pg_mu->SetPoint(0, 2, 0.935261);
    randomforests_pg_mu->SetPoint(1, 3, 0.933233);
    randomforests_pg_mu->SetPoint(2, 4, 0.932697);
    randomforests_pg_mu->SetPoint(3, 6, 0.932132);
    randomforests_pg_mu->SetPoint(4, 8, 0.932711);
    randomforests_pg_mu->SetPoint(5, 10, 0.932393);
    randomforests_pg_mu->SetPoint(6, 12, 0.933088);
    randomforests_pg_mu->SetLineColor( kBlue); randomforests_pg_mu->SetMarkerColor( kBlue); randomforests_pg_mu->SetFillColor( kWhite);
    
    TGraph* randomforests_pg_pi = new TGraph();
    randomforests_pg_pi->SetTitle("#pi^{+} identified as #pi^{+}");
    randomforests_pg_pi->SetPoint(0, 2, 0.611547);
    randomforests_pg_pi->SetPoint(1, 3, 0.614148);
    randomforests_pg_pi->SetPoint(2, 4, 0.623083);
    randomforests_pg_pi->SetPoint(3, 6, 0.619865);
    randomforests_pg_pi->SetPoint(4, 8, 0.615021);
    randomforests_pg_pi->SetPoint(5, 10, 0.616973);
    randomforests_pg_pi->SetPoint(6, 12, 0.616151);
    randomforests_pg_pi->SetLineColor( kRed); randomforests_pg_pi->SetMarkerColor( kRed); randomforests_pg_pi->SetFillColor( kWhite);
    
    TGraph* randomforests_pg_p = new TGraph();
    randomforests_pg_p->SetTitle("p identified as p");
    randomforests_pg_p->SetPoint(0, 2, 0.916229);
    randomforests_pg_p->SetPoint(1, 3, 0.913618);
    randomforests_pg_p->SetPoint(2, 4, 0.911406);
    randomforests_pg_p->SetPoint(3, 6, 0.915641);
    randomforests_pg_p->SetPoint(4, 8, 0.915658);
    randomforests_pg_p->SetPoint(5, 10, 0.914707);
    randomforests_pg_p->SetPoint(6, 12, 0.91488);
    randomforests_pg_p->SetLineColor( kGreen); randomforests_pg_p->SetMarkerColor( kGreen); randomforests_pg_p->SetFillColor( kWhite); 
    
    TGraph* randomforests_pg_e = new TGraph();
    randomforests_pg_e->SetTitle("e^{+} identified as e^{+}");
    randomforests_pg_e->SetPoint(0, 2, 0.64346);
    randomforests_pg_e->SetPoint(1, 3, 0.647439);
    randomforests_pg_e->SetPoint(2, 4, 0.651581);
    randomforests_pg_e->SetPoint(3, 6, 0.644187);
    randomforests_pg_e->SetPoint(4, 8, 0.632071);
    randomforests_pg_e->SetPoint(5, 10, 0.640906);
    randomforests_pg_e->SetPoint(6, 12, 0.641024);
    randomforests_pg_e->SetLineColor( kMagenta); randomforests_pg_e->SetMarkerColor( kMagenta); randomforests_pg_e->SetFillColor( kWhite); 
    
    TGraph* randomforests_pg_diff_mu = new TGraph();
    randomforests_pg_diff_mu->SetPoint(0, 2, 0.935261-refvalue_pg_mu);
    randomforests_pg_diff_mu->SetPoint(1, 3, 0.933233-refvalue_pg_mu);
    randomforests_pg_diff_mu->SetPoint(2, 4, 0.932697-refvalue_pg_mu);
    randomforests_pg_diff_mu->SetPoint(3, 6, 0.932132-refvalue_pg_mu);
    randomforests_pg_diff_mu->SetPoint(4, 8, 0.932711-refvalue_pg_mu);
    randomforests_pg_diff_mu->SetPoint(5, 10, 0.932393-refvalue_pg_mu);
    randomforests_pg_diff_mu->SetPoint(6, 12, 0.933088-refvalue_pg_mu);
    randomforests_pg_diff_mu->SetLineColor( kBlue); randomforests_pg_diff_mu->SetMarkerColor( kBlue); randomforests_pg_diff_mu->SetFillColor( kWhite);
    
    TGraph* randomforests_pg_diff_pi = new TGraph();
    randomforests_pg_diff_pi->SetPoint(0, 2, 0.611547-refvalue_pg_pi);
    randomforests_pg_diff_pi->SetPoint(1, 3, 0.614148-refvalue_pg_pi);
    randomforests_pg_diff_pi->SetPoint(2, 4, 0.623083-refvalue_pg_pi);
    randomforests_pg_diff_pi->SetPoint(3, 6, 0.619865-refvalue_pg_pi);
    randomforests_pg_diff_pi->SetPoint(4, 8, 0.615021-refvalue_pg_pi);
    randomforests_pg_diff_pi->SetPoint(5, 10, 0.616973-refvalue_pg_pi);
    randomforests_pg_diff_pi->SetPoint(6, 12, 0.616151-refvalue_pg_pi);
    randomforests_pg_diff_pi->SetLineColor( kRed); randomforests_pg_diff_pi->SetMarkerColor( kRed); randomforests_pg_diff_pi->SetFillColor( kWhite);
    
    TGraph* randomforests_pg_diff_p = new TGraph();
    randomforests_pg_diff_p->SetPoint(0, 2, 0.916229-refvalue_pg_p);
    randomforests_pg_diff_p->SetPoint(1, 3, 0.913618-refvalue_pg_p); 
    randomforests_pg_diff_p->SetPoint(2, 4, 0.911406-refvalue_pg_p);
    randomforests_pg_diff_p->SetPoint(3, 6, 0.915641-refvalue_pg_p);
    randomforests_pg_diff_p->SetPoint(4, 8, 0.915658-refvalue_pg_p);
    randomforests_pg_diff_p->SetPoint(5, 10, 0.914707-refvalue_pg_p);
    randomforests_pg_diff_p->SetPoint(6, 12, 0.91488-refvalue_pg_p);
    randomforests_pg_diff_p->SetLineColor( kGreen); randomforests_pg_diff_p->SetMarkerColor( kGreen); randomforests_pg_diff_p->SetFillColor( kWhite); 
    
    TGraph* randomforests_pg_diff_e = new TGraph();
    randomforests_pg_diff_e->SetPoint(0, 2, 0.64346-refvalue_pg_e);
    randomforests_pg_diff_e->SetPoint(1, 3, 0.647439-refvalue_pg_e);
    randomforests_pg_diff_e->SetPoint(2, 4, 0.651581-refvalue_pg_e);
    randomforests_pg_diff_e->SetPoint(3, 6, 0.644187-refvalue_pg_e);
    randomforests_pg_diff_e->SetPoint(4, 8, 0.632071-refvalue_pg_e);
    randomforests_pg_diff_e->SetPoint(5, 10, 0.640906-refvalue_pg_e);
    randomforests_pg_diff_e->SetPoint(6, 12, 0.641024-refvalue_pg_e);
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
