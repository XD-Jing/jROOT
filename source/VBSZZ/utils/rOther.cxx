#include "VBSZZ/jSYST.h"
#include "VBSZZ/jTHEO.h"
#include "VBSZZ/jTREE.h"
#include <string>
#include <iostream>
#include <TString.h>

void read_TREE(std::string treename, std::string outopt = "update", bool THEO = false, bool SYST = false){
    jTREE t(treename, "Other_" + treename + ".root", outopt, THEO, SYST);
    std::string path = "/lustre/umt3/user/liji/VBSZZ-samples/p3759-2Jets/";
    t.LoopROOT(path + "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root", 0.007198);
    t.LoopROOT(path + "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root", 0.001797);
    t.LoopROOT(path + "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root", 0.003547);
    t.LoopROOT(path + "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root", 0.000188);
    t.LoopROOT(path + "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root", 0.000744);
    t.LoopROOT(path + "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root", 0.000015);
    t.LoopROOT(path + "mc16_13TeV.364248.Sherpa_222_NNPDF30NNLO_ZZZ_4l2v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root", 0.000087);
    t.LoopROOT(path + "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root", 0.000171);
    t.LoopROOT(path + "mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_STDM3.e4111_s3126_r9364_p3759.root", 0.009904);
    t.LoopROOT(path + "mc16_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.deriv.DAOD_STDM3.e5070_s3126_r9364_p3759.root", 0.601024);
    t.LoopROOT(path + "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_STDM3.e5070_s3126_r9364_p3759.root", 0.171939);
    t.LoopROOT(path + "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_STDM3.e5070_s3126_r9364_p3759.root", 0.58618);

    t.LoopROOT(path + "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root", 0.007198);
    t.LoopROOT(path + "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root", 0.001797);
    t.LoopROOT(path + "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root", 0.003547);
    t.LoopROOT(path + "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root", 0.000188);
    t.LoopROOT(path + "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root", 0.000744);
    t.LoopROOT(path + "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root", 0.000015);
    t.LoopROOT(path + "mc16_13TeV.364248.Sherpa_222_NNPDF30NNLO_ZZZ_4l2v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root", 0.000087);
    t.LoopROOT(path + "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root", 0.000171);
    t.LoopROOT(path + "mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_STDM3.e4111_s3126_r10201_p3759.root", 0.009904);
    t.LoopROOT(path + "mc16_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.deriv.DAOD_STDM3.e5070_s3126_r10201_p3759.root", 0.601024);
    t.LoopROOT(path + "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_STDM3.e5070_s3126_r10201_p3759.root", 0.171939);
    t.LoopROOT(path + "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_STDM3.e5070_s3126_r10201_p3759.root", 0.58618);

    t.LoopROOT(path + "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root", 0.007198);
    t.LoopROOT(path + "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root", 0.001797);
    t.LoopROOT(path + "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root", 0.003547);
    t.LoopROOT(path + "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root", 0.000188);
    t.LoopROOT(path + "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root", 0.000744);
    t.LoopROOT(path + "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root", 0.000015);
    t.LoopROOT(path + "mc16_13TeV.364248.Sherpa_222_NNPDF30NNLO_ZZZ_4l2v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root", 0.000087);
    t.LoopROOT(path + "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root", 0.000171);
    t.LoopROOT(path + "mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_STDM3.e4111_s3126_r10724_p3759.root", 0.009904);
    t.LoopROOT(path + "mc16_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.deriv.DAOD_STDM3.e5070_s3126_r10724_p3759.root", 0.601024);
    t.LoopROOT(path + "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_STDM3.e5070_s3126_r10724_p3759.root", 0.171939);
    t.LoopROOT(path + "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_STDM3.e5070_s3126_r10724_p3759.root", 0.58618);


}

