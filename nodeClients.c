#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


#include "margin.h"
#include "nodeClients.h"
#include "clients.h"


NODCLI* initNodeCli()
{
    return NULL;
}



NODCLI* newNodCli(CLI dato)
{
    NODCLI* nuevo = (NODCLI*) malloc(sizeof(NODCLI));

    nuevo->c = dato;

    nuevo->siguiente = NULL;

    return nuevo;
}





NODCLI* addIniCli (NODCLI* lista, NODCLI* newNode)
{
    newNode->siguiente = lista;

    return newNode;
}





NODCLI* searchNullCliList (NODCLI* lista)
{
    if (lista)
        {
        while (lista->siguiente)
            {
            lista = lista->siguiente;
            }
        }

    return lista;
}





NODCLI* addEndCli (NODCLI* lista, NODCLI* newNode)
{
    if (!lista)
        {
        lista = newNode;
        }
    else
        {
        NODCLI* aux = searchNullCliList(lista);
        aux->siguiente = newNode;
        }

    return lista;
}




void printListCli (NODCLI* lista)
{
    NODCLI* aux = lista;

    while (aux)
        {
        printAClient(aux->c);
        printf("\n________________________________________________________");
        aux = aux->siguiente;
        }
}





void print_list_cli (NODCLI* lista, char message[])
{
    if (lista)
        {
        printInMarg(message);
        printListCli(lista);
        printf("\n");
        printInMarg("PRESIONE CUALQUIER TECLA PARA CONTINUAR");
        }
    else
        {
        alertMessagge(">>>[ERROR]<<< LA LISTA NO CONTIENE DATOS");
        }
    getch();
}





NODCLI* search_client_list_dni (NODCLI* lista, char dni[])
{
    NODCLI* aux = lista;

    while (aux && strcmp(aux->c.dni, dni) != 0)
        {
        aux = aux->siguiente;
        }

    return aux;
}





NODCLI* passage_interc_list_to_one (NODCLI* sort_1, NODCLI* sort_2, NODCLI* result_list)
{
    NODCLI* aux = NULL;


    if (sort_1 && sort_2)
        {
        while (sort_1 && sort_2)
            {
            if (strcmp(sort_1->c.dni, sort_2->c.dni) < 0)
                {
                aux = sort_1;
                sort_1 = sort_1->siguiente;
                }
            else
                {
                aux = sort_2;
                sort_2 = sort_2->siguiente;
                }

            aux->siguiente = NULL;
            result_list = addEndCli(result_list, aux);
            }

        if (sort_1)
            {
            result_list = addEndCli(result_list, sort_1);
            }
        else if (sort_2)
            {
            result_list = addEndCli(result_list, sort_2);
            }
        }
    else
        {
        alertMessagge("ALGUNA DE LAS 2 LISTAS SE ENCUENTRA VACIA");
        getch();
        }

    return result_list;
}





CLI return_first (NODCLI* lista)
{
    CLI c = lista->c;

    return c;
}





NODCLI* remove_first_nod (NODCLI* lista)
{
    NODCLI* aux = lista;

    lista = lista->siguiente;

    free(aux);

    return lista;
}
