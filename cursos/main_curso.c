#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "curso.h"

int main(int argc, char **argv)
{
    if(argc!=2)
    {
        printf("numero de argumentos invalido\n");
        exit(-1);
    }
    char *nF=argv[1];   
    crear_curso(nF,1);
    printf("\n");

    return 0;
}