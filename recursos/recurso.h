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

void asignar_recursos(char *nF,char *nF2,char *nF3,int cod);
int buscar_recurso(char *nF,int cod);
void modificar_recursos(char *nF1,char *nF2,int cod);
void eliminar_recurso(char *nF1,char *nF2,int cod);
void asignar_globales(char *nF);
void comprobar_existencias(char *nF1,char *nF2);

#endif