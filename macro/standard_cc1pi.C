{
  DrawingTools draw("/hepstore/gpenn/nd280gitlab/12.31/antiNumuCCMultiPiAnalysis_2.11/output/output_prod6T_allruns.root");
  DataSample mc("/hepstore/gpenn/nd280gitlab/12.31/antiNumuCCMultiPiAnalysis_2.11/output/output_prod6T_allruns.root");
  
  draw.SetTitleX("Event topology");
  
  TCanvas effpur;
  draw.DrawEffPurVSCut(mc,"topology==1");
  
  TCanvas events;
  draw.Draw(default,"topology",10,0,10,"topology","accum_level[][1]>8");
  TCanvas sig;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>8)&&(topology==1)");
  TCanvas bkg;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>8)&&(topology!=1)");
  
  TCanvas true_sig;
  draw.Draw(truth,"topology",10,0,10,"topology","(topology==1)");
  
}
