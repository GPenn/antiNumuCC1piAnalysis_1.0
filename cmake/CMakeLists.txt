# CMakeLists.txt for antiNumuCCMultiPiAnalysis package. It creates a library with dictionary and a main program

cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
find_package(nd280SoftwarePolicy 3.1)
if( NOT nd280SoftwarePolicy_FOUND)
   message(FATAL_ERROR " nd280SoftwarePolicy not found - abort ")
endif()

include(antiNumuCC1piAnalysisPackageVersion.cmake)
ND280_PROJECT(antiNumuCC1piAnalysis ${PACKAGE_VERSION} NOVERSION)
include(antiNumuCC1piAnalysisND280_USE.cmake)


ND280_STANDARD_LIBRARY()

ND280_EXECUTABLE(RunAntiNumuCC1piAnalysis RunAntiNumuCC1piAnalysis.cxx)

ND280_END_PROJECT()
