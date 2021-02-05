{
  DrawingTools draw("output/output_p6T_allruns.root");
  DataSample mc("output/output_p6T_allruns.root");
  
  TCanvas bothseg_muon_EbyL;
  draw.SetTitleX("Antimuon candidate ECal energy/length");
  draw.Draw(default,"selmu_ecal_EMenergy[0]/selmu_ecal_length[0]",50,0,4,"topology","accum_level[][1]>8&&selmu_necals>0&&HMNT_NEcalSegments>0");
  draw.DrawCutLineVertical(1.0,true,"l");
  draw.DrawCutLineVertical(1.1,true,"l");
  
  TCanvas bothseg_muon_mippion;
  draw.SetTitleX("Antimuon candidate ECal MipPion");
  draw.Draw(default,"selmu_ecal_mippion",50,-50,50,"topology","accum_level[][1]>8&&selmu_necals>0&&HMNT_NEcalSegments>0");
  draw.DrawCutLineVertical(0.0,true,"l");
  draw.DrawCutLineVertical(8.3,true,"l");
}
