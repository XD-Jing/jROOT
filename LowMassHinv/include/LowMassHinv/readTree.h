#ifndef LowMassHinv_readTree_h
#define LowMassHinv_readTree_h

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
        std::map<std::pair<std::string, std::string>, TH1F*> hist_llvv;
        std::map<std::pair<std::string, std::string>, TH1F*> hist_eevv;
        std::map<std::pair<std::string, std::string>, TH1F*> hist_mmvv;
        std::map<std::pair<std::string, std::string>, TH1F*> hist_emvv;

        TTree *tree;
        TH1F *hInfo;
        TFile *fout;

        //bool SYST;
        //bool THEO;
        int count;
        float factorSR;
        float factorCR;
        bool isMC;
        std::string treename;
        TMVA::Reader* reader;

    public :
        readTree(std::string outfile = "out.root", std::string infile = ".root", std::string sysname = "PFLOW", float factorSR = 1., float factorCR = 1.0);
        virtual ~readTree();
        virtual void Close();
        virtual void initWeights(std::string infile);
        virtual void LoopEVT(int);
        virtual int Cut();
        virtual bool mkHist();
        virtual bool mkHistVar(std::string, int nbins, double left, double right, int nbins2 = 0, double rebins [] = {});
        //virtual bool LoopROOT(std::string filename, std::string treename = "tree_PFLOW", float factor = 1.0);
};

#endif

