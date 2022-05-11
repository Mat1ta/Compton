//
// Simple plot of log file, run with the following command:
//      root 'hexahist.cpp(fname)'
// For example: root 'hexahist.cpp("plot0427.dat")'
//

#include <iostream>
#include <fstream>
#include <string>
#include "TH1F.h"
#include "TF1.h"
#include "TGraphErrors.h"
#include "TMultiGraph.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TFitResult.h"
#include "TFitResultPtr.h"
#include "TPaveText.h"
#include "TAxis.h"
#include "TStyle.h"

void fancyPlot(TH1F * hist){
    hist->GetXaxis()->SetTitle("bin [u.a.]");
    hist->GetXaxis()->SetTitleSize(0.045);
    hist->GetYaxis()->SetTitle("occurences [u.a.]");
    hist->GetYaxis()->SetTitleSize(0.045);
    hist->GetYaxis()->SetTitleOffset(1.05);
}

TLegend * drawLegend();
/*
TPaveText * drawInfos(){
    TPaveText * infos = new TPaveText(.35, .69, .5, .84, "NDC nb");
    infos->SetTextFont(42);
    infos->SetTextSizePixels(22);
    infos->SetFillColorAlpha(0,0.0);
    infos->SetTextAlign(11);
    infos->AddText("D = 1 cm");
    infos->AddText("T = 300 ns");
    infos->AddText("Plot 06/05/22");
    infos->Draw();
    return infos;
}
*/

void hexahist(std::string fname){
    std::ifstream fin("../dati/" + fname);
    std::string element;

    TCanvas * c1 = new TCanvas("c1", "c1", 1);
    TH1F * h1 = new TH1F("h1", "h1", 70, 0, 8000);

    while (fin >> element){
        unsigned int value = std::stoul(element, nullptr, 16);
        h1->Fill(value);
    }

    // Plot and fancy histogram
    gStyle->SetOptStat(1110);
    gStyle->SetOptFit(1111);
    gStyle->SetStatBorderSize(0.);
    gStyle->SetStatX(.35);
    gStyle->SetStatY(.89);
    h1->Draw();
//    TPaveText * infos = drawInfos();
    fancyPlot(h1);
}
