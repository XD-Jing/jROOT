#include "HZZ/Acceptance.h" #include <string>
#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <cmath>

std::string path = "/lustre/umt3/user/liji/HZZ-samples/ZZ-2019-09-11/";

float Yield(TFile *f, std::string hname){
    TH1F *h = (TH1F*)f->Get(hname.c_str());
    return h->Integral(0, -1);
}

void uncertainty(std::string fname, std::string region){
    TFile *f = new TFile(fname.c_str(), "read");
    float NOMINAL = Yield(f, "llvv__" + region + "__YLD__NOMINAL");

    float PDF = 0,
          QCD = 0;

    for (int i=0; i<100; i++){
        float pdf = Yield(f, "llvv__" + region + "__YLD__" + "PDF" + std::to_string(i));
        printf("PDF %3i: %10.5f\n", i, pdf/NOMINAL*100);
        PDF += (NOMINAL - pdf) * (NOMINAL - pdf);
    }
    PDF = sqrt(PDF / 100.0);

    std::vector<std::string> W = {"QCD55", "QCD15", "QCD51", "QCD12", "QCD21", "QCD22"};
    for (auto w: W){
        float qcd = Yield(f, "llvv__" + region + "__YLD__" + w);
        if (fabs(qcd - NOMINAL) > QCD) QCD = fabs(qcd - NOMINAL);
    }

    printf("%-15s %-10s\n", fname.c_str(), region.c_str());
    printf("    %10.5f %10.5f(%5.2f%%) %10.5f(%5.2f%%)\n", NOMINAL, PDF, PDF/NOMINAL*100, QCD, QCD/NOMINAL*100);
    f->Close();

}

void qqZZ(){
    Acceptance qqZZ("NOMINAL", "qqZZ-reco.root","recreate", true, false);
    qqZZ.LoopROOT(path + "mc16_13TeV.345666.Sherpa_222_NNPDF30NNLO_llvvZZ.deriv.DAOD_HIGG2D1.e6240_s3126_r9364_p3652.root" , 0.49785);
    qqZZ.LoopROOT(path + "mc16_13TeV.345666.Sherpa_222_NNPDF30NNLO_llvvZZ.deriv.DAOD_HIGG2D1.e6240_s3126_r10201_p3652.root", 0.49785);
    qqZZ.LoopROOT(path + "mc16_13TeV.345666.Sherpa_222_NNPDF30NNLO_llvvZZ.deriv.DAOD_HIGG2D1.e6240_s3126_r10724_p3652.root", 0.49785);
    qqZZ.Close();
}

void ggZZ(){
    Acceptance ggZZ("NOMINAL", "ggZZ-reco.root","recreate", true, false);
    ggZZ.LoopROOT(path + "mc16_13TeV.345723.Sherpa_222_NNPDF30NNLO_ggllvvZZ.deriv.DAOD_HIGG2D1.e6213_s3126_r9364_p3652.root" , 0.0071055);
    ggZZ.LoopROOT(path + "mc16_13TeV.345723.Sherpa_222_NNPDF30NNLO_ggllvvZZ.deriv.DAOD_HIGG2D1.e6213_s3126_r10201_p3652.root", 0.0071055);
    ggZZ.LoopROOT(path + "mc16_13TeV.345723.Sherpa_222_NNPDF30NNLO_ggllvvZZ.deriv.DAOD_HIGG2D1.e6213_s3126_r10724_p3652.root", 0.0071055);
    ggZZ.Close();
}


int main(int argc, const char *argv[]){
    qqZZ();
    ggZZ();
    //uncertainty("qqZZ.root", "_GGH");
    //uncertainty("qqZZ.root", "2JET");
    //uncertainty("qqZZ.root", "_VBF");

    return 0;
}
