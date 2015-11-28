#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("FUNZIONA tutto!");
    pid=fork();
    if (pid==1)
        exit;
}
