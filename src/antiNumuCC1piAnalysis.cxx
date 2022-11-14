#include "antiNumuCC1piAnalysis.hxx"
#include "antiNumuCC1piSelection.hxx"

//constructor
//********************************************************************
antiNumuCC1piAnalysis::antiNumuCC1piAnalysis(AnalysisAlgorithm* ana) : baseTrackerAnalysis(ana) {
//********************************************************************

  // Add the package version
  ND::versioning().AddPackage("antiNumuCC1piAnalysis", anaUtils::GetSoftwareVersionFromPath((std::string)getenv("ANTINUMUCC1PIANALYSISROOT")));

  // Create a antiNumuCCAnalysis passing this analysis to the constructor. In that way the same managers are used
  //_antiNumuCCAnalysis = new antiNumuCCAnalysis(this);
  
  // Create a numuCCMultiPiAnalysis passing this analysis to the constructor. In that way the same managers are used
  //_numuCCMultiPiAnalysis = new numuCCMultiPiAnalysis(this);
  
  // Create a antiNumuCCMultiPiAnalysis passing this analysis to the constructor. In that way the same managers are used
  _antiNumuCCMultiPiAnalysis = new antiNumuCCMultiPiAnalysis(this);

  // Use the antiNumuCCAnalysis (in practice that means that the same box and event will be used for the antiNumuCCAnalysis as for this analysis)
  //UseAnalysis(_antiNumuCCAnalysis);
  //UseAnalysis(_numuCCMultiPiAnalysis);
  UseAnalysis(_antiNumuCCMultiPiAnalysis);
}

//********************************************************************
bool antiNumuCC1piAnalysis::Initialize() {
//********************************************************************

  // Initialize the baseAnalysis instead of numuCCAnalysis
  // since we do not want to call and overload numu categories
  if(!baseTrackerAnalysis::Initialize()) return false;

  // Minimum accum level to save event into the output tree
  SetMinAccumCutLevelToSave(ND::params().GetParameterI("antiNumuCC1piAnalysis.MinAccumLevelToSave"));

  // which analysis: FGD1, FGD2 or FGDs
  _whichFGD = ND::params().GetParameterI("antiNumuCC1piAnalysis.Selections.whichFGD");
  if (_whichFGD == 3) {
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "WARNING: only for events with accum_level > 6 the vars in the output microtree will surely refer to the muon candidate in that FGD" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
  }
  
  
  

  // CC-multi-pi or CC-multi-track
   _runMultiTrack = ND::params().GetParameterI("antiNumuCC1piAnalysis.Selections.RunMultiTrack");
  
  // Define antinu categories (different legend from numuCC)
  // for FGD2 same categories with prefix "fgd2", i,e, "fgd2reaction" etc.)
  anaUtils::AddStandardAntiNumuCategories();
  anaUtils::AddStandardAntiNumuCategories("fgd2");
  //TODO: add categories

  // Note to self: figure out how best to integrate this
  //_numuCCMultiPiAnalysis->SetStoreAllTruePrimaryPions((bool)ND::params().GetParameterI("antiNumuCCMultiPiAnalysis.MicroTrees.StoreAllTruePrimaryPions"));
  
  myBDTPIDmanagerCC1pi = new BDTPIDmanager();
  
  return true;
}

//********************************************************************
void antiNumuCC1piAnalysis::DefineSelections(){
//********************************************************************
  
  // FGD1 antineutrino analysis:
  //if(_whichFGD==1 || _whichFGD==3){
    // ---- Inclusive CC ----
    //if(!_runMultiTrack)
      sel().AddSelection("kTrackerAntiNumuCC1pi",    "antiNumu FGD1 CC 1 Pion selection",  new antiNumuCC1piSelection(false, &(input()), myBDTPIDmanagerCC1pi));
    // ---- CC Multi Pion Samples ----
    //else
      //sel().AddSelection("kTrackerAntiNumuCCMultiTrack", "antiNumu FGD1 CC Multiple Track selection", new antiNumuCCMultiTrackSelection(false));
  //}
  // FGD2 antineutrino analysis:
  //if (_whichFGD==2 || _whichFGD==3){
    // ---- CC Inclusive ----
    //if(!_runMultiTrack)
      //sel().AddSelection("kTrackerAntiNumuCCMultiPiFGD2",  "antiNumu FGD2 CC Multiple Pion selection",  new antiNumuCCMultiPiFGD2Selection(false));
    // ---- CC Multi Track Samples ----
    //else
      //sel().AddSelection("kTrackerAntiNumuMultiTrackFGD2", "antiNumu FGD2 CC Multiple Track selection", new antiNumuCCMultiTrackFGD2Selection(false));
  //}

  
}

