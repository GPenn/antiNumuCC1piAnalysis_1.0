{
  DrawingTools draw("output/particle_gun/particlegun_antimu.root");
  DataSample mc("output/particle_gun/particlegun_antimu.root");
  
  draw.SetTitleX("Main track true momentum (MeV/c)");
  TCanvas overall_mom;
  draw.Draw(default,"selmu_truemom",60,0,3000,"particle","(accum_level[][0]>4)");
  overall_mom->SaveAs("img/particlegun/migration_checks_antimu_truemom_accum4_pg.png");
  TCanvas trueantimu_mom;
  draw.Draw(default,"selmu_truemom",60,0,3000,"particle","(accum_level[][0]>4)&&(particle==-13)");
  
  draw.SetTitleX("Main track reco momentum (MeV/c)");
  TCanvas overall_recomom;
  draw.Draw(default,"selmu_mom",60,0,3000,"particle","(accum_level[][0]>4)");
  overall_recomom->SaveAs("img/particlegun/migration_checks_antimu_recomom_accum4_pg.png");
}
