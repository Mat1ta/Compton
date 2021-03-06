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

| V<sub>mon1</sub> [V] | V<sub>THR</sub> [mV] | D [cm] | name_file |
| -------------------- | -------------------- | ------ | --------- |
| 670                  | -68.3                |        |           |

### lista di domande
* le ripartenze sono un problema?


## 13 aprile 2022
Il rate che osservavamo era basso perché la soglia di trigger era troppo alta, per alimentazioni più basse serve una soglia più bassa, e.g. V<sub>mon</sub> = 757 V  e V<sub>TR</sub> = -20.0 mV, rate ad angolo zero è 9 KHz, ad angolo 30 è 200 Hz, attenuazione 23dB.

D è la distanza tra l'inizio della guida e l'inizio del carrello. 
La distanza tra:
* l'inizio del carrello e l'inizio del cristallo è 7.3(2) cm,
* l'inizio della guida e la vite è 22.8(2) cm, 
* la vite e il foro è 4.7(2) cm

 <img src="apparato.jpg"/>
 
    
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

## 26 aprile
 Fissiamo il punto di lavoro del PMT1:
 V<sub>mon</sub> = 649 V, corse gain=10, fine gain = 0.942, attenuazione = 1.5 dB.
 
 Misuraimo la variazione di rate diretto ($\theta = 0$) com e senza PMT2:
 senza PMT2 7.5 kHz, con 7.3 kHz (soglia di trigger = -8 mV)
 
 Faccimao un campionamento a diversi angoli dei fotoni incidenti:
 soglia di trigger dell'oscilloscopio -8.0 mV
 | angolo [deg] | rate [Hz] |
 | ------------ | --------- |
 | 0            | 7.5(5) k  |
 | 6            | 3.3(3)k   |
 | 12           | 440(100)  |
 | 30           | 280(40)   |
 | 60           | 200(40)   |
 
 Fissiamo V<sub>mon</sub> del PMT2 a 1570 V (il rate misurato all'oscilloscopio a questa tensione è 180(40)Hz con una soglia di -11 mV)
 
 Inviamo al GATE del CAEN N957 l'uscita PMT1b modificata dal discriminatore (soglia -35.1 mV) e da un QUAD GATE (per allargare il segnale): largezza del segnale 10 us, in anticipo rispetto al picco PMT1a di 4.3 us, e dopo il picco passano altri 5.7 us.
 Inviamo al IN del CAEN N957 l'uscita del PMT1a: si vedono i due picchi del Co.
 Aumentando in valore assoluto questa soglia, i picchi venivano mano a mano mangiati

 Poiche' siamo al limite inferiore della soglia del discriminatore proviamo a cambiare il punto di lavoro del PMT1 aumentando V<sub>mon</sub>.
 Allora fissiamo il punto di lavoro del PMT1 a V<sub>mon</sub> = 689 V, corse gain=10, fine gain = 0.732, attenuazione = 5.5 dB.
 Fissiamo il punto di lavoro del PMT2 a Vmon = 1632 V (facendo la stessa considerazine di prima di variazione del rate del PMT1 con e senza targhetta). Ora la soglia del discriminatore è 41.6 e 36.5 rispettivamente per PMT1 e PMT2.
 
 Facciamo la coincidenza tra il PMT1b e PMT2. I segnali sono prima discriminati (come sopra) e successivamente allargati entrambi a 10 us. Si prende l'uscita del modulo di coincidenza OUT e si allrga in modo tale che sia largo 10 us, e che preceda e segua il picco del PMT1a di almeno 200 ns (non è fisso).
 
 * Misuriamo le dimensioni del fascio di fotoni diffusi -> per fare questo non serve prima aggiustare il trigger??)
 * coincidenza PMT1b e PMT2
 * soglia del gate (per fotoni incidenti o fotoni diffusi?)
 
 
 ## 27 aprile
 
 Collego l'uscita del PMT1b all'oscilloscopio con un cavo da 4 ns senza terminazione, si osservano delle riflessioni di 97(1)ns.
 Faccio la stessa cosa con il PMT2 (stesso cavo) e osservo delle riflessioni di 62.00(40) ns. Si osserva che per questo canale ci sono le stesse riflessioni anche con la terminazione a 50 ohm anche se più attenuate.
 
 Da queste misure si può ricavare che la lunghezza del filo che va dal PMT1 all'uscita PMT1b sul track è di 44.5 ns, e quella che va dal PMT2 alla sua uscita sul track è di 27 ns.
 Allora la differenza di tempo di due segnali simultanei sui due PMT è di 17.5 ns.

 I due segnali non sono simultanei (anche se si potrebbe fare una stima teorica di questa differenza) e soprattutto non conosciamo i tempi di risposta dei due PMT, allora ha più senso guardare i due segnali in persistenza all'osscilloscopio e stimare così il ritardo tra le due risposte (comprese di cavi, momento in cui passa la particella dal rivelatore e risposta dello stesso).
 
 Ci sono pochi segnali, percio' si abbassano le soglie del discriminatore al minimo, -35.2 per PMT1b e -36.6 mV per PMT2.
 Abbiamo guardato se si vedevano più coincidenze con una tensine di alimentazione del PMT1 più alta ma poi l'abbiamo reimpostata a 690 V.
 
 Cerchiamo di eliminare le ripartenze del PMT1b, inviamo il segnale del PMT al discriminatore con soglia -35.2 mV, e inviamo il segnale a un dual timer che lo allarga fino a circa 800 ns, e poi lo riduce a 200 ns.
 Il seganle del PMT2 invece è mandato al discriminatore con soglia -36.6 mV, e poi è ritardato di 108 ns e allargato a 324 ns con un modulo quad gate delay.

 Aumentiamo l'alimentazione del PMT2 a 1891 V.
 
 Facciamo la coincidenza tra i due seganli modificati come sopra, ed essa viene allargata a 1 us con il modulo quad gate
 Iniziamo a salvare un file di eventi triggerati sulla coincidenza tra così fatta. Il nome del file è `plot0427.log`, l'angolo del cristallo è 34 gradi.
 
 <img src="plot_jpegs/plot0427.jpg"/>
 
 ## 28 aprile
 
 Avviamo il progrmma per fare una presa dati con le stesse condizini di ieri: `plot0428_1890.dat`
 
 <img src="plot_jpegs/plot0428_1890.jpg"/>
 
 Abbassiamo la tensione di alimentazione del PMT2 a 1790 V (dato che la tensione massima è 1800 V).
 Amplifichiamo di un fattore 10 il segnale del PMT2 prima di mandarlo al discriminatore, la cui sogli aviene alzata a -150 mV (così che la soglia di discriminazione sul segnale non amplificato sia di -15 mV).
 Le larghezze dei due segnali in coincidenza sono di 1 us.
 
 Iniziamo una run con queste condizioni (avendo controllato che la coincidenza fosse ancora corretta): `plot0428th30.log`.
 
