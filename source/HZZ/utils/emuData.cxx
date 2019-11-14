#include "HZZ/emuROOT.h"
#include "HZZ/emuAna.h"
#include <string>
#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <TH2F.h>
#include <cmath>


void readROOT(){
    emuROOT job("PFLOW", "emuCR-Data.root", "recreate", "Data");

    std::string treeSR = "PFLOW";
    std::string treeCR = "emu_PFLOW";
    double factor = 1;

    std::string path_SR_data15 = "/store/bl2/atlas/lijing/minitrees_rel75/data15/Nominal/";
    std::string path_SR_data16 = "/store/bl2/atlas/lijing/minitrees_rel75/data16/Nominal/";
    std::string path_SR_data17 = "/store/bl2/atlas/lijing/minitrees_rel75/data17/Nominal/";
    std::string path_SR_data18 = "/store/bl2/atlas/lijing/minitrees_rel75/data18/Nominal/";
    std::string path_CR_data = "/store/bl2/atlas/lijing/minitrees_rel75/data/";
//    std::string path_CR_data15 = "/store/bl2/atlas/lijing/minitrees_rel75/data15/Background/";
//    std::string path_CR_data16 = "/store/bl2/atlas/lijing/minitrees_rel75/data16/Background/";
//    std::string path_CR_data17 = "/store/bl2/atlas/lijing/minitrees_rel75/data17/Background/";
//    std::string path_CR_data18 = "/store/bl2/atlas/lijing/minitrees_rel75/data18/Background/";

//    job.LoopROOT(path_SR_data15 + "data15_13TeV.periodD1.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data15 + "data15_13TeV.periodD2.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data15 + "data15_13TeV.periodD3.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data15 + "data15_13TeV.periodD4.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data15 + "data15_13TeV.periodD6.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data15 + "data15_13TeV.periodE.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root" , factor, treeSR);
//    job.LoopROOT(path_SR_data15 + "data15_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root" , factor, treeSR);
//    job.LoopROOT(path_SR_data15 + "data15_13TeV.periodG.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root" , factor, treeSR);
//    job.LoopROOT(path_SR_data15 + "data15_13TeV.periodH.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root" , factor, treeSR);
//    job.LoopROOT(path_SR_data15 + "data15_13TeV.periodJ.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root" , factor, treeSR);
//
//    job.LoopROOT(path_SR_data16 + "data16_13TeV.periodA.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data16 + "data16_13TeV.periodB.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data16 + "data16_13TeV.periodC.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data16 + "data16_13TeV.periodD.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data16 + "data16_13TeV.periodE.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data16 + "data16_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data16 + "data16_13TeV.periodG.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data16 + "data16_13TeV.periodI.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data16 + "data16_13TeV.periodK.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data16 + "data16_13TeV.periodL.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root", factor, treeSR);
//
//    job.LoopROOT(path_SR_data17 + "data17_13TeV.periodB.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data17 + "data17_13TeV.periodC.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data17 + "data17_13TeV.periodD.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data17 + "data17_13TeV.periodE.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data17 + "data17_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data17 + "data17_13TeV.periodH.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data17 + "data17_13TeV.periodI.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data17 + "data17_13TeV.periodK.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root", factor, treeSR);
//
//    job.LoopROOT(path_SR_data18 + "data18_13TeV.periodB.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data18 + "data18_13TeV.periodC.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data18 + "data18_13TeV.periodD.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data18 + "data18_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data18 + "data18_13TeV.periodI.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data18 + "data18_13TeV.periodK.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data18 + "data18_13TeV.periodL.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data18 + "data18_13TeV.periodM.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data18 + "data18_13TeV.periodO.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root", factor, treeSR);
//    job.LoopROOT(path_SR_data18 + "data18_13TeV.periodQ.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root", factor, treeSR);

    job.LoopROOT(path_CR_data + "data15_13TeV.periodD1.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data15_13TeV.periodD2.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data15_13TeV.periodD3.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data15_13TeV.periodD4.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data15_13TeV.periodD6.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data15_13TeV.periodE.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root" , factor, treeCR);
    job.LoopROOT(path_CR_data + "data15_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root" , factor, treeCR);
    job.LoopROOT(path_CR_data + "data15_13TeV.periodG.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root" , factor, treeCR);
    job.LoopROOT(path_CR_data + "data15_13TeV.periodH.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root" , factor, treeCR);
    job.LoopROOT(path_CR_data + "data15_13TeV.periodJ.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root" , factor, treeCR);
    job.LoopROOT(path_CR_data + "data16_13TeV.periodA.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data16_13TeV.periodB.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data16_13TeV.periodC.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data16_13TeV.periodD.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data16_13TeV.periodE.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data16_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data16_13TeV.periodG.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data16_13TeV.periodI.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data16_13TeV.periodK.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data16_13TeV.periodL.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data17_13TeV.periodB.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data17_13TeV.periodC.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data17_13TeV.periodD.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data17_13TeV.periodE.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data17_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data17_13TeV.periodH.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data17_13TeV.periodI.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data17_13TeV.periodK.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data18_13TeV.periodB.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data18_13TeV.periodC.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data18_13TeV.periodD.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data18_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data18_13TeV.periodI.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data18_13TeV.periodK.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data18_13TeV.periodL.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data18_13TeV.periodM.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data18_13TeV.periodO.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data + "data18_13TeV.periodQ.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root", factor, treeCR);

    job.Close();
}


int main(int argc, const char *argv[]){
    //readROOT();
    analysis("Data", "emuCR-Data.root");
    return 0;
}
