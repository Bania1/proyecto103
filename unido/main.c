#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funciones.h"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        printf("Error, debe de introducir el nombre del fichero\n");
        exit(-1);
    }
    char *fichUsuarios = argv[1];
    char *fichCursos = argv[2];
    char *fichInscripciones = argv[3];
    struct user usern;
    
    //Hacemos el menu
    system("clear");
    int c=0;
    while(c != 4)
    {
        menuPrincipal();
        scanf("%d", &c); printf("\n");
        switch (c)
        {
            case 1: 
            //Iniciar sesion
                system("clear");
                
                int cont=0;
            
                while(cont < 3)
                {
                    menu_iniciando_sesion();

                    printf("CORREO: "); scanf("%s", usern.email);
                    printf("CONTRASEÑA: "); scanf("%s", usern.password);

                    int sesion = iniciar_sesion(fichUsuarios, usern);
                    int comprobar1 = comprobar_correo(usern);

                    if(sesion == 0)
                    {
                        printf("\nERROR, INTENTELO DE NUEVO\n\n");
                        cont++;
                        sleep(1);
                        system("clear");
                    }
                    else if((sesion == 1) && (comprobar1) == 1) //Participante
                    {
                        cont=4;
                    }
                    else if ((sesion == 1) && (comprobar1) == 2) //Admin
                    {
                        cont=5;
                    }
                    else if ((sesion == 1) && (comprobar1 == 3)) //Coord. de cursos
                    {
                        cont=6;
                    }
                    else if ((sesion == 1) && (comprobar1 == 4)) //Coord. de recursos
                    {
                        cont=7;
                    }
                    
                }
                
                if(cont == 4) //Menu de usuario normal
                {
                    system("clear");
                    int op=0;
                    while (op != 4) //Menu cuando inicias sesion
                    {
                        menu_iniciado();
                        scanf("%d", &op); printf("\n");
                        switch (op)
                        {
                            case 1:
                                system("clear");
                                printf("SE HA EJECUTADO VER CURSOS\n");
                                sleep(2);
                                system("clear");
                                break;

                            case 2:
                                system("clear");
                                printf("SE HA EJECUTADO INSCRIBIRSE AL CURSO\n");
                                sleep(2);
                                system("clear");
                                break;
                            case 3:
                                system("clear");
                                printf("SE HA EJECUTADO BUSCAR CURSO\n");
                                sleep(2);
                                system("clear");
                                break;

                            default:
                                break;
                        }
                    }
                }

                else if (cont == 5) //Menu del admin
                {
                    system("clear");
                    int op3=0;
                    while (op3 != 16)
                    {
                        menu_admin();
                        scanf("%d", &op3); printf("\n");

                        switch (op3)
                        {
                        case 1:
                            system("clear");
                            printf("SE HA EJECUTADO VER CURSOS\n");
                            sleep(2);
                            system("clear");
                            break;

                        case 2:
                            system("clear");
                            printf("SE HA EJECUTADO INSCRIBIRSE AL CURSO\n");
                            sleep(2);
                            system("clear");

                        default:
                            break;
                        }
                    }
                    
                }
                
                else if (cont == 6) //Menu de coord. de cursos
                {
                    system("clear");
                    int op4=0;
                    while (op4 != 11)
                    {
                        menu_coordinador_cursos();
                        scanf("%d", &op4); printf("\n");

                        switch (op4)
                        {
                        case 1:
                            system("clear");
                            printf("SE HA EJECUTADO VER CURSOS\n");
                            sleep(2);
                            system("clear");
                            break;

                        case 2:
                            system("clear");
                            printf("SE HA EJECUTADO INSCRIBIRSE AL CURSO\n");
                            sleep(2);
                            system("clear");

                        default:
                            break;
                        }
                    }
                }
                
                else if (cont == 7) //Menu del coord. de recursos
                {
                    system("clear");
                    int op5=0;
                    while (op5 != 6)
                    {
                        menu_coordinador_recursos();
                        scanf("%d", &op5); printf("\n");

                        switch (op5)
                        {
                        case 1:
                            system("clear");
                            printf("SE HA EJECUTADO VER CURSOS\n");
                            sleep(2);
                            system("clear");
                            break;

                        case 2:
                            system("clear");
                            printf("SE HA EJECUTADO INSCRIBIRSE AL CURSO\n");
                            sleep(2);
                            system("clear");

                        default:
                            break;
                        }
                    }
                }
                
                
                system("clear");
                
                break;

            case 2:
            //Creamos la cuenta
                system("clear");

                menu_creando_usuario();
                
                int cont2=0;

                while(cont2 < 3)
                {
                    printf("CORREO: "); scanf("%s", usern.email);
                    printf("CONTRASEÑA: "); scanf("%s", usern.password);

                    int comprobar = comprobar_correo(usern);

                    if((comprobar == 0 ) || (comprobar == 2) || (comprobar == 3) || (comprobar == 4))
                    {
                        printf("\nCORREO NO VALIDO, TIENE QUE SER '@uco.es'\n\n");
                        cont2++;
                        sleep(2);
                        system("clear");
                        menu_creando_usuario();
                    }
                    else
                    {
                        crear_cuenta(fichUsuarios, usern);
                        cont2=3;
                    }
                }
                
                system("clear");
                
                break;

            case 3:
            //Se abre el menu modo visitante
                system("clear");
                int op2=0;

                while (op2 != 2)
                {
                    menu_visitante();
                    scanf("%d",&op2);

                    switch (op2)
                    {
                    case 1:
                        system("clear");
                        printf("SE HA EJECUTADO VER CURSOS\n");
                        sleep(2);
                        system("clear");
                        break;
                    
                    default:
                        break;
                    }
                }
                system("clear");

            default:
                break;

        }
    }
    exit(0);
}