/*TEIO*/
#include "race.h"


//preenche a matrix espaços vazios================================
void init(char matrix[ROWS][COLUNN] ){
    int i, j;
        for ( i = 0; i <= ROWS; i++){
            for ( j = 0; j <= COLUNN; j++){
                 if (i == 0 || i == (ROWS -1))  matrix[i][j] = ASTERISCO;
                 else if (j == 0 || j == (COLUNN-1)) matrix[i][j] = ASTERISCO; //cria paredes no mapa============
                 else if (j == 1 && i%2 != 0 || j == (COLUNN-2) && i%2 != 0) matrix[i][j] = PiXEL;
                 else matrix[i][j] = ' ';
            }
        }
            
        
        


}
//imprimi a matrix jogo===========================================
void printMatrix(char matrix[ROWS][COLUNN]){
    int i, j;

        for ( i = 0; i < ROWS; i++){
            for ( j = 0; j < COLUNN; j++){
                printf("%c", matrix[i][j]);
            }
            printf("\n");
        }
    
}



void drawBar(char matrix[ROWS][COLUNN], Bloco barra, int simbolo){
              
              matrix[barra.i][barra.j] = simbolo;//cabeca carrinho
   
              if(barra.j+1>=0) matrix[barra.i+1][barra.j-1] = simbolo;  //bracos
              if(barra.j+1>=0) matrix[barra.i+1][barra.j+1] = simbolo;  //bracos
              if(barra.j+1>=0) matrix[barra.i+1][barra.j-2] = simbolo;  //bracos
              if(barra.j+1>=0) matrix[barra.i+1][barra.j+2] = simbolo;  //bracos

              if(barra.j+1>=0) matrix[barra.i+1][barra.j] = simbolo;    //corpo
              if(barra.j+1>=0) matrix[barra.i+2][barra.j] = simbolo;    //corpo
              

              if(barra.j+1>=0) matrix[barra.i+3][barra.j-1] = simbolo;    //final
              if(barra.j+1>=0) matrix[barra.i+3][barra.j+1] = simbolo;    //final
              if(barra.j+1>=0) matrix[barra.i+3][barra.j-2] = simbolo;    //final
              if(barra.j+1>=0) matrix[barra.i+3][barra.j+2] = simbolo;    //final

}


//inico dos carrinhos
void NewCar(Bloco *barra){
    barra->i      = (ROWS-5); //ROWS/2;  //faz A PECA fica embaixo do mapa===============
    barra->j      = COLUNN/2;
    barra->height = 1;
    barra->width  = 5;
}