#define HZZ_LM_Michiel_Tree_cxx
#include "HZZ/LM_Michiel_Tree.h"
#include "HZZ/regions.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>


    LM_Michiel_Tree::LM_Michiel_Tree(std::string treename, std::string outfile, std::string outopt, bool THEO, bool SYST)
: tree(0), treename(treename), SYST(SYST), THEO(THEO)
{
    std::cout << treename << std::endl;

    inVarF = {
        "M2Lep"     , "leading_jet_pt" , "second_jet_pt" , "dLepR"   , "met_tst"       ,
        "met_signif"  , "mjj"            , "detajj"        , "dMetZPhi", "dPhiJ100met", 
        "lepplus_eta", "lepplus_phi", "lepminus_eta", "lepminus_phi", "frac_pT",
        "mT_Hinv", "sumpT_scalar", 
        "weight"  , "weight_pileup" , "mT_ZZ" , "Z_eta", "MetOHT",
        "weight_exp" , "weight_trig"    , "weight_jets"   , "weight_jvt"
    };
    inVarI = {
        "event_type" , "event_3CR"      , "n_jets"        , "n_bjets", "SR_HM_LM"
    };
    onVarF = {
        "event_3CR", "event_4CR", "SR_HM_LM", "n_bjets", "event_type", "dLepEta", "dLepPhi"
    };

    inVarTHEO.clear();
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
    }

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
        "Z_eta", "mT_ZZ", "dLepR", "dMetZPhi", "met_signif",
        "frac_pT", "MetOHT", "met_tst", "mT_Hinv", "M2Lep",
        "sumpT_scalar", "dLepEta", "dLepPhi"};
    std::vector<std::string> iMVA= {"event_3CR", "event_4CR", "SR_HM_LM", "n_bjets", "event_type"};
    reader->AddVariable("Z_eta", &fEvt["Z_eta"]);
    reader->AddVariable("mT_ZZ", &fEvt["mT_ZZ"]);
    reader->AddVariable("dLepR", &fEvt["dLepR"]);
    reader->AddVariable("dMetZPhi", &fEvt["dMetZPhi"]);
    reader->AddVariable("met_signif", &fEvt["met_signif"]);
    reader->AddVariable("frac_pT", &fEvt["frac_pT"]);
    reader->AddVariable("MetOHT", &fEvt["MetOHT"]);
    reader->AddVariable("met_tst", &fEvt["met_tst"]);
    reader->AddVariable("mT_Hinv", &fEvt["mT_Hinv"]);
    reader->AddVariable("M2Lep", &fEvt["M2Lep"]);
    reader->AddVariable("sumpT_scalar", &fEvt["sumpT_scalar"]);
    reader->AddVariable("fabs(lepplus_eta-lepminus_eta)", &fEvt["dLepEta"]);
    reader->AddVariable("fabs(lepplus_phi-lepminus_phi)", &fEvt["dLepPhi"]);
    //for (auto v: fMVA) reader->AddVariable(v, &fEvt[v]);
    for (auto v: iMVA) reader->AddSpectator(v, &fEvt[v]);
    reader->BookMVA( "BDTG", "/home/lijing/jROOT/source/HZZ/marco/TMVAClassification_BDTG.weights.xml");
}

LM_Michiel_Tree::~LM_Michiel_Tree(){
}

void LM_Michiel_Tree::Close(){
    fout->cd();
    for (auto h : llvv_GGH)  h.second->Write();
    for (auto h : eevv_GGH)  h.second->Write();
    for (auto h : mmvv_GGH)  h.second->Write();
    fout->Close();
}

bool LM_Michiel_Tree::LoopROOT(std::string filename, float xsec){
    TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(filename.c_str());
    if (!f || !f->IsOpen()) f = new TFile(filename.c_str(), "read");
    //f->GetObject(("tree_"+this->treename).c_str(), this->tree);
    f->GetObject("tree_PFLOW", this->tree);

    std::cout << "      reading... " << filename << std::endl;

    hInfo = (TH1F*)f->Get("Hist/hInfo_PFlow");
    this->xsec = hInfo->GetBinContent(1) * 2.0 / hInfo->GetEntries() / hInfo->GetBinContent(2);
    if (filename.find("r9364")  != std::string::npos) this->xsec *= (3.21956 + 32.9653);
    if (filename.find("r10201") != std::string::npos) this->xsec *= 44.3074;
    if (filename.find("r10724") != std::string::npos) this->xsec *= 58.4501;

    for (auto varname: inVarI) tree->SetBranchAddress(varname.c_str(), &iEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    for (auto varname: inVarF) tree->SetBranchAddress(varname.c_str(), &fEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    for (auto varname: inVarTHEO) tree->SetBranchAddress(varname.second.c_str(), &fEvt[varname.second.c_str()], &BrEvt[varname.second.c_str()]);
    for (auto varname: inVarSYST) tree->SetBranchAddress(varname.second.c_str(), &fEvt[varname.second.c_str()], &BrEvt[varname.second.c_str()]);
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


bool LM_Michiel_Tree::mkHist(){
    double binVBF[5] = {100, 420, 540, 820, 1700};
    mkHistVar("BDT", 40, -1, 1);

    /*
    h_BDT[std::make_pair(this->treename, "BDT" )] = new TH1F(("llvv__GGH__BDT__" +this->treename).c_str(), "", 40, -1, 1);
    h_BDT[std::make_pair(this->treename, "mTZZ")] = new TH1F(("llvv__GGH__mTZZ__"+this->treename).c_str(), "", 60, 0, 3000);

    //h_BDT[this->treename] = new TH1F(("llvv__GGH__BDT__"+this->treename).c_str(), "", 40, -1, 1);
    h_GGH[this->treename] = new TH1F(("llvv__GGH__mTZZ__"+this->treename).c_str(), "", 60, 0, 3000);
    h_VBF[this->treename] = new TH1F(("llvv__VBF__mTZZ__"+this->treename).c_str(), "", 170, 0, 1700);
    //h_VBF[this->treename] = h_VBF[this->treename].Rebin(4, ("llvv__VBF__mTZZ__"+this->treename).c_str(), binVBF);

    h_GGH["ee_" + this->treename] = new TH1F(("llvv__ee__GGH__mTZZ__"+this->treename).c_str(), "", 60, 0, 3000);
    h_GGH["mm_" + this->treename] = new TH1F(("llvv__mm__GGH__mTZZ__"+this->treename).c_str(), "", 60, 0, 3000);
    h_VBF["ee_" + this->treename] = new TH1F(("llvv__ee__VBF__mTZZ__"+this->treename).c_str(), "", 170, 0, 1700);
    h_VBF["mm_" + this->treename] = new TH1F(("llvv__mm__VBF__mTZZ__"+this->treename).c_str(), "", 170, 0, 1700);
    //h_VBF["ee_" + this->treename] = h_VBF["ee_" + this->treename].Rebin(4, ("llvv__ee__VBF__mTZZ__"+this->treename).c_str(), binVBF);
    //h_VBF["mm_" + this->treename] = h_VBF["mm_" + this->treename].Rebin(4, ("llvv__mm__VBF__mTZZ__"+this->treename).c_str(), binVBF);

    for (auto v: inVarTHEO){
        h_GGH[v.first]         = new TH1F(("llvv__GGH__mTZZ__"    +v.first).c_str(), "", 60, 0, 3000);
        h_GGH["ee_" + v.first] = new TH1F(("llvv__ee__GGH__mTZZ__"+v.first).c_str(), "", 60, 0, 3000);
        h_GGH["mm_" + v.first] = new TH1F(("llvv__mm__GGH__mTZZ__"+v.first).c_str(), "", 60, 0, 3000);
        h_VBF[v.first]         = new TH1F(("llvv__VBF__mTZZ__"    +v.first).c_str(), "", 170, 0, 1700);
        h_VBF["ee_" + v.first] = new TH1F(("llvv__ee__VBF__mTZZ__"+v.first).c_str(), "", 170, 0, 1700);
        h_VBF["mm_" + v.first] = new TH1F(("llvv__mm__VBF__mTZZ__"+v.first).c_str(), "", 170, 0, 1700);
        //h_VBF[v.first]         = h_VBF[v.first]        .Rebin(4, ("llvv__VBF__mTZZ__"    +v.first).c_str(), binVBF);
        //h_VBF["ee_" + v.first] = h_VBF["ee_" + v.first].Rebin(4, ("llvv__ee__VBF__mTZZ__"+v.first).c_str(), binVBF);
        //h_VBF["mm_" + v.first] = h_VBF["mm_" + v.first].Rebin(4, ("llvv__mm__VBF__mTZZ__"+v.first).c_str(), binVBF);
    }
    */

    return true;
}


bool LM_Michiel_Tree::mkHistVar(std::string var, int nbins, double left, double right){
    histVars.push_back(var);
    llvv_GGH[std::make_pair(this->treename, var )] = new TH1F(("llvv__GGH__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    eevv_GGH[std::make_pair(this->treename, var )] = new TH1F(("eevv__GGH__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    mmvv_GGH[std::make_pair(this->treename, var )] = new TH1F(("mmvv__GGH__"+var+"__"+this->treename).c_str(), "", nbins, left, right);
    for (auto theo:inVarTHEO){
        llvv_GGH[std::make_pair(theo.first, var)] = new TH1F(("llvv__GGH__"+var+"__"+theo.first).c_str(), "", nbins, left, right);
        eevv_GGH[std::make_pair(theo.first, var)] = new TH1F(("eevv__GGH__"+var+"__"+theo.first).c_str(), "", nbins, left, right);
        mmvv_GGH[std::make_pair(theo.first, var)] = new TH1F(("mmvv__GGH__"+var+"__"+theo.first).c_str(), "", nbins, left, right);
    }
    for (auto syst:inVarSYST){
        llvv_GGH[std::make_pair(syst.first, var)] = new TH1F(("llvv__GGH__"+var+"__"+syst.first).c_str(), "", nbins, left, right);
        eevv_GGH[std::make_pair(syst.first, var)] = new TH1F(("eevv__GGH__"+var+"__"+syst.first).c_str(), "", nbins, left, right);
        mmvv_GGH[std::make_pair(syst.first, var)] = new TH1F(("mmvv__GGH__"+var+"__"+syst.first).c_str(), "", nbins, left, right);
    }
    return true;
}

int LM_Michiel_Tree::Cut()
{

    fEvt["event_type"] = iEvt["event_type"];
    fEvt["event_3CR"] = iEvt["event_3CR"];
    fEvt["event_4CR"] = 0;
    fEvt["SR_HM_LM"] = iEvt["SR_HM_LM"];
    fEvt["n_bjets"] = iEvt["n_bjets"];
    fEvt["dLepEta"] = fabs(fEvt["lepplus_eta"] - fEvt["lepminus_eta"]);
    fEvt["dLepPhi"] = fabs(fEvt["lepplus_phi"] - fEvt["lepminus_phi"]);
    fEvt["mTZZ"] = fEvt["mT_ZZ"];
    if (iEvt["event_3CR"]!=0)                     return RG::_NONE;
    if (!(fEvt["M2Lep"]>76 && fEvt["M2Lep"]<106)) return RG::_NONE;
    if (fEvt["met_tst"]<=90)                      return RG::_NONE;
    if (iEvt["n_bjets"]!=0)                       return RG::_NONE;
    if (fabs(fEvt["dLepR"])>=1.8)                 return RG::_NONE;
    if (fabs(fEvt["dMetZPhi"])<=2.5)              return RG::_NONE;
    if (fabs(fEvt["dPhiJ100met"])<=0.4)           return RG::_NONE;
    if (fEvt["met_signif"]<=9)                    return RG::_NONE;

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

void LM_Michiel_Tree::LoopEVT(int region)
{
    float sf = this->xsec * fEvt["weight"];
    fEvt["BDT"] = reader->EvaluateMVA("BDTG");

    if (region == RG::_VBF_MM){
        if (fabs(fEvt["weight_gen"])<=100){
            for (auto var: histVars){
                llvv_GGH[std::make_pair(this->treename, var)]->Fill(fEvt[var], fEvt["weight"] * this->xsec);
                mmvv_GGH[std::make_pair(this->treename, var)]->Fill(fEvt[var], fEvt["weight"] * this->xsec);
                for (auto theo:inVarTHEO){
                    llvv_GGH[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
                    mmvv_GGH[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
                }
                for (auto syst:inVarSYST){
                    llvv_GGH[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->xsec);
                    mmvv_GGH[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->xsec);
                }
            }
        }
    }

    if (region == RG::_VBF_EE){
        if (fabs(fEvt["weight_gen"])<=100){
            for (auto var: histVars){
                llvv_GGH[std::make_pair(this->treename, var)]->Fill(fEvt[var], fEvt["weight"] * this->xsec);
                eevv_GGH[std::make_pair(this->treename, var)]->Fill(fEvt[var], fEvt["weight"] * this->xsec);
                for (auto theo:inVarTHEO){
                    llvv_GGH[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
                    eevv_GGH[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
                }
                for (auto syst:inVarSYST){
                    llvv_GGH[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->xsec);
                    eevv_GGH[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->xsec);
                }
            }
        }
    }

    if (region == RG::_GGH_MM){
        if (fabs(fEvt["weight_gen"])<=100){
            for (auto var: histVars){
                llvv_GGH[std::make_pair(this->treename, var)]->Fill(fEvt[var], fEvt["weight"] * this->xsec);
                mmvv_GGH[std::make_pair(this->treename, var)]->Fill(fEvt[var], fEvt["weight"] * this->xsec);
                for (auto theo:inVarTHEO){
                    llvv_GGH[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
                    mmvv_GGH[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
                }
                for (auto syst:inVarSYST){
                    llvv_GGH[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->xsec);
                    mmvv_GGH[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->xsec);
                }
            }
        }
    }

    if (region == RG::_GGH_EE){
        if (fabs(fEvt["weight_gen"])<=100){
            for (auto var: histVars){
                llvv_GGH[std::make_pair(this->treename, var)]->Fill(fEvt[var], fEvt["weight"] * this->xsec);
                eevv_GGH[std::make_pair(this->treename, var)]->Fill(fEvt[var], fEvt["weight"] * this->xsec);
                for (auto theo:inVarTHEO){
                    llvv_GGH[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
                    eevv_GGH[std::make_pair(theo.first, var)]->Fill(fEvt[var], fEvt[theo.second] * sf);
                }
                for (auto syst:inVarSYST){
                    llvv_GGH[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->xsec);
                    eevv_GGH[std::make_pair(syst.first, var)]->Fill(fEvt[var], fEvt[syst.second] * this->xsec);
                }
            }
        }
    }
}
