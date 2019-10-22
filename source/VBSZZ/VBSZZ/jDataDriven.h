#ifndef VBSZZ_jDataDriven_h
#define VBSZZ_jDataDriven_h

#include <TROOT.h>
#include <TFile.h>
#include <iostream>
#include <TH1F.h>
#include <TMath.h>
#include <TString.h>
#include "TMVA/Reader.h"

// Header file for the classes stored in the TTree if any.

class jDataDriven {
    private :
        std::vector<std::string> plotVars;
        std::vector<std::string> inVarF;
        std::vector<std::string> inVarI;
        std::vector<std::string> inVarV;
        std::vector<std::string> onVarF;
        std::vector<std::string> inVarSYST;
        std::map<std::string, int> inVarTHEO;
        std::map<std::string, float> fEvt;
        std::map<std::string, int> iEvt;
        std::map<std::string, std::vector<float>*> vEvt;
        std::map<std::string, TBranch*> BrEvt;
        //std::map<std::pair<std::string, std::string>, TH1F> h2JET;
        std::map<std::pair<std::string, std::string>, TH1F> h2lSR;
        std::map<std::pair<std::string, std::string>, TH1F> h2lVR;
        //std::map<std::pair<std::string, std::string>, TH1F> hemCR;

        TMVA::Reader *reader;
        TTree *tree;
        TFile *fout;

        int mc;
        bool SYST;
        bool THEO;
        bool isData;
        int count;
        float factor;
        std::string treename;


    public :
        jDataDriven(std::string treename, std::string outfile = "out.root", std::string outopt = "update", bool THEO = false, bool SYST = false, bool isData = false);
        virtual ~jDataDriven();
        virtual void LoopEVT(int);
        virtual int Cut();
        virtual float calculateMC(float, float, float, float);
        virtual float calculateData(float, float, float, float);
        virtual bool mkHist(std::string, const int, const float, const float);
        virtual bool LoopROOT(std::string filename, float factor = 1.0);
};

#endif

