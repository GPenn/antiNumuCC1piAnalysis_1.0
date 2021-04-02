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
  
  TCanvas tpc1pos1neg_bothseg;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>4)&&(ntpcposQualityFV==1)&&(ntpcnegQualityFV==1)&&(selmu_necals>0)&&(HMNT_NEcalSegments>0)");
  TCanvas tpc1pos1neg_bothseg_sig;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>4)&&(topology==1)&&(ntpcposQualityFV==1)&&(ntpcnegQualityFV==1)&&(selmu_necals>0)&&(HMNT_NEcalSegments>0)");
  TCanvas tpc1pos1neg_bothseg_bkg;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>4)&&(topology!=1)&&(ntpcposQualityFV==1)&&(ntpcnegQualityFV==1)&&(selmu_necals>0)&&(HMNT_NEcalSegments>0)");
  
  TCanvas tpc1pos1neg_museg;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>4)&&(ntpcposQualityFV==1)&&(ntpcnegQualityFV==1)&&(selmu_necals>0)&&(HMNT_NEcalSegments==0)");
  TCanvas tpc1pos1neg_museg_sig;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>4)&&(topology==1)&&(ntpcposQualityFV==1)&&(ntpcnegQualityFV==1)&&(selmu_necals>0)&&(HMNT_NEcalSegments==0)");
  TCanvas tpc1pos1neg_museg_bkg;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>4)&&(topology!=1)&&(ntpcposQualityFV==1)&&(ntpcnegQualityFV==1)&&(selmu_necals>0)&&(HMNT_NEcalSegments==0)");
  
  TCanvas tpc1pos1neg_piseg;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>4)&&(ntpcposQualityFV==1)&&(ntpcnegQualityFV==1)&&(selmu_necals==0)&&(HMNT_NEcalSegments>0)");
  TCanvas tpc1pos1neg_piseg_sig;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>4)&&(topology==1)&&(ntpcposQualityFV==1)&&(ntpcnegQualityFV==1)&&(selmu_necals==0)&&(HMNT_NEcalSegments>0)");
  TCanvas tpc1pos1neg_piseg_bkg;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>4)&&(topology!=1)&&(ntpcposQualityFV==1)&&(ntpcnegQualityFV==1)&&(selmu_necals==0)&&(HMNT_NEcalSegments>0)");
  
  TCanvas tpc1pos1neg_noseg;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>4)&&(ntpcposQualityFV==1)&&(ntpcnegQualityFV==1)&&(selmu_necals==0)&&(HMNT_NEcalSegments==0)");
  TCanvas tpc1pos1neg_noseg_sig;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>4)&&(topology==1)&&(ntpcposQualityFV==1)&&(ntpcnegQualityFV==1)&&(selmu_necals==0)&&(HMNT_NEcalSegments==0)");
  TCanvas tpc1pos1neg_noseg_bkg;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>4)&&(topology!=1)&&(ntpcposQualityFV==1)&&(ntpcnegQualityFV==1)&&(selmu_necals==0)&&(HMNT_NEcalSegments==0)");
  
  /*TCanvas tpc1pos0neg;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>4)&&(ntpcposQualityFV==1)&&(ntpcnegQualityFV==0)&&(NME==1)");
  TCanvas tpc1pos0neg_sig;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>4)&&(topology==1)&&(ntpcposQualityFV==1)&&(ntpcnegQualityFV==0)&&(NME==1)");
  TCanvas tpc1pos0neg_bkg;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>4)&&(topology!=1)&&(ntpcposQualityFV==1)&&(ntpcnegQualityFV==0)&&(NME==1)");
  
  TCanvas tpc2pos1neg;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>4)&&(ntpcposQualityFV==2)&&(ntpcnegQualityFV==1)");
  TCanvas tpc2pos1neg_sig;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>4)&&(topology==1)&&(ntpcposQualityFV==2)&&(ntpcnegQualityFV==1)");
  TCanvas tpc2pos1neg_bkg;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>4)&&(topology!=1)&&(ntpcposQualityFV==2)&&(ntpcnegQualityFV==1)");
  
  TCanvas tpc2pos0neg;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>4)&&(ntpcposQualityFV==2)&&(ntpcnegQualityFV==0)&&(NME==1)");
  TCanvas tpc2pos0neg_sig;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>4)&&(topology==1)&&(ntpcposQualityFV==2)&&(ntpcnegQualityFV==0)&&(NME==1)");
  TCanvas tpc2pos0neg_bkg;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>4)&&(topology!=1)&&(ntpcposQualityFV==2)&&(ntpcnegQualityFV==0)&&(NME==1)");*/

}
