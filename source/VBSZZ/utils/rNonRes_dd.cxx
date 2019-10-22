#include "VBSZZ/jDataDriven.h"
#include <string>
#include <iostream>
#include <TString.h>

void MC(){
    jDataDriven t("NOMINAL", "NonRes_dd.root", "recreate", false, false, false);
    std::string path = "/lustre/umt3/user/liji/VBSZZ-samples/p3759-2lXR/";

    t.LoopROOT(path + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_STDM3.e6527_s3126_r9364_p3759.root", 2.061459);
    t.LoopROOT(path + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_STDM3.e6527_s3126_r9364_p3759.root", 1.28856558);
    t.LoopROOT(path + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_STDM3.e6671_s3126_r9364_p3759.root", 44.154726);
    t.LoopROOT(path + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_STDM3.e6671_s3126_r9364_p3759.root", 26.2751575);
    t.LoopROOT(path + "mc16_13TeV.410648.PowhegPythia8EvtGen_A14_Wt_DR_dilepton_top.deriv.DAOD_STDM3.e6615_s3126_r9364_p3759.root", 3.7775647);
    t.LoopROOT(path + "mc16_13TeV.410649.PowhegPythia8EvtGen_A14_Wt_DR_dilepton_antitop.deriv.DAOD_STDM3.e6615_s3126_r9364_p3759.root", 3.77743062);
    t.LoopROOT(path + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_STDM3.e6348_s3126_r9364_p3759.root", 87.709092);
    t.LoopROOT(path + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_STDM3.e5916_s3126_r9364_p3759.isZZWW0.root", 12.5);
    t.LoopROOT(path + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_STDM3.e5916_s3126_r9364_p3759.isZZWW-1.root", 12.5);
    t.LoopROOT(path + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_STDM3.e5916_s3126_r9364_p3759.isZZWW1.root", -12.5 * 0.5);
    t.LoopROOT(path + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_STDM3.e5307_s3126_r9364_p3759.root", 1587.413665);
    t.LoopROOT(path + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_STDM3.e5307_s3126_r9364_p3759.root", 211.708887);
    t.LoopROOT(path + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_STDM3.e5307_s3126_r9364_p3759.root", 127.089013);
    t.LoopROOT(path + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_STDM3.e5307_s3126_r9364_p3759.root", 74.707406);
    t.LoopROOT(path + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_STDM3.e5307_s3126_r9364_p3759.root", 20.508136);
    t.LoopROOT(path + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_STDM3.e5307_s3126_r9364_p3759.root", 11.960781);
    t.LoopROOT(path + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_STDM3.e5307_s3126_r9364_p3759.root", 24.576956);
    t.LoopROOT(path + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_STDM3.e5307_s3126_r9364_p3759.root", 9.301822);
    t.LoopROOT(path + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_STDM3.e5307_s3126_r9364_p3759.root", 6.196243);
    t.LoopROOT(path + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_STDM3.e5307_s3126_r9364_p3759.root", 4.759698);
    t.LoopROOT(path + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_STDM3.e5313_s3126_r9364_p3759.root", 2.243734);
    t.LoopROOT(path + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_STDM3.e5313_s3126_r9364_p3759.root", 1.491823);
    t.LoopROOT(path + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_STDM3.e5307_s3126_r9364_p3759.root", 1.763176);
    t.LoopROOT(path + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_STDM3.e5307_s3126_r9364_p3759.root", 0.144568);

    t.LoopROOT(path + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_STDM3.e6527_s3126_r10201_p3759.root", 2.061459);
    t.LoopROOT(path + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_STDM3.e6527_s3126_r10201_p3759.root", 1.28856558);
    t.LoopROOT(path + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_STDM3.e6671_s3126_r10201_p3759.root", 44.154726);
    t.LoopROOT(path + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_STDM3.e6671_s3126_r10201_p3759.root", 26.2751575);
    t.LoopROOT(path + "mc16_13TeV.410648.PowhegPythia8EvtGen_A14_Wt_DR_dilepton_top.deriv.DAOD_STDM3.e6615_s3126_r10201_p3759.root", 3.7775647);
    t.LoopROOT(path + "mc16_13TeV.410649.PowhegPythia8EvtGen_A14_Wt_DR_dilepton_antitop.deriv.DAOD_STDM3.e6615_s3126_r10201_p3759.root", 3.77743062);
    t.LoopROOT(path + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_STDM3.e6348_s3126_r10201_p3759.root", 87.709092);
    t.LoopROOT(path + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_STDM3.e5916_s3126_r10201_p3759.isZZWW0.root", 12.5);
    t.LoopROOT(path + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_STDM3.e5916_s3126_r10201_p3759.isZZWW-1.root", 12.5);
    t.LoopROOT(path + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_STDM3.e5916_s3126_r10201_p3759.isZZWW1.root", -12.5 * 0.5);
    t.LoopROOT(path + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_STDM3.e5307_s3126_r10201_p3759.root", 1587.413665);
    t.LoopROOT(path + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_STDM3.e5307_s3126_r10201_p3759.root", 211.708887);
    t.LoopROOT(path + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_STDM3.e5307_s3126_r10201_p3759.root", 127.089013);
    t.LoopROOT(path + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_STDM3.e5307_s3126_r10201_p3759.root", 74.707406);
    t.LoopROOT(path + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_STDM3.e5307_s3126_r10201_p3759.root", 20.508136);
    t.LoopROOT(path + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_STDM3.e5307_s3126_r10201_p3759.root", 11.960781);
    t.LoopROOT(path + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_STDM3.e5307_s3126_r10201_p3759.root", 24.576956);
    t.LoopROOT(path + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_STDM3.e5307_s3126_r10201_p3759.root", 9.301822);
    t.LoopROOT(path + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_STDM3.e5307_s3126_r10201_p3759.root", 6.196243);
    t.LoopROOT(path + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_STDM3.e5307_s3126_r10201_p3759.root", 4.759698);
    t.LoopROOT(path + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_STDM3.e5313_s3126_r10201_p3759.root", 2.243734);
    t.LoopROOT(path + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_STDM3.e5313_s3126_r10201_p3759.root", 1.491823);
    t.LoopROOT(path + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_STDM3.e5307_s3126_r10201_p3759.root", 1.763176);
    t.LoopROOT(path + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_STDM3.e5307_s3126_r10201_p3759.root", 0.144568);

    t.LoopROOT(path + "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_STDM3.e6527_s3126_r10724_p3759.root", 2.061459);
    t.LoopROOT(path + "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_STDM3.e6527_s3126_r10724_p3759.root", 1.28856558);
    t.LoopROOT(path + "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_STDM3.e6671_s3126_r10724_p3759.root", 44.154726);
    t.LoopROOT(path + "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_STDM3.e6671_s3126_r10724_p3759.root", 26.2751575);
    t.LoopROOT(path + "mc16_13TeV.410648.PowhegPythia8EvtGen_A14_Wt_DR_dilepton_top.deriv.DAOD_STDM3.e6615_s3126_r10724_p3759.root", 3.7775647);
    t.LoopROOT(path + "mc16_13TeV.410649.PowhegPythia8EvtGen_A14_Wt_DR_dilepton_antitop.deriv.DAOD_STDM3.e6615_s3126_r10724_p3759.root", 3.77743062);
    t.LoopROOT(path + "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_STDM3.e6348_s3126_r10724_p3759.root", 87.709092);
    t.LoopROOT(path + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_STDM3.e5916_s3126_r10724_p3759.isZZWW0.root", 12.5);
    t.LoopROOT(path + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_STDM3.e5916_s3126_r10724_p3759.isZZWW-1.root", 12.5);
    t.LoopROOT(path + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_STDM3.e5916_s3126_r10724_p3759.isZZWW1.root", -12.5 * 0.5);
    t.LoopROOT(path + "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_STDM3.e5307_s3126_r10724_p3759.root", 1587.413665);
    t.LoopROOT(path + "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_STDM3.e5307_s3126_r10724_p3759.root", 211.708887);
    t.LoopROOT(path + "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_STDM3.e5307_s3126_r10724_p3759.root", 127.089013);
    t.LoopROOT(path + "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_STDM3.e5307_s3126_r10724_p3759.root", 74.707406);
    t.LoopROOT(path + "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_STDM3.e5307_s3126_r10724_p3759.root", 20.508136);
    t.LoopROOT(path + "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_STDM3.e5307_s3126_r10724_p3759.root", 11.960781);
    t.LoopROOT(path + "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_STDM3.e5307_s3126_r10724_p3759.root", 24.576956);
    t.LoopROOT(path + "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_STDM3.e5307_s3126_r10724_p3759.root", 9.301822);
    t.LoopROOT(path + "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_STDM3.e5307_s3126_r10724_p3759.root", 6.196243);
    t.LoopROOT(path + "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_STDM3.e5307_s3126_r10724_p3759.root", 4.759698);
    t.LoopROOT(path + "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_STDM3.e5313_s3126_r10724_p3759.root", 2.243734);
    t.LoopROOT(path + "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_STDM3.e5313_s3126_r10724_p3759.root", 1.491823);
    t.LoopROOT(path + "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_STDM3.e5307_s3126_r10724_p3759.root", 1.763176);
    t.LoopROOT(path + "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_STDM3.e5307_s3126_r10724_p3759.root", 0.144568);
}


void DATA(){
    jDataDriven t("NOMINAL", "Data_dd.root", "recreate", false, false, true);
    std::string path = "/lustre/umt3/user/liji/VBSZZ-samples/p3759-2lXR/";
    t.LoopROOT(path + "data15_13TeV.periodD.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data15_13TeV.periodE.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data15_13TeV.periodF.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data15_13TeV.periodG.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data15_13TeV.periodH.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data15_13TeV.periodJ.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data16_13TeV.periodA.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data16_13TeV.periodB.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data16_13TeV.periodC.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data16_13TeV.periodD.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data16_13TeV.periodE.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data16_13TeV.periodF.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data16_13TeV.periodG.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data16_13TeV.periodI.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data16_13TeV.periodK.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data16_13TeV.periodL.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data17_13TeV.periodB.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data17_13TeV.periodC.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data17_13TeV.periodD.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data17_13TeV.periodE.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data17_13TeV.periodF.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data17_13TeV.periodH.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data17_13TeV.periodI.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data17_13TeV.periodK.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data18_13TeV.periodB.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data18_13TeV.periodC.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data18_13TeV.periodD.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data18_13TeV.periodF.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data18_13TeV.periodI.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data18_13TeV.periodK.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data18_13TeV.periodL.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data18_13TeV.periodM.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data18_13TeV.periodO.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");
    t.LoopROOT(path + "data18_13TeV.periodQ.physics_Main.PhysCont.DAOD_STDM3.grp23_v01_p3760.root");

    // ggZZ
    t.LoopROOT(path + "mc16_13TeV.343233.Powheggg2vvPythia8EvtGen_ggH125p5_gg_ZZ_2l2v_13TeV.deriv.DAOD_STDM3.e4568_s3126_r9364_p3759.root" , -0.0228992218);
    t.LoopROOT(path + "mc16_13TeV.343233.Powheggg2vvPythia8EvtGen_ggH125p5_gg_ZZ_2l2v_13TeV.deriv.DAOD_STDM3.e4568_s3126_r10201_p3759.root", -0.0228992218);
    t.LoopROOT(path + "mc16_13TeV.343233.Powheggg2vvPythia8EvtGen_ggH125p5_gg_ZZ_2l2v_13TeV.deriv.DAOD_STDM3.e4568_s3126_r10724_p3759.root", -0.0228992218);

    // qqZZ
    t.LoopROOT(path + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_STDM3.e5916_s3126_r9364_p3759.isZZWW1.root" , -12.5 * 1.5);
    t.LoopROOT(path + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_STDM3.e5916_s3126_r10201_p3759.isZZWW1.root", -12.5 * 1.5);
    t.LoopROOT(path + "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_STDM3.e5916_s3126_r10724_p3759.isZZWW1.root", -12.5 * 1.5);

    // WZ
    t.LoopROOT(path + "mc16_13TeV.364253.Sherpa_222_NNPDF30NNLO_lllv.deriv.DAOD_STDM3.e5916_s3126_r9364_p3759.root"        , -4.5768);
    t.LoopROOT(path + "mc16_13TeV.364253.Sherpa_222_NNPDF30NNLO_lllv.deriv.DAOD_STDM3.e5916_s3126_r10201_p3759.root"       , -4.5768);
    t.LoopROOT(path + "mc16_13TeV.364253.Sherpa_222_NNPDF30NNLO_lllv.deriv.DAOD_STDM3.e5916_s3126_r10724_p3759.root"       , -4.5768);
    t.LoopROOT(path + "mc16_13TeV.364284.Sherpa_222_NNPDF30NNLO_lllvjj_EW6.deriv.DAOD_STDM3.e6055_s3126_r9364_p3759.root"  , -0.046921 * 1.77);
    t.LoopROOT(path + "mc16_13TeV.364284.Sherpa_222_NNPDF30NNLO_lllvjj_EW6.deriv.DAOD_STDM3.e6055_s3126_r10201_p3759.root" , -0.046921 * 1.77);
    t.LoopROOT(path + "mc16_13TeV.364284.Sherpa_222_NNPDF30NNLO_lllvjj_EW6.deriv.DAOD_STDM3.e6055_s3126_r10724_p3759.root" , -0.046921 * 1.77);

    // ZJet
    t.LoopROOT(path + "mc16_13TeV.364114.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root"         , -1587.021595);
    t.LoopROOT(path + "mc16_13TeV.364115.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root"       , -220.385164);
    t.LoopROOT(path + "mc16_13TeV.364116.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_BFilter.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root"            , -127.115367);
    t.LoopROOT(path + "mc16_13TeV.364117.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root"       , -74.871644);
    t.LoopROOT(path + "mc16_13TeV.364118.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root"     , -20.173903);
    t.LoopROOT(path + "mc16_13TeV.364119.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_BFilter.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root"          , -12.867332);
    t.LoopROOT(path + "mc16_13TeV.364120.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root"      , -24.453401);
    t.LoopROOT(path + "mc16_13TeV.364121.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root"    , -9.237606);
    t.LoopROOT(path + "mc16_13TeV.364122.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_BFilter.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root"         , -6.081254);
    t.LoopROOT(path + "mc16_13TeV.364123.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root"      , -4.78967);
    t.LoopROOT(path + "mc16_13TeV.364124.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root"    , -2.249987);
    t.LoopROOT(path + "mc16_13TeV.364125.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_BFilter.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root"         , -1.492419);
    t.LoopROOT(path + "mc16_13TeV.364126.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV500_1000.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root"                , -1.764151);
    t.LoopROOT(path + "mc16_13TeV.364127.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV1000_E_CMS.deriv.DAOD_STDM3.e5299_s3126_r9364_p3759.root"              , -0.145046);
    t.LoopROOT(path + "mc16_13TeV.364100.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root"       , -1588.471363);
    t.LoopROOT(path + "mc16_13TeV.364101.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root"     , -219.521258);
    t.LoopROOT(path + "mc16_13TeV.364102.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_BFilter.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root"          , -127.130374);
    t.LoopROOT(path + "mc16_13TeV.364103.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root"     , -73.369403);
    t.LoopROOT(path + "mc16_13TeV.364104.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root"   , -20.807822);
    t.LoopROOT(path + "mc16_13TeV.364105.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_BFilter.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root"        , -12.50543);
    t.LoopROOT(path + "mc16_13TeV.364106.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root"    , -23.437351);
    t.LoopROOT(path + "mc16_13TeV.364107.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root"  , -9.144901);
    t.LoopROOT(path + "mc16_13TeV.364108.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_BFilter.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root"       , -6.07699);
    t.LoopROOT(path + "mc16_13TeV.364109.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root"    , -4.657367);
    t.LoopROOT(path + "mc16_13TeV.364110.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root"  , -2.214828);
    t.LoopROOT(path + "mc16_13TeV.364111.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_BFilter.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root"       , -1.468424);
    t.LoopROOT(path + "mc16_13TeV.364112.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV500_1000.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root"              , -1.742601);
    t.LoopROOT(path + "mc16_13TeV.364113.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV1000_E_CMS.deriv.DAOD_STDM3.e5271_s3126_r9364_p3759.root"            , -0.143925);
    t.LoopROOT(path + "mc16_13TeV.364114.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root"        , -1587.021595);
    t.LoopROOT(path + "mc16_13TeV.364115.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root"      , -220.385164);
    t.LoopROOT(path + "mc16_13TeV.364116.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_BFilter.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root"           , -127.115367);
    t.LoopROOT(path + "mc16_13TeV.364117.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root"      , -74.871644);
    t.LoopROOT(path + "mc16_13TeV.364118.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root"    , -20.173903);
    t.LoopROOT(path + "mc16_13TeV.364119.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_BFilter.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root"         , -12.867332);
    t.LoopROOT(path + "mc16_13TeV.364120.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root"     , -24.453401);
    t.LoopROOT(path + "mc16_13TeV.364121.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root"   , -9.237606);
    t.LoopROOT(path + "mc16_13TeV.364122.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_BFilter.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root"        , -6.081254);
    t.LoopROOT(path + "mc16_13TeV.364123.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root"     , -4.78967);
    t.LoopROOT(path + "mc16_13TeV.364124.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root"   , -2.249987);
    t.LoopROOT(path + "mc16_13TeV.364125.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_BFilter.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root"        , -1.492419);
    t.LoopROOT(path + "mc16_13TeV.364126.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV500_1000.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root"               , -1.764151);
    t.LoopROOT(path + "mc16_13TeV.364127.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV1000_E_CMS.deriv.DAOD_STDM3.e5299_s3126_r10201_p3759.root"             , -0.145046);
    t.LoopROOT(path + "mc16_13TeV.364100.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root"      , -1588.471363);
    t.LoopROOT(path + "mc16_13TeV.364101.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root"    , -219.521258);
    t.LoopROOT(path + "mc16_13TeV.364102.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_BFilter.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root"         , -127.130374);
    t.LoopROOT(path + "mc16_13TeV.364103.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root"    , -73.369403);
    t.LoopROOT(path + "mc16_13TeV.364104.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root"  , -20.807822);
    t.LoopROOT(path + "mc16_13TeV.364105.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_BFilter.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root"       , -12.50543);
    t.LoopROOT(path + "mc16_13TeV.364106.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root"   , -23.437351);
    t.LoopROOT(path + "mc16_13TeV.364107.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root" , -9.144901);
    t.LoopROOT(path + "mc16_13TeV.364108.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_BFilter.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root"      , -6.07699);
    t.LoopROOT(path + "mc16_13TeV.364109.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root"   , -4.657367);
    t.LoopROOT(path + "mc16_13TeV.364110.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root" , -2.214828);
    t.LoopROOT(path + "mc16_13TeV.364111.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_BFilter.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root"      , -1.468424);
    t.LoopROOT(path + "mc16_13TeV.364112.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV500_1000.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root"             , -1.742601);
    t.LoopROOT(path + "mc16_13TeV.364113.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV1000_E_CMS.deriv.DAOD_STDM3.e5271_s3126_r10201_p3759.root"           , -0.143925);
    t.LoopROOT(path + "mc16_13TeV.364114.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root"        , -1587.021595);
    t.LoopROOT(path + "mc16_13TeV.364115.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root"      , -220.385164);
    t.LoopROOT(path + "mc16_13TeV.364116.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_BFilter.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root"           , -127.115367);
    t.LoopROOT(path + "mc16_13TeV.364117.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root"      , -74.871644);
    t.LoopROOT(path + "mc16_13TeV.364118.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root"    , -20.173903);
    t.LoopROOT(path + "mc16_13TeV.364119.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_BFilter.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root"         , -12.867332);
    t.LoopROOT(path + "mc16_13TeV.364120.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root"     , -24.453401);
    t.LoopROOT(path + "mc16_13TeV.364121.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root"   , -9.237606);
    t.LoopROOT(path + "mc16_13TeV.364122.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_BFilter.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root"        , -6.081254);
    t.LoopROOT(path + "mc16_13TeV.364123.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root"     , -4.78967);
    t.LoopROOT(path + "mc16_13TeV.364124.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root"   , -2.249987);
    t.LoopROOT(path + "mc16_13TeV.364125.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_BFilter.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root"        , -1.492419);
    t.LoopROOT(path + "mc16_13TeV.364126.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV500_1000.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root"               , -1.764151);
    t.LoopROOT(path + "mc16_13TeV.364127.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV1000_E_CMS.deriv.DAOD_STDM3.e5299_s3126_r10724_p3759.root"             , -0.145046);
    t.LoopROOT(path + "mc16_13TeV.364100.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root"      , -1588.471363);
    t.LoopROOT(path + "mc16_13TeV.364101.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root"    , -219.521258);
    t.LoopROOT(path + "mc16_13TeV.364102.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_BFilter.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root"         , -127.130374);
    t.LoopROOT(path + "mc16_13TeV.364103.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root"    , -73.369403);
    t.LoopROOT(path + "mc16_13TeV.364104.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root"  , -20.807822);
    t.LoopROOT(path + "mc16_13TeV.364105.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_BFilter.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root"       , -12.50543);
    t.LoopROOT(path + "mc16_13TeV.364106.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root"   , -23.437351);
    t.LoopROOT(path + "mc16_13TeV.364107.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root" , -9.144901);
    t.LoopROOT(path + "mc16_13TeV.364108.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_BFilter.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root"      , -6.07699);
    t.LoopROOT(path + "mc16_13TeV.364109.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root"   , -4.657367);
    t.LoopROOT(path + "mc16_13TeV.364110.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root" , -2.214828);
    t.LoopROOT(path + "mc16_13TeV.364111.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_BFilter.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root"      , -1.468424);
    t.LoopROOT(path + "mc16_13TeV.364112.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV500_1000.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root"             , -1.742601);
    t.LoopROOT(path + "mc16_13TeV.364113.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV1000_E_CMS.deriv.DAOD_STDM3.e5271_s3126_r10724_p3759.root"           , -0.143925);

    // ZZ4l
    t.LoopROOT(path + "mc16_13TeV.345706.Sherpa_222_NNPDF30NNLO_ggllll_130M4l.deriv.DAOD_STDM3.e6213_s3126_r9364_p3759.root",  -0.01009);
    t.LoopROOT(path + "mc16_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.deriv.DAOD_STDM3.e5894_s3126_r9364_p3759.root",           -1.2519);
    t.LoopROOT(path + "mc16_13TeV.364283.Sherpa_222_NNPDF30NNLO_lllljj_EW6.deriv.DAOD_STDM3.e6055_s3126_r9364_p3759.root",     -0.010545);
    t.LoopROOT(path + "mc16_13TeV.345706.Sherpa_222_NNPDF30NNLO_ggllll_130M4l.deriv.DAOD_STDM3.e6213_s3126_r10201_p3759.root", -0.01009);
    t.LoopROOT(path + "mc16_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.deriv.DAOD_STDM3.e5894_s3126_r10201_p3759.root",          -1.2519);
    t.LoopROOT(path + "mc16_13TeV.364283.Sherpa_222_NNPDF30NNLO_lllljj_EW6.deriv.DAOD_STDM3.e6055_s3126_r10201_p3759.root",    -0.010545);
    t.LoopROOT(path + "mc16_13TeV.345706.Sherpa_222_NNPDF30NNLO_ggllll_130M4l.deriv.DAOD_STDM3.e6213_s3126_r10724_p3759.root", -0.01009);
    t.LoopROOT(path + "mc16_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.deriv.DAOD_STDM3.e5894_s3126_r10724_p3759.root",          -1.2519);
    t.LoopROOT(path + "mc16_13TeV.364283.Sherpa_222_NNPDF30NNLO_lllljj_EW6.deriv.DAOD_STDM3.e6055_s3126_r10724_p3759.root",    -0.010545);

    // Other
    t.LoopROOT(path + "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root",              -0.007198);
    t.LoopROOT(path + "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root",              -0.001797);
    t.LoopROOT(path + "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root",              -0.003547);
    t.LoopROOT(path + "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root",              -0.000188);
    t.LoopROOT(path + "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root",              -0.000744);
    t.LoopROOT(path + "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root",              -0.000015);
    t.LoopROOT(path + "mc16_13TeV.364248.Sherpa_222_NNPDF30NNLO_ZZZ_4l2v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root",              -0.000087);
    t.LoopROOT(path + "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root",              -0.000171);
    t.LoopROOT(path + "mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_STDM3.e4111_s3126_r9364_p3759.root",         -0.009904);
    t.LoopROOT(path + "mc16_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.deriv.DAOD_STDM3.e5070_s3126_r9364_p3759.root",      -0.601024);
    t.LoopROOT(path + "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_STDM3.e5070_s3126_r9364_p3759.root",  -0.171939);
    t.LoopROOT(path + "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_STDM3.e5070_s3126_r9364_p3759.root",    -0.58618);
    t.LoopROOT(path + "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root",             -0.007198);
    t.LoopROOT(path + "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root",             -0.001797);
    t.LoopROOT(path + "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root",             -0.003547);
    t.LoopROOT(path + "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root",             -0.000188);
    t.LoopROOT(path + "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root",             -0.000744);
    t.LoopROOT(path + "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root",             -0.000015);
    t.LoopROOT(path + "mc16_13TeV.364248.Sherpa_222_NNPDF30NNLO_ZZZ_4l2v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root",             -0.000087);
    t.LoopROOT(path + "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root",             -0.000171);
    t.LoopROOT(path + "mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_STDM3.e4111_s3126_r10201_p3759.root",        -0.009904);
    t.LoopROOT(path + "mc16_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.deriv.DAOD_STDM3.e5070_s3126_r10201_p3759.root",     -0.601024);
    t.LoopROOT(path + "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_STDM3.e5070_s3126_r10201_p3759.root", -0.171939);
    t.LoopROOT(path + "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_STDM3.e5070_s3126_r10201_p3759.root",   -0.58618);
    t.LoopROOT(path + "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root",             -0.007198);
    t.LoopROOT(path + "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root",             -0.001797);
    t.LoopROOT(path + "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root",             -0.003547);
    t.LoopROOT(path + "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root",             -0.000188);
    t.LoopROOT(path + "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root",             -0.000744);
    t.LoopROOT(path + "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root",             -0.000015);
    t.LoopROOT(path + "mc16_13TeV.364248.Sherpa_222_NNPDF30NNLO_ZZZ_4l2v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root",             -0.000087);
    t.LoopROOT(path + "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root",             -0.000171);
    t.LoopROOT(path + "mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_STDM3.e4111_s3126_r10724_p3759.root",        -0.009904);
    t.LoopROOT(path + "mc16_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.deriv.DAOD_STDM3.e5070_s3126_r10724_p3759.root",     -0.601024);
    t.LoopROOT(path + "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_STDM3.e5070_s3126_r10724_p3759.root", -0.171939);
    t.LoopROOT(path + "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_STDM3.e5070_s3126_r10724_p3759.root",   -0.58618);

}

int main(int argc, const char *argv[]){
    MC();
    DATA();
    return 0;
}
