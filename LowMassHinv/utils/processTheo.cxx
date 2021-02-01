#include <string>
#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <cmath>
#include <map>
#include <algorithm>


int main(int argc, const char *argv[]){
    std::string filename = argv[1];
    std::cout << filename << std::endl;
    TFile *f = new TFile(filename.c_str(), "update");
    std::map<std::pair<std::string, std::string>, TH1F*> hists;
    hists.clear();
    //std::vector<std::string> chans = {"llvv", "eevv", "mmvv", "emvv"};
    //std::vector<std::string> vars = {"BDT", "met_signif", "M2Lep", "mT", "MET", "Z_eta", "dLepR", "dMetZPhi", "frac_pT", "MetOHT", "sumpT_scalar"};
    std::vector<std::string> chans = {"eevv", "mmvv", "emvv"};
    //std::vector<std::string> chans = {"eevv"};
    std::vector<std::string> vars = {"BDT", "mT", "MET"};
    //std::vector<std::string> vars = {"BDT"};
    std::vector<std::string> QCDs = {"QCD55", "QCD15", "QCD51", "QCD12", "QCD21", "QCD22"};
    for (auto chan : chans){
        for (auto var : vars){
            std::string key = chan + "__" + var + "__";

            hists[std::make_pair("PFLOW", key)] = (TH1F*) f->Get((key+"PFLOW").c_str());
            int nbins = hists[std::make_pair("PFLOW", key)]->GetNbinsX();
            float left = hists[std::make_pair("PFLOW", key)]->GetBinLowEdge(1);
            float right = hists[std::make_pair("PFLOW", key)]->GetBinLowEdge(nbins) + hists[std::make_pair("PFLOW", key)]->GetBinWidth(nbins);

            hists[std::make_pair("QCDUP", key)] = (TH1F*) hists[std::make_pair("PFLOW", key)]->Clone();
            hists[std::make_pair("QCDDN", key)] = (TH1F*) hists[std::make_pair("PFLOW", key)]->Clone();
            hists[std::make_pair("PDFUP", key)] = (TH1F*) hists[std::make_pair("PFLOW", key)]->Clone();
            hists[std::make_pair("PDFDN", key)] = (TH1F*) hists[std::make_pair("PFLOW", key)]->Clone();
            hists[std::make_pair("QCDUP", key)]->SetName((key + "QCDUP").c_str());
            hists[std::make_pair("QCDDN", key)]->SetName((key + "QCDDN").c_str());
            hists[std::make_pair("PDFUP", key)]->SetName((key + "PDFUP").c_str());
            hists[std::make_pair("PDFDN", key)]->SetName((key + "PDFDN").c_str());

            std::string QCDUP = "PFLOW";
            std::string QCDDN = "PFLOW";
            double norm_yield = hists[std::make_pair("PFLOW", key)]->Integral(0, -1);
            double QCDUP_integral = norm_yield, QCDDN_integral = norm_yield;
            for(auto index:QCDs){
                hists[std::make_pair(index, key)] = (TH1F*)f->Get((key+index).c_str());
                if (hists[std::make_pair(index, key)]->Integral(0, -1) > std::max(norm_yield, QCDUP_integral)) {
                    QCDUP_integral = hists[std::make_pair(index, key)]->Integral(0, -1);
                    QCDUP = index;
                }
                if (hists[std::make_pair(index, key)]->Integral(0, -1) < std::min(norm_yield, QCDDN_integral)) {
                    QCDDN_integral = hists[std::make_pair(index, key)]->Integral(0, -1);
                    QCDDN = index;
                }
            }
            //std::cout << "QCD "<< QCDUP_integral << " "<<QCDDN_integral<<std::endl;
            for (int nb = 1; nb<=nbins; nb++){
                hists[std::make_pair("QCDUP", key)]->SetBinContent(nb, hists[std::make_pair(QCDUP, key)]->GetBinContent(nb));
                hists[std::make_pair("QCDDN", key)]->SetBinContent(nb, hists[std::make_pair(QCDDN, key)]->GetBinContent(nb));
                hists[std::make_pair("QCDUP", key)]->SetBinError  (nb, hists[std::make_pair(QCDUP, key)]->GetBinError  (nb));
                hists[std::make_pair("QCDDN", key)]->SetBinError  (nb, hists[std::make_pair(QCDDN, key)]->GetBinError  (nb));
            }
            hists[std::make_pair("QCDUP", key)]->Write((key + "QCDUP").c_str());
            hists[std::make_pair("QCDDN", key)]->Write((key + "QCDDN").c_str());

            //for (int i = 1; i<=100; i++){
            //    hists[std::make_pair("PDF" + std::to_string(i), key)] = (TH1F*)f->Get((key+"PDF" + std::to_string(i)).c_str());
            //    std::cout << "PDF"+ std::to_string(i) << "   " << hists[std::make_pair("PDF" + std::to_string(i), key)]->Integral() << std::endl;
            //}
            for (int nb = 1; nb<=nbins; nb++){
                float central = hists[std::make_pair("PFLOW", key)]->GetBinContent(nb);
                double PDF = 0;
                for (int i = 1; i<=100; i++){
                    hists[std::make_pair("PDF" + std::to_string(i), key)] = (TH1F*)f->Get((key+"PDF" + std::to_string(i)).c_str());
                    double contentPDF = hists[std::make_pair("PDF" + std::to_string(i), key)]->GetBinContent(nb);
                    PDF += (central - contentPDF) * (central - contentPDF);
                }
                PDF = sqrt(PDF/100);
                hists[std::make_pair("PDFUP", key)]->SetBinContent(nb, central + PDF);
                hists[std::make_pair("PDFDN", key)]->SetBinContent(nb, central - PDF);
                //printf("%f %f\n", central, PDF);
            }
            hists[std::make_pair("PDFUP", key)]->Write((key + "PDFUP").c_str());
            hists[std::make_pair("PDFDN", key)]->Write((key + "PDFDN").c_str());
            //for (int nb = 1; nb<=nbins; nb++){
            //    printf("%f  %f  %f\n",
            //            hists[std::make_pair("PFLOW", key)]->GetBinContent(nb),
            //            hists[std::make_pair("PDFDN", key)]->GetBinContent(nb),
            //            hists[std::make_pair("PDFUP", key)]->GetBinContent(nb));
            //}
            printf("%f  %f  %f  %f  %f\n",
                    hists[std::make_pair("PFLOW", key)]->Integral(),
                    hists[std::make_pair("PDFDN", key)]->Integral(),
                    hists[std::make_pair("PDFUP", key)]->Integral(),
                    hists[std::make_pair("QCDDN", key)]->Integral(),
                    hists[std::make_pair("QCDUP", key)]->Integral());
        }
    }

    f->Close();
    return 0;
}

