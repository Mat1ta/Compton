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

| V<sub>mon1<sub> | V<sub>mon2<sub> | V<sub>THR1<sub> |
| --------------- | --------------- | --------------- |
| 670 V           | 1510 V          | -207.8 mV       |

Controlliamo il funzionamento del PMT1 con punto di lavoro fissato come sopra e $\theta=0$.
A V<sub>THR1</sub> = 207.8 mV vediamo un rate di 0.7 Hz (anche cambiando l'angolo), quando ce ne aspettiamo uno di 74 MBq
A V<sub>THR1</sub>= 68.3 mV il rate è di 16 Hz (3Hz per un angolo di 45$^\circ$).

Andiamo a vedere che energie legge il PMT1a in diverse configurazioni: cambiando la tensione di alimentazione(, la tensione di soglia?), la distanza dalla sorgente.
Prendiamo il segnale PMT1a, lo inviamo all'attenuatore passivo con una attenuazione di 20 dB, il segnale attenuato passa dal TENNELEC che aggiusta la forma d'onda in modo tale che sia compatibile con il modulo ADC CAEN, che misura l'energia dell'evento.
L'attenuatore serve perchè il segnale satura nel TENNELEC per tensioni superiori a 4.84 V (cursori)

| V<sub>mon1</sub> [V] | V<sub>THR</sub> [mV] | D [cm] | name_file.dat |
| -------------------- | -------------------- | ------ | ------------- |
| 670                  | -68.3                |        |               |

### lista di domande
* le ripartenze sono un problema?


## 13 aprile 2022
Il rate che osservavamo era basso perché la soglia di trigger era troppo alta, per alimentazioni più basse serve una soglia più bassa, e.g. V<sub>mon</sub> = 757 V  e V<sub>TR</sub> = -20.0 mV, rate ad angolo zero è 9 KHz, ad angolo 30 è 200 Hz, attenuazione 23dB.

D è la distanza tra l'inizio della guida e l'inizio del carrello. 
La distanza tra:
* l'inizio del carrello e l'inizio del cristallo è 7.3(2) cm,
* l'inizio del carrello e la vite è 22.8(2) cm, 
* la vite e il foro è 4.7(2) cm

 ![apparato]{https://github.com/Mat1ta/Compton/blob/0ac586cf8d2f194be7bcc3b7c58b521b58b0c038/apparato.jpg}
    
Disegnamo sul carrello delle tacchette distanti 1 cm a partire dal bordo più vicino al foro (si fanno 21 segni con un pennarello STAEDTLER permanent Lumacolor F).

Note sulla ultima parte in compagnia del professore Dell'Orso:
1. fissiamo D= 0 cm e per vari valori di V<sub>mon</sub> andiamo a regolare l'attenuazione per ottenere la massima risoluzione evitando che il TENNELEC saturi in corrispondenza dei picchi dei fotoni. Scriviamo i punti di lavoro buoni.
    | V<sub>mon</sub> [V] | coarse gain | fine gain | attenuazione [dB] |
    | ------------------- | ----------- | --------- | ----------------- |
    | 634                 | 10          | 0.85      | --                |
    | 648                 | 10          | 0.942     | 2                 |    
    | 688                 | 10          | 0.738     | 6.5               |


2. La configurazione a riga 2 è accettabile.
3. Le terminazioni a 50$\Omega$ ammazzavano il segnale. Il percorso seguito dal segnale per i dati in tabella è:
PMT1amp $\rightarrow$ Attenuatore $\rightarrow$ TENNELEC $\rightarrow$ CAEN N957.


