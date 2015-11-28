#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK 1000
typedef struct
{
   char array[MAX_STACK];
   int indice ;
}Stack;

void push(Stack pila, char a)
{
  if(pila.indice == MAX_STACK)
    printf("Stack Overflow");
  else
  {
    pila.array[pila.indice] = a;
    pila.indice++;
  }
}

int pop(Stack pila)
{
  if(pila.indice == MAX_STACK)
    printf("\nStack Overflow");
  else
  {
    pila.indice--;
  }
    return pila.indice;
}

 void controllo(char stringa [] ,int N ,Stack pila)
{
    int b = 1;
    for ( int i = 0  ; i < N ; i++)
    {
        if (stringa[i] == '(')
            push(pila,stringa[i]);
        if (stringa[i] == ')')
             b =  pop(pila);
    }

    if ( b == 0 )
        printf("Stringa Corretta");
    else
        printf("Stringa Errata");

}

int main()
{
    int N = 10 ;
    Stack pila;
    pila.indice = 0;
    char stringa [N];
    printf("Inserisci la stringa : ");
    scanf("%s",&stringa);
    controllo(stringa,N,pila);

    return 0;
}
