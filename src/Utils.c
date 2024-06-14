#include "Utils.h"

int inputc(int a, int b, void* valore, char* messaggio, DataType tipo)
{
    int corretto = 0;

    do
    {
        printf("%s", messaggio);

        if (tipo == INTEGER)
        {
            scanf("%d", (int*)valore);
        }
        else if (tipo == STRING)
        {
            char msg[MAX_LUN_STRINGA];
            // Pulisci il buffer per evitare letture precedenti
            memset(msg, 0, MAX_LUN_STRINGA);

            // Usa fgets per leggere l'intera linea
            fgets(msg, MAX_LUN_STRINGA, stdin);

            // Rimuovi il newline finale se presente
            size_t len = strlen(msg);
            if (len > 0 && msg[len - 1] == '\n') {
                msg[len - 1] = '\0';
            }

            // Passa il buffer alla funzione scrivi_stringa
            scrivi_stringa((Stringa*)valore, msg);
        }

    } while ((tipo == INTEGER && (*(int*)valore < a || *(int*)valore > b)) ||
        (tipo == STRING && (leggi_lun_stringa(*(Stringa*)valore) < a || leggi_lun_stringa(*(Stringa*)valore) > b)));

    fflush(stdin);

    corretto = 1;
    return corretto;
}

void  gotoxy(int x, int  y) {
    COORD CursorPos = { x, y };
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, CursorPos);
}