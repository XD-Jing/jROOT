#ifndef LowMassHinv_emuMC_h
#define LowMassHinv_emuMC_h

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

class emuMC{
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

        bool SYST;
        bool THEO;
        int count;
        float xsec;
        std::string treename;
        TMVA::Reader* reader;

    public :
        emuMC(std::string treename, std::string outfile = "out.root", std::string outopt = "update", bool THEO = false, bool SYST = false, std::string type = "sherpa");
        virtual ~emuMC();
        virtual void Close();
        virtual void initWeights(std::string type);
        virtual void LoopEVT(int);
        virtual int Cut();
        virtual bool mkHist();
        virtual bool mkHistVar(std::string, int, double, double);
        virtual bool LoopROOT(std::string filename, std::string treename = "tree_PFLOW", float factor = 1.0);
};

#endif

