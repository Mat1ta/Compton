#include <iostream>
#include <fstream>
#include <string>
#include "TH1F.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TFitResult.h"
#include "TFitResultPtr.h"
#include "TMath.h"
#include "TStyle.h"
#include "TLegend.h"
#include "TPaveText.h"

TPaveText * drawInfos(){
    TPaveText * infos = new TPaveText(.35, .69, .5, .84, "NDC nb");
    infos->SetTextFont(42);
    infos->SetTextSizePixels(22);
    infos->SetFillColorAlpha(0,0.0);
    infos->SetTextAlign(11);
    infos->AddText("12th of may");
    infos->AddText("#theta = 22#circ");
    infos->AddText("Lenght =  26677 s");
    infos->Draw();
    return infos;
}

void fancyPlot(TH1F * plt){
    plt->GetXaxis()->SetTitle("E [a.u.]"); plt->GetXaxis()->SetTitleSize(0.045);
    plt->GetYaxis()->SetTitle("occurrencies"); plt->GetYaxis()->SetTitleSize(0.045);
    plt->GetYaxis()->SetTitleOffset(1.05);
}

TLegend * drawLegend(TH1F * leg_h1, TF1 * leg_f0, TF1 * leg_f1, TF1 * leg_f2, TF1 * leg_f3){
    TLegend * legend = new TLegend(0.15, 0.7, 0.35, 0.85, "", "NDC nb");
    legend->SetBorderSize(0.);
    legend->SetTextFont(42);
    legend->SetTextSizePixels(22);
    legend->SetFillColorAlpha(0,0.0);
    legend->AddEntry(leg_h1, "^{60}Co", "E");
    legend->AddEntry(leg_f0, "best-fit", "L");
    legend->AddEntry(leg_f1, "Compton edge", "L");
    legend->AddEntry(leg_f2, "1^{st} peak", "L");
    legend->AddEntry(leg_f3, "2^{nd} peak", "L");
    legend->Draw();
    return legend;
}

Double_t background(Double_t * x, Double_t *p){
    return p[0] + p[1] * x[0] + p[2] * pow(x[0], 2);
}

// arXiv:1610.09185 [physics.ins-det]
// Safari, Davani, Afarideh
Double_t SDAfunc(Double_t * x, Double_t * p){
    Double_t E = x[0], a = p[0], b = p[1], c = p[2], mu = p[3], s = p[4];
    Double_t alpha = (a * (pow(E,2) + pow(s,2)) + b * E + c) / 2;
    Double_t beta = - s * (a * (E + mu)) / (sqrt(2 * TMath::Pi())) + c;
    Double_t exp = (E - mu) / (sqrt(2) * s);

    return (alpha * TMath::Erfc(exp) + beta * TMath::Exp(-pow(exp,2))) + p[5] * E + p[6];
}

Double_t gaus(Double_t * x, Double_t * p){
    return p[0] * TMath::Gaus(x[0], p[1], p[2]);
}

Double_t ufunc(Double_t * x, Double_t * p){
    Double_t g1[] = {p[0], p[1], p[2]};
    Double_t g2[] = {p[3], p[4], p[5]};
    //return p[0] + p[1]*xx + p[2]*TMath::Gaus(xx, p[3], p[4]) + p[5]*TMath::Gaus(xx, p[6], p[7]);
    return SDAfunc(x, &p[6]) + gaus(x, g1) + gaus(x, g2);
}

void fit_2gaus(std::string fname){
    gStyle->SetOptStat("e"); gStyle->SetOptFit(1111);
    gStyle->SetStatBorderSize(0.); gStyle->SetTextSize(19);
    gStyle->SetStatX(.92); gStyle->SetStatY(.89);

    std::ifstream fin("../dati/" + fname);
    std::string element;
    Double_t par[8];
    Double_t min = 3750, max = 6800;

    TCanvas * c1 = new TCanvas("c1", "c1", 1);
    TH1F * h1 = new TH1F("h1", "h1", 120, 3000, 9000);

    while (fin >> element){
        unsigned int value = std::stoul(element, nullptr, 16);
        h1->Fill(value);
    }
    TF1 * func = new TF1("func", ufunc, min, max, 13);
    TF1 * gaus1 = new TF1("gaus1", gaus, min, max, 3); gaus1->SetLineColor(4);
    TF1 * gaus2 = new TF1("gaus2", gaus, min, max, 3); gaus2->SetLineColor(3);
    TF1 * fSDA = new TF1("SDA", SDAfunc, min, max, 7); fSDA->SetLineColor(6);

    // func->SetParNames("A_{0}", "#mu_{0}", "#sigma_{0}", "A_{1}", "#mu_{1}", "#sigma_{1}", "a", "b", "c", "E_{c}" ,"#sigma_{c}", "m", "q");
    Double_t par0[] = {100, 4650, 100, 100, 5200, 100, 2e-5, 2e-4, 1e-3, 3400, 100, -0.01, 1};
    func->SetParName(0, "A_{0}"); func->SetParName(1, "#mu_{0}"); func->SetParName(2, "#sigma_{0}");
    func->SetParName(3, "A_{1}"); func->SetParName(4, "#mu_{1}"); func->SetParName(5, "#sigma_{1}");
    func->SetParName(6, "a"); func->SetParName(7, "b"); func->SetParName(8, "c");
    func->SetParName(9, "E_{C}"); func->SetParName(10, "#sigma_{C}");
    func->SetParName(11, "m"); func->SetParName(12, "q");
    func->SetParameters(par0);
    func->SetParLimits(0, 100, 300);   // A_0
    func->SetParLimits(1, 4700, 4800); // mu_0
    func->SetParLimits(2, 0, 300);     // sigma_0
    func->SetParLimits(3, 100, 300);   // A_1
    func->SetParLimits(4, 4800, 5200); // mu_1
    func->SetParLimits(5, 0, 300);     // sigma_1
    func->SetParLimits(6, 0, 1e-4);       // a
    // func->SetParLimits(7, 0, 1);       // b
    // func->SetParLimits(8, 0, 1);       // c
    func->SetParLimits(9, 3300, 4000); // E_c
    func->SetParLimits(10, 0, 600);// sigma_c
    func->SetParLimits(11, -1, 0);     // m
    func->SetParLimits(12, -10, 10);   // q
    //func->FixParameter(11, -1.78e-5);
    //func->FixParameter(12, 4);

    TFitResultPtr r = h1->Fit("func", "","LIRMS", min, max);
    func->GetParameters(par);
    Double_t g1[] = {par[0], par[1], par[2]};
    Double_t g2[] = {par[3], par[4], par[5]};
    gaus1->SetParameters(g1);
    gaus2->SetParameters(g2);
    fSDA->SetParameters(&par[6]);
    // fSDA->SetParameters(1e-5,1e-4,1e-4,3400, 500, 0, 0);

    h1->Draw("E");
    func->Draw("SAME");
    gaus1->Draw("SAME");
    gaus2->Draw("SAME");
    fSDA->Draw("SAME");

    TLegend * leg = drawLegend(h1, func, fSDA, gaus1, gaus2);
    drawInfos();
    fancyPlot(h1);
}