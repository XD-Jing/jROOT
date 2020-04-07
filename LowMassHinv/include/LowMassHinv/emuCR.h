#ifndef LowMassHinv_emuCR_h
#define LowMassHinv_emuCR_h

#include <TROOT.h>
#include <TFile.h>
#include <iostream>
#include <TH1D.h>
#include <TH2D.h>
#include <TH3D.h>
#include <TMath.h>
#include <TString.h>
#include <TBranch.h>
#include <TTree.h>

#include <map>
#include <vector>
#include "TMVA/Reader.h"

// Header file for the classes stored in the TTree if any.

class emuCR{
    private :
        std::vector<std::string> inVarF;
        std::vector<std::string> inVarI;
        std::vector<std::string> inVarV;
        std::vector<std::string> onVarF;
        std::vector<std::string> mcVarF;
        std::map<std::string, float> fEvt;
        std::map<std::string, int> iEvt;
        std::map<std::string, std::vector<float>*> vEvt;
        std::map<std::string, TBranch*> BrEvt;
        std::map<std::string, TH3D*> H3;
        std::map<std::string, TH2D*> H2;
        std::map<std::string, TH1D*> H1;

        TTree *tree;
        TH1F *hInfo;
        TFile *fout;

        int count;
        bool isMC;
        float xsec;
        std::string treename;
        TMVA::Reader* reader;

    public :
        emuCR(std::string treename, std::string outfile = "out.root", std::string outopt = "update", std::string tag = "emuCR");
        virtual ~emuCR();
        virtual void Close();
        virtual void LoopEVT(int);
        virtual int Cut();
        virtual bool mkHist(std::string tag);
        virtual bool LoopROOT(std::string filename, double factor = 1.0, std::string treename = "");
};

#endif

