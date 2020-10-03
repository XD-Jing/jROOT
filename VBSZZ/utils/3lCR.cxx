#include "VBSZZ/VBS_3lCR.h" 
#include <string>
#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <cmath>

std::string path = "/lustre/umt3/user/liji/VBSZZ-samples/p3759-3lCR/";
std::string path_theo = "/lustre/umt3/user/liji/VBSZZ-samples/WZ_theo/";

void process(std::string fin, std::string treename, std::string fout, float factor, bool syst, bool theo){
    if (syst){
        VBS_3lCR job(treename, fout, "recreate", false, true, true);
        job.LoopROOT(path + fin, "tree_"+treename, factor);
        job.Close();
    }else if (theo){
        VBS_3lCR job(treename, fout, "update", true, false, true);
        job.LoopROOT(path_theo + fin, "tree_"+treename, factor);
        job.Close();
    }else{
        VBS_3lCR job(treename, fout, "update", false, false, true);
        job.LoopROOT(path + fin, "tree_"+treename, factor);
        job.Close();

    }
}

int main(int argc, const char *argv[]){
    std::string fin = argv[3];
    std::string fout = argv[1];
    float factor = std::stof(argv[2]);
    std::vector<std::string> systematics = {
        //"NOMINAL",
        "EG_RESOLUTION_ALL__1down",
        "EG_RESOLUTION_ALL__1up",
        "EG_SCALE_AF2__1down",
        "EG_SCALE_AF2__1up",
        "EG_SCALE_ALL__1down",
        "EG_SCALE_ALL__1up",
        "JET_EtaIntercalibration_NonClosure__1up",
        "JET_EtaIntercalibration_NonClosure__1down",
        "JET_GroupedNP_1__1up",
        "JET_GroupedNP_1__1down",
        "JET_GroupedNP_2__1up",
        "JET_GroupedNP_2__1down",
        "JET_GroupedNP_3__1up",
        "JET_GroupedNP_3__1down",
        "JET_JER_SINGLE_NP__1up",
        "MET_SoftTrk_ResoPara",
        "MET_SoftTrk_ResoPerp",
        "MET_SoftTrk_ScaleDown",
        "MET_SoftTrk_ScaleUp",
        "MUON_ID__1down",
        "MUON_ID__1up",
        "MUON_MS__1down",
        "MUON_MS__1up",
        "MUON_SAGITTA_RESBIAS__1down",
        "MUON_SAGITTA_RESBIAS__1up",
        "MUON_SAGITTA_RHO__1down",
        "MUON_SAGITTA_RHO__1up",
        "MUON_SCALE__1down",
        "MUON_SCALE__1up",
        "PRW_DATASF__1down",
        "PRW_DATASF__1up",
    };
    if (fin.find("364284")!=std::string::npos || 
            fin.find("364253")!=std::string::npos){
        process(fin, "NOMINAL", fout, factor, false, true);
        //process(fin, "NOMINAL", fout, factor, true);
        //for (auto key: systematics) process(fin, key, fout, factor, false);
    }else{
        process(fin, "NOMINAL", fout, factor, false, false);
    }
    //process(fin, "NOMINAL", fout, factor, false, false);
    return 0;
}

