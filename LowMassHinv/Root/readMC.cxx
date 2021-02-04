#define LowMassHinv_readMC_cxx
#include <set>
#include "LowMassHinv/readMC.h"
#include "LowMassHinv/regions.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>


    readMC::readMC(std::string treename, std::string outfile, std::string outopt, bool THEO, bool SYST)
: tree(0), treename(treename), SYST(SYST), THEO(THEO)
{
    std::cout << treename << std::endl;

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
        "weight_trig"
    };
    inVarI = {
        "event_type",
        "event_3CR", 
        "n_bjets"
    };
    onVarF = {
        "event_3CR",
        "n_bjets",
        "event_type"
    };

    inVarTHEO.clear();
    //if (THEO){
        //initWeights(type);
        /*
           inVarTHEO["QCD55"] = "weight_var_th_MUR0p5_MUF0p5_PDF261000";
           inVarTHEO["QCD51"] = "weight_var_th_MUR0p5_MUF1_PDF261000";
           inVarTHEO["QCD15"] = "weight_var_th_MUR1_MUF0p5_PDF261000";
           inVarTHEO["QCD12"] = "weight_var_th_MUR1_MUF2_PDF261000";
           inVarTHEO["QCD21"] = "weight_var_th_MUR2_MUF1_PDF261000";
           inVarTHEO["QCD22"] = "weight_var_th_MUR2_MUF2_PDF261000";
           for (int i =0; i<=100; i++){
           inVarTHEO["PDF"+std::to_string(i)] = "weight_var_th_MUR1_MUF1_PDF"+std::to_string(i+261000);
           }
           */
    //}

    inVarSYST.clear();
    if (SYST){
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

    for (auto v: onVarF)    fEvt[v] = -999999;
    for (auto v: inVarF)    { BrEvt[v] = new TBranch(); fEvt[v] = -999999; }
    for (auto v: inVarI)    { BrEvt[v] = new TBranch(); iEvt[v] = -999999; }
    for (auto v: inVarTHEO) { BrEvt[v.second] = new TBranch(); fEvt[v.second] = -999999; }
    for (auto v: inVarSYST) { BrEvt[v.second] = new TBranch(); fEvt[v.second] = -999999; }

    mkHist();

    fout = new TFile(outfile.c_str(), outopt.c_str());

    //reader = new TMVA::Reader( "V:Color" );
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
}

readMC::~readMC(){
    for (auto h : hist_llvv)  delete h.second;
    for (auto h : hist_eevv)  delete h.second;
    for (auto h : hist_mmvv)  delete h.second;
    for (auto h : hist_emvv)  delete h.second;
    //for (auto b : BrEvt) delete b.second;
}

void readMC::Close(){
    fout->cd();
    for (auto h : hist_llvv)  h.second->Write();
    for (auto h : hist_eevv)  h.second->Write();
    for (auto h : hist_mmvv)  h.second->Write();
    for (auto h : hist_emvv)  h.second->Write();
    fout->Close();
}


