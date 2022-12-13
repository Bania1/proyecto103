#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

void crear_cuenta(char *nf, struct user usuario)
{
    FILE *fich = fopen(nf, "a");
    if (fich == NULL)
    {
        printf("Error en crear cuenta\n");
        exit(-1);
    }
    fprintf(fich, "%s\n%s\n", usuario.username, usuario.password);
    fclose(fich);
}