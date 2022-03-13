#ifndef antiNumuCC1piSelection_h
#define antiNumuCC1piSelection_h

#include "TMVA/Tools.h"
#include "TMVA/Reader.h"

#include "SelectionBase.hxx"
#include "antiNumuCCMultiPiSelection.hxx"
#include "InputManager.hxx"
#include "DataClasses.hxx"
#include "BDTPIDUtils.hxx"


typedef std::vector<AnaTECALReconObject*>        AnaTECALObjectVec;

class antiNumuCC1piSelection: public SelectionBase{
public:
  antiNumuCC1piSelection(bool forceBreak=true, InputManager *INPUT=NULL, BDTPIDmanager *BDTPID=NULL);
  virtual ~antiNumuCC1piSelection(){}

  //---- These are mandatory functions
  void DefineSteps();
  void DefineDetectorFV();
  
  ToyBoxB* MakeToyBox(); 
  bool FillEventSummary(AnaEventC& event, Int_t allCutsPassed[]);
  SampleId_h GetSampleId(){return SampleId::kFGD1AntiNuMuCC0Pi;}
  bool IsRelevantRecObjectForSystematic(const AnaEventC& event, AnaRecObjectC* recObj, SystId_h systId, Int_t branch) const;
  bool IsRelevantTrueObjectForSystematic(const AnaEventC& event, AnaTrueObjectC* trueObj, SystId_h systId, Int_t branch) const;
  bool IsRelevantSystematic(const AnaEventC& event, const ToyBoxB& box, SystId_h systId, Int_t branch) const;
  void InitializeEvent(AnaEventC& event);
  bool CheckRedoSelection(const AnaEventC& event, const ToyBoxB& PreviousToyBox, Int_t& redoFromStep);
   
  bool IsRelevantRecObjectForSystematicInToy(const AnaEventC& event, const ToyBoxB& box, AnaRecObjectC* recObj, SystId_h systId, Int_t branch) const;
  bool IsRelevantTrueObjectForSystematicInToy(const AnaEventC& event, const ToyBoxB& box, AnaTrueObjectC* trueTrack, SystId_h systId, Int_t branch) const;
  
  Int_t GetRelevantRecObjectGroupsForSystematic(SystId_h systId, Int_t* IDs, Int_t branch) const;    
  Int_t GetRelevantTrueObjectGroupsForSystematic(SystId_h systId, Int_t* IDs, Int_t branch) const;
 
  void SetDetectorFV(SubDetId_h det, Int_t ibranch=-1){
    SelectionBase::SetDetectorFV(det, ibranch);
    // Set to the selection that are used
    _antiNumuCCSelection.SetDetectorFV(det, ibranch); 
    //_numuCCMultiPiSelection.SetDetectorFV(det, ibranch); 
    _antiNumuCCMultiPiSelection.SetDetectorFV(det, ibranch); 
  }



protected:
  antiNumuCCSelection _antiNumuCCSelection;
  //numuCCMultiPiSelection _numuCCMultiPiSelection;
  antiNumuCCMultiPiSelection _antiNumuCCMultiPiSelection;
  InputManager* _input;
  BDTPIDmanager* _bdtpid;
  
  Int_t _MuonPIDCutIndex;
  Int_t _FindPionsStepIndex; 
  bool  _useECalPiZeroInfo;
};

class ToyBoxAntiCC1Pi: public ToyBoxAntiCCMultiPi{

public:
  ToyBoxAntiCC1Pi(){}

  virtual ~ToyBoxAntiCC1Pi(){
    Reset();
  }
  
  void Reset(){

    ToyBoxCCMultiPi::Reset();
  
    TECALReconObjects.clear();
    FGD1GoodTPCTrackLocalECalSegments.clear();
    
    MainTrackLocalECalSegment = NULL;
    HMNTLocalECalSegment = NULL;
  
  }
  
  // These objects need to be read from the additional tecalRecon information in AnaLocalReconBunch
  AnaTECALObjectVec TECALReconObjects;
  
  // Local reco ECal segments matched to those of the main tracks:
  AnaTECALReconObject* MainTrackLocalECalSegment;
  AnaTECALReconObject* HMNTLocalECalSegment;
  AnaTECALObjectVec FGD1GoodTPCTrackLocalECalSegments;

};


//Insert methods into a namespace.
namespace BDTPIDUtils {

//  std::vector<Float_t> GetBDTPIDVars(const AnaTrackB& track, const AnaTECALReconObject& localecalsegment);
  
  void FillPionInfo(const AnaEventC& event, multipart::MultiParticleBox& pionBox, const multipart::PionSelectionParams& params, 
                    BDTPIDmanager* bdtpidmanager, ToyBoxAntiCC1Pi* anticc1pibox);
  
