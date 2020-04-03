#include "LowMassHinv/LM_ZZ.h" 
#include <string>
#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <cmath>


void qqZZ(std::string folder){
    if (folder.find("PFLOW") != std::string::npos){
        LM_ZZ qqZZ("PFLOW", "qqZZ-rel75-LM.root","recreate", true, true);
        //LM_ZZ qqZZ("PFLOW", "qqZZ-rel75-LM.root","recreate", false, false);
        qqZZ.LoopROOT("/eos/atlas/atlascerngroupdisk/phys-higgs/HSG2/Hllvv/Run2/minitrees_rel75/mc16a/Systematics/weightSyst/mc16_13TeV.345666.Sherpa_222_NNPDF30NNLO_llvvZZ.deriv.DAOD_HIGG2D1.e6240_s3126_r9364_p3872.root");
        qqZZ.LoopROOT("/eos/atlas/atlascerngroupdisk/phys-higgs/HSG2/Hllvv/Run2/minitrees_rel75/mc16d/Systematics/weightSyst/mc16_13TeV.345666.Sherpa_222_NNPDF30NNLO_llvvZZ.deriv.DAOD_HIGG2D1.e6240_s3126_r10201_p3872.root");
        qqZZ.LoopROOT("/eos/atlas/atlascerngroupdisk/phys-higgs/HSG2/Hllvv/Run2/minitrees_rel75/mc16e/Systematics/weightSyst/mc16_13TeV.345666.Sherpa_222_NNPDF30NNLO_llvvZZ.deriv.DAOD_HIGG2D1.e6240_s3126_r10724_p3872.root");
        qqZZ.Close();
    }else{
        LM_ZZ qqZZ(folder, "qqZZ-rel75-LM.root","update", false, false);
        qqZZ.LoopROOT("/eos/atlas/atlascerngroupdisk/phys-higgs/HSG2/Hllvv/Run2/minitrees_rel75/mc16a/Systematics/"+folder+"/mc16_13TeV.345666.Sherpa_222_NNPDF30NNLO_llvvZZ.deriv.DAOD_HIGG2D1.e6240_s3126_r9364_p3872.root");
        qqZZ.LoopROOT("/eos/atlas/atlascerngroupdisk/phys-higgs/HSG2/Hllvv/Run2/minitrees_rel75/mc16d/Systematics/"+folder+"/mc16_13TeV.345666.Sherpa_222_NNPDF30NNLO_llvvZZ.deriv.DAOD_HIGG2D1.e6240_s3126_r10201_p3872.root");
        qqZZ.LoopROOT("/eos/atlas/atlascerngroupdisk/phys-higgs/HSG2/Hllvv/Run2/minitrees_rel75/mc16e/Systematics/"+folder+"/mc16_13TeV.345666.Sherpa_222_NNPDF30NNLO_llvvZZ.deriv.DAOD_HIGG2D1.e6240_s3126_r10724_p3872.root");
        qqZZ.Close();
    }
}

void ggZZ(std::string folder){
    if (folder.find("PFLOW") != std::string::npos){
        LM_ZZ ggZZ("PFLOW", "ggZZ-rel75-LM.root","recreate", true, true);
        ggZZ.LoopROOT("/eos/atlas/atlascerngroupdisk/phys-higgs/HSG2/Hllvv/Run2/minitrees_rel75/mc16a/Systematics/weightSyst/mc16_13TeV.345723.Sherpa_222_NNPDF30NNLO_ggllvvZZ.deriv.DAOD_HIGG2D1.e6213_s3126_r9364_p3872.root");
        ggZZ.LoopROOT("/eos/atlas/atlascerngroupdisk/phys-higgs/HSG2/Hllvv/Run2/minitrees_rel75/mc16d/Systematics/weightSyst/mc16_13TeV.345723.Sherpa_222_NNPDF30NNLO_ggllvvZZ.deriv.DAOD_HIGG2D1.e6213_s3126_r10201_p3872.root");
        ggZZ.LoopROOT("/eos/atlas/atlascerngroupdisk/phys-higgs/HSG2/Hllvv/Run2/minitrees_rel75/mc16e/Systematics/weightSyst/mc16_13TeV.345723.Sherpa_222_NNPDF30NNLO_ggllvvZZ.deriv.DAOD_HIGG2D1.e6213_s3126_r10724_p3872.root");
        ggZZ.Close();
    }else{
        LM_ZZ ggZZ(folder, "ggZZ-rel75-LM.root","update", false, false);
        ggZZ.LoopROOT("/eos/atlas/atlascerngroupdisk/phys-higgs/HSG2/Hllvv/Run2/minitrees_rel75/mc16a/Systematics/"+folder+"/mc16_13TeV.345723.Sherpa_222_NNPDF30NNLO_ggllvvZZ.deriv.DAOD_HIGG2D1.e6213_s3126_r9364_p3872.root");
        ggZZ.LoopROOT("/eos/atlas/atlascerngroupdisk/phys-higgs/HSG2/Hllvv/Run2/minitrees_rel75/mc16d/Systematics/"+folder+"/mc16_13TeV.345723.Sherpa_222_NNPDF30NNLO_ggllvvZZ.deriv.DAOD_HIGG2D1.e6213_s3126_r10201_p3872.root");
        ggZZ.LoopROOT("/eos/atlas/atlascerngroupdisk/phys-higgs/HSG2/Hllvv/Run2/minitrees_rel75/mc16e/Systematics/"+folder+"/mc16_13TeV.345723.Sherpa_222_NNPDF30NNLO_ggllvvZZ.deriv.DAOD_HIGG2D1.e6213_s3126_r10724_p3872.root");
        ggZZ.Close();
    }
}

