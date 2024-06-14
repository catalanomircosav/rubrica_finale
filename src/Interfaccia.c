#include "Interfaccia.h"

// * funzioni di lettura
char* leggi_percorso_file(Interfaccia interfaccia)
{
    char* percorso;
    percorso = interfaccia.percorso_file;

    return percorso;
}

int leggi_scelta_max(Interfaccia interfaccia)
{
    int max;
    max = interfaccia.scelta_max;

    return max;
}

// * funzioni di scrittura
void scrivi_percorso_file(Interfaccia* interfaccia, char* percorso)
{
    interfaccia->percorso_file = percorso;
}
void scrivi_scelta_max(Interfaccia* interfaccia, int max)
{
    interfaccia->scelta_max = max;
}

// * funzione di inizializzazione dell'interfaccia
void inizializza_interfaccia(Interfaccia* interfaccia, char* file, int scelta_max)
{
    scrivi_percorso_file(interfaccia, file);
    scrivi_scelta_max(interfaccia, scelta_max);
}

// * funzioni utili
void stampa_interfaccia(Interfaccia interfaccia)
{

    // ? per stampare caratteri unicode
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    char c;

    FILE* fp;

    const char* percorso;
    percorso = leggi_percorso_file(interfaccia);

    fp = fopen(percorso, "rb");

    if (!fp)
    {
        perror("Errore apertura file");
    }
    else
    {
        while ((c = fgetc(fp)) != EOF)
        {
            putchar(c);
        }
        fclose(fp);
    }

    printf("\n");
}