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
     
            defout->evt    		                  = evt;
            defout->topology		                  = topology;
            defout->particle		                  = particle;
            defout->ntpcposQualityFV               = ntpcposQualityFV;
            defout->ntpcnegQualityFV               = ntpcnegQualityFV;
         
            defout->selmu_necals                   = selmu_necals;
            defout->selmu_ecal_mippion		         = selmu_ecal_mippion[0];	
            defout->selmu_ecal_EMenergy            = selmu_ecal_EMenergy[0];
            defout->selmu_ecal_length              = selmu_ecal_length[0]; 
            defout->selmu_ecal_avg_mippion         = selmu_ecal_avg_mippion;
            defout->selmu_ecal_avg_EbyL            = selmu_ecal_avg_EbyL;
         
            defout->selmu_tpc_like_mu              = selmu_tpc_like_mu;
            defout->selmu_tpc_like_e               = selmu_tpc_like_e;
            defout->selmu_tpc_like_p               = selmu_tpc_like_p;
            defout->selmu_tpc_like_pi              = selmu_tpc_like_pi;
         
            defout->selmu_has_fgd1seg              = selmu_has_fgd1seg;
            defout->selmu_fgd1_pull_mu             = selmu_fgd1_pull_mu;
            defout->selmu_fgd1_pull_p              = selmu_fgd1_pull_p;
            defout->selmu_fgd1_pull_pi             = selmu_fgd1_pull_pi;
            defout->selmu_fgd1_pull_no             = selmu_fgd1_pull_no;
         
            defout->selmu_has_fgd2seg              = selmu_has_fgd2seg;
            defout->selmu_fgd2_pull_mu             = selmu_fgd2_pull_mu;
            defout->selmu_fgd2_pull_p              = selmu_fgd2_pull_p;
            defout->selmu_fgd2_pull_pi             = selmu_fgd2_pull_pi;
            defout->selmu_fgd2_pull_no             = selmu_fgd2_pull_no;
            
            defout->HMNT_NEcalSegments		         = HMNT_NEcalSegments;
            defout->HMNT_ecal_mippion		         = HMNT_ecal_mippion;	
            defout->HMNT_ecal_EMenergy             = HMNT_ecal_EMenergy;
            defout->HMNT_ecal_length               = HMNT_ecal_length; 
            defout->HMNT_ecal_avg_mippion          = HMNT_ecal_avg_mippion;
            defout->HMNT_ecal_avg_EbyL             = HMNT_ecal_avg_EbyL;
         
            defout->HMNT_tpc_like_mu              = HMNT_tpc_like_mu;
            defout->HMNT_tpc_like_e               = HMNT_tpc_like_e;
            defout->HMNT_tpc_like_p               = HMNT_tpc_like_p;
            defout->HMNT_tpc_like_pi              = HMNT_tpc_like_pi;
         
            defout->HMNT_has_fgd1seg              = HMNT_has_fgd1seg;
            defout->HMNT_fgd1_pull_mu             = HMNT_fgd1_pull_mu;
            defout->HMNT_fgd1_pull_p              = HMNT_fgd1_pull_p;
            defout->HMNT_fgd1_pull_pi             = HMNT_fgd1_pull_pi;
            defout->HMNT_fgd1_pull_no             = HMNT_fgd1_pull_no;
         
            defout->HMNT_has_fgd2seg              = HMNT_has_fgd2seg;
            defout->HMNT_fgd2_pull_mu             = HMNT_fgd2_pull_mu;
            defout->HMNT_fgd2_pull_p              = HMNT_fgd2_pull_p;
            defout->HMNT_fgd2_pull_pi             = HMNT_fgd2_pull_pi;
            defout->HMNT_fgd2_pull_no             = HMNT_fgd2_pull_no;
            
            if (selmu_necals>0)
            {
               defout->selmu_ecal_EoverL            = selmu_ecal_EMenergy[0] / selmu_ecal_length[0];
            }
            else
            {
               defout->selmu_ecal_EoverL            = -1.0;
            }
         
            if (HMNT_NEcalSegments>0)
            {
               defout->HMNT_ecal_EoverL            = HMNT_ecal_EMenergy / HMNT_ecal_length;
            }
            else
            {
               defout->HMNT_ecal_EoverL            = -1.0;
            }
         
            //defout->Fill();
         
            if ( topology==1 && (entry%5)<4 ) {defout->Fill_SigTrain();} // Signal training
            if ( topology==1 && (entry%5)>=4 ) {defout->Fill_SigTest();}  // Signal testing
            if ( topology!=1 && (entry%5)<4 ) {defout->Fill_BkgTrain();} // Background training
            if ( topology!=1 && (entry%5)>=4 ) {defout->Fill_BkgTest();}  // Background testing
               
            
         
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
  
  // ----------- Signal training tree -----------
   
  fDefaultOut_SigTrain = new TTree("SignalTraining", "");

  foutb_evt_SigTrain 	                      = fDefaultOut_SigTrain->Branch("evt"                            , &evt 	                     , "evt/I");
  foutb_topology_SigTrain 	                   = fDefaultOut_SigTrain->Branch("topology"                       , &topology 	                  , "topology/I");
  foutb_particle_SigTrain 	                   = fDefaultOut_SigTrain->Branch("particle"                       , &particle 	                  , "particle/I");
  foutb_ntpcposQualityFV_SigTrain 	          = fDefaultOut_SigTrain->Branch("ntpcposQualityFV"               , &ntpcposQualityFV 	         , "ntpcposQualityFV/I");
  foutb_ntpcnegQualityFV_SigTrain 	          = fDefaultOut_SigTrain->Branch("ntpcnegQualityFV"               , &ntpcnegQualityFV 	         , "ntpcnegQualityFV/I");
  
  foutb_selmu_necals_SigTrain 	             = fDefaultOut_SigTrain->Branch("selmu_necals"                   , &selmu_necals       	      , "selmu_necals/I");
  foutb_selmu_ecal_mippion_SigTrain 	       = fDefaultOut_SigTrain->Branch("selmu_ecal_mippion"             , &selmu_ecal_mippion 	      , "selmu_ecal_mippion/F");
  foutb_selmu_ecal_EMenergy_SigTrain 	       = fDefaultOut_SigTrain->Branch("selmu_ecal_EMenergy"            , &selmu_ecal_EMenergy	      , "selmu_ecal_EMenergy/F");
  foutb_selmu_ecal_length_SigTrain  	       = fDefaultOut_SigTrain->Branch("selmu_ecal_length"              , &selmu_ecal_length  	      , "selmu_ecal_length/F");
  foutb_selmu_ecal_EoverL_SigTrain  	       = fDefaultOut_SigTrain->Branch("selmu_ecal_EoverL"              , &selmu_ecal_EoverL  	      , "selmu_ecal_EoverL/F");
  foutb_selmu_ecal_avg_mippion_SigTrain       = fDefaultOut_SigTrain->Branch("selmu_ecal_avg_mippion"         , &selmu_ecal_avg_mippion  	   , "selmu_ecal_avg_mippion/F");
  foutb_selmu_ecal_avg_EbyL_SigTrain  	       = fDefaultOut_SigTrain->Branch("selmu_ecal_avg_EbyL"            , &selmu_ecal_avg_EbyL  	      , "selmu_ecal_avg_EbyL/F");
   
  foutb_selmu_tpc_like_mu_SigTrain  	       = fDefaultOut_SigTrain->Branch("selmu_tpc_like_mu"              , &selmu_tpc_like_mu  	      , "selmu_tpc_like_mu/F");
  foutb_selmu_tpc_like_e_SigTrain  	          = fDefaultOut_SigTrain->Branch("selmu_tpc_like_e"               , &selmu_tpc_like_e  	         , "selmu_tpc_like_e/F");
  foutb_selmu_tpc_like_p_SigTrain  	          = fDefaultOut_SigTrain->Branch("selmu_tpc_like_p"               , &selmu_tpc_like_p  	         , "selmu_tpc_like_p/F");
  foutb_selmu_tpc_like_pi_SigTrain  	       = fDefaultOut_SigTrain->Branch("selmu_tpc_like_pi"              , &selmu_tpc_like_pi  	      , "selmu_tpc_like_pi/F");
   
  foutb_selmu_has_fgd1seg_SigTrain 	          = fDefaultOut_SigTrain->Branch("selmu_has_fgd1seg"              , &selmu_has_fgd1seg 	         , "selmu_has_fgd1seg/I");
  foutb_selmu_fgd1_pull_mu_SigTrain  	       = fDefaultOut_SigTrain->Branch("selmu_fgd1_pull_mu"             , &selmu_fgd1_pull_mu  	      , "selmu_fgd1_pull_mu/F");
  foutb_selmu_fgd1_pull_p_SigTrain  	       = fDefaultOut_SigTrain->Branch("selmu_fgd1_pull_p"              , &selmu_fgd1_pull_p  	      , "selmu_fgd1_pull_p/F");
  foutb_selmu_fgd1_pull_pi_SigTrain  	       = fDefaultOut_SigTrain->Branch("selmu_fgd1_pull_pi"             , &selmu_fgd1_pull_pi  	      , "selmu_fgd1_pull_pi/F");
  foutb_selmu_fgd1_pull_no_SigTrain  	       = fDefaultOut_SigTrain->Branch("selmu_fgd1_pull_no"             , &selmu_fgd1_pull_no  	      , "selmu_fgd1_pull_no/F");
   
  foutb_selmu_has_fgd2seg_SigTrain 	          = fDefaultOut_SigTrain->Branch("selmu_has_fgd2seg"              , &selmu_has_fgd2seg 	         , "selmu_has_fgd2seg/I");
  foutb_selmu_fgd2_pull_mu_SigTrain  	       = fDefaultOut_SigTrain->Branch("selmu_fgd2_pull_mu"             , &selmu_fgd2_pull_mu  	      , "selmu_fgd2_pull_mu/F");
  foutb_selmu_fgd2_pull_p_SigTrain  	       = fDefaultOut_SigTrain->Branch("selmu_fgd2_pull_p"              , &selmu_fgd2_pull_p  	      , "selmu_fgd2_pull_p/F");
  foutb_selmu_fgd2_pull_pi_SigTrain  	       = fDefaultOut_SigTrain->Branch("selmu_fgd2_pull_pi"             , &selmu_fgd2_pull_pi  	      , "selmu_fgd2_pull_pi/F");
  foutb_selmu_fgd2_pull_no_SigTrain  	       = fDefaultOut_SigTrain->Branch("selmu_fgd2_pull_no"             , &selmu_fgd2_pull_no  	      , "selmu_fgd2_pull_no/F");
  
  foutb_HMNT_NEcalSegments_SigTrain	          = fDefaultOut_SigTrain->Branch("HMNT_NEcalSegments"             , &HMNT_NEcalSegments	         , "HMNT_NEcalsSegments/I");
  foutb_HMNT_ecal_mippion_SigTrain 	          = fDefaultOut_SigTrain->Branch("HMNT_ecal_mippion"              , &HMNT_ecal_mippion 	         , "HMNT_ecal_mippion/F");
  foutb_HMNT_ecal_EMenergy_SigTrain 	       = fDefaultOut_SigTrain->Branch("HMNT_ecal_EMenergy"             , &HMNT_ecal_EMenergy	         , "HMNT_ecal_EMenergy/F");
  foutb_HMNT_ecal_length_SigTrain  	          = fDefaultOut_SigTrain->Branch("HMNT_ecal_length"               , &HMNT_ecal_length  	         , "HMNT_ecal_length/F");
  foutb_HMNT_ecal_EoverL_SigTrain  	          = fDefaultOut_SigTrain->Branch("HMNT_ecal_EoverL"               , &HMNT_ecal_EoverL  	         , "HMNT_ecal_EoverL/F");
  foutb_HMNT_ecal_avg_mippion_SigTrain       = fDefaultOut_SigTrain->Branch("HMNT_ecal_avg_mippion"         , &HMNT_ecal_avg_mippion        , "HMNT_ecal_avg_mippion/F");
  foutb_HMNT_ecal_avg_EbyL_SigTrain             = fDefaultOut_SigTrain->Branch("HMNT_ecal_avg_EbyL"            , &HMNT_ecal_avg_EbyL         , "HMNT_ecal_avg_EbyL/F");
   
  foutb_HMNT_tpc_like_mu_SigTrain               = fDefaultOut_SigTrain->Branch("HMNT_tpc_like_mu"              , &HMNT_tpc_like_mu           , "HMNT_tpc_like_mu/F");
  foutb_HMNT_tpc_like_e_SigTrain             = fDefaultOut_SigTrain->Branch("HMNT_tpc_like_e"               , &HMNT_tpc_like_e            , "HMNT_tpc_like_e/F");
  foutb_HMNT_tpc_like_p_SigTrain             = fDefaultOut_SigTrain->Branch("HMNT_tpc_like_p"               , &HMNT_tpc_like_p            , "HMNT_tpc_like_p/F");
  foutb_HMNT_tpc_like_pi_SigTrain               = fDefaultOut_SigTrain->Branch("HMNT_tpc_like_pi"              , &HMNT_tpc_like_pi           , "HMNT_tpc_like_pi/F");
   
  foutb_HMNT_has_fgd1seg_SigTrain            = fDefaultOut_SigTrain->Branch("HMNT_has_fgd1seg"              , &HMNT_has_fgd1seg           , "HMNT_has_fgd1seg/I");
  foutb_HMNT_fgd1_pull_mu_SigTrain              = fDefaultOut_SigTrain->Branch("HMNT_fgd1_pull_mu"             , &HMNT_fgd1_pull_mu          , "HMNT_fgd1_pull_mu/F");
  foutb_HMNT_fgd1_pull_p_SigTrain               = fDefaultOut_SigTrain->Branch("HMNT_fgd1_pull_p"              , &HMNT_fgd1_pull_p           , "HMNT_fgd1_pull_p/F");
  foutb_HMNT_fgd1_pull_pi_SigTrain              = fDefaultOut_SigTrain->Branch("HMNT_fgd1_pull_pi"             , &HMNT_fgd1_pull_pi          , "HMNT_fgd1_pull_pi/F");
  foutb_HMNT_fgd1_pull_no_SigTrain              = fDefaultOut_SigTrain->Branch("HMNT_fgd1_pull_no"             , &HMNT_fgd1_pull_no          , "HMNT_fgd1_pull_no/F");
   
  foutb_HMNT_has_fgd2seg_SigTrain            = fDefaultOut_SigTrain->Branch("HMNT_has_fgd2seg"              , &HMNT_has_fgd2seg           , "HMNT_has_fgd2seg/I");
  foutb_HMNT_fgd2_pull_mu_SigTrain              = fDefaultOut_SigTrain->Branch("HMNT_fgd2_pull_mu"             , &HMNT_fgd2_pull_mu          , "HMNT_fgd2_pull_mu/F");
  foutb_HMNT_fgd2_pull_p_SigTrain               = fDefaultOut_SigTrain->Branch("HMNT_fgd2_pull_p"              , &HMNT_fgd2_pull_p           , "HMNT_fgd2_pull_p/F");
  foutb_HMNT_fgd2_pull_pi_SigTrain              = fDefaultOut_SigTrain->Branch("HMNT_fgd2_pull_pi"             , &HMNT_fgd2_pull_pi          , "HMNT_fgd2_pull_pi/F");
  foutb_HMNT_fgd2_pull_no_SigTrain              = fDefaultOut_SigTrain->Branch("HMNT_fgd2_pull_no"             , &HMNT_fgd2_pull_no          , "HMNT_fgd2_pull_no/F");
   
  // ----------- Signal testing tree -----------
   
  fDefaultOut_SigTest = new TTree("SignalTesting", "");

  foutb_evt_SigTest                            = fDefaultOut_SigTest->Branch("evt"                            , &evt                         , "evt/I");
  foutb_topology_SigTest                        = fDefaultOut_SigTest->Branch("topology"                       , &topology                    , "topology/I");
  foutb_particle_SigTest                        = fDefaultOut_SigTest->Branch("particle"                       , &particle                    , "particle/I");
  foutb_ntpcposQualityFV_SigTest             = fDefaultOut_SigTest->Branch("ntpcposQualityFV"               , &ntpcposQualityFV            , "ntpcposQualityFV/I");
  foutb_ntpcnegQualityFV_SigTest             = fDefaultOut_SigTest->Branch("ntpcnegQualityFV"               , &ntpcnegQualityFV            , "ntpcnegQualityFV/I");
  
  foutb_selmu_necals_SigTest                    = fDefaultOut_SigTest->Branch("selmu_necals"                   , &selmu_necals                , "selmu_necals/I");
  foutb_selmu_ecal_mippion_SigTest              = fDefaultOut_SigTest->Branch("selmu_ecal_mippion"             , &selmu_ecal_mippion          , "selmu_ecal_mippion/F");
  foutb_selmu_ecal_EMenergy_SigTest             = fDefaultOut_SigTest->Branch("selmu_ecal_EMenergy"            , &selmu_ecal_EMenergy         , "selmu_ecal_EMenergy/F");
  foutb_selmu_ecal_length_SigTest               = fDefaultOut_SigTest->Branch("selmu_ecal_length"              , &selmu_ecal_length           , "selmu_ecal_length/F");
  foutb_selmu_ecal_EoverL_SigTest               = fDefaultOut_SigTest->Branch("selmu_ecal_EoverL"              , &selmu_ecal_EoverL           , "selmu_ecal_EoverL/F");
  foutb_selmu_ecal_avg_mippion_SigTest       = fDefaultOut_SigTest->Branch("selmu_ecal_avg_mippion"         , &selmu_ecal_avg_mippion      , "selmu_ecal_avg_mippion/F");
  foutb_selmu_ecal_avg_EbyL_SigTest             = fDefaultOut_SigTest->Branch("selmu_ecal_avg_EbyL"            , &selmu_ecal_avg_EbyL         , "selmu_ecal_avg_EbyL/F");
   
  foutb_selmu_tpc_like_mu_SigTest               = fDefaultOut_SigTest->Branch("selmu_tpc_like_mu"              , &selmu_tpc_like_mu           , "selmu_tpc_like_mu/F");
  foutb_selmu_tpc_like_e_SigTest             = fDefaultOut_SigTest->Branch("selmu_tpc_like_e"               , &selmu_tpc_like_e            , "selmu_tpc_like_e/F");
  foutb_selmu_tpc_like_p_SigTest             = fDefaultOut_SigTest->Branch("selmu_tpc_like_p"               , &selmu_tpc_like_p            , "selmu_tpc_like_p/F");
  foutb_selmu_tpc_like_pi_SigTest               = fDefaultOut_SigTest->Branch("selmu_tpc_like_pi"              , &selmu_tpc_like_pi           , "selmu_tpc_like_pi/F");
   
  foutb_selmu_has_fgd1seg_SigTest            = fDefaultOut_SigTest->Branch("selmu_has_fgd1seg"              , &selmu_has_fgd1seg           , "selmu_has_fgd1seg/I");
  foutb_selmu_fgd1_pull_mu_SigTest              = fDefaultOut_SigTest->Branch("selmu_fgd1_pull_mu"             , &selmu_fgd1_pull_mu          , "selmu_fgd1_pull_mu/F");
  foutb_selmu_fgd1_pull_p_SigTest               = fDefaultOut_SigTest->Branch("selmu_fgd1_pull_p"              , &selmu_fgd1_pull_p           , "selmu_fgd1_pull_p/F");
  foutb_selmu_fgd1_pull_pi_SigTest              = fDefaultOut_SigTest->Branch("selmu_fgd1_pull_pi"             , &selmu_fgd1_pull_pi          , "selmu_fgd1_pull_pi/F");
  foutb_selmu_fgd1_pull_no_SigTest              = fDefaultOut_SigTest->Branch("selmu_fgd1_pull_no"             , &selmu_fgd1_pull_no          , "selmu_fgd1_pull_no/F");
   
  foutb_selmu_has_fgd2seg_SigTest            = fDefaultOut_SigTest->Branch("selmu_has_fgd2seg"              , &selmu_has_fgd2seg           , "selmu_has_fgd2seg/I");
  foutb_selmu_fgd2_pull_mu_SigTest              = fDefaultOut_SigTest->Branch("selmu_fgd2_pull_mu"             , &selmu_fgd2_pull_mu          , "selmu_fgd2_pull_mu/F");
  foutb_selmu_fgd2_pull_p_SigTest               = fDefaultOut_SigTest->Branch("selmu_fgd2_pull_p"              , &selmu_fgd2_pull_p           , "selmu_fgd2_pull_p/F");
  foutb_selmu_fgd2_pull_pi_SigTest              = fDefaultOut_SigTest->Branch("selmu_fgd2_pull_pi"             , &selmu_fgd2_pull_pi          , "selmu_fgd2_pull_pi/F");
  foutb_selmu_fgd2_pull_no_SigTest              = fDefaultOut_SigTest->Branch("selmu_fgd2_pull_no"             , &selmu_fgd2_pull_no          , "selmu_fgd2_pull_no/F");
  
  foutb_HMNT_NEcalSegments_SigTest           = fDefaultOut_SigTest->Branch("HMNT_NEcalSegments"             , &HMNT_NEcalSegments          , "HMNT_NEcalsSegments/I");
  foutb_HMNT_ecal_mippion_SigTest            = fDefaultOut_SigTest->Branch("HMNT_ecal_mippion"              , &HMNT_ecal_mippion           , "HMNT_ecal_mippion/F");
  foutb_HMNT_ecal_EMenergy_SigTest              = fDefaultOut_SigTest->Branch("HMNT_ecal_EMenergy"             , &HMNT_ecal_EMenergy             , "HMNT_ecal_EMenergy/F");
  foutb_HMNT_ecal_length_SigTest             = fDefaultOut_SigTest->Branch("HMNT_ecal_length"               , &HMNT_ecal_length            , "HMNT_ecal_length/F");
  foutb_HMNT_ecal_EoverL_SigTest             = fDefaultOut_SigTest->Branch("HMNT_ecal_EoverL"               , &HMNT_ecal_EoverL            , "HMNT_ecal_EoverL/F");
  foutb_HMNT_ecal_avg_mippion_SigTest       = fDefaultOut_SigTest->Branch("HMNT_ecal_avg_mippion"         , &HMNT_ecal_avg_mippion        , "HMNT_ecal_avg_mippion/F");
  foutb_HMNT_ecal_avg_EbyL_SigTest             = fDefaultOut_SigTest->Branch("HMNT_ecal_avg_EbyL"            , &HMNT_ecal_avg_EbyL         , "HMNT_ecal_avg_EbyL/F");
   
  foutb_HMNT_tpc_like_mu_SigTest               = fDefaultOut_SigTest->Branch("HMNT_tpc_like_mu"              , &HMNT_tpc_like_mu           , "HMNT_tpc_like_mu/F");
  foutb_HMNT_tpc_like_e_SigTest             = fDefaultOut_SigTest->Branch("HMNT_tpc_like_e"               , &HMNT_tpc_like_e            , "HMNT_tpc_like_e/F");
  foutb_HMNT_tpc_like_p_SigTest             = fDefaultOut_SigTest->Branch("HMNT_tpc_like_p"               , &HMNT_tpc_like_p            , "HMNT_tpc_like_p/F");
  foutb_HMNT_tpc_like_pi_SigTest               = fDefaultOut_SigTest->Branch("HMNT_tpc_like_pi"              , &HMNT_tpc_like_pi           , "HMNT_tpc_like_pi/F");
   
  foutb_HMNT_has_fgd1seg_SigTest            = fDefaultOut_SigTest->Branch("HMNT_has_fgd1seg"              , &HMNT_has_fgd1seg           , "HMNT_has_fgd1seg/I");
  foutb_HMNT_fgd1_pull_mu_SigTest              = fDefaultOut_SigTest->Branch("HMNT_fgd1_pull_mu"             , &HMNT_fgd1_pull_mu          , "HMNT_fgd1_pull_mu/F");
  foutb_HMNT_fgd1_pull_p_SigTest               = fDefaultOut_SigTest->Branch("HMNT_fgd1_pull_p"              , &HMNT_fgd1_pull_p           , "HMNT_fgd1_pull_p/F");
  foutb_HMNT_fgd1_pull_pi_SigTest              = fDefaultOut_SigTest->Branch("HMNT_fgd1_pull_pi"             , &HMNT_fgd1_pull_pi          , "HMNT_fgd1_pull_pi/F");
  foutb_HMNT_fgd1_pull_no_SigTest              = fDefaultOut_SigTest->Branch("HMNT_fgd1_pull_no"             , &HMNT_fgd1_pull_no          , "HMNT_fgd1_pull_no/F");
   
  foutb_HMNT_has_fgd2seg_SigTest            = fDefaultOut_SigTest->Branch("HMNT_has_fgd2seg"              , &HMNT_has_fgd2seg           , "HMNT_has_fgd2seg/I");
  foutb_HMNT_fgd2_pull_mu_SigTest              = fDefaultOut_SigTest->Branch("HMNT_fgd2_pull_mu"             , &HMNT_fgd2_pull_mu          , "HMNT_fgd2_pull_mu/F");
  foutb_HMNT_fgd2_pull_p_SigTest               = fDefaultOut_SigTest->Branch("HMNT_fgd2_pull_p"              , &HMNT_fgd2_pull_p           , "HMNT_fgd2_pull_p/F");
  foutb_HMNT_fgd2_pull_pi_SigTest              = fDefaultOut_SigTest->Branch("HMNT_fgd2_pull_pi"             , &HMNT_fgd2_pull_pi          , "HMNT_fgd2_pull_pi/F");
  foutb_HMNT_fgd2_pull_no_SigTest              = fDefaultOut_SigTest->Branch("HMNT_fgd2_pull_no"             , &HMNT_fgd2_pull_no          , "HMNT_fgd2_pull_no/F");
   
  // ----------- Background training tree -----------
   
  fDefaultOut_BkgTrain = new TTree("BackgroundTraining", "");

  foutb_evt_BkgTrain                            = fDefaultOut_BkgTrain->Branch("evt"                            , &evt                         , "evt/I");
  foutb_topology_BkgTrain                        = fDefaultOut_BkgTrain->Branch("topology"                       , &topology                    , "topology/I");
  foutb_particle_BkgTrain                        = fDefaultOut_BkgTrain->Branch("particle"                       , &particle                    , "particle/I");
  foutb_ntpcposQualityFV_BkgTrain             = fDefaultOut_BkgTrain->Branch("ntpcposQualityFV"               , &ntpcposQualityFV            , "ntpcposQualityFV/I");
  foutb_ntpcnegQualityFV_BkgTrain             = fDefaultOut_BkgTrain->Branch("ntpcnegQualityFV"               , &ntpcnegQualityFV            , "ntpcnegQualityFV/I");
  
  foutb_selmu_necals_BkgTrain                    = fDefaultOut_BkgTrain->Branch("selmu_necals"                   , &selmu_necals                , "selmu_necals/I");
  foutb_selmu_ecal_mippion_BkgTrain              = fDefaultOut_BkgTrain->Branch("selmu_ecal_mippion"             , &selmu_ecal_mippion          , "selmu_ecal_mippion/F");
  foutb_selmu_ecal_EMenergy_BkgTrain             = fDefaultOut_BkgTrain->Branch("selmu_ecal_EMenergy"            , &selmu_ecal_EMenergy         , "selmu_ecal_EMenergy/F");
  foutb_selmu_ecal_length_BkgTrain               = fDefaultOut_BkgTrain->Branch("selmu_ecal_length"              , &selmu_ecal_length           , "selmu_ecal_length/F");
  foutb_selmu_ecal_EoverL_BkgTrain               = fDefaultOut_BkgTrain->Branch("selmu_ecal_EoverL"              , &selmu_ecal_EoverL           , "selmu_ecal_EoverL/F");
  foutb_selmu_ecal_avg_mippion_BkgTrain       = fDefaultOut_BkgTrain->Branch("selmu_ecal_avg_mippion"         , &selmu_ecal_avg_mippion      , "selmu_ecal_avg_mippion/F");
  foutb_selmu_ecal_avg_EbyL_BkgTrain             = fDefaultOut_BkgTrain->Branch("selmu_ecal_avg_EbyL"            , &selmu_ecal_avg_EbyL         , "selmu_ecal_avg_EbyL/F");
   
  foutb_selmu_tpc_like_mu_BkgTrain               = fDefaultOut_BkgTrain->Branch("selmu_tpc_like_mu"              , &selmu_tpc_like_mu           , "selmu_tpc_like_mu/F");
  foutb_selmu_tpc_like_e_BkgTrain             = fDefaultOut_BkgTrain->Branch("selmu_tpc_like_e"               , &selmu_tpc_like_e            , "selmu_tpc_like_e/F");
  foutb_selmu_tpc_like_p_BkgTrain             = fDefaultOut_BkgTrain->Branch("selmu_tpc_like_p"               , &selmu_tpc_like_p            , "selmu_tpc_like_p/F");
  foutb_selmu_tpc_like_pi_BkgTrain               = fDefaultOut_BkgTrain->Branch("selmu_tpc_like_pi"              , &selmu_tpc_like_pi           , "selmu_tpc_like_pi/F");
   
  foutb_selmu_has_fgd1seg_BkgTrain            = fDefaultOut_BkgTrain->Branch("selmu_has_fgd1seg"              , &selmu_has_fgd1seg           , "selmu_has_fgd1seg/I");
  foutb_selmu_fgd1_pull_mu_BkgTrain              = fDefaultOut_BkgTrain->Branch("selmu_fgd1_pull_mu"             , &selmu_fgd1_pull_mu          , "selmu_fgd1_pull_mu/F");
  foutb_selmu_fgd1_pull_p_BkgTrain               = fDefaultOut_BkgTrain->Branch("selmu_fgd1_pull_p"              , &selmu_fgd1_pull_p           , "selmu_fgd1_pull_p/F");
  foutb_selmu_fgd1_pull_pi_BkgTrain              = fDefaultOut_BkgTrain->Branch("selmu_fgd1_pull_pi"             , &selmu_fgd1_pull_pi          , "selmu_fgd1_pull_pi/F");
  foutb_selmu_fgd1_pull_no_BkgTrain              = fDefaultOut_BkgTrain->Branch("selmu_fgd1_pull_no"             , &selmu_fgd1_pull_no          , "selmu_fgd1_pull_no/F");
   
  foutb_selmu_has_fgd2seg_BkgTrain            = fDefaultOut_BkgTrain->Branch("selmu_has_fgd2seg"              , &selmu_has_fgd2seg           , "selmu_has_fgd2seg/I");
  foutb_selmu_fgd2_pull_mu_BkgTrain              = fDefaultOut_BkgTrain->Branch("selmu_fgd2_pull_mu"             , &selmu_fgd2_pull_mu          , "selmu_fgd2_pull_mu/F");
  foutb_selmu_fgd2_pull_p_BkgTrain               = fDefaultOut_BkgTrain->Branch("selmu_fgd2_pull_p"              , &selmu_fgd2_pull_p           , "selmu_fgd2_pull_p/F");
  foutb_selmu_fgd2_pull_pi_BkgTrain              = fDefaultOut_BkgTrain->Branch("selmu_fgd2_pull_pi"             , &selmu_fgd2_pull_pi          , "selmu_fgd2_pull_pi/F");
  foutb_selmu_fgd2_pull_no_BkgTrain              = fDefaultOut_BkgTrain->Branch("selmu_fgd2_pull_no"             , &selmu_fgd2_pull_no          , "selmu_fgd2_pull_no/F");
  
  foutb_HMNT_NEcalSegments_BkgTrain           = fDefaultOut_BkgTrain->Branch("HMNT_NEcalSegments"             , &HMNT_NEcalSegments          , "HMNT_NEcalsSegments/I");
  foutb_HMNT_ecal_mippion_BkgTrain            = fDefaultOut_BkgTrain->Branch("HMNT_ecal_mippion"              , &HMNT_ecal_mippion           , "HMNT_ecal_mippion/F");
  foutb_HMNT_ecal_EMenergy_BkgTrain              = fDefaultOut_BkgTrain->Branch("HMNT_ecal_EMenergy"             , &HMNT_ecal_EMenergy             , "HMNT_ecal_EMenergy/F");
  foutb_HMNT_ecal_length_BkgTrain             = fDefaultOut_BkgTrain->Branch("HMNT_ecal_length"               , &HMNT_ecal_length            , "HMNT_ecal_length/F");
  foutb_HMNT_ecal_EoverL_BkgTrain             = fDefaultOut_BkgTrain->Branch("HMNT_ecal_EoverL"               , &HMNT_ecal_EoverL            , "HMNT_ecal_EoverL/F");
  foutb_HMNT_ecal_avg_mippion_BkgTrain       = fDefaultOut_BkgTrain->Branch("HMNT_ecal_avg_mippion"         , &HMNT_ecal_avg_mippion        , "HMNT_ecal_avg_mippion/F");
  foutb_HMNT_ecal_avg_EbyL_BkgTrain             = fDefaultOut_BkgTrain->Branch("HMNT_ecal_avg_EbyL"            , &HMNT_ecal_avg_EbyL         , "HMNT_ecal_avg_EbyL/F");
   
  foutb_HMNT_tpc_like_mu_BkgTrain               = fDefaultOut_BkgTrain->Branch("HMNT_tpc_like_mu"              , &HMNT_tpc_like_mu           , "HMNT_tpc_like_mu/F");
  foutb_HMNT_tpc_like_e_BkgTrain             = fDefaultOut_BkgTrain->Branch("HMNT_tpc_like_e"               , &HMNT_tpc_like_e            , "HMNT_tpc_like_e/F");
  foutb_HMNT_tpc_like_p_BkgTrain             = fDefaultOut_BkgTrain->Branch("HMNT_tpc_like_p"               , &HMNT_tpc_like_p            , "HMNT_tpc_like_p/F");
  foutb_HMNT_tpc_like_pi_BkgTrain               = fDefaultOut_BkgTrain->Branch("HMNT_tpc_like_pi"              , &HMNT_tpc_like_pi           , "HMNT_tpc_like_pi/F");
   
  foutb_HMNT_has_fgd1seg_BkgTrain            = fDefaultOut_BkgTrain->Branch("HMNT_has_fgd1seg"              , &HMNT_has_fgd1seg           , "HMNT_has_fgd1seg/I");
  foutb_HMNT_fgd1_pull_mu_BkgTrain              = fDefaultOut_BkgTrain->Branch("HMNT_fgd1_pull_mu"             , &HMNT_fgd1_pull_mu          , "HMNT_fgd1_pull_mu/F");
  foutb_HMNT_fgd1_pull_p_BkgTrain               = fDefaultOut_BkgTrain->Branch("HMNT_fgd1_pull_p"              , &HMNT_fgd1_pull_p           , "HMNT_fgd1_pull_p/F");
  foutb_HMNT_fgd1_pull_pi_BkgTrain              = fDefaultOut_BkgTrain->Branch("HMNT_fgd1_pull_pi"             , &HMNT_fgd1_pull_pi          , "HMNT_fgd1_pull_pi/F");
  foutb_HMNT_fgd1_pull_no_BkgTrain              = fDefaultOut_BkgTrain->Branch("HMNT_fgd1_pull_no"             , &HMNT_fgd1_pull_no          , "HMNT_fgd1_pull_no/F");
   
  foutb_HMNT_has_fgd2seg_BkgTrain            = fDefaultOut_BkgTrain->Branch("HMNT_has_fgd2seg"              , &HMNT_has_fgd2seg           , "HMNT_has_fgd2seg/I");
  foutb_HMNT_fgd2_pull_mu_BkgTrain              = fDefaultOut_BkgTrain->Branch("HMNT_fgd2_pull_mu"             , &HMNT_fgd2_pull_mu          , "HMNT_fgd2_pull_mu/F");
  foutb_HMNT_fgd2_pull_p_BkgTrain               = fDefaultOut_BkgTrain->Branch("HMNT_fgd2_pull_p"              , &HMNT_fgd2_pull_p           , "HMNT_fgd2_pull_p/F");
  foutb_HMNT_fgd2_pull_pi_BkgTrain              = fDefaultOut_BkgTrain->Branch("HMNT_fgd2_pull_pi"             , &HMNT_fgd2_pull_pi          , "HMNT_fgd2_pull_pi/F");
  foutb_HMNT_fgd2_pull_no_BkgTrain              = fDefaultOut_BkgTrain->Branch("HMNT_fgd2_pull_no"             , &HMNT_fgd2_pull_no          , "HMNT_fgd2_pull_no/F");
   
  // ----------- Background testing tree -----------
   
  fDefaultOut_BkgTest = new TTree("BackgroundTesting", "");

  foutb_evt_BkgTest                            = fDefaultOut_BkgTest->Branch("evt"                            , &evt                         , "evt/I");
  foutb_topology_BkgTest                        = fDefaultOut_BkgTest->Branch("topology"                       , &topology                    , "topology/I");
  foutb_particle_BkgTest                        = fDefaultOut_BkgTest->Branch("particle"                       , &particle                    , "particle/I");
  foutb_ntpcposQualityFV_BkgTest             = fDefaultOut_BkgTest->Branch("ntpcposQualityFV"               , &ntpcposQualityFV            , "ntpcposQualityFV/I");
  foutb_ntpcnegQualityFV_BkgTest             = fDefaultOut_BkgTest->Branch("ntpcnegQualityFV"               , &ntpcnegQualityFV            , "ntpcnegQualityFV/I");
  
  foutb_selmu_necals_BkgTest                    = fDefaultOut_BkgTest->Branch("selmu_necals"                   , &selmu_necals                , "selmu_necals/I");
  foutb_selmu_ecal_mippion_BkgTest              = fDefaultOut_BkgTest->Branch("selmu_ecal_mippion"             , &selmu_ecal_mippion          , "selmu_ecal_mippion/F");
  foutb_selmu_ecal_EMenergy_BkgTest             = fDefaultOut_BkgTest->Branch("selmu_ecal_EMenergy"            , &selmu_ecal_EMenergy         , "selmu_ecal_EMenergy/F");
  foutb_selmu_ecal_length_BkgTest               = fDefaultOut_BkgTest->Branch("selmu_ecal_length"              , &selmu_ecal_length           , "selmu_ecal_length/F");
  foutb_selmu_ecal_EoverL_BkgTest               = fDefaultOut_BkgTest->Branch("selmu_ecal_EoverL"              , &selmu_ecal_EoverL           , "selmu_ecal_EoverL/F");
  foutb_selmu_ecal_avg_mippion_BkgTest       = fDefaultOut_BkgTest->Branch("selmu_ecal_avg_mippion"         , &selmu_ecal_avg_mippion      , "selmu_ecal_avg_mippion/F");
  foutb_selmu_ecal_avg_EbyL_BkgTest             = fDefaultOut_BkgTest->Branch("selmu_ecal_avg_EbyL"            , &selmu_ecal_avg_EbyL         , "selmu_ecal_avg_EbyL/F");
   
  foutb_selmu_tpc_like_mu_BkgTest               = fDefaultOut_BkgTest->Branch("selmu_tpc_like_mu"              , &selmu_tpc_like_mu           , "selmu_tpc_like_mu/F");
  foutb_selmu_tpc_like_e_BkgTest             = fDefaultOut_BkgTest->Branch("selmu_tpc_like_e"               , &selmu_tpc_like_e            , "selmu_tpc_like_e/F");
  foutb_selmu_tpc_like_p_BkgTest             = fDefaultOut_BkgTest->Branch("selmu_tpc_like_p"               , &selmu_tpc_like_p            , "selmu_tpc_like_p/F");
  foutb_selmu_tpc_like_pi_BkgTest               = fDefaultOut_BkgTest->Branch("selmu_tpc_like_pi"              , &selmu_tpc_like_pi           , "selmu_tpc_like_pi/F");
   
  foutb_selmu_has_fgd1seg_BkgTest            = fDefaultOut_BkgTest->Branch("selmu_has_fgd1seg"              , &selmu_has_fgd1seg           , "selmu_has_fgd1seg/I");
  foutb_selmu_fgd1_pull_mu_BkgTest              = fDefaultOut_BkgTest->Branch("selmu_fgd1_pull_mu"             , &selmu_fgd1_pull_mu          , "selmu_fgd1_pull_mu/F");
  foutb_selmu_fgd1_pull_p_BkgTest               = fDefaultOut_BkgTest->Branch("selmu_fgd1_pull_p"              , &selmu_fgd1_pull_p           , "selmu_fgd1_pull_p/F");
  foutb_selmu_fgd1_pull_pi_BkgTest              = fDefaultOut_BkgTest->Branch("selmu_fgd1_pull_pi"             , &selmu_fgd1_pull_pi          , "selmu_fgd1_pull_pi/F");
  foutb_selmu_fgd1_pull_no_BkgTest              = fDefaultOut_BkgTest->Branch("selmu_fgd1_pull_no"             , &selmu_fgd1_pull_no          , "selmu_fgd1_pull_no/F");
   
  foutb_selmu_has_fgd2seg_BkgTest            = fDefaultOut_BkgTest->Branch("selmu_has_fgd2seg"              , &selmu_has_fgd2seg           , "selmu_has_fgd2seg/I");
  foutb_selmu_fgd2_pull_mu_BkgTest              = fDefaultOut_BkgTest->Branch("selmu_fgd2_pull_mu"             , &selmu_fgd2_pull_mu          , "selmu_fgd2_pull_mu/F");
  foutb_selmu_fgd2_pull_p_BkgTest               = fDefaultOut_BkgTest->Branch("selmu_fgd2_pull_p"              , &selmu_fgd2_pull_p           , "selmu_fgd2_pull_p/F");
  foutb_selmu_fgd2_pull_pi_BkgTest              = fDefaultOut_BkgTest->Branch("selmu_fgd2_pull_pi"             , &selmu_fgd2_pull_pi          , "selmu_fgd2_pull_pi/F");
  foutb_selmu_fgd2_pull_no_BkgTest              = fDefaultOut_BkgTest->Branch("selmu_fgd2_pull_no"             , &selmu_fgd2_pull_no          , "selmu_fgd2_pull_no/F");
  
  foutb_HMNT_NEcalSegments_BkgTest           = fDefaultOut_BkgTest->Branch("HMNT_NEcalSegments"             , &HMNT_NEcalSegments          , "HMNT_NEcalsSegments/I");
  foutb_HMNT_ecal_mippion_BkgTest            = fDefaultOut_BkgTest->Branch("HMNT_ecal_mippion"              , &HMNT_ecal_mippion           , "HMNT_ecal_mippion/F");
  foutb_HMNT_ecal_EMenergy_BkgTest              = fDefaultOut_BkgTest->Branch("HMNT_ecal_EMenergy"             , &HMNT_ecal_EMenergy             , "HMNT_ecal_EMenergy/F");
  foutb_HMNT_ecal_length_BkgTest             = fDefaultOut_BkgTest->Branch("HMNT_ecal_length"               , &HMNT_ecal_length            , "HMNT_ecal_length/F");
  foutb_HMNT_ecal_EoverL_BkgTest             = fDefaultOut_BkgTest->Branch("HMNT_ecal_EoverL"               , &HMNT_ecal_EoverL            , "HMNT_ecal_EoverL/F");
  foutb_HMNT_ecal_avg_mippion_BkgTest       = fDefaultOut_BkgTest->Branch("HMNT_ecal_avg_mippion"         , &HMNT_ecal_avg_mippion        , "HMNT_ecal_avg_mippion/F");
  foutb_HMNT_ecal_avg_EbyL_BkgTest             = fDefaultOut_BkgTest->Branch("HMNT_ecal_avg_EbyL"            , &HMNT_ecal_avg_EbyL         , "HMNT_ecal_avg_EbyL/F");
   
  foutb_HMNT_tpc_like_mu_BkgTest               = fDefaultOut_BkgTest->Branch("HMNT_tpc_like_mu"              , &HMNT_tpc_like_mu           , "HMNT_tpc_like_mu/F");
  foutb_HMNT_tpc_like_e_BkgTest             = fDefaultOut_BkgTest->Branch("HMNT_tpc_like_e"               , &HMNT_tpc_like_e            , "HMNT_tpc_like_e/F");
  foutb_HMNT_tpc_like_p_BkgTest             = fDefaultOut_BkgTest->Branch("HMNT_tpc_like_p"               , &HMNT_tpc_like_p            , "HMNT_tpc_like_p/F");
  foutb_HMNT_tpc_like_pi_BkgTest               = fDefaultOut_BkgTest->Branch("HMNT_tpc_like_pi"              , &HMNT_tpc_like_pi           , "HMNT_tpc_like_pi/F");
   
  foutb_HMNT_has_fgd1seg_BkgTest            = fDefaultOut_BkgTest->Branch("HMNT_has_fgd1seg"              , &HMNT_has_fgd1seg           , "HMNT_has_fgd1seg/I");
  foutb_HMNT_fgd1_pull_mu_BkgTest              = fDefaultOut_BkgTest->Branch("HMNT_fgd1_pull_mu"             , &HMNT_fgd1_pull_mu          , "HMNT_fgd1_pull_mu/F");
  foutb_HMNT_fgd1_pull_p_BkgTest               = fDefaultOut_BkgTest->Branch("HMNT_fgd1_pull_p"              , &HMNT_fgd1_pull_p           , "HMNT_fgd1_pull_p/F");
  foutb_HMNT_fgd1_pull_pi_BkgTest              = fDefaultOut_BkgTest->Branch("HMNT_fgd1_pull_pi"             , &HMNT_fgd1_pull_pi          , "HMNT_fgd1_pull_pi/F");
  foutb_HMNT_fgd1_pull_no_BkgTest              = fDefaultOut_BkgTest->Branch("HMNT_fgd1_pull_no"             , &HMNT_fgd1_pull_no          , "HMNT_fgd1_pull_no/F");
   
  foutb_HMNT_has_fgd2seg_BkgTest            = fDefaultOut_BkgTest->Branch("HMNT_has_fgd2seg"              , &HMNT_has_fgd2seg           , "HMNT_has_fgd2seg/I");
  foutb_HMNT_fgd2_pull_mu_BkgTest              = fDefaultOut_BkgTest->Branch("HMNT_fgd2_pull_mu"             , &HMNT_fgd2_pull_mu          , "HMNT_fgd2_pull_mu/F");
  foutb_HMNT_fgd2_pull_p_BkgTest               = fDefaultOut_BkgTest->Branch("HMNT_fgd2_pull_p"              , &HMNT_fgd2_pull_p           , "HMNT_fgd2_pull_p/F");
  foutb_HMNT_fgd2_pull_pi_BkgTest              = fDefaultOut_BkgTest->Branch("HMNT_fgd2_pull_pi"             , &HMNT_fgd2_pull_pi          , "HMNT_fgd2_pull_pi/F");
  foutb_HMNT_fgd2_pull_no_BkgTest              = fDefaultOut_BkgTest->Branch("HMNT_fgd2_pull_no"             , &HMNT_fgd2_pull_no          , "HMNT_fgd2_pull_no/F");
   
  return;
}
