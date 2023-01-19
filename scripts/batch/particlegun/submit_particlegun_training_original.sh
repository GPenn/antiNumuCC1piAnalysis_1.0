#!/bin/bash
#SBATCH -N 1
#SBATCH -c 1
#SBATCH -p short
#SBATCH -o /user/gpenn/nd280software/nd280release_12.31/antiNumuCC1piAnalysis_1.0/scripts/log/pg-%j.out
#SBATCH -e /user/gpenn/nd280software/nd280release_12.31/antiNumuCC1piAnalysis_1.0/scripts/log/pg-%j.err
#SBATCH -J pg_train
#SBATCH -t 3:00:00

#run the application:
source ~/highlandsetup.sh
RunAntiNumuCC1piAnalysis.exe /user/gpenn/nd280software/nd280release_12.31/antiNumuCC1piAnalysis_1.0/fileList/particlegun_allpositive_training_original.txt -o output/particle_gun/particlegun_allpositive_training_original.root
