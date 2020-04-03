#define HZZ_Acceptance_truth_cxx
#include "HZZ/Acceptance_truth.h"
#include "HZZ/regions.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>


Acceptance_truth::Acceptance_truth(std::string treename, std::string outfile, std::string outopt, bool THEO)
: tree(0), treename(treename), THEO(THEO)
{
    std::cout << treename << std::endl;

    inVarF = {
        "weight", "M2L", "PtL1", "PtL2", "EtaL1", "EtaL2",
        "PhiL1", "PhiL2", "MJJ", "dEtaJJ", "PtJ1", "PtJ2", "EtaJ1",
        "EtaJ2", "PhiJ1", "PhiJ2", "MET", "dLepR", "dMetZPhi", "dPhiJ100met", "mTZZ"
    };
    inVarI = {
        "event_type" ,"ggH", "TwoJ", "VBF" ,"nele" ,"nmuo" ,"ntau", "nJets"
    };
    if (THEO){
        inVarV= { "vw" };
        inVarTHEO["QCD55"] = 4;
        inVarTHEO["QCD15"] = 6;
        inVarTHEO["QCD51"] = 5;
        inVarTHEO["QCD12"] = 8;
        inVarTHEO["QCD21"] = 9;
        inVarTHEO["QCD22"] = 10;
        for (int i =11; i<111; i++) inVarTHEO["PDF"+std::to_string(i-11)] = i;
    }

    for (auto v: inVarV)    { BrEvt[v] = new TBranch(); vEvt[v] = new std::vector<float>(); }
    for (auto v: inVarF)    { BrEvt[v] = new TBranch(); fEvt[v] = -999999; }
    for (auto v: inVarI)    { BrEvt[v] = new TBranch(); iEvt[v] = -999999; }

    mkHist();

    fout = new TFile(outfile.c_str(), outopt.c_str());
}

Acceptance_truth::~Acceptance_truth(){
}

void Acceptance_truth::Close(){
    fout->cd();
    for (auto h : hDAOD)  h.second.Write();
    //for (auto h : h2JET)  h.second.Write();
    for (auto h : h_GGH)  h.second.Write();
    for (auto h : h_VBF)  h.second.Write();
    for (auto h : hDAOD) { printf(" YLD %7.5f\n", h.second.Integral()); break; } 
    //for (auto h : h2JET) { printf(" 2JET %7.5f\n", h.second.Integral()); break; } 
    for (auto h : h_GGH) { printf("  GGH %7.5f\n", h.second.Integral()); break; } 
    for (auto h : h_VBF) { printf("  VBF %7.5f\n", h.second.Integral()); break; } 
    fout->Close();
}

bool Acceptance_truth::LoopROOT(std::string filename, float xsec){
    TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(filename.c_str());
    if (!f || !f->IsOpen()) f = new TFile(filename.c_str(), "read");
    f->GetObject("analysis", this->tree);

    std::cout << "      reading... " << filename << std::endl;

    //hInfo = (TH1F*)f->Get("hInfo");
    //if (filename.find("r9364")  != std::string::npos) this->xsec = xsec * (3219.56 + 32965.3);
    //if (filename.find("r10201") != std::string::npos) this->xsec = xsec * 44307.4;
    //if (filename.find("r10724") != std::string::npos) this->xsec = xsec * 58450.1;
    //this->xsec *= 1.0 / (3219.56 + 32965.3 + 44307.4 + 58450.1);

    for (auto varname: inVarI) tree->SetBranchAddress(varname.c_str(), &iEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    for (auto varname: inVarF) tree->SetBranchAddress(varname.c_str(), &fEvt[varname.c_str()], &BrEvt[varname.c_str()]);
    for (auto varname: inVarV) tree->SetBranchAddress(varname.c_str(), &vEvt[varname.c_str()], &BrEvt[varname.c_str()]);

    Long64_t nentries = tree->GetEntriesFast();
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
        tree->GetEntry(jentry);
        int region = Cut();
        LoopEVT(region);
    }

    f->Close();
    return true;
}


