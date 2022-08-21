# Python script to set up config files and launch scripts for producing a MC particle gun sample suitable for BDT training.
# Note that the particle gun takes relativistic kinetic energies (NOT momenta) as input, so you will need to convert the
# desired momentum range to an energy range. The values given here are for the momentum range 150-2000 MeV for each particle
# type.

# Generates a single script (submit_batch_jobs.sh) to submit all jobs for all particle types.

import random
import os

# Run and subrun numbers (update these if you want to add to an existing sample, I just used the current date and time)
run = "1213"
subrun = 1804

# Path for the scripts, config files and output:
path = "/bundle/data/T2K/users/gpenn/particle_gun/"

# Set to "true" if you need to create the directory structure at the destination
set_up_directories = True;

# Setup script paths for your ND280 software installation:
nd280setup_path = "/hepstore/gpenn/nd280v11r31p43setup.sh"
nd280control_path = "/hepstore/gpenn/nd280v11r31p43/nd280Control/v1r77p1/cmt/setup.sh"

# Desired number of files for each particle type (10k events per file):
nAntimu = 25
nProton = 25
nPiplus = 25
nPositron = 25
nMu = 0
nPiminus = 0
nElectron = 0

if set_up_directories:
    os.mkdir(path + "antimu")
    os.mkdir(path + "antimu/cfg")
    os.mkdir(path + "antimu/scripts")
    os.mkdir(path + "antimu/output")
    os.mkdir(path + "proton")
    os.mkdir(path + "proton/cfg")
    os.mkdir(path + "proton/scripts")
    os.mkdir(path + "proton/output")
    os.mkdir(path + "piplus")
    os.mkdir(path + "piplus/cfg")
    os.mkdir(path + "piplus/scripts")
    os.mkdir(path + "piplus/output")
    os.mkdir(path + "positron")
    os.mkdir(path + "positron/cfg")
    os.mkdir(path + "positron/scripts")
    os.mkdir(path + "positron/output")
    os.mkdir(path + "mu")
    os.mkdir(path + "mu/cfg")
    os.mkdir(path + "mu/scripts")
    os.mkdir(path + "mu/output")
    os.mkdir(path + "piminus")
    os.mkdir(path + "piminus/cfg")
    os.mkdir(path + "piminus/scripts")
    os.mkdir(path + "piminus/output")
    os.mkdir(path + "electron")
    os.mkdir(path + "electron/cfg")
    os.mkdir(path + "electron/scripts")
    os.mkdir(path + "electron/output")

launchscriptfile = open(path + "submit_batch_jobs.sh", 'w')

print "Generating antimu config files and job scripts..."

launchscriptfile.write("cd antimu/output\n")

for i in range(0, nAntimu):
    cfgname = path + "antimu/cfg/antimu" + str(i) + ".cfg"
    subrun += 1
    seed = random.randrange(10000000, 100000000, 1)
    elecseed = random.randrange(10000000, 100000000, 1)
    cfgfile = open(cfgname, 'w')
    cfgfile.write("[software]\ncmtpath = environment\ncmtroot = environment\n\n")
    cfgfile.write("[configuration]\nmodule_list = nd280MC elecSim oaCalibMC oaRecon oaAnalysis\n\n")
    cfgfile.write("[filenaming]\nrun_number = " + run + "\nsubrun = " + str(subrun) + "\n\n")
    cfgfile.write("[nd280mc]\nnum_events = 10000\nmc_type = ParticleGun\nmc_particle = mu+\nmc_position = Subdetector FGD1\nmc_energy = uniform 77.81 1897.76\nmc_direction = cone +z 0 65\nrandom_seed = " + str(seed) + "\n\n")
    cfgfile.write("[geometry]\nbaseline = Full\n\n")
    cfgfile.write("[electronics]\nrandom_seed = " + str(elecseed) + "\n\n")
    cfgfile.close()

    shname = path + "antimu/scripts/antimu_job" + str(i) + ".sh"
    shfile = open(shname, 'w')
    shfile.write("#!/bin/bash\n")
    shfile.write("#SBATCH -N 1\n")
    shfile.write("#SBATCH -c 1\n")
    shfile.write("#SBATCH -p compute\n")
    shfile.write("#SBATCH -o slurm-%j.out\n")
    shfile.write("#SBATCH -e slurm-%j.err\n")
    shfile.write("#SBATCH -J pg_amu" + str(i) + "\n")
    shfile.write("#SBATCH -t 18:00:00\n\n")
    shfile.write("#run the application:\n")
    shfile.write("source " + nd280setup_path + "\n")
    shfile.write("source " + nd280control_path + "\n")
    shfile.write("runND280 -c " + cfgname + "\n")
    shfile.close()

    launchscriptfile.write("sbatch ../../" + shname + "\n")

