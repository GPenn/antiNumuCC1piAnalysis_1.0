# antiNumuCC1piAnalysis_1.0
Gabriel Penn (gabriel.penn@liverpool.ac.uk)

This is a Highland analysis package for antinumu CC1pi- events, based on antiNumuCCMultiPiAnalysis. It also contains the code from my BDT PID development work.

Standard Highland package directories:
 - app
 - cmake
 - doc
 - inc
 - parameters (also contains the BDT weights file from TMVA)
 - src
 
Additional directories:
 - tmva: contains TMVA macros for BDT development, as well as a converter program to prepare flat trees from Highland output for TMVA input
 - fileList: lists of file locations for Highland input (mostly on /bundle/data/T2K/users/gpenn/oaAnalysis)
 - customplotting: custom-written plotting and analysis code for the plots in my thesis (may be useful for reference)
 - macro: Highland DrawingTools macros for plotting various things
 - scripts: shell and python scripts for various purposes, mostly for bulk submission of batch jobs
 
BDT development workflow:
 1. Prepare particle gun input oaAnalysis files (*scripts/batch/particlegun_generator*) and split into training and testing samples
 2. Run training sample through Highland analysis to extract BDT input variables from suitable events
 3. Convert training sample Highland output file(s) to flat trees files for TMVA input (*tmva/tree_converter*)
 4. Run TMVA macro on training sample to train BDT(s) (*tmva/BDT_PID_multiclass.C*)
 5. Load new BDT xml file into Highland (*src/BDTPIDUtils.cxx*)
 6. Run PG testing sample (or full event MC/real data) through Highland analysis to extract BDT outputs and/or apply BDT PID cuts to events
 7. Analyse Highland output file(s) using DrawingTools macros and/or custom code (see *customplotting* and *macro* for reference, but you'll mostly need to write these yourself)

Loading the BDT into Highland and using it for PID in selections is a non-trivial coding problem! The code supporting this can be found as part of the source code in inc and src. BDTPIDUtils contains the BDTPIDmanager class, which interfaces with TMVA to book the BDT from its weights file and retrieves its outputs when applied to a particular track. AntiNumuCC1PiSelection contains Psyche cuts and actions which apply the BDT for both primary PID (antimuon candidate) and secondary PID (all other tracks). In the latter case, modified versions of several Psyche functions had to be made (FindProtonsAction etc). The BDT currently takes the low-level ECals as inputs: these are not saved by default for global tracks, so the local ECal objects must be retrieved and matched to the global tracks. This is handled by code within AntiNumuCC1PiSelection (specifically GetAllTECALReconObjectsAction and MatchECalGlobalToLocalObjectsAction).
