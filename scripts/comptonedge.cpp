#include <iostream>
#include <string>
#include <fstream>
#include "TStyle.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TF1.h"
#include "TFitResult.h"
#include "TFitResultPtr.h"

void comptonedge(std::string fname){
    gStyle->SetOptStat("e"); gStyle->SetOptFit(1111);
    gStyle->SetStatBorderSize(0.);
    gStyle->SetStatX(.92); gStyle->SetStatY(.89);

    std::ifstream fin("../dati/" + fname);
    std::string element;
    Double_t par[8];

    TCanvas * c1 = new TCanvas("c1", "c1", 1);
    TH1F * h1 = new TH1F("h1", "h1", 100, 4000, 8000);

    while (fin >> element){
        unsigned int value = std::stoul(element, nullptr, 16);
        h1->Fill(value);
    TF1 * fit_g = new TF1("gaus", "gaus", )
}