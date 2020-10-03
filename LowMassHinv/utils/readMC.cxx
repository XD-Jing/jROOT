#include "LowMassHinv/readMC.h" 
#include <string>
#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <cmath>

#define path_SR_data15 "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/data15/Nominal/"
#define path_SR_data16 "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/data16/Nominal/"
#define path_SR_data17 "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/data17/Nominal/"
#define path_SR_data18 "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/data18/Nominal/"
#define path_CR_data15 "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/data15/Background/"
#define path_CR_data16 "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/data16/Background/"
#define path_CR_data17 "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/data17/Background/"
#define path_CR_data18 "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/data18/Background/"
#define path_SR_mc16a "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/mc16a/Systematics/"
#define path_SR_mc16d "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/mc16d/Systematics/"
#define path_SR_mc16e "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/mc16e/Systematics/"
#define path_CR_mc16a "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/mc16a/Systematics_Background/"
#define path_CR_mc16d "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/mc16d/Systematics_Background/"
#define path_CR_mc16e "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/mc16e/Systematics_Background/"
#define treeSR "tree_PFLOW"
#define treeCR "tree_emu_PFLOW"
#define factor 1

void processVVV(std::string folder){
    if (folder.find("PFLOW") != std::string::npos){
        readMC job("PFLOW", "VVV-readMC-rel75-"+folder+".root","recreate", true, true);
        std::string subpath = "weightSyst/";

        job.LoopROOT(std::string(path_SR_mc16a) + subpath + "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16a) + subpath + "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16a) + subpath + "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16a) + subpath + "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16a) + subpath + "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16a) + subpath + "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16a) + subpath + "mc16_13TeV.364248.Sherpa_222_NNPDF30NNLO_ZZZ_4l2v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16a) + subpath + "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870.root", treeSR);

        job.LoopROOT(std::string(path_SR_mc16d) + subpath + "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16d) + subpath + "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16d) + subpath + "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16d) + subpath + "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16d) + subpath + "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16d) + subpath + "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16d) + subpath + "mc16_13TeV.364248.Sherpa_222_NNPDF30NNLO_ZZZ_4l2v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16d) + subpath + "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870.root", treeSR);

        job.LoopROOT(std::string(path_SR_mc16e) + subpath + "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16e) + subpath + "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16e) + subpath + "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16e) + subpath + "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16e) + subpath + "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16e) + subpath + "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16e) + subpath + "mc16_13TeV.364248.Sherpa_222_NNPDF30NNLO_ZZZ_4l2v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16e) + subpath + "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870.root", treeSR);

        job.Close();
    }else{
        readMC job(folder, "VVV-readMC-rel75-"+folder+".root","recreate", false, false);

        job.LoopROOT(std::string(path_SR_mc16a) + folder + "/" + "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16a) + folder + "/" + "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16a) + folder + "/" + "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16a) + folder + "/" + "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16a) + folder + "/" + "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16a) + folder + "/" + "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16a) + folder + "/" + "mc16_13TeV.364248.Sherpa_222_NNPDF30NNLO_ZZZ_4l2v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16a) + folder + "/" + "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r9364_p3870.root", treeSR);

        job.LoopROOT(std::string(path_SR_mc16d) + folder + "/" + "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16d) + folder + "/" + "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16d) + folder + "/" + "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16d) + folder + "/" + "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16d) + folder + "/" + "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16d) + folder + "/" + "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16d) + folder + "/" + "mc16_13TeV.364248.Sherpa_222_NNPDF30NNLO_ZZZ_4l2v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16d) + folder + "/" + "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10201_p3870.root", treeSR);

        job.LoopROOT(std::string(path_SR_mc16e) + folder + "/" + "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16e) + folder + "/" + "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16e) + folder + "/" + "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16e) + folder + "/" + "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16e) + folder + "/" + "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16e) + folder + "/" + "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16e) + folder + "/" + "mc16_13TeV.364248.Sherpa_222_NNPDF30NNLO_ZZZ_4l2v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16e) + folder + "/" + "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_HIGG2D1.e5887_s3126_r10724_p3870.root", treeSR);

        job.Close();
    }
}

