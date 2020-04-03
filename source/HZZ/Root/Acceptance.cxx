#define HZZ_Acceptance_cxx
#include "HZZ/Acceptance.h"
#include "HZZ/regions.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>


Acceptance::Acceptance(std::string treename, std::string outfile, std::string outopt, bool THEO, bool SYST)
: tree(0), treename(treename), SYST(SYST), THEO(THEO)
{
    std::cout << treename << std::endl;

    inVarF = {
         "M2Lep"     , "leading_jet_pt" , "second_jet_pt" , "dLepR"   , "met_tst"       ,
        "met_signif"  , "mjj"            , "detajj"        , "dMetZPhi", "dPhiJ100met", 
        "weight"  , "weight_pileup" , "mT_ZZ" ,
        "weight_exp" , "weight_trig"    , "weight_jets"   , "weight_jvt"
    };
    inVarI = {
        "event_type" , "event_3CR"      , "n_jets"        , "n_bjets"
    };
    onVarF = {
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
        inVarTHEO["QCD55"] = 4;
        inVarTHEO["QCD15"] = 6;
        inVarTHEO["QCD51"] = 5;
        inVarTHEO["QCD12"] = 8;
        inVarTHEO["QCD21"] = 9;
        inVarTHEO["QCD22"] = 10;
        for (int i =11; i<111; i++) inVarTHEO["PDF"+std::to_string(i-11)] = i;
    }

    for (auto v: onVarF)    fEvt[v] = -999999;
    for (auto v: inVarV)    { BrEvt[v] = new TBranch(); vEvt[v] = new std::vector<float>(); }
    for (auto v: inVarF)    { BrEvt[v] = new TBranch(); fEvt[v] = -999999; }
    for (auto v: inVarI)    { BrEvt[v] = new TBranch(); iEvt[v] = -999999; }
    for (auto v: inVarSYST) { BrEvt[v] = new TBranch(); fEvt[v] = -999999; }

    mkHist();

    fout = new TFile(outfile.c_str(), outopt.c_str());
}

Acceptance::~Acceptance(){
}

void Acceptance::Close(){
    fout->cd();
    for (auto h : h2JET)  h.second.Write();
    for (auto h : h_GGH)  h.second.Write();
    for (auto h : h_VBF)  h.second.Write();
    for (auto h : h2JET) { printf(" 2JET %7.5f\n", h.second.Integral()); break; } 
    for (auto h : h_GGH) { printf("  GGH %7.5f\n", h.second.Integral()); break; } 
    for (auto h : h_VBF) { printf("  VBF %7.5f\n", h.second.Integral()); break; } 
    fout->Close();
}

