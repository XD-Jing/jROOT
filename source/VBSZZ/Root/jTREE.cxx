#define VBSZZ_jTREE_cxx
#include "VBSZZ/jTREE.h"
#include "VBSZZ/regions.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>


jTREE::jTREE(std::string treename, std::string outfile, std::string outopt, bool THEO, bool SYST, std::string Wname)
: tree(0), treename(treename), SYST(SYST), THEO(THEO), Wname(Wname)
{
    std::cout << treename << std::endl;

    inVarF = {
        "weight"               , "M2Lep"               , "leading_pT_lepton" , "subleading_pT_lepton" ,
        "lepplus_pt"           , "lepminus_pt"         , "lepplus_eta"       , "lepminus_eta"         ,
        "lepplus_phi"          , "lepminus_phi"        , "lep3rd_pt"         , "lep3rd_eta"           ,
        "leading_jet_pt"       , "second_jet_pt"       , "leading_jet_eta"   , "second_jet_eta"       ,
        "leading_jet_rapidity" , "second_jet_rapidity" , "dLepR"             , "sumpT_scalar"         ,
        "met_tst"              , "met_signi"           , "mjj"               , "mtw"                  ,
        "weight_pileup"        , "weight_exp"          , "weight_trig"       , "weight_jets"          ,
        "weight_jvt"
    };
    inVarI = {
        "event_type"           , "event_3CR"           , "n_jets"            , "n_bjets"              ,
        "medium_3rd"
    };
    onVarF = {
        "PtL1"                 , "PtL2"                , "EtaL1"             , "EtaL2"                ,
        "PhiL1"                , "PhiL2"               ,
        "PtJ1"                 , "PtJ2"                , "EtaJ1"             , "EtaJ2"                ,
        "PhiJ1"                , "PhiJ2"               , "YJ1"               , "YJ2"                  ,
        "M2L"                  , "MET"                 , "METSIG"            ,
        "MJJ"                  , "MTW"                 , "NJET"              , "HT"                   ,
        "jYxY"                 , "dLepEta"             , "dLepPhi"           , "BDT"
    };

    if (SYST){
        inVarSYST = {
            "EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR__1down",
            "EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR__1up",
            "EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR__1down",
            "EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR__1up",
            "EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR__1down",
            "EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR__1up",
            "EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down",
            "EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up",
            "FT_EFF_B_systematics__1down",
            "FT_EFF_B_systematics__1up",
            "FT_EFF_C_systematics__1down",
            "FT_EFF_C_systematics__1up",
            "FT_EFF_Light_systematics__1down",
            "FT_EFF_Light_systematics__1up",
            "FT_EFF_extrapolation__1down",
            "FT_EFF_extrapolation__1up",
            "FT_EFF_extrapolation_from_charm__1down",
            "FT_EFF_extrapolation_from_charm__1up",
            "JET_JvtEfficiency__1down",
            "JET_JvtEfficiency__1up",
            //"JET_fJvtEfficiency__1down",
            //"JET_fJvtEfficiency__1up",
            "MUON_EFF_ISO_STAT__1down",
            "MUON_EFF_ISO_STAT__1up",
            "MUON_EFF_ISO_SYS__1down",
            "MUON_EFF_ISO_SYS__1up",
            "MUON_EFF_RECO_STAT_LOWPT__1down",
            "MUON_EFF_RECO_STAT_LOWPT__1up",
            "MUON_EFF_RECO_STAT__1down",
            "MUON_EFF_RECO_STAT__1up",
            "MUON_EFF_RECO_SYS_LOWPT__1down",
            "MUON_EFF_RECO_SYS_LOWPT__1up",
            "MUON_EFF_RECO_SYS__1down",
            "MUON_EFF_RECO_SYS__1up",
            "MUON_EFF_TTVA_STAT__1down",
            "MUON_EFF_TTVA_STAT__1up",
            "MUON_EFF_TTVA_SYS__1down",
            "MUON_EFF_TTVA_SYS__1up",
            "MUON_EFF_TrigStatUncertainty__1down",
            "MUON_EFF_TrigStatUncertainty__1up",
            "MUON_EFF_TrigSystUncertainty__1down",
            "MUON_EFF_TrigSystUncertainty__1up",
        };
    }

    if (THEO){
        inVarV= { "vw" };
        if (outfile.find("EWK") != std::string::npos){
            inVarTHEO["QCD55"] = 0;
            inVarTHEO["QCD15"] = 22;
            inVarTHEO["QCD51"] = 44;
            inVarTHEO["QCD12"] = 88;
            inVarTHEO["QCD21"] = 66;
            inVarTHEO["QCD22"] = 99;
            int c = 0;
            for (int i =1; i<111; i++){
                if (i%11!=0){
                    inVarTHEO["PDF"+std::to_string(c)] = i;
                    c++;
                }
            }
        } else{ // Sherpa
            inVarTHEO["QCD55"] = 4;
            inVarTHEO["QCD15"] = 6;
            inVarTHEO["QCD51"] = 5;
            inVarTHEO["QCD12"] = 8;
            inVarTHEO["QCD21"] = 9;
            inVarTHEO["QCD22"] = 10;
            for (int i =11; i<111; i++) inVarTHEO["PDF"+std::to_string(i-11)] = i;
        }
    }

    for (auto v: onVarF)    fEvt[v] = -999999;
    for (auto v: inVarV)    { BrEvt[v] = new TBranch(); vEvt[v] = new std::vector<float>(); }
    for (auto v: inVarF)    { BrEvt[v] = new TBranch(); fEvt[v] = -999999; }
    for (auto v: inVarI)    { BrEvt[v] = new TBranch(); iEvt[v] = -999999; }
    for (auto v: inVarSYST) { BrEvt[v] = new TBranch(); fEvt[v] = -999999; }

    mkHist("M2L"     , 40 , 80   ,  100);
    mkHist("MTW"     , 40 , 0    ,  400);
    mkHist("MET"     ,100 , 0    , 1000);
    mkHist("METSIG"  , 50 , 0    ,   25);
    mkHist("MJJ"     ,300 , 0    , 3000);
    mkHist("dYJJ"    , 50 , 0    ,   10);
    mkHist("jYxY"    , 40 , -10  ,   10);
    mkHist("NJET"    , 15 , 0    ,   15);
    mkHist("BDT"     , 20 , -1   ,    1);
    mkHist("EtaL1"   , 50 , -2.5 ,  2.5);
    mkHist("EtaL2"   , 50 , -2.5 ,  2.5);
    mkHist("EtaJ1"   , 90 , -4.5 ,  4.5);
    mkHist("EtaJ2"   , 90 , -4.5 ,  4.5);
    mkHist("PtL1"    ,100 , 0    , 1000);
    mkHist("PtL2"    ,100 , 0    , 1000);
    mkHist("PtJ1"    ,100 , 0    , 1000);
    mkHist("PtJ2"    ,100 , 0    , 1000);
    mkHist("dLepR"   , 40 , 0    ,    4);
    mkHist("dLepPhi" , 80 , 0    ,    8);
    mkHist("dLepEta" , 40 , 0    ,    4);

    fout = new TFile(outfile.c_str(), outopt.c_str());

    reader = new TMVA::Reader("Silent");
    reader->AddVariable("leading_pT_lepton"    , & fEvt["PtL1"   ]);
    reader->AddVariable("subleading_pT_lepton" , & fEvt["PtL2"   ]);
    reader->AddVariable("second_jet_pt"        , & fEvt["PtJ2"   ]);
    reader->AddVariable("met_tst"              , & fEvt["MET"    ]);
    reader->AddVariable("M2Lep"                , & fEvt["M2L"    ]);
    reader->AddVariable("dLepR"                , & fEvt["dLepR"  ]);
    reader->AddVariable("dLepPhi"              , & fEvt["dLepPhi"]);
    reader->AddVariable("dLepEta"              , & fEvt["dLepEta"]);
    reader->AddVariable("mjj"                  , & fEvt["MJJ"    ]);
    reader->AddVariable("dYJJ"                 , & fEvt["dYJJ"   ]);
    reader->AddVariable("sumpT_scalar"         , & fEvt["HT"     ]);
    reader->AddVariable("met_signi"            , & fEvt["METSIG" ]);
    reader->AddVariable("j1timej2Rap"          , & fEvt["jYxY"   ]);
    reader->AddSpectator("weight"              , & fEvt["weight" ]);
    reader->BookMVA("BDT", "/atlas/data19/liji/Jing/Jing/vbszz/TrainBDT/N-LeadJpt/MC/weights/VBS_BDTG.weights.xml");

}

