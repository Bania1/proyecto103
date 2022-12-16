#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#ifndef FUNCIONES_H
#define FUNCIONES_H

struct user
{
    char email[200];
    char password[200];
};

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

//MENUS

void menuPrincipal();
void menu_iniciado();
void menu_visitante();
void menu_iniciando_sesion();
void menu_creando_usuario();
void menu_admin();
void menu_coordinador_cursos();
void menu_coordinador_recursos();

//FUNCIONES USUARIOS

int iniciar_sesion(char *nf, struct user datos);
void visualizar_informacion_usuarios(char *nf);
void crear_cuenta(char *nf, struct user usuario);
int comprobar_correo(struct user datos);
void usuarios_en_curso(char *nF, int cod);
int buscar_usuario(char *nF1, char *email);
void mostrar_usuario(char *nF1, char *email);
/*int inscribirse_al_curso();
int acceder_a_informacion();*/
/*int gestionar_recursos();
int crear_cursos();
int gestionar_permisos();
int modificar_curso();
int gestionar_plazas();*/


//FUNCIONES CURSOS

int crear_curso(char *nF,int cod);
int modificar_curso(char *nF,int cod);
void mostrar_curso(char *nF,int cod);
void mostrar_todos_cursos(char *nF);
int buscar_curso(char *nF,int cod);
int eliminar_curso(char *nF, int cod);
int comprobar_fecha(char *nF,int cod);
int inscribirse(char *nF1,char *nF2,int cod,char *usuario);
void ver_mis_cursos(char *nF1,char*nF2,char *usuario);
int comprobar_inscripcion(char *nF,int cod,char *usuario);
void mostrar_waitlist(char *nF,int cod);
#endif