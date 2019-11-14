#include "HZZ/Accept_Michiel_Tree.h" #include <string>
#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <cmath>


float Yield(TFile *f, std::string hname){
    TH1F *h = (TH1F*)f->Get(hname.c_str());
    return h->Integral(0, -1);
}

void uncertainty(std::string fname, std::string region, std::string channel = ""){
    TFile *f = new TFile(fname.c_str(), "read");
    float NOMINAL = Yield(f, "llvv__" + channel + region + "__mTZZ__PFLOW");

    float PDF = 0,
          QCD = 0;

    for (int i=0; i<=100; i++){
        float pdf = Yield(f, "llvv__" + channel + region + "__mTZZ__" + "PDF" + std::to_string(i));
        //printf("PDF %3i: %10.5f\n", i, pdf/NOMINAL*100);
        PDF += (NOMINAL - pdf) * (NOMINAL - pdf);
    }
    PDF = sqrt(PDF / 100.0);

    std::vector<std::string> W = {"QCD55", "QCD15", "QCD51", "QCD12", "QCD21", "QCD22"};
    for (auto w: W){
        float qcd = Yield(f, "llvv__" + channel + region + "__mTZZ__" + w);
        if (fabs(qcd - NOMINAL) > QCD) QCD = fabs(qcd - NOMINAL);
    }

    printf("%-15s %-10s %-10s\n", fname.c_str(), region.c_str(), channel.c_str());
    //printf("    %10.5f %10.5f(%5.2f%%) %10.5f(%5.2f%%)\n", NOMINAL, PDF, PDF/NOMINAL*100, QCD, QCD/NOMINAL*100);
    printf("    PDF %5.2f%% QCD %5.2f%%\n", PDF/NOMINAL*100, QCD/NOMINAL*100);
    f->Close();

}

void qqZZ(){
    Accept_Michiel_Tree qqZZ("PFLOW", "qqZZ-rel75.root","recreate", true);
    qqZZ.LoopROOT("/store/bl2/atlas/lijing/minitrees_rel75/mc16a/Systematics/weightSyst/mc16_13TeV.345666.Sherpa_222_NNPDF30NNLO_llvvZZ.deriv.DAOD_HIGG2D1.e6240_s3126_r9364_p3872.root");
    qqZZ.LoopROOT("/store/bl2/atlas/lijing/minitrees_rel75/mc16d/Systematics/weightSyst/mc16_13TeV.345666.Sherpa_222_NNPDF30NNLO_llvvZZ.deriv.DAOD_HIGG2D1.e6240_s3126_r10201_p3872.root");
    qqZZ.LoopROOT("/store/bl2/atlas/lijing/minitrees_rel75/mc16e/Systematics/weightSyst/mc16_13TeV.345666.Sherpa_222_NNPDF30NNLO_llvvZZ.deriv.DAOD_HIGG2D1.e6240_s3126_r10724_p3872.root");
    qqZZ.Close();
}

void ggZZ(){
    Accept_Michiel_Tree ggZZ("PFLOW", "ggZZ-rel75.root","recreate", true);
    ggZZ.LoopROOT("/store/bl2/atlas/lijing/minitrees_rel75/mc16a/Systematics/weightSyst/mc16_13TeV.345723.Sherpa_222_NNPDF30NNLO_ggllvvZZ.deriv.DAOD_HIGG2D1.e6213_s3126_r9364_p3872.root");
    ggZZ.LoopROOT("/store/bl2/atlas/lijing/minitrees_rel75/mc16d/Systematics/weightSyst/mc16_13TeV.345723.Sherpa_222_NNPDF30NNLO_ggllvvZZ.deriv.DAOD_HIGG2D1.e6213_s3126_r10201_p3872.root");
    ggZZ.LoopROOT("/store/bl2/atlas/lijing/minitrees_rel75/mc16e/Systematics/weightSyst/mc16_13TeV.345723.Sherpa_222_NNPDF30NNLO_ggllvvZZ.deriv.DAOD_HIGG2D1.e6213_s3126_r10724_p3872.root");
    ggZZ.Close();
}

int main(int argc, const char *argv[]){
    //qqZZ();
    //ggZZ();
    uncertainty("qqZZ-rel75.root", "GGH");
    uncertainty("qqZZ-rel75.root", "VBF");
    uncertainty("ggZZ-rel75.root", "GGH");
    uncertainty("ggZZ-rel75.root", "VBF");

    uncertainty("qqZZ-rel75.root", "GGH", "ee__");
    uncertainty("qqZZ-rel75.root", "VBF", "ee__");
    uncertainty("ggZZ-rel75.root", "GGH", "ee__");
    uncertainty("ggZZ-rel75.root", "VBF", "ee__");
    uncertainty("qqZZ-rel75.root", "GGH", "mm__");
    uncertainty("qqZZ-rel75.root", "VBF", "mm__");
    uncertainty("ggZZ-rel75.root", "GGH", "mm__");
    uncertainty("ggZZ-rel75.root", "VBF", "mm__");

    return 0;
}
