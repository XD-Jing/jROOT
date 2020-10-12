#define LowMassHinv_readTree_cxx
#include "LowMassHinv/readTree.h"
#include "LowMassHinv/regions.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>


    readTree::readTree(std::string outfile, std::string infile, std::string sysname, float factorSR, float factorCR)
: tree(0)
{
    //std::cout << treename << std::endl;
    this->treename = sysname;
    this->factorSR = factorSR;
    this->factorCR = factorCR;

    inVarF = {
        "M2Lep",
        "dLepR",
        "met_tst",
        "met_signif",
        "dMetZPhi",
        "frac_pT",
        "mT_Hinv",
        "sumpT_scalar", 
        "weight",
        "mT_ZZ" ,
        "Z_eta",
        "MetOHT",
        "weight_gen"
    };
    inVarI = {
        "event_type",
        "n_bjets"
    };
    onVarF = {
        "n_bjets",
        "event_type"
    };

    initWeights(infile);

    for (auto v: onVarF)    fEvt[v] = -999999;
    for (auto v: inVarF)    { BrEvt[v] = new TBranch(); fEvt[v] = -999999; }
    for (auto v: inVarI)    { BrEvt[v] = new TBranch(); iEvt[v] = -999999; }
    for (auto v: inVarTHEO) { BrEvt[v.second] = new TBranch(); fEvt[v.second] = -999999; }
    for (auto v: inVarSYST) { BrEvt[v.second] = new TBranch(); fEvt[v.second] = -999999; }

    mkHist();

    fout = new TFile(outfile.c_str(), "recreate");

    reader = new TMVA::Reader( "Silent" );
    std::vector<std::string> fMVA= {
        "Z_eta",
        "dLepR",
        "dMetZPhi",
        "met_signif",
        "frac_pT",
        "MetOHT",
        "M2Lep",
        "sumpT_scalar",
    };
    std::vector<std::string> iMVA= {
        "event_3CR",
        "n_bjets",
        "event_type"
    };
    for (auto v: fMVA) reader->AddVariable(v, &fEvt[v]);
    for (auto v: iMVA) reader->AddSpectator(v, &fEvt[v]);
    reader->BookMVA( "BDTG", "/atlas/data19/liji/jROOT/LowMassHinv/marco/hinvzll/BDTget/weights_newHinv_ewkMetOHT/TMVAClassification_BDTG.weights.xml");

    //LoopROOT(infile, "tree_PFLOW", 1);
    //LoopROOT(infile, "tree_emCR_PFLOW", 1);

    TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(infile.c_str());
    if (!f || !f->IsOpen()) f = new TFile(infile.c_str(), "read");

    //std::cout << "      reading... " << infile << std::endl;

    if (infile.find("data")==std::string::npos) {
        hInfo = (TH1F*)f->Get("hInfo");
        this->factorSR *= hInfo->GetBinContent(1) * 2.0 / hInfo->GetEntries() / hInfo->GetBinContent(2);
        this->factorCR *= hInfo->GetBinContent(1) * 2.0 / hInfo->GetEntries() / hInfo->GetBinContent(2);
        if (infile.find("r9364")  != std::string::npos) this->factorSR *= (3.21956 + 32.9653);
        if (infile.find("r10201") != std::string::npos) this->factorSR *= 44.3074;
        if (infile.find("r10724") != std::string::npos) this->factorSR *= 58.4501;
        if (infile.find("r9364")  != std::string::npos) this->factorCR *= (3.21956 + 32.9653);
        if (infile.find("r10201") != std::string::npos) this->factorCR *= 44.3074;
        if (infile.find("r10724") != std::string::npos) this->factorCR *= 58.4501;
        this->isMC = true;
    }
    else{
        this->factorSR = 1;
        this->factorCR = 1;
        this->isMC = false;
    }


    f->GetObject("tree_PFLOW", this->tree);
    for (auto varname: inVarI) tree->SetBranchAddress(varname.c_str(), &iEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    for (auto varname: inVarF) tree->SetBranchAddress(varname.c_str(), &fEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    for (auto varname: inVarTHEO) tree->SetBranchAddress(varname.second.c_str(), &fEvt[varname.second.c_str()], &BrEvt[varname.second.c_str()]);
    for (auto varname: inVarSYST) tree->SetBranchAddress(varname.second.c_str(), &fEvt[varname.second.c_str()], &BrEvt[varname.second.c_str()]);
    for (Long64_t jentry=0; jentry<tree->GetEntriesFast();jentry++) {
        tree->GetEntry(jentry);
        int region = Cut();
        if (region == RG_Hinv::_NONE) continue;
        LoopEVT(region);
    }

    f->GetObject("tree_emCR_PFLOW", this->tree);
    for (auto varname: inVarI) tree->SetBranchAddress(varname.c_str(), &iEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    for (auto varname: inVarF) tree->SetBranchAddress(varname.c_str(), &fEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    for (auto varname: inVarTHEO) tree->SetBranchAddress(varname.second.c_str(), &fEvt[varname.second.c_str()], &BrEvt[varname.second.c_str()]);
    for (auto varname: inVarSYST) tree->SetBranchAddress(varname.second.c_str(), &fEvt[varname.second.c_str()], &BrEvt[varname.second.c_str()]);
    for (Long64_t jentry=0; jentry<tree->GetEntriesFast();jentry++) {
        tree->GetEntry(jentry);
        int region = Cut();
        if (region == RG_Hinv::_NONE) continue;
        LoopEVT(region);
    }

    f->Close();
}


readTree::~readTree(){
    for (auto h : hist_llvv)  delete h.second;
    for (auto h : hist_eevv)  delete h.second;
    for (auto h : hist_mmvv)  delete h.second;
    for (auto h : hist_emvv)  delete h.second;
}

void readTree::Close(){
    fout->cd();
    for (auto h : hist_llvv)  h.second->Write();
    for (auto h : hist_eevv)  h.second->Write();
    for (auto h : hist_mmvv)  h.second->Write();
    for (auto h : hist_emvv)  h.second->Write();
    fout->Close();
}


void readTree::initWeights(std::string infile){

    inVarSYST.clear();
    inVarTHEO.clear();

    if (infile.find("PFLOW") == std::string::npos) return;

    if (infile.find("PFLOW")!=std::string::npos){
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP0__1down" ] = "weight_EL_EFF_ID_CorrUncertaintyNP0__1down";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP0__1up"   ] = "weight_EL_EFF_ID_CorrUncertaintyNP0__1up";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP10__1down"] = "weight_EL_EFF_ID_CorrUncertaintyNP10__1down";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP10__1up"  ] = "weight_EL_EFF_ID_CorrUncertaintyNP10__1up";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP11__1down"] = "weight_EL_EFF_ID_CorrUncertaintyNP11__1down";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP11__1up"  ] = "weight_EL_EFF_ID_CorrUncertaintyNP11__1up";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP12__1down"] = "weight_EL_EFF_ID_CorrUncertaintyNP12__1down";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP12__1up"  ] = "weight_EL_EFF_ID_CorrUncertaintyNP12__1up";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP13__1down"] = "weight_EL_EFF_ID_CorrUncertaintyNP13__1down";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP13__1up"  ] = "weight_EL_EFF_ID_CorrUncertaintyNP13__1up";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP14__1down"] = "weight_EL_EFF_ID_CorrUncertaintyNP14__1down";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP14__1up"  ] = "weight_EL_EFF_ID_CorrUncertaintyNP14__1up";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP15__1down"] = "weight_EL_EFF_ID_CorrUncertaintyNP15__1down";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP15__1up"  ] = "weight_EL_EFF_ID_CorrUncertaintyNP15__1up";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP1__1down" ] = "weight_EL_EFF_ID_CorrUncertaintyNP1__1down";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP1__1up"   ] = "weight_EL_EFF_ID_CorrUncertaintyNP1__1up";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP2__1down" ] = "weight_EL_EFF_ID_CorrUncertaintyNP2__1down";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP2__1up"   ] = "weight_EL_EFF_ID_CorrUncertaintyNP2__1up";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP3__1down" ] = "weight_EL_EFF_ID_CorrUncertaintyNP3__1down";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP3__1up"   ] = "weight_EL_EFF_ID_CorrUncertaintyNP3__1up";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP4__1down" ] = "weight_EL_EFF_ID_CorrUncertaintyNP4__1down";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP4__1up"   ] = "weight_EL_EFF_ID_CorrUncertaintyNP4__1up";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP5__1down" ] = "weight_EL_EFF_ID_CorrUncertaintyNP5__1down";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP5__1up"   ] = "weight_EL_EFF_ID_CorrUncertaintyNP5__1up";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP6__1down" ] = "weight_EL_EFF_ID_CorrUncertaintyNP6__1down";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP6__1up"   ] = "weight_EL_EFF_ID_CorrUncertaintyNP6__1up";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP7__1down" ] = "weight_EL_EFF_ID_CorrUncertaintyNP7__1down";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP7__1up"   ] = "weight_EL_EFF_ID_CorrUncertaintyNP7__1up";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP8__1down" ] = "weight_EL_EFF_ID_CorrUncertaintyNP8__1down";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP8__1up"   ] = "weight_EL_EFF_ID_CorrUncertaintyNP8__1up";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP9__1down" ] = "weight_EL_EFF_ID_CorrUncertaintyNP9__1down";
        inVarSYST["EL_EFF_ID_CorrUncertaintyNP9__1up"   ] = "weight_EL_EFF_ID_CorrUncertaintyNP9__1up";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP0__1down" ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP0__1down";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP0__1up"   ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP0__1up";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP10__1down"] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP10__1down";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP10__1up"  ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP10__1up";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP11__1down"] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP11__1down";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP11__1up"  ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP11__1up";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP12__1down"] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP12__1down";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP12__1up"  ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP12__1up";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP13__1down"] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP13__1down";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP13__1up"  ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP13__1up";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP14__1down"] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP14__1down";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP14__1up"  ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP14__1up";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP15__1down"] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP15__1down";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP15__1up"  ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP15__1up";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP16__1down"] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP16__1down";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP16__1up"  ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP16__1up";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP17__1down"] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP17__1down";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP17__1up"  ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP17__1up";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP1__1down" ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP1__1down";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP1__1up"   ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP1__1up";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP2__1down" ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP2__1down";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP2__1up"   ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP2__1up";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP3__1down" ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP3__1down";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP3__1up"   ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP3__1up";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP4__1down" ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP4__1down";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP4__1up"   ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP4__1up";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP5__1down" ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP5__1down";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP5__1up"   ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP5__1up";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP6__1down" ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP6__1down";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP6__1up"   ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP6__1up";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP7__1down" ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP7__1down";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP7__1up"   ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP7__1up";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP8__1down" ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP8__1down";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP8__1up"   ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP8__1up";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP9__1down" ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP9__1down";
        inVarSYST["EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP9__1up"   ] = "weight_EL_EFF_ID_SIMPLIFIED_UncorrUncertaintyNP9__1up";
        inVarSYST["EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR__1down"        ] = "weight_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR__1down";
        inVarSYST["EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR__1up"          ] = "weight_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR__1up";
        inVarSYST["EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR__1down"       ] = "weight_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR__1down";
        inVarSYST["EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR__1up"         ] = "weight_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR__1up";
        inVarSYST["EL_EFF_TriggerEff_TOTAL_1NPCOR_PLUS_UNCOR__1down" ] = "weight_EL_EFF_TriggerEff_TOTAL_1NPCOR_PLUS_UNCOR__1down";
        inVarSYST["EL_EFF_TriggerEff_TOTAL_1NPCOR_PLUS_UNCOR__1up"   ] = "weight_EL_EFF_TriggerEff_TOTAL_1NPCOR_PLUS_UNCOR__1up";
        inVarSYST["EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down"    ] = "weight_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down";
        inVarSYST["EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up"      ] = "weight_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up";
        inVarSYST["FT_EFF_B_systematics__1down"                      ] = "weight_FT_EFF_B_systematics__1down";
        inVarSYST["FT_EFF_B_systematics__1up"                        ] = "weight_FT_EFF_B_systematics__1up";
        inVarSYST["FT_EFF_C_systematics__1down"                      ] = "weight_FT_EFF_C_systematics__1down";
        inVarSYST["FT_EFF_C_systematics__1up"                        ] = "weight_FT_EFF_C_systematics__1up";
        inVarSYST["FT_EFF_Light_systematics__1down"                  ] = "weight_FT_EFF_Light_systematics__1down";
        inVarSYST["FT_EFF_Light_systematics__1up"                    ] = "weight_FT_EFF_Light_systematics__1up";
        inVarSYST["FT_EFF_extrapolation__1down"                      ] = "weight_FT_EFF_extrapolation__1down";
        inVarSYST["FT_EFF_extrapolation__1up"                        ] = "weight_FT_EFF_extrapolation__1up";
        inVarSYST["FT_EFF_extrapolation_from_charm__1down"           ] = "weight_FT_EFF_extrapolation_from_charm__1down";
        inVarSYST["FT_EFF_extrapolation_from_charm__1up"             ] = "weight_FT_EFF_extrapolation_from_charm__1up";
        inVarSYST["JET_JvtEfficiency__1down"                         ] = "weight_JET_JvtEfficiency__1down";
        inVarSYST["JET_JvtEfficiency__1up"                           ] = "weight_JET_JvtEfficiency__1up";
        inVarSYST["MUON_EFF_ISO_STAT__1down"                         ] = "weight_MUON_EFF_ISO_STAT__1down";
        inVarSYST["MUON_EFF_ISO_STAT__1up"                           ] = "weight_MUON_EFF_ISO_STAT__1up";
        inVarSYST["MUON_EFF_ISO_SYS__1down"                          ] = "weight_MUON_EFF_ISO_SYS__1down";
        inVarSYST["MUON_EFF_ISO_SYS__1up"                            ] = "weight_MUON_EFF_ISO_SYS__1up";
        inVarSYST["MUON_EFF_RECO_STAT_LOWPT__1down"                  ] = "weight_MUON_EFF_RECO_STAT_LOWPT__1down";
        inVarSYST["MUON_EFF_RECO_STAT_LOWPT__1up"                    ] = "weight_MUON_EFF_RECO_STAT_LOWPT__1up";
        inVarSYST["MUON_EFF_RECO_STAT__1down"                        ] = "weight_MUON_EFF_RECO_STAT__1down";
        inVarSYST["MUON_EFF_RECO_STAT__1up"                          ] = "weight_MUON_EFF_RECO_STAT__1up";
        inVarSYST["MUON_EFF_RECO_SYS_LOWPT__1down"                   ] = "weight_MUON_EFF_RECO_SYS_LOWPT__1down";
        inVarSYST["MUON_EFF_RECO_SYS_LOWPT__1up"                     ] = "weight_MUON_EFF_RECO_SYS_LOWPT__1up";
        inVarSYST["MUON_EFF_RECO_SYS__1down"                         ] = "weight_MUON_EFF_RECO_SYS__1down";
        inVarSYST["MUON_EFF_RECO_SYS__1up"                           ] = "weight_MUON_EFF_RECO_SYS__1up";
        inVarSYST["MUON_EFF_TTVA_STAT__1down"                        ] = "weight_MUON_EFF_TTVA_STAT__1down";
        inVarSYST["MUON_EFF_TTVA_STAT__1up"                          ] = "weight_MUON_EFF_TTVA_STAT__1up";
        inVarSYST["MUON_EFF_TTVA_SYS__1down"                         ] = "weight_MUON_EFF_TTVA_SYS__1down";
        inVarSYST["MUON_EFF_TTVA_SYS__1up"                           ] = "weight_MUON_EFF_TTVA_SYS__1up";
        inVarSYST["MUON_EFF_TrigStatUncertainty__1down"              ] = "weight_MUON_EFF_TrigStatUncertainty__1down";
        inVarSYST["MUON_EFF_TrigStatUncertainty__1up"                ] = "weight_MUON_EFF_TrigStatUncertainty__1up";
        inVarSYST["MUON_EFF_TrigSystUncertainty__1down"              ] = "weight_MUON_EFF_TrigSystUncertainty__1down";
        inVarSYST["MUON_EFF_TrigSystUncertainty__1up"                ] = "weight_MUON_EFF_TrigSystUncertainty__1up";
        inVarSYST["PRW_DATASF__1down"                                ] = "weight_PRW_DATASF__1down";
        inVarSYST["PRW_DATASF__1up"                                  ] = "weight_PRW_DATASF__1up";

    }

    std::set<std::string> ttbar = {"410472"};
    for (auto DSID : ttbar){
        if (infile.find(DSID)!=std::string::npos){
            inVarTHEO["QCD55"] = "weight_var_th_muR_0p5_muF_0p5";
            inVarTHEO["QCD51"] = "weight_var_th_muR_0p5_muF_1p0";
            inVarTHEO["QCD15"] = "weight_var_th_muR_1p0_muF_0p5";
            inVarTHEO["QCD12"] = "weight_var_th_muR_1p0_muF_2p0";
            inVarTHEO["QCD21"] = "weight_var_th_muR_2p0_muF_1p0";
            inVarTHEO["QCD22"] = "weight_var_th_muR_2p0_muF_2p0";
            for (int i =1; i<=100; i++){
                inVarTHEO["PDF"+std::to_string(i)] = "weight_var_th_PDF_set_"+std::to_string(i+260000);
            }
        }
    }

    std::set<std::string> Wt = { "410646", "410647", "410648", "410649", "410656", "410657"};
    for (auto DSID : Wt){
        if (infile.find(DSID)!=std::string::npos){
            inVarTHEO["QCD55"] = "weight_var_th_muR_0p50_muF_0p50";
            inVarTHEO["QCD51"] = "weight_var_th_muR_0p50_muF_1p00";
            inVarTHEO["QCD15"] = "weight_var_th_muR_1p00_muF_0p50";
            inVarTHEO["QCD12"] = "weight_var_th_muR_1p00_muF_2p00";
            inVarTHEO["QCD21"] = "weight_var_th_muR_2p00_muF_1p00";
            inVarTHEO["QCD22"] = "weight_var_th_muR_2p00_muF_2p00";
            for (int i =1; i<=100; i++){
                inVarTHEO["PDF"+std::to_string(i)] = "weight_var_th_PDF_set_"+std::to_string(i+260000);
            }
        }
    }

    std::set<std::string> sherpa222 = {
        "364242", "364243", "364244", "364245", "364246", "364247", "364248", "364249", // VVV
        "345666", "345723", "364254", "364285" // ZZ -> llvv
        "364283", "364250", "345706", // ZZ -> llll
        "364253", "364284", // WZ
        "345718", // WW
    };

    for (auto DSID : sherpa222){
        if (infile.find(DSID)!=std::string::npos){
            inVarTHEO["QCD55"] = "weight_var_th_MUR0p5_MUF0p5_PDF261000";
            inVarTHEO["QCD51"] = "weight_var_th_MUR0p5_MUF1_PDF261000";
            inVarTHEO["QCD15"] = "weight_var_th_MUR1_MUF0p5_PDF261000";
            inVarTHEO["QCD12"] = "weight_var_th_MUR1_MUF2_PDF261000";
            inVarTHEO["QCD21"] = "weight_var_th_MUR2_MUF1_PDF261000";
            inVarTHEO["QCD22"] = "weight_var_th_MUR2_MUF2_PDF261000";
            for (int i =0; i<=100; i++){
                inVarTHEO["PDF"+std::to_string(i)] = "weight_var_th_MUR1_MUF1_PDF"+std::to_string(i+261000);
            }
            return;
        }
    }

    std::set<std::string> sherpa221 = { /* for ZJets */
        "364100", "364101", "364102", "364103", "364104", "364105", "364106",
        "364107", "364108", "364109", "364110", "364111", "364112", "364113",
        "364114", "364115", "364116", "364117", "364118", "364119", "364120",
        "364121", "364122", "364123", "364124", "364125", "364126", "364127",
        "364128", "364129", "364130", "364131", "364132", "364133", "364134",
        "364135", "364136", "364137", "364138", "364139", "364140", "364141",
        "363356", "308092", "308093", "308094"};

    for (auto DSID : sherpa221){
        if (infile.find(DSID)!=std::string::npos){
            inVarTHEO["QCD55"] = "weight_var_th_MUR0p5_MUF0p5_PDF261000";
            inVarTHEO["QCD51"] = "weight_var_th_MUR0p5_MUF1_PDF261000";
            inVarTHEO["QCD15"] = "weight_var_th_MUR1_MUF0p5_PDF261000";
            inVarTHEO["QCD12"] = "weight_var_th_MUR1_MUF2_PDF261000";
            inVarTHEO["QCD21"] = "weight_var_th_MUR2_MUF1_PDF261000";
            inVarTHEO["QCD22"] = "weight_var_th_MUR2_MUF2_PDF261000";
            return;
        }
    }

    /*
    if (type == "ww"){// powheg
        inVarTHEO["QCD55"] = "weight_var_th_muR0p5_muF0p5";
        inVarTHEO["QCD51"] = "weight_var_th_muR0p5_muF1p0";
        inVarTHEO["QCD15"] = "weight_var_th_muR1p0_muF0p5";
        inVarTHEO["QCD12"] = "weight_var_th_muR1p0_muF2p0";
        inVarTHEO["QCD21"] = "weight_var_th_muR2p0_muF1p0";
        inVarTHEO["QCD22"] = "weight_var_th_muR2p0_muF2p0";
        for (int i =1; i<=52; i++){
            inVarTHEO["PDF"+std::to_string(i)] = "weight_var_th_pdf_"+std::to_string(i+11000);
        }
    }


    if (type == "sherpa"){
        inVarTHEO["QCD55"] = "weight_var_th_MUR0p5_MUF0p5_PDF261000";
        inVarTHEO["QCD51"] = "weight_var_th_MUR0p5_MUF1_PDF261000";
        inVarTHEO["QCD15"] = "weight_var_th_MUR1_MUF0p5_PDF261000";
        inVarTHEO["QCD12"] = "weight_var_th_MUR1_MUF2_PDF261000";
        inVarTHEO["QCD21"] = "weight_var_th_MUR2_MUF1_PDF261000";
        inVarTHEO["QCD22"] = "weight_var_th_MUR2_MUF2_PDF261000";
        for (int i =0; i<=100; i++){
            inVarTHEO["PDF"+std::to_string(i)] = "weight_var_th_MUR1_MUF1_PDF"+std::to_string(i+261000);
        }
    }

    if (type == "ttbar"){
        inVarTHEO["QCD55"] = "weight_var_th_muR0p5_muF0p5";
        inVarTHEO["QCD51"] = "weight_var_th_muR0p5_muF1p0";
        inVarTHEO["QCD15"] = "weight_var_th_muR1p0_muF0p5";
        inVarTHEO["QCD12"] = "weight_var_th_muR1p0_muF2p0";
        inVarTHEO["QCD21"] = "weight_var_th_muR2p0_muF1p0";
        inVarTHEO["QCD22"] = "weight_var_th_muR2p0_muF2p0";
        for (int i =1; i<=100; i++){
            inVarTHEO["PDF"+std::to_string(i)] = "weight_var_th_pdf_"+std::to_string(i+260000);
        }
    }

    if (type =="tchan_top"){
        inVarTHEO["QCD55"] = "weight_var_th_muR0p5_muF0p5";
        inVarTHEO["QCD51"] = "weight_var_th_muR0p5_muF1p0";
        inVarTHEO["QCD15"] = "weight_var_th_muR1p0_muF0p5";
        inVarTHEO["QCD12"] = "weight_var_th_muR1p0_muF2p0";
        inVarTHEO["QCD21"] = "weight_var_th_muR2p0_muF1p0";
        inVarTHEO["QCD22"] = "weight_var_th_muR2p0_muF2p0";
        for (int i =1; i<=100; i++){
            inVarTHEO["PDF"+std::to_string(i)] = "weight_var_th_pdf_"+std::to_string(i+260400);
        }
    }
    */
}

