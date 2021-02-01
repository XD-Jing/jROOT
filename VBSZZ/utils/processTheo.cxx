#include <string>
#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <cmath>
#include <map>
#include <algorithm>


int main(int argc, const char *argv[]){
    std::string filename = argv[1];
    TFile *f = new TFile(filename.c_str(), "update");
    std::map<std::pair<std::string, std::string>, TH1F*> hists;
    hists.clear();
    std::vector<std::string> chans = {"lllv", "eeev", "eemv" ,"mmev", "mmmv"};
    std::vector<std::string> vars = {"MTW", "BDT", "MJJ", "dYJJ", "METS", "M2L", "nJet"};
    std::vector<std::string> QCDs = {"QCD55", "QCD15", "QCD51", "QCD12", "QCD21", "QCD22"};
    for (auto chan : chans){
        for (auto var : vars){
            std::string key = chan + "__" + var + "__";

            hists[std::make_pair("NOMINAL", key)] = (TH1F*) f->Get((key+"NOMINAL").c_str());
            int nbins = hists[std::make_pair("NOMINAL", key)]->GetNbinsX();
            float left = hists[std::make_pair("NOMINAL", key)]->GetBinLowEdge(1);
            float right = hists[std::make_pair("NOMINAL", key)]->GetBinLowEdge(nbins) + hists[std::make_pair("NOMINAL", key)]->GetBinWidth(nbins);

            hists[std::make_pair("QCDUP", key)] = new TH1F((key+"QCDUP").c_str(), (key+"QCDUP").c_str(), nbins, left, right);
            hists[std::make_pair("QCDDN", key)] = new TH1F((key+"QCDDN").c_str(), (key+"QCDDN").c_str(), nbins, left, right);
            hists[std::make_pair("PDFUP", key)] = new TH1F((key+"PDFUP").c_str(), (key+"PDFUP").c_str(), nbins, left, right);
            hists[std::make_pair("PDFDN", key)] = new TH1F((key+"PDFDN").c_str(), (key+"PDFDN").c_str(), nbins, left, right);
            //hists[std::make_pair("QCDUP", key)] = (TH1F*) hists[std::make_pair("NOMINAL", key)]->Clone();
            //hists[std::make_pair("QCDDN", key)] = (TH1F*) hists[std::make_pair("NOMINAL", key)]->Clone();
            //hists[std::make_pair("PDFUP", key)] = (TH1F*) hists[std::make_pair("NOMINAL", key)]->Clone();
            //hists[std::make_pair("PDFDN", key)] = (TH1F*) hists[std::make_pair("NOMINAL", key)]->Clone();
            for (int nb = 1; nb<=nbins; nb++){

                float central = hists[std::make_pair("NOMINAL", key)]->GetBinContent(nb);
                double QCDUP = central, QCDDN = central;
                for (auto index : QCDs){
                    hists[std::make_pair(index, key)] = (TH1F*)f->Get((key+index).c_str());
                    QCDUP = std::max(QCDUP, hists[std::make_pair(index, key)]->GetBinContent(nb));
                    QCDDN = std::min(QCDDN, hists[std::make_pair(index, key)]->GetBinContent(nb));
                }
                hists[std::make_pair("QCDUP", key)]->SetBinContent(nb, QCDUP);
                hists[std::make_pair("QCDDN", key)]->SetBinContent(nb, QCDDN);
            }
            hists[std::make_pair("QCDUP", key)]->Write((key + "QCDUP").c_str());
            hists[std::make_pair("QCDDN", key)]->Write((key + "QCDDN").c_str());

            for (int nb = 1; nb<=nbins; nb++){
                float central = hists[std::make_pair("NOMINAL", key)]->GetBinContent(nb);
                double PDF = 0;
                for (int i = 0; i<=100; i++){
                    hists[std::make_pair("PDF" + std::to_string(i), key)] = (TH1F*)f->Get((key+"PDF" + std::to_string(i)).c_str());
                    double contentPDF = hists[std::make_pair("PDF" + std::to_string(i), key)]->GetBinContent(nb);
                    PDF += (central - contentPDF) * (central - contentPDF);
                }
                PDF = sqrt(PDF/100);
                hists[std::make_pair("PDFUP", key)]->SetBinContent(nb, central + PDF);
                hists[std::make_pair("PDFDN", key)]->SetBinContent(nb, central - PDF);
                printf("%f %f\n", central, PDF);
            }
            hists[std::make_pair("PDFUP", key)]->Write((key + "PDFUP").c_str());
            hists[std::make_pair("PDFDN", key)]->Write((key + "PDFDN").c_str());
            //for (int nb = 1; nb<=nbins; nb++){
            //    printf("%f \n", hists[std::make_pair("PDFDN", key)]->GetBinContent(nb));
            //}
        }
    }

    f->Close();
    return 0;
}

