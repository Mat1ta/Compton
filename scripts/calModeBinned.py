import numpy as np
from ROOT import TCanvas, TH1F

''' Ranges of energies E for different sources:
        Na_low :  2000 < E < 4000
        Na_high : 5800 < E < 7400
        Cs :      2000 < E < 5000
        Co_low :  5500 < E < 6400
        Co_high : 6400 < E < 7500
'''

DRAW = int(2e3) # Number of draws in the sample
REP = int(3e3) # Number of repetitions
BIN = 100 # Bins in temp histogram

if __name__ == '__main__':
    
    fname = '../dati/plot0510calNa.dat'
    arr = np.array([int(hexa, base=16) for hexa in np.genfromtxt(fname, dtype='str')])
    mask1 = arr > 2000
    mask2 = arr < 4000
    arr = arr[mask1 & mask2]

    mode = np.zeros(REP)

    for i in range(REP):
        temp = np.random.choice(arr, DRAW)
        hist, bins = np.histogram(temp, BIN)
        mode[i] = (bins[np.argmax(hist)+1] + bins[np.argmax(hist)]) / 2

    opt = 0 # 0 to simple print the result, 1 to plot histogram (remember to adjust parameters in histogram)    
    if opt == 0:
        print(f'MODE = {np.mean(mode):.0f} +/- {np.std(mode):.0f}')
    elif opt == 1:
        c1 = TCanvas("c1", "c1", 1)
        h1 = TH1F("h1", "h1", 30, 3400, 3700)
        for val in mode:
            h1.Fill(val)
        h1.Draw()