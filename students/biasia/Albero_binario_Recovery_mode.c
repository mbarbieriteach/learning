#include<stdio.h>
#include<stdlib.h>

struct n_nodo
{
    struct n_nodo* Padre;
    int contenuto;
    struct n_nodo* FiglioDestro;
    struct n_nodo* FiglioSinistro;
};

    typedef struct n_nodo Nodo;


void Insert_Albero(Nodo** NODO)
{
    Nodo* Radice=*NODO;
    Radice->FiglioDestro=NULL;
    Radice->FiglioSinistro=NULL;

    int D_S;
    if(Radice->Padre==NULL)
    {
        printf("\n Inserisci il contenuto della radice : ");
        scanf("%d",Radice->contenuto);
    }
    else {
            if(Radice->contenuto!=0)
            {
                printf("\n il nodo e' gia' stato inserito ");
            }
            else{
                printf("\n Inserisci il contenuto del nodo : ");
                scanf("%d",Radice->contenuto);
            }
    }
            printf("\n Inserisci 1 per andare a destra ");
            printf("\n Inserisci 2 per andare a sinistra ");
            printf("\n Inserisci 3 per tornare al nodo precedente ");
            printf("\n Inserisci 0 per uscire ");
            scanf("%d",&D_S);

//if(D_S==1)
//{
    struct n_nodo* new_address = malloc(sizeof(Nodo));
                printf("  %d  ", new_address);
                Radice->FiglioDestro = new_address;
                printf("r54");

                //Nodo* tmp=Radice->FiglioDestro;

                printf("%d", Radice->FiglioDestro);// = Radice;
                printf("r56");
                Radice->FiglioDestro->contenuto=0;
                printf("r57");
                Insert_Albero(&(Radice->FiglioDestro));
//}
/*
    switch(D_S)
        {
            case 0:
                printf("Hai scelto di uscire dal programma");
                break;
            case 1: {
                struct n_nodo* new_address = malloc(sizeof(Nodo));
                printf("  %d  ", new_address);
                Radice->FiglioDestro = new_address;
                printf("r54");

                //Nodo* tmp=Radice->FiglioDestro;

                printf("%d", Radice->FiglioDestro);// = Radice;
                printf("r56");
                Radice->FiglioDestro->contenuto=0;
                printf("r57");
                Insert_Albero(&(Radice->FiglioDestro));
                break;
            }
            case 2:
                Radice->FiglioSinistro=malloc(sizeof(Nodo));
                Insert_Albero(&(Radice->FiglioSinistro));
                break;
            case 3:
                Insert_Albero(&(Radice->Padre));
                break;

        }

    //}*/
}




int main()
{

    Nodo* Radice=malloc(sizeof(Nodo));
    printf("%d", Radice);
    Radice->Padre=NULL;
    Insert_Albero(&Radice);

    return 0;
}
