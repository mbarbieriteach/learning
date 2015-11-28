void Ordina(nodo** seguence)
{
    int tmpV=9999;
    nodo* memory;
    nodo* puntaglobale = *sequence;
    int tmp;
    while((*puntaglobale!=NULL))
    {
        while((*seguence)->next!=NULL)
        {
            if(tmpV > (*seguence)->dato)
            {
                memory = *seguence;
                tmpV = (*seguence)->dato;
                printf("%d",tmpV);
            }
            *seguence = (*seguence)->next;
        }
        tmp = (*puntaglobale->dato)

    }

}
