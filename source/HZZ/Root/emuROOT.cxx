#define HZZ_emuROOT_cxx
#include "HZZ/emuROOT.h"
#include "HZZ/regions.h"
#include <TH1F.h>
#include <TStyle.h>
#include <TCanvas.h>


emuROOT::emuROOT(std::string treename, std::string outfile, std::string outopt, std::string tag)
: tree(0), treename(treename)
{
    inVarF = {
         "M2Lep"     , "leading_jet_pt" , "second_jet_pt" , "dLepR"   , "met_tst"       ,
        "met_signif"  , "mjj"            , "detajj"        , "dMetZPhi", "dPhiJ100met", 
        "lepplus_pt", "lepplus_eta", "lepminus_pt", "lepminus_eta", "weight", 
        "mT_ZZ", 
    };
    inVarI = {
        "event_type" , "event_3CR"      , "n_jets"        , "n_bjets"
    };
    onVarF = {
    };

    for (auto v: onVarF)    fEvt[v] = -999999;
    for (auto v: inVarV)    { BrEvt[v] = new TBranch(); vEvt[v] = new std::vector<float>(); }
    for (auto v: inVarF)    { BrEvt[v] = new TBranch(); fEvt[v] = -999999; }
    for (auto v: inVarI)    { BrEvt[v] = new TBranch(); iEvt[v] = -999999; }

    H1.clear(); H2.clear(); H3.clear();
    mkHist(tag);

    fout = new TFile(outfile.c_str(), outopt.c_str());
}

emuROOT::~emuROOT(){
}

void emuROOT::Close(){
    fout->cd();
    for (auto h : H3) h.second.Write();
    for (auto h : H2) h.second.Write();
    for (auto h : H1) h.second.Write();
    fout->Close();
}

