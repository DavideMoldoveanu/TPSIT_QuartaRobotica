#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int n;
    struct nodo* next;
}Nodo;

int is_empty(Nodo *head){
    if (head == NULL)
    {
        return 1;
    }else
    {
        return 0;
    } 
}

void enqueue(Nodo** head, Nodo** tail, Nodo* element){
    
    if(is_empty(*head))
        *head = element;
    else
        (*tail)->next = element;
    
    *tail = element;
    element->next = NULL;

    return;
}

Nodo* dequeue(Nodo** head, Nodo** tail){
    
    Nodo* ret = *head;

    if(is_empty(*head))
        return NULL;
    else
        *head = ret->next;
    
    if(*head == NULL)
        *tail = NULL;

    return ret;
}

void stampaCoda(Nodo **head, Nodo **tail){

    Nodo* valore = (Nodo*) malloc(sizeof(Nodo));
    valore = dequeue(head, tail);

    while (valore != NULL) {
        printf("%d\n",valore->n);
        valore = dequeue(head, tail);
    }
    free(valore);
}

void main(){
    Nodo *head = NULL;
    Nodo *tail = NULL;
    Nodo* element = NULL;
    int risposta;

    do{

        element = (Nodo*) malloc(sizeof(Nodo));
        printf("Inserisci un valore: ");
        scanf("%d", &element->n);

        enqueue(&head, &tail, element);

        printf("Inserisci 0 se vuoi uscire. || Inserisci 1 per continuare: ");
        fflush(stdin);
        scanf("%d", &risposta);

    }while(risposta != 0);
    
    stampaCoda(&head, &tail);
    
}