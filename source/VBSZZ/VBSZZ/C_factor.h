#ifndef VBSZZ_C_factor_h
#define VBSZZ_C_factor_h

#include <TROOT.h>
#include <TFile.h>
#include <iostream>
#include <TH1F.h>
#include <TMath.h>
#include <TString.h>
#include "TMVA/Reader.h"

// Header file for the classes stored in the TTree if any.

class C_factor {
    private :
        std::vector<std::string> inVarF;
        std::vector<std::string> inVarI;
        std::vector<std::string> inVarV;
        std::map<std::string, int> inVarTHEO;
        std::vector<std::string> inVarW;
        std::vector<std::string> onVarF;
        std::map<std::string, float> fEvt;
        std::map<std::string, int> iEvt;
        std::map<std::string, std::vector<float>*> vEvt;
        std::map<std::string, TBranch*> BrEvt;
        std::map<std::string, TH1F> h2lSR;
        std::map<std::string, TH1F> h2lFV;

        TTree *tree;
        TH1F *hInfo;
        TFile *fout;

        int count;
        float factor;
        std::string treename;
        std::string outfile;

    public :
        C_factor(std::string treename, std::string outfile = "out.root", std::string outopt = "update");
        ~C_factor();
        void LoopEVT(int, int);
        int CutFV();
        int CutSR();
        bool mkHist();
        bool LoopROOT(std::string filename, float factor = 1.0);
};

#endif

