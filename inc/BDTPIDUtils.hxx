#ifndef BDTPIDUtils_h
#define BDTPIDUtils_h

#include "DataClasses.hxx"
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"


// Insert methods into a namespace.
namespace BDTPIDUtils {

  std::vector<Float_t> GetBDTPIDVars(const AnaTrackB& track, const AnaTECALReconObject& localecalsegment);
  
}

#endif