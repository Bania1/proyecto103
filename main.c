#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios/usuario.h"

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
    int c;
    //c = menu();
    
    while(c != 4)
    {
        c = menu();
        switch (c)
        {
        case 1: 
        //Menu del participante
            system("clear");
            
            //menuPartipante();
            
            int cont=0;
            
            printf("CORREO: "); scanf("%s", usern.email);
            printf("CONTRASEÑA: "); scanf("%s", usern.password);

            int comprobar = iniciar_sesion(nF1, usern);

            if (comprobar != 1)
            {
                printf("Error, intentelo de nuevo\n");
                cont++;
            }
            else
            {
                system("clear");
                return menu();
            }

            break;

        case 2:
        //Creamos la cuenta
            system("clear");

            menuPartipante();

            printf("CORREO: "); scanf("%s", usern.email);
            printf("CONTRASEÑA: "); scanf("%s", usern.password);

            crear_cuenta(nF1, usern);
            
            system("clear");
            return menu();

            break;

        case 3:
            system("clear");

        default:
            break;
        }
    }

    
}