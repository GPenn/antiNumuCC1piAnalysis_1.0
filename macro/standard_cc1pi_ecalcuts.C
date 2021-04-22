{
  DrawingTools draw("output/output_p6T_allruns_standard_withoptimised.root");
  DataSample mc("output/output_p6T_allruns_standard_withoptimised.root");
  
  draw.SetTitleX("Event topology");
  
  TCanvas effpur;
  draw.DrawEffPurVSCut(mc, 1, "topology==1");
  
  TCanvas events;
  draw.Draw(default,"topology",10,0,10,"topology","accum_level[][1]>10");
  TCanvas sig;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>10)&&(topology==1)");
  TCanvas bkg;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>10)&&(topology!=1)");
  
  TCanvas true_sig;
  draw.Draw(truth,"topology",10,0,10,"topology","(topology==1)");
  
}
