#!/bin/bash
#SBATCH -N 1
#SBATCH -c 1
#SBATCH -p compute
#SBATCH -o log/slurm-%j.out
#SBATCH -e log/slurm-%j.err
#SBATCH -J run5test
#SBATCH -t 18:00:00

#run the application:
date
source ~/highlandsetup.sh
rm output/oaAnalysis_prod6Trun5_test_bdttesting.root
RunAntiNumuBDTTestingAnalysis.exe fileList/oaAnalysis_prod6Trun5_test.txt -o output/oaAnalysis_prod6Trun5_test_bdttesting.root
date
