#include<stdio.h>
#include<stdlib.h>

struct s_nodo{
    int dato;
    struct s_nodo* next;
};

typedef struct s_nodo nodo;

void print(nodo** seguence){
    nodo* tmp=*seguence;
    while(tmp!=NULL){
        printf("%d ",tmp->dato);
        tmp=tmp->next;
    }
    printf("\n");
}

void insert_at(nodo** seguence,int dato,int pos){
    nodo* n=malloc(sizeof(nodo));
    n->dato=dato;

    if(*seguence==NULL){
        n->next=NULL;
        *seguence=n;
    }else{
        if(pos==0){
            n->next=*seguence;
            *seguence=n;
        }else{
            nodo* tmp=*seguence;
            nodo* prev=tmp;
            int i=0;
            while(tmp!=NULL&&i<pos){
                prev=tmp;
                tmp=tmp->next;
                i++;
            }
            prev->next=n;
            n->next=tmp;
        }
    }
}

void unisci(nodo** testa1,nodo** testa2){
    nodo* tmp=*testa1;
    if(tmp!=NULL){
        while(tmp->next!=NULL)
            tmp=tmp->next;
        tmp->next=*testa2;
        *testa2=*testa1;
    }else{
        *testa1=*testa2;
    }
}

void Ordina(nodo** seguence){

    int tmp=1;/*variabile utilizzata per verificae se si sono effetuati ordinamenti in questo turno*/
    nodo* finale;
    nodo* post;
    finale=NULL;

    printf("a");

    while(tmp==1){
        tmp=0;
        nodo* N_nodo=*seguence;
        post=N_nodo;
        nodo* sup=finale;

            printf("b");

        while(post!=sup){

                    printf("c");

            post=post->next;
            if(N_nodo->dato>post->dato){
                tmp=1;
                printf("d");
                nodo* n_tmp=post;  /*non funziona il cambio indirizzi*/
                post=N_nodo;
                N_nodo->next=n_tmp;
                finale=post;
            }
            N_nodo=N_nodo->next;

                printf("e");

        }
    }

}

int main()
{
    nodo* head;
    head=NULL;
    insert_at(&head,1,0);
    insert_at(&head,2,0);
    insert_at(&head,3,0);
    insert_at(&head,4,0);
    insert_at(&head,5,0);

    print(&head);

    Ordina(&head);

    print(&head);

    return 0;
}
