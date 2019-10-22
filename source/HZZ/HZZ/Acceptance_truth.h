#ifndef HZZ_Acceptance_truth_h
#define HZZ_Acceptance_truth_h

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

class Acceptance_truth{
    private :
        std::vector<std::string> inVarF;
        std::vector<std::string> inVarI;
        std::vector<std::string> inVarV;
        std::map<std::string, int> inVarTHEO;
        std::map<std::string, double> fEvt;
        std::map<std::string, int> iEvt;
        std::map<std::string, std::vector<float>*> vEvt;
        std::map<std::string, TBranch*> BrEvt;
        std::map<std::string, TH1F> h_GGH;
        std::map<std::string, TH1F> h_VBF;
        std::map<std::string, TH1F> h2JET;
        std::map<std::string, TH1F> hDAOD;

        TTree *tree;
        TH1F *hInfo;
        TFile *fout;

        bool SYST;
        bool THEO;
        int count;
        float xsec;
        std::string treename;

    public :
        Acceptance_truth(std::string treename, std::string outfile = "out.root", std::string outopt = "update", bool THEO = false);
        virtual ~Acceptance_truth();
        virtual void LoopEVT(int);
        virtual void Close();
        virtual int Cut();
        virtual bool mkHist();
        virtual bool LoopROOT(std::string filename, float xsec = 1.0);
};

#endif

