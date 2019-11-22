/*TEIO*/
#include "race.h"


//preenche a matrix espaços vazios================================
void init(char matrix[ROWS][COLUMN] ){
    int i, j;
        
        for ( i = 0; i < ROWS; i++){
            for ( j = 0; j < COLUMN; j++){
                 if (i == 0 || i == (ROWS -1))  matrix[i][j] = ASTERISCO;
                 else if (j == 0 || j == (COLUMN-1)) matrix[i][j] = ASTERISCO; //cria paredes no mapa============
                 else if (j == 1 && i%2 != 0 || j == (COLUMN-2) && i%2 != 0) matrix[i][j] = PiXEL;
                 else matrix[i][j] = ' ';
            }
        }
}

//preenche a matrix espaços vazios================================
void initM(char matrix[ROWS][COLUMN] ){
    int i, j;
        
        for ( i = 0; i < ROWS; i++){
            for ( j = 0; j < COLUMN; j++){
                 if (i == 0 || i == (ROWS -1))  matrix[i][j] = ASTERISCO;
                 else if (j == 0 || j == (COLUMN-1)) matrix[i][j] = ASTERISCO; //cria paredes no mapa============
                 else if (j == 1 && i%2 == 0 || j == (COLUMN-2) && i%2 == 0) matrix[i][j] = PiXEL;
                 else matrix[i][j] = ' ';
            }
        }
}



//imprimi a matrix jogo===========================================
void printMatrix(char matrix[ROWS][COLUMN]){
    int i, j;

        for ( i = 0; i < ROWS; i++){
            for ( j = 0; j < COLUMN; j++){
                printf("%c", matrix[i][j]);
            }
            printf("\n");
        }
    
}

//desenho do carro=============
void drawBar(char matrix[ROWS][COLUMN], Bloco barra, int simbolo){
              
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
    barra->j      = COLUMN/2; //peca fica no meio
}

//novo jogador
void NewPlayer(highscores *gamer){
    gamer->name ;
    gamer->ponto = 0;
}

//menu  Jogo
void MenuGame(){
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
	printf("\n\xBA     MENU DO JOGO    \xBA");
	printf("\n\xCC\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xB9\n");	
	printf("\xBA  1-NOVO JOGO        \xBA\n");
	printf("\xBA                     \xBA\n");	
	printf("\xBA  2-RECORDS          \xBA\n");
	printf("\xBA                     \xBA\n");	
	printf("\xBA  3-SAIR             \xBA\n");
	printf("\xBA                     \xBA\n");	
	printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n\n");
}

// gera os numeros aleatorios
int num_aleatorio(){
    srand(time(NULL));
    int retorno = 0;
    
    retorno = (rand() % 10 );

    return retorno;

}