//********************************************************************
void antiNumuCC1piAnalysis::DefineMicroTrees(bool addBase){
//********************************************************************

  // -------- Add variables to the analysis tree ----------------------

  //if(_runMultiTrack){
    //_antiNumuCCAnalysis->DefineMicroTrees(addBase);
  //}
  //else{
    //_numuCCMultiPiAnalysis->DefineMicroTrees(addBase); 
  //}
  
  _antiNumuCCMultiPiAnalysis->DefineMicroTrees(addBase); 
  
  // --- Muon candidate variables
  
  AddVarF(output(),selmu_det_theta, "");
  
  AddVarF(output(),selmu_tpc_like_mu, "");
  AddVarF(output(),selmu_tpc_like_e, "");
  AddVarF(output(),selmu_tpc_like_p, "");
  AddVarF(output(),selmu_tpc_like_pi, "");
  
  AddVarI(output(),selmu_has_fgd1seg, "");
  AddVarF(output(),selmu_fgd1_pull_mu, "");
  AddVarF(output(),selmu_fgd1_pull_e, "");
  AddVarF(output(),selmu_fgd1_pull_p, "");
  AddVarF(output(),selmu_fgd1_pull_pi, "");
  AddVarF(output(),selmu_fgd1_pull_no, "");
  AddVarF(output(),selmu_fgd1_energy, "");
  AddVarF(output(),selmu_fgd1_length, "");
  AddVarF(output(),selmu_fgd1_EbyL, "");
  
  AddVarI(output(),selmu_has_fgd2seg, "");
  AddVarF(output(),selmu_fgd2_pull_mu, "");
  AddVarF(output(),selmu_fgd2_pull_e, "");
  AddVarF(output(),selmu_fgd2_pull_p, "");
  AddVarF(output(),selmu_fgd2_pull_pi, "");
  AddVarF(output(),selmu_fgd2_pull_no, "");
  AddVarF(output(),selmu_fgd2_energy, "");
  AddVarF(output(),selmu_fgd2_length, "");
  AddVarF(output(),selmu_fgd2_EbyL, "");
  
  AddVarF(output(),selmu_ecal_bestseg_EMenergy, "");
  AddVarF(output(),selmu_ecal_bestseg_mippion, "");
  AddVarF(output(),selmu_ecal_bestseg_EbyL, "");
  
  AddVarF(output(),selmu_ecal_amr, "");
  AddVarF(output(),selmu_ecal_angle, "");
  AddVarF(output(),selmu_ecal_asymmetry, "");
  AddVarF(output(),selmu_ecal_circularity, "");
  AddVarF(output(),selmu_ecal_fbr, "");
  AddVarF(output(),selmu_ecal_maxratio, "");
  AddVarF(output(),selmu_ecal_meanpos, "");
  AddVarF(output(),selmu_ecal_qrms, "");
  AddVarF(output(),selmu_ecal_showerangle, "");
  AddVarF(output(),selmu_ecal_showerwidth, "");
  AddVarF(output(),selmu_ecal_tcr, "");
  AddVarF(output(),selmu_ecal_tmr, "");
  
  // --- Highest-momentum negative track variables
    
  AddVarF(output(),HMNT_mom, "");
  AddVarF(output(),HMNT_costheta, "");
  AddVarI(output(),HMNT_pdg, "");
  AddVarI(output(),HMNT_truepdg, "");
  
  AddVarI(output(),HMNT_NEcalSegments, "");
  AddVarF(output(),HMNT_ecal_EMenergy, "");
  AddVarF(output(),HMNT_ecal_length, "");
  AddVarF(output(),HMNT_ecal_mippion, "");
  AddVarF(output(),HMNT_ecal_angle, "");
  
  AddVarF(output(),HMNT_ecal_bestseg_EMenergy, "");
  AddVarF(output(),HMNT_ecal_bestseg_mippion, "");
  AddVarF(output(),HMNT_ecal_bestseg_EbyL, "");
 
  AddVarF(output(),HMNT_tpc_like_mu, "");
  AddVarF(output(),HMNT_tpc_like_e, "");
  AddVarF(output(),HMNT_tpc_like_p, "");
  AddVarF(output(),HMNT_tpc_like_pi, "");
  
  AddVarI(output(),HMNT_has_fgd1seg, "");
  AddVarF(output(),HMNT_fgd1_pull_mu, "");
  AddVarF(output(),HMNT_fgd1_pull_e, "");
  AddVarF(output(),HMNT_fgd1_pull_p, "");
  AddVarF(output(),HMNT_fgd1_pull_pi, "");
  AddVarF(output(),HMNT_fgd1_pull_no, "");
  
  AddVarI(output(),HMNT_has_fgd2seg, "");
  AddVarF(output(),HMNT_fgd2_pull_mu, "");
  AddVarF(output(),HMNT_fgd2_pull_e, "");
  AddVarF(output(),HMNT_fgd2_pull_p, "");
  AddVarF(output(),HMNT_fgd2_pull_pi, "");
  AddVarF(output(),HMNT_fgd2_pull_no, "");
  
  AddVarF(output(),selmu_bdt_pid_mu, "");
  AddVarF(output(),selmu_bdt_pid_pi, "");
  AddVarF(output(),selmu_bdt_pid_p, "");
  AddVarF(output(),selmu_bdt_pid_e, "");
  
  AddVarF(output(),hmnt_bdt_pid_mu, "");
  AddVarF(output(),hmnt_bdt_pid_pi, "");
  AddVarF(output(),hmnt_bdt_pid_p, "");
  AddVarF(output(),hmnt_bdt_pid_e, "");
  
  //AddVarF(output(),selmu_bdt_pid_mu_cc1pi, "");
  //AddVarF(output(),hmnt_bdt_pid_pi_cc1pi, "");
  
  AddVarF(output(),selmu_bdt_pid_mu_test1, "");
  AddVarF(output(),selmu_bdt_pid_pi_test1, "");
  AddVarF(output(),selmu_bdt_pid_p_test1, "");
  AddVarF(output(),selmu_bdt_pid_e_test1, "");
  AddVarF(output(),hmnt_bdt_pid_pi_test1, "");
  
  AddVarF(output(),selmu_bdt_pid_mu_test2, "");
  AddVarF(output(),selmu_bdt_pid_pi_test2, "");
  AddVarF(output(),selmu_bdt_pid_p_test2, "");
  AddVarF(output(),selmu_bdt_pid_e_test2, "");
  AddVarF(output(),hmnt_bdt_pid_pi_test2, "");
  
  AddVarF(output(),selmu_bdt_pid_mu_test3, "");
  AddVarF(output(),selmu_bdt_pid_pi_test3, "");
  AddVarF(output(),selmu_bdt_pid_p_test3, "");
  AddVarF(output(),selmu_bdt_pid_e_test3, "");
  AddVarF(output(),hmnt_bdt_pid_pi_test3, "");
  
  AddVarF(output(),selmu_bdt_pid_mu_test4, "");
  AddVarF(output(),selmu_bdt_pid_pi_test4, "");
  AddVarF(output(),selmu_bdt_pid_p_test4, "");
  AddVarF(output(),selmu_bdt_pid_e_test4, "");
  AddVarF(output(),hmnt_bdt_pid_pi_test4, "");
  
  AddVarF(output(),selmu_bdt_pid_mu_test5, "");
  AddVarF(output(),selmu_bdt_pid_pi_test5, "");
  AddVarF(output(),selmu_bdt_pid_p_test5, "");
  AddVarF(output(),selmu_bdt_pid_e_test5, "");
  AddVarF(output(),hmnt_bdt_pid_pi_test5, "");
  
  AddVarF(output(),selmu_bdt_pid_unweighted_mu_cc1pi, "");
  AddVarF(output(),hmnt_bdt_pid_unweighted_pi_cc1pi, "");
  
  AddVarI(output(), particle_pg, "particle gun compatible main track PDG");
  
  baseTrackerAnalysis::AddEffCounters();
  
  
}

