#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

int menu()
{
    printf("----------------- MENU PRINCIPAL -----------------\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("1. INICIAR SESION.\n");
    printf("2. VISITANTE.\n");
    printf("3. CREAR CUENTA.\n");
    printf("4.SALIR\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\nINTRODUZCA EL NUMERO PARA ENTRAR EN LA OPCION QUE DESEE\n");
    printf("---->");
    int c; 
    scanf("%d", &c);
    return c;
}

int menuPartipante()
{
    printf("\n----------------- PARTICIPANTE -----------------\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("1. INICIAR SESION\n");
    printf("2. VOLVER\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\nINTRODUZCA EL NUMERO PARA ENTRAR EN LA OPCION QUE DESEE\n");
    printf("---->");
    int p;
    scanf("%d", &p);
    return p;
}

int main()
{
    //struct user usern;
    //Hacemos el menu
    system("clear");
    int c=0;
    c = menu();
    
    while(c != 4)
    {
        switch (c)
        {
        case 1: //Menu del participante
            system("clear");
            int p = 0;
            p = menuPartipante();

            switch (p)
            {
            case 1:
                
                break;

            case 2:
                return main();

            default:
                break;
            }
            
            break;

        case 2:
            system("clear");
        case 3:
            system("clear");

        default:
            break;
        }
    }

    return 0;
}