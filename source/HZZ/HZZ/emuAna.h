#ifndef HZZ_EMUANA_H
#define HZZ_EMUANA_H

#include <string>
#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <TH1D.h>
#include <TH2D.h>
#include <cmath>

double H2GetBinContents(TH2D* h, double xMin, double xMax, double yMin, double yMax){
    double r = 0.0;
    for (int i=1; i<=h->GetNbinsX(); i++){
        for (int j=1; j<=h->GetNbinsY(); j++){
            if (xMin<=h->GetXaxis()->GetBinLowEdge(i) && xMax>=h->GetXaxis()->GetBinUpEdge(i)
                    && yMin<=h->GetYaxis()->GetBinLowEdge(j) && yMax>=h->GetYaxis()->GetBinUpEdge(j)){
            r+= h->GetBinContent(i, j);
            }
        }
    }
    return r;
}

double H2GetBinErrors(TH2D* h, double xMin, double xMax, double yMin, double yMax){
    double r2 = 0.0;
    for (int i=1; i<=h->GetNbinsX(); i++){
        for (int j=1; j<=h->GetNbinsY(); j++){
            if (xMin<=h->GetXaxis()->GetBinLowEdge(i) && xMax>=h->GetXaxis()->GetBinUpEdge(i)
                    && yMin<=h->GetYaxis()->GetBinLowEdge(j) && yMax>=h->GetYaxis()->GetBinUpEdge(j)){
            r2+= h->GetBinError(i, j) * h->GetBinError(i, j);
            }
        }
    }
    return  sqrt(r2);
}

TH3D* GetH3(TFile* f, std::string key){
    TH3D *h = (TH3D*)f->Get(key.c_str());
    if (!h){
        printf("%s not exists.\n", key.c_str());
        return 0;
    }
    return h;
}

TH2D* GetH2(TFile* f, std::string key){
    TH2D *h = (TH2D*)f->Get(key.c_str());
    if (!h){
        printf("%s not exists.\n", key.c_str());
        return 0;
    }
    return h;
}

TH1D* GetH1(TFile* f, std::string key){
    TH1D *h = (TH1D*)f->Get(key.c_str());
    if (!h){
        printf("%s not exists.\n", key.c_str());
        return 0;
    }
    return h;
}


void analysis(std::string tag, std::string filename){
    TFile *f = new TFile(filename.c_str(), "read");
    if (!f) {
        printf("%s not opened.\n", filename.c_str());
        return;
    }

    TH2D* H2EE = GetH2(f, tag+"_onshell_EE");
    TH2D* H2MM = GetH2(f, tag+"_onshell_MM");

    double YieldEE = 0.0,
           YieldMM = 0.0,
           Epsilon = 0.0;
    double eYieldEE = 0.0,
           eYieldMM = 0.0,
           eEpsilon = 0.0;
    std::vector<double> ptMins  = {20, 45,  55,   20,   45,   55,   20,   45,   55};
    std::vector<double> ptMaxs  = {45, 55, 9e9,   45,   55,  9e9,   45,   55,  9e9};
    std::vector<double> etaMins = { 0,  0,   0,    1,    1,    1, 1.37, 1.37, 1.37};
    std::vector<double> etaMaxs = { 1,  1,   1, 1.37, 1.37, 1.37,  2.5,  2.5,  2.5};

    for (int i=0; i<ptMaxs.size(); i++){
        YieldEE = H2GetBinContents(H2EE, ptMins[i], ptMaxs[i], etaMins[i], etaMaxs[i]);
        YieldMM = H2GetBinContents(H2MM, ptMins[i], ptMaxs[i], etaMins[i], etaMaxs[i]);
        eYieldEE = H2GetBinErrors(H2EE, ptMins[i], ptMaxs[i], etaMins[i], etaMaxs[i]);
        eYieldMM = H2GetBinErrors(H2MM, ptMins[i], ptMaxs[i], etaMins[i], etaMaxs[i]);
        double R = YieldEE / YieldMM;
        double eR = R * sqrt(pow(eYieldEE/YieldEE, 2) + pow(eYieldMM/YieldMM, 2));
        Epsilon = sqrt(R);
        eEpsilon = 0.5 * Epsilon * eR / R;
        printf("%10.0f  %10.0f  %10.2f  %10.2f  :  %10.2f +- %10.2f  /  %10.2f +- %10.2f  =  %10.5f +- %10.5f\n", 
                ptMins[i], ptMaxs[i], etaMins[i], etaMaxs[i],
                YieldEE, eYieldEE, YieldMM, eYieldMM, Epsilon, eEpsilon);
    }
    f->Close();
}

#endif
