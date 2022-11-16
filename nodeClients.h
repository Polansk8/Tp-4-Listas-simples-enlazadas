#ifndef NODECLIENTS_H_INCLUDED
#define NODECLIENTS_H_INCLUDED
#include "clients.h"


typedef struct _NODCLI
{
    CLI c;
    struct _NODCLI* siguiente;
}NODCLI;





NODCLI* initNodeCli();
NODCLI* newNodCli(CLI dato);
NODCLI* addIniCli (NODCLI* lista, NODCLI* newNode);
NODCLI* searchNullCliList (NODCLI* lista);
NODCLI* addEndCli (NODCLI* lista, NODCLI* newNode);
void printListCli (NODCLI* lista);
void print_list_cli (NODCLI* lista, char message[]);
NODCLI* search_client_list_dni (NODCLI* lista, char dni[]);
NODCLI* passage_interc_list_to_one (NODCLI* sort_1, NODCLI* sort_2, NODCLI* result_list);
CLI return_first (NODCLI* lista);
NODCLI* remove_first_nod (NODCLI* lista);




#endif // NODECLIENTS_H_INCLUDED
