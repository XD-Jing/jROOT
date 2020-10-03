#include "VBSZZ/VBS_CutFlow.h" 
#include <string>
#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <cmath>

#define factor 1
std::string path = "/lustre/umt3/user/liji/VBSZZ-samples/p3759-minitrees/";
std::string tree = "tree_NOMINAL";

void process_Data(std::string folder){
    VBS_CutFlow job("NOMINAL", "CutFlow_llvv_Data_NOMINAL.root", "recreate", false, false);

    std::vector<std::string> samples = {
        "data15_13TeV.periodD.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data15_13TeV.periodE.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data15_13TeV.periodF.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data15_13TeV.periodG.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data15_13TeV.periodH.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data15_13TeV.periodJ.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data16_13TeV.periodA.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data16_13TeV.periodB.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data16_13TeV.periodC.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data16_13TeV.periodD.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data16_13TeV.periodE.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data16_13TeV.periodF.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data16_13TeV.periodG.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data16_13TeV.periodI.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data16_13TeV.periodK.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data16_13TeV.periodL.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data17_13TeV.periodB.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data17_13TeV.periodC.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data17_13TeV.periodD.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data17_13TeV.periodE.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data17_13TeV.periodF.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data17_13TeV.periodH.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data17_13TeV.periodI.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data17_13TeV.periodK.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data18_13TeV.periodB.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data18_13TeV.periodC.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data18_13TeV.periodD.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data18_13TeV.periodF.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data18_13TeV.periodI.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data18_13TeV.periodK.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data18_13TeV.periodL.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data18_13TeV.periodM.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data18_13TeV.periodO.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
        "data18_13TeV.periodQ.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root",
    };

    for (auto sample: samples) job.LoopROOT(path + sample);
    job.Close();
}



void process_EWK(std::string folder){
    if (folder.find("NOMINAL") != std::string::npos){
        VBS_CutFlow job("NOMINAL", "CutFlow_llvv_EWK_NOMINAL.root","recreate", false, false);

        job.LoopROOT(path + "mc16_13TeV.363724.MadGraphPythia8EvtGen_ZZllvv2jEWK.deriv.DAOD_STDM3.e5712_s3126_r9364_p3759.root ", tree, 3);
        job.LoopROOT(path + "mc16_13TeV.363724.MadGraphPythia8EvtGen_ZZllvv2jEWK.deriv.DAOD_STDM3.e5712_s3126_r10201_p3759.root", tree, 3);
        job.LoopROOT(path + "mc16_13TeV.363724.MadGraphPythia8EvtGen_ZZllvv2jEWK.deriv.DAOD_STDM3.e5712_s3126_r10724_p3759.root", tree, 3);

        job.Close();
    }else{
    }
}

