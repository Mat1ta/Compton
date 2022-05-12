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
    return p[0] + p[1] * xx + p[2] * TMath::Gaus(xx, p[3], p[4], false);
}

TLegend * drawLegend(TH1F * leg_h1, TF1 * leg_f1){
    TLegend * legend = new TLegend(0.15, 0.7, 0.35, 0.85, "", "NDC nb");
    legend->SetBorderSize(0.);
    legend->SetTextFont(42);
    legend->SetTextSizePixels(22);
    legend->SetFillColorAlpha(0,0.0);
    legend->AddEntry(leg_h1, "^{137}Cs", "L");
    legend->AddEntry(leg_f1, "best-fit", "L");
    legend->Draw();
    return legend;
}

void calNa(){
    std::string fname = "plot0504calNa_0.dat";
    std::ifstream fin("../dati/" + fname);
    std::string element;

    TCanvas * c1 = new TCanvas("c1", "c1", 1);
    TH1F * h1 = new TH1F("h1", "h1", 100, 3000, 4200);
    TF1 * func = new TF1("gausbg", GausBg, 3000, 4200, 5);
    Double_t pars[] = {40, -0.01, 500, 3600, 100}; // q, m, A_0, mean, sigma
    func->SetParameters(pars);
    func->SetParNames("q", "m", "A_{0}", "#mu", "#sigma");

    while (fin >> element){
        unsigned int value = std::stoul(element, nullptr, 16);
        h1->Fill(value);
    }

    // Plot, fit and fancy graph
    gStyle->SetOptStat("e"); gStyle->SetOptFit(1111);
    gStyle->SetStatBorderSize(0.);
    gStyle->SetStatX(.92); gStyle->SetStatY(.89);
    h1->Draw();
    TFitResultPtr r = h1->Fit("gausbg", "LMS"); r->Print();
    TLegend * legend = drawLegend(h1, func);
}