<image src="plot_jpegs/plot0428th30.jpg"/> 
 
 Ne facciamo un'altra con il cristallo ad angolo 15 gradi: `plot0428th15.log`
 
 <img src="plot_jpegs/plot0428th15.jpg"/>
 
 Amplifichiamo anche il PMT1b, con lo scopo di abbassare la sua tensione di soglia così da poter vedere uno spettro più ampio in energia.
 Questa run è salvata nel file `plot0428th15bis.log`
 
 <img src="plot_jpegs/plot0428th15bis.jpg"/>
 
## 3 maggio
 Briefing:
 * calibrazione per fare osservazioni quantitative su dove mi aspetto di trovare i picchi
 * conoscere la risoluzione dell'apparato (con sorgenti diverse, come quelle con un solo picco)
 * presa dati di un paio d'ore per fare delle considerazioni quantitative e sull'importanza del rumore
 * misura del rumore (?)
 
 Usando l'equazione dell'effetto compton ci si aspetta le seguenti energie per i fotoni scatterati ad angolo $\theta$:
 | $\theta$             | 0    | 15   | 22   | 30   |
 | -------------------- | ---- | ---- | ---- | ---- |
 | E<sub>1</sub> [MeV]  | 1.17 | 1.08 | 1.00 | 0.89 |
 | E<sub>1</sub>} [MeV] | 1.33 | 1.22 | 1.12 | 0.99 |
 
 Facciamo una prima calibrazione usando la sorgente di cobaldo diretta sul cristallo (theta=0), ci aspettiamo due picchi: uno a 1 MeV e uno a 1.2 MeV. Vediamo che il grafico satura sul secondo picco: decidiamo di cambiare il fine gain (del PMT1) a 0.700 (V<sub>mon</sub> = 690 V).
 I dati di questo istogramma sono salvati sul file `plot0503cal60Co.dat` (trigger automatico).
 Il primo picco è 6457(192), il secondo è 7281(188).
 
 <img src="plot_jpegs/plot0503cal60Co.jpg"/>
 
 Facciamo una presa dati a 15 gradi col setup così fatto (gate quello della volta scorsa, con i segnali dei due PMT in coincidenza sono entrambi amplificati e il fine gain del cristalllo modificato come sopra): `plot0503th15_0.dat` e `plot0503th15_1.dat` (quest'ultimo comprende i dati del primo: è stata messa in "pausa" l'acquisizione).
 
 <img src="plot_jpegs/plot0503th15.jpg"/> 
 <img src="plot_jpegs/plot0503th15_1.jpg"/>
 
