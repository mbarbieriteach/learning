#include <stdlib.h>
#include <stdio.h>
#define fflush(stdin) while ((getchar()) != '\n') //per evitare problemi con lo scanf

//----------------------------------------------------------------------------//
typedef struct vertexT{
    char vName;
    struct edgeT* eNext;
    struct vertexT* next;
}vertex;                
typedef struct edgeT{
    int weight;
    struct vertexT* arc;
    struct edgeT* next;
}edge;
//----------------------------------------------------------------------------//
void addVertex(vertex** graph,char name) {
    vertex* newVert = malloc(sizeof(vertex));
    vertex* last = *graph;
    while(last!=NULL)
    {
        if(last->vName == name)
        {
            printf("Error: Vertex is already existent\n");
            return;
        }
        last = last->next;
    }
    newVert->vName = name;
    newVert->eNext = NULL;
    newVert->next = NULL;
    if(*graph == NULL)
        *graph = newVert;
    else{
        last = *graph; 
        while(last->next != NULL)
            last=last->next;
        last->next=newVert;
    }
}
void addEdge(vertex* graph,char srcname,char destname,int edgeweight){
    if(graph == NULL){return;}
    vertex* src = graph;
    vertex* dest = graph;
    while(src->vName != srcname){
        src= src->next;
        if(src == NULL){
            printf("Error 404.1: Source node not found\n");
            return;
        }
    }
    while(dest->vName != destname){
        dest= dest->next;
        if(dest == NULL){
            printf("Error 404.2: Destination node not found\n");
            return;
        }
    }
    edge* newEdge = malloc(sizeof(edge));
    newEdge->arc = dest;
    newEdge->weight = edgeweight;
    newEdge->next = NULL;
    edge* last = src->eNext;
    while(last!=NULL)
    {
        if(last->arc->vName == destname)
        {
            printf("Error: Edge is already existent\n");
            return;
        }
        last = last->next;
    }
    if(src->eNext == NULL)
        src->eNext = newEdge;
    else{
        last = src->eNext;
        while(last->next != NULL){
            last=last->next;
        }
        last->next=newEdge;
    }
}
void printInc(char** array,int m, int n){
    FILE* text = fopen("ematrix","w");
    int i,j;
    for(i = 0; i < m; i++){
        if(i != 1 || i != 2){
            fprintf(text,"|----");
            for(j = 1; j < n; j++)
                fprintf(text,"+----");
            fprintf(text,"|\n");
        }
        for(j = 0; j < n; j++)
            fprintf(text,"| %c ",array[i][j]);
        fprintf(text,"|\n");
    }
        fprintf(text,"|----");
        for(j = 1; j < n; j++)
            fprintf(text,"+----");
        fprintf(text,"|\n");
    fclose(text);
}
int isReachable(vertex* graph, char srcname, char destname,char mode){
    if(graph == NULL){
        printf("Can't search in empty list. Aborting function.\n");
        return 0;
    }
    vertex* srcvert = graph;
    while(srcvert->vName != srcname){
        srcvert= srcvert->next;
        if(srcvert == NULL){
            if(mode != 'c'){printf("Error 404.1: Source node non existent\n");}
            return 78;
        }
    }
    edge* destedge;
    if((destedge = srcvert->eNext) == NULL)
    {
        if(mode != 'c'){printf("Error: source doesn't have edges");}
        return 78;
    }
    while(destedge->arc->vName != destname){
        destedge= destedge->next;
        if(destedge == NULL){
            if(mode != 'c'){printf("Can't find edge\n");}
            return 78;
        }
    }
    if(mode != 'c'){printf("Operation completed, edge found successfully\n");}
    return 1;
}
void pmllist(vertex* graph){           //print multi linked list
    if(graph == NULL){
        printf("Can't print NULL list. Aborting function.\n");
        return;
    }
    printf("$$$$$$$$$$$$$$$$$START$PRINT$$$$$$$$$$$$$$$$$$$\n");
    while(graph!=NULL){
        edge* lastedge = graph->eNext;
        printf("||=====||\n");
        printf("||-----||");
        while(lastedge!=NULL){
             printf("-----|");
             lastedge = lastedge->next;
        }
        printf("\n||");
        lastedge = graph->eNext;
        printf("  %c  ||",graph->vName);
        while(lastedge!=NULL){
             printf("  %c  |",lastedge->arc->vName);
             lastedge = lastedge->next;
        }
        printf("\n||-----||");
        lastedge = graph->eNext;
        while(lastedge!=NULL){
             printf("-----|");
             lastedge = lastedge->next;
        }
        printf("\n");
        graph = graph->next;
    }
    printf("||=====||\n");
    printf("$$$$$$$$$$$$$$$$$$$$END$$$$$$$$$$$$$$$$$$$$$$$$\n");
}// Copyright Silver & Basso(2015), licensed under creative commons

