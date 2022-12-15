#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int crear_curso(char *nF,int cod)
{
    FILE *fich=fopen(nF,"a");
    if(fich==NULL)
    {
        printf("ERROR AL ABRIR FICHERO\n");
        exit(-1);
    }
    struct curso c;
    c.id=cod;

    printf("INTRODUCE EL NOMBRE DEL CURSO CON CODIGO %d\n",c.id);
    fgets(c.nombre,200,stdin);
    c.nombre[strlen(c.nombre)-1]='\0';
    fflush(stdin);

    printf("INTRODUCE LA DESCRIPCION DEL CURSO CON CODIGO %d\n",c.id);
    fgets(c.descripcion,200,stdin);
    c.descripcion[strlen(c.descripcion)-1]='\0';
    fflush(stdin);  

    printf("INTRODUCE EL NOMBRE DEL PRIMER PONENTE\n");
    fgets(c.ponente1,200,stdin);
    c.ponente1[strlen(c.ponente1)-1]='\0';

    printf("INTRODUCE EL NOMBRE DEL SEGUNDO PONENTE\n");
    fgets(c.ponente2,200,stdin);
    c.ponente2[strlen(c.ponente2)-1]='\0';

    printf("INTRODUCE EL PRECIO DEL CURSO CON CODIGO %d\n",c.id);
    scanf("%d",&c.precio);
    printf("INTRODUCE EL AFORO DEL CURSO CON CODIGO %d\n",c.id);
    scanf("%d",&c.aforo);

    printf("INTRODUCE EL DIA DE INICIO DEL CURSO\n");
    scanf("%d",&c.dia_inicio);
    if((c.dia_inicio<1)||(c.dia_inicio>31))
    {
        fclose(fich);
        return 0;//error
    }
    printf("INTRODUCE EL MES DE INICIO DEL CURSO\n");
    scanf("%d",&c.mes_inicio);
    if((c.mes_inicio<1)||(c.mes_inicio>12))
    {
        fclose(fich);
        return 0;//error
    }
    printf("INTRODUCE EL AÑO DE INICIO DEL CURSO\n");
    scanf("%d",&c.anio_inicio);
    if(c.anio_inicio<2022)
    {
        fclose(fich);
        return 0;//error
    }
    printf("INTRODUCE EL DIA DE FINALIZACION DEL CURSO\n");
    scanf("%d",&c.dia_final);
    if((c.dia_final<1)||(c.dia_final>31))
    {
        fclose(fich);
        return 0;//error
    }
    printf("INTRODUCE EL MES DE FINALIZACION DEL CURSO\n");
    scanf("%d",&c.mes_final);
    if((c.mes_final<1)||(c.mes_final>12))
    {
        fclose(fich);
        return 0;//error
    }
    printf("INTRODUCE EL AÑO DE FINALIZACION DEL CURSO\n");
    scanf("%d",&c.anio_final);
    if(c.anio_final<c.anio_inicio)
    {
        fclose(fich);
        return 0;//error
    }

    c.inscritos=0;

    fprintf(fich,"%s\n%s\n%d %d %d %d\n%s\n%s\n%d %d %d\n%d %d %d\n",c.nombre,c.descripcion,c.id,c.precio,c.aforo,c.inscritos,c.ponente1,c.ponente2,c.dia_inicio,c.mes_inicio,c.anio_inicio,c.dia_final,c.mes_final,c.anio_final);

    fclose(fich);
    return 1;//exito
}

