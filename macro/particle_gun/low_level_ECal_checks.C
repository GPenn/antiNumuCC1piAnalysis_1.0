{
  DrawingTools draw("output/particle_gun/particlegun_allpositive.root");
  DataSample mc("output/particle_gun/particlegun_allpositive.root");
  
  draw.SetTitleX("ECal QRMS");
  TCanvas selmu_ecal_qrms;
  draw.Draw(default,"selmu_ecal_qrms",50,-1.0,4.0,"particle","(accum_level[][0]>4)&&(selmu_necals==1)");
  
  draw.SetTitleX("ECal axis max ratio");
  TCanvas selmu_ecal_amr;
  draw.Draw(default,"selmu_ecal_amr",20,-10,400,"particle","(accum_level[][0]>4)&&(selmu_necals==1)");
  
  draw.SetTitleX("selmu_ecal_angle");
  TCanvas selmu_ecal_angle;
  draw.Draw(default,"selmu_ecal_angle",20,0,100,"particle","(accum_level[][0]>4)&&(selmu_necals==1)");
  
  draw.SetTitleX("selmu_ecal_asymmetry");
  TCanvas selmu_ecal_asymmetry;
  draw.Draw(default,"selmu_ecal_asymmetry",20,0,1,"particle","(accum_level[][0]>4)&&(selmu_necals==1)");
  
  draw.SetTitleX("ECal circularity");
  TCanvas selmu_ecal_circularity;
  draw.Draw(default,"selmu_ecal_circularity",20,0,1,"particle","(accum_level[][0]>4)&&(selmu_necals==1)");
  
  draw.SetTitleX("ECal FrontBackRatio");
  TCanvas selmu_ecal_fbr;
  draw.Draw(default,"selmu_ecal_fbr",20,0,50,"particle","(accum_level[][0]>4)&&(selmu_necals==1)");
  
  draw.SetTitleX("ECal charge max ratio");
  TCanvas selmu_ecal_maxratio;
  draw.Draw(default,"selmu_ecal_maxratio",20,-50,400,"particle","(accum_level[][0]>4)&&(selmu_necals==1)");
  
  draw.SetTitleX("selmu_ecal_meanpos");
  TCanvas selmu_ecal_meanpos;
  draw.Draw(default,"selmu_ecal_meanpos",20,0,800,"particle","(accum_level[][0]>4)&&(selmu_necals==1)");
 
  draw.SetTitleX("ECal shower opening angle (rad)");
  TCanvas selmu_ecal_showerangle;
  draw.Draw(default,"selmu_ecal_showerangle",20,0,1,"particle","(accum_level[][0]>4)&&(selmu_necals==1)");
  
  draw.SetTitleX("ECal shower width");
  TCanvas selmu_ecal_showerwidth;
  draw.Draw(default,"selmu_ecal_showerwidth",20,0,1,"particle","(accum_level[][0]>4)&&(selmu_necals==1)");
  
  draw.SetTitleX("selmu_ecal_tcr");
  TCanvas selmu_ecal_tcr;
  draw.Draw(default,"selmu_ecal_tcr",20,0,3,"particle","(accum_level[][0]>4)&&(selmu_necals==1)");
  
  draw.SetTitleX("ECal truncated max ratio");
  TCanvas selmu_ecal_tmr;
  draw.Draw(default,"selmu_ecal_tmr",20,0,1,"particle","(accum_level[][0]>4)&&(selmu_necals==1)");
}
