# Python script to set up config files and launch scripts for producing extra low-momentum protons for a PG sample.
# Note that the particle gun takes relativistic kinetic energies (NOT momenta) as input, so you will need to convert the
# desired momentum range to an energy range. The values given here are for the momentum range 150-2000 MeV for each particle
# type.

import random
import os

# Run and subrun numbers (update these if you want to add to an existing sample, I just used the current date and time)
run = "0126"
subrun = 1804

# Path for the scripts, config files and output:
path = "/bundle/data/T2K/users/gpenn/particle_gun/"

# Setup script paths for your ND280 software installation:
nd280setup_path = "/hepstore/gpenn/nd280v11r31p43setup.sh"
nd280control_path = "/hepstore/gpenn/nd280v11r31p43/nd280Control/v1r77p1/cmt/setup.sh"

# Desired number of files (10k events per file):
nProton = 25

launchscriptfile = open(path + "submit_batch_jobs_protonlowmom.sh", 'w')

print "Generating proton config files and job scripts..."

launchscriptfile.write("cd proton/output\n")

for i in range(0, nProton):
    cfgname = path + "proton/cfg/protonlowmom" + str(i) + ".cfg"
    subrun += 1
    seed = random.randrange(10000000, 100000000, 1)
    elecseed = random.randrange(10000000, 100000000, 1)
    cfgfile = open(cfgname, 'w')
    cfgfile.write("[software]\ncmtpath = environment\ncmtroot = environment\n\n")
    cfgfile.write("[configuration]\nmodule_list = nd280MC elecSim oaCalibMC oaRecon oaAnalysis\n\n")
    cfgfile.write("[filenaming]\nrun_number = " + run + "\nsubrun = " + str(subrun) + "\n\n")
    cfgfile.write("[nd280mc]\nnum_events = 10000\nmc_type = ParticleGun\nmc_particle = proton\nmc_position = Subdetector FGD1\nmc_energy = uniform 11.92 46.79\nmc_direction = cone +z 0 65\nrandom_seed = " + str(seed) + "\n\n")
    cfgfile.write("[geometry]\nbaseline = Full\n\n")
    cfgfile.write("[electronics]\nrandom_seed = " + str(elecseed) + "\n\n")
    cfgfile.close()

    shname = path + "proton/scripts/protonlowmom_job" + str(i) + ".sh"
    shfile = open(shname, 'w')
    shfile.write("#!/bin/bash\n")
    shfile.write("#SBATCH -N 1\n")
    shfile.write("#SBATCH -c 1\n")
    shfile.write("#SBATCH -p compute\n")
    shfile.write("#SBATCH -o protonlowmom-%j.out\n")
    shfile.write("#SBATCH -e protonlowmom-%j.err\n")
    shfile.write("#SBATCH -J pg_pro" + str(i) + "\n")
    shfile.write("#SBATCH -t 18:00:00\n\n")
    shfile.write("#run the application:\n")
    shfile.write("source " + nd280setup_path + "\n")
    shfile.write("source " + nd280control_path + "\n")
    shfile.write("runND280 -c " + cfgname + "\n")
    shfile.close()

    launchscriptfile.write("sbatch " + shname + "\n")



launchscriptfile.close()

print "Done.\n"
