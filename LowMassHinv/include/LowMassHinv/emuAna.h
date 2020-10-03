#ifndef LowMassHinv_emuAna_H
#define LowMassHinv_emuAna_H

#include <string>
#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <TH1D.h>
#include <TH2D.h>
#include <cmath>

double H2GetBinContents(TH2D* h, int nb, double factor){
    double r = 0.0;
    for (int j=1; j<=h->GetNbinsY(); j++){
        r+= h->GetBinContent(nb, j);
        h->SetBinContent(nb, j, h->GetBinContent(nb, j) * factor);
    }
    return r;
}

double H2GetBinErrors(TH2D* h, int nb, double factor){
    double r2 = 0.0;
    for (int j=1; j<=h->GetNbinsY(); j++){
        r2+= h->GetBinError(nb, j) * h->GetBinError(nb, j);
        h->SetBinError(nb, j, h->GetBinError(nb, j) * factor);
    }
    return  sqrt(r2);
}

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


void HM_analysis(std::string tag, std::string filename){
    TFile *f = new TFile(filename.c_str(), "update");
    if (!f) {
        printf("%s not opened.\n", filename.c_str());
        return;
    }

    TH1D* H1EEggF = GetH1(f, tag+"_ggF_EE_BDT");
    TH1D* H1MMggF = GetH1(f, tag+"_ggF_MM_BDT");
    TH1D* H1EMggF = GetH1(f, tag+"_ggF_EM_BDT");
    TH1D* H1EEVBF = GetH1(f, tag+"_VBF_EE_BDT");
    TH1D* H1MMVBF = GetH1(f, tag+"_VBF_MM_BDT");
    TH1D* H1EMVBF = GetH1(f, tag+"_VBF_EM_BDT");
    TH1D* H1EEJET = GetH1(f, tag+"_JET_EE_BDT");
    TH1D* H1MMJET = GetH1(f, tag+"_JET_MM_BDT");
    TH1D* H1EMJET = GetH1(f, tag+"_JET_EM_BDT");
    TH1D* H1EE = GetH1(f, tag+"_onshell_EE");
    TH1D* H1MM = GetH1(f, tag+"_onshell_MM");
    TH2D* H2JETE = GetH2(f, tag+"_JET_E_PT_ETA_BDT");
    TH2D* H2JETM = GetH2(f, tag+"_JET_M_PT_ETA_BDT");
    TH2D* H2VBFE = GetH2(f, tag+"_VBF_E_PT_ETA_BDT");
    TH2D* H2VBFM = GetH2(f, tag+"_VBF_M_PT_ETA_BDT");
    TH2D* H2ggFE = GetH2(f, tag+"_ggF_E_PT_ETA_BDT");
    TH2D* H2ggFM = GetH2(f, tag+"_ggF_M_PT_ETA_BDT");
    TH2D* H2JETEbk = (TH2D*)H2JETE->Clone();
    TH2D* H2JETMbk = (TH2D*)H2JETM->Clone();
    TH2D* H2VBFEbk = (TH2D*)H2VBFE->Clone();
    TH2D* H2VBFMbk = (TH2D*)H2VBFM->Clone();
    TH2D* H2ggFEbk = (TH2D*)H2ggFE->Clone();
    TH2D* H2ggFMbk = (TH2D*)H2ggFM->Clone();

    double R, uR;
    double inc_epsilon, uinc_epsilon;
    double inc_ee, uinc_ee;
    double inc_mm, uinc_mm;
    double inc_em, uinc_em;
    inc_ee = H1EE->IntegralAndError(0, -1, uinc_ee);
    inc_mm = H1MM->IntegralAndError(0, -1, uinc_mm);
    inc_em = H1EMggF->IntegralAndError(0, -1, uinc_em);
    R = inc_ee / inc_mm;
    uR = inc_epsilon * sqrt(pow(uinc_ee/inc_ee, 2) + pow(uinc_mm/inc_mm, 2));
    inc_epsilon = sqrt(R);
    uinc_epsilon = 0.5 * inc_epsilon * uR / R;
    inc_ee = 0.5 * inc_em * inc_epsilon;
    inc_mm = 0.5 * inc_em / inc_epsilon;
    uinc_ee = 0.5 * sqrt(uinc_em * uinc_em + uinc_epsilon * uinc_epsilon);
    uinc_mm = 0.5 * sqrt(pow(uinc_em*inc_epsilon, 2) + pow(uinc_epsilon*uinc_em, 2)) / pow(inc_epsilon, 2);
    printf("inclusive estimation:\n");
    printf("epsilon factor: %6.4f \\pm %6.4f\n", inc_epsilon, uinc_epsilon);
    printf("em events     : %6.2f \\pm %6.2f\n", inc_em, uinc_em);
    printf("ee events     : %6.2f \\pm %6.2f\n", inc_ee, uinc_ee);
    printf("mm events     : %6.2f \\pm %6.2f\n", inc_mm, uinc_mm);
    printf("\n");

    std::vector<double>  loose_ee;  loose_ee.clear();
    std::vector<double>  loose_mm;  loose_mm.clear();
    std::vector<double>  epsilon;   epsilon.clear();
    std::vector<double>  uloose_ee;  uloose_ee.clear();
    std::vector<double>  uloose_mm;  uloose_mm.clear();
    std::vector<double>  uepsilon;   uepsilon.clear();
    std::vector<double> selected_em_for_ee; selected_em_for_ee.clear();
    std::vector<double> selected_em_for_mm; selected_em_for_mm.clear();
    std::vector<double> estimated_ee; estimated_ee.clear();
    std::vector<double> estimated_mm; estimated_mm.clear();
    std::vector<double> uselected_em_for_ee; uselected_em_for_ee.clear();
    std::vector<double> uselected_em_for_mm; uselected_em_for_mm.clear();
    std::vector<double> uestimated_ee; uestimated_ee.clear();
    std::vector<double> uestimated_mm; uestimated_mm.clear();

    std::vector<double> ptMins  = {20, 45,  55,   20,   45,   55,   20,   45,   55};
    std::vector<double> ptMaxs  = {45, 55, 9e9,   45,   55,  9e9,   45,   55,  9e9};
    std::vector<double> etaMins = { 0,  0,   0,    1,    1,    1, 1.37, 1.37, 1.37};
    std::vector<double> etaMaxs = { 1,  1,   1, 1.37, 1.37, 1.37,  2.5,  2.5,  2.5};

    for (int i=0; i<ptMaxs.size(); i++){
        loose_ee.push_back(0.); uloose_ee.push_back(0.);
        loose_mm.push_back(0.); uloose_mm.push_back(0.);
        epsilon.push_back(0.); uepsilon.push_back(0.);
        selected_em_for_ee.push_back(0.); uselected_em_for_ee.push_back(0.);
        selected_em_for_mm.push_back(0.); uselected_em_for_mm.push_back(0.);
        estimated_ee.push_back(0.); uestimated_ee.push_back(0.);
        estimated_mm.push_back(0.); uestimated_mm.push_back(0.);
    }

    double electron, muon, uelectron, umuon;
    double tmp0, tmp1;


    for (int i=0; i<ptMaxs.size(); i++){
        // epsilon factor
        loose_ee[i]  = H1EE->GetBinContent(i+1);
        loose_mm[i]  = H1MM->GetBinContent(i+1);
        uloose_ee[i] = H1EE->GetBinError  (i+1);
        uloose_mm[i] = H1MM->GetBinError  (i+1);
        R = loose_ee[i] / loose_mm[i];
        uR = R * sqrt(pow(uloose_ee[i]/loose_ee[i], 2) + pow(uloose_mm[i]/loose_mm[i], 2));
        epsilon[i] = sqrt(R);
        uepsilon[i] = 0.5 * epsilon[i] * uR / R;
    }


    printf("%s\n", std::string(80,'*').c_str());
    printf("\\begin{tabular}{|c|c|c|c|}\n");
    printf("\\hline\n");
    printf("                 & $0<\\eta<1$            & $1<\\eta<1.37$         & $1.37<\\eta<2.5$       \\\\ \\hline\n");
    printf("$20<\\pt<45$ GeV  & $%6.4f \\pm %6.4f$   & $%6.4f \\pm %6.4f$   & $%6.4f \\pm %6.4f$   \\\\ \\hline\n", epsilon[0], uepsilon[0], epsilon[3], uepsilon[3], epsilon[6], uepsilon[6]);
    printf("$45<\\pt<55$ GeV  & $%6.4f \\pm %6.4f$   & $%6.4f \\pm %6.4f$   & $%6.4f \\pm %6.4f$   \\\\ \\hline\n", epsilon[1], uepsilon[1], epsilon[4], uepsilon[4], epsilon[7], uepsilon[7]);
    printf("$   \\pt>55$ GeV  & $%6.4f \\pm %6.4f$   & $%6.4f \\pm %6.4f$   & $%6.4f \\pm %6.4f$   \\\\ \\hline\n", epsilon[2], uepsilon[2], epsilon[5], uepsilon[5], epsilon[8], uepsilon[8]);
    printf("\\end{tabular}\n");
    printf("%s\n", std::string(80,'*').c_str());


    electron = 0.0; muon = 0.0; uelectron = 0.0; umuon = 0.0;
    for (int i=0; i<ptMaxs.size(); i++){
        // emu -> mm
        selected_em_for_mm[i]  = H2GetBinContents(H2ggFEbk, i+1, 0.5/epsilon[i]);
        uselected_em_for_mm[i] = H2GetBinErrors  (H2ggFEbk, i+1, 0.5/epsilon[i]);
        estimated_mm[i]  = 0.5 * selected_em_for_mm[i] / epsilon[i];
        uestimated_mm[i] = 0.5 * sqrt(pow(uselected_em_for_mm[i]*epsilon[i], 2) + pow(uepsilon[i]*selected_em_for_mm[i], 2)) / pow(epsilon[i], 2);

        // emu -> ee
        selected_em_for_ee[i]  = H2GetBinContents(H2ggFMbk, i+1, 0.5*epsilon[i]);
        uselected_em_for_ee[i] = H2GetBinErrors  (H2ggFMbk, i+1, 0.5*epsilon[i]);
        estimated_ee[i]  = 0.5 * selected_em_for_ee[i] * epsilon[i];
        uestimated_ee[i] = 0.5 * sqrt(pow(uepsilon[i], 2) + pow(uselected_em_for_ee[i], 2));

        electron  +=  estimated_ee[i];
        muon      +=  estimated_mm[i];
        uelectron += uestimated_ee[i] * uestimated_ee[i];
        umuon     += uestimated_mm[i] * uestimated_mm[i];
    }

    printf("\\begin{tabular}{|c|c|c|c|c|}\n");
    printf("\\hline\n");
    printf(" & selected $e\\mu$ for $ee$ & estimated $ee$ & selected $e\\mu$ for $\\mu\\mu$ & estimated $\\mu\\mu$       \\\\ \\hline\n");
    printf("$20<\\pt<45$ GeV, $0   <\\eta<1   $  & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   \\\\ \\hline\n",
            selected_em_for_ee[0], uselected_em_for_ee[0], estimated_ee[0], uestimated_ee[0],
            selected_em_for_mm[0], uselected_em_for_mm[0], estimated_mm[0], uestimated_mm[0]);
    printf("$45<\\pt<55$ GeV, $0   <\\eta<1   $  & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   \\\\ \\hline\n",
            selected_em_for_ee[1], uselected_em_for_ee[1], estimated_ee[1], uestimated_ee[1],
            selected_em_for_mm[1], uselected_em_for_mm[1], estimated_mm[1], uestimated_mm[1]);
    printf("$   \\pt>55$ GeV, $0   <\\eta<1   $  & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   \\\\ \\hline\n",
            selected_em_for_ee[2], uselected_em_for_ee[2], estimated_ee[2], uestimated_ee[2],
            selected_em_for_mm[2], uselected_em_for_mm[2], estimated_mm[2], uestimated_mm[2]);
    printf("$20<\\pt<45$ GeV, $1   <\\eta<1.37$  & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   \\\\ \\hline\n",
            selected_em_for_ee[3], uselected_em_for_ee[3], estimated_ee[3], uestimated_ee[3],
            selected_em_for_mm[3], uselected_em_for_mm[3], estimated_mm[3], uestimated_mm[3]);
    printf("$45<\\pt<55$ GeV, $1   <\\eta<1.37$  & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   \\\\ \\hline\n",
            selected_em_for_ee[4], uselected_em_for_ee[4], estimated_ee[4], uestimated_ee[4],
            selected_em_for_mm[4], uselected_em_for_mm[4], estimated_mm[4], uestimated_mm[4]);
    printf("$   \\pt>55$ GeV, $1   <\\eta<1.37$  & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   \\\\ \\hline\n",
            selected_em_for_ee[5], uselected_em_for_ee[5], estimated_ee[5], uestimated_ee[5],
            selected_em_for_mm[5], uselected_em_for_mm[5], estimated_mm[5], uestimated_mm[5]);
    printf("$20<\\pt<45$ GeV, $1.37<\\eta<2.5 $  & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   \\\\ \\hline\n",
            selected_em_for_ee[6], uselected_em_for_ee[6], estimated_ee[6], uestimated_ee[6],
            selected_em_for_mm[6], uselected_em_for_mm[6], estimated_mm[6], uestimated_mm[6]);
    printf("$45<\\pt<55$ GeV, $1.37<\\eta<2.5 $  & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   \\\\ \\hline\n",
            selected_em_for_ee[7], uselected_em_for_ee[7], estimated_ee[7], uestimated_ee[7],
            selected_em_for_mm[7], uselected_em_for_mm[7], estimated_mm[7], uestimated_mm[7]);
    printf("$   \\pt>55$ GeV, $1.37<\\eta<2.5 $  & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   \\\\ \\hline\n",
            selected_em_for_ee[8], uselected_em_for_ee[8], estimated_ee[8], uestimated_ee[8],
            selected_em_for_mm[8], uselected_em_for_mm[8], estimated_mm[8], uestimated_mm[8]);
    printf("\\end{tabular}]\n");
    printf("%s\n", std::string(80,'*').c_str());


    printf("from selection\n");
    tmp0 = H1EEggF->IntegralAndError(0, -1, tmp1);
    printf("electron: %10.5f +- %10.5f\n", tmp0, tmp1);
    tmp0 = H1MMggF->IntegralAndError(0, -1, tmp1);
    printf("muon    : %10.5f +- %10.5f\n", tmp0, tmp1);
    tmp0 = H1EMggF->IntegralAndError(0, -1, tmp1);
    printf("em/2    : %10.5f +- %10.5f\n", tmp0/2, tmp1/2);
    printf("from estimation\n");
    printf("electron: %10.5f +- %10.5f\n", electron, sqrt(uelectron));
    printf("muon    : %10.5f +- %10.5f\n", muon, sqrt(umuon));
    printf("\n\n");


    electron = 0.0; muon = 0.0; uelectron = 0.0; umuon = 0.0;
    for (int i=0; i<ptMaxs.size(); i++){
        // emu -> mm
        selected_em_for_mm[i]  = H2GetBinContents(H2VBFEbk, i+1, 0.5/epsilon[i]);
        uselected_em_for_mm[i] = H2GetBinErrors  (H2VBFEbk, i+1, 0.5/epsilon[i]);
        estimated_mm[i]  = 0.5 * selected_em_for_mm[i] / epsilon[i];
        uestimated_mm[i] = 0.5 * sqrt(pow(uselected_em_for_mm[i]*epsilon[i], 2) + pow(uepsilon[i]*selected_em_for_mm[i], 2)) / pow(epsilon[i], 2);

        // emu -> ee
        selected_em_for_ee[i]  = H2GetBinContents(H2VBFMbk, i+1, 0.5*epsilon[i]);
        uselected_em_for_ee[i] = H2GetBinErrors  (H2VBFMbk, i+1, 0.5*epsilon[i]);
        estimated_ee[i]  = 0.5 * selected_em_for_ee[i] * epsilon[i];
        uestimated_ee[i] = 0.5 * sqrt(pow(uepsilon[i], 2) + pow(uselected_em_for_ee[i], 2));

        electron  +=  estimated_ee[i];
        muon      +=  estimated_mm[i];
        uelectron += uestimated_ee[i] * uestimated_ee[i];
        umuon     += uestimated_mm[i] * uestimated_mm[i];
    }

    printf("from selection\n");
    tmp0 = H1EEVBF->IntegralAndError(0, -1, tmp1);
    printf("electron: %10.5f +- %10.5f\n", tmp0, tmp1);
    tmp0 = H1MMVBF->IntegralAndError(0, -1, tmp1);
    printf("muon    : %10.5f +- %10.5f\n", tmp0, tmp1);
    tmp0 = H1EMVBF->IntegralAndError(0, -1, tmp1);
    printf("em/2    : %10.5f +- %10.5f\n", tmp0/2, tmp1/2);
    printf("from estimation\n");
    printf("electron: %10.5f +- %10.5f\n", electron, sqrt(uelectron));
    printf("muon    : %10.5f +- %10.5f\n", muon, sqrt(umuon));
    printf("\n\n");


    electron = 0.0; muon = 0.0; uelectron = 0.0; umuon = 0.0;
    for (int i=0; i<ptMaxs.size(); i++){
        // emu -> mm
        selected_em_for_mm[i]  = H2GetBinContents(H2JETEbk, i+1, 0.5/epsilon[i]);
        uselected_em_for_mm[i] = H2GetBinErrors  (H2JETEbk, i+1, 0.5/epsilon[i]);
        estimated_mm[i]  = 0.5 * selected_em_for_mm[i] / epsilon[i];
        uestimated_mm[i] = 0.5 * sqrt(pow(uselected_em_for_mm[i]*epsilon[i], 2) + pow(uepsilon[i]*selected_em_for_mm[i], 2)) / pow(epsilon[i], 2);

        // emu -> ee
        selected_em_for_ee[i]  = H2GetBinContents(H2JETMbk, i+1, 0.5*epsilon[i]);
        uselected_em_for_ee[i] = H2GetBinErrors  (H2JETMbk, i+1, 0.5*epsilon[i]);
        estimated_ee[i]  = 0.5 * selected_em_for_ee[i] * epsilon[i];
        uestimated_ee[i] = 0.5 * sqrt(pow(uepsilon[i], 2) + pow(uselected_em_for_ee[i], 2));

        electron  +=  estimated_ee[i];
        muon      +=  estimated_mm[i];
        uelectron += uestimated_ee[i] * uestimated_ee[i];
        umuon     += uestimated_mm[i] * uestimated_mm[i];
    }

    printf("from selection\n");
    tmp0 = H1EEJET->IntegralAndError(0, -1, tmp1);
    printf("electron: %10.5f +- %10.5f\n", tmp0, tmp1);
    tmp0 = H1MMJET->IntegralAndError(0, -1, tmp1);
    printf("muon    : %10.5f +- %10.5f\n", tmp0, tmp1);
    tmp0 = H1EMJET->IntegralAndError(0, -1, tmp1);
    printf("em/2    : %10.5f +- %10.5f\n", tmp0/2, tmp1/2);
    printf("from estimation\n");
    printf("electron: %10.5f +- %10.5f\n", electron, sqrt(uelectron));
    printf("muon    : %10.5f +- %10.5f\n", muon, sqrt(umuon));
    printf("\n\n");


    TH1D* H1ggFM = H2ggFEbk->ProjectionY();
    TH1D* H1ggFE = H2ggFMbk->ProjectionY();
    TH1D* H1VBFM = H2VBFEbk->ProjectionY();
    TH1D* H1VBFE = H2VBFMbk->ProjectionY();
    TH1D* H1JETM = H2JETEbk->ProjectionY();
    TH1D* H1JETE = H2JETMbk->ProjectionY();

    f->cd();
    H1ggFE->Write((tag+"_ggF_ee_BDT").c_str());
    H1ggFM->Write((tag+"_ggF_mm_BDT").c_str());
    H1VBFE->Write((tag+"_VBF_ee_BDT").c_str());
    H1VBFM->Write((tag+"_VBF_mm_BDT").c_str());
    H1JETE->Write((tag+"_JET_ee_BDT").c_str());
    H1JETM->Write((tag+"_JET_mm_BDT").c_str());

    f->Close();
}

