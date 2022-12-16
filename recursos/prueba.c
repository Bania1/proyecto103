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