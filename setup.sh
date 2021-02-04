#!/usr/bin/env bash

source /cvmfs/sft.cern.ch/lcg/views/LCG_98python3/x86_64-centos7-gcc10-opt/setup.sh

export WORKDIR="$( cd "$( dirname "${BASH_SOURCE[0]}"  )" >/dev/null 2>&1 && pwd  )"
export PATH=${WORKDIR}/build/LowMassHinv:${WORKDIR}/build:${PATH}
export PATH=${WORKDIR}/build/VBSZZ:${WORKDIR}/build:${PATH}

function compile(){
    make -C ${WORKDIR}/build -j 8
}

function recmake(){
    CURRENTDIR=${PWD}
    cd ${WORKDIR}/build
    cmake ..
    cd ${CURRENTDIR}
}

# for env setup, run "source setup.sh"
# to compile, run "compile"

#the variables and selections can be added in LowMassHinv/Root/*.cxx
#the samples can be added in LowMassHinv/utils/*.cxx
