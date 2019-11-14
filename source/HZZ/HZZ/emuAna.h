#ifndef HZZ_EMUANA_H
#define HZZ_EMUANA_H

#include <string>
#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <TH1D.h>
#include <TH2D.h>
#include <cmath>

double H3GetBinContents(TH3D* h, double xMin, double xMax, double yMin, double yMax, double factor){
    double r = 0.0;
    for (int i=1; i<=h->GetNbinsX(); i++){
        for (int j=1; j<=h->GetNbinsY(); j++){
            for (int k=1; k<=h->GetNbinsZ(); k++){
                if (xMin<=h->GetXaxis()->GetBinLowEdge(i) && xMax>=h->GetXaxis()->GetBinUpEdge(i)
                        && yMin<=h->GetYaxis()->GetBinLowEdge(j) && yMax>=h->GetYaxis()->GetBinUpEdge(j)){
                    r+= h->GetBinContent(i, j, k);
                    h->SetBinContent(i, j, k, h->GetBinContent(i, j, k) * factor);
                }
            }
        }
    }
    return r;
}

double H3GetBinErrors(TH3D* h, double xMin, double xMax, double yMin, double yMax, double factor){
    double r2 = 0.0;
    for (int i=1; i<=h->GetNbinsX(); i++){
        for (int j=1; j<=h->GetNbinsY(); j++){
            for (int k=1; k<=h->GetNbinsZ(); k++){
                if (xMin<=h->GetXaxis()->GetBinLowEdge(i) && xMax>=h->GetXaxis()->GetBinUpEdge(i)
                        && yMin<=h->GetYaxis()->GetBinLowEdge(j) && yMax>=h->GetYaxis()->GetBinUpEdge(j)){
                    r2+= h->GetBinError(i, j, k) * h->GetBinError(i, j, k);
                    h->SetBinError(i, j, k, h->GetBinError(i, j, k) * factor);
                }
            }
        }
    }
    return  sqrt(r2);
}

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
    TFile *f = new TFile(filename.c_str(), "update");
    if (!f) {
        printf("%s not opened.\n", filename.c_str());
        return;
    }

    TH1D* H1EE = GetH1(f, tag+"_ggF_EE_mTZZ");
    TH1D* H1MM = GetH1(f, tag+"_ggF_MM_mTZZ");
    TH1D* H1EM = GetH1(f, tag+"_ggF_EM_mTZZ");
    TH2D* H2EE = GetH2(f, tag+"_onshell_EE");
    TH2D* H2MM = GetH2(f, tag+"_onshell_MM");
    //TH3D* H3JETE = GetH3(f, tag+"_JET_E_PT_ETA_mTZZ");
    //TH3D* H3JETM = GetH3(f, tag+"_JET_M_PT_ETA_mTZZ");
    //TH3D* H3VBFE = GetH3(f, tag+"_VBF_E_PT_ETA_mTZZ");
    //TH3D* H3VBFM = GetH3(f, tag+"_VBF_M_PT_ETA_mTZZ");
    TH3D* H3ggFE = GetH3(f, tag+"_ggF_E_PT_ETA_mTZZ");
    TH3D* H3ggFM = GetH3(f, tag+"_ggF_M_PT_ETA_mTZZ");
    TH3D* H3ggFEbk = (TH3D*)H3ggFE->Clone();
    TH3D* H3ggFMbk = (TH3D*)H3ggFM->Clone();

    double YieldEE = 0.0,
           YieldMM = 0.0,
           Epsilon = 0.0;
    double eYieldEE = 0.0,
           eYieldMM = 0.0,
           eEpsilon = 0.0;
    double R = 0.0,
           eR = 0.0;
    double YieldE = 0.0,
           YieldM = 0.0,
           eYieldE = 0.0,
           eYieldM = 0.0;
    double ansEE = 0.0,
           ansMM = 0.0,
           eansEE = 0.0,
           eansMM = 0.0;
    double electron = 0.0,
           muon = 0.0,
           eelectron = 0.0,
           emuon = 0.0;
    std::vector<double> ptMins  = {20, 45,  55,   20,   45,   55,   20,   45,   55};
    std::vector<double> ptMaxs  = {45, 55, 9e9,   45,   55,  9e9,   45,   55,  9e9};
    std::vector<double> etaMins = { 0,  0,   0,    1,    1,    1, 1.37, 1.37, 1.37};
    std::vector<double> etaMaxs = { 1,  1,   1, 1.37, 1.37, 1.37,  2.5,  2.5,  2.5};

    for (int i=0; i<ptMaxs.size(); i++){
        // epsilon factor
        YieldEE = H2GetBinContents(H2EE, ptMins[i], ptMaxs[i], etaMins[i], etaMaxs[i]);
        YieldMM = H2GetBinContents(H2MM, ptMins[i], ptMaxs[i], etaMins[i], etaMaxs[i]);
        eYieldEE = H2GetBinErrors(H2EE, ptMins[i], ptMaxs[i], etaMins[i], etaMaxs[i]);
        eYieldMM = H2GetBinErrors(H2MM, ptMins[i], ptMaxs[i], etaMins[i], etaMaxs[i]);
        R = YieldEE / YieldMM;
        eR = R * sqrt(pow(eYieldEE/YieldEE, 2) + pow(eYieldMM/YieldMM, 2));
        Epsilon = sqrt(R);
        eEpsilon = 0.5 * Epsilon * eR / R;

        // emu -> mm
        YieldE = H3GetBinContents(H3ggFEbk, ptMins[i], ptMaxs[i], etaMins[i], etaMaxs[i], 0.5/Epsilon);
        eYieldE = H3GetBinErrors(H3ggFEbk, ptMins[i], ptMaxs[i], etaMins[i], etaMaxs[i], 0.5/Epsilon);
        ansMM = 0.5 * YieldE / Epsilon;
        eansMM = 0.5 * sqrt(pow(eYieldE*Epsilon, 2) + pow(eEpsilon*YieldE, 2)) / pow(Epsilon, 2);

        // emu -> ee
        YieldM = H3GetBinContents(H3ggFMbk, ptMins[i], ptMaxs[i], etaMins[i], etaMaxs[i], 0.5*Epsilon);
        eYieldM = H3GetBinErrors(H3ggFMbk, ptMins[i], ptMaxs[i], etaMins[i], etaMaxs[i], 0.5*Epsilon);
        ansEE = 0.5 * YieldM * Epsilon;
        eansEE = 0.5 * sqrt(pow(eEpsilon, 2) + pow(eYieldM, 2));

        electron += ansEE;
        muon += ansMM;
        eelectron += eansEE * eansEE;
        emuon += eansMM * eansMM;
        printf("%10.0f  %10.0f  %10.2f  %10.2f  :  %10.2f +- %10.2f  /  %10.2f +- %10.2f  =  %10.5f +- %10.5f  ->  %10.5f +- %10.5f , %10.5f +- %10.5f\n", 
                ptMins[i], ptMaxs[i], etaMins[i], etaMaxs[i],
                YieldEE, eYieldEE, YieldMM, eYieldMM, Epsilon, eEpsilon, 
                //YieldE, eYieldE, YieldM, eYieldM
                ansEE, eansEE, ansMM, eansMM
              );

    }
    printf("from selection\n");
    double tmp0, tmp1;
    tmp0 = H1EE->IntegralAndError(0, -1, tmp1);
    printf("electron: %10.5f +- %10.5f\n", tmp0, tmp1);
    tmp0 = H1MM->IntegralAndError(0, -1, tmp1);
    printf("muon    : %10.5f +- %10.5f\n", tmp0, tmp1);
    tmp0 = H1EM->IntegralAndError(0, -1, tmp1);
    printf("em/2    : %10.5f +- %10.5f\n", tmp0/2, tmp1/2);
    printf("from estimation\n");
    printf("electron: %10.5f +- %10.5f\n", electron, sqrt(eelectron));
    printf("muon    : %10.5f +- %10.5f\n", muon, sqrt(emuon));

    TH1D* H1ggFM = H3ggFEbk->ProjectionZ();
    TH1D* H1ggFE = H3ggFMbk->ProjectionZ();

    f->cd();
    H1ggFE->Write((tag+"_ggF_ee_mTZZ").c_str());
    H1ggFM->Write((tag+"_ggF_mm_mTZZ").c_str());

    f->Close();
}

#endif
