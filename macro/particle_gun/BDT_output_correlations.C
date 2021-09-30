{
  DrawingTools draw_amu("output/particle_gun/particlegun_antimu.root");
  DataSample mc_amu("output/particle_gun/particlegun_antimu.root");
  
  draw_amu.SetTitleX("Antimu BDT output mu-like");
  draw_amu.SetTitleY("Antimu BDT output pi-like");
  TCanvas amu_bdtmupi_accum4;
  draw_amu.Draw(default,"selmu_bdt_pid_pi:selmu_bdt_pid_mu",100,0.0,1.0,100,0.0,1.0, "all", "(accum_level[][0]>4)&&(particle==-13)&&(selmu_mom > 150.0)&&(selmu_mom < 1500.0)", "colz");
  //amu_momcorr_accum4->SaveAs("img/particlegun/reco_vs_true_mom_antimu_pg.png");
  
  DrawingTools draw_pi("output/particle_gun/particlegun_piplus.root");
  DataSample mc_pi("output/particle_gun/particlegun_piplus.root");
  
  draw_pi.SetTitleX("Pi+ BDT output mu-like");
  draw_pi.SetTitleY("Pi+ BDT output pi-like");
  TCanvas pi_momcorr_accum4;
  draw_pi.Draw(default,"selmu_bdt_pid_pi:selmu_bdt_pid_mu",100,0.0,1.0,100,0.0,1.0, "all", "(accum_level[][0]>4)&&(particle==211)&&(selmu_mom > 150.0)&&(selmu_mom < 1500.0)", "colz");
  //pi_momcorr_accum4->SaveAs("img/particlegun/reco_vs_true_mom_piplus_pg.png");
  
  DrawingTools draw_p("output/particle_gun/particlegun_proton.root");
  DataSample mc_p("output/particle_gun/particlegun_proton.root");
  
  draw_p.SetTitleX("Proton BDT output mu-like");
  draw_p.SetTitleY("Proton BDT output pi-like");
  TCanvas p_momcorr_accum4;
  draw_p.Draw(default,"selmu_bdt_pid_pi:selmu_bdt_pid_mu",100,0.0,1.0,100,0.0,1.0, "all", "(accum_level[][0]>4)&&(particle==2212)&&(selmu_mom > 150.0)&&(selmu_mom < 1500.0)", "colz");
  //p_momcorr_accum4->SaveAs("img/particlegun/reco_vs_true_mom_proton_pg.png");
  
  DrawingTools draw_pos("output/particle_gun/particlegun_positron.root");
  DataSample mc_pos("output/particle_gun/particlegun_positron.root");
  
  draw_pos.SetTitleX("Positron BDT output mu-like");
  draw_pos.SetTitleY("Positron BDT output pi-like");
  TCanvas pos_momcorr_accum4;
  draw_pos.Draw(default,"selmu_bdt_pid_pi:selmu_bdt_pid_mu",100,0.0,1.0,100,0.0,1.0, "all", "(accum_level[][0]>4)&&(particle==-11)&&(selmu_mom > 150.0)&&(selmu_mom < 1500.0)", "colz");
  //pos_momcorr_accum4->SaveAs("img/particlegun/reco_vs_true_mom_positron_pg.png");
}
