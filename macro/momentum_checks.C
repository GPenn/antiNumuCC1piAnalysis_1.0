
{
  DrawingTools draw("output/output_p6T_allruns_ecalbestseg.root");
  DataSample mc("output/output_p6T_allruns_ecalbestseg.root");

  draw.DumpPOT(mc);
  
  TCanvas selmu_mom;
  draw.Draw(default,"selmu_mom[0]",50,0,15000,"topology","accum_level[][1]>4");
  TCanvas selmu_mom_low;
  draw.Draw(default,"selmu_mom[0]",50,0,500,"topology","accum_level[][1]>4");
  TCanvas selmu_mom_low_sig;
  draw.Draw(default,"selmu_mom[0]",50,0,500,"topology","accum_level[][1]>4&&topology==1");
 
  TCanvas HMNT_mom;
  draw.Draw(default,"HMNT_mom[0]",50,0,15000,"topology","(accum_level[][1]>4)&&(ntpcnegQualityFV>0)");
  TCanvas HMNT_mom_low;
  draw.Draw(default,"HMNT_mom[0]",50,0,500,"topology","(accum_level[][1]>4)&&(ntpcnegQualityFV>0)");
  
  TCanvas preselection_eff_selmu_mom;
  draw.DrawRatio(default,"selmu_truemom",50,0,5000,"(accum_level[][1]>4)&&(ntpcposQualityFV==1)&&(ntpcnegQualityFV==1)&&(topology==1)","topology==1");
  TCanvas preselection_eff_selmu_mom_low;
  draw.DrawRatio(default,"selmu_truemom",50,0,500,"(accum_level[][1]>4)&&(ntpcposQualityFV==1)&&(ntpcnegQualityFV==1)&&(topology==1)","topology==1");
}