void read_SYST(std::string treename){
    jSYST t(treename, "Other_SYST.root");
    std::string path = "/lustre/umt3/user/liji/VBSZZ-samples/p3759-2Jets/";
    t.LoopROOT(path + "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root", 0.007198);
    t.LoopROOT(path + "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root", 0.001797);
    t.LoopROOT(path + "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root", 0.003547);
    t.LoopROOT(path + "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root", 0.000188);
    t.LoopROOT(path + "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root", 0.000744);
    t.LoopROOT(path + "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root", 0.000015);
    t.LoopROOT(path + "mc16_13TeV.364248.Sherpa_222_NNPDF30NNLO_ZZZ_4l2v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root", 0.000087);
    t.LoopROOT(path + "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_STDM3.e5887_s3126_r9364_p3759.root", 0.000171);
    t.LoopROOT(path + "mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_STDM3.e4111_s3126_r9364_p3759.root", 0.009904);
    t.LoopROOT(path + "mc16_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.deriv.DAOD_STDM3.e5070_s3126_r9364_p3759.root", 0.601024);
    t.LoopROOT(path + "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_STDM3.e5070_s3126_r9364_p3759.root", 0.171939);
    t.LoopROOT(path + "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_STDM3.e5070_s3126_r9364_p3759.root", 0.58618);

    t.LoopROOT(path + "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root", 0.007198);
    t.LoopROOT(path + "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root", 0.001797);
    t.LoopROOT(path + "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root", 0.003547);
    t.LoopROOT(path + "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root", 0.000188);
    t.LoopROOT(path + "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root", 0.000744);
    t.LoopROOT(path + "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root", 0.000015);
    t.LoopROOT(path + "mc16_13TeV.364248.Sherpa_222_NNPDF30NNLO_ZZZ_4l2v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root", 0.000087);
    t.LoopROOT(path + "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10201_p3759.root", 0.000171);
    t.LoopROOT(path + "mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_STDM3.e4111_s3126_r10201_p3759.root", 0.009904);
    t.LoopROOT(path + "mc16_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.deriv.DAOD_STDM3.e5070_s3126_r10201_p3759.root", 0.601024);
    t.LoopROOT(path + "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_STDM3.e5070_s3126_r10201_p3759.root", 0.171939);
    t.LoopROOT(path + "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_STDM3.e5070_s3126_r10201_p3759.root", 0.58618);

    t.LoopROOT(path + "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root", 0.007198);
    t.LoopROOT(path + "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root", 0.001797);
    t.LoopROOT(path + "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root", 0.003547);
    t.LoopROOT(path + "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root", 0.000188);
    t.LoopROOT(path + "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root", 0.000744);
    t.LoopROOT(path + "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root", 0.000015);
    t.LoopROOT(path + "mc16_13TeV.364248.Sherpa_222_NNPDF30NNLO_ZZZ_4l2v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root", 0.000087);
    t.LoopROOT(path + "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_STDM3.e5887_s3126_r10724_p3759.root", 0.000171);
    t.LoopROOT(path + "mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_STDM3.e4111_s3126_r10724_p3759.root", 0.009904);
    t.LoopROOT(path + "mc16_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.deriv.DAOD_STDM3.e5070_s3126_r10724_p3759.root", 0.601024);
    t.LoopROOT(path + "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_STDM3.e5070_s3126_r10724_p3759.root", 0.171939);
    t.LoopROOT(path + "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_STDM3.e5070_s3126_r10724_p3759.root", 0.58618);
}



int main(int argc, const char *argv[]){
    if (argc==1){
        read_SYST("NOMINAL");
    }
    else{
        read_TREE(argv[1], "recreate");
    }
    //read_TREE("NOMINAL", "recreate");
    //read_TREE("EG_RESOLUTION_ALL__1down");
    //read_TREE("EG_RESOLUTION_ALL__1up");
    //read_TREE("EG_SCALE_AF2__1down");
    //read_TREE("EG_SCALE_AF2__1up");
    //read_TREE("EG_SCALE_ALL__1down");
    //read_TREE("EG_SCALE_ALL__1up");
    //read_TREE("JET_EtaIntercalibration_NonClosure__1up");
    //read_TREE("JET_EtaIntercalibration_NonClosure__1down");
    //read_TREE("JET_GroupedNP_1__1up");
    //read_TREE("JET_GroupedNP_1__1down");
    //read_TREE("JET_GroupedNP_2__1up");
    //read_TREE("JET_GroupedNP_2__1down");
    //read_TREE("JET_GroupedNP_3__1up");
    //read_TREE("JET_GroupedNP_3__1down");
    //read_TREE("JET_JER_SINGLE_NP__1up");
    //read_TREE("MET_SoftTrk_ResoPara");
    //read_TREE("MET_SoftTrk_ResoPerp");
    //read_TREE("MET_SoftTrk_ScaleDown");
    //read_TREE("MET_SoftTrk_ScaleUp");
    //read_TREE("MUON_ID__1down");
    //read_TREE("MUON_ID__1up");
    //read_TREE("MUON_MS__1down");
    //read_TREE("MUON_MS__1up");
    //read_TREE("MUON_SAGITTA_RESBIAS__1down");
    //read_TREE("MUON_SAGITTA_RESBIAS__1up");
    //read_TREE("MUON_SAGITTA_RHO__1down");
    //read_TREE("MUON_SAGITTA_RHO__1up");
    //read_TREE("MUON_SCALE__1down");
    //read_TREE("MUON_SCALE__1up");
    //read_TREE("PRW_DATASF__1down");
    //read_TREE("PRW_DATASF__1up");

    return 0;
}
