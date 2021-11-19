#!/bin/bash
#SBATCH -N 1
#SBATCH -c 1
#SBATCH -p compute
#SBATCH -o log/run5-%j.out
#SBATCH -e log/run5-%j.err
#SBATCH -J run5bdt
#SBATCH -t 24:00:00

#run the application:
source ~/highlandsetup.sh
rm output/oaAnalysis_prod6Trun5_all_bdttesting.root
date
RunAntiNumuBDTTestingAnalysis.exe fileList/oaAnalysis_prod6Trun5_all.txt -o output/oaAnalysis_prod6Trun5_bdttesting.root
date
