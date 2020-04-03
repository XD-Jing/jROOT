#define HZZ_HM_ZZ_cxx
#include "HZZ/HM_ZZ.h"
#include "HZZ/regions.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>


HM_ZZ::HM_ZZ(std::string treename, std::string outfile, std::string outopt, bool THEO)
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
        "event_type" , "event_3CR"      , "n_jets"        , "n_bjets", "llvv_is_WW_ZZ",
    };
    onVarF = {
    };

    if (THEO){
        inVarTHEO["QCD55"] = "weight_var_th_MUR0p5_MUF0p5_PDF261000";
        inVarTHEO["QCD51"] = "weight_var_th_MUR0p5_MUF1_PDF261000";
        inVarTHEO["QCD15"] = "weight_var_th_MUR1_MUF0p5_PDF261000";
        inVarTHEO["QCD12"] = "weight_var_th_MUR1_MUF2_PDF261000";
        inVarTHEO["QCD21"] = "weight_var_th_MUR2_MUF1_PDF261000";
        inVarTHEO["QCD22"] = "weight_var_th_MUR2_MUF2_PDF261000";
        for (int i =0; i<=100; i++){
            inVarTHEO["PDF"+std::to_string(i)] = "weight_var_th_MUR1_MUF1_PDF"+std::to_string(i+261000);
        }
        //for (auto v : inVarTHEO) printf("%s  %s\n", v.first.c_str(), v.second.c_str());
    }

    for (auto v: onVarF)    fEvt[v] = -999999;
    for (auto v: inVarF)    { BrEvt[v] = new TBranch(); fEvt[v] = -999999; }
    for (auto v: inVarI)    { BrEvt[v] = new TBranch(); iEvt[v] = -999999; }
    for (auto v: inVarTHEO) { BrEvt[v.second] = new TBranch(); fEvt[v.second] = -999999; }

    mkHist();

    fout = new TFile(outfile.c_str(), outopt.c_str());
}

HM_ZZ::~HM_ZZ(){
}

void HM_ZZ::Close(){
    fout->cd();
    //for (auto h : h2JET)  h.second.Write();
    for (auto h : h_GGH)  h.second.Write();
    for (auto h : h_VBF)  h.second.Write();
    //for (auto h : h2JET) { printf(" 2JET %7.5f\n", h.second.Integral());/* break;*/ } 
    //for (auto h : h_GGH) { printf("  GGH %7.5f\n", h.second.Integral());/* break;*/ } 
    for (auto h : h_VBF) {
        //printf("  VBF %7.5f\n", h.second.Integral());/* break;*/ 
        //printf("  VBF   %7.5f   %50s\n", h.second.Integral(), h.second.GetName());/* break;*/ 
    } 
    fout->Close();
}

