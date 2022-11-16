#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


#include "clients.h"
#include "nodeClients.h"
#include "nodeStack.h"


#define STCK_CLI NODCLI*





void init_stack_nod (STCK_CLI* pila)
{
    (*pila) = initNodeCli();
}





int void_stack_nod (STCK_CLI* pila)
{
    return (!(*pila)) ? 1 : 0;
}





CLI top_stack (STCK_CLI* pila)
{
    return return_first((*pila));
}





CLI unstack_nod(STCK_CLI* pila)
{
    CLI c = return_first((*pila));

    (*pila) = remove_first_nod((*pila));

    return c;
}





void stack_node (STCK_CLI* pila, CLI c)
{
    (*pila) = addIniCli((*pila), newNodCli(c));
}





void print_stack_nod (STCK_CLI* pila, char message[])
{
    print_list_cli((*pila), message);
}





