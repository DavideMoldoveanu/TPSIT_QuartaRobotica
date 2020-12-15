//ESERCIZIO 1

#include <stdio.h>
#include <stdlib.h>
    struct El
{
    int valore;
    struct El *next;
};

int main()
{
    int n;
    struct El *lista;
    struct El *l;
    lista = NULL; /* mette lista che punta a NULL (niente) */

    do
    {
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if (n >= 0)
        {
            if (lista == NULL) /* controllo che lista non abbia nessun valore */
            {
                /* se lista non ha valori faccio la malloc e poi faaccio puntare "l" alla stessa cella di memoria che punta lista */

                lista = (struct El *)malloc(sizeof(struct El));

                l = lista;
            }
            else /* se lista ha valori, quindi punta a qualcosa */
            {
                /* assegno a "l" la cella dopo e faccio già subito la malloc alla nuova cella. A "l" assegno la nuova cella */

                l->next = (struct El *)malloc(sizeof(struct El));

                l = l->next;
            }
            l->valore = n;  /* al valore di "l" assegno il valore di n  */
            l->next = NULL; /* al next di "l" assegno valore NULL */
        }
    } while (n >= 0);

    l = lista; /* mette lista che punta a NULL (niente) */
    printf("numeri inseriti: \n");
    while (l != NULL)
    {
        printf("%d - %p \n", l->valore, l->next);
        l = l->next; /* "l" punta alla cella futura */
    }
    printf("\n");
    return 0;
}



//===============================================================================================

//ESERCIZIO 2

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

//======================================================================================

//ESERCIZIO 4

#include <stdio.h>
#include <stdlib.h>
    struct El
{
    int valore;
    struct El *next;
};

void deAlloca(struct El* l){
    while (l != NULL){
        free(l);
        l = l->next;
    }   
}

int main()
{
    int n;
    struct El *lista;
    struct El *l;
    lista = NULL; /* mette lista che punta a NULL (niente) */

    do
    {
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if (n >= 0)
        {
            if (lista == NULL) /* controllo che lista non abbia nessun valore */
            {
                /* se lista non ha valori faccio la malloc e poi faaccio puntare "l" alla stessa cella di memoria che punta lista */

                lista = (struct El *)malloc(sizeof(struct El));

                l = lista;
            }
            else /* se lista ha valori, quindi punta a qualcosa */
            {
                /* assegno a "l" la cella dopo e faccio già subito la malloc alla nuova cella. A "l" assegno la nuova cella */

                l->next = (struct El *)malloc(sizeof(struct El));

                l = l->next;
            }
            l->valore = n;  /* al valore di "l" assegno il valore di n  */
            l->next = NULL; /* al next di "l" assegno valore NULL */
        }
    } while (n >= 0);

    l = lista; /* mette lista che punta a NULL (niente) */
    printf("numeri inseriti: \n");
    while (l != NULL)
    {
        printf("%d - %p \n", l->valore, l->next);
        l = l->next; /* "l" punta alla cella futura */
    }
    printf("\n");

    deAlloca(l);

    printf("numeri inseriti: ");
    while (l != NULL)
    {
        printf("%d - %p \n", l->valore, l->next);
        l = l->next; /* "l" punta alla cella futura */
    }
    printf("\n");

    return 0;
}

//=====================================================================================================================================================================

//ESERCIZIO 5

#include <stdio.h>
#include <stdlib.h>
    struct El
{
    int valore;
    struct El *next;
};

struct El* ordina(struct El* l){
    struct El t;
    
}

int main()
{
    int n;
    struct El *lista;
    struct El *l;
    lista = NULL; /* mette lista che punta a NULL (niente) */

    do
    {
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if (n >= 0)
        {
            if (lista == NULL) /* controllo che lista non abbia nessun valore */
            {
                /* se lista non ha valori faccio la malloc e poi faaccio puntare "l" alla stessa cella di memoria che punta lista */

                lista = (struct El *)malloc(sizeof(struct El));

                l = lista;
            }
            else /* se lista ha valori, quindi punta a qualcosa */
            {
                /* assegno a "l" la cella dopo e faccio già subito la malloc alla nuova cella. A "l" assegno la nuova cella */

                l->next = (struct El *)malloc(sizeof(struct El));

                l = l->next;
            }
            l->valore = n;  /* al valore di "l" assegno il valore di n  */
            l->next = NULL; /* al next di "l" assegno valore NULL */
        }
    } while (n >= 0);

    l = lista; /* mette lista che punta a NULL (niente) */
    printf("numeri inseriti: \n");
    while (l != NULL)
    {
        printf("%d - %p \n", l->valore, l->next);
        l = l->next; /* "l" punta alla cella futura */
    }
    printf("\n");
    return 0;
}

//===============================================================================================================================================================================

//ESERCIZIO 6