bool readMC::LoopROOT(std::string filename, std::string treename, float factor){
    TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(filename.c_str());
    if (!f || !f->IsOpen()) f = new TFile(filename.c_str(), "read");
    f->GetObject(treename.c_str(), this->tree);

    std::cout << "      reading... " << filename << std::endl;

    if (filename.find("data")==std::string::npos) {
        hInfo = (TH1F*)f->Get("Hist/hInfo_PFlow");
        this->xsec = hInfo->GetBinContent(1) * 2.0 / hInfo->GetEntries() / hInfo->GetBinContent(2) * factor;
        if (filename.find("r9364")  != std::string::npos) this->xsec *= (3.21956 + 32.9653);
        if (filename.find("r10201") != std::string::npos) this->xsec *= 44.3074;
        if (filename.find("r10724") != std::string::npos) this->xsec *= 58.4501;
        this->isMC = true;
    }
    else{

        this->xsec = factor;
        this->isMC = false;
    }

    if (this->THEO){
        std::set<std::string> topDSID = {"410472", "410644", "410645", "410646", "410647"};
        std::set<std::string> tchantopDSID = {"410658", "410659"};
        std::set<std::string> wwDSID = {"361600"};
        std::set<std::string> sherpaDSID = {"345718", "364285", "364254", "364128", "364129", "364130", "364131", "364132", "364133", "364134", "364135", "364136", "364137", "364138", "364139", "364140", "364141"};
        std::set<std::string> sherpa222 = {
            "364242", "364243", "364244", "364245", "364246", "364247", "364248", "364249", // VVV
        };

        //for (auto DSID: topDSID) if (filename.find(DSID) != std::string::npos) initWeights("top");
        //for (auto DSID: tchantopDSID) if (filename.find(DSID) != std::string::npos) initWeights("tchan_top");
        //for (auto DSID: wwDSID) if (filename.find(DSID) != std::string::npos) initWeights("ww");
        //for (auto DSID: sherpaDSID) if (filename.find(DSID) != std::string::npos) initWeights("sherpa");
        for (auto DSID: sherpa222 ) if (filename.find(DSID) != std::string::npos) initWeights("sherpa222");
    }

    for (auto varname: inVarI) tree->SetBranchAddress(varname.c_str(), &iEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    for (auto varname: inVarF) tree->SetBranchAddress(varname.c_str(), &fEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    for (auto varname: inVarTHEO) tree->SetBranchAddress(varname.second.c_str(), &fEvt[varname.second.c_str()], &BrEvt[varname.second.c_str()]);
    for (auto varname: inVarSYST) tree->SetBranchAddress(varname.second.c_str(), &fEvt[varname.second.c_str()], &BrEvt[varname.second.c_str()]);

    Long64_t nentries = tree->GetEntriesFast();
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
        tree->GetEntry(jentry);
        int region = Cut();
        if (region == RG_emuMC::_NONE) continue;
        LoopEVT(region);
    }

    f->Close();
    return true;
}

void readMC::initWeights(std::string type){

    if (type == "sherpa222"){
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

}

bool readMC::mkHist(){
    mkHistVar("BDT", 200, -1, 1);
    mkHistVar("MET", 1000, 0, 1000);
    mkHistVar("mT", 3000, 0, 3000);
    return true;
}


bool readMC::mkHistVar(std::string var, int nbins, double left, double right){
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

int readMC::Cut()
{

    fEvt["event_type"] = iEvt["event_type"];
    fEvt["event_3CR"] = iEvt["event_3CR"];
    fEvt["event_4CR"] = 0;
    fEvt["SR_HM_LM"] = iEvt["SR_HM_LM"];
    fEvt["n_bjets"] = iEvt["n_bjets"];
    if (iEvt["event_3CR"]!=0)                     return RG_emuMC::_NONE;
    if (!(fEvt["M2Lep"]>76 && fEvt["M2Lep"]<106)) return RG_emuMC::_NONE;
    if (fEvt["met_tst"]<=90)                      return RG_emuMC::_NONE;
    if (iEvt["n_bjets"]!=0)                       return RG_emuMC::_NONE;
    if (fabs(fEvt["dLepR"])>=1.8)                 return RG_emuMC::_NONE;
    if (fEvt["met_signif"]<=9)                    return RG_emuMC::_NONE;

    if (iEvt["event_type"]==0)         return RG_emuMC::_MM;
    if (iEvt["event_type"]==1)         return RG_emuMC::_EE;
    if (iEvt["event_type"]==2)         return RG_emuMC::_EM;

    return RG_emuMC::_NONE;
}

void readMC::LoopEVT(int region)
{

    float sf;
    if (this->isMC) sf = this->xsec * fEvt["weight"];
    else sf = this->xsec;
    fEvt["BDT"] = reader->EvaluateMVA("BDTG");
    fEvt["MET"] = fEvt["met_tst"];
    fEvt["mT"] = fEvt["mT_ZZ"];

    if (region == RG_emuMC::_MM){
        for (auto var: histVars){
            hist_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
            hist_mmvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
            for (auto theo:inVarTHEO){
                hist_llvv[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
                hist_mmvv[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
            }
            for (auto syst:inVarSYST){
                hist_llvv[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->xsec);
                hist_mmvv[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->xsec);
            }
        }
    }

    if (region == RG_emuMC::_EE){
        for (auto var: histVars){
            hist_llvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
            hist_eevv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf);
            for (auto theo:inVarTHEO){
                hist_llvv[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
                hist_eevv[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
            }
            for (auto syst:inVarSYST){
                hist_llvv[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->xsec);
                hist_eevv[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->xsec);
            }
        }
    }

    if (region == RG_emuMC::_EM){
        if (fEvt["weight_trig"] == 0) fEvt["weight_trig"] = 1.0;
        if (!this->isMC) fEvt["weight_trig"] = 1.0;
        for (auto var: histVars){
            hist_emvv[std::make_pair(this->treename, var)]->Fill(fEvt[var], sf / fEvt["weight_trig"]);
            for (auto theo:inVarTHEO){
                hist_emvv[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf / fEvt["weight_trig"]);
            }
            for (auto syst:inVarSYST){
                hist_emvv[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->xsec / fEvt["weight_trig"]);
            }
        }
    }
}
