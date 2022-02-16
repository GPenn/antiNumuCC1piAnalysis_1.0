{
  DrawingTools draw("/bundle/data/T2K/users/gpenn/highlandBDTtests/ecallowlevel/particlegun/particlegun_allpositive_testing.root");
  DataSample mc("/bundle/data/T2K/users/gpenn/highlandBDTtests/ecallowlevel/particlegun/particlegun_allpositive_testing.root");
  
  // ----------------  ----------------
  
  draw.SetTitleX("TPC2 reconstructed momentum (MeV/c)");
  draw.SetTitleY("TPC2 dE/dx");
  TCanvas tpc2_dedx_vs_recomom;
  draw.Draw(default,"selmu_tpc_dedx[0]:selmu_mom[0]",50,0,2000,50,0,2000, "all", "(accum_level[][1]>5)", "colz");
  
  draw.SetTitleX("TPC3 reconstructed momentum (MeV/c)");
  draw.SetTitleY("TPC3 dE/dx");
  TCanvas tpc3_dedx_vs_recomom;
  draw.Draw(default,"selmu_tpc_dedx[1]:selmu_mom[1]",50,0,2000,50,0,2000, "all", "(accum_level[][1]>5)", "colz");
  
  draw.SetTitleX("TPC3 reconstructed momentum (MeV/c)");
  draw.SetTitleY("TPC2 dE/dx");
  TCanvas tpc3_dedx_vs_tpc2_recomom;
  draw.Draw(default,"selmu_tpc_dedx[1]:selmu_mom[0]",50,0,2000,50,0,2000, "all", "(accum_level[][1]>5)", "colz");
  
  draw.SetTitleX("TPC2 dE/dx");
  draw.SetTitleY("TPC3 dE/dx");
  TCanvas tpc3dedx_vs_tpc2dedx;
  draw.Draw(default,"selmu_tpc_dedx[1]:selmu_tpc_dedx[0]",50,0,2000,50,0,2000, "all", "(accum_level[][1]>5)", "colz");
}
