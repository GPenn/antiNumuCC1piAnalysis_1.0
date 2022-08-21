import random

launchscriptfile = open("submit_batch_jobs.sh", 'w')

run = "1213"
subrun = 1804

print "Generating antimu config files and job scripts..."

launchscriptfile.write("cd antimu/output\n")

for i in range(0, 0):
    cfgname = "antimu/cfg/antimu" + str(i) + ".cfg"
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

    shname = "antimu/scripts/antimu_job" + str(i) + ".sh"
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
    shfile.write("source /hepstore/gpenn/nd280v11r31p43setup.sh\n")
    shfile.write("source /hepstore/gpenn/nd280v11r31p43/nd280Control/v1r77p1/cmt/setup.sh\n")
    shfile.write("runND280 -c /bundle/data/T2K/users/gpenn/particle_gun/" + cfgname + "\n")
    shfile.close()

    launchscriptfile.write("sbatch ../../" + shname + "\n")

print "Generating proton config files and job scripts..."

launchscriptfile.write("cd ../../proton/output\n")

for i in range(0, 0):
    cfgname = "proton/cfg/proton" + str(i) + ".cfg"
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

    shname = "proton/scripts/proton_job" + str(i) + ".sh"
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
    shfile.write("source /hepstore/gpenn/nd280v11r31p43setup.sh\n")
    shfile.write("source /hepstore/gpenn/nd280v11r31p43/nd280Control/v1r77p1/cmt/setup.sh\n")
    shfile.write("runND280 -c /bundle/data/T2K/users/gpenn/particle_gun/" + cfgname + "\n")
    shfile.close()

    launchscriptfile.write("sbatch ../../" + shname + "\n")

print "Generating piplus config files and job scripts..."

launchscriptfile.write("cd ../../piplus/output\n")

for i in range(0, 0):
    cfgname = "piplus/cfg/piplus" + str(i) + ".cfg"
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

    shname = "piplus/scripts/piplus_job" + str(i) + ".sh"
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
    shfile.write("source /hepstore/gpenn/nd280v11r31p43setup.sh\n")
    shfile.write("source /hepstore/gpenn/nd280v11r31p43/nd280Control/v1r77p1/cmt/setup.sh\n")
    shfile.write("runND280 -c /bundle/data/T2K/users/gpenn/particle_gun/" + cfgname + "\n")
    shfile.close()

    launchscriptfile.write("sbatch ../../" + shname + "\n")

print "Generating positron config files and job scripts..."

launchscriptfile.write("cd ../../positron/output\n")

for i in range(0, 0):
    cfgname = "positron/cfg/positron" + str(i) + ".cfg"
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

    shname = "positron/scripts/positron_job" + str(i) + ".sh"
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
    shfile.write("source /hepstore/gpenn/nd280v11r31p43setup.sh\n")
    shfile.write("source /hepstore/gpenn/nd280v11r31p43/nd280Control/v1r77p1/cmt/setup.sh\n")
    shfile.write("runND280 -c /bundle/data/T2K/users/gpenn/particle_gun/" + cfgname + "\n")
    shfile.close()

    launchscriptfile.write("sbatch ../../" + shname + "\n")

print "Generating mu config files and job scripts..."

launchscriptfile.write("cd ../../mu/output\n")

for i in range(0, 25):
    cfgname = "mu/cfg/mu" + str(i) + ".cfg"
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

    shname = "mu/scripts/mu_job" + str(i) + ".sh"
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
    shfile.write("source /hepstore/gpenn/nd280v11r31p43setup.sh\n")
    shfile.write("source /hepstore/gpenn/nd280v11r31p43/nd280Control/v1r77p1/cmt/setup.sh\n")
    shfile.write("runND280 -c /bundle/data/T2K/users/gpenn/particle_gun/" + cfgname + "\n")
    shfile.close()

    launchscriptfile.write("sbatch ../../" + shname + "\n")

print "Generating piminus config files and job scripts..."

launchscriptfile.write("cd ../../piminus/output\n")

for i in range(0, 25):
    cfgname = "piminus/cfg/piminus" + str(i) + ".cfg"
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

    shname = "piminus/scripts/piminus_job" + str(i) + ".sh"
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
    shfile.write("source /hepstore/gpenn/nd280v11r31p43setup.sh\n")
    shfile.write("source /hepstore/gpenn/nd280v11r31p43/nd280Control/v1r77p1/cmt/setup.sh\n")
    shfile.write("runND280 -c /bundle/data/T2K/users/gpenn/particle_gun/" + cfgname + "\n")
    shfile.close()

    launchscriptfile.write("sbatch ../../" + shname + "\n")

print "Generating electron config files and job scripts..."

launchscriptfile.write("cd ../../electron/output\n")

for i in range(0, 25):
    cfgname = "electron/cfg/electron" + str(i) + ".cfg"
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

    shname = "electron/scripts/electron_job" + str(i) + ".sh"
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
    shfile.write("source /hepstore/gpenn/nd280v11r31p43setup.sh\n")
    shfile.write("source /hepstore/gpenn/nd280v11r31p43/nd280Control/v1r77p1/cmt/setup.sh\n")
    shfile.write("runND280 -c /bundle/data/T2K/users/gpenn/particle_gun/" + cfgname + "\n")
    shfile.close()

    launchscriptfile.write("sbatch ../../" + shname + "\n")

launchscriptfile.write("cd ../..\n")

launchscriptfile.close()

print "Done.\n"
