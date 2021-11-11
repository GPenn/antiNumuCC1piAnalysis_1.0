{
  DrawingTools draw("output/particle_gun/particlegun_allpositive_bdttest.root");
  DataSample mc("output/particle_gun/particlegun_allpositive_bdttest.root");
  
 /* TCanvas effpur_mu;
  draw.DrawEffPurVSCut(mc, 0, "particle_pg==-13");
  
  TCanvas effpur_pi;
  draw.DrawEffPurVSCut(mc, 1, "particle_pg==211");
  
  TCanvas effpur_p;
  draw.DrawEffPurVSCut(mc, 2, "particle_pg==2212");
  
  TCanvas effpur_e;
  draw.DrawEffPurVSCut(mc, 3, "particle_pg==-11");*/
  
  TCanvas pur_vs_recomom_mu;
  draw.SetTitleX("Reco momentum");
  draw.SetTitleY("Mu+ selection purity");
  draw.DrawEff(default, "selmu_mom",50,200,1500,"particle_pg==-13","accum_level[][0]>6");
  
  TCanvas pur_vs_recomom_pi;
  draw.SetTitleX("Reco momentum");
  draw.SetTitleY("Pi+ selection purity");
  draw.DrawEff(default, "selmu_mom",50,200,1500,"particle_pg==211","accum_level[][1]>6");
  
  TCanvas pur_vs_recomom_p;
  draw.SetTitleX("Reco momentum");
  draw.SetTitleY("Proton selection purity");
  draw.DrawEff(default, "selmu_mom",50,200,1500,"particle_pg==2212","accum_level[][2]>6");
  
  TCanvas pur_vs_recomom_e;
  draw.SetTitleX("Reco momentum");
  draw.SetTitleY("Positron selection purity");
  draw.DrawEff(default, "selmu_mom",50,200,1500,"particle_pg==-11","accum_level[][3]>6");
  
  TCanvas eff_vs_recomom_mu;
  draw.SetTitleX("Reco momentum");
  draw.SetTitleY("Mu+ PID efficiency");
  draw.DrawEff(truth, "pg_trueparticle_mom",50,150,2000,"accum_level[][0]>6","(particle_pg==-13)&&(accum_level[][0]>5)");
  
  TCanvas eff_vs_recomom_pi;
  draw.SetTitleX("Reco momentum");
  draw.SetTitleY("Pi+ PID efficiency");
  draw.DrawEff(truth, "pg_trueparticle_mom",50,150,2000,"accum_level[][1]>6","(particle_pg==211)&&(accum_level[][1]>5)");
  
  TCanvas eff_vs_recomom_p;
  draw.SetTitleX("Reco momentum");
  draw.SetTitleY("Proton PID efficiency");
  draw.DrawEff(truth, "pg_trueparticle_mom",50,150,2000,"accum_level[][2]>6","(particle_pg==2212)&&(accum_level[][2]>5)");
  
  TCanvas eff_vs_recomom_e;
  draw.SetTitleX("Reco momentum");
  draw.SetTitleY("Positron PID efficiency");
  draw.DrawEff(truth, "pg_trueparticle_mom",50,150,2000,"accum_level[][3]>6","(particle_pg==-11)&&(accum_level[][3]>5)");

}
