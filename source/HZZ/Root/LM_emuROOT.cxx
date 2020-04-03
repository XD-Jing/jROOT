#define HZZ_LM_emuROOT_cxx
#include "HZZ/LM_emuROOT.h"
#include "HZZ/regions.h"
#include <TH1F.h>
#include <TStyle.h>
#include <TCanvas.h>


LM_emuROOT::LM_emuROOT(std::string treename, std::string outfile, std::string outopt, std::string tag)
: tree(0), treename(treename)
{
    inVarF = {
         "M2Lep"     , "leading_jet_pt" , "second_jet_pt" , "dLepR"   , "met_tst"       ,
        "met_signif"  , "mjj"            , "detajj"        , "dMetZPhi", "dPhiJ100met", 
        "lepplus_pt", "lepplus_eta", "lepminus_pt", "lepminus_eta",
        "mT_ZZ", "lepplus_m", "lepminus_m"
    };
    inVarI = {
        "event_type" , "event_3CR"      , "n_jets"        , "n_bjets"
    };
    onVarF = {
        "muon_eta", "muon_pt", "electron_eta", "electron_pt", "MET"
    };
    mcVarF = {"weight_trig", "weight"};

    for (auto v: onVarF)    fEvt[v] = -999999;
    for (auto v: inVarV)    { BrEvt[v] = new TBranch(); vEvt[v] = new std::vector<float>(); }
    for (auto v: inVarF)    { BrEvt[v] = new TBranch(); fEvt[v] = -999999; }
    for (auto v: inVarI)    { BrEvt[v] = new TBranch(); iEvt[v] = -999999; }
    for (auto v: mcVarF)    { BrEvt[v] = new TBranch(); fEvt[v] = -999999; }

    H1.clear(); H2.clear(); H3.clear();
    mkHist(tag);

    fout = new TFile(outfile.c_str(), outopt.c_str());

    reader = new TMVA::Reader( "Silent" );
    std::vector<std::string> fMVA= {
        "Z_eta", "mT_ZZ", "dLepR", "dMetZPhi", "met_signif",
        "frac_pT", "MetOHT", "met_tst", "mT_Hinv", "M2Lep",
        "sumpT_scalar", "dLepEta", "dLepPhi"};
    std::vector<std::string> iMVA= {"event_3CR", "n_bjets", "event_type"};
    reader->AddVariable("Z_eta", &fEvt["Z_eta"]);
    reader->AddVariable("dLepR", &fEvt["dLepR"]);
    reader->AddVariable("dMetZPhi", &fEvt["dMetZPhi"]);
    reader->AddVariable("met_signif", &fEvt["met_signif"]);
    reader->AddVariable("frac_pT", &fEvt["frac_pT"]);
    reader->AddVariable("MetOHT", &fEvt["MetOHT"]);
    reader->AddVariable("M2Lep", &fEvt["M2Lep"]);
    reader->AddVariable("sumpT_scalar", &fEvt["sumpT_scalar"]);
    for (auto v: iMVA) reader->AddSpectator(v, &fEvt[v]);
    reader->BookMVA( "BDTG", "/afs/cern.ch/work/l/liji/public/jROOT/source/HZZ/marco/hinvzll/BDTget/weights/TMVAClassification_BDTG.weights.xml");
}

LM_emuROOT::~LM_emuROOT(){
}

void LM_emuROOT::Close(){
    fout->cd();
    for (auto h : H3) h.second->Write();
    for (auto h : H2) h.second->Write();
    for (auto h : H1) h.second->Write();
    fout->Close();
}

