#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "recurso.h"
#include "curso.h"

int cont_clas = 0;
int cont_proy = 0;
int cont_cam = 0;
int max_clas = 15;
int max_proy = 20;
int max_cam = 20;

void asignar_globales(char *nF)
{
    
    FILE * fich = fopen(nF,"a");
    if(fich == NULL)
    {
        printf("ERROR AL ABRIR EL FICHERO\n");
        exit(-1);
    }
    fseek(fich,0,SEEK_END);

    if(ftell(fich) == 0)
    {
        fprintf(fich,"%d %d %d %d %d %d\n",cont_clas,cont_cam,cont_proy,max_clas,max_cam,max_proy);   
        fseek(fich,0,SEEK_SET);
    }
    else
    {
        fseek(fich,0,SEEK_SET);
    }
}

void asignar_recursos(char *nF,char *nF2,char *nF3,int cod)
{
    FILE * fich = fopen(nF,"r");
    if(fich == NULL)
    {
        printf("ERROR AL ABRIR EL FICHERO\n");
        exit(-1);
    }
    
    FILE *fich2=fopen(nF2,"a");
    if(fich2==NULL)
    {
        printf("ERROR AL ABRIR FICHERO\n");
        fclose(fich);
        exit(-1);
    }
    FILE *fich3=fopen(nF3,"r");
    printf("LLEGA2");
    if(fich3==NULL)
    {
        printf("ERROR AL ABRIR FICHERO\n");
        fclose(fich);
        exit(-1);
    }
    FILE *fich4=fopen("aux.txt","w");
    printf("LLEGA3");
    if(fich4==NULL)
    {
        printf("ERROR AL ABRIR FICHERO\n");
        fclose(fich);
        exit(-1);
    }

    struct curso c;
    struct recurso r;
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
            int asignado = buscar_recurso("recursos.txt",c.id);

            if(asignado == 1)
            {
                printf("ERROR-No es posible añadir recursos a un curso al que ya han sido asignados-> USE 'MODIFICAR RECURSOS'\n");
                exit(-1);
            }
            else
            {
                while(fscanf(fich3,"%d %d %d %d %d %d\n",&cont_clas,&cont_cam,&cont_proy,&max_clas,&max_cam,&max_proy) == 6)
                {
                    if(cont_clas < max_clas)
                    {
                        printf("INTRIDUCE EL NUMERO DE AULAS.QUEDAN DISPONIBLES: %d\n",(max_clas-cont_clas));
                        scanf("%d",&r.aulas);

                        while(r.aulas > (max_clas-cont_clas))
                        {
                            printf("ERROR->LA CANTIDAD DE AULAS SOLICITADA SUPERA LA CANTIDAD DE AULAS DISPONIBLES-VUELVA A INTRODUCIR UNA CANTIDAD:\n");
                            scanf("%d",&r.aulas);
                        }
                        while(r.aulas < 0 || r.aulas > (max_clas-cont_clas))
                        {
                            printf("ERROR-NO PUEDE SER SOLICITADA UNA CANTIDAD DE AULAS NEGATIVA-VUELVA A INTRODUCIR UNA CANTIDAD\n");
                            scanf("%d",&r.aulas);
                            if(r.aulas > (max_clas-cont_clas))
                            {
                                printf("ERROR-NO PUEDE AÑADIR\n");
                            }
                        }

                        cont_clas = cont_clas + r.aulas;
                    }
                    if(cont_cam < max_cam)
                    {
                        printf("INTRIDUCE EL NUMERO DE CAMARAS.QUEDAN DISPONIBLES: %d\n",(max_cam-cont_cam));
                        scanf("%d",&r.camaras);

                        while(r.camaras > (max_cam-cont_cam))
                        {
                            printf("ERROR->LA CANTIDAD DE CAMARAS SOLICITADA SUPERA LA CANTIDAD DE CAMARAS DISPONIBLES-VUELVA A INTRODUCIR UNA CANTIDAD:\n");
                            scanf("%d",&r.camaras);
                        }
                        while(r.camaras < 0 || r.camaras > (max_cam-cont_cam))
                        {
                            printf("ERROR-NO PUEDE SER SOLICITADA UNA CANTIDAD DE CAMARAS NEGATIVA-VUELVA A INTRODUCIR UNA CANTIDAD\n");
                            scanf("%d",&r.camaras);
                            if(r.camaras > (max_cam-cont_cam))
                            {
                                printf("ERROR\n");
                            }
                        }

                        cont_cam = cont_cam + r.camaras;
                    }
                    if(cont_proy < max_proy)
                    {
                        printf("INTRIDUCE EL NUMERO DE PROYECTORES.QUEDAN DISPONIBLES: %d\n",(max_proy-cont_proy));
                        scanf("%d",&r.proyectores);

                        while(r.proyectores > (max_proy-cont_proy))
                        {
                            printf("ERROR->LA CANTIDAD DE PROYECTORES SOLICITADA SUPERA LA CANTIDAD DE PROYECTORES DISPONIBLES-VUELVA A INTRODUCIR UNA CANTIDAD:\n");
                            scanf("%d",&r.proyectores);
                        }
                        while(r.proyectores < 0 || r.proyectores > (max_proy-cont_proy))
                        {
                            printf("ERROR-NO PUEDE SER SOLICITADA UNA CANTIDAD DE PROYECTORES NEGATIVA-VUELVA A INTRODUCIR UNA CANTIDAD\n");
                            scanf("%d",&r.proyectores);
                            if(r.proyectores > (max_proy-cont_proy))
                            {
                                printf("ERROR");
                            }
                        }

                        cont_proy = cont_proy + r.proyectores;
                    }
                    else
                    {
                        printf("ERROR->NO QUEDAN RECURSOS DISPONIBLES\n");
                        exit(-1);
                    }
                }
              
                  
                         
                         
                              

                   
            }
                
            fprintf(fich2,"%d %d %d %d\n",c.id,r.aulas,r.camaras,r.proyectores);
            fprintf(fich4,"%d %d %d %d %d %d\n",cont_clas,cont_cam,cont_proy,max_clas,max_cam,max_proy);    
        }

            


    }


    fclose(fich);
    fclose(fich2);
    fclose(fich3);
    fclose(fich4);
    remove(nF3);
    rename("aux.txt",nF3);

}



