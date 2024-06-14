#ifndef __STRINGA_H__
#define __STRINGA_H__

#define MAX_LUN_STRINGA 10

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Stringa
{
    int lun;
    char buffer[MAX_LUN_STRINGA];
} Stringa;

// * funzioni di lettura
int leggi_lun_stringa(Stringa stringa);
char* leggi_stringa(Stringa stringa);
char leggi_carattere(Stringa stringa, int pos);

// * funzioni di scrittura
void scrivi_lun_stringa(Stringa* stringa, int lun);
void scrivi_stringa(Stringa* stringa, char* buffer);
void scrivi_carattere(Stringa* stringa, int pos, char carattere);
#endif // __STRINGA_H__