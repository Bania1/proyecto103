#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "recurso.h"
#include "curso.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Error, debe de introducir el nombre del fichero\n");
        exit(-1);
    }
    char *nF1 = argv[1];
    int cod;
   
    printf("Introduce el codigo del curso que desea\n");
    scanf("%d",&cod);

    //modificar_recursos(nF1,cod);

    //eliminar_recurso(nF1,cod);

    asignar_recursos(nF1,cod);
 
   return 0; 
}