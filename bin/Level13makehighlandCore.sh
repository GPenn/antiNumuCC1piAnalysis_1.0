#!/bin/bash 
#! This file was autogenerated by ND280_END_PROJECT 
 [  -z "$1" ] && set -e 
 ND280_NJOBS="${ND280_NJOBS:=1}" 
  
export ND280_NJOBS=${ND280_NJOBS}
function shout {
  echo "+=======================================+" 
 echo "+                                       +" 
 echo "   Build of package highlandCore_2.40 in  /user/gpenn/nd280software/nd280release_12.31/highlandCore_2.40  FAILED          " 
 echo "+                                       +" 
 echo "+=======================================+" 
 exit 1 
 } 
 trap shout ERR 
  echo "" ; echo " Building highlandCore_2.40  ( package number " 8 " out of " 24 " ) " ; echo "" 
   makeTarget=$1 
  if [ "$1" == "documentation" ] ; then makeTarget=highlandCore_$1 ; fi 
   cd  /user/gpenn/nd280software/nd280release_12.31/highlandCore_2.40 
 SYS_DIR=`nd280-system` 
  [ -d ${SYS_DIR} ] || mkdir ${SYS_DIR} 
  cd  ${SYS_DIR} 
  [ -d inc ] || mkdir inc 
  [ -d bin ] || mkdir bin 
  [ -d lib ] || mkdir lib 
  cmake ../cmake $2 
 [ -f ../bin/setup.sh ] && . ../bin/setup.sh 
  make -j ${ND280_NJOBS}  ${makeTarget} ;
