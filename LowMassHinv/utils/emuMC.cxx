#include "LowMassHinv/emuMC.h" 
#include <string>
#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <cmath>

#define path_SR_mc16a "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/mc16a/Systematics/"
#define path_SR_mc16d "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/mc16d/Systematics/"
#define path_SR_mc16e "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/mc16e/Systematics/"
#define path_CR_mc16a "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/mc16a/Systematics_Background/"
#define path_CR_mc16d "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/mc16d/Systematics_Background/"
#define path_CR_mc16e "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/mc16e/Systematics_Background/"
#define treeSR "tree_PFLOW"
#define treeCR "tree_emu_PFLOW"
#define factor 1

void process(std::string folder){

    if (folder.find("PFLOW") != std::string::npos){
        emuMC job("PFLOW", "LM-emuMC-rel75-"+folder+".root","recreate", false, false);
        std::string subpath = "weightSyst/";
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);

        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r10201_p3652.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);

        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);

        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);

        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r10201_p3652_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);

        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.Close();
    }else{
        emuMC job(folder, "LM-emuMC-rel75-"+folder+".root","recreate", false, false);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);

        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r10201_p3652.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);

        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);

        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);

        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r10201_p3652_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);

        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.Close();
    }
}

void process_powhegWW(std::string folder){

    if (folder.find("PFLOW") != std::string::npos){
        emuMC job("PFLOW", "LM-emuMC-rel75-powhegWW-"+folder+".root","recreate", true, false, "ww");
        std::string subpath = "weightSyst/";

        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r10201_p3652.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r10724_p3870.root", treeSR);

        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r10201_p3652_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r10724_p3870_CR.root", treeCR);
        job.Close();
    }else{
        emuMC job(folder, "LM-emuMC-rel75-powhegWW-"+folder+".root","recreate", false, false);

        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r10201_p3652.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r10724_p3870.root", treeSR);

        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r10201_p3652_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r10724_p3870_CR.root", treeCR);
        job.Close();
    }
}

void process_sherpaWW(std::string folder){

    if (folder.find("PFLOW") != std::string::npos){
        emuMC job("PFLOW", "LM-emuMC-rel75-sherpaWW-"+folder+".root","recreate", true, false, "sherpa");
        std::string subpath = "weightSyst/";

        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_HIGG2D1.e5916_s3126_r9364_p3652.isZZWW0.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_HIGG2D1.e5916_s3126_r9364_p3652.isZZWW2.root", treeSR, -0.5);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364285.Sherpa_222_NNPDF30NNLO_llvvjj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r9364_p3870.isZZWW0.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364285.Sherpa_222_NNPDF30NNLO_llvvjj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r9364_p3870.isZZWW2.root", treeSR, -0.5);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.345718.Sherpa_222_NNPDF30NNLO_ggllvvWW.deriv.DAOD_HIGG2D1.e6525_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_HIGG2D1.e5916_s3126_r10201_p3870.isZZWW0.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_HIGG2D1.e5916_s3126_r10201_p3870.isZZWW2.root", treeSR, -0.5);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364285.Sherpa_222_NNPDF30NNLO_llvvjj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r10201_p3870.isZZWW0.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364285.Sherpa_222_NNPDF30NNLO_llvvjj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r10201_p3870.isZZWW2.root", treeSR, -0.5);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.345718.Sherpa_222_NNPDF30NNLO_ggllvvWW.deriv.DAOD_HIGG2D1.e6525_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_HIGG2D1.e5916_s3126_r10724_p3870.isZZWW0.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_HIGG2D1.e5916_s3126_r10724_p3870.isZZWW2.root", treeSR, -0.5);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364285.Sherpa_222_NNPDF30NNLO_llvvjj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r10724_p3870.isZZWW0.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364285.Sherpa_222_NNPDF30NNLO_llvvjj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r10724_p3870.isZZWW2.root", treeSR, -0.5);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.345718.Sherpa_222_NNPDF30NNLO_ggllvvWW.deriv.DAOD_HIGG2D1.e6525_s3126_r10724_p3870.root", treeSR);

        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_HIGG2D1.e5916_s3126_r9364_p3652_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364285.Sherpa_222_NNPDF30NNLO_llvvjj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.345718.Sherpa_222_NNPDF30NNLO_ggllvvWW.deriv.DAOD_HIGG2D1.e6525_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_HIGG2D1.e5916_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364285.Sherpa_222_NNPDF30NNLO_llvvjj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.345718.Sherpa_222_NNPDF30NNLO_ggllvvWW.deriv.DAOD_HIGG2D1.e6525_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_HIGG2D1.e5916_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364285.Sherpa_222_NNPDF30NNLO_llvvjj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.345718.Sherpa_222_NNPDF30NNLO_ggllvvWW.deriv.DAOD_HIGG2D1.e6525_s3126_r10724_p3870_CR.root", treeCR);
        job.Close();
    }else{
        emuMC job(folder, "LM-emuMC-rel75-sherpaWW-"+folder+".root","recreate", false, false);

        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_HIGG2D1.e5916_s3126_r9364_p3652.isZZWW0.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_HIGG2D1.e5916_s3126_r9364_p3652.isZZWW2.root", treeSR, -0.5);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364285.Sherpa_222_NNPDF30NNLO_llvvjj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r9364_p3870.isZZWW0.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364285.Sherpa_222_NNPDF30NNLO_llvvjj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r9364_p3870.isZZWW2.root", treeSR, -0.5);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_HIGG2D1.e5916_s3126_r10201_p3870.isZZWW0.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_HIGG2D1.e5916_s3126_r10201_p3870.isZZWW2.root", treeSR, -0.5);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364285.Sherpa_222_NNPDF30NNLO_llvvjj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r10201_p3870.isZZWW0.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364285.Sherpa_222_NNPDF30NNLO_llvvjj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r10201_p3870.isZZWW2.root", treeSR, -0.5);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_HIGG2D1.e5916_s3126_r10724_p3870.isZZWW0.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_HIGG2D1.e5916_s3126_r10724_p3870.isZZWW2.root", treeSR, -0.5);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364285.Sherpa_222_NNPDF30NNLO_llvvjj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r10724_p3870.isZZWW0.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364285.Sherpa_222_NNPDF30NNLO_llvvjj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r10724_p3870.isZZWW2.root", treeSR, -0.5);

        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_HIGG2D1.e5916_s3126_r9364_p3652_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364285.Sherpa_222_NNPDF30NNLO_llvvjj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_HIGG2D1.e5916_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364285.Sherpa_222_NNPDF30NNLO_llvvjj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_HIGG2D1.e5916_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364285.Sherpa_222_NNPDF30NNLO_llvvjj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r10724_p3870_CR.root", treeCR);
        job.Close();
    }
}