void mostrar_curso(char *nF,int cod)
{
    FILE *fich=fopen(nF,"r");
    if(fich==NULL)
    {
        printf("ERROR AL ABRIR EL FI\n");
        exit(-1);
    }
    struct curso c;

    while(fgets(c.nombre,200,fich))
    {
        c.nombre[strlen(c.nombre)-1]='\0';

        fgets(c.descripcion,200,fich);
        c.descripcion[strlen(c.descripcion)-1]='\0';

        fscanf(fich,"%d %d %d %d\n",&c.id,&c.precio,&c.aforo,&c.inscritos);

        fgets(c.ponente1,200,fich);
        c.ponente1[strlen(c.ponente1)-1]='\0';
        fgets(c.ponente2,200,fich);
        c.ponente2[strlen(c.ponente2)-1]='\0';

        fscanf(fich,"%d %d %d\n",&c.dia_inicio,&c.mes_inicio,&c.anio_inicio);
        fscanf(fich,"%d %d %d\n",&c.dia_final,&c.mes_final,&c.anio_final);

        if(c.id==cod)
        {
            printf("-------------------------------------------------\n");
            printf("CURSO: %s -------- IDENTIFICADOR: [%d]\nDESCRIPCION:\n%s\nPRECIO: %d EUROS ----- AFORO: %d PERSONAS\nPONENTE 1: %s ----- PONENTE 2: %s\n",c.nombre,c.id,c.descripcion,c.precio,c.aforo,c.ponente1,c.ponente2);
            printf("FECHA DE INICIO --> %d DEL %d DEL %d -- FECHA DE FINALIZACION --> %d DEL %d DEL %d\n",c.dia_inicio,c.mes_inicio,c.anio_inicio,c.dia_final,c.mes_final,c.anio_final);
            printf("-------------------------------------------------\n");
        }
    }
    fclose(fich);
}

void mostrar_todos_cursos(char *nF)
{
    FILE *fich=fopen(nF,"r");
    if(fich==NULL)
    {
        printf("ERROR AL ABRIR FICHERO\n");
        exit(-1);
    }
    struct curso c;

    while(fgets(c.nombre,200,fich))
    {
        c.nombre[strlen(c.nombre)-1]='\0';

        fgets(c.descripcion,200,fich);
        c.descripcion[strlen(c.descripcion)-1]='\0';

        fscanf(fich,"%d %d %d %d\n",&c.id,&c.precio,&c.aforo,&c.inscritos);

        fgets(c.ponente1,200,fich);
        c.ponente1[strlen(c.ponente1)-1]='\0';
        fgets(c.ponente2,200,fich);
        c.ponente2[strlen(c.ponente2)-1]='\0';

        fscanf(fich,"%d %d %d\n",&c.dia_inicio,&c.mes_inicio,&c.anio_inicio);
        fscanf(fich,"%d %d %d\n",&c.dia_final,&c.mes_final,&c.anio_final);

        printf("-------------------------------------------------\n");
        printf("CURSO: %s -------- IDENTIFICADOR: [%d]\nDESCRIPCION:\n%s\nPRECIO: %d EUROS ----- AFORO: %d PERSONAS\nPONENTE 1: %s ----- PONENTE 2: %s\n",c.nombre,c.id,c.descripcion,c.precio,c.aforo,c.ponente1,c.ponente2);
        printf("FECHA DE INICIO --> %d DEL %d DEL %d -- FECHA DE FINALIZACION --> %d DEL %d DEL %d\n",c.dia_inicio,c.mes_inicio,c.anio_inicio,c.dia_final,c.mes_final,c.anio_final);
        printf("-------------------------------------------------\n");
    }
    fclose(fich);
}

int buscar_curso(char *nF,int cod)
{
    FILE *fich=fopen(nF,"r");
    if(fich==NULL)
    {
        printf("error\n");
        exit(-1);
    }
    struct curso c;
    while(fgets(c.nombre,200,fich))
    {
        c.nombre[strlen(c.nombre)-1]='\0';

        fgets(c.descripcion,200,fich);
        c.descripcion[strlen(c.descripcion)-1]='\0';

        fscanf(fich,"%d %d %d %d\n",&c.id,&c.precio,&c.aforo,&c.inscritos);

        fgets(c.ponente1,200,fich);
        c.ponente1[strlen(c.ponente1)-1]='\0';
        fgets(c.ponente2,200,fich);
        c.ponente2[strlen(c.ponente2)-1]='\0';

        fscanf(fich,"%d %d %d\n",&c.dia_inicio,&c.mes_inicio,&c.anio_inicio);
        fscanf(fich,"%d %d %d\n",&c.dia_final,&c.mes_final,&c.anio_final);

        if(cod==c.id)
        {
            fclose(fich);
            return 1;
        }   
    }
    fclose(fich);
    return 0;
}

