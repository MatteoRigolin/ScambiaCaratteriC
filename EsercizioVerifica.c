// Author: Matteo Rigolin
// Si scriva un programma che sostituisca un carattereDaCambiare dentro ad un file di testo, ogni volta che questo compare. 
// Al termine della sostituzione il programma deve scrivere su un nuovo file di testo l’array con i caratteri sostituiti. 

#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
  
void cambiaCaratteri(char stringa[100][100], int lunghezza,char carattereDaCambiare ,char carattereInserito, int * num) 
{ 
    for(int j = 0; j < lunghezza ; j++) 
    { 
        for(int i = 0; i < strlen(stringa[j]) ; i++){ 
            if(stringa[j][i] == carattereDaCambiare) {
                carattereDaCambiare = carattereInserito;
                ++(*num); 
            }
        } 
    } 
} 
 
void scriviOutput(char * argv[], char * stringa ,int num){ 
    FILE* stream; 
    if((stream = fopen(argv[2], "w")) == NULL){ 
        printf("errore nell'apertura del file output"); 
        exit(4); 
    } 
    if(num==0){
        printf("La ricerca non ha prodotto risultati");
        fprintf(stream, "La ricerca non ha prodotto risultati");

    }
    else{
        fprintf(stream,"%s", stringa); 
    }                     
    fclose(stream); 
} 
  
int main(int argc, char * argv[]){ 
    FILE* stream; 
    char  stringa[100][100];  
    int numParole = 0; 
    int num = 0; 
    if (argc != 6){ 
        printf("Argomenti errati"); 
        exit(1);     
    } 
    if(argv[3][1] != 's'){ 
        printf("Metodo errato"); 
        exit(2); 
    }  
    //apro stream input     
    if((stream = fopen(argv[1], "r")) == NULL){ 
        printf("errore nell'apertura del file input"); 
        exit(3); 
    }     
    do{
        fscanf(stream, "%s\t", stringa[numParole]);
        numParole++;
    }    
    //prelevo stringa da  stream input
    while(!feof(stream)) 
    fclose(stream); 
    cambiaCaratteri(stringa, numParole, argv[4][0] , argv[5][0], &num); 
    scriviOutput(argv, stringa, num); 
    return 0; 
}