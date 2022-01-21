{
    // =============== Tree depth ===============
    
    TGraph* treedepth_cc1pi_mu = new TGraph();
    treedepth_cc1pi_mu->SetTitle("#mu^{+} selection mu-like cut");
    treedepth_cc1pi_mu->SetPoint(0, 2.0, 33.4749);
    treedepth_cc1pi_mu->SetPoint(1, 3.0, 34.1666);
    treedepth_cc1pi_mu->SetPoint(2, 4.0, 34.0363);
    treedepth_cc1pi_mu->SetPoint(3, 5.0, 34.2227);
    treedepth_cc1pi_mu->SetLineColor( kBlue); treedepth_cc1pi_mu->SetMarkerColor( kBlue); treedepth_cc1pi_mu->SetFillColor( kWhite); 
    
    TGraph* treedepth_cc1pi_pi = new TGraph();
    treedepth_cc1pi_pi->SetTitle("#pi^{-} selection pi-like cut");
    treedepth_cc1pi_pi->SetPoint(0, 2.0, 35.4578);
    treedepth_cc1pi_pi->SetPoint(1, 3.0, 37.6588);
    treedepth_cc1pi_pi->SetPoint(2, 4.0, 37.9999);
    treedepth_cc1pi_pi->SetPoint(3, 5.0, 38.4385);
    treedepth_cc1pi_pi->SetLineColor( kRed); treedepth_cc1pi_pi->SetMarkerColor( kRed); treedepth_cc1pi_pi->SetFillColor( kWhite); 
    
    TGraph* treedepth_pg_mu = new TGraph();
    treedepth_pg_mu->SetTitle("#mu^{+} selection mu-like cut");
    treedepth_pg_mu->SetPoint(0, 2.0, 213.045);
    treedepth_pg_mu->SetPoint(1, 3.0, 216.102);
    treedepth_pg_mu->SetPoint(2, 4.0, 215.92);
    treedepth_pg_mu->SetPoint(3, 5.0, 216.812);
    treedepth_pg_mu->SetLineColor( kBlue); treedepth_pg_mu->SetMarkerColor( kBlue); treedepth_pg_mu->SetFillColor( kWhite);
    
    TGraph* treedepth_pg_pi = new TGraph();
    treedepth_pg_pi->SetTitle("#pi^{+} selection pi-like cut");
    treedepth_pg_pi->SetPoint(0, 2.0, 148.487);
    treedepth_pg_pi->SetPoint(1, 3.0, 151.511);
    treedepth_pg_pi->SetPoint(2, 4.0, 150.04);
    treedepth_pg_pi->SetPoint(3, 5.0, 151.614);
    treedepth_pg_pi->SetLineColor( kRed); treedepth_pg_pi->SetMarkerColor( kRed); treedepth_pg_pi->SetFillColor( kWhite); 
    
    TGraph* treedepth_pg_p = new TGraph();
    treedepth_pg_p->SetTitle("p selection p-like cut");
    treedepth_pg_p->SetPoint(0, 2.0, 201.171);
    treedepth_pg_p->SetPoint(1, 3.0, 202.493);
    treedepth_pg_p->SetPoint(2, 4.0, 205.948);
    treedepth_pg_p->SetPoint(3, 5.0, 204.806);
    treedepth_pg_p->SetLineColor( kGreen); treedepth_pg_p->SetMarkerColor( kGreen); treedepth_pg_p->SetFillColor( kWhite); 
    
    TGraph* treedepth_pg_e = new TGraph();
    treedepth_pg_e->SetTitle("e^{+} selection e-like cut");
    treedepth_pg_e->SetPoint(0, 2.0, 219.126);
    treedepth_pg_e->SetPoint(1, 3.0, 188.998);
    treedepth_pg_e->SetPoint(2, 4.0, 189.719);
    treedepth_pg_e->SetPoint(3, 5.0, 189.99);
    treedepth_pg_e->SetLineColor( kMagenta); treedepth_pg_e->SetMarkerColor( kMagenta); treedepth_pg_e->SetFillColor( kWhite); 
    
    TCanvas* canvas_treedepth = new TCanvas("canvas_treedepth","",200,10,1000,400);
    canvas_treedepth->Divide(2,1,0.005,0.005);
    canvas_treedepth->cd(1);
    
    treedepth_cc1pi_mu->GetYaxis()->SetRangeUser(30.0, 40.0);
    treedepth_cc1pi_mu->GetXaxis()->SetTitle("Maximum tree depth"); treedepth_cc1pi_mu->GetYaxis()->SetTitle("Optimal selection significance");
    
    treedepth_cc1pi_mu->Draw("AL*");
    treedepth_cc1pi_pi->Draw("L* same");
    canvas_treedepth->cd(1)->BuildLegend();
    
    canvas_treedepth->cd(2);
    treedepth_pg_mu->GetYaxis()->SetRangeUser(140.0, 230.0);
    treedepth_pg_mu->GetXaxis()->SetTitle("Maximum tree depth"); treedepth_pg_mu->GetYaxis()->SetTitle("Optimal selection significance");
    treedepth_pg_mu->Draw("AL*");
    treedepth_pg_pi->Draw("L* same");
    treedepth_pg_p->Draw("L* same");
    treedepth_pg_e->Draw("L* same");
    canvas_treedepth->cd(2)->BuildLegend();
    
    // =============== Tree number ===============
    
    TGraph* treenumber_cc1pi_mu = new TGraph();
    treenumber_cc1pi_mu->SetTitle("#mu^{+} selection mu-like cut");
    treenumber_cc1pi_mu->SetPoint(0, 500.0, 31.882);
    treenumber_cc1pi_mu->SetPoint(1, 1000.0, 31.5975);
    treenumber_cc1pi_mu->SetPoint(2, 1500.0, 31.4073);
    treenumber_cc1pi_mu->SetPoint(3, 2000.0, 31.2578);
    treenumber_cc1pi_mu->SetPoint(4, 2500.0, 31.1631);
    treenumber_cc1pi_mu->SetLineColor( kBlue); treenumber_cc1pi_mu->SetMarkerColor( kBlue); treenumber_cc1pi_mu->SetFillColor( kWhite); 
    
    TGraph* treenumber_cc1pi_pi = new TGraph();
    treenumber_cc1pi_pi->SetTitle("#pi^{-} selection pi-like cut");
    treenumber_cc1pi_pi->SetPoint(0, 500.0, 34.7918);
    treenumber_cc1pi_pi->SetPoint(1, 1000.0, 34.8224);
    treenumber_cc1pi_pi->SetPoint(2, 1500.0, 35.0421);
    treenumber_cc1pi_pi->SetPoint(3, 2000.0, 35.0117);
    treenumber_cc1pi_pi->SetPoint(4, 2500.0, 35.0931);
    treenumber_cc1pi_pi->SetLineColor( kRed); treenumber_cc1pi_pi->SetMarkerColor( kRed); treenumber_cc1pi_pi->SetFillColor( kWhite); 
    
    TGraph* treenumber_pg_mu = new TGraph();
    treenumber_pg_mu->SetTitle("#mu^{+} selection mu-like cut");
    treenumber_pg_mu->SetPoint(0, 500.0, 216.416);
    treenumber_pg_mu->SetPoint(1, 1000.0, 216.102);
    treenumber_pg_mu->SetPoint(2, 1500.0, 215.37);
    treenumber_pg_mu->SetPoint(3, 2000.0, 214.997);
    treenumber_pg_mu->SetPoint(4, 2500.0, 214.842);
    treenumber_pg_mu->SetLineColor( kBlue); treenumber_pg_mu->SetMarkerColor( kBlue); treenumber_pg_mu->SetFillColor( kWhite);
    
    TGraph* treenumber_pg_pi = new TGraph();
    treenumber_pg_pi->SetTitle("#pi^{+} selection pi-like cut");
    treenumber_pg_pi->SetPoint(0, 500.0, 153.701);
    treenumber_pg_pi->SetPoint(1, 1000.0, 151.511);
    treenumber_pg_pi->SetPoint(2, 1500.0, 150.081);
    treenumber_pg_pi->SetPoint(3, 2000.0, 149.145);
    treenumber_pg_pi->SetPoint(4, 2500.0, 149.125);
    treenumber_pg_pi->SetLineColor( kRed); treenumber_pg_pi->SetMarkerColor( kRed); treenumber_pg_pi->SetFillColor( kWhite);
    
    TGraph* treenumber_pg_p = new TGraph();
    treenumber_pg_p->SetTitle("p selection p-like cut");
    treenumber_pg_p->SetPoint(0, 500.0, 198.702);
    treenumber_pg_p->SetPoint(1, 1000.0, 202.493);
    treenumber_pg_p->SetPoint(2, 1500.0, 204.717);
    treenumber_pg_p->SetPoint(3, 2000.0, 206.116);
    treenumber_pg_p->SetPoint(4, 2500.0, 206.554);
    treenumber_pg_p->SetLineColor( kGreen); treenumber_pg_p->SetMarkerColor( kGreen); treenumber_pg_p->SetFillColor( kWhite); 
    
    TGraph* treenumber_pg_e = new TGraph();
    treenumber_pg_e->SetTitle("e^{+} selection e-like cut");
    treenumber_pg_e->SetPoint(0, 500.0, 219.786);
    treenumber_pg_e->SetPoint(1, 1000.0, 188.988);
    treenumber_pg_e->SetPoint(2, 1500.0, 189.329);
    treenumber_pg_e->SetPoint(3, 2000.0, 189.509);
    treenumber_pg_e->SetPoint(4, 2500.0, 189.788);
    treenumber_pg_e->SetLineColor( kMagenta); treenumber_pg_e->SetMarkerColor( kMagenta); treenumber_pg_e->SetFillColor( kWhite); 
    
    TCanvas* canvas_treenumber = new TCanvas("canvas_treenumber","",200,10,1000,400);
    canvas_treenumber->Divide(2,1,0.005,0.005);
    canvas_treenumber->cd(1);
    
    treenumber_cc1pi_mu->GetYaxis()->SetRangeUser(30.0, 36.0);
    treenumber_cc1pi_mu->GetXaxis()->SetTitle("Number of trees"); treenumber_cc1pi_mu->GetYaxis()->SetTitle("Optimal selection significance");
    
    treenumber_cc1pi_mu->Draw("AL*");
    treenumber_cc1pi_pi->Draw("L* same");
    canvas_treenumber->cd(1)->BuildLegend();
    
    canvas_treenumber->cd(2);
    treenumber_pg_mu->GetYaxis()->SetRangeUser(140.0, 230.0);
    treenumber_pg_mu->GetXaxis()->SetTitle("Number of trees"); treenumber_pg_mu->GetYaxis()->SetTitle("Optimal selection significance");
    treenumber_pg_mu->Draw("AL*");
    treenumber_pg_pi->Draw("L* same");
    treenumber_pg_p->Draw("L* same");
    treenumber_pg_e->Draw("L* same");
    canvas_treenumber->cd(2)->BuildLegend();
    
    // =============== Shrinkage ===============
    
    TGraph* shrinkage_cc1pi_mu = new TGraph();
    shrinkage_cc1pi_mu->SetTitle("#mu^{+} selection mu-like cut");
    shrinkage_cc1pi_mu->SetPoint(0, 0.1, 31.29);
    shrinkage_cc1pi_mu->SetPoint(1, 0.3, 31.5275);
    shrinkage_cc1pi_mu->SetPoint(2, 0.5, 31.6751);
    shrinkage_cc1pi_mu->SetPoint(3, 0.7, 31.5224);
    shrinkage_cc1pi_mu->SetPoint(4, 0.9, 31.5727);
    shrinkage_cc1pi_mu->SetLineColor( kBlue); shrinkage_cc1pi_mu->SetMarkerColor( kBlue); shrinkage_cc1pi_mu->SetFillColor( kWhite); 
    
    TGraph* shrinkage_cc1pi_pi = new TGraph();
    shrinkage_cc1pi_pi->SetTitle("#pi^{-} selection pi-like cut");
    shrinkage_cc1pi_pi->SetPoint(0, 0.1, 34.0015);
    shrinkage_cc1pi_pi->SetPoint(1, 0.3, 34.1212);
    shrinkage_cc1pi_pi->SetPoint(2, 0.5, 34.2785);
    shrinkage_cc1pi_pi->SetPoint(3, 0.7, 34.5959);
    shrinkage_cc1pi_pi->SetPoint(4, 0.9, 34.2874);
    shrinkage_cc1pi_pi->SetLineColor( kRed); shrinkage_cc1pi_pi->SetMarkerColor( kRed); shrinkage_cc1pi_pi->SetFillColor( kWhite); 
    
    TGraph* shrinkage_pg_mu = new TGraph();
    shrinkage_pg_mu->SetTitle("#mu^{+} selection mu-like cut");
    shrinkage_pg_mu->SetPoint(0, 0.1, 214.753);
    shrinkage_pg_mu->SetPoint(1, 0.3, 215.118);
    shrinkage_pg_mu->SetPoint(2, 0.5, 216.193);
    shrinkage_pg_mu->SetPoint(3, 0.7, 215.175);
    shrinkage_pg_mu->SetPoint(4, 0.9, 215.394);
    shrinkage_pg_mu->SetLineColor( kBlue); shrinkage_pg_mu->SetMarkerColor( kBlue); shrinkage_pg_mu->SetFillColor( kWhite);
    
    TGraph* shrinkage_pg_pi = new TGraph();
    shrinkage_pg_pi->SetTitle("#pi^{+} selection pi-like cut");
    shrinkage_pg_pi->SetPoint(0, 0.1, 156.525);
    shrinkage_pg_pi->SetPoint(1, 0.3, 151.953);
    shrinkage_pg_pi->SetPoint(2, 0.5, 153.455);
    shrinkage_pg_pi->SetPoint(3, 0.7, 150.447);
    shrinkage_pg_pi->SetPoint(4, 0.9, 150.671);
    shrinkage_pg_pi->SetLineColor( kRed); shrinkage_pg_pi->SetMarkerColor( kRed); shrinkage_pg_pi->SetFillColor( kWhite);
    
    TGraph* shrinkage_pg_p = new TGraph();
    shrinkage_pg_p->SetTitle("p selection p-like cut");
    shrinkage_pg_p->SetPoint(0, 0.1, 192.499);
    shrinkage_pg_p->SetPoint(1, 0.3, 200.318);
    shrinkage_pg_p->SetPoint(2, 0.5, 198.885);
    shrinkage_pg_p->SetPoint(3, 0.7, 202.08);
    shrinkage_pg_p->SetPoint(4, 0.9, 203.232);
    shrinkage_pg_p->SetLineColor( kGreen); shrinkage_pg_p->SetMarkerColor( kGreen); shrinkage_pg_p->SetFillColor( kWhite); 
    
    TGraph* shrinkage_pg_e = new TGraph();
    shrinkage_pg_e->SetTitle("e^{+} selection e-like cut");
    shrinkage_pg_e->SetPoint(0, 0.1, 217.285);
    shrinkage_pg_e->SetPoint(1, 0.3, 230.162);
    shrinkage_pg_e->SetPoint(2, 0.5, 217.9);
    shrinkage_pg_e->SetPoint(3, 0.7, 211.18);
    shrinkage_pg_e->SetPoint(4, 0.9, 200.639);
    shrinkage_pg_e->SetLineColor( kMagenta); shrinkage_pg_e->SetMarkerColor( kMagenta); shrinkage_pg_e->SetFillColor( kWhite); 
    
    TCanvas* canvas_shrinkage = new TCanvas("canvas_shrinkage","",200,10,1000,400);
    canvas_shrinkage->Divide(2,1,0.005,0.005);
    canvas_shrinkage->cd(1);
    
    shrinkage_cc1pi_mu->GetYaxis()->SetRangeUser(30.0, 36.0);
    shrinkage_cc1pi_mu->GetXaxis()->SetTitle("Shrinkage"); shrinkage_cc1pi_mu->GetYaxis()->SetTitle("Optimal selection significance");
    
    shrinkage_cc1pi_mu->Draw("AL*");
    shrinkage_cc1pi_pi->Draw("L* same");
    canvas_shrinkage->cd(1)->BuildLegend();
    
    canvas_shrinkage->cd(2);
    shrinkage_pg_mu->GetYaxis()->SetRangeUser(140.0, 240.0);
    shrinkage_pg_mu->GetXaxis()->SetTitle("Shrinkage"); shrinkage_pg_mu->GetYaxis()->SetTitle("Optimal selection significance");
    shrinkage_pg_mu->Draw("AL*");
    shrinkage_pg_pi->Draw("L* same");
    shrinkage_pg_p->Draw("L* same");
    shrinkage_pg_e->Draw("L* same");
    canvas_shrinkage->cd(2)->BuildLegend();
    
    // =============== Bagged ===============
    
    TGraph* bagged_cc1pi_mu = new TGraph();
    bagged_cc1pi_mu->SetTitle("#mu^{+} selection mu-like cut");
    bagged_cc1pi_mu->SetPoint(0, 0.1, 22.5832);
    bagged_cc1pi_mu->SetPoint(1, 0.3, 27.6244);
    bagged_cc1pi_mu->SetPoint(2, 0.5, 31.1143);
    bagged_cc1pi_mu->SetPoint(3, 0.7, 31.3501);
    bagged_cc1pi_mu->SetPoint(4, 0.9, 31.0307);
    bagged_cc1pi_mu->SetLineColor( kBlue); bagged_cc1pi_mu->SetMarkerColor( kBlue); bagged_cc1pi_mu->SetFillColor( kWhite); 
    
    TGraph* bagged_cc1pi_pi = new TGraph();
    bagged_cc1pi_pi->SetTitle("#pi^{-} selection pi-like cut");
    bagged_cc1pi_pi->SetPoint(0, 0.1, 25.9107);
    bagged_cc1pi_pi->SetPoint(1, 0.3, 28.8149);
    bagged_cc1pi_pi->SetPoint(2, 0.5, 34.402);
    bagged_cc1pi_pi->SetPoint(3, 0.7, 35.1219);
    bagged_cc1pi_pi->SetPoint(4, 0.9, 34.3025);
    bagged_cc1pi_pi->SetLineColor( kRed); bagged_cc1pi_pi->SetMarkerColor( kRed); bagged_cc1pi_pi->SetFillColor( kWhite); 
    
    TGraph* bagged_pg_mu = new TGraph();
    bagged_pg_mu->SetTitle("#mu^{+} selection mu-like cut");
    bagged_pg_mu->SetPoint(0, 0.1, 156.171);
    bagged_pg_mu->SetPoint(1, 0.3, 196.069);
    bagged_pg_mu->SetPoint(2, 0.5, 213.241);
    bagged_pg_mu->SetPoint(3, 0.7, 214.974);
    bagged_pg_mu->SetPoint(4, 0.9, 213.777);
    bagged_pg_mu->SetLineColor( kBlue); bagged_pg_mu->SetMarkerColor( kBlue); bagged_pg_mu->SetFillColor( kWhite);
    
    TGraph* bagged_pg_pi = new TGraph();
    bagged_pg_pi->SetTitle("#pi^{+} selection pi-like cut");
    bagged_pg_pi->SetPoint(0, 0.1, 119.081);
    bagged_pg_pi->SetPoint(1, 0.3, 114.072);
    bagged_pg_pi->SetPoint(2, 0.5, 149.798);
    bagged_pg_pi->SetPoint(3, 0.7, 150.126);
    bagged_pg_pi->SetPoint(4, 0.9, 150.175);
    bagged_pg_pi->SetLineColor( kRed); bagged_pg_pi->SetMarkerColor( kRed); bagged_pg_pi->SetFillColor( kWhite);
    
    TGraph* bagged_pg_p = new TGraph();
    bagged_pg_p->SetTitle("p selection p-like cut");
    bagged_pg_p->SetPoint(0, 0.1, 34.3667);
    bagged_pg_p->SetPoint(1, 0.3, 122.973);
    bagged_pg_p->SetPoint(2, 0.5, 202.662);
    bagged_pg_p->SetPoint(3, 0.7, 203.904);
    bagged_pg_p->SetPoint(4, 0.9, 202.83);
    bagged_pg_p->SetLineColor( kGreen); bagged_pg_p->SetMarkerColor( kGreen); bagged_pg_p->SetFillColor( kWhite); 
    
    TGraph* bagged_pg_e = new TGraph();
    bagged_pg_e->SetTitle("e^{+} selection e-like cut");
    bagged_pg_e->SetPoint(0, 0.1, 42.9093);
    bagged_pg_e->SetPoint(1, 0.3, 188.561);
    bagged_pg_e->SetPoint(2, 0.5, 188.965);
    bagged_pg_e->SetPoint(3, 0.7, 188.728);
    bagged_pg_e->SetPoint(4, 0.9, 197.86);
    bagged_pg_e->SetLineColor( kMagenta); bagged_pg_e->SetMarkerColor( kMagenta); bagged_pg_e->SetFillColor( kWhite); 
    
    TCanvas* canvas_bagged = new TCanvas("canvas_bagged","",200,10,1000,400);
    canvas_bagged->Divide(2,1,0.005,0.005);
    canvas_bagged->cd(1);
    
    bagged_cc1pi_mu->GetYaxis()->SetRangeUser(20.0, 36.0);
    bagged_cc1pi_mu->GetXaxis()->SetTitle("BaggedSampleFraction"); bagged_cc1pi_mu->GetYaxis()->SetTitle("Optimal selection significance");
    
    bagged_cc1pi_mu->Draw("AL*");
    bagged_cc1pi_pi->Draw("L* same");
    canvas_bagged->cd(1)->BuildLegend();
    
    canvas_bagged->cd(2);
    bagged_pg_mu->GetYaxis()->SetRangeUser(30.0, 240.0);
    bagged_pg_mu->GetXaxis()->SetTitle("BaggedSampleFraction"); bagged_pg_mu->GetYaxis()->SetTitle("Optimal selection significance");
    bagged_pg_mu->Draw("AL*");
    bagged_pg_pi->Draw("L* same");
    bagged_pg_p->Draw("L* same");
    bagged_pg_e->Draw("L* same");
    canvas_bagged->cd(2)->BuildLegend();
    
    // =============== Random Forests ===============
    
    TGraph* randomforests_cc1pi_mu = new TGraph();
    randomforests_cc1pi_mu->SetTitle("#mu^{+} selection mu-like cut");
    randomforests_cc1pi_mu->SetPoint(0, 4, 31.7349);
    randomforests_cc1pi_mu->SetPoint(1, 6, 31.4449);
    randomforests_cc1pi_mu->SetPoint(2, 8, 31.5028);
    randomforests_cc1pi_mu->SetPoint(3, 10, 31.3693);
    randomforests_cc1pi_mu->SetPoint(4, 12, 31.4114);
    randomforests_cc1pi_mu->SetLineColor( kBlue); randomforests_cc1pi_mu->SetMarkerColor( kBlue); randomforests_cc1pi_mu->SetFillColor( kWhite); 
    
    TGraph* randomforests_cc1pi_pi = new TGraph();
    randomforests_cc1pi_pi->SetTitle("#pi^{-} selection pi-like cut");
    randomforests_cc1pi_pi->SetPoint(0, 4, 35.5932);
    randomforests_cc1pi_pi->SetPoint(1, 6, 35.1679);
    randomforests_cc1pi_pi->SetPoint(2, 8, 34.8337);
    randomforests_cc1pi_pi->SetPoint(3, 0.7, 34.6818);
    randomforests_cc1pi_pi->SetPoint(4, 0.9, 35.2115);
    randomforests_cc1pi_pi->SetLineColor( kRed); randomforests_cc1pi_pi->SetMarkerColor( kRed); randomforests_cc1pi_pi->SetFillColor( kWhite); 
    
    TGraph* randomforests_pg_mu = new TGraph();
    randomforests_pg_mu->SetTitle("#mu^{+} selection mu-like cut");
    randomforests_pg_mu->SetPoint(0, 4, 216.438);
    randomforests_pg_mu->SetPoint(1, 6, 214.792);
    randomforests_pg_mu->SetPoint(2, 8, 215.376);
    randomforests_pg_mu->SetPoint(3, 10, 214.695);
    randomforests_pg_mu->SetPoint(4, 12, 214.212);
    randomforests_pg_mu->SetLineColor( kBlue); randomforests_pg_mu->SetMarkerColor( kBlue); randomforests_pg_mu->SetFillColor( kWhite);
    
    TGraph* randomforests_pg_pi = new TGraph();
    randomforests_pg_pi->SetTitle("#pi^{+} selection pi-like cut");
    randomforests_pg_pi->SetPoint(0, 4, 152.548);
    randomforests_pg_pi->SetPoint(1, 6, 153.389);
    randomforests_pg_pi->SetPoint(2, 8, 150.509);
    randomforests_pg_pi->SetPoint(3, 10, 151.431);
    randomforests_pg_pi->SetPoint(4, 12, 151.773);
    randomforests_pg_pi->SetLineColor( kRed); randomforests_pg_pi->SetMarkerColor( kRed); randomforests_pg_pi->SetFillColor( kWhite);
    
    TGraph* randomforests_pg_p = new TGraph();
    randomforests_pg_p->SetTitle("p selection p-like cut");
    randomforests_pg_p->SetPoint(0, 4, 200.419);
    randomforests_pg_p->SetPoint(1, 6, 202.775);
    randomforests_pg_p->SetPoint(2, 8, 204.349);
    randomforests_pg_p->SetPoint(3, 10, 200.328);
    randomforests_pg_p->SetPoint(4, 12, 200.547);
    randomforests_pg_p->SetLineColor( kGreen); randomforests_pg_p->SetMarkerColor( kGreen); randomforests_pg_p->SetFillColor( kWhite); 
    
    TGraph* randomforests_pg_e = new TGraph();
    randomforests_pg_e->SetTitle("e^{+} selection e-like cut");
    randomforests_pg_e->SetPoint(0, 4, 204.334);
    randomforests_pg_e->SetPoint(1, 6, 223.064);
    randomforests_pg_e->SetPoint(2, 8, 200.124);
    randomforests_pg_e->SetPoint(3, 10, 198.827);
    randomforests_pg_e->SetPoint(4, 12, 189.298);
    randomforests_pg_e->SetLineColor( kMagenta); randomforests_pg_e->SetMarkerColor( kMagenta); randomforests_pg_e->SetFillColor( kWhite); 
    
    TCanvas* canvas_randomforests = new TCanvas("canvas_randomforests","",200,10,1000,400);
    canvas_randomforests->Divide(2,1,0.005,0.005);
    canvas_randomforests->cd(1);
    
    randomforests_cc1pi_mu->GetYaxis()->SetRangeUser(20.0, 36.0);
    randomforests_cc1pi_mu->GetXaxis()->SetTitle("Random forests NVars"); randomforests_cc1pi_mu->GetYaxis()->SetTitle("Optimal selection significance");
    
    randomforests_cc1pi_mu->Draw("AL*");
    randomforests_cc1pi_pi->Draw("L* same");
    canvas_randomforests->cd(1)->BuildLegend();
    
    canvas_randomforests->cd(2);
    randomforests_pg_mu->GetYaxis()->SetRangeUser(30.0, 240.0);
    randomforests_pg_mu->GetXaxis()->SetTitle("Random forests NVars"); randomforests_pg_mu->GetYaxis()->SetTitle("Optimal selection significance");
    randomforests_pg_mu->Draw("AL*");
    randomforests_pg_pi->Draw("L* same");
    randomforests_pg_p->Draw("L* same");
    randomforests_pg_e->Draw("L* same");
    canvas_randomforests->cd(2)->BuildLegend();
    
}
