#include "antiNumuCCMultiPiAnalysis.hxx"
#include "AnalysisLoop.hxx"

int main(int argc, char *argv[]){
  antiNumuCCMultiPiAnalysis* ana = new antiNumuCCMultiPiAnalysis();
  AnalysisLoop loop(ana, argc, argv); 
  loop.Execute();
}