void processttV(std::string folder){
    if (folder.find("PFLOW") != std::string::npos){
        readMC job("PFLOW", "ttV-readMC-rel75-"+folder+".root","recreate", false, true);
        std::string subpath = "weightSyst/";

        job.LoopROOT(std::string(path_SR_mc16a) + subpath + "mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_HIGG2D1.e4111_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16a) + subpath + "mc16_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.deriv.DAOD_HIGG2D1.e5070_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16a) + subpath + "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_HIGG2D1.e5070_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16a) + subpath + "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_HIGG2D1.e5070_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16a) + subpath + "mc16_13TeV.410218.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttee.deriv.DAOD_HIGG2D1.e5070_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16a) + subpath + "mc16_13TeV.410219.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttmumu.deriv.DAOD_HIGG2D1.e5070_s3126_r9364_p3870.root", treeSR);

        job.LoopROOT(std::string(path_SR_mc16d) + subpath + "mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_HIGG2D1.e4111_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16d) + subpath + "mc16_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.deriv.DAOD_HIGG2D1.e5070_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16d) + subpath + "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_HIGG2D1.e5070_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16d) + subpath + "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_HIGG2D1.e5070_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16d) + subpath + "mc16_13TeV.410218.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttee.deriv.DAOD_HIGG2D1.e5070_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16d) + subpath + "mc16_13TeV.410219.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttmumu.deriv.DAOD_HIGG2D1.e5070_s3126_r10201_p3870.root", treeSR);
            
        job.LoopROOT(std::string(path_SR_mc16e) + subpath + "mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_HIGG2D1.e4111_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16e) + subpath + "mc16_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.deriv.DAOD_HIGG2D1.e5070_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16e) + subpath + "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_HIGG2D1.e5070_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16e) + subpath + "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_HIGG2D1.e5070_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16e) + subpath + "mc16_13TeV.410218.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttee.deriv.DAOD_HIGG2D1.e5070_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16e) + subpath + "mc16_13TeV.410219.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttmumu.deriv.DAOD_HIGG2D1.e5070_s3126_r10724_p3870.root", treeSR);

        job.Close();
    }else{
        readMC job(folder, "ttV-readMC-rel75-"+folder+".root", "recreate", false, false);

        job.LoopROOT(std::string(path_SR_mc16a) + folder + "/" + "mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_HIGG2D1.e4111_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16a) + folder + "/" + "mc16_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.deriv.DAOD_HIGG2D1.e5070_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16a) + folder + "/" + "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_HIGG2D1.e5070_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16a) + folder + "/" + "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_HIGG2D1.e5070_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16a) + folder + "/" + "mc16_13TeV.410218.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttee.deriv.DAOD_HIGG2D1.e5070_s3126_r9364_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16a) + folder + "/" + "mc16_13TeV.410219.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttmumu.deriv.DAOD_HIGG2D1.e5070_s3126_r9364_p3870.root", treeSR);

        job.LoopROOT(std::string(path_SR_mc16d) + folder + "/" + "mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_HIGG2D1.e4111_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16d) + folder + "/" + "mc16_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.deriv.DAOD_HIGG2D1.e5070_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16d) + folder + "/" + "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_HIGG2D1.e5070_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16d) + folder + "/" + "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_HIGG2D1.e5070_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16d) + folder + "/" + "mc16_13TeV.410218.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttee.deriv.DAOD_HIGG2D1.e5070_s3126_r10201_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16d) + folder + "/" + "mc16_13TeV.410219.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttmumu.deriv.DAOD_HIGG2D1.e5070_s3126_r10201_p3870.root", treeSR);
            
        job.LoopROOT(std::string(path_SR_mc16e) + folder + "/" + "mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_HIGG2D1.e4111_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16e) + folder + "/" + "mc16_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.deriv.DAOD_HIGG2D1.e5070_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16e) + folder + "/" + "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_HIGG2D1.e5070_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16e) + folder + "/" + "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_HIGG2D1.e5070_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16e) + folder + "/" + "mc16_13TeV.410218.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttee.deriv.DAOD_HIGG2D1.e5070_s3126_r10724_p3870.root", treeSR);
        job.LoopROOT(std::string(path_SR_mc16e) + folder + "/" + "mc16_13TeV.410219.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttmumu.deriv.DAOD_HIGG2D1.e5070_s3126_r10724_p3870.root", treeSR);

        job.Close();
    }
}
int main(int argc, const char *argv[]){
    std::string tree_SYST = "PFLOW";
    if (argc==2) tree_SYST = argv[1];
    processVVV(tree_SYST);
    //processttV(tree_SYST);
    return 0;
}
