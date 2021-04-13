
{
  DrawingTools draw("output/output_p6T_allruns_ecalbestseg.root");
  DataSample mc("output/output_p6T_allruns_ecalbestseg.root");

  draw.DumpPOT(mc);
  
  draw.SetTitleX("Muon candidate reco momentum");
  draw.SetTitleY("Events passing preselection");
  TCanvas selmu_mom;
  draw.Draw(default,"selmu_mom[0]",50,0,15000,"topology","accum_level[][1]>4");
  TCanvas selmu_mom_low;
  draw.Draw(default,"selmu_mom[0]",50,0,500,"topology","accum_level[][1]>4");
  TCanvas selmu_mom_low_sig;
  draw.Draw(default,"selmu_mom[0]",50,0,500,"topology","accum_level[][1]>4&&topology==1");
  
  draw.SetTitleX("Pion candidate reco momentum");
  TCanvas HMNT_mom;
  draw.Draw(default,"HMNT_mom[0]",50,0,15000,"topology","(accum_level[][1]>4)&&(ntpcnegQualityFV>0)");
  TCanvas HMNT_mom_low;
  draw.Draw(default,"HMNT_mom[0]",50,0,500,"topology","(accum_level[][1]>4)&&(ntpcnegQualityFV>0)");
  TCanvas HMNT_mom_low_sig;
  draw.Draw(default,"HMNT_mom[0]",50,0,500,"topology","(accum_level[][1]>4)&&(ntpcnegQualityFV>0)&&(topology==1)");
  
  draw.SetTitleX("Muon candidate true momentum");
  draw.SetTitleY("Preselection CC1pi efficiency");
  TCanvas preselection_eff_selmu_truemom;
  draw.DrawRatio(default,"selmu_truemom",50,0,5000,"(accum_level[][1]>4)&&(ntpcposQualityFV==1)&&(ntpcnegQualityFV==1)&&(topology==1)","topology==1");
  TCanvas preselection_eff_selmu_truemom_low;
  draw.DrawRatio(default,"selmu_truemom",25,0,500,"(accum_level[][1]>4)&&(ntpcposQualityFV==1)&&(ntpcnegQualityFV==1)&&(topology==1)","topology==1");
  
  draw.SetTitleY("Good quality event w/ +ve TPC track efficiency");
  draw.SetTitleX("True lepton true momentum");
  TCanvas muon_eff_truelepton_mom;
  draw.DrawRatio(default,"truelepton_mom",50,0,5000,"(accum_level[][1]>4)&&(ntpcposQualityFV==1)&&(particle==-13)","particle==-13");
  TCanvas muon_eff_truelepton_mom_low;
  draw.DrawRatio(default,"truelepton_mom",25,0,500,"(accum_level[][1]>4)&&(ntpcposQualityFV==1)&&(particle==-13)","particle==-13");
  
  draw.SetTitleY("Good quality event w/ -ve TPC track efficiency");
  draw.SetTitleX("True pion true momentum");
  TCanvas pion_eff_truepi_mom;
  draw.DrawRatio(default,"truepi_mom",50,0,5000,"(accum_level[][1]>4)&&(ntpcnegQualityFV==1)&&(HMNT_truepdg==-211)","HMNT_truepdg==-211");
  TCanvas pion_eff_truepi_mom_low;
  draw.DrawRatio(default,"truepi_mom",25,0,500,"(accum_level[][1]>4)&&(ntpcnegQualityFV==1)&&(HMNT_truepdg==-211)","HMNT_truepdg==-211");
}
