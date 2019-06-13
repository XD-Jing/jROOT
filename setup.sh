#!/usr/bin/env bash

export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase
source ${ATLAS_LOCAL_ROOT_BASE}/user/atlasLocalSetup.sh

#export WorkDir=$PWD
cd build/
#asetup 21.2.64,AnalysisBase
acmSetup --sourcedir=../source AnalysisBase,21.2.64
cd ..
