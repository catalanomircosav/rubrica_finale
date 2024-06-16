#include "Rubrica.h"
#include "Utils.h"
#include "File.h"

#include <unistd.h>

int main(int argc, char** argv)
{
    Interfaccia inter;
    int scelta;

    Rubrica rub;
    scrivi_dim_rubrica(&rub, 0);

    inizializza_interfaccia(&inter, "interfaces\\principale.txt", 6);

    do
    {
        stampa_interfaccia(inter);

        inputc_int(1, 9, &scelta, "Inserisci scelta: ");
        if (scelta == 1)
        {
            scrivi_contatto(&rub, leggi_dim_rubrica(rub), inserisci_contatto());
            scrivi_dim_rubrica(&rub, leggi_dim_rubrica(rub) + 1);
        }
        else if (scelta == 2)
        {
            cancella_contatto(&rub);
        }
        else if (scelta == 3)
        {
            modifica_contatto(&rub);
        }
        else if (scelta == 4)
        {
            Rubrica aux;
            aux = ricerca_contatto(rub, inserisci_contatto());

            if (leggi_dim_rubrica(aux) > 0)
            {
                stampa_rubrica(aux);
            }
            else
            {
                printf("Contatto non trovato\n");
            }

            sleep(3);
        }
        else if (scelta == 5)
        {
            ordina_rubrica(&rub);
            stampa_rubrica(rub);
            sleep(3);
        }
        else if (scelta == 6)
        {
            stampa_rubrica(rub);
            sleep(3);
        }
        else if (scelta == 7)
        {
            rub = importa_contatto_da_file(".\\file\\rubrica.bin");
        }
        else if (scelta == 8)
        {
            esporta_rubrica_su_file(rub, ".\\file\\rubrica.bin");
        }

        system("cls");

    } while (scelta != 9);
    printf("Uscita...");

    system("pause");
    return 0;
}