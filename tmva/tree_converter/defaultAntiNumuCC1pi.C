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
          if (accum_level[0][1] <= 4) continue; // Set accum_level
          if (selmu_mom[0] > 10000.0) continue;
          if (HMNT_mom > 10000.0) continue;
             
            defout->evt    		                  = evt;
            defout->topology		                  = topology;
            defout->particle		                  = particle;
            defout->ntpcposQualityFV               = ntpcposQualityFV;
            defout->ntpcnegQualityFV               = ntpcnegQualityFV;
            defout->NME    		                  = NME;
            defout->NFGDPi    		               = NFGDPi;
            defout->NPi0El    		               = NPi0El;
            defout->NPi0Pos    		               = NPi0Pos;
         
            defout->selmu_mom    		            = selmu_mom[0];
         
            defout->selmu_necals                   = selmu_necals;
            if (selmu_ecal_bestseg_EMenergy > 0.0)
            {
              defout->selmu_ecal_bestseg_EMenergy    = selmu_ecal_bestseg_EMenergy;
              defout->selmu_ecal_bestseg_mippion     = selmu_ecal_bestseg_mippion;
              defout->selmu_ecal_bestseg_EbyL        = selmu_ecal_bestseg_EbyL;
              defout->selmu_ecal_bestseg_EbyP        = selmu_ecal_bestseg_EMenergy/selmu_mom[0];
            }
            else
            {
              defout->selmu_ecal_bestseg_EMenergy    = -100.0;
              defout->selmu_ecal_bestseg_mippion     = -100.0;
              defout->selmu_ecal_bestseg_EbyL        = -1.0;
              defout->selmu_ecal_bestseg_EbyP        = -1.0;
            }
         
            defout->selmu_tpc_like_mu              = selmu_tpc_like_mu;
            defout->selmu_tpc_like_e               = selmu_tpc_like_e;
            defout->selmu_tpc_like_p               = selmu_tpc_like_p;
            defout->selmu_tpc_like_pi              = selmu_tpc_like_pi;
         
            defout->selmu_has_fgd1seg              = selmu_has_fgd1seg;
            if (selmu_fgd1_pull_mu > -30.0 && selmu_fgd1_pull_mu < 60.0)  {defout->selmu_fgd1_pull_mu = selmu_fgd1_pull_mu;}
            else                                                          {defout->selmu_fgd1_pull_mu = -30.0;}
            if (selmu_fgd1_pull_p > -30.0  && selmu_fgd1_pull_p < 60.0)   {defout->selmu_fgd1_pull_p  = selmu_fgd1_pull_p;}
            else                                                          {defout->selmu_fgd1_pull_p  = -30.0;}
            if (selmu_fgd1_pull_pi > -30.0 && selmu_fgd1_pull_pi < 60.0)  {defout->selmu_fgd1_pull_pi = selmu_fgd1_pull_pi;}
            else                                                          {defout->selmu_fgd1_pull_pi = -30.0;}
            if (selmu_fgd1_pull_no > -30.0)                               {defout->selmu_fgd1_pull_no = selmu_fgd1_pull_no;}
            else                                                          {defout->selmu_fgd1_pull_no = -30.0;}
            
         
            defout->selmu_has_fgd2seg              = selmu_has_fgd2seg;
            if (selmu_fgd2_pull_mu > -30.0 && selmu_fgd2_pull_mu < 60.0)  {defout->selmu_fgd2_pull_mu = selmu_fgd2_pull_mu;}
            else                                                          {defout->selmu_fgd2_pull_mu = -30.0;}
            if (selmu_fgd2_pull_p > -30.0  && selmu_fgd2_pull_p < 60.0)   {defout->selmu_fgd2_pull_p  = selmu_fgd2_pull_p;}
            else                                                          {defout->selmu_fgd2_pull_p  = -30.0;}
            if (selmu_fgd2_pull_pi > -30.0 && selmu_fgd2_pull_pi < 60.0)  {defout->selmu_fgd2_pull_pi = selmu_fgd2_pull_pi;}
            else                                                          {defout->selmu_fgd2_pull_pi = -30.0;}
            if (selmu_fgd2_pull_no > -30.0)                               {defout->selmu_fgd2_pull_no = selmu_fgd2_pull_no;}
            else                                                          {defout->selmu_fgd2_pull_no = -30.0;}
         
            defout->HMNT_mom      		            = HMNT_mom;
            
            defout->HMNT_NEcalSegments		         = HMNT_NEcalSegments;
            if (HMNT_ecal_bestseg_EMenergy > 0.0)
            {
              defout->HMNT_ecal_bestseg_EMenergy    = HMNT_ecal_bestseg_EMenergy;
              defout->HMNT_ecal_bestseg_mippion     = HMNT_ecal_bestseg_mippion;
              defout->HMNT_ecal_bestseg_EbyL        = HMNT_ecal_bestseg_EbyL;
              defout->HMNT_ecal_bestseg_EbyP        = HMNT_ecal_bestseg_EMenergy/HMNT_mom;
            }
            else
            {
              defout->HMNT_ecal_bestseg_EMenergy    = -100.0;
              defout->HMNT_ecal_bestseg_mippion     = -100.0;
              defout->HMNT_ecal_bestseg_EbyL        = -1.0;
              defout->HMNT_ecal_bestseg_EbyP        = -1.0;
            }
         
            defout->HMNT_tpc_like_mu              = HMNT_tpc_like_mu;
            defout->HMNT_tpc_like_e               = HMNT_tpc_like_e;
            defout->HMNT_tpc_like_p               = HMNT_tpc_like_p;
            defout->HMNT_tpc_like_pi              = HMNT_tpc_like_pi;
         
            defout->HMNT_has_fgd1seg              = HMNT_has_fgd1seg;
            if (HMNT_fgd1_pull_mu > -30.0 && HMNT_fgd1_pull_mu < 60.0)  {defout->HMNT_fgd1_pull_mu = HMNT_fgd1_pull_mu;}
            else                                                        {defout->HMNT_fgd1_pull_mu = -30.0;}
            if (HMNT_fgd1_pull_p > -30.0  && HMNT_fgd1_pull_p < 60.0)   {defout->HMNT_fgd1_pull_p  = HMNT_fgd1_pull_p;}
            else                                                        {defout->HMNT_fgd1_pull_p  = -30.0;}
            if (HMNT_fgd1_pull_pi > -30.0 && HMNT_fgd1_pull_pi < 60.0)  {defout->HMNT_fgd1_pull_pi = HMNT_fgd1_pull_pi;}
            else                                                        {defout->HMNT_fgd1_pull_pi = -30.0;}
            if (HMNT_fgd1_pull_no > -30.0)                              {defout->HMNT_fgd1_pull_no = HMNT_fgd1_pull_no;}
            else                                                        {defout->HMNT_fgd1_pull_no = -30.0;}
         
            defout->HMNT_has_fgd2seg              = HMNT_has_fgd2seg;
            if (HMNT_fgd2_pull_mu > -30.0 && HMNT_fgd2_pull_mu < 60.0)  {defout->HMNT_fgd2_pull_mu = HMNT_fgd2_pull_mu;}
            else                                                        {defout->HMNT_fgd2_pull_mu = -30.0;}
            if (HMNT_fgd2_pull_p > -30.0  && HMNT_fgd2_pull_p < 60.0)   {defout->HMNT_fgd2_pull_p  = HMNT_fgd2_pull_p;}
            else                                                        {defout->HMNT_fgd2_pull_p  = -30.0;}
            if (HMNT_fgd2_pull_pi > -30.0 && HMNT_fgd2_pull_pi < 60.0)  {defout->HMNT_fgd2_pull_pi = HMNT_fgd2_pull_pi;}
            else                                                        {defout->HMNT_fgd2_pull_pi = -30.0;}
            if (HMNT_fgd2_pull_no > -30.0)                              {defout->HMNT_fgd2_pull_no = HMNT_fgd2_pull_no;}
            else                                                        {defout->HMNT_fgd2_pull_no = -30.0;}
         
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
  foutb_NME_SigTrain 	                      = fDefaultOut_SigTrain->Branch("NME"                            , &NME 	                     , "NME/I");
  foutb_NFGDPi_SigTrain 	                   = fDefaultOut_SigTrain->Branch("NFGDPi"                         , &NFGDPi 	                  , "NFGDPi/I");
  foutb_NPi0El_SigTrain 	                   = fDefaultOut_SigTrain->Branch("NPi0El"                         , &NPi0El 	                  , "NPi0El/I");
  foutb_NPi0Pos_SigTrain 	                   = fDefaultOut_SigTrain->Branch("NPi0Pos"                        , &NPi0Pos 	                  , "NPi0Pos/I");
   
  foutb_selmu_mom_SigTrain 	                = fDefaultOut_SigTrain->Branch("selmu_mom"                      , &selmu_mom 	               , "selmu_mom/F");
  
  foutb_selmu_necals_SigTrain 	             = fDefaultOut_SigTrain->Branch("selmu_necals"                   , &selmu_necals       	      , "selmu_necals/I");
  foutb_selmu_ecal_bestseg_EMenergy_SigTrain  = fDefaultOut_SigTrain->Branch("selmu_ecal_bestseg_EMenergy"    , &selmu_ecal_bestseg_EMenergy , "selmu_ecal_bestseg_EMenergy/F");
  foutb_selmu_ecal_bestseg_mippion_SigTrain   = fDefaultOut_SigTrain->Branch("selmu_ecal_bestseg_mippion"     , &selmu_ecal_bestseg_mippion  , "selmu_ecal_bestseg_mippion/F");
  foutb_selmu_ecal_bestseg_EbyL_SigTrain      = fDefaultOut_SigTrain->Branch("selmu_ecal_bestseg_EbyL"        , &selmu_ecal_bestseg_EbyL     , "selmu_ecal_bestseg_EbyL/F");
  foutb_selmu_ecal_bestseg_EbyP_SigTrain      = fDefaultOut_SigTrain->Branch("selmu_ecal_bestseg_EbyP"        , &selmu_ecal_bestseg_EbyP     , "selmu_ecal_bestseg_EbyP/F");
   
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
   
  foutb_HMNT_mom_SigTrain 	                   = fDefaultOut_SigTrain->Branch("HMNT_mom"                       , &HMNT_mom 	                  , "HMNT_mom/F");
  
  foutb_HMNT_NEcalSegments_SigTrain	          = fDefaultOut_SigTrain->Branch("HMNT_NEcalSegments"             , &HMNT_NEcalSegments	         , "HMNT_NEcalsSegments/I");
  foutb_HMNT_ecal_bestseg_EMenergy_SigTrain   = fDefaultOut_SigTrain->Branch("HMNT_ecal_bestseg_EMenergy"     , &HMNT_ecal_bestseg_EMenergy  , "HMNT_ecal_bestseg_EMenergy/F");
  foutb_HMNT_ecal_bestseg_mippion_SigTrain   = fDefaultOut_SigTrain->Branch("HMNT_ecal_bestseg_mippion"     , &HMNT_ecal_bestseg_mippion  , "HMNT_ecal_bestseg_mippion/F");
  foutb_HMNT_ecal_bestseg_EbyL_SigTrain      = fDefaultOut_SigTrain->Branch("HMNT_ecal_bestseg_EbyL"        , &HMNT_ecal_bestseg_EbyL     , "HMNT_ecal_bestseg_EbyL/F");
  foutb_HMNT_ecal_bestseg_EbyP_SigTrain      = fDefaultOut_SigTrain->Branch("HMNT_ecal_bestseg_EbyP"        , &HMNT_ecal_bestseg_EbyP     , "HMNT_ecal_bestseg_EbyP/F");
   
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

  foutb_evt_SigTest                        = fDefaultOut_SigTest->Branch("evt"                            , &evt                       , "evt/I");
  foutb_topology_SigTest                      = fDefaultOut_SigTest->Branch("topology"                       , &topology                    , "topology/I");
  foutb_particle_SigTest                      = fDefaultOut_SigTest->Branch("particle"                       , &particle                    , "particle/I");
  foutb_ntpcposQualityFV_SigTest             = fDefaultOut_SigTest->Branch("ntpcposQualityFV"               , &ntpcposQualityFV            , "ntpcposQualityFV/I");
  foutb_ntpcnegQualityFV_SigTest             = fDefaultOut_SigTest->Branch("ntpcnegQualityFV"               , &ntpcnegQualityFV            , "ntpcnegQualityFV/I");
  foutb_NME_SigTest                        = fDefaultOut_SigTest->Branch("NME"                            , &NME                       , "NME/I");
  foutb_NFGDPi_SigTest                      = fDefaultOut_SigTest->Branch("NFGDPi"                         , &NFGDPi                    , "NFGDPi/I");
  foutb_NPi0El_SigTest                      = fDefaultOut_SigTest->Branch("NPi0El"                         , &NPi0El                    , "NPi0El/I");
  foutb_NPi0Pos_SigTest                     = fDefaultOut_SigTest->Branch("NPi0Pos"                        , &NPi0Pos                     , "NPi0Pos/I");
   
  foutb_selmu_mom_SigTest                  = fDefaultOut_SigTest->Branch("selmu_mom"                      , &selmu_mom                 , "selmu_mom/F");
  
  foutb_selmu_necals_SigTest                = fDefaultOut_SigTest->Branch("selmu_necals"                   , &selmu_necals              , "selmu_necals/I");
  foutb_selmu_ecal_bestseg_EMenergy_SigTest  = fDefaultOut_SigTest->Branch("selmu_ecal_bestseg_EMenergy"    , &selmu_ecal_bestseg_EMenergy , "selmu_ecal_bestseg_EMenergy/F");
  foutb_selmu_ecal_bestseg_mippion_SigTest   = fDefaultOut_SigTest->Branch("selmu_ecal_bestseg_mippion"     , &selmu_ecal_bestseg_mippion  , "selmu_ecal_bestseg_mippion/F");
  foutb_selmu_ecal_bestseg_EbyL_SigTest      = fDefaultOut_SigTest->Branch("selmu_ecal_bestseg_EbyL"        , &selmu_ecal_bestseg_EbyL     , "selmu_ecal_bestseg_EbyL/F");
  foutb_selmu_ecal_bestseg_EbyP_SigTest      = fDefaultOut_SigTest->Branch("selmu_ecal_bestseg_EbyP"        , &selmu_ecal_bestseg_EbyP     , "selmu_ecal_bestseg_EbyP/F");
   
  foutb_selmu_tpc_like_mu_SigTest           = fDefaultOut_SigTest->Branch("selmu_tpc_like_mu"              , &selmu_tpc_like_mu         , "selmu_tpc_like_mu/F");
  foutb_selmu_tpc_like_e_SigTest             = fDefaultOut_SigTest->Branch("selmu_tpc_like_e"               , &selmu_tpc_like_e            , "selmu_tpc_like_e/F");
  foutb_selmu_tpc_like_p_SigTest             = fDefaultOut_SigTest->Branch("selmu_tpc_like_p"               , &selmu_tpc_like_p            , "selmu_tpc_like_p/F");
  foutb_selmu_tpc_like_pi_SigTest           = fDefaultOut_SigTest->Branch("selmu_tpc_like_pi"              , &selmu_tpc_like_pi         , "selmu_tpc_like_pi/F");
   
  foutb_selmu_has_fgd1seg_SigTest            = fDefaultOut_SigTest->Branch("selmu_has_fgd1seg"              , &selmu_has_fgd1seg           , "selmu_has_fgd1seg/I");
  foutb_selmu_fgd1_pull_mu_SigTest          = fDefaultOut_SigTest->Branch("selmu_fgd1_pull_mu"             , &selmu_fgd1_pull_mu          , "selmu_fgd1_pull_mu/F");
  foutb_selmu_fgd1_pull_p_SigTest           = fDefaultOut_SigTest->Branch("selmu_fgd1_pull_p"              , &selmu_fgd1_pull_p         , "selmu_fgd1_pull_p/F");
  foutb_selmu_fgd1_pull_pi_SigTest          = fDefaultOut_SigTest->Branch("selmu_fgd1_pull_pi"             , &selmu_fgd1_pull_pi          , "selmu_fgd1_pull_pi/F");
  foutb_selmu_fgd1_pull_no_SigTest          = fDefaultOut_SigTest->Branch("selmu_fgd1_pull_no"             , &selmu_fgd1_pull_no          , "selmu_fgd1_pull_no/F");
   
  foutb_selmu_has_fgd2seg_SigTest            = fDefaultOut_SigTest->Branch("selmu_has_fgd2seg"              , &selmu_has_fgd2seg           , "selmu_has_fgd2seg/I");
  foutb_selmu_fgd2_pull_mu_SigTest          = fDefaultOut_SigTest->Branch("selmu_fgd2_pull_mu"             , &selmu_fgd2_pull_mu          , "selmu_fgd2_pull_mu/F");
  foutb_selmu_fgd2_pull_p_SigTest           = fDefaultOut_SigTest->Branch("selmu_fgd2_pull_p"              , &selmu_fgd2_pull_p         , "selmu_fgd2_pull_p/F");
  foutb_selmu_fgd2_pull_pi_SigTest          = fDefaultOut_SigTest->Branch("selmu_fgd2_pull_pi"             , &selmu_fgd2_pull_pi          , "selmu_fgd2_pull_pi/F");
  foutb_selmu_fgd2_pull_no_SigTest          = fDefaultOut_SigTest->Branch("selmu_fgd2_pull_no"             , &selmu_fgd2_pull_no          , "selmu_fgd2_pull_no/F");
   
  foutb_HMNT_mom_SigTest                      = fDefaultOut_SigTest->Branch("HMNT_mom"                       , &HMNT_mom                    , "HMNT_mom/F");
  
  foutb_HMNT_NEcalSegments_SigTest           = fDefaultOut_SigTest->Branch("HMNT_NEcalSegments"             , &HMNT_NEcalSegments          , "HMNT_NEcalsSegments/I");
  foutb_HMNT_ecal_bestseg_EMenergy_SigTest   = fDefaultOut_SigTest->Branch("HMNT_ecal_bestseg_EMenergy"     , &HMNT_ecal_bestseg_EMenergy  , "HMNT_ecal_bestseg_EMenergy/F");
  foutb_HMNT_ecal_bestseg_mippion_SigTest   = fDefaultOut_SigTest->Branch("HMNT_ecal_bestseg_mippion"     , &HMNT_ecal_bestseg_mippion  , "HMNT_ecal_bestseg_mippion/F");
  foutb_HMNT_ecal_bestseg_EbyL_SigTest      = fDefaultOut_SigTest->Branch("HMNT_ecal_bestseg_EbyL"        , &HMNT_ecal_bestseg_EbyL     , "HMNT_ecal_bestseg_EbyL/F");
  foutb_HMNT_ecal_bestseg_EbyP_SigTest      = fDefaultOut_SigTest->Branch("HMNT_ecal_bestseg_EbyP"        , &HMNT_ecal_bestseg_EbyP     , "HMNT_ecal_bestseg_EbyP/F");
   
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

  foutb_evt_BkgTrain                        = fDefaultOut_BkgTrain->Branch("evt"                            , &evt                       , "evt/I");
  foutb_topology_BkgTrain                      = fDefaultOut_BkgTrain->Branch("topology"                       , &topology                    , "topology/I");
  foutb_particle_BkgTrain                      = fDefaultOut_BkgTrain->Branch("particle"                       , &particle                    , "particle/I");
  foutb_ntpcposQualityFV_BkgTrain             = fDefaultOut_BkgTrain->Branch("ntpcposQualityFV"               , &ntpcposQualityFV            , "ntpcposQualityFV/I");
  foutb_ntpcnegQualityFV_BkgTrain             = fDefaultOut_BkgTrain->Branch("ntpcnegQualityFV"               , &ntpcnegQualityFV            , "ntpcnegQualityFV/I");
  foutb_NME_BkgTrain                        = fDefaultOut_BkgTrain->Branch("NME"                            , &NME                       , "NME/I");
  foutb_NFGDPi_BkgTrain                      = fDefaultOut_BkgTrain->Branch("NFGDPi"                         , &NFGDPi                    , "NFGDPi/I");
  foutb_NPi0El_BkgTrain                      = fDefaultOut_BkgTrain->Branch("NPi0El"                         , &NPi0El                    , "NPi0El/I");
  foutb_NPi0Pos_BkgTrain                     = fDefaultOut_BkgTrain->Branch("NPi0Pos"                        , &NPi0Pos                     , "NPi0Pos/I");
   
  foutb_selmu_mom_BkgTrain                  = fDefaultOut_BkgTrain->Branch("selmu_mom"                      , &selmu_mom                 , "selmu_mom/F");
  
  foutb_selmu_necals_BkgTrain                = fDefaultOut_BkgTrain->Branch("selmu_necals"                   , &selmu_necals              , "selmu_necals/I");
  foutb_selmu_ecal_bestseg_EMenergy_BkgTrain  = fDefaultOut_BkgTrain->Branch("selmu_ecal_bestseg_EMenergy"    , &selmu_ecal_bestseg_EMenergy , "selmu_ecal_bestseg_EMenergy/F");
  foutb_selmu_ecal_bestseg_mippion_BkgTrain   = fDefaultOut_BkgTrain->Branch("selmu_ecal_bestseg_mippion"     , &selmu_ecal_bestseg_mippion  , "selmu_ecal_bestseg_mippion/F");
  foutb_selmu_ecal_bestseg_EbyL_BkgTrain      = fDefaultOut_BkgTrain->Branch("selmu_ecal_bestseg_EbyL"        , &selmu_ecal_bestseg_EbyL     , "selmu_ecal_bestseg_EbyL/F");
  foutb_selmu_ecal_bestseg_EbyP_BkgTrain      = fDefaultOut_BkgTrain->Branch("selmu_ecal_bestseg_EbyP"        , &selmu_ecal_bestseg_EbyP     , "selmu_ecal_bestseg_EbyP/F");
   
  foutb_selmu_tpc_like_mu_BkgTrain           = fDefaultOut_BkgTrain->Branch("selmu_tpc_like_mu"              , &selmu_tpc_like_mu         , "selmu_tpc_like_mu/F");
  foutb_selmu_tpc_like_e_BkgTrain             = fDefaultOut_BkgTrain->Branch("selmu_tpc_like_e"               , &selmu_tpc_like_e            , "selmu_tpc_like_e/F");
  foutb_selmu_tpc_like_p_BkgTrain             = fDefaultOut_BkgTrain->Branch("selmu_tpc_like_p"               , &selmu_tpc_like_p            , "selmu_tpc_like_p/F");
  foutb_selmu_tpc_like_pi_BkgTrain           = fDefaultOut_BkgTrain->Branch("selmu_tpc_like_pi"              , &selmu_tpc_like_pi         , "selmu_tpc_like_pi/F");
   
  foutb_selmu_has_fgd1seg_BkgTrain            = fDefaultOut_BkgTrain->Branch("selmu_has_fgd1seg"              , &selmu_has_fgd1seg           , "selmu_has_fgd1seg/I");
  foutb_selmu_fgd1_pull_mu_BkgTrain          = fDefaultOut_BkgTrain->Branch("selmu_fgd1_pull_mu"             , &selmu_fgd1_pull_mu          , "selmu_fgd1_pull_mu/F");
  foutb_selmu_fgd1_pull_p_BkgTrain           = fDefaultOut_BkgTrain->Branch("selmu_fgd1_pull_p"              , &selmu_fgd1_pull_p         , "selmu_fgd1_pull_p/F");
  foutb_selmu_fgd1_pull_pi_BkgTrain          = fDefaultOut_BkgTrain->Branch("selmu_fgd1_pull_pi"             , &selmu_fgd1_pull_pi          , "selmu_fgd1_pull_pi/F");
  foutb_selmu_fgd1_pull_no_BkgTrain          = fDefaultOut_BkgTrain->Branch("selmu_fgd1_pull_no"             , &selmu_fgd1_pull_no          , "selmu_fgd1_pull_no/F");
   
  foutb_selmu_has_fgd2seg_BkgTrain            = fDefaultOut_BkgTrain->Branch("selmu_has_fgd2seg"              , &selmu_has_fgd2seg           , "selmu_has_fgd2seg/I");
  foutb_selmu_fgd2_pull_mu_BkgTrain          = fDefaultOut_BkgTrain->Branch("selmu_fgd2_pull_mu"             , &selmu_fgd2_pull_mu          , "selmu_fgd2_pull_mu/F");
  foutb_selmu_fgd2_pull_p_BkgTrain           = fDefaultOut_BkgTrain->Branch("selmu_fgd2_pull_p"              , &selmu_fgd2_pull_p         , "selmu_fgd2_pull_p/F");
  foutb_selmu_fgd2_pull_pi_BkgTrain          = fDefaultOut_BkgTrain->Branch("selmu_fgd2_pull_pi"             , &selmu_fgd2_pull_pi          , "selmu_fgd2_pull_pi/F");
  foutb_selmu_fgd2_pull_no_BkgTrain          = fDefaultOut_BkgTrain->Branch("selmu_fgd2_pull_no"             , &selmu_fgd2_pull_no          , "selmu_fgd2_pull_no/F");
   
  foutb_HMNT_mom_BkgTrain                      = fDefaultOut_BkgTrain->Branch("HMNT_mom"                       , &HMNT_mom                    , "HMNT_mom/F");
  
  foutb_HMNT_NEcalSegments_BkgTrain           = fDefaultOut_BkgTrain->Branch("HMNT_NEcalSegments"             , &HMNT_NEcalSegments          , "HMNT_NEcalsSegments/I");
  foutb_HMNT_ecal_bestseg_EMenergy_BkgTrain   = fDefaultOut_BkgTrain->Branch("HMNT_ecal_bestseg_EMenergy"     , &HMNT_ecal_bestseg_EMenergy  , "HMNT_ecal_bestseg_EMenergy/F");
  foutb_HMNT_ecal_bestseg_mippion_BkgTrain   = fDefaultOut_BkgTrain->Branch("HMNT_ecal_bestseg_mippion"     , &HMNT_ecal_bestseg_mippion  , "HMNT_ecal_bestseg_mippion/F");
  foutb_HMNT_ecal_bestseg_EbyL_BkgTrain      = fDefaultOut_BkgTrain->Branch("HMNT_ecal_bestseg_EbyL"        , &HMNT_ecal_bestseg_EbyL     , "HMNT_ecal_bestseg_EbyL/F");
  foutb_HMNT_ecal_bestseg_EbyP_BkgTrain      = fDefaultOut_BkgTrain->Branch("HMNT_ecal_bestseg_EbyP"        , &HMNT_ecal_bestseg_EbyP     , "HMNT_ecal_bestseg_EbyP/F");
   
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

  foutb_evt_BkgTest                        = fDefaultOut_BkgTest->Branch("evt"                            , &evt                       , "evt/I");
  foutb_topology_BkgTest                      = fDefaultOut_BkgTest->Branch("topology"                       , &topology                    , "topology/I");
  foutb_particle_BkgTest                      = fDefaultOut_BkgTest->Branch("particle"                       , &particle                    , "particle/I");
  foutb_ntpcposQualityFV_BkgTest             = fDefaultOut_BkgTest->Branch("ntpcposQualityFV"               , &ntpcposQualityFV            , "ntpcposQualityFV/I");
  foutb_ntpcnegQualityFV_BkgTest             = fDefaultOut_BkgTest->Branch("ntpcnegQualityFV"               , &ntpcnegQualityFV            , "ntpcnegQualityFV/I");
  foutb_NME_BkgTest                        = fDefaultOut_BkgTest->Branch("NME"                            , &NME                       , "NME/I");
  foutb_NFGDPi_BkgTest                      = fDefaultOut_BkgTest->Branch("NFGDPi"                         , &NFGDPi                    , "NFGDPi/I");
  foutb_NPi0El_BkgTest                      = fDefaultOut_BkgTest->Branch("NPi0El"                         , &NPi0El                    , "NPi0El/I");
  foutb_NPi0Pos_BkgTest                     = fDefaultOut_BkgTest->Branch("NPi0Pos"                        , &NPi0Pos                     , "NPi0Pos/I");
   
  foutb_selmu_mom_BkgTest                  = fDefaultOut_BkgTest->Branch("selmu_mom"                      , &selmu_mom                 , "selmu_mom/F");
  
  foutb_selmu_necals_BkgTest                = fDefaultOut_BkgTest->Branch("selmu_necals"                   , &selmu_necals              , "selmu_necals/I");
  foutb_selmu_ecal_bestseg_EMenergy_BkgTest  = fDefaultOut_BkgTest->Branch("selmu_ecal_bestseg_EMenergy"    , &selmu_ecal_bestseg_EMenergy , "selmu_ecal_bestseg_EMenergy/F");
  foutb_selmu_ecal_bestseg_mippion_BkgTest   = fDefaultOut_BkgTest->Branch("selmu_ecal_bestseg_mippion"     , &selmu_ecal_bestseg_mippion  , "selmu_ecal_bestseg_mippion/F");
  foutb_selmu_ecal_bestseg_EbyL_BkgTest      = fDefaultOut_BkgTest->Branch("selmu_ecal_bestseg_EbyL"        , &selmu_ecal_bestseg_EbyL     , "selmu_ecal_bestseg_EbyL/F");
  foutb_selmu_ecal_bestseg_EbyP_BkgTest      = fDefaultOut_BkgTest->Branch("selmu_ecal_bestseg_EbyP"        , &selmu_ecal_bestseg_EbyP     , "selmu_ecal_bestseg_EbyP/F");
   
  foutb_selmu_tpc_like_mu_BkgTest           = fDefaultOut_BkgTest->Branch("selmu_tpc_like_mu"              , &selmu_tpc_like_mu         , "selmu_tpc_like_mu/F");
  foutb_selmu_tpc_like_e_BkgTest             = fDefaultOut_BkgTest->Branch("selmu_tpc_like_e"               , &selmu_tpc_like_e            , "selmu_tpc_like_e/F");
  foutb_selmu_tpc_like_p_BkgTest             = fDefaultOut_BkgTest->Branch("selmu_tpc_like_p"               , &selmu_tpc_like_p            , "selmu_tpc_like_p/F");
  foutb_selmu_tpc_like_pi_BkgTest           = fDefaultOut_BkgTest->Branch("selmu_tpc_like_pi"              , &selmu_tpc_like_pi         , "selmu_tpc_like_pi/F");
   
  foutb_selmu_has_fgd1seg_BkgTest            = fDefaultOut_BkgTest->Branch("selmu_has_fgd1seg"              , &selmu_has_fgd1seg           , "selmu_has_fgd1seg/I");
  foutb_selmu_fgd1_pull_mu_BkgTest          = fDefaultOut_BkgTest->Branch("selmu_fgd1_pull_mu"             , &selmu_fgd1_pull_mu          , "selmu_fgd1_pull_mu/F");
  foutb_selmu_fgd1_pull_p_BkgTest           = fDefaultOut_BkgTest->Branch("selmu_fgd1_pull_p"              , &selmu_fgd1_pull_p         , "selmu_fgd1_pull_p/F");
  foutb_selmu_fgd1_pull_pi_BkgTest          = fDefaultOut_BkgTest->Branch("selmu_fgd1_pull_pi"             , &selmu_fgd1_pull_pi          , "selmu_fgd1_pull_pi/F");
  foutb_selmu_fgd1_pull_no_BkgTest          = fDefaultOut_BkgTest->Branch("selmu_fgd1_pull_no"             , &selmu_fgd1_pull_no          , "selmu_fgd1_pull_no/F");
   
  foutb_selmu_has_fgd2seg_BkgTest            = fDefaultOut_BkgTest->Branch("selmu_has_fgd2seg"              , &selmu_has_fgd2seg           , "selmu_has_fgd2seg/I");
  foutb_selmu_fgd2_pull_mu_BkgTest          = fDefaultOut_BkgTest->Branch("selmu_fgd2_pull_mu"             , &selmu_fgd2_pull_mu          , "selmu_fgd2_pull_mu/F");
  foutb_selmu_fgd2_pull_p_BkgTest           = fDefaultOut_BkgTest->Branch("selmu_fgd2_pull_p"              , &selmu_fgd2_pull_p         , "selmu_fgd2_pull_p/F");
  foutb_selmu_fgd2_pull_pi_BkgTest          = fDefaultOut_BkgTest->Branch("selmu_fgd2_pull_pi"             , &selmu_fgd2_pull_pi          , "selmu_fgd2_pull_pi/F");
  foutb_selmu_fgd2_pull_no_BkgTest          = fDefaultOut_BkgTest->Branch("selmu_fgd2_pull_no"             , &selmu_fgd2_pull_no          , "selmu_fgd2_pull_no/F");
   
  foutb_HMNT_mom_BkgTest                      = fDefaultOut_BkgTest->Branch("HMNT_mom"                       , &HMNT_mom                    , "HMNT_mom/F");
  
  foutb_HMNT_NEcalSegments_BkgTest           = fDefaultOut_BkgTest->Branch("HMNT_NEcalSegments"             , &HMNT_NEcalSegments          , "HMNT_NEcalsSegments/I");
  foutb_HMNT_ecal_bestseg_EMenergy_BkgTest   = fDefaultOut_BkgTest->Branch("HMNT_ecal_bestseg_EMenergy"     , &HMNT_ecal_bestseg_EMenergy  , "HMNT_ecal_bestseg_EMenergy/F");
  foutb_HMNT_ecal_bestseg_mippion_BkgTest   = fDefaultOut_BkgTest->Branch("HMNT_ecal_bestseg_mippion"     , &HMNT_ecal_bestseg_mippion  , "HMNT_ecal_bestseg_mippion/F");
  foutb_HMNT_ecal_bestseg_EbyL_BkgTest      = fDefaultOut_BkgTest->Branch("HMNT_ecal_bestseg_EbyL"        , &HMNT_ecal_bestseg_EbyL     , "HMNT_ecal_bestseg_EbyL/F");
  foutb_HMNT_ecal_bestseg_EbyP_BkgTest      = fDefaultOut_BkgTest->Branch("HMNT_ecal_bestseg_EbyP"        , &HMNT_ecal_bestseg_EbyP     , "HMNT_ecal_bestseg_EbyP/F");
   
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
