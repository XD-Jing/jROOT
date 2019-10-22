#include "HZZ/Acceptance_jun.h" #include <string>
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
    //printf("S = %f, B = %f\n", s, b);
    return sqrt(s*(1-s/b)) / b;
}

void uncertainty(std::string fname, std::string region){
    TFile *f = new TFile(fname.c_str(), "read");
    float NOMINAL = Accept(f, region, "NOMINAL");
    float STAT = Stat(f, region, "NOMINAL");

    float PDF = 0,
          QCD = 0,
          PS = 0;

    for (int i=0; i<26; i++){
        float pdfup = Accept(f, region, "PDF" + std::to_string(i * 2));
        float pdfdn = Accept(f, region, "PDF" + std::to_string(i * 2 + 1));
        PDF += std::max((NOMINAL - pdfup) * (NOMINAL - pdfup), (NOMINAL - pdfdn) * (NOMINAL - pdfdn));
    }
    PDF = sqrt(PDF);

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
    //PS = sqrt(PS);

    printf("%-15s %-10s\n", fname.c_str(), region.c_str());
    printf("    %12s %9s %9s %9s %9s\n", "Accept",  "STAT", "PDF", "QCD", "PS");
    printf("    %12.8f %8.3f%% %8.3f%% %8.3f%% %8.3f%%\n", NOMINAL, STAT/NOMINAL*100, PDF/NOMINAL*100, QCD/NOMINAL*100, PS/NOMINAL*100);
    printf("\n");
    f->Close();

}

void process(std::string tree, std::string output, std::string file, bool THEO = false){
    std::string path = "/atlas/data19/liji/xAOD/run/PS/";
    if (THEO){
        Acceptance_jun run(tree, output,"recreate", true);
        run.LoopROOT(path + file);
        run.Close();
    }
    else{
        Acceptance_jun run(tree, output,"update", false);
        run.LoopROOT(path + file);
        run.Close();
    }
}


int main(int argc, const char *argv[]){
    std::vector<std::string> l = {
        "300", "400", "500", "600", "700", "800", "900", "1000",
        "1200", "1400", "1600", "1800", "2000", "2400", "3000"
    };
    for (auto i : l){
        //process("NOMINAL", "VBF"+i+".root", "VBF"+i+".root", true);
        uncertainty("VBF"+i+".root", "_VBF");

    }



    return 0;
}
