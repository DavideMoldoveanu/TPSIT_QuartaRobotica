#include <stdio.h>
#include <stdlib.h>
#define DIM 1000

/*
Creare un programma che dato un numero intero, avente un numero arbitrario di cifre inserite
dall’utente, lo scriva in output con le cifre in ordine inverso. Utilizzare una pila e le implementazioni
dei metodi push e pop.
*/

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

void push (Nodo **head, Nodo *element){
    if (is_empty(*head))                //if (is_empty(*head) == NULL)
    {
        *head = element;
        element->next = NULL;
    }else
    {
        element->next = *head;
        *head = element;
    }
}

Nodo* pop(Nodo **head){
    Nodo* ret = *head;

    if (is_empty(*head))
    {
        return NULL;
    }else
    {
        *head = ret->next;
    }

    return ret;
}

void inverti(Nodo **head){
    Nodo *val;
    val = pop(head);
    while (val != NULL)     //eseguo il ciclo finché ci sono elementi e val non ha valore di NULL
    {
        printf("%d",val->n);
        free(val);
        val = pop(head);    //inserisco in val il prossimo elemento
    }    
}

int main(){
    Nodo* head;
    Nodo* element;
    char nInString[DIM];

    printf("Inserisci numero: ");
    fflush(stdin);
    scanf("%s", nInString);

    //carico nella pila
    for (int i = 0; nInString[i] != '\0'; i++)
    {
        element = (Nodo*) malloc(sizeof(Nodo));
        element->n = nInString[i] - 48;         //converto il carattere numero in numero intero
        push(&head, element);
    }

    printf("Caricamento completato, ora stampo i numeri al contrario:\n");

    inverti(&head);

    return 0;
    

    
}