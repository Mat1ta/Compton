# Logbook esperinza Compton
## 12 aprile 2022
### Punto 1
Stima limite superiore di dose equivalente:
* 73 nSv/s
* 9.3 mSv per il periodo totale di acquisizione

### Ingresso in laboratorio
Iniziamo a familiarizzare con la strumentazione:
* alimentatore CAEN N471, ha due canali di cui è possibile settare e monitorare la tensione di alimntazione, la corrente e la tensione massima.
* PMT1 alimentato positivamente dal canale A dell'alimentatore ad alta tensione
* PMT2 alimentato negativamente dal canale B 

**what?** osseviamo senza aver settato niente il segnale uscente dal PMT1, quando togliamo il cilindretto che blocca la radiazione della sorgente, la frequenza di trigger passa da il centinaio di hertz a sotto la decina... noi ci saremmo aspettati il contrario
**risposta** è la schifezza che viene fuori dallo scattering col tappo

Impostiamo delle tensioni di alimentazioni consigliate e scegliamo le tensioni di soglia in modo che segnali aventi forme d'onda diverse da quella aspettata siano disciminati.

|$$V_{mon1}$$ |$$V_{mon2}$$| V_{THR1}|
|-------------|------------|---------|
|670 V        |1510 V      |-207.8mV |

Controlliamo il funzionamento del PMT1 con punto di lavoro fissato come sopra e $\theta$=0.
A V_{THR1}= 207.8 mV vediamo un rate di 0.7 Hz (anche cambiando l'angolo), quando ce ne aspettiamo uno di 74 MBq
A V_{THR1}= 68.3 mV il rate è di 16 Hz (3Hz per un angolo di 45 degree)

Andiamo a vedere che energie legge il PMT1a in diverse configurazioni: cambiando la tensione di alimentazione(, la tensione di soglia?), la distanza dalla sorgente.
Prendiamo il segnale PMT1a, lo inviamo all'attenuatore passivo con una attenuazione di 20 dB, il segnale attenuato passa dal TENNELEC che aggiusta la forma d'onda in modo tale che sia compatibile con il modulo ADC CAEN, che misura l'energia dell'evento.
L'attenuatore serve perchè il segnale satura nel TENNELEC per tensioni superiori a 4.84 V (cursori)

|V_mon1 [V] |V_THR [mV] |D [cm] |name_file.dat  |
|-----------|-----------|-------|---------------|
|670        |-68.3      |       |               |

### lista di domande
* le ripartenze sono un problema?
* 
## 13 aprile 2022

