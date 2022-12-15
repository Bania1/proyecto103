#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "curso.h"

int crear_curso(char *nF,int cod)
{
    FILE *fich=fopen(nF,"a");
    if(fich==NULL)
    {
        printf("error al abrir el archivo\n");
        exit(-1);
    }
    struct curso c;
    c.id=cod;

    printf("introduce el nombre del curso con codigo %d\n",c.id);
    fgets(c.nombre,200,stdin);
    c.nombre[strlen(c.nombre)-1]='\0';
    fflush(stdin);

    printf("introduce la descipcion del curso con codigo %d\n",c.id);
    fgets(c.descripcion,200,stdin);
    c.descripcion[strlen(c.descripcion)-1]='\0';
    fflush(stdin);  

    printf("introduce el nombre del primer ponente\n");
    fgets(c.ponente1,200,stdin);
    c.ponente1[strlen(c.ponente1)-1]='\0';

    printf("introduce el nombre del segundo ponente\n");
    fgets(c.ponente2,200,stdin);
    c.ponente2[strlen(c.ponente2)-1]='\0';

    printf("introduce el precio del curso con codigo %d\n",c.id);
    scanf("%d",&c.precio);
    printf("introduce el aforo del curso con codigo %d\n",c.id);
    scanf("%d",&c.aforo);

    printf("introduce el primer dia del curso\n");
    scanf("%d",&c.dia_inicio);
    if((c.dia_inicio<1)||(c.dia_inicio>31))
    {
        fclose(fich);
        return 0;//error
    }
    printf("introduce el mes de inicio del curso\n");
    scanf("%d",&c.mes_inicio);
    if((c.mes_inicio<1)||(c.mes_inicio>12))
    {
        fclose(fich);
        return 0;//error
    }
    printf("introduce el anio de inicio\n");
    scanf("%d",&c.anio_inicio);
    if(c.anio_inicio<2022)
    {
        fclose(fich);
        return 0;//error
    }
    printf("introduce el ultimo dia del curso\n");
    scanf("%d",&c.dia_final);
    if((c.dia_final<1)||(c.dia_final>31))
    {
        fclose(fich);
        return 0;//error
    }
    printf("introduce el mes de finalizacion\n");
    scanf("%d",&c.mes_final);
    if((c.mes_final<1)||(c.mes_final>12))
    {
        fclose(fich);
        return 0;//error
    }
    printf("introduce el anio de finalizacion\n");
    scanf("%d",&c.anio_final);
    if(c.anio_final<c.anio_inicio)
    {
        fclose(fich);
        return 0;//error
    }

    fprintf(fich,"%s\n%s\n%d %d %d\n%s\n%s\n%d %d %d\n%d %d %d\n",c.nombre,c.descripcion,c.id,c.precio,c.aforo,c.ponente1,c.ponente2,c.dia_inicio,c.mes_inicio,c.anio_inicio,c.dia_final,c.mes_final,c.anio_final);

    fclose(fich);
    return 1;//exito
}

