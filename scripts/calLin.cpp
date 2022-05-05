#include <iostream>
#include <vector>
#include "TF1.h"
#include "TGraphErrors.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "Fit/FitResult.h"
#include "TPaveText.h"

TLegend * drawLegend(TGraph * leg_plot1, TF1 * leg_func_linear){
    TLegend * legend = new TLegend(0.1, 0.7, 0.4, 0.8);
    legend->SetBorderSize(0.);
    legend->SetTextFont(42);
    legend->AddEntry(leg_plot1, "Data", "E");
    legend->AddEntry(leg_func_linear, "best-fit", "L");
    legend->Draw();
    return legend;
}

TPaveText * drawInfos(TFitResultPtr r){
    TPaveText * infos = new TPaveText(0.1, 0.3, 0.4, 0.4, "NDC nb");
    infos->AddText("Ciao");
    infos->AddText("Come va?");
    infos->Draw();
    return infos; 
}

Double_t linear(Double_t * x, Double_t * p){
    Double_t x_val = x[0];
    return p[0] * x_val + p[1];
}

void calLin(){

    // Sources order: Na_low, Cs_0, Cs_1, Na_high
    Double_t bin_value[4] = {2637, 3394, 3414, 6381};
    Double_t bin_errors[4] = {96, 119, 107, 187};
    Double_t eV_value[4] = {0.511, 0.662, 0.662, 1.275}; // MeV
    Double_t eV_errors[4] = {0, 0, 0, 0};

    TCanvas * c1 = new TCanvas("c1", "c1", 1);
    TF1 * func_linear = new TF1("linear", linear, 0, 8000, 2); 
    TGraphErrors * plot1 = new TGraphErrors(4, eV_value, bin_value, eV_errors, bin_errors);

    func_linear->SetParNames("m", "q");
    plot1->Draw("AP");
    TFitResultPtr r = plot1->Fit("linear");

    TLegend * legend = drawLegend(plot1, func_linear);
    TPaveText * infos = drawInfos(r);
}