print "Generating proton config files and job scripts..."

launchscriptfile.write("cd ../../proton/output\n")

for i in range(0, nProton):
    cfgname = path + "proton/cfg/proton" + str(i) + ".cfg"
    subrun += 1
    seed = random.randrange(10000000, 100000000, 1)
    elecseed = random.randrange(10000000, 100000000, 1)
    cfgfile = open(cfgname, 'w')
    cfgfile.write("[software]\ncmtpath = environment\ncmtroot = environment\n\n")
    cfgfile.write("[configuration]\nmodule_list = nd280MC elecSim oaCalibMC oaRecon oaAnalysis\n\n")
    cfgfile.write("[filenaming]\nrun_number = " + run + "\nsubrun = " + str(subrun) + "\n\n")
    cfgfile.write("[nd280mc]\nnum_events = 10000\nmc_type = ParticleGun\nmc_particle = proton\nmc_position = Subdetector FGD1\nmc_energy = uniform 11.92 1271\nmc_direction = cone +z 0 65\nrandom_seed = " + str(seed) + "\n\n")
    cfgfile.write("[geometry]\nbaseline = Full\n\n")
    cfgfile.write("[electronics]\nrandom_seed = " + str(elecseed) + "\n\n")
    cfgfile.close()

    shname = path + "proton/scripts/proton_job" + str(i) + ".sh"
    shfile = open(shname, 'w')
    shfile.write("#!/bin/bash\n")
    shfile.write("#SBATCH -N 1\n")
    shfile.write("#SBATCH -c 1\n")
    shfile.write("#SBATCH -p compute\n")
    shfile.write("#SBATCH -o slurm-%j.out\n")
    shfile.write("#SBATCH -e slurm-%j.err\n")
    shfile.write("#SBATCH -J pg_pro" + str(i) + "\n")
    shfile.write("#SBATCH -t 18:00:00\n\n")
    shfile.write("#run the application:\n")
    shfile.write("source " + nd280setup_path + "\n")
    shfile.write("source " + nd280control_path + "\n")
    shfile.write("runND280 -c " + cfgname + "\n")
    shfile.close()

    launchscriptfile.write("sbatch ../../" + shname + "\n")

print "Generating piplus config files and job scripts..."

launchscriptfile.write("cd ../../piplus/output\n")

for i in range(0, nPiplus):
    cfgname = path + "piplus/cfg/piplus" + str(i) + ".cfg"
    subrun += 1
    seed = random.randrange(10000000, 100000000, 1)
    elecseed = random.randrange(10000000, 100000000, 1)
    cfgfile = open(cfgname, 'w')
    cfgfile.write("[software]\ncmtpath = environment\ncmtroot = environment\n\n")
    cfgfile.write("[configuration]\nmodule_list = nd280MC elecSim oaCalibMC oaRecon oaAnalysis\n\n")
    cfgfile.write("[filenaming]\nrun_number = " + run + "\nsubrun = " + str(subrun) + "\n\n")
    cfgfile.write("[nd280mc]\nnum_events = 10000\nmc_type = ParticleGun\nmc_particle = pi+\nmc_position = Subdetector FGD1\nmc_energy = uniform 65.33 1865.55\nmc_direction = cone +z 0 65\nrandom_seed = " + str(seed) + "\n\n")
    cfgfile.write("[geometry]\nbaseline = Full\n\n")
    cfgfile.write("[electronics]\nrandom_seed = " + str(elecseed) + "\n\n")
    cfgfile.close()

    shname = path + "piplus/scripts/piplus_job" + str(i) + ".sh"
    shfile = open(shname, 'w')
    shfile.write("#!/bin/bash\n")
    shfile.write("#SBATCH -N 1\n")
    shfile.write("#SBATCH -c 1\n")
    shfile.write("#SBATCH -p compute\n")
    shfile.write("#SBATCH -o slurm-%j.out\n")
    shfile.write("#SBATCH -e slurm-%j.err\n")
    shfile.write("#SBATCH -J pg_pip" + str(i) + "\n")
    shfile.write("#SBATCH -t 18:00:00\n\n")
    shfile.write("#run the application:\n")
    shfile.write("source " + nd280setup_path + "\n")
    shfile.write("source " + nd280control_path + "\n")
    shfile.write("runND280 -c " + cfgname + "\n")
    shfile.close()

    launchscriptfile.write("sbatch ../../" + shname + "\n")

