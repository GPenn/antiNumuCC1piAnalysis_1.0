{
  DrawingTools draw_amu("output/particle_gun/particlegun_antimu.root");
  DataSample mc_amu("output/particle_gun/particlegun_antimu.root");
  
  //draw_amu.SetTitleX("Antimu true momentum");
  //draw_amu.SetTitleY("Antimu reco momentum");
  //TCanvas amu_momcorr_accum4;
  //draw_amu.Draw(default,"selmu_mom:selmu_truemom",100,0,2500,120,0,3000, "all", "(accum_level[][0]>4)&&(particle==-13)", "colz");
  //amu_momcorr_accum4->SaveAs("img/particlegun/reco_vs_true_mom_antimu_pg.png");
  
  draw_amu.SetTitleX("Mu+ reco momentum");
  TCanvas amu_recomom_preselection;
  draw_amu.Draw(default,"selmu_mom[0]", 50,200,1500, "particle", "(accum_level[][0]>4)&&(particle==-13)");
  
  DrawingTools draw_pi("output/particle_gun/particlegun_piplus.root");
  DataSample mc_pi("output/particle_gun/particlegun_piplus.root");
  
  //draw_pi.SetTitleX("Pi+ true momentum");
  //draw_pi.SetTitleY("Pi+ reco momentum");
  //TCanvas pi_momcorr_accum4;
  //draw_pi.Draw(default,"selmu_mom:selmu_truemom",100,0,2500,120,0,3000, "all", "(accum_level[][0]>4)&&(particle==211)", "colz");
  //pi_momcorr_accum4->SaveAs("img/particlegun/reco_vs_true_mom_piplus_pg.png");
  
  DrawingTools draw_p("output/particle_gun/particlegun_proton.root");
  DataSample mc_p("output/particle_gun/particlegun_proton.root");
  
  //draw_p.SetTitleX("Proton true momentum");
  //draw_p.SetTitleY("Proton reco momentum");
  //TCanvas p_momcorr_accum4;
  //draw_p.Draw(default,"selmu_mom:selmu_truemom",100,0,2500,120,0,3000, "all", "(accum_level[][0]>4)&&(particle==2212)", "colz");
  //p_momcorr_accum4->SaveAs("img/particlegun/reco_vs_true_mom_proton_pg.png");
  
  DrawingTools draw_pos("output/particle_gun/particlegun_positron.root");
  DataSample mc_pos("output/particle_gun/particlegun_positron.root");
  
  //draw_pos.SetTitleX("Positron true momentum");
  //draw_pos.SetTitleY("Positron reco momentum");
  //TCanvas pos_momcorr_accum4;
  //draw_pos.Draw(default,"selmu_mom:selmu_truemom",100,0,2500,120,0,3000, "all", "(accum_level[][0]>4)&&(particle==-11)", "colz");
  //pos_momcorr_accum4->SaveAs("img/particlegun/reco_vs_true_mom_positron_pg.png");
}
