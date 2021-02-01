#ifndef HZZ_HinvComb_h
#define HZZ_HinvComb_h

#include <TROOT.h>
#include <TFile.h>
#include <iostream>
#include <TH1F.h>
#include <TH2F.h>
#include <TProfile.h>
#include <TMath.h>
#include <TString.h>
#include <TBranch.h>
#include <TTree.h>

#include <map>
#include <vector>
#include "TMVA/Reader.h"

// Header file for the classes stored in the TTree if any.

class HinvComb{
    private :
        std::vector<std::string> inVarF;
        std::vector<std::string> inVarI;
        std::vector<std::string> inVarL;
        std::vector<std::string> onVarF;
        std::vector<std::string> histVars;
        std::map<std::string, float> fEvt;
        std::map<std::string, int> iEvt;
        std::map<std::string, ULong64_t> lEvt;
        std::map<std::string, TBranch*> BrEvt;

        TTree *tree_out;


        TTree *tree;
        TH1F *hInfo;
        TFile *fout;

        bool SYST;
        bool THEO;
        int count;
        float xsec;
        std::string treename;
        TMVA::Reader* reader;

        bool _EWcorr_error;

        Int_t run_number = -99999;
        ULong64_t event_number = -99999;
        float truth_H_pt = -999;
        float met = -999;
        int bcid = -999;
        std::vector<int> category;// = -99999;

    public :
        HinvComb(std::string treename, std::string outfile = "out.root", std::string outopt = "update", bool THEO = false, bool SYST = false);
        virtual ~HinvComb();
        virtual void Close();
        virtual void LoopEVT(int);
        virtual int Cut();
        virtual bool LoopROOT(std::string filename, std::string treename);

};

#endif

