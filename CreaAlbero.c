#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo_s
{
    struct Nodo* SX;
    struct Nodo* DX;
}Nodo;

int main()
{
    printf("Hello world!\n");
    Nodo* radice=malloc(sizeof(Nodo));
    Nodo* puntatore=radice;

    Creanodo(&puntatore);
    Creanodo(&puntatore);
    Creanodo(&puntatore);
    Creanodo(&puntatore);
    Creanodo(&puntatore);
    Creanodo(&puntatore);
    return 0;
}

void Creanodo(Nodo** punt)
{
    printf("*****************Creanodo******************");
    if(*punt->SX != NULL)
    {
        printf("\n\nA sinistra c'è già un nodo");
    }

    if(*punt->DX != NULL)
    {
        printf("\nA destra c'è già un nodo");
    }

    char scelta;
    printf("\nNodo a sinista(s) o a destra(d)? ");
    scanf("%c",&scelta);

    Nodo* nuovonodo=malloc(sizeof(Nodo));
    if(scelta=='s')
    {
        if(*punt->SX==NULL)
        {
            *punt->SX=nuovonodo;
            printf("\n\nil nodo è stato aggiunto a sinistra");
            *punt=*punt->SX;
        }
        else
        {
            printf("\n\nA sinistra c'è già un nodo");
            printf("\nCi spostiamo al nodo a sinistra");
            *punt=*punt->SX;
        }

    }
    else if(scelta=='d')
    {

       if(*punt->DX==NULL)
        {
            *punt->DX=nuovonodo;
            printf("\n\nil nodo è stato aggiunto a destra");
            *punt=*punt->DX;
        }
        else
        {
            printf("\n\nA destra c'è già un nodo");
            printf("\nCi spostiamo al nodo a destra");
            *punt=*punt->DX;
        }
    }
    printf("*************************************************");
    return 0;
}
