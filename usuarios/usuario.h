#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#ifndef USUARIO_H
#define USUARIO_H

struct user
{
    char email[200];
    char password[200];
};

void menuPrincipal();
void menu_iniciado();
void menu_visitante();
void menu_iniciando_sesion();
void menu_creando_usuario();
void menu_admin();
void menu_coordinador_cursos();

int iniciar_sesion(char *nf, struct user datos);
void visualizar_informacion_usuarios(char *nf);
void crear_cuenta(char *nf, struct user usuario);
int comprobar_correo(struct user datos);
/*int inscribirse_al_curso();
int acceder_a_informacion();*/
/*int gestionar_recursos();
int crear_cursos();
int gestionar_permisos();
int modificar_curso();
int gestionar_plazas();*/

#endif