{
  DrawingTools draw_amu("output/particle_gun/particlegun_allpositive_weightingcomparison.root");
  DataSample mc_amu("output/particle_gun/particlegun_allpositive_weightingcomparison.root");
  
  // ---------------- mu-like ----------------
  
  draw_amu.SetTitleX("True mu+ reconstructed momentum (MeV/c)");
  draw_amu.SetTitleY("BDT mu-like disagreement (weighted - unweighted)");
  TCanvas mulikedisagreement_vs_recomom_mu;
  draw_amu.Draw(default,"(selmu_bdt_pid_mu-selmu_bdt_pid_unweighted_mu):selmu_mom[0]",40,200,1500,40,-1.0,1.0, "all", "(accum_level[][0]>5)&&(particle==-13)", "colz");
  //mulikedisagreement_vs_recomom->SaveAs("img/particlegun/blah.png");
  
  draw_amu.SetTitleX("True pi+ reconstructed momentum (MeV/c)");
  draw_amu.SetTitleY("BDT mu-like disagreement (weighted - unweighted)");
  TCanvas mulikedisagreement_vs_recomom_pi;
  draw_amu.Draw(default,"(selmu_bdt_pid_mu-selmu_bdt_pid_unweighted_mu):selmu_mom[0]",40,200,1500,40,-1.0,1.0, "all", "(accum_level[][0]>5)&&(particle==211)", "colz");
  
  draw_amu.SetTitleX("True p reconstructed momentum (MeV/c)");
  draw_amu.SetTitleY("BDT mu-like disagreement (weighted - unweighted)");
  TCanvas mulikedisagreement_vs_recomom_p;
  draw_amu.Draw(default,"(selmu_bdt_pid_mu-selmu_bdt_pid_unweighted_mu):selmu_mom[0]",40,200,1500,40,-1.0,1.0, "all", "(accum_level[][0]>5)&&(particle==2212)", "colz");
  
  draw_amu.SetTitleX("True e+ reconstructed momentum (MeV/c)");
  draw_amu.SetTitleY("BDT mu-like disagreement (weighted - unweighted)");
  TCanvas mulikedisagreement_vs_recomom_e;
  draw_amu.Draw(default,"(selmu_bdt_pid_mu-selmu_bdt_pid_unweighted_mu):selmu_mom[0]",40,200,1500,40,-1.0,1.0, "all", "(accum_level[][0]>5)&&(particle==-11)", "colz");
  
  // ---------------- pi-like ----------------
  
  draw_amu.SetTitleX("True mu+ reconstructed momentum (MeV/c)");
  draw_amu.SetTitleY("BDT pi-like disagreement (weighted - unweighted)");
  TCanvas pilikedisagreement_vs_recomom_mu;
  draw_amu.Draw(default,"(selmu_bdt_pid_pi-selmu_bdt_pid_unweighted_pi):selmu_mom[0]",40,200,1500,40,-1.0,1.0, "all", "(accum_level[][0]>5)&&(particle==-13)", "colz");
  //pilikedisagreement_vs_recomom->SaveAs("img/particlegun/blah.png");
  
  draw_amu.SetTitleX("True pi+ reconstructed momentum (MeV/c)");
  draw_amu.SetTitleY("BDT pi-like disagreement (weighted - unweighted)");
  TCanvas pilikedisagreement_vs_recomom_pi;
  draw_amu.Draw(default,"(selmu_bdt_pid_pi-selmu_bdt_pid_unweighted_pi):selmu_mom[0]",40,200,1500,40,-1.0,1.0, "all", "(accum_level[][0]>5)&&(particle==211)", "colz");
  //pilikedisagreement_vs_recomom->SaveAs("img/particlegun/blah.png");
  
  draw_amu.SetTitleX("True p reconstructed momentum (MeV/c)");
  draw_amu.SetTitleY("BDT pi-like disagreement (weighted - unweighted)");
  TCanvas pilikedisagreement_vs_recomom_p;
  draw_amu.Draw(default,"(selmu_bdt_pid_pi-selmu_bdt_pid_unweighted_pi):selmu_mom[0]",40,200,1500,40,-1.0,1.0, "all", "(accum_level[][0]>5)&&(particle==2212)", "colz");
  //pilikedisagreement_vs_recomom->SaveAs("img/particlegun/blah.png");
  
  draw_amu.SetTitleX("True e+ reconstructed momentum (MeV/c)");
  draw_amu.SetTitleY("BDT pi-like disagreement (weighted - unweighted)");
  TCanvas pilikedisagreement_vs_recomom_e;
  draw_amu.Draw(default,"(selmu_bdt_pid_pi-selmu_bdt_pid_unweighted_pi):selmu_mom[0]",40,200,1500,40,-1.0,1.0, "all", "(accum_level[][0]>5)&&(particle==-11)", "colz");
  //pilikedisagreement_vs_recomom->SaveAs("img/particlegun/blah.png");
  
  // ---------------- p-like ----------------
  
  draw_amu.SetTitleX("True mu+ reconstructed momentum (MeV/c)");
  draw_amu.SetTitleY("BDT p-like disagreement (weighted - unweighted)");
  TCanvas plikedisagreement_vs_recomom_mu;
  draw_amu.Draw(default,"(selmu_bdt_pid_p-selmu_bdt_pid_unweighted_p):selmu_mom[0]",40,200,1500,40,-1.0,1.0, "all", "(accum_level[][0]>5)&&(particle==-13)", "colz");
  
  draw_amu.SetTitleX("True pi+ reconstructed momentum (MeV/c)");
  draw_amu.SetTitleY("BDT p-like disagreement (weighted - unweighted)");
  TCanvas plikedisagreement_vs_recomom_pi;
  draw_amu.Draw(default,"(selmu_bdt_pid_p-selmu_bdt_pid_unweighted_p):selmu_mom[0]",40,200,1500,40,-1.0,1.0, "all", "(accum_level[][0]>5)&&(particle==211)", "colz");
  
  draw_amu.SetTitleX("True p reconstructed momentum (MeV/c)");
  draw_amu.SetTitleY("BDT p-like disagreement (weighted - unweighted)");
  TCanvas plikedisagreement_vs_recomom_p;
  draw_amu.Draw(default,"(selmu_bdt_pid_p-selmu_bdt_pid_unweighted_p):selmu_mom[0]",40,200,1500,40,-1.0,1.0, "all", "(accum_level[][0]>5)&&(particle==2212)", "colz");
  //plikedisagreement_vs_recomom->SaveAs("img/particlegun/blah.png");
  
  draw_amu.SetTitleX("True e+ reconstructed momentum (MeV/c)");
  draw_amu.SetTitleY("BDT p-like disagreement (weighted - unweighted)");
  TCanvas plikedisagreement_vs_recomom_e;
  draw_amu.Draw(default,"(selmu_bdt_pid_p-selmu_bdt_pid_unweighted_p):selmu_mom[0]",40,200,1500,40,-1.0,1.0, "all", "(accum_level[][0]>5)&&(particle==-11)", "colz");
  
  // ---------------- e-like ----------------
  
  draw_amu.SetTitleX("True mu+ reconstructed momentum (MeV/c)");
  draw_amu.SetTitleY("BDT e-like disagreement (weighted - unweighted)");
  TCanvas elikedisagreement_vs_recomom_mu;
  draw_amu.Draw(default,"(selmu_bdt_pid_e-selmu_bdt_pid_unweighted_e):selmu_mom[0]",40,200,1500,40,-1.0,1.0, "all", "(accum_level[][0]>5)&&(particle==-13)", "colz");
  
  draw_amu.SetTitleX("True pi+ reconstructed momentum (MeV/c)");
  draw_amu.SetTitleY("BDT e-like disagreement (weighted - unweighted)");
  TCanvas elikedisagreement_vs_recomom_pi;
  draw_amu.Draw(default,"(selmu_bdt_pid_e-selmu_bdt_pid_unweighted_e):selmu_mom[0]",40,200,1500,40,-1.0,1.0, "all", "(accum_level[][0]>5)&&(particle==211)", "colz");
  
  draw_amu.SetTitleX("True p reconstructed momentum (MeV/c)");
  draw_amu.SetTitleY("BDT e-like disagreement (weighted - unweighted)");
  TCanvas elikedisagreement_vs_recomom_p;
  draw_amu.Draw(default,"(selmu_bdt_pid_e-selmu_bdt_pid_unweighted_e):selmu_mom[0]",40,200,1500,40,-1.0,1.0, "all", "(accum_level[][0]>5)&&(particle==2212)", "colz");
  
  draw_amu.SetTitleX("True e+ reconstructed momentum (MeV/c)");
  draw_amu.SetTitleY("BDT e-like disagreement (weighted - unweighted)");
  TCanvas elikedisagreement_vs_recomom_e;
  draw_amu.Draw(default,"(selmu_bdt_pid_e-selmu_bdt_pid_unweighted_e):selmu_mom[0]",40,200,1500,40,-1.0,1.0, "all", "(accum_level[][0]>5)&&(particle==-11)", "colz");
  //elikedisagreement_vs_recomom->SaveAs("img/particlegun/blah.png");
  
}
