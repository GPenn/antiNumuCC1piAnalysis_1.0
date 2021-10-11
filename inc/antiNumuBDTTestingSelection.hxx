#ifndef antiNumuBDTTestingSelection_h
#define antiNumuBDTTestingSelection_h

#include "TMVA/Tools.h"
#include "TMVA/Reader.h"

#include "SelectionBase.hxx"
#include "antiNumuCC1piSelection.hxx"
#include "InputManager.hxx"
#include "DataClasses.hxx"



typedef std::vector<AnaTECALReconObject*>        AnaTECALObjectVec;

class antiNumuBDTTestingSelection: public SelectionBase{
public:
  antiNumuBDTTestingSelection(bool forceBreak=true, InputManager *INPUT=NULL);
  virtual ~antiNumuBDTTestingSelection(){}


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
    _antiNumuCC1piSelection.SetDetectorFV(det, ibranch); 
  }



protected:
  //antiNumuCCSelection _antiNumuCCSelection;
  //numuCCMultiPiSelection _numuCCMultiPiSelection;
  antiNumuCC1piSelection _antiNumuCC1piSelection;
  InputManager* _input;
  BDTPIDmanager* myBDTPIDmanager;
  
  Int_t _MuonPIDCutIndex;
  Int_t _FindPionsStepIndex; 
  bool  _useECalPiZeroInfo;
};

inline ToyBoxB* antiNumuBDTTestingSelection::MakeToyBox(){return new ToyBoxAntiCC1Pi();}


#endif
