#ifndef FILENODCLI_H_INCLUDED
#define FILENODCLI_H_INCLUDED


void file_to_list_menu (char archi[]);
NODCLI* file_to_list (char archi[]);
NODCLI* passage_file_to_list (FILE* fil_cli, NODCLI* lista);
void sort_file_to_list_menu(char archi[]);
NODCLI* sort_file_to_list (char archi[]);
NODCLI* sort_dni_list_cli(FILE* fil_cli, NODCLI* lista);
NODCLI* add_end_list(NODCLI* lista, NODCLI* nuevo);
void search_client_dni (char fil_cli[]);
void list_to_file_menu(char archi_orig[], char archi_dest[]);
int list_to_file (NODCLI* clients, char archi[]);
void passage_list_to_file(NODCLI* clients, char archi[]);
void print_fil (char archi[]);
void interc_2_list_to_one_menu (char ar_sort[]);




#endif // FILENODCLI_H_INCLUDED