  void FillProtonInfo(const AnaEventC& event, multipart::MultiParticleBox& protonBox, const multipart::ProtonSelectionParams& params, 
                      BDTPIDmanager* bdtpidmanager, ToyBoxAntiCC1Pi* anticc1pibox);
  
  void FindGoodQualityTPCPionInfoInFGDFV(const AnaEventC& event, const AnaTrackB* reftrack, multipart::MultiParticleBox& pionBox, 
      bool useOldSecondaryPID, BDTPIDmanager* bdtpidmanager, ToyBoxAntiCC1Pi* anticc1pibox);
  
  void FindGoodQualityTPCPionInfo(const AnaEventC& event, const AnaTrackB* reftrack, multipart::MultiParticleBox& pionBox, 
      EventBoxTracker::RecObjectGroupEnum groupID, 
      bool useOldSecondaryPID, BDTPIDmanager* bdtpidmanager, ToyBoxAntiCC1Pi* anticc1pibox);
  
  void FindGoodQualityTPCProtonsInFGDFV(const AnaEventC& event, multipart::MultiParticleBox& protonBox,
      const multipart::ProtonSelectionParams& params, BDTPIDmanager* bdtpidmanager, ToyBoxAntiCC1Pi* anticc1pibox);
   
  void FindGoodQualityTPCProtons(const AnaEventC& event, multipart::MultiParticleBox& protonBox, 
      const multipart::ProtonSelectionParams& params, 
      EventBoxTracker::RecObjectGroupEnum groupID, BDTPIDmanager* bdtpidmanager, ToyBoxAntiCC1Pi* anticc1pibox);
}



inline ToyBoxB* antiNumuCC1piSelection::MakeToyBox(){return new ToyBoxAntiCC1Pi();}



class FillSummaryAction_antinuCC1pi: public StepBase{
public:
  using StepBase::Apply;
  bool Apply(AnaEventC& event, ToyBoxB& box) const;  
  StepBase* MakeClone(){return new FillSummaryAction_antinuCC1pi();}
};

class FindPionsAction_antinuCC1pi: public StepBase{
public:
  using StepBase::Apply;
  FindPionsAction_antinuCC1pi(){
    pionSelParams.useTPCPions                 = (bool)ND::params().GetParameterI("psycheSelections.antinumuCCMultiPi.UseTPCPions");
    pionSelParams.useME                       = (bool)ND::params().GetParameterI("psycheSelections.antinumuCCMultiPi.UseME");
    pionSelParams.useFGDPions                 = (bool)ND::params().GetParameterI("psycheSelections.antinumuCCMultiPi.UseFGDPions");
    pionSelParams.useOldSecondaryPID          = (bool)ND::params().GetParameterI("psycheSelections.antinumuCCMultiPi.OldSecondaryPID");
    pionSelParams.useECalPiZeroInfo           = (bool)ND::params().GetParameterI("psycheSelections.antinumuCCMultiPi.UseECalPiZeroInfo");
    
    pionSelParams.ECalMostUpstreamLayerHitCut = (Int_t)ND::params().GetParameterI("psycheSelections.antinumuCCMultiPi.MostUpstreamLayerHitCut");
    // Default
    pionSelParams.ECalEMEnergyCut = 30.;
    pionSelParams.ECalPIDMipEmCut = 0.;
  } 
  bool Apply(AnaEventC& event, ToyBoxB& box) const;  
  StepBase* MakeClone(){return new FindPionsAction_antinuCC1pi();}

protected:
  mutable multipart::PionSelectionParams pionSelParams;
};

//--------------
// My cuts

class MyDummyCut: public StepBase{
public:
  using StepBase::Apply;
  bool Apply(AnaEventC& event, ToyBoxB& box) const;
  StepBase* MakeClone(){return new MyDummyCut();}
};

class AntiMuonPIDCut_Loop: public StepBase{
public:
  using StepBase::Apply;
  bool Apply(AnaEventC& event, ToyBoxB& box) const;
  StepBase* MakeClone(){return new AntiMuonPIDCut_Loop();}
};

class AntiMuonPIDCut_LoopBDTPID: public StepBase{
public:
  using StepBase::Apply;
  AntiMuonPIDCut_LoopBDTPID(BDTPIDmanager *bdtpidmanager=NULL){
    _bdtpidmanager = bdtpidmanager;
    if (!bdtpidmanager) std::cout << "!!!" << std::endl << "DEBUG: NO BDT PID MANAGER FOUND!" << std::endl << "!!!" << std::endl;
  }
  bool Apply(AnaEventC& event, ToyBoxB& box) const;
  StepBase* MakeClone(){return new AntiMuonPIDCut_LoopBDTPID();}
  
  BDTPIDmanager* _bdtpidmanager;
};

