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
    //mostrar_curso(nF,1); 
    //crear_curso(nF,1);
    /*if(buscar_curso(nF,1)==1)
    {
        printf("el curso existe\n");
    }
    else
    {
        printf("el curso no existe\n");
    }
    if(buscar_curso(nF,2)==1)
    {
        printf("el curso existe\n");
    }
    else
    {
        printf("el curso no existe\n");
    }
    printf("\n");*/
    if(modificar_curso(nF,1)==1)
    {
        printf("modificado cno exito\n");
    }
    else
    {
        printf("error al omdificar\n"); 
    }
    return 0;
}