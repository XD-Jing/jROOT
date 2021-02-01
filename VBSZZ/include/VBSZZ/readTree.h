#ifndef VBSZZ_readTree_h
#define VBSZZ_readTree_h

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

class readTree{
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
        std::map<std::pair<std::string, std::string>, TH1F*> h2lSR_llvv;
        std::map<std::pair<std::string, std::string>, TH1F*> h2lSR_eevv;
        std::map<std::pair<std::string, std::string>, TH1F*> h2lSR_mmvv;
        std::map<std::pair<std::string, std::string>, TH1F*> h2lVR_llvv;
        std::map<std::pair<std::string, std::string>, TH1F*> h2lVR_eevv;
        std::map<std::pair<std::string, std::string>, TH1F*> h2lVR_mmvv;
        std::map<std::pair<std::string, std::string>, TH1F*> h2lCR_emvv;
        std::map<std::pair<std::string, std::string>, TH1F*> h3lCR_lllv;
        std::map<std::pair<std::string, std::string>, TH1F*> h3lCR_eeev;
        std::map<std::pair<std::string, std::string>, TH1F*> h3lCR_mmev;
        std::map<std::pair<std::string, std::string>, TH1F*> h3lCR_eemv;
        std::map<std::pair<std::string, std::string>, TH1F*> h3lCR_mmmv;

        TTree *tree;
        TH1F *hInfo;
        TFile *fout;

        //bool SYST;
        //bool THEO;
        int count;
        float factor;
        bool isMC;
        std::string treename;
        TMVA::Reader* reader;

    public :
        readTree(std::string outfile = "out.root", std::string infile = ".root", std::string sysname = "PFLOW", float factor = 1.);
        virtual ~readTree();
        virtual void Close();
        virtual void initWeights(std::string infile);
        virtual void LoopEVT(int);
        virtual int Cut();
        virtual bool mkHist();
        virtual bool mkHistVar(std::string, int, double, double);
        //virtual bool LoopROOT(std::string filename, std::string treename = "tree_PFLOW", float factor = 1.0);
};

#endif

