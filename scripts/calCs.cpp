#include <iostream>
#include <fstream>
#include <string>
#include "TH1F.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TMath.h"
#include "TFitResult.h"
#include "TFitResultPtr.h"
#include "TLegend.h"
#include "TStyle.h"

Double_t GausBg(Double_t * x, Double_t * p){
    Double_t xx = x[0];
    return p[0]*TMath::Exp(-xx / p[1]) + p[4]*TMath::Gaus(xx, p[2], p[3], false) + p[5];
}

TLegend * drawLegend(TH1F * leg_h1, TF1 * leg_f1){
    TLegend * legend = new TLegend(0.15, 0.7, 0.35, 0.85, "", "NDC nb");
    legend->SetBorderSize(0.);
    legend->SetTextFont(42);
    legend->SetTextSizePixels(22);
    legend->SetFillColorAlpha(0,0.0);
    legend->AddEntry(leg_h1, "^{22}Na", "EP");
    legend->AddEntry(leg_f1, "^{137}Cs", "L");
    legend->Draw();
    return legend;
}

void calCs(){
    std::string fname = "plot0510calCs.dat";
    std::ifstream fin("../dati/" + fname);
    std::vector<int> data;
    std::string element;

    TCanvas * c1 = new TCanvas("c1", "c1", 1);
    TH1F * h1 = new TH1F("h1", "h1", 100, 2500, 4500);
    TF1 * func = new TF1("gausbg", GausBg, 2500, 4500, 6);
    Double_t pars[] = {50, 333, 3600, 100, 1500, 0};
    func->SetParameters(pars);

    while (fin >> element){
        unsigned int value = std::stoul(element, nullptr, 16);
        h1->Fill(value);
    }

    // Plot, fit and fancy graph
    gStyle->SetOptStat(0110); gStyle->SetOptFit(1111);
    h1->Draw();
    TFitResultPtr r = h1->Fit("gausbg", "LMS");
    TLegend * legend = drawLegend(h1, func);
}