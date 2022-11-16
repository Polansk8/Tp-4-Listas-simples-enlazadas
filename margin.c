#include <stdlib.h>
#include <stdio.h>


#define LONG 116



void contarTitulo(char titulo[])
{
    int anchoTotal = 118;
    int contador = 0;
    while (titulo[contador] != 0)
        {
        contador ++;
        }
    int espacio = anchoTotal - contador;
    printf("%c", 219);


    for(int i = 0; i < anchoTotal-4; i++)
        {
        printf(" ");
        }

    printf("%c", 219);
    printf("\n");
    printf("%c", 219);
    for(int i = 0; i < (espacio/2)-2; i++)
        {
        printf(" ");
        }

    printf("%s", titulo);


    if(espacio % 2 != 0)
        {
        for(int i = 0; i < (espacio/2)-1; i++)
            {
            printf(" ");
            }
        }
    else
        {
        for(int i = 0; i < (espacio/2)-2; i++)
            {
            printf(" ");
            }
        }

    printf("%c", 219);
    printf("\n");
    printf("%c", 219);

    for(int i = 0; i < anchoTotal-4; i++)
        {
        printf(" ");
        }
    printf("%c", 219);
    printf("\n");
}





void imprimirTecho(int anchoTotal)
{
    for(int i = 0; i < anchoTotal; i++)
        {
        printf("%c", 223);
        }
    printf("\n");
}





void printInMarg(char titulo[])
{
    imprimirTecho(LONG);
    contarTitulo(titulo);
    imprimirTecho(LONG);
}





void printLoadMessagge (char data[])
{
    printInMarg("CARGANDO EMPLEADO");
    contarTitulo(data);
    imprimirTecho(LONG);
    printf("\n\t\t\t\t\t\t");
}





void loadMessagge (char message[], char data[])
{
    printInMarg(message);
    contarTitulo(data);
    imprimirTecho(LONG);
    printf("\n\t\t\t\t\t\t");
}





void alertMessagge (char titulo[])
{
    printf("\n\n\n\n\n\n\n\n");
    printInMarg(titulo);
    contarTitulo("PRESIONE CUALQUIER TECLA PARA CONTINUAR");
    imprimirTecho(LONG);
}
