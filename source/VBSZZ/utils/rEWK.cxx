#include "VBSZZ/jSYST.h"
#include "VBSZZ/jTHEO.h"
#include "VBSZZ/jTREE.h"
#include <string>
#include <iostream>
#include <TString.h>

void read_TREE(std::string treename){
    jTREE t(treename, "EWK.root");
    std::string path = "/lustre/umt3/user/liji/VBSZZ-samples/p3761-minitrees-vw/";
    t.LoopROOT(path + "mc16_13TeV.363724.MadGraphPythia8EvtGen_ZZllvv2jEWK.deriv.DAOD_STDM3.e5712_s3126_r9364_p3761.root" , 0.001353 * 3);
    t.LoopROOT(path + "mc16_13TeV.363724.MadGraphPythia8EvtGen_ZZllvv2jEWK.deriv.DAOD_STDM3.e5712_s3126_r10201_p3761.root", 0.001353 * 3);
    t.LoopROOT(path + "mc16_13TeV.363724.MadGraphPythia8EvtGen_ZZllvv2jEWK.deriv.DAOD_STDM3.e5712_s3126_r10724_p3761.root", 0.001353 * 3);
}

void read_SYST(std::string treename){
    jSYST t(treename, "EWK.root");
    std::string path = "/lustre/umt3/user/liji/VBSZZ-samples/p3761-minitrees-vw/";
    t.LoopROOT(path + "mc16_13TeV.363724.MadGraphPythia8EvtGen_ZZllvv2jEWK.deriv.DAOD_STDM3.e5712_s3126_r9364_p3761.root" , 0.001353 * 3);
    t.LoopROOT(path + "mc16_13TeV.363724.MadGraphPythia8EvtGen_ZZllvv2jEWK.deriv.DAOD_STDM3.e5712_s3126_r10201_p3761.root", 0.001353 * 3);
    t.LoopROOT(path + "mc16_13TeV.363724.MadGraphPythia8EvtGen_ZZllvv2jEWK.deriv.DAOD_STDM3.e5712_s3126_r10724_p3761.root", 0.001353 * 3);
}

void read_THEO(std::string treename){
    jTHEO t(treename, "EWK.root");
    std::string path = "/lustre/umt3/user/liji/VBSZZ-samples/p3761-minitrees-vw/";
    t.LoopROOT(path + "mc16_13TeV.363724.MadGraphPythia8EvtGen_ZZllvv2jEWK.deriv.DAOD_STDM3.e5712_s3126_r9364_p3761.root" , 0.001353 * 3);
    t.LoopROOT(path + "mc16_13TeV.363724.MadGraphPythia8EvtGen_ZZllvv2jEWK.deriv.DAOD_STDM3.e5712_s3126_r10201_p3761.root", 0.001353 * 3);
    t.LoopROOT(path + "mc16_13TeV.363724.MadGraphPythia8EvtGen_ZZllvv2jEWK.deriv.DAOD_STDM3.e5712_s3126_r10724_p3761.root", 0.001353 * 3);
}


int main(int argc, const char *argv[]){
    //read_TREE("NOMINAL");
    read_THEO("NOMINAL");
    //read_SYST("NOMINAL");
    //read_TREE("EG_RESOLUTION_ALL__1down");
    //read_TREE("EG_RESOLUTION_ALL__1up");
    //read_TREE("EG_SCALE_AF2__1down");
    //read_TREE("EG_SCALE_AF2__1up");
    //read_TREE("EG_SCALE_ALL__1down");
    //read_TREE("EG_SCALE_ALL__1up");
    //read_TREE("JET_EtaIntercalibration_NonClosure__1up");
    //read_TREE("JET_EtaIntercalibration_NonClosure__1down");
    //read_TREE("JET_GroupedNP_1__1up");
    //read_TREE("JET_GroupedNP_1__1down");
    //read_TREE("JET_GroupedNP_2__1up");
    //read_TREE("JET_GroupedNP_2__1down");
    //read_TREE("JET_GroupedNP_3__1up");
    //read_TREE("JET_GroupedNP_3__1down");
    //read_TREE("JET_JER_SINGLE_NP__1up");
    //read_TREE("MET_SoftTrk_ResoPara");
    //read_TREE("MET_SoftTrk_ResoPerp");
    //read_TREE("MET_SoftTrk_ScaleDown");
    //read_TREE("MET_SoftTrk_ScaleUp");
    //read_TREE("MUON_ID__1down");
    //read_TREE("MUON_ID__1up");
    //read_TREE("MUON_MS__1down");
    //read_TREE("MUON_MS__1up");
    //read_TREE("MUON_SAGITTA_RESBIAS__1down");
    //read_TREE("MUON_SAGITTA_RESBIAS__1up");
    //read_TREE("MUON_SAGITTA_RHO__1down");
    //read_TREE("MUON_SAGITTA_RHO__1up");
    //read_TREE("MUON_SCALE__1down");
    //read_TREE("MUON_SCALE__1up");
    //read_TREE("PRW_DATASF__1down");
    //read_TREE("PRW_DATASF__1up");

    return 0;
}
