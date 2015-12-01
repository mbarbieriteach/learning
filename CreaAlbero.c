#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo_s
{
    int valnome;
    int status;
    struct Nodo* SX;
    struct Nodo* DX;
}Nodo;

int main()
{
    printf("Hello world!\n");
    Nodo* radice=malloc(sizeof(Nodo));
    radice->SX=NULL;
    radice->DX=NULL;
    radice->valnome=0;

    Creanodo(&radice,1);
    Creanodo(&radice,2);
    Creanodo(&radice,3);
    Creanodo(&radice,4);
    Creanodo(&radice,5);
    Creanodo(&radice,6);

    visita(&radice);
    return 0;
}

void Creanodo(Nodo** head,int val)
{
    Nodo* punter=*head;
    printf("\n\n------------Creanodo------------->(%d)",punter->valnome);
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
            printf("\n---Ci spostiamo al nodo a sinistra---");
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
            printf("\n---Ci spostiamo al nodo a destra---");
            punter=punter->DX;
            Creanodo(&punter,val);
        }
    }
    printf("\n______________________________________________\n\n\n\n");
    return 0;
}

void visita(Nodo** head)
{
    Nodo* punter=*head;
    Nodo* pp=punter;
    punter->status=2;
    printf("%d ",punter->valnome);

    if(punter->SX!=NULL)
    {
        pp=punter->SX;
    }

    if(punter->SX=!NULL)
    {
        pp=punter->SX;
        visita(pp);
    }

    if(punter->DX!=NULL)
    {
        pp=punter->DX;
        visita(pp);
    }

    return 0;
}
