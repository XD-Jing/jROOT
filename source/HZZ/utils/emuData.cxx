#include "HZZ/emuROOT.h"
#include "HZZ/emuAna.h"
#include <string>
#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <TH2F.h>
#include <cmath>


void readROOT(){
    emuROOT job("PFLOW", "emuCR-test.root","recreate");

    std::string path_data15 = "/store/bl2/atlas/lijing/minitrees_rel75/data15/Nominal/";
    job.LoopROOT(path_data15 + "data15_13TeV.periodD1.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root");
    job.LoopROOT(path_data15 + "data15_13TeV.periodD2.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root");
    job.LoopROOT(path_data15 + "data15_13TeV.periodD3.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root");
    job.LoopROOT(path_data15 + "data15_13TeV.periodD4.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root");
    job.LoopROOT(path_data15 + "data15_13TeV.periodD6.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root");
    job.LoopROOT(path_data15 + "data15_13TeV.periodE.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root");
    job.LoopROOT(path_data15 + "data15_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root");
    job.LoopROOT(path_data15 + "data15_13TeV.periodG.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root");
    job.LoopROOT(path_data15 + "data15_13TeV.periodH.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root");
    job.LoopROOT(path_data15 + "data15_13TeV.periodJ.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root");

    std::string path_data16 = "/store/bl2/atlas/lijing/minitrees_rel75/data16/Nominal/";
    job.LoopROOT(path_data16 + "data16_13TeV.periodA.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root");
    job.LoopROOT(path_data16 + "data16_13TeV.periodB.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root");
    job.LoopROOT(path_data16 + "data16_13TeV.periodC.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root");
    job.LoopROOT(path_data16 + "data16_13TeV.periodD.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root");
    job.LoopROOT(path_data16 + "data16_13TeV.periodE.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root");
    job.LoopROOT(path_data16 + "data16_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root");
    job.LoopROOT(path_data16 + "data16_13TeV.periodG.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root");
    job.LoopROOT(path_data16 + "data16_13TeV.periodI.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root");
    job.LoopROOT(path_data16 + "data16_13TeV.periodK.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root");
    job.LoopROOT(path_data16 + "data16_13TeV.periodL.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root");

    std::string path_data17 = "/store/bl2/atlas/lijing/minitrees_rel75/data17/Nominal/";
    job.LoopROOT(path_data17 + "data17_13TeV.periodB.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root");
    job.LoopROOT(path_data17 + "data17_13TeV.periodC.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root");
    job.LoopROOT(path_data17 + "data17_13TeV.periodD.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root");
    job.LoopROOT(path_data17 + "data17_13TeV.periodE.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root");
    job.LoopROOT(path_data17 + "data17_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root");
    job.LoopROOT(path_data17 + "data17_13TeV.periodH.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root");
    job.LoopROOT(path_data17 + "data17_13TeV.periodI.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root");
    job.LoopROOT(path_data17 + "data17_13TeV.periodK.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root");

    std::string path_data18 = "/store/bl2/atlas/lijing/minitrees_rel75/data18/Nominal/";
    job.LoopROOT(path_data18 + "data18_13TeV.periodB.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root");
    job.LoopROOT(path_data18 + "data18_13TeV.periodC.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root");
    job.LoopROOT(path_data18 + "data18_13TeV.periodD.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root");
    job.LoopROOT(path_data18 + "data18_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root");
    job.LoopROOT(path_data18 + "data18_13TeV.periodI.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root");
    job.LoopROOT(path_data18 + "data18_13TeV.periodK.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root");
    job.LoopROOT(path_data18 + "data18_13TeV.periodL.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root");
    job.LoopROOT(path_data18 + "data18_13TeV.periodM.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root");
    job.LoopROOT(path_data18 + "data18_13TeV.periodO.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root");
    job.LoopROOT(path_data18 + "data18_13TeV.periodQ.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root");
    job.Close();
}


int main(int argc, const char *argv[]){
    readROOT();
    //analysis();
    return 0;
}
