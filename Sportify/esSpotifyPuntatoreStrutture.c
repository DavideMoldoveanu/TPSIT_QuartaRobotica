#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define LUNG 25
#define SIZE 100

typedef struct canzone{
    int num;
    char nome_canzone[LUNG];
    char artista[LUNG];
    struct canzone *next;
}Canzone;

void push(Canzone* p, int ind, char* nC, char* nA){
    Canzone* pAppoggio;
    pAppoggio = p;  //puntano lo stesso spazio in memoria
    if(ind == 1){
        pAppoggio->num = ind;                   
        strcpy(pAppoggio->nome_canzone,nC);
        strcpy(pAppoggio->artista,nA);
    }else{
        while (pAppoggio->next != NULL){
            pAppoggio = pAppoggio->next;
        }
        pAppoggio->next = (Canzone*) malloc (sizeof(Canzone));
        pAppoggio->next->num = ind;
        strcpy(pAppoggio->next->nome_canzone,nC);
        strcpy(pAppoggio->next->artista,nA);
        pAppoggio->next->next = NULL;        
    }
}

bool check(int* vet,int nCerc,int dim){
    bool ok=false;
    for(int k=0;k<dim;k++){
        if(nCerc==*(vet+k)){
            ok=true;
            k=dim;
        }
    }
    return ok;
}

void canzoniRand(Canzone* p, int dim){
    Canzone* pAppoggio;
    int k=0;
    int* vet = malloc(dim  * sizeof(int));
    srand(time(NULL));
    for(int i = 0; i < dim; i++){
        do{
            *(vet+i)=rand()%(dim-1+1)+1;                //metodologia per far randomizzare un numero -- > rand()%(max-min)+1        max --> dim       min --> 0 (inutile scrivere)        
        }while(check(vet,*(vet+i),i)==true);          //verifico che il numero appena randomizzato sia diverso da quelli già presenti
    }

    for (int j = 0; j < dim; j++){
        pAppoggio = p;
        k = 0;
        while(k < *(vet+j)){
            if(k+1==*(vet+j)){              //faccio k+1 perché se non lo faccio non potrà mai essere uguale, dato che nel while metto la condizione k<...
                printf("%2d, %s, %s\n",pAppoggio->num,pAppoggio->nome_canzone,pAppoggio->artista);
            }
            pAppoggio = pAppoggio->next;
            k++;
        }
    }
}

void main(){

    //Canzone *primaCanzone;
    //primaCanzone = (Canzone*) malloc (sizeof(Canzone));

 
    Canzone *playlist;
    playlist = (Canzone*) malloc (sizeof(Canzone));

    FILE *fp;

    char* buffer;
    buffer = malloc(SIZE * sizeof(char));       //malloc returna un numero che verrà preso da buffer e glielo mette come dimensione (100 caratteri può avere buffer)
    int k=0;

    int ind=0;
    char* nomeArt = malloc(SIZE * sizeof(char));    //variabili d'appoggio
    char* nomeCanz = malloc(SIZE * sizeof(char));  

    fp=fopen("canzoni.csv","r");

    //LETTURA FILE
    if(fp==NULL){
        printf("File non esistente");
    }else{
        while(fgets(buffer,SIZE,fp)){
            ind = atoi(strtok(buffer,","));         //non assegno già subito la prima perché se no la prima e l'ultima saranno uguali perché playlist non cambia 
            strcpy(nomeCanz,strtok(NULL,","));   
            strcpy(nomeArt,strtok(NULL,"\n"));
            push(playlist,ind,nomeCanz,nomeArt);    //passo alla procedura le variabili d'appoggio
            k++;
        }
    }
    canzoniRand(playlist,k);  
}


    /*
    Canzone *secondaCaznone;
    secondaCaznone = (Canzone*) malloc (sizeof(Canzone));

    strcpy(primaCanzone->artista,"Carl Brave");
    strcpy(primaCanzone->nome_canzone, "Shangay");

    primaCanzone->num = 1;
    primaCanzone->next = secondaCaznone;

    strcpy(secondaCaznone->nome_canzone, "1984");
    strcpy(secondaCaznone->artista, "Salmo");
    secondaCaznone->num = 2;
    secondaCaznone->next = NULL;

    printf("%s\n", primaCanzone->nome_canzone);
    printf("%s\n", secondaCaznone->nome_canzone);
    printf("%s", primaCanzone->next->nome_canzone);

    */ 