bool HM_ZZ::LoopROOT(std::string filename, float factor){
    TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(filename.c_str());
    if (!f || !f->IsOpen()) f = new TFile(filename.c_str(), "read");
    f->GetObject(("tree_"+this->treename).c_str(), this->tree);

    std::cout << "      reading... " << filename << std::endl;

    hInfo = (TH1F*)f->Get("Hist/hInfo_PFlow");
    this->xsec = factor * hInfo->GetBinContent(1) * 2.0 / hInfo->GetEntries() / hInfo->GetBinContent(2);
    if (filename.find("r9364")  != std::string::npos) this->xsec *= (3.21956 + 32.9653);
    if (filename.find("r10201") != std::string::npos) this->xsec *= 44.3074;
    if (filename.find("r10724") != std::string::npos) this->xsec *= 58.4501;

    for (auto varname: inVarI) tree->SetBranchAddress(varname.c_str(), &iEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    for (auto varname: inVarF) tree->SetBranchAddress(varname.c_str(), &fEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    for (auto varname: inVarTHEO) tree->SetBranchAddress(varname.second.c_str(), &fEvt[varname.second.c_str()], &BrEvt[varname.second.c_str()]);
    //for (auto varname: inVarV) tree->SetBranchAddress(varname.c_str(), &vEvt[varname.c_str()], &BrEvt[varname.c_str()]);

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


bool HM_ZZ::mkHist(){
    double binVBF[5] = {100, 420, 540, 820, 1700};

    h_GGH[      this->treename] = TH1F(("llvv__GGH__mTZZ__"+this->treename).c_str(), "",  60, 0, 3000);
    h_GGH["ee_"+this->treename] = TH1F(("eevv__GGH__mTZZ__"+this->treename).c_str(), "",  60, 0, 3000);
    h_GGH["mm_"+this->treename] = TH1F(("mmvv__GGH__mTZZ__"+this->treename).c_str(), "",  60, 0, 3000);
    h_VBF[      this->treename] = TH1F(("llvv__VBF__mTZZ__"+this->treename).c_str(), "", 170, 0, 1700);
    h_VBF["ee_"+this->treename] = TH1F(("eevv__VBF__mTZZ__"+this->treename).c_str(), "", 170, 0, 1700);
    h_VBF["mm_"+this->treename] = TH1F(("mmvv__VBF__mTZZ__"+this->treename).c_str(), "", 170, 0, 1700);

    for (auto v: inVarTHEO){
        h_GGH[      v.first] = TH1F(("llvv__GGH__mTZZ__"+v.first).c_str(), "",  60, 0, 3000);
        h_GGH["ee_"+v.first] = TH1F(("eevv__GGH__mTZZ__"+v.first).c_str(), "",  60, 0, 3000);
        h_GGH["mm_"+v.first] = TH1F(("mmvv__GGH__mTZZ__"+v.first).c_str(), "",  60, 0, 3000);
        h_VBF[      v.first] = TH1F(("llvv__VBF__mTZZ__"+v.first).c_str(), "", 170, 0, 1700);
        h_VBF["ee_"+v.first] = TH1F(("eevv__VBF__mTZZ__"+v.first).c_str(), "", 170, 0, 1700);
        h_VBF["mm_"+v.first] = TH1F(("mmvv__VBF__mTZZ__"+v.first).c_str(), "", 170, 0, 1700);
    }

    return true;
}


int HM_ZZ::Cut()
{

    //printf("OOO");
    if (iEvt["llvv_is_WW_ZZ"]==2)                 return RG::_NONE;
    if (iEvt["event_3CR"]!=0)                     return RG::_NONE;
    if (!(fEvt["M2Lep"]>76 && fEvt["M2Lep"]<106)) return RG::_NONE;
    if (fEvt["met_tst"]<=120)                     return RG::_NONE;
    if (iEvt["n_bjets"]!=0)                       return RG::_NONE;
    if (fabs(fEvt["dLepR"])>=1.8)                 return RG::_NONE;
    if (fabs(fEvt["dMetZPhi"])<=2.5)              return RG::_NONE;
    if (fabs(fEvt["dPhiJ100met"])<=0.4)           return RG::_NONE;
    if (fEvt["met_signif"]<=10)                   return RG::_NONE;

    if (iEvt["n_jets"]>=2 && fEvt["leading_jet_pt"]>30 && fEvt["second_jet_pt"]>30){
        if (fEvt["mjj"]>550 && fabs(fEvt["detajj"])>4.4){
            if (iEvt["event_type"]==0) return RG::_VBF_MM;
            if (iEvt["event_type"]==1) return RG::_VBF_EE;
            if (iEvt["event_type"]==2) return RG::_VBF_EM;
        }
    }
    if (iEvt["event_type"]==0)         return RG::_GGH_MM;
    if (iEvt["event_type"]==1)         return RG::_GGH_EE;
    if (iEvt["event_type"]==2)         return RG::_GGH_EM;

    return RG::_NONE;
}

void HM_ZZ::LoopEVT(int region)
{
    float sf = this->xsec * fEvt["weight"];

    if (region == RG::_VBF_MM){
            if (fabs(fEvt["weight_gen"])<=100){
            h_GGH[        this->treename].Fill(fEvt["mT_ZZ"], fEvt["weight"] * this->xsec);
            h_VBF[        this->treename].Fill(fEvt["mT_ZZ"], fEvt["weight"] * this->xsec);
            h_GGH["mm_" + this->treename].Fill(fEvt["mT_ZZ"], fEvt["weight"] * this->xsec);
            h_VBF["mm_" + this->treename].Fill(fEvt["mT_ZZ"], fEvt["weight"] * this->xsec);

            for (auto v: inVarTHEO){
                h_GGH[        v.first].Fill(fEvt["mT_ZZ"], fEvt[v.second] * sf);
                h_VBF[        v.first].Fill(fEvt["mT_ZZ"], fEvt[v.second] * sf);
                h_GGH["mm_" + v.first].Fill(fEvt["mT_ZZ"], fEvt[v.second] * sf);
                h_VBF["mm_" + v.first].Fill(fEvt["mT_ZZ"], fEvt[v.second] * sf);
            }
        }
    }

    if (region == RG::_VBF_EE){
        if (fabs(fEvt["weight_gen"])<=100){
            h_GGH[        this->treename].Fill(fEvt["mT_ZZ"], fEvt["weight"] * this->xsec);
            h_VBF[        this->treename].Fill(fEvt["mT_ZZ"], fEvt["weight"] * this->xsec);
            h_GGH["ee_" + this->treename].Fill(fEvt["mT_ZZ"], fEvt["weight"] * this->xsec);
            h_VBF["ee_" + this->treename].Fill(fEvt["mT_ZZ"], fEvt["weight"] * this->xsec);

            for (auto v: inVarTHEO){
                h_GGH[        v.first].Fill(fEvt["mT_ZZ"], fEvt[v.second] * sf);
                h_VBF[        v.first].Fill(fEvt["mT_ZZ"], fEvt[v.second] * sf);
                h_GGH["ee_" + v.first].Fill(fEvt["mT_ZZ"], fEvt[v.second] * sf);
                h_VBF["ee_" + v.first].Fill(fEvt["mT_ZZ"], fEvt[v.second] * sf);
            }
        }
    }

    if (region == RG::_GGH_MM){
        if (fabs(fEvt["weight_gen"])<=100){
            h_GGH[        this->treename].Fill(fEvt["mT_ZZ"], fEvt["weight"] * this->xsec);
            h_GGH["mm_" + this->treename].Fill(fEvt["mT_ZZ"], fEvt["weight"] * this->xsec);

            for (auto v: inVarTHEO){
                h_GGH[        v.first].Fill(fEvt["mT_ZZ"], fEvt[v.second] * sf);
                h_GGH["mm_" + v.first].Fill(fEvt["mT_ZZ"], fEvt[v.second] * sf);
            }
        }
    }

    if (region == RG::_GGH_EE){
        if (fabs(fEvt["weight_gen"])<=100){
            h_GGH[        this->treename].Fill(fEvt["mT_ZZ"], fEvt["weight"] * this->xsec);
            h_GGH["ee_" + this->treename].Fill(fEvt["mT_ZZ"], fEvt["weight"] * this->xsec);

            for (auto v: inVarTHEO){
                h_GGH[        v.first].Fill(fEvt["mT_ZZ"], fEvt[v.second] * sf);
                h_GGH["ee_" + v.first].Fill(fEvt["mT_ZZ"], fEvt[v.second] * sf);
            }
        }
    }
}
