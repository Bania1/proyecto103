#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef CURSO_H
#define CURSO_H

struct curso
{
    char nombre[200];
    int id,precio,aforo;
    char descripcion[200];
    //faltan las fechas
};
struct ponente
{
    char nombre[200];
};

void crear_curso(char *nF,int cod);
//void modificar_curso();
//void mostrar_curso();

#endif