void LM_analysis(std::string tag, std::string filename){
    TFile *f = new TFile(filename.c_str(), "update");
    if (!f) {
        printf("%s not opened.\n", filename.c_str());
        return;
    }

    TH1D* H1EEggF = GetH1(f, tag+"_ggF_EE_BDT");
    TH1D* H1MMggF = GetH1(f, tag+"_ggF_MM_BDT");
    TH1D* H1EMggF = GetH1(f, tag+"_ggF_EM_BDT");
    TH1D* H1EE = GetH1(f, tag+"_onshell_EE");
    TH1D* H1MM = GetH1(f, tag+"_onshell_MM");
    TH2D* H2ggFE = GetH2(f, tag+"_ggF_E_PT_ETA_BDT");
    TH2D* H2ggFM = GetH2(f, tag+"_ggF_M_PT_ETA_BDT");
    TH2D* H2ggFEbk = (TH2D*)H2ggFE->Clone();
    TH2D* H2ggFMbk = (TH2D*)H2ggFM->Clone();

    double R, uR;
    double inc_epsilon, uinc_epsilon;
    double inc_ee, uinc_ee;
    double inc_mm, uinc_mm;
    double inc_em, uinc_em;
    inc_ee = H1EE->IntegralAndError(0, -1, uinc_ee);
    inc_mm = H1MM->IntegralAndError(0, -1, uinc_mm);
    inc_em = H1EMggF->IntegralAndError(0, -1, uinc_em);
    R = inc_ee / inc_mm;
    uR = inc_epsilon * sqrt(pow(uinc_ee/inc_ee, 2) + pow(uinc_mm/inc_mm, 2));
    inc_epsilon = sqrt(R);
    uinc_epsilon = 0.5 * inc_epsilon * uR / R;
    inc_ee = 0.5 * inc_em * inc_epsilon;
    inc_mm = 0.5 * inc_em / inc_epsilon;
    uinc_ee = 0.5 * sqrt(uinc_em * uinc_em + uinc_epsilon * uinc_epsilon);
    uinc_mm = 0.5 * sqrt(pow(uinc_em*inc_epsilon, 2) + pow(uinc_epsilon*uinc_em, 2)) / pow(inc_epsilon, 2);
    printf("inclusive estimation:\n");
    printf("epsilon factor: %6.4f \\pm %6.4f\n", inc_epsilon, uinc_epsilon);
    printf("em events     : %6.2f \\pm %6.2f\n", inc_em, uinc_em);
    printf("ee events     : %6.2f \\pm %6.2f\n", inc_ee, uinc_ee);
    printf("mm events     : %6.2f \\pm %6.2f\n", inc_mm, uinc_mm);
    printf("\n");

    std::vector<double>  loose_ee;  loose_ee.clear();
    std::vector<double>  loose_mm;  loose_mm.clear();
    std::vector<double>  epsilon;   epsilon.clear();
    std::vector<double>  uloose_ee;  uloose_ee.clear();
    std::vector<double>  uloose_mm;  uloose_mm.clear();
    std::vector<double>  uepsilon;   uepsilon.clear();
    std::vector<double> selected_em_for_ee; selected_em_for_ee.clear();
    std::vector<double> selected_em_for_mm; selected_em_for_mm.clear();
    std::vector<double> estimated_ee; estimated_ee.clear();
    std::vector<double> estimated_mm; estimated_mm.clear();
    std::vector<double> uselected_em_for_ee; uselected_em_for_ee.clear();
    std::vector<double> uselected_em_for_mm; uselected_em_for_mm.clear();
    std::vector<double> uestimated_ee; uestimated_ee.clear();
    std::vector<double> uestimated_mm; uestimated_mm.clear();

    std::vector<double> ptMins  = {20, 45,  55,   20,   45,   55,   20,   45,   55};
    std::vector<double> ptMaxs  = {45, 55, 9e9,   45,   55,  9e9,   45,   55,  9e9};
    std::vector<double> etaMins = { 0,  0,   0,    1,    1,    1, 1.37, 1.37, 1.37};
    std::vector<double> etaMaxs = { 1,  1,   1, 1.37, 1.37, 1.37,  2.5,  2.5,  2.5};

    for (int i=0; i<ptMaxs.size(); i++){
        loose_ee.push_back(0.); uloose_ee.push_back(0.);
        loose_mm.push_back(0.); uloose_mm.push_back(0.);
        epsilon.push_back(0.); uepsilon.push_back(0.);
        selected_em_for_ee.push_back(0.); uselected_em_for_ee.push_back(0.);
        selected_em_for_mm.push_back(0.); uselected_em_for_mm.push_back(0.);
        estimated_ee.push_back(0.); uestimated_ee.push_back(0.);
        estimated_mm.push_back(0.); uestimated_mm.push_back(0.);
    }

    double electron, muon, uelectron, umuon;
    double tmp0, tmp1;


    for (int i=0; i<ptMaxs.size(); i++){
        // epsilon factor
        loose_ee[i]  = H1EE->GetBinContent(i+1);
        loose_mm[i]  = H1MM->GetBinContent(i+1);
        uloose_ee[i] = H1EE->GetBinError  (i+1);
        uloose_mm[i] = H1MM->GetBinError  (i+1);
        R = loose_ee[i] / loose_mm[i];
        uR = R * sqrt(pow(uloose_ee[i]/loose_ee[i], 2) + pow(uloose_mm[i]/loose_mm[i], 2));
        epsilon[i] = sqrt(R);
        uepsilon[i] = 0.5 * epsilon[i] * uR / R;
    }


    printf("%s\n", std::string(80,'*').c_str());
    printf("\\begin{tabular}{|c|c|c|c|}\n");
    printf("\\hline\n");
    printf("                 & $0<\\eta<1$            & $1<\\eta<1.37$         & $1.37<\\eta<2.5$       \\\\ \\hline\n");
    printf("$20<\\pt<45$ GeV  & $%6.4f \\pm %6.4f$   & $%6.4f \\pm %6.4f$   & $%6.4f \\pm %6.4f$   \\\\ \\hline\n", epsilon[0], uepsilon[0], epsilon[3], uepsilon[3], epsilon[6], uepsilon[6]);
    printf("$45<\\pt<55$ GeV  & $%6.4f \\pm %6.4f$   & $%6.4f \\pm %6.4f$   & $%6.4f \\pm %6.4f$   \\\\ \\hline\n", epsilon[1], uepsilon[1], epsilon[4], uepsilon[4], epsilon[7], uepsilon[7]);
    printf("$   \\pt>55$ GeV  & $%6.4f \\pm %6.4f$   & $%6.4f \\pm %6.4f$   & $%6.4f \\pm %6.4f$   \\\\ \\hline\n", epsilon[2], uepsilon[2], epsilon[5], uepsilon[5], epsilon[8], uepsilon[8]);
    printf("\\end{tabular}\n");
    printf("%s\n", std::string(80,'*').c_str());


    electron = 0.0; muon = 0.0; uelectron = 0.0; umuon = 0.0;
    for (int i=0; i<ptMaxs.size(); i++){
        // emu -> mm
        selected_em_for_mm[i]  = H2GetBinContents(H2ggFEbk, i+1, 0.5/epsilon[i]);
        uselected_em_for_mm[i] = H2GetBinErrors  (H2ggFEbk, i+1, 0.5/epsilon[i]);
        estimated_mm[i]  = 0.5 * selected_em_for_mm[i] / epsilon[i];
        uestimated_mm[i] = 0.5 * sqrt(pow(uselected_em_for_mm[i]*epsilon[i], 2) + pow(uepsilon[i]*selected_em_for_mm[i], 2)) / pow(epsilon[i], 2);

        // emu -> ee
        selected_em_for_ee[i]  = H2GetBinContents(H2ggFMbk, i+1, 0.5*epsilon[i]);
        uselected_em_for_ee[i] = H2GetBinErrors  (H2ggFMbk, i+1, 0.5*epsilon[i]);
        estimated_ee[i]  = 0.5 * selected_em_for_ee[i] * epsilon[i];
        uestimated_ee[i] = 0.5 * sqrt(pow(uepsilon[i], 2) + pow(uselected_em_for_ee[i], 2));

        electron  +=  estimated_ee[i];
        muon      +=  estimated_mm[i];
        uelectron += uestimated_ee[i] * uestimated_ee[i];
        umuon     += uestimated_mm[i] * uestimated_mm[i];
    }

    printf("\\begin{tabular}{|c|c|c|c|c|}\n");
    printf("\\hline\n");
    printf(" & selected $e\\mu$ for $ee$ & estimated $ee$ & selected $e\\mu$ for $\\mu\\mu$ & estimated $\\mu\\mu$       \\\\ \\hline\n");
    printf("$20<\\pt<45$ GeV, $0   <\\eta<1   $  & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   \\\\ \\hline\n",
            selected_em_for_ee[0], uselected_em_for_ee[0], estimated_ee[0], uestimated_ee[0],
            selected_em_for_mm[0], uselected_em_for_mm[0], estimated_mm[0], uestimated_mm[0]);
    printf("$45<\\pt<55$ GeV, $0   <\\eta<1   $  & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   \\\\ \\hline\n",
            selected_em_for_ee[1], uselected_em_for_ee[1], estimated_ee[1], uestimated_ee[1],
            selected_em_for_mm[1], uselected_em_for_mm[1], estimated_mm[1], uestimated_mm[1]);
    printf("$   \\pt>55$ GeV, $0   <\\eta<1   $  & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   \\\\ \\hline\n",
            selected_em_for_ee[2], uselected_em_for_ee[2], estimated_ee[2], uestimated_ee[2],
            selected_em_for_mm[2], uselected_em_for_mm[2], estimated_mm[2], uestimated_mm[2]);
    printf("$20<\\pt<45$ GeV, $1   <\\eta<1.37$  & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   \\\\ \\hline\n",
            selected_em_for_ee[3], uselected_em_for_ee[3], estimated_ee[3], uestimated_ee[3],
            selected_em_for_mm[3], uselected_em_for_mm[3], estimated_mm[3], uestimated_mm[3]);
    printf("$45<\\pt<55$ GeV, $1   <\\eta<1.37$  & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   \\\\ \\hline\n",
            selected_em_for_ee[4], uselected_em_for_ee[4], estimated_ee[4], uestimated_ee[4],
            selected_em_for_mm[4], uselected_em_for_mm[4], estimated_mm[4], uestimated_mm[4]);
    printf("$   \\pt>55$ GeV, $1   <\\eta<1.37$  & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   \\\\ \\hline\n",
            selected_em_for_ee[5], uselected_em_for_ee[5], estimated_ee[5], uestimated_ee[5],
            selected_em_for_mm[5], uselected_em_for_mm[5], estimated_mm[5], uestimated_mm[5]);
    printf("$20<\\pt<45$ GeV, $1.37<\\eta<2.5 $  & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   \\\\ \\hline\n",
            selected_em_for_ee[6], uselected_em_for_ee[6], estimated_ee[6], uestimated_ee[6],
            selected_em_for_mm[6], uselected_em_for_mm[6], estimated_mm[6], uestimated_mm[6]);
    printf("$45<\\pt<55$ GeV, $1.37<\\eta<2.5 $  & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   \\\\ \\hline\n",
            selected_em_for_ee[7], uselected_em_for_ee[7], estimated_ee[7], uestimated_ee[7],
            selected_em_for_mm[7], uselected_em_for_mm[7], estimated_mm[7], uestimated_mm[7]);
    printf("$   \\pt>55$ GeV, $1.37<\\eta<2.5 $  & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   & $%6.2f \\pm %6.2f$   \\\\ \\hline\n",
            selected_em_for_ee[8], uselected_em_for_ee[8], estimated_ee[8], uestimated_ee[8],
            selected_em_for_mm[8], uselected_em_for_mm[8], estimated_mm[8], uestimated_mm[8]);
    printf("\\end{tabular}]\n");
    printf("%s\n", std::string(80,'*').c_str());


    printf("from selection\n");
    tmp0 = H1EEggF->IntegralAndError(0, -1, tmp1);
    printf("electron: %10.5f +- %10.5f\n", tmp0, tmp1);
    tmp0 = H1MMggF->IntegralAndError(0, -1, tmp1);
    printf("muon    : %10.5f +- %10.5f\n", tmp0, tmp1);
    tmp0 = H1EMggF->IntegralAndError(0, -1, tmp1);
    printf("em/2    : %10.5f +- %10.5f\n", tmp0/2, tmp1/2);
    printf("from estimation\n");
    printf("electron: %10.5f +- %10.5f\n", electron, sqrt(uelectron));
    printf("muon    : %10.5f +- %10.5f\n", muon, sqrt(umuon));
    printf("\n\n");


    TH1D* H1ggFM = H2ggFEbk->ProjectionY();
    TH1D* H1ggFE = H2ggFMbk->ProjectionY();

    f->cd();
    H1ggFE->Write((tag+"_ggF_ee_BDT").c_str());
    H1ggFM->Write((tag+"_ggF_mm_BDT").c_str());

    f->Close();
}



#endif
