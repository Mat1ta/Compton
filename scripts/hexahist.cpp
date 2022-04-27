#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "TH1F.h"
#include "TCanvas.h"

void hexahist(){
    std::ifstream fin("../scripts/plot0427.log");
    std::vector<int> data;
    std::string element;

    TCanvas * c1 = new TCanvas("c1", "c1", 1);
    c1->cd();
    TH1F * h1 = new TH1F("h1", "h1", 500, 0, 8000);
    
    while (fin >> element){
        unsigned int value = std::stoul(element, nullptr, 16);
        data.push_back(value);
        h1->Fill(value);
        std::cout << "ciao" << std::endl;
    }
    h1->Fill(200);
    h1->Draw("E");
}