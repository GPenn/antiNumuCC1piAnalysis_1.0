{
  DrawingTools draw("output/output_p6T_allruns.root");
  DataSample mc("output/output_p6T_allruns.root");

  draw.DumpPOT(mc);
  
  /*TCanvas muontrack_sig;
  draw.Draw(default,"particle==-13",2,0,2,"particle","accum_level[][1]>8&&topology==1");
  
  TCanvas muontrack_bkg;
  draw.Draw(default,"particle==-13",2,0,2,"particle","accum_level[][1]>8&&topology!=1");
  
  TCanvas piontrack_sig;
  draw.Draw(default,"HMNT_truepdg==-211",2,0,2,"topology","accum_level[][1]>8&&topology==1");
  
  TCanvas piontrack_bkg;
  draw.Draw(default,"HMNT_truepdg==-211",2,0,2,"topology","accum_level[][1]>8&&topology!=1");*/
  
  TCanvas bothtracks_sig;
  draw.Draw(default,"particle==-13&&HMNT_truepdg==-211",2,0,2,"topology","accum_level[][1]>8&&topology==1&&HMNT_mom>0");
  
  TCanvas bothtracks_bkg;
  draw.Draw(default,"particle==-13&&HMNT_truepdg==-211",2,0,2,"topology","accum_level[][1]>8&&topology!=1&&HMNT_mom>0");
}