void process_qqZZ(std::string folder){
    if (folder.find("NOMINAL") != std::string::npos){
        VBS_CutFlow job("NOMINAL", "CutFlow_llvv_qqZZ_NOMINAL.root","recreate", false, false);

        job.LoopROOT(path + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_STDM3.e5916_s3126_r9364_p3759.isZZWW1.root ", tree, 1.5);
        job.LoopROOT(path + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_STDM3.e5916_s3126_r10201_p3759.isZZWW1.root", tree, 1.5);
        job.LoopROOT(path + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_STDM3.e5916_s3126_r10724_p3759.isZZWW1.root", tree, 1.5);

        job.Close();
    }else{
    }
}

void process_ggZZ(std::string folder){
    if (folder.find("NOMINAL") != std::string::npos){
        VBS_CutFlow job("NOMINAL", "CutFlow_llvv_ggZZ_NOMINAL.root","recreate", false, false);

        job.LoopROOT(path + "mc16_13TeV.343233.Powheggg2vvPythia8EvtGen_ggH125p5_gg_ZZ_2l2v_13TeV.deriv.DAOD_STDM3.e4568_s3126_r9364_p3759.root ", tree);
        job.LoopROOT(path + "mc16_13TeV.343233.Powheggg2vvPythia8EvtGen_ggH125p5_gg_ZZ_2l2v_13TeV.deriv.DAOD_STDM3.e4568_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.343233.Powheggg2vvPythia8EvtGen_ggH125p5_gg_ZZ_2l2v_13TeV.deriv.DAOD_STDM3.e4568_s3126_r10724_p3759.root", tree);

        job.Close();
    }else{
    }
}

void process_WZ(std::string folder){
    if (folder.find("NOMINAL") != std::string::npos){
        VBS_CutFlow job("NOMINAL", "CutFlow_llvv_WZ_NOMINAL.root","recreate", false, false);
            
        job.LoopROOT(path + "mc16_13TeV.364253.Sherpa_222_NNPDF30NNLO_lllv.deriv.DAOD_STDM3.e5916_s3126_r9364_p3759.root ", tree);
        job.LoopROOT(path + "mc16_13TeV.364253.Sherpa_222_NNPDF30NNLO_lllv.deriv.DAOD_STDM3.e5916_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364253.Sherpa_222_NNPDF30NNLO_lllv.deriv.DAOD_STDM3.e5916_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364284.Sherpa_222_NNPDF30NNLO_lllvjj_EW6.deriv.DAOD_STDM3.e6055_s3126_r9364_p3759.root ", tree);
        job.LoopROOT(path + "mc16_13TeV.364284.Sherpa_222_NNPDF30NNLO_lllvjj_EW6.deriv.DAOD_STDM3.e6055_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364284.Sherpa_222_NNPDF30NNLO_lllvjj_EW6.deriv.DAOD_STDM3.e6055_s3126_r10724_p3759.root", tree);

        job.Close();
    }else{
    }
}

void process_ZJets(std::string folder){
    if (folder.find("NOMINAL") != std::string::npos){
        VBS_CutFlow job("NOMINAL", "CutFlow_llvv_ZJets_NOMINAL.root","recreate", false, false);
            
        job.LoopROOT(path + "mc16_13TeV.364100.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364100.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364100.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364101.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364101.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364101.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364102.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_BFilter.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364102.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_BFilter.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364102.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_BFilter.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364103.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364103.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364103.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364104.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364104.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364104.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364105.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_BFilter.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364105.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_BFilter.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364105.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_BFilter.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364106.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364106.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364106.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364107.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364107.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364107.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364108.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_BFilter.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364108.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_BFilter.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364108.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_BFilter.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364109.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364109.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364109.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364110.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364110.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364110.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364111.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_BFilter.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364111.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_BFilter.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364111.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_BFilter.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364112.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV500_1000.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364112.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV500_1000.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364112.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV500_1000.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364113.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV1000_E_CMS.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364113.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV1000_E_CMS.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364113.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV1000_E_CMS.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364114.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364114.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364114.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364115.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364115.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364115.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364116.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_BFilter.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364116.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_BFilter.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364116.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_BFilter.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364117.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364117.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364117.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364118.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364118.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364118.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364119.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_BFilter.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364119.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_BFilter.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364119.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_BFilter.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364120.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364120.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364120.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364121.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364121.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364121.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364122.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_BFilter.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364122.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_BFilter.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364122.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_BFilter.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364123.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364123.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364123.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364124.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364124.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364124.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364125.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_BFilter.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364125.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_BFilter.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364125.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_BFilter.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364126.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV500_1000.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364126.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV500_1000.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364126.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV500_1000.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364127.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV1000_E_CMS.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364127.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV1000_E_CMS.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364127.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV1000_E_CMS.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root", tree);

        job.Close();
    }else{
    }
}

void process_NonRes(std::string folder){
    if (folder.find("NOMINAL") != std::string::npos){
        VBS_CutFlow job("NOMINAL", "CutFlow_llvv_NonRes_NOMINAL.root","recreate", false, false);

        job.LoopROOT(path + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_STDM3.e5307_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_STDM3.e5307_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_STDM3.e5307_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_STDM3.e5307_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_STDM3.e5307_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_STDM3.e5307_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_STDM3.e5307_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_STDM3.e5307_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_STDM3.e5307_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_STDM3.e5307_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_STDM3.e5307_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_STDM3.e5307_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_STDM3.e5307_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_STDM3.e5307_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_STDM3.e5307_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_STDM3.e5307_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_STDM3.e5307_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_STDM3.e5307_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_STDM3.e5307_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_STDM3.e5307_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_STDM3.e5307_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_STDM3.e5307_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_STDM3.e5307_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_STDM3.e5307_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_STDM3.e5307_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_STDM3.e5307_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_STDM3.e5307_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_STDM3.e5307_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_STDM3.e5307_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_STDM3.e5307_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_STDM3.e5313_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_STDM3.e5313_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_STDM3.e5313_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_STDM3.e5313_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_STDM3.e5313_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_STDM3.e5313_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_STDM3.e5307_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_STDM3.e5307_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_STDM3.e5307_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_STDM3.e5307_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_STDM3.e5307_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_STDM3.e5307_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_STDM3.e5916_s3126_r10201_p3759.isZZWW-1.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_STDM3.e5916_s3126_r10201_p3759.isZZWW0.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_STDM3.e5916_s3126_r10201_p3759.isZZWW1.root", tree, -0.5);
        job.LoopROOT(path + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_STDM3.e5916_s3126_r10724_p3759.isZZWW-1.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_STDM3.e5916_s3126_r10724_p3759.isZZWW0.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_STDM3.e5916_s3126_r10724_p3759.isZZWW1.root", tree, -0.5);
        job.LoopROOT(path + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_STDM3.e5916_s3126_r9364_p3759.isZZWW-1.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_STDM3.e5916_s3126_r9364_p3759.isZZWW0.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_STDM3.e5916_s3126_r9364_p3759.isZZWW1.root", tree, -0.5);
        job.LoopROOT(path + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_STDM3.e6348_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_STDM3.e6348_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_STDM3.e6348_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_STDM3.e6527_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_STDM3.e6527_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_STDM3.e6527_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_STDM3.e6527_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_STDM3.e6527_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_STDM3.e6527_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410648.PowhegPythia8EvtGen_A14_Wt_DR_dilepton_top.deriv.DAOD_STDM3.e6615_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410648.PowhegPythia8EvtGen_A14_Wt_DR_dilepton_top.deriv.DAOD_STDM3.e6615_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410648.PowhegPythia8EvtGen_A14_Wt_DR_dilepton_top.deriv.DAOD_STDM3.e6615_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410649.PowhegPythia8EvtGen_A14_Wt_DR_dilepton_antitop.deriv.DAOD_STDM3.e6615_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410649.PowhegPythia8EvtGen_A14_Wt_DR_dilepton_antitop.deriv.DAOD_STDM3.e6615_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410649.PowhegPythia8EvtGen_A14_Wt_DR_dilepton_antitop.deriv.DAOD_STDM3.e6615_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_STDM3.e6671_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_STDM3.e6671_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_STDM3.e6671_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_STDM3.e6671_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_STDM3.e6671_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_STDM3.e6671_s3126_r9364_p3759.root", tree);

        job.Close();
    }else{
    }
}

void process_Other(std::string folder){
    if (folder.find("NOMINAL") != std::string::npos){
        VBS_CutFlow job("NOMINAL", "CutFlow_llvv_Other_NOMINAL.root","recreate", false, false);

        job.LoopROOT(path + "mc16_13TeV.345706.Sherpa_222_NNPDF30NNLO_ggllll_130M4l.deriv.DAOD_STDM3.e6213_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.345706.Sherpa_222_NNPDF30NNLO_ggllll_130M4l.deriv.DAOD_STDM3.e6213_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.345706.Sherpa_222_NNPDF30NNLO_ggllll_130M4l.deriv.DAOD_STDM3.e6213_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364248.Sherpa_222_NNPDF30NNLO_ZZZ_4l2v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364248.Sherpa_222_NNPDF30NNLO_ZZZ_4l2v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364248.Sherpa_222_NNPDF30NNLO_ZZZ_4l2v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.deriv.DAOD_STDM3.e5894_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.deriv.DAOD_STDM3.e5894_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.deriv.DAOD_STDM3.e5894_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364283.Sherpa_222_NNPDF30NNLO_lllljj_EW6.deriv.DAOD_STDM3.e6055_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364283.Sherpa_222_NNPDF30NNLO_lllljj_EW6.deriv.DAOD_STDM3.e6055_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.364283.Sherpa_222_NNPDF30NNLO_lllljj_EW6.deriv.DAOD_STDM3.e6055_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_STDM3.e4111_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_STDM3.e4111_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_STDM3.e4111_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.deriv.DAOD_STDM3.e5070_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.deriv.DAOD_STDM3.e5070_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.deriv.DAOD_STDM3.e5070_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_STDM3.e5070_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_STDM3.e5070_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_STDM3.e5070_s3126_r9364_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_STDM3.e5070_s3126_r10201_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_STDM3.e5070_s3126_r10724_p3759.root", tree);
        job.LoopROOT(path + "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_STDM3.e5070_s3126_r9364_p3759.root", tree);

        job.Close();
    }else{
    }
}
int main(int argc, const char *argv[]){
    std::string tree_SYST = "NOMINAL";
    if (argc==2) tree_SYST = argv[1];
    //process(tree_SYST);
    process_Data(tree_SYST);
    //process_EWK(tree_SYST);
    //process_ggZZ(tree_SYST);
    //process_qqZZ(tree_SYST);
    //process_WZ(tree_SYST);
    //process_ZJets(tree_SYST);
    //process_NonRes(tree_SYST);
    //process_Other(tree_SYST);
    return 0;
}
