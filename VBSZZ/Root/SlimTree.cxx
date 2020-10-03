#define SlimTree_cxx
#include "VBSZZ/SlimTree.h"
#include "VBSZZ/regions.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TVector2.h>


    SlimTree::SlimTree(std::string treename, std::string outfile, std::string outopt, bool THEO, bool SYST)
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
        "lep3rd_pt",  "lep3rd_eta", "lep3rd_phi", "met_py_tst", "met_px_tst", 
        "sumpT_scalar",
        //"weight",
    };
    inVarI = {
        "event_type", "event_3CR", "n_bjets", "n_jets", "medium_3rd",

    };
    onVarF = {
        "weight", "HT",
        "PtL1", "PtL2", "PtJ1", "PtJ2",
        "EtaL1", "EtaL2", "EtaJ1", "EtaJ2",
        "MET", "METS", "M2L", "BDT", "MTW",
        "dLepEta", "dLepPhi", "dYJJ", "J1xJ2",
    };
    onVarI = {
        "nJet", "event_type", "event_3CR",     
    };
    onVarB = {
        "is2lSR", "isemCR", "is3lCR", "bVeto"
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
    
    fout = new TFile(outfile.c_str(), outopt.c_str());

    //inVarF.push_back(weightname);
    BrEvt["weight"] = new TBranch();
    fEvt["weight"] = -999999;
    for (auto v: onVarF)    { fEvt[v] = -999999;}
    for (auto v: onVarI)    { fEvt[v] = -999999;}
    for (auto v: onVarB)    { bEvt[v] = false;}
    for (auto v: inVarF)    { BrEvt[v] = new TBranch(); fEvt[v] = -999999; }
    for (auto v: inVarI)    { BrEvt[v] = new TBranch(); iEvt[v] = -999999; }
    for (auto v: inVarTHEO) { BrEvt[v.second] = new TBranch(); fEvt[v.second] = -999999; }
    for (auto v: inVarSYST) { BrEvt[v.second] = new TBranch(); fEvt[v.second] = -999999; }


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

SlimTree::~SlimTree(){
}

void SlimTree::Close(){
    fout->cd();
    //outTree->Write();
    fout->Close();
}

bool SlimTree::LoopROOT(std::string filename, std::string treename, std::string weightname, std::string outtreename, float factor){
    fout->cd();

    outTree = new TTree(outtreename.c_str(), outtreename.c_str());
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

    tree->SetBranchAddress(weightname.c_str(), &fEvt["weight"], &BrEvt["weight"]);
    for (auto varname: inVarI) tree->SetBranchAddress(varname.c_str(), &iEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    for (auto varname: inVarF) tree->SetBranchAddress(varname.c_str(), &fEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    for (auto varname: inVarTHEO) tree->SetBranchAddress(varname.second.c_str(), &fEvt[varname.second.c_str()], &BrEvt[varname.second.c_str()]);
    for (auto varname: inVarSYST) tree->SetBranchAddress(varname.second.c_str(), &fEvt[varname.second.c_str()], &BrEvt[varname.second.c_str()]);

    for (auto varname: onVarI) outTree->Branch(varname.c_str(), &iEvt[varname.c_str()], (varname+"/I").c_str());
    for (auto varname: onVarB) outTree->Branch(varname.c_str(), &bEvt[varname.c_str()], (varname+"/O").c_str());
    for (auto varname: onVarF) outTree->Branch(varname.c_str(), &fEvt[varname.c_str()], (varname+"/F").c_str());

    fEvt["xesc"] = this->xsec;
    Long64_t nentries = tree->GetEntriesFast();
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
        tree->GetEntry(jentry);

        fEvt["PtL1" ] = fEvt["lepplus_pt"] > fEvt["lepminus_pt"]? fEvt["lepplus_pt" ]:fEvt["lepminus_pt" ];
        fEvt["PtL2" ] = fEvt["lepplus_pt"] < fEvt["lepminus_pt"]? fEvt["lepplus_pt" ]:fEvt["lepminus_pt" ];
        fEvt["EtaL1"] = fEvt["lepplus_pt"] > fEvt["lepminus_pt"]? fEvt["lepplus_eta"]:fEvt["lepminus_eta"];
        fEvt["EtaL2"] = fEvt["lepplus_pt"] < fEvt["lepminus_pt"]? fEvt["lepplus_eta"]:fEvt["lepminus_eta"];
        fEvt["PtL3" ] = fEvt["lep3rd_pt" ] ;
        fEvt["EtaL3"] = fEvt["lep3rd_eta"] ;

        fEvt["PtJ1" ] = fEvt["leading_jet_pt" ];
        fEvt["PtJ2" ] = fEvt["second_jet_pt"  ];
        fEvt["EtaJ1"] = fEvt["leading_jet_eta"];
        fEvt["EtaJ2"] = fEvt["second_jet_eta" ];

        fEvt["J1xJ2"] = fEvt["leading_jet_rapidity"]*fEvt["second_jet_rapidity"];
        fEvt["dYJJ"] = fabs(fEvt["leading_jet_rapidity"]-fEvt["second_jet_rapidity"]);

        fEvt["BDT"] = reader->EvaluateMVA("BDTG");
        fEvt["MET"] = fEvt["met_tst"];
        fEvt["METS"] = fEvt["met_signi"];
        fEvt["M2L"] = fEvt["M2Lep"];
        fEvt["MJJ"] = fEvt["mjj"];
        fEvt["HT"] = fEvt["sumpT_scalar"];
        fEvt["dLepEta"] = fabs(fEvt["lepplus_eta"] - fEvt["lepminus_eta"]);
        fEvt["dLepPhi"] = fabs(fEvt["lepplus_phi"] - fEvt["lepminus_phi"]);
        fEvt["MTW"] = TMath::Sqrt( 2 * fEvt["lep3rd_pt "]* fEvt["MET"]* (1 - TMath::Cos( TVector2::Phi_mpi_pi( fEvt["lep3rd_phi"] -TMath::ATan2(fEvt["met_py_tst"], fEvt["met_px_tst"])))));
        fEvt["weight"] *= this->xsec;
        iEvt["nJet"] = iEvt["n_jets"];
        bEvt["bVeto"] = (iEvt["n_bjets"]==0);


        if (iEvt["event_3CR"]==0 &&
                fEvt["PtL1"]>30 && fabs(fEvt["EtaL1"])<2.5 &&
                fEvt["PtL2"]>20 && fabs(fEvt["EtaL2"])<2.5 && 
                fEvt["M2L"]>80 && fEvt["M2L"]<100 &&
                fEvt["METS"]>12 && 
                iEvt["nJet"]>=2 && bEvt["bVeto"] &&
                fabs(fEvt["EtaJ1"])<4.5 && fEvt["PtJ1"]>60 &&
                fabs(fEvt["EtaJ2"])<4.5 && fEvt["PtJ2"]>40 && 
                fEvt["J1xJ2"]<=0 && fEvt["dYJJ"]>2 && 
                fEvt["MJJ"]>400)
        {
            if (iEvt["event_type"]==0 || iEvt["event_type"]==1) bEvt["is2lSR"] = true;
            if (iEvt["event_type"]==2) bEvt["isemCR"] = true;
        }
        else if (iEvt["event_3CR"]<5 &&
                fEvt["PtL1"]>30 && fabs(fEvt["EtaL1"])<2.5 &&
                fEvt["PtL2"]>20 && fabs(fEvt["EtaL2"])<2.5 && 
                fEvt["PtL3"]>20 && fabs(fEvt["EtaL3"])<2.5 && 
                fEvt["M2L"]>80 && fEvt["M2L"]<100 &&
                fEvt["METS"]>3 && 
                fEvt["MTW"]>40 && 
                iEvt["medium_3rd"]==1 &&
                iEvt["nJet"]>=2 && bEvt["bVeto"] &&
                fabs(fEvt["EtaJ1"])<4.5 && fabs(fEvt["EtaJ2"])<4.5)
        {
            bEvt["is3lCR"] = true;
        }

        outTree->Fill();
    }
    f->Close();
    fout->cd();
    outTree->Write();
    return true;
}

