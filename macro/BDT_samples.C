{
  DrawingTools draw("output/output_p6T_allruns_ecalbestseg.root");
  DataSample mc("output/output_p6T_allruns_ecalbestseg.root");
  
  draw.SetTitleX("Event topology");
  
  TCanvas inclusive;
  draw.Draw(default,"topology",10,0,10,"topology","accum_level[][1]>4");
  TCanvas inclusive_sig;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>4)&&(topology==1)");
  TCanvas inclusive_bkg;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>4)&&(topology!=1)");
  
  TCanvas tpc1pos1neg;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>4)&&(ntpcposQualityFV==1)&&(ntpcnegQualityFV==1)");
  TCanvas tpc1pos1neg_sig;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>4)&&(topology==1)&&(ntpcposQualityFV==1)&&(ntpcnegQualityFV==1)");
  TCanvas tpc1pos1neg_bkg;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>4)&&(topology!=1)&&(ntpcposQualityFV==1)&&(ntpcnegQualityFV==1)");

}
