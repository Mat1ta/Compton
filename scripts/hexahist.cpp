//
// Simple plot of log file, run with the following command:
//      root 'hexahist.cpp(fname)'
// For example: root 'hexahist.cpp("plot0427.log")'

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "TH1F.h"
#include "TCanvas.h"

void hexahist(std::string fname){
    std::ifstream fin("../data/" + fname);
    std::vector<int> data;
    std::string element;

    TCanvas * c1 = new TCanvas("c1", "c1", 1);
    TH1F * h1 = new TH1F("h1", "h1", 50, 0, 8000);

    while (fin >> element){
        unsigned int value = std::stoul(element, nullptr, 16);
        data.push_back(value);
        h1->Fill(value);
    }
    h1->Draw();
}