class MuonWithECalSegmentsCut: public StepBase{
public:
  using StepBase::Apply;
  bool Apply(AnaEventC& event, ToyBoxB& box) const;
  StepBase* MakeClone(){return new MuonWithECalSegmentsCut();}
};

class MuonWithoutECalSegmentsCut: public StepBase{
public:
  using StepBase::Apply;
  bool Apply(AnaEventC& event, ToyBoxB& box) const;
  StepBase* MakeClone(){return new MuonWithoutECalSegmentsCut();}
};

class MuonECalEMEnergyLengthCut: public StepBase{
public:
  using StepBase::Apply;
  bool Apply(AnaEventC& event, ToyBoxB& box) const;
  StepBase* MakeClone(){return new MuonECalEMEnergyLengthCut();}
};

class MuonECalMipPionCut: public StepBase{
public:
  using StepBase::Apply;
  bool Apply(AnaEventC& event, ToyBoxB& box) const;
  StepBase* MakeClone(){return new MuonECalMipPionCut();}
};

class PionECalEMEnergyLengthCut: public StepBase{
public:
  using StepBase::Apply;
  bool Apply(AnaEventC& event, ToyBoxB& box) const;
  StepBase* MakeClone(){return new PionECalEMEnergyLengthCut();}
};

class OptimisedMuonECalPIDCut: public StepBase{
public:
  using StepBase::Apply;
  bool Apply(AnaEventC& event, ToyBoxB& box) const;
  StepBase* MakeClone(){return new OptimisedMuonECalPIDCut();}
};

class ReoptimisedMuonECalPIDCut: public StepBase{
public:
  using StepBase::Apply;
  bool Apply(AnaEventC& event, ToyBoxB& box) const;
  StepBase* MakeClone(){return new ReoptimisedMuonECalPIDCut();}
};

class ReoptimisedMuonECalPIDCut_ifnoBDT: public StepBase{
public:
  using StepBase::Apply;
  bool Apply(AnaEventC& event, ToyBoxB& box) const;
  StepBase* MakeClone(){return new ReoptimisedMuonECalPIDCut_ifnoBDT();}
};

class OptimisedPionECalPIDCut: public StepBase{
public:
  using StepBase::Apply;
  bool Apply(AnaEventC& event, ToyBoxB& box) const;
  StepBase* MakeClone(){return new OptimisedPionECalPIDCut();}
};

class ReoptimisedPionECalPIDCut: public StepBase{
public:
  using StepBase::Apply;
  bool Apply(AnaEventC& event, ToyBoxB& box) const;
  StepBase* MakeClone(){return new ReoptimisedPionECalPIDCut();}
};

class ReoptimisedPionECalPIDCut_ifnoBDT: public StepBase{
public:
  using StepBase::Apply;
  bool Apply(AnaEventC& event, ToyBoxB& box) const;
  StepBase* MakeClone(){return new ReoptimisedPionECalPIDCut_ifnoBDT();}
};

// GetAllTECALReconObjects from the AnaLocalReconBunch
class GetAllTECALReconObjectsAction: public StepBase{
public:
  using StepBase::Apply;
  GetAllTECALReconObjectsAction(InputManager *INPUT=NULL){
    _input     = INPUT;
    if (!INPUT) std::cout << "!!!" << std::endl << "DEBUG: NO INPUT MANAGER FOUND!" << std::endl << "!!!" << std::endl;
  }
  InputManager* _input;
  bool      Apply    (AnaEventC& event, ToyBoxB& box) const;
  StepBase* MakeClone(){return new GetAllTECALReconObjectsAction(_input);}
};

// Match to local reconstruction
class MatchECalGlobalToLocalObjectsAction: public StepBase{
public:
  using StepBase::Apply;
  MatchECalGlobalToLocalObjectsAction(){}
  bool      Apply    (AnaEventC& event, ToyBoxB& box) const;
  StepBase* MakeClone(){return new MatchECalGlobalToLocalObjectsAction();}
};

class BDTPIDMuLikeCut: public StepBase{
public:
  using StepBase::Apply;
  BDTPIDMuLikeCut(BDTPIDmanager *bdtpidmanager=NULL){
    _bdtpidmanager = bdtpidmanager;
    if (!bdtpidmanager) std::cout << "!!!" << std::endl << "DEBUG: NO BDT PID MANAGER FOUND!" << std::endl << "!!!" << std::endl;
  }
  bool Apply(AnaEventC& event, ToyBoxB& box) const;
  StepBase* MakeClone(){return new BDTPIDMuLikeCut();}
  
  BDTPIDmanager* _bdtpidmanager;
};

class BDTPIDPiLikeCut: public StepBase{
public:
  using StepBase::Apply;
  BDTPIDPiLikeCut(BDTPIDmanager *bdtpidmanager=NULL){
    _bdtpidmanager = bdtpidmanager;
    if (!bdtpidmanager) std::cout << "!!!" << std::endl << "DEBUG: NO BDT PID MANAGER FOUND!" << std::endl << "!!!" << std::endl;
  }
  bool Apply(AnaEventC& event, ToyBoxB& box) const;
  StepBase* MakeClone(){return new BDTPIDPiLikeCut();}
  
  BDTPIDmanager* _bdtpidmanager;
};

class BDTPIDProtonLikeCut: public StepBase{
public:
  using StepBase::Apply;
  BDTPIDProtonLikeCut(BDTPIDmanager *bdtpidmanager=NULL){
    _bdtpidmanager = bdtpidmanager;
    if (!bdtpidmanager) std::cout << "!!!" << std::endl << "DEBUG: NO BDT PID MANAGER FOUND!" << std::endl << "!!!" << std::endl;
  }
  bool Apply(AnaEventC& event, ToyBoxB& box) const;
  StepBase* MakeClone(){return new BDTPIDProtonLikeCut();}
  
  BDTPIDmanager* _bdtpidmanager;
};

class BDTPIDElectronLikeCut: public StepBase{
public:
  using StepBase::Apply;
  BDTPIDElectronLikeCut(BDTPIDmanager *bdtpidmanager=NULL){
    _bdtpidmanager = bdtpidmanager;
    if (!bdtpidmanager) std::cout << "!!!" << std::endl << "DEBUG: NO BDT PID MANAGER FOUND!" << std::endl << "!!!" << std::endl;
  }
  bool Apply(AnaEventC& event, ToyBoxB& box) const;
  StepBase* MakeClone(){return new BDTPIDElectronLikeCut();}
  
  BDTPIDmanager* _bdtpidmanager;
};

// Two-track cut for antinumu CC1pi
class TwoTrack1pos1negCut: public StepBase{
public:
  using StepBase::Apply;
  bool Apply(AnaEventC& event, ToyBoxB& box) const;
  StepBase* MakeClone(){return new TwoTrack1pos1negCut();}
};

// Modified FindPionsAction
class FindPionsAction_BDTPID: public StepBase{
public:
  using StepBase::Apply;
  FindPionsAction_BDTPID(BDTPIDmanager *bdtpidmanager=NULL){
    pionSelParams.useTPCPions                 = (bool)ND::params().GetParameterI("psycheSelections.antinumuCCMultiPi.UseTPCPions");
    pionSelParams.useME                       = (bool)ND::params().GetParameterI("psycheSelections.antinumuCCMultiPi.UseME");
    pionSelParams.useFGDPions                 = (bool)ND::params().GetParameterI("psycheSelections.antinumuCCMultiPi.UseFGDPions");
    pionSelParams.useOldSecondaryPID          = (bool)ND::params().GetParameterI("psycheSelections.antinumuCCMultiPi.OldSecondaryPID");
    pionSelParams.useECalPiZeroInfo           = (bool)ND::params().GetParameterI("psycheSelections.antinumuCCMultiPi.UseECalPiZeroInfo");
    
    pionSelParams.ECalMostUpstreamLayerHitCut = (Int_t)ND::params().GetParameterI("psycheSelections.antinumuCCMultiPi.MostUpstreamLayerHitCut");
    // Default
    pionSelParams.ECalEMEnergyCut = 30.;
    pionSelParams.ECalPIDMipEmCut = 0.;
    
    _bdtpidmanager = bdtpidmanager;
  } 
  bool Apply(AnaEventC& event, ToyBoxB& box) const;  
  StepBase* MakeClone(){return new FindPionsAction_BDTPID();}
  
  BDTPIDmanager* _bdtpidmanager;
  
protected:
  mutable multipart::PionSelectionParams pionSelParams;
};


// Modified FindProtonsAction
class FindProtonsAction_BDTPID: public StepBase{
public:
 using StepBase::Apply;
 FindProtonsAction_BDTPID(BDTPIDmanager *bdtpidmanager=NULL){
   protonSelParams.tpcPIDCut  = (Float_t)ND::params().GetParameterD("psycheSelections.numuCCMultiPi.Protons.TPCPIDCut");
   protonSelParams.fgd1PIDCut = (Float_t)ND::params().GetParameterD("psycheSelections.numuCCMultiPi.Protons.FGD1PIDCut");
   protonSelParams.fgd2PIDCut = (Float_t)ND::params().GetParameterD("psycheSelections.numuCCMultiPi.Protons.FGD2PIDCut");
   
   _bdtpidmanager = bdtpidmanager;
 } 
 bool Apply(AnaEventC& event, ToyBoxB& box) const;  
 StepBase* MakeClone(){return new FindProtonsAction_BDTPID();}
  
 BDTPIDmanager* _bdtpidmanager;
  
protected:
  mutable multipart::ProtonSelectionParams protonSelParams;
};

#endif
