{
  DrawingTools draw("output/output_p6T_allruns.root");
  DataSample mc("output/output_p6T_allruns.root");
  
  draw.SetTitleX("Antimuon candidate ECal energy/length");
  
  draw.Draw(default,"selmu_ecal_EMenergy[0]/selmu_ecal_length[0]",50,0,4,"topology","accum_level[][1]>8&&selmu_necals>0&&HMNT_NEcalSegments>0");
  
  
}
