#include "HZZ/emuROOT.h"
#include "HZZ/emuAna.h"
#include <string>
#include <iostream>
#include <TFile.h>
#include <cmath>


void readROOT(std::string filename, std::string tag){
    emuROOT job("PFLOW", filename,"recreate", tag);

    std::string path_SR_mc16a = "/store/bl2/atlas/lijing/minitrees_rel75/mc16a/Nominal/";
    std::string path_SR_mc16d = "/store/bl2/atlas/lijing/minitrees_rel75/mc16d/Nominal/";
    std::string path_SR_mc16e = "/store/bl2/atlas/lijing/minitrees_rel75/mc16e/Nominal/";

    std::string path_CR_mc16a = "/store/bl2/atlas/lijing/minitrees_rel75/mc16a/Systematics_Background/weightSyst/";
    std::string path_CR_mc16d = "/store/bl2/atlas/lijing/minitrees_rel75/mc16d/Systematics_Background/weightSyst/";
    std::string path_CR_mc16e = "/store/bl2/atlas/lijing/minitrees_rel75/mc16e/Systematics_Background/weightSyst/";

    std::string treeSR = "PFLOW";
    std::string treeCR = "emu_PFLOW";
    double factor = 1;

    if (tag.find("ZZ")!=std::string::npos){
        job.LoopROOT(path_SR_mc16a + "", factor, treeSR);
        job.LoopROOT(path_CR_mc16e + "", factor, treeCR);
        //mc16_13TeV.345723.Sherpa_222_NNPDF30NNLO_ggllvvZZ.deriv.DAOD_HIGG2D1.e6213_s3126_r9364_p3872_CR.root
    }
    if (tag.find("ZJets")!=std::string::npos){
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
    }


    if (tag.find("Other")!=std::string::npos){
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364248.Sherpa_222_NNPDF30NNLO_ZZZ_4l2v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.deriv.DAOD_HIGG2D1.e5894_s3126_r9364_p3872_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364283.Sherpa_222_NNPDF30NNLO_lllljj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r9364_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.345706.Sherpa_222_NNPDF30NNLO_ggllll_130M4l.deriv.DAOD_HIGG2D1.e6213_s3126_r9364_p3872_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_HIGG2D1.e4111_s3126_r9364_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.deriv.DAOD_HIGG2D1.e5070_s3126_r9364_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_HIGG2D1.e5070_s3126_r9364_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_HIGG2D1.e5070_s3126_r9364_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410218.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttee.deriv.DAOD_HIGG2D1.e5070_s3126_r9364_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.410219.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttmumu.deriv.DAOD_HIGG2D1.e5070_s3126_r9364_p3870_CR.root", factor, treeCR);

        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364248.Sherpa_222_NNPDF30NNLO_ZZZ_4l2v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.deriv.DAOD_HIGG2D1.e5894_s3126_r10201_p3872_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364283.Sherpa_222_NNPDF30NNLO_lllljj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r10201_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.345706.Sherpa_222_NNPDF30NNLO_ggllll_130M4l.deriv.DAOD_HIGG2D1.e6213_s3126_r10201_p3872_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_HIGG2D1.e4111_s3126_r10201_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.deriv.DAOD_HIGG2D1.e5070_s3126_r10201_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_HIGG2D1.e5070_s3126_r10201_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_HIGG2D1.e5070_s3126_r10201_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410218.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttee.deriv.DAOD_HIGG2D1.e5070_s3126_r10201_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.410219.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttmumu.deriv.DAOD_HIGG2D1.e5070_s3126_r10201_p3870_CR.root", factor, treeCR);

        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364248.Sherpa_222_NNPDF30NNLO_ZZZ_4l2v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.deriv.DAOD_HIGG2D1.e5894_s3126_r10724_p3872_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364283.Sherpa_222_NNPDF30NNLO_lllljj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r10724_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.345706.Sherpa_222_NNPDF30NNLO_ggllll_130M4l.deriv.DAOD_HIGG2D1.e6213_s3126_r10724_p3872_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_HIGG2D1.e4111_s3126_r10724_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.deriv.DAOD_HIGG2D1.e5070_s3126_r10724_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_HIGG2D1.e5070_s3126_r10724_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_HIGG2D1.e5070_s3126_r10724_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410218.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttee.deriv.DAOD_HIGG2D1.e5070_s3126_r10724_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.410219.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttmumu.deriv.DAOD_HIGG2D1.e5070_s3126_r10724_p3870_CR.root", factor, treeCR);
    }

    if (tag.find("WZ")!=std::string::npos){

        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364253.Sherpa_222_NNPDF30NNLO_lllv.deriv.DAOD_HIGG2D1.e5916_s3126_r9364_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16a + "mc16_13TeV.364284.Sherpa_222_NNPDF30NNLO_lllvjj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r9364_p3870_CR.root", factor, treeCR);

        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364253.Sherpa_222_NNPDF30NNLO_lllv.deriv.DAOD_HIGG2D1.e5916_s3126_r10201_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16d + "mc16_13TeV.364284.Sherpa_222_NNPDF30NNLO_lllvjj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r10201_p3870_CR.root", factor, treeCR);

        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364253.Sherpa_222_NNPDF30NNLO_lllv.deriv.DAOD_HIGG2D1.e5916_s3126_r10724_p3870_CR.root", factor, treeCR);
        job.LoopROOT(path_CR_mc16e + "mc16_13TeV.364284.Sherpa_222_NNPDF30NNLO_lllvjj_EW6.deriv.DAOD_HIGG2D1.e6055_s3126_r10724_p3870_CR.root", factor, treeCR);
    }

    job.Close();
}

int main(int argc, const char *argv[]){
    readROOT("emuCR-ZJets.root", "ZJets");
    readROOT("emuCR-Other.root", "Other");
    readROOT("emuCR-WZ.root", "WZ");
    //analysis("NonRes", "emuCR-MC.root");
    return 0;
}
