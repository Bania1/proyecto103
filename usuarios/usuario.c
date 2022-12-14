#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

void menuPrincipal()
{
    printf("----------------- MENU PRINCIPAL -----------------\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("1. INICIAR SESION.\n");
    printf("2. CREAR CUENTA.\n");
    printf("3. VISITANTE.\n");
    printf("4. SALIR\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\nINTRODUZCA EL NUMERO PARA ENTRAR EN LA OPCION QUE DESEE\n");
    printf("---->");

}

void menuParticipante()
{
    printf("\n----------------- PARTICIPANTE -----------------\n");
    printf("\n");
    printf("\n");
    printf("\n");
}

void crear_cuenta(char *nf, struct user usuario)
{
    FILE *fich = fopen(nf, "a");
    if (fich == NULL)
    {
        printf("Error en crear cuenta\n");
        exit(-1);
    }
    fprintf(fich, "%s %s\n", usuario.email, usuario.password);
    fclose(fich);
}

int iniciar_sesion(char *nf, struct user datos)
{
    FILE *fich = fopen(nf, "r");
    if (fich == NULL)
    {
        printf("Error en iniciar sesion\n");
        exit(-1);
    }
    struct user aux;

    while (fscanf(fich, "%s %s\n", aux.email, aux.password) == 2)
    {
        if ((strcmp(datos.email, aux.email) == 0) && (strcmp(datos.password, aux.password) == 0))
        {
            fclose(fich);
            return 1;
        }
    }
    fclose(fich);
    return 0;
}

void visualizar_informacion_usuarios(char *nf) //Falta añadir datos como el nombre y apellidos
{
    FILE *fich = fopen(nf, "r");
    if (fich == NULL)
    {
        printf("Error en iniciar sesion\n");
        exit(-1);
    }
    struct user aux;
    while (fscanf(fich, "%s %s\n", aux.email, aux.password))
    {
        printf("EL CORREO DEL USUARIO ES: %s\n", aux.email);
    }
    fclose(fich);
}