bool emuROOT::LoopROOT(std::string filename, double factor, std::string treename){
    TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(filename.c_str());
    if (!f || !f->IsOpen()) f = new TFile(filename.c_str(), "read");
    if (!treename.empty()) f->GetObject(("tree_"+treename).c_str(), this->tree);
    else f->GetObject(("tree_"+this->treename).c_str(), this->tree);


    if (filename.find("data")==std::string::npos) {
    //if (hInfo){
        hInfo = 0;
        hInfo = (TH1F*)f->Get("Hist/hInfo_PFlow");
        this->xsec = hInfo->GetBinContent(1)*2.0/hInfo->GetEntries();
        if (filename.find("r9364")  != std::string::npos) this->xsec *= (3.21956 + 32.9653);
        if (filename.find("r10201") != std::string::npos) this->xsec *= 44.3074;
        if (filename.find("r10724") != std::string::npos) this->xsec *= 58.4501;
        this->xsec *= factor / hInfo->GetBinContent(2);
        this->isMC = true;
    }else{
        this->xsec = factor;
        this->isMC = false;
    }

    //std::cout << "      reading... " << filename << std::endl;
    printf(" %20.10f     reading... %s\n", this->xsec, filename.c_str());

    for (auto varname: inVarI) tree->SetBranchAddress(varname.c_str(), &iEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    for (auto varname: inVarF) tree->SetBranchAddress(varname.c_str(), &fEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    for (auto varname: inVarV) tree->SetBranchAddress(varname.c_str(), &vEvt[varname.c_str()], &BrEvt[varname.c_str()]);

    Long64_t nentries = tree->GetEntriesFast();
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
        tree->GetEntry(jentry);
        int region = Cut();
        if (region == EM::_NONE) continue;
        LoopEVT(region);
    }

    f->Close();
    return true;
}


bool emuROOT::mkHist(std::string tag){

    H3["ggF_e_pt_eta_mTZZ"] = TH3D( (tag+"_ggF_E_PT_ETA_mTZZ").c_str(), "", 600, 0, 3000, 250, 0, 2.5, 300, 0, 3000);
    H3["JET_e_pt_eta_mTZZ"] = TH3D( (tag+"_JET_E_PT_ETA_mTZZ").c_str(), "", 600, 0, 3000, 250, 0, 2.5, 300, 0, 3000);
    H3["VBF_e_pt_eta_mTZZ"] = TH3D( (tag+"_VBF_E_PT_ETA_mTZZ").c_str(), "", 600, 0, 3000, 250, 0, 2.5, 300, 0, 3000);
    H3["ggF_m_pt_eta_mTZZ"] = TH3D( (tag+"_ggF_M_PT_ETA_mTZZ").c_str(), "", 600, 0, 3000, 250, 0, 2.5, 300, 0, 3000);
    H3["JET_m_pt_eta_mTZZ"] = TH3D( (tag+"_JET_M_PT_ETA_mTZZ").c_str(), "", 600, 0, 3000, 250, 0, 2.5, 300, 0, 3000);
    H3["VBF_m_pt_eta_mTZZ"] = TH3D( (tag+"_VBF_M_PT_ETA_mTZZ").c_str(), "", 600, 0, 3000, 250, 0, 2.5, 300, 0, 3000);

    H2["onshell_ee"]  = TH2D( (tag+"_onshell_EE").c_str(),  "", 600, 0, 3000, 250, 0, 2.5);
    H2["onshell_mm"]  = TH2D( (tag+"_onshell_MM").c_str(),  "", 600, 0, 3000, 250, 0, 2.5);

    H1["ggF_ee_mTZZ"] = TH1D( (tag+"_ggF_EE_mTZZ").c_str(), "", 300, 0, 3000);
    H1["JET_ee_mTZZ"] = TH1D( (tag+"_JET_EE_mTZZ").c_str(), "", 300, 0, 3000);
    H1["VBF_ee_mTZZ"] = TH1D( (tag+"_VBF_EE_mTZZ").c_str(), "", 300, 0, 3000);
    H1["ggF_mm_mTZZ"] = TH1D( (tag+"_ggF_MM_mTZZ").c_str(), "", 300, 0, 3000);
    H1["JET_mm_mTZZ"] = TH1D( (tag+"_JET_MM_mTZZ").c_str(), "", 300, 0, 3000);
    H1["VBF_mm_mTZZ"] = TH1D( (tag+"_VBF_MM_mTZZ").c_str(), "", 300, 0, 3000);
    H1["ggF_em_mTZZ"] = TH1D( (tag+"_ggF_EM_mTZZ").c_str(), "", 300, 0, 3000);
    H1["JET_em_mTZZ"] = TH1D( (tag+"_JET_EM_mTZZ").c_str(), "", 300, 0, 3000);
    H1["VBF_em_mTZZ"] = TH1D( (tag+"_VBF_EM_mTZZ").c_str(), "", 300, 0, 3000);
    H1["onshell_em_mTZZ"] = TH1D( (tag+"_onshell_EM_mTZZ").c_str(), "", 300, 0, 3000);

    return true;
}


int emuROOT::Cut()
{
    //if (iEvt["event_type"]==2){
    //    fEvt["electron_pt"] = fEvt["leading_pT_lepton"];
    //    fEvt["muon_pt"] = fEvt["subleading_pT_lepton"];
    //    if (fEvt["electron_pt"]==fEvt["lepplus_pt"]){
    //        fEvt["electron_eta"] = fEvt["lepplus_eta"];
    //        fEvt["muon_eta"] = fEvt["lepminus_eta"];
    //    }else{
    //        fEvt["muon_eta"] = fEvt["lepplus_eta"];
    //        fEvt["electron_eta"] = fEvt["lepminus_eta"];
    //    }
    //}

    if (iEvt["event_3CR"]!=0)                     return EM::_NONE;
    if (!(fEvt["M2Lep"]>76 && fEvt["M2Lep"]<106)) return EM::_NONE;
    int channel = 0;
    if (iEvt["event_type"]==1)      channel = EM::_ONSHELL_EE;
    else if (iEvt["event_type"]==0) channel = EM::_ONSHELL_MM;
    else if (iEvt["event_type"]==2) channel = EM::_ONSHELL_EM;
    if (fEvt["met_tst"]<=120)                     return channel;
    if (iEvt["n_bjets"]!=0)                       return channel;
    if (fabs(fEvt["dLepR"])>=1.8)                 return channel;
    if (fabs(fEvt["dMetZPhi"])<=2.5)              return channel;
    if (fabs(fEvt["dPhiJ100met"])<=0.4)           return channel;
    if (fEvt["met_signif"]<=10)                   return channel;
    channel += 3;
    if (iEvt["n_jets"]<2)                         return channel;
    if (fEvt["leading_jet_pt"]<30)                return channel;
    if (fEvt["second_jet_pt"]<30)                 return channel;
    channel += 3;
    if (fEvt["mjj"]<=550)                         return channel;
    if (fabs(fEvt["detajj"])<=4.4)                 return channel;
    channel += 3;
    return channel;
}

void emuROOT::LoopEVT(int region)
{
    double weight;
    if (this->isMC) weight = fEvt["weight"] * this->xsec;
    else weight = this->xsec;

    if (region==EM::_ONSHELL_EE){
        H2["onshell_ee"].Fill(fEvt["lepplus_pt"], fabs(fEvt["lepplus_eta"]), weight);
        H2["onshell_ee"].Fill(fEvt["lepminus_pt"], fabs(fEvt["lepminus_eta"]), weight);
    }

    if(region==EM::_GGF_EE){
        H2["onshell_ee"].Fill(fEvt["lepplus_pt"], fabs(fEvt["lepplus_eta"]), weight);
        H2["onshell_ee"].Fill(fEvt["lepminus_pt"], fabs(fEvt["lepminus_eta"]), weight);
        H1["ggF_ee_mTZZ"].Fill(fEvt["mT_ZZ"], weight);
    }
            
    if(region==EM::_JET_EE){
        H2["onshell_ee"].Fill(fEvt["lepplus_pt"], fabs(fEvt["lepplus_eta"]), weight);
        H2["onshell_ee"].Fill(fEvt["lepminus_pt"], fabs(fEvt["lepminus_eta"]), weight);
        H1["ggF_ee_mTZZ"].Fill(fEvt["mT_ZZ"], weight);
        H1["JET_ee_mTZZ"].Fill(fEvt["mT_ZZ"], weight);
    }
            
    if(region==EM::_VBF_EE){
        H2["onshell_ee"].Fill(fEvt["lepplus_pt"], fabs(fEvt["lepplus_eta"]), weight);
        H2["onshell_ee"].Fill(fEvt["lepminus_pt"], fabs(fEvt["lepminus_eta"]), weight);
        H1["ggF_ee_mTZZ"].Fill(fEvt["mT_ZZ"], weight);
        H1["JET_ee_mTZZ"].Fill(fEvt["mT_ZZ"], weight);
        H1["VBF_ee_mTZZ"].Fill(fEvt["mT_ZZ"], weight);
    }

    if (region==EM::_ONSHELL_MM){
        H2["onshell_mm"].Fill(fEvt["lepplus_pt"], fabs(fEvt["lepplus_eta"]), weight);
        H2["onshell_mm"].Fill(fEvt["lepminus_pt"], fabs(fEvt["lepminus_eta"]), weight);
    }

    if(region==EM::_GGF_MM){
        H2["onshell_mm"].Fill(fEvt["lepplus_pt"], fabs(fEvt["lepplus_eta"]), weight);
        H2["onshell_mm"].Fill(fEvt["lepminus_pt"], fabs(fEvt["lepminus_eta"]), weight);
        H1["ggF_mm_mTZZ"].Fill(fEvt["mT_ZZ"], weight);
    }
            
    if(region==EM::_JET_MM){
        H2["onshell_mm"].Fill(fEvt["lepplus_pt"], fabs(fEvt["lepplus_eta"]), weight);
        H2["onshell_mm"].Fill(fEvt["lepminus_pt"], fabs(fEvt["lepminus_eta"]), weight);
        H1["ggF_mm_mTZZ"].Fill(fEvt["mT_ZZ"], weight);
        H1["JET_mm_mTZZ"].Fill(fEvt["mT_ZZ"], weight);
    }
            
    if(region==EM::_VBF_MM){
        H2["onshell_mm"].Fill(fEvt["lepplus_pt"], fabs(fEvt["lepplus_eta"]), weight);
        H2["onshell_mm"].Fill(fEvt["lepminus_pt"], fabs(fEvt["lepminus_eta"]), weight);
        H1["ggF_mm_mTZZ"].Fill(fEvt["mT_ZZ"], weight);
        H1["JET_mm_mTZZ"].Fill(fEvt["mT_ZZ"], weight);
        H1["VBF_mm_mTZZ"].Fill(fEvt["mT_ZZ"], weight);
    }


    if(region==EM::_GGF_EM){
        if (fEvt["leading_pT_lepton"]==fEvt["lepplus_pt"]){
            H3["ggF_e_pt_eta_mTZZ"].Fill(fEvt["lepplus_pt"], fabs(fEvt["lepplus_eta"]), fEvt["mT_ZZ"], weight);
            H3["ggF_m_pt_eta_mTZZ"].Fill(fEvt["lepminus_pt"], fabs(fEvt["lepminus_eta"]), fEvt["mT_ZZ"], weight);
        }
        else{
            H3["ggF_m_pt_eta_mTZZ"].Fill(fEvt["lepplus_pt"], fabs(fEvt["lepplus_eta"]), fEvt["mT_ZZ"], weight);
            H3["ggF_e_pt_eta_mTZZ"].Fill(fEvt["lepminus_pt"], fabs(fEvt["lepminus_eta"]), fEvt["mT_ZZ"], weight);
        }
        H1["onshell_em_mTZZ"].Fill(fEvt["mT_ZZ"], weight);
        //printf("%f\n", weight);
        H1["ggF_em_mTZZ"].Fill(fEvt["mT_ZZ"], weight);
    }
            
    if(region==EM::_JET_EM){
        if (fEvt["leading_pT_lepton"]==fEvt["lepplus_pt"]){
            H3["ggF_e_pt_eta_mTZZ"].Fill(fEvt["lepplus_pt"], fabs(fEvt["lepplus_eta"]), fEvt["mT_ZZ"], weight);
            H3["ggF_m_pt_eta_mTZZ"].Fill(fEvt["lepminus_pt"], fabs(fEvt["lepminus_eta"]), fEvt["mT_ZZ"], weight);
            H3["JET_e_pt_eta_mTZZ"].Fill(fEvt["lepplus_pt"], fabs(fEvt["lepplus_eta"]), fEvt["mT_ZZ"], weight);
            H3["JET_m_pt_eta_mTZZ"].Fill(fEvt["lepminus_pt"], fabs(fEvt["lepminus_eta"]), fEvt["mT_ZZ"], weight);
        }
        else{
            H3["ggF_m_pt_eta_mTZZ"].Fill(fEvt["lepplus_pt"], fabs(fEvt["lepplus_eta"]), fEvt["mT_ZZ"], weight);
            H3["ggF_e_pt_eta_mTZZ"].Fill(fEvt["lepminus_pt"], fabs(fEvt["lepminus_eta"]), fEvt["mT_ZZ"], weight);
            H3["JET_m_pt_eta_mTZZ"].Fill(fEvt["lepplus_pt"], fabs(fEvt["lepplus_eta"]), fEvt["mT_ZZ"], weight);
            H3["JET_e_pt_eta_mTZZ"].Fill(fEvt["lepminus_pt"], fabs(fEvt["lepminus_eta"]), fEvt["mT_ZZ"], weight);
        }
        H1["onshell_em_mTZZ"].Fill(fEvt["mT_ZZ"], weight);
        H1["ggF_em_mTZZ"].Fill(fEvt["mT_ZZ"], weight);
        //printf("%f\n", weight);
        H1["JET_em_mTZZ"].Fill(fEvt["mT_ZZ"], weight);
    }
            
    if(region==EM::_VBF_EM){
        if (fEvt["leading_pT_lepton"]==fEvt["lepplus_pt"]){
            H3["ggF_e_pt_eta_mTZZ"].Fill(fEvt["lepplus_pt"], fabs(fEvt["lepplus_eta"]), fEvt["mT_ZZ"], weight);
            H3["ggF_m_pt_eta_mTZZ"].Fill(fEvt["lepminus_pt"], fabs(fEvt["lepminus_eta"]), fEvt["mT_ZZ"], weight);
            H3["JET_e_pt_eta_mTZZ"].Fill(fEvt["lepplus_pt"], fabs(fEvt["lepplus_eta"]), fEvt["mT_ZZ"], weight);
            H3["JET_m_pt_eta_mTZZ"].Fill(fEvt["lepminus_pt"], fabs(fEvt["lepminus_eta"]), fEvt["mT_ZZ"], weight);
            H3["VBF_e_pt_eta_mTZZ"].Fill(fEvt["lepplus_pt"], fabs(fEvt["lepplus_eta"]), fEvt["mT_ZZ"], weight);
            H3["VBF_m_pt_eta_mTZZ"].Fill(fEvt["lepminus_pt"], fabs(fEvt["lepminus_eta"]), fEvt["mT_ZZ"], weight);
        }
        else{
            H3["ggF_m_pt_eta_mTZZ"].Fill(fEvt["lepplus_pt"], fabs(fEvt["lepplus_eta"]), fEvt["mT_ZZ"], weight);
            H3["ggF_e_pt_eta_mTZZ"].Fill(fEvt["lepminus_pt"], fabs(fEvt["lepminus_eta"]), fEvt["mT_ZZ"], weight);
            H3["JET_m_pt_eta_mTZZ"].Fill(fEvt["lepplus_pt"], fabs(fEvt["lepplus_eta"]), fEvt["mT_ZZ"], weight);
            H3["JET_e_pt_eta_mTZZ"].Fill(fEvt["lepminus_pt"], fabs(fEvt["lepminus_eta"]), fEvt["mT_ZZ"], weight);
            H3["VBF_m_pt_eta_mTZZ"].Fill(fEvt["lepplus_pt"], fabs(fEvt["lepplus_eta"]), fEvt["mT_ZZ"], weight);
            H3["VBF_e_pt_eta_mTZZ"].Fill(fEvt["lepminus_pt"], fabs(fEvt["lepminus_eta"]), fEvt["mT_ZZ"], weight);
        }
        H1["onshell_em_mTZZ"].Fill(fEvt["mT_ZZ"], weight);
        H1["ggF_em_mTZZ"].Fill(fEvt["mT_ZZ"], weight);
        //printf("%f\n", weight);
        H1["JET_em_mTZZ"].Fill(fEvt["mT_ZZ"], weight);
        H1["VBF_em_mTZZ"].Fill(fEvt["mT_ZZ"], weight);
    }
}
