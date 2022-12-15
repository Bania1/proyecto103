#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifndef CURSO_H
#define CURSO_H


struct curso
{
    char nombre[200];
    int id,precio,aforo;
    char descripcion[200];
    char ponente1[200];
    char ponente2[200];
    int dia_inicio,dia_final,mes_inicio,mes_final,anio_inicio,anio_final;
    int inscritos;
};


int crear_curso(char *nF,int cod);
int modificar_curso(char *nF,int cod);
void mostrar_curso(char *nF,int cod);
void mostrar_todos_cursos(char *nF);
int buscar_curso(char *nF,int cod);
int eliminar_curso(char *nF, int cod);
int comprobar_fecha(char *nF,int cod);
int inscribirse(char *nF1,char *nF2,int cod,char *usuario);
int comprobar_inscripcion();

#endif