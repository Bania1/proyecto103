#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "recurso.h"
#include "curso.h"

void asignar_recursos(char *nF, int cod)
{
    FILE * fich = fopen(nF,"a");
    if(fich == NULL)
    {
        printf("ERROR AL ABRIR EL FICHERO\n");
        exit(-1);
    }

    struct curso c;
    struct recurso r;
    //id aulas camaras proyectores cont_aulas cont_camaras cont_proyecores
    while(fscanf(fich,"%d %d %d %d %d %d %d\n",c.id,)==7)
    {
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
