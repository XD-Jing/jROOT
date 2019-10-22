#define VBSZZ_C_factor_cxx
#include "VBSZZ/C_factor.h"
#include "VBSZZ/regions.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <string.h>

C_factor::C_factor(std::string treename , std::string outfile , std::string outopt)
: tree(0), treename(treename) , hInfo(0), outfile(outfile)
{

    std::cout << "reading... "<< this->treename << std::endl;
    inVarF = {
        "weight"               , "M2Lep"               , "met_signi"       , "mjj"            ,
        "lepplus_pt"           , "lepminus_pt"         , "lepplus_eta"     , "lepminus_eta"   ,
        "leading_jet_pt"       , "second_jet_pt"       , "leading_jet_eta" , "second_jet_eta" ,
        "leading_jet_rapidity" , "second_jet_rapidity" , "weight_jvt"      , "weight_gen"     ,
        "weight_pileup"        , "weight_exp"          , "weight_trig"     , "weight_jets"    ,
        "mc_lep1_pt"           , "mc_lep2_pt"          , "mc_jet1_pt"      , "mc_jet2_pt"     ,
        "mc_lep1_eta"          , "mc_lep2_eta"         , "mc_jet1_eta"     , "mc_jet2_eta"    ,
        "mc_YJ1"               , "mc_YJ2"              , "mc_mjj"          , "mc_dYJJ"        ,
        "mc_m2l"               , "mc_met"              ,
    };
    inVarI = {
        "event_type"           , "event_3CR"           , "n_jets"          , "n_bjets"        ,
        "medium_3rd"           , "mc_event_type"       , "n_bjets"         , "mc_njets"       ,
        "isZZWW"
    };
    onVarF = {
        "PtL1"                 , "PtL2"                , "YJ1"             , "YJ2"            ,
        "jYxY"                 , "dYJJ"
    };

    inVarW = {
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
        "JET_fJvtEfficiency__1down",
        "JET_fJvtEfficiency__1up",
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

    if (this->outfile.find("363742") != std::string::npos){
        inVarV = { "vw" };
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
    } else if (this->outfile.find("364254") != std::string::npos){
        inVarV = { "vw" };
        inVarTHEO["QCD55"] = 4;
        inVarTHEO["QCD15"] = 6;
        inVarTHEO["QCD51"] = 5;
        inVarTHEO["QCD12"] = 8;
        inVarTHEO["QCD21"] = 9;
        inVarTHEO["QCD22"] = 10;
        for (int i =11; i<111; i++) inVarTHEO["PDF"+std::to_string(i-11)] = i;
    }

    for (auto v: inVarV) { BrEvt[v] = new TBranch(); vEvt[v] = new std::vector<float>(); }
    for (auto v: inVarF) { BrEvt[v] = new TBranch(); fEvt[v] = -999999; }
    for (auto v: inVarW) { BrEvt[v] = new TBranch(); fEvt[v] = -999999; }
    for (auto v: inVarI) { BrEvt[v] = new TBranch(); iEvt[v] = -999999; }
    for (auto v: onVarF) fEvt[v] = -999999;

    mkHist();

    fout = new TFile(this->outfile.c_str(), outopt.c_str());

}

C_factor::~C_factor(){
    fout->cd();
    for (auto h : h2lSR)  h.second.Write();
    for (auto h : h2lFV)  h.second.Write();
    fout->Close();
}


bool C_factor::LoopROOT(std::string filename, float xsec){
    TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(filename.c_str());
    if (!f || !f->IsOpen()) f = new TFile(filename.c_str(), "read");
    f->GetObject(("tree_"+this->treename).c_str(), this->tree);
    hInfo = (TH1F*)f->Get("hInfo");

    this->factor = xsec / hInfo->GetBinContent(2) * 1000;

    if (filename.find("r9364")  != std::string::npos) this->factor *= 3219.56 + 32965.3;
    if (filename.find("r10201") != std::string::npos) this->factor *= 44307.4;
    if (filename.find("r10724") != std::string::npos) this->factor *= 58450.1;

    this->factor *= 1.0 / (3219.56 + 32965.3 + 44307.4 + 58450.1);

    for (auto v: inVarI) tree->SetBranchAddress(v.c_str(), &iEvt[v.c_str()], &BrEvt[v.c_str()]);
    for (auto v: inVarF) tree->SetBranchAddress(v.c_str(), &fEvt[v.c_str()], &BrEvt[v.c_str()]);
    if (this->treename.compare("NOMINAL")==0){
        for (auto v: inVarV) tree->SetBranchAddress(v.c_str(), &vEvt[v.c_str()], &BrEvt[v.c_str()]);
        for (auto v: inVarW) tree->SetBranchAddress(("weight_"+v).c_str(), &fEvt[v.c_str()], &BrEvt[v.c_str()]);
    }

    Long64_t nentries = tree->GetEntriesFast();
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
        tree->GetEntry(jentry);
        int fv = CutFV();
        int sr = CutSR();
        LoopEVT(fv, sr);
    }

    f->Close();
    return true;
}


bool C_factor::mkHist(){
    if (this->treename.compare("NOMINAL")==0){
        for (auto v: inVarTHEO){
            h2lSR[v.first] = TH1F(("llvv__2lSR__"+v.first).c_str(), "", 1, 0, 10);
            h2lFV[v.first] = TH1F(("llvv__2lFV__"+v.first).c_str(), "", 1, 0, 10);
        }
        for (auto v: inVarW){
            h2lSR[v] = TH1F(("llvv__2lSR__"+v).c_str(), "", 1, 0, 10);
        }
        h2lFV[this->treename] = TH1F(("llvv__2lFV__"+this->treename).c_str(), "", 1, 0, 10);
    }
    h2lSR[this->treename] = TH1F(("llvv__2lSR__"+this->treename).c_str(), "", 1, 0, 10);
    return true;
}


