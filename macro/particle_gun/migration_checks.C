{
  DrawingTools draw("output/particle_gun/particlegun_allpositive.root");
  DataSample mc("output/particle_gun/particlegun_allpositive.root");
  
  draw.SetTitleX("HMT parent");
  TCanvas selmu_mom_accum4_parent;
  draw.Draw(default,"parent",40,-20,20,"particle","(accum_level[][0]>4)");
  
  /*draw.SetTitleX("HMT reco momentum");
  TCanvas selmu_mom_accum4_originals;
  draw.Draw(default,"selmu_mom",20,0,7000,"particle","(accum_level[][0]>4)&&(parent==)");
  draw.DrawCutLineVertical(2000,true,"l");
  //selmu_mom_accum4->SaveAs("img/particlegun/kinematic_checks_selmu_mom_accum4_pg.png");
  
  draw.SetTitleX("HMT reco momentum");
  TCanvas selmu_mom_accum4_lowmom_originals;
  draw.Draw(default,"selmu_mom",20,0,500,"particle","accum_level[][0]>4");
  draw.DrawCutLineVertical(150,true,"r");
  //selmu_mom_accum4_lowmom->SaveAs("img/particlegun/kinematic_checks_selmu_mom_accum4_lowmom_pg.png");
  
  draw.SetTitleX("HMT true momentum");
  TCanvas selmu_truemom_accum4_originals;
  draw.Draw(default,"selmu_truemom",20,0,7000,"particle","accum_level[][0]>4");
  draw.DrawCutLineVertical(2000,true,"l");
  //selmu_truemom_accum4->SaveAs("img/particlegun/kinematic_checks_selmu_truemom_accum4_pg.png");
  
  draw.SetTitleX("HMT true momentum");
  TCanvas selmu_truemom_accum4_lowmom_originals;
  draw.Draw(default,"selmu_truemom",20,0,500,"particle","accum_level[][0]>4");
  draw.DrawCutLineVertical(150,true,"r");
  //selmu_truemom_accum4_lowmom->SaveAs("img/particlegun/kinematic_checks_selmu_truemom_accum4_lowmom_pg.png");
  
  draw.SetTitleX("HMT reco angle (deg)");
  TCanvas selmu_theta_accum4_originals;
  draw.Draw(default,"(TMath::ACos(selmu_costheta))*360/6.283",30,0,90,"particle","accum_level[][0]>4");
  draw.DrawCutLineVertical(65,true,"l");
  //selmu_theta_accum4->SaveAs("img/particlegun/kinematic_checks_selmu_theta_accum4_pg.png");*/
}