//********************************************************************
void antiNumuCC1piAnalysis::DefineTruthTree(){
//********************************************************************

  //if(_runMultiTrack){
    //_antiNumuCCAnalysis->DefineTruthTree();
  //}
  //else{
    //_numuCCMultiPiAnalysis->DefineTruthTree();
  //}
  
  _antiNumuCCMultiPiAnalysis->DefineTruthTree();
  
  AddVarI(output(), particle_pg, "particle gun compatible main track PDG");
  AddVarF(output(), pg_trueparticle_mom, "particle gun true particle momentum");
  AddVarF(output(), pg_trueparticle_costheta, "particle gun true particle costheta");
}

//********************************************************************
void antiNumuCC1piAnalysis::FillMicroTrees(bool addBase){
//********************************************************************
  
  //if(_runMultiTrack){
    //_antiNumuCCAnalysis->FillMicroTrees(addBase);
  //}
  //else{
   // _numuCCMultiPiAnalysis->FillMicroTrees(addBase); 
  //}
  //std::cout << "DEBUG: Filling micro trees from _antiNumuCCMultiPiAnalysis..." << std::endl;
  _antiNumuCCMultiPiAnalysis->FillMicroTrees(addBase); 
  
  //ResetBDTInputVariables();
  
  // Fill muon candidate variables
  if (mybox().MainTrack  ) 
  {
    //std::cout << "DEBUG: Filling muon candidate variables..." << std::endl;
    //std::cout << "DEBUG: Filling PDG ID..." << std::endl;
    if (GetEvent().GetIsMC())
    {
      output().FillVar(particle_pg, mybox().MainTrack->GetTrueParticle()->PDG); // Note: meant for particle gun MC, okay for full MC, but can't be filled for real data
    }
    
    //std::cout << "DEBUG: Filling angle wrt detector..." << std::endl;
    TVector3 nuDirVec = anaUtils::GetNuDirRec(box().MainTrack->PositionStart);
    TVector3 muDirVec = anaUtils::ArrayToTVector3(box().MainTrack->DirectionStart);
    //double costheta_mu_nu = nuDirVec.Dot(muDirVec);
    Float_t selmu_theta_wrt_detector = TMath::ACos(muDirVec[2]);
    
    output().FillVar(selmu_det_theta,        selmu_theta_wrt_detector);
    
    //std::cout << "DEBUG: Filling TPC info..." << std::endl;
    output().FillVar(selmu_tpc_like_mu,      anaUtils::GetPIDLikelihood( *(mybox().MainTrack),0));
    output().FillVar(selmu_tpc_like_e,       anaUtils::GetPIDLikelihood( *(mybox().MainTrack),1));
    output().FillVar(selmu_tpc_like_p,       anaUtils::GetPIDLikelihood( *(mybox().MainTrack),2));
    output().FillVar(selmu_tpc_like_pi,      anaUtils::GetPIDLikelihood( *(mybox().MainTrack),3));
    
    //std::cout << "DEBUG: Filling FGD1 info..." << std::endl;
    AnaFGDParticle* FGD1Segment = static_cast<AnaFGDParticle*>(anaUtils::GetSegmentInDet( *mybox().MainTrack,static_cast<SubDetId::SubDetEnum >(0)));
    if (FGD1Segment) 
    {
      output().FillVar(selmu_has_fgd1seg,      1);
      output().FillVar(selmu_fgd1_pull_mu,     FGD1Segment->Pullmu);
      output().FillVar(selmu_fgd1_pull_e,      FGD1Segment->Pulle);
      output().FillVar(selmu_fgd1_pull_p,      FGD1Segment->Pullp);
      output().FillVar(selmu_fgd1_pull_pi,     FGD1Segment->Pullpi);
      output().FillVar(selmu_fgd1_pull_no,     FGD1Segment->Pullno);
      output().FillVar(selmu_fgd1_energy,      FGD1Segment->E);
      output().FillVar(selmu_fgd1_length,      FGD1Segment->Length);
      if ((FGD1Segment->E > 0)&&(FGD1Segment->Length > 0))
      {
          output().FillVar(selmu_fgd1_EbyL,        FGD1Segment->E/FGD1Segment->Length);
      }
    }
    else
    {
      output().FillVar(selmu_has_fgd1seg,      0);
    }
    
    //std::cout << "DEBUG: Filling FGD2 info..." << std::endl;
    AnaFGDParticle* FGD2Segment = static_cast<AnaFGDParticle*>(anaUtils::GetSegmentInDet( *mybox().MainTrack,static_cast<SubDetId::SubDetEnum >(1)));
    if (FGD2Segment) 
    {
      output().FillVar(selmu_has_fgd2seg,      1);
      output().FillVar(selmu_fgd2_pull_mu,     FGD2Segment->Pullmu);
      output().FillVar(selmu_fgd2_pull_e,      FGD2Segment->Pulle);
      output().FillVar(selmu_fgd2_pull_p,      FGD2Segment->Pullp);
      output().FillVar(selmu_fgd2_pull_pi,     FGD2Segment->Pullpi);
      output().FillVar(selmu_fgd2_pull_no,     FGD2Segment->Pullno);
      output().FillVar(selmu_fgd2_energy,      FGD2Segment->E);
      output().FillVar(selmu_fgd2_length,      FGD2Segment->Length);
      if ((FGD2Segment->E > 0)&&(FGD2Segment->Length > 0))
      {
          output().FillVar(selmu_fgd2_EbyL,        FGD2Segment->E/FGD2Segment->Length);
      }
      
    }
    else
    {
      output().FillVar(selmu_has_fgd2seg,      0);
    }
    
    //std::cout << "DEBUG: Filling ECal info..." << std::endl;
    
    Float_t selmu_max_EMenergy = -999.0;
    Float_t selmu_best_mippion = -999.0;
    Float_t selmu_best_EbyL = -999.0;
    //Int_t selmu_mean_denom = 0;
  
    for (Int_t subdet = 0; subdet<9; subdet++) {
      if (!SubDetId::GetDetectorUsed(mybox().MainTrack->Detector, static_cast<SubDetId::SubDetEnum >(subdet+6))) continue;

      AnaECALParticle* ECALSegment = static_cast<AnaECALParticle*>(anaUtils::GetSegmentInDet( *mybox().MainTrack,static_cast<SubDetId::SubDetEnum >(subdet+6)));

      if (!ECALSegment) continue;
      
      if (ECALSegment->EMEnergy > selmu_max_EMenergy) 
      {
        selmu_max_EMenergy     = ECALSegment->EMEnergy;
        selmu_best_mippion     = ECALSegment->PIDMipPion;
        selmu_best_EbyL        = (ECALSegment->EMEnergy)/(ECALSegment->Length);
      }
      
      //if (selmu_mean_mippion==-999.0) selmu_mean_mippion=0;
      //if (selmu_mean_EbyL==-999.0) selmu_mean_EbyL=0;
      //selmu_mean_mippion += ECALSegment->PIDMipPion;
      //selmu_mean_EbyL += (ECALSegment->EMEnergy)/(ECALSegment->Length);
      //selmu_mean_denom++;
    }
    
    //selmu_mean_mippion /= selmu_mean_denom;
    //selmu_mean_EbyL /= selmu_mean_denom;
    
    output().FillVar(selmu_ecal_bestseg_EMenergy,    selmu_max_EMenergy);
    output().FillVar(selmu_ecal_bestseg_mippion,     selmu_best_mippion);
    output().FillVar(selmu_ecal_bestseg_EbyL,        selmu_best_EbyL);
    
    
    // Get variables from local reco ECal segment:
    //std::cout << "DEBUG: Filling local ECal info..." << std::endl;
    if (mybox().MainTrackLocalECalSegment  )
    {
      output().FillVar(selmu_ecal_amr,            mybox().MainTrackLocalECalSegment->PIDAMR);
      output().FillVar(selmu_ecal_angle,          mybox().MainTrackLocalECalSegment->PIDAngle);
      output().FillVar(selmu_ecal_asymmetry,      mybox().MainTrackLocalECalSegment->PIDAsymmetry);
      output().FillVar(selmu_ecal_circularity,    mybox().MainTrackLocalECalSegment->PIDCircularity);
      output().FillVar(selmu_ecal_fbr,            mybox().MainTrackLocalECalSegment->PIDFBR);
      output().FillVar(selmu_ecal_maxratio,       mybox().MainTrackLocalECalSegment->PIDMaxRatio);
      output().FillVar(selmu_ecal_meanpos,        mybox().MainTrackLocalECalSegment->PIDMeanPos);
      output().FillVar(selmu_ecal_qrms,           mybox().MainTrackLocalECalSegment->EMEnergyFitParaQRMS);
      output().FillVar(selmu_ecal_showerangle,    mybox().MainTrackLocalECalSegment->PIDShowerAngle);
      output().FillVar(selmu_ecal_showerwidth,    mybox().MainTrackLocalECalSegment->PIDShowerWidth);
      output().FillVar(selmu_ecal_tcr,            mybox().MainTrackLocalECalSegment->PIDTransverseChargeRatio);
      output().FillVar(selmu_ecal_tmr,            mybox().MainTrackLocalECalSegment->PIDTruncatedMaxRatio);
      
    }
    
    /*std::cout << "DEBUG: Evaluating BDT output..." << std::endl;
    if (mybox().MainTrack) std::cout << "DEBUG: Main track exists." << std::endl;
    else std::cout << "DEBUG: Main track DOES NOT EXIST." << std::endl;
    if (mybox().MainTrackLocalECalSegment) std::cout << "DEBUG: Main track local ECal segment exists." << std::endl;
    else std::cout << "DEBUG: Main track local ECal segment DOES NOT EXIST." << std::endl;
    AnaTrackB* track_for_bdt = NULL;
    AnaTECALReconObject* localseg_for_bdt = NULL;
    //std::vector<Float_t> BDT_PID_results = myBDTPIDmanager->GetBDTPIDVars(mybox().MainTrack, mybox().MainTrackLocalECalSegment);
    std::vector<Float_t> BDT_PID_results = myBDTPIDmanager->GetBDTPIDVars(track_for_bdt, localseg_for_bdt);
    
    output().FillVar(selmu_bdt_pid_mu, BDT_PID_results[0]);
    output().FillVar(selmu_bdt_pid_pi, BDT_PID_results[1]);
    output().FillVar(selmu_bdt_pid_p, BDT_PID_results[2]);
    output().FillVar(selmu_bdt_pid_e, BDT_PID_results[3]);*/
    
    //std::cout << "DEBUG: Filling BDT outputs..." << std::endl;
    
    std::vector<Float_t> BDT_PID_results_vector = myBDTPIDmanagerCC1pi->GetBDTPIDVarsPos(mybox().MainTrack, mybox().MainTrackLocalECalSegment);
    //output().FillVar(selmu_bdt_pid_mu_cc1pi, BDT_PID_results_vector[0]);
    output().FillVar(selmu_bdt_pid_mu, BDT_PID_results_vector[0]);
    output().FillVar(selmu_bdt_pid_pi, BDT_PID_results_vector[1]);
    output().FillVar(selmu_bdt_pid_p, BDT_PID_results_vector[2]);
    output().FillVar(selmu_bdt_pid_e, BDT_PID_results_vector[3]);
    
    
    /*BDT_PID_results_vector = myBDTPIDmanagerCC1pi->GetBDTPIDVarsPos(mybox().MainTrack, mybox().MainTrackLocalECalSegment, "BDTG_2vars");
    output().FillVar(selmu_bdt_pid_mu_test1, BDT_PID_results_vector[0]);
    output().FillVar(selmu_bdt_pid_pi_test1, BDT_PID_results_vector[1]);
    output().FillVar(selmu_bdt_pid_p_test1, BDT_PID_results_vector[2]);
    output().FillVar(selmu_bdt_pid_e_test1, BDT_PID_results_vector[3]);
    
    BDT_PID_results_vector = myBDTPIDmanagerCC1pi->GetBDTPIDVarsPos(mybox().MainTrack, mybox().MainTrackLocalECalSegment, "BDTG_3vars");
    output().FillVar(selmu_bdt_pid_mu_test2, BDT_PID_results_vector[0]);
    output().FillVar(selmu_bdt_pid_pi_test2, BDT_PID_results_vector[1]);
    output().FillVar(selmu_bdt_pid_p_test2, BDT_PID_results_vector[2]);
    output().FillVar(selmu_bdt_pid_e_test2, BDT_PID_results_vector[3]);
    
    BDT_PID_results_vector = myBDTPIDmanagerCC1pi->GetBDTPIDVarsPos(mybox().MainTrack, mybox().MainTrackLocalECalSegment, "BDTG_8vars");
    output().FillVar(selmu_bdt_pid_mu_test3, BDT_PID_results_vector[0]);
    output().FillVar(selmu_bdt_pid_pi_test3, BDT_PID_results_vector[1]);
    output().FillVar(selmu_bdt_pid_p_test3, BDT_PID_results_vector[2]);
    output().FillVar(selmu_bdt_pid_e_test3, BDT_PID_results_vector[3]);
    
    BDT_PID_results_vector = myBDTPIDmanagerCC1pi->GetBDTPIDVarsPos(mybox().MainTrack, mybox().MainTrackLocalECalSegment, "BDTG_10vars");
    output().FillVar(selmu_bdt_pid_mu_test4, BDT_PID_results_vector[0]);
    output().FillVar(selmu_bdt_pid_pi_test4, BDT_PID_results_vector[1]);
    output().FillVar(selmu_bdt_pid_p_test4, BDT_PID_results_vector[2]);
    output().FillVar(selmu_bdt_pid_e_test4, BDT_PID_results_vector[3]);
    
    BDT_PID_results_vector = myBDTPIDmanagerCC1pi->GetBDTPIDVarsPos(mybox().MainTrack, mybox().MainTrackLocalECalSegment, "BDTG_12vars");
    output().FillVar(selmu_bdt_pid_mu_test5, BDT_PID_results_vector[0]);
    output().FillVar(selmu_bdt_pid_pi_test5, BDT_PID_results_vector[1]);
    output().FillVar(selmu_bdt_pid_p_test5, BDT_PID_results_vector[2]);
    output().FillVar(selmu_bdt_pid_e_test5, BDT_PID_results_vector[3]);*/
    
    //BDT_PID_results_vector = myBDTPIDmanagerCC1pi->GetBDTPIDVars(mybox().MainTrack, mybox().MainTrackLocalECalSegment, "BDTG_tree3_noweights");
    //output().FillVar(selmu_bdt_pid_unweighted_mu_cc1pi, BDT_PID_results_vector[0]);
    
    //std::cout << "DEBUG: Finished filling muon candidate variables." << std::endl;

  }
  
  

  
  // Fill HMNT variables
  if (mybox().HMNtrack  ) 
  {
    //std::cout << "DEBUG: Filling HMNT variables..." << std::endl;
    output().FillVar(HMNT_mom,      mybox().HMNtrack->Momentum);
    //output().FillVar(HMNT_costheta, mybox().HMNtrack->Costheta);
    if (mybox().HMNtrack->GetTrueParticle()  ) 
    { 
      output().FillVar(HMNT_truepdg, mybox().HMNtrack->GetTrueParticle()->PDG);
    }
    
    output().FillVar(HMNT_NEcalSegments,      mybox().HMNtrack->nECALSegments);
    
    //std::cout << "DEBUG: Filling ECal info..." << std::endl;
    if (mybox().HMNtrack->nECALSegments > 0)
    {
      AnaECALParticle* ECalSeg = static_cast<AnaECALParticle*>( mybox().HMNtrack->ECALSegments[0] );
      
      output().FillVar(HMNT_ecal_EMenergy,      ECalSeg->EMEnergy);
      output().FillVar(HMNT_ecal_length,        ECalSeg->Length);
      output().FillVar(HMNT_ecal_mippion,       ECalSeg->PIDMipPion);
      //output().FillVar(HMNT_ecal_angle,         ECalSeg->PID_Angle);
    }
    
    Float_t HMNT_max_EMenergy = -999.0;
    Float_t HMNT_best_mippion = -999.0;
    Float_t HMNT_best_EbyL = -999.0;
    //Int_t HMNT_mean_denom = 0;
  
    for (Int_t subdet = 0; subdet<9; subdet++) {
      if (!SubDetId::GetDetectorUsed(mybox().HMNtrack->Detector, static_cast<SubDetId::SubDetEnum >(subdet+6))) continue;

      AnaECALParticle* ECALSegment = static_cast<AnaECALParticle*>(anaUtils::GetSegmentInDet( *mybox().HMNtrack,static_cast<SubDetId::SubDetEnum >(subdet+6)));

      if (!ECALSegment) continue;
      
      if (ECALSegment->EMEnergy > HMNT_max_EMenergy) 
      {
        HMNT_max_EMenergy = ECALSegment->EMEnergy;
        HMNT_best_mippion = ECALSegment->PIDMipPion;
        HMNT_best_EbyL    = (ECALSegment->EMEnergy)/(ECALSegment->Length);
      }
      
      //if (HMNT_mean_mippion==-999.0) HMNT_mean_mippion=0;
      //if (HMNT_mean_EbyL==-999.0) HMNT_mean_EbyL=0;
      //HMNT_mean_mippion += ECALSegment->PIDMipPion;
      //HMNT_mean_EbyL += (ECALSegment->EMEnergy)/(ECALSegment->Length);
      //HMNT_mean_denom++;
    }
    
    //HMNT_mean_mippion /= HMNT_mean_denom;
    //HMNT_mean_EbyL /= HMNT_mean_denom;
    
    output().FillVar(HMNT_ecal_bestseg_EMenergy,    HMNT_max_EMenergy);
    output().FillVar(HMNT_ecal_bestseg_mippion,     HMNT_best_mippion);
    output().FillVar(HMNT_ecal_bestseg_EbyL,        HMNT_best_EbyL);
    
    //std::cout << "DEBUG: Filling TPC info..." << std::endl;
    
    output().FillVar(HMNT_tpc_like_mu,      anaUtils::GetPIDLikelihood( *(mybox().HMNtrack),0));
    output().FillVar(HMNT_tpc_like_e,       anaUtils::GetPIDLikelihood( *(mybox().HMNtrack),1));
    output().FillVar(HMNT_tpc_like_p,       anaUtils::GetPIDLikelihood( *(mybox().HMNtrack),2));
    output().FillVar(HMNT_tpc_like_pi,      anaUtils::GetPIDLikelihood( *(mybox().HMNtrack),3));
    
    //std::cout << "DEBUG: Filling FGD1 info..." << std::endl;
    
    AnaFGDParticle* FGD1Segment = static_cast<AnaFGDParticle*>(anaUtils::GetSegmentInDet( *mybox().HMNtrack,static_cast<SubDetId::SubDetEnum >(0)));
    if (FGD1Segment) 
    {
      output().FillVar(HMNT_has_fgd1seg,      1);
      output().FillVar(HMNT_fgd1_pull_mu,     FGD1Segment->Pullmu);
      output().FillVar(HMNT_fgd1_pull_e,      FGD1Segment->Pulle);
      output().FillVar(HMNT_fgd1_pull_p,      FGD1Segment->Pullp);
      output().FillVar(HMNT_fgd1_pull_pi,     FGD1Segment->Pullpi);
      output().FillVar(HMNT_fgd1_pull_no,     FGD1Segment->Pullno);
    }
    else
    {
      output().FillVar(HMNT_has_fgd1seg,      0);
    }
    
    //std::cout << "DEBUG: Filling FGD2 info..." << std::endl;
    
    AnaFGDParticle* FGD2Segment = static_cast<AnaFGDParticle*>(anaUtils::GetSegmentInDet( *mybox().HMNtrack,static_cast<SubDetId::SubDetEnum >(1)));
    if (FGD2Segment) 
    {
      output().FillVar(HMNT_has_fgd2seg,      1);
      output().FillVar(HMNT_fgd2_pull_mu,     FGD2Segment->Pullmu);
      output().FillVar(HMNT_fgd2_pull_e,      FGD2Segment->Pulle);
      output().FillVar(HMNT_fgd2_pull_p,      FGD2Segment->Pullp);
      output().FillVar(HMNT_fgd2_pull_pi,     FGD2Segment->Pullpi);
      output().FillVar(HMNT_fgd2_pull_no,     FGD2Segment->Pullno);
    }
    else
    {
      output().FillVar(HMNT_has_fgd2seg,      0);
    }
    
      //std::cout << "DEBUG: Filling BDT outputs..." << std::endl;
    
      std::vector<Float_t> BDT_PID_results_vector = myBDTPIDmanagerCC1pi->GetBDTPIDVarsPos(mybox().HMNtrack, mybox().HMNTLocalECalSegment);
    
      output().FillVar(hmnt_bdt_pid_mu, BDT_PID_results_vector[0]);
      output().FillVar(hmnt_bdt_pid_pi, BDT_PID_results_vector[1]);
      output().FillVar(hmnt_bdt_pid_p, BDT_PID_results_vector[2]);
      output().FillVar(hmnt_bdt_pid_e, BDT_PID_results_vector[3]);
    
      //output().FillVar(hmnt_bdt_pid_pi_cc1pi, BDT_PID_results_vector[1]);
    
      /*BDT_PID_results_vector = myBDTPIDmanagerCC1pi->GetBDTPIDVarsPos(mybox().HMNtrack, mybox().HMNTLocalECalSegment, "BDTG_default");
      output().FillVar(hmnt_bdt_pid_pi_test1, BDT_PID_results_vector[1]);
    
      BDT_PID_results_vector = myBDTPIDmanagerCC1pi->GetBDTPIDVarsPos(mybox().HMNtrack, mybox().HMNTLocalECalSegment, "BDTG_default");
      output().FillVar(hmnt_bdt_pid_pi_test2, BDT_PID_results_vector[1]);
    
      BDT_PID_results_vector = myBDTPIDmanagerCC1pi->GetBDTPIDVarsPos(mybox().HMNtrack, mybox().HMNTLocalECalSegment, "BDTG_default");
      output().FillVar(hmnt_bdt_pid_pi_test3, BDT_PID_results_vector[1]);
    
      BDT_PID_results_vector = myBDTPIDmanagerCC1pi->GetBDTPIDVarsPos(mybox().HMNtrack, mybox().HMNTLocalECalSegment, "BDTG_default");
      output().FillVar(hmnt_bdt_pid_pi_test4, BDT_PID_results_vector[1]);
    
      BDT_PID_results_vector = myBDTPIDmanagerCC1pi->GetBDTPIDVarsPos(mybox().HMNtrack, mybox().HMNTLocalECalSegment, "BDTG_default");
      output().FillVar(hmnt_bdt_pid_pi_test5, BDT_PID_results_vector[1]);*/
      
    
      //BDT_PID_results_vector = myBDTPIDmanagerCC1pi->GetBDTPIDVars(mybox().HMNtrack, mybox().HMNTLocalECalSegment, "BDTG_tree3_noweights");
      //output().FillVar(hmnt_bdt_pid_unweighted_pi_cc1pi, BDT_PID_results_vector[1]);
    
    //std::cout << "DEBUG: Finished filling HMNT variables." << std::endl;
    
  }

  
  baseTrackerAnalysis::FillEffCounters();
    
}

