#include "HZZ/emuSYST.h"
#include <string>
#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <cmath>


//float Yield(TFile *f, std::string hname){
//    TH1F *h = (TH1F*)f->Get(hname.c_str());
//    return h->Integral(0, -1);
//}

void run(std::string folder){
    if (folder.find("PFLOW") != std::string::npos){
        emuSYST job("PFLOW", "emuSYST-rel75-HM.root","recreate", false, true);
        std::string path_CR_mc16a = "/eos/atlas/atlascerngroupdisk/phys-higgs/HSG2/Hllvv/Run2/minitrees_rel75/mc16a/Systematics_Background/weightSyst/";
        std::string path_CR_mc16d = "/eos/atlas/atlascerngroupdisk/phys-higgs/HSG2/Hllvv/Run2/minitrees_rel75/mc16d/Systematics_Background/weightSyst/";
        std::string path_CR_mc16e = "/eos/atlas/atlascerngroupdisk/phys-higgs/HSG2/Hllvv/Run2/minitrees_rel75/mc16e/Systematics_Background/weightSyst/";

        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root");

        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r10201_p3652_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root");

        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root");

        job.Close();
    }else{
        emuSYST job(folder, "emuSYST-rel75-HM.root","update", false, false);
        std::string path_CR_mc16a = "/eos/atlas/atlascerngroupdisk/phys-higgs/HSG2/Hllvv/Run2/minitrees_rel75/mc16a/Systematics_Background/"+folder+"/";
        std::string path_CR_mc16d = "/eos/atlas/atlascerngroupdisk/phys-higgs/HSG2/Hllvv/Run2/minitrees_rel75/mc16d/Systematics_Background/"+folder+"/";
        std::string path_CR_mc16e = "/eos/atlas/atlascerngroupdisk/phys-higgs/HSG2/Hllvv/Run2/minitrees_rel75/mc16e/Systematics_Background/"+folder+"/";

        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root");
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root");

        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r10201_p3652_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root");
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root");

        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root");
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root");

        job.Close();
    }
}


int main(int argc, const char *argv[]){

    std::vector<std::string> folders = {
        /*
        "PFLOW",
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
        */
        "JET_JER_EffectiveNP_7restTerm__1down" ,"JET_JER_EffectiveNP_7restTerm__1up"
        /*
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
        */
    };
    for (auto folder: folders) run(folder);
    return 0;
}
