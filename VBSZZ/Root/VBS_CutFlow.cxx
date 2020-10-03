#define VBS_CutFlow_cxx
#include "VBSZZ/VBS_CutFlow.h"
#include "VBSZZ/regions.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>


    VBS_CutFlow::VBS_CutFlow(std::string treename, std::string outfile, std::string outopt, bool THEO, bool SYST)
: tree(0), treename(treename), SYST(SYST), THEO(THEO)
{
    std::cout << treename << std::endl;

    inVarF = {
        "leading_pT_lepton", "subleading_pT_lepton",
        "lepplus_pt", "lepminus_pt",
        "lepplus_eta", "lepminus_eta",
        "lepplus_phi", "lepminus_phi",
        "leading_jet_pt", "second_jet_pt",
        "leading_jet_eta", "second_jet_eta",
        "leading_jet_rapidity", "second_jet_rapidity",
        "M2Lep", "mjj", "dLepR", "met_tst", "met_signi",
        "sumpT_scalar",
        "weight",
    };
    inVarI = {
        "event_type", "event_3CR", "n_bjets", "n_jets"
    };
    onVarF = {
        "nJet", "HT",
        "PtL1", "PtL2", "PtJ1", "PtJ2",
        "EtaL1", "EtaL2", "EtaJ1", "EtaJ2",
        "MET", "METS", "M2L", 
        "dLepEta", "dLepPhi", "dYJJ", "J1xJ2",
    };

    inVarTHEO.clear();
    //if (THEO){
    //    inVarTHEO["QCD55"] = "weight_var_th_MUR0p5_MUF0p5_PDF261000";
    //    inVarTHEO["QCD51"] = "weight_var_th_MUR0p5_MUF1_PDF261000";
    //    inVarTHEO["QCD15"] = "weight_var_th_MUR1_MUF0p5_PDF261000";
    //    inVarTHEO["QCD12"] = "weight_var_th_MUR1_MUF2_PDF261000";
    //    inVarTHEO["QCD21"] = "weight_var_th_MUR2_MUF1_PDF261000";
    //    inVarTHEO["QCD22"] = "weight_var_th_MUR2_MUF2_PDF261000";
    //    for (int i =0; i<=100; i++){
    //        inVarTHEO["PDF"+std::to_string(i)] = "weight_var_th_MUR1_MUF1_PDF"+std::to_string(i+261000);
    //    }
    //}

    inVarSYST.clear();
    //if (SYST){
    //    inVarSYST["EL_EFF_ID_CorrUncertaintyNP0__1down" ] = "weight_EL_EFF_ID_CorrUncertaintyNP0__1down";
    //}

    for (auto v: onVarF)    fEvt[v] = -999999;
    for (auto v: inVarF)    { BrEvt[v] = new TBranch(); fEvt[v] = -999999; }
    for (auto v: inVarI)    { BrEvt[v] = new TBranch(); iEvt[v] = -999999; }
    for (auto v: inVarTHEO) { BrEvt[v.second] = new TBranch(); fEvt[v.second] = -999999; }
    for (auto v: inVarSYST) { BrEvt[v.second] = new TBranch(); fEvt[v.second] = -999999; }

    mkHist();

    fout = new TFile(outfile.c_str(), outopt.c_str());

    //reader = new TMVA::Reader( "V:Color" );
    reader = new TMVA::Reader( "Silent" );
    reader->AddVariable("leading_pT_lepton"      , &fEvt["PtL1"]);
    reader->AddVariable("subleading_pT_lepton"   , &fEvt["PtL2"]);
    reader->AddVariable("leading_jet_pt"         , &fEvt["PtJ1"]);
    reader->AddVariable("second_jet_pt"          , &fEvt["PtJ2"]);
    reader->AddVariable("met_tst"                , &fEvt["MET"]);
    reader->AddVariable("M2Lep"                  , &fEvt["M2Lep"]);
    reader->AddVariable("dLepR"                  , &fEvt["dLepR"]);
    reader->AddVariable("dLepPhi"                , &fEvt["dLepPhi"]);
    reader->AddVariable("dLepEta"                , &fEvt["dLepEta"]);
    reader->AddVariable("mjj"                    , &fEvt["MJJ"]);
    reader->AddVariable("dYJJ"                   , &fEvt["dYJJ"]);
    reader->AddVariable("sumpT_scalar"           , &fEvt["HT"]);
    reader->AddVariable("met_signi"              , &fEvt["METS"]);
    reader->AddVariable("j1timej2Rap"            , &fEvt["J1xJ2"]);

    reader->AddSpectator("weight"                , &fEvt["weight"]);
    reader->BookMVA( "BDTG", "/atlas/data19/liji/jROOT/VBSZZ/marco/VBS_BDTG.weights.xml");
}

