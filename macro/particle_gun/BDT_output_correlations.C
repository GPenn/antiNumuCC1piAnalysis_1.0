{
  DrawingTools draw_amu("output/particle_gun/particlegun_antimu.root");
  DataSample mc_amu("output/particle_gun/particlegun_antimu.root");
  
  //draw_amu.SetTitleX("Antimu BDT output mu-like");
  //draw_amu.SetTitleY("Antimu BDT output pi-like");
  //TCanvas amu_bdtmupi_accum4;
  //draw_amu.Draw(default,"selmu_bdt_pid_pi:selmu_bdt_pid_mu",20,0.0,1.0,20,0.0,1.0, "all", "(accum_level[][0]>4)&&(particle==-13)&&(selmu_mom > 150.0)&&(selmu_mom < 1500.0)", "colz");
  //amu_momcorr_accum4->SaveAs("img/particlegun/reco_vs_true_mom_antimu_pg.png");
  
  draw_amu.SetTitleX("Antimu reco momentum (MeV)");
  draw_amu.SetTitleY("Antimu BDT output mu-like");
  TCanvas amu_bdtmu_vs_recomom_accum4;
  draw_amu.Draw(default,"selmu_bdt_pid_mu:selmu_mom", 40,150.0,1500.0, 40,0.7,1.0, "all", "(accum_level[][0]>4)&&(particle==-13)&&(selmu_mom > 150.0)&&(selmu_mom < 1500.0)", "colz");
  
  //draw_amu.SetTitleX("Antimu true momentum (MeV)");
  //draw_amu.SetTitleY("Antimu BDT output mu-like");
  //TCanvas amu_bdtmu_vs_truemom_accum4;
  //draw_amu.Draw(default,"selmu_bdt_pid_mu:selmu_truemom", 40,150.0,1500.0, 40,0.0,1.0, "all", "(accum_level[][0]>4)&&(particle==-13)&&(selmu_mom > 150.0)&&(selmu_mom < 1500.0)", "colz");
  
  
  DrawingTools draw_pi("output/particle_gun/particlegun_piplus.root");
  DataSample mc_pi("output/particle_gun/particlegun_piplus.root");
  
  //draw_pi.SetTitleX("Pi+ BDT output mu-like");
  //draw_pi.SetTitleY("Pi+ BDT output pi-like");
  //TCanvas pi_momcorr_accum4;
  //draw_pi.Draw(default,"selmu_bdt_pid_pi:selmu_bdt_pid_mu",20,0.0,1.0,20,0.0,1.0, "all", "(accum_level[][0]>4)&&(particle==211)&&(selmu_mom > 150.0)&&(selmu_mom < 1500.0)", "colz");
  //pi_momcorr_accum4->SaveAs("img/particlegun/reco_vs_true_mom_piplus_pg.png");
  
  draw_pi.SetTitleX("Pi+ reco momentum (MeV)");
  draw_pi.SetTitleY("Pi+ BDT output mu-like");
  TCanvas pi_bdtmu_vs_recomom_accum4;
  draw_pi.Draw(default,"selmu_bdt_pid_mu:selmu_mom", 40,150.0,1500.0, 40,0.0,1.0, "all", "(accum_level[][0]>4)&&(particle==211)&&(selmu_mom > 150.0)&&(selmu_mom < 1500.0)", "colz");
  
  draw_pi.SetTitleX("Pi+ reco momentum (MeV)");
  draw_pi.SetTitleY("Pi+ BDT output pi-like");
  TCanvas pi_bdtpi_vs_recomom_accum4;
  draw_pi.Draw(default,"selmu_bdt_pid_pi:selmu_mom", 40,150.0,1500.0, 40,0.0,1.0, "all", "(accum_level[][0]>4)&&(particle==211)&&(selmu_mom > 150.0)&&(selmu_mom < 1500.0)", "colz");
  
  draw_pi.SetTitleX("Pi+ reco momentum (MeV)");
  draw_pi.SetTitleY("Pi+ BDT output proton-like");
  TCanvas pi_bdtp_vs_recomom_accum4;
  draw_pi.Draw(default,"selmu_bdt_pid_p:selmu_mom", 40,150.0,1500.0, 40,0.0,1.0, "all", "(accum_level[][0]>4)&&(particle==211)&&(selmu_mom > 150.0)&&(selmu_mom < 1500.0)", "colz");
  
  //draw_pi.SetTitleX("Pi+ true momentum (MeV)");
  //draw_pi.SetTitleY("Pi+ BDT output mu-like");
  //TCanvas pi_bdtmu_vs_truemom_accum4;
  //draw_pi.Draw(default,"selmu_bdt_pid_mu:selmu_truemom", 40,150.0,1500.0, 40,0.0,1.0, "all", "(accum_level[][0]>4)&&(particle==211)&&(selmu_mom > 150.0)&&(selmu_mom < 1500.0)", "colz");
  
  
  
  DrawingTools draw_p("output/particle_gun/particlegun_proton.root");
  DataSample mc_p("output/particle_gun/particlegun_proton.root");
  
  //draw_p.SetTitleX("Proton BDT output mu-like");
  //draw_p.SetTitleY("Proton BDT output pi-like");
  //TCanvas p_momcorr_accum4;
  //draw_p.Draw(default,"selmu_bdt_pid_pi:selmu_bdt_pid_mu",20,0.0,1.0,20,0.0,1.0, "all", "(accum_level[][0]>4)&&(particle==2212)&&(selmu_mom > 150.0)&&(selmu_mom < 1500.0)", "colz");
  //p_momcorr_accum4->SaveAs("img/particlegun/reco_vs_true_mom_proton_pg.png");
  
  DrawingTools draw_pos("output/particle_gun/particlegun_positron.root");
  DataSample mc_pos("output/particle_gun/particlegun_positron.root");
  
  //draw_pos.SetTitleX("Positron BDT output mu-like");
  //draw_pos.SetTitleY("Positron BDT output pi-like");
  //TCanvas pos_momcorr_accum4;
  //draw_pos.Draw(default,"selmu_bdt_pid_pi:selmu_bdt_pid_mu",20,0.0,1.0,20,0.0,1.0, "all", "(accum_level[][0]>4)&&(particle==-11)&&(selmu_mom > 150.0)&&(selmu_mom < 1500.0)", "colz");
  //pos_momcorr_accum4->SaveAs("img/particlegun/reco_vs_true_mom_positron_pg.png");
  
  draw_pos.SetTitleX("Positron reco momentum (MeV)");
  draw_pos.SetTitleY("Positron BDT output e-like");
  TCanvas pos_bdte_vs_recomom_accum4;
  draw_pos.Draw(default,"selmu_bdt_pid_e:selmu_mom", 40,150.0,1500.0, 40,0.0,1.0, "all", "(accum_level[][0]>4)&&(particle==-11)&&(selmu_mom > 150.0)&&(selmu_mom < 1500.0)", "colz");
}
