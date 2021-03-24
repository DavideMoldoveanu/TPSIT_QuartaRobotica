#include <stdio.h>
#include <stdlib.h>
struct El{
    int valore;
    struct El *next;
};

void push(struct El* l,int v){
    struct El* temp;
    temp = l;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = (struct El *)malloc(sizeof(struct El));
    temp->next->valore = v;
    temp->next->next = NULL;
}

void stampaLista(struct El* l){
    while(l!=NULL){
        printf("%d - %p \n",l->valore, l->next);
        l=l->next;
    }
}

int main()
{
    int n;
    struct El *lista;
    lista = NULL; 

    do
    {
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if (n >= 0)
        {
            if (lista == NULL) 
            {
                lista = (struct El *)malloc(sizeof(struct El));   
                lista->valore = n;
                lista->next = NULL;
            }else{  
                
                push(lista,n);
            }
            
        }
    } while (n >= 0);

    printf("numeri inseriti: \n");

    stampaLista(lista);

    printf("\n");

    return 0;
}