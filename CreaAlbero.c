#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo_s
{
    int valnome;
    struct Nodo* SX;
    struct Nodo* DX;
}Nodo;

int main()
{
    printf("Hello world!\n");
    Nodo* radice=malloc(sizeof(Nodo));
    radice->SX=NULL;
    radice->DX=NULL;

    Creanodo(&radice,1);
    Creanodo(&radice,2);
    Creanodo(&radice,3);
    Creanodo(&radice,4);
    Creanodo(&radice,5);
    Creanodo(&radice,6);
    return 0;
}

void Creanodo(Nodo** head,int val)
{
    Nodo* punter=*head;
    printf("\n\n*****************Creanodo****************** ");
    if(punter->SX != NULL)
    {
        printf("\nA sinistra c'e' gia' un nodo");
    }

    if(punter->DX != NULL)
    {
        printf("\nA destra c'e' gia' un nodo");
    }

    char scelta;
    printf("\nNodo a sinista(s) o a destra(d)? ");
    fflush(stdin);
    scanf("%c",&scelta);

    Nodo* nuovonodo=malloc(sizeof(Nodo));
    nuovonodo->SX=NULL;
    nuovonodo->DX=NULL;
    if(scelta=='s')
    {
        if(punter->SX==NULL)
        {
            punter->SX=nuovonodo;
            printf("\nil nodo e' stato aggiunto a sinistra");
            punter=punter->SX;
            punter->valnome=val;
        }
        else
        {
            printf("\nA sinistra c'e' gia' un nodo");
            printf("\nCi spostiamo al nodo a sinistra");
            punter=punter->SX;
            Creanodo(&punter,val);
        }

    }
    else if(scelta=='d')
    {

       if(punter->DX==NULL)
        {
            punter->DX=nuovonodo;
            printf("\nil nodo e' stato aggiunto a destra");
            punter=punter->DX;
            punter->valnome=val;
        }
        else
        {
            printf("\nA destra c'e' gia' un nodo");
            printf("\nCi spostiamo al nodo a destra");
            punter=punter->DX;
            Creanodo(&punter,val);
        }
    }
    printf("\n*************************************************");
    return 0;
}
