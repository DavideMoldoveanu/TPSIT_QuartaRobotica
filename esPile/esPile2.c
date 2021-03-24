/*
Scrivere un programma che chieda all’utente una stringa composta da parentesi aperte e chiuse: (,),[,],{,} e
che verifichi se le coppie e l’ordine delle (,),[,],{,} sono corretti. Utilizzare uno stack.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define LUNG  100

typedef struct nodo{
    char parentesi;
    struct nodo* next;
}Nodo;

int is_empty(Nodo *head){
    if(head==NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(Nodo** head, Nodo* element){
    if(is_empty(*head)){
        *head=element;
        element->next=NULL;
    }else{
        element->next=*head;
        *head= element;
    }
}

Nodo* pop(Nodo **head){
    Nodo* ret= *head;
    if(is_empty(*head)){
        return NULL;
    }else{
        *head= ret->next;
    }
    return ret;
}

void stampaPIla(Nodo** head){
    Nodo *appoggio;
    appoggio =pop(head);
    while(appoggio!=NULL){   //ripeto finchè ci sono elementi
        printf("%d\n",appoggio->parentesi);
        free(appoggio);
        appoggio=pop(head); 
    }
}

int main(){
    Nodo* head;
    Nodo* input;
    char* espressione = (char*) malloc(sizeof(char) * LUNG);
    bool corretta = true;
    char parAppoggio;
    head=NULL;
    int k=0;

    printf("Inserire l'espressione: ");
    fflush(stdin);
    scanf("%s",espressione);

    while(k < strlen(espressione) && corretta==true){                                       //eseguo i dovuti controlli per vedere se sono inseriti correttamente le parentesi e le carico in una pila
        if(*(espressione+k)=='('|| *(espressione+k)=='['|| *(espressione+k)=='{' ){
            input = (char*) malloc (sizeof(char));
            input->parentesi=*(espressione+k);
            push(&head,input);
        }else{
            if(*(espressione+k)==')'){
                if(pop(&head)->parentesi!='('){
                    corretta=false;
                }               
            }else{
                if(*(espressione+k)==']'){
                    if(pop(&head)->parentesi!='['){
                        corretta=false;
                    }               
                }else{
                    if(*(espressione+k)=='}'){
                        if(pop(&head)->parentesi!='{'){
                        corretta=false;
                        }               
                    }       
                }
            }
        }
        k++;
    }
    if(head!=NULL){
        corretta=false;
    }
    if(corretta){
        printf("Espressione scritta correttamente!");
    }else{
        printf("Hai sbagliato");
    }
    return 0;
}



//=========================================================================================================================================================



/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct El{
    char valore;
    struct El* next;
}El;

void push(struct El** head, struct El* element){
    if(&head == NULL){
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }
}

struct El* pop(struct El** head){
    struct El* ret = *head;
    if(&head == NULL) return NULL;
    else *head = ret->next;

    return ret;
    
}

void stampa(struct El **head){
    struct El *appoggio;
    
    while(appoggio != NULL){
        appoggio = pop(head);
        printf("%c ", appoggio->valore);
        free(appoggio);
    }
}

void main(){
    struct El* head;
    struct El* element;
    struct El* ret;

    bool correct = true;    //divanta false se incotra una parentesi chiusa diversa da quella aperta

    char espressione[1000]; //stringa da verificare

    printf("inserisci la serie di parentesi:\n");
    fflush(stdin);
    scanf("%s" , espressione);

    //a seconda che la parentesi sia aperta o chiusa carico o tolgo un elemento nell pila
    for (int i = 0; espressione[i]!='\0' && correct; i++){
        if(espressione[i] == '(' || espressione[i] == '[' || espressione[i] == '{' || espressione[i] == ')' || espressione[i] == ']' || espressione[i] == '}'){
            element = (struct El*) malloc(sizeof(struct El));
            element->valore = espressione[i];
            push(&head,element);
        }

        stampa(&head);

        if(espressione[i] == ')' || espressione[i] == ']' || espressione[i] == '}'){
            ret = pop(&head);
            if(ret->valore != ret->valore-2) correct = false;
            else ret = pop(&head);
        }
    }

    if(correct) printf("espressione inserita correttamente");
    else printf("espressione errata");
}
*/