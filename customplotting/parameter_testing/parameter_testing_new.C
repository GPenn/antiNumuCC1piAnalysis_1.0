{
    gStyle->SetTitleYOffset(1.5);
    
    Float_t refvalue_cc1pi_mu, refvalue_cc1pi_pi, refvalue_pg_mu, refvalue_pg_pi, refvalue_pg_p, refvalue_pg_e;
    
    // =============== Tree depth ===============
    
    refvalue_pg_mu = 0.963724;
    TGraph* treedepth_pg_mu = new TGraph();
    treedepth_pg_mu->SetTitle("#mu^{+} identified as #mu^{+}");
    treedepth_pg_mu->SetPoint(0, 2.0, 0.976332-refvalue_pg_mu);
    treedepth_pg_mu->SetPoint(1, 3.0, 0.963724-refvalue_pg_mu);
    treedepth_pg_mu->SetPoint(2, 4.0, 0.955835-refvalue_pg_mu);
    treedepth_pg_mu->SetPoint(3, 5.0, 0.959671-refvalue_pg_mu);
    treedepth_pg_mu->SetLineColor( kBlue); treedepth_pg_mu->SetMarkerColor( kBlue); treedepth_pg_mu->SetFillColor( kWhite);
    
    refvalue_pg_pi = 0.525485;
    TGraph* treedepth_pg_pi = new TGraph();
    treedepth_pg_pi->SetTitle("#pi^{+} identified as #pi^{+}");
    treedepth_pg_pi->SetPoint(0, 2.0, 0.450048-refvalue_pg_pi);
    treedepth_pg_pi->SetPoint(1, 3.0, 0.525485-refvalue_pg_pi);
    treedepth_pg_pi->SetPoint(2, 4.0, 0.556587-refvalue_pg_pi);
    treedepth_pg_pi->SetPoint(3, 5.0, 0.538685-refvalue_pg_pi);
    treedepth_pg_pi->SetLineColor( kRed); treedepth_pg_pi->SetMarkerColor( kRed); treedepth_pg_pi->SetFillColor( kWhite); 
    
    refvalue_pg_p = 0.845924;
    TGraph* treedepth_pg_p = new TGraph();
    treedepth_pg_p->SetTitle("p identified as p");
    treedepth_pg_p->SetPoint(0, 2.0, 0.85422-refvalue_pg_p);
    treedepth_pg_p->SetPoint(1, 3.0, 0.845924-refvalue_pg_p);
    treedepth_pg_p->SetPoint(2, 4.0, 0.864603-refvalue_pg_p);
    treedepth_pg_p->SetPoint(3, 5.0, 0.861057-refvalue_pg_p);
    treedepth_pg_p->SetLineColor( kGreen); treedepth_pg_p->SetMarkerColor( kGreen); treedepth_pg_p->SetFillColor( kWhite); 
    
    refvalue_pg_e = 0.549095;
    TGraph* treedepth_pg_e = new TGraph();
    treedepth_pg_e->SetTitle("e^{+} identified as e^{+}");
    treedepth_pg_e->SetPoint(0, 2.0, 0.546797-refvalue_pg_e);
    treedepth_pg_e->SetPoint(1, 3.0, 0.549095-refvalue_pg_e);
    treedepth_pg_e->SetPoint(2, 4.0, 0.549198-refvalue_pg_e);
    treedepth_pg_e->SetPoint(3, 5.0, 0.549714-refvalue_pg_e);
    treedepth_pg_e->SetLineColor( kMagenta); treedepth_pg_e->SetMarkerColor( kMagenta); treedepth_pg_e->SetFillColor( kWhite); 
    
    TCanvas* canvas_treedepth = new TCanvas("canvas_treedepth","",200,10,1000,800);
    //canvas_treedepth->Divide(2,1,0.005,0.005);
    //canvas_treedepth->cd(1);
    
    treedepth_pg_mu->GetYaxis()->SetRangeUser(-0.1, 0.04);
    treedepth_pg_mu->GetXaxis()->SetTitle("Maximum tree depth"); treedepth_pg_mu->GetYaxis()->SetTitle("Difference in efficiency");
    treedepth_pg_mu->Draw("AL*");
    treedepth_pg_pi->Draw("L* same");
    treedepth_pg_p->Draw("L* same");
    treedepth_pg_e->Draw("L* same");
    canvas_treedepth->BuildLegend();
    
    // =============== Tree number ===============
    
    TGraph* treenumber_pg_mu = new TGraph();
    treenumber_pg_mu->SetTitle("#mu^{+} selection mu-like cut");
    treenumber_pg_mu->SetPoint(0, 500.0, 0.-refvalue_pg_mu);
    treenumber_pg_mu->SetPoint(1, 1000.0, 0.-refvalue_pg_mu);
    treenumber_pg_mu->SetPoint(2, 1500.0, 0.-refvalue_pg_mu);
    treenumber_pg_mu->SetPoint(3, 2000.0, 0.-refvalue_pg_mu);
    treenumber_pg_mu->SetPoint(4, 2500.0, 0.-refvalue_pg_mu);
    treenumber_pg_mu->SetLineColor( kBlue); treenumber_pg_mu->SetMarkerColor( kBlue); treenumber_pg_mu->SetFillColor( kWhite);
    
    TGraph* treenumber_pg_pi = new TGraph();
    treenumber_pg_pi->SetTitle("#pi^{+} selection pi-like cut");
    treenumber_pg_pi->SetPoint(0, 500.0, 0.-refvalue_pg_pi);
    treenumber_pg_pi->SetPoint(1, 1000.0, 0.-refvalue_pg_pi);
    treenumber_pg_pi->SetPoint(2, 1500.0, 0.-refvalue_pg_pi);
    treenumber_pg_pi->SetPoint(3, 2000.0, 0.-refvalue_pg_pi);
    treenumber_pg_pi->SetPoint(4, 2500.0, 0.-refvalue_pg_pi);
    treenumber_pg_pi->SetLineColor( kRed); treenumber_pg_pi->SetMarkerColor( kRed); treenumber_pg_pi->SetFillColor( kWhite);
    
    TGraph* treenumber_pg_p = new TGraph();
    treenumber_pg_p->SetTitle("p selection p-like cut");
    treenumber_pg_p->SetPoint(0, 500.0, 0.-refvalue_pg_p);
    treenumber_pg_p->SetPoint(1, 1000.0, 0.-refvalue_pg_p);
    treenumber_pg_p->SetPoint(2, 1500.0, 0.-refvalue_pg_p);
    treenumber_pg_p->SetPoint(3, 2000.0, 0.-refvalue_pg_p);
    treenumber_pg_p->SetPoint(4, 2500.0, 0.-refvalue_pg_p);
    treenumber_pg_p->SetLineColor( kGreen); treenumber_pg_p->SetMarkerColor( kGreen); treenumber_pg_p->SetFillColor( kWhite); 
    
    TGraph* treenumber_pg_e = new TGraph();
    treenumber_pg_e->SetTitle("e^{+} selection e-like cut");
    treenumber_pg_e->SetPoint(0, 500.0, 0.-refvalue_pg_e);
    treenumber_pg_e->SetPoint(1, 1000.0, 0.-refvalue_pg_e);
    treenumber_pg_e->SetPoint(2, 1500.0, 0.-refvalue_pg_e);
    treenumber_pg_e->SetPoint(3, 2000.0, 0.-refvalue_pg_e);
    treenumber_pg_e->SetPoint(4, 2500.0, 0.-refvalue_pg_e);
    treenumber_pg_e->SetLineColor( kMagenta); treenumber_pg_e->SetMarkerColor( kMagenta); treenumber_pg_e->SetFillColor( kWhite); 
    
    TCanvas* canvas_treenumber = new TCanvas("canvas_treenumber","",200,10,1000,800);
    treenumber_pg_mu->GetYaxis()->SetRangeUser(-0.5, 0.5);
    treenumber_pg_mu->GetXaxis()->SetTitle("Number of trees"); treenumber_pg_mu->GetYaxis()->SetTitle("Difference in efficiency");
    treenumber_pg_mu->Draw("AL*");
    treenumber_pg_pi->Draw("L* same");
    treenumber_pg_p->Draw("L* same");
    treenumber_pg_e->Draw("L* same");
    canvas_treenumber->BuildLegend();
    
    // =============== Shrinkage ===============
    
    TGraph* shrinkage_pg_mu = new TGraph();
    shrinkage_pg_mu->SetTitle("#mu^{+} selection mu-like cut");
    shrinkage_pg_mu->SetPoint(0, 0.01, 0.-refvalue_pg_mu);
    shrinkage_pg_mu->SetPoint(1, 0.02, 0.-refvalue_pg_mu);
    shrinkage_pg_mu->SetPoint(2, 0.04, 0.-refvalue_pg_mu);
    shrinkage_pg_mu->SetPoint(3, 0.06, 0.-refvalue_pg_mu);
    shrinkage_pg_mu->SetPoint(4, 0.08, 0.-refvalue_pg_mu);
    shrinkage_pg_mu->SetPoint(5, 0.1, 0.-refvalue_pg_mu);
    shrinkage_pg_mu->SetPoint(6, 0.3, 0.-refvalue_pg_mu);
    shrinkage_pg_mu->SetPoint(7, 0.5, 0.-refvalue_pg_mu);
    shrinkage_pg_mu->SetPoint(8, 0.7, 0.-refvalue_pg_mu);
    shrinkage_pg_mu->SetPoint(9, 0.9, 0.-refvalue_pg_mu);
    shrinkage_pg_mu->SetLineColor( kBlue); shrinkage_pg_mu->SetMarkerColor( kBlue); shrinkage_pg_mu->SetFillColor( kWhite);
    
    TGraph* shrinkage_pg_pi = new TGraph();
    shrinkage_pg_pi->SetTitle("#pi^{+} selection pi-like cut");
    shrinkage_pg_pi->SetPoint(0, 0.01, 0.-refvalue_pg_pi);
    shrinkage_pg_pi->SetPoint(1, 0.02, 0.-refvalue_pg_pi);
    shrinkage_pg_pi->SetPoint(2, 0.04, 0.-refvalue_pg_pi);
    shrinkage_pg_pi->SetPoint(3, 0.06, 0.-refvalue_pg_pi);
    shrinkage_pg_pi->SetPoint(4, 0.08, 0.-refvalue_pg_pi);
    shrinkage_pg_pi->SetPoint(5, 0.1, 0.-refvalue_pg_pi);
    shrinkage_pg_pi->SetPoint(6, 0.3, 0.-refvalue_pg_pi);
    shrinkage_pg_pi->SetPoint(7, 0.5, 0.-refvalue_pg_pi);
    shrinkage_pg_pi->SetPoint(8, 0.7, 0.-refvalue_pg_pi);
    shrinkage_pg_pi->SetPoint(9, 0.9, 0.-refvalue_pg_pi);
    shrinkage_pg_pi->SetLineColor( kRed); shrinkage_pg_pi->SetMarkerColor( kRed); shrinkage_pg_pi->SetFillColor( kWhite);
    
    TGraph* shrinkage_pg_p = new TGraph();
    shrinkage_pg_p->SetTitle("p selection p-like cut");
    shrinkage_pg_p->SetPoint(0, 0.01, 0.-refvalue_pg_p);
    shrinkage_pg_p->SetPoint(1, 0.02, 0.-refvalue_pg_p);
    shrinkage_pg_p->SetPoint(2, 0.04, 0.-refvalue_pg_p);
    shrinkage_pg_p->SetPoint(3, 0.06, 0.-refvalue_pg_p);
    shrinkage_pg_p->SetPoint(4, 0.08, 0.-refvalue_pg_p);
    shrinkage_pg_p->SetPoint(5, 0.1, 0.-refvalue_pg_p);
    shrinkage_pg_p->SetPoint(6, 0.3, 0.-refvalue_pg_p);
    shrinkage_pg_p->SetPoint(7, 0.5, 0.-refvalue_pg_p);
    shrinkage_pg_p->SetPoint(8, 0.7, 0.-refvalue_pg_p);
    shrinkage_pg_p->SetPoint(9, 0.9, 0.-refvalue_pg_p);
    shrinkage_pg_p->SetLineColor( kGreen); shrinkage_pg_p->SetMarkerColor( kGreen); shrinkage_pg_p->SetFillColor( kWhite); 
    
    TGraph* shrinkage_pg_e = new TGraph();
    shrinkage_pg_e->SetTitle("e^{+} selection e-like cut");
    shrinkage_pg_e->SetPoint(0, 0.01, 0.-refvalue_pg_e);
    shrinkage_pg_e->SetPoint(1, 0.02, 0.-refvalue_pg_e);
    shrinkage_pg_e->SetPoint(2, 0.04, 0.-refvalue_pg_e);
    shrinkage_pg_e->SetPoint(3, 0.06, 0.-refvalue_pg_e);
    shrinkage_pg_e->SetPoint(4, 0.08, 0.-refvalue_pg_e);
    shrinkage_pg_e->SetPoint(5, 0.1, 0.-refvalue_pg_e);
    shrinkage_pg_e->SetPoint(6, 0.3, 0.-refvalue_pg_e);
    shrinkage_pg_e->SetPoint(7, 0.5, 0.-refvalue_pg_e);
    shrinkage_pg_e->SetPoint(8, 0.7, 0.-refvalue_pg_e);
    shrinkage_pg_e->SetPoint(9, 0.9, 0.-refvalue_pg_e);
    shrinkage_pg_e->SetLineColor( kMagenta); shrinkage_pg_e->SetMarkerColor( kMagenta); shrinkage_pg_e->SetFillColor( kWhite); 
    
    TCanvas* canvas_shrinkage = new TCanvas("canvas_shrinkage","",200,10,1000,800);
    shrinkage_pg_mu->GetYaxis()->SetRangeUser(-0.5, 0.5);
    shrinkage_pg_mu->GetXaxis()->SetTitle("Shrinkage"); shrinkage_pg_mu->GetYaxis()->SetTitle("Difference in efficiency");
    shrinkage_pg_mu->Draw("AL*");
    shrinkage_pg_pi->Draw("L* same");
    shrinkage_pg_p->Draw("L* same");
    shrinkage_pg_e->Draw("L* same");
    canvas_shrinkage->BuildLegend();
    
    // =============== Bagged ===============
    
    TGraph* bagged_pg_mu = new TGraph();
    bagged_pg_mu->SetTitle("#mu^{+} selection mu-like cut");
    bagged_pg_mu->SetPoint(0, 0.1, 0.-refvalue_pg_mu);
    bagged_pg_mu->SetPoint(1, 0.3, 0.-refvalue_pg_mu);
    bagged_pg_mu->SetPoint(2, 0.5, 0.-refvalue_pg_mu);
    bagged_pg_mu->SetPoint(3, 0.7, 0.-refvalue_pg_mu);
    bagged_pg_mu->SetPoint(4, 0.9, 0.-refvalue_pg_mu);
    bagged_pg_mu->SetLineColor( kBlue); bagged_pg_mu->SetMarkerColor( kBlue); bagged_pg_mu->SetFillColor( kWhite);
    
    TGraph* bagged_pg_pi = new TGraph();
    bagged_pg_pi->SetTitle("#pi^{+} selection pi-like cut");
    bagged_pg_pi->SetPoint(0, 0.1, 0.-refvalue_pg_pi);
    bagged_pg_pi->SetPoint(1, 0.3, 0.-refvalue_pg_pi);
    bagged_pg_pi->SetPoint(2, 0.5, 0.-refvalue_pg_pi);
    bagged_pg_pi->SetPoint(3, 0.7, 0.-refvalue_pg_pi);
    bagged_pg_pi->SetPoint(4, 0.9, 0.-refvalue_pg_pi);
    bagged_pg_pi->SetLineColor( kRed); bagged_pg_pi->SetMarkerColor( kRed); bagged_pg_pi->SetFillColor( kWhite);
    
    TGraph* bagged_pg_p = new TGraph();
    bagged_pg_p->SetTitle("p selection p-like cut");
    bagged_pg_p->SetPoint(0, 0.1, 0.-refvalue_pg_p);
    bagged_pg_p->SetPoint(1, 0.3, 0.-refvalue_pg_p);
    bagged_pg_p->SetPoint(2, 0.5, 0.-refvalue_pg_p);
    bagged_pg_p->SetPoint(3, 0.7, 0.-refvalue_pg_p);
    bagged_pg_p->SetPoint(4, 0.9, 0.-refvalue_pg_p);
    bagged_pg_p->SetLineColor( kGreen); bagged_pg_p->SetMarkerColor( kGreen); bagged_pg_p->SetFillColor( kWhite); 
    
    TGraph* bagged_pg_e = new TGraph();
    bagged_pg_e->SetTitle("e^{+} selection e-like cut");
    bagged_pg_e->SetPoint(0, 0.1, 0.-refvalue_pg_e);
    bagged_pg_e->SetPoint(1, 0.3, 0.-refvalue_pg_e);
    bagged_pg_e->SetPoint(2, 0.5, 0.-refvalue_pg_e);
    bagged_pg_e->SetPoint(3, 0.7, 0.-refvalue_pg_e);
    bagged_pg_e->SetPoint(4, 0.9, 0.-refvalue_pg_e);
    bagged_pg_e->SetLineColor( kMagenta); bagged_pg_e->SetMarkerColor( kMagenta); bagged_pg_e->SetFillColor( kWhite); 
    
    TCanvas* canvas_bagged = new TCanvas("canvas_bagged","",200,10,1000,400);
    bagged_pg_mu->GetYaxis()->SetRangeUser(-0.5, 0.5);
    bagged_pg_mu->GetXaxis()->SetTitle("BaggedSampleFraction"); bagged_pg_mu->GetYaxis()->SetTitle("Difference in efficiency");
    bagged_pg_mu->Draw("AL*");
    bagged_pg_pi->Draw("L* same");
    bagged_pg_p->Draw("L* same");
    bagged_pg_e->Draw("L* same");
    canvas_bagged->BuildLegend();
    
    // =============== Random Forests ===============
    
    TGraph* randomforests_pg_mu = new TGraph();
    randomforests_pg_mu->SetTitle("#mu^{+} selection mu-like cut");
    randomforests_pg_mu->SetPoint(0, 4, 0.-refvalue_pg_mu);
    randomforests_pg_mu->SetPoint(1, 6, 0.-refvalue_pg_mu);
    randomforests_pg_mu->SetPoint(2, 8, 0.-refvalue_pg_mu);
    randomforests_pg_mu->SetPoint(3, 10, 0.-refvalue_pg_mu);
    randomforests_pg_mu->SetPoint(4, 12, 0.-refvalue_pg_mu);
    randomforests_pg_mu->SetLineColor( kBlue); randomforests_pg_mu->SetMarkerColor( kBlue); randomforests_pg_mu->SetFillColor( kWhite);
    
    TGraph* randomforests_pg_pi = new TGraph();
    randomforests_pg_pi->SetTitle("#pi^{+} selection pi-like cut");
    randomforests_pg_pi->SetPoint(0, 4, 0.-refvalue_pg_pi);
    randomforests_pg_pi->SetPoint(1, 6, 0.-refvalue_pg_pi);
    randomforests_pg_pi->SetPoint(2, 8, 0.-refvalue_pg_pi);
    randomforests_pg_pi->SetPoint(3, 10, 0.-refvalue_pg_pi);
    randomforests_pg_pi->SetPoint(4, 12, 0.-refvalue_pg_pi);
    randomforests_pg_pi->SetLineColor( kRed); randomforests_pg_pi->SetMarkerColor( kRed); randomforests_pg_pi->SetFillColor( kWhite);
    
    TGraph* randomforests_pg_p = new TGraph();
    randomforests_pg_p->SetTitle("p selection p-like cut");
    randomforests_pg_p->SetPoint(0, 4, 0.-refvalue_pg_p);
    randomforests_pg_p->SetPoint(1, 6, 0.-refvalue_pg_p);
    randomforests_pg_p->SetPoint(2, 8, 0.-refvalue_pg_p);
    randomforests_pg_p->SetPoint(3, 10, 0.-refvalue_pg_p);
    randomforests_pg_p->SetPoint(4, 12, 0.-refvalue_pg_p);
    randomforests_pg_p->SetLineColor( kGreen); randomforests_pg_p->SetMarkerColor( kGreen); randomforests_pg_p->SetFillColor( kWhite); 
    
    TGraph* randomforests_pg_e = new TGraph();
    randomforests_pg_e->SetTitle("e^{+} selection e-like cut");
    randomforests_pg_e->SetPoint(0, 4, 0.-refvalue_pg_e);
    randomforests_pg_e->SetPoint(1, 6, 0.-refvalue_pg_e);
    randomforests_pg_e->SetPoint(2, 8, 0.-refvalue_pg_e);
    randomforests_pg_e->SetPoint(3, 10, 0.-refvalue_pg_e);
    randomforests_pg_e->SetPoint(4, 12, 0.-refvalue_pg_e);
    randomforests_pg_e->SetLineColor( kMagenta); randomforests_pg_e->SetMarkerColor( kMagenta); randomforests_pg_e->SetFillColor( kWhite); 
    
    TCanvas* canvas_randomforests = new TCanvas("canvas_randomforests","",200,10,1000,400);
    randomforests_pg_mu->GetYaxis()->SetRangeUser(-0.5, 0.5);
    randomforests_pg_mu->GetXaxis()->SetTitle("Random forests NVars"); randomforests_pg_mu->GetYaxis()->SetTitle("Difference in efficiency");
    randomforests_pg_mu->Draw("AL*");
    randomforests_pg_pi->Draw("L* same");
    randomforests_pg_p->Draw("L* same");
    randomforests_pg_e->Draw("L* same");
    canvas_randomforests->BuildLegend();
    
}
