#include "antiNumuCC1piAnalysis.hxx"
#include "AnalysisLoop.hxx"

int main(int argc, char *argv[]){
  antiNumuCC1piAnalysis* ana = new antiNumuCC1piAnalysis();
  AnalysisLoop loop(ana, argc, argv); 
  loop.Execute();
}
