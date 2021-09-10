#!/bin/bash 
 set -e 
ND280_SYSTEM=`nd280-system` 
export ND280_NJOBS=${ND280_NJOBS:=1}
  if [ -f /user/gpenn/nd280software/nd280release_12.31/MYSQL_5.6.20.01/cmake/CMakeLists.txt ] ; then
  echo " cd  /user/gpenn/nd280software/nd280release_12.31/MYSQL_5.6.20.01/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackageMYSQL.sh 
  fi 
    if [ -f /user/gpenn/nd280software/nd280release_12.31/GSL_1.15.0.00/cmake/CMakeLists.txt ] ; then
  echo " cd  /user/gpenn/nd280software/nd280release_12.31/GSL_1.15.0.00/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackageGSL.sh 
  fi 
    if [ -f /user/gpenn/nd280software/nd280release_12.31/ROOT_5.34.34.00/cmake/CMakeLists.txt ] ; then
  echo " cd  /user/gpenn/nd280software/nd280release_12.31/ROOT_5.34.34.00/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackageROOT.sh 
  fi 
    if [ -f /user/gpenn/nd280software/nd280release_12.31/psycheCore_3.45/cmake/CMakeLists.txt ] ; then
  echo " cd  /user/gpenn/nd280software/nd280release_12.31/psycheCore_3.45/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagepsycheCore.sh 
  fi 
    if [ -f /user/gpenn/nd280software/nd280release_12.31/psycheEventModel_3.41/cmake/CMakeLists.txt ] ; then
  echo " cd  /user/gpenn/nd280software/nd280release_12.31/psycheEventModel_3.41/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagepsycheEventModel.sh 
  fi 
    if [ -f /user/gpenn/nd280software/nd280release_12.31/psycheUtils_3.34/cmake/CMakeLists.txt ] ; then
  echo " cd  /user/gpenn/nd280software/nd280release_12.31/psycheUtils_3.34/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagepsycheUtils.sh 
  fi 
    if [ -f /user/gpenn/nd280software/nd280release_12.31/psycheND280Utils_3.63/cmake/CMakeLists.txt ] ; then
  echo " cd  /user/gpenn/nd280software/nd280release_12.31/psycheND280Utils_3.63/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagepsycheND280Utils.sh 
  fi 
    if [ -f /user/gpenn/nd280software/nd280release_12.31/psycheIO_3.34/cmake/CMakeLists.txt ] ; then
  echo " cd  /user/gpenn/nd280software/nd280release_12.31/psycheIO_3.34/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagepsycheIO.sh 
  fi 
    if [ -f /user/gpenn/nd280software/nd280release_12.31/highlandCore_2.40/cmake/CMakeLists.txt ] ; then
  echo " cd  /user/gpenn/nd280software/nd280release_12.31/highlandCore_2.40/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagehighlandCore.sh 
  fi 
    if [ -f /user/gpenn/nd280software/nd280release_12.31/oaAnalysisReader_2.23/cmake/CMakeLists.txt ] ; then
  echo " cd  /user/gpenn/nd280software/nd280release_12.31/oaAnalysisReader_2.23/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackageoaAnalysisReader.sh 
  fi 
    if [ -f /user/gpenn/nd280software/nd280release_12.31/highlandEventModel_2.34/cmake/CMakeLists.txt ] ; then
  echo " cd  /user/gpenn/nd280software/nd280release_12.31/highlandEventModel_2.34/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagehighlandEventModel.sh 
  fi 
    if [ -f /user/gpenn/nd280software/nd280release_12.31/highlandUtils_2.36/cmake/CMakeLists.txt ] ; then
  echo " cd  /user/gpenn/nd280software/nd280release_12.31/highlandUtils_2.36/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagehighlandUtils.sh 
  fi 
    if [ -f /user/gpenn/nd280software/nd280release_12.31/psycheSelections_3.51/cmake/CMakeLists.txt ] ; then
  echo " cd  /user/gpenn/nd280software/nd280release_12.31/psycheSelections_3.51/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagepsycheSelections.sh 
  fi 
    if [ -f /user/gpenn/nd280software/nd280release_12.31/psycheSystematics_3.54/cmake/CMakeLists.txt ] ; then
  echo " cd  /user/gpenn/nd280software/nd280release_12.31/psycheSystematics_3.54/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagepsycheSystematics.sh 
  fi 
    if [ -f /user/gpenn/nd280software/nd280release_12.31/highlandCorrections_2.25/cmake/CMakeLists.txt ] ; then
  echo " cd  /user/gpenn/nd280software/nd280release_12.31/highlandCorrections_2.25/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagehighlandCorrections.sh 
  fi 
    if [ -f /user/gpenn/nd280software/nd280release_12.31/highlandIO_2.45/cmake/CMakeLists.txt ] ; then
  echo " cd  /user/gpenn/nd280software/nd280release_12.31/highlandIO_2.45/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagehighlandIO.sh 
  fi 
    if [ -f /user/gpenn/nd280software/nd280release_12.31/highlandTools_2.29/cmake/CMakeLists.txt ] ; then
  echo " cd  /user/gpenn/nd280software/nd280release_12.31/highlandTools_2.29/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagehighlandTools.sh 
  fi 
    if [ -f /user/gpenn/nd280software/nd280release_12.31/baseAnalysis_2.33/cmake/CMakeLists.txt ] ; then
  echo " cd  /user/gpenn/nd280software/nd280release_12.31/baseAnalysis_2.33/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagebaseAnalysis.sh 
  fi 
    if [ -f /user/gpenn/nd280software/nd280release_12.31/baseTrackerAnalysis_2.25/cmake/CMakeLists.txt ] ; then
  echo " cd  /user/gpenn/nd280software/nd280release_12.31/baseTrackerAnalysis_2.25/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagebaseTrackerAnalysis.sh 
  fi 
    if [ -f /user/gpenn/nd280software/nd280release_12.31/numuCCAnalysis_2.21/cmake/CMakeLists.txt ] ; then
  echo " cd  /user/gpenn/nd280software/nd280release_12.31/numuCCAnalysis_2.21/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagenumuCCAnalysis.sh 
  fi 
    if [ -f /user/gpenn/nd280software/nd280release_12.31/antiNumuCCAnalysis_2.7/cmake/CMakeLists.txt ] ; then
  echo " cd  /user/gpenn/nd280software/nd280release_12.31/antiNumuCCAnalysis_2.7/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackageantiNumuCCAnalysis.sh 
  fi 
    if [ -f /user/gpenn/nd280software/nd280release_12.31/numuCCMultiPiAnalysis_2.29/cmake/CMakeLists.txt ] ; then
  echo " cd  /user/gpenn/nd280software/nd280release_12.31/numuCCMultiPiAnalysis_2.29/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackagenumuCCMultiPiAnalysis.sh 
  fi 
    if [ -f /user/gpenn/nd280software/nd280release_12.31/antiNumuCCMultiPiAnalysis_2.12/cmake/CMakeLists.txt ] ; then
  echo " cd  /user/gpenn/nd280software/nd280release_12.31/antiNumuCCMultiPiAnalysis_2.12/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackageantiNumuCCMultiPiAnalysis.sh 
  fi 
    if [ -f /user/gpenn/nd280software/nd280release_12.31/antiNumuCC1piAnalysis_1.0/cmake/CMakeLists.txt ] ; then
  echo " cd  /user/gpenn/nd280software/nd280release_12.31/antiNumuCC1piAnalysis_1.0/${ND280_SYSTEM}/ ;cmake ../cmake ; " >../bin/cmakePackageantiNumuCC1piAnalysis.sh 
  fi 
  find ../bin -name 'cmakePackage*.sh' -print0 | xargs -0 -I NAME -P ${ND280_NJOBS} /bin/bash NAME "$1" "$2"  
