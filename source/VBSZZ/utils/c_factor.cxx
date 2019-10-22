#include <string>
#include <TString.h>
#include "TH1F.h"
#include "TFile.h"


TFile *f = 0;

float ySR(std::string treename){
    if (f->GetListOfKeys()->Contains(("llvv__2lSR__"+treename).c_str())){
        TH1F *h = (TH1F*) f->Get(("llvv__2lSR__"+treename).c_str());
        return h->Integral(0, -1);
    }
    return -1;
}


float yFV(std::string treename){
    if (f->GetListOfKeys()->Contains(("llvv__2lFV__"+treename).c_str())){
        TH1F *h = (TH1F*) f->Get(("llvv__2lFV__"+treename).c_str());
        return h->Integral(0, -1);
    }
    return -1;
}


int c_factor(std::string fname){

    printf("%s\n", fname.c_str());
    f = new TFile(fname.c_str(), "r");
    
    TH1F *fFV = (TH1F*)f->Get("llvv__2lFV__NOMINAL");
    TH1F *fSR = (TH1F*)f->Get("llvv__2lSR__NOMINAL");

    float nFV = fFV->GetBinContent(1);
    float sFV = fFV->GetBinError(1);
    float nSR = fSR->GetBinContent(1);
    float sSR = fSR->GetBinError(1);
    float nCF = nSR / nFV;
    float sCF = sqrt(fSR->GetEntries() * (1.0 - fSR->GetEntries() / fFV->GetEntries())) / fFV->GetEntries();

    float QCDFV = 0,
          PDFFV = 0,
          QCDSR = 0,
          PDFSR = 0,
          QCDCF= 0,
          PDFCF= 0;
    // QCD
    std::vector<std::string> wQCD = { "QCD12", "QCD15", "QCD21", "QCD22", "QCD51", "QCD55" };
    for (auto w : wQCD){
        float wSR = ySR(w);
        float wFV = yFV(w);
        if (wSR==-1.0) continue;
        if (wFV==-1.0) continue;
        float wCF= wSR / wFV;

        if (fabs(wSR - nSR)>QCDSR) QCDSR = fabs(wSR - nSR);
        if (fabs(wFV - nFV)>QCDFV) QCDFV = fabs(wFV - nFV);
        if (fabs(wCF - nCF)>QCDCF) QCDCF = fabs(wCF - nCF);
    }

    // PDF
    for (int i =0; i<100; i++){
        float wSR = ySR("PDF"+std::to_string(i));
        float wFV = yFV("PDF"+std::to_string(i));
        if (wSR==-1.0) continue;
        if (wFV==-1.0) continue;
        float wCF= wSR / wFV;
        PDFSR += (wSR - nSR) * (wSR - nSR);
        PDFFV += (wFV - nFV) * (wFV - nFV);
        PDFCF += (wCF - nCF) * (wCF - nCF);
    }
    PDFSR = sqrt(PDFSR);
    PDFFV = sqrt(PDFFV);
    PDFCF = sqrt(PDFCF);

    // SYST

    float CPSR = 0,
          CPCF = 0;
    std::vector<std::string> wCPup;
    std::vector<std::string> wCPdown;
    std::vector<std::string> wCP;
    wCPdown.push_back("EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR__1down");        wCPup.push_back("EL_EFF_ID_TOTAL_1NPCOR_PLUS_UNCOR__1up");
    wCPdown.push_back("EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR__1down");       wCPup.push_back("EL_EFF_Iso_TOTAL_1NPCOR_PLUS_UNCOR__1up");
    wCPdown.push_back("EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR__1down");      wCPup.push_back("EL_EFF_Reco_TOTAL_1NPCOR_PLUS_UNCOR__1up");
    wCPdown.push_back("EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down");   wCPup.push_back("EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up");
    wCPdown.push_back("FT_EFF_B_systematics__1down");                     wCPup.push_back("FT_EFF_B_systematics__1up");
    wCPdown.push_back("FT_EFF_C_systematics__1down");                     wCPup.push_back("FT_EFF_C_systematics__1up");
    wCPdown.push_back("FT_EFF_Light_systematics__1down");                 wCPup.push_back("FT_EFF_Light_systematics__1up");
    wCPdown.push_back("FT_EFF_extrapolation__1down");                     wCPup.push_back("FT_EFF_extrapolation__1up");
    wCPdown.push_back("FT_EFF_extrapolation_from_charm__1down");          wCPup.push_back("FT_EFF_extrapolation_from_charm__1up");
    wCPdown.push_back("JET_JvtEfficiency__1down");                        wCPup.push_back("JET_JvtEfficiency__1up");
    //wCPdown.push_back("JET_fJvtEfficiency__1down");                       wCPup.push_back("JET_fJvtEfficiency__1up");
    wCPdown.push_back("MUON_EFF_ISO_STAT__1down");                        wCPup.push_back("MUON_EFF_ISO_STAT__1up");
    wCPdown.push_back("MUON_EFF_ISO_SYS__1down");                         wCPup.push_back("MUON_EFF_ISO_SYS__1up");
    wCPdown.push_back("MUON_EFF_RECO_STAT_LOWPT__1down");                 wCPup.push_back("MUON_EFF_RECO_STAT_LOWPT__1up");
    wCPdown.push_back("MUON_EFF_RECO_STAT__1down");                       wCPup.push_back("MUON_EFF_RECO_STAT__1up");
    wCPdown.push_back("MUON_EFF_RECO_SYS_LOWPT__1down");                  wCPup.push_back("MUON_EFF_RECO_SYS_LOWPT__1up");
    wCPdown.push_back("MUON_EFF_RECO_SYS__1down");                        wCPup.push_back("MUON_EFF_RECO_SYS__1up");
    wCPdown.push_back("MUON_EFF_TTVA_STAT__1down");                       wCPup.push_back("MUON_EFF_TTVA_STAT__1up");
    wCPdown.push_back("MUON_EFF_TTVA_SYS__1down");                        wCPup.push_back("MUON_EFF_TTVA_SYS__1up");
    wCPdown.push_back("MUON_EFF_TrigStatUncertainty__1down");             wCPup.push_back("MUON_EFF_TrigStatUncertainty__1up");
    wCPdown.push_back("MUON_EFF_TrigSystUncertainty__1down");             wCPup.push_back("MUON_EFF_TrigSystUncertainty__1up");
    wCPdown.push_back("EG_RESOLUTION_ALL__1down");                        wCPup.push_back("EG_RESOLUTION_ALL__1up");
    wCPdown.push_back("EG_SCALE_AF2__1down");                             wCPup.push_back("EG_SCALE_AF2__1up");
    wCPdown.push_back("EG_SCALE_ALL__1down");                             wCPup.push_back("EG_SCALE_ALL__1up");
    wCPdown.push_back("JET_EtaIntercalibration_NonClosure__1down");       wCPup.push_back("JET_EtaIntercalibration_NonClosure__1up");
    wCPdown.push_back("JET_GroupedNP_1__1down");                          wCPup.push_back("JET_GroupedNP_1__1up");
    wCPdown.push_back("JET_GroupedNP_2__1down");                          wCPup.push_back("JET_GroupedNP_2__1up");
    wCPdown.push_back("JET_GroupedNP_3__1down");                          wCPup.push_back("JET_GroupedNP_3__1up");
    wCPdown.push_back("MET_SoftTrk_ScaleDown");                           wCPup.push_back("MET_SoftTrk_ScaleUp");
    wCPdown.push_back("MUON_ID__1down");                                  wCPup.push_back("MUON_ID__1up");
    wCPdown.push_back("MUON_MS__1down");                                  wCPup.push_back("MUON_MS__1up");
    wCPdown.push_back("MUON_SAGITTA_RESBIAS__1down");                     wCPup.push_back("MUON_SAGITTA_RESBIAS__1up");
    wCPdown.push_back("MUON_SAGITTA_RHO__1down");                         wCPup.push_back("MUON_SAGITTA_RHO__1up");
    wCPdown.push_back("MUON_SCALE__1down");                               wCPup.push_back("MUON_SCALE__1up");
    wCPdown.push_back("PRW_DATASF__1down");                               wCPup.push_back("PRW_DATASF__1up");

    wCP.push_back("JET_JER_SINGLE_NP__1up");
    wCP.push_back("MET_SoftTrk_ResoPara");
    wCP.push_back("MET_SoftTrk_ResoPerp");

    for (int i=0; i<wCPup.size(); i++){
        float wSRu = ySR(wCPup[i]);
        float wSRd = ySR(wCPdown[i]);
        if (wSRu==-1.0) continue;
        if (wSRd==-1.0) continue;
        //printf("%-60s  %7.5f\n", wCPup[i].c_str(), wSRu);
        //printf("%-60s  %7.5f\n", wCPdown[i].c_str(), wSRd);
        if (fabs(wSRu-nSR) > fabs(wSRd-nSR)) CPSR += (wSRu - nSR) * (wSRu - nSR);
        else CPSR += (wSRd - nSR) * (wSRd - nSR);
    }
    for (int i=0; i<wCP.size(); i++){
        float wSR = ySR(wCP[i]);
        if (wSR==-1.0) continue;
        CPSR += (wSR - nSR) * (wSR - nSR);
    }
    CPSR = sqrt(CPSR);
    CPCF = CPSR / nFV;


    printf("     %7s    %7s    %7s    %7s    %7s\n", "NORM",  "STAT", "QCD", "PDF", "EXP");
    printf("FV   %7.5f    %7.5f    %7.5f    %7.5f\n", nFV, sFV, QCDFV, PDFFV);
    printf("SR   %7.5f    %7.5f    %7.5f    %7.5f    %7.5f\n", nSR, sSR, QCDSR, PDFSR, CPSR);
    printf("CF   %7.5f    %7.5f    %7.5f    %7.5f    %7.5f\n", nCF, sCF, QCDCF, PDFCF, CPCF);
    printf("\n");

    f->Close();
    return 0;
}


int main(int argc, const char *argv[]){
    c_factor("/atlas/data19/liji/jROOT/source/VBSZZ/share/cEWK.363724.root");
    c_factor("/atlas/data19/liji/jROOT/source/VBSZZ/share/cqqZZ.364254.root");
    c_factor("/atlas/data19/liji/jROOT/source/VBSZZ/share/cggZZ.343233.root");
    return 0;
}
