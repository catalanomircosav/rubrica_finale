#include "Utils.h"

void inputc_int(int a, int b, int* valore, char* messaggio)
{
    do
    {
        printf("%s", messaggio);
        scanf("%d", valore);
        if (*valore < a || *valore > b)
        {
            printf("Valore intero non ammesso.\n");
        }
    } while (*valore < a || *valore > b);
}

void inputc_stringa(int a, int b, Stringa* stringa, char* messaggio)
{
    char buffer[b];
    do
    {
        printf("%s", messaggio);
        scanf("%s", buffer);


    } while (strlen(buffer) < a || strlen(buffer) > b);
    
    scrivi_stringa(stringa, buffer);
}

void inputc_char(int a, int b, char* valore, char* messaggio)
{
    do
    {
        printf("%s", messaggio);
        scanf("%c", valore);

        if (*valore < a || *valore > b)
        {
            printf("Valore carattere non ammesso.\n");
            fflush(stdin);
        }
    } while (*valore < a || *valore > b);
}

void  gotoxy(int x, int  y) {
    COORD CursorPos = { x, y };
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, CursorPos);
}