//********************************************************************
void antiNumuCC1piAnalysis::FillToyVarsInMicroTrees(bool addBase){
//********************************************************************
 
  //if(_runMultiTrack){
    //_antiNumuCCAnalysis->FillToyVarsInMicroTrees(addBase);
  //}
  //else{
    //_numuCCMultiPiAnalysis->FillToyVarsInMicroTrees(addBase); 
  //}
  
  _antiNumuCCMultiPiAnalysis->FillToyVarsInMicroTrees(addBase); 
  
}

//********************************************************************
bool antiNumuCC1piAnalysis::CheckFillTruthTree(const AnaTrueVertex& vtx){
//********************************************************************

  SubDetId::SubDetEnum fgdID;
  if (_whichFGD == 1) fgdID = SubDetId::kFGD1;
  if (_whichFGD == 2) fgdID = SubDetId::kFGD2;
  if (_whichFGD == 3) fgdID = SubDetId::kFGD;

  bool IsAntinu = true;

  // GetReactionCC already takes into account the outFV and also
  // the NuWro reaction code for 2p2h in prod5 (that is 70)
  bool antiNumuCCinFV = (anaUtils::GetReactionCC(vtx, fgdID, IsAntinu) == 1);

  // Since our topology definition doesn't consider the reaction code
  // and since a muon pair can be created in the FSI (likely in DIS)
  // in principle we might have a non-CC vertex categorized as CCother
  // (nevertheless I didn't find any)
  int topo = anaUtils::GetTopology(vtx, fgdID, IsAntinu);
  bool topoCCinFV = (topo == 0 || topo == 1 || topo == 2);

  return (antiNumuCCinFV || topoCCinFV);  
}

