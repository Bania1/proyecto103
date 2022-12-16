#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char **argv)
{
    char *nF=argv[1];

    if(crear_curso(nF,1)==1)
    {
        printf("bien\n");
    }
}