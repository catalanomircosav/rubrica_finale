#ifndef __CONTATTO_H__
#define __CONTATTO_H__

#include "Stringa.h"

typedef struct Contatto
{
    Stringa nome;
    Stringa cognome;
    Stringa telefono;
    int stato;
} Contatto;

// * funzioni di lettura
Stringa leggi_nome_contatto(Contatto contatto);
Stringa leggi_cognome_contatto(Contatto contatto);
Stringa leggi_telefono_contatto(Contatto contatto);
int leggi_stato_contatto(Contatto contatto);

// * funzioni di scrittura
void scrivi_nome_contatto(Contatto* contatto, Stringa nome);
void scrivi_cognome_contatto(Contatto* contatto, Stringa cognome);
void scrivi_telefono_contatto(Contatto* contatto, Stringa telefono);
void scrivi_stato_contatto(Contatto* contatto, int stato);

//* funzioni utili
void stampa_contatto(Contatto contatto);

#endif // __CONTATTO_H__