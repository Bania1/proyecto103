#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "usuario.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Error, debe de introducir el nombre del fichero\n");
        exit(-1);
    }
    char *nF1 = argv[1];
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

                    int sesion = iniciar_sesion(nF1, usern);
                    int comprobar1 = comprobar_correo(usern);

                    if ((sesion == 0) && (comprobar1 == 0))
                    {
                        printf("\nERROR, INTENTELO DE NUEVO\n\n");
                        cont++;
                        sleep(1);
                        system("clear");
                    }
                    else
                    {
                        cont=4;
                    }
                }
                
                if(cont == 4)
                {
                    system("clear");
                    int op=0;
                    while (op != 3) //Menu cuando inicias sesion
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

                    if(comprobar == 0)
                    {
                        printf("\nCORREO NO VALIDO, TIENE QUE SER '@uco.es'\n\n");
                        cont2++;
                        sleep(1);
                        system("clear");
                        menu_creando_usuario();
                    }
                    else
                    {
                        crear_cuenta(nF1, usern);
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