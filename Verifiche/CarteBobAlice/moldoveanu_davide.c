#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>



struct El{
    char seme;
    char val;
    struct El* next;
}El;

int is_empty(struct El *head){
    if (head == NULL)
    {
        return 1;
    }else
    {
        return 0;
    } 
}

void push (struct El **head, struct El *element){
    if (is_empty(*head))                //if (is_empty(*head) == NULL)
    {
        *head = element;            //se vero assegno il valore passato nell'head
        element->next = NULL;       //e creo spazio libero nella cella futura
    }else
    {
        element->next = *head;      //se falso assegno alla cella futura la head    
        *head = element;            //e assegno a head il valore passato
    }
}

struct El* pop(struct El **head){
    struct El* ret = *head;

    if (is_empty(*head))    //if (is_empty(*head) == NULL)
    {
        return NULL;        //se vero returna NULL
    }else   
    {
        *head = ret->next;     //se vero sposta il valore futuro nella head
    }

    return ret;
}


int main(){
    struct El* head = NULL;
    struct El* element = NULL;
    struct El* temp = NULL;
    struct El* Alice = NULL;
    struct El* Bob = NULL;
    int randomBit = 0;

    //faccio 4 for dove per ciascun seme e tutte e 13 le carte

    for (int i = 1; i <= 13; i++)
    {
        element = (struct El*) malloc(sizeof(struct El));
        element->seme = 'C';
        element->val = i;
        push(&head, element);
    }

    for (int i = 1; i <= 13; i++)
    {
        element = (struct El*) malloc(sizeof(struct El));
        element->seme = 'P';
        element->val = i;
        push(&head, element);
    }
    
    for (int i = 1; i <= 13; i++)
    {
        element = (struct El*) malloc(sizeof(struct El));
        element->seme = 'D';
        element->val = i;
        push(&head, element);
    }


    for (int i = 1; i <= 13; i++)
    {
        element = (struct El*) malloc(sizeof(struct El));
        element->seme = 'F';
        element->val = i;
        push(&head, element);
    }


    srand(time(NULL));          //serve per il rand e deve essere fatto una sola volta in tutto il codice
    for (int i = 0; i < 52; i++)    //ciclo tutte le carte del mazzo
    {
        randomBit = rand() % 2;
        if(randomBit == 1){         //se randomBit è 1 Alice pesca per prima
            temp = pop(&head);
            push(&Alice,temp);

            /*
            temp = pop(&head);      //blocca il codice ma è così che dovrebbe essere
            push(&Bob,temp);
            */

        }else{                      //se randomBit è 0 Bob pesca per prima
            temp = pop(&head);
            push(&Bob,temp);

            /*
            temp = pop(&head);
            push(&Alice,temp);      //blocca il codice ma è così che dovrebbe essere
            */

        }      
    }

    for (int i = 0; i < 26; i++)        //stampo le 26 carte che Alice ha in mano
    {
        temp = pop(&Alice);
        printf("%c%d\n", temp->seme, temp->val);
    }   
    

}