#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRLEN 25
#define MAX_STR 5
#define M 2
#define F 2

struct s_studente {
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    int  eta;
    char sesso[MAX_STRLEN+1];
    char classe[MAX_STR];
};

struct s_studente v[M];
struct s_studente l[F];


void funzioneOrdinamento (struct s_studente v[]);
void funzioneOrdinamentoFemmine (struct s_studente l[]);

int main(int argc, char** argv) {
    
    int i,j;
    FILE *PuntaFile;
    
  printf("Inserisci i dati degli alunni maschi\n");
  
    for(i=0;i<M;i++){
        printf("Nome %d : ", i+1);
        scanf("%s", v[i].nome);
        printf("Cognome %d : ", i+1);
        scanf("%s", v[i].cognome);
        printf("Eta' %d : ", i+1);
        scanf("%d", &(v[i].eta));
        printf("Sesso %d : ", i+1);
        scanf("%s", (v[i].sesso));
        printf("Classe %d : \n", i+1);
        scanf("%s", v[i].classe);
        
    }
    
    funzioneOrdinamento;
    
    PuntaFile = fopen("maschi.csv", "wb");
    if(PuntaFile != NULL) {
        fwrite(&v, sizeof(v), M, PuntaFile);
        fclose(PuntaFile);
    }
    
  
    printf("Inserisci i dati delle alunne femmine\n");
    
     for(j=0;j<F;j++){
        printf("Nome %d : ", j+1);
        scanf("%s", l[j].nome);
        printf("Cognome %d : ", j+1);
        scanf("%s", l[j].cognome);
        printf("Eta' %d : ", j+1);
        scanf("%d", &(l[j].eta));
        printf("Sesso %d : ", j+1);
        scanf("%s", (l[j].sesso));
        printf("Classe %d : \n", j+1);
        scanf("%s", l[j].classe);
    }
     
    funzioneOrdinamentoFemmine;
    
    PuntaFile = fopen("femmine.csv", "wb");
    if(PuntaFile != NULL) {
        fwrite(&l, sizeof(l), F, PuntaFile);
        fclose(PuntaFile);
    }
    

    return (EXIT_SUCCESS);
}


void funzioneOrdinamento (struct s_studente v[]) {
    int i, j, iMin;
    struct s_studente temporanea;   
    for(i = 0; i < M-1; i++) {
        iMin = i;
        for(j = i + 1; j < M; j++) {
            if(strcmp(v[j].cognome, v[iMin].cognome ) < 0) {
                iMin = j;
    }
    }
        if(i != iMin) {
        temporanea = v[i];
         v[i] = v[iMin];
         v[iMin] = temporanea;
    }
    }
}


void funzioneOrdinamentoFemmine (struct s_studente l[]) {
    int i, j, iMin;
    struct s_studente temporanea;
   
    for(i = 0; i < F-1; i++) {
        iMin = i;
        for(j = i + 1; j < F; j++) {
            if(strcmp(l[j].cognome, l[iMin].cognome ) < 0) {
                iMin = j;
            }
        }
        if(i != iMin) {
            temporanea = v[i];
            l[i] = l[iMin];
            l[iMin] = temporanea;
        }
    }
}

