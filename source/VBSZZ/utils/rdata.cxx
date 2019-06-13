#include "VBSZZ/jTREE.h"
#include <string>
#include <iostream>
#include <TString.h>

void read_Tree(std::string treename){
    jTREE t(treename, "data.root");
    std::string path = "/lustre/umt3/user/liji/VBSZZ-samples/p3759-2Jets/";
    //std::string path = "/lustre/umt3/user/liji/VBSZZ-samples/p3759-3lCR/";
    t.LoopROOT(path + "data15_13TeV.periodD.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data15_13TeV.periodE.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data15_13TeV.periodF.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data15_13TeV.periodG.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data15_13TeV.periodH.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data15_13TeV.periodJ.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data16_13TeV.periodA.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data16_13TeV.periodB.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data16_13TeV.periodC.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data16_13TeV.periodD.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data16_13TeV.periodE.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data16_13TeV.periodF.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data16_13TeV.periodG.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data16_13TeV.periodI.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data16_13TeV.periodK.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data16_13TeV.periodL.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data17_13TeV.periodB.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data17_13TeV.periodC.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data17_13TeV.periodD.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data17_13TeV.periodE.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data17_13TeV.periodF.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data17_13TeV.periodH.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data17_13TeV.periodI.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data17_13TeV.periodK.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data18_13TeV.periodB.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data18_13TeV.periodC.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data18_13TeV.periodD.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data18_13TeV.periodF.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data18_13TeV.periodI.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data18_13TeV.periodK.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data18_13TeV.periodL.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data18_13TeV.periodM.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data18_13TeV.periodO.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data18_13TeV.periodQ.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
}


int main(int argc, const char *argv[]){
    read_Tree("NOMINAL");
    return 0;
}
