#define defaultAntiNumuCC1pi_cxx
#include "defaultAntiNumuCC1pi.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TMath.h>
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
   
    std::cout << "Generating weight histogram... ";
   
    TH1F *recomom_hist = new TH1F("recomom_hist", "Reco momentum", 150, 0, 1500);
   
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
   
        fChain->GetEntry(jentry);

        // Cut on accum_level etc. N.B. make sure these cuts are the same as below
        if (accum_level[0][1] <= 4) continue; // Set accum_level
        if (selmu_mom[0] > 1500.0) continue;
        if (selmu_mom[0] < 150.0) continue;
        if ((defout->ntpcnegQualityFV)&&(HMNT_mom > 10000.0)) continue;
        if (particle != -11) continue;
      
        recomom_hist->Fill(selmu_mom[0]);
    }
   
    std::cout << "Done." << std::endl << std::endl;
      
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
   
       fChain->GetEntry(jentry);
       
       // Cut on accum_level etc.
       if (accum_level[0][1] <= 4) continue; // Set accum_level
       if (selmu_mom[0] > 1500.0) continue;
       if (selmu_mom[0] < 150.0) continue;
       if ((defout->ntpcnegQualityFV)&&(HMNT_mom > 10000.0)) continue;
       if (particle != -11) continue;
             
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
       defout->selmu_theta    		            = TMath::ACos(selmu_costheta[0]);
       
       // Calculate event weight based on reco mom histogram:
       Int_t weight_bin = selmu_mom[0]/10;
       Float_t inv_weight = recomom_hist->GetBinContent(weight_bin);
       if (inv_weight > 0) {defout->selmu_mom_weight = 1/inv_weight;}
       else                {defout->selmu_mom_weight = 0;}
        
        
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
         
       if (selmu_ecal_asymmetry > 0.0)
       {
          defout->selmu_ecal_amr                 = selmu_ecal_amr;
          defout->selmu_ecal_angle               = selmu_ecal_angle;
          defout->selmu_ecal_asymmetry           = selmu_ecal_asymmetry;
          defout->selmu_ecal_circularity         = selmu_ecal_circularity;
          defout->selmu_ecal_fbr                 = selmu_ecal_fbr;
          defout->selmu_ecal_maxratio            = selmu_ecal_maxratio;
          defout->selmu_ecal_meanpos             = selmu_ecal_meanpos;
          defout->selmu_ecal_showerangle         = selmu_ecal_showerangle;
          defout->selmu_ecal_showerwidth         = selmu_ecal_showerwidth;
          defout->selmu_ecal_tcr                 = selmu_ecal_tcr;
          defout->selmu_ecal_tmr                 = selmu_ecal_tmr;
       }
       else
       {
          defout->selmu_ecal_amr                 = -50.0;
          defout->selmu_ecal_angle               = -20.0;
          defout->selmu_ecal_asymmetry           = -0.5;
          defout->selmu_ecal_circularity         = -0.5;
          defout->selmu_ecal_fbr                 = -5.0;
          defout->selmu_ecal_maxratio            = -50.0;
          defout->selmu_ecal_meanpos             = -100.0;
          defout->selmu_ecal_showerangle         = -0.1;
          defout->selmu_ecal_showerwidth         = -0.1;
          defout->selmu_ecal_tcr                 = -0.5;
          defout->selmu_ecal_tmr                 = -0.2;
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
  
  // ----------- Output tree -----------
   
  fDefaultOut = new TTree("default", "");

  foutb_evt 	                      = fDefaultOut->Branch("evt"                            , &evt 	                     , "evt/I");
  foutb_topology 	                   = fDefaultOut->Branch("topology"                       , &topology 	                  , "topology/I");
  foutb_particle 	                   = fDefaultOut->Branch("particle"                       , &particle 	                  , "particle/I");
  foutb_ntpcposQualityFV 	          = fDefaultOut->Branch("ntpcposQualityFV"               , &ntpcposQualityFV 	         , "ntpcposQualityFV/I");
  foutb_ntpcnegQualityFV 	          = fDefaultOut->Branch("ntpcnegQualityFV"               , &ntpcnegQualityFV 	         , "ntpcnegQualityFV/I");
  foutb_NME 	                      = fDefaultOut->Branch("NME"                            , &NME 	                     , "NME/I");
  foutb_NFGDPi 	                   = fDefaultOut->Branch("NFGDPi"                         , &NFGDPi 	                  , "NFGDPi/I");
  foutb_NPi0El 	                   = fDefaultOut->Branch("NPi0El"                         , &NPi0El 	                  , "NPi0El/I");
  foutb_NPi0Pos 	                   = fDefaultOut->Branch("NPi0Pos"                        , &NPi0Pos 	                  , "NPi0Pos/I");
   
  foutb_selmu_mom 	                    = fDefaultOut->Branch("selmu_mom"                      , &selmu_mom 	               , "selmu_mom/F");
  foutb_selmu_mom_weight                = fDefaultOut->Branch("selmu_mom_weight"               , &selmu_mom_weight 	           , "selmu_mom_weight/F");
  foutb_selmu_theta 	                = fDefaultOut->Branch("selmu_theta"                    , &selmu_theta 	               , "selmu_theta/F");
  
  foutb_selmu_necals 	             = fDefaultOut->Branch("selmu_necals"                   , &selmu_necals       	      , "selmu_necals/I");
  foutb_selmu_ecal_bestseg_EMenergy  = fDefaultOut->Branch("selmu_ecal_bestseg_EMenergy"    , &selmu_ecal_bestseg_EMenergy , "selmu_ecal_bestseg_EMenergy/F");
  foutb_selmu_ecal_bestseg_mippion   = fDefaultOut->Branch("selmu_ecal_bestseg_mippion"     , &selmu_ecal_bestseg_mippion  , "selmu_ecal_bestseg_mippion/F");
  foutb_selmu_ecal_bestseg_EbyL      = fDefaultOut->Branch("selmu_ecal_bestseg_EbyL"        , &selmu_ecal_bestseg_EbyL     , "selmu_ecal_bestseg_EbyL/F");
  foutb_selmu_ecal_bestseg_EbyP      = fDefaultOut->Branch("selmu_ecal_bestseg_EbyP"        , &selmu_ecal_bestseg_EbyP     , "selmu_ecal_bestseg_EbyP/F");
  foutb_selmu_ecal_amr               = fDefaultOut->Branch("selmu_ecal_amr"                 , &selmu_ecal_amr              , "selmu_ecal_amr/F");
  foutb_selmu_ecal_angle             = fDefaultOut->Branch("selmu_ecal_angle"               , &selmu_ecal_angle            , "selmu_ecal_angle/F");
  foutb_selmu_ecal_asymmetry         = fDefaultOut->Branch("selmu_ecal_asymmetry"           , &selmu_ecal_asymmetry        , "selmu_ecal_asymmetry/F");
  foutb_selmu_ecal_circularity       = fDefaultOut->Branch("selmu_ecal_circularity"         , &selmu_ecal_circularity      , "selmu_ecal_circularity/F");
  foutb_selmu_ecal_fbr               = fDefaultOut->Branch("selmu_ecal_fbr"                 , &selmu_ecal_fbr              , "selmu_ecal_fbr/F");
  foutb_selmu_ecal_maxratio          = fDefaultOut->Branch("selmu_ecal_maxratio"            , &selmu_ecal_maxratio         , "selmu_ecal_maxratio/F");
  foutb_selmu_ecal_meanpos           = fDefaultOut->Branch("selmu_ecal_meanpos"             , &selmu_ecal_meanpos          , "selmu_ecal_meanpos/F");
  foutb_selmu_ecal_showerangle       = fDefaultOut->Branch("selmu_ecal_showerangle"         , &selmu_ecal_showerangle      , "selmu_ecal_showerangle/F");
  foutb_selmu_ecal_showerwidth       = fDefaultOut->Branch("selmu_ecal_showerwidth"         , &selmu_ecal_showerwidth      , "selmu_ecal_showerwidth/F");
  foutb_selmu_ecal_tcr               = fDefaultOut->Branch("selmu_ecal_tcr"                 , &selmu_ecal_tcr              , "selmu_ecal_tcr/F");
  foutb_selmu_ecal_tmr               = fDefaultOut->Branch("selmu_ecal_tmr"                 , &selmu_ecal_tmr              , "selmu_ecal_tmr/F");
   
  foutb_selmu_tpc_like_mu  	       = fDefaultOut->Branch("selmu_tpc_like_mu"              , &selmu_tpc_like_mu  	      , "selmu_tpc_like_mu/F");
  foutb_selmu_tpc_like_e  	          = fDefaultOut->Branch("selmu_tpc_like_e"               , &selmu_tpc_like_e  	         , "selmu_tpc_like_e/F");
  foutb_selmu_tpc_like_p  	          = fDefaultOut->Branch("selmu_tpc_like_p"               , &selmu_tpc_like_p  	         , "selmu_tpc_like_p/F");
  foutb_selmu_tpc_like_pi  	       = fDefaultOut->Branch("selmu_tpc_like_pi"              , &selmu_tpc_like_pi  	      , "selmu_tpc_like_pi/F");
   
  foutb_selmu_has_fgd1seg 	          = fDefaultOut->Branch("selmu_has_fgd1seg"              , &selmu_has_fgd1seg 	         , "selmu_has_fgd1seg/I");
  foutb_selmu_fgd1_pull_mu  	       = fDefaultOut->Branch("selmu_fgd1_pull_mu"             , &selmu_fgd1_pull_mu  	      , "selmu_fgd1_pull_mu/F");
  foutb_selmu_fgd1_pull_p  	       = fDefaultOut->Branch("selmu_fgd1_pull_p"              , &selmu_fgd1_pull_p  	      , "selmu_fgd1_pull_p/F");
  foutb_selmu_fgd1_pull_pi  	       = fDefaultOut->Branch("selmu_fgd1_pull_pi"             , &selmu_fgd1_pull_pi  	      , "selmu_fgd1_pull_pi/F");
  foutb_selmu_fgd1_pull_no  	       = fDefaultOut->Branch("selmu_fgd1_pull_no"             , &selmu_fgd1_pull_no  	      , "selmu_fgd1_pull_no/F");
   
  foutb_selmu_has_fgd2seg 	          = fDefaultOut->Branch("selmu_has_fgd2seg"              , &selmu_has_fgd2seg 	         , "selmu_has_fgd2seg/I");
  foutb_selmu_fgd2_pull_mu  	       = fDefaultOut->Branch("selmu_fgd2_pull_mu"             , &selmu_fgd2_pull_mu  	      , "selmu_fgd2_pull_mu/F");
  foutb_selmu_fgd2_pull_p  	       = fDefaultOut->Branch("selmu_fgd2_pull_p"              , &selmu_fgd2_pull_p  	      , "selmu_fgd2_pull_p/F");
  foutb_selmu_fgd2_pull_pi  	       = fDefaultOut->Branch("selmu_fgd2_pull_pi"             , &selmu_fgd2_pull_pi  	      , "selmu_fgd2_pull_pi/F");
  foutb_selmu_fgd2_pull_no  	       = fDefaultOut->Branch("selmu_fgd2_pull_no"             , &selmu_fgd2_pull_no  	      , "selmu_fgd2_pull_no/F");
   
  foutb_HMNT_mom 	                   = fDefaultOut->Branch("HMNT_mom"                       , &HMNT_mom 	                  , "HMNT_mom/F");
  
  foutb_HMNT_NEcalSegments	          = fDefaultOut->Branch("HMNT_NEcalSegments"             , &HMNT_NEcalSegments	         , "HMNT_NEcalsSegments/I");
  foutb_HMNT_ecal_bestseg_EMenergy   = fDefaultOut->Branch("HMNT_ecal_bestseg_EMenergy"     , &HMNT_ecal_bestseg_EMenergy  , "HMNT_ecal_bestseg_EMenergy/F");
  foutb_HMNT_ecal_bestseg_mippion   = fDefaultOut->Branch("HMNT_ecal_bestseg_mippion"     , &HMNT_ecal_bestseg_mippion  , "HMNT_ecal_bestseg_mippion/F");
  foutb_HMNT_ecal_bestseg_EbyL      = fDefaultOut->Branch("HMNT_ecal_bestseg_EbyL"        , &HMNT_ecal_bestseg_EbyL     , "HMNT_ecal_bestseg_EbyL/F");
  foutb_HMNT_ecal_bestseg_EbyP      = fDefaultOut->Branch("HMNT_ecal_bestseg_EbyP"        , &HMNT_ecal_bestseg_EbyP     , "HMNT_ecal_bestseg_EbyP/F");
   
  foutb_HMNT_tpc_like_mu               = fDefaultOut->Branch("HMNT_tpc_like_mu"              , &HMNT_tpc_like_mu           , "HMNT_tpc_like_mu/F");
  foutb_HMNT_tpc_like_e             = fDefaultOut->Branch("HMNT_tpc_like_e"               , &HMNT_tpc_like_e            , "HMNT_tpc_like_e/F");
  foutb_HMNT_tpc_like_p             = fDefaultOut->Branch("HMNT_tpc_like_p"               , &HMNT_tpc_like_p            , "HMNT_tpc_like_p/F");
  foutb_HMNT_tpc_like_pi               = fDefaultOut->Branch("HMNT_tpc_like_pi"              , &HMNT_tpc_like_pi           , "HMNT_tpc_like_pi/F");
   
  foutb_HMNT_has_fgd1seg            = fDefaultOut->Branch("HMNT_has_fgd1seg"              , &HMNT_has_fgd1seg           , "HMNT_has_fgd1seg/I");
  foutb_HMNT_fgd1_pull_mu              = fDefaultOut->Branch("HMNT_fgd1_pull_mu"             , &HMNT_fgd1_pull_mu          , "HMNT_fgd1_pull_mu/F");
  foutb_HMNT_fgd1_pull_p               = fDefaultOut->Branch("HMNT_fgd1_pull_p"              , &HMNT_fgd1_pull_p           , "HMNT_fgd1_pull_p/F");
  foutb_HMNT_fgd1_pull_pi              = fDefaultOut->Branch("HMNT_fgd1_pull_pi"             , &HMNT_fgd1_pull_pi          , "HMNT_fgd1_pull_pi/F");
  foutb_HMNT_fgd1_pull_no              = fDefaultOut->Branch("HMNT_fgd1_pull_no"             , &HMNT_fgd1_pull_no          , "HMNT_fgd1_pull_no/F");
   
  foutb_HMNT_has_fgd2seg            = fDefaultOut->Branch("HMNT_has_fgd2seg"              , &HMNT_has_fgd2seg           , "HMNT_has_fgd2seg/I");
  foutb_HMNT_fgd2_pull_mu              = fDefaultOut->Branch("HMNT_fgd2_pull_mu"             , &HMNT_fgd2_pull_mu          , "HMNT_fgd2_pull_mu/F");
  foutb_HMNT_fgd2_pull_p               = fDefaultOut->Branch("HMNT_fgd2_pull_p"              , &HMNT_fgd2_pull_p           , "HMNT_fgd2_pull_p/F");
  foutb_HMNT_fgd2_pull_pi              = fDefaultOut->Branch("HMNT_fgd2_pull_pi"             , &HMNT_fgd2_pull_pi          , "HMNT_fgd2_pull_pi/F");
  foutb_HMNT_fgd2_pull_no              = fDefaultOut->Branch("HMNT_fgd2_pull_no"             , &HMNT_fgd2_pull_no          , "HMNT_fgd2_pull_no/F");
   
  return;
}