void process_ttbar(std::string folder){

    if (folder.find("PFLOW") != std::string::npos){
        emuMC job("PFLOW", "LM-emuMC-rel75-ttbar-"+folder+".root","recreate", true, false, "top");
        std::string subpath = "weightSyst/";

        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r10724_p3870.root", treeSR);

        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r10724_p3870_CR.root", treeCR);
        job.Close();
    }else{
        emuMC job(folder, "LM-emuMC-rel75-ttbar-"+folder+".root","recreate", false, false);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r10724_p3870.root", treeSR);

        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r10724_p3870_CR.root", treeCR);
        job.Close();
    }
}


void process_Wt(std::string folder){

    if (folder.find("PFLOW") != std::string::npos){
        emuMC job("PFLOW", "LM-emuMC-rel75-Wt-"+folder+".root","recreate", true, false, "top");
        std::string subpath = "weightSyst/";
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r10724_p3870.root", treeSR);

        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r10724_p3870_CR.root", treeCR);
        job.Close();
    }else{
        emuMC job(folder, "LM-emuMC-rel75-Wt-"+folder+".root","recreate", false, false);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r10724_p3870_CR.root", treeCR);
        job.Close();
    }
}



void process_top(std::string folder){

    if (folder.find("PFLOW") != std::string::npos){
        emuMC job("PFLOW", "LM-emuMC-rel75-top-"+folder+".root","recreate", true, false, "top");
        std::string subpath = "weightSyst/";

        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r9364_p3870.root", treeSR);

        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r10201_p3870.root", treeSR);

        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r10724_p3870.root", treeSR);

        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r9364_p3870_CR.root", treeCR);

        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r10201_p3870_CR.root", treeCR);

        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r10724_p3870_CR.root", treeCR);
        job.Close();
    }else{
        emuMC job(folder, "LM-emuMC-rel75-top-"+folder+".root","recreate", false, false);

        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r9364_p3870.root", treeSR);

        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r10201_p3870.root", treeSR);

        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r10724_p3870.root", treeSR);

        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r9364_p3870_CR.root", treeCR);

        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r10201_p3870_CR.root", treeCR);

        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r10724_p3870_CR.root", treeCR);
        job.Close();
    }
}


void process_Ztautau(std::string folder){

    if (folder.find("PFLOW") != std::string::npos){
        emuMC job("PFLOW", "LM-emuMC-rel75-Ztautau-"+folder+".root","recreate", true, false, "sherpa");
        std::string subpath = "weightSyst/";
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + subpath + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);

        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + subpath + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);

        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + subpath + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);

        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + subpath + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);

        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + subpath + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);

        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + subpath + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.Close();
    }else{
        emuMC job(folder, "LM-emuMC-rel75-Ztautau-"+folder+".root","recreate", false, false);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16a + folder + "/" + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", treeSR);

        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16d + folder + "/" + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", treeSR);

        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(path_SR_mc16e + folder + "/" + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", treeSR);

        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16a + folder + "/" + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", treeCR);

        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16d + folder + "/" + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", treeCR);

        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.LoopROOT(path_CR_mc16e + folder + "/" + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", treeCR);
        job.Close();
    }
}



int main(int argc, const char *argv[]){
    std::string tree_SYST = "PFLOW";
    if (argc==2) tree_SYST = argv[1];
    process(tree_SYST);
    process_sherpaWW(tree_SYST);
    process_powhegWW(tree_SYST);
    process_Ztautau(tree_SYST);
    process_top(tree_SYST);
    process_ttbar(tree_SYST);
    process_Wt(tree_SYST);
    return 0;
}
