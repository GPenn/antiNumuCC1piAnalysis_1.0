# Setup the PATH and LD_LIBRARY_PATH environment variables 
# and run all setup scripts
HERE=`pwd` 
export ND280_SYSTEM=`nd280-system` 
unset -f path_remove 
unset -f path_append 
unset -f ld_remove 
unset -f ld_append 
path_remove ()  { export PATH=`echo -n $PATH | awk -v RS=: -v ORS=: '$0 != "'$1'"' | sed 's/:$//'`; } 
path_append ()  { path_remove $1; export PATH="$PATH:$1" ;} 
ld_remove ()  { export LD_LIBRARY_PATH=`echo -n $LD_LIBRARY_PATH | awk -v RS=: -v ORS=: '$0 != "'$1'"' | sed 's/:$//'`; } 
ld_append ()  { ld_remove $1; export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$1" ;} 
path_append /hepstore/gpenn/nd280gitlab/12.31/antiNumuCC1piAnalysis_1.0/${ND280_SYSTEM}/bin 
ld_append /hepstore/gpenn/nd280gitlab/12.31/antiNumuCC1piAnalysis_1.0/${ND280_SYSTEM}/lib 
export ND280SOFTWAREPOLICYROOT=/hepstore/gpenn/nd280gitlab/12.31/nd280SoftwarePolicy_master/modules/.. 
path_append /hepstore/gpenn/nd280gitlab/12.31/MYSQL_5.6.20.01/${ND280_SYSTEM}/bin 
ld_append /hepstore/gpenn/nd280gitlab/12.31/MYSQL_5.6.20.01/${ND280_SYSTEM}/lib 
export MYSQLROOT=/hepstore/gpenn/nd280gitlab/12.31/MYSQL_5.6.20.01 
export MYSQLCONFIG=${ND280_SYSTEM}  
path_append /hepstore/gpenn/nd280gitlab/12.31/GSL_1.15.0.00/${ND280_SYSTEM}/bin 
ld_append /hepstore/gpenn/nd280gitlab/12.31/GSL_1.15.0.00/${ND280_SYSTEM}/lib 
export GSLROOT=/hepstore/gpenn/nd280gitlab/12.31/GSL_1.15.0.00 
export GSLCONFIG=${ND280_SYSTEM}  
path_append /hepstore/gpenn/nd280gitlab/12.31/ROOT_5.34.34.00/${ND280_SYSTEM}/bin 
ld_append /hepstore/gpenn/nd280gitlab/12.31/ROOT_5.34.34.00/${ND280_SYSTEM}/lib 
export ROOTROOT=/hepstore/gpenn/nd280gitlab/12.31/ROOT_5.34.34.00 
export ROOTCONFIG=${ND280_SYSTEM}  
for file in /hepstore/gpenn/nd280gitlab/12.31/ROOT_5.34.34.00/setup_script/*.sh ; do [ -f $file ] && . $file ; done
path_append /hepstore/gpenn/nd280gitlab/12.31/psycheCore_3.41/${ND280_SYSTEM}/bin 
ld_append /hepstore/gpenn/nd280gitlab/12.31/psycheCore_3.41/${ND280_SYSTEM}/lib 
export PSYCHECOREROOT=/hepstore/gpenn/nd280gitlab/12.31/psycheCore_3.41 
export PSYCHECORECONFIG=${ND280_SYSTEM}  
for file in /hepstore/gpenn/nd280gitlab/12.31/psycheCore_3.41/setup_script/*.sh ; do [ -f $file ] && . $file ; done
path_append /hepstore/gpenn/nd280gitlab/12.31/psycheEventModel_3.38/${ND280_SYSTEM}/bin 
ld_append /hepstore/gpenn/nd280gitlab/12.31/psycheEventModel_3.38/${ND280_SYSTEM}/lib 
export PSYCHEEVENTMODELROOT=/hepstore/gpenn/nd280gitlab/12.31/psycheEventModel_3.38 
export PSYCHEEVENTMODELCONFIG=${ND280_SYSTEM}  
for file in /hepstore/gpenn/nd280gitlab/12.31/psycheEventModel_3.38/setup_script/*.sh ; do [ -f $file ] && . $file ; done
path_append /hepstore/gpenn/nd280gitlab/12.31/psycheUtils_3.34/${ND280_SYSTEM}/bin 
ld_append /hepstore/gpenn/nd280gitlab/12.31/psycheUtils_3.34/${ND280_SYSTEM}/lib 
export PSYCHEUTILSROOT=/hepstore/gpenn/nd280gitlab/12.31/psycheUtils_3.34 
export PSYCHEUTILSCONFIG=${ND280_SYSTEM}  
path_append /hepstore/gpenn/nd280gitlab/12.31/psycheND280Utils_3.57/${ND280_SYSTEM}/bin 
ld_append /hepstore/gpenn/nd280gitlab/12.31/psycheND280Utils_3.57/${ND280_SYSTEM}/lib 
export PSYCHEND280UTILSROOT=/hepstore/gpenn/nd280gitlab/12.31/psycheND280Utils_3.57 
export PSYCHEND280UTILSCONFIG=${ND280_SYSTEM}  
for file in /hepstore/gpenn/nd280gitlab/12.31/psycheND280Utils_3.57/setup_script/*.sh ; do [ -f $file ] && . $file ; done
path_append /hepstore/gpenn/nd280gitlab/12.31/psycheIO_3.32/${ND280_SYSTEM}/bin 
ld_append /hepstore/gpenn/nd280gitlab/12.31/psycheIO_3.32/${ND280_SYSTEM}/lib 
export PSYCHEIOROOT=/hepstore/gpenn/nd280gitlab/12.31/psycheIO_3.32 
export PSYCHEIOCONFIG=${ND280_SYSTEM}  
path_append /hepstore/gpenn/nd280gitlab/12.31/highlandCore_2.37/${ND280_SYSTEM}/bin 
ld_append /hepstore/gpenn/nd280gitlab/12.31/highlandCore_2.37/${ND280_SYSTEM}/lib 
export HIGHLANDCOREROOT=/hepstore/gpenn/nd280gitlab/12.31/highlandCore_2.37 
export HIGHLANDCORECONFIG=${ND280_SYSTEM}  
for file in /hepstore/gpenn/nd280gitlab/12.31/highlandCore_2.37/setup_script/*.sh ; do [ -f $file ] && . $file ; done
path_append /hepstore/gpenn/nd280gitlab/12.31/oaAnalysisReader_2.21/${ND280_SYSTEM}/bin 
ld_append /hepstore/gpenn/nd280gitlab/12.31/oaAnalysisReader_2.21/${ND280_SYSTEM}/lib 
export OAANALYSISREADERROOT=/hepstore/gpenn/nd280gitlab/12.31/oaAnalysisReader_2.21 
export OAANALYSISREADERCONFIG=${ND280_SYSTEM}  
path_append /hepstore/gpenn/nd280gitlab/12.31/highlandEventModel_2.31/${ND280_SYSTEM}/bin 
ld_append /hepstore/gpenn/nd280gitlab/12.31/highlandEventModel_2.31/${ND280_SYSTEM}/lib 
export HIGHLANDEVENTMODELROOT=/hepstore/gpenn/nd280gitlab/12.31/highlandEventModel_2.31 
export HIGHLANDEVENTMODELCONFIG=${ND280_SYSTEM}  
for file in /hepstore/gpenn/nd280gitlab/12.31/highlandEventModel_2.31/setup_script/*.sh ; do [ -f $file ] && . $file ; done
path_append /hepstore/gpenn/nd280gitlab/12.31/highlandUtils_2.34/${ND280_SYSTEM}/bin 
ld_append /hepstore/gpenn/nd280gitlab/12.31/highlandUtils_2.34/${ND280_SYSTEM}/lib 
export HIGHLANDUTILSROOT=/hepstore/gpenn/nd280gitlab/12.31/highlandUtils_2.34 
export HIGHLANDUTILSCONFIG=${ND280_SYSTEM}  
path_append /hepstore/gpenn/nd280gitlab/12.31/psycheSelections_3.46/${ND280_SYSTEM}/bin 
ld_append /hepstore/gpenn/nd280gitlab/12.31/psycheSelections_3.46/${ND280_SYSTEM}/lib 
export PSYCHESELECTIONSROOT=/hepstore/gpenn/nd280gitlab/12.31/psycheSelections_3.46 
export PSYCHESELECTIONSCONFIG=${ND280_SYSTEM}  
path_append /hepstore/gpenn/nd280gitlab/12.31/psycheSystematics_3.44/${ND280_SYSTEM}/bin 
ld_append /hepstore/gpenn/nd280gitlab/12.31/psycheSystematics_3.44/${ND280_SYSTEM}/lib 
export PSYCHESYSTEMATICSROOT=/hepstore/gpenn/nd280gitlab/12.31/psycheSystematics_3.44 
export PSYCHESYSTEMATICSCONFIG=${ND280_SYSTEM}  
path_append /hepstore/gpenn/nd280gitlab/12.31/highlandCorrections_2.21/${ND280_SYSTEM}/bin 
ld_append /hepstore/gpenn/nd280gitlab/12.31/highlandCorrections_2.21/${ND280_SYSTEM}/lib 
export HIGHLANDCORRECTIONSROOT=/hepstore/gpenn/nd280gitlab/12.31/highlandCorrections_2.21 
export HIGHLANDCORRECTIONSCONFIG=${ND280_SYSTEM}  
path_append /hepstore/gpenn/nd280gitlab/12.31/highlandIO_2.41/${ND280_SYSTEM}/bin 
ld_append /hepstore/gpenn/nd280gitlab/12.31/highlandIO_2.41/${ND280_SYSTEM}/lib 
export HIGHLANDIOROOT=/hepstore/gpenn/nd280gitlab/12.31/highlandIO_2.41 
export HIGHLANDIOCONFIG=${ND280_SYSTEM}  
path_append /hepstore/gpenn/nd280gitlab/12.31/highlandTools_2.29/${ND280_SYSTEM}/bin 
ld_append /hepstore/gpenn/nd280gitlab/12.31/highlandTools_2.29/${ND280_SYSTEM}/lib 
export HIGHLANDTOOLSROOT=/hepstore/gpenn/nd280gitlab/12.31/highlandTools_2.29 
export HIGHLANDTOOLSCONFIG=${ND280_SYSTEM}  
for file in /hepstore/gpenn/nd280gitlab/12.31/highlandTools_2.29/setup_script/*.sh ; do [ -f $file ] && . $file ; done
path_append /hepstore/gpenn/nd280gitlab/12.31/baseAnalysis_2.33/${ND280_SYSTEM}/bin 
ld_append /hepstore/gpenn/nd280gitlab/12.31/baseAnalysis_2.33/${ND280_SYSTEM}/lib 
export BASEANALYSISROOT=/hepstore/gpenn/nd280gitlab/12.31/baseAnalysis_2.33 
export BASEANALYSISCONFIG=${ND280_SYSTEM}  
path_append /hepstore/gpenn/nd280gitlab/12.31/baseTrackerAnalysis_2.21/${ND280_SYSTEM}/bin 
ld_append /hepstore/gpenn/nd280gitlab/12.31/baseTrackerAnalysis_2.21/${ND280_SYSTEM}/lib 
export BASETRACKERANALYSISROOT=/hepstore/gpenn/nd280gitlab/12.31/baseTrackerAnalysis_2.21 
export BASETRACKERANALYSISCONFIG=${ND280_SYSTEM}  
path_append /hepstore/gpenn/nd280gitlab/12.31/numuCCAnalysis_2.21/${ND280_SYSTEM}/bin 
ld_append /hepstore/gpenn/nd280gitlab/12.31/numuCCAnalysis_2.21/${ND280_SYSTEM}/lib 
export NUMUCCANALYSISROOT=/hepstore/gpenn/nd280gitlab/12.31/numuCCAnalysis_2.21 
export NUMUCCANALYSISCONFIG=${ND280_SYSTEM}  
path_append /hepstore/gpenn/nd280gitlab/12.31/antiNumuCCAnalysis_2.7/${ND280_SYSTEM}/bin 
ld_append /hepstore/gpenn/nd280gitlab/12.31/antiNumuCCAnalysis_2.7/${ND280_SYSTEM}/lib 
export ANTINUMUCCANALYSISROOT=/hepstore/gpenn/nd280gitlab/12.31/antiNumuCCAnalysis_2.7 
export ANTINUMUCCANALYSISCONFIG=${ND280_SYSTEM}  
path_append /hepstore/gpenn/nd280gitlab/12.31/numuCCMultiPiAnalysis_2.25/${ND280_SYSTEM}/bin 
ld_append /hepstore/gpenn/nd280gitlab/12.31/numuCCMultiPiAnalysis_2.25/${ND280_SYSTEM}/lib 
export NUMUCCMULTIPIANALYSISROOT=/hepstore/gpenn/nd280gitlab/12.31/numuCCMultiPiAnalysis_2.25 
export NUMUCCMULTIPIANALYSISCONFIG=${ND280_SYSTEM}  
path_append /hepstore/gpenn/nd280gitlab/12.31/antiNumuCCMultiPiAnalysis_2.11/${ND280_SYSTEM}/bin 
ld_append /hepstore/gpenn/nd280gitlab/12.31/antiNumuCCMultiPiAnalysis_2.11/${ND280_SYSTEM}/lib 
export ANTINUMUCCMULTIPIANALYSISROOT=/hepstore/gpenn/nd280gitlab/12.31/antiNumuCCMultiPiAnalysis_2.11 
export ANTINUMUCCMULTIPIANALYSISCONFIG=${ND280_SYSTEM}  
path_append /hepstore/gpenn/nd280gitlab/12.31/antiNumuCC1piAnalysis_1.0/${ND280_SYSTEM}/bin 
ld_append /hepstore/gpenn/nd280gitlab/12.31/antiNumuCC1piAnalysis_1.0/${ND280_SYSTEM}/lib 
export ANTINUMUCC1PIANALYSISROOT=/hepstore/gpenn/nd280gitlab/12.31/antiNumuCC1piAnalysis_1.0 
export ANTINUMUCC1PIANALYSISCONFIG=${ND280_SYSTEM}  
export LD_LIBRARY_PATH=`echo $LD_LIBRARY_PATH | sed 's/^://g'`
cd $HERE 
