#include <stdio.h>
//#include "grafi.h"
#include <stdlib.h>

typedef char graphElementT;

//vertice
typedef struct vertexTag {
    graphElementT element;         //nome del vertice
    int visted;                    //flag di visita
    struct edgeTag* edges;         //lisstadi collegamneti
    struct vertexTag* next;        //collegamento a nodo sequente
}vertexT;

//arco orientato
typedef struct edgeTag{
    struct vertexTag* connectsTo;   //vertice a cui si è collegato
    struct edgeTag* next;           //puntatore al collegamneto succesivo
}edgeT;

//grafo
typedef struct graphCDT {
    vertexT* vertices;              //puntatore al primo elemnto dellalista
}graphCDT;


/*sottoprogramma cre ritorna un puntatore ad una lista di archi acui un possibile vertice possiede
non aggiunge un solo arco ma tutti quelli si consiglia di utilizzarla anche dopo aver creato il l'insieme
di vertici perche se no non appariranno tutti i possibili collegamenti

    è presente una funzione che fa aggiungere tutti i possibili vertici di tutti i nodiutiliare quello al fine dell'inserimento principale

*/
edgeT* graph_add_edge(graphCDT* testa){
    vertexT* alpha=testa->vertices;
    edgeT* list=NULL;
    edgeT* l_tmp=list;



    while(alpha!=NULL){
        printf("Vuoi aggingere il vertice %c (0 per si 1 per no) ?",alpha->element);
        int tmp;
        scanf("%d",&tmp);
        if(tmp==0&&list==NULL){                     //se la lista è vuota aggingo il collegamento direttamente da li
            l_tmp=malloc(sizeof(edgeT));
            l_tmp->next=NULL;
            l_tmp->connectsTo=alpha;
        }else if(tmp==0){                           //altrimenti insrisco il collegamento in fondo alla lista e scorrp l_tmp(variabiole temporanea che utilizzo per scorrere la lista di archi)
            edgeT* local_tmp=malloc(sizeof(edgeT));   //aggiongo i vari collegamenti ai vertici e passo a quella succesiva
            local_tmp->next=NULL;
            local_tmp->connectsTo=alpha;
            l_tmp->next=local_tmp;
            l_tmp=l_tmp->next;
        }else if(tmp==1)
            printf("\nVertice non inserito\n");
        alpha=alpha->next;
    }

    return list;                                    //ritorno il puntatore della lista
}

void graph_add_vertex(graphCDT* testa){
    vertexT* vert=testa->vertices;

    //alloco un nuovo vertice
    vertexT* tmp=malloc(sizeof(vertexT));
    tmp->next=NULL;                     //il succesivo punterà a ninete
    tmp->visted=0;                      //non sarà visitato
    tmp->edges=NULL//graph_add_edge(testa);   //aggiungo i vari colegamenti
    printf("\nInserire il nome del vertice");
    scanf("%c",tmp->element);           //input del nome dell'elemento

    //lo aggiungo alla lista principale
    if (vert==NULL){
        testa->vertices=tmp;
    }else{
        while(vert->next!=NULL)
            vert=vert->next;
        vert->next=tmp;
    }
}

void crea_edge(graphCDT* testa){
    vertextT* vert=testa->vertices;
    while(testa!=NULL){
        testa->edges=raph_add_edge(testa);
        testa=testa->next;
    }
}

int main(){

    return 0;
}
