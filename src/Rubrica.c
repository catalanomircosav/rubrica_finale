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

    inputc(0, leggi_dim_rubrica(*rub), &pos, "Inserire la posizione del contatto da modificare: ", INTEGER);

    cont = leggi_contatto(*rub, pos);

    do
    {
        stampa_interfaccia(i);
        inputc(1, 5, &scelta, "Inserisci scelta: ", INTEGER);

        if (scelta == 1)
        {
            inputc(1, MAX_LUN_STRINGA, &aux, "Inserire nome: ", STRING);
            scrivi_nome_contatto(&cont, aux);
            scrivi_contatto(rub, pos, cont);
        }
        else if (scelta == 2)
        {
            inputc(1, MAX_LUN_STRINGA, &aux, "Inserire cognome: ", STRING);
            scrivi_cognome_contatto(&cont, aux);
            scrivi_contatto(rub, pos, cont);
        }
        else if (scelta == 3)
        {
            inputc(1, MAX_LUN_STRINGA, &aux, "Inserire telefono: ", STRING);
            scrivi_telefono_contatto(&cont, aux);
            scrivi_contatto(rub, pos, cont);
        }
        else if (scelta == 4)
        {
            inputc(0, 2, &val, "Inserire stato: ", INTEGER);
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
    inputc(0, leggi_dim_rubrica(*rub) - 1, &indice, "Inserisci la posizione del contatto da cancellare: ", INTEGER);

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
        printf("%d.\n", i);
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
void ordina_rubrica(Rubrica* rub)
{
    Interfaccia inter;
    inizializza_interfaccia(&inter, "interfaces\\ordina_rubrica.txt", 4);
    stampa_interfaccia(inter);

    int scelta;
    int risultato;

    inputc(1, 4, &scelta, "Inserisci scelta: ", INTEGER);

    if (scelta < 1 || scelta > 4) {
        printf("Scelta non valida.\n");
        return;
    }

    int ordinato;
    int dim = rub->dim;

    do {
        ordinato = 1;
        int i = 0;
        while (i < dim - 1) {
            Contatto contatto1 = rub->contatti[i];
            Contatto contatto2 = rub->contatti[i + 1];

            Stringa str1, str2;
            int comparison_result;

            if (scelta == 1 || scelta == 3) {
                str1 = leggi_nome_contatto(contatto1);
                str2 = leggi_nome_contatto(contatto2);
            }
            else {
                str1 = leggi_cognome_contatto(contatto1);
                str2 = leggi_cognome_contatto(contatto2);
            }

            if (scelta == 1 || scelta == 2) {
                risultato = strcmp(str1.buffer, str2.buffer);
            }
            else {
                risultato = strcmp(str2.buffer, str1.buffer);
            }

            if (risultato > 0) {
                rub->contatti[i] = contatto2;
                rub->contatti[i + 1] = contatto1;
                ordinato = 0;
            }

            i++;
        }
    } while (!ordinato);
}