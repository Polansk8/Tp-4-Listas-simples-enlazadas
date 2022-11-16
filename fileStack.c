#include <stdio.h>
#include <stdlib.h>

#include "nodeStack.h"
#include "fileStack.h"



void file_to_stack_menu (char archi[])
{
    FILE* fil_cli = fopen(archi, "rb");

    if (fil_cli)
        {
        STCK_CLI clients;
        init_stack_nod(&clients);

        file_to_stack(&clients, fil_cli);

        if (!void_stack_nod(&clients))
            {
            print_stack_nod(&clients, "CLIENTES PASADOS DEL ARCHIVO A LA PILA");
            }
        else
            {
            alertMessagge("EL ARCHIVO SE ENCUENTRA VACIO");
            getch();
            }
        }
    else
        {
        alertMessagge("FALLO AL ABRIR EL ARCHIVO");
        getch();
        }

    fclose(fil_cli);


}





void file_to_stack (STCK_CLI* pila, FILE* fil_cli)
{
    CLI c;

    while (fread(&c, sizeof(CLI), 1, fil_cli) > 0)
        {
        stack_node(pila, c);
        }
}





