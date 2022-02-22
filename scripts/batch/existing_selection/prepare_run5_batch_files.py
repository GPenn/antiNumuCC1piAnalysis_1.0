import random

launchscriptfile = open("/user/gpenn/nd280software/nd280release_12.31/antiNumuCC1piAnalysis_1.0/scripts/batch/existing_selection/run5/submit_batch_jobs_run5.sh", 'w')

print "Generating job scripts..."

launchscriptfile.write("cd /user/gpenn/nd280software/nd280release_12.31/antiNumuCC1piAnalysis_1.0\n")

listsfile = open('/user/gpenn/nd280software/nd280release_12.31/antiNumuCC1piAnalysis_1.0/fileList/run5/lists.txt', 'r')
lists = listsfile.readlines()

count = 0

for list in lists:
    count += 1
    shname = "/user/gpenn/nd280software/nd280release_12.31/antiNumuCC1piAnalysis_1.0/scripts/batch/existing_selection/run5/submit_run5_" + str(count) + ".sh"
    shfile = open(shname, 'w')
    shfile.write("#!/bin/bash\n")
    shfile.write("#SBATCH -N 1\n")
    shfile.write("#SBATCH -c 1\n")
    shfile.write("#SBATCH -p compute\n")
    shfile.write("#SBATCH -o /user/gpenn/nd280software/nd280release_12.31/antiNumuCC1piAnalysis_1.0/scripts/log/run5-%j.out\n")
    shfile.write("#SBATCH -e /user/gpenn/nd280software/nd280release_12.31/antiNumuCC1piAnalysis_1.0/scripts/log/run5-%j.err\n")
    shfile.write("#SBATCH -J run5_" + str(count) + "\n")
    shfile.write("#SBATCH -t 6:00:00\n\n")
    shfile.write("#run the application:\n")
    shfile.write("source ~/highlandsetup.sh\n")
    shfile.write("RunAntiNumuCCMultiPiAnalysis.exe " + list.strip() + " -o output/existing_selection/run5/oaAnalysis_prod6Trun5_" + str(count) + ".root\n")
    shfile.close()

    launchscriptfile.write("sbatch " + shname + "\n")


launchscriptfile.write("\n echo \"All jobs submitted.\"\n")
launchscriptfile.close()

print "Done.\n"
