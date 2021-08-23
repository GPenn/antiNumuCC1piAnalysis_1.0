{
  DrawingTools draw_amu("output/particle_gun/particlegun_antimu.root");
  DataSample mc_amu("output/particle_gun/particlegun_antimu.root");
  
  DrawingTools draw_pip("output/particle_gun/particlegun_piplus.root");
  DataSample mc_pip("output/particle_gun/particlegun_piplus.root");
  
  DrawingTools draw_pro("output/particle_gun/particlegun_proton.root");
  DataSample mc_pro("output/particle_gun/particlegun_proton.root");
  
  DrawingTools draw_pos("output/particle_gun/particlegun_positron.root");
  DataSample mc_pos("output/particle_gun/particlegun_positron.root");
  
  //draw.SetTitleX("HMT parent");
  //TCanvas selmu_mom_accum4_parent;
  //draw.Draw(default,"parent",40,-20,20,"particle","(accum_level[][0]>4)");
  /*
  draw.SetTitleX("HMT reco momentum");
  TCanvas selmu_mom_accum4_originals;
  draw.Draw(default,"selmu_mom",30,0,3000,"particle","(accum_level[][0]>4)&&(parent==0)");
  draw.DrawCutLineVertical(2000,true,"l");
  //selmu_mom_accum4->SaveAs("img/particlegun/kinematic_checks_selmu_mom_accum4_pg.png");
  
  TCanvas selmu_mom_accum4_migrated;
  draw.Draw(default,"selmu_mom",30,0,3000,"particle","(accum_level[][0]>4)&&(parent!=0)");
  draw.DrawCutLineVertical(2000,true,"l");
  //selmu_mom_accum4->SaveAs("img/particlegun/kinematic_checks_selmu_mom_accum4_pg.png");

  TCanvas selmu_mom_accum4_lowmom_originals;
  draw.Draw(default,"selmu_mom",20,0,500,"particle","(accum_level[][0]>4)&&(parent==0)");
  draw.DrawCutLineVertical(150,true,"r");
  //selmu_mom_accum4_lowmom->SaveAs("img/particlegun/kinematic_checks_selmu_mom_accum4_lowmom_pg.png");
  
  TCanvas selmu_mom_accum4_lowmom_migrated;
  draw.Draw(default,"selmu_mom",20,0,500,"particle","(accum_level[][0]>4)&&(parent!=0)");
  draw.DrawCutLineVertical(150,true,"r");
  //selmu_mom_accum4_lowmom->SaveAs("img/particlegun/kinematic_checks_selmu_mom_accum4_lowmom_pg.png");
  
  draw.SetTitleX("HMT true momentum");
  TCanvas selmu_truemom_accum4_originals;
  draw.Draw(default,"selmu_truemom",30,0,3000,"particle","(accum_level[][0]>4)&&(parent==0)");
  draw.DrawCutLineVertical(2000,true,"l");
  //selmu_truemom_accum4->SaveAs("img/particlegun/kinematic_checks_selmu_truemom_accum4_pg.png");
  
  TCanvas selmu_truemom_accum4_migrated;
  draw.Draw(default,"selmu_truemom",30,0,3000,"particle","(accum_level[][0]>4)&&(parent!=0)");
  draw.DrawCutLineVertical(2000,true,"l");
  //selmu_truemom_accum4->SaveAs("img/particlegun/kinematic_checks_selmu_truemom_accum4_pg.png");
  
  TCanvas selmu_truemom_accum4_lowmom_originals;
  draw.Draw(default,"selmu_truemom",20,0,500,"particle","(accum_level[][0]>4)&&(parent==0)");
  draw.DrawCutLineVertical(150,true,"r");
  //selmu_truemom_accum4_lowmom->SaveAs("img/particlegun/kinematic_checks_selmu_truemom_accum4_lowmom_pg.png");
  
  TCanvas selmu_truemom_accum4_lowmom_migrated;
  draw.Draw(default,"selmu_truemom",20,0,500,"particle","(accum_level[][0]>4)&&(parent!=0)");
  draw.DrawCutLineVertical(150,true,"r");
  //selmu_truemom_accum4_lowmom->SaveAs("img/particlegun/kinematic_checks_selmu_truemom_accum4_lowmom_pg.png");
  
  draw.SetTitleX("HMT reco angle (deg)");
  TCanvas selmu_theta_accum4_originals;
  draw.Draw(default,"(TMath::ACos(selmu_costheta))*360/6.283",36,0,90,"particle","(accum_level[][0]>4)&&(parent==0)");
  draw.DrawCutLineVertical(65,true,"l");
  //selmu_theta_accum4->SaveAs("img/particlegun/kinematic_checks_selmu_theta_accum4_pg.png");
  
  TCanvas selmu_theta_accum4_migrated;
  draw.Draw(default,"(TMath::ACos(selmu_costheta))*360/6.283",36,0,90,"particle","(accum_level[][0]>4)&&(parent!=0)");
  draw.DrawCutLineVertical(65,true,"l");
  //selmu_theta_accum4->SaveAs("img/particlegun/kinematic_checks_selmu_theta_accum4_pg.png");
  
  */
  
  // --------- Particle count checks --------------
  
  TCanvas antimu_all;
  draw_amu.Draw(default,"selmu_truemom",50,0,5000,"particle","(accum_level[][0]>4)");
  TCanvas antimu_true;
  draw_amu.Draw(default,"selmu_truemom",50,0,5000,"particle","(accum_level[][0]>4)&&(particle==-13)");
  /*TCanvas antimu_originals;
  draw_amu.Draw(default,"selmu_truemom",50,0,5000,"particle","(accum_level[][0]>4)&&(parent==0)&&(particle==-13)");
  TCanvas antimu_migrated;
  draw_amu.Draw(default,"selmu_truemom",50,0,5000,"particle","(accum_level[][0]>4)&&(parent!=0)&&(particle==-13)");*/
  
  TCanvas piplus_all;
  draw_pip.Draw(default,"selmu_truemom",50,0,5000,"particle","(accum_level[][0]>4)");
  TCanvas piplus_true;
  draw_pip.Draw(default,"selmu_truemom",50,0,5000,"particle","(accum_level[][0]>4)&&(particle==211)");
  /*TCanvas piplus_originals;
  draw_pip.Draw(default,"selmu_truemom",50,0,5000,"particle","(accum_level[][0]>4)&&(parent==0)&&(particle==211)");
  TCanvas piplus_migrated;
  draw_pip.Draw(default,"selmu_truemom",50,0,5000,"particle","(accum_level[][0]>4)&&(parent!=0)&&(particle==211)");*/
  
  TCanvas proton_all;
  draw_pro.Draw(default,"selmu_truemom",50,0,5000,"particle","(accum_level[][0]>4)");
  TCanvas proton_true;
  draw_pro.Draw(default,"selmu_truemom",50,0,5000,"particle","(accum_level[][0]>4)&&(particle==2212)");
  /*TCanvas proton_originals;
  draw_pro.Draw(default,"selmu_truemom",50,0,5000,"particle","(accum_level[][0]>4)&&(parent==0)&&(particle==2212)");
  TCanvas proton_migrated;
  draw_pro.Draw(default,"selmu_truemom",50,0,5000,"particle","(accum_level[][0]>4)&&(parent!=0)&&(particle==2212)");*/
  
  TCanvas positron_all;
  draw_pos.Draw(default,"selmu_truemom",50,0,5000,"particle","(accum_level[][0]>4)");
  TCanvas positron_true;
  draw_pos.Draw(default,"selmu_truemom",50,0,5000,"particle","(accum_level[][0]>4)&&(particle==-11)");
  /*TCanvas positron_originals;
  draw_pos.Draw(default,"selmu_truemom",50,0,5000,"particle","(accum_level[][0]>4)&&(parent==0)&&(particle==-11)");
  TCanvas positron_migrated;
  draw_pos.Draw(default,"selmu_truemom",50,0,5000,"particle","(accum_level[][0]>4)&&(parent!=0)&&(particle==-11)");*/
}
