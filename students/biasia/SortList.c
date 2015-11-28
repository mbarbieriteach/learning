#include<stdio.h>
#include<stdlib.h>




struct n_Nodo
{
    int valore;
    struct n_Nodo* Next;
};
typedef struct n_Nodo Nodo;


void SortList(Nodo* N)
{
    int tmp;
    int ordinato=0;
do{
        do {
               if(N->Next->valore>N->valore)
               {
                   tmp=N->valore;
                   N->valore=N->Next->valore;
                   N->Next->valore=tmp;
                   ordinato =0;

               }
               else {
                    ordinato=1;
                    }

               if(N->Next!=NULL)
               {
                   N=N->Next;
               }

       }while(N->Next!=NULL);

}while(N->Next!=N&&ordinato==0);

}
void Inserisci(int n_nodi,Nodo* Testa)
{

    Nodo* PLocomotore;
    Nodo* PCarrozza;

        PLocomotore = NULL;
        PCarrozza = NULL;

            PCarrozza = malloc (sizeof(Nodo));
            printf("Inserisci il valore nel nodo 1 : ");
            scanf("%d",&PCarrozza->valore);
            PCarrozza->Next = NULL;
            PLocomotore = PCarrozza;

            for ( int i = 1; i < n_nodi ; i++)
            {
                PCarrozza = malloc (sizeof(Nodo));
                printf("Inserisci il valore nel nodo %d : ",i+1);
                scanf("%d",&PCarrozza->valore);
                PCarrozza->Next = PLocomotore;
                PLocomotore = PCarrozza;
            }
        Testa=PLocomotore;

}



int main()
{
    Nodo* testa;
    testa =malloc(sizeof(Nodo));
    int n_Nodi=5;
    Inserisci(n_Nodi,testa);
    SortList(testa);


return 0;
}
