{
  DrawingTools draw("output/output_p6T_run5_ecalavgvartest.root");
  DataSample mc("output/output_p6T_run5_ecalavgvartest.root");

  draw.DumpPOT(mc);
  
  TCanvas ntpcposQualityFV_5;
  draw.Draw(default,"ntpcposQualityFV",4,0,4,"topology","accum_level[][1]>5");
  TCanvas ntpcnegQualityFV_5;
  draw.Draw(default,"ntpcnegQualityFV",4,0,4,"topology","accum_level[][1]>5");
  
  TCanvas ntpcposQualityFV_6;
  draw.Draw(default,"ntpcposQualityFV",4,0,4,"topology","accum_level[][1]>6");
  TCanvas ntpcnegQualityFV_6;
  draw.Draw(default,"ntpcnegQualityFV",4,0,4,"topology","accum_level[][1]>6");
  
  TCanvas ntpcposQualityFV_7;
  draw.Draw(default,"ntpcposQualityFV",4,0,4,"topology","accum_level[][1]>7");
  TCanvas ntpcnegQualityFV_7;
  draw.Draw(default,"ntpcnegQualityFV",4,0,4,"topology","accum_level[][1]>7");
  
}
