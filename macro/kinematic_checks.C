{
  DrawingTools draw("output/output_p6T_allruns_standard_withoptimised.root");
  DataSample mc("output/output_p6T_allruns_standard_withoptimised.root");
  
  draw.SetTitleX("HMPT reco momentum");
  TCanvas selmu_mom_accum4;
  draw.Draw(default,"selmu_mom",20,0,7000,"particle","accum_level[][0]>4");
  draw.DrawCutLineVertical(2000,true,"l");
  selmu_mom_accum4->SaveAs("img/particlegun/kinematic_checks_selmu_mom_accum4_evt.png");
  
  draw.SetTitleX("HMPT reco momentum");
  TCanvas selmu_mom_accum4_lowmom;
  draw.Draw(default,"selmu_mom",20,0,500,"particle","accum_level[][0]>4");
  draw.DrawCutLineVertical(150,true,"r");
  selmu_mom_accum4_lowmom->SaveAs("img/particlegun/kinematic_checks_selmu_mom_accum4_lowmom_evt.png");
  
  draw.SetTitleX("HMPT true momentum");
  TCanvas selmu_truemom_accum4;
  draw.Draw(default,"selmu_truemom",20,0,7000,"particle","accum_level[][0]>4");
  draw.DrawCutLineVertical(2000,true,"l");
  selmu_truemom_accum4->SaveAs("img/particlegun/kinematic_checks_selmu_truemom_accum4_evt.png");
  
  draw.SetTitleX("HMPT true momentum");
  TCanvas selmu_truemom_accum4_lowmom;
  draw.Draw(default,"selmu_truemom",20,0,500,"particle","accum_level[][0]>4");
  draw.DrawCutLineVertical(150,true,"r");
  selmu_truemom_accum4_lowmom->SaveAs("img/particlegun/kinematic_checks_selmu_truemom_accum4_lowmom_evt.png");
    
  draw.SetTitleX("HMPT reco costheta");
  TCanvas selmu_costheta_accum4;
  draw.Draw(default,"selmu_costheta",30,0,1.5,"particle","accum_level[][0]>4");
  draw.DrawCutLineVertical(0.4,true,"r");
  selmu_costheta_accum4->SaveAs("img/particlegun/kinematic_checks_selmu_costheta_accum4_evt.png");
  
  draw.SetTitleX("HMPT reco angle");
  TCanvas selmu_theta_accum4;
  draw.Draw(default,"(TMath::ACos(selmu_costheta))*360/6.283",30,0,90,"particle","accum_level[][0]>4");
  draw.DrawCutLineVertical(65,true,"l");
  selmu_theta_accum4->SaveAs("img/particlegun/kinematic_checks_selmu_theta_accum4_evt.png");
}
