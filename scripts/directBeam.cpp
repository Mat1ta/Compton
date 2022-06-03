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
#include "TMath.h"

void directBeam(){
    gStyle->SetOptStat(1111); gStyle->SetOptFit(1111);
    gStyle->SetStatBorderSize(0.);
    gStyle->SetStatX(.5); gStyle->SetStatY(.35); gStyle->SetFillColorAlpha(0,0.);

    Double_t freq[] = {285, 308, 378, 908, 4120, 7807, 8852, 8058, 7256, 4371};
    Double_t angle[] = {15, 12, 9, 6, 3, 0, -1, -2, -3, -5};
    Double_t dfreq[] = {2, 2, 2, 3, 9, 19, 22, 24, 14, 13};
    Double_t dangle[] = {0.29, 0.29, 0.29, 0.29, 0.29, 0.29, 0.29, 0.29, 0.29, 0.29};

    TGraphErrors * gr1 = new TGraphErrors(10, angle, freq, dangle, dfreq);
    TF1 * func = new TF1("func", "[0] * TMath::Gaus(x, [1], [2]) + [3]", -10, 20);
    func->SetParameters(9000, -1, 3, 0);
    func->SetParNames("A", "#mu", "#sigma", "k");
    gr1->Fit("func", "M");
    gr1->Draw("AP"); 
    gr1->GetXaxis()->SetTitle("#theta [degrees]"); gr1->GetXaxis()->SetTitleSize(0.045);
    gr1->GetYaxis()->SetTitle("frequency [Hz]"); gr1->GetYaxis()->SetTitleSize(0.045);
    gr1->GetYaxis()->SetTitleOffset(1.05);
    gr1->SetMarkerStyle(20);
    gr1->SetMarkerColor(3);

    TLegend * legend = new TLegend(0.15, 0.4, 0.35, 0.57, "", "NDC nb");
    legend->SetBorderSize(0.);
    legend->SetTextFont(42);
    legend->SetTextSizePixels(22);
    legend->SetFillColorAlpha(0,0.0);
    legend->AddEntry(gr1, "Data", "EP");
    legend->AddEntry(func, "best-fit", "L");
    legend->Draw();
}