void mostrar_curso(char *nF,int cod)
{
    FILE *fich=fopen(nF,"r");
    if(fich==NULL)
    {
        printf("error al abrir el archivo\n");
        exit(-1);
    }
    struct curso c;

    while(fgets(c.nombre,200,fich))
    {
        c.nombre[strlen(c.nombre)-1]='\0';

        fgets(c.descripcion,200,fich);
        c.descripcion[strlen(c.descripcion)-1]='\0';

        fscanf(fich,"%d %d %d\n",&c.id,&c.precio,&c.aforo);

        fgets(c.ponente1,200,fich);
        c.ponente1[strlen(c.ponente1)-1]='\0';
        fgets(c.ponente2,200,fich);
        c.ponente2[strlen(c.ponente2)-1]='\0';

        fscanf(fich,"%d %d %d\n",&c.dia_inicio,&c.mes_inicio,&c.anio_inicio);
        fscanf(fich,"%d %d %d\n",&c.dia_final,&c.mes_final,&c.anio_final);

        if(c.id==cod)
        {
            printf("-------------------------------------------------\n");
            printf("Curso: %s -------- Identidficador: [%d]\nDescripcion:\n%s\nPrecio: %d euros ----- Aforo: %d personas\nPonente 1: %s ----- Ponente 2: %s\n",c.nombre,c.id,c.descripcion,c.precio,c.aforo,c.ponente1,c.ponente2);
            printf("fecha de inicio--> %d del %d del %d -- fecha de finalizacion--> %d del %d del %d\n",c.dia_inicio,c.mes_inicio,c.anio_inicio,c.dia_final,c.mes_final,c.anio_final);
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
        printf("error al abrir el archivo\n");
        exit(-1);
    }
    struct curso c;

    while(fgets(c.nombre,200,fich))
    {
        c.nombre[strlen(c.nombre)-1]='\0';

        fgets(c.descripcion,200,fich);
        c.descripcion[strlen(c.descripcion)-1]='\0';

        fscanf(fich,"%d %d %d\n",&c.id,&c.precio,&c.aforo);

        fgets(c.ponente1,200,fich);
        c.ponente1[strlen(c.ponente1)-1]='\0';
        fgets(c.ponente2,200,fich);
        c.ponente2[strlen(c.ponente2)-1]='\0';

        fscanf(fich,"%d %d %d\n",&c.dia_inicio,&c.mes_inicio,&c.anio_inicio);
        fscanf(fich,"%d %d %d\n",&c.dia_final,&c.mes_final,&c.anio_final);

        printf("-------------------------------------------------\n");
        printf("Curso: %s -------- Identidficador: [%d]\nDescripcion:\n%s\nPrecio: %d euros ----- Aforo: %d personas\nPonente 1: %s ----- Ponente 2: %s\n",c.nombre,c.id,c.descripcion,c.precio,c.aforo,c.ponente1,c.ponente2);
        printf("fecha de inicio--> %d del %d del %d -- fecha de finalizacion--> %d del %d del %d\n",c.dia_inicio,c.mes_inicio,c.anio_inicio,c.dia_final,c.mes_final,c.anio_final);
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

        fscanf(fich,"%d %d %d\n",&c.id,&c.precio,&c.aforo);

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
        printf("error al abrir el archivo\n");
        exit(-1);
    }
    FILE *fich2=fopen("auxf.txt","w");
    if(fich2==NULL)
    {
        printf("error al abrir el archivo\n");
        fclose(fich);
        exit(-1);
    }

    struct curso c;

    while(fgets(c.nombre,200,fich))
    {
        c.nombre[strlen(c.nombre)-1]='\0';

        fgets(c.descripcion,200,fich);
        c.descripcion[strlen(c.descripcion)-1]='\0';

        fscanf(fich,"%d %d %d\n",&c.id,&c.precio,&c.aforo);

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

            printf("introduce la nueva descipcion del curso %s con codigo %d\n",c.nombre,cod);
            fgets(c.descripcion,200,stdin);
            c.descripcion[strlen(c.descripcion)-1]='\0';
            fflush(stdin);  
            
            printf("introduce el nombre del primer ponente del curso %s\n",c.nombre);
            fgets(c.ponente1,200,stdin);
            c.ponente1[strlen(c.ponente1)-1]='\0';

            printf("introduce el nombre del segundo ponente del curso %s\n",c.nombre);
            fgets(c.ponente2,200,stdin);
            c.ponente2[strlen(c.ponente2)-1]='\0';

            printf("introduce el nuevo precio del curso %s con codigo %d\n",c.nombre,cod);
            scanf("%d",&c.precio);
            printf("introduce el nuevo aforo del curso %s con codigo %d\n",c.nombre,cod);
            scanf("%d",&c.aforo);

            printf("introduce el primer dia del curso\n");
            scanf("%d",&c.dia_inicio);
            if((c.dia_inicio<1)||(c.dia_inicio>31))
            {
                fclose(fich);
                fclose(fich2);
                remove("auxf.txt");
                return 0;//error
            }
            printf("introduce el mes de inicio del curso\n");
            scanf("%d",&c.mes_inicio);
            if((c.mes_inicio<1)||(c.mes_inicio>12))
            {
                fclose(fich);
                fclose(fich2);
                remove("auxf.txt");
                return 0;//error
            }
            printf("introduce el anio de inicio\n");
            scanf("%d",&c.anio_inicio);
            if(c.anio_inicio<2022)
            {
                fclose(fich);
                fclose(fich2);
                remove("auxf.txt");
                return 0;//error
            }
            printf("introduce el ultimo dia del curso\n");
            scanf("%d",&c.dia_final);
            if((c.dia_final<1)||(c.dia_final>31))
            {
                fclose(fich);
                fclose(fich2);
                remove("auxf.txt");
                return 0;//error
            }
            printf("introduce el mes de finalizacion\n");
            scanf("%d",&c.mes_final);
            if((c.mes_final<1)||(c.mes_final>12))
            {
                fclose(fich);
                fclose(fich2);
                remove("auxf.txt");
                return 0;//error
            }
            printf("introduce el anio de finalizacion\n");
            scanf("%d",&c.anio_final);
            if(c.anio_final<c.anio_inicio)
            {
                fclose(fich);
                fclose(fich2);
                remove("auxf.txt");
                return 0;//error
            }
        }   
        fprintf(fich2,"%s\n%s\n%d %d %d\n%s\n%s\n%d %d %d\n%d %d %d\n",c.nombre,c.descripcion,c.id,c.precio,c.aforo,c.ponente1,c.ponente2,c.dia_inicio,c.mes_inicio,c.anio_inicio,c.dia_final,c.mes_final,c.anio_final);
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
        printf("error al abrir el archivo\n");
        exit(-1);
    }
    FILE *fich2=fopen("auxf.txt","w");
    if(fich2==NULL)
    {
        printf("error al abrir el archivo\n");
        fclose(fich);
        exit(-1);
    }

    struct curso c;

    while(fgets(c.nombre,200,fich))
    {
        c.nombre[strlen(c.nombre)-1]='\0';

        fgets(c.descripcion,200,fich);
        c.descripcion[strlen(c.descripcion)-1]='\0';

        fscanf(fich,"%d %d %d\n",&c.id,&c.precio,&c.aforo);

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
            fprintf(fich2,"%s\n%s\n%d %d %d\n%s\n%s\n%d %d %d\n%d %d %d\n",c.nombre,c.descripcion,c.id,c.precio,c.aforo,c.ponente1,c.ponente2,c.dia_inicio,c.mes_inicio,c.anio_inicio,c.dia_final,c.mes_final,c.anio_final);
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
    printf("hoy es %d del %d del %d\n",day,month,year);

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

        fscanf(fich,"%d %d %d\n",&c.id,&c.precio,&c.aforo);

        fgets(c.ponente1,200,fich);
        c.ponente1[strlen(c.ponente1)-1]='\0';
        fgets(c.ponente2,200,fich);
        c.ponente2[strlen(c.ponente2)-1]='\0';

        fscanf(fich,"%d %d %d\n",&c.dia_inicio,&c.mes_inicio,&c.anio_inicio);
        fscanf(fich,"%d %d %d\n",&c.dia_final,&c.mes_final,&c.anio_final);

        if(c.id==cod)
        {
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
