#define VBS_2lXR_cxx
#include "VBSZZ/VBS_2lXR.h"
#include "VBSZZ/regions.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <algorithm>


    VBS_2lXR::VBS_2lXR(std::string treename, std::string outfile, std::string outopt, bool THEO, bool SYST, bool NOMI)
: tree(0), treename(treename), SYST(SYST), THEO(THEO), NOMI(NOMI)
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
        "lep3rd_pt", "lep3rd_eta", "lep3rd_phi", "met_py_tst", "met_px_tst",
        "sumpT_scalar", "mtw",
        "weight", "weight_trig", "weight_exp", "weight_jvt", "weight_pileup", "weight_jets"
    };
    inVarI = {
        "event_type", "event_3CR", "n_bjets", "n_jets", "medium_3rd"
    };
    inVarV = {"vw"};
    onVarF = {
        "nJet", "HT",
        "PtL1", "PtL2", "PtJ1", "PtJ2",
        "EtaL1", "EtaL2", "EtaJ1", "EtaJ2",
        "PtL3", "EtaL3", "MTW",
        "MET", "METS", "M2L", 
        "dLepEta", "dLepPhi", "dYJJ", "J1xJ2",
    };

    inVarTHEO.clear();
    if (THEO){
        inVarTHEO["QCD55"] = 4;
        inVarTHEO["QCD51"] = 5;
        inVarTHEO["QCD15"] = 6;
        inVarTHEO["QCD12"] = 8;
        inVarTHEO["QCD21"] = 9;
        inVarTHEO["QCD22"] = 10;
        for (int i =0; i<=100; i++){
            inVarTHEO["PDF"+std::to_string(i)] = i + 11;
        }
    }

    inVarSYST.clear();
    if (SYST){
        inVarSYST["weight_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR__1down"       ] = "EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR__1down";
        inVarSYST["weight_EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR__1up"         ] = "EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR__1up";
        inVarSYST["weight_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR__1down"      ] = "EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR__1down";
        inVarSYST["weight_EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR__1up"        ] = "EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR__1up";
        inVarSYST["weight_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR__1down"     ] = "EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR__1down";
        inVarSYST["weight_EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR__1up"       ] = "EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR__1up";
        inVarSYST["weight_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down"  ] = "EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down";
        inVarSYST["weight_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up"    ] = "EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up";
        inVarSYST["weight_FT_EFF_B_systematics__1down"                    ] = "FT_EFF_B_systematics__1down";
        inVarSYST["weight_FT_EFF_B_systematics__1up"                      ] = "FT_EFF_B_systematics__1up";
        inVarSYST["weight_FT_EFF_C_systematics__1down"                    ] = "FT_EFF_C_systematics__1down";
        inVarSYST["weight_FT_EFF_C_systematics__1up"                      ] = "FT_EFF_C_systematics__1up";
        inVarSYST["weight_FT_EFF_Light_systematics__1down"                ] = "FT_EFF_Light_systematics__1down";
        inVarSYST["weight_FT_EFF_Light_systematics__1up"                  ] = "FT_EFF_Light_systematics__1up";
        inVarSYST["weight_FT_EFF_extrapolation__1down"                    ] = "FT_EFF_extrapolation__1down";
        inVarSYST["weight_FT_EFF_extrapolation__1up"                      ] = "FT_EFF_extrapolation__1up";
        inVarSYST["weight_FT_EFF_extrapolation_from_charm__1down"         ] = "FT_EFF_extrapolation_from_charm__1down";
        inVarSYST["weight_FT_EFF_extrapolation_from_charm__1up"           ] = "FT_EFF_extrapolation_from_charm__1up";
        inVarSYST["weight_JET_JvtEfficiency__1down"                       ] = "JET_JvtEfficiency__1down";
        inVarSYST["weight_JET_JvtEfficiency__1up"                         ] = "JET_JvtEfficiency__1up";
        inVarSYST["weight_JET_fJvtEfficiency__1down"                      ] = "JET_fJvtEfficiency__1down";
        inVarSYST["weight_JET_fJvtEfficiency__1up"                        ] = "JET_fJvtEfficiency__1up";
        inVarSYST["weight_MUON_EFF_ISO_STAT__1down"                       ] = "MUON_EFF_ISO_STAT__1down";
        inVarSYST["weight_MUON_EFF_ISO_STAT__1up"                         ] = "MUON_EFF_ISO_STAT__1up";
        inVarSYST["weight_MUON_EFF_ISO_SYS__1down"                        ] = "MUON_EFF_ISO_SYS__1down";
        inVarSYST["weight_MUON_EFF_ISO_SYS__1up"                          ] = "MUON_EFF_ISO_SYS__1up";
        inVarSYST["weight_MUON_EFF_RECO_STAT_LOWPT__1down"                ] = "MUON_EFF_RECO_STAT_LOWPT__1down";
        inVarSYST["weight_MUON_EFF_RECO_STAT_LOWPT__1up"                  ] = "MUON_EFF_RECO_STAT_LOWPT__1up";
        inVarSYST["weight_MUON_EFF_RECO_STAT__1down"                      ] = "MUON_EFF_RECO_STAT__1down";
        inVarSYST["weight_MUON_EFF_RECO_STAT__1up"                        ] = "MUON_EFF_RECO_STAT__1up";
        inVarSYST["weight_MUON_EFF_RECO_SYS_LOWPT__1down"                 ] = "MUON_EFF_RECO_SYS_LOWPT__1down";
        inVarSYST["weight_MUON_EFF_RECO_SYS_LOWPT__1up"                   ] = "MUON_EFF_RECO_SYS_LOWPT__1up";
        inVarSYST["weight_MUON_EFF_RECO_SYS__1down"                       ] = "MUON_EFF_RECO_SYS__1down";
        inVarSYST["weight_MUON_EFF_RECO_SYS__1up"                         ] = "MUON_EFF_RECO_SYS__1up";
        inVarSYST["weight_MUON_EFF_TTVA_STAT__1down"                      ] = "MUON_EFF_TTVA_STAT__1down";
        inVarSYST["weight_MUON_EFF_TTVA_STAT__1up"                        ] = "MUON_EFF_TTVA_STAT__1up";
        inVarSYST["weight_MUON_EFF_TTVA_SYS__1down"                       ] = "MUON_EFF_TTVA_SYS__1down";
        inVarSYST["weight_MUON_EFF_TTVA_SYS__1up"                         ] = "MUON_EFF_TTVA_SYS__1up";
        inVarSYST["weight_MUON_EFF_TrigStatUncertainty__1down"            ] = "MUON_EFF_TrigStatUncertainty__1down";
        inVarSYST["weight_MUON_EFF_TrigStatUncertainty__1up"              ] = "MUON_EFF_TrigStatUncertainty__1up";
        inVarSYST["weight_MUON_EFF_TrigSystUncertainty__1down"            ] = "MUON_EFF_TrigSystUncertainty__1down";
        inVarSYST["weight_MUON_EFF_TrigSystUncertainty__1up"              ] = "MUON_EFF_TrigSystUncertainty__1up";
    }

    for (auto v: onVarF)    fEvt[v] = -999999;
    for (auto v: inVarF)    { BrEvt[v] = new TBranch(); fEvt[v] = -999999; }
    for (auto v: inVarV)    { BrEvt[v] = new TBranch(); vEvt[v] = new std::vector<float>(); }
    for (auto v: inVarI)    { BrEvt[v] = new TBranch(); iEvt[v] = -999999; }
    for (auto v: inVarTHEO) { BrEvt[v.first] = new TBranch(); fEvt[v.first] = -999999; }
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

