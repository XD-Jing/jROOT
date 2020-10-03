#ifndef SlimTree_h
#define SlimTree_h

#include <TROOT.h>
#include <TFile.h>
#include <iostream>
#include <TH1F.h>
#include <TMath.h>
#include <TString.h>
#include <TBranch.h>
#include <TTree.h>

#include <map>
#include <vector>
#include "TMVA/Reader.h"

// Header file for the classes stored in the TTree if any.

class SlimTree{
    private :
        std::vector<std::string> inVarF;
        std::vector<std::string> inVarI;
        std::vector<std::string> onVarF;
        std::vector<std::string> onVarI;
        std::vector<std::string> onVarB;
        std::vector<std::string> histVars;
        std::map<std::string, std::string> inVarTHEO;
        std::map<std::string, std::string> inVarSYST;
        std::map<std::string, float> fEvt;
        std::map<std::string, int> iEvt;
        std::map<std::string, bool> bEvt;
        std::map<std::string, TBranch*> BrEvt;

        TTree *tree;
        TTree *outTree;
//        std::map<std::string, TTree*> outTree;
        TH1F *hInfo;
        TFile *fout;

        bool SYST;
        bool THEO;
        int count;
        float xsec;
        std::string treename;
        TMVA::Reader* reader;

    public :
        SlimTree(std::string treename, std::string outfile = "out.root", std::string outopt = "update", bool THEO = false, bool SYST = false);
        virtual ~SlimTree();
        virtual void Close();
        virtual bool LoopROOT(std::string filename, std::string treename = "tree_NOMINAL", std::string weightname = "weight", std::string outtreename = "tree_NOMINAL", float factor = 1.0);
};

#endif

