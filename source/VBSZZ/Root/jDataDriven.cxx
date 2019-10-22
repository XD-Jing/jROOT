#define VBSZZ_jDataDriven_cxx
#include "VBSZZ/jDataDriven.h"
#include "VBSZZ/regions.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>


jDataDriven::jDataDriven(std::string treename, std::string outfile, std::string outopt, bool THEO, bool SYST, bool isData)
: tree(0), treename(treename), SYST(SYST), THEO(THEO), isData(isData)
{
    std::cout << treename << std::endl;

    inVarF = {
        "electron_pt"          , "electron_eta"        , "muon_pt"           , "muon_eta"             ,
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
        "medium_3rd", "run"
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

    /*
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
    */

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

jDataDriven::~jDataDriven(){
    fout->cd();
    for (auto h : h2lSR)  h.second.Write();
    for (auto h : h2lVR)  h.second.Write();
    for (auto h : h2lSR)  { std::cout << "2lSR      " << h.second.Integral(0, -1) << std::endl; break; }
    for (auto h : h2lVR)  { std::cout << "2lVR      " << h.second.Integral(0, -1) << std::endl; break; }
    fout->Close();
}

float jDataDriven::calculateMC(float elePt, float eleEta, float muonPt, float muonEta){
    float epsilon[3][6] = {
        {0.9327643586365427, 0.7542107879076977, 0.9871128932574271, 0.8230077475728382, 1.0569512036066002, 0.9043257541989639},
        {0.9868547953651904, 0.8273174156156066, 0.997136826411902, 0.8422879966155524, 1.059153035287991, 0.9039873683450291},
        {1.0249021061183607, 0.7761809752424993, 1.0108050862929632, 0.8529553713106591, 1.0693917888598385, 0.908827805246411}
    };

    float w = 0;

    if (muonPt>20 && muonPt<40){
        if (muonEta<1) w += 0.5 * epsilon[this->mc][0];
        else w += 0.5 * epsilon[this->mc][1];
    }else if (muonPt<60){
        if (muonEta<1) w += 0.5 * epsilon[this->mc][2];
        else w += 0.5 * epsilon[this->mc][3];
    }else{
        if (muonEta<1) w += 0.5 * epsilon[this->mc][4];
        else w += 0.5 * epsilon[this->mc][5];
    }

    if (elePt>20 && elePt<40){
        if (eleEta<1) w += 0.5 / epsilon[this->mc][0];
        else w += 0.5 / epsilon[this->mc][1];
    }else if (elePt<60){
        if (eleEta<1) w += 0.5 / epsilon[this->mc][2];
        else w += 0.5 / epsilon[this->mc][3];
    }else{
        if (eleEta<1) w += 0.5 / epsilon[this->mc][4];
        else w += 0.5 / epsilon[this->mc][5];
    }

    return w;
}

float jDataDriven::calculateData(float elePt, float eleEta, float muonPt, float muonEta){
    float epsilon[3][6] = {
        {0.9026503130680116, 0.7534702245306562, 0.979198213479133, 0.7780899672324034, 1.057740043147226, 0.8898630505312791},
        {0.8997739367739191, 0.756997051563584, 0.9770908018899246, 0.7776811662430159, 1.056375404435594, 0.8950528988918638},
        {0.8922105690717944, 0.7685009161937671, 0.9817131809987504, 0.7791684495916141, 1.0608563202069186, 0.8895168982181126}
    };

    float w = 0;

    if (muonPt>20 && muonPt<40){
        if (muonEta<1) w += 0.5 * epsilon[this->mc][0];
        else w += 0.5 * epsilon[this->mc][1];
    }else if (muonPt<60){
        if (muonEta<1) w += 0.5 * epsilon[this->mc][2];
        else w += 0.5 * epsilon[this->mc][3];
    }else{
        if (muonEta<1) w += 0.5 * epsilon[this->mc][4];
        else w += 0.5 * epsilon[this->mc][5];
    }

    if (elePt>20 && elePt<40){
        if (eleEta<1) w += 0.5 / epsilon[this->mc][0];
        else w += 0.5 / epsilon[this->mc][1];
    }else if (elePt<60){
        if (eleEta<1) w += 0.5 / epsilon[this->mc][2];
        else w += 0.5 / epsilon[this->mc][3];
    }else{
        if (eleEta<1) w += 0.5 / epsilon[this->mc][4];
        else w += 0.5 / epsilon[this->mc][5];
    }

    return w;
}

bool jDataDriven::LoopROOT(std::string filename, float xsec){
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

    this->mc = YEAR::NONE;

    if (filename.find("r9364")  != std::string::npos) this->mc = YEAR::MC16A;
    if (filename.find("r10201") != std::string::npos) this->mc = YEAR::MC16D;
    if (filename.find("r10724") != std::string::npos) this->mc = YEAR::MC16E;

    if (filename.find("data15") != std::string::npos) this->mc = YEAR::MC16A;
    if (filename.find("data16") != std::string::npos) this->mc = YEAR::MC16A;
    if (filename.find("data17") != std::string::npos) this->mc = YEAR::MC16D;
    if (filename.find("data18") != std::string::npos) this->mc = YEAR::MC16E;

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


bool jDataDriven::mkHist(std::string hname, const int nBins, const float left, const float right){
    plotVars.push_back(hname);
    h2lSR [std::make_pair(hname, "NOMINAL")] = TH1F(("llvv__2lSR__"  +hname+"__"+"DD").c_str(), "", nBins, left, right);
    h2lSR [std::make_pair(hname, "HIGH")] = TH1F(("llvv__HIGH__"  +hname+"__"+"DD").c_str(), "", nBins, left, right);
    h2lSR [std::make_pair(hname, "LOW")] = TH1F(("llvv__LOW__"  +hname+"__"+"DD").c_str(), "", nBins, left, right);
    h2lVR [std::make_pair(hname, "NOMINAL")] = TH1F(("llvv__2lVR__"  +hname+"__"+"DD").c_str(), "", nBins, left, right);

    return true;
}


int jDataDriven::Cut()
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
            return RG::_2JET;
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
            //if (fEvt["MJJ"]>400 && fEvt["dYJJ"]>2)                        return RG::_2lSR;
            //if ((fEvt["MJJ"]<=400 && fEvt["MJJ"]>200) || fEvt["dYJJ"]<=2) return RG::_2lVR;
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

            //fEvt["electron_pt"] = fEvt["leading_pT_lepton"];
            //fEvt["muon_pt"] = fEvt["subleading_pT_lepton"];
            //if (fEvt["PtL1"] == fEvt["electron_pt"]){
            //    fEvt["electron_eta"] = fEvt["EtaL1"];
            //    fEvt["muon_eta"] = fEvt["EtaL2"];
            //}else{
            //    fEvt["electron_eta"] = fEvt["EtaL2"];
            //    fEvt["muon_eta"] = fEvt["EtaL1"];
            //}

            if (fEvt["MJJ"]>400 && fEvt["dYJJ"]>2)                        return RG::_2lSR;
            if ((fEvt["MJJ"]<=400 && fEvt["MJJ"]>200) || fEvt["dYJJ"]<=2) return RG::_2lVR;
            //if (fEvt["MJJ"]>400 && fEvt["dYJJ"]>2) return RG::_emCR;
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

void jDataDriven::LoopEVT(int region)
{
    if (!(region==RG::_2lSR || region==RG::_2lVR)) return;
    fEvt["BDT"] = this->reader->EvaluateMVA("BDT");
    float w = fEvt["weight"] * this->factor;
    if (isData) w *= calculateData(fEvt["electron_pt"], fabs(fEvt["electron_eta"]), fEvt["muon_pt"], fabs(fEvt["muon_eta"]));
    else w *= calculateMC(fEvt["electron_pt"], fabs(fEvt["electron_eta"]), fEvt["muon_pt"], fabs(fEvt["muon_eta"]));

    if (region == RG::_2lSR){
        for (auto var: plotVars) h2lSR [std::make_pair(var, "NOMINAL")].Fill(fEvt[var], w); 
        if (fEvt["BDT"]>=0.2) for (auto var: plotVars) h2lSR [std::make_pair(var, "HIGH")].Fill(fEvt[var], w); 
        if (fEvt["BDT"]>=0.2) for (auto var: plotVars) h2lSR [std::make_pair(var, "LOW")].Fill(fEvt[var], w); 
    }
    if (region == RG::_2lVR){ for (auto var: plotVars) h2lVR [std::make_pair(var, "NOMINAL")].Fill(fEvt[var], w); }
}
