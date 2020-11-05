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
}Canzone;

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

void canzoniRand(Canzone *playlist,int dim){       //creo un vettore di numeri randomizzati che poi userò il vettore come indice nella stampa
    int *vet;
    vet = malloc(dim * sizeof(int));
    srand(time(NULL));                              //inizializzo srand perché così ogni volta che faccio partire il programma cambia la randomizzazione
    for(int i=0;i<dim;i++){
        do{
            *(vet+i)=rand()%(dim-1+1);                //metodologia per far randomizzare un numero -- > rand()%(max-min)+1        max --> dim-1       min --> 0 (inutile scrivere)        
        }while(check(vet,*(vet+i),i)==true);          //verifico che il numero appena randomizzato sia diverso da quelli già presenti
    }
    for(int j=0;j<dim;j++){
        printf("%d - %s - %s\n",(playlist+(*(vet+j)))->num,(playlist+(*(vet+j)))->nome_canzone,(playlist+(*(vet+j)))->artista);
    }
}

int main(){
    FILE *fp;
    Canzone* playlist;
    char* buffer;
    buffer = malloc(SIZE * sizeof(char));       //malloc returna un numero che verrà preso da buffer e glielo mette come dimensione (100 caratteri può avere buffer)
    int k=0;
    fp=fopen("canzoni.csv","r");
    if(fp==NULL){
        printf("File non esistente");
    }else{
        while (fgets(buffer,SIZE,fp))           //apro il file due volte, la prima volta mi serve per contare il numero di canzoni e assegnare a playlist il numero di canzoni presenti nel .csv in modo dinamico
        {
            k++;
        }
        fclose(fp);
        fp=fopen("canzoni.csv","r");
        playlist = malloc(k * sizeof(Canzone));
        k=0;
        while(fgets(buffer,SIZE,fp)){                                     //ho provato a mettere l'asterisco quando chiamavo playlist ma non funzionava e penso che non funzioni perché le strutture occupano spazio in maniera diverso nella memoria
            (playlist+k)->num = atoi(strtok(buffer,","));                 //prendo la prima parte della stringa (la prima parte va fino alla prima virgola)
            strcpy((playlist+k)->nome_canzone,strtok(NULL,","));          //prendo la seconda parte della stringa (la seconda parte parte va fino alla seconda virgola)
            strcpy((playlist+k)->artista,strtok(NULL,"\n"));              //prendo la terza parte della stringa (la terza parte va fino all'acapo)
            k++;
        }
        canzoniRand(playlist,k);  
    }
}