jTREE::~jTREE(){
    fout->cd();
    for (auto h : h2JET)  h.second.Write();
    for (auto h : h2lSR)  h.second.Write();
    for (auto h : h2lVR)  h.second.Write();
    for (auto h : hemCR)  h.second.Write();
    for (auto h : h3lCR)  h.second.Write();
    for (auto h : hmmmCR) h.second.Write();
    for (auto h : hmmeCR) h.second.Write();
    for (auto h : heeeCR) h.second.Write();
    for (auto h : heemCR) h.second.Write();
    for (auto h : h2JET)  { std::cout << "2JET      " << h.second.Integral(0, -1) << std::endl; break; }
    for (auto h : h2lSR)  { std::cout << "2lSR      " << h.second.Integral(0, -1) << std::endl; break; }
    for (auto h : h2lVR)  { std::cout << "2lVR      " << h.second.Integral(0, -1) << std::endl; break; }
    for (auto h : hemCR)  { std::cout << "emCR      " << h.second.Integral(0, -1) << std::endl; break; }
    for (auto h : h3lCR)  { std::cout << "3lCR      " << h.second.Integral(0, -1) << std::endl; break; }
    for (auto h : hmmmCR) { std::cout << "3lCR mmm  " << h.second.Integral(0, -1) << std::endl; break; }
    for (auto h : hmmeCR) { std::cout << "3lCR mme  " << h.second.Integral(0, -1) << std::endl; break; }
    for (auto h : heeeCR) { std::cout << "3lCR eee  " << h.second.Integral(0, -1) << std::endl; break; }
    for (auto h : heemCR) { std::cout << "3lCR eem  " << h.second.Integral(0, -1) << std::endl; break; }
    fout->Close();
}


