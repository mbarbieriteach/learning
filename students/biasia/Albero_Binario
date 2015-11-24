#include<stdio.h>
#include<stdlib.h>

struct n_nodo
{
    struct Nodo* Padre;
    int contenuto;
    struct n_nodo* FiglioDestro;
    struct n_nodo* FiglioSinistro;
};

    typedef struct n_nodo Nodo;


void Insert_Albero(Nodo** NODO)
{
    Nodo* Radice=NODO;

    int D_S;
    if(Radice->Padre==NULL)
    {
        printf("\n Inserisci il contenuto della radice : ");
        scanf("%d",Padre->contenuto);
    }
    else {
            if(Radice->contenuto>0)
            {
                printf("\n il nodo e' gia' stato inserito ");
            }
            else{
                printf("\n Inserisci il contenuto del nodo : ");
                scanf("%d",Radice->contenuto);
            }
            printf("\n Inserisci 1 per andare a destra ");
            printf("\n Inserisci 2 per andare a sinistra ");
            printf("\n Inserisci 3 per tornare al nodo precedente ");
            printf("\n Inserisci 0 per uscire ");
            scanf("%d",&D_S);

    switch(D_S)
        {
            case 0:
                printf("Hai scelto di uscire dal programma");
                break;
            case 1:
                Padre->FiglioDestro=malloc(sizeof(Nodo));
                Insert_Albero(Radice->FiglioDestro);
                break;
            case 2:
                Padre->FiglioSinistro=malloc(sizeof(Nodo));
                Insert_Albero(Radice->FiglioSinistro);
                break;
            case 3:
                Insert_Albero(Radice->Padre);
                break;

        }

    }
}




int main()
{
    Nodo** Radice=malloc(sizeof(Nodo));
    Radice->Padre=NULL;
    Insert_Albero(Radice);

    return 0;
}
