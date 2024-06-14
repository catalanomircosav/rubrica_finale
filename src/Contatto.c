#include "Contatto.h"

// * funzioni di lettura
Stringa leggi_nome_contatto(Contatto contatto)
{
    Stringa nome;
    nome = contatto.nome;

    return nome;
}

Stringa leggi_cognome_contatto(Contatto contatto)
{
    Stringa cognome;
    cognome = contatto.cognome;

    return cognome;
}

Stringa leggi_telefono_contatto(Contatto contatto)
{
    Stringa telefono;
    telefono = contatto.telefono;

    return telefono;
}

int leggi_stato_contatto(Contatto contatto)
{
    int stato;
    stato = contatto.stato;

    return stato;
}

// * funzioni di scrittura
void scrivi_nome_contatto(Contatto* contatto, Stringa nome)
{
    contatto->nome = nome;
}

void scrivi_cognome_contatto(Contatto* contatto, Stringa cognome)
{
    contatto->cognome = cognome;
}

void scrivi_telefono_contatto(Contatto* contatto, Stringa telefono)
{
    contatto->telefono = telefono;
}

void scrivi_stato_contatto(Contatto* contatto, int stato)
{
    contatto->stato = stato;
}

void stampa_contatto(Contatto contatto)
{
    printf("Nome: %s\n", leggi_stringa(leggi_nome_contatto(contatto)));
    printf("Cognome: %s\n", leggi_stringa(leggi_cognome_contatto(contatto)));
    printf("Telefono: %s\n", leggi_stringa(leggi_telefono_contatto(contatto)));
    printf("Stato: %s\n", leggi_stato_contatto(contatto) == 1 ? "Preferito" : (leggi_stato_contatto(contatto) == 2 ? "Bloccato" : "Predefinito"));
}