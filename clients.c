#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>


#include "clients.h"
#include "margin.h"




CLI loadAClient (CLI c)
{
    system("cls");
    printLoadMessagge("Ingrese el apellido");
    fflush(stdin);
    gets(c.apellido);
    system("cls");

    printLoadMessagge("Ingrese el nombre");
    fflush(stdin);
    gets(c.name);
    system("cls");

    printLoadMessagge("Ingrese el genero(M o F): ");
    fflush(stdin);
    scanf("%c", &c.sexo);
    system("cls");

    printLoadMessagge("Ingrese el celular");
    fflush(stdin);
    gets(c.celular);
    system("cls");

    printLoadMessagge("Ingrese el eMail");
    fflush(stdin);
    gets(c.email);

    return c;
}



void printAClient (CLI c)
{
    printf("\n                    Id: %d", c.id);
    printf("\n     Apellido y nombre: %s %s", c.apellido, c.name);
    printf("\n                D.N.I.: %s", c.dni);
if (c.sexo == 'm' || c.sexo == 'M')
    {
    printf("\n                Genero: Masculino");
    }
else
    {
    printf("\n                Genero: Femenino");
    }
    printf("\n               Celular: %s", c.celular);
    printf("\n                 eMail: %s", c.email);
if (!c.baja)
    {
    printf("\n                Estado: ALTA");
    }
else
    {
    printf("\n                Estado: BAJA");
    }
}




/**
CLI load_search_client ()
{
    CLI c;
    c.baja = 0;

    loadMessagge("BUSCANDO CLIENTE", "Ingrese el D.N.I.");
    fflush(stdin);
    gets()

    loadMessagge("BUSCANDO CLIENTE", "Ingrese el apellido");
    fflush(stdin);
    gets(c.name);
    system("cls");

    loadMessagge("BUSCANDO CLIENTE", "Ingrese el nombre");
    fflush(stdin);
    gets(c.apellido);
    system("cls");

    loadMessagge("BUSCANDO CLIENTE", "Ingrese el")
    fflush(stdin);
    gets(c.email)

    return c;
}*/
