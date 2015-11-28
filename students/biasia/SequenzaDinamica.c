#include<stdio.h>
#include<stdlib.h>

struct s_nodo
{
    int dato;
    struct s_nodo* Next;
};

typedef struct s_nodo nodo;

void Crea(nodo* testa,int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&testa->dato);
        testa->Next=malloc(sizeof(nodo));
        testa=testa->Next;
    }
    testa->Next=NULL;
}
nodo* Delete(nodo* A)
{
    nodo* tmp;
    nodo* Lista;
    Lista=A;
    printf("\n in quale posizione vuoi cancellare il numero?");
    int i=0;
    scanf("%d",&i);
    for(int j=0;j<i-2;j++)
    {
        Lista=Lista->Next;
    }
    tmp=Lista->Next;
    Lista->Next=Lista->Next->Next;
    free(tmp);
    return A;
}

nodo* Add(nodo* A)
{
    int numero;
    printf("\n Che valore vuoi inserire ?");
    scanf("%d",&numero);
    nodo* Lista;
    Lista=A;
    while(Lista->Next!=NULL)
    {
        Lista=Lista->Next;
    }
    Lista->Next=malloc(sizeof(nodo));
    Lista=Lista->Next;
    Lista->dato=numero;
    Lista->Next=NULL;

    return A;
}

void Print(nodo* A)
{
    nodo* Lista;
    Lista=A;
    while(Lista->Next!=NULL)
    {
        printf("%d ",Lista->dato);
        Lista=Lista->Next;
    }
}

int main()
{
    printf("\n Quanti numeri vuoi inserire ?");
    int n;
    scanf("%d",&n);
    nodo* testa;
    testa=malloc(sizeof(nodo));
    Crea(testa,n);
    printf("Cosa vuoi fare ?");
    int decisione;
    do{

    printf("\n -Digita 1 per togliere un elemento dalla sequenza");
    printf("\n -Digita 2 per aggiungere un elemento alla sequenza");
    printf("\n -Digita 3 per stampare la sequenza");
    printf("\n -Digita 0 per uscire dal programma");
    scanf("%d",&decisione);
    switch(decisione)
    {
    case 0:
        {
            break;
        }
    case 1:
        {
            testa=Delete(testa);
            break;
        }
    case 2:
        {
            testa=Add(testa);
            break;
        }
    case 3:
        {
            Print(testa);
            break;
        }
    }
    printf("\n Se vuoi terminare inserisci 0");
    printf("\n Se vuoi continuare inserisci 1");
    scanf("%d",&decisione);
    }while(decisione!=0);
    return 0;
}
