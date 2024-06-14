#include "Rubrica.h"

// * funzioni di lettura
int leggi_dim_rubrica(Rubrica rub)
{
    int dim;
    dim = rub.dim;

    return dim;
}
Contatto leggi_contatto(Rubrica rub, int pos)
{
    Contatto cont;
    cont = rub.contatti[pos];

    return cont;
}

// * funzioni di scrittura
void scrivi_dim_rubrica(Rubrica* rub, int dim)
{
    rub->dim = dim;
}

void scrivi_contatto(Rubrica* rub, int pos, Contatto cont)
{
    rub->contatti[pos] = cont;
}

// * funzioni utili
void inserisci_contatto(Rubrica* rub)
{
    int var;

    int a;
    a = 1;

    int b;
    b = MAX_LUN_STRINGA;

    Interfaccia inserimento;
    Stringa str;

    Contatto aux;

    inizializza_interfaccia(&inserimento, "interfaces\\inserisci_contatto.txt", 0);

    system("cls");
    stampa_interfaccia(inserimento);

    gotoxy(20, 4);
    inputc(a, b, &str, "", STRING);
    scrivi_nome_contatto(&aux, str);

    gotoxy(23, 5);
    inputc(a, b, &str, "", STRING);
    scrivi_cognome_contatto(&aux, str);

    gotoxy(24, 6);
    inputc(a, b, &str, "", STRING);
    scrivi_telefono_contatto(&aux, str);

    scrivi_stato_contatto(&aux, 0);

    scrivi_contatto(rub, leggi_dim_rubrica(*rub), aux);
    scrivi_dim_rubrica(rub, leggi_dim_rubrica(*rub) + 1);
}
void modifica_contatto(Rubrica* rub)
{
    Interfaccia i;
    inizializza_interfaccia(&i, "interfaces\\modifica_contatto.txt", 5);

    int scelta;
    scelta = 0;

    int pos;
    pos = 0;

    int val;
    val = 0;

    Stringa aux;

    Contatto cont;

    int a;
    a = 1;

    int b;
    b = 5;

    int d;
    d = 5;

    inputc(a, b, &pos, "Inserire la posizione del contatto da modificare: ", INTEGER);

    cont = leggi_contatto(*rub, pos);

    do
    {
        stampa_interfaccia(i);
        inputc(a, d, &scelta, "Inserisci scelta: ", INTEGER);

        b = MAX_LUN_STRINGA;

        if (scelta == 1)
        {
            inputc(a, b, &aux, "Inserire nome: ", STRING);
            scrivi_nome_contatto(&cont, aux);
            scrivi_contatto(rub, pos - 1, cont);
        }
        else if (scelta == 2)
        {
            inputc(a, b, &aux, "Inserire cognome: ", STRING);
            scrivi_cognome_contatto(&cont, aux);
            scrivi_contatto(rub, pos - 1, cont);
        }
        else if (scelta == 3)
        {
            inputc(a, b, &aux, "Inserire telefono: ", STRING);
            scrivi_telefono_contatto(&cont, aux);
            scrivi_contatto(rub, pos - 1, cont);
        }
        else if (scelta == 4)
        {
            a = 0;
            b = 2;
            inputc(a, b, &val, "Inserire stato: ", INTEGER);
            scrivi_stato_contatto(&cont, val);
            scrivi_contatto(rub, pos - 1, cont);
        }
        else if (scelta == 5)
        {
            printf("Uscita dal menu' di modifica...");
            Sleep(2);
        }
    } while (scelta != 5);

    printf("Contatto modificato correttamente.");
}
void cancella_contatto(Rubrica* rub)
{
    int a;
    a = 1;

    int b;
    b = leggi_dim_rubrica(*rub);

    int pos;

    inputc(a, b, &pos, "inserisci la posizione del contatto da eliminare", INTEGER);

    while (pos - 1 < leggi_dim_rubrica(*rub))
    {
        scrivi_contatto(rub, pos - 1, leggi_contatto(*rub, pos));
        pos = pos + 1;
    }
    scrivi_dim_rubrica(rub, leggi_dim_rubrica(*rub) - 1);
}
void stampa_rubrica(Rubrica rub)
{
    int i;
    i = 0;
    while (i < leggi_dim_rubrica(rub))
    {
        stampa_contatto(leggi_contatto(rub, i));
        i = i + 1;
    }
}
Rubrica ricerca_contatto(Rubrica rub, Contatto cont)
{
    Rubrica aux;
    scrivi_dim_rubrica(&aux, 0);

    int i;
    i = 0;

    while (i < leggi_dim_rubrica(rub))
    {
        char* nome_rub = leggi_stringa(leggi_nome_contatto(leggi_contatto(rub, i)));
        char* cognome_rub = leggi_stringa(leggi_cognome_contatto(leggi_contatto(rub, i)));

        if (nome_rub && cognome_rub &&
            strcmp(nome_rub, leggi_stringa(leggi_nome_contatto(cont))) == 0 &&
            strcmp(cognome_rub, leggi_stringa(leggi_cognome_contatto(cont))) == 0)
        {
            scrivi_contatto(&aux, i, leggi_contatto(rub, i));
            scrivi_dim_rubrica(&aux, leggi_dim_rubrica(aux) + 1);
        }
        else
        {
            if (leggi_stringa(leggi_nome_contatto(cont)) != NULL)
            {
                if (strcmp(nome_rub, leggi_stringa(leggi_nome_contatto(cont))) == 0)
                {
                    scrivi_contatto(&aux, i, leggi_contatto(rub, i));
                    scrivi_dim_rubrica(&aux, leggi_dim_rubrica(aux) + 1);
                }
            }
            else if (leggi_stringa(leggi_cognome_contatto(cont)) != NULL)
            {
                if (strcmp(cognome_rub, leggi_stringa(leggi_cognome_contatto(cont))) == 0)
                {
                    scrivi_contatto(&aux, i, leggi_contatto(rub, i));
                    scrivi_dim_rubrica(&aux, leggi_dim_rubrica(aux) + 1);
                }
            }
        }
        i = i + 1;
    }
    return aux;
}

