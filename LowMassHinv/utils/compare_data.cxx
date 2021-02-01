#include <libgen.h>
#include <set>
#include <string>
#include <TFile.h>
#include <TMath.h>
#include <TVector2.h>
#include <TTree.h>
#include <TKey.h>
#include <iostream>
#include <iomanip>


void loopNtuple(std::string filename, std::set<std::pair<int, unsigned long long int>> &index, std::string treename, bool allevents){
    std::cout << basename(&filename[0])<< std::endl;
    TFile file(filename.c_str());
    TTree *tree;
    file.GetObject(treename.c_str(), tree);
    int run, n_bjets;
    unsigned long long int event;
    float met_signif, M2Lep, dLepR, met_tst, dMetZPhi, dPhiJ100met, factor;
    float lep3rd_pt, lep3rd_phi, met_py_tst, met_px_tst;
    //printf("filename %s\n", filename[0]);

    //if (filename.find("CR") != std::string::npos) {
    //    TH1F *hInfo;
    //    file.GetObject("Hist/hInfo_PFlow", hInfo);
    //    factor = hInfo->GetBinContent(1)*2.0 / hInfo->GetEntries() / hInfo->GetBinContent(2);
    //}
    //else{
    //    TH1D *hInfo;
    //    file.GetObject("hInfo", hInfo);
    //    factor = hInfo->GetBinContent(1)*2.0 / hInfo->GetEntries() / hInfo->GetBinContent(2);
    //}
    //if (filename.find("r9364" ) != std::string::npos) factor *= 3.21956 + 32.9653;
    //if (filename.find("r10201") != std::string::npos) factor *= 44.3074;
    //if (filename.find("r10724") != std::string::npos) factor *= 58.4501;
    //printf("factor = %10.5f\n", factor);

    tree->SetBranchAddress("run", &run);
    tree->SetBranchAddress("n_bjets", &n_bjets);
    tree->SetBranchAddress("event", &event);
    tree->SetBranchAddress("met_signif", &met_signif);
    tree->SetBranchAddress("met_tst", &met_tst);
    tree->SetBranchAddress("M2Lep", &M2Lep);
    tree->SetBranchAddress("dLepR", &dLepR);
    tree->SetBranchAddress("dPhiJ100met", &dPhiJ100met);
    tree->SetBranchAddress("dMetZPhi", &dMetZPhi);
    tree->SetBranchAddress("lep3rd_pt", &lep3rd_pt);
    tree->SetBranchAddress("lep3rd_phi", &lep3rd_phi);
    tree->SetBranchAddress("met_py_tst", &met_py_tst);
    tree->SetBranchAddress("met_px_tst", &met_px_tst);
    //tree->SetBranchAddress("weight", &weight);
    for (unsigned int i=0; i<tree->GetEntries(); i++){
        tree->GetEntry(i);
        if (allevents) {
            index.insert(std::make_pair(run, event));
        }
        else{
            if (TMath::Sqrt(2*lep3rd_pt*met_tst*(1-TMath::Cos(TVector2::Phi_mpi_pi(lep3rd_phi-TMath::ATan2(met_py_tst,met_px_tst)))))<=60) continue;
            if (lep3rd_pt<=20) continue;
            if (!(M2Lep>76 && M2Lep<106)) continue;
            if (n_bjets!=0) continue;
            if (met_signif<3) continue;


            //if (!(M2Lep>76 && M2Lep<106)) continue;
            //if (met_tst<=120) continue;
            //if (n_bjets!=0) continue;
            //if (fabs(dLepR)>=1.8) continue;
            //if (fabs(dPhiJ100met)<=0.4) continue;
            //if (fabs(dMetZPhi)<=2.5) continue;
            //if (met_signif<10) continue;
            index.insert(std::make_pair(run, event));
        }
    }
    file.Close();
}