bool Acceptance_truth::mkHist(){
    hDAOD[this->treename] = TH1F(("truth__DAOD__"+this->treename).c_str(), "", 1, 0, 10);
    //h2JET[this->treename] = TH1F(("truth__2JET__"+this->treename).c_str(), "", 1, 0, 10);
    h_GGH[this->treename] = TH1F(("truth___GGH__"+this->treename).c_str(), "", 1, 0, 10);
    h_VBF[this->treename] = TH1F(("truth___VBF__"+this->treename).c_str(), "", 1, 0, 10);
    hDAOD[this->treename+ "mTZZ"] = TH1F(("truth__DAOD__mTZZ__"+this->treename).c_str(), "", 60, 0, 3000);
    //h2JET[this->treename+ "mTZZ"] = TH1F(("truth__2JET__mTZZ__"+this->treename).c_str(), "", 60, 0, 3000);
    h_GGH[this->treename+ "mTZZ"] = TH1F(("truth___GGH__mTZZ__"+this->treename).c_str(), "", 60, 0, 3000);
    h_VBF[this->treename+ "mTZZ"] = TH1F(("truth___VBF__mTZZ__"+this->treename).c_str(), "", 60, 0, 3000);

    hDAOD["ee_"+this->treename] = TH1F(("truth__ee__DAOD__"+this->treename).c_str(), "", 1, 0, 10);
    //h2JET["ee_"+this->treename] = TH1F(("truth__ee__2JET__"+this->treename).c_str(), "", 1, 0, 10);
    h_GGH["ee_"+this->treename] = TH1F(("truth__ee___GGH__"+this->treename).c_str(), "", 1, 0, 10);
    h_VBF["ee_"+this->treename] = TH1F(("truth__ee___VBF__"+this->treename).c_str(), "", 1, 0, 10);
    hDAOD["ee_"+this->treename+ "mTZZ"] = TH1F(("truth__ee__DAOD__mTZZ__"+this->treename).c_str(), "", 60, 0, 3000);
    //h2JET["ee_"+this->treename+ "mTZZ"] = TH1F(("truth__ee__2JET__mTZZ__"+this->treename).c_str(), "", 60, 0, 3000);
    h_GGH["ee_"+this->treename+ "mTZZ"] = TH1F(("truth__ee___GGH__mTZZ__"+this->treename).c_str(), "", 60, 0, 3000);
    h_VBF["ee_"+this->treename+ "mTZZ"] = TH1F(("truth__ee___VBF__mTZZ__"+this->treename).c_str(), "", 60, 0, 3000);

    hDAOD["mm_"+this->treename] = TH1F(("truth__mm__DAOD__"+this->treename).c_str(), "", 1, 0, 10);
    //h2JET["mm_"+this->treename] = TH1F(("truth__mm__2JET__"+this->treename).c_str(), "", 1, 0, 10);
    h_GGH["mm_"+this->treename] = TH1F(("truth__mm___GGH__"+this->treename).c_str(), "", 1, 0, 10);
    h_VBF["mm_"+this->treename] = TH1F(("truth__mm___VBF__"+this->treename).c_str(), "", 1, 0, 10);
    hDAOD["mm_"+this->treename+ "mTZZ"] = TH1F(("truth__mm__DAOD__mTZZ__"+this->treename).c_str(), "", 60, 0, 3000);
    //h2JET["mm_"+this->treename+ "mTZZ"] = TH1F(("truth__mm__2JET__mTZZ__"+this->treename).c_str(), "", 60, 0, 3000);
    h_GGH["mm_"+this->treename+ "mTZZ"] = TH1F(("truth__mm___GGH__mTZZ__"+this->treename).c_str(), "", 60, 0, 3000);
    h_VBF["mm_"+this->treename+ "mTZZ"] = TH1F(("truth__mm___VBF__mTZZ__"+this->treename).c_str(), "", 60, 0, 3000);

    for (auto v: inVarTHEO){
        hDAOD[v.first] = TH1F(("truth__DAOD__"+v.first).c_str(), "", 1, 0, 10);
    //    h2JET[v.first] = TH1F(("truth__2JET__"+v.first).c_str(), "", 1, 0, 10);
        h_GGH[v.first] = TH1F(("truth___GGH__"+v.first).c_str(), "", 1, 0, 10);
        h_VBF[v.first] = TH1F(("truth___VBF__"+v.first).c_str(), "", 1, 0, 10);
        hDAOD[v.first+ "mTZZ"] = TH1F(("truth__DAOD__mTZZ__"+v.first).c_str(), "", 60, 0, 3000);
    //    h2JET[v.first+ "mTZZ"] = TH1F(("truth__2JET__mTZZ__"+v.first).c_str(), "", 60, 0, 3000);
        h_GGH[v.first+ "mTZZ"] = TH1F(("truth___GGH__mTZZ__"+v.first).c_str(), "", 60, 0, 3000);
        h_VBF[v.first+ "mTZZ"] = TH1F(("truth___VBF__mTZZ__"+v.first).c_str(), "", 60, 0, 3000);

        hDAOD["ee_"+v.first] = TH1F(("truth__ee__DAOD__"+v.first).c_str(), "", 1, 0, 10);
    //    h2JET["ee_"+v.first] = TH1F(("truth__ee__2JET__"+v.first).c_str(), "", 1, 0, 10);
        h_GGH["ee_"+v.first] = TH1F(("truth__ee___GGH__"+v.first).c_str(), "", 1, 0, 10);
        h_VBF["ee_"+v.first] = TH1F(("truth__ee___VBF__"+v.first).c_str(), "", 1, 0, 10);
        hDAOD["ee_"+v.first+ "mTZZ"] = TH1F(("truth__ee__DAOD__mTZZ__"+v.first).c_str(), "", 60, 0, 3000);
    //    h2JET["ee_"+v.first+ "mTZZ"] = TH1F(("truth__ee__2JET__mTZZ__"+v.first).c_str(), "", 60, 0, 3000);
        h_GGH["ee_"+v.first+ "mTZZ"] = TH1F(("truth__ee___GGH__mTZZ__"+v.first).c_str(), "", 60, 0, 3000);
        h_VBF["ee_"+v.first+ "mTZZ"] = TH1F(("truth__ee___VBF__mTZZ__"+v.first).c_str(), "", 60, 0, 3000);

        hDAOD["mm_"+v.first] = TH1F(("truth__mm__DAOD__"+v.first).c_str(), "", 1, 0, 10);
    //    h2JET["mm_"+v.first] = TH1F(("truth__mm__2JET__"+v.first).c_str(), "", 1, 0, 10);
        h_GGH["mm_"+v.first] = TH1F(("truth__mm___GGH__"+v.first).c_str(), "", 1, 0, 10);
        h_VBF["mm_"+v.first] = TH1F(("truth__mm___VBF__"+v.first).c_str(), "", 1, 0, 10);
        hDAOD["mm_"+v.first+ "mTZZ"] = TH1F(("truth__mm__DAOD__mTZZ__"+v.first).c_str(), "", 60, 0, 3000);
    //    h2JET["mm_"+v.first+ "mTZZ"] = TH1F(("truth__mm__2JET__mTZZ__"+v.first).c_str(), "", 60, 0, 3000);
        h_GGH["mm_"+v.first+ "mTZZ"] = TH1F(("truth__mm___GGH__mTZZ__"+v.first).c_str(), "", 60, 0, 3000);
        h_VBF["mm_"+v.first+ "mTZZ"] = TH1F(("truth__mm___VBF__mTZZ__"+v.first).c_str(), "", 60, 0, 3000);
    }

    return true;
}


