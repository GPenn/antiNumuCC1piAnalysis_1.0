# antiNumuCC1piAnalysis_1.0
Gabriel Penn (gabriel.penn@liverpool.ac.uk)

This is a Highland analysis package for antinumu CC1pi- events, also containing the code from my BDT PID development work.

Branches:
 - main

Standard Highland package directories:
 - app
 - cmake
 - doc
 - inc
 - parameters (note: I've been putting the TMVA xml files here to read into Highland in my copy)
 - src
 
Additional directories:
 - tmva: contains TMVA macros for BDT development, as well as a converter program to prepare flat trees from Highland output for TMVA input
 - fileList: lists of file locations for Highland input (mostly on /bundle/data/T2K/users/gpenn/oaAnalysis)
 - customplotting: custom-written plotting and analysis code for the plots in my thesis (may be useful for reference)
 - macro: Highland DrawingTools macros for plotting various things
 - scripts: shell and python scripts for various purposes, mostly for bulk submission of batch jobs
 
BDT development workflow:
 1. Prepare particle gun input oaAnalysis files and split into training and testing samples
 2. Run training sample through Highland analysis to extract BDT input variables from suitable events
 3. Convert training sample Highland output file(s) to flat trees files for TMVA input
 4. Run TMVA macro on training sample to train BDT(s)
 5. Load new BDT xml file into Highland (see src/BDTPIDUtils.cxx)
 6. Run PG testing sample (or full event MC/real data) through Highland analysis to extract BDT outputs and/or apply BDT PID cuts to events
 7. Analyse Highland output file(s) using DrawingTools macros and/or custom code
