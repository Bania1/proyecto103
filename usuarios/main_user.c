#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        scanf("%d", &c);
        switch (c)
        {
            case 1: 
            //Menu del participante
                system("clear");
                
                int cont=0;
            
                while(cont < 3)
                {
                    printf("CORREO: "); scanf("%s", usern.email);
                    printf("CONTRASEÑA: "); scanf("%s", usern.password);
                    int comprobar = iniciar_sesion(nF1, usern);
                    if (comprobar == 0)
                    {
                        printf("\nERROR, INTENTELO DE NUEVO\n");
                        cont++;
                    }
                    else
                    {
                        cont=3;
                    }
                }
                menuPrincipal();
                system("clear");
                
                break;

            case 2:
            //Creamos la cuenta
                system("clear");

                menuParticipante();

                printf("CORREO: "); scanf("%s", usern.email);
                printf("CONTRASEÑA: "); scanf("%s", usern.password);

                crear_cuenta(nF1, usern);
                
                system("clear");
                menuPrincipal();

                break;

            case 3:
                system("clear");

            default:
                break;

        }
    }
    exit(0);
}