int main(int argc, const char *argv[]){

    std::vector<std::string> folders = {"PFLOW",
        "EG_RESOLUTION_ALL__1down" ,"EG_RESOLUTION_ALL__1up",
        "EG_SCALE_AF2__1down" ,"EG_SCALE_AF2__1up",
        "EG_SCALE_ALL__1down" ,"EG_SCALE_ALL__1up",
        "JET_BJES_Response__1down" ,"JET_BJES_Response__1up",
        "JET_EffectiveNP_1__1down" ,"JET_EffectiveNP_1__1up",
        "JET_EffectiveNP_2__1down" ,"JET_EffectiveNP_2__1up",
        "JET_EffectiveNP_3__1down" ,"JET_EffectiveNP_3__1up",
        "JET_EffectiveNP_4__1down" ,"JET_EffectiveNP_4__1up",
        "JET_EffectiveNP_5__1down" ,"JET_EffectiveNP_5__1up",
        "JET_EffectiveNP_6__1down" ,"JET_EffectiveNP_6__1up",
        "JET_EffectiveNP_7__1down" ,"JET_EffectiveNP_7__1up",
        "JET_EffectiveNP_8restTerm__1down" ,"JET_EffectiveNP_8restTerm__1up",
        "JET_EtaIntercalibration_Modelling__1down" ,"JET_EtaIntercalibration_Modelling__1up",
        "JET_EtaIntercalibration_NonClosure_highE__1down" ,"JET_EtaIntercalibration_NonClosure_highE__1up",
        "JET_EtaIntercalibration_NonClosure_negEta__1down" ,"JET_EtaIntercalibration_NonClosure_negEta__1up",
        "JET_EtaIntercalibration_NonClosure_posEta__1down" ,"JET_EtaIntercalibration_NonClosure_posEta__1up",
        "JET_EtaIntercalibration_TotalStat__1down" ,"JET_EtaIntercalibration_TotalStat__1up",
        "JET_Flavor_Composition__1down" ,"JET_Flavor_Composition__1up",
        "JET_Flavor_Response__1down" ,"JET_Flavor_Response__1up",
        "JET_JER_DataVsMC_MC16__1down" ,"JET_JER_DataVsMC_MC16__1up",
        "JET_JER_EffectiveNP_1__1down" ,"JET_JER_EffectiveNP_1__1up",
        "JET_JER_EffectiveNP_2__1down" ,"JET_JER_EffectiveNP_2__1up",
        "JET_JER_EffectiveNP_3__1down" ,"JET_JER_EffectiveNP_3__1up",
        "JET_JER_EffectiveNP_4__1down" ,"JET_JER_EffectiveNP_4__1up",
        "JET_JER_EffectiveNP_5__1down" ,"JET_JER_EffectiveNP_5__1up",
        "JET_JER_EffectiveNP_6__1down" ,"JET_JER_EffectiveNP_6__1up",
        "JET_JER_EffectiveNP_7restTerm__1down" ,"JET_JER_EffectiveNP_7restTerm__1up",
        "JET_Pileup_OffsetMu__1down" ,"JET_Pileup_OffsetMu__1up",
        "JET_Pileup_OffsetNPV__1down" ,"JET_Pileup_OffsetNPV__1up",
        "JET_Pileup_PtTerm__1down" ,"JET_Pileup_PtTerm__1up",
        "JET_Pileup_RhoTopology__1down" ,"JET_Pileup_RhoTopology__1up",
        "JET_PunchThrough_MC16__1down" ,"JET_PunchThrough_MC16__1up",
        "JET_SingleParticle_HighPt__1down" ,"JET_SingleParticle_HighPt__1up",
        "MET_SoftTrk_ResoPara" ,"MET_SoftTrk_ResoPerp",
        "MET_SoftTrk_ScaleDown" ,"MET_SoftTrk_ScaleUp",
        "MUON_ID__1down" ,"MUON_ID__1up",
        "MUON_MS__1down" ,"MUON_MS__1up",
        "MUON_SAGITTA_RESBIAS__1down" ,"MUON_SAGITTA_RESBIAS__1up",
        "MUON_SAGITTA_RHO__1down" ,"MUON_SAGITTA_RHO__1up",
        "MUON_SCALE__1down" ,"MUON_SCALE__1up"
        };
    for (auto folder: folders) qqZZ(folder);
    //for (auto folder: folders) ggZZ(folder);
    return 0;
}
