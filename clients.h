#ifndef CLIENTS_H_INCLUDED
#define CLIENTS_H_INCLUDED



typedef struct
{
    int id;
    char apellido[50];
    char name[50];
    char dni[50];
    char sexo;
    char celular[50];
    char email[50];
    int baja;           ///1 si esta de baja, 0 si esta de alta
}CLI;




///Carga un cliente
CLI loadAClient (CLI c);
///Muestra un cliente
void printAClient (CLI c);





#endif // CLIENTS_H_INCLUDED
