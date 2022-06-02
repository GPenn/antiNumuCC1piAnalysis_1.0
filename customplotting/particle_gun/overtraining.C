{
    TCanvas* canvas_overtrain_check = new TCanvas("canvas_overtrain_check","canvas_overtrain_check",200,10,1000,600);
    
    TFile *trainingfile = new TFile("output/trainingsample.root");
    trainingfile.ls();
    
    TGraph* training_antimu = (TGraph*)trainingfile.Get("graph_bdt_efficiency_recomom_antimu");
    TGraph* training_piplus = (TGraph*)trainingfile.Get("graph_bdt_efficiency_recomom_piplus");
    TGraph* training_proton = (TGraph*)trainingfile.Get("graph_bdt_efficiency_recomom_proton");
    TGraph* training_positron = (TGraph*)trainingfile.Get("graph_bdt_efficiency_recomom_positron");
    
    training_antimu->Draw("AL");
    training_piplus->Draw("L same");
    training_proton->Draw("L same");
    training_positron->Draw("L same");
    
    TFile *testingfile = new TFile("output/testingsample.root");
    testingfile.ls();
    
    TGraph* testing_antimu = (TGraph*)testingfile.Get("graph_bdt_efficiency_recomom_antimu");
    TGraph* testing_piplus = (TGraph*)testingfile.Get("graph_bdt_efficiency_recomom_piplus");
    TGraph* testing_proton = (TGraph*)testingfile.Get("graph_bdt_efficiency_recomom_proton");
    TGraph* testing_positron = (TGraph*)testingfile.Get("graph_bdt_efficiency_recomom_positron");
    
    testing_antimu->SetLineStyle(kDashed);
    testing_piplus->SetLineStyle(kDashed);
    testing_proton->SetLineStyle(kDashed);
    testing_positron->SetLineStyle(kDashed);
    
    testing_antimu->Draw("L same");
    testing_piplus->Draw("L same");
    testing_proton->Draw("L same");
    testing_positron->Draw("L same");
}
