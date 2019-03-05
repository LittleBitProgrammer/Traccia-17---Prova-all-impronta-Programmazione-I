//
//  main.c
//  Traccia 17 - Prova all'impronta Programmazione I
//
//  Created by Roberto Vecchio on 19/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

//Sviluppare una function C che, dati come parametri di input un array di char e il suo size, determina e restituisce come parametro di un dato logico che indica se il testo nell’array è un pangramma, ovvero è un testo che contiene, almeno una volta, tutte le 21 lettere dell’alfabeto italiano.
#include <stdio.h>
#include <string.h>

typedef enum {false,true}bool;

bool lettersOccurence(char *, unsigned long);

int main(int argc, const char * argv[]) {
    
    char phrase[100];
    printf("insert phrase: ");
    fgets(phrase, 4096, stdin);
    
    bool isAll = lettersOccurence(phrase, strlen(phrase));
    
    printf("\n\n%d\n\n", isAll);
    
    
    return 0;
}

bool lettersOccurence(char *phrase, unsigned long size){
    int i;
    int count[21] = {0};
    bool isAll = false;
    
    if (strlen(phrase) >= 21) {
        // incremento array
        for (i = 0; i < size; i++) {
            
            if (phrase[i] >= 'a' && phrase[i] <= 'i' ) {
                count[phrase[i] - 'a']++;
            }else if (phrase[i] >= 'l' && phrase[i] <= 'v' ) {
                count[phrase[i] - 'c']++;
            }else if (phrase[i] == 'z' ) {
                count[phrase[i] - 'f']++;
            }
        }
    
        //verifico sia un pangramma
        for (i = 0; i < 21; i++){
            if (count[i] > 0) {
                isAll = true;
            }
        }
    }
    
    return isAll;
    
}