int buscar_recurso(char *nF,int cod)
{
    FILE *fich=fopen(nF,"r");
    if(fich==NULL)
    {
        printf("ERROR AL ABRIR EL FICHERO\n");
        exit(-1);
    }
    struct curso c;
    struct recurso r;
    fseek(fich,0,SEEK_END);

    if(ftell(fich) == 0)
    {

    }
    else
    {
        fseek(fich,0,SEEK_SET);

        while(fscanf(fich,"%d %d %d %d\n",&c.id,&r.aulas,&r.camaras,&r.proyectores) == 4)
        {
            if(c.id == cod)
            {
                return 1;
                fclose(fich);
            }

        }    
    }

    fclose(fich);
    return 0;
}
void modificar_recursos(char *nF1,char *nF2,int cod)
{
    FILE * fich = fopen(nF1,"r");
    if(fich == NULL)
    {
        printf("ERROR AL ABRIR EL FICHERO\n");
        exit(-1);
    }
    FILE *fich2=fopen("aux.txt","w");
    if(fich2==NULL)
    {
        printf("ERROR AL ABRIR FICHERO\n");
        fclose(fich);
        exit(-1);
    }
    FILE *fich3=fopen(nF2,"r");
    if(fich3==NULL)
    {
        printf("ERROR AL ABRIR FICHERO\n");
        fclose(fich3);
        exit(-1);
    }
    FILE *fich4=fopen("aux2.txt","w");
    if(fich4==NULL)
    {
        printf("ERROR AL ABRIR FICHERO\n");
        fclose(fich4);
        exit(-1);
    }

    struct curso c;
    struct recurso r;

        while(fscanf(fich,"%d %d %d %d\n",&c.id,&r.aulas,&r.camaras,&r.proyectores) == 4)
        {
            printf("LLEGO");
            int aux1 = r.aulas;
            int aux2 = r.camaras;
            int aux3 = r.proyectores;
            printf("%d",c.id);

            
            
            if(c.id == cod)
            {
                printf("LLEGO2");
                while(fscanf(fich3,"%d %d %d %d %d %d\n",&cont_clas,&cont_cam,&cont_proy,&max_clas,&max_cam,&max_proy) == 6)
                {
                    printf("LLEGO3");
                    printf("%d",cont_clas);
                    printf("%d",cont_cam);
                    printf("%d",cont_proy);
                    char tipo[50];
                    printf("Introduzca el tipo de recurso a reasignar\n");
                    printf("'Aula', 'Camara o 'Proyector'\n");
                    scanf("%s",tipo);
                    while(strcmp(tipo,"Aula") != 0 && strcmp(tipo,"Camara") != 0 && strcmp(tipo,"Proyector") != 0)
                    {
                        printf("ERROR-Debes introducir 'Aula','Camara' o 'Proyector'\n");
                        scanf("%s",tipo);

                    }
                    

                    if(strcmp(tipo,"Aula") == 0 && cont_clas < max_clas)
                    {
                        printf("%d",cont_clas);
                        printf("Introduce el numero de aulas que desea asignar->QUEDAN LIBRES:%d\n",(max_clas-cont_clas));
                        scanf("%d",&r.aulas);
                        
                        while(r.aulas > (max_clas-cont_clas))
                        {
                            printf("ERROR->LA CANTIDAD DE AULAS SOLICITADA SUPERA LA CANTIDAD DE AULAS DISPONIBLES-VUELVA A INTRODUCIR UNA CANTIDAD:\n");
                            scanf("%d",&r.aulas);
                        }
                        while(r.aulas < 0 || r.aulas > (max_clas-cont_clas))
                        {
                            printf("ERROR-NO PUEDE SER SOLICITADA UNA CANTIDAD DE AULAS NEGATIVA-VUELVA A INTRODUCIR UNA CANTIDAD\n");
                            scanf("%d",&r.aulas);
                            if(r.aulas > (max_clas-cont_clas))
                            {
                                printf("ERROR-NO PUEDE AÑADIR\n");
                            }
                        }

                        cont_clas = cont_clas + (r.aulas-aux1);

                    }
                    else if(strcmp(tipo,"Camara") == 0 && cont_cam < max_cam)
                    {
                        printf("Introduce el numero de aulas que desea asignar->QUEDAN LIBRES:%d\n",(max_cam-cont_cam));
                        scanf("%d",&r.camaras);
                        
                        while(r.camaras > (max_cam-cont_cam))
                        {
                            printf("ERROR->LA CANTIDAD DE AULAS SOLICITADA SUPERA LA CANTIDAD DE AULAS DISPONIBLES-VUELVA A INTRODUCIR UNA CANTIDAD:\n");
                            scanf("%d",&r.camaras);
                        }
                        while(r.camaras < 0 || r.camaras > (max_cam-cont_cam))
                        {
                            printf("ERROR-NO PUEDE SER SOLICITADA UNA CANTIDAD DE AULAS NEGATIVA-VUELVA A INTRODUCIR UNA CANTIDAD\n");
                            scanf("%d",&r.camaras);
                            if(r.camaras > (max_clas-cont_cam))
                            {
                                printf("ERROR-NO PUEDE AÑADIR\n");
                            }
                        cont_cam = cont_cam + (r.camaras-aux2);
                        }


                    }
                    else if(strcmp(tipo,"Proyector") == 0 && cont_proy < max_proy)
                    {
                        printf("Introduce el numero de aulas que desea asignar->QUEDAN LIBRES:%d\n",(max_proy-cont_proy));
                        scanf("%d",&r.proyectores);
                        
                        while(r.proyectores > (max_proy-cont_proy))
                        {
                            printf("ERROR->LA CANTIDAD DE AULAS SOLICITADA SUPERA LA CANTIDAD DE AULAS DISPONIBLES-VUELVA A INTRODUCIR UNA CANTIDAD:\n");
                            scanf("%d",&r.proyectores);
                        }
                        while(r.proyectores < 0 || r.proyectores > (max_proy-cont_proy))
                        {
                            printf("ERROR-NO PUEDE SER SOLICITADA UNA CANTIDAD DE AULAS NEGATIVA-VUELVA A INTRODUCIR UNA CANTIDAD\n");
                            scanf("%d",&r.proyectores);
                            if(r.proyectores > (max_proy-cont_proy))
                            {
                                printf("ERROR-NO PUEDE AÑADIR\n");
                            }
                        }

                        cont_proy = cont_proy + (r.proyectores-aux3);

                    }
                    else
                    {
                        printf("ERROR->NO QUEDAN RECURSOS DISPONIBLES\n");
                        exit(-1);
                    }
                    

                    fprintf(fich4,"%d %d %d %d %d %d\n",cont_clas,cont_cam,cont_proy,max_clas,max_cam,max_proy);

                    
                }


            }
            
            
            fprintf(fich2,"%d %d %d %d\n",c.id,r.aulas,r.camaras,r.proyectores);
            
           
        }                 

    
    fclose(fich);
    fclose(fich2);
    fclose(fich3);
    fclose(fich4);
    remove(nF1);
    remove(nF2);
    rename("aux.txt",nF1);
    rename("aux2.txt",nF2);
}

