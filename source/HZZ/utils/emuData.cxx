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
    std::string path_CR_data15 = "/store/bl2/atlas/lijing/minitrees_rel75/data15/Background/";
    std::string path_CR_data16 = "/store/bl2/atlas/lijing/minitrees_rel75/data16/Background/";
    std::string path_CR_data17 = "/store/bl2/atlas/lijing/minitrees_rel75/data17/Background/";
    std::string path_CR_data18 = "/store/bl2/atlas/lijing/minitrees_rel75/data18/Background/";

    std::string path_CR_mc16a = "/store/bl2/atlas/lijing/minitrees_rel75/mc16a/Systematics_Background/weightSyst/";
    std::string path_CR_mc16d = "/store/bl2/atlas/lijing/minitrees_rel75/mc16d/Systematics_Background/weightSyst/";
    std::string path_CR_mc16e = "/store/bl2/atlas/lijing/minitrees_rel75/mc16e/Systematics_Background/weightSyst/";

    job.LoopROOT(path_SR_data15 + "data15_13TeV.periodD1.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data15 + "data15_13TeV.periodD2.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data15 + "data15_13TeV.periodD3.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data15 + "data15_13TeV.periodD4.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data15 + "data15_13TeV.periodD6.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data15 + "data15_13TeV.periodE.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root" , factor, treeSR);
    job.LoopROOT(path_SR_data15 + "data15_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root" , factor, treeSR);
    job.LoopROOT(path_SR_data15 + "data15_13TeV.periodG.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root" , factor, treeSR);
    job.LoopROOT(path_SR_data15 + "data15_13TeV.periodH.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root" , factor, treeSR);
    job.LoopROOT(path_SR_data15 + "data15_13TeV.periodJ.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root" , factor, treeSR);

    job.LoopROOT(path_SR_data16 + "data16_13TeV.periodA.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data16 + "data16_13TeV.periodB.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data16 + "data16_13TeV.periodC.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data16 + "data16_13TeV.periodD.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data16 + "data16_13TeV.periodE.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data16 + "data16_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data16 + "data16_13TeV.periodG.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data16 + "data16_13TeV.periodI.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data16 + "data16_13TeV.periodK.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data16 + "data16_13TeV.periodL.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root", factor, treeSR);

    job.LoopROOT(path_SR_data17 + "data17_13TeV.periodB.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data17 + "data17_13TeV.periodC.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data17 + "data17_13TeV.periodD.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data17 + "data17_13TeV.periodE.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data17 + "data17_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data17 + "data17_13TeV.periodH.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data17 + "data17_13TeV.periodI.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data17 + "data17_13TeV.periodK.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root", factor, treeSR);

    job.LoopROOT(path_SR_data18 + "data18_13TeV.periodB.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data18 + "data18_13TeV.periodC.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data18 + "data18_13TeV.periodD.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data18 + "data18_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data18 + "data18_13TeV.periodI.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data18 + "data18_13TeV.periodK.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data18 + "data18_13TeV.periodL.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data18 + "data18_13TeV.periodM.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data18 + "data18_13TeV.periodO.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root", factor, treeSR);
    job.LoopROOT(path_SR_data18 + "data18_13TeV.periodQ.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root", factor, treeSR);

    job.LoopROOT(path_CR_data15 + "data15_13TeV.periodD1.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data15 + "data15_13TeV.periodD2.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data15 + "data15_13TeV.periodD3.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data15 + "data15_13TeV.periodD4.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data15 + "data15_13TeV.periodD6.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data15 + "data15_13TeV.periodE.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root" , factor, treeCR);
    job.LoopROOT(path_CR_data15 + "data15_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root" , factor, treeCR);
    job.LoopROOT(path_CR_data15 + "data15_13TeV.periodG.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root" , factor, treeCR);
    job.LoopROOT(path_CR_data15 + "data15_13TeV.periodH.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root" , factor, treeCR);
    job.LoopROOT(path_CR_data15 + "data15_13TeV.periodJ.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root" , factor, treeCR);

    job.LoopROOT(path_CR_data16 + "data16_13TeV.periodA.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data16 + "data16_13TeV.periodB.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data16 + "data16_13TeV.periodC.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data16 + "data16_13TeV.periodD.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data16 + "data16_13TeV.periodE.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data16 + "data16_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data16 + "data16_13TeV.periodG.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data16 + "data16_13TeV.periodI.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data16 + "data16_13TeV.periodK.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data16 + "data16_13TeV.periodL.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root", factor, treeCR);

    job.LoopROOT(path_CR_data17 + "data17_13TeV.periodB.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data17 + "data17_13TeV.periodC.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data17 + "data17_13TeV.periodD.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data17 + "data17_13TeV.periodE.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data17 + "data17_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data17 + "data17_13TeV.periodH.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data17 + "data17_13TeV.periodI.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data17 + "data17_13TeV.periodK.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917_CR.root", factor, treeCR);

    job.LoopROOT(path_CR_data18 + "data18_13TeV.periodB.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data18 + "data18_13TeV.periodC.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data18 + "data18_13TeV.periodD.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data18 + "data18_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data18 + "data18_13TeV.periodI.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data18 + "data18_13TeV.periodK.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data18 + "data18_13TeV.periodL.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data18 + "data18_13TeV.periodM.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data18 + "data18_13TeV.periodO.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_data18 + "data18_13TeV.periodQ.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root", factor, treeCR);

    factor = -1;

    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.345666.Sherpa_222_NNPDF30NNLO_llvvZZ.deriv.DAOD_HIGG2D1.e6240_s3126_r9364_p3872_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.345706.Sherpa_222_NNPDF30NNLO_ggllll_130M4l.deriv.DAOD_HIGG2D1.e6213_s3126_r9364_p3872_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.345723.Sherpa_222_NNPDF30NNLO_ggllvvZZ.deriv.DAOD_HIGG2D1.e6213_s3126_r9364_p3872_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.363356.Sherpa_221_NNPDF30NNLO_ZqqZll.deriv.DAOD_HIGG2D1.e5525_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.363358.Sherpa_221_NNPDF30NNLO_WqqZll.deriv.DAOD_HIGG2D1.e5525_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364100.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5271_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364101.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5271_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364102.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5271_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364103.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5271_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364104.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5271_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364105.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5271_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364106.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5271_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364107.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5271_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364108.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5271_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364109.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5271_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364110.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5271_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364111.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5271_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364112.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5271_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364113.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5271_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364114.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5299_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364115.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5299_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364116.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5299_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364117.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5299_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364118.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5299_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364119.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5299_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364120.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5299_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364121.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5299_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364122.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5299_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364123.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5299_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364124.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5299_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364125.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5299_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364126.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5299_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364127.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5299_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364248.Sherpa_222_NNPDF30NNLO_ZZZ_4l2v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.deriv.DAOD_HIGG2D1.e5894_s3126_r9364_p3872_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364253.Sherpa_222_NNPDF30NNLO_lllv.deriv.DAOD_HIGG2D1.e5916_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364283.Sherpa_222_NNPDF30NNLO_lllljj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364284.Sherpa_222_NNPDF30NNLO_lllvjj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.deriv.DAOD_HIGG2D1.e5070_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_HIGG2D1.e5070_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_HIGG2D1.e5070_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410218.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttee.deriv.DAOD_HIGG2D1.e5070_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410219.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttmumu.deriv.DAOD_HIGG2D1.e5070_s3126_r9364_p3870_CR.root", factor, treeCR);

    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.345666.Sherpa_222_NNPDF30NNLO_llvvZZ.deriv.DAOD_HIGG2D1.e6240_s3126_r10201_p3872_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.345706.Sherpa_222_NNPDF30NNLO_ggllll_130M4l.deriv.DAOD_HIGG2D1.e6213_s3126_r10201_p3872_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.345723.Sherpa_222_NNPDF30NNLO_ggllvvZZ.deriv.DAOD_HIGG2D1.e6213_s3126_r10201_p3872_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.363356.Sherpa_221_NNPDF30NNLO_ZqqZll.deriv.DAOD_HIGG2D1.e5525_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.363358.Sherpa_221_NNPDF30NNLO_WqqZll.deriv.DAOD_HIGG2D1.e5525_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364100.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5271_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364101.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5271_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364102.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5271_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364103.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5271_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364104.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5271_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364105.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5271_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364106.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5271_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364107.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5271_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364108.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5271_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364109.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5271_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364110.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5271_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364111.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5271_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364112.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5271_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364113.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5271_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364114.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5299_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364115.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5299_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364116.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5299_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364117.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5299_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364118.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5299_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364119.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5299_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364120.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5299_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364121.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5299_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364122.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5299_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364123.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5299_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364124.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5299_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364125.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5299_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364126.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5299_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364127.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5299_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364248.Sherpa_222_NNPDF30NNLO_ZZZ_4l2v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.deriv.DAOD_HIGG2D1.e5894_s3126_r10201_p3872_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364253.Sherpa_222_NNPDF30NNLO_lllv.deriv.DAOD_HIGG2D1.e5916_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364283.Sherpa_222_NNPDF30NNLO_lllljj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364284.Sherpa_222_NNPDF30NNLO_lllvjj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_HIGG2D1.e4111_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.deriv.DAOD_HIGG2D1.e5070_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_HIGG2D1.e5070_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_HIGG2D1.e5070_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410218.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttee.deriv.DAOD_HIGG2D1.e5070_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410219.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttmumu.deriv.DAOD_HIGG2D1.e5070_s3126_r10201_p3870_CR.root", factor, treeCR);

    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.345666.Sherpa_222_NNPDF30NNLO_llvvZZ.deriv.DAOD_HIGG2D1.e6240_s3126_r10724_p3872_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.345706.Sherpa_222_NNPDF30NNLO_ggllll_130M4l.deriv.DAOD_HIGG2D1.e6213_s3126_r10724_p3872_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.345723.Sherpa_222_NNPDF30NNLO_ggllvvZZ.deriv.DAOD_HIGG2D1.e6213_s3126_r10724_p3872_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.363356.Sherpa_221_NNPDF30NNLO_ZqqZll.deriv.DAOD_HIGG2D1.e5525_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.363358.Sherpa_221_NNPDF30NNLO_WqqZll.deriv.DAOD_HIGG2D1.e5525_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364100.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5271_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364101.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5271_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364102.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5271_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364103.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5271_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364104.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5271_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364105.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5271_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364106.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5271_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364107.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5271_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364108.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5271_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364109.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5271_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364110.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5271_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364111.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5271_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364112.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5271_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364113.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5271_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364114.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5299_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364115.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5299_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364116.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5299_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364117.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5299_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364118.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5299_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364119.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5299_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364120.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5299_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364121.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5299_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364122.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5299_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364123.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5299_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364124.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5299_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364125.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5299_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364126.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5299_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364127.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5299_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364248.Sherpa_222_NNPDF30NNLO_ZZZ_4l2v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.deriv.DAOD_HIGG2D1.e5894_s3126_r10724_p3872_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364253.Sherpa_222_NNPDF30NNLO_lllv.deriv.DAOD_HIGG2D1.e5916_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364283.Sherpa_222_NNPDF30NNLO_lllljj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364284.Sherpa_222_NNPDF30NNLO_lllvjj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_HIGG2D1.e4111_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.deriv.DAOD_HIGG2D1.e5070_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_HIGG2D1.e5070_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_HIGG2D1.e5070_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410218.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttee.deriv.DAOD_HIGG2D1.e5070_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410219.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttmumu.deriv.DAOD_HIGG2D1.e5070_s3126_r10724_p3870_CR.root", factor, treeCR);

    job.Close();
}


int main(int argc, const char *argv[]){
    //readROOT();
    analysis("Data", "emuCR-Data.root");
    return 0;
}