print "Generating positron config files and job scripts..."

launchscriptfile.write("cd ../../positron/output\n")

for i in range(0, nPositron):
    cfgname = path + "positron/cfg/positron" + str(i) + ".cfg"
    subrun += 1
    seed = random.randrange(10000000, 100000000, 1)
    elecseed = random.randrange(10000000, 100000000, 1)
    cfgfile = open(cfgname, 'w')
    cfgfile.write("[software]\ncmtpath = environment\ncmtroot = environment\n\n")
    cfgfile.write("[configuration]\nmodule_list = nd280MC elecSim oaCalibMC oaRecon oaAnalysis\n\n")
    cfgfile.write("[filenaming]\nrun_number = " + run + "\nsubrun = " + str(subrun) + "\n\n")
    cfgfile.write("[nd280mc]\nnum_events = 10000\nmc_type = ParticleGun\nmc_particle = e+\nmc_position = Subdetector FGD1\nmc_energy = uniform 149.50 1999.61\nmc_direction = cone +z 0 65\nrandom_seed = " + str(seed) + "\n\n")
    cfgfile.write("[geometry]\nbaseline = Full\n\n")
    cfgfile.write("[electronics]\nrandom_seed = " + str(elecseed) + "\n\n")
    cfgfile.close()

    shname = path + "positron/scripts/positron_job" + str(i) + ".sh"
    shfile = open(shname, 'w')
    shfile.write("#!/bin/bash\n")
    shfile.write("#SBATCH -N 1\n")
    shfile.write("#SBATCH -c 1\n")
    shfile.write("#SBATCH -p compute\n")
    shfile.write("#SBATCH -o slurm-%j.out\n")
    shfile.write("#SBATCH -e slurm-%j.err\n")
    shfile.write("#SBATCH -J pg_pos" + str(i) + "\n")
    shfile.write("#SBATCH -t 30:00:00\n\n")
    shfile.write("#run the application:\n")
    shfile.write("source " + nd280setup_path + "\n")
    shfile.write("source " + nd280control_path + "\n")
    shfile.write("runND280 -c " + cfgname + "\n")
    shfile.close()

    launchscriptfile.write("sbatch ../../" + shname + "\n")

print "Generating mu config files and job scripts..."

launchscriptfile.write("cd ../../mu/output\n")

for i in range(0, nMu):
    cfgname = path + "mu/cfg/mu" + str(i) + ".cfg"
    subrun += 1
    seed = random.randrange(10000000, 100000000, 1)
    elecseed = random.randrange(10000000, 100000000, 1)
    cfgfile = open(cfgname, 'w')
    cfgfile.write("[software]\ncmtpath = environment\ncmtroot = environment\n\n")
    cfgfile.write("[configuration]\nmodule_list = nd280MC elecSim oaCalibMC oaRecon oaAnalysis\n\n")
    cfgfile.write("[filenaming]\nrun_number = " + run + "\nsubrun = " + str(subrun) + "\n\n")
    cfgfile.write("[nd280mc]\nnum_events = 10000\nmc_type = ParticleGun\nmc_particle = mu-\nmc_position = Subdetector FGD1\nmc_energy = uniform 77.81 1897.76\nmc_direction = cone +z 0 65\nrandom_seed = " + str(seed) + "\n\n")
    cfgfile.write("[geometry]\nbaseline = Full\n\n")
    cfgfile.write("[electronics]\nrandom_seed = " + str(elecseed) + "\n\n")
    cfgfile.close()

    shname = path + "mu/scripts/mu_job" + str(i) + ".sh"
    shfile = open(shname, 'w')
    shfile.write("#!/bin/bash\n")
    shfile.write("#SBATCH -N 1\n")
    shfile.write("#SBATCH -c 1\n")
    shfile.write("#SBATCH -p compute\n")
    shfile.write("#SBATCH -o slurm-%j.out\n")
    shfile.write("#SBATCH -e slurm-%j.err\n")
    shfile.write("#SBATCH -J pg_mu" + str(i) + "\n")
    shfile.write("#SBATCH -t 18:00:00\n\n")
    shfile.write("#run the application:\n")
    shfile.write("source " + nd280setup_path + "\n")
    shfile.write("source " + nd280control_path + "\n")
    shfile.write("runND280 -c " + cfgname + "\n")
    shfile.close()

    launchscriptfile.write("sbatch ../../" + shname + "\n")

