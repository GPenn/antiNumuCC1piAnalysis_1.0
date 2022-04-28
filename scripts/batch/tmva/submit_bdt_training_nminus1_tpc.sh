#!/bin/bash
#SBATCH -N 1
#SBATCH -c 1
#SBATCH -p compute
#SBATCH -o /user/gpenn/nd280software/nd280release_12.31/antiNumuCC1piAnalysis_1.0/scripts/log/tmva-%j.out
#SBATCH -e /user/gpenn/nd280software/nd280release_12.31/antiNumuCC1piAnalysis_1.0/scripts/log/tmva-%j.err
#SBATCH -J bdt_train
#SBATCH -t 24:00:00

#run the application:
source ~/highlandsetup.sh
cd tmva
root -b BDT_PID_multiclass_nminus1_ntpcs.C
