#include "Rubrica.h"
#include "Utils.h"
#include <unistd.h>

int main(int argc, char** argv)
{
    Interfaccia inter;
    int scelta;

    Rubrica rub;
    scrivi_dim_rubrica(&rub, 0);

    int a;
    a = 1;

    int b;
    b = 6;

    inizializza_interfaccia(&inter, ".\\interfaces\\principale.txt", 6);

    do
    {
        stampa_interfaccia(inter);

        if (inputc(a, b, &scelta, "Inserisci scelta: ", INTEGER))
        {
            if (scelta == 1)
            {
                inserisci_contatto(&rub);
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
                Contatto cont;
                Stringa nome;
                Rubrica aux;

                scrivi_stringa(&nome, "Mirco");
                scrivi_nome_contatto(&cont, nome);

                aux = ricerca_contatto(rub, cont);
                if (leggi_dim_rubrica(aux) > 0)
                {
                    stampa_rubrica(aux);
                }
                else
                {
                    printf("Contatto non trovato\n");
                }

                Sleep(3);
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
                sleep(4);
            }
        }
        system("cls");

    } while (scelta != 7);
    printf("Uscita...");

    system("pause");
    return 0;
}