void fpmllist(vertex* graph){           //print multi linked list on file
    FILE* text = fopen("graph","w");
    if(graph == NULL){
        fprintf(text,"Can't print NULL list. Aborting function.\n");
        return;
    }
    fprintf(text,"./=====\\.\n");
    while(graph!=NULL){
        edge* lastedge = graph->eNext;
        fprintf(text,"||=====||");
        while(lastedge!=NULL){
            if(lastedge->weight<10)
                 fprintf(text,"  %d  .",lastedge->weight);
            else
                fprintf(text,"  %d .",lastedge->weight);
            lastedge = lastedge->next;
        }
        lastedge = graph->eNext;
        fprintf(text,"\n||-----||");
        while(lastedge!=NULL){
             fprintf(text,"-----|");
             lastedge = lastedge->next;
        }
        fprintf(text,"\n||");
        lastedge = graph->eNext;
        fprintf(text,"  %c  ||",graph->vName);
        while(lastedge!=NULL){
             fprintf(text,"  %c  |",lastedge->arc->vName);
             lastedge = lastedge->next;
        }
        fprintf(text,"\n||-----||");
        lastedge = graph->eNext;
        while(lastedge!=NULL){
             fprintf(text,"-----|");
             lastedge = lastedge->next;
        }
        fprintf(text,"\n");
        graph = graph->next;
    }
    fprintf(text,"||=====||\n");
    fprintf(text,"°\\=====/°\n");
    fclose(text);
}
void vertexInit(vertex** graph){
    char ch,a;
    do{
        printf("Do u want to add a new vertex? [y/n]: ");
        scanf("%c",&ch);
        fflush(stdin);
        if(ch != 'n' && ch != 'y'){
            printf("invalid character input\n");
            ch = 'y';
        }
        else if(ch == 'y'){
            printf("Insert vertex name (max 1 char): ");
            char a;
            scanf("%c",&a);
            fflush(stdin);
            addVertex(graph,a);
            fpmllist(*graph);
        }
    }while(ch == 'y');
//-------------------------------------------------------------------------------------//
    /*printf("You completed the vertex input, do u want to print the list? [y/n]: ");
    do{
        scanf("%c",&ch);
        fflush(stdin);
        if(ch == 'y'){pmllist(*graph);}
        else if (ch!='n'){
            printf("invalid character input\n");
        }
    }while(ch != 'y' && ch != 'n');*/
//-------------------------------------------------------------------------------------//
    do{
        printf("Do u want to add a new edge? [y/n]: ");
        scanf("%c",&ch);
        fflush(stdin);
        if(ch != 'n' && ch != 'y'){
            printf("invalid character input\n");
            ch = 'y';
        }
        else if(ch == 'y'){
            char b;
            int c;
            printf("Insert vertex name (max 1 char): ");
            scanf("%c",&a);
            fflush(stdin);
            printf("Insert vertex destination name (max 1 char): ");
            scanf("%c",&b);
            fflush(stdin);
            printf("Insert edge weight: ");
            scanf("%d",&c);
            fflush(stdin);
            addEdge(*graph,a,b,c);
            fpmllist(*graph);
        }
    }while(ch == 'y');
//-------------------------------------------------------------------------------------//
    /*printf("You completed the edge input, do u want to print the list? [y/n]: ");
    do{
        scanf("%c",&ch);
        fflush(stdin);
        if(ch == 'y'){pmllist(*graph);}
        else if (ch!='n'){
            printf("invalid character input\n");
        }
    }while(ch != 'y' && ch != 'n');*/
//-------------------------------------------------------------------------------------*//*
    printf("Graph creation complete.\n");
    do{
        printf("Do u want to search an edge? [y/n]: ");
        scanf("%c",&ch);
        fflush(stdin);
        if(ch != 'n' && ch != 'y'){
            printf("invalid character input\n");
            ch = 'y';
        }
        else if(ch == 'y'){
            char a,b;
            printf("Insert vertex name (max 1 char): ");
            scanf("%c",&a);
            fflush(stdin);
            printf("Insert vertex destination name (max 1 char): ");
            scanf("%c",&b);
            fflush(stdin);
            isReachable(*graph,a,b,'t');
        }
    }while(ch == 'y');
}
int vlength(vertex* graph){
    int i=0;
    vertex* tmp = graph;
    while(tmp!=NULL){
        i++;
        tmp = tmp->next;
    }
    return i;
}
int elength(vertex* graph){
    int i=0;
    edge* counter = malloc(sizeof(edge));
    while(graph!=NULL){
        counter = graph->eNext;
        while(counter != NULL){
            i++;
            counter=counter->next;
        }
        graph=graph->next;
    }
    return i;
}
void adiacenze_mtx(vertex* graph){
    int i,j,l=1,N = 1+vlength(graph);
    char amtx[N][N];
    vertex* tmp = graph;
    amtx[0][0] = '-';
    while(tmp!=NULL){
        amtx[0][l]=tmp->vName;
        amtx[l][0]=tmp->vName;
        tmp=tmp->next;
        l++;
    }
    tmp = graph;
    edge* etmp = tmp->eNext;
    for(i=1;i<N;i++){
        for(j=1;j<N;j++){
            if(isReachable(graph,amtx[i][0],amtx[0][j],'c')==1){
                int x = etmp->weight;
                if(x<9)
                    amtx[i][j] = (char)(48+x);
                else{
                    amtx[i][j] = '#';
                    printf("Peso[%c][%c] = %d\n",amtx[i][0],amtx[0][j],x);
                }
                if(etmp->next!=NULL)
                    etmp=etmp->next;
            }
            else
                amtx[i][j] = '~';
        }
        tmp = tmp->next;
        if(tmp != NULL)
            etmp=tmp->eNext;
    }
    FILE* text = fopen("amatrix","w");
    for(i = 0; i < N; i++){
        fprintf(text,"|---");
        for(j = 1; j < N; j++)
            fprintf(text,"+---");
        fprintf(text,"|\n");
        for(j = 0; j < N; j++)
            fprintf(text,"| %c ",amtx[i][j]);
        fprintf(text,"|\n");
    }
        fprintf(text,"|---");
        for(j = 1; j < N; j++)
             fprintf(text,"+---");
        fprintf(text,"|\n");
    fclose(text);
}
void incidenza_mtx(vertex* graph){
    int i,j,l,N = 3+vlength(graph),M = 1+elength(graph);
    char amtx[N][M];
    vertex* tmpv = graph;
    amtx[0][0] = '-';
    amtx[1][0] = '-';
    amtx[2][0] = '-';
    l=3;
    while(tmpv!=NULL){
        amtx[l][0]=tmpv->vName;
        tmpv=tmpv->next;
        l++;
    }
    tmpv = graph;
    edge* tmpe = malloc(sizeof(edge));
    l = 1;
    while(tmpv!=NULL){
        tmpe = tmpv->eNext;
        while(tmpe!=NULL){
            amtx[0][l]=tmpv->vName;
            amtx[1][l]='v';
            amtx[2][l]=tmpe->arc->vName;
            tmpe = tmpe->next;
            l++;
        }
        tmpv=tmpv->next;
    }
    tmpv = graph;
    vertex* tmpvv = tmpv; 
    i=3,j=1;
    for(i=3;i<N;i++)
        for(j=1;j<M;j++)
            if(amtx[i][0] == amtx[2][j])
                amtx[i][j] = '1';
            else
                amtx[i][j] = '~';
    FILE* text = fopen("ematrix","w");
    for(i = 0; i < N; i++){
        if(i != 1 && i != 2){
            fprintf(text,"|---");
            for(j = 1; j < M; j++)
                fprintf(text,"+---");
            fprintf(text,"|\n");
        }
        for(j = 0; j < M; j++)
            fprintf(text,"| %c ",amtx[i][j]);
        fprintf(text,"|\n");
    }
        fprintf(text,"|---");
        for(j = 1; j < M; j++)
             fprintf(text,"+---");
        fprintf(text,"|\n");
    fclose(text);
}/*
vertex* bbsortricvertex(vertex* graph,vertex* p,int count){
    if(p->next == NULL)                                 //controllo fine lista
        if(count)                                       //count controlla l'ordinamento completato
            return bbsortricvertex(graph,graph,0);              //scorro la lista da zero
        else
            return graph;                                //ritorno la lista ordinata (al main)
    else{
        if(p->vName > p->next->vName){                    //controllo valori p1>p2
            edge* tmpe = p->eNext;
            edge* tmpee = p->next->eNext;
            
            char tmp = p->vName;
            p->vName = p->next->vName;
            p->next->vName = tmp;
            
            p->eNext = NULL;
            while(tmpee!=NULL){
                addEdge(graph, p->vName, tmpee->arc->vName, tmpee->weight);
                tmpee = tmpee->next;
            }
            free(tmpee);
            p->next->eNext = NULL;
            while(tmpe!=NULL){
                addEdge(graph, p->next->vName, tmpe->arc->vName, tmpe->weight);
                tmpe = tmpe->next;
            }
            free(tmpe);
            count=1;
                          //necessario al controllo seguente (ricorda gli scambi)
        }
        return bbsortricvertex(graph,p->next,count);           //scorre la lista dalla prima all'ultima posizione
    }
}*/
vertex* list_switch( vertex* l1, vertex* l2 )
{
    l1->next = l2->next;
    l2->next = l1;
    return l2;
}
vertex* sort( vertex* start )
{
    vertex *p, *q, *top;
    int changed = 1;
    top->next = start;
    if( start != NULL && start->next != NULL ) {
        while( changed ) {
            changed = 0;
            q = top;
            p = top->next;
            while( p->next != NULL ) {
                if( p->vName > p->next->vName ) {
                    q->next = list_switch( p, p->next );
                    changed = 1;
                }
                q = p;
                if( p->next != NULL )
                    p = p->next;
            }
        }
    }
    p = top->next;
    free( top );
    return p;
}


int main () {
    
    vertex* graph = NULL;
    //vertexInit(&graph);
    addVertex(&graph,'C');
    addVertex(&graph,'D');
    addVertex(&graph,'B');
    addVertex(&graph,'A');
    addEdge(graph,'A','B',5);
    addEdge(graph,'D','B',6);
    addEdge(graph,'D','A',7);
    addEdge(graph,'C','D',8);
    adiacenze_mtx(graph);
    incidenza_mtx(graph);
    //bbsortricvertex(graph,graph,0);
    //vertex* bbgraph = sort(graph);
    sleep(1);
    fpmllist(graph);
    return 0;
}
