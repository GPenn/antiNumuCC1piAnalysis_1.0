#!/bin/bash 
 set -e 
ND280_SYSTEM=`nd280-system` 
export ND280_NJOBS=${ND280_NJOBS:=1}
  if [ -f /hepstore/gpenn/nd280gitlab/12.31/MYSQL_5.6.20.01/cmake/CMakeLists.txt ] ; then
  echo " cd  /hepstore/gpenn/nd280gitlab/12.31/MYSQL_5.6.20.01/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackageMYSQL.sh 
  fi 
    if [ -f /hepstore/gpenn/nd280gitlab/12.31/GSL_1.15.0.00/cmake/CMakeLists.txt ] ; then
  echo " cd  /hepstore/gpenn/nd280gitlab/12.31/GSL_1.15.0.00/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackageGSL.sh 
  fi 
    if [ -f /hepstore/gpenn/nd280gitlab/12.31/ROOT_5.34.34.00/cmake/CMakeLists.txt ] ; then
  echo " cd  /hepstore/gpenn/nd280gitlab/12.31/ROOT_5.34.34.00/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackageROOT.sh 
  fi 
    if [ -f /hepstore/gpenn/nd280gitlab/12.31/psycheCore_3.41/cmake/CMakeLists.txt ] ; then
  echo " cd  /hepstore/gpenn/nd280gitlab/12.31/psycheCore_3.41/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagepsycheCore.sh 
  fi 
    if [ -f /hepstore/gpenn/nd280gitlab/12.31/psycheEventModel_3.38/cmake/CMakeLists.txt ] ; then
  echo " cd  /hepstore/gpenn/nd280gitlab/12.31/psycheEventModel_3.38/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagepsycheEventModel.sh 
  fi 
    if [ -f /hepstore/gpenn/nd280gitlab/12.31/psycheUtils_3.34/cmake/CMakeLists.txt ] ; then
  echo " cd  /hepstore/gpenn/nd280gitlab/12.31/psycheUtils_3.34/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagepsycheUtils.sh 
  fi 
    if [ -f /hepstore/gpenn/nd280gitlab/12.31/psycheND280Utils_3.57/cmake/CMakeLists.txt ] ; then
  echo " cd  /hepstore/gpenn/nd280gitlab/12.31/psycheND280Utils_3.57/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagepsycheND280Utils.sh 
  fi 
    if [ -f /hepstore/gpenn/nd280gitlab/12.31/psycheIO_3.32/cmake/CMakeLists.txt ] ; then
  echo " cd  /hepstore/gpenn/nd280gitlab/12.31/psycheIO_3.32/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagepsycheIO.sh 
  fi 
    if [ -f /hepstore/gpenn/nd280gitlab/12.31/highlandCore_2.37/cmake/CMakeLists.txt ] ; then
  echo " cd  /hepstore/gpenn/nd280gitlab/12.31/highlandCore_2.37/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagehighlandCore.sh 
  fi 
    if [ -f /hepstore/gpenn/nd280gitlab/12.31/oaAnalysisReader_2.21/cmake/CMakeLists.txt ] ; then
  echo " cd  /hepstore/gpenn/nd280gitlab/12.31/oaAnalysisReader_2.21/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackageoaAnalysisReader.sh 
  fi 
    if [ -f /hepstore/gpenn/nd280gitlab/12.31/highlandEventModel_2.31/cmake/CMakeLists.txt ] ; then
  echo " cd  /hepstore/gpenn/nd280gitlab/12.31/highlandEventModel_2.31/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagehighlandEventModel.sh 
  fi 
    if [ -f /hepstore/gpenn/nd280gitlab/12.31/highlandUtils_2.34/cmake/CMakeLists.txt ] ; then
  echo " cd  /hepstore/gpenn/nd280gitlab/12.31/highlandUtils_2.34/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagehighlandUtils.sh 
  fi 
    if [ -f /hepstore/gpenn/nd280gitlab/12.31/psycheSelections_3.46/cmake/CMakeLists.txt ] ; then
  echo " cd  /hepstore/gpenn/nd280gitlab/12.31/psycheSelections_3.46/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagepsycheSelections.sh 
  fi 
    if [ -f /hepstore/gpenn/nd280gitlab/12.31/psycheSystematics_3.44/cmake/CMakeLists.txt ] ; then
  echo " cd  /hepstore/gpenn/nd280gitlab/12.31/psycheSystematics_3.44/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagepsycheSystematics.sh 
  fi 
    if [ -f /hepstore/gpenn/nd280gitlab/12.31/highlandCorrections_2.21/cmake/CMakeLists.txt ] ; then
  echo " cd  /hepstore/gpenn/nd280gitlab/12.31/highlandCorrections_2.21/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagehighlandCorrections.sh 
  fi 
    if [ -f /hepstore/gpenn/nd280gitlab/12.31/highlandIO_2.41/cmake/CMakeLists.txt ] ; then
  echo " cd  /hepstore/gpenn/nd280gitlab/12.31/highlandIO_2.41/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagehighlandIO.sh 
  fi 
    if [ -f /hepstore/gpenn/nd280gitlab/12.31/highlandTools_2.29/cmake/CMakeLists.txt ] ; then
  echo " cd  /hepstore/gpenn/nd280gitlab/12.31/highlandTools_2.29/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagehighlandTools.sh 
  fi 
    if [ -f /hepstore/gpenn/nd280gitlab/12.31/baseAnalysis_2.33/cmake/CMakeLists.txt ] ; then
  echo " cd  /hepstore/gpenn/nd280gitlab/12.31/baseAnalysis_2.33/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagebaseAnalysis.sh 
  fi 
    if [ -f /hepstore/gpenn/nd280gitlab/12.31/baseTrackerAnalysis_2.21/cmake/CMakeLists.txt ] ; then
  echo " cd  /hepstore/gpenn/nd280gitlab/12.31/baseTrackerAnalysis_2.21/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagebaseTrackerAnalysis.sh 
  fi 
    if [ -f /hepstore/gpenn/nd280gitlab/12.31/numuCCAnalysis_2.21/cmake/CMakeLists.txt ] ; then
  echo " cd  /hepstore/gpenn/nd280gitlab/12.31/numuCCAnalysis_2.21/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagenumuCCAnalysis.sh 
  fi 
    if [ -f /hepstore/gpenn/nd280gitlab/12.31/antiNumuCCAnalysis_2.7/cmake/CMakeLists.txt ] ; then
  echo " cd  /hepstore/gpenn/nd280gitlab/12.31/antiNumuCCAnalysis_2.7/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackageantiNumuCCAnalysis.sh 
  fi 
    if [ -f /hepstore/gpenn/nd280gitlab/12.31/numuCCMultiPiAnalysis_2.25/cmake/CMakeLists.txt ] ; then
  echo " cd  /hepstore/gpenn/nd280gitlab/12.31/numuCCMultiPiAnalysis_2.25/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagenumuCCMultiPiAnalysis.sh 
  fi 
    if [ -f /hepstore/gpenn/nd280gitlab/12.31/antiNumuCCMultiPiAnalysis_2.11/cmake/CMakeLists.txt ] ; then
  echo " cd  /hepstore/gpenn/nd280gitlab/12.31/antiNumuCCMultiPiAnalysis_2.11/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackageantiNumuCCMultiPiAnalysis.sh 
  fi 
    if [ -f /hepstore/gpenn/nd280gitlab/12.31/antiNumuCC1piAnalysis_1.0/cmake/CMakeLists.txt ] ; then
  echo " cd  /hepstore/gpenn/nd280gitlab/12.31/antiNumuCC1piAnalysis_1.0/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackageantiNumuCC1piAnalysis.sh 
  fi 
  find ../bin -name 'cmakePackage*.sh' -print0 | xargs -0 -I NAME -P ${ND280_NJOBS} /bin/bash NAME "$1" 
