#define VBSZZ_readTree_cxx
#include "VBSZZ/readTree.h"
#include "VBSZZ/regions.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>


    readTree::readTree(std::string outfile, std::string infile, std::string sysname, float factor)
: tree(0)
{
    //std::cout << treename << std::endl;
    this->treename = sysname;
    this->factor = factor;

    inVarF = {
        "leading_pT_lepton", "subleading_pT_lepton",
        "lepplus_pt", "lepminus_pt",
        "lepplus_eta", "lepminus_eta",
        "lepplus_phi", "lepminus_phi",
        "leading_jet_pt", "second_jet_pt",
        "leading_jet_eta", "second_jet_eta",
        "leading_jet_rapidity", "second_jet_rapidity",
        "M2Lep", "mjj", "dLepR", "met_tst", "met_signi",
        "lep3rd_pt", "lep3rd_eta", "lep3rd_phi", "met_py_tst", "met_px_tst",
        "sumpT_scalar", "mtw", "weight",
    };
    inVarI = {
        "event_type",
        "event_3CR",
        "n_bjets",
        "n_jets",
        "medium_3rd",
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
    //std::vector<std::string> fMVA= {
    //    "Z_eta",
    //    "dLepR",
    //    "dMetZPhi",
    //    "met_signif",
    //    "frac_pT",
    //    "MetOHT",
    //    "M2Lep",
    //    "sumpT_scalar",
    //};
    //std::vector<std::string> iMVA= {
    //    "event_3CR",
    //    "n_bjets",
    //    "event_type"
    //};
    //for (auto v: fMVA) reader->AddVariable(v, &fEvt[v]);
    //for (auto v: iMVA) reader->AddSpectator(v, &fEvt[v]);
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

    //LoopROOT(infile, "tree_PFLOW", 1);
    //LoopROOT(infile, "tree_emCR_PFLOW", 1);

    TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(infile.c_str());
    if (!f || !f->IsOpen()) f = new TFile(infile.c_str(), "read");

    //std::cout << "      reading... " << infile << std::endl;

    if (infile.find("data")==std::string::npos) {
        //hInfo = (TH1F*)f->Get("hInfo");
        //this->factor *= hInfo->GetBinContent(1) * 2.0 / hInfo->GetEntries() / hInfo->GetBinContent(2);
        if (infile.find("r9364")  != std::string::npos) this->factor *= (3.21956 + 32.9653);
        if (infile.find("r10201") != std::string::npos) this->factor *= 44.3074;
        if (infile.find("r10724") != std::string::npos) this->factor *= 58.4501;
        this->isMC = true;
    }
    else{
        this->factor = 1;
        this->isMC = false;
    }

    std::cout << "factor   :  " << this->factor<< std::endl;

    f->GetObject(("tree_"+sysname).c_str(), this->tree);
    for (auto varname: inVarI) tree->SetBranchAddress(varname.c_str(), &iEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    for (auto varname: inVarF) tree->SetBranchAddress(varname.c_str(), &fEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    for (auto varname: inVarTHEO) tree->SetBranchAddress(varname.second.c_str(), &fEvt[varname.second.c_str()], &BrEvt[varname.second.c_str()]);
    for (auto varname: inVarSYST) tree->SetBranchAddress(varname.second.c_str(), &fEvt[varname.second.c_str()], &BrEvt[varname.second.c_str()]);
    for (Long64_t jentry=0; jentry<tree->GetEntriesFast();jentry++) {
        tree->GetEntry(jentry);
        int region = Cut();
        //std::cout << region << std::endl;
        if (region == RG_VBS::_none) continue;
        LoopEVT(region);
    }

    f->Close();
}


readTree::~readTree(){
    for (auto h : h2lSR_llvv)  delete h.second;
    for (auto h : h2lSR_eevv)  delete h.second;
    for (auto h : h2lSR_mmvv)  delete h.second;
    for (auto h : h2lVR_llvv)  delete h.second;
    for (auto h : h2lVR_eevv)  delete h.second;
    for (auto h : h2lVR_mmvv)  delete h.second;
    for (auto h : h2lCR_emvv)  delete h.second;
    for (auto h : h3lCR_lllv)  delete h.second;
    for (auto h : h3lCR_eeev)  delete h.second;
    for (auto h : h3lCR_mmmv)  delete h.second;
    for (auto h : h3lCR_mmev)  delete h.second;
    for (auto h : h3lCR_eemv)  delete h.second;
}

void readTree::Close(){
    fout->cd();
    for (auto h : h2lSR_llvv)  h.second->Write();
    for (auto h : h2lSR_eevv)  h.second->Write();
    for (auto h : h2lSR_mmvv)  h.second->Write();
    //for (auto h : h2lVR_llvv)  h.second->Write();
    //for (auto h : h2lVR_eevv)  h.second->Write();
    //for (auto h : h2lVR_mmvv)  h.second->Write();
    //for (auto h : h2lCR_emvv)  h.second->Write();
    //for (auto h : h3lCR_lllv)  h.second->Write();
    //for (auto h : h3lCR_eeev)  h.second->Write();
    //for (auto h : h3lCR_mmmv)  h.second->Write();
    //for (auto h : h3lCR_mmev)  h.second->Write();
    //for (auto h : h3lCR_eemv)  h.second->Write();
    fout->Close();
}


void readTree::initWeights(std::string infile){

    inVarSYST.clear();
    inVarTHEO.clear();

    return;

    //if (infile.find("PFLOW") == std::string::npos) return;
    if (this->treename != "NOMINAL") return;

    std::set<std::string> EXP = {
        "364242", "364243", "364244", "364245", "364246", "364247", "364248", "364249", // VVV
        "345666", "345723", "364254", "364285", // ZZ -> llvv
        "364283", "364250", "345706", // ZZ -> llll
        "364253", "364284", // WZ
        //"345718", // WW
        "363724", // signal
    };

    for (auto DSID : EXP){
        if (infile.find(DSID)!=std::string::npos){
            inVarSYST["weight_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR__1down"     ] = "weight_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR__1down";
            inVarSYST["weight_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR__1up"       ] = "weight_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR__1up";
            inVarSYST["weight_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR__1down"    ] = "weight_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR__1down";
            inVarSYST["weight_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR__1up"      ] = "weight_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR__1up";
            inVarSYST["weight_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR__1down"   ] = "weight_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR__1down";
            inVarSYST["weight_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR__1up"     ] = "weight_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR__1up";
            inVarSYST["weight_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down"] = "weight_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down";
            inVarSYST["weight_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up"  ] = "weight_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up";
            inVarSYST["weight_FT_EFF_B_systematics__1down"                  ] = "weight_FT_EFF_B_systematics__1down";
            inVarSYST["weight_FT_EFF_B_systematics__1up"                    ] = "weight_FT_EFF_B_systematics__1up";
            inVarSYST["weight_FT_EFF_C_systematics__1down"                  ] = "weight_FT_EFF_C_systematics__1down";
            inVarSYST["weight_FT_EFF_C_systematics__1up"                    ] = "weight_FT_EFF_C_systematics__1up";
            inVarSYST["weight_FT_EFF_Light_systematics__1down"              ] = "weight_FT_EFF_Light_systematics__1down";
            inVarSYST["weight_FT_EFF_Light_systematics__1up"                ] = "weight_FT_EFF_Light_systematics__1up";
            inVarSYST["weight_FT_EFF_extrapolation__1down"                  ] = "weight_FT_EFF_extrapolation__1down";
            inVarSYST["weight_FT_EFF_extrapolation__1up"                    ] = "weight_FT_EFF_extrapolation__1up";
            inVarSYST["weight_FT_EFF_extrapolation_from_charm__1down"       ] = "weight_FT_EFF_extrapolation_from_charm__1down";
            inVarSYST["weight_FT_EFF_extrapolation_from_charm__1up"         ] = "weight_FT_EFF_extrapolation_from_charm__1up";
            inVarSYST["weight_JET_JvtEfficiency__1down"                     ] = "weight_JET_JvtEfficiency__1down";
            inVarSYST["weight_JET_JvtEfficiency__1up"                       ] = "weight_JET_JvtEfficiency__1up";
            inVarSYST["weight_MUON_EFF_ISO_STAT__1down"                     ] = "weight_MUON_EFF_ISO_STAT__1down";
            inVarSYST["weight_MUON_EFF_ISO_STAT__1up"                       ] = "weight_MUON_EFF_ISO_STAT__1up";
            inVarSYST["weight_MUON_EFF_ISO_SYS__1down"                      ] = "weight_MUON_EFF_ISO_SYS__1down";
            inVarSYST["weight_MUON_EFF_ISO_SYS__1up"                        ] = "weight_MUON_EFF_ISO_SYS__1up";
            inVarSYST["weight_MUON_EFF_RECO_STAT_LOWPT__1down"              ] = "weight_MUON_EFF_RECO_STAT_LOWPT__1down";
            inVarSYST["weight_MUON_EFF_RECO_STAT_LOWPT__1up"                ] = "weight_MUON_EFF_RECO_STAT_LOWPT__1up";
            inVarSYST["weight_MUON_EFF_RECO_STAT__1down"                    ] = "weight_MUON_EFF_RECO_STAT__1down";
            inVarSYST["weight_MUON_EFF_RECO_STAT__1up"                      ] = "weight_MUON_EFF_RECO_STAT__1up";
            inVarSYST["weight_MUON_EFF_RECO_SYS_LOWPT__1down"               ] = "weight_MUON_EFF_RECO_SYS_LOWPT__1down";
            inVarSYST["weight_MUON_EFF_RECO_SYS_LOWPT__1up"                 ] = "weight_MUON_EFF_RECO_SYS_LOWPT__1up";
            inVarSYST["weight_MUON_EFF_RECO_SYS__1down"                     ] = "weight_MUON_EFF_RECO_SYS__1down";
            inVarSYST["weight_MUON_EFF_RECO_SYS__1up"                       ] = "weight_MUON_EFF_RECO_SYS__1up";
            inVarSYST["weight_MUON_EFF_TTVA_STAT__1down"                    ] = "weight_MUON_EFF_TTVA_STAT__1down";
            inVarSYST["weight_MUON_EFF_TTVA_STAT__1up"                      ] = "weight_MUON_EFF_TTVA_STAT__1up";
            inVarSYST["weight_MUON_EFF_TTVA_SYS__1down"                     ] = "weight_MUON_EFF_TTVA_SYS__1down";
            inVarSYST["weight_MUON_EFF_TTVA_SYS__1up"                       ] = "weight_MUON_EFF_TTVA_SYS__1up";
            inVarSYST["weight_MUON_EFF_TrigStatUncertainty__1down"          ] = "weight_MUON_EFF_TrigStatUncertainty__1down";
            inVarSYST["weight_MUON_EFF_TrigStatUncertainty__1up"            ] = "weight_MUON_EFF_TrigStatUncertainty__1up";
            inVarSYST["weight_MUON_EFF_TrigSystUncertainty__1down"          ] = "weight_MUON_EFF_TrigSystUncertainty__1down";
            inVarSYST["weight_MUON_EFF_TrigSystUncertainty__1up"            ] = "weight_MUON_EFF_TrigSystUncertainty__1up";
        }
    }

    std::set<std::string> sherpa222 = {
        "364242", "364243", "364244", "364245", "364246", "364247", "364248", "364249", // VVV
        "345666", "345723", "364254", "364285" // ZZ -> llvv
            "364283", "364250", "345706", // ZZ -> llll
        //"364253", "364284", // WZ
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
}

bool readTree::mkHist(){
    // ZJCR 
    mkHistVar("METS", 300, 0, 30);
    mkHistVar("BDT", 200, -1, 1);

    //mkHistVar("MET", 1000, 0, 1000);
    //mkHistVar("mT", 3000, 0, 3000);
    //mkHistVar("dMetZPhi",40, 0, 4);
    //mkHistVar("METS", 30, 0, 30);
    //mkHistVar("PtL1", 1000, 0, 1000);
    //mkHistVar("PtL2", 1000, 0, 1000);
    //mkHistVar("PtJ1", 1000, 0, 1000);
    //mkHistVar("PtJ2", 1000, 0, 1000);
    //mkHistVar("EtaL1", 200, -10, 10);
    //mkHistVar("EtaL2", 200, -10, 10);
    //mkHistVar("EtaJ1", 200, -10, 10);
    //mkHistVar("EtaJ2", 200, -10, 10);

    //mkHistVar("M2L", 60, 60, 120);
    //mkHistVar("J1xJ2", 60, -30, 30);
    //mkHistVar("dLepR", 100, 0, 20);
    //mkHistVar("dLepEta", 200, 0, 20);
    //mkHistVar("dLepPhi", 200, 0, 20);

    //mkHistVar("MJJ", 200, 0, 2000);
    //mkHistVar("dYJJ", 100, 0, 10);
    //mkHistVar("J1xJ2", 1000, -50, 50);
    //mkHistVar("nJet", 30, 0, 30);
    //mkHistVar("HT", 5000, 0, 5000);
    //mkHistVar("BDT", 40, -1, 1);
    return true;
}


bool readTree::mkHistVar(std::string var, int nbins, double left, double right){
    histVars.push_back(var);
    h2lSR_llvv[std::make_pair(this->treename, var )] = new TH1F(("llvv_2lSR__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    h2lSR_eevv[std::make_pair(this->treename, var )] = new TH1F(("eevv_2lSR__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    h2lSR_mmvv[std::make_pair(this->treename, var )] = new TH1F(("mmvv_2lSR__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    h2lVR_llvv[std::make_pair(this->treename, var )] = new TH1F(("llvv_2lVR__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    h2lVR_eevv[std::make_pair(this->treename, var )] = new TH1F(("eevv_2lVR__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    h2lVR_mmvv[std::make_pair(this->treename, var )] = new TH1F(("mmvv_2lVR__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    h2lCR_emvv[std::make_pair(this->treename, var )] = new TH1F(("emvv_2lCR__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    h3lCR_lllv[std::make_pair(this->treename, var )] = new TH1F(("lllv_3lCR__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    h3lCR_eeev[std::make_pair(this->treename, var )] = new TH1F(("eeev_3lCR__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    h3lCR_mmmv[std::make_pair(this->treename, var )] = new TH1F(("mmmv_3lCR__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    h3lCR_mmev[std::make_pair(this->treename, var )] = new TH1F(("mmev_3lCR__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    h3lCR_eemv[std::make_pair(this->treename, var )] = new TH1F(("eemv_3lCR__"+var+"__"+this->treename).c_str(), "", nbins, left, right);

    for (auto theo:inVarTHEO){
        h2lSR_llvv[std::make_pair(theo.first, var)] = new TH1F(("llvv_2lSR__"+var+"__"+theo.first).c_str(), "", nbins, left, right);
        h2lSR_eevv[std::make_pair(theo.first, var)] = new TH1F(("eevv_2lSR__"+var+"__"+theo.first).c_str(), "", nbins, left, right);
        h2lSR_mmvv[std::make_pair(theo.first, var)] = new TH1F(("mmvv_2lSR__"+var+"__"+theo.first).c_str(), "", nbins, left, right);
        h2lVR_llvv[std::make_pair(theo.first, var)] = new TH1F(("llvv_2lVR__"+var+"__"+theo.first).c_str(), "", nbins, left, right);
        h2lVR_eevv[std::make_pair(theo.first, var)] = new TH1F(("eevv_2lVR__"+var+"__"+theo.first).c_str(), "", nbins, left, right);
        h2lVR_mmvv[std::make_pair(theo.first, var)] = new TH1F(("mmvv_2lVR__"+var+"__"+theo.first).c_str(), "", nbins, left, right);
        h2lCR_emvv[std::make_pair(theo.first, var)] = new TH1F(("emvv_2lCR__"+var+"__"+theo.first).c_str(), "", nbins, left, right);
        h3lCR_lllv[std::make_pair(theo.first, var)] = new TH1F(("lllv_3lCR__"+var+"__"+theo.first).c_str(), "", nbins, left, right);
        h3lCR_eeev[std::make_pair(theo.first, var)] = new TH1F(("eeev_3lCR__"+var+"__"+theo.first).c_str(), "", nbins, left, right);
        h3lCR_mmmv[std::make_pair(theo.first, var)] = new TH1F(("mmmv_3lCR__"+var+"__"+theo.first).c_str(), "", nbins, left, right);
        h3lCR_mmev[std::make_pair(theo.first, var)] = new TH1F(("mmev_3lCR__"+var+"__"+theo.first).c_str(), "", nbins, left, right);
        h3lCR_eemv[std::make_pair(theo.first, var)] = new TH1F(("eemv_3lCR__"+var+"__"+theo.first).c_str(), "", nbins, left, right);
    }                                                                      
    for (auto syst:inVarSYST){                                             
        h2lSR_llvv[std::make_pair(syst.first, var)] = new TH1F(("llvv_2lSR__"+var+"__"+syst.first).c_str(), "", nbins, left, right);
        h2lSR_eevv[std::make_pair(syst.first, var)] = new TH1F(("eevv_2lSR__"+var+"__"+syst.first).c_str(), "", nbins, left, right);
        h2lSR_mmvv[std::make_pair(syst.first, var)] = new TH1F(("mmvv_2lSR__"+var+"__"+syst.first).c_str(), "", nbins, left, right);
        h2lVR_llvv[std::make_pair(syst.first, var)] = new TH1F(("llvv_2lVR__"+var+"__"+syst.first).c_str(), "", nbins, left, right);
        h2lVR_eevv[std::make_pair(syst.first, var)] = new TH1F(("eevv_2lVR__"+var+"__"+syst.first).c_str(), "", nbins, left, right);
        h2lVR_mmvv[std::make_pair(syst.first, var)] = new TH1F(("mmvv_2lVR__"+var+"__"+syst.first).c_str(), "", nbins, left, right);
        h2lCR_emvv[std::make_pair(syst.first, var)] = new TH1F(("emvv_2lCR__"+var+"__"+syst.first).c_str(), "", nbins, left, right);
        h3lCR_lllv[std::make_pair(syst.first, var)] = new TH1F(("lllv_3lCR__"+var+"__"+syst.first).c_str(), "", nbins, left, right);
        h3lCR_eeev[std::make_pair(syst.first, var)] = new TH1F(("eeev_3lCR__"+var+"__"+syst.first).c_str(), "", nbins, left, right);
        h3lCR_mmmv[std::make_pair(syst.first, var)] = new TH1F(("mmmv_3lCR__"+var+"__"+syst.first).c_str(), "", nbins, left, right);
        h3lCR_mmev[std::make_pair(syst.first, var)] = new TH1F(("mmev_3lCR__"+var+"__"+syst.first).c_str(), "", nbins, left, right);
        h3lCR_eemv[std::make_pair(syst.first, var)] = new TH1F(("eemv_3lCR__"+var+"__"+syst.first).c_str(), "", nbins, left, right);
    }
    return true;
}

int readTree::Cut()
{
    fEvt["event_type"] = iEvt["event_type"];
    fEvt["event_3CR"] = iEvt["event_3CR"];
    fEvt["n_bjets"] = iEvt["n_bjets"];
    fEvt["PtL1"] = fEvt["lepplus_pt"] > fEvt["lepminus_pt"]?  fEvt["lepplus_pt"]:fEvt["lepminus_pt"];
    fEvt["PtL2"] = fEvt["lepplus_pt"] < fEvt["lepminus_pt"]?  fEvt["lepplus_pt"]:fEvt["lepminus_pt"];
    fEvt["EtaL1"] = fEvt["lepplus_pt"] > fEvt["lepminus_pt"]?  fEvt["lepplus_eta"]:fEvt["lepminus_eta"];
    fEvt["EtaL2"] = fEvt["lepplus_pt"] < fEvt["lepminus_pt"]?  fEvt["lepplus_eta"]:fEvt["lepminus_eta"];
    fEvt["PtJ1"] = fEvt["leading_jet_pt"] ;
    fEvt["PtJ2"] = fEvt["second_jet_pt"] ;
    fEvt["EtaJ1"] = fEvt["leading_jet_eta"];
    fEvt["EtaJ2"] = fEvt["second_jet_eta"];

    fEvt["PtL3"] = fEvt["lep3rd_pt"];
    fEvt["EtaL3"] = fEvt["lep3rd_eta"];
    fEvt["M2L"] = fEvt["M2Lep"];
    fEvt["MET"] = fEvt["met_tst"];
    fEvt["METS"] = fEvt["met_signi"];
    fEvt["MJJ"] = fEvt["mjj"];
    fEvt["mT"] = fEvt["mT_ZZ"];


    fEvt["J1xJ2"] = fEvt["leading_jet_rapidity"]*fEvt["second_jet_rapidity"];
    fEvt["dYJJ"] = fabs(fEvt["leading_jet_rapidity"]-fEvt["second_jet_rapidity"]);
    fEvt["nJet"] = iEvt["n_jets"];
    fEvt["MTW"] = fEvt["mtw"];
    fEvt["HT"] = fEvt["sumpT_scalar"];
    fEvt["dLepEta"] = fabs(fEvt["lepplus_eta"] - fEvt["lepminus_eta"]);
    fEvt["dLepPhi"] = fabs(fEvt["lepplus_phi"] - fEvt["lepminus_phi"]);

    if (iEvt["event_3CR"] != 0){// 3lCR selections
        if (iEvt["event_3CR"]<=0)                     return RG_VBS::_none;
        if (iEvt["event_3CR"]>=5)                     return RG_VBS::_none;
        if (iEvt["medium_3rd"]!=1)                    return RG_VBS::_none;
        if (fEvt["PtL1"]<30)                          return RG_VBS::_none;
        if (fEvt["PtL2"]<20)                          return RG_VBS::_none;
        if (fEvt["PtL3"]<20)                          return RG_VBS::_none;
        if (fabs(fEvt["EtaL1"])>=2.5)                 return RG_VBS::_none;
        if (fabs(fEvt["EtaL2"])>=2.5)                 return RG_VBS::_none;
        if (fabs(fEvt["EtaL3"])>=2.5)                 return RG_VBS::_none;
        if (!(fEvt["M2Lep"]>80 && fEvt["M2Lep"]<100)) return RG_VBS::_none;
        if (fEvt["MTW"]<=40)                          return RG_VBS::_none;
        if (fEvt["met_signi"]<=3)                     return RG_VBS::_none;
        if (iEvt["n_jets"]<2)                         return RG_VBS::_none;
        if (iEvt["n_bjets"]!=0)                       return RG_VBS::_none;
        if (fEvt["PtJ1"]<=60 || fEvt["PtJ2"]<=40)     return RG_VBS::_none;
        if (iEvt["event_3CR"]==1)                     return RG_VBS::_3lCR_mmmv;
        if (iEvt["event_3CR"]==2)                     return RG_VBS::_3lCR_mmev;
        if (iEvt["event_3CR"]==3)                     return RG_VBS::_3lCR_eeev;
        if (iEvt["event_3CR"]==4)                     return RG_VBS::_3lCR_eemv;
    }
    else{// 2lXR selections
        if (fEvt["PtL1"]<30)                          return RG_VBS::_none;
        if (fEvt["PtL2"]<20)                          return RG_VBS::_none;
        if (fabs(fEvt["EtaL1"])>=2.5)                 return RG_VBS::_none;
        if (fabs(fEvt["EtaL2"])>=2.5)                 return RG_VBS::_none;
        if (!(fEvt["M2Lep"]>80 && fEvt["M2Lep"]<100)) return RG_VBS::_none;
        //if (fEvt["met_signi"]<=12)                    return RG_VBS::_none;
        if (iEvt["n_jets"]<2)                         return RG_VBS::_none;
        if (iEvt["n_bjets"]!=0)                       return RG_VBS::_none;
        if (fEvt["J1xJ2"]>=0)                         return RG_VBS::_none;
        if (fEvt["PtJ1"]<=60)                         return RG_VBS::_none;
        if (fEvt["PtJ2"]<=40)                         return RG_VBS::_none;
        if (fabs(fEvt["EtaJ1"])>=4.5)                 return RG_VBS::_none;
        if (fabs(fEvt["EtaJ2"])>=4.5)                 return RG_VBS::_none;
        if (fEvt["mjj"]>400 && fEvt["dYJJ"]>2){
            //std::cout << "SR  " << fEvt["mjj"] << " " <<fEvt["dYJJ"]<<std::endl;
            if (iEvt["event_type"]==0)                return RG_VBS::_2lSR_mmvv;
            if (iEvt["event_type"]==1)                return RG_VBS::_2lSR_eevv;
            if (iEvt["event_type"]==2)                return RG_VBS::_2lCR_emvv;
        }
        if (fEvt["mjj"]<=400 || fEvt["dYJJ"]<=2){
            if (iEvt["event_type"]==0)                return RG_VBS::_2lVR_mmvv;
            if (iEvt["event_type"]==1)                return RG_VBS::_2lVR_eevv;
        }
        //
    }

    return RG_VBS::_none;
}

void readTree::LoopEVT(int region)
{

    float sf, weight;
    if (this->isMC) {
        sf = this->factor * fEvt["weight"] / fEvt["weight_gen"];
        weight = this->factor * fEvt["weight"];
    }
    else {
        weight = 1;
    }

    fEvt["BDT"] = reader->EvaluateMVA("BDTG");

    if (region == RG_VBS::_2lSR_mmvv){
        for (auto var: histVars){
            h2lSR_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], weight);
            h2lSR_mmvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], weight);
            for (auto theo:inVarTHEO){
                h2lSR_llvv[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
                h2lSR_mmvv[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
            }
            for (auto syst:inVarSYST){
                h2lSR_llvv[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->factor);
                h2lSR_mmvv[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->factor);
            }
        }
    }

    if (region == RG_VBS::_2lSR_eevv){
        for (auto var: histVars){
            h2lSR_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], weight);
            h2lSR_eevv[std::make_pair(this->treename, var)]->Fill(fEvt[var], weight);
            for (auto theo:inVarTHEO){
                h2lSR_llvv[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
                h2lSR_eevv[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
            }
            for (auto syst:inVarSYST){
                h2lSR_llvv[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->factor);
                h2lSR_eevv[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->factor);
            }
        }
    }

    if (region == RG_VBS::_2lVR_mmvv){
        for (auto var: histVars){
            //h2lVR_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], weight);
            h2lVR_mmvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], weight);
            for (auto theo:inVarTHEO){
                //h2lVR_llvv[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
                h2lVR_mmvv[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
            }
            for (auto syst:inVarSYST){
                //h2lVR_llvv[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->factor);
                h2lVR_mmvv[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->factor);
            }
        }
    }

    if (region == RG_VBS::_2lVR_eevv){
        for (auto var: histVars){
            //h2lVR_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], weight);
            h2lVR_eevv[std::make_pair(this->treename, var)]->Fill(fEvt[var], weight);
            for (auto theo:inVarTHEO){
                //h2lVR_llvv[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
                h2lVR_eevv[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
            }
            for (auto syst:inVarSYST){
                //h2lVR_llvv[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->factor);
                h2lVR_eevv[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->factor);
            }
        }
    }

    if (region == RG_VBS::_2lCR_emvv){
        for (auto var: histVars){
            h2lCR_emvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], weight);
            for (auto theo:inVarTHEO){
                h3lCR_lllv[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
                h2lCR_emvv[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
            }
            for (auto syst:inVarSYST){
                h2lCR_emvv[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->factor);
            }
        }
    }

    if (region == RG_VBS::_3lCR_mmmv){
        for (auto var: histVars){
            h3lCR_lllv[std::make_pair(this->treename, var)]->Fill(fEvt[var], weight);
            h3lCR_mmmv[std::make_pair(this->treename, var)]->Fill(fEvt[var], weight);
            for (auto theo:inVarTHEO){
                h3lCR_lllv[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
                h3lCR_mmmv[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
            }
            for (auto syst:inVarSYST){
                h3lCR_lllv[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->factor);
                h3lCR_mmmv[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->factor);
            }
        }
    }

    if (region == RG_VBS::_3lCR_eemv){
        for (auto var: histVars){
            h3lCR_lllv[std::make_pair(this->treename, var)]->Fill(fEvt[var], weight);
            h3lCR_eemv[std::make_pair(this->treename, var)]->Fill(fEvt[var], weight);
            for (auto theo:inVarTHEO){
                h3lCR_lllv[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
                h3lCR_eemv[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
            }
            for (auto syst:inVarSYST){
                h3lCR_lllv[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->factor);
                h3lCR_eemv[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->factor);
            }
        }
    }

    if (region == RG_VBS::_3lCR_mmev){
        for (auto var: histVars){
            h3lCR_lllv[std::make_pair(this->treename, var)]->Fill(fEvt[var], weight);
            h3lCR_mmev[std::make_pair(this->treename, var)]->Fill(fEvt[var], weight);
            for (auto theo:inVarTHEO){
                h3lCR_lllv[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
                h3lCR_mmev[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
            }
            for (auto syst:inVarSYST){
                h3lCR_lllv[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->factor);
                h3lCR_mmev[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->factor);
            }
        }
    }

    if (region == RG_VBS::_3lCR_eeev){
        for (auto var: histVars){
            h3lCR_lllv[std::make_pair(this->treename, var)]->Fill(fEvt[var], weight);
            h3lCR_eeev[std::make_pair(this->treename, var)]->Fill(fEvt[var], weight);
            for (auto theo:inVarTHEO){
                h3lCR_lllv[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
                h3lCR_eeev[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
            }
            for (auto syst:inVarSYST){
                h3lCR_lllv[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->factor);
                h3lCR_eeev[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->factor);
            }
        }
    }
}
