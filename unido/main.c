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
    struct curso curson;
    int volver; //boton para volver
    
    //Hacemos el menu
    system("clear");
    int c=0;
    int op=0;
    
    while(c != 4)
    {
        menuPrincipal();
        scanf("%d", &c); printf("\n");
        fflush(stdin);
        clearerr(stdin);
        switch (c)
        {
            case 1: 
            //Iniciar sesion
                system("clear");
                fflush(stdin);
                clearerr(stdin);
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
                    op=0;
                    while (op != 5) //Menu cuando inicias sesion
                    {
                        menu_iniciado();
                        scanf("%d", &op); printf("\n");
                        switch (op)
                        {
                            case 1:
                                system("clear");
                                printf("SE HA EJECUTADO VER CURSOS\n");
                                mostrar_todos_cursos(fichCursos);
                                int volver;
                                printf("PRESIONE '1' PARA VOLVER.\n");
                                scanf("%d", &volver);

                                while(volver != 1)
                                {
                                    system("clear");
                                    printf("\nERROR, PRESIONE '1' PARA VOLVER.\n");
                                    scanf("%d", &volver);
                                }
                                
                                system("clear");
                                op=0;
                                volver=0;
                                break;
                                //sleep(2);
                                //system("clear");

                            case 2:
                                system("clear");
                                printf("SE HA EJECUTADO INSCRIBIRSE AL CURSO\n\n");
                                printf("INTRODUCE EL CODIGO DEL CURSO EN EL QUE QUIERES INSCRIBIRTE: ");
                                int cod;
                                scanf("%d",&cod);
                                printf("\n");
                                if(buscar_curso(fichCursos,cod)!=1)
                                {
                                    printf("CURSO INTRODUCIDO NO EXITENTE\n");
                                    sleep(2);
                                    system("clear");
                                    break;
                                }
                                if(comprobar_fecha(fichCursos,cod)==1)
                                {
                                    printf("EL CURSO SELECCIONADO HA EMPEZADO YA O HA ACABADO\n");
                                    printf("\nPRESIONE '1' PARA VOLVER.\n");
                                    scanf("%d", &volver);

                                    while(volver != 1)
                                    {
                                        system("clear");
                                        printf("\nERROR, PRESIONE '1' PARA VOLVER\n");
                                        scanf("%d", &volver);
                                    }
                                
                                    system("clear");
                                    op=0;
                                    volver=0;

                                    break;
                                }
                                
                                if(inscribirse(fichCursos,fichInscripciones,cod,usern.email)==1)
                                {
                                    printf("UNIDO CON EXITO AL CURSO CON CODIGO %d\n",cod);
                                }
                                else if(inscribirse(fichCursos,fichInscripciones,cod,usern.email)==0)
                                {
                                    printf("CURSO CON AFORO COMPLETO, USUARIO AÑADIDO A LA LISTA DE ESPERA\n");
                                }
                                else if(inscribirse(fichCursos,fichInscripciones,cod,usern.email)==2)
                                {
                                    printf("ERROR AL UNIRSE, EL USUARIO YA ESTA EN LA LISTA E ESPERA\n");
                                }
                                else if(inscribirse(fichCursos,fichInscripciones,cod,usern.email)==3)
                                {
                                    printf("ERROR AL UNIRSE, EL USUARIO YA ESTA INSCRITO\n");
                                }
                                
                                printf("\nPRESIONE '1' PARA VOLVER.\n");
                                scanf("%d", &volver);

                                while(volver != 1)
                                {
                                    system("clear");
                                    printf("\nERROR, PRESIONE '1' PARA VOLVER\n");
                                    scanf("%d", &volver);
                                }
                            
                                system("clear");
                                op=0;
                                volver=0;
                                break;
                                
                            case 3:
                                system("clear");
                                printf("SE HA EJECUTADO BUSCAR CURSO\n");
                                printf("INTRODUCE EL ID DEL CURSO A BUSCAR\n");
                                int n;
                                scanf("%d",&n);
                                mostrar_curso(fichCursos,n);
                                
                                printf("\nPRESIONE '1' PARA VOLVER.\n");
                                scanf("%d", &volver);

                                while(volver != 1)
                                {   
                                    system("clear");
                                    printf("\nERROR, PRESIONE '1' PARA VOLVER\n");
                                    scanf("%d", &volver);
                                }
                            
                                system("clear");
                                op=0;
                                volver=0;
                                break;
                            
                            case 4:
                                system("clear");
                                printf("SE HA EJECUTADO VER MIS CURSOS\n");
                                ver_mis_cursos(fichInscripciones,fichCursos,usern.email);
                                
                                printf("\nPRESIONE '1' PARA VOLVER.\n");
                                scanf("%d", &volver);
                                while(volver != 1)
                                {   
                                    system("clear");
                                    printf("\nERROR, PRESIONE '1' PARA VOLVER\n");
                                    scanf("%d", &volver);
                                }
                            
                                system("clear");
                                op=0;
                                volver=0;
                                break;

                            default:
                                break;
                        }
                    }
                }

                else if (cont == 5) //Menu del admin
                {
                    system("clear");
                    op=0;
                    fflush(stdin);
                    clearerr(stdin);
                    while (op != 16)
                    {
                        menu_admin();
                        scanf("%d", &op); printf("\n");
                        fflush(stdin);
                        clearerr(stdin);

                        switch (op)
                        {
                        case 1:
                            system("clear");
                            printf("SE HA EJECUTADO VER CURSOS\n");
                            mostrar_todos_cursos(fichCursos);
                            
                            printf("PRESIONE '1' PARA VOLVER.\n");
                            scanf("%d", &volver);

                            while(volver != 1)
                            {
                                system("clear");
                                printf("ERROR, PRESIONE '1' PARA VOLVER\n");
                                scanf("%d", &volver);
                            }
                            
                            system("clear");
                            op=0;
                            break;

                        case 2:
                            system("clear");
                                printf("SE HA EJECUTADO INSCRIBIRSE AL CURSO\n\n");
                                printf("INTRODUCE EL CODIGO DEL CURSO EN EL QUE QUIERES INSCRIBIRTE: ");
                                int cod;
                                scanf("%d",&cod);
                                printf("\n");
                                if(buscar_curso(fichCursos,cod)!=1)
                                {
                                    printf("CURSO INTRODUCIDO NO EXITENTE\n");
                                    sleep(2);
                                    system("clear");
                                    break;
                                }
                                if(comprobar_fecha(fichCursos,cod)==1)
                                {
                                    printf("EL CURSO SELECCIONADO HA EMPEZADO YA O HA ACABADO\n");
                                    printf("\nPRESIONE '1' PARA VOLVER.\n");
                                    scanf("%d", &volver);

                                    while(volver != 1)
                                    {
                                        system("clear");
                                        printf("\nERROR, PRESIONE '1' PARA VOLVER\n");
                                        scanf("%d", &volver);
                                    }
                                
                                    system("clear");
                                    op=0;
                                    volver=0;

                                    break;
                                }
                                
                                if(inscribirse(fichCursos,fichInscripciones,cod,usern.email)==1)
                                {
                                    printf("UNIDO CON EXITO AL CURSO CON CODIGO %d\n",cod);
                                }
                                else
                                {
                                    printf("CURSO CON AFORO COMPLETO\n");
                                }
                                
                                printf("\nPRESIONE '1' PARA VOLVER.\n");
                                scanf("%d", &volver);

                                while(volver != 1)
                                {
                                    system("clear");
                                    printf("\nERROR, PRESIONE '1' PARA VOLVER\n");
                                    scanf("%d", &volver);
                                }
                            
                                system("clear");
                                op=0;
                                volver=0;
                                break;

                        case 3:
                            system("clear");
                            curson.id=0;
                            printf("ID DEL CURSO A CREAR: ");
                            scanf("%d",&curson.id);

                            if(buscar_curso(fichCursos,curson.id) == 1)
                            {
                                system("clear");
                                printf("ERROR AL CREAR CURSO, PUEDE QUE EL ID ESTE YA UTILIZADO.\n");
                                printf("\nPRESIONE '1' PARA VOLVER.\n");
                                scanf("%d", &volver);

                                while(volver != 1)
                                {
                                    system("clear");
                                    printf("\nERROR, PRESIONE '1' PARA VOLVER\n");
                                    scanf("%d", &volver);
                                }
                            
                                system("clear");
                                op=0;
                                volver=0;

                                break;
                            }
                            
                            else if(buscar_curso(fichCursos, curson.id) == 0)
                            {
                                if(crear_curso(fichCursos,curson.id) == 1)
                                {
                                    system("clear");
                                    printf("\nCURSO CREADO CON EXITO.\n");
                                }
                                else
                                {
                                    printf("\nERROR AL CREAR EL CURSO\n");
                                }
                                printf("\nPRESIONE '1' PARA VOLVER.\n");
                                scanf("%d", &volver);
                            
                                while(volver != 1)
                                {
                                    system("clear");
                                    printf("\nERROR, PRESIONE '1' PARA VOLVER\n");
                                    scanf("%d", &volver);
                                }
                            
                                system("clear");
                                op=0;
                                volver=0;

                                break; 
                            }
                             
                        case 4:
                            system("clear");
                            printf("ID DEL CURSO A MODIFICAR: ");
                            scanf("%d", &curson.id);
                            //fgets(curson.id,200,stdin);
                            
                            fflush(stdin);
                            clearerr(stdin);
                            if(buscar_curso(fichCursos, curson.id) != 1)
                            {
                                system("clear");
                                printf("ERROR AL MODIFICAR CURSO.\n");
                                printf("\nPRESIONE '1' PARA VOLVER.\n");
                                scanf("%d", &volver);

                                while(volver != 1)
                                {
                                    system("clear");
                                    printf("\nERROR, PRESIONE '1' PARA VOLVER\n");
                                    scanf("%d", &volver);
                                }
                            
                                system("clear");
                                op=0;
                                volver=0;

                                break;
                            }
                            
                            else if(modificar_curso(fichCursos,curson.id) == 1)
                            {
                                
                                //system("clear");
                                printf("\nCURSO MODIFICADO CON EXITO.\n");
                            }
                            
                            printf("\nPRESIONE '1' PARA VOLVER.\n");
                            scanf("%d", &volver);

                            while(volver != 1)
                            {
                                system("clear");
                                printf("\nERROR, PRESIONE '1' PARA VOLVER\n");
                                scanf("%d", &volver);
                            }
                        
                            system("clear");
                            op=0;
                            volver=0;

                            break;

                        case 5:
                            system("clear");
                            system("clear");
                            printf("ID DEL CURSO A ELIMINAR: ");
                            scanf("%d", &curson.id);
                            //fgets(curson.id,200,stdin);
                            
                            fflush(stdin);
                            clearerr(stdin);
                            if(buscar_curso(fichCursos, curson.id) != 1)
                            {
                                system("clear");
                                printf("ERROR AL ELIMINAR CURSO.\n");
                                printf("\nPRESIONE '1' PARA VOLVER.\n");
                                scanf("%d", &volver);

                                while(volver != 1)
                                {
                                    system("clear");
                                    printf("\nERROR, PRESIONE '1' PARA VOLVER\n");
                                    scanf("%d", &volver);
                                }
                            
                                system("clear");
                                op=0;
                                volver=0;

                                break;
                            }
                            
                            else if(eliminar_curso(fichCursos,curson.id) == 1)
                            {
                                
                                //system("clear");
                                printf("\nCURSO ELIMINADO CON EXITO.\n");
                            }
                            
                            printf("\nPRESIONE '1' PARA VOLVER.\n");
                            scanf("%d", &volver);

                            while(volver != 1)
                            {
                                system("clear");
                                printf("\nERROR, PRESIONE '1' PARA VOLVER\n");
                                scanf("%d", &volver);
                            }
                        
                            system("clear");
                            op=0;
                            volver=0;

                            break;
                        
                        case 6:
                            system("clear");
                            printf("SE HA EJECUTADO BUSCAR CURSO\n");
                            printf("INTRODUCE EL ID DEL CURSO A BUSCAR\n");
                            int n;
                            scanf("%d",&n);
                            mostrar_curso(fichCursos,n);
                            
                            printf("\nPRESIONE '1' PARA VOLVER.\n");
                            scanf("%d", &volver);

                            while(volver != 1)
                            {   
                                system("clear");
                                printf("\nERROR, PRESIONE '1' PARA VOLVER\n");
                                scanf("%d", &volver);
                            }
                        
                            system("clear");
                            op=0;
                            volver=0;
                            break;

                        case 10:
                            system("clear");
                            printf("\n----------------- USUARIOS EN LA BASE DE DATOS -----------------\n");
                            printf("\n");
                            printf("\n");
                            printf("\n");

                            visualizar_informacion_usuarios(fichUsuarios);
                            printf("\nPRESIONE '1' PARA VOLVER.\n");
                            scanf("%d", &volver);

                            while(volver != 1)
                            {
                                system("clear");
                                printf("\nERROR, PRESIONE '1' PARA VOLVER\n");
                                scanf("%d", &volver);
                            }
                            
                            system("clear");
                            op=0;
                            volver=0;

                            break;

                        case 11: 
                            system("clear");
                            printf("INTRODUCE EL CORREO QUE DESEA MODIFICAR\n");
                            printf("---->");
                            scanf("%s", usern.email);

                            if (modificar_usuarios(fichUsuarios, fichInscripciones, usern.email) != 1)
                            {
                                system("clear");
                                printf("ERROR AL MODIFICAR USUARIO, EL CORREO INTRODUCIDO NO EXISTE.\n");
                                printf("\nPRESIONE '1' PARA VOLVER.\n");
                                scanf("%d", &volver);

                                while(volver != 1)
                                {
                                    system("clear");
                                    printf("\nERROR, PRESIONE '1' PARA VOLVER\n");
                                    scanf("%d", &volver);
                                }
                            
                                system("clear");
                                op=0;
                                volver=0;

                                break;
                            }
                            else //if(modificar_usuarios(fichUsuarios, fichInscripciones, usern.email) == 1) si pones esto, no funciona, no  se pq
                            {
                                
                                system("clear");
                                printf("\nUSUARIO MODIFICADO CON EXITO.\n");
                            }
                            
                            printf("\nPRESIONE '1' PARA VOLVER.\n");
                            scanf("%d", &volver);

                            while(volver != 1)
                            {
                                system("clear");
                                printf("\nERROR, PRESIONE '1' PARA VOLVER\n");
                                scanf("%d", &volver);
                            }
                        
                            system("clear");
                            op=0;
                            volver=0;

                            break;

                        case 13:
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

                            printf("\nUSUARIO CREADO CON EXITO.\n");
                            sleep(2);
                            system("clear");
                            
                            break;

                        case 14:
                            system("clear");
                            printf("INTRODUZCA EL CORREO DEL USUARIO A BUSCAR\n");
                            printf("----> ");
                            scanf("%s", usern.email);
                            printf("\n");

                            if (buscar_usuario(fichUsuarios, usern.email) != 1)
                            {
                                system("clear");
                                printf("ERROR, NO SE ENCUENTRA EL USUARIO.\n");
                                printf("\nPRESIONE '1' PARA VOLVER.\n");
                                scanf("%d", &volver);

                                while(volver != 1)
                                {
                                    system("clear");
                                    printf("\nERROR, PRESIONE '1' PARA VOLVER\n");
                                    scanf("%d", &volver);
                                }
                            
                                system("clear");
                                op=0;
                                volver=0;

                                break;
                            }
                            
                            mostrar_usuario(fichUsuarios, usern.email);
                            printf("\nPRESIONE '1' PARA VOLVER.\n");
                            scanf("%d", &volver);

                            while(volver != 1)
                            {
                                system("clear");
                                printf("\nERROR, PRESIONE '1' PARA VOLVER\n");
                                scanf("%d", &volver);
                            }
                        
                            system("clear");
                            op=0;
                            volver=0;

                            break;

                        case 15:
                            system("clear");

                            menu_creando_usuario();
                            
                            cont2=0;

                            while(cont2 < 3)
                            {
                                printf("CORREO: "); scanf("%s", usern.email);
                                printf("CONTRASEÑA: "); scanf("%s", usern.password);

                                int comprobar = comprobar_correo(usern);

                                if((comprobar == 0 ) || (comprobar == 1) || (comprobar == 2))
                                {
                                    printf("\nCORREO NO VALIDO, TIENE QUE SER '@curso' || '@recurso'\n\n");
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

                            printf("\nUSUARIO CREADO CON EXITO.\n");
                            sleep(2);
                            system("clear");
                            
                            break;
                            
                        default:
                            break;
                        }
                    }
                    
                }
                
                else if (cont == 6) //Menu de coord. de cursos
                {
                    system("clear");
                    op=0;
                    while (op != 11)
                    {
                        menu_coordinador_cursos();
                        scanf("%d", &op); printf("\n");

                        switch (op)
                        {
                        case 1:
                            system("clear");
                            printf("SE HA EJECUTADO VER CURSOS\n");
                            mostrar_todos_cursos(fichCursos);
                            int volver;
                            printf("PRESIONE '1' PARA VOLVER.\n");
                            scanf("%d", &volver);

                            while(volver != 1)
                            {
                                system("clear");
                                printf("ERROR, PRESIONE '1' PARA VOLVER\n");
                                scanf("%d", &volver);
                            }
                            
                            system("clear");
                            op=0;
                            volver=0;
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
                    op=0;
                    while (op != 6)
                    {
                        menu_coordinador_recursos();
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
                op=0;

                while (op != 2)
                {
                    menu_visitante();
                    scanf("%d",&op);

                    switch (op)
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