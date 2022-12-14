#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "curso.h"

void crear_curso(char *nF,int cod)
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
    //scanf("%s",c.nombre);
    fgets(c.nombre,200,stdin);
    c.nombre[strlen(c.nombre)-1]='\0';
    fflush(stdin);

    printf("introduce la descipcion del curso con codigo %d\n",c.id);
    fgets(c.descripcion,200,stdin);
    c.descripcion[strlen(c.descripcion)-1]='\0';
    //scanf("%s",c.descripcion);
    fflush(stdin);  
    

    printf("introduce el precio del curso con codigo %d\n",c.id);
    scanf("%d",&c.precio);
    printf("introduce el aforo del curso con codigo %d\n",c.id);
    scanf("%d",&c.aforo);

    printf("introduce el nombre del primer ponente\n");
    scanf("%s",c.ponente1);
    //fgets(c.ponente1,200,stdin);
    //c.ponente1[strlen(c.ponente1)-1]='\0';
    //fflush(stdin);
    printf("introduce el nombre del segundo ponente\n");
    scanf("%s",c.ponente2);
    //fgets(c.ponente2,200,stdin);
    //c.ponente2[strlen(c.ponente2)-1]='\0';
    //fflush(stdin);

    fprintf(fich,"%s\n%s\n%d %d %d\n%s\n%s\n",c.nombre,c.descripcion,c.id,c.precio,c.aforo,c.ponente1,c.ponente2);

    fclose(fich);
}

void mostrar_curso(char *nF,int codigo)
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
        //fscanf("%s",c.ponente1);
        //fscanf("%s",c.ponente2);

        fgets(c.ponente1,200,fich);
        c.ponente1[strlen(c.ponente1)-1]='\0';
        fgets(c.ponente2,200,fich);
        c.ponente2[strlen(c.ponente2)-1]='\0';
        printf("-------------------------------------------------\n");
        printf("Curso: %s -------- Identidficador: [%d]\nDescripcion:\n%s\nPrecio: %d euros ----- Aforo:%d personas\nPonente 1: %s ----- Ponente 2: %s\n",c.nombre,c.id,c.descripcion,c.precio,c.aforo,c.ponente1,c.ponente2);
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
        //fscanf("%s",c.ponente1);
        //fscanf("%s",c.ponente2);

        fgets(c.ponente1,200,fich);
        c.ponente1[strlen(c.ponente1)-1]='\0';
        fgets(c.ponente2,200,fich);
        c.ponente2[strlen(c.ponente2)-1]='\0';

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

        if(buscar_curso(nF,cod)==0)
        {
            printf("Curso no existente\n");
            return  0;
        }

        if(c.id==cod)
        {
            printf("introduce el nuevo nombre del curso con codigo %d\n",cod);
            fgets(c.nombre,200,stdin);
            c.nombre[strlen(c.nombre)-1]='\0';
            fflush(stdin);

            printf("introduce la nueva descipcion del curso con codigo %d\n",cod);
            fgets(c.descripcion,200,stdin);
            c.descripcion[strlen(c.descripcion)-1]='\0';
            fflush(stdin);  
            

            printf("introduce el nuevo precio del curso con codigo %d\n",cod);
            scanf("%d",&c.precio);
            printf("introduce el nuevo aforo del curso con codigo %d\n",cod);
            scanf("%d",&c.aforo);

            printf("introduce el nuevo nombre del primer ponente\n");
            scanf("%s",c.ponente1);
            printf("introduce el nuevo nombre del segundo ponente\n");
            scanf("%s",c.ponente2);
        }   
    }
    fprintf(fich,"%s\n%s\n%d %d %d\n%s\n%s\n",c.nombre,c.descripcion,c.id,c.precio,c.aforo,c.ponente1,c.ponente2);
    fclose(fich);
    fclose(fich2);
    remove(nF);
    rename("auxf.txt",nF);
    return 1;
}