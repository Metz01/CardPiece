Card Piece è un simulatore di gioco che prende ispirazione  dal gioco di carte One Piece Card Game. All’interno dell'applicazione è possibile  simulare una partita uno contro uno
tra se stessi a carte scoperte. Lo scopo ideale è quello di potersi allenare in solitario nel gioco e testare nuovi mazzi da utilizzare o contro cui giocare.

![counterrules_image](https://github.com/Metz01/CardPiece/assets/36533886/643d7502-05b1-4482-af62-3416f9e97eb5)

Sebbene non completa rispetto a quello che è il gioco originale, questa applicazione permette comunque di poter simulare le azioni principali del gioco, con la possibilità di 
salvare e riprendere in seguito una partita. 
I tipi di carte che compongono e caratterizzano il simulatore sono:

Leader: è il personaggio principale da cui si costruisce il mazzo. È importante notare che il parametro "Vita" del Leader rappresenta anche la vita del giocatore, una delle 
condizioni di vittoria di CARD PIECE. Quando questo valore scende a zero, il gioco termina ("game over").

Character: sono le carte effettivamente giocabili e piazzabili sul campo. I Character, così come il Leader, possono attaccare, subire attacchi e ricevere un bonus sul loro 
parametro "Attacco" che rappresenta sia la potenza d'attacco che la difesa del Character. Inoltre, i Character possono essere utilizzati come "counter" per potenziare la difesa di
un altro Character o del Leader che sta subendo un attacco.

Event: sono carte speciali che possono essere giocate e hanno l'effetto di fornire un bonus temporaneo (valido solo durante il turno in cui vengono giocate) al parametro "Attacco" 
dei Character e del Leader.

Stage: sono carte particolari che, una volta giocate e posizionate sul campo, rimangono in gioco per un tempo indefinito. Queste carte forniscono un bonus permanente (ma attivo 
solo durante il turno del giocatore che le ha giocate) al parametro "Attacco" dei Character e del Leader.

Don: sono carte che non vengono pescate direttamente dal mazzo normale né giocate dalla mano del giocatore. Queste carte vengono pescate, due alla volta per turno, fino a un 
massimo di dieci, all'inizio del turno di ogni giocatore dal Don Deck. Le carte Don possono essere utilizzate per due scopi distinti: come risorse per giocare nuove carte dalla 
mano (ogni carta giocabile ha un parametro "Costo" che rappresenta il numero di Don necessari per giocarla) e come bonus temporaneo al parametro "Attacco" dei Character e del 
Leader.

Per avviare l’applicazione una volta andati all’interno della cartella CardPiece bisognerà eseguire i tre seguenti comandi:

qmake

make

./CardPiece

L'applicazione è stata sviluppata per la versione 6.2.4 di QT e la 3.1 di qmake

