#ifndef __FILE_H__
#define __FILE_H__

#include "Rubrica.h"

void esporta_rubrica_su_file(Rubrica rub, const char* nome_file);
Rubrica importa_contatto_da_file(const char* nome_file);

#endif // __FILE_H__