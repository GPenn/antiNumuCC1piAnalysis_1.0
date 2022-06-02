{
    TFile *trainingfile = new TFile(“trainingsample.root”);

    trainingfile.ls();
    
    TCanvas* canvas_overtrain_check = new TCanvas("canvas_overtrain_check","canvas_overtrain_check",200,10,1000,600);

    TGraph * test = new TGraph();
    test = (TGraph*)trainingfile.Get("graph_bdt_efficiency_recomom_antimu");
    test->Draw();
}
