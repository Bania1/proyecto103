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
    printf("3. ACCEDER SIN INICIAR SESION.\n");
    printf("4. SALIR\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\nINTRODUZCA EL NUMERO PARA ENTRAR EN LA OPCION QUE DESEE\n");
    printf("---->");

}

void menu_iniciado()
{
    printf("\n----------------- CURSOS DE EXTENSION -----------------\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("1. VER CURSOS.\n");
    printf("2. INSCRIBIRSE A UN CURSO.\n");
    printf("3. BUSCAR CURSO.\n");
    printf("4. VOLVER.\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\nINTRODUZCA EL NUMERO PARA ENTRAR EN LA OPCION QUE DESEE\n");
    printf("---->");
}

void menu_admin()
{
    printf("\n----------------- CURSOS DE EXTENSION -----------------\n");
    printf("\n                    [ADMINISTRADOR]\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("1. VER CURSOS.\n");
    printf("2. INSCRIBIRSE A UN CURSO.\n");
    printf("3. CREAR CURSO.\n");
    printf("4. MODIFICAR CURSO.\n");
    printf("5. ELIMINAR CURSO.\n");
    printf("6. BUSCAR CURSO.\n");
    printf("7. ASIGNAR RECURSO.\n");
    printf("8. MODIFICAR RECURSO.\n");
    printf("9. ELIMINAR RECURSO.\n");
    printf("10. VISUALIZAR USUARIOS.\n");
    printf("11. MODIFICAR USUARIO.\n");
    printf("12. ELIMINAR USUARIO.\n");
    printf("13. AGREGAR USUARIO.\n");
    printf("14. BUSCAR USUARIO.\n");
    printf("15. ASIGNAR COORDINADOR.\n");
    printf("16. VOLVER.\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\nINTRODUZCA EL NUMERO PARA ENTRAR EN LA OPCION QUE DESEE\n");
    printf("---->");
}

void menu_coordinador_cursos()
{
    printf("\n----------------- CURSOS DE EXTENSION -----------------\n");
    printf("\n                [COORDINADOR DE CURSO]\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("1. VER CURSOS.\n");
    printf("2. INSCRIBIRSE A UN CURSO.\n");
    printf("3. CREAR CURSO.\n");
    printf("4. MODIFICAR CURSO.\n");
    printf("5. ELIMINAR CURSO.\n");
    printf("6. BUSCAR CURSO.\n");
    printf("7. VISUALIZAR USUARIOS.\n");
    printf("8. ELIMINAR USUARIO.\n");
    printf("9. AGREGAR USUARIO.\n");
    printf("10. BUSCAR USUARIO.\n");
    printf("11. VOLVER.\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\nINTRODUZCA EL NUMERO PARA ENTRAR EN LA OPCION QUE DESEE\n");
    printf("---->");
}

void menu_coordinador_recursos()
{
    printf("\n----------------- CURSOS DE EXTENSION -----------------\n");
    printf("\n               [COORDINADOR DE RECURSOS]\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("1. VER CURSOS.\n");
    printf("2. INSCRIBIRSE A UN CURSO.\n");
    printf("3. ASIGNAR RECURSOS.\n");
    printf("4. MODIFICAR RECURSOS.\n");
    printf("5. ELIMINAR RECURSOS\n");    
    printf("6. VOLVER.\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\nINTRODUZCA EL NUMERO PARA ENTRAR EN LA OPCION QUE DESEE\n");
    printf("---->");
}

void menu_creando_usuario()
{
    printf("\n----------------- CREANDO USUARIO -----------------\n");
    printf("\n");
    printf("\n");
    printf("\n");
}

void menu_iniciando_sesion()
{
    printf("\n----------------- INICIANDO SESION -----------------\n");
    printf("\n");
    printf("\n");
    printf("\n");
}

void menu_visitante()
{
    printf("\n----------------- CURSOS DE EXTENSION -----------------\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("1. VER CURSOS.\n");
    printf("2. VOLVER.\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\nINTRODUZCA EL NUMERO PARA ENTRAR EN LA OPCION QUE DESEE\n");
    printf("---->");
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
            return 1; //con exito
        }
    }
    fclose(fich);
    return 0; //sin exito
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

int comprobar_correo(struct user datos)
{
    char uco[10] = "@uco.es";
    char admin[10]= "@admin";
    char curso[10]= "@curso";
    char recurso[10]= "@recurso";

    if (strstr(datos.email, uco) != NULL)
    {
        return 1; //con exito
    }
    else if (strstr(datos.email, admin) != NULL)
    {
        return 2; //con exito admin
    }
    else if (strstr(datos.email, curso) != NULL)
    {
        return 3; //con exito cursos
    }
    else if (strstr(datos.email, recurso) != NULL)
    {
        return 4; //con exito recursos
    }
    else
    {
        return 0; //sin exito 
    }
}