int confronto_nome(char* nome1, char* nome2)
{
    int risultato;

    risultato = strcmp(nome1, nome2);
    return risultato;
}

int confronto_cognome(char* cognome1, char* cognome2)
{
    int risultato;

    risultato = strcmp(cognome1, cognome2);
    return risultato;
}

void scambio(Contatto* cont1, Contatto* cont2)
{
    Contatto aux;
    aux = *cont1;
    *cont1 = *cont2;
    *cont2 = aux;
}

void ordina_rubrica(Rubrica* rub)
{
    Interfaccia inter;
    inizializza_interfaccia(&inter, ".\\interfaces\\ordina_rubrica.txt", 4);
    stampa_interfaccia(inter);

    int scelta;
    int risultato;

    risultato = inputc(1, 4, &scelta, "Inserisci scelta: ", 1);

    int sorted;
    int dim = rub->dim;

    if (risultato == 1) { // nome crescente
        do {
            sorted = 1;
            int i = 0;
            while (i < dim - 1) {
                Contatto contatto1 = rub->contatti[i];
                Contatto contatto2 = rub->contatti[i + 1];

                Stringa nome1 = leggi_nome_contatto(contatto1);
                Stringa nome2 = leggi_nome_contatto(contatto2);

                if (strcmp(nome1.buffer, nome2.buffer) > 0) {
                    rub->contatti[i] = contatto2;
                    rub->contatti[i + 1] = contatto1;
                    sorted = 0;
                }
                i++;
            }
        } while (!sorted);
    }
    else if (risultato == 2) { // cognome crescente
        do {
            sorted = 1;
            int i = 0;
            while (i < dim - 1) {
                Contatto contatto1 = rub->contatti[i];
                Contatto contatto2 = rub->contatti[i + 1];

                Stringa cognome1 = leggi_cognome_contatto(contatto1);
                Stringa cognome2 = leggi_cognome_contatto(contatto2);

                if (strcmp(cognome1.buffer, cognome2.buffer) > 0) {
                    rub->contatti[i] = contatto2;
                    rub->contatti[i + 1] = contatto1;
                    sorted = 0;
                }
                i++;
            }
        } while (!sorted);
    }
    else if (risultato == 3) { // nome decrescente
        do {
            sorted = 1;
            int i = 0;
            while (i < dim - 1) {
                Contatto contatto1 = rub->contatti[i];
                Contatto contatto2 = rub->contatti[i + 1];

                Stringa nome1 = leggi_nome_contatto(contatto1);
                Stringa nome2 = leggi_nome_contatto(contatto2);

                if (strcmp(nome1.buffer, nome2.buffer) < 0) {
                    rub->contatti[i] = contatto2;
                    rub->contatti[i + 1] = contatto1;
                    sorted = 0;
                }
                i++;
            }
        } while (!sorted);
    }
    else if (risultato == 4) { // cognome decrescente
        do {
            sorted = 1;
            int i = 0;
            while (i < dim - 1) {
                Contatto contatto1 = rub->contatti[i];
                Contatto contatto2 = rub->contatti[i + 1];

                Stringa cognome1 = leggi_cognome_contatto(contatto1);
                Stringa cognome2 = leggi_cognome_contatto(contatto2);

                if (strcmp(cognome1.buffer, cognome2.buffer) < 0) {
                    rub->contatti[i] = contatto2;
                    rub->contatti[i + 1] = contatto1;
                    sorted = 0;
                }
                i++;
            }
        } while (!sorted);
    }
}