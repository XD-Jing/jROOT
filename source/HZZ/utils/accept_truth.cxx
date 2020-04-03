#include "HZZ/Acceptance_truth.h" #include <string>
#include <iostream>
#include <TFile.h>
#include <TH1F.h>
#include <cmath>


float Accept(TFile *f, std::string region, std::string weight){
    TH1F *h = (TH1F*)f->Get(("llvv__" + region + "__" + weight).c_str());
    TH1F *t = (TH1F*)f->Get(("llvv__DAOD__" + weight).c_str());
    return h->Integral(0, -1) / t->Integral(0, -1);
}

float Stat(TFile *f, std::string region, std::string weight){
    TH1F *h = (TH1F*)f->Get(("llvv__" + region + "__" + weight).c_str());
    TH1F *t = (TH1F*)f->Get(("llvv__DAOD__" + weight).c_str());
    float s = h->GetEntries();
    float b = t->GetEntries();
    printf("S = %f, B = %f\n", s, b);
    return sqrt(s*(1-s/b)) / b;
}

void uncertainty(std::string fname, std::string region){
    TFile *f = new TFile(fname.c_str(), "read");
    float NOMINAL = Accept(f, region, "NOMINAL");
    float STAT = Stat(f, region, "NOMINAL");

    float PDF = 0,
          QCD = 0,
          PS = 0;

    for (int i=0; i<100; i++){
        float pdf = Accept(f, region, "PDF" + std::to_string(i));
        //printf("PDF %3i: %10.5f\n", i, pdf/NOMINAL*100);
        PDF += (NOMINAL - pdf) * (NOMINAL - pdf);
    }
    PDF = sqrt(PDF / 100.0);

    std::vector<std::string> wQCD = {"QCD55", "QCD15", "QCD51", "QCD12", "QCD21", "QCD22"};
    for (auto w: wQCD){
        float qcd = Accept(f, region, w);
        if (fabs(qcd - NOMINAL) > QCD) QCD = fabs(qcd - NOMINAL);
    }

    //std::vector<std::string> wPS = {"CKKW15", "CKKW30", "QSF025", "QSF4", "CSSKIN"};
    //for (auto w: wPS){
    //    float ps = Accept(f, region, w);
    //    PS += (ps - NOMINAL) * (ps - NOMINAL);
    //}
    float CKKW15 = Accept(f, region, "CKKW15");
    float CKKW30 = Accept(f, region, "CKKW30");
    float QSF025 = Accept(f, region, "QSF025");
    float QSF4   = Accept(f, region, "QSF4"  );
    float CSSKIN = Accept(f, region, "CSSKIN");
    PS += std::max(
            (CKKW15 - NOMINAL) * (CKKW15 - NOMINAL),
            (CKKW30 - NOMINAL) * (CKKW30 - NOMINAL)
            );
    PS += std::max(
            (QSF025 - NOMINAL) * (QSF025 - NOMINAL),
            (QSF4   - NOMINAL) * (QSF4   - NOMINAL)
            );
    PS += (CSSKIN - NOMINAL) * (CSSKIN - NOMINAL);

    PS = sqrt(PS);

    printf("%-15s %-10s\n", fname.c_str(), region.c_str());
    printf("    %12s %9s %9s %9s %9s\n", "Accept",  "STAT", "PDF", "QCD", "PS");
    printf("    %12.8f %8.3f%% %8.3f%% %8.3f%% %8.3f%%\n", NOMINAL, STAT/NOMINAL*100, PDF/NOMINAL*100, QCD/NOMINAL*100, PS/NOMINAL*100);
    printf("\n");
    f->Close();

}

void process(std::string tree, std::string output, std::string file, bool THEO = false){
    std::string path = "/atlas/data19/liji/xAOD/run/PS/";
    if (THEO){
        //Acceptance_truth run(tree, output,"recreate", true);
        Acceptance_truth run(tree, output,"recreate", false);
        run.LoopROOT(path + file);
        run.Close();
    }
    else{
        Acceptance_truth run(tree, output,"update", false);
        run.LoopROOT(path + file);
        run.Close();
    }
}


int main(int argc, const char *argv[]){
    process("NOMINAL", "qqZZ-truth.root", "mc15_13TeV.345666.Sherpa_222_NNPDF30NNLO_llvvZZ.deriv.DAOD_TRUTH1.e6240_e5984_p3655.root", true);
    process("CKKW15",  "qqZZ-truth.root", "mc15_13TeV.345858.Sherpa_222_NNPDF30NNLO_llvvZZ_CKKW15.deriv.DAOD_TRUTH1.e6469_p3655.root");
    process("CKKW30",  "qqZZ-truth.root", "mc15_13TeV.345859.Sherpa_222_NNPDF30NNLO_llvvZZ_CKKW30.deriv.DAOD_TRUTH1.e6469_p3655.root");
    process("QSF025",  "qqZZ-truth.root", "mc15_13TeV.345860.Sherpa_222_NNPDF30NNLO_llvvZZ_QSF025.deriv.DAOD_TRUTH1.e6469_p3655.root");
    process("QSF4",    "qqZZ-truth.root", "mc15_13TeV.345861.Sherpa_222_NNPDF30NNLO_llvvZZ_QSF4.deriv.DAOD_TRUTH1.e6469_p3655.root");
    process("CSSKIN",  "qqZZ-truth.root", "mc15_13TeV.345862.Sherpa_222_NNPDF30NNLO_llvvZZ_CSSKIN.deriv.DAOD_TRUTH1.e6469_p3655.root");

    process("NOMINAL", "ggZZ-truth.root", "mc15_13TeV.345723.Sherpa_222_NNPDF30NNLO_ggllvvZZ.deriv.DAOD_TRUTH1.e6213_e5984_p3655.root", true);
    process("CKKW15",  "ggZZ-truth.root", "mc15_13TeV.345848.Sherpa_222_NNPDF30NNLO_ggllvvZZ_CKKW15.deriv.DAOD_TRUTH1.e6469_p3655.root");
    process("CKKW30",  "ggZZ-truth.root", "mc15_13TeV.345849.Sherpa_222_NNPDF30NNLO_ggllvvZZ_CKKW30.deriv.DAOD_TRUTH1.e6469_p3655.root");
    process("QSF025",  "ggZZ-truth.root", "mc15_13TeV.345850.Sherpa_222_NNPDF30NNLO_ggllvvZZ_QSF025.deriv.DAOD_TRUTH1.e6469_p3655.root");
    process("QSF4",    "ggZZ-truth.root", "mc15_13TeV.345851.Sherpa_222_NNPDF30NNLO_ggllvvZZ_QSF4.deriv.DAOD_TRUTH1.e6469_p3655.root");
    process("CSSKIN",  "ggZZ-truth.root", "mc15_13TeV.345852.Sherpa_222_NNPDF30NNLO_ggllvvZZ_CSSKIN.deriv.DAOD_TRUTH1.e6469_p3655.root");

    //uncertainty("qqZZ.root", "_GGH");
    //uncertainty("qqZZ.root", "2JET");
    //uncertainty("qqZZ.root", "_VBF");

    //uncertainty("ggZZ.root", "_GGH");
    //uncertainty("ggZZ.root", "2JET");
    //uncertainty("ggZZ.root", "_VBF");

    return 0;
}