bool jTREE::LoopROOT(std::string filename, float xsec){
    TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(filename.c_str());
    if (!f || !f->IsOpen()) f = new TFile(filename.c_str(), "read");
    f->GetObject(("tree_"+this->treename).c_str(), this->tree);

    std::cout << "      reading... " << filename << std::endl;

    TH1F *hInfo = (TH1F*)f->Get("hInfo");
    if (hInfo) this->factor = xsec / hInfo->GetBinContent(2);
    else this->factor = xsec;

    if (filename.find("r9364")  != std::string::npos) this->factor *= 3219.56 + 32965.3;
    if (filename.find("r10201") != std::string::npos) this->factor *= 44307.4;
    if (filename.find("r10724") != std::string::npos) this->factor *= 58450.1;

    for (auto varname: inVarI) tree->SetBranchAddress(varname.c_str(), &iEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    for (auto varname: inVarF) tree->SetBranchAddress(varname.c_str(), &fEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    for (auto varname: inVarV) tree->SetBranchAddress(varname.c_str(), &vEvt[varname.c_str()], &BrEvt[varname.c_str()]);

    Long64_t nentries = tree->GetEntriesFast();
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
        tree->GetEntry(jentry);
        int region = Cut();
        if (region == RG::_NONE) continue;
        LoopEVT(region);
    }

    f->Close();
    return true;
}


bool jTREE::mkHist(std::string hname, const int nBins, const float left, const float right){
    plotVars.push_back(hname);
    if (!(this->Wname).empty()){
        h2JET [std::make_pair(hname, this->treename)] = TH1F(("llvv__2JET__"  +hname+"__"+this->Wname).c_str(), "", nBins, left, right);
        h2lSR [std::make_pair(hname, this->treename)] = TH1F(("llvv__2lSR__"  +hname+"__"+this->Wname).c_str(), "", nBins, left, right);
        h2lSR [std::make_pair(hname, "high_" + this->treename)] = TH1F(("llvv__HIGH__"  +hname+"__"+this->Wname).c_str(), "", nBins, left, right);
        h2lSR [std::make_pair(hname, "low_" + this->treename)] = TH1F(("llvv__LOW__"  +hname+"__"+this->Wname).c_str(), "", nBins, left, right);
        h2lVR [std::make_pair(hname, this->treename)] = TH1F(("llvv__2lVR__"  +hname+"__"+this->Wname).c_str(), "", nBins, left, right);
        hemCR [std::make_pair(hname, this->treename)] = TH1F(("llvv__emCR__"  +hname+"__"+this->Wname).c_str(), "", nBins, left, right);
        h3lCR [std::make_pair(hname, this->treename)] = TH1F(("llvv__3lCR__"  +hname+"__"+this->Wname).c_str(), "", nBins, left, right);
        hmmmCR[std::make_pair(hname, this->treename)] = TH1F(("llvv__mmmCR__" +hname+"__"+this->Wname).c_str(), "", nBins, left, right);
        hmmeCR[std::make_pair(hname, this->treename)] = TH1F(("llvv__mmeCR__" +hname+"__"+this->Wname).c_str(), "", nBins, left, right);
        heeeCR[std::make_pair(hname, this->treename)] = TH1F(("llvv__eeeCR__" +hname+"__"+this->Wname).c_str(), "", nBins, left, right);
        heemCR[std::make_pair(hname, this->treename)] = TH1F(("llvv__eemCR__" +hname+"__"+this->Wname).c_str(), "", nBins, left, right);
    }
    else{
        h2JET [std::make_pair(hname, this->treename)] = TH1F(("llvv__2JET__"  +hname+"__"+this->treename).c_str(), "", nBins, left, right);
        h2lSR [std::make_pair(hname, this->treename)] = TH1F(("llvv__2lSR__"  +hname+"__"+this->treename).c_str(), "", nBins, left, right);
        h2lSR [std::make_pair(hname, "high_" + this->treename)] = TH1F(("llvv__HIGH__"  +hname+"__"+this->treename).c_str(), "", nBins, left, right);
        h2lSR [std::make_pair(hname, "low_" + this->treename)] = TH1F(("llvv__LOW__"  +hname+"__"+this->treename).c_str(), "", nBins, left, right);
        h2lVR [std::make_pair(hname, this->treename)] = TH1F(("llvv__2lVR__"  +hname+"__"+this->treename).c_str(), "", nBins, left, right);
        hemCR [std::make_pair(hname, this->treename)] = TH1F(("llvv__emCR__"  +hname+"__"+this->treename).c_str(), "", nBins, left, right);
        h3lCR [std::make_pair(hname, this->treename)] = TH1F(("llvv__3lCR__"  +hname+"__"+this->treename).c_str(), "", nBins, left, right);
        hmmmCR[std::make_pair(hname, this->treename)] = TH1F(("llvv__mmmCR__" +hname+"__"+this->treename).c_str(), "", nBins, left, right);
        hmmeCR[std::make_pair(hname, this->treename)] = TH1F(("llvv__mmeCR__" +hname+"__"+this->treename).c_str(), "", nBins, left, right);
        heeeCR[std::make_pair(hname, this->treename)] = TH1F(("llvv__eeeCR__" +hname+"__"+this->treename).c_str(), "", nBins, left, right);
        heemCR[std::make_pair(hname, this->treename)] = TH1F(("llvv__eemCR__" +hname+"__"+this->treename).c_str(), "", nBins, left, right);
    }

    for (auto v: inVarSYST){
        h2JET [std::make_pair(hname, v)] = TH1F(("llvv__2JET__"  +hname+"__"+v).c_str(), "", nBins, left, right);
        h2lSR [std::make_pair(hname, v)] = TH1F(("llvv__2lSR__"  +hname+"__"+v).c_str(), "", nBins, left, right);
        h2lSR [std::make_pair(hname, "high_" + v)] = TH1F(("llvv__HIGH__"  +hname+"__"+v).c_str(), "", nBins, left, right);
        h2lSR [std::make_pair(hname, "low_" + v)] = TH1F(("llvv__LOW__"  +hname+"__"+v).c_str(), "", nBins, left, right);
        h2lVR [std::make_pair(hname, v)] = TH1F(("llvv__2lVR__"  +hname+"__"+v).c_str(), "", nBins, left, right);
        hemCR [std::make_pair(hname, v)] = TH1F(("llvv__emCR__"  +hname+"__"+v).c_str(), "", nBins, left, right);
        h3lCR [std::make_pair(hname, v)] = TH1F(("llvv__3lCR__"  +hname+"__"+v).c_str(), "", nBins, left, right);
        hmmmCR[std::make_pair(hname, v)] = TH1F(("llvv__mmmCR__" +hname+"__"+v).c_str(), "", nBins, left, right);
        hmmeCR[std::make_pair(hname, v)] = TH1F(("llvv__mmeCR__" +hname+"__"+v).c_str(), "", nBins, left, right);
        heeeCR[std::make_pair(hname, v)] = TH1F(("llvv__eeeCR__" +hname+"__"+v).c_str(), "", nBins, left, right);
        heemCR[std::make_pair(hname, v)] = TH1F(("llvv__eemCR__" +hname+"__"+v).c_str(), "", nBins, left, right);
    }
    return true;
}


int jTREE::Cut()
{

    if (!(fEvt["M2Lep"]>80 && fEvt["M2Lep"]<100)) return RG::_NONE;
    if (iEvt["n_jets"]<2)                         return RG::_NONE;

    if (fEvt["lepminus_pt"] > fEvt["lepplus_pt"]){
        fEvt["PtL1"]  = fEvt["lepminus_pt"];
        fEvt["EtaL1"] = fEvt["lepminus_eta"];
        fEvt["PhiL1"] = fEvt["lepminus_phi"];
        fEvt["PtL2"]  = fEvt["lepplus_pt"];
        fEvt["EtaL2"] = fEvt["lepplus_eta"];
        fEvt["PhiL2"] = fEvt["lepplus_phi"];
    }else{
        fEvt["PtL2"]  = fEvt["lepminus_pt"];
        fEvt["EtaL2"] = fEvt["lepminus_eta"];
        fEvt["PhiL2"] = fEvt["lepminus_phi"];
        fEvt["PtL1"]  = fEvt["lepplus_pt"];
        fEvt["EtaL1"] = fEvt["lepplus_eta"];
        fEvt["PhiL1"] = fEvt["lepplus_phi"];
    }

    fEvt["PtJ1"]    = fEvt["leading_jet_pt"];
    fEvt["EtaJ1"]   = fEvt["leading_jet_eta"];
    fEvt["YJ1"]     = fEvt["leading_jet_rapidity"];
    fEvt["PtJ2"]    = fEvt["second_jet_pt"];
    fEvt["EtaJ2"]   = fEvt["second_jet_eta"];
    fEvt["YJ2"]     = fEvt["second_jet_rapidity"];
    fEvt["M2L"]     = fEvt["M2Lep"];
    fEvt["MJJ"]     = fEvt["mjj"];
    fEvt["MTW"]     = fEvt["mtw"];
    fEvt["MET"]     = fEvt["met_tst"];
    fEvt["METSIG"]  = fEvt["met_signi"];
    fEvt["NJET"]    = iEvt["n_jets"];
    fEvt["HT"]      = fEvt["sumpT_scalar"];
    fEvt["dLepPhi"] = fabs(fEvt["PhiL1"] - fEvt["PhiL2"]);
    fEvt["dLepEta"] = fabs(fEvt["EtaL1"] - fEvt["EtaL2"]);
    fEvt["dYJJ"]    = fabs(fEvt["YJ1"]   - fEvt["YJ2"]);
    fEvt["jYxY"]    = fEvt["YJ1"]        * fEvt["YJ2"];

    if (iEvt["event_3CR"]==0){
        if (iEvt["event_type"]==0 || iEvt["event_type"]==1){
            if (fEvt["METSIG"]<=12)                                       return RG::_2JET;
            if (iEvt["n_bjets"]!=0)                                       return RG::_2JET;
            if (fEvt["PtL1"]<=30)                                         return RG::_2JET;
            if (fEvt["PtL2"]<=20)                                         return RG::_2JET;
            if (fabs(fEvt["EtaL1"])>=2.5)                                 return RG::_2JET;
            if (fabs(fEvt["EtaL2"])>=2.5)                                 return RG::_2JET;
            if (fEvt["PtJ1"]<=60)                                         return RG::_2JET;
            if (fEvt["PtJ2"]<=40)                                         return RG::_2JET;
            if (fabs(fEvt["EtaJ1"])>=4.5)                                 return RG::_2JET;
            if (fabs(fEvt["EtaJ2"])>=4.5)                                 return RG::_2JET;
            if (fEvt["jYxY"]>=0)                                          return RG::_2JET;
            if (fEvt["MJJ"]>400 && fEvt["dYJJ"]>2)                        return RG::_2lSR;
            if ((fEvt["MJJ"]<=400 && fEvt["MJJ"]>200) || fEvt["dYJJ"]<=2) return RG::_2lVR;
            return RG::_2JET;
        }else if (iEvt["event_type"]==2){
            if (fEvt["METSIG"]<=12)                return RG::_NONE;
            if (iEvt["n_bjets"]!=0)                return RG::_NONE;
            if (fEvt["PtL1"]<=30)                  return RG::_NONE;
            if (fEvt["PtL2"]<=20)                  return RG::_NONE;
            if (fabs(fEvt["EtaL1"])>=2.5)          return RG::_NONE;
            if (fabs(fEvt["EtaL2"])>=2.5)          return RG::_NONE;
            if (fEvt["PtJ1"]<=60)                  return RG::_NONE;
            if (fEvt["PtJ2"]<=40)                  return RG::_NONE;
            if (fabs(fEvt["EtaJ1"])>=4.5)          return RG::_NONE;
            if (fabs(fEvt["EtaJ2"])>=4.5)          return RG::_NONE;
            if (fEvt["jYxY"]>=0)                   return RG::_NONE;
            if (fEvt["MJJ"]>400 && fEvt["dYJJ"]>2) return RG::_emCR;
            return RG::_NONE;
        }
    }else{
        if (fEvt["METSIG"]<=3)             return RG::_NONE;
        if (iEvt["n_bjets"]!=0)            return RG::_NONE;
        if (fEvt["PtL1"]<=30)              return RG::_NONE;
        if (fEvt["PtL2"]<=20)              return RG::_NONE;
        if (fabs(fEvt["EtaL1"])>=2.5)      return RG::_NONE;
        if (fabs(fEvt["EtaL2"])>=2.5)      return RG::_NONE;
        if (fEvt["PtJ1"]<=60)              return RG::_NONE;
        if (fEvt["PtJ2"]<=40)              return RG::_NONE;
        if (fEvt["MTW"]<=40)               return RG::_NONE;
        if (fEvt["lep3rd_pt"]<=20)         return RG::_NONE;
        if (fabs(fEvt["lep3rd_eta"])>=2.5) return RG::_NONE;
        if (iEvt["medium_3rd"]!=1)         return RG::_NONE;
        if (iEvt["event_3CR"]==1)          return RG::_3MMM;
        if (iEvt["event_3CR"]==2)          return RG::_3MME;
        if (iEvt["event_3CR"]==3)          return RG::_3EEE;
        if (iEvt["event_3CR"]==4)          return RG::_3EEM;
        return RG::_NONE;
    }
    return RG::_NONE;
}

void jTREE::LoopEVT(int region)
{
    fEvt["BDT"] = this->reader->EvaluateMVA("BDT");
    float w = fEvt["weight"] * this->factor;

    if (region >= RG::_2JET){ for (auto var: plotVars) h2JET [std::make_pair(var, this->treename)].Fill(fEvt[var], w); }
    if (region == RG::_2lSR){
        for (auto var: plotVars) h2lSR [std::make_pair(var, this->treename)].Fill(fEvt[var], w); 
        if (fEvt["BDT"]>=0.2) for (auto var: plotVars) h2lSR [std::make_pair(var, "high_" + this->treename)].Fill(fEvt[var], w); 
        else for (auto var: plotVars) h2lSR [std::make_pair(var, "low_" + this->treename)].Fill(fEvt[var], w); 
    }
    if (region == RG::_2lVR){ for (auto var: plotVars) h2lVR [std::make_pair(var, this->treename)].Fill(fEvt[var], w); }
    if (region == RG::_emCR){ for (auto var: plotVars) hemCR [std::make_pair(var, this->treename)].Fill(fEvt[var], w); }
    if (region == RG::_3MMM){
        for (auto var: plotVars) hmmmCR[std::make_pair(var, this->treename)].Fill(fEvt[var], w); 
        for (auto var: plotVars) h3lCR [std::make_pair(var, this->treename)].Fill(fEvt[var], w); 
    }
    if (region == RG::_3MME){
        for (auto var: plotVars) hmmeCR[std::make_pair(var, this->treename)].Fill(fEvt[var], w); 
        for (auto var: plotVars) h3lCR [std::make_pair(var, this->treename)].Fill(fEvt[var], w); 
    }
    if (region == RG::_3EEE){
        for (auto var: plotVars) heeeCR[std::make_pair(var, this->treename)].Fill(fEvt[var], w); 
        for (auto var: plotVars) h3lCR [std::make_pair(var, this->treename)].Fill(fEvt[var], w); 
    }
    if (region == RG::_3EEM){
        for (auto var: plotVars) heemCR[std::make_pair(var, this->treename)].Fill(fEvt[var], w); 
        for (auto var: plotVars) h3lCR [std::make_pair(var, this->treename)].Fill(fEvt[var], w); 
    }

    for (auto v: inVarSYST){
        float w = fEvt[v] * this->factor;

        if (region >= RG::_2JET){ for (auto var: plotVars) h2JET [std::make_pair(var, v)].Fill(fEvt[var], w); }
        if (region == RG::_2lSR){
            for (auto var: plotVars) h2lSR [std::make_pair(var, v)].Fill(fEvt[var], w); 
            if (fEvt["BDT"]>=0.2) for (auto var: plotVars) h2lSR [std::make_pair(var, "high_" + v)].Fill(fEvt[var], w); 
            else for (auto var: plotVars) h2lSR [std::make_pair(var, "low_" + v)].Fill(fEvt[var], w); 
        }
        if (region == RG::_2lVR){ for (auto var: plotVars) h2lVR [std::make_pair(var, v)].Fill(fEvt[var], w); }
        if (region == RG::_emCR){ for (auto var: plotVars) hemCR [std::make_pair(var, v)].Fill(fEvt[var], w); }
        if (region == RG::_3MMM){
            for (auto var: plotVars) hmmmCR[std::make_pair(var, v)].Fill(fEvt[var], w); 
            for (auto var: plotVars) h3lCR [std::make_pair(var, v)].Fill(fEvt[var], w); 
        }
        if (region == RG::_3MME){
            for (auto var: plotVars) hmmeCR[std::make_pair(var, v)].Fill(fEvt[var], w); 
            for (auto var: plotVars) h3lCR [std::make_pair(var, v)].Fill(fEvt[var], w); 
        }
        if (region == RG::_3EEE){
            for (auto var: plotVars) heeeCR[std::make_pair(var, v)].Fill(fEvt[var], w); 
            for (auto var: plotVars) h3lCR [std::make_pair(var, v)].Fill(fEvt[var], w); 
        }
        if (region == RG::_3EEM){
            for (auto var: plotVars) heemCR[std::make_pair(var, v)].Fill(fEvt[var], w); 
            for (auto var: plotVars) h3lCR [std::make_pair(var, v)].Fill(fEvt[var], w); 
        }
    }

    float sf = this->factor * fEvt["weight_pileup"] * fEvt["weight_exp"] * fEvt["weight_trig"] * fEvt["weight_jets"] * fEvt["weight_jvt"];
    for (auto v: inVarTHEO){
        float w = vEvt["vw"]->at(v.second) * sf;

        if (region >= RG::_2JET){ for (auto var: plotVars) h2JET [std::make_pair(var, v.first)].Fill(fEvt[var], w); }
        if (region == RG::_2lSR){
            for (auto var: plotVars) h2lSR [std::make_pair(var, v.first)].Fill(fEvt[var], w); 
            if (fEvt["BDT"]>=0.2) for (auto var: plotVars) h2lSR [std::make_pair(var, "high_" + v.first)].Fill(fEvt[var], w); 
            else for (auto var: plotVars) h2lSR[std::make_pair(var, "low_" + v.first)].Fill(fEvt[var], w); 
        }
        if (region == RG::_2lVR){ for (auto var: plotVars) h2lVR [std::make_pair(var, v.first)].Fill(fEvt[var], w); }
        if (region == RG::_emCR){ for (auto var: plotVars) hemCR [std::make_pair(var, v.first)].Fill(fEvt[var], w); }
        if (region == RG::_3MMM){
            for (auto var: plotVars) hmmmCR[std::make_pair(var, v.first)].Fill(fEvt[var], w); 
            for (auto var: plotVars) h3lCR [std::make_pair(var, v.first)].Fill(fEvt[var], w); 
        }
        if (region == RG::_3MME){
            for (auto var: plotVars) hmmeCR[std::make_pair(var, v.first)].Fill(fEvt[var], w); 
            for (auto var: plotVars) h3lCR [std::make_pair(var, v.first)].Fill(fEvt[var], w); 
        }
        if (region == RG::_3EEE){
            for (auto var: plotVars) heeeCR[std::make_pair(var, v.first)].Fill(fEvt[var], w); 
            for (auto var: plotVars) h3lCR [std::make_pair(var, v.first)].Fill(fEvt[var], w); 
        }
        if (region == RG::_3EEM){
            for (auto var: plotVars) heemCR[std::make_pair(var, v.first)].Fill(fEvt[var], w); 
            for (auto var: plotVars) h3lCR [std::make_pair(var, v.first)].Fill(fEvt[var], w); 
        }
    }
}
