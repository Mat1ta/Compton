#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
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

TLegend * drawLegend(TGraph * leg_plot1, TGraph * leg_plot2, TGraph * leg_plot3,TF1 * leg_func_linear){
    TLegend * legend = new TLegend(0.15, 0.7, 0.35, 0.87, "", "NDC nb");
    legend->SetBorderSize(0.);
    legend->SetTextFont(42);
    legend->SetTextSizePixels(22);
    legend->SetFillColorAlpha(0,0.0);
    legend->AddEntry(leg_plot1, "^{22}Na", "EP");
    legend->AddEntry(leg_plot2, "^{137}Cs", "EP");
    legend->AddEntry(leg_plot3, "^{60}Co", "EP");
    legend->AddEntry(leg_func_linear, "best-fit", "L");
    legend->Draw();
    return legend;
}

TPaveText * drawInfos(){
    TPaveText * infos = new TPaveText(0.55, 0.8, 0.35, 0.85, "NDC nb");
    infos->SetTextFont(42);
    infos->SetTextSizePixels(22);
    infos->SetFillColorAlpha(0,0.0);
    infos->AddText("Plot 06/05/22");
    infos->Draw();
    return infos; 
}

void fancyPlot(TMultiGraph * plt, TGraphErrors * plt1, TGraphErrors * plt2, TGraphErrors * plt3){
    plt->GetXaxis()->SetTitle("E [MeV]"); plt->GetXaxis()->SetTitleSize(0.045);
    plt->GetYaxis()->SetTitle("bin [u.a.]"); plt->GetYaxis()->SetTitleSize(0.045);
    plt->GetYaxis()->SetTitleOffset(1.05);
    plt1->SetMarkerStyle(20);
    plt1->SetMarkerColor(3);
    plt2->SetMarkerStyle(21);
    plt2->SetMarkerColor(4);
    plt3->SetMarkerStyle(22);
    plt3->SetMarkerColor(6);
}

Double_t ffunc(Double_t * x, Double_t * p){
    Double_t x_val = x[0];
    return p[0] * pow(x_val, 2) + p[1] * x_val + p[2];
}

void getSources(Double_t * vNa, Double_t * vCs, Double_t * vCo, Double_t * eNa, Double_t * eCs, Double_t * eCo){
    std::string name = "calStart.txt";
    std::ifstream fin("../dati/" + name);
    std::string line, lline;
    int i = 0;
    Double_t v[3][11];
    while(std::getline(fin, line)){
        lline = line[0];
        if (lline != "#"){
            Double_t value;
            int k = 0;
            std::stringstream ss(line);
            while (ss >> value)
            {
                v[i][k] = value;
                ++k;
            }
            ++i;
        }
    }
    i = 0;
    Double_t date = 220510; // Select which calibration you want, format = yymmdd
    while (v[i][0] != date){
        i++;
    }
    vNa[0] = v[i][1]; vNa[1] = v[i][2];
    vCs[0] = v[i][3];
    vCo[0] = v[i][4]; vCo[1] = v[i][5];
    eNa[0] = v[i][6]; eNa[1] = v[i][7];
    eCs[0] = v[i][8];
    eCo[0] = v[i][9]; eCo[1] = v[i][10];
    return;
}

void calLin(){
    gStyle->SetOptStat(1111); gStyle->SetOptFit(1111);
    gStyle->SetStatBorderSize(0.);
    gStyle->SetStatX(.89); gStyle->SetStatY(.35); gStyle->SetFillColorAlpha(0,0.);

    // Sources
    Double_t binNa_val[2], binNa_err[2];
    Double_t binCs_val[1], binCs_err[1];
    Double_t binCo_val[2], binCo_err[2];
    Double_t eVNa_val[2] = {0.511, 1.275}; // MeV
    Double_t eVCs_val[1] = {0.662}; // MeV
    Double_t eVCo_val[2] = {1.17, 1.33}; // MeV
    Double_t eV_err[2] = {0, 0};
    getSources(binNa_val, binCs_val, binCo_val, binNa_err, binCs_err, binCo_err);


    TCanvas * c1 = new TCanvas("c1", "c1", 1);
    TF1 * func = new TF1("func", ffunc, 0, 8000, 3); 
    func->SetParNames("a", "b", "c");
    TGraphErrors * plotNa = new TGraphErrors(2, eVNa_val, binNa_val, eV_err, binNa_err);
    TGraphErrors * plotCs = new TGraphErrors(1, eVCs_val, binCs_val, eV_err, binCs_err);
    TGraphErrors * plotCo = new TGraphErrors(2, eVCo_val, binCo_val, eV_err, binCo_err);
    TMultiGraph * plot = new TMultiGraph();
    plot->Add(plotNa); plot->Add(plotCs); plot->Add(plotCo);

    // Plot, fit and fancy graph
    plot->Draw("AP");
    TFitResultPtr r = plot->Fit("func", "CS");
    r->Print();
    TLegend * legend = drawLegend(plotNa, plotCs, plotCo,func);
    TPaveText * infos = drawInfos();
    fancyPlot(plot, plotNa, plotCs, plotCo);
}