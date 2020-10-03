#define LowMassHinv_HinvComb_cxx
#include "LowMassHinv/HinvComb.h"
#include "LowMassHinv/regions.h"
#include <TH2.h>
#include <TLorentzVector.h>
#include <TStyle.h>
#include <TCanvas.h>


    HinvComb::HinvComb(std::string treename, std::string outfile, std::string outopt, bool THEO, bool SYST)
: tree(0), treename(treename), SYST(SYST), THEO(THEO),_EWcorr_error(false)
{
    std::cout << treename << std::endl;

    inVarF = {
        "M2Lep"     , "leading_jet_pt" , "second_jet_pt" , "dLepR"   , "met_tst"       ,
        "met_signif"  , "mjj"            , "detajj"        , "dMetZPhi", "dPhiJ100met", 
        "lepplus_eta", "lepplus_phi", "lepminus_eta", "lepminus_phi", "frac_pT",
        "mT_Hinv", "sumpT_scalar", 
        "weight"  , "weight_pileup" , "mT_ZZ" , "Z_eta", "MetOHT",
        "weight_exp" , "weight_trig"    , "weight_jets"   , "weight_jvt", 
        "lep3rd_pt","lep3rd_eta","lep3rd_phi","lep3rd_m",
        "met_px_tst","met_py_tst", "truth_H_pt",
    };
    inVarI = {
        "event_type", "event_3CR",  "event_4CR", "n_jets", "n_bjets", "SR_HM_LM", "run"
    };
    inVarL = {
        "event"
    };
    onVarF = {
        "event_3CR", "event_4CR", "SR_HM_LM", "n_bjets", "event_type", "dLepEta", "dLepPhi"
    };


    for (auto v: onVarF)    fEvt[v] = -999999;
    for (auto v: inVarF)    { BrEvt[v] = new TBranch(); fEvt[v] = -999999; }
    for (auto v: inVarL)    { BrEvt[v] = new TBranch(); lEvt[v] = -999999; }
    for (auto v: inVarI)    { BrEvt[v] = new TBranch(); iEvt[v] = -999999; }


    fout = new TFile(outfile.c_str(), outopt.c_str());

    tree_out = new TTree("physics","physics");
    tree_out->Branch("run_number",&run_number,"run_number/I");
    tree_out->Branch("event_number",&event_number,"event_number/l");
    tree_out->Branch("truth_H_pt",&truth_H_pt,"truth_H_pt/F");
    tree_out->Branch("category",&category);

}

HinvComb::~HinvComb(){
}

void HinvComb::Close(){
    fout->cd();
    tree_out->Write();
    fout->Close();
}

bool HinvComb::LoopROOT(std::string filename, std::string treename){
    TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(filename.c_str());
    if (!f || !f->IsOpen()) f = new TFile(filename.c_str(), "read");

    f->GetObject(treename.c_str(), this->tree);

    std::cout << "      reading... " << filename << std::endl;

    for (auto varname: inVarI) if (tree->FindBranch(varname.c_str())) tree->SetBranchAddress(varname.c_str(), &iEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    for (auto varname: inVarF) if (tree->FindBranch(varname.c_str())) tree->SetBranchAddress(varname.c_str(), &fEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    for (auto varname: inVarL) if (tree->FindBranch(varname.c_str())) tree->SetBranchAddress(varname.c_str(), &lEvt[varname.c_str()], &BrEvt[varname.c_str()]);

    Long64_t nentries = tree->GetEntriesFast();
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
        tree->GetEntry(jentry);
        int region = Cut();
        if (region == RG_HinvComb::_NONE) continue;
        //std::cout << jentry << "    " << region << std::endl;
        LoopEVT(region);
        //printf("%i\n", region);
        tree_out->Fill();
        category.clear();
    }

    f->Close();
    return true;
}




int HinvComb::Cut()
{

    fEvt["event_type"] = iEvt["event_type"];
    fEvt["event_3CR"] = iEvt["event_3CR"];
    //fEvt["event_4CR"] = 0;
    //fEvt["SR_HM_LM"] = iEvt["SR_HM_LM"];
    //fEvt["dLepEta"] = fabs(fEvt["lepplus_eta"] - fEvt["lepminus_eta"]);
    //fEvt["dLepPhi"] = fabs(fEvt["lepplus_phi"] - fEvt["lepminus_phi"]);
    //fEvt["mTZZ"] = fEvt["mT_ZZ"];

    //4lCR
    if (iEvt["event_4CR"]==3)         return RG_HinvComb::_4CR;

    //common cut
    if (!(fEvt["M2Lep"]>76 && fEvt["M2Lep"]<106)) return RG_HinvComb::_NONE;
    if (iEvt["n_bjets"]!=0)                       return RG_HinvComb::_NONE;

    //3l CR
    if (iEvt["event_3CR"]>0){
        TLorentzVector met4v; 
        TLorentzVector third4v;
        float dphi_3rdlep_met, mT_W;

        third4v.SetPtEtaPhiM(fEvt["lep3rd_pt"], fEvt["lep3rd_eta"] , fEvt["lep3rd_phi"] , fEvt["lep3rd_m"] );
        met4v.SetPxPyPzE(fEvt["met_px_tst"], fEvt["met_py_tst"],  0. , fEvt["met_tst"] );
        dphi_3rdlep_met = fabs(third4v.DeltaPhi(met4v));
        mT_W = sqrt (2*fEvt["lep3rd_pt"]*met4v.Pt()*(1 - cos(dphi_3rdlep_met)));

        //printf("mT_W = %.2f\n",mT_W);

        if(mT_W>60 && fEvt["met_signif"]>3)    
            return RG_HinvComb::_3CR;
        return RG_HinvComb::_NONE;
    }

    //ZjetCR, emuCR and SR
    if (fEvt["met_tst"]<=90)                      return RG_HinvComb::_NONE;
    if (fabs(fEvt["dLepR"])>=1.8)                 return RG_HinvComb::_NONE;

    if (iEvt["event_3CR"]==0){
        if (fEvt["met_signif"]<=9)                    return RG_HinvComb::_ZjetCR;
        if (fEvt["met_signif"]>9){
            if (iEvt["event_type"]==0)         return RG_HinvComb::_SR;
            if (iEvt["event_type"]==1)         return RG_HinvComb::_SR;
            if (iEvt["event_type"]==2)         return RG_HinvComb::_emuCR;
        }
    }
    return RG_HinvComb::_NONE;
}

void HinvComb::LoopEVT(int region)
{


    run_number = iEvt["run"];
    event_number = lEvt["event"];
    truth_H_pt = fEvt["truth_H_pt"];


    if (region == RG_HinvComb::_SR){
        category.push_back(91000);
    }

    if (region == RG_HinvComb::_3CR){
        category.push_back(91010);
    }

    if (region == RG_HinvComb::_4CR){
        category.push_back(91011);
    }

    if (region == RG_HinvComb::_emuCR){
        category.push_back(91012);
    }
    if (region == RG_HinvComb::_ZjetCR){
        category.push_back(91013);
    }

}
