#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int test_iniciar_sesion_1()
{
    struct user u = {"pepito@uco.es","1234"};


    int res = iniciar_sesion("1.txt",u);

    if(res == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int test_iniciar_sesion_2()
{
    struct user u = {"eje2@uco.es","1234"};

    int res = iniciar_sesion("1.txt",u);

    if(res == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int test_buscar_usuario_1()
{
   char email[200] = "pepito@uco.es";
   int res = buscar_usuario("1.txt",email);

   if(res == 0)
   {
        return 1;
   }
   else
   {
        return 0;
   }
}
int test_buscar_usuario_2()
{
   char email[200] = "eje3@uco.es";
   int res = buscar_usuario("1.txt",email);

   if(res == 1)
   {
        return 1;
   }
   else
   {
        return 0;
   }
}
int test_buscar_recurso_1()
{
   int res = buscar_recurso("4.txt",2);

   if(res == 1)
   {
        return 1;
   }
   else
   {
        return 0;
   }
}
int test_buscar_recurso_2()
{
   int res = buscar_recurso("4.txt",4);

   if(res == 0)
   {
        return 1;
   }
   else
   {
        return 0;
   }
}
int test_buscar_curso_1()
{
   int cod = 5;
   int res = buscar_curso("2.txt",cod);

   if(res == 0)
   {
        return 1;
   }
   else
   {
        return 0;
   }   
}
int test_buscar_curso_2()
{
   int cod = 4;
   int res = buscar_curso("2.txt",cod);

   if(res == 1)
   {
        return 1;
   }
   else
   {
        return 0;
   }   
}
int test_inscribirse()
{
   char email[200] = "eje1@uco.es";

   int res = inscribirse("2.txt","3.txt",1,email);

   if(res == 3)
   {
        return 1;
   }
   else
   {
        return 0;
   }   
}
int test_comprobar_inscripcion_1()
{

   char email[200] = "eje6@uco.es";

   int res = comprobar_inscripcion("3.txt",2,email);

   if(res == 0)
   {
        return 1;
   }
   else
   {
        return 0;
   }   
}
int test_comprobar_inscripcion_2()
{

   char email[200] = "eje2@uco.es";

   int res = comprobar_inscripcion("3.txt",2,email);

   if(res == 1)
   {
        return 1;
   }
   else
   {
        return 0;
   }   
}










