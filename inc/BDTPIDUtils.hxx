#ifndef BDTPIDUtils_h
#define BDTPIDUtils_h

#include "DataClasses.hxx"
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "HighlandAnalysisUtils.hxx"
#include "NuDirUtils.hxx"

class BDTPIDmanager{
  public:
    BDTPIDmanager();
    virtual ~BDTPIDmanager();
    
    std::vector<Float_t> GetBDTPIDVars(const AnaTrackB& track, const AnaTECALReconObject& localecalsegment);
  
  protected:
    TMVA::Reader* tmvareader;
    // NOTE: Need to add default values in GetVars function
    Float_t bdt_mom, bdt_theta;
    Float_t bdt_ecal_EMenergy, bdt_ecal_EbyP, bdt_ecal_EbyL, bdt_ecal_circularity, bdt_ecal_fbr, bdt_ecal_tmr, bdt_ecal_qrms;
    Float_t bdt_tpc_like_mu, bdt_tpc_like_e, bdt_tpc_like_p, bdt_tpc_like_pi;
    Float_t bdt_fgd1pullmu, bdt_fgd1pullp, bdt_fgd1pullpi, bdt_fgd2pullmu, bdt_fgd2pullp, bdt_fgd2pullpi;
    
};

// Insert methods into a namespace.
//namespace BDTPIDUtils {

//  std::vector<Float_t> GetBDTPIDVars(const AnaTrackB& track, const AnaTECALReconObject& localecalsegment);
  
//}

#endif