void eliminar_recurso(char *nF1,char *nF2,int cod)
{
    FILE * fich = fopen(nF1,"r");
    if(fich == NULL)
    {
        printf("ERROR AL ABRIR EL FICHERO\n");
        exit(-1);
    }

    FILE * fich2 = fopen("aux.txt","w");
    if(fich2 == NULL)
    {
        printf("ERROR AL ABRIR EL FICHERO\n");
        exit(-1);
    }

    FILE * fich3 = fopen(nF2,"r");
    if(fich3 == NULL)
    {
        printf("ERROR AL ABRIR EL FICHERO\n");
        exit(-1);
    }

    FILE * fich4 = fopen("aux2.txt","w");
    if(fich4 == NULL)
    {
        printf("ERROR AL ABRIR EL FICHERO\n");
        exit(-1);
    }    


    struct curso c;
    struct recurso r;


    while(fscanf(fich,"%d %d %d %d\n",&c.id,&r.aulas,&r.camaras,&r.proyectores) == 4)
    {
        if(c.id == cod)
        {
            while(fscanf(fich3,"%d %d %d %d %d %d\n",&cont_clas,&cont_cam,&cont_proy,&max_clas,&max_cam,&max_proy) == 6)
            {
                char tipo[50];
                printf("Introduzca el tipo de recurso a eliminar\n");
                printf("'Aula', 'Camara o 'Proyector'\n");
                scanf("%s",tipo);
                while(strcmp(tipo,"Aula") != 0 && strcmp(tipo,"Camara") != 0 && strcmp(tipo,"Proyector") != 0)
                {
                    printf("ERROR-Debes introducir 'Aula','Camara' o 'Proyector'\n");
                    scanf("%s",tipo);

                }

                if(strcmp(tipo,"Aula") == 0)
                {
                    cont_clas = cont_clas - r.aulas;
                    r.aulas = 0;
                }
                else if(strcmp(tipo,"Camara") == 0)
                {
                    cont_cam = cont_cam - r.camaras;
                    r.camaras = 0;
                }
                else if(strcmp(tipo,"Proyector") == 0)
                {
                    cont_proy = cont_proy - r.proyectores;
                    r.proyectores = 0;
                }

                fprintf(fich4,"%d %d %d %d %d %d\n",cont_clas,cont_cam,cont_proy,max_clas,max_cam,max_proy);

                    
            }
        }

        fprintf(fich2,"%d %d %d %d\n",c.id,r.aulas,r.camaras,r.proyectores);

    }

    fclose(fich);
    fclose(fich2);
    fclose(fich3);
    fclose(fich4);
    remove(nF1);
    remove(nF2);
    rename("aux.txt",nF1);
    rename("aux2.txt",nF2);
}

