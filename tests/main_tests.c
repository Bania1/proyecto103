#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "tests.h"

void main()
{
    int test1 = test_iniciar_sesion_1();
    int test2 = test_iniciar_sesion_2();
    if(test1 == 1 && test2 == 1)
    {
        printf("FUNCION DE INICIAR SESION CORRECTA\n");
    }
    int test3 = test_buscar_usuario_1();
    int test4 = test_buscar_usuario_2();
    if(test3 == 1 && test4 == 1)
    {
        printf("FUNCION DE BUSCAR USUARIO CORRECTA\n");
    }
    int test5 = test_buscar_recurso_1();
    int test6 =test_buscar_recurso_2();
    if(test5 == 1 && test6 == 1)
    {
        printf("FUNCION DE BUSCAR RECURSO CORRECTA\n");
    }
    int test7 = test_buscar_curso_1();
    int test8 = test_buscar_curso_2();
    if(test7 == 1 && test8 == 1)
    {
        printf("FUNCION DE BUSCAR CURSO CORRECTA\n");
    }
    int test9 = test_inscribirse();
    if(test9 == 1)
    {
        printf("FUNCION DE INSCRIBIRSE CORRECTA\n");
    }
    int test10 = test_comprobar_inscripcion_1();
    int test11 = test_comprobar_inscripcion_2();
    if(test10 == 1 && test11 == 1)
    {
        printf("FUNCION DE COMPROBAR INSCRIPCION CORRECTA\n");
    }
}