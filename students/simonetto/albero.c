#include <stdio.h>
#include <stdlib.h>

//numero del prossimo vertice da inserire
int n_vet=0;

//definizione di albero binario
typedef struct ab_nodo{
    int dato;               //numero dell'albero;
    struct ab_nodo* DX;     //puntatore a figlio destro
    struct ab_nodo* SX;     //puntatore a figlio sinistro
}nodo;

//stampa in profondità
void stampa(nodo* radice){
    if(radice!=NULL){
        printf("\nRadice %d albero DX",radice->dato);
        stampa(radice->DX);
        printf("\nRadice %d albero SX",radice->dato);
        stampa(radice->SX);
    }
};

//funzione che ritorna il un puntatore ad un nodo già identato e con figli = ad NULL
nodo* crea_nodo(){
    nodo* tmp=malloc(sizeof(nodo));
    tmp->dato=n_vet;
    n_vet++;                //incremento questa variabile per inserire il nodo succesivo
    tmp->DX=NULL;           //NON Possiede figli
    tmp->SX=NULL;           //" "  "   "    " "
    return tmp;
}

int decisione(){
    int tmp=-1;
    while(tmp!=1||tmp!=0){
        printf("\nInserire 0 per si o 1 per no ");
        scanf("%d",&tmp);
    }
    return tmp;
}

//funzione che scoore l'albero al fine di allocare il prossimo figlio
void alloca_figlo(nodo* radice){

        //controllo se la radice ha figlio destro
        if(radice->DX==NULL){
            printf("\nLa radice %d non ha figli a destra.Si desidera iplementare il prossimo figlio qui?",radice->dato);
            if(decisione()){
                radice->DX=crea_nodo();
                return;
            }
        }else{  //altrimenti chiedo se vuole scorrere il figio
            printf("\nLa radice &d ha già un figio a DX paassare a questo nodo per inserire il prossimo figio?");
            if(decisione()){
                alloca_figlo(radice->DX);
                return;
            }
        }

        //faccio lo stesso a sinistra
        if(radice->SX==NULL){
            printf("\nLa radice %d non ha figli a sinistra.Si desidera iplementare il prossimo figlio qui?",radice->dato);
            if(decisione()){
                radice->SX=crea_nodo();
                return;
            }
        }else{  //altrimenti chiedo se vuole scorrere il figio
            printf("\nLa radice &d ha già un figio a SX paassare a questo nodo per inserire il prossimo figio?");
            if(decisione()){
                alloca_figlo(radice->SX);
                return;
            }
        }


}

int main(){
    //creo l'albero binario
    nodo* radice = crea_nodo();

    printf("\nSi vuole inserire dei figli?");
    
    //non entra nel ciclo ma la funzione decisiione all'infinito
    while(decisione()){
        printf("\nSi procede con l'inserimento di %d\n",n_vet);
        alloca_figlo(radice);
        printf("\nContinuare?");
    }

    stampa(radice);

    return 0;
}