int modificar_curso(char *nF,int cod)
{
    FILE *fich=fopen(nF,"r");
    if(fich==NULL)
    {
        printf("ERROR AL ABRIR FICHERO\n");
        exit(-1);
    }
    FILE *fich2=fopen("auxf.txt","w");
    if(fich2==NULL)
    {
        printf("ERROR AL ABRIR FICHERO\n");
        fclose(fich);
        exit(-1);
    }

    struct curso c;

    while(fgets(c.nombre,200,fich))
    {
        c.nombre[strlen(c.nombre)-1]='\0';

        fgets(c.descripcion,200,fich);
        c.descripcion[strlen(c.descripcion)-1]='\0';

        fscanf(fich,"%d %d %d %d\n",&c.id,&c.precio,&c.aforo,&c.inscritos);

        fgets(c.ponente1,200,fich);
        c.ponente1[strlen(c.ponente1)-1]='\0';
        fgets(c.ponente2,200,fich);
        c.ponente2[strlen(c.ponente2)-1]='\0';

        fscanf(fich,"%d %d %d\n",&c.dia_inicio,&c.mes_inicio,&c.anio_inicio);
        fscanf(fich,"%d %d %d\n",&c.dia_final,&c.mes_final,&c.anio_final);

        if(buscar_curso(nF,cod)==0)
        {
            //printf("Curso no existente\n");
            fclose(fich);
            fclose(fich2);
            remove("auxf.txt");
            return 0;//error
        }

        if(c.id==cod)
        {
            /*printf("introduce el nuevo nombre del curso con codigo %d\n",cod);
            fgets(c.nombre,200,stdin);
            c.nombre[strlen(c.nombre)-1]='\0';
            fflush(stdin);*/

            printf("INTRODUCE LA NUEVA DESCRIPCION DEL CURSO %s con codigo %d\n",c.nombre,cod);
            fgets(c.descripcion,200,stdin);
            c.descripcion[strlen(c.descripcion)-1]='\0';
            fflush(stdin);  
            
            printf("INTRODUCE EL NOMBRE DEL PRIMER PONENTE DEL CURSO %s\n",c.nombre);
            fgets(c.ponente1,200,stdin);
            c.ponente1[strlen(c.ponente1)-1]='\0';

            printf("INTRODUCE EL NOMBRE DEL SEGUNDO PONENTE DEL CURSO %s\n",c.nombre);
            fgets(c.ponente2,200,stdin);
            c.ponente2[strlen(c.ponente2)-1]='\0';

            printf("INTRODUCE EL NUEVO PRECIO DEL CURSO %s CON CODIGO %d\n",c.nombre,cod);
            scanf("%d",&c.precio);
            printf("INTRODUCE EL NUEVO AFORO DEL CURSO %s CON CODIGO %d\n",c.nombre,cod);
            scanf("%d",&c.aforo);

            printf("INTRODUCE EL PRIMER DIA DEL CURSO\n");
            scanf("%d",&c.dia_inicio);
            if((c.dia_inicio<1)||(c.dia_inicio>31))
            {
                fclose(fich);
                fclose(fich2);
                remove("auxf.txt");
                return 0;//error
            }
            printf("INTRODUCE EL MES DE INICIO DEL CURSO\n");
            scanf("%d",&c.mes_inicio);
            if((c.mes_inicio<1)||(c.mes_inicio>12))
            {
                fclose(fich);
                fclose(fich2);
                remove("auxf.txt");
                return 0;//error
            }
            printf("INTRODUCE EL AÑO DE INICIO DEL CURSO\n");
            scanf("%d",&c.anio_inicio);
            if(c.anio_inicio<2022)
            {
                fclose(fich);
                fclose(fich2);
                remove("auxf.txt");
                return 0;//error
            }
            printf("INTRODUCE EL DIA DE FINALIZACION\n");
            scanf("%d",&c.dia_final);
            if((c.dia_final<1)||(c.dia_final>31))
            {
                fclose(fich);
                fclose(fich2);
                remove("auxf.txt");
                return 0;//error
            }
            printf("INTRODUCE EL MES DE FINALIZACION\n");
            scanf("%d",&c.mes_final);
            if((c.mes_final<1)||(c.mes_final>12))
            {
                fclose(fich);
                fclose(fich2);
                remove("auxf.txt");
                return 0;//error
            }
            printf("INTRODUCE EL AÑO DE FINALIZACION\n");
            scanf("%d",&c.anio_final);
            if(c.anio_final<c.anio_inicio)
            {
                fclose(fich);
                fclose(fich2);
                remove("auxf.txt");
                return 0;//error
            }
        }   
        fprintf(fich2,"%s\n%s\n%d %d %d %d\n%s\n%s\n%d %d %d\n%d %d %d\n",c.nombre,c.descripcion,c.id,c.precio,c.aforo,c.inscritos,c.ponente1,c.ponente2,c.dia_inicio,c.mes_inicio,c.anio_inicio,c.dia_final,c.mes_final,c.anio_final);
    }
    
    fclose(fich);
    fclose(fich2);
    remove(nF);
    rename("auxf.txt",nF);
    return 1;
}

