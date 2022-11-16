#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>



#include "margin.h"
#include "nodeClients.h"
#include "fileNodCli.h"
#include "menu.h"


#define ANCHO 116


#define AR_CLIENTS "clientes.dat"
#define AR_PASS_CLIENTS "pass_clients.dat"
#define AR_SORT_CLIENTS "sort_clients.dat"




void main_menu(void)
{
    char opcion = 0;

    while (opcion != 27)
        {
        Beep(2000, 300);
        system("cls");
        system("COLOR 1E");
        printInMarg("TP 4: LISTAS");
        contarTitulo(">>[1]<< Pasaje de datos");
        contarTitulo(">>[2]<< Buscar un cliente determinado en una lista");
        contarTitulo(">>[3]<< Pila de listas");
        contarTitulo(">>[ESC]<< SALIR DEL PROGRAMA");
        imprimirTecho(ANCHO);

        opcion = getch();
        Beep(2000, 300);

        system("cls");

        switch(opcion)
            {
            case '1':
                passage_menu();
                break;
            case '2':
                search_client_dni(AR_CLIENTS);
                break;
            case '3':
                stack_menu();
                break;
            case 27:
                alertMessagge("AAA CULOOO");
                break;
            default:
                alertMessagge("OPCION INVALIDA POR FAVOR ELIJA OTRA");
                getch();
                break;
            }
        }

    system("cls");
    imprimirTecho(ANCHO);
    contarTitulo("WOOOOW QUE PROGRAMA PEDORRO");
    contarTitulo("Lo que juego en C soy una locura");
    imprimirTecho(ANCHO);
    alertMessagge("ESTE PROGRAMA ES UNA PORONGA");

    int i=0;

    while (!kbhit())
        {
        if (!i)
            {
            system("COLOR 0B");
            i = 1;
            }
        else if (i == 1)
            {
            system("COLOR A7");
            i = 666;
            }
        else
            {
            system("COLOR F2");
            i = 0;
            }
        }

    Beep(400, 2000);
}





void passage_menu (void)
{
    char opcion = 0;

    while (opcion != 27)
        {
        system("cls");
        printInMarg("MENU DE PASAJE DE DATOS");
        contarTitulo(">>[1]<< Pasar del archivo a la lista");
        contarTitulo(">>[2]<< Pasar del archivo a la lista ordenandolos");
        contarTitulo(">>[3]<< Pasar de la lista al archivo");
        contarTitulo(">>[4]<< Intercalas 2 listas ordenadas y pasarlas a 1");
        contarTitulo(">>[ESC]<< VOLVER AL MENU PRINCIPAL");
        imprimirTecho(ANCHO);


        opcion = getch();
        Beep(2000, 300);
        system("cls");

        switch(opcion)
            {
            case '1':
                file_to_list_menu(AR_CLIENTS);
                break;
            case '2':
                sort_file_to_list_menu(AR_CLIENTS);
                break;
            case '3':
                list_to_file_menu(AR_CLIENTS, AR_PASS_CLIENTS);
                break;
            case '4':
                interc_2_list_to_one_menu(AR_SORT_CLIENTS);
                break;
            case 27:
                alertMessagge("AAA CULOOO");
                break;
            default:
                alertMessagge("OPCION INVALIDA POR FAVOR ELIJA OTRA");
                getch();
                break;
            }
        }
}




void stack_menu ()
{
    char opcion = 0;

    while (opcion != 27)
        {
        system("cls");
        printInMarg("MENU DE PILAS DE NODOS");
        contarTitulo(">>>[1]<<< Pasar del archivo a la pila");
        imprimirTecho(ANCHO);

        opcion = getch();

        system("cls");

        switch (opcion)
            {
            case '1':
                file_to_stack_menu(AR_CLIENTS);
                break;
            case 27:
                alertMessagge("AAAA CULOO");
                break;
            default:
                alertMessagge("OPCION INVALIDA POR FAVOR ELIJA OTRA");
                getch();
                break;
            }
        }
}
