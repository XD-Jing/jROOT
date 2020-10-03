#include "VBSZZ/VBS_CutFlow.h" 
#include <string>
#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <cmath>

std::string path = "/lustre/umt3/user/liji/VBSZZ-samples/p3759-minitrees/";
std::string tree = "tree_NOMINAL";

int main(int argc, const char *argv[]){
    std::string ntuple_input = argv[3];
    std::string ntuple_output = argv[1];
    float factor = std::stoi(argv[2]);
    VBS_CutFlow job("NOMINAL", ntuple_output, "recreate", false, false);
    job.LoopROOT(path + ntuple_input, tree, factor);
    job.Close();
    return 0;
}

