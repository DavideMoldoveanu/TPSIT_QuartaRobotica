#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define LUNG 100
#define SIZE 100

//free(variabileInMalloc)


//Autore: Moldoveanu Davide

//Non mi carica


typedef struct droneVolo{
    int tempo;
    float lat;
    float lon;    
}DroneVolo;

typedef struct anomalieDrone{
    int tempo;
    char tipoErrore[LUNG];
}AnomalieDrone;


void calcLatLongProblema(DroneVolo *stato, AnomalieDrone *problemi, int dim1, int dim2){ //calcola la latitudine e la longitudine di dove si trova l'anomalia
    for (int i = 0; i < dim1; i++){
        for(int k = 0; k < dim2; k++){
            if((stato+i)->tempo == (problemi+k)->tempo){    //controllo i due tempi delle struttre
                printf("L'anomalia di tipo: %s e' stata trovata alla latitutdine: %.3f e alla longitudine: %.3f",(problemi+k)->tipoErrore,(stato+i)->lat,(stato+i)->lon);
            }
        } 
    }
}


void verificaCaricamento(DroneVolo *stato, AnomalieDrone *problemi, int dim1, int dim2){
    for (int i = 0; i < dim1; i++)
    {
        printf("%d %f %f\n",(stato+i)->tempo,(stato+i)->lat,(stato+i)->lon);
    }

    for (int i = 0; i < dim1; i++)
    {
        printf("%d %s\n",(problemi+i)->tempo,(problemi+i)->tipoErrore);
    }
    
}




void main(){
    FILE *f1, *f2;
    DroneVolo *statoDrone;
    AnomalieDrone *problemiVolo;
    char *buffer;
    int k1 = 0;
    int k2 = 0;
    char *stringaInutile;
    buffer = malloc(SIZE * sizeof(char));   //moltiplico per 100 la dimensione di un tipo char e determino l'allocazione dinamica in memoria per buffer (con malloc)
    f1 = fopen("Volo_drone.csv", "r");
    if (f1 == NULL){
        printf("File contenete i voli del drone non e' presente!");
    }else{
        f2 = fopen("Anomalie_drone.csv", "r");
        if(f2 == NULL){
            printf("File contenete le anomalie del drone non e' presente!");
        }else{
            while(fgets(buffer,SIZE,f1)){   //leggo una volta tutto il file per sapere quanti tempi ci sono all'interno
                k1++;
            }

            fclose(f1);
            statoDrone = malloc(k1 * sizeof(DroneVolo));  //allocazione dinamica della memoria --> moltiplico per k la dimensione di un tipo DroneVolo
            k1=1;

            while(fgets(buffer,SIZE,f2)){   //leggo una volta tutto il file per sapere quanti tempi ci sono all'interno
                k2++;
            }

            fclose(f2);
            problemiVolo = malloc(k2 * sizeof(AnomalieDrone));  //allocazione dinamica della memoria --> moltiplico per k la dimensione di un tipo AnomalieDrone
            k2=1;

            f1 = fopen("Volo_drone.csv", "r");
            while (fgets(buffer,SIZE,f1)){
                (statoDrone+k1)->tempo = atoi(strtok(buffer,","));
                (statoDrone+k1)->lat = atof(strtok(NULL,","));
                (statoDrone+k1)->lon = atof(strtok(NULL,"\n"));
                k1++;
            }

            f2 = fopen("Anomalie_drone.csv", "r");
            while (fgets(buffer,SIZE,f2)){
                (problemiVolo+k2)->tempo = atoi(strtok(buffer,","));
                strcpy((problemiVolo+k2)->tipoErrore, strtok(NULL,"\n"));
            }

            calcLatLongProblema(statoDrone, problemiVolo, k1, k2);   
            verificaCaricamento(statoDrone, problemiVolo, k1, k2);
        }
    }
}