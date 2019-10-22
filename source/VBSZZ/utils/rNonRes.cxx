#include "VBSZZ/jTREE.h"
#include <string>
#include <iostream>
#include <TString.h>

void read_Tree(std::string treename){
    jTREE t(treename, "NonRes.root");
    std::string path = "/lustre/umt3/user/liji/VBSZZ-samples/p3759-2Jets/";

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



int main(int argc, const char *argv[]){
    read_Tree("NOMINAL");
    return 0;
}
