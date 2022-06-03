import numpy as np
from ROOT import TCanvas, TH1F

''' Ranges of energies E for different sources:
        Na_low :  2000 < E < 4000
        Na_high : 5800 < E < 7400
        Cs :      2000 < E < 5000
        Co_low :  5500 < E < 6400
        Co_high : 6400 < E < 7500
'''

DRAW = int(1e4) # Number of draws in the sample
REP = int(500) # Number of repetitions
BIN = 1000 # Bins in temp histogram

def BSfunc(arr, min, max):
    mask1 = arr > min
    mask2 = arr < max

    arr = arr[mask1 & mask2]
    DRAW = len(arr)
    mode = np.zeros(REP)

    for i in range(REP):
        temp = np.random.choice(arr, DRAW)
        hist, bins = np.histogram(temp, BIN)
        mode[i] = (bins[np.argmax(hist)+1] + bins[np.argmax(hist)]) / 2

    print(f'MODE = {np.mean(mode):.0f} +/- {np.std(mode):.0f}')  
    return

if __name__ == '__main__':
    
    fname = '../dati/plot0519calCs_0.dat'
    print(fname[8:])
    arr = np.array([int(hexa, base=16) for hexa in np.genfromtxt(fname, dtype='str')])

    if fname[19:21] == 'Na':
        BSfunc(arr, 2000, 4000)
        BSfunc(arr, 5800, 7400)
    elif fname[19:21] == 'Cs':
        BSfunc(arr, 2000, 5000)
    elif fname[19:21] == 'Co':
        BSfunc(arr, 5500, 6400)
        BSfunc(arr, 6400, 7500)
    else: print('Warning: source not found')