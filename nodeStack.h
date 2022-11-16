#ifndef NODESTACK_H_INCLUDED
#define NODESTACK_H_INCLUDED
#include "nodeClients.h"
#define STCK_CLI NODCLI*


void init_stack_nod (STCK_CLI* pila);
int void_stack_nod (STCK_CLI* pila);
CLI top_stack (STCK_CLI* pila);
CLI unstack_nod (STCK_CLI* pila);
void stack_node (STCK_CLI* pila, CLI c);
void print_stack_nod (NODCLI** pila, char message[]);




#endif // NODESTACK_H_INCLUDED
