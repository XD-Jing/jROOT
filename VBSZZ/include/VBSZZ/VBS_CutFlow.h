#ifndef VBS_CutFlow_h
#define VBS_CutFlow_h

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

class VBS_CutFlow{
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
        std::map<std::pair<std::string, std::string>, TH1F*> hist_Zmass_llvv;
        std::map<std::pair<std::string, std::string>, TH1F*> hist_Zmass_eevv;
        std::map<std::pair<std::string, std::string>, TH1F*> hist_Zmass_mmvv;
        std::map<std::pair<std::string, std::string>, TH1F*> hist_Zmass_emvv;
        std::map<std::pair<std::string, std::string>, TH1F*> hist_2Jet_llvv;
        std::map<std::pair<std::string, std::string>, TH1F*> hist_2Jet_eevv;
        std::map<std::pair<std::string, std::string>, TH1F*> hist_2Jet_mmvv;
        std::map<std::pair<std::string, std::string>, TH1F*> hist_2Jet_emvv;
        std::map<std::pair<std::string, std::string>, TH1F*> hist_MET_llvv;
        std::map<std::pair<std::string, std::string>, TH1F*> hist_MET_eevv;
        std::map<std::pair<std::string, std::string>, TH1F*> hist_MET_mmvv;
        std::map<std::pair<std::string, std::string>, TH1F*> hist_MET_emvv;
        std::map<std::pair<std::string, std::string>, TH1F*> hist_2lSR_llvv;
        std::map<std::pair<std::string, std::string>, TH1F*> hist_2lSR_eevv;
        std::map<std::pair<std::string, std::string>, TH1F*> hist_2lSR_mmvv;
        std::map<std::pair<std::string, std::string>, TH1F*> hist_2lCR_llvv;
        std::map<std::pair<std::string, std::string>, TH1F*> hist_2lCR_eevv;
        std::map<std::pair<std::string, std::string>, TH1F*> hist_2lCR_mmvv;
        std::map<std::pair<std::string, std::string>, TH1F*> hist_2lCR_emvv;

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
        VBS_CutFlow(std::string treename, std::string outfile = "out.root", std::string outopt = "update", bool THEO = false, bool SYST = false);
        virtual ~VBS_CutFlow();
        virtual void Close();
        virtual void LoopEVT(int);
        virtual int Cut();
        virtual bool mkHist();
        virtual bool mkHistVar(std::string, int, double, double);
        virtual bool LoopROOT(std::string filename, std::string treename = "tree_NOMINAL", float factor = 1.0);
};

#endif

