{
  DrawingTools draw("output/output_p6T_allruns.root");
  DataSample mc("output/output_p6T_allruns.root");
  
  // Bothseg
  
  TCanvas bothseg_muon_EbyL;
  draw.SetTitleX("Antimuon candidate ECal energy/length");
  draw.Draw(default,"selmu_ecal_EMenergy[0]/selmu_ecal_length[0]",50,0,4,"topology","accum_level[][1]>7&&selmu_necals>0&&HMNT_NEcalSegments>0");
  draw.DrawCutLineVertical(1.0,true,"l");
  draw.DrawCutLineVertical(1.1,true,"l");
  
  TCanvas bothseg_muon_mippion;
  draw.SetTitleX("Antimuon candidate ECal MipPion");
  draw.Draw(default,"selmu_ecal_mippion",50,-30,70,"topology","accum_level[][1]>7&&selmu_necals>0&&HMNT_NEcalSegments>0");
  draw.DrawCutLineVertical(0.0,true,"l");
  draw.DrawCutLineVertical(8.3,true,"l");
  
  TCanvas bothseg_pion_EbyL;
  draw.SetTitleX("Pi- candidate ECal energy/length");
  draw.Draw(default,"HMNT_ecal_EMenergy/HMNT_ecal_length",50,0,4,"topology","accum_level[][1]>7&&selmu_necals>0&&HMNT_NEcalSegments>0");
  draw.DrawCutLineVertical(1.0,true,"r");
  draw.DrawCutLineVertical(0.1,true,"r");
  
  TCanvas bothseg_pion_mippion;
  draw.SetTitleX("Pi- candidate ECal MipPion");
  draw.Draw(default,"HMNT_ecal_mippion",50,-30,70,"topology","accum_level[][1]>7&&selmu_necals>0&&HMNT_NEcalSegments>0");
  draw.DrawCutLineVertical(0.0,true,"r");
  draw.DrawCutLineVertical(-6.0,true,"r");
  
  // Museg
  
  TCanvas museg_muon_EbyL;
  draw.SetTitleX("Antimuon candidate ECal energy/length");
  draw.Draw(default,"selmu_ecal_EMenergy[0]/selmu_ecal_length[0]",50,0,4,"topology","accum_level[][1]>7&&selmu_necals>0&&HMNT_NEcalSegments<1");
  draw.DrawCutLineVertical(1.0,true,"l");
  draw.DrawCutLineVertical(1.6,true,"l");
  
  TCanvas museg_muon_mippion;
  draw.SetTitleX("Antimuon candidate ECal MipPion");
  draw.Draw(default,"selmu_ecal_mippion",50,-30,70,"topology","accum_level[][1]>7&&selmu_necals>0&&HMNT_NEcalSegments<1");
  draw.DrawCutLineVertical(0.0,true,"l");
  draw.DrawCutLineVertical(17.0,true,"l");
  
  // Piseg
  
  TCanvas piseg_pion_EbyL;
  draw.SetTitleX("Pi- candidate ECal energy/length");
  draw.Draw(default,"HMNT_ecal_EMenergy/HMNT_ecal_length",50,0,4,"topology","accum_level[][1]>7&&selmu_necals<1&&HMNT_NEcalSegments>0");
  draw.DrawCutLineVertical(1.0,true,"r");
  draw.DrawCutLineVertical(0.28,true,"r");
  
  TCanvas piseg_pion_mippion;
  draw.SetTitleX("Pi- candidate ECal MipPion");
  draw.Draw(default,"HMNT_ecal_mippion",50,-30,70,"topology","accum_level[][1]>7&&selmu_necals<1&&HMNT_NEcalSegments>0");
  draw.DrawCutLineVertical(0.0,true,"r");
  draw.DrawCutLineVertical(0.91,true,"r");
}
