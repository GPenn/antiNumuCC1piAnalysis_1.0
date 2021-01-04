#!/bin/bash 
#! This file was autogenerated by ND280_END_PROJECT 
 [  -z "$1" ] && set -e 
 ND280_NJOBS="${ND280_NJOBS:=1}" 
  
export ND280_NJOBS=${ND280_NJOBS}
function shout {
  echo "+=======================================+" 
 echo "+                                       +" 
 echo "   Build of package baseTrackerAnalysis_2.21 in  /hepstore/gpenn/nd280gitlab/12.31/baseTrackerAnalysis_2.21  FAILED          " 
 echo "+                                       +" 
 echo "+=======================================+" 
 exit 1 
 } 
 trap shout ERR 
  echo "" ; echo " Building baseTrackerAnalysis_2.21  ( package number " 19 " out of " 24 " ) " ; echo "" 
   makeTarget=$1 
  if [ "$1" == "documentation" ] ; then makeTarget=baseTrackerAnalysis_$1 ; fi 
   cd  /hepstore/gpenn/nd280gitlab/12.31/baseTrackerAnalysis_2.21 
 SYS_DIR=`nd280-system` 
  [ -d ${SYS_DIR} ] || mkdir ${SYS_DIR} 
  cd  ${SYS_DIR} 
  [ -d inc ] || mkdir inc 
  [ -d bin ] || mkdir bin 
  [ -d lib ] || mkdir lib 
  cmake ../cmake 
 [ -f ../bin/setup.sh ] && . ../bin/setup.sh 
  make -j ${ND280_NJOBS}  ${makeTarget} ;
