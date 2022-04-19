#ifndef BDTPIDUtils_h
#define BDTPIDUtils_h

#include "DataClasses.hxx"
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "HighlandAnalysisUtils.hxx"
#include "NuDirUtils.hxx"
#include "ToyBoxTracker.hxx"
#include "CutUtils.hxx"
#include "numuCCMultiPiSelection.hxx"

class BDTPIDmanager{
  public:
    BDTPIDmanager();
    virtual ~BDTPIDmanager(){delete tmvareader;}
    
    //std::vector<Float_t> GetBDTPIDVars(const AnaTrackB& track, const AnaTECALReconObject& localecalsegment);
  std::vector<Float_t> GetBDTPIDVarsPos(AnaTrackB* track, AnaTECALReconObject* localecalsegment, TString BDTname="BDTG_tuned");
  std::vector<Float_t> GetBDTPIDVarsNeg(AnaTrackB* track, AnaTECALReconObject* localecalsegment, TString BDTname="BDTG_tree3_neg");
  
  bool GetBDTPIDValidity(AnaTrackB* track);
  
  protected:
    TMVA::Reader* tmvareader;
    // NOTE: Need to add default values in GetVars function
    Float_t bdt_mom, bdt_theta;
    Float_t bdt_ecal_EMenergy, bdt_ecal_EbyP, bdt_ecal_EbyL, bdt_ecal_circularity, bdt_ecal_fbr, bdt_ecal_tmr, bdt_ecal_qrms, bdt_ecal_mipem, bdt_ecal_emhip, bdt_ecal_mippion;
    Float_t bdt_tpc_like_mu, bdt_tpc_like_e, bdt_tpc_like_p, bdt_tpc_like_pi, bdt_tpc2_dedx, bdt_tpc3_dedx, bdt_tpc2_pullmu, bdt_tpc2_pullpi, bdt_tpc2_pullp, bdt_tpc2_pulle, bdt_tpc3_pullmu, bdt_tpc3_pullpi, bdt_tpc3_pullp, bdt_tpc3_pulle;
    Float_t bdt_fgd1pullmu, bdt_fgd1pullp, bdt_fgd1pullpi, bdt_fgd2pullmu, bdt_fgd2pullp, bdt_fgd2pullpi, bdt_fgd1_EbyL, bdt_fgd2_EbyL;
    Float_t bdt_nsmrds, bdt_ntpcs;
    
    bool ignoreBDTvalidity = true;
};


// Apply BDT kinematics preselection cut
class BDTPreselectionKinematicsCut: public StepBase{
public:
  using StepBase::Apply;
  bool Apply(AnaEventC& event, ToyBoxB& box) const;
  StepBase* MakeClone(){return new BDTPreselectionKinematicsCut();}
};

// Apply BDT kinematics preselection cut (CC1pi pi- candidate)
class BDTPreselectionKinematicsPiCandCut: public StepBase{
public:
  using StepBase::Apply;
  bool Apply(AnaEventC& event, ToyBoxB& box) const;
  StepBase* MakeClone(){return new BDTPreselectionKinematicsPiCandCut();}
};


#endif
