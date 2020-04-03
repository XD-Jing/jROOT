#!/usr/bin/env bash

export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase
source ${ATLAS_LOCAL_ROOT_BASE}/user/atlasLocalSetup.sh

source /cvmfs/sft.cern.ch/lcg/views/LCG_94python3/x86_64-centos7-gcc8-opt/setup.sh


export WORKDIR="$( cd "$( dirname "${BASH_SOURCE[0]}"  )" >/dev/null 2>&1 && pwd  )"
export PATH=${WORKDIR}/build/LowMassHinv:${WORKDIR}/build:${PATH}

function compile(){
    CURRENTDIR=${PWD}
    cd ${WORKDIR}/build
    make
    cd ${CURRENTDIR}
}

function recmake(){
    CURRENTDIR=${PWD}
    cd ${WORKDIR}/build
    cmake ..
    cd ${CURRENTDIR}
}

#cd build/
#acmSetup --sourcedir=../source AnalysisBase,21.2.64
#cd ..



# for env setup, run "source setup.sh"
# to compile, run "acm compile"

#the variables and selections can be added in source/HZZ/Root/*.cxx
#the samples can be added in source/HZZ/utils/*.cxx
