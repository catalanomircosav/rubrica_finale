#ifndef __INTERFACCIA_H__
#define __INTERFACCIA_H__

#define MAX_SCELTA 10

#include "Stringa.h"
#include <conio.h>
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

/*
    ? struttura dati "Interfaccia" per poter gestire in maniera
    ? efficiente e dinamica i menu della rubrica
*/

typedef struct Interfaccia
{
    char* percorso_file;
    int scelta_max;             // variabile che indica la scelta più grande possibile nell'interfaccia
} Interfaccia;

// * funzioni di lettura
char* leggi_percorso_file(Interfaccia interfaccia);
int leggi_scelta_max(Interfaccia interfaccia);

// * funzioni di scrittura
void scrivi_percorso_file(Interfaccia* interfaccia, char* percorso);
void scrivi_scelta_max(Interfaccia* interfaccia, int max);

// * funzioni utili
void stampa_interfaccia(Interfaccia interfaccia);

// * funzione di inizializzazione dell'interfaccia
void inizializza_interfaccia(Interfaccia* interfaccia, char* file, int scelta_max);

#endif // __INTERFACCIA_H__