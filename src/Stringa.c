#include "Stringa.h"

// *funzioni di lettura
int leggi_lun_stringa(Stringa stringa)
{
    int lun;
    lun = stringa.lun;

    return lun;
}

char* leggi_stringa(Stringa stringa)
{
    // Alloca memoria sufficiente per la stringa inclusa la terminazione null
    char* str = (char*)malloc((leggi_lun_stringa(stringa) + 1) * sizeof(char));
    if (str != NULL)
    {
        strcpy(str, stringa.buffer);
    }

    return str;
}


char leggi_carattere(Stringa stringa, int pos)
{
    char car;
    car = stringa.buffer[pos];

    return car;
}

// * funzioni di scrittura
void scrivi_lun_stringa(Stringa* stringa, int lun)
{
    stringa->lun = lun;
}

/* void scrivi_stringa(Stringa* stringa, char* buffer)
{
    if (!(strlen(buffer) >= MAX_LUN_STRINGA))
    {
        strncpy(stringa->buffer, buffer, MAX_LUN_STRINGA - 1);
        scrivi_carattere(stringa->buffer, MAX_LUN_STRINGA - 1, '\0');

        scrivi_lun_stringa(stringa, strlen(stringa->buffer));
    }
} */

void scrivi_stringa(Stringa* stringa, char* buffer)
{
    // Controllo della lunghezza del buffer per prevenire buffer overflow
    if (strlen(buffer) < MAX_LUN_STRINGA)
    {
        // Copia sicura del buffer nella struttura
        strncpy(stringa->buffer, buffer, MAX_LUN_STRINGA - 1);
        stringa->buffer[MAX_LUN_STRINGA - 1] = '\0'; // Null-terminate il buffer

        // Aggiornamento della lunghezza della stringa
        stringa->lun = strlen(stringa->buffer);
    }
    else
    {
        printf("Debug: Stringa non valida...\n");
    }
}
void scrivi_carattere(Stringa* stringa, int pos, char carattere)
{
    stringa->buffer[pos] = carattere;
    scrivi_lun_stringa(stringa, leggi_lun_stringa(*stringa) + 1);
}