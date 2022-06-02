{
    TFile *trainingfile = new TFile("output/trainingsample.root");

    trainingfile.ls();
    
    TCanvas* canvas_overtrain_check = new TCanvas("canvas_overtrain_check","canvas_overtrain_check",200,10,1000,600);

    TGraph* training_antimu = (TGraph*)trainingfile.Get("graph_bdt_efficiency_recomom_antimu");
    TGraph* training_piplus = (TGraph*)trainingfile.Get("graph_bdt_efficiency_recomom_piplus");
    TGraph* training_proton = (TGraph*)trainingfile.Get("graph_bdt_efficiency_recomom_proton");
    TGraph* training_positron = (TGraph*)trainingfile.Get("graph_bdt_efficiency_recomom_positron");
    
    training_antimu->Draw("AL");
    training_piplus->Draw("L same");
    training_proton->Draw("L same");
    training_positron->Draw("L same");
}
