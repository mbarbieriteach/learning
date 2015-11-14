#include <stdio.h>
//#include "grafi.h"
#include <stdlib.h>

typedef char graphElementT;

//vertice
typedef struct vertexTag {
    graphElementT element;         //nome del vertice
    int visted;                    //flag di visita
    struct edgeTag *edges;         //lisstadi collegamneti
    struct vertexTag *next;        //collegamento a nodo sequente
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

edgeT* graph_add_edge(graphCDT* testa){
    vertexT* alpha=testa->vertices;
    edge* list=NULL;



    while(alpha!=NULL){
        printf("Vuoi aggingere il vertice %c?",alpha->element);

    }

    return list;
}

void graph_add_vertex(graphCDT* testa){
    vertexT* vert=testa->vertices;

    //alloco un nuovo vertice
    vertexT* tmp=malloc(sizeof(vertexT));
    tmp->next=NULL;                     //il succesivo punterà a ninete
    tmp->visted=0;                      //non sarà visitato
    tmp->edges=graph_add_edge(*testa);   //aggiungo i vari colegamenti
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
