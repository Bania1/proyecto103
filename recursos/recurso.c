#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "recurso.h"
#include "curso.h"

void asignar_recursos(char *nF, int cod)
{
    FILE * fich = fopen(nF,"r");
    if(fich == NULL)
    {
        printf("ERROR AL ABRIR EL FICHERO\n");
        exit(-1);
    }
    FILE *fich2=fopen("recursos.txt","a");
    if(fich2==NULL)
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
                bool flagcontcam,flagcontaul,flagcontproy = false;

                while(flagcontaul == false)
                {
                    if(cont_clas < total_clas)
                    {
                        bool flag1 = false;
                        while(flag1 == false)
                        {
                            
                            printf("Introduce el numero de aulas que desea asignar--->QUEDAN LIBRES: %d\n",(total_clas-cont_clas));
                            scanf("%d",&r.aulas);
                            
                            While(r.aulas >(total_clas-cont_clas))
                            {
                                printf("LA CANTIDAD DE AULAS INTRODUCIDAS EXCEDE EL LIMITE\n");
                                scanf("%d",&r.aulas);
                            }
                            flag1 = true;
                            if(r.aulas < 0)
                            {
                                printf("ERROR->No puede ser asigando un numero negativo de aulas\n");
                                flag1 = false;
                            }
                        }

                        cont_clas = cont_clas + r.aulas;
                        flagcontaul = true;
                    }
                    else
                    {
                        printf("No quedan aulas libres para asignar\n");
                        flagcontaul = false;
                    }
                }
               
                    
                while(flagcontcam == false)
                    {
                        if(cont_cam < total_cam)
                        {
                            bool flag2 = false;

                            while(flag2 == false)
                            {
                                printf("INTRODUCE EL NUMERO DE AULAS QUE DESEA ASIGNAR->QUEDAN LIBRES: %d\n",total_cam);
                                scanf("%s",r.camaras);
                                flag2 = true;
                                if(r.camaras < 0)
                                {
                                    printf("ERROR->NO PUEDE SER ASIGNADO UN NUMERO NEGATIVO DE CAMARAS\n");
                                    flag2 = false;
                                }

                                
                            }

                            cont_cam++;
                            total_cam--;
                            flagcontcam = true;
                           
                        }
                        else
                        {
                            printf("No quedan camaras libres para asignar\n");
                            flagcontcam = false;
                        }
                        
                        
                    }    
                        

                while(flagcontproy == false)
                    {
                        
                            if(cont_proy < total_proy)
                            {
                                bool flag3 = false;
                                while(flag3 == false)
                                {
                                    printf("INTRODUCE EL NUMERO DE PROYECTORES QUE DESEEN ASIGNAR->QUEDAN LIBRES: %d\n");
                                    scanf("%s",r.proyectores);
                                    flag3 = true;

                                    if(r.proyectores < 0)
                                    {
                                        printf("ERROR-NO PUEDE SER ASIGNADO UN NUMERO NEGATIVO DE PROYECTORES\n");
                                        flag3 = false;
                                    }

                                    
                                    
                                }
                                cont_proy++;
                                total_proy--;
                                flagcontproy = true;
                                
                            }
                            else
                            {
                                printf("No quedan proyectores libres para asignar\n");
                                flagcontproy = false;
                            }
                           
                        
                       
                    }
                        

                   
                }
                
                fprintf(fich2,"%d %d %d %d\n",c.id,r.aulas,r.camaras,r.proyectores);    
            }

            


        }

       fclose(fich);
       fclose(fich2);
    }



