/*        ***TEIO***
Alifer da silva souza -TADS-19

trabalho final semestre jogo Car Racing......
03/12/2019
*/
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

//desenho do carro=============================================================
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
//inicia jogador
void NewPlayer(Score *gamer){
    gamer -> ponto = 0;
}


//menu Jogo------------------------------------------------------
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

//verifica colisao entre os carros====================================================
int Colisao(char matrix[ROWS][COLUMN], Bloco carro, Bloco carro_ini){

    int retorno = 0;

    if(carro.i == carro_ini.i+3 && (carro.j == carro_ini.j || carro.j-4 == carro_ini.j || carro.j+4 == carro_ini.j ||carro.j-3 == carro_ini.j || carro.j+3 == carro_ini.j || carro.j+2 == carro_ini.j || carro.j-2 == carro_ini.j || carro.j+1 == carro_ini.j || carro.j-1 == carro_ini.j)){        
        retorno = 1;
    }
    return retorno;
}

//gera numeros aleatorios para escolher lados das pecas inimigas
int lados_aleatorios(){
srand(time(NULL));
    int aleatorio = 0;
    aleatorio = rand()%99;
    int lado = 0;

    if(aleatorio%5 == 0 && aleatorio <= 49){
        lado = 3;
    }else if(aleatorio%5 == 0 && aleatorio > 49){
        lado = 2;
    }else if(aleatorio%2 == 0 ){
        lado = 1;
    }else if(aleatorio%2 != 0 ){
        lado = 0;
    }

    return lado;
}