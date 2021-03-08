{
  DrawingTools draw("output/output_p6T_run5_ecalavgvartest.root");
  DataSample mc("output/output_p6T_run5_ecalavgvartest.root");

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
  
  /*TCanvas selmu_ecal_det_correlation;
  draw.SetTitleX("selmu_ecal_det[1]");
  draw.SetTitleY("selmu_ecal_det[0]");
  draw.Draw(default,"selmu_ecal_det[1]:selmu_ecal_det[0]",9,0,9,9,0,9,"all","accum_level[][1]>5&&selmu_necals>1","colz");
  
  TCanvas selmu_ecal_EMenergy_correlation;
  draw.SetTitleX("selmu_ecal_EMenergy[1]");
  draw.SetTitleY("selmu_ecal_EMenergy[0]");
  draw.Draw(default,"selmu_ecal_EMenergy[0]:selmu_ecal_EMenergy[1]",50,0,400,50,0,400,"all","accum_level[][1]>5&&selmu_necals>1","colz");
  
  TCanvas selmu_ecal_endpos_correlationX;
  draw.SetTitleX("selmu_ecal_showerendpos[1][0]");
  draw.SetTitleY("selmu_ecal_showerendpos[0][0]");
  draw.Draw(default,"selmu_ecal_showerendpos[0][0]:selmu_ecal_showerendpos[1][0]",50,-2000,2000,50,-2000,2000,"all","accum_level[][1]>5&&selmu_necals>1","colz");
  
  TCanvas selmu_ecal_endpos_correlationY;
  draw.SetTitleX("selmu_ecal_showerendpos[1][1]");
  draw.SetTitleY("selmu_ecal_showerendpos[0][1]");
  draw.Draw(default,"selmu_ecal_showerendpos[0][1]:selmu_ecal_showerendpos[1][1]",50,500,2000,50,500,2000,"all","accum_level[][1]>5&&selmu_necals>1","colz");
  
  TCanvas selmu_ecal_endpos_correlationZ;
  draw.SetTitleX("selmu_ecal_showerendpos[1][2]");
  draw.SetTitleY("selmu_ecal_showerendpos[0][2]");
  draw.Draw(default,"selmu_ecal_showerendpos[0][2]:selmu_ecal_showerendpos[1][2]",50,500,3500,50,500,3500,"all","accum_level[][1]>5&&selmu_necals>1","colz");
  
  TCanvas selmu_ecal_endpos_correlationT;
  draw.SetTitleX("selmu_ecal_showerendpos[1][3]");
  draw.SetTitleY("selmu_ecal_showerendpos[0][3]");
  draw.Draw(default,"selmu_ecal_showerendpos[0][3]:selmu_ecal_showerendpos[1][3]",50,2000,8000,50,2000,8000,"all","accum_level[][1]>5&&selmu_necals>1","colz");
  
  TCanvas selmu_ecal_endpos_correlationXZ;
  draw.SetTitleX("selmu_ecal_showerendpos[0][0]");
  draw.SetTitleY("selmu_ecal_showerendpos[0][2]");
  draw.Draw(default,"selmu_ecal_showerendpos[0][2]:selmu_ecal_showerendpos[0][0]",50,-2000,2000,50,500,3500,"all","accum_level[][1]>5&&selmu_necals>1","colz");*/
  
  /*TCanvas selmu_ecal_mippion_correlation;
  draw.SetTitleX("selmu_ecal_mippion[1]");
  draw.SetTitleY("selmu_ecal_mippion[0]");
  draw.Draw(default,"selmu_ecal_mippion[0]:selmu_ecal_mippion[1]",50,-20,30,50,-20,30,"all","accum_level[][1]>4&&selmu_necals>1","colz");
  TCanvas selmu_ecal_mippion_correlation_sig;
  draw.Draw(default,"selmu_ecal_mippion[0]:selmu_ecal_mippion[1]",50,-20,30,50,-20,30,"all","accum_level[][1]>4&&selmu_necals>1&&particle==-13","colz");
  TCanvas selmu_ecal_mippion_correlation_bkg;
  draw.Draw(default,"selmu_ecal_mippion[0]:selmu_ecal_mippion[1]",50,-20,30,50,-20,30,"all","accum_level[][1]>4&&selmu_necals>1&&particle!=-13","colz");
  
  TCanvas selmu_ecal_EbyL_correlation;
  draw.SetTitleX("selmu_ecal_EMenergy[1]/selmu_ecal_length[1]");
  draw.SetTitleY("selmu_ecal_EMenergy[0]/selmu_ecal_length[0]");
  draw.Draw(default,"selmu_ecal_EMenergy[0]/selmu_ecal_length[0]:selmu_ecal_EMenergy[1]/selmu_ecal_length[1]",50,0,4,50,0,4,"all","accum_level[][1]>4&&selmu_necals>1","colz");
  TCanvas selmu_ecal_EbyL_correlation_sig;
  draw.Draw(default,"selmu_ecal_EMenergy[0]/selmu_ecal_length[0]:selmu_ecal_EMenergy[1]/selmu_ecal_length[1]",50,0,4,50,0,4,"all","accum_level[][1]>4&&selmu_necals>1&&particle==-13","colz");
  TCanvas selmu_ecal_EbyL_correlation_bkg;
  draw.Draw(default,"selmu_ecal_EMenergy[0]/selmu_ecal_length[0]:selmu_ecal_EMenergy[1]/selmu_ecal_length[1]",50,0,4,50,0,4,"all","accum_level[][1]>4&&selmu_necals>1&&particle!=-13","colz");
  */
  TCanvas selmu_ecal_avg_mippion;
  draw.Draw(default,"selmu_ecal_avg_mippion",50,-20,80,"topology","accum_level[][1]>4&&selmu_necals>0");
  TCanvas selmu_ecal_avg_mippion_1ecal;
  draw.Draw(default,"selmu_ecal_avg_mippion",50,-20,80,"topology","accum_level[][1]>4&&selmu_necals==1");
  TCanvas selmu_ecal_avg_mippion_multiplecals;
  draw.Draw(default,"selmu_ecal_avg_mippion",50,-20,80,"topology","accum_level[][1]>4&&selmu_necals>1");
  TCanvas selmu_ecal_avg_EbyL;
  draw.Draw(default,"selmu_ecal_avg_EbyL",50,0,4,"topology","accum_level[][1]>4&&selmu_necals>0");
  TCanvas selmu_ecal_avg_EbyL_1ecal;
  draw.Draw(default,"selmu_ecal_avg_EbyL",50,0,4,"topology","accum_level[][1]>4&&selmu_necals==1");
  TCanvas selmu_ecal_avg_EbyL_multiplecals;
  draw.Draw(default,"selmu_ecal_avg_EbyL",50,0,4,"topology","accum_level[][1]>4&&selmu_necals>1");
  
  TCanvas HMNT_ecal_avg_mippion;
  draw.Draw(default,"HMNT_ecal_avg_mippion",50,-20,80,"topology","accum_level[][1]>4&&HMNT_NEcalSegments>0");
  TCanvas HMNT_ecal_avg_mippion_1ecal;
  draw.Draw(default,"HMNT_ecal_avg_mippion",50,-20,80,"topology","accum_level[][1]>4&&HMNT_NEcalSegments==1");
  TCanvas HMNT_ecal_avg_mippion_multiplecals;
  draw.Draw(default,"HMNT_ecal_avg_mippion",50,-20,80,"topology","accum_level[][1]>4&&HMNT_NEcalSegments>1");
  TCanvas HMNT_ecal_avg_EbyL;
  draw.Draw(default,"HMNT_ecal_avg_EbyL",50,0,4,"topology","accum_level[][1]>4&&HMNT_NEcalSegments>0");
  TCanvas HMNT_ecal_avg_EbyL_1ecal;
  draw.Draw(default,"HMNT_ecal_avg_EbyL",50,0,4,"topology","accum_level[][1]>4&&HMNT_NEcalSegments==1");
  TCanvas HMNT_ecal_avg_EbyL_multiplecals;
  draw.Draw(default,"HMNT_ecal_avg_EbyL",50,0,4,"topology","accum_level[][1]>4&&HMNT_NEcalSegments>1");
  
}