int main(int argc, char* argv[]){
    std::set<std::pair<int, unsigned long long int>> rel075_index;
    std::set<std::pair<int, unsigned long long int>> rel115_index;
    std::set<std::string> rel075_data = {
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
        //"data15/Nominal/data15_13TeV.periodD1.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root",
        //"data15/Nominal/data15_13TeV.periodD2.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root",
        //"data15/Nominal/data15_13TeV.periodD3.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root",
        //"data15/Nominal/data15_13TeV.periodD4.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root",
        //"data15/Nominal/data15_13TeV.periodD6.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root",
        //"data15/Nominal/data15_13TeV.periodE.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root",
        //"data15/Nominal/data15_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root",
        //"data15/Nominal/data15_13TeV.periodG.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root",
        //"data15/Nominal/data15_13TeV.periodH.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root",
        //"data15/Nominal/data15_13TeV.periodJ.physics_Main.PhysCont.DAOD_HIGG2D1.grp15_v01_p3917.root",
        //"data16/Nominal/data16_13TeV.periodA.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root",
        //"data16/Nominal/data16_13TeV.periodB.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root",
        //"data16/Nominal/data16_13TeV.periodC.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root",
        //"data16/Nominal/data16_13TeV.periodD.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root",
        //"data16/Nominal/data16_13TeV.periodE.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root",
        //"data16/Nominal/data16_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root",
        //"data16/Nominal/data16_13TeV.periodG.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root",
        //"data16/Nominal/data16_13TeV.periodI.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root",
        //"data16/Nominal/data16_13TeV.periodK.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root",
        //"data16/Nominal/data16_13TeV.periodL.physics_Main.PhysCont.DAOD_HIGG2D1.grp16_v01_p3917.root",
        //"data17/Nominal/data17_13TeV.periodB.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root",
        //"data17/Nominal/data17_13TeV.periodC.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root",
        //"data17/Nominal/data17_13TeV.periodD.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root",
        //"data17/Nominal/data17_13TeV.periodE.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root",
        //"data17/Nominal/data17_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root",
        //"data17/Nominal/data17_13TeV.periodH.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root",
        //"data17/Nominal/data17_13TeV.periodI.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root",
        //"data17/Nominal/data17_13TeV.periodK.physics_Main.PhysCont.DAOD_HIGG2D1.grp17_v01_p3917.root",
        //"data18/Nominal/data18_13TeV.periodB.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root",
        //"data18/Nominal/data18_13TeV.periodC.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root",
        //"data18/Nominal/data18_13TeV.periodD.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root",
        //"data18/Nominal/data18_13TeV.periodF.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root",
        //"data18/Nominal/data18_13TeV.periodI.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root",
        //"data18/Nominal/data18_13TeV.periodK.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root",
        //"data18/Nominal/data18_13TeV.periodL.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root",
        //"data18/Nominal/data18_13TeV.periodM.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root",
        //"data18/Nominal/data18_13TeV.periodO.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root",
        //"data18/Nominal/data18_13TeV.periodQ.physics_Main.PhysCont.DAOD_HIGG2D1.grp18_v01_p3917.root",
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
    std::string rel075_path = "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/";
    //for (auto data : rel075_data) loopNtuple(rel075_path + data, rel075_index, "tree_emu_PFLOW", false);
    //for (auto data : rel115_data) loopNtuple(rel115_path + data, rel115_index, "tree_emCR_PFLOW", true);
    for (auto data : rel075_data) loopNtuple(rel075_path + data, rel075_index, "tree_3l_PFLOW", false);
    for (auto data : rel115_data) loopNtuple(rel115_path + data, rel115_index, "tree_3lCR_PFLOW", true);
    //for (auto data : rel075_data) loopNtuple(rel075_path + data, rel075_index, "tree_PFLOW", false);
    //for (auto data : rel115_data) loopNtuple(rel115_path + data, rel115_index, "tree_PFLOW", true);

    for (auto item : rel075_index){
        if (rel115_index.find(item) != rel115_index.end()) {
            std::cout << std::setw(20) << item.first << std::setw(20) << item.second << std::setw(10) << "yes" << std::endl;
            //printf("%10.5f %10.5f %10.5f %10.f\n", item.second, rel115_index[item.first], mapw75[item.first], mapw115[item.first]);
        }
        else{
            std::cout << std::setw(20) << item.first << std::setw(20) << item.second << std::setw(10) << "no" << std::endl;
        }

    }


    return 0;
}
