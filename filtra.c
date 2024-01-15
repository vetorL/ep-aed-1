#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool filtra(char *palavra)
{
    // Coloca todas as palavras em minusculo
    for (int i = 0; palavra[i]; i++)
    {
        palavra[i] = tolower(palavra[i]);
    }

    if (strcmp(palavra, "") == 0)
    {
        return true;
    }

    return false;
}