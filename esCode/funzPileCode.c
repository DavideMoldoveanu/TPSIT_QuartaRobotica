#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct El{
    int valore;
    struct El* next;
}El;

//PILE----------------------------------------------------------------------------------------------------

int is_empty(struct El* head){
    if (head == NULL) return 1;
    else return 0;
}

void push(struct El** pila, struct El* element){
	if (&pila==NULL){
		*pila = element;
		element->next = NULL;
	}else{
		element->next = *pila;
		*pila = element;
	}
}

struct El* pop(struct El** pila){
	struct El *ret = *pila;
	if(&pila==NULL){
		return NULL;
	}else{
		*pila = ret->next;
	}
	return ret;
}

void stampaPila(struct El* l){
    while(!is_empty(l)){
        printf("%d",pop(&l)->valore);
    }
}

void stampaListaRec(struct El* l){  //inserire l'inizio della lista
    if(l!=NULL){    //ripeto finchè esiste un elemento successivo
        printf("%c \n",l->valore);    //stampo il valore dell'elemento della lista e l'indirizzo del successivo
        l=l->next; //passo all'elemento successivo della lista
        stampaListaRec(l); //passo all'elemento successivo
    }
    return;
}

void inverti(struct El **head){
    struct El *val;
    val = pop(head);
    while (val != NULL)     //eseguo il ciclo finché ci sono elementi e val non ha valore di NULL
    {
        printf("%d",val->valore);
        free(val);
        val = pop(head);    //inserisco in val il prossimo elemento
    }    
}

//CODE----------------------------------------------------------------------------------------------------

void enqueue(struct El **head, struct El **tail, struct El *element){

    if(is_empty(*head)){
        *head = element;
    }else{
        (*tail)->next=element;
    }
    *tail = element;
    element->next=NULL;    
}

struct El * dequeue(struct El **head, struct El **tail){
    struct El *ret = *head;
    if(is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }
    if (*head==NULL){
        *tail = NULL;
    }
    return ret;
}

void push (struct El **head, struct El** tail, struct El *element){    //inverto la coda
    struct El* supportHead = NULL;
    struct El* supportTail = NULL;
    struct El* element2;

    while (!is_empty(*head)){
        element2 = dequeue(head,tail);
        enqueue(&supportHead, &supportTail, element2);
    }

    enqueue(head, tail, element);

    while (!is_empty(supportHead)){
        enqueue(head, tail, dequeue(&supportHead, &supportTail));
    }
}

void stampaCoda(struct El** head, struct El** tail){

    struct El* valore = (struct El*) malloc(sizeof(struct El));
    valore = dequeue(head, tail);

    while (valore != NULL) {
        printf("%d\n",valore->valore);
        valore = dequeue(head, tail);
    }
    free(valore);
}