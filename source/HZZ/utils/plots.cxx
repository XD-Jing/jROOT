#include <map>
#include <vector>
#include <TFile.h>
#include <TTree.h>
#include <TH1D.h>
#include <TChain.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <THStack.h>
#include <TLegend.h>
#include <TColor.h>

int main(){
    TCanvas* c = new TCanvas("c", "c", 800, 800);
    c->Print("dp.pdf[");
    gStyle->SetOptStat(0);
    TFile* fData = new TFile("emuCR-Data.root", "read");
    TFile* fNonRes = new TFile("emuCR-MC.root", "read");
    TFile* fOther = new TFile("emuCR-Other.root", "read");
    TFile* fWZ = new TFile("emuCR-WZ.root", "read");
    TFile* fZJets = new TFile("emuCR-ZJets.root", "read");

    TH1D* hData = (TH1D*)fData->Get("Data_ggF_EM_mTZZ");
    TH1D* hNonRes = (TH1D*)fNonRes->Get("NonRes_ggF_EM_mTZZ");
    TH1D* hWZ = (TH1D*)fWZ->Get("WZ_ggF_EM_mTZZ");
    TH1D* hZJets = (TH1D*)fZJets->Get("ZJets_ggF_EM_mTZZ");
    TH1D* hOther = (TH1D*)fOther->Get("Other_ggF_EM_mTZZ");
    
    hNonRes->SetLineColor(2);
    hNonRes->SetFillColor(2);

    hWZ->SetLineColor(3);
    hWZ->SetFillColor(3);

    hOther->SetLineColor(4);
    hOther->SetFillColor(4);

    hZJets->SetLineColor(5);
    hZJets->SetFillColor(5);

    hData->SetMarkerSize(10);

    THStack *hs = new THStack("hs","");

    hs->Add(hZJets);
    hs->Add(hWZ);
    hs->Add(hOther);
    hs->Add(hNonRes);

    hs->SetMaximum(hs->GetMaximum()*1.5);

    hs->Draw("HIST");
    c->cd();
    hData->Draw("E1 X SAME");
    //hNonRes->Draw("HIST SAME");

    hs->GetXaxis()->SetTitle("m_{T}^{ZZ} [GeV]");
    hs->GetYaxis()->SetTitle("Events");

    TLegend* l = new TLegend(0.65, 0.6, 0.9, 0.9);
    l->SetBorderSize(0);
    l->SetFillStyle(0);
    l->AddEntry(hData, "Data", "lep");
    l->AddEntry(hNonRes, "NonRes.", "f");
    l->AddEntry(hWZ, "WZ", "f");
    l->AddEntry(hZJets, "ZJets", "f");
    l->AddEntry(hOther, "Other", "f");
    l->Draw();

    gStyle->SetLegendFont(42);
    gStyle->SetLegendTextSize(0.03);
    //gPad->SetLeftMargin(0.15);
    c->Print("dp.pdf");

    c->cd();
    c->Print("dp.pdf]");
    return 0;
}
