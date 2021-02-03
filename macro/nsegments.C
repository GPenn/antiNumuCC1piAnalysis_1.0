{
  DrawingTools draw("output/output_p6T_allruns.root");
  DataSample mc("output/output_p6T_allruns.root");

  draw.DumpPOT(mc);
  
  /*TCanvas selmu_necals;
  draw.Draw(default,"selmu_necals",5,0,5,"topology","accum_level[][1]>5&&selmu_necals>0");
  
  TCanvas selmu_necals_multiple;
  draw.Draw(default,"selmu_necals",5,0,5,"topology","accum_level[][1]>5&&selmu_necals>1");
  
  TCanvas selpi_necals;
  draw.Draw(default,"HMNT_NEcalSegments",5,0,5,"topology","accum_level[][1]>5&&HMNT_NEcalSegments>0");
  
  TCanvas selpi_necals_multiple;
  draw.Draw(default,"HMNT_NEcalSegments",5,0,5,"topology","accum_level[][1]>5&&HMNT_NEcalSegments>1");
  */
  
  TCanvas selmu_ecal_det_correlation;
  draw.SetTitleX("selmu_ecal_det[1]");
  draw.SetTitleY("selmu_ecal_det[0]");
  draw.Draw(default,"selmu_ecal_det[1]:selmu_ecal_det[0]",9,0,9,9,0,9,"all","accum_level[][1]>5&&selmu_necals>1","colz");
  
  TCanvas selmu_ecal_EMenergy_correlation;
  draw.SetTitleX("selmu_ecal_EMenergy[1]");
  draw.SetTitleY("selmu_ecal_EMenergy[0]");
  draw.Draw(default,"selmu_ecal_EMenergy[0]:selmu_ecal_EMenergy[1]",50,0,400,50,0,400,"all","accum_level[][1]>5&&selmu_necals>1","colz");
  
  TCanvas selmu_ecal_endpos_correlation0;
  draw.SetTitleX("selmu_ecal_showerendpos[1][0]");
  draw.SetTitleY("selmu_ecal_showerendpos[0][0]");
  draw.Draw(default,"selmu_ecal_showerendpos[0][0]:selmu_ecal_showerendpos[1][0]",50,-2000,2000,50,-2000,2000,"all","accum_level[][1]>5&&selmu_necals>1","colz");
  
  TCanvas selmu_ecal_endpos_correlation1;
  draw.SetTitleX("selmu_ecal_showerendpos[1][1]");
  draw.SetTitleY("selmu_ecal_showerendpos[0][1]");
  draw.Draw(default,"selmu_ecal_showerendpos[0][1]:selmu_ecal_showerendpos[1][1]",50,500,2000,50,500,2000,"all","accum_level[][1]>5&&selmu_necals>1","colz");
  
  TCanvas selmu_ecal_endpos_correlation2;
  draw.SetTitleX("selmu_ecal_showerendpos[1][2]");
  draw.SetTitleY("selmu_ecal_showerendpos[0][2]");
  draw.Draw(default,"selmu_ecal_showerendpos[0][2]:selmu_ecal_showerendpos[1][2]",50,500,3500,50,500,3500,"all","accum_level[][1]>5&&selmu_necals>1","colz");
  
  TCanvas selmu_ecal_endpos_correlation3;
  draw.SetTitleX("selmu_ecal_showerendpos[1][3]");
  draw.SetTitleY("selmu_ecal_showerendpos[0][3]");
  draw.Draw(default,"selmu_ecal_showerendpos[0][3]:selmu_ecal_showerendpos[1][3]",50,2000,8000,50,2000,8000,"all","accum_level[][1]>5&&selmu_necals>1","colz");
  
}
