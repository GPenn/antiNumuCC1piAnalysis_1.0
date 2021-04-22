{
  DrawingTools draw("output/output_p6T_allruns_modified_withoptimised.root");
  DataSample mc("output/output_p6T_allruns_modified_withoptimised.root");
  
  draw.SetTitleX("Event topology");
  
  TCanvas effpur;
  draw.DrawEffPurVSCut(mc, 1, "topology==1");
  
  TCanvas events_preecal;
  draw.Draw(default,"topology",10,0,10,"topology","accum_level[][1]>7");
  TCanvas sig_preecal;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>7)&&(topology==1)");
  TCanvas bkg_preecal;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>7)&&(topology!=1)");
  
  TCanvas events_postecal;
  draw.Draw(default,"topology",10,0,10,"topology","accum_level[][1]>9");
  TCanvas sig_postecal;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>9)&&(topology==1)");
  TCanvas bkg_postecal;
  draw.Draw(default,"topology",10,0,10,"topology","(accum_level[][1]>9)&&(topology!=1)");
  
  TCanvas true_sig;
  draw.Draw(truth,"topology",10,0,10,"topology","(topology==1)");
  
}