bool Acceptance::LoopROOT(std::string filename, float xsec){
    TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(filename.c_str());
    if (!f || !f->IsOpen()) f = new TFile(filename.c_str(), "read");
    f->GetObject(("tree_"+this->treename).c_str(), this->tree);

    std::cout << "      reading... " << filename << std::endl;

    hInfo = (TH1F*)f->Get("hInfo");
    //this->xsec = 1;
    this->xsec = xsec;
    //this->xsec = hInfo->GetBinContent(1)*2.0/hInfo->GetEntries();
    if (filename.find("r9364")  != std::string::npos) this->xsec *= (3.21956 + 32.9653);
    if (filename.find("r10201") != std::string::npos) this->xsec *= 44.3074;
    if (filename.find("r10724") != std::string::npos) this->xsec *= 58.4501;
    this->xsec *= 1000;// / (3219.56 + 32965.3 + 44307.4 + 58450.1);
    this->xsec *= 1.0 / hInfo->GetBinContent(2);

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


bool Acceptance::mkHist(){

    h_GGH[this->treename] = TH1F(("llvv__GGH__mTZZ__"+this->treename).c_str(), "", 60, 0, 3000);
    h_VBF[this->treename] = TH1F(("llvv__VBF__mTZZ__"+this->treename).c_str(), "", 60, 0, 3000);

    h_GGH["ee_" + this->treename] = TH1F(("llvv__ee__GGH__mTZZ__"+this->treename).c_str(), "", 60, 0, 3000);
    h_GGH["mm_" + this->treename] = TH1F(("llvv__mm__GGH__mTZZ__"+this->treename).c_str(), "", 60, 0, 3000);
    h_VBF["ee_" + this->treename] = TH1F(("llvv__ee__VBF__mTZZ__"+this->treename).c_str(), "", 60, 0, 3000);
    h_VBF["mm_" + this->treename] = TH1F(("llvv__mm__VBF__mTZZ__"+this->treename).c_str(), "", 60, 0, 3000);

    for (auto v: inVarSYST){
        h_GGH[v] = TH1F(("llvv__GGH__mTZZ__"+v).c_str(), "", 60, 0, 3000);
        h_VBF[v] = TH1F(("llvv__VBF__mTZZ__"+v).c_str(), "", 60, 0, 3000);
        h_GGH["ee_" + v] = TH1F(("llvv__ee__GGH__mTZZ__"+v).c_str(), "", 60, 0, 3000);
        h_GGH["mm_" + v] = TH1F(("llvv__mm__GGH__mTZZ__"+v).c_str(), "", 60, 0, 3000);
        h_VBF["ee_" + v] = TH1F(("llvv__ee__VBF__mTZZ__"+v).c_str(), "", 60, 0, 3000);
        h_VBF["mm_" + v] = TH1F(("llvv__mm__VBF__mTZZ__"+v).c_str(), "", 60, 0, 3000);
    }

    for (auto v: inVarTHEO){
        h_GGH[v.first] = TH1F(("llvv__GGH__mTZZ__"+v.first).c_str(), "", 60, 0, 3000);
        h_VBF[v.first] = TH1F(("llvv__VBF__mTZZ__"+v.first).c_str(), "", 60, 0, 3000);
        h_GGH["ee_" + v.first] = TH1F(("llvv__ee__GGH__mTZZ__"+v.first).c_str(), "", 60, 0, 3000);
        h_GGH["mm_" + v.first] = TH1F(("llvv__mm__GGH__mTZZ__"+v.first).c_str(), "", 60, 0, 3000);
        h_VBF["ee_" + v.first] = TH1F(("llvv__ee__VBF__mTZZ__"+v.first).c_str(), "", 60, 0, 3000);
        h_VBF["mm_" + v.first] = TH1F(("llvv__mm__VBF__mTZZ__"+v.first).c_str(), "", 60, 0, 3000);
    }

    return true;
}


int Acceptance::Cut()
{

    if (iEvt["event_3CR"]!=0)                     return RG::_NONE;
    if (!(fEvt["M2Lep"]>76 && fEvt["M2Lep"]<106)) return RG::_NONE;
    if (fEvt["met_tst"]<=120)                     return RG::_NONE;
    if (iEvt["n_bjets"]!=0)                       return RG::_NONE;
    if (fabs(fEvt["dLepR"])>=1.8)                 return RG::_NONE;
    if (fabs(fEvt["dMetZPhi"])<=2.5)              return RG::_NONE;
    if (fabs(fEvt["dPhiJ100met"])<=0.4)           return RG::_NONE;
    if (fEvt["met_signif"]<=10)                    return RG::_NONE;
    //printf("y\n");

    if (iEvt["n_jets"]>=2 && fEvt["leading_jet_pt"]>30 && fEvt["second_jet_pt"]>30){
        if (fEvt["mjj"]>550 && fabs(fEvt["detajj"])>4.4){
            if (iEvt["event_type"]==0) return RG::_VBF_MM;
            if (iEvt["event_type"]==1) return RG::_VBF_EE;
            if (iEvt["event_type"]==2) return RG::_VBF_EM;
        }
        //if (iEvt["event_type"]==0)     return RG::_2JET_MM;
        //if (iEvt["event_type"]==1)     return RG::_2JET_EE;
        //if (iEvt["event_type"]==2)     return RG::_2JET_EM;
    }
    if (iEvt["event_type"]==0)         return RG::_GGH_MM;
    if (iEvt["event_type"]==1)         return RG::_GGH_EE;
    if (iEvt["event_type"]==2)         return RG::_GGH_EM;

    return RG::_NONE;
}

void Acceptance::LoopEVT(int region)
{
    float sf = this->xsec * fEvt["weight_pileup"] * fEvt["weight_exp"] * fEvt["weight_trig"] * fEvt["weight_jets"] * fEvt["weight_jvt"];
    //for (auto v: inVarTHEO){
    //    float tmp = fabs((vEvt["vw"]->at(v.second) - vEvt["vw"]->at(0)) / vEvt["vw"]->at(0));
    //    if (tmp>50) std::cout << v.first << "   " << tmp<<std::endl;
    //}

    if (region == RG::_VBF_MM){
        if (fabs(fEvt["weight_gen"])<=100){

            h_GGH[this->treename].Fill(fEvt["mT_ZZ"], fEvt["weight"] * this->xsec);
            h_VBF[this->treename].Fill(fEvt["mT_ZZ"], fEvt["weight"] * this->xsec);
            h_GGH["mm_" + this->treename].Fill(fEvt["mT_ZZ"], fEvt["weight"] * this->xsec);
            h_VBF["mm_" + this->treename].Fill(fEvt["mT_ZZ"], fEvt["weight"] * this->xsec);

            for (auto v: inVarSYST){
                h_GGH[v].Fill(fEvt["mT_ZZ"], fEvt[v] * this->xsec);
                h_VBF[v].Fill(fEvt["mT_ZZ"], fEvt[v] * this->xsec);
                h_GGH["mm_" + v].Fill(fEvt["mT_ZZ"], fEvt[v] * this->xsec);
                h_VBF["mm_" + v].Fill(fEvt["mT_ZZ"], fEvt[v] * this->xsec);
            }
        }

        for (auto v: inVarTHEO){
            if (fabs(vEvt["vw"]->at(v.second))<=100){
                h_GGH[v.first].Fill(fEvt["mT_ZZ"], vEvt["vw"]->at(v.second) * sf);
                h_VBF[v.first].Fill(fEvt["mT_ZZ"], vEvt["vw"]->at(v.second) * sf);
                h_GGH["mm_" + v.first].Fill(fEvt["mT_ZZ"], vEvt["vw"]->at(v.second) * sf);
                h_VBF["mm_" + v.first].Fill(fEvt["mT_ZZ"], vEvt["vw"]->at(v.second) * sf);
            }
        }
    }

    if (region == RG::_VBF_EE){
        if (fabs(fEvt["weight_gen"])<=100){

            h_GGH[this->treename].Fill(fEvt["mT_ZZ"], fEvt["weight"] * this->xsec);
            h_VBF[this->treename].Fill(fEvt["mT_ZZ"], fEvt["weight"] * this->xsec);
            h_GGH["ee_" + this->treename].Fill(fEvt["mT_ZZ"], fEvt["weight"] * this->xsec);
            h_VBF["ee_" + this->treename].Fill(fEvt["mT_ZZ"], fEvt["weight"] * this->xsec);

            for (auto v: inVarSYST){
                h_GGH[v].Fill(fEvt["mT_ZZ"], fEvt[v] * this->xsec);
                h_VBF[v].Fill(fEvt["mT_ZZ"], fEvt[v] * this->xsec);
                h_GGH["ee_" + v].Fill(fEvt["mT_ZZ"], fEvt[v] * this->xsec);
                h_VBF["ee_" + v].Fill(fEvt["mT_ZZ"], fEvt[v] * this->xsec);
            }
        }

        for (auto v: inVarTHEO){
            if (fabs(vEvt["vw"]->at(v.second))<=100){

                h_GGH[v.first].Fill(fEvt["mT_ZZ"], vEvt["vw"]->at(v.second) * sf);
                h_VBF[v.first].Fill(fEvt["mT_ZZ"], vEvt["vw"]->at(v.second) * sf);
                h_GGH["ee_" + v.first].Fill(fEvt["mT_ZZ"], vEvt["vw"]->at(v.second) * sf);
                h_VBF["ee_" + v.first].Fill(fEvt["mT_ZZ"], vEvt["vw"]->at(v.second) * sf);
            }
        }
    }

    if (region == RG::_GGH_MM){
        if (fabs(fEvt["weight_gen"])<=100){
            h_GGH[this->treename].Fill(fEvt["mT_ZZ"], fEvt["weight"] * this->xsec);
            h_GGH["mm_" + this->treename].Fill(fEvt["mT_ZZ"], fEvt["weight"] * this->xsec);

            for (auto v: inVarSYST){
                h_GGH[v].Fill(fEvt["mT_ZZ"], fEvt[v] * this->xsec);
                h_GGH["mm_" + v].Fill(fEvt["mT_ZZ"], fEvt[v] * this->xsec);
            }

        }
        for (auto v: inVarTHEO){
            if (fabs(vEvt["vw"]->at(v.second))<=100){
                h_GGH[v.first].Fill(fEvt["mT_ZZ"], vEvt["vw"]->at(v.second) * sf);
                h_GGH["mm_" + v.first].Fill(fEvt["mT_ZZ"], vEvt["vw"]->at(v.second) * sf);
            }
        }
    }

    if (region == RG::_GGH_EE){
        if (fabs(fEvt["weight_gen"])<=100){
            h_GGH[this->treename].Fill(fEvt["mT_ZZ"], fEvt["weight"] * this->xsec);
            h_GGH["ee_" + this->treename].Fill(fEvt["mT_ZZ"], fEvt["weight"] * this->xsec);

            for (auto v: inVarSYST){
                h_GGH[v].Fill(fEvt["mT_ZZ"], fEvt[v] * this->xsec);
                h_GGH["ee_" + v].Fill(fEvt["mT_ZZ"], fEvt[v] * this->xsec);
            }

        }
        for (auto v: inVarTHEO){
            if (fabs(vEvt["vw"]->at(v.second))<=100){
                h_GGH[v.first].Fill(fEvt["mT_ZZ"], vEvt["vw"]->at(v.second) * sf);
                h_GGH["ee_" + v.first].Fill(fEvt["mT_ZZ"], vEvt["vw"]->at(v.second) * sf);
            }
        }
    }
}
