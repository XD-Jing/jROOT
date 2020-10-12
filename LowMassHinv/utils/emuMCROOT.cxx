#include "LowMassHinv/emuMC.h" 
#include <string>
#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <cmath>

#define path_SR_data15 "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/data15/Nominal/"
#define path_SR_data16 "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/data16/Nominal/"
#define path_SR_data17 "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/data17/Nominal/"
#define path_SR_data18 "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/data18/Nominal/"
#define path_CR_data15 "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/data15/Background/"
#define path_CR_data16 "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/data16/Background/"
#define path_CR_data17 "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/data17/Background/"
#define path_CR_data18 "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/data18/Background/"
#define path_SR_mc16a  "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/mc16a/Systematics/"
#define path_SR_mc16d  "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/mc16d/Systematics/"
#define path_SR_mc16e  "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/mc16e/Systematics/"
#define path_CR_mc16a  "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/mc16a/Systematics_Background/"
#define path_CR_mc16d  "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/mc16d/Systematics_Background/"
#define path_CR_mc16e  "/lustre/umt3/user/liji/HZZ-samples/minitrees_rel75/mc16e/Systematics_Background/"
#define treeSR "tree_PFLOW"
#define treeCR "tree_em_PFLOW"

int main(int argc, const char *argv[]){
    std::string fout = argv[1];
    std::string fin = argv[2];
    std::string theo_arg = argv[3];
    std::string syst_arg = argv[4];
    double factor = std::stof(argv[5]);
    std::string type = argv[6];
    std::string wname = argv[7]; // default : PFLOW
    bool if_theo = theo_arg.find("true")!=std::string::npos ;
    bool if_syst = syst_arg.find("true")!=std::string::npos ;

    std::string path;
    std::string tree;
    if (fin.find("CR") == std::string::npos){
        tree = std::string(treeSR);
        if (fin.find("data15") != std::string::npos) path = std::string(path_SR_data15);
        if (fin.find("data16") != std::string::npos) path = std::string(path_SR_data16);
        if (fin.find("data17") != std::string::npos) path = std::string(path_SR_data17);
        if (fin.find("data18") != std::string::npos) path = std::string(path_SR_data18);
        if (fin.find("r9364" ) != std::string::npos) path = std::string(path_SR_mc16a);
        if (fin.find("r10201") != std::string::npos) path = std::string(path_SR_mc16d);
        if (fin.find("r10724") != std::string::npos) path = std::string(path_SR_mc16e);
    }else{
        tree = std::string(treeCR);
        if (fin.find("data15") != std::string::npos) path = std::string(path_CR_data15);
        if (fin.find("data16") != std::string::npos) path = std::string(path_CR_data16);
        if (fin.find("data17") != std::string::npos) path = std::string(path_CR_data17);
        if (fin.find("data18") != std::string::npos) path = std::string(path_CR_data18);
        if (fin.find("r9364" ) != std::string::npos) path = std::string(path_CR_mc16a);
        if (fin.find("r10201") != std::string::npos) path = std::string(path_CR_mc16d);
        if (fin.find("r10724") != std::string::npos) path = std::string(path_CR_mc16e);
    }

    //std::cout << path << std::endl;
    emuMC job(wname, fout, "recreate", if_theo, if_syst, type);
    if (fin.find("data") != std::string::npos)
        job.LoopROOT(path + fin, tree, factor);
    else if (wname == "PFLOW")
        job.LoopROOT(path + "weightSyst/" + fin, tree, factor);
    else
        job.LoopROOT(path + wname + "/" + fin, tree, factor);

    job.Close();
    return 0;
}
