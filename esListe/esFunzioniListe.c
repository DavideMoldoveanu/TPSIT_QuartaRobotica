#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodo{
    int valore;
    struct nodo* successivo;
}Nodo;

//=======================================================================================================

void stampaLista(Nodo* lista){
    //funzione iterativa
    if(lista != NULL){
        Nodo* temp = lista;         //uso temp perché in caso dovessi riutilizzare lista, nel main, posso farlo senza problemi
        while (temp != NULL){
            printf("%d\n",temp->valore);
            temp=temp->successivo;
        }
    }else{
        printf("----\n");
    }   
}

//=======================================================================================================

void stampaLista1(Nodo* lista){
    //funzione ricorsiva
    if(lista == NULL){
        printf("----\n");
    }else{
        printf("%d\n",lista->valore);
        stampaLista1(lista->successivo);
    }
}

//=======================================================================================================

int lughezzaLista_iterativa(Nodo* lista){
    //funzione iterativa
    int cnt = 0;
    while(lista != NULL){
        lista = lista->successivo;
        cnt++;
    }
    return cnt;
}

//=======================================================================================================

int lughezzaLista_ricorsiva(Nodo* lista){
    //funzione ricorsiva
    if(lista == NULL){
        return 0;
    }else
    {
        return 1 + lughezzaLista_ricorsiva(lista->successivo); //1 + 1 + 1 + 1 + 1 + 0
    }
    
}

//=======================================================================================================

void deAllocaLista_ricorsiva(Nodo* lista){
    //funzione ricorsiva
    if(lista != NULL){
        deAllocaLista(lista->successivo);
        //printf("deAllocaLista: %d\n", lista->valore);

        free(lista);
        //printf("free: %d\n", lista->valore);
    }
}

//=======================================================================================================

void deAlloca_iterativa(Nodo* lista){
    //funzione iterativa
    while (lista != NULL){
        free(lista);
        lista = lista->successivo;
    }   
}

//=======================================================================================================

void push_iterativa(Nodo* lista, int n){
    //funzione iterativa
    Nodo* t = lista;
    while (t->successivo != NULL)
    {
        t = t->successivo;
    }
    t->successivo = (Nodo*) malloc(sizeof(Nodo));
    t->successivo->valore = n;
    t->successivo->successivo = NULL;      
}

//=======================================================================================================

void push(Nodo* lista, int num){
    if(lista==NULL){
        lista->valore=num;
    }else{
        Nodo* temp=lista;
        while(temp->successivo!=NULL){
            temp=temp->successivo;
        }
        temp->successivo = (Nodo*)malloc(sizeof(Nodo));
        temp->successivo->valore = num;
        temp->successivo->successivo=NULL;
    }
}

//=======================================================================================================

void rem(Nodo* lista, int valore){
    Nodo* l=lista;
    Nodo* r=lista;
    while(l->successivo!=NULL){
        if(valore==l->successivo->valore){
            r=l->successivo;
            l->successivo=l->successivo->successivo;
            free(r);
        }else{
            l=l->successivo;
        }
    }
}

//=======================================================================================================

int main(){

}