VBS_2lXR::~VBS_2lXR(){
    for (auto h : hist_llvv)  delete h.second;
    for (auto h : hist_eevv)  delete h.second;
    for (auto h : hist_emvv)  delete h.second;
    for (auto h : hist_mmvv)  delete h.second;
}

void VBS_2lXR::Close(){
    fout->cd();

    for (auto h : hist_llvv)  h.second->Write();
    for (auto h : hist_eevv)  h.second->Write();
    for (auto h : hist_emvv)  h.second->Write();
    for (auto h : hist_mmvv)  h.second->Write();
    fout->Close();
}


bool VBS_2lXR::LoopROOT(std::string filename, std::string treename, float factor){
    TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(filename.c_str());
    if (!f || !f->IsOpen()) f = new TFile(filename.c_str(), "read");
    f->GetObject(treename.c_str(), this->tree);

    std::cout << "      reading... " << filename << std::endl;

    if (filename.find("data") != std::string::npos) this->xsec = factor;
    else{
        hInfo = (TH1F*)f->Get("hInfo");
        this->xsec = hInfo->GetBinContent(1) * 2.0 / hInfo->GetEntries() / hInfo->GetBinContent(2) * factor;
        if (filename.find("r9364" ) != std::string::npos) this->xsec *= (3.21956 + 32.9653);
        if (filename.find("r10201") != std::string::npos) this->xsec *= 44.3074;
        if (filename.find("r10724") != std::string::npos) this->xsec *= 58.4501;
    }


    for (auto varname: inVarI) tree->SetBranchAddress(varname.c_str(), &iEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    for (auto varname: inVarF) tree->SetBranchAddress(varname.c_str(), &fEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    if (this->THEO){
        for (auto varname: inVarV) tree->SetBranchAddress(varname.c_str(), &vEvt[varname.c_str()], &BrEvt[varname.c_str()]);
        //for (auto varname: inVarTHEO) tree->SetBranchAddress(varname.first.c_str(), &fEvt[varname.first.c_str()], &BrEvt[varname.first.c_str()]);
    }
    for (auto varname: inVarSYST) tree->SetBranchAddress(varname.first.c_str(), &fEvt[varname.first.c_str()], &BrEvt[varname.first.c_str()]);

    Long64_t nentries = tree->GetEntriesFast();
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
        tree->GetEntry(jentry);
        int region = Cut();
        if (region == RG_2lXR::_NONE) continue;
        LoopEVT(region);
    }

    f->Close();
    return true;
}


bool VBS_2lXR::mkHist(){
    mkHistVar("M2L", 10, 80, 100);
    mkHistVar("METS", 9, 3, 21);
    mkHistVar("MET", 8, 0, 800);

    //mkHistVar("PtL1", 1000, 0, 1000);
    //mkHistVar("PtL2", 1000, 0, 1000);
    //mkHistVar("PtJ1", 1000, 0, 1000);
    //mkHistVar("PtJ2", 1000, 0, 1000);
    //mkHistVar("EtaL1", 200, -10, 10);
    //mkHistVar("EtaL2", 200, -10, 10);
    //mkHistVar("EtaJ1", 200, -10, 10);
    //mkHistVar("EtaJ2", 200, -10, 10);
    //mkHistVar("PhiL1", 200, -10, 10);
    //mkHistVar("PhiL2", 200, -10, 10);
    //mkHistVar("PhiJ1", 200, -10, 10);
    //mkHistVar("PhiJ2", 200, -10, 10);
    
    //mkHistVar("dLepEta", 200, 0, 20);
    //mkHistVar("dLepPhi", 200, 0, 20);

    mkHistVar("MJJ", 10, 0, 1000);
    mkHistVar("dYJJ", 8, 0, 8);
    mkHistVar("J1xJ2", 1000, -50, 50);
    mkHistVar("nJet", 30, 0, 30);
    //mkHistVar("HT", 5000, 0, 5000);
    mkHistVar("BDT", 20, -1, 1);
    mkHistVar("MTW", 20, 0, 800);
    return true;
}


bool VBS_2lXR::mkHistVar(std::string var, int nbins, double left, double right){
    histVars.push_back(var);
    if (this->NOMI){
        hist_llvv[std::make_pair(this->treename, var )] = new TH1F(("llvv__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
        hist_eevv[std::make_pair(this->treename, var )] = new TH1F(("eevv__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
        hist_emvv[std::make_pair(this->treename, var )] = new TH1F(("emvv__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
        hist_mmvv[std::make_pair(this->treename, var )] = new TH1F(("mmvv__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    }
    if (this->SYST){
        for (auto sysname: inVarSYST){
            hist_llvv[std::make_pair(sysname.second, var )] = new TH1F(("llvv__"+var+"__"+sysname.second).c_str(), "", nbins, left, right);
            hist_eevv[std::make_pair(sysname.second, var )] = new TH1F(("eevv__"+var+"__"+sysname.second).c_str(), "", nbins, left, right);
            hist_emvv[std::make_pair(sysname.second, var )] = new TH1F(("emvv__"+var+"__"+sysname.second).c_str(), "", nbins, left, right);
            hist_mmvv[std::make_pair(sysname.second, var )] = new TH1F(("mmvv__"+var+"__"+sysname.second).c_str(), "", nbins, left, right);
        }
    }
    if (this->THEO){
        for (auto sysname: inVarTHEO){
            hist_llvv[std::make_pair(sysname.first, var )] = new TH1F(("llvv__"+var+"__"+sysname.first).c_str(), "", nbins, left, right);
            hist_eevv[std::make_pair(sysname.first, var )] = new TH1F(("eevv__"+var+"__"+sysname.first).c_str(), "", nbins, left, right);
            hist_emvv[std::make_pair(sysname.first, var )] = new TH1F(("emvv__"+var+"__"+sysname.first).c_str(), "", nbins, left, right);
            hist_mmvv[std::make_pair(sysname.first, var )] = new TH1F(("mmvv__"+var+"__"+sysname.first).c_str(), "", nbins, left, right);
        }
        //hist_llvv[std::make_pair("PDFDN", var )] = new TH1F(("llvv__"+var+"__PDFDN").c_str(), "", nbins, left, right);
        //hist_eevv[std::make_pair("PDFDN", var )] = new TH1F(("eevv__"+var+"__PDFDN").c_str(), "", nbins, left, right);
        //hist_emvv[std::make_pair("PDFDN", var )] = new TH1F(("emvv__"+var+"__PDFDN").c_str(), "", nbins, left, right);
        //hist_mmvv[std::make_pair("PDFDN", var )] = new TH1F(("mmvv__"+var+"__PDFDN").c_str(), "", nbins, left, right);
        //hist_llvv[std::make_pair("PDFDN", var )] = new TH1F(("llvv__"+var+"__PDFDN").c_str(), "", nbins, left, right);
        //hist_eevv[std::make_pair("QCDDN", var )] = new TH1F(("eevv__"+var+"__QCDDN").c_str(), "", nbins, left, right);
        //hist_emvv[std::make_pair("QCDDN", var )] = new TH1F(("emvv__"+var+"__QCDDN").c_str(), "", nbins, left, right);
        //hist_mmvv[std::make_pair("QCDDN", var )] = new TH1F(("mmvv__"+var+"__QCDDN").c_str(), "", nbins, left, right);
        //hist_llvv[std::make_pair("QCDDN", var )] = new TH1F(("llvv__"+var+"__QCDDN").c_str(), "", nbins, left, right);
        //hist_eevv[std::make_pair("QCDDN", var )] = new TH1F(("eevv__"+var+"__QCDDN").c_str(), "", nbins, left, right);
        //hist_emvv[std::make_pair("PDFUP", var )] = new TH1F(("emvv__"+var+"__PDFUP").c_str(), "", nbins, left, right);
        //hist_mmvv[std::make_pair("PDFUP", var )] = new TH1F(("mmvv__"+var+"__PDFUP").c_str(), "", nbins, left, right);
        //hist_llvv[std::make_pair("PDFUP", var )] = new TH1F(("llvv__"+var+"__PDFUP").c_str(), "", nbins, left, right);
        //hist_eevv[std::make_pair("PDFUP", var )] = new TH1F(("eevv__"+var+"__PDFUP").c_str(), "", nbins, left, right);
        //hist_emvv[std::make_pair("PDFUP", var )] = new TH1F(("emvv__"+var+"__PDFUP").c_str(), "", nbins, left, right);
        //hist_mmvv[std::make_pair("QCDUP", var )] = new TH1F(("mmvv__"+var+"__QCDUP").c_str(), "", nbins, left, right);
        //hist_llvv[std::make_pair("QCDUP", var )] = new TH1F(("llvv__"+var+"__QCDUP").c_str(), "", nbins, left, right);
        //hist_eevv[std::make_pair("QCDUP", var )] = new TH1F(("eevv__"+var+"__QCDUP").c_str(), "", nbins, left, right);
        //hist_emvv[std::make_pair("QCDUP", var )] = new TH1F(("emvv__"+var+"__QCDUP").c_str(), "", nbins, left, right);
        //hist_mmvv[std::make_pair("QCDUP", var )] = new TH1F(("mmvv__"+var+"__QCDUP").c_str(), "", nbins, left, right);
    }
    return true;
}

int VBS_2lXR::Cut()
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

    fEvt["PtL3"] = fEvt["lep3rd_pt"];
    fEvt["EtaL3"] = fEvt["lep3rd_eta"];

    fEvt["J1xJ2"] = fEvt["leading_jet_rapidity"]*fEvt["second_jet_rapidity"];
    fEvt["dYJJ"] = fabs(fEvt["leading_jet_rapidity"]-fEvt["second_jet_rapidity"]);
    fEvt["nJet"] = iEvt["n_jets"];
    fEvt["MTW"] = fEvt["mtw"];
    //fEvt["MTW"] = TMath::Sqrt( 2*fEvt["PtL3"]*fEvt["MET"]*(1-
    //            TMath::Cos(TVector2::Phi_mpi_pi(fEvt["lep3rd_phi"]-TMath::ATan2(fEvt["met_py_tst"], fEvt["met_px_tst"])))));

    if (iEvt["event_3CR"]<=0)                     return RG_2lXR::_NONE;
    if (iEvt["event_3CR"]>=5)                     return RG_2lXR::_NONE;
    if (iEvt["medium_3rd"]!=1)                    return RG_2lXR::_NONE;
    if (fEvt["PtL1"]<30)                          return RG_2lXR::_NONE;
    if (fEvt["PtL2"]<20)                          return RG_2lXR::_NONE;
    if (fEvt["PtL3"]<20)                          return RG_2lXR::_NONE;
    if (fabs(fEvt["EtaL1"])>=2.5)                 return RG_2lXR::_NONE;
    if (fabs(fEvt["EtaL2"])>=2.5)                 return RG_2lXR::_NONE;
    if (fabs(fEvt["EtaL3"])>=2.5)                 return RG_2lXR::_NONE;
    if (!(fEvt["M2Lep"]>80 && fEvt["M2Lep"]<100)) return RG_2lXR::_NONE;
    if (fEvt["MTW"]<=40)                          return RG_2lXR::_NONE;
    if (fEvt["met_signi"]<=3)                     return RG_2lXR::_NONE;
    if (iEvt["n_jets"]<2)                         return RG_2lXR::_NONE;
    if (iEvt["n_bjets"]!=0)                       return RG_2lXR::_NONE;
    if (fEvt["PtJ1"]<=60 || fEvt["PtJ2"]<=40)     return RG_2lXR::_NONE;
    if (iEvt["event_3CR"]==1)                     return RG_2lXR::_mmvv;
    if (iEvt["event_3CR"]==2)                     return RG_2lXR::_mmvv;
    if (iEvt["event_3CR"]==3)                     return RG_2lXR::_eevv;
    if (iEvt["event_3CR"]==4)                     return RG_2lXR::_eevv;
    return RG_2lXR::_NONE;
}

void VBS_2lXR::LoopEVT(int region)
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

    float weight_other = this->xsec * fEvt["weight_trig"] * fEvt["weight_exp"] * fEvt["weight_jvt"] * fEvt["weight_pileup"] * fEvt["weight_jets"];

    if (region == RG_2lXR::_eevv){
        for (auto var: histVars) {
            if (this->NOMI){
                hist_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
                hist_eevv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
            }
            for (auto sysname: inVarSYST){
                hist_llvv[std::make_pair(sysname.second, var)]->Fill(fEvt[var], fEvt[sysname.first] * this->xsec);
                hist_eevv[std::make_pair(sysname.second, var)]->Fill(fEvt[var], fEvt[sysname.first] * this->xsec);
            }
            for (auto sysname: inVarTHEO){
                hist_llvv[std::make_pair(sysname.first, var)]->Fill(fEvt[var], vEvt["vw"]->at(sysname.second) * weight_other);
                hist_eevv[std::make_pair(sysname.first, var)]->Fill(fEvt[var], vEvt["vw"]->at(sysname.second) * weight_other);
            }
        }
    }

    if (region == RG_2lXR::_mmvv){
        for (auto var: histVars) {
            if (this->NOMI){
                hist_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
                hist_mmvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
            }
            for (auto sysname: inVarSYST){
                hist_llvv[std::make_pair(sysname.second, var)]->Fill(fEvt[var], fEvt[sysname.first] * this->xsec);
                hist_mmvv[std::make_pair(sysname.second, var)]->Fill(fEvt[var], fEvt[sysname.first] * this->xsec);
            }
            for (auto sysname: inVarTHEO){
                hist_llvv[std::make_pair(sysname.first, var)]->Fill(fEvt[var], vEvt["vw"]->at(sysname.second) * weight_other);
                hist_mmvv[std::make_pair(sysname.first, var)]->Fill(fEvt[var], vEvt["vw"]->at(sysname.second) * weight_other);
            }
        }
    }

    if (region == RG_2lXR::_emvv){
        for (auto var: histVars) {
            if (this->NOMI){
                hist_emvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
            }
            for (auto sysname: inVarSYST){
                hist_emvv[std::make_pair(sysname.second, var)]->Fill(fEvt[var], fEvt[sysname.first] * this->xsec);
            }
            for (auto sysname: inVarTHEO){
                hist_emvv[std::make_pair(sysname.first, var)]->Fill(fEvt[var], vEvt["vw"]->at(sysname.second) * weight_other);
            }
        }
    }

}
