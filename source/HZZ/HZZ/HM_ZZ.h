#ifndef HZZ_HM_ZZ_h
#define HZZ_HM_ZZ_h

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
//#include "TMVA/Reader.h"

// Header file for the classes stored in the TTree if any.

class HM_ZZ{
    private :
        std::vector<std::string> inVarF;
        std::vector<std::string> inVarI;
        std::vector<std::string> onVarF;
        std::map<std::string, std::string> inVarTHEO;
        std::map<std::string, float> fEvt;
        std::map<std::string, int> iEvt;
        std::map<std::string, TBranch*> BrEvt;
        std::map<std::string, TH1F> h_GGH;
        std::map<std::string, TH1F> h_VBF;
        std::map<std::string, TH1F> h2JET;

        TTree *tree;
        TH1F *hInfo;
        TFile *fout;

        bool SYST;
        bool THEO;
        int count;
        float xsec;
        std::string treename;

    public :
        HM_ZZ(std::string treename, std::string outfile = "out.root", std::string outopt = "update", bool THEO = false);
        virtual ~HM_ZZ();
        virtual void Close();
        virtual void LoopEVT(int);
        virtual int Cut();
        virtual bool mkHist();
        virtual bool LoopROOT(std::string filename, float factor = 1.0);
};

#endif