bool LM_emuROOT::LoopROOT(std::string filename, double factor, std::string treename){
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

    //printf(" %20.10f     reading... %s\n", this->xsec, filename.c_str());
    printf("    reading... %s\n", filename.c_str());

    for (auto varname: inVarI) tree->SetBranchAddress(varname.c_str(), &iEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    for (auto varname: inVarF) tree->SetBranchAddress(varname.c_str(), &fEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    for (auto varname: inVarV) tree->SetBranchAddress(varname.c_str(), &vEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    if (this->isMC) for (auto varname: mcVarF) tree->SetBranchAddress(varname.c_str(), &fEvt[varname.c_str()], &BrEvt[varname.c_str()]);

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


bool LM_emuROOT::mkHist(std::string tag){

    H2["ggF_e_pt_eta_MET"] = new TH2D( (tag+"_ggF_E_PT_ETA_MET").c_str(), "", 9, 0, 9, 1000, 0, 1000);
    H2["ggF_m_pt_eta_MET"] = new TH2D( (tag+"_ggF_M_PT_ETA_MET").c_str(), "", 9, 0, 9, 1000, 0, 1000);


    H1["onshell_ee"] = new TH1D( (tag+"_onshell_EE").c_str(),  "", 9, 0, 9);
    H1["onshell_mm"] = new TH1D( (tag+"_onshell_MM").c_str(),  "", 9, 0, 9);

    H1["ggF_ee_MET"] = new TH1D( (tag+"_ggF_EE_MET").c_str(), "", 1000, 0, 1000);
    H1["ggF_mm_MET"] = new TH1D( (tag+"_ggF_MM_MET").c_str(), "", 1000, 0, 1000);
    H1["ggF_em_MET"] = new TH1D( (tag+"_ggF_EM_MET").c_str(), "", 1000, 0, 1000);
    H1["onshell_em_MET"] = new TH1D( (tag+"_onshell_EM_MET").c_str(), "", 1000, 0, 1000);

    H2["ggF_e_pt_eta_BDT"] = new TH2D( (tag+"_ggF_E_PT_ETA_BDT").c_str(), "", 9, 0, 9, 20, -1, 1);
    H2["ggF_m_pt_eta_BDT"] = new TH2D( (tag+"_ggF_M_PT_ETA_BDT").c_str(), "", 9, 0, 9, 20, -1, 1);
    H1["ggF_ee_BDT"] = new TH1D( (tag+"_ggF_EE_BDT").c_str(), "", 20, -1, 1);
    H1["ggF_mm_BDT"] = new TH1D( (tag+"_ggF_MM_BDT").c_str(), "", 20, -1, 1);
    H1["ggF_em_BDT"] = new TH1D( (tag+"_ggF_EM_BDT").c_str(), "", 20, -1, 1);
    H1["onshell_em_BDT"] = new TH1D( (tag+"_onshell_EM_BDT").c_str(), "", 20, -1, 1);
    return true;
}


int LM_emuROOT::Cut()
{

    fEvt["MET"] = fEvt["met_tst"];
    if (fEvt["lepplus_m"]>fEvt["lepminus_m"]){
        fEvt["muon_eta"] = fEvt["lepplus_eta"];
        fEvt["muon_pt" ] = fEvt["lepplus_pt" ];
        fEvt["electron_eta"] = fEvt["lepminus_eta"];
        fEvt["electron_pt" ] = fEvt["lepminus_pt" ];
    }else{
        fEvt["electron_eta"] = fEvt["lepplus_eta"];
        fEvt["electron_pt" ] = fEvt["lepplus_pt" ];
        fEvt["muon_eta"] = fEvt["lepminus_eta"];
        fEvt["muon_pt" ] = fEvt["lepminus_pt" ];
    }
    if (iEvt["event_3CR"]!=0)                     return EM::_NONE;
    if (!(fEvt["M2Lep"]>76 && fEvt["M2Lep"]<106)) return EM::_NONE;
    int channel = 0;
    if (iEvt["event_type"]==1)      channel = EM::_ONSHELL_EE;
    else if (iEvt["event_type"]==0) channel = EM::_ONSHELL_MM;
    else if (iEvt["event_type"]==2) channel = EM::_ONSHELL_EM;
    if (fEvt["met_tst"]<=90)                      return channel;
    if (iEvt["n_bjets"]!=0)                       return channel;
    if (fabs(fEvt["dLepR"])>=1.8)                 return channel;
    if (fEvt["met_signif"]<=9)                    return channel;
    channel += 3;
    return channel;
}

void LM_emuROOT::LoopEVT(int region)
{
    double weight;
    if (this->isMC) weight = fEvt["weight"] * this->xsec;
    else weight = this->xsec;
    fEvt["BDT"] = reader->EvaluateMVA("BDTG");

    // default 
    std::vector<double> ptMins  = {20, 45,  55,   20,   45,   55,   20,   45,   55};
    std::vector<double> ptMaxs  = {45, 55, 9e9,   45,   55,  9e9,   45,   55,  9e9};
    std::vector<double> etaMins = { 0,  0,   0,    1,    1,    1, 1.37, 1.37, 1.37};
    std::vector<double> etaMaxs = { 1,  1,   1, 1.37, 1.37, 1.37,  2.5,  2.5,  2.5};

    // Bin1
    //std::vector<double> ptMins  = {20, 40,  50,   20,   40,   50,   20,   40,   50};
    //std::vector<double> ptMaxs  = {40, 50, 9e9,   40,   50,  9e9,   40,   50,  9e9};
    //std::vector<double> etaMins = { 0,  0,   0,    1,    1,    1, 1.37, 1.37, 1.37};
    //std::vector<double> etaMaxs = { 1,  1,   1, 1.37, 1.37, 1.37,  2.5,  2.5,  2.5};

    // Bin2
    //std::vector<double> ptMins  = {20, 50,  60,   20,   50,   60,   20,   50,   60};
    //std::vector<double> ptMaxs  = {50, 60, 9e9,   50,   60,  9e9,   50,   60,  9e9};
    //std::vector<double> etaMins = { 0,  0,   0,    1,    1,    1, 1.37, 1.37, 1.37};
    //std::vector<double> etaMaxs = { 1,  1,   1, 1.37, 1.37, 1.37,  2.5,  2.5,  2.5};

    // Bin3
    //std::vector<double> ptMins  = {20, 45,  55,   20,   45,   55,   20,   45,   55};
    //std::vector<double> ptMaxs  = {45, 55, 9e9,   45,   55,  9e9,   45,   55,  9e9};
    //std::vector<double> etaMins = { 0,  0,   0,    1,    1,    1, 1.27, 1.27, 1.27};
    //std::vector<double> etaMaxs = { 1,  1,   1, 1.27, 1.27, 1.27,  2.5,  2.5,  2.5};

    // Bin4
    //std::vector<double> ptMins  = {20, 45,  55,   20,   45,   55,   20,   45,   55};
    //std::vector<double> ptMaxs  = {45, 55, 9e9,   45,   55,  9e9,   45,   55,  9e9};
    //std::vector<double> etaMins = { 0,  0,   0,    1,    1,    1, 1.47, 1.47, 1.47};
    //std::vector<double> etaMaxs = { 1,  1,   1, 1.47, 1.47, 1.47,  2.5,  2.5,  2.5};

    if (region==EM::_ONSHELL_EE){
        for (int i=0; i<9; i++) {
            if( fabs(fEvt["lepplus_eta"])<etaMaxs[i] && fabs(fEvt["lepplus_eta"])>etaMins[i] &&
                    fabs(fEvt["lepminus_eta"])<etaMaxs[i] && fabs(fEvt["lepminus_eta"])>etaMins[i] &&
                    fEvt["lepplus_pt"]<ptMaxs[i] && fEvt["lepplus_pt"]>ptMins[i] &&
                    fEvt["lepminus_pt"]<ptMaxs[i] && fEvt["lepminus_pt"]>ptMins[i]){
                H1["onshell_ee"]->Fill(i, weight);
            }
        }
    }

    if(region==EM::_GGF_EE){
        for (int i=0; i<9; i++) {
            if( fabs(fEvt["lepplus_eta"])<etaMaxs[i] && fabs(fEvt["lepplus_eta"])>etaMins[i] &&
                    fabs(fEvt["lepminus_eta"])<etaMaxs[i] && fabs(fEvt["lepminus_eta"])>etaMins[i] &&
                    fEvt["lepplus_pt"]<ptMaxs[i] && fEvt["lepplus_pt"]>ptMins[i] &&
                    fEvt["lepminus_pt"]<ptMaxs[i] && fEvt["lepminus_pt"]>ptMins[i]){
                H1["onshell_ee"]->Fill(i, weight);
            }
        }
        H1["ggF_ee_MET"]->Fill(fEvt["MET"], weight);
        H1["ggF_ee_BDT"]->Fill(fEvt["BDT"], weight);
    }
            

    if (region==EM::_ONSHELL_MM){
        for (int i=0; i<9; i++) {
            if( fabs(fEvt["lepplus_eta"])<etaMaxs[i] && fabs(fEvt["lepplus_eta"])>etaMins[i] &&
                    fabs(fEvt["lepminus_eta"])<etaMaxs[i] && fabs(fEvt["lepminus_eta"])>etaMins[i] &&
                    fEvt["lepplus_pt"]<ptMaxs[i] && fEvt["lepplus_pt"]>ptMins[i] &&
                    fEvt["lepminus_pt"]<ptMaxs[i] && fEvt["lepminus_pt"]>ptMins[i]){
                H1["onshell_mm"]->Fill(i, weight);
            }
        }
    }

    if(region==EM::_GGF_MM){
        for (int i=0; i<9; i++) {
            if( fabs(fEvt["lepplus_eta"])<etaMaxs[i] && fabs(fEvt["lepplus_eta"])>etaMins[i] &&
                    fabs(fEvt["lepminus_eta"])<etaMaxs[i] && fabs(fEvt["lepminus_eta"])>etaMins[i] &&
                    fEvt["lepplus_pt"]<ptMaxs[i] && fEvt["lepplus_pt"]>ptMins[i] &&
                    fEvt["lepminus_pt"]<ptMaxs[i] && fEvt["lepminus_pt"]>ptMins[i]){
                H1["onshell_mm"]->Fill(i, weight);
            }
        }
        H1["ggF_mm_MET"]->Fill(fEvt["MET"], weight);
        H1["ggF_mm_BDT"]->Fill(fEvt["BDT"], weight);
    }
            
            
    if (this->isMC && (region==EM::_GGF_EM || region==EM::_JET_EM || region==EM::_VBF_EM)) weight *= 1./fEvt["weight_trig"];

    if(region==EM::_GGF_EM){
        for (int i=0; i<9; i++) {
            if( fabs(fEvt["electron_eta"])<etaMaxs[i] && fabs(fEvt["electron_eta"])>etaMins[i] &&
                    fEvt["electron_pt"]<ptMaxs[i] && fEvt["electron_pt"]>ptMins[i]){
                H2["ggF_e_pt_eta_MET"]->Fill(i, fEvt["MET"], weight);
                H2["ggF_e_pt_eta_BDT"]->Fill(i, fEvt["BDT"], weight);
            }
            if( fabs(fEvt["muon_eta"])<etaMaxs[i] && fabs(fEvt["muon_eta"])>etaMins[i] &&
                    fEvt["muon_pt"]<ptMaxs[i] && fEvt["muon_pt"]>ptMins[i]){
                H2["ggF_m_pt_eta_MET"]->Fill(i, fEvt["MET"], weight);
                H2["ggF_m_pt_eta_BDT"]->Fill(i, fEvt["BDT"], weight);
            }
        }
        H1["onshell_em_MET"]->Fill(fEvt["MET"], weight);
        H1["ggF_em_MET"]->Fill(fEvt["MET"], weight);
        H1["onshell_em_BDT"]->Fill(fEvt["BDT"], weight);
        H1["ggF_em_BDT"]->Fill(fEvt["BDT"], weight);
    }
            
}
