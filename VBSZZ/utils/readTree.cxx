#include "VBSZZ/readTree.h" 
#include <string>
#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <cmath>

//#define path_data "/lustre/umt3/user/liji/Hinv_minitree/minitrees_rel115/data/"
//#define path_mc16 "/lustre/umt3/user/liji/VBSZZ-samples/p3759-minitrees/"
#define path_mc16 "/lustre/umt3/user/liji/VBSZZ-samples/p3759-2Jets/"
//#define path_mc16 "/lustre/umt3/user/liji/VBSZZ-samples/p3759-2lXR/"
#define treeSR "tree_PFLOW"

int main(int argc, const char *argv[]){
    std::string fout = argv[1];
    std::string fin = argv[2];
    std::string sysname = argv[3];
    //std::string theo_arg = argv[3];
    //std::string syst_arg = argv[4];
    //double factor = std::stof(argv[5]);
    //std::string type = argv[6];
    //std::string wname = argv[7]; // default : PFLOW
    //std::string tree  = argv[8]; // default : PFLOW
    //bool if_theo = theo_arg.find("true")!=std::string::npos ;
    //bool if_syst = syst_arg.find("true")!=std::string::npos ;

    std::string path;
    //std::string tree;
        //tree = std::string(treeCR);
    //if (fin.find("data") != std::string::npos) path = std::string(path_data) + fin;

    path = std::string(path_mc16) + fin;
    //if (fin.find("mc16") != std::string::npos) path = std::string(path_mc16) + fin;

    //std::cout << path << std::endl;

    if (argc==5) {
        float factor = atof(argv[4]);
        //float factor = std::stoi(argv[4]);
        std::cout << "factor input : " << factor << std::endl;
        readTree job(fout, path, sysname, factor);
        job.Close();
    }
    else{
        readTree job(fout, path, sysname);
        job.Close();
    }
    return 0;
}
