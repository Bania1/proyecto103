#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef USUARIO_H
#define USUARIO_H

struct user
{
    char email[200];
    char password[200];
};


int iniciar_sesion(char *nf, struct user datos);
void visualizar_informacion_usuarios(char *nf);
/*int inscribirse_al_curso();
int acceder_a_informacion();*/
//void crear_cuenta(char *nf, struct user usuario);
/*int gestionar_recursos();
int crear_cursos();
int gestionar_permisos();
int modificar_curso();
int gestionar_plazas();*/

#endif