#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct indirizzo{
    char provincia[2];
    char citta[10];
    char via[10];
    char n_c[3];
};

struct studente{
    char* nome;
    char* cognome;
    short matricola;
    struct indirizzo abitazione;
};

struct studente V[1000];

short hash(const char* zKey, int iPrecision /*= 6*/)
{
        /////FROM : http://courses.cs.vt.edu/~cs2604/spring02/Projects/4/elfhash.cpp

        unsigned long h = 0;
        long M = pow(10, iPrecision);

        while(*zKey)
        {
                h = (h << 4) + *zKey++;
                unsigned long g = h & 0xF0000000L;
                if (g) h ^= g >> 24;
                h &= ~g;
        }

        return (unsigned short) ((h % M)/1000);
}



void inserimento(){
    char nome[10];
    char cognome[10];
    fflush(stdin);
    printf("Insertisci il nome ");
    fgets(nome, 10, stdin);
    fflush(stdin);
     printf("Insertisci il cognome ");
    fgets(cognome, 10, stdin);
    char* nc;
    nc=strcat(nome,cognome);
    int t=hash(nc,6);
    V[t].nome=nome;
    V[t].cognome=cognome;
    V[t].matricola=t;

    fflush(stdin);
    printf("Insertisci la provincia ");
    fgets(V[t].abitazione.provincia, 2, stdin);

    fflush(stdin);
    printf("Insertisci la citta' ");
    fgets(V[t].abitazione.citta, 10, stdin);

    fflush(stdin);
    printf("Insertisci la via ");
    fgets(V[t].abitazione.via, 10, stdin);

    fflush(stdin);
    printf("Insertisci il numero civico ");
    fgets(V[t].abitazione.n_c, 3, stdin);
}

void ricerca(){
    char nome[10];
    char cognome[10];
    fflush(stdin);
    printf("Insertisci il nome ");

    fgets(nome, 10, stdin);
    fflush(stdin);
     printf("Insertisci il cognome ");
    fgets(cognome, 10, stdin);
    char* nc;
    nc=strcat(nome,cognome);
    int t=hash(nc,6);

    printf("\nMatricola %d",V[t].matricola);

    printf("\nAbita a %s (%s) via %s %s",V[t].abitazione.citta,V[t].abitazione.provincia,V[t].abitazione.via,V[t].abitazione.n_c);
}

int main(){
    int tmp=0;
    do{
        inserimento();
        printf("\nContinuare l'inserimento? 0=si\n");
        scanf("%d",&tmp);
    }while(tmp==0);
    do{
        ricerca();
        printf("\nContinuare la ricerca? 0=si");
        scanf("%d",&tmp);
    }while(tmp==0);
}
