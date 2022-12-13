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
    scanf("%s",c.nombre);

    printf("introduce la descipcion del curso con codigo %d\n",c.id);
    fgets(c.descripcion,200,stdout);
    c.descripcion[strlen(c.descripcion)-1]='\0';
    

    printf("introduce el precio del curso con codigo %d\n",c.id);
    scanf("%d",&c.precio);
    printf("introduce el aforo del curso con codigo %d\n",c.id);
    scanf("%d",&c.aforo);

    fprintf(fich,"%d %s %s %d %d ",c.id,c.nombre,c.descripcion,c.precio,c.aforo);

    printf("cuantos ponentes tiene el curso?\n");
    int n;
    scanf("%d",&n);
    struct ponente p[n];

    for(int i=0;i<n;i++)
    {
        printf("introduce el nombre del ponente numero %d \n",i);
        scanf("%s",p[i].nombre);
        fprintf(fich,"%s ",p[i].nombre);
    }
    fprintf(fich,"\n");

    fclose(fich);
}