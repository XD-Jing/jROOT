#ifndef VBSZZ_jTHEO_h
#define VBSZZ_jTHEO_h

#include <TROOT.h>
#include <TFile.h>
#include <iostream>
#include <TH1F.h>
#include <TMath.h>
#include <TString.h>
#include "TMVA/Reader.h"

// Header file for the classes stored in the TTree if any.

class jTHEO {
    private :
        std::vector<std::string> plotVars;
        std::vector<std::string> inVarF;
        std::vector<std::string> inVarI;
        std::vector<std::string> inVarV;
        std::map<std::string, int> inVarW;
        std::vector<std::string> onVarF;
        std::map<std::string, float> fEvt;
        std::map<std::string, int> iEvt;
        std::map<std::string, std::vector<float>*> vEvt;
        std::map<std::string, TBranch*> BrEvt;
        std::map<std::pair<std::string, std::string>, TH1F> h2JET;
        std::map<std::pair<std::string, std::string>, TH1F> h2lSR;
        std::map<std::pair<std::string, std::string>, TH1F> h2lVR;
        std::map<std::pair<std::string, std::string>, TH1F> hemCR;
        std::map<std::pair<std::string, std::string>, TH1F> h3lCR;
        std::map<std::pair<std::string, std::string>, TH1F> hmmmCR;
        std::map<std::pair<std::string, std::string>, TH1F> hmmeCR;
        std::map<std::pair<std::string, std::string>, TH1F> heeeCR;
        std::map<std::pair<std::string, std::string>, TH1F> heemCR;

        TMVA::Reader *reader;
        TTree *tree;
        TFile *fout;
        std::vector<float> *vw;
        TBranch *b_vw; //!

        int count;
        float factor;
        std::string treename;

    public :
        jTHEO(std::string treename, std::string outfile = "out.root", std::string outopt = "update");
        ~jTHEO();
        void LoopEVT(int);
        virtual int Cut();
        bool mkHist(std::string, const int, const float, const float);
        bool LoopROOT(std::string filename, float factor = 1.0);
};

#endif