bool readTree::mkHist(){
    mkHistVar("BDT", 200, -1, 1);
    mkHistVar("MET", 1000, 0, 1000);
    mkHistVar("mT", 3000, 0, 3000);
    mkHistVar("Z_eta", 200, -10, 10);
    mkHistVar("dLepR", 40, 0, 4);
    mkHistVar("dMetZPhi",40, 0, 4);
    mkHistVar("met_signif", 30, 0, 30);
    mkHistVar("frac_pT", 100, 0, 10);
    mkHistVar("MetOHT", 20, 0, 2);
    mkHistVar("M2Lep", 60, 60, 120);
    mkHistVar("sumpT_scalar", 2000, 0, 2000);
    return true;
}


bool readTree::mkHistVar(std::string var, int nbins, double left, double right){
    histVars.push_back(var);
    hist_llvv[std::make_pair(this->treename, var )] = new TH1F(("llvv__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    hist_eevv[std::make_pair(this->treename, var )] = new TH1F(("eevv__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    hist_mmvv[std::make_pair(this->treename, var )] = new TH1F(("mmvv__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    hist_emvv[std::make_pair(this->treename, var )] = new TH1F(("emvv__"+var+"__"+this->treename).c_str(), "", nbins, left, right);

    for (auto theo:inVarTHEO){
        hist_llvv[std::make_pair(theo.first, var)] = new TH1F(("llvv__"+var+"__"+theo.first).c_str(), "", nbins, left, right);
        hist_eevv[std::make_pair(theo.first, var)] = new TH1F(("eevv__"+var+"__"+theo.first).c_str(), "", nbins, left, right);
        hist_mmvv[std::make_pair(theo.first, var)] = new TH1F(("mmvv__"+var+"__"+theo.first).c_str(), "", nbins, left, right);
        hist_emvv[std::make_pair(theo.first, var)] = new TH1F(("emvv__"+var+"__"+theo.first).c_str(), "", nbins, left, right);
    }
    for (auto syst:inVarSYST){
        hist_llvv[std::make_pair(syst.first, var)] = new TH1F(("llvv__"+var+"__"+syst.first).c_str(), "", nbins, left, right);
        hist_eevv[std::make_pair(syst.first, var)] = new TH1F(("eevv__"+var+"__"+syst.first).c_str(), "", nbins, left, right);
        hist_mmvv[std::make_pair(syst.first, var)] = new TH1F(("mmvv__"+var+"__"+syst.first).c_str(), "", nbins, left, right);
        hist_emvv[std::make_pair(syst.first, var)] = new TH1F(("emvv__"+var+"__"+syst.first).c_str(), "", nbins, left, right);
    }
    return true;
}

int readTree::Cut()
{
    fEvt["event_type"] = iEvt["event_type"];
    //fEvt["event_3CR"] = iEvt["event_3CR"];
    fEvt["event_4CR"] = 0;
    //fEvt["SR_HM_LM"] = iEvt["SR_HM_LM"];
    fEvt["n_bjets"] = iEvt["n_bjets"];
    //if (iEvt["event_3CR"]!=0)                     return RG_readTree::_NONE;
    if (!(fEvt["M2Lep"]>76 && fEvt["M2Lep"]<106)) return RG_Hinv::_NONE;
    if (fEvt["met_tst"]<=90)                      return RG_Hinv::_NONE;
    if (iEvt["n_bjets"]!=0)                       return RG_Hinv::_NONE;
    if (fabs(fEvt["dLepR"])>=1.8)                 return RG_Hinv::_NONE;
    if (fEvt["met_signif"]<=9)                    return RG_Hinv::_NONE;

    if (iEvt["event_type"]==0)         return RG_Hinv::_MM;
    if (iEvt["event_type"]==1)         return RG_Hinv::_EE;
    if (iEvt["event_type"]==2)         return RG_Hinv::_EM;

    return RG_Hinv::_NONE;
}

void readTree::LoopEVT(int region)
{

    float sf, weight;
    //if (this->isMC) sf = this->xsec * fEvt["weight"];
    if (this->isMC) {
        sf = this->factorSR * fEvt["weight"] / fEvt["weight_gen"];
        weight = this->factorSR * fEvt["weight"];
    }
    else {
        weight = 1;
    }
    
    fEvt["BDT"] = reader->EvaluateMVA("BDTG");
    fEvt["MET"] = fEvt["met_tst"];
    fEvt["mT"] = fEvt["mT_ZZ"];

    if (region == RG_Hinv::_MM){
        for (auto var: histVars){
            hist_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], weight);
            hist_mmvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], weight);
            for (auto theo:inVarTHEO){
                hist_llvv[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
                hist_mmvv[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
            }
            for (auto syst:inVarSYST){
                hist_llvv[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->factorSR);
                hist_mmvv[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->factorSR);
            }
        }
    }

    if (region == RG_Hinv::_EE){
        for (auto var: histVars){
            hist_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], weight);
            hist_eevv[std::make_pair(this->treename, var)]->Fill(fEvt[var], weight);
            for (auto theo:inVarTHEO){
                hist_llvv[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
                hist_eevv[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
            }
            for (auto syst:inVarSYST){
                hist_llvv[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->factorSR);
                hist_eevv[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->factorSR);
            }
        }
    }

    if (this->isMC) {
        sf = this->factorCR * fEvt["weight"] / fEvt["weight_gen"];
        weight = this->factorCR * fEvt["weight"];
    }
    else {
        weight = 1;
        //sf = ;
    }

    //printf("%f\n", weight);
    if (region == RG_Hinv::_EM){
        for (auto var: histVars){
            hist_emvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], weight);
            for (auto theo:inVarTHEO){
                hist_emvv[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
            }
            for (auto syst:inVarSYST){
                hist_emvv[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->factorCR);
            }
        }
    }
}
