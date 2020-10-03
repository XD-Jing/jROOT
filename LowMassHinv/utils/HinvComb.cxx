#include "LowMassHinv/HinvComb.h" 
#include <string>
#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <cmath>


void process(std::string filename){
    //if (folder.find("PFLOW") != std::string::npos){
    HinvComb job("PFLOW", filename, "recreate", false, false);
    //std::string path = "/lustre/umt3/user/liji/HinvComb/PFLOWONLY/";
    std::string path = "/atlas/data19/liji/production_codes/Hinv/run/";
    job.LoopROOT(path + filename, "tree_PFLOW");
    job.LoopROOT(path + filename, "tree_emCR_PFLOW");
    job.LoopROOT(path + filename, "tree_3lCR_PFLOW");
    //job.LoopROOT(path + filename, "tree_4lCR_PFLOW");
    job.Close();
    //}
}



int main(int argc, const char *argv[]){

    std::vector<std::string> files = {
        "mc16_13TeV.311058.MGPy8EG_A14N23LO_PS2HDMtW_a250_DM10_H800_tb10_st0p7_2L.deriv.DAOD_HIGG2D1.e7336_a875_r10724_p3872.root",
        "mc16_13TeV.311130.MGPy8EG_A14N23LO_PS2HDMtW_a250_DM10_H800_tb10_st0p7_1L0L.deriv.DAOD_HIGG2D1.e7335_a875_r10724_p3872.root",
        "mc16_13TeV.313188.MGPy8EG_2HDMa_gg_MonoZ_ll_tb1p0_sp0p35_mH1000_ma350_mDM10.deriv.DAOD_HIGG2D1.e7971_a875_r10724_p3872.root",
        "mc16_13TeV.313189.MGPy8EG_2HDMa_bb_MonoZ_ll_tb1p0_sp0p35_mH1000_ma350_mDM10.deriv.DAOD_HIGG2D1.e7971_a875_r10724_p3872.root",
    };
    for (auto file: files) process(file);
    return 0;
}
