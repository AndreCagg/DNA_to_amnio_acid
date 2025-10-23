
# DNA Translator

Questo programma, seppur semplice nella sua struttura, ha l’obiettivo di convertire una sequenza di basi nucleotidiche del DNA nella corrispondente sequenza di amminoacidi, cioè nella proteina codificata da quella sequenza.

Il DNA è costituito da quattro basi — Adenina (A), Timina (T), Citosina (C) e Guanina (G) — organizzate in triplette chiamate codoni. Ogni codone codifica uno specifico amminoacido secondo il codice genetico universale. Il programma legge la sequenza di DNA da un file, suddivide le basi in codoni, e per ciascun codone determina l’amminoacido corrispondente, generando così la sequenza proteica.

Vengono inoltre gestiti codoni di stop, rappresentati da _, che indicano la fine della traduzione proteica. L’output risultante viene scritto in un file separato, in modo da permettere un’analisi o un’ulteriore elaborazione della sequenza proteica generata.

Nonostante la sua semplicità, questo strumento rappresenta un esempio pratico di bioinformatica a cui mi sto interessando.





## Installation

Per l'installazione è sufficiente il download del repository e la compilazione del ```main.c```
```bash
  gcc main.c -o dna_translator
  ./dna_translator
```

le informazioni riguardo la sequenza di DNA sono presenti nel file ```asset/dna.txt``` ed il risultato è in ```asset/translation.txt```
    