int eliminar_curso(char *nF, int cod)
{
    FILE *fich=fopen(nF,"r");
    if(fich==NULL)
    {
        printf("ERROR AL ABRIR FICHERO\n");
        exit(-1);
    }
    FILE *fich2=fopen("auxf.txt","w");
    if(fich2==NULL)
    {
        printf("ERROR AL ABRIR FICHERO\n");
        fclose(fich);
        exit(-1);
    }

    struct curso c;

    while(fgets(c.nombre,200,fich))
    {
        c.nombre[strlen(c.nombre)-1]='\0';

        fgets(c.descripcion,200,fich);
        c.descripcion[strlen(c.descripcion)-1]='\0';

        fscanf(fich,"%d %d %d %d\n",&c.id,&c.precio,&c.aforo,&c.inscritos);

        fgets(c.ponente1,200,fich);
        c.ponente1[strlen(c.ponente1)-1]='\0';
        fgets(c.ponente2,200,fich);
        c.ponente2[strlen(c.ponente2)-1]='\0';

        fscanf(fich,"%d %d %d\n",&c.dia_inicio,&c.mes_inicio,&c.anio_inicio);
        fscanf(fich,"%d %d %d\n",&c.dia_final,&c.mes_final,&c.anio_final);

        if(buscar_curso(nF,cod)==0)
        {
            //printf("Curso no existente\n");
            return  0;
        }

        if(c.id!=cod)
        {
            fprintf(fich2,"%s\n%s\n%d %d %d %d\n%s\n%s\n%d %d %d\n%d %d %d\n",c.nombre,c.descripcion,c.id,c.precio,c.aforo,c.inscritos,c.ponente1,c.ponente2,c.dia_inicio,c.mes_inicio,c.anio_inicio,c.dia_final,c.mes_final,c.anio_final);
        }   
    }
    
    fclose(fich);
    fclose(fich2);
    remove(nF);
    rename("auxf.txt",nF);
    return 1;
}

