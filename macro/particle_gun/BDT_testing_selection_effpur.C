{
  DrawingTools draw("output/particle_gun/bdt_testing_selection_test.root");
  DataSample mc("output/particle_gun/bdt_testing_selection_test.root");
  
  draw.DrawEffPurVSCut(mc,"particle==1")

}
