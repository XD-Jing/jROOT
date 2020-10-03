#ifndef VBS_3lCR_h
#define VBS_3lCR_h

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

class VBS_3lCR{
    private :
        std::vector<std::string> inVarF;
        std::vector<std::string> inVarI;
        std::vector<std::string> inVarV;
        std::vector<std::string> onVarF;
        std::vector<std::string> histVars;
        std::map<std::string, int> inVarTHEO;
        std::map<std::string, std::string> inVarSYST;
        std::map<std::string, float> fEvt;
        std::map<std::string, int> iEvt;
        std::map<std::string, std::vector<float>*> vEvt;
        std::map<std::string, TBranch*> BrEvt;
        std::map<std::pair<std::string, std::string>, TH1F*> hist_3lCR_lllv;
        std::map<std::pair<std::string, std::string>, TH1F*> hist_3lCR_eeev;
        std::map<std::pair<std::string, std::string>, TH1F*> hist_3lCR_eemv;
        std::map<std::pair<std::string, std::string>, TH1F*> hist_3lCR_mmev;
        std::map<std::pair<std::string, std::string>, TH1F*> hist_3lCR_mmmv;

        TTree *tree;
        TH1F *hInfo;
        TFile *fout;

        bool SYST;
        bool THEO;
        bool NOMI;
        int count;
        float xsec;
        std::string treename;
        TMVA::Reader* reader;

    public :
        VBS_3lCR(std::string treename, std::string outfile = "out.root", std::string outopt = "update", bool THEO = false, bool SYST = false, bool NOMI = true);
        virtual ~VBS_3lCR();
        virtual void Close();
        virtual void LoopEVT(int);
        virtual int Cut();
        virtual bool mkHist();
        virtual bool mkHistVar(std::string, int, double, double);
        virtual bool LoopROOT(std::string filename, std::string treename = "tree_NOMINAL", float factor = 1.0);
};

#endif

