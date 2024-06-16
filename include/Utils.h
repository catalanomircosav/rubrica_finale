#ifndef __UTILS_H__
#define __UTILS_H__

#include "Stringa.h"

#ifdef _WIN32
#include <windows.h>
#endif

// ? Funzione utilizzato per controllare che l'input da utente sia corretto
void inputc_int(int a, int b, int* valore, char* messaggio);
void inputc_stringa(int a, int b, Stringa* valore, char* messaggio);
void inputc_char(int a, int b, char* valore, char* messaggio);

// ? Funzione utilizzata per spostare il cursore
void  gotoxy(int x, int  y);

#endif // __UTILS_H__