VBS_CutFlow::~VBS_CutFlow(){
    for (auto h : hist_Zmass_llvv)  delete h.second;
    for (auto h : hist_Zmass_eevv)  delete h.second;
    for (auto h : hist_Zmass_mmvv)  delete h.second;
    for (auto h : hist_Zmass_emvv)  delete h.second;
    for (auto h : hist_MET_llvv)  delete h.second;
    for (auto h : hist_MET_eevv)  delete h.second;
    for (auto h : hist_MET_mmvv)  delete h.second;
    for (auto h : hist_MET_emvv)  delete h.second;
    for (auto h : hist_2lSR_llvv)  delete h.second;
    for (auto h : hist_2lSR_eevv)  delete h.second;
    for (auto h : hist_2lSR_mmvv)  delete h.second;
    for (auto h : hist_2lCR_llvv)  delete h.second;
    for (auto h : hist_2lCR_eevv)  delete h.second;
    for (auto h : hist_2lCR_mmvv)  delete h.second;
    for (auto h : hist_2lCR_emvv)  delete h.second;
}

void VBS_CutFlow::Close(){
    fout->cd();
    for (auto h : hist_Zmass_llvv)  h.second->Write();
    for (auto h : hist_Zmass_eevv)  h.second->Write();
    for (auto h : hist_Zmass_mmvv)  h.second->Write();
    for (auto h : hist_Zmass_emvv)  h.second->Write();
    for (auto h : hist_2Jet_llvv)  h.second->Write();
    for (auto h : hist_2Jet_eevv)  h.second->Write();
    for (auto h : hist_2Jet_mmvv)  h.second->Write();
    for (auto h : hist_2Jet_emvv)  h.second->Write();
    for (auto h : hist_MET_llvv)  h.second->Write();
    for (auto h : hist_MET_eevv)  h.second->Write();
    for (auto h : hist_MET_mmvv)  h.second->Write();
    for (auto h : hist_MET_emvv)  h.second->Write();
    for (auto h : hist_2lSR_llvv)  h.second->Write();
    for (auto h : hist_2lSR_eevv)  h.second->Write();
    for (auto h : hist_2lSR_mmvv)  h.second->Write();
    for (auto h : hist_2lCR_llvv)  h.second->Write();
    for (auto h : hist_2lCR_eevv)  h.second->Write();
    for (auto h : hist_2lCR_mmvv)  h.second->Write();
    for (auto h : hist_2lCR_emvv)  h.second->Write();
    fout->Close();
}