int C_factor::CutSR()
{
    if (fEvt["lepminus_pt"] > fEvt["lepplus_pt"]){
        fEvt["PtL1"] = fEvt["lepminus_pt"];
        fEvt["PtL2"] = fEvt["lepplus_pt"];
    }else{
        fEvt["PtL2"] = fEvt["lepminus_pt"];
        fEvt["PtL1"] = fEvt["lepplus_pt"];
    }

    fEvt["dYJJ"] = fabs(fEvt["second_jet_rapidity"] - fEvt["leading_jet_rapidity"]);
    fEvt["jYxY"] =      fEvt["second_jet_rapidity"] * fEvt["leading_jet_rapidity"];

    if (this->outfile.find("364254") != std::string::npos) if (iEvt["isZZWW"] != 1) return RG::_NONE;

    if (!(fEvt["M2Lep"]>80 && fEvt["M2Lep"]<100))          return RG::_NONE;
    if (iEvt["n_jets"]<2)                                  return RG::_NONE;
    if (iEvt["event_3CR"]!=0)                              return RG::_NONE;
    if (!(iEvt["event_type"]==0 || iEvt["event_type"]==1)) return RG::_NONE;
    if (fEvt["met_signi"]<=12)                             return RG::_NONE;
    if (iEvt["n_bjets"]!=0)                                return RG::_NONE;
    if (fEvt["PtL1"]<=30)                                  return RG::_NONE;
    if (fEvt["PtL2"]<=20)                                  return RG::_NONE;
    if (fabs(fEvt["lepplus_eta"])>=2.5)                    return RG::_NONE;
    if (fabs(fEvt["lepminus_eta"])>=2.5)                   return RG::_NONE;
    if (fEvt["leading_jet_pt"]<=60)                        return RG::_NONE;
    if (fEvt["second_jet_pt"]<=40)                         return RG::_NONE;
    if (fabs(fEvt["leading_jet_eta"])>=4.5)                return RG::_NONE;
    if (fabs(fEvt["second_jet_eta"])>=4.5)                 return RG::_NONE;
    if (fEvt["jYxY"]>=0)                                   return RG::_NONE;
    if (fEvt["mjj"]>400 && fEvt["dYJJ"]>2)                 return RG::_2lSR;

    return RG::_NONE;
}

int C_factor::CutFV()
{
    if (this->outfile.find("364254") != std::string::npos) if (iEvt["isZZWW"] != 1) return RG::_NONE;

    if (this->treename.compare("NOMINAL")!=0)                    return RG::_NONE;
    if (!(fEvt["mc_m2l"]>80 && fEvt["mc_m2l"]<100))              return RG::_NONE;
    if (iEvt["mc_njets"]<2)                                      return RG::_NONE;
    if (!(iEvt["mc_event_type"]==0 || iEvt["mc_event_type"]==1)) return RG::_NONE;
    if (fEvt["mc_lep1_pt"]<=30)                                  return RG::_NONE;
    if (fEvt["mc_lep2_pt"]<=20)                                  return RG::_NONE;
    if (fabs(fEvt["mc_lep1_eta"])>=2.5)                          return RG::_NONE;
    if (fabs(fEvt["mc_lep2_eta"])>=2.5)                          return RG::_NONE;
    if (fEvt["mc_jet1_pt"]<=60)                                  return RG::_NONE;
    if (fEvt["mc_jet2_pt"]<=40)                                  return RG::_NONE;
    if (fabs(fEvt["mc_jet1_eta"])>=4.5)                          return RG::_NONE;
    if (fabs(fEvt["mc_jet2_eta"])>=4.5)                          return RG::_NONE;
    if (fEvt["mc_met"]<=130)                                     return RG::_NONE;
    if (fEvt["mc_YJ1"] * fEvt["mc_YJ2"]>=0)                      return RG::_NONE;
    if (fEvt["mc_mjj"]>400 && fEvt["mc_dYJJ"]>2)                 return RG::_2lFV;

    return RG::_NONE;
}

void C_factor::LoopEVT(int fv, int sr)
{

    if (this->treename.compare("NOMINAL")==0){
        if (fv == RG::_2lFV){
            h2lFV["NOMINAL"].Fill(1, fEvt["weight_gen"] * this->factor);
            for (auto v: inVarTHEO) h2lFV[v.first].Fill(1, vEvt["vw"]->at(v.second) * this->factor);
        }

        if (sr == RG::_2lSR){
            float sf = this->factor * fEvt["weight_pileup"] * fEvt["weight_exp"] * fEvt["weight_trig"] * fEvt["weight_jets"] * fEvt["weight_jvt"];
            for (auto v: inVarTHEO) h2lSR[v.first].Fill(1, vEvt["vw"]->at(v.second) * sf);
            for (auto v: inVarW) h2lSR[v].Fill(1, fEvt[v] * this->factor);
            h2lSR[this->treename].Fill(1, fEvt["weight"] * this->factor);
        }
    }else{
        if (sr == RG::_2lSR) h2lSR[this->treename].Fill(1, fEvt["weight"] * this->factor);
    }
}
