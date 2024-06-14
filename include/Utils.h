#ifndef __UTILS_H__
#define __UTILS_H__

#include "Stringa.h"

#ifdef _WIN32
#include <windows.h>
#endif

typedef enum {
    INTEGER,
    STRING
} DataType;

// ? Funzione utilizzato per controllare che l'input da utente sia corretto
int inputc(int a, int b, void* valore, char* messaggio, DataType tipo);

// ? Funzione utilizzata per spostare il cursore
void  gotoxy(int x, int  y);

#endif // __UTILS_H__