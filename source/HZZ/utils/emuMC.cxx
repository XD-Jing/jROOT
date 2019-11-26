#include "HZZ/emuROOT.h"
#include "HZZ/emuAna.h"
#include <string>
#include <iostream>
#include <TFile.h>
#include <cmath>


void readROOT(){
    emuROOT job("PFLOW", "emuCR-MC.root","recreate", "NonRes");

    std::string path_SR_mc16a = "/store/bl2/atlas/lijing/minitrees_rel75/mc16a/Nominal/";
    std::string path_SR_mc16d = "/store/bl2/atlas/lijing/minitrees_rel75/mc16d/Nominal/";
    std::string path_SR_mc16e = "/store/bl2/atlas/lijing/minitrees_rel75/mc16e/Nominal/";

    std::string path_CR_mc16a = "/store/bl2/atlas/lijing/minitrees_rel75/mc16a/Systematics_Background/weightSyst/";
    std::string path_CR_mc16d = "/store/bl2/atlas/lijing/minitrees_rel75/mc16d/Systematics_Background/weightSyst/";
    std::string path_CR_mc16e = "/store/bl2/atlas/lijing/minitrees_rel75/mc16e/Systematics_Background/weightSyst/";

    std::string treeSR = "PFLOW";
    std::string treeCR = "emu_PFLOW";
    double factor = 1;

    job.LoopROOT(path_SR_mc16a + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r9364_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16a + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r9364_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16a + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r9364_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16a + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r9364_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16a + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r9364_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16a + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r9364_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16a + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r9364_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16a + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r9364_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16a + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16a + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16a + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16a + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16a + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16a + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16a + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16a + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16a + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16a + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16a + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r9364_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16a + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r9364_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16a + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16a + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870.root", factor, treeSR);
        
    job.LoopROOT(path_SR_mc16d + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r10201_p3652.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16d + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r10201_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16d + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r10201_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16d + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r10201_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16d + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r10201_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16d + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r10201_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16d + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r10201_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16d + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r10201_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16d + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16d + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16d + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16d + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16d + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16d + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16d + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16d + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16d + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16d + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16d + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r10201_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16d + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r10201_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16d + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16d + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870.root", factor, treeSR);

    job.LoopROOT(path_SR_mc16e + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r10724_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16e + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r10724_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16e + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r10724_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16e + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r10724_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16e + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r10724_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16e + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r10724_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16e + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r10724_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16e + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r10724_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16e + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16e + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16e + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16e + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16e + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16e + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16e + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16e + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16e + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16e + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16e + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r10724_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16e + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r10724_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16e + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", factor, treeSR);
    job.LoopROOT(path_SR_mc16e + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870.root", factor, treeSR);

    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r9364_p3870_CR.root", factor, treeCR);
        
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r10201_p3652_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r10201_p3870_CR.root", factor, treeCR);

    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.361600.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WWlvlv.deriv.DAOD_HIGG2D1.e4616_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG2D1.e6348_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG2D1.e6527_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG2D1.e6527_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG2D1.e6552_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG2D1.e6552_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG2D1.e6671_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG2D1.e6671_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG2D1.e5313_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG2D1.e5313_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG2D1.e5307_s3126_r10724_p3870_CR.root", factor, treeCR);
    job.Close();
}

int main(int argc, const char *argv[]){
    //readROOT();
    analysis("NonRes", "emuCR-MC.root");
    return 0;
}

