#include <iostream>
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

TLegend * drawLegend(TGraph * leg_plot1, TGraph * leg_plot2, TF1 * leg_func_linear){
    TLegend * legend = new TLegend(0.15, 0.7, 0.35, 0.85, "", "NDC nb");
    legend->SetBorderSize(0.);
    legend->SetTextFont(42);
    legend->SetTextSizePixels(22);
    legend->SetFillColorAlpha(0,0.0);
    legend->AddEntry(leg_plot1, "^{22}Na", "EP");
    legend->AddEntry(leg_plot2, "^{137}Cs", "EP");
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

void fancyPlot(TMultiGraph * plt, TGraphErrors * plt1, TGraphErrors * plt2){
    plt->GetXaxis()->SetTitle("E [MeV]"); plt->GetXaxis()->SetTitleSize(0.045);
    plt->GetYaxis()->SetTitle("bin [u.a.]"); plt->GetYaxis()->SetTitleSize(0.045);
    plt->GetYaxis()->SetTitleOffset(1.05);
    plt1->SetMarkerStyle(20);
    plt1->SetMarkerColor(3);
    plt2->SetMarkerStyle(21);
    plt2->SetMarkerColor(4);
}

Double_t linear(Double_t * x, Double_t * p){
    Double_t x_val = x[0];
    return p[0] * x_val + p[1];
}

void calLin(){

    gStyle->SetOptStat(1111); gStyle->SetOptFit(1111);
    gStyle->SetStatBorderSize(0.);
    gStyle->SetStatX(.89); gStyle->SetStatY(.35); gStyle->SetFillColorAlpha(0,0.);

    // Sources
    Double_t binNa_val[2] = {2637, 6381};
    Double_t binNa_err[2] = {96, 187};
    Double_t binCs_val[2] = {3394, 3414};
    Double_t binCs_err[2] = {119, 107};
    Double_t eVNa_val[2] = {0.511, 1.275}; // MeV
    Double_t eVCs_val[2] = {0.662, 0.662}; // MeV
    Double_t eV_err[2] = {0, 0};

    TCanvas * c1 = new TCanvas("c1", "c1", 1);
    TF1 * func_linear = new TF1("linear", linear, 0, 8000, 2); 
    func_linear->SetParNames("m", "q");
    TGraphErrors * plotNa = new TGraphErrors(2, eVNa_val, binNa_val, eV_err, binNa_err);
    TGraphErrors * plotCs = new TGraphErrors(2, eVCs_val, binCs_val, eV_err, binCs_err);
    TMultiGraph * plot = new TMultiGraph();
    plot->Add(plotNa); plot->Add(plotCs);

    // Plot, fit and fancy graph
    plot->Draw("AP");
    TFitResultPtr r = plot->Fit("linear", "CS");
    r->Print();
    TLegend * legend = drawLegend(plotNa, plotCs, func_linear);
    TPaveText * infos = drawInfos();
    fancyPlot(plot, plotNa, plotCs);
}