## 4 maggio
 Misuro il diametro del cristallo col calibro: 5.860(5) cm.
 Questo mi serve per determinare l'apertura angolare rispetto alla distanza del cristallo dal foro della sorgente.
 Il PMT2 è largo 1.180(5) cm.
 
 Da oggi in poi iniziamo una procedura di controllo dei punti lavoro e della calibrazione:
 * punti di lavoro
    | V<sub>mon1</sub> [V] | coarse gain PMT1a | fine gain PMT1a | attenuazione [dB] PMT1a | V<sub>mon2</sub> [V] | V_th1b    | V_th2     |
    | -------------------- | ----------------- | --------------- | ----------------------- | -------------------- | --------- | --------- |
    | 690                  | 10                | 0.700           | 5.5                     | 1788                 | -259.5 mV | -151.8 mV |
 * calibrazione
   * sodio: `plot0504calNa_0.dat`, `plot0504calNa_1.dat`
 <img src="plot_jpegs/plot0504calNa_0.jpg"/> 
 <img src="plot_jpegs/plot0504calNa_1.jpg"/> 
   * cesio: `plot0504calCs.dat`
 <img src="plot_jpegs/plot0504calCs.jpg"/> ----- da FARE jpg e pdf
 
 Si osserva che se la scatola con le sorgenti non viene schermata dal Pb, il picco del Cesio si vede sempre, in quanto la scatola non è sufficiente a schermarne i fotoni.
 
 Iniziamo una presa dati a 15 gradi: `plot0504th15.dat` (1h55). 

 <img src="plot_jpegs/plot0504th15.jpg"/> 
 
 Nel frattenpo si fa un'analisi approssimativa dei dati di calibrazione:
 * sodio due picchi : 6381(187) e 2637(96) (Na)
 * cesio un picco in due grafici : 3414(107) (Cs), 3394(119) (Na)
 * picco osservato nello spettro del cesio in 1014(150) (Cs) --> chi è??
 
 Fit di calibrazione:
 
 <img src="plot_jpegs/calLin0504.jpg"/> ---------- da FARE
 
 ## 5 maggio

 Procedure iniziali:
 * punto di lavoro
  abbiamo cambiato multimetro (usato per misurare le tensioni di discriminazione)
    | V<sub>mon1</sub> [V] | coarse gain PMT1a | fine gain PMT1a | attenuazione [dB] PMT1a | V<sub>mon2</sub> [V] | V_th1b    | V_th2     |
    | -------------------- | ----------------- | --------------- | ----------------------- | -------------------- | --------- | --------- |
    | 693                  | 10                | 0.700           | 5.5                     | 1790                 | -258.0 mV | -151.0 mV |
 
 
 Abbiamo stretto i segnali che erano in coincidenza a 300 ns.
 Facciamo così un'acquisizione a 15 gradi: `plot0505th15d01.dat` (0h17).
 
 <img src="plot_jpegs/plot0505th15d01.jpg"/>
 
 Allontanizmo il carrello di 12 cm (prima era a un centrimetro dall'iniziono della guida) e facciamo un'altra acquisizione: `plot0505the15d13.dat` (0h17).
 
 <img src="plot_jpegs/plot0505th15d13.jpg"/>
 
 Stringiamo ancora i segnali in coincidenza entrambi a 152 ns, e faccimao partire l'acquisizione: `plot0505th15d01_01.dat` (0h17).
 
 <img src="plot_jpegs/plot0505th15d01_01.jpg"/>
 
 Facciamo due misure di calibrazione col sodio (`plot0505calNa.dat`) e col Cesio (`plot0505calCs.dat`).
 
 <img src="plot_jpegs/plot0505calNa.jpg"/>
 <img src="plot_jpegs/plot0505calCs.jpg"/>
 
 Fit di calibrazione:
 
 <img src="plot_jpegs/calLin0505.jpg"/> ---------- da FARE
 
 ## 10 maggio
 
 Procedure iniziali:
 * punto di lavoro
  siamo tornati al multimetro iniziale (usato per misurare le tensioni di discriminazione)
    | V<sub>mon1</sub> [V] | coarse gain PMT1a | fine gain PMT1a | attenuazione [dB] PMT1a | V<sub>mon2</sub> [V] | V_th1b    | V_th2     |
    | -------------------- | ----------------- | --------------- | ----------------------- | -------------------- | --------- | --------- |
    | 690                  | 10                | 0.700           | 5.5                     | 1789                 | -260.0 mV | -152.0 mV |
 
 Facciamo una presa dati dello spettro della sorgente all'interno della scatola: `plot0510cal60Co.dat` (30 secondi).
 
 <img src="plot_jpegs/plot0510cal60Co.jpg"/>
 
  Avendo osservato che i picchi non coincidono con la sorgente di cobalto nella scatola a disposizione si fa un'acquisizione del Cobalto (quello dentro al "sarcofago") smorzato (21.5 cm sulla guida a 5 gradi) `plot0510cal60Co_1.dat` -> i picchi si spostano, allora c'è dipendenza dal rate (intensità) della sorgente.
 
 <img src="plot_jpegs/plot0510cal60Co_1.jpg"/>
 
 Con i segnali in coincidenza entrambi a 152 ns, e faccimao partire l'acquisizione col carrello a 13 cm dall'inizio della guida: `plot0510th15d13T150.dat` (0h17).
 
 <img src="plot_jpegs/plot0510the15d13T150.jpg"/>
 
 Facciamo le calibrazioni (16:30 cca):
 * cobalto `plot0510calCo.dat` (60 secondi)
 <img src="plot_jpegs/plot0510calCo.jpg"/>
 * cesio `plot0510calCs.dat` (30 secondi)
 <img src="plot_jpegs/plot0510calCs.jpg"/>
 * sodio `plot0510calNa.dat` (240 secondi)
 <img src="plot_jpegs/plot0510calNa.jpg"/>
 

 
 Con i segnali in coincidenza entrambi a 152 ns, e faccimao partire l'acquisizione col carrello a 13 cm dall'inizio della guida: `plot0510th15d13T150_1.dat` (1h13).
 
 <img src="plot_jpegs/plot0510th15d13T150_1.jpg"/> ----- da FARE
 
 Facciamo un'altra calibrazione (18:36):
 * sodio `plot0510calNa_1.dat` (240 secondi)
 <img src="plot_jpegs/plot0510calNa_1.jpg"/> ----- da FARE jpg
 * cesio `plot0510calCs_1.dat` (30 secondi)
 <img src="plot_jpegs/plot0510calCs_1.jpg"/> ----- da FARE jpg
 * cobalto `plot0510calCo_1.dat` (60 secondi)
 <img src="plot_jpegs/plot0510calCo_1.jpg"/> ----- da FARE jpg

 Fit di calibrazione:
 
 <img src="plot_jpegs/calLin0510fin.jpg"/> ---------- da FARE
 
 ## 11 maggio
 
 Alziamo (in valore assouto) la soglia del del PMT1b a -301.7 mV. E facciamo un'acquisizione, ci aspettimao che la parte sinistra del grafico se ne vada: non salviamo i dati vediamo che il grafico è popolato dal bin 3500 fino a saturazione.
 
  Procedure iniziali:
 * punto di lavoro
  siamo tornati al multimetro iniziale (usato per misurare le tensioni di discriminazione)
    | V<sub>mon1</sub> [V] | coarse gain PMT1a | fine gain PMT1a | attenuazione [dB] PMT1a | V<sub>mon2</sub> [V] | V_th1b    | V_th2     |
    | -------------------- | ----------------- | --------------- | ----------------------- | -------------------- | --------- | --------- |
    | 694                  | 10                | 0.700           | 5.5                     | 1789                 | -301.9 mV | -152.2 mV |
 * calibrazione (10:48):
   * sodio `plot0511calNa.dat` (240 secondi)
 <img src="plot_jpegs/plot0511calNa.jpg"/> ----- da FARE jpg e pdf
   * cesio `plot0511calCs.dat` (30 secondi)
 <img src="plot_jpegs/plot0511calCs.jpg"/> ----- da FARE jpg e pdf
   * cobalto `plot0511calCo.dat` (70 secondi) 
 <img src="plot_jpegs/plot0511calCo.jpg"/> ----- da FARE jpg e pdf
 
 Fit di calibrazione:
 
 <img src="plot_jpegs/calLin0511in.jpg"/> ---------- da FARE
 
 Facciamo una presa dati a 22 gradi: `plot0511th22d13T150.dat` (1h32).
 
 <img src="plot_jpegs/plot0511th22d13T150.jpg"/>    
 
 Procedure finali:
 * calibrazione (12:30)
    * sodio `plot0511calNa_1.dat` (124 secondi)
 <img src="plot_jpegs/plot0511calNa_1.jpg"/>
   * cesio `plot0511calCs_1.dat` (33 secondi)
 <img src="plot_jpegs/plot0511calCs_1.jpg"/>
   * cobalto `plot0511calCo_1.dat` (97 secondi) 
 <img src="plot_jpegs/plot0511calCo_1.jpg"/>
 
 Fit di calibrazione:
 
 <img src="plot_jpegs/calLin0511fin.jpg"/> ---------- da FARE
 
 ## 12 maggio
 Andiamo in laboratorio alle 9:00 per iniziare una presa dati: `plot0512th22d13T150.dat` (inizio 9:15-fine 16:40 = 26677.314 s)
 
 <img src="plot_jpegs/plot0512th22d13T150.jpg"/>
 
 * punto di lavoro alle 9:15
  siamo tornati al multimetro iniziale (usato per misurare le tensioni di discriminazione)
    | V<sub>mon1</sub> [V] | coarse gain PMT1a | fine gain PMT1a | attenuazione [dB] PMT1a | V<sub>mon2</sub> [V] | V_th1b    | V_th2     |
    | -------------------- | ----------------- | --------------- | ----------------------- | -------------------- | --------- | --------- |
    | 694                  | 10                | 0.700           | 5.5                     | 1789                 | -301.4 mV | -151.9 mV |
 
 Torniamo in laboratorio alle 16:30.
 Procedure iniziali:
 * punto di lavoro
  siamo tornati al multimetro iniziale (usato per misurare le tensioni di discriminazione)
    | V<sub>mon1</sub> [V] | coarse gain PMT1a | fine gain PMT1a | attenuazione [dB] PMT1a | V<sub>mon2</sub> [V] | V_th1b    | V_th2     |
    | -------------------- | ----------------- | --------------- | ----------------------- | -------------------- | --------- | --------- |
    | 694                  | 10                | 0.700           | 5.5                     | 1792                 | -302.7 mV | -152.2 mV |
 
 * calibrazione (16:46, il cobalto è stato usato invece alle 16:58 perche' occupato da altri):
   * sodio `plot0512calNa_0.dat` ( 175 secondi)
  <img src="plot_jpegs/plot0512calNa_0.jpg"/>
   * cesio `plot0512calCs_0.dat` ( 37 secondi)
   <img src="plot_jpegs/plot0512calCs_0.jpg"/>
   * cobalto `plot0512calCo_0.dat` ( 42 secondi) 
  <img src="plot_jpegs/plot0512calCo_0.jpg"/>

 Iniziamo una presa dati a 30 gradi: `plot0512th30d13T150.dat` (5057 s).
 
 <img src="plot_jpegs/plot0512th30d13T150.jpg"/>
 
 Dato che le distribuzione in energia delle sorgenti di calibrazione non sono delle gaussiane, scegliamo di utilizzare un estimatore diverso dalla media: la moda. Parlando col professore ci si presentano due modi per il calcolo della moda:
 * binned, cercando il massimo di occorrenze nell'istogramma
 * unbinned, cercando nel set di dati i due valori più vicini tra loro

In entrambi i casi per trovare l'errore sulla moda si fa un [bootstrap](https://en.wikipedia.org/wiki/Bootstrapping_(statistics)).
 
 * Calibrazione finale (18:45):
   * sodio `plot0512calNa_1.dat` ( 39 secondi)
 <img src="plot_jpegs/plot0512calNa_1.jpg"/>
 
   * cesio `plot0512calCs_1.dat` ( 20 secondi)
 <img src="plot_jpegs/plot0512calCs_1.jpg"/>

   * cobalto `plot0512calCo_1.dat` ( 40 secondi) 
  <img src="plot_jpegs/plot0512calCo_1.jpg"/>

 

Eseguiamo e testiamo il bootstrap sui dati del 10 maggio per ottenere la moda dei vari picchi delle sorgenti di calibrazione. 
* Dipendenza del _BOOTSTRAP_ dai vari parametri, analisi fatta su `plot0510calCs.dat`
  * Variazione di `REP`: numero di ripetizioni del BS
  <img src="plot_jpegs/calBS_spanRep.jpg"/>
  * Variazione di `DRAW`: numero di elementi nel subsample
  <img src="plot_jpegs/calBS_spanDraw.jpg"/>
  * Variazione di `BIN`: numero di bin del subsample
  <img src="plot_jpegs/calBS_spanBin.jpg"/>

Compariamo i risultati del fit quadratico, ottenuto con un fit locale con una curva gaussiana e con il metodo di stima della moda prima descritto:
  |                         | $\chi^2$/ndf | _p-value_ | a            | b            | c           |
  | ----------------------- | ------------ | --------- | ------------ | ------------ | ----------- |
  | local _Gaussian_-fit    | $2.1/2$      | $0.35$    | $-368\pm20$  | $5783\pm37$  | $-90\pm15$  |
  | _BOOTSTRAP_ mode        | $0.15/2$     | $0.93$    | $-250\pm293$ | $5551\pm540$ | $-13\pm214$ |
  | _BOOTSTRAP_ mode (a==0) | $0.87/3$     | $0.83$    | $0$          | $5092\pm41$  | $192\pm38$  |
 
 
 ## 17 maggio
 ### laboratorio
 Andiamo in laboratorio alle 9:00 per fare un'aquisizione a 30 gradi: `plotth30d13T150.dat` (17:22-9:15= h =29192 s)
 
 | V<sub>mon1</sub> [V] | coarse gain PMT1a | fine gain PMT1a | attenuazione [dB] PMT1a | V<sub>mon2</sub> [V] | V_th1b    | V_th2     |
 | -------------------- | ----------------- | --------------- | ----------------------- | -------------------- | --------- | --------- |
 | 694                  | 10                | 0.700           | 5.5                     | 1795                 | -302.1 mV | -151.3 mV |

 
 ### Breafing:
 Vogliamo avere una stima della massa dell'elettrone a partire dall'acquisizione del 12 maggio a 22 gradi. Facendo una calibrazione attraverso la moda come spiegato in precedenza.
 Usiamo gli spettri di calibrazioni fatti alle 16:50, con i seguenti risultati:
 * m = 5010 pm 36
 * q = 180 pm 33
 
 Le energie dei fotoni scatterate per i due picchi sono in unità arbitrarie:
 * 5250 pm 52
 * 5740 pm 54
 
 Per una stima primaria, usiamo la formula inversa dell'equazone dell'effetto compton si trovano i seguenti valori per la massa dell'elettrone:
 * m = 0.55 pm 0.15
 * m = 0.49 pm 0.11
 
 Gli errori percentuali sono (per i due picchi):
* energia della particella scatterata  10.3%, 6.9%  -> controllare script sono sbagliati
* errore dell'angolo  4.9%, 4.4%

 ### di nuovo in laboratorio:
 
 * Punto di lavoro (16:22):
 | V<sub>mon1</sub> [V] | coarse gain PMT1a | fine gain PMT1a | attenuazione [dB] PMT1a | V<sub>mon2</sub> [V] | V_th1b    | V_th2     |
 | -------------------- | ----------------- | --------------- | ----------------------- | -------------------- | --------- | --------- |
 | 694                  | 10                | 0.700           | 5.5                     | 1799                 | -303.1 mV | -152.9 mV |

 * Calibrazioni (17:30):
   * sodio `plot0517calNa_0.dat` ( 146 secondi)
 <img src="plot_jpegs/plot0512calNa_0.jpg"/>
   * cesio `plot0517calCs_0.dat` ( 27 secondi)
 <img src="plot_jpegs/plot0512calCs_0.jpg"/>
   * cobalto `plot0517calCo_0.dat` ( 49 secondi) 
  <img src="plot_jpegs/plot0512calCo_0.jpg"/>
 
 
 * Acquisizione a 10 gradi: `plot0517th10d13T150.dat` (0h57 = 3429 s)
 
 * Calibrazione (18:40)
   * sodio `plot0517calNa_1.dat` ( 95 secondi)
 <img src="plot_jpegs/plot0517calNa_1.jpg"/>
   * cesio `plot0517calCs_1.dat` ( 48 secondi)
 <img src="plot_jpegs/plot0517calCs_1.jpg"/>
   * cobalto `plot0517calCo_1.dat` ( 79 secondi) 
  <img src="plot_jpegs/plot0517calCo_1.jpg"/>

 ## 18 maggio
  
 ### In laboratorio:
 
 * Calibrazioni (9:35):
   * sodio `plot0518calNa_0.dat` ( 189 secondi)
   * cesio `plot0518calCs_0.dat` ( 36 secondi)
   * cobalto `plot0518calCo_0.dat` ( 67 secondi) 
 
 * Punto di lavoro (9:38):
 | V<sub>mon1</sub> [V] | coarse gain PMT1a | fine gain PMT1a | attenuazione [dB] PMT1a | V<sub>mon2</sub> [V] | V_th1b    | V_th2     |
 | -------------------- | ----------------- | --------------- | ----------------------- | -------------------- | --------- | --------- |
 | 694                  | 10                | 0.700           | 5.5                     | 1795                 | -302.3 mV | -152.1 mV |

 * Acquisizione a 15 gradi con carrello su ultima tacchetta (22 cm): `plot0518th15d22T150.dat` (3395 s)
  
 * Calibrazioni (10:47):
   * sodio `plot0518calNa_1.dat` ( 184 secondi)
   * cesio `plot0518calCs_1.dat` ( 36 secondi)
   * cobalto `plot0518calCo_1.dat` ( 77 secondi) 
 
 * Acquisizione a 15 gradi con carrello su ultima tacchetta (22 cm): `plot0518th15d22T150_1.dat` ( 2152 s)
 
 * Calibrazione (11:35):
   * sodio `plot0518calNa_2.dat` ( 186 secondi)
   * cesio `plot0518calCs_2.dat` ( 307 secondi)
 <img src="plot_jpegs/plot0518Cs_2"/>
 Usiamo questo spettro per studiare la forma della spalla compton in modo da avere una conoscenza migliore del fondo per le stime delle energie dei fotoni dopo lo scattering (e diminuire così l'incertezza sistematica proveniente dal foondo).
   * cobalto `plot0518calCo_2.dat` ( 65 secondi) 
 
 * Acquisizione a 15 gradi con carrello su ultima tacchetta (22 cm): `plot0518th15d22T150_2.dat` ( 3306 s)
 
 * Calibrazioni (12:40):
   * sodio `plot0518calNa_3.dat` ( 185 secondi)
   * cesio `plot0518calCs_3.dat` ( 31 secondi)
   * cobalto `plot0518calCo_3.dat` ( 62 secondi) 
 
## 19 maggio
 ### In laboratorio (10:00)
 
 * Acquisizione a 15 gradi e distanza 23 cm dall'inizio della guida: `plot0519th15d22T150.dat` (27928 s)
 
 * Punto di lavoro
 | V<sub>mon1</sub> [V] | coarse gain PMT1a | fine gain PMT1a | attenuazione [dB] PMT1a | V<sub>mon2</sub> [V] | V_th1b    | V_th2     |
 | -------------------- | ----------------- | --------------- | ----------------------- | -------------------- | --------- | --------- |
 | 692                  | 10                | 0.700           | 5.5                     | 1789                 | -302.0 mV | -152.0 mV |
 
 ### In laboratorio (16:30)
 
 Fermiamo l'acquisizione iniziata la mattina
 
 * Punto di lavoro (17:35)
 | V<sub>mon1</sub> [V] | coarse gain PMT1a | fine gain PMT1a | attenuazione [dB] PMT1a | V<sub>mon2</sub> [V] | V_th1b    | V_th2     |
 | -------------------- | ----------------- | --------------- | ----------------------- | -------------------- | --------- | --------- |
 | 692                  | 10                | 0.700           | 5.5                     | 1793                 | -303.3 mV | -153.4 mV |
 
 * Calibrazioni (17:40)
   * sodio `plot0519calNa_0.dat` ( 619 secondi)
   * cesio `plot0519calCs_0.dat` ( 27 secondi)
   * cobalto `plot0519calCo_0.dat` ( 409 secondi) 
 
 * Acquisizione 18 gradi, distanza 22 cm dall'inizio della guida: `plot0519th18d22T150.dat` ( 2329 secondi)
 
 * Calibrazioni (17:40)
   * sodio `plot0519calNa_1.dat` ( 138 secondi)
   * cesio `plot0519calCs_1.dat` ( 34 secondi)
   * cobalto `plot0519calCo_1.dat` ( 74 secondi) 
 
## 24 maggio
 
 ### In laboratorio (9:15)
 
 * Acquisizione 26 gradi, tacchetta 22: `plot0524th26d22T150.dat` ( 25451 secondi)
 
 * Punto di lavoro (9:15)
  | V<sub>mon1</sub> [V] | coarse gain PMT1a | fine gain PMT1a | attenuazione [dB] PMT1a | V<sub>mon2</sub> [V] | V_th1b    | V_th2     |
  | -------------------- | ----------------- | --------------- | ----------------------- | -------------------- | --------- | --------- |
  | 693                  | 10                | 0.700           | 5.5                     | 1790                 | -302.4 mV | -152.2 mV |
 
 ### In laboratorio (15:44)
 
  * Punto di lavoro (15:44)
    | V<sub>mon1</sub> [V] | coarse gain PMT1a | fine gain PMT1a | attenuazione [dB] PMT1a | V<sub>mon2</sub> [V] | V_th1b    | V_th2     |
    | -------------------- | ----------------- | --------------- | ----------------------- | -------------------- | --------- | --------- |
    | 692                  | 10                | 0.700           | 5.5                     | 1792                 | -303.3 mV | -152.3 mV |

 * Calibrazioni (16:20)
   * sodio `plot0524calNa_0.dat` ( 229 secondi)
   * cesio `plot0524calCs_0.dat` ( 43 secondi)
   * cobalto `plot0524calCo_0.dat` ( 67 secondi)

 * Acquisizione a 22 gradi, tacchetta 22: `plot0524th22d22T150.dat` (7001 secondi)
 
 * Calibrazione (18:40)
   * sodio `plot0524calNa_1.dat` (  secondi)
   * cesio `plot0524calCs_1.dat` (  secondi)
   * cobalto `plot0524calCo_1.dat` (  secondi)

 ## 25 maggio
 
 * Punto di lavoro (15:44)
    | V<sub>mon1</sub> [V] | coarse gain PMT1a | fine gain PMT1a | attenuazione [dB] PMT1a | V<sub>mon2</sub> [V] | V_th1b  | V_th2   |
    | -------------------- | ----------------- | --------------- | ----------------------- | -------------------- | ------- | ------- |
    | 692                  | 10                | 0.700           | 5.5                     | 1790                 | -303 mV | -152 mV |
 
 Facciamo acquisizioni di cui teniamo solo il numero di entrate e il tempo per capire come cambia la frequenza del fascio al variare dell'angolo. D = 22

  | $\theta$ | entries | time  | freq [Hz] | NOTE            |
  | -------- | ------- | ----- | --------- | --------------- |
  | 15       | 27024   | 94.9  | 284       |                 |
  | 12       | 32125   | 104.4 | 307       |                 |
  | 9        | 32673   | 86.4  | 378       |                 |
  | 6        | 97916   | 107.8 | 908       | picchi visibili |
  | 3        | 307351  | 74.6  | 4.12k     | picchi spostati |
  | 0        | 405191  | 51.9  | 7.81k     | picchi spostati |
  | -1       | 408813  | 47.8  | 8.55k     | picchi spostati |
  | -2       | 334416  | 41.5  | 8.05k     | picchi spostati |
  | -3       | 549336  | 75.7  | 7.65k     | picchi spostati |
  | -5       | 220753  | 50.5  | 4.37k     | picchi spostati |
 
 ## 26 maggio 

  * Punto di lavoro (15:44)
    | V<sub>mon1</sub> [V] | coarse gain PMT1a | fine gain PMT1a | attenuazione [dB] PMT1a | V<sub>mon2</sub> [V] | V_th1b    | V_th2     |
    | -------------------- | ----------------- | --------------- | ----------------------- | -------------------- | --------- | --------- |
    | 692                  | 10                | 0.700           | 5.5                     | 1792                 | -303.3 mV | -152.3 mV |

   * Acquisizione a 18 gradi: `plot0526th18d22T150.dat`, di durata 30959 secondi
   * Ho fatto le solite calibrazioni con le seguenti durate
     * Na: 52 secondi
     * Cs: 18 secondi
     * Co: 43 secondi
  
  Il foro del sarcofago ha un diametro di 0.9 +/- 0.1 cm. 
   * sodio `plot0524calNa_1.dat` ( 52 secondi)
   * cesio `plot0524calCs_1.dat` ( 19 secondi)
   * cobalto `plot0524calCo_1.dat` ( 30 secondi)

