#include <stdio.h>
#include <ctype.h>

void filtra(char *palavra)
{
    // Coloca todas as palavras em minusculo
    for (int i = 0; palavra[i]; i++)
    {
        palavra[i] = tolower(palavra[i]);
    }
}