int Acceptance_truth::Cut()
{

    if (!(fEvt["M2L"]>76 && fEvt["M2L"]<106)) return RG::_NONE;
    if (fEvt["MET"]<=120)                     return RG::_NONE;
    if (fabs(fEvt["dLepR"])>=1.8)                 return RG::_NONE;
    if (fabs(fEvt["dMetZPhi"])<=2.5)              return RG::_NONE;
    if (fabs(fEvt["dPhiJ100met"])<=0.4)           return RG::_NONE;
    //printf("y\n");

    if (iEvt["nJets"]>=2 && fEvt["PtJ1"]>30 && fEvt["PtJ2"]>30){
        if (fEvt["MJJ"]>550 && fabs(fEvt["dEtaJJ"])>4.4){
            if (iEvt["event_type"]==0) return RG::_VBF_MM;
            if (iEvt["event_type"]==1) return RG::_VBF_EE;
            if (iEvt["event_type"]==2) return RG::_VBF_EM;
        }
        if (iEvt["event_type"]==0)     return RG::_2JET_MM;
        if (iEvt["event_type"]==1)     return RG::_2JET_EE;
        if (iEvt["event_type"]==2)     return RG::_2JET_EM;
    }
    if (iEvt["event_type"]==0)         return RG::_GGH_MM;
    if (iEvt["event_type"]==1)         return RG::_GGH_EE;
    if (iEvt["event_type"]==2)         return RG::_GGH_EM;

    return RG::_NONE;
}