print "Generating piminus config files and job scripts..."

launchscriptfile.write("cd ../../piminus/output\n")

for i in range(0, nPiminus):
    cfgname = path + "piminus/cfg/piminus" + str(i) + ".cfg"
    subrun += 1
    seed = random.randrange(10000000, 100000000, 1)
    elecseed = random.randrange(10000000, 100000000, 1)
    cfgfile = open(cfgname, 'w')
    cfgfile.write("[software]\ncmtpath = environment\ncmtroot = environment\n\n")
    cfgfile.write("[configuration]\nmodule_list = nd280MC elecSim oaCalibMC oaRecon oaAnalysis\n\n")
    cfgfile.write("[filenaming]\nrun_number = " + run + "\nsubrun = " + str(subrun) + "\n\n")
    cfgfile.write("[nd280mc]\nnum_events = 10000\nmc_type = ParticleGun\nmc_particle = pi-\nmc_position = Subdetector FGD1\nmc_energy = uniform 65.33 1865.55\nmc_direction = cone +z 0 65\nrandom_seed = " + str(seed) + "\n\n")
    cfgfile.write("[geometry]\nbaseline = Full\n\n")
    cfgfile.write("[electronics]\nrandom_seed = " + str(elecseed) + "\n\n")
    cfgfile.close()

    shname = path + "piminus/scripts/piminus_job" + str(i) + ".sh"
    shfile = open(shname, 'w')
    shfile.write("#!/bin/bash\n")
    shfile.write("#SBATCH -N 1\n")
    shfile.write("#SBATCH -c 1\n")
    shfile.write("#SBATCH -p compute\n")
    shfile.write("#SBATCH -o slurm-%j.out\n")
    shfile.write("#SBATCH -e slurm-%j.err\n")
    shfile.write("#SBATCH -J pg_pim" + str(i) + "\n")
    shfile.write("#SBATCH -t 18:00:00\n\n")
    shfile.write("#run the application:\n")
    shfile.write("source " + nd280setup_path + "\n")
    shfile.write("source " + nd280control_path + "\n")
    shfile.write("runND280 -c " + cfgname + "\n")
    shfile.close()

    launchscriptfile.write("sbatch ../../" + shname + "\n")

print "Generating electron config files and job scripts..."

launchscriptfile.write("cd ../../electron/output\n")

for i in range(0, nElectron):
    cfgname = path + "electron/cfg/electron" + str(i) + ".cfg"
    subrun += 1
    seed = random.randrange(10000000, 100000000, 1)
    elecseed = random.randrange(10000000, 100000000, 1)
    cfgfile = open(cfgname, 'w')
    cfgfile.write("[software]\ncmtpath = environment\ncmtroot = environment\n\n")
    cfgfile.write("[configuration]\nmodule_list = nd280MC elecSim oaCalibMC oaRecon oaAnalysis\n\n")
    cfgfile.write("[filenaming]\nrun_number = " + run + "\nsubrun = " + str(subrun) + "\n\n")
    cfgfile.write("[nd280mc]\nnum_events = 10000\nmc_type = ParticleGun\nmc_particle = e-\nmc_position = Subdetector FGD1\nmc_energy = uniform 149.50 1999.61\nmc_direction = cone +z 0 65\nrandom_seed = " + str(seed) + "\n\n")
    cfgfile.write("[geometry]\nbaseline = Full\n\n")
    cfgfile.write("[electronics]\nrandom_seed = " + str(elecseed) + "\n\n")
    cfgfile.close()

    shname = path + "electron/scripts/electron_job" + str(i) + ".sh"
    shfile = open(shname, 'w')
    shfile.write("#!/bin/bash\n")
    shfile.write("#SBATCH -N 1\n")
    shfile.write("#SBATCH -c 1\n")
    shfile.write("#SBATCH -p compute\n")
    shfile.write("#SBATCH -o slurm-%j.out\n")
    shfile.write("#SBATCH -e slurm-%j.err\n")
    shfile.write("#SBATCH -J pg_ele" + str(i) + "\n")
    shfile.write("#SBATCH -t 30:00:00\n\n")
    shfile.write("#run the application:\n")
    shfile.write("source " + nd280setup_path + "\n")
    shfile.write("source " + nd280control_path + "\n")
    shfile.write("runND280 -c " + cfgname + "\n")
    shfile.close()

    launchscriptfile.write("sbatch ../../" + shname + "\n")

launchscriptfile.write("cd ../..\n")

launchscriptfile.close()

print "Done.\n"
