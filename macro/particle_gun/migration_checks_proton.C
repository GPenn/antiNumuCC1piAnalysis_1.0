{
  DrawingTools draw("output/particle_gun/particlegun_proton.root");
  DataSample mc("output/particle_gun/particlegun_proton.root");
  
  draw.SetTitleX("Main track true momentum (MeV/c)");
  TCanvas overall_mom;
  draw.Draw(default,"selmu_truemom",60,0,3000,"particle","(accum_level[][0]>4)");
  overall_mom->SaveAs("img/particlegun/migration_checks_proton_truemom_accum4_pg.png");
  TCanvas trueproton_mom;
  draw.Draw(default,"selmu_truemom",60,0,3000,"particle","(accum_level[][0]>4)&&(particle==2212)");
  
  draw.SetTitleX("Main track reco momentum (MeV/c)");
  TCanvas overall_recomom;
  draw.Draw(default,"selmu_mom",60,0,3000,"particle","(accum_level[][0]>4)");
  overall_recomom->SaveAs("img/particlegun/migration_checks_proton_recomom_accum4_pg.png");
}
