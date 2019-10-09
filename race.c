#include "race.h"



//preenche a matrix==============================================
void init(char matrix[LIN][COL]){
    int i, j;
    for(i = 0; i <= LIN; i++){
        for(j = 0; j <= COL; j++){
            if(i == 0 || i == LIN) {matrix[LIN][COL] = '_';}
            else matrix[LIN][COL] = ' ';
        }
    }    
}

//imprimi a matrix do jogo na tela================================
void printMatrix(char matrix[LIN][COL]){
    int i, j;
    for(i = 0; i <= LIN; i++){
        for(j = 0; j <= COL; j++){
            printf("%c",matrix[LIN][COL]);
        }
        printf("\n");
    }
}