#define defaultAntiNumuCC1pi_cxx
#include "defaultAntiNumuCC1pi.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <ctime> 

void defaultAntiNumuCC1pi::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L defaultAntiNumuCC1pi.C
//      Root > defaultAntiNumuCC1pi t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntries();
   
   std::cout << "Total entries to convert: " << nentries << std::endl << std::endl;
   
   std::time_t time_start = std::time(0);
      
      for (Long64_t jentry=0; jentry<nentries;jentry++) {
   
          fChain->GetEntry(jentry);

          // Cut on accum_level etc.
          if (accum_level[0][1] < 8) continue; // Set accum_level
     
            defout->topology		                  = topology;
            defout->selmu_ecal_mippion		         = selmu_ecal_mippion[0];	
            defout->selmu_ecal_EMenergy            = selmu_ecal_EMenergy[0];
            defout->selmu_ecal_length              = selmu_ecal_length[0]; 
         
            defout->Fill();
            
         
            // Code to keep track of completion percentage and estimate time remaining:
         
            Double_t completion = (Double_t)jentry/(Double_t)nentries;
         
            std::time_t time_now = std::time(0);
            std::time_t time_sofar = time_now - time_start;
         
            Long64_t time_total_guess = time_sofar / completion;
            Long64_t time_left_guess = time_total_guess - time_sofar;
         
            std::cout << "Converted " << jentry << " of " << nentries << " entries (" << (Int_t)(completion*100) << "\%). " 
               << "Time elapsed: " << time_sofar << "s. "
               << "Estimated time remaining: " << time_left_guess << "s. \r";

   }
   
   std::cout << std::endl << "All entries converted. Writing output file...\n\n";
   
   defout->Write();
}

int main(int argc, char* argv[]) {

  std::string outFileName;

  // Check for command line options
  for (;;) {
    int c = getopt(argc, argv, "o:");
    if (c<0) break;
    switch (c) {
    case 'o':
      outFileName = optarg;
      break;
    }
  } // Closes process options for loop 
  
  // Test for further command line arguments after options
  if (argc<=optind) {
    std::cout << "ERROR: No input file(s)" << std::endl << std::endl;
    return 1;
  }

  // Create file TChain
  TChain* rootFiles = new TChain("default");
  std::cout<<"Number of files to read  = "<<argc-optind<<std::endl;

  std::vector<std::string> files;
  for(int i=optind; i<argc; i++){
    char* f = argv[i];
    files.push_back(f);
    std::cout<<files[i-optind]<<std::endl;
  }
  
  for(std::vector<std::string>::const_iterator f = files.begin(); f != files.end(); ++f){
    // Add files to TChain
    rootFiles->Add(f->c_str());
    std::cout<<"Adding file "<<f->c_str()<<std::endl;
  }
  
  defaultAntiNumuCC1pi *deftree = new defaultAntiNumuCC1pi(rootFiles, outFileName);
  
  deftree->Loop();

  return 0;
}

defaultOut::defaultOut(std::string outname) {
  
  fOutFile = new TFile(outname.c_str(), "RECREATE");
  fOutFile->cd();
  fDefaultOut = new TTree("default", "");

  foutb_topology 	                   = fDefaultOut->Branch("topology"                       , &topology 	                  , "topology/I");
  foutb_selmu_ecal_mippion 	       = fDefaultOut->Branch("selmu_ecal_mippion"             , &selmu_ecal_mippion 	      , "selmu_ecal_mippion/F");
  foutb_selmu_ecal_EMenergy 	       = fDefaultOut->Branch("selmu_ecal_EMenergy"            , &selmu_ecal_EMenergy	      , "selmu_ecal_EMenergy/F");
  foutb_selmu_ecal_length  	       = fDefaultOut->Branch("selmu_ecal_length"              , &selmu_ecal_length  	      , "selmu_ecal_length/F");
   
  return;
}