int buscar_recurso(char *nF,int id)
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
        
            if(c.id == id)
            {
                return 1;
                fclose(fich);
            }

        }    
    }

    fclose(fich);
    return 0;
}
void modificar_recursos(char *nF,int cod)
{
    FILE * fich = fopen("recursos.txt","r");
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

    struct curso c;
    struct recurso r;

        while(fscanf(fich,"%d %d %d %d\n",&c.id,&r.aulas,&r.camaras,&r.proyectores) == 4)
        {

            if(c.id == cod)
            {
                bool flag=false;
                while(flag == false)
                {
                    char tipo[50];
                    printf("Introduzca el tipo de recurso a reasignar\n");
                    printf("'Aula', 'Camara o 'Proyector'\n");
                    scanf("%s",tipo);
                    flag = true;

                    if(strcmp(tipo, "Aula") == 0)
                        {
                            bool flag1 = false;
                            while(flag1 == false)
                            {
                                
                                printf("Introduce el numero de aulas que desea asignar--->MAXIMO 3\n");
                                scanf("%d",&r.aulas);
                                flag1 = true;
                                if(r.aulas > 3)
                                {
                                    printf("ERROR->Solo pueden ser asignadas un máximo de 3 aulas por curso\n");
                                    flag1 = false;
                                }
                                else if(r.aulas < 0)
                                {
                                    printf("ERROR->No puede ser asigando un numero negativo de aulas\n");
                                    flag1 = false;
                                }
                            }
                            

                        }
                        else if(strcmp(tipo,"Camara") == 0)
                        {
                            bool flag2 = false;
                            while(flag2 == false)
                            {
                            
                                printf("Introduce el numero de camaras que desea asignar--->MAXIMO 40\n");
                                scanf("%d",&r.camaras);
                                flag2 = true;
                                if(r.camaras > 40)
                                {
                                    printf("ERROR->Solo pueden ser asignadas un máximo de 40 camaras por curso\n");
                                    flag2 = false;
                                }
                                else if(r.camaras < 0)
                                {
                                    printf("ERROR->No puede ser asigando un numero negativo de camaras\n");
                                    flag2 = false;
                                }
                            }
                            

                        }
                        else if(strcmp(tipo,"Proyector") == 0)
                        {
                            bool flag3 = false;
                            while(flag3 == false)
                            {
                                printf("Introduce el numero de proyectores que desea asignar--->MAXIMO 20\n");
                                scanf("%d",&r.proyectores);
                                flag3 = true;
                                if(r.proyectores > 20)
                                {
                                    printf("ERROR->Solo puede ser asignadas un máximo de 20 proyectores por curso\n");
                                    flag3 = false;
                                }
                                else if(r.proyectores < 0)
                                {
                                    printf("ERROR->No puede ser asigando un numero negativo de proyectores\n");
                                    flag3 = false;
                                }
                            }
                            

                        }
                        else
                        {
                            printf("ERROR-Debes introducir 'Aula','Camara' o 'Proyector'\n");
                            flag = false;
                        }
            }
           
         }                 

        fprintf(fich2,"%d %d %d %d\n",c.id,r.aulas,r.camaras,r.proyectores);
    }

    fclose(fich);
    fclose(fich2);
    remove("recursos.txt");
    rename("aux.txt","recursos.txt");
}

void eliminar_recurso(char *nF,int cod)
{
    FILE * fich = fopen("recursos.txt","r");
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

    struct curso c;
    struct recurso r;

    while(fscanf(fich,"%d %d %d %d\n",&c.id,&r.aulas,&r.camaras,&r.proyectores) == 4)
    {
        if(c.id == cod)
        {
            bool flag = false;

            while(flag == false)
            {
                char tipo[50];
                printf("Introduzca el tipo de recurso a eliminar\n");
                printf("'Aula', 'Camara' o 'Proyector'\n");
                scanf("%s",tipo);
                flag = true;
            
                if(strcmp("Aula",tipo) == 0)
                {
                    r.aulas = 0;
                }
                else if(strcmp("Camara",tipo) == 0)
                {
                    r.camaras = 0;
                }
                else if(strcmp("Proyectores",tipo) == 0)
                {
                    r.proyectores = 0;
                }
                else
                {
                    printf("ERROR-Debes introducir 'Aula','Camara' o 'Proyector'\n");
                    flag = false;
                }
            }
 

        }

        fprintf(fich2,"%d %d %d %d\n",c.id,r.aulas,r.camaras,r.proyectores);

    }

    fclose(fich);
    fclose(fich2);
    remove("recursos.txt");
    rename("aux.txt","recursos.txt");    

}