#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef RECURSO_H
#define RECURSO_H

struct recurso
{    
    int aulas;
    int camaras;
    int proyectores;
};

void asignar_recursos(char *nF,int cod);
int buscar_recurso(char *nF,int id);
void modificar_recursos(char *nF,int cod);
void eliminar_recurso(char *nF,int cod);


#endif