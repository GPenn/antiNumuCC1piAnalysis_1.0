#ifndef antiNumuCC1piSelection_h
#define antiNumuCC1piSelection_h

#include "SelectionBase.hxx"
#include "antiNumuCCMultiPiSelection.hxx"
#include "InputManager.hxx"
#include "DataClasses.hxx"

typedef std::vector<AnaTECALReconObject*>        AnaTECALObjectVec;

class antiNumuCC1piSelection: public SelectionBase{
public:
  antiNumuCC1piSelection(bool forceBreak=true, InputManager *INPUT=NULL);
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
    //_antiNumuCCSelection.SetDetectorFV(det, ibranch); 
    //_numuCCMultiPiSelection.SetDetectorFV(det, ibranch); 
    _antiNumuCCMultiPiSelection.SetDetectorFV(det, ibranch); 
  }



protected:
  //antiNumuCCSelection _antiNumuCCSelection;
  //numuCCMultiPiSelection _numuCCMultiPiSelection;
  antiNumuCCMultiPiSelection _antiNumuCCMultiPiSelection;
  InputManager* _input;
  
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
    
    MainTrackLocalECalSegment.clear();
  
  }
  
  // These objects need to be read from the additional tecalRecon information in AnaLocalReconBunch
  AnaTECALObjectVec TECALReconObjects;
  
  // Local reco ECal segments matched to those of the main tracks:
  AnaTECALReconObject MainTrackLocalECalSegment;
  //AnaTECALObject HMNTLocalECalSegment;


};

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

class AntiMuonPIDCut_Loop: public StepBase{
public:
  using StepBase::Apply;
  bool Apply(AnaEventC& event, ToyBoxB& box) const;
  StepBase* MakeClone(){return new AntiMuonPIDCut_Loop();}
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

class OptimisedPionECalPIDCut: public StepBase{
public:
  using StepBase::Apply;
  bool Apply(AnaEventC& event, ToyBoxB& box) const;
  StepBase* MakeClone(){return new OptimisedPionECalPIDCut();}
};

// GetAllTECALReconObjects from the AnaLocalReconBunch
class GetAllTECALReconObjectsAction: public StepBase{
public:
  using StepBase::Apply;
  GetAllTECALReconObjectsAction(InputManager *INPUT=NULL){
    _input     = INPUT;
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



#endif