bool VBS_CutFlow::LoopROOT(std::string filename, std::string treename, float factor){
    TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(filename.c_str());
    if (!f || !f->IsOpen()) f = new TFile(filename.c_str(), "read");
    f->GetObject(treename.c_str(), this->tree);

    std::cout << "      reading... " << filename << std::endl;

    if (filename.find("data") != std::string::npos) this->xsec = factor;
    else{
        hInfo = (TH1F*)f->Get("hInfo");
        this->xsec = hInfo->GetBinContent(1) * 2.0 / hInfo->GetEntries() / hInfo->GetBinContent(2) * factor;
        if (filename.find("r9364")  != std::string::npos) this->xsec *= (3.21956 + 32.9653);
        if (filename.find("r10201") != std::string::npos) this->xsec *= 44.3074;
        if (filename.find("r10724") != std::string::npos) this->xsec *= 58.4501;
    }


    for (auto varname: inVarI) tree->SetBranchAddress(varname.c_str(), &iEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    for (auto varname: inVarF) tree->SetBranchAddress(varname.c_str(), &fEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    for (auto varname: inVarTHEO) tree->SetBranchAddress(varname.second.c_str(), &fEvt[varname.second.c_str()], &BrEvt[varname.second.c_str()]);
    for (auto varname: inVarSYST) tree->SetBranchAddress(varname.second.c_str(), &fEvt[varname.second.c_str()], &BrEvt[varname.second.c_str()]);

    Long64_t nentries = tree->GetEntriesFast();
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
        tree->GetEntry(jentry);
        int region = Cut();
        if (region == RG_CutFlow::_NONE) continue;
        LoopEVT(region);
    }

    f->Close();
    return true;
}


bool VBS_CutFlow::mkHist(){
    mkHistVar("M2L", 600, 60, 120);
    mkHistVar("METS", 50, 0, 50);
    mkHistVar("MET", 1500, 0, 1500);

    mkHistVar("PtL1", 1000, 0, 1000);
    mkHistVar("PtL2", 1000, 0, 1000);
    mkHistVar("PtJ1", 1000, 0, 1000);
    mkHistVar("PtJ2", 1000, 0, 1000);
    mkHistVar("EtaL1", 200, -10, 10);
    mkHistVar("EtaL2", 200, -10, 10);
    mkHistVar("EtaJ1", 200, -10, 10);
    mkHistVar("EtaJ2", 200, -10, 10);
    //mkHistVar("PhiL1", 200, -10, 10);
    //mkHistVar("PhiL2", 200, -10, 10);
    //mkHistVar("PhiJ1", 200, -10, 10);
    //mkHistVar("PhiJ2", 200, -10, 10);

    mkHistVar("dLepR", 200, 0, 20);
    mkHistVar("dLepEta", 200, 0, 20);
    mkHistVar("dLepPhi", 200, 0, 20);

    mkHistVar("MJJ", 5000, 0, 5000);
    mkHistVar("dYJJ", 200, 0, 20);
    mkHistVar("J1xJ2", 1000, -50, 50);
    mkHistVar("nJet", 30, 0, 30);
    mkHistVar("HT", 5000, 0, 5000);
    mkHistVar("BDT", 40, -1, 1);
    return true;
}


bool VBS_CutFlow::mkHistVar(std::string var, int nbins, double left, double right){
    histVars.push_back(var);
    hist_Zmass_llvv[std::make_pair(this->treename, var )] = new TH1F(("llvv__Zmass__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    hist_Zmass_eevv[std::make_pair(this->treename, var )] = new TH1F(("eevv__Zmass__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    hist_Zmass_mmvv[std::make_pair(this->treename, var )] = new TH1F(("mmvv__Zmass__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    hist_Zmass_emvv[std::make_pair(this->treename, var )] = new TH1F(("emvv__Zmass__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    hist_2Jet_llvv[std::make_pair(this->treename, var )] = new TH1F(("llvv__2Jet__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    hist_2Jet_eevv[std::make_pair(this->treename, var )] = new TH1F(("eevv__2Jet__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    hist_2Jet_mmvv[std::make_pair(this->treename, var )] = new TH1F(("mmvv__2Jet__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    hist_2Jet_emvv[std::make_pair(this->treename, var )] = new TH1F(("emvv__2Jet__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    hist_MET_llvv[std::make_pair(this->treename, var )] = new TH1F(("llvv__MET__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    hist_MET_eevv[std::make_pair(this->treename, var )] = new TH1F(("eevv__MET__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    hist_MET_mmvv[std::make_pair(this->treename, var )] = new TH1F(("mmvv__MET__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    hist_MET_emvv[std::make_pair(this->treename, var )] = new TH1F(("emvv__MET__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    hist_2lSR_llvv[std::make_pair(this->treename, var )] = new TH1F(("llvv__2lSR__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    hist_2lSR_eevv[std::make_pair(this->treename, var )] = new TH1F(("eevv__2lSR__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    hist_2lSR_mmvv[std::make_pair(this->treename, var )] = new TH1F(("mmvv__2lSR__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    hist_2lCR_llvv[std::make_pair(this->treename, var )] = new TH1F(("llvv__2lCR__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    hist_2lCR_eevv[std::make_pair(this->treename, var )] = new TH1F(("eevv__2lCR__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    hist_2lCR_mmvv[std::make_pair(this->treename, var )] = new TH1F(("mmvv__2lCR__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    hist_2lCR_emvv[std::make_pair(this->treename, var )] = new TH1F(("emvv__2lCR__"+var+"__"+this->treename).c_str(), "", nbins, left, right);

    return true;
}

int VBS_CutFlow::Cut()
{

    fEvt["event_type"] = iEvt["event_type"];
    fEvt["event_3CR"] = iEvt["event_3CR"];
    fEvt["PtL1"] = fEvt["lepplus_pt"] > fEvt["lepminus_pt"]?  fEvt["lepplus_pt"]:fEvt["lepminus_pt"];
    fEvt["PtL2"] = fEvt["lepplus_pt"] < fEvt["lepminus_pt"]?  fEvt["lepplus_pt"]:fEvt["lepminus_pt"];
    fEvt["EtaL1"] = fEvt["lepplus_pt"] > fEvt["lepminus_pt"]?  fEvt["lepplus_eta"]:fEvt["lepminus_eta"];
    fEvt["EtaL2"] = fEvt["lepplus_pt"] < fEvt["lepminus_pt"]?  fEvt["lepplus_eta"]:fEvt["lepminus_eta"];
    fEvt["PtJ1"] = fEvt["leading_jet_pt"] ;
    fEvt["PtJ2"] = fEvt["second_jet_pt"] ;
    fEvt["EtaJ1"] = fEvt["leading_jet_eta"];
    fEvt["EtaJ2"] = fEvt["second_jet_eta"];

    fEvt["J1xJ2"] = fEvt["leading_jet_rapidity"]*fEvt["second_jet_rapidity"];
    fEvt["dYJJ"] = fabs(fEvt["leading_jet_rapidity"]-fEvt["second_jet_rapidity"]);
    fEvt["nJet"] = iEvt["n_jets"];

    if (iEvt["event_3CR"]!=0)                     return RG_CutFlow::_NONE;
    if (fEvt["PtL1"]<30)                          return RG_CutFlow::_NONE;
    if (fEvt["PtL2"]<20)                          return RG_CutFlow::_NONE;
    if (fabs(fEvt["EtaL1"])>=2.5)           return RG_CutFlow::_NONE;
    if (fabs(fEvt["EtaL2"])>=2.5)          return RG_CutFlow::_NONE;
    if (!(fEvt["M2Lep"]>76 && fEvt["M2Lep"]<106)) return RG_CutFlow::_NONE;

    if (!(fEvt["M2Lep"]>80 && fEvt["M2Lep"]<100)){
        if (iEvt["event_type"]==0)                return RG_CutFlow::_Zmass_MM;
        if (iEvt["event_type"]==1)                return RG_CutFlow::_Zmass_EE;
        if (iEvt["event_type"]==2)                return RG_CutFlow::_Zmass_EM;
    }

    if (fEvt["met_signi"]<=12){
        if (iEvt["event_type"]==0)                return RG_CutFlow::_Zmass_MM;
        if (iEvt["event_type"]==1)                return RG_CutFlow::_Zmass_EE;
        if (iEvt["event_type"]==2)                return RG_CutFlow::_Zmass_EM;
    }

    if (iEvt["n_jets"]<2){
        if (iEvt["event_type"]==0)                return RG_CutFlow::_2Jet_MM;
        if (iEvt["event_type"]==1)                return RG_CutFlow::_2Jet_EE;
        if (iEvt["event_type"]==2)                return RG_CutFlow::_2Jet_EM;
    }
    if (iEvt["n_bjets"]!=0){
        if (iEvt["event_type"]==0)                return RG_CutFlow::_MET_MM;
        if (iEvt["event_type"]==1)                return RG_CutFlow::_MET_EE;
        if (iEvt["event_type"]==2)                return RG_CutFlow::_MET_EM;
    }
    if (fabs(fEvt["EtaJ1"])>4.5 ||fabs(fEvt["EtaJ2"])>4.5 ||
            fEvt["PtJ1"]<=60 || fEvt["PtJ2"]<=40 ||
            fEvt["J1xJ2"]>=0){
        if (iEvt["event_type"]==0)                return RG_CutFlow::_MET_MM;
        if (iEvt["event_type"]==1)                return RG_CutFlow::_MET_EE;
        if (iEvt["event_type"]==2)                return RG_CutFlow::_MET_EM;
    }
    if (fEvt["mjj"]>400 && fEvt["dYJJ"]>2){
        if (iEvt["event_type"]==0)                return RG_CutFlow::_2lSR_MM;
        if (iEvt["event_type"]==1)                return RG_CutFlow::_2lSR_EE;
        if (iEvt["event_type"]==2)                return RG_CutFlow::_2lCR_EM;
    }
    if (fEvt["mjj"]<=400 && fEvt["dYJJ"]<=2){
        if (iEvt["event_type"]==0)                return RG_CutFlow::_2lCR_MM;
        if (iEvt["event_type"]==1)                return RG_CutFlow::_2lCR_EE;
    }

    if (iEvt["event_type"]==0)         return RG_CutFlow::_MET_MM;
    if (iEvt["event_type"]==1)         return RG_CutFlow::_MET_EE;
    if (iEvt["event_type"]==2)         return RG_CutFlow::_MET_EM;
}

void VBS_CutFlow::LoopEVT(int region)
{
    float sf = this->xsec * fEvt["weight"];
    fEvt["BDT"] = reader->EvaluateMVA("BDTG");
    fEvt["MET"] = fEvt["met_tst"];
    fEvt["METS"] = fEvt["met_signi"];
    fEvt["M2L"] = fEvt["M2Lep"];
    fEvt["MJJ"] = fEvt["mjj"];
    fEvt["HT"] = fEvt["sumpT_scalar"];
    fEvt["dLepEta"] = fabs(fEvt["lepplus_eta"] - fEvt["lepminus_eta"]);
    fEvt["dLepPhi"] = fabs(fEvt["lepplus_phi"] - fEvt["lepminus_phi"]);

    if (region == RG_CutFlow::_Zmass_MM){
        for (auto var: histVars) hist_Zmass_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_Zmass_mmvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
    }

    if (region == RG_CutFlow::_Zmass_EE){
        for (auto var: histVars) hist_Zmass_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_Zmass_eevv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
    }

    if (region == RG_CutFlow::_Zmass_EM){
        for (auto var: histVars) hist_Zmass_emvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
    }

    if (region == RG_CutFlow::_2Jet_MM){
        for (auto var: histVars) hist_Zmass_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_Zmass_mmvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_2Jet_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_2Jet_mmvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
    }
    if (region == RG_CutFlow::_2Jet_EE){
        for (auto var: histVars) hist_Zmass_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_Zmass_eevv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_2Jet_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_2Jet_eevv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
    }
    if (region == RG_CutFlow::_2Jet_EM){
        for (auto var: histVars) hist_Zmass_emvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_2Jet_emvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
    }

    if (region == RG_CutFlow::_MET_MM){
        for (auto var: histVars) hist_Zmass_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_Zmass_mmvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_2Jet_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_2Jet_mmvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_MET_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_MET_mmvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
    }

    if (region == RG_CutFlow::_MET_EE){
        for (auto var: histVars) hist_Zmass_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_Zmass_eevv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_2Jet_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_2Jet_eevv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_MET_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_MET_eevv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
    }

    if (region == RG_CutFlow::_MET_EM){
        for (auto var: histVars) hist_Zmass_emvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_2Jet_emvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_MET_emvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
    }

    if (region == RG_CutFlow::_2lSR_MM){
        for (auto var: histVars) hist_2lSR_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_2lSR_mmvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_Zmass_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_Zmass_mmvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_2Jet_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_2Jet_mmvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_MET_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_MET_mmvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
    }

    if (region == RG_CutFlow::_2lSR_EE){
        for (auto var: histVars) hist_2lSR_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_2lSR_eevv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_Zmass_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_Zmass_eevv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_2Jet_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_2Jet_eevv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_MET_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_MET_eevv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
    }

    if (region == RG_CutFlow::_2lCR_MM){
        for (auto var: histVars) hist_2lCR_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_2lCR_mmvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_Zmass_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_Zmass_mmvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_2Jet_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_2Jet_mmvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_MET_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_MET_mmvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
    }

    if (region == RG_CutFlow::_2lCR_EE){
        for (auto var: histVars) hist_2lCR_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_2lCR_eevv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_Zmass_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_Zmass_eevv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_2Jet_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_2Jet_eevv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_MET_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_MET_eevv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
    }

    if (region == RG_CutFlow::_2lCR_EM){
        for (auto var: histVars) hist_2lCR_emvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_Zmass_emvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_2Jet_emvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
        for (auto var: histVars) hist_MET_emvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
    }
}
