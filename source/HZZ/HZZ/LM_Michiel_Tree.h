#ifndef HZZ_LM_Michiel_Tree_h
#define HZZ_LM_Michiel_Tree_h

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

class LM_Michiel_Tree{
    private :
        std::vector<std::string> inVarF;
        std::vector<std::string> inVarI;
        std::vector<std::string> onVarF;
        std::vector<std::string> histVars;
        std::map<std::string, std::string> inVarTHEO;
        std::map<std::string, std::string> inVarSYST;
        std::map<std::string, float> fEvt;
        std::map<std::string, int> iEvt;
        std::map<std::string, TBranch*> BrEvt;
        std::map<std::pair<std::string, std::string>, TH1F*> llvv_GGH;
        std::map<std::pair<std::string, std::string>, TH1F*> llvv_VBF;
        std::map<std::pair<std::string, std::string>, TH1F*> eevv_GGH;
        std::map<std::pair<std::string, std::string>, TH1F*> eevv_VBF;
        std::map<std::pair<std::string, std::string>, TH1F*> mmvv_GGH;
        std::map<std::pair<std::string, std::string>, TH1F*> mmvv_VBF;

        TTree *tree;
        TH1F *hInfo;
        TFile *fout;

        bool SYST;
        bool THEO;
        int count;
        float xsec;
        std::string treename;
        TMVA::Reader* reader;

    public :
        LM_Michiel_Tree(std::string treename, std::string outfile = "out.root", std::string outopt = "update", bool THEO = false, bool SYST = false);
        virtual ~LM_Michiel_Tree();
        virtual void Close();
        virtual void LoopEVT(int);
        virtual int Cut();
        virtual bool mkHist();
        virtual bool mkHistVar(std::string, int, double, double);
        virtual bool LoopROOT(std::string filename, float xsec = 1.0);
};

#endif

