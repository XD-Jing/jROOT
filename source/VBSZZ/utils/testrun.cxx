#include "VBSZZ/jTREE.h"
#include <string>
#include <iostream>
#include <TString.h>

void read_Tree(std::string treename){
    jTREE t(treename);
    std::string path = "/lustre/umt3/user/liji/VBSZZ-samples/p3761-minitrees/";
    t.LoopROOT(path + "mc16_13TeV.363724.MadGraphPythia8EvtGen_ZZllvv2jEWK.deriv.DAOD_STDM3.e5712_s3126_r9364_p3761.root" , 0.001353 * 3);
    t.LoopROOT(path + "mc16_13TeV.363724.MadGraphPythia8EvtGen_ZZllvv2jEWK.deriv.DAOD_STDM3.e5712_s3126_r10201_p3761.root", 0.001353 * 3);
    t.LoopROOT(path + "mc16_13TeV.363724.MadGraphPythia8EvtGen_ZZllvv2jEWK.deriv.DAOD_STDM3.e5712_s3126_r10724_p3761.root", 0.001353 * 3);
}


int main(int argc, const char *argv[]){
    //TString fname(argv[1]);

    read_Tree("NOMINAL");
    return 0;
}
