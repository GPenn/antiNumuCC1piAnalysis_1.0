#!/bin/bash
#SBATCH -N 1
#SBATCH -c 1
#SBATCH -p compute
#SBATCH -o /user/gpenn/nd280software/nd280release_12.31/antiNumuCC1piAnalysis_1.0/scripts/log/rd-%j.out
#SBATCH -e /user/gpenn/nd280software/nd280release_12.31/antiNumuCC1piAnalysis_1.0/scripts/log/rd-%j.err
#SBATCH -J rd_run7
#SBATCH -t 24:00:00

#run the application:
source ~/highlandsetup.sh
RunAntiNumuCC1piAnalysis.exe /user/gpenn/nd280software/nd280release_12.31/antiNumuCC1piAnalysis_1.0/fileList/real_data/real_data_run7_all.txt -o output/real_data_run7_all.root
