#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef USUARIO_H
#define USUARIO_H

struct user
{
    char username[200];
    char password[10];
};

/*int iniciar_sesion();
void visualizar_informacion();
int inscribirse_al_curso();
int acceder_a_informacion();*/
void crear_cuenta(char *nf, struct user usuario);
/*int gestionar_recursos();
int crear_cursos();
int gestionar_permisos();
int modificar_curso();
int gestionar_plazas();*/

#endif