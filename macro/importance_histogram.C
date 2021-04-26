{
  TH1F h("h","Importance",6,0.,6.0e-02);
  
  h.SetTitle(
       ";"
       "Importance (arb. units);"
       "Input variables");
  h.SetFillColor(kYellow);

  
  h.Fill(5.706e-02);
  h.Fill(4.882e-02);
  h.Fill(4.657e-02);
  h.Fill(4.579e-02);
  h.Fill(4.576e-02);
  h.Fill(4.513e-02);
  h.Fill(4.394e-02);
  h.Fill(4.272e-02);
  h.Fill(3.762e-02);
  h.Fill(3.733e-02);
  h.Fill(3.683e-02);
  h.Fill(3.672e-02);
  h.Fill(3.612e-02);
  h.Fill(3.581e-02);
  h.Fill(3.577e-02);
  h.Fill(3.438e-02);
  h.Fill(3.276e-02);
  h.Fill(3.265e-02);
  h.Fill(3.263e-02);
  h.Fill(3.238e-02);
  h.Fill(3.109e-02);
  h.Fill(3.100e-02);
  h.Fill(3.073e-02);
  h.Fill(2.985e-02);
  h.Fill(2.731e-02);
  h.Fill(2.647e-02);
  h.Fill(2.076e-02);
  h.Fill(5.978e-03);
  h.Fill(0.0);
  h.Fill(0.0);
  
  TCanvas c1;
  
  h.Draw();
}