//********************************************************************
void antiNumuCC1piAnalysis::FillTruthTree(const AnaTrueVertex& vtx){
//********************************************************************

  //_antiNumuCCAnalysis->FillTruthTree(vtx);
  
  //if (!_runMultiTrack){
    //_numuCCMultiPiAnalysis->FillTruePionInfo(vtx); 
  //}
  
  _antiNumuCCMultiPiAnalysis->FillTruthTree(vtx);
  
  output().FillVar(particle_pg, vtx.TrueParticles[0]->PDG);
  
  TVector3 muDirVec = anaUtils::ArrayToTVector3(vtx.TrueParticles[0]->Direction);
  Float_t muDirCostheta = muDirVec[2];
  
  output().FillVar(pg_trueparticle_mom, vtx.TrueParticles[0]->Momentum);
  output().FillVar(pg_trueparticle_costheta, muDirCostheta);
}

//********************************************************************
void antiNumuCC1piAnalysis::FillCategories(){
//********************************************************************

  _antiNumuCCMultiPiAnalysis->FillCategories();

}

//********************************************************************
/*void antiNumuCC1piAnalysis::ResetBDTInputVariables(){
//********************************************************************

  bdt_mom              = 0.0;
  bdt_theta            = 0.0;
  bdt_ecal_EMenergy    = -100.0;
  bdt_ecal_EbyP        = -1.0;
  bdt_ecal_EbyL        = -1.0; 
  bdt_ecal_circularity = -0.5; 
  bdt_ecal_fbr         = -5.0;
  bdt_ecal_tmr         = -0.2;
  bdt_ecal_qrms        = -0.1;
  bdt_tpc_like_mu      = -1.0; 
  bdt_tpc_like_e       = -1.0;
  bdt_tpc_like_p       = -1.0; 
  bdt_tpc_like_pi      = -1.0;
  bdt_fgd1pullmu       = -30.0; 
  bdt_fgd1pullp        = -30.0;
  bdt_fgd1pullpi       = -30.0; 
  bdt_fgd2pullmu       = -30.0; 
  bdt_fgd2pullp        = -30.0;
  bdt_fgd2pullpi       = -30.0;

}*/
