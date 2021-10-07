#include "antiNumuBDTTestingAnalysis.hxx"
#include "AnalysisLoop.hxx"

int main(int argc, char *argv[]){
  antiNumuBDTTestingAnalysis* ana = new antiNumuBDTTestingAnalysis();
  AnalysisLoop loop(ana, argc, argv); 
  loop.Execute();
}
