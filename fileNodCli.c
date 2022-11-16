#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


#include "clients.h"
#include "nodeClients.h"
#include "margin.h"
#include "fileNodCli.h"





void file_to_list_menu (char archi[])
{
    NODCLI* clients = file_to_list(archi);

    if (clients)
        {
        print_list_cli(clients, "SE PASARON LOS CLIENTES DEL ARHIVO A LA LISTA");
        }
    else
        {
        alertMessagge("LA LISTA SE ENCUENTRA VACIA");
        getch();
        }
}





NODCLI* file_to_list (char archi[])
{
    FILE* fil_cli = fopen(archi, "rb");

    NODCLI* lista = NULL;

    if (fil_cli)
        {
        lista = passage_file_to_list(fil_cli, lista);
        }
    else
        {
        alertMessagge(">>>[ERROR]<<< OCURRIO UN FALLO AL ABRIR EL ARCHIVO");
        getch();
        }

    fclose(fil_cli);

    return lista;
}






NODCLI* passage_file_to_list (FILE* fil_cli, NODCLI* lista)
{
    CLI ax_cli;

    rewind(fil_cli);

    while (fread(&ax_cli, sizeof(CLI), 1, fil_cli) > 0)
        {
        lista = addEndCli(lista, newNodCli(ax_cli));
        }

    return lista;
}




void sort_file_to_list_menu(char archi[])
{
    NODCLI* clients = sort_file_to_list(archi);

    if (clients)
        {
        print_list_cli(clients, "SE PASARON LOS CLIENTES ORDENANDOLOS POR D.N.I.");
        }
    else
        {
        alertMessagge("LA LISTA SE ENCUENTRA VACIA");
        getch();
        }
}




NODCLI* sort_file_to_list (char archi[])
{
    FILE* fil_cli = fopen(archi, "rb");

    NODCLI* lista = NULL;

    if (fil_cli)
        {
        lista = sort_dni_list_cli(fil_cli, lista);
        }
    else
        {
        alertMessagge(">>>[ERROR]<<< OCURRIO UN FALLO AL ABRIR EL ARCHIVO");
        getch();
        }

    fclose(fil_cli);

    return lista;
}






NODCLI* sort_dni_list_cli(FILE* fil_cli, NODCLI* lista)
{
    rewind(fil_cli);

    CLI ax_cli;

    if (!lista && fread(&ax_cli, sizeof(CLI), 1, fil_cli) > 0)
        {
        lista = addEndCli(lista, newNodCli(ax_cli));
        }

    while (fread(&ax_cli, sizeof(CLI), 1, fil_cli) > 0)
        {
        lista = add_end_list(lista, newNodCli(ax_cli));
        }

    return lista;
}



NODCLI* add_end_list(NODCLI* lista, NODCLI* nuevo)
{
    if (!lista)
        {
        lista = nuevo;
        }
    else
        {
        if (strcmp(lista->c.dni, nuevo->c.dni) >= 0)
            {
            lista = addIniCli(lista, nuevo);
            }
        else
            {
            NODCLI* prev = lista;
            NODCLI* next = lista;

            while (next && strcmp(next->c.dni, nuevo->c.dni) < 0)
                {
                prev = next;
                next = next->siguiente;
                }

            nuevo->siguiente = next;
            prev->siguiente = nuevo;
            }
        }

    return lista;
}




void search_client_dni (char fil_cli[])
{
    char dni[30];

    NODCLI* clients = file_to_list(fil_cli);
    NODCLI* cli_result = NULL;

    loadMessagge("BUSCANDO CLIENTE", "Ingrese el dni del cliente");
    fflush(stdin);
    gets(dni);
    system("cls");

    cli_result = search_client_list_dni(clients, dni);

    if (cli_result)
        {
        printInMarg("CLIENTE ENCONTRADO");
        printAClient(cli_result->c);
        }
    else
        {
        alertMessagge(">>>[ERROR]<<< NO EXISTE UN CLIENTE CON ESE D.N.I.");
        }
    getch();
}











int cant_node_rec (NODCLI* lista)
{
    return (lista) ? 1 + cant_node_rec(lista->siguiente) : 0;
}





void list_to_file_menu(char archi_orig[], char archi_dest[])
{
    NODCLI* clients = file_to_list(archi_orig);

    if(list_to_file(clients, archi_dest))
        {
        printInMarg("SE PASARON LOS CLIENTES DE LA LISTA AL ARCHIVO");
        print_fil(archi_dest);
        printf("\n");

        printInMarg("PRESIONE UNA TECLA PARA CONTINUAR");
        }
    else
        {
        alertMessagge("FALLO AL ABRIR EL ARCHIVO O LISTA VACIA");
        }

    getch();
}





int list_to_file (NODCLI* clients, char archi[])
{
    int flag = 0;

    if (clients)
        {
        passage_list_to_file(clients, archi);
        flag = 1;
        }
    else
        {
        alertMessagge("LA LISTA SE ENCUENTRA VACIA");
        getch();
        }

    return flag;
}





void passage_list_to_file (NODCLI* clients, char archi[])
{
    FILE* fil_cli = fopen(archi, "wb");

    if (fil_cli)
        {
        CLI c;

        while (clients)
            {
            c = clients->c;
            fwrite(&c, sizeof(CLI), 1, fil_cli);
            clients = clients->siguiente;
            }

        fclose(fil_cli);
        }
    else
        {
        alertMessagge("FALLO AL ABRIR EL ARCHIVO");
        getch();
        }
}





void print_fil (char archi[])
{
    FILE* fil_cli = fopen(archi, "rb");

    if(fil_cli)
        {
        CLI c;

        while (fread(&c, sizeof(CLI), 1, fil_cli) > 0)
            {
            printAClient(c);
            printf("\n________________________________________");
            }
        }
    else
        {
        alertMessagge("FALLO AL ABRIR EL ARCHIVO");
        getch();
        }
}





void interc_2_list_to_one_menu (char ar_sort[])
{
    FILE* fil_cli = fopen(ar_sort, "rb");

    if (fil_cli)
        {
        NODCLI* result_list = NULL;
        NODCLI* sort_1 = NULL;
        NODCLI* sort_2 = NULL;

        CLI c;

        while (fread(&c, sizeof(CLI), 1, fil_cli) > 0)
            {
            sort_1 = addEndCli(sort_1, newNodCli(c));
            if (fread(&c, sizeof(CLI), 1, fil_cli) > 0)
                {
                sort_2 = addEndCli(sort_2, newNodCli(c));
                }
            }

        print_list_cli(sort_1, "sort_1");
        system("cls");
        print_list_cli(sort_2, "sort_2");
        system("cls");

        result_list = passage_interc_list_to_one(sort_1, sort_2, result_list);

        if (result_list)
            {
            sort_1 = NULL;
            sort_2 = NULL;

            print_list_cli(result_list, "SE PASARON LOS CLIENTES DE LAS 2 LISTAS");
            system("cls");

            if (sort_1 || sort_2)
                {
                alertMessagge("UNA DE LAS LISTAS TIENE DATOS");
                }
            else
                {
                alertMessagge("LAS LISTAS SE ENCUENTRAN VACIAS");
                }
            getch();
            }
        else
            {
            alertMessagge("LISTA VACIA");
            getch();
            }
        }
    else
        {
        alertMessagge("FALLO AL ABRIR EL ARCHIVO");
        getch();
        }

}