int comprobar_fecha(char *nF,int cod)//0=no ha empezado el curso, 1=ha emezado el curso
{
    int day, month, year;
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    day = local->tm_mday; 
    month = local->tm_mon + 1;
    year = local->tm_year + 1900;   
    printf("DIA ACTUAL: %d/%d/%d\n",day,month,year);

    FILE *fich=fopen(nF,"r");
    if(fich==NULL)
    {
        printf("error\n");
        exit(-1);
    }
    struct curso c;
    while(fgets(c.nombre,200,fich))
    {
        c.nombre[strlen(c.nombre)-1]='\0';

        fgets(c.descripcion,200,fich);
        c.descripcion[strlen(c.descripcion)-1]='\0';

        fscanf(fich,"%d %d %d %d\n",&c.id,&c.precio,&c.aforo,&c.inscritos);

        fgets(c.ponente1,200,fich);
        c.ponente1[strlen(c.ponente1)-1]='\0';
        fgets(c.ponente2,200,fich);
        c.ponente2[strlen(c.ponente2)-1]='\0';

        fscanf(fich,"%d %d %d\n",&c.dia_inicio,&c.mes_inicio,&c.anio_inicio);
        fscanf(fich,"%d %d %d\n",&c.dia_final,&c.mes_final,&c.anio_final);

        if(c.id==cod)
        {
            printf("COMIENZO DEL CURSO: %d/%d/%d\n",c.dia_inicio,c.mes_inicio,c.anio_inicio);
            printf("FIN DEL CURSO: %d/%d/%d\n",c.dia_final,c.mes_final,c.anio_final);
            if(year>c.anio_inicio)
            {
                fclose(fich);
                return 1;
            }
            else if(year==c.anio_inicio)
            {
                if(month>c.mes_inicio)
                {
                    fclose(fich);
                    return 1;
                }
                else if(month==c.mes_inicio)
                {
                    if(day>=c.dia_inicio)
                    {
                        fclose(fich);
                        return 1;
                    }
                }
            }
            fclose(fich);
            return 0;
        } 
    }
}

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
    printf("4. VER MIS CURSOS.\n");
    printf("5. VOLVER.\n");
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
    while (fscanf(fich, "%s %s\n", aux.email, aux.password)== 2)    {
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

int inscribirse(char *nF1,char *nF2,int cod,char *usuario)
{
    FILE *fichCursos=fopen(nF1,"r");
    if(fichCursos==NULL)
    {
        printf("ERROR AL ABRIR FICHERO\n");
        exit(-1);
    }
    FILE *fichAux=fopen("aux.txt","w");
    if(fichCursos==NULL)
    {
        printf("ERROR AL ABRIR FICHERO\n");
        fclose(fichCursos);
        exit(-1);
    }
    FILE *fichIscripciones=fopen(nF2,"a");
    if(fichIscripciones==NULL)
    {
        printf("ERROR AL ABRIR FICHERO\n");
        fclose(fichCursos);
        fclose(fichAux);
        remove("aux.txt");
        exit(-1);
    }

    struct curso c;

    while(fgets(c.nombre,200,fichCursos))
    {
        c.nombre[strlen(c.nombre)-1]='\0';

        fgets(c.descripcion,200,fichCursos);
        c.descripcion[strlen(c.descripcion)-1]='\0';

        fscanf(fichCursos,"%d %d %d %d\n",&c.id,&c.precio,&c.aforo,&c.inscritos);

        fgets(c.ponente1,200,fichCursos);
        c.ponente1[strlen(c.ponente1)-1]='\0';
        fgets(c.ponente2,200,fichCursos);
        c.ponente2[strlen(c.ponente2)-1]='\0';

        fscanf(fichCursos,"%d %d %d\n",&c.dia_inicio,&c.mes_inicio,&c.anio_inicio);
        fscanf(fichCursos,"%d %d %d\n",&c.dia_final,&c.mes_final,&c.anio_final);

        if(c.id==cod)
        {
            if(c.inscritos<c.aforo)
            {
                c.inscritos++;
                fprintf(fichIscripciones,"%d %s\n",cod,usuario);
            }
            /*else if(c.inscritos>=c.aforo)
            {
                llamada a la funcion de waitlist
                fclose(fichCursos);
                fclose(fichIscripciones);
                return 0;
            }*/
        }
        fprintf(fichAux,"%s\n%s\n%d %d %d %d\n%s\n%s\n%d %d %d\n%d %d %d\n",c.nombre,c.descripcion,c.id,c.precio,c.aforo,c.inscritos,c.ponente1,c.ponente2,c.dia_inicio,c.mes_inicio,c.anio_inicio,c.dia_final,c.mes_final,c.anio_final);
    }
    fclose(fichCursos);
    fclose(fichIscripciones);
    fclose(fichAux);
    remove(nF1);
    rename("aux.txt",nF1);
    return 1;
}

void usuarios_en_curso(char *nF,int cod)
{
    FILE *fichInscripciones=fopen(nF, "r");
    if(fichInscripciones == NULL)
    {
        printf("ERROR EN ABRIR EL FICHERO\n");
        exit(-1);
    }
    struct user u;
    struct curso c;
    while(fscanf(fichInscripciones,"%d %s\n",&c.id,u.email) == 2)
    {
        if (cod == c.id)
        {
            printf("\nUSUARIO: %s\n", u.email);
        }
    }
    fclose(fichInscripciones);
}

void ver_mis_cursos(char *nF1,char*nF2,char *usuario)
{
    FILE *fichInscripciones=fopen(nF1, "r");
    if(fichInscripciones == NULL)
    {
        printf("ERROR EN ABRIR EL FICHERO\n");
        exit(-1);
    }
    FILE *fichCursos=fopen(nF2, "r");
    if(fichCursos == NULL)
    {
        printf("ERROR EN ABRIR EL FICHERO\n");
        fclose(fichInscripciones);
        exit(-1);
    }
    int id;
    char *email;

    while(fscanf(fichInscripciones,"%d %s\n",&id,email) == 2)
    {
        if (strcmp(usuario,email)==0)
        {
            mostrar_curso(nF2,id);
        }
    }
    fclose(fichCursos);
    fclose(fichInscripciones);
}





