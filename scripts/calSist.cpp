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
#include "TMatrixD.h"

void calSist(){
    gStyle->SetOptStat(1111); gStyle->SetOptFit(1111);
    gStyle->SetStatBorderSize(0.);
    gStyle->SetStatX(.5); gStyle->SetStatY(.35); gStyle->SetFillColorAlpha(0,0.);

    Double_t time[] = {0, 4320, 7200, 10950}, etime[] = {60, 60, 60, 60};
    Double_t Na_0[] = {2786, 2765, 2744, 2726}, eNa_0[] = {27, 24, 22, 20};
    Double_t Na_1[] = {6700, 6614, 6592, 6557}, eNa_1[] = {50, 37, 41, 61};
    Double_t Cs[] = {3605, 3576, 3554, 3526}, eCs[] = {28, 26, 26, 25};
    Double_t Co_0[] = {6195, 6153, 6116, 6051}, eCo_0[] = {33, 47, 43, 41};
    Double_t Co_1[] = {6985, 6918, 6895, 6851}, eCo_1[] = {41, 40, 54, 44};

    TCanvas * c1 = new TCanvas("c1", "c1", 1);
    TMultiGraph * plot = new TMultiGraph();
    TGraphErrors * gr = new TGraphErrors(4, time, Co_1, etime, eCo_1); 
    gr->SetMarkerStyle(20); gr->SetMarkerColor(2);

    TF1 * func = new TF1("func", "[0] + [1] * x", 0, 10950);
    gr->Fit(func);
    gr->Draw("AP");
}