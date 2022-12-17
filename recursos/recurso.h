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

int total_clas = 30;

int total_cam = 50;

int total_proy = 40;

int cont_clas = 0;

int cont_cam = 0;

int cont_proy = 0;
//id camaras aulas proyectores   - - -



void asignar_recursos(char *nF,int cod);
int buscar_recurso(char *nF,int id);
void modificar_recursos(char *nF,int cod);
void eliminar_recurso(char *nF,int cod);


#endif