#include "VBSZZ/SlimTree.h" 
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
    int factor = std::stoi(argv[2]);
    SlimTree job("NOMINAL", ntuple_output, "recreate", false, false);
    std::string filepath = path + ntuple_input;
    job.LoopROOT(filepath, "tree_NOMINAL",  "weight", "tree_NOMINAL", factor);
    job.LoopROOT(filepath, "tree_NOMINAL",  "weight_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR__1down", "tree_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR__1down", factor);
    job.Close();
    return 0;
}

