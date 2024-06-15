#include "File.h"

void esporta_rubrica_su_file(Rubrica rub, const char* nome_file)
{
    int i;
    i = 0;

    FILE* fp;
    fp = fopen(nome_file, "wb+");

    Contatto cont;

    if (!fp)
    {
        perror("Impossibile aprire il file");
    }
    else
    {
        while (i < leggi_dim_rubrica(rub))
        {
            cont = leggi_contatto(rub, i);
            fwrite(&cont, sizeof(Contatto), 1, fp);

            i = i + 1;
        }
    }
    fclose(fp);
}

Rubrica importa_contatto_da_file(const char* nome_file) {
    Rubrica rub;
    FILE* fp = fopen(nome_file, "rb+");

    if (!fp) {
        perror("Impossibile aprire il file");
    }

    Contatto cont;

    int dim;
    dim = 0;

    while (fread(&cont, sizeof(Contatto), 1, fp) == 1) {
        if (strcmp(leggi_stringa(leggi_nome_contatto(cont)), "") != 0)
        {
            scrivi_contatto(&rub, dim, cont);
            dim = dim + 1;
            scrivi_dim_rubrica(&rub, dim);
        }
    }

    fclose(fp);

    return rub;
}
