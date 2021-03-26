{
  DrawingTools draw("output/output_p6T_run5_ecalbestsegtest.root");
  DataSample mc("output/output_p6T_run5_ecalbestsegtest.root");

  draw.DumpPOT(mc);
  
  TCanvas selmu_ecal_bestseg_EMenergy;
  draw.Draw(default,"selmu_ecal_bestseg_EMenergy",50,0,10000,"topology","accum_level[][1]>4&&selmu_necals>0");
  
  TCanvas selmu_ecal_bestseg_EbyP;
  draw.Draw(default,"selmu_ecal_bestseg_EMenergy/selmu_mom[0]",50,0,250,"topology","accum_level[][1]>4&&selmu_necals>0");
  
  TCanvas selmu_ecal_bestseg_EMenergy_vs_EbyP;
  draw.Draw(default,"(selmu_ecal_bestseg_EMenergy/selmu_mom[0]):selmu_ecal_bestseg_EMenergy",50,0,10000,50,0,250,"accum_level[][1]>4&&selmu_necals>0", "colz");
  
  TCanvas HMNT_ecal_bestseg_EMenergy;
  draw.Draw(default,"HMNT_ecal_bestseg_EMenergy",50,0,10000,"topology","accum_level[][1]>4&&HMNT_NEcalSegments>0");
}
