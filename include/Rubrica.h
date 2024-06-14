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

// ! Questa funzione deve implementare scrivi_contatto() con l'interfaccia e l'I/O dell'utente
void inserisci_contatto(Rubrica* rub);

/*
    ? QUESTA FUNZIONE DEVE IMPLEMENTARE LA RICERCA, OPPURE VERRA'
    ? PRIMA STAMPATO TUTTA LA RUBRICA E VERRA' CHIESTO ALL'UTENTE DI SELEZIONARE IL CONTATTO DA CANCELLARE?
    ? IN TAL CASO NON SERVIRA' EFFETTUARE LA RICERCA
*/
void cancella_contatto(Rubrica* rub);

// ! QUESTA FUNZIONE DEVE IMPLEMENTARE LE FUNZIONI DI SCRITTURA DELLA STRUCT CONTATTO
// ! CON L'INTERFACCIA E L'I/O DELL'UTENTE O VERRA' CHIESTO ALL'UTENTE IL CAMPO DA MODIFICARE?
void modifica_contatto(Rubrica* rub);

// ? semplice funzione di ricerca per cognome, nome, e infine telefono o altre casistiche
Rubrica ricerca_contatto(Rubrica rub, Contatto cont);

void stampa_rubrica(Rubrica rub);
int confronto_nome(char* nome1, char* nome2);
int confronto_cognome(char* cognome1, char* cognome2);
void scambio(Contatto* cont1, Contatto* cont2);
void ordina_rubrica(Rubrica* rub);

#endif