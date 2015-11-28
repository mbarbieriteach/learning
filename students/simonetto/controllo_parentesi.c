#include <stdio.h>
#include <stdlib.h>

int MAX_LENG_STRING=100;

//implementazione di pila
typedef struct nodo{
    char info;
    struct nodo* next;
}node;
int length(node* top, int i){
    if(top != NULL)
		return length(top->next,++i);
	else
		return i;
}
void clear(node** top)
{
	if(*top !=NULL)
	{
		node* x = *top;
		*top = (*top)->next;
		free(x);
		clear(top);
	}
}
//ritorna 1 se la pila non è vuota
int piena(node** top){
    if(*top!=NULL)
        return 1;
    return 0;
}
//aggiunge il nodo desiderato,ritorna 1 se incontra errori
int push(node** top,char value){
    node* newNodo = malloc(sizeof(node*));
    if (newNodo==NULL)
        return 1;
    newNodo->info = value;
    newNodo->next = *top;
    *top = newNodo;
    return 0;
}
//ritorna puntatore a nodo desiderato si raccomanda usare il free() dopo aver estratto i dati necessari
node* pop(node** top){
    if (*top==NULL)
        return NULL;
    node* x = *top;
    *top = (*top)->next;
    return x;
}

int controlla_parentesi(char V[]){
    int i=0;
    node* testa=NULL;
    while(i<MAX_LENG_STRING && V[i]!='\0'){
        if(V[i]=='(')
            push(&testa,'(');
        if(V[i]==')'){
            node* tmp=pop(&testa);
            if(tmp==NULL)
                return 1;
            free(tmp);
        }
        i++;
    }
    return piena(&testa);
}

int main(){
    char V[MAX_LENG_STRING];
    printf("Digitare la stringa che si vuole controllare\n");
    //scanf("%s",V);
    fgets(V,MAX_LENG_STRING, stdin);//uso questa funzione per prelevare le stringhe con gli spazi

    if(controlla_parentesi(V)==0)
        printf("\nLa stringa e' corretta");
    else
        printf("\nLa stringa non e' corretta");

    return 0;
}