void comprobar_existencias(char *nF1,char *nF2)
{
    FILE * fich = fopen(nF1,"r");
    if(fich == NULL)
    {
        printf("ERROR AL ABRIR EL FICHERO\n");
        exit(-1);
    }

    FILE * fich2 = fopen(nF2,"r");
    if(fich2 == NULL)
    {
        printf("ERROR AL ABRIR EL FICHERO\n");
        exit(-1);
    }

    struct curso c;
    struct recurso r;

    while(fscanf(fich,"%d %d %d %d\n",&c.id,&r.aulas,&r.camaras,&r.proyectores) == 4)
    {
        while(fscanf(fich2,"%d %d %d %d %d %d\n",&cont_clas,&cont_cam,&cont_proy,&max_clas,&max_cam,&max_proy) == 6)
        {
            printf("AULAS DISPONIBLES: %d AULAS EN USO: %d\n",(max_clas-cont_clas),cont_clas);
            printf("\n");
            printf("CAMARAS DISPONIBLES: %d CAMARAS EN USO: %d\n",(max_cam-cont_cam),cont_cam);
            printf("\n");
            printf("PROYECTORES DISPONIBLES: %d PROYECTORES EN USO: %d\n",(max_proy-cont_proy),cont_proy);

        }
       
    }

    fclose(fich);
    fclose(fich2);

}