void Acceptance_truth::LoopEVT(int region)
{

    if (fabs(fEvt["weight"])>100) return;
    for (auto v: inVarTHEO){
        if (fabs(vEvt["vw"]->at(v.second))>100) return;
    }

    hDAOD[this->treename].Fill(1, fEvt["weight"]);
    for (auto v: inVarTHEO){
        hDAOD[v.first].Fill(1, vEvt["vw"]->at(v.second));
    }
    if (region == RG::_VBF_EE){
        h_GGH["ee_"+this->treename].Fill(1, fEvt["weight"]);
        //h2JET["ee_"+this->treename].Fill(1, fEvt["weight"]);
        h_VBF["ee_"+this->treename].Fill(1, fEvt["weight"]);
        h_GGH["ee_"+this->treename+"mTZZ"].Fill(fEvt["mTZZ"], fEvt["weight"]);
        //h2JET["ee_"+this->treename+"mTZZ"].Fill(fEvt["mTZZ"], fEvt["weight"]);
        h_VBF["ee_"+this->treename+"mTZZ"].Fill(fEvt["mTZZ"], fEvt["weight"]);
        for (auto v: inVarTHEO){
            h_GGH["ee_"+v.first].Fill(1, vEvt["vw"]->at(v.second));
            //h2JET["ee_"+v.first].Fill(1, vEvt["vw"]->at(v.second));
            h_VBF["ee_"+v.first].Fill(1, vEvt["vw"]->at(v.second));
            h_GGH["ee_"+v.first+"mTZZ"].Fill(fEvt["mTZZ"], vEvt["vw"]->at(v.second));
            //h2JET["ee_"+v.first+"mTZZ"].Fill(fEvt["mTZZ"], vEvt["vw"]->at(v.second));
            h_VBF["ee_"+v.first+"mTZZ"].Fill(fEvt["mTZZ"], vEvt["vw"]->at(v.second));
        }
        h_GGH[this->treename].Fill(1, fEvt["weight"]);
        //h2JET[this->treename].Fill(1, fEvt["weight"]);
        h_VBF[this->treename].Fill(1, fEvt["weight"]);
        h_GGH[this->treename+"mTZZ"].Fill(fEvt["mTZZ"], fEvt["weight"]);
        //h2JET[this->treename+"mTZZ"].Fill(fEvt["mTZZ"], fEvt["weight"]);
        h_VBF[this->treename+"mTZZ"].Fill(fEvt["mTZZ"], fEvt["weight"]);
        for (auto v: inVarTHEO){
            h_GGH[v.first].Fill(1, vEvt["vw"]->at(v.second));
            //h2JET[v.first].Fill(1, vEvt["vw"]->at(v.second));
            h_VBF[v.first].Fill(1, vEvt["vw"]->at(v.second));
            h_GGH[v.first+"mTZZ"].Fill(fEvt["mTZZ"], vEvt["vw"]->at(v.second));
            //h2JET[v.first+"mTZZ"].Fill(fEvt["mTZZ"], vEvt["vw"]->at(v.second));
            h_VBF[v.first+"mTZZ"].Fill(fEvt["mTZZ"], vEvt["vw"]->at(v.second));
        }
    }
    if (region == RG::_VBF_MM){
        h_GGH["mm_"+this->treename].Fill(1, fEvt["weight"]);
        //h2JET["mm_"+this->treename].Fill(1, fEvt["weight"]);
        h_VBF["mm_"+this->treename].Fill(1, fEvt["weight"]);
        h_GGH["mm_"+this->treename+"mTZZ"].Fill(fEvt["mTZZ"], fEvt["weight"]);
        //h2JET["mm_"+this->treename+"mTZZ"].Fill(fEvt["mTZZ"], fEvt["weight"]);
        h_VBF["mm_"+this->treename+"mTZZ"].Fill(fEvt["mTZZ"], fEvt["weight"]);
        for (auto v: inVarTHEO){
            h_GGH["mm_"+v.first].Fill(1, vEvt["vw"]->at(v.second));
            //h2JET["mm_"+v.first].Fill(1, vEvt["vw"]->at(v.second));
            h_VBF["mm_"+v.first].Fill(1, vEvt["vw"]->at(v.second));
            h_GGH["mm_"+v.first+"mTZZ"].Fill(fEvt["mTZZ"], vEvt["vw"]->at(v.second));
            //h2JET["mm_"+v.first+"mTZZ"].Fill(fEvt["mTZZ"], vEvt["vw"]->at(v.second));
            h_VBF["mm_"+v.first+"mTZZ"].Fill(fEvt["mTZZ"], vEvt["vw"]->at(v.second));
        }
        h_GGH[this->treename].Fill(1, fEvt["weight"]);
        //h2JET[this->treename].Fill(1, fEvt["weight"]);
        h_VBF[this->treename].Fill(1, fEvt["weight"]);
        h_GGH[this->treename+"mTZZ"].Fill(fEvt["mTZZ"], fEvt["weight"]);
        //h2JET[this->treename+"mTZZ"].Fill(fEvt["mTZZ"], fEvt["weight"]);
        h_VBF[this->treename+"mTZZ"].Fill(fEvt["mTZZ"], fEvt["weight"]);
        for (auto v: inVarTHEO){
            h_GGH[v.first].Fill(1, vEvt["vw"]->at(v.second));
         //   h2JET[v.first].Fill(1, vEvt["vw"]->at(v.second));
            h_VBF[v.first].Fill(1, vEvt["vw"]->at(v.second));
            h_GGH[v.first+"mTZZ"].Fill(fEvt["mTZZ"], vEvt["vw"]->at(v.second));
          //  h2JET[v.first+"mTZZ"].Fill(fEvt["mTZZ"], vEvt["vw"]->at(v.second));
            h_VBF[v.first+"mTZZ"].Fill(fEvt["mTZZ"], vEvt["vw"]->at(v.second));
        }
    }

    if (region == RG::_2JET_EE){
        h_GGH["ee_"+this->treename].Fill(1, fEvt["weight"]);
        //h2JET["ee_"+this->treename].Fill(1, fEvt["weight"]);
        h_GGH["ee_"+this->treename+"mTZZ"].Fill(fEvt["mTZZ"], fEvt["weight"]);
        //h2JET["ee_"+this->treename+"mTZZ"].Fill(fEvt["mTZZ"], fEvt["weight"]);
        for (auto v: inVarTHEO){
            h_GGH["ee_"+v.first].Fill(1, vEvt["vw"]->at(v.second));
            //h2JET["ee_"+v.first].Fill(1, vEvt["vw"]->at(v.second));
            h_GGH["ee_"+v.first+"mTZZ"].Fill(fEvt["mTZZ"], vEvt["vw"]->at(v.second));
            //h2JET["ee_"+v.first+"mTZZ"].Fill(fEvt["mTZZ"], vEvt["vw"]->at(v.second));
        }
        h_GGH[this->treename].Fill(1, fEvt["weight"]);
        //h2JET[this->treename].Fill(1, fEvt["weight"]);
        h_GGH[this->treename+"mTZZ"].Fill(fEvt["mTZZ"], fEvt["weight"]);
        //h2JET[this->treename+"mTZZ"].Fill(fEvt["mTZZ"], fEvt["weight"]);
        for (auto v: inVarTHEO){
            h_GGH[v.first].Fill(1, vEvt["vw"]->at(v.second));
            //h2JET[v.first].Fill(1, vEvt["vw"]->at(v.second));
            h_GGH[v.first+"mTZZ"].Fill(fEvt["mTZZ"], vEvt["vw"]->at(v.second));
            //h2JET[v.first+"mTZZ"].Fill(fEvt["mTZZ"], vEvt["vw"]->at(v.second));
        }
    }

    if (region == RG::_2JET_MM){
        h_GGH["mm_"+this->treename].Fill(1, fEvt["weight"]);
        //h2JET["mm_"+this->treename].Fill(1, fEvt["weight"]);
        h_GGH["mm_"+this->treename+"mTZZ"].Fill(fEvt["mTZZ"], fEvt["weight"]);
        //h2JET["mm_"+this->treename+"mTZZ"].Fill(fEvt["mTZZ"], fEvt["weight"]);
        for (auto v: inVarTHEO){
            h_GGH["mm_"+v.first].Fill(1, vEvt["vw"]->at(v.second));
            //h2JET["mm_"+v.first].Fill(1, vEvt["vw"]->at(v.second));
            h_GGH["mm_"+v.first+"mTZZ"].Fill(fEvt["mTZZ"], vEvt["vw"]->at(v.second));
            //h2JET["mm_"+v.first+"mTZZ"].Fill(fEvt["mTZZ"], vEvt["vw"]->at(v.second));
        }
        h_GGH[this->treename].Fill(1, fEvt["weight"]);
        //h2JET[this->treename].Fill(1, fEvt["weight"]);
        h_GGH[this->treename+"mTZZ"].Fill(fEvt["mTZZ"], fEvt["weight"]);
        //h2JET[this->treename+"mTZZ"].Fill(fEvt["mTZZ"], fEvt["weight"]);
        for (auto v: inVarTHEO){
            h_GGH[v.first].Fill(1, vEvt["vw"]->at(v.second));
            //h2JET[v.first].Fill(1, vEvt["vw"]->at(v.second));
            h_GGH[v.first+"mTZZ"].Fill(fEvt["mTZZ"], vEvt["vw"]->at(v.second));
            //h2JET[v.first+"mTZZ"].Fill(fEvt["mTZZ"], vEvt["vw"]->at(v.second));
        }
    }

    if (region == RG::_GGH_EE){
        h_GGH["ee_"+this->treename].Fill(1, fEvt["weight"]);
        h_GGH["ee_"+this->treename+"mTZZ"].Fill(fEvt["mTZZ"], fEvt["weight"]);
        for (auto v: inVarTHEO){
            h_GGH["ee_"+v.first].Fill(1, vEvt["vw"]->at(v.second));
            h_GGH["ee_"+v.first+"mTZZ"].Fill(fEvt["mTZZ"], vEvt["vw"]->at(v.second));
        }
        h_GGH[this->treename].Fill(1, fEvt["weight"]);
        h_GGH[this->treename+"mTZZ"].Fill(fEvt["mTZZ"], fEvt["weight"]);
        for (auto v: inVarTHEO){
            h_GGH[v.first].Fill(1, vEvt["vw"]->at(v.second));
            h_GGH[v.first+"mTZZ"].Fill(fEvt["mTZZ"], vEvt["vw"]->at(v.second));
        }
    }

    if (region == RG::_GGH_MM){
        h_GGH["mm_"+this->treename].Fill(1, fEvt["weight"]);
        h_GGH["mm_"+this->treename+"mTZZ"].Fill(fEvt["mTZZ"], fEvt["weight"]);
        for (auto v: inVarTHEO){
            h_GGH["mm_"+v.first].Fill(1, vEvt["vw"]->at(v.second));
            h_GGH["mm_"+v.first+"mTZZ"].Fill(fEvt["mTZZ"], vEvt["vw"]->at(v.second));
        }
        h_GGH[this->treename].Fill(1, fEvt["weight"]);
        h_GGH[this->treename+"mTZZ"].Fill(fEvt["mTZZ"], fEvt["weight"]);
        for (auto v: inVarTHEO){
            h_GGH[v.first].Fill(1, vEvt["vw"]->at(v.second));
            h_GGH[v.first+"mTZZ"].Fill(fEvt["mTZZ"], vEvt["vw"]->at(v.second));
        }
    }
}
