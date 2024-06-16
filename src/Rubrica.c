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
Contatto inserisci_contatto()
{
    int var;

    Interfaccia inserimento;
    Stringa str;

    Contatto aux;

    inizializza_interfaccia(&inserimento, "interfaces\\inserisci_contatto.txt", 0);

    system("cls");
    stampa_interfaccia(inserimento);

    gotoxy(20, 4);
    inputc_stringa(1, MAX_LUN_STRINGA, &str, "");
    scrivi_nome_contatto(&aux, str);

    gotoxy(23, 5);
    inputc_stringa(1, MAX_LUN_STRINGA, &str, "");
    scrivi_cognome_contatto(&aux, str);

    gotoxy(24, 6);
    inputc_stringa(1, MAX_LUN_STRINGA, &str, "");
    scrivi_telefono_contatto(&aux, str);

    scrivi_stato_contatto(&aux, 0);

    return aux;
}
void modifica_contatto(Rubrica* rub)
{
    Interfaccia i;
    inizializza_interfaccia(&i, "interfaces\\modifica_contatto.txt", 5);

    int scelta;
    int pos;
    int val;

    Stringa aux;
    Contatto cont;

    inputc_int(0, leggi_dim_rubrica(*rub), &pos, "Inserire la posizione del contatto da modificare: ");

    cont = leggi_contatto(*rub, pos);

    do
    {
        stampa_interfaccia(i);
        inputc_int(1, 5, &scelta, "Inserisci scelta: ");

        if (scelta == 1)
        {
            inputc_stringa(1, MAX_LUN_STRINGA, &aux, "Inserire nome: ");
            printf("NUOVO NOME: %s", leggi_stringa(aux));
            scrivi_nome_contatto(&cont, aux);
            scrivi_contatto(rub, pos, cont);
        }
        else if (scelta == 2)
        {
            inputc_stringa(1, MAX_LUN_STRINGA, &aux, "Inserire cognome: ");
            scrivi_cognome_contatto(&cont, aux);
            scrivi_contatto(rub, pos, cont);
        }
        else if (scelta == 3)
        {
            inputc_stringa(1, MAX_LUN_STRINGA, &aux, "Inserire telefono: ");
            scrivi_telefono_contatto(&cont, aux);
            scrivi_contatto(rub, pos, cont);
        }
        else if (scelta == 4)
        {
            inputc_int(0, 2, &val, "Inserire stato: ");
            scrivi_stato_contatto(&cont, val);
            scrivi_contatto(rub, pos, cont);
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
    int indice;

    stampa_rubrica(*rub);
    inputc_int(0, leggi_dim_rubrica(*rub) - 1, &indice, "Inserisci la posizione del contatto da cancellare: ");

    while (indice < leggi_dim_rubrica(*rub))
    {
        scrivi_contatto(rub, indice, leggi_contatto(*rub, indice + 1));
        indice = indice + 1;
    }
    scrivi_dim_rubrica(rub, leggi_dim_rubrica(*rub) - 1);
}
void stampa_rubrica(Rubrica rub)
{
    int i;
    i = 0;

    while (i < leggi_dim_rubrica(rub))
    {
        printf("Contatto %d:\n", i);
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
            if (leggi_stringa(leggi_nome_contatto(cont)))
            {
                if (strcmp(nome_rub, leggi_stringa(leggi_nome_contatto(cont))) == 0)
                {
                    scrivi_contatto(&aux, i, leggi_contatto(rub, i));
                    scrivi_dim_rubrica(&aux, leggi_dim_rubrica(aux) + 1);
                }
            }
            else if (leggi_stringa(leggi_cognome_contatto(cont)))
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
void ordina_rubrica(Rubrica* rub)
{
    Interfaccia inter;

    int scelta;
    int i;

    int risultato;
    int ordinato;


    Contatto contatto1;
    Contatto contatto2;

    Stringa str1;
    Stringa str2;


    inizializza_interfaccia(&inter, "interfaces\\ordina_rubrica.txt", 4);
    stampa_interfaccia(inter);

    inputc_int(1, 5, &scelta, "Inserisci scelta: ");

    int dim;
    dim = leggi_dim_rubrica(*rub);
    do
    {
        do
        {
            ordinato = 1;

            i = 0;

            while (i < dim - 1) {
                contatto1 = leggi_contatto(*rub, i);
                contatto2 = leggi_contatto(*rub, i + 1);

                if (scelta == 1 || scelta == 3)
                {
                    str1 = leggi_nome_contatto(contatto1);
                    str2 = leggi_nome_contatto(contatto2);
                }
                else
                {
                    str1 = leggi_cognome_contatto(contatto1);
                    str2 = leggi_cognome_contatto(contatto2);
                }

                if (scelta == 1 || scelta == 2)
                {
                    risultato = strcmp(str1.buffer, str2.buffer);
                }
                else
                {
                    risultato = strcmp(str2.buffer, str1.buffer);
                }

                if (risultato > 0)
                {
                    scrivi_contatto(rub, i, contatto2);
                    scrivi_contatto(rub, i + 1, contatto1);
                    ordinato = 0;
                }

                i = i + 1;
            }
        } while (!ordinato);
    } while (scelta != 5);
}