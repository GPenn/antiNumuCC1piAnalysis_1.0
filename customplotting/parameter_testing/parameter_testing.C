{
    Float_t refvalue_cc1pi_mu, refvalue_cc1pi_pi, refvalue_pg_mu, refvalue_pg_pi, refvalue_pg_p, refvalue_pg_e;
    
    // =============== Tree depth ===============
    
    refvalue_cc1pi_mu = 33.8996;
    TGraph* treedepth_cc1pi_mu = new TGraph();
    treedepth_cc1pi_mu->SetTitle("#mu^{+} selection mu-like cut");
    treedepth_cc1pi_mu->SetPoint(0, 2.0, 33.6252/refvalue_cc1pi_mu);
    treedepth_cc1pi_mu->SetPoint(1, 3.0, 33.8996/refvalue_cc1pi_mu);
    treedepth_cc1pi_mu->SetPoint(2, 4.0, 33.8306/refvalue_cc1pi_mu);
    treedepth_cc1pi_mu->SetPoint(3, 5.0, 33.9517/refvalue_cc1pi_mu);
    treedepth_cc1pi_mu->SetLineColor( kBlue); treedepth_cc1pi_mu->SetMarkerColor( kBlue); treedepth_cc1pi_mu->SetFillColor( kWhite); 
    
    refvalue_cc1pi_pi = 37.6332;
    TGraph* treedepth_cc1pi_pi = new TGraph();
    treedepth_cc1pi_pi->SetTitle("#pi^{-} selection pi-like cut");
    treedepth_cc1pi_pi->SetPoint(0, 2.0, 36.5911/refvalue_cc1pi_pi);
    treedepth_cc1pi_pi->SetPoint(1, 3.0, 37.6332/refvalue_cc1pi_pi);
    treedepth_cc1pi_pi->SetPoint(2, 4.0, 38.3201/refvalue_cc1pi_pi);
    treedepth_cc1pi_pi->SetPoint(3, 5.0, 37.4604/refvalue_cc1pi_pi);
    treedepth_cc1pi_pi->SetLineColor( kRed); treedepth_cc1pi_pi->SetMarkerColor( kRed); treedepth_cc1pi_pi->SetFillColor( kWhite); 
    
    refvalue_pg_mu = 215.289;
    TGraph* treedepth_pg_mu = new TGraph();
    treedepth_pg_mu->SetTitle("#mu^{+} selection mu-like cut");
    treedepth_pg_mu->SetPoint(0, 2.0, 213.861/refvalue_pg_mu);
    treedepth_pg_mu->SetPoint(1, 3.0, 215.289/refvalue_pg_mu);
    treedepth_pg_mu->SetPoint(2, 4.0, 215.964/refvalue_pg_mu);
    treedepth_pg_mu->SetPoint(3, 5.0, 215.816/refvalue_pg_mu);
    treedepth_pg_mu->SetLineColor( kBlue); treedepth_pg_mu->SetMarkerColor( kBlue); treedepth_pg_mu->SetFillColor( kWhite);
    
    refvalue_pg_pi = 150.043;
    TGraph* treedepth_pg_pi = new TGraph();
    treedepth_pg_pi->SetTitle("#pi^{+} selection pi-like cut");
    treedepth_pg_pi->SetPoint(0, 2.0, 149.891/refvalue_pg_pi);
    treedepth_pg_pi->SetPoint(1, 3.0, 150.043/refvalue_pg_pi);
    treedepth_pg_pi->SetPoint(2, 4.0, 152.363/refvalue_pg_pi);
    treedepth_pg_pi->SetPoint(3, 5.0, 149.491/refvalue_pg_pi);
    treedepth_pg_pi->SetLineColor( kRed); treedepth_pg_pi->SetMarkerColor( kRed); treedepth_pg_pi->SetFillColor( kWhite); 
    
    refvalue_pg_p = 203.881;
    TGraph* treedepth_pg_p = new TGraph();
    treedepth_pg_p->SetTitle("p selection p-like cut");
    treedepth_pg_p->SetPoint(0, 2.0, 202.915/refvalue_pg_p);
    treedepth_pg_p->SetPoint(1, 3.0, 203.881/refvalue_pg_p);
    treedepth_pg_p->SetPoint(2, 4.0, 203.882/refvalue_pg_p);
    treedepth_pg_p->SetPoint(3, 5.0, 204.167/refvalue_pg_p);
    treedepth_pg_p->SetLineColor( kGreen); treedepth_pg_p->SetMarkerColor( kGreen); treedepth_pg_p->SetFillColor( kWhite); 
    
    refvalue_pg_e = 190.245;
    TGraph* treedepth_pg_e = new TGraph();
    treedepth_pg_e->SetTitle("e^{+} selection e-like cut");
    treedepth_pg_e->SetPoint(0, 2.0, 189.429/refvalue_pg_e);
    treedepth_pg_e->SetPoint(1, 3.0, 190.245/refvalue_pg_e);
    treedepth_pg_e->SetPoint(2, 4.0, 190.529/refvalue_pg_e);
    treedepth_pg_e->SetPoint(3, 5.0, 190.811/refvalue_pg_e);
    treedepth_pg_e->SetLineColor( kMagenta); treedepth_pg_e->SetMarkerColor( kMagenta); treedepth_pg_e->SetFillColor( kWhite); 
    
    TCanvas* canvas_treedepth = new TCanvas("canvas_treedepth","",200,10,1000,400);
    canvas_treedepth->Divide(2,1,0.005,0.005);
    canvas_treedepth->cd(1);
    
    treedepth_cc1pi_mu->GetYaxis()->SetRangeUser(0.97, 1.02);
    treedepth_cc1pi_mu->GetXaxis()->SetTitle("Maximum tree depth"); treedepth_cc1pi_mu->GetYaxis()->SetTitle("Optimal selection significance");
    
    treedepth_cc1pi_mu->Draw("AL*");
    treedepth_cc1pi_pi->Draw("L* same");
    canvas_treedepth->cd(1)->BuildLegend();
    
    canvas_treedepth->cd(2);
    treedepth_pg_mu->GetYaxis()->SetRangeUser(0.99, 1.02);
    treedepth_pg_mu->GetXaxis()->SetTitle("Maximum tree depth"); treedepth_pg_mu->GetYaxis()->SetTitle("Optimal selection significance");
    treedepth_pg_mu->Draw("AL*");
    treedepth_pg_pi->Draw("L* same");
    treedepth_pg_p->Draw("L* same");
    treedepth_pg_e->Draw("L* same");
    canvas_treedepth->cd(2)->BuildLegend();
    
    // =============== Tree number ===============
    
    TGraph* treenumber_cc1pi_mu = new TGraph();
    treenumber_cc1pi_mu->SetTitle("#mu^{+} selection mu-like cut");
    treenumber_cc1pi_mu->SetPoint(0, 500.0, 34.1489/refvalue_cc1pi_mu);
    treenumber_cc1pi_mu->SetPoint(1, 1000.0, 33.8996/refvalue_cc1pi_mu);
    treenumber_cc1pi_mu->SetPoint(2, 1500.0, 33.8901/refvalue_cc1pi_mu);
    treenumber_cc1pi_mu->SetPoint(3, 2000.0, 33.7458/refvalue_cc1pi_mu);
    treenumber_cc1pi_mu->SetPoint(4, 2500.0, 33.6327/refvalue_cc1pi_mu);
    treenumber_cc1pi_mu->SetLineColor( kBlue); treenumber_cc1pi_mu->SetMarkerColor( kBlue); treenumber_cc1pi_mu->SetFillColor( kWhite); 
    
    TGraph* treenumber_cc1pi_pi = new TGraph();
    treenumber_cc1pi_pi->SetTitle("#pi^{-} selection pi-like cut");
    treenumber_cc1pi_pi->SetPoint(0, 500.0, 37.9658/refvalue_cc1pi_pi);
    treenumber_cc1pi_pi->SetPoint(1, 1000.0, 37.6332/refvalue_cc1pi_pi);
    treenumber_cc1pi_pi->SetPoint(2, 1500.0, 37.9448/refvalue_cc1pi_pi);
    treenumber_cc1pi_pi->SetPoint(3, 2000.0, 38.1583/refvalue_cc1pi_pi);
    treenumber_cc1pi_pi->SetPoint(4, 2500.0, 38.2595/refvalue_cc1pi_pi);
    treenumber_cc1pi_pi->SetLineColor( kRed); treenumber_cc1pi_pi->SetMarkerColor( kRed); treenumber_cc1pi_pi->SetFillColor( kWhite); 
    
    TGraph* treenumber_pg_mu = new TGraph();
    treenumber_pg_mu->SetTitle("#mu^{+} selection mu-like cut");
    treenumber_pg_mu->SetPoint(0, 500.0, 215.51/refvalue_pg_mu);
    treenumber_pg_mu->SetPoint(1, 1000.0, 215.289/refvalue_pg_mu);
    treenumber_pg_mu->SetPoint(2, 1500.0, 215.027/refvalue_pg_mu);
    treenumber_pg_mu->SetPoint(3, 2000.0, 215.179/refvalue_pg_mu);
    treenumber_pg_mu->SetPoint(4, 2500.0, 215.111/refvalue_pg_mu);
    treenumber_pg_mu->SetLineColor( kBlue); treenumber_pg_mu->SetMarkerColor( kBlue); treenumber_pg_mu->SetFillColor( kWhite);
    
    TGraph* treenumber_pg_pi = new TGraph();
    treenumber_pg_pi->SetTitle("#pi^{+} selection pi-like cut");
    treenumber_pg_pi->SetPoint(0, 500.0, 151.925/refvalue_pg_pi);
    treenumber_pg_pi->SetPoint(1, 1000.0, 150.043/refvalue_pg_pi);
    treenumber_pg_pi->SetPoint(2, 1500.0, 148.971/refvalue_pg_pi);
    treenumber_pg_pi->SetPoint(3, 2000.0, 148.151/refvalue_pg_pi);
    treenumber_pg_pi->SetPoint(4, 2500.0, 147.368/refvalue_pg_pi);
    treenumber_pg_pi->SetLineColor( kRed); treenumber_pg_pi->SetMarkerColor( kRed); treenumber_pg_pi->SetFillColor( kWhite);
    
    TGraph* treenumber_pg_p = new TGraph();
    treenumber_pg_p->SetTitle("p selection p-like cut");
    treenumber_pg_p->SetPoint(0, 500.0, 200.286/refvalue_pg_p);
    treenumber_pg_p->SetPoint(1, 1000.0, 203.881/refvalue_pg_p);
    treenumber_pg_p->SetPoint(2, 1500.0, 205.612/refvalue_pg_p);
    treenumber_pg_p->SetPoint(3, 2000.0, 206.868/refvalue_pg_p);
    treenumber_pg_p->SetPoint(4, 2500.0, 207.432/refvalue_pg_p);
    treenumber_pg_p->SetLineColor( kGreen); treenumber_pg_p->SetMarkerColor( kGreen); treenumber_pg_p->SetFillColor( kWhite); 
    
    TGraph* treenumber_pg_e = new TGraph();
    treenumber_pg_e->SetTitle("e^{+} selection e-like cut");
    treenumber_pg_e->SetPoint(0, 500.0, 189.781/refvalue_pg_e);
    treenumber_pg_e->SetPoint(1, 1000.0, 190.245/refvalue_pg_e);
    treenumber_pg_e->SetPoint(2, 1500.0, 190.52/refvalue_pg_e);
    treenumber_pg_e->SetPoint(3, 2000.0, 190.794/refvalue_pg_e);
    treenumber_pg_e->SetPoint(4, 2500.0, 190.877/refvalue_pg_e);
    treenumber_pg_e->SetLineColor( kMagenta); treenumber_pg_e->SetMarkerColor( kMagenta); treenumber_pg_e->SetFillColor( kWhite); 
    
    TCanvas* canvas_treenumber = new TCanvas("canvas_treenumber","",200,10,1000,400);
    canvas_treenumber->Divide(2,1,0.005,0.005);
    canvas_treenumber->cd(1);
    
    treenumber_cc1pi_mu->GetYaxis()->SetRangeUser(0.99, 1.02);
    treenumber_cc1pi_mu->GetXaxis()->SetTitle("Number of trees"); treenumber_cc1pi_mu->GetYaxis()->SetTitle("Optimal selection significance");
    
    treenumber_cc1pi_mu->Draw("AL*");
    treenumber_cc1pi_pi->Draw("L* same");
    canvas_treenumber->cd(1)->BuildLegend();
    
    canvas_treenumber->cd(2);
    treenumber_pg_mu->GetYaxis()->SetRangeUser(0.98, 1.02);
    treenumber_pg_mu->GetXaxis()->SetTitle("Number of trees"); treenumber_pg_mu->GetYaxis()->SetTitle("Optimal selection significance");
    treenumber_pg_mu->Draw("AL*");
    treenumber_pg_pi->Draw("L* same");
    treenumber_pg_p->Draw("L* same");
    treenumber_pg_e->Draw("L* same");
    canvas_treenumber->cd(2)->BuildLegend();
    
    // =============== Shrinkage ===============
    
    TGraph* shrinkage_cc1pi_mu = new TGraph();
    shrinkage_cc1pi_mu->SetTitle("#mu^{+} selection mu-like cut");
    shrinkage_cc1pi_mu->SetPoint(0, 0.01, 32.5775/refvalue_cc1pi_mu);
    shrinkage_cc1pi_mu->SetPoint(1, 0.02, 33.567/refvalue_cc1pi_mu);
    shrinkage_cc1pi_mu->SetPoint(2, 0.04, 33.8197/refvalue_cc1pi_mu);
    shrinkage_cc1pi_mu->SetPoint(3, 0.06, 33.8718/refvalue_cc1pi_mu);
    shrinkage_cc1pi_mu->SetPoint(4, 0.08, 33.8665/refvalue_cc1pi_mu);
    shrinkage_cc1pi_mu->SetPoint(5, 0.1, 33.9103/refvalue_cc1pi_mu);
    shrinkage_cc1pi_mu->SetPoint(6, 0.3, 33.9083/refvalue_cc1pi_mu);
    shrinkage_cc1pi_mu->SetPoint(7, 0.5, 34.1139/refvalue_cc1pi_mu);
    shrinkage_cc1pi_mu->SetPoint(8, 0.7, 33.8571/refvalue_cc1pi_mu);
    shrinkage_cc1pi_mu->SetPoint(9, 0.9, 33.7009/refvalue_cc1pi_mu);
    shrinkage_cc1pi_mu->SetLineColor( kBlue); shrinkage_cc1pi_mu->SetMarkerColor( kBlue); shrinkage_cc1pi_mu->SetFillColor( kWhite); 
    
    TGraph* shrinkage_cc1pi_pi = new TGraph();
    shrinkage_cc1pi_pi->SetTitle("#pi^{-} selection pi-like cut");
    shrinkage_cc1pi_pi->SetPoint(0, 0.01, 38.1005/refvalue_cc1pi_pi);
    shrinkage_cc1pi_pi->SetPoint(1, 0.02, 38.4391/refvalue_cc1pi_pi);
    shrinkage_cc1pi_pi->SetPoint(2, 0.04, 38.2936/refvalue_cc1pi_pi);
    shrinkage_cc1pi_pi->SetPoint(3, 0.06, 37.8807/refvalue_cc1pi_pi);
    shrinkage_cc1pi_pi->SetPoint(4, 0.08, 37.4445/refvalue_cc1pi_pi);
    shrinkage_cc1pi_pi->SetPoint(5, 0.1, 37.2625/refvalue_cc1pi_pi);
    shrinkage_cc1pi_pi->SetPoint(6, 0.3, 36.8078/refvalue_cc1pi_pi);
    shrinkage_cc1pi_pi->SetPoint(7, 0.5, 37.2966/refvalue_cc1pi_pi);
    shrinkage_cc1pi_pi->SetPoint(8, 0.7, 37.4721/refvalue_cc1pi_pi);
    shrinkage_cc1pi_pi->SetPoint(9, 0.9, 37.7535/refvalue_cc1pi_pi);
    shrinkage_cc1pi_pi->SetLineColor( kRed); shrinkage_cc1pi_pi->SetMarkerColor( kRed); shrinkage_cc1pi_pi->SetFillColor( kWhite); 
    
    TGraph* shrinkage_pg_mu = new TGraph();
    shrinkage_pg_mu->SetTitle("#mu^{+} selection mu-like cut");
    shrinkage_pg_mu->SetPoint(0, 0.01, 207.859/refvalue_pg_mu);
    shrinkage_pg_mu->SetPoint(1, 0.02, 212.464/refvalue_pg_mu);
    shrinkage_pg_mu->SetPoint(2, 0.04, 214.211/refvalue_pg_mu);
    shrinkage_pg_mu->SetPoint(3, 0.06, 214.38/refvalue_pg_mu);
    shrinkage_pg_mu->SetPoint(4, 0.08, 214.699/refvalue_pg_mu);
    shrinkage_pg_mu->SetPoint(5, 0.1, 214.515/refvalue_pg_mu);
    shrinkage_pg_mu->SetPoint(6, 0.3, 214.925/refvalue_pg_mu);
    shrinkage_pg_mu->SetPoint(7, 0.5, 214.935/refvalue_pg_mu);
    shrinkage_pg_mu->SetPoint(8, 0.7, 213.648/refvalue_pg_mu);
    shrinkage_pg_mu->SetPoint(9, 0.9, 214.2/refvalue_pg_mu);
    shrinkage_pg_mu->SetLineColor( kBlue); shrinkage_pg_mu->SetMarkerColor( kBlue); shrinkage_pg_mu->SetFillColor( kWhite);
    
    TGraph* shrinkage_pg_pi = new TGraph();
    shrinkage_pg_pi->SetTitle("#pi^{+} selection pi-like cut");
    shrinkage_pg_pi->SetPoint(0, 0.01, 161.943/refvalue_pg_pi);
    shrinkage_pg_pi->SetPoint(1, 0.02, 162.073/refvalue_pg_pi);
    shrinkage_pg_pi->SetPoint(2, 0.04, 159.466/refvalue_pg_pi);
    shrinkage_pg_pi->SetPoint(3, 0.06, 161.579/refvalue_pg_pi);
    shrinkage_pg_pi->SetPoint(4, 0.08, 160.826/refvalue_pg_pi);
    shrinkage_pg_pi->SetPoint(5, 0.1, 160.788/refvalue_pg_pi);
    shrinkage_pg_pi->SetPoint(6, 0.3, 151.696/refvalue_pg_pi);
    shrinkage_pg_pi->SetPoint(7, 0.5, 150.355/refvalue_pg_pi);
    shrinkage_pg_pi->SetPoint(8, 0.7, 152.226/refvalue_pg_pi);
    shrinkage_pg_pi->SetPoint(9, 0.9, 149.946/refvalue_pg_pi);
    shrinkage_pg_pi->SetLineColor( kRed); shrinkage_pg_pi->SetMarkerColor( kRed); shrinkage_pg_pi->SetFillColor( kWhite);
    
    TGraph* shrinkage_pg_p = new TGraph();
    shrinkage_pg_p->SetTitle("p selection p-like cut");
    shrinkage_pg_p->SetPoint(0, 0.01, 165.537/refvalue_pg_p);
    shrinkage_pg_p->SetPoint(1, 0.02, 172.343/refvalue_pg_p);
    shrinkage_pg_p->SetPoint(2, 0.04, 179.977/refvalue_pg_p);
    shrinkage_pg_p->SetPoint(3, 0.06, 183.995/refvalue_pg_p);
    shrinkage_pg_p->SetPoint(4, 0.08, 191.024/refvalue_pg_p);
    shrinkage_pg_p->SetPoint(5, 0.1, 194.072/refvalue_pg_p);
    shrinkage_pg_p->SetPoint(6, 0.3, 200.638/refvalue_pg_p);
    shrinkage_pg_p->SetPoint(7, 0.5, 202.898/refvalue_pg_p);
    shrinkage_pg_p->SetPoint(8, 0.7, 201.552/refvalue_pg_p);
    shrinkage_pg_p->SetPoint(9, 0.9, 204.437/refvalue_pg_p);
    shrinkage_pg_p->SetLineColor( kGreen); shrinkage_pg_p->SetMarkerColor( kGreen); shrinkage_pg_p->SetFillColor( kWhite); 
    
    TGraph* shrinkage_pg_e = new TGraph();
    shrinkage_pg_e->SetTitle("e^{+} selection e-like cut");
    shrinkage_pg_e->SetPoint(0, 0.01, 178.483/refvalue_pg_e);
    shrinkage_pg_e->SetPoint(1, 0.02, 179.224/refvalue_pg_e);
    shrinkage_pg_e->SetPoint(2, 0.04, 190.025/refvalue_pg_e);
    shrinkage_pg_e->SetPoint(3, 0.06, 209.452/refvalue_pg_e);
    shrinkage_pg_e->SetPoint(4, 0.08, 225.196/refvalue_pg_e);
    shrinkage_pg_e->SetPoint(5, 0.1, 226.61/refvalue_pg_e);
    shrinkage_pg_e->SetPoint(6, 0.3, 204.121/refvalue_pg_e);
    shrinkage_pg_e->SetPoint(7, 0.5, 189.983/refvalue_pg_e);
    shrinkage_pg_e->SetPoint(8, 0.7, 190.093/refvalue_pg_e);
    shrinkage_pg_e->SetPoint(9, 0.9, 190.258/refvalue_pg_e);
    shrinkage_pg_e->SetLineColor( kMagenta); shrinkage_pg_e->SetMarkerColor( kMagenta); shrinkage_pg_e->SetFillColor( kWhite); 
    
    TCanvas* canvas_shrinkage = new TCanvas("canvas_shrinkage","",200,10,1000,400);
    canvas_shrinkage->Divide(2,1,0.005,0.005);
    canvas_shrinkage->cd(1);
    
    shrinkage_cc1pi_mu->GetYaxis()->SetRangeUser(0.97, 1.01);
    shrinkage_cc1pi_mu->GetXaxis()->SetTitle("Shrinkage"); shrinkage_cc1pi_mu->GetYaxis()->SetTitle("Optimal selection significance");
    
    shrinkage_cc1pi_mu->Draw("AL*");
    shrinkage_cc1pi_pi->Draw("L* same");
    canvas_shrinkage->cd(1)->BuildLegend();
    
    canvas_shrinkage->cd(2);
    shrinkage_pg_mu->GetYaxis()->SetRangeUser(0.94, 1.2);
    shrinkage_pg_mu->GetXaxis()->SetTitle("Shrinkage"); shrinkage_pg_mu->GetYaxis()->SetTitle("Optimal selection significance");
    shrinkage_pg_mu->Draw("AL*");
    shrinkage_pg_pi->Draw("L* same");
    shrinkage_pg_p->Draw("L* same");
    shrinkage_pg_e->Draw("L* same");
    canvas_shrinkage->cd(2)->BuildLegend();
    
    // =============== Bagged ===============
    
    TGraph* bagged_cc1pi_mu = new TGraph();
    bagged_cc1pi_mu->SetTitle("#mu^{+} selection mu-like cut");
    bagged_cc1pi_mu->SetPoint(0, 0.1, 3.84728/refvalue_cc1pi_mu);
    bagged_cc1pi_mu->SetPoint(1, 0.3, 33.6713/refvalue_cc1pi_mu);
    bagged_cc1pi_mu->SetPoint(2, 0.5, 33.9727/refvalue_cc1pi_mu);
    bagged_cc1pi_mu->SetPoint(3, 0.7, 34.0087/refvalue_cc1pi_mu);
    bagged_cc1pi_mu->SetPoint(4, 0.9, 33.9844/refvalue_cc1pi_mu);
    bagged_cc1pi_mu->SetLineColor( kBlue); bagged_cc1pi_mu->SetMarkerColor( kBlue); bagged_cc1pi_mu->SetFillColor( kWhite); 
    
    TGraph* bagged_cc1pi_pi = new TGraph();
    bagged_cc1pi_pi->SetTitle("#pi^{-} selection pi-like cut");
    bagged_cc1pi_pi->SetPoint(0, 0.1, 20.8977/refvalue_cc1pi_pi);
    bagged_cc1pi_pi->SetPoint(1, 0.3, 38.0971/refvalue_cc1pi_pi);
    bagged_cc1pi_pi->SetPoint(2, 0.5, 39.0355/refvalue_cc1pi_pi);
    bagged_cc1pi_pi->SetPoint(3, 0.7, 38.0736/refvalue_cc1pi_pi);
    bagged_cc1pi_pi->SetPoint(4, 0.9, 37.5323/refvalue_cc1pi_pi);
    bagged_cc1pi_pi->SetLineColor( kRed); bagged_cc1pi_pi->SetMarkerColor( kRed); bagged_cc1pi_pi->SetFillColor( kWhite); 
    
    TGraph* bagged_pg_mu = new TGraph();
    bagged_pg_mu->SetTitle("#mu^{+} selection mu-like cut");
    bagged_pg_mu->SetPoint(0, 0.1, 17.2556/refvalue_pg_mu);
    bagged_pg_mu->SetPoint(1, 0.3, 212.734/refvalue_pg_mu);
    bagged_pg_mu->SetPoint(2, 0.5, 215.361/refvalue_pg_mu);
    bagged_pg_mu->SetPoint(3, 0.7, 213.182/refvalue_pg_mu);
    bagged_pg_mu->SetPoint(4, 0.9, 213.343/refvalue_pg_mu);
    bagged_pg_mu->SetLineColor( kBlue); bagged_pg_mu->SetMarkerColor( kBlue); bagged_pg_mu->SetFillColor( kWhite);
    
    TGraph* bagged_pg_pi = new TGraph();
    bagged_pg_pi->SetTitle("#pi^{+} selection pi-like cut");
    bagged_pg_pi->SetPoint(0, 0.1, 78.4228/refvalue_pg_pi);
    bagged_pg_pi->SetPoint(1, 0.3, 150.307/refvalue_pg_pi);
    bagged_pg_pi->SetPoint(2, 0.5, 151.027/refvalue_pg_pi);
    bagged_pg_pi->SetPoint(3, 0.7, 152.723/refvalue_pg_pi);
    bagged_pg_pi->SetPoint(4, 0.9, 152.474/refvalue_pg_pi);
    bagged_pg_pi->SetLineColor( kRed); bagged_pg_pi->SetMarkerColor( kRed); bagged_pg_pi->SetFillColor( kWhite);
    
    TGraph* bagged_pg_p = new TGraph();
    bagged_pg_p->SetTitle("p selection p-like cut");
    bagged_pg_p->SetPoint(0, 0.1, 21.5663/refvalue_pg_p);
    bagged_pg_p->SetPoint(1, 0.3, 201.232/refvalue_pg_p);
    bagged_pg_p->SetPoint(2, 0.5, 203.881/refvalue_pg_p);
    bagged_pg_p->SetPoint(3, 0.7, 201.34/refvalue_pg_p);
    bagged_pg_p->SetPoint(4, 0.9, 200.998/refvalue_pg_p);
    bagged_pg_p->SetLineColor( kGreen); bagged_pg_p->SetMarkerColor( kGreen); bagged_pg_p->SetFillColor( kWhite); 
    
    TGraph* bagged_pg_e = new TGraph();
    bagged_pg_e->SetTitle("e^{+} selection e-like cut");
    bagged_pg_e->SetPoint(0, 0.1, 70.5179/refvalue_pg_e);
    bagged_pg_e->SetPoint(1, 0.3, 189.74/refvalue_pg_e);
    bagged_pg_e->SetPoint(2, 0.5, 189.412/refvalue_pg_e);
    bagged_pg_e->SetPoint(3, 0.7, 189.534/refvalue_pg_e);
    bagged_pg_e->SetPoint(4, 0.9, 189.716/refvalue_pg_e);
    bagged_pg_e->SetLineColor( kMagenta); bagged_pg_e->SetMarkerColor( kMagenta); bagged_pg_e->SetFillColor( kWhite); 
    
    TCanvas* canvas_bagged = new TCanvas("canvas_bagged","",200,10,1000,400);
    canvas_bagged->Divide(2,1,0.005,0.005);
    canvas_bagged->cd(1);
    
    bagged_cc1pi_mu->GetYaxis()->SetRangeUser(0.0, 1.1);
    bagged_cc1pi_mu->GetXaxis()->SetTitle("BaggedSampleFraction"); bagged_cc1pi_mu->GetYaxis()->SetTitle("Optimal selection significance");
    
    bagged_cc1pi_mu->Draw("AL*");
    bagged_cc1pi_pi->Draw("L* same");
    canvas_bagged->cd(1)->BuildLegend();
    
    canvas_bagged->cd(2);
    bagged_pg_mu->GetYaxis()->SetRangeUser(0.0, 1.1);
    bagged_pg_mu->GetXaxis()->SetTitle("BaggedSampleFraction"); bagged_pg_mu->GetYaxis()->SetTitle("Optimal selection significance");
    bagged_pg_mu->Draw("AL*");
    bagged_pg_pi->Draw("L* same");
    bagged_pg_p->Draw("L* same");
    bagged_pg_e->Draw("L* same");
    canvas_bagged->cd(2)->BuildLegend();
    
    // =============== Random Forests ===============
    
    TGraph* randomforests_cc1pi_mu = new TGraph();
    randomforests_cc1pi_mu->SetTitle("#mu^{+} selection mu-like cut");
    randomforests_cc1pi_mu->SetPoint(0, 4, 34.1248/refvalue_cc1pi_mu);
    randomforests_cc1pi_mu->SetPoint(1, 6, 33.6847/refvalue_cc1pi_mu);
    randomforests_cc1pi_mu->SetPoint(2, 8, 33.6481/refvalue_cc1pi_mu);
    randomforests_cc1pi_mu->SetPoint(3, 10, 33.9779/refvalue_cc1pi_mu);
    randomforests_cc1pi_mu->SetPoint(4, 12, 33.941/refvalue_cc1pi_mu);
    randomforests_cc1pi_mu->SetLineColor( kBlue); randomforests_cc1pi_mu->SetMarkerColor( kBlue); randomforests_cc1pi_mu->SetFillColor( kWhite); 
    
    TGraph* randomforests_cc1pi_pi = new TGraph();
    randomforests_cc1pi_pi->SetTitle("#pi^{-} selection pi-like cut");
    randomforests_cc1pi_pi->SetPoint(0, 4, 38.1458/refvalue_cc1pi_pi);
    randomforests_cc1pi_pi->SetPoint(1, 6, 38.2231/refvalue_cc1pi_pi);
    randomforests_cc1pi_pi->SetPoint(2, 8, 37.4376/refvalue_cc1pi_pi);
    randomforests_cc1pi_pi->SetPoint(3, 10, 38.1163/refvalue_cc1pi_pi);
    randomforests_cc1pi_pi->SetPoint(4, 12, 37.6063/refvalue_cc1pi_pi);
    randomforests_cc1pi_pi->SetLineColor( kRed); randomforests_cc1pi_pi->SetMarkerColor( kRed); randomforests_cc1pi_pi->SetFillColor( kWhite); 
    
    TGraph* randomforests_pg_mu = new TGraph();
    randomforests_pg_mu->SetTitle("#mu^{+} selection mu-like cut");
    randomforests_pg_mu->SetPoint(0, 4, 216.212/refvalue_pg_mu);
    randomforests_pg_mu->SetPoint(1, 6, 212.49/refvalue_pg_mu);
    randomforests_pg_mu->SetPoint(2, 8, 214.048/refvalue_pg_mu);
    randomforests_pg_mu->SetPoint(3, 10, 215.163/refvalue_pg_mu);
    randomforests_pg_mu->SetPoint(4, 12, 214.458/refvalue_pg_mu);
    randomforests_pg_mu->SetLineColor( kBlue); randomforests_pg_mu->SetMarkerColor( kBlue); randomforests_pg_mu->SetFillColor( kWhite);
    
    TGraph* randomforests_pg_pi = new TGraph();
    randomforests_pg_pi->SetTitle("#pi^{+} selection pi-like cut");
    randomforests_pg_pi->SetPoint(0, 4, 151.775/refvalue_pg_pi);
    randomforests_pg_pi->SetPoint(1, 6, 155.36/refvalue_pg_pi);
    randomforests_pg_pi->SetPoint(2, 8, 151.529/refvalue_pg_pi);
    randomforests_pg_pi->SetPoint(3, 10, 152.472/refvalue_pg_pi);
    randomforests_pg_pi->SetPoint(4, 12, 149.771/refvalue_pg_pi);
    randomforests_pg_pi->SetLineColor( kRed); randomforests_pg_pi->SetMarkerColor( kRed); randomforests_pg_pi->SetFillColor( kWhite);
    
    TGraph* randomforests_pg_p = new TGraph();
    randomforests_pg_p->SetTitle("p selection p-like cut");
    randomforests_pg_p->SetPoint(0, 4, 208.424/refvalue_pg_p);
    randomforests_pg_p->SetPoint(1, 6, 202.563/refvalue_pg_p);
    randomforests_pg_p->SetPoint(2, 8, 204.814/refvalue_pg_p);
    randomforests_pg_p->SetPoint(3, 10, 201.384/refvalue_pg_p);
    randomforests_pg_p->SetPoint(4, 12, 205.496/refvalue_pg_p);
    randomforests_pg_p->SetLineColor( kGreen); randomforests_pg_p->SetMarkerColor( kGreen); randomforests_pg_p->SetFillColor( kWhite); 
    
    TGraph* randomforests_pg_e = new TGraph();
    randomforests_pg_e->SetTitle("e^{+} selection e-like cut");
    randomforests_pg_e->SetPoint(0, 4, 190.772/refvalue_pg_e);
    randomforests_pg_e->SetPoint(1, 6, 190.411/refvalue_pg_e);
    randomforests_pg_e->SetPoint(2, 8, 190.36/refvalue_pg_e);
    randomforests_pg_e->SetPoint(3, 10, 190.32/refvalue_pg_e);
    randomforests_pg_e->SetPoint(4, 12, 190.345/refvalue_pg_e);
    randomforests_pg_e->SetLineColor( kMagenta); randomforests_pg_e->SetMarkerColor( kMagenta); randomforests_pg_e->SetFillColor( kWhite); 
    
    TCanvas* canvas_randomforests = new TCanvas("canvas_randomforests","",200,10,1000,400);
    canvas_randomforests->Divide(2,1,0.005,0.005);
    canvas_randomforests->cd(1);
    
    randomforests_cc1pi_mu->GetYaxis()->SetRangeUser(0.9, 1.1);
    randomforests_cc1pi_mu->GetXaxis()->SetTitle("Random forests NVars"); randomforests_cc1pi_mu->GetYaxis()->SetTitle("Optimal selection significance");
    
    randomforests_cc1pi_mu->Draw("AL*");
    randomforests_cc1pi_pi->Draw("L* same");
    canvas_randomforests->cd(1)->BuildLegend();
    
    canvas_randomforests->cd(2);
    randomforests_pg_mu->GetYaxis()->SetRangeUser(0.9, 1.1);
    randomforests_pg_mu->GetXaxis()->SetTitle("Random forests NVars"); randomforests_pg_mu->GetYaxis()->SetTitle("Optimal selection significance");
    randomforests_pg_mu->Draw("AL*");
    randomforests_pg_pi->Draw("L* same");
    randomforests_pg_p->Draw("L* same");
    randomforests_pg_e->Draw("L* same");
    canvas_randomforests->cd(2)->BuildLegend();
    
}
