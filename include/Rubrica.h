#ifndef __RUBRICA_H__
#define __RUBRICA_H__

#include "Utils.h"
#include "Contatto.h"
#include "Interfaccia.h"

#define MAX_NUM_CONTATTI 50

typedef struct Rubrica
{
    int dim;
    Contatto contatti[MAX_NUM_CONTATTI];
} Rubrica;

// * funzioni di lettura
int leggi_dim_rubrica(Rubrica rub);
Contatto leggi_contatto(Rubrica rub, int pos);

// * funzioni di scrittura
void scrivi_dim_rubrica(Rubrica* rub, int dim);
void scrivi_contatto(Rubrica* rub, int pos, Contatto cont);

// * funzioni di inserimento, cancellazione, modifica, ricerca, ordinamento
Contatto inserisci_contatto();
void cancella_contatto(Rubrica* rub, Contatto cont);
void modifica_contatto(Rubrica* rub);
Rubrica ricerca_contatto(Rubrica rub, Contatto cont);

void stampa_rubrica(Rubrica rub);
void ordina_rubrica(Rubrica* rub);

#endif