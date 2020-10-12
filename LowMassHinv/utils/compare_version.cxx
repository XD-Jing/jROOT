#include <libgen.h>
#include <set>
#include <map>
#include <string>
#include <TFile.h>
#include <TH1D.h>
#include <TH2F.h>
#include <TTree.h>
#include <TKey.h>
#include <iostream>
#include <TCanvas.h>
#include <TStyle.h>
#include <TLine.h>


void loopNtuple(std::string filename, std::map<std::pair<int, unsigned long long int>, float> &index, std::string treename){
    std::cout << basename(&filename[0])<< std::endl;
    TFile file(filename.c_str());
    TTree *tree;
    file.GetObject(treename.c_str(), tree);
    int run, n_bjets;
    unsigned long long int event;
    float met_signif, M2Lep, dLepR, met_tst;
    tree->SetBranchAddress("run", &run);
    tree->SetBranchAddress("n_bjets", &n_bjets);
    tree->SetBranchAddress("event", &event);
    tree->SetBranchAddress("met_signif", &met_signif);
    tree->SetBranchAddress("met_tst", &met_tst);
    tree->SetBranchAddress("M2Lep", &M2Lep);
    tree->SetBranchAddress("dLepR", &dLepR);
    for (unsigned int i=0; i<tree->GetEntries(); i++){
        tree->GetEntry(i);
        if (n_bjets!=0) continue;
        if (met_tst<=90) continue;
        if (met_signif<8) continue;
        if (fabs(dLepR)>=1.8) continue;
        index[std::make_pair(run, event)] = met_signif;
    }
    file.Close();
}

int main(int argc, char* argv[]){
    std::map<std::pair<int, unsigned long long int>, float> rel75_index;
    std::map<std::pair<int, unsigned long long int>, float> rel115_index;
    std::set<std::string> rel75_data = {
        "data15/Background/data15_13TeV.periodD1.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root",
        "data15/Background/data15_13TeV.periodD2.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root",
        "data15/Background/data15_13TeV.periodD3.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root",
        "data15/Background/data15_13TeV.periodD4.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root",
        "data15/Background/data15_13TeV.periodD6.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root",
        "data15/Background/data15_13TeV.periodE.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root",
        "data15/Background/data15_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root",
        "data15/Background/data15_13TeV.periodG.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root",
        "data15/Background/data15_13TeV.periodH.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root",
        "data15/Background/data15_13TeV.periodJ.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917_CR.root",
        "data16/Background/data16_13TeV.periodA.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root",
        "data16/Background/data16_13TeV.periodB.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root",
        "data16/Background/data16_13TeV.periodC.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root",
        "data16/Background/data16_13TeV.periodD.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root",
        "data16/Background/data16_13TeV.periodE.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root",
        "data16/Background/data16_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root",
        "data16/Background/data16_13TeV.periodG.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root",
        "data16/Background/data16_13TeV.periodI.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root",
        "data16/Background/data16_13TeV.periodK.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root",
        "data16/Background/data16_13TeV.periodL.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917_CR.root",
        "data17/Background/data17_13TeV.periodB.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917_CR.root",
        "data17/Background/data17_13TeV.periodC.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917_CR.root",
        "data17/Background/data17_13TeV.periodD.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917_CR.root",
        "data17/Background/data17_13TeV.periodE.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917_CR.root",
        "data17/Background/data17_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917_CR.root",
        "data17/Background/data17_13TeV.periodH.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917_CR.root",
        "data17/Background/data17_13TeV.periodI.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917_CR.root",
        "data17/Background/data17_13TeV.periodK.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917_CR.root",
        "data18/Background/data18_13TeV.periodB.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root",
        "data18/Background/data18_13TeV.periodC.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root",
        "data18/Background/data18_13TeV.periodD.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root",
        "data18/Background/data18_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root",
        "data18/Background/data18_13TeV.periodI.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root",
        "data18/Background/data18_13TeV.periodK.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root",
        "data18/Background/data18_13TeV.periodL.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root",
        "data18/Background/data18_13TeV.periodM.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root",
        "data18/Background/data18_13TeV.periodO.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root",
        "data18/Background/data18_13TeV.periodQ.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917_CR.root",
    };
    std::set<std::string> rel115_data = {
        "data15_13TeV.periodD1.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root",
        "data15_13TeV.periodD2.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root",
        "data15_13TeV.periodD3.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root",
        "data15_13TeV.periodD4.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root",
        "data15_13TeV.periodD6.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root",
        "data15_13TeV.periodE.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root",
        "data15_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root",
        "data15_13TeV.periodG.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root",
        "data15_13TeV.periodH.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root",
        "data15_13TeV.periodJ.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root",
        "data16_13TeV.periodA.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root",
        "data16_13TeV.periodB.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root",
        "data16_13TeV.periodC.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root",
        "data16_13TeV.periodD.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root",
        "data16_13TeV.periodE.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root",
        "data16_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root",
        "data16_13TeV.periodG.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root",
        "data16_13TeV.periodI.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root",
        "data16_13TeV.periodK.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root",
        "data16_13TeV.periodL.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root",
        "data17_13TeV.periodB.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root",
        "data17_13TeV.periodC.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root",
        "data17_13TeV.periodD.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root",
        "data17_13TeV.periodE.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root",
        "data17_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root",
        "data17_13TeV.periodH.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root",
        "data17_13TeV.periodI.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root",
        "data17_13TeV.periodK.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root",
        "data18_13TeV.periodB.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root",
        "data18_13TeV.periodC.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root",
        "data18_13TeV.periodD.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root",
        "data18_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root",
        "data18_13TeV.periodI.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root",
        "data18_13TeV.periodK.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root",
        "data18_13TeV.periodL.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root",
        "data18_13TeV.periodM.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root",
        "data18_13TeV.periodO.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root",
        "data18_13TeV.periodQ.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root",
    };

    std::string rel115_path = "/lustre/umt3/user/liji/Hinv_minitree/minitrees_rel115/data/";
    std::string rel75_path = "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/";
    for (auto data : rel75_data) loopNtuple(rel75_path + data, rel75_index, "tree_emu_PFLOW");
    for (auto data : rel115_data) loopNtuple(rel115_path + data, rel115_index, "tree_emCR_PFLOW");

    TFile *f = new TFile("a.root", "recreate");
    TCanvas *c = new TCanvas();
    TH2F *hist = new TH2F("", "", 100, 8, 10, 100, 8, 10);
    for (auto item : rel75_index) if (rel115_index.find(item.first) != rel115_index.end()) hist->Fill(item.second, rel115_index[item.first]);

    gStyle->SetOptStat(0);
    hist->GetXaxis()->SetTitle("rel 21.2.75 MET Signif");
    hist->GetYaxis()->SetTitle("rel 21.2.115 MET Signif");
    hist->Draw("colz");

    TLine *l1 = new TLine(9, 8, 9, 10); l1->Draw();
    TLine *l2 = new TLine(8, 9, 10, 9); l2->Draw();
    c->Print("a.pdf");

    f->cd(); hist->Write(); f->Close();

    return 0;
}
