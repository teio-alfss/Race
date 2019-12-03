/*        ***TEIO***
Alifer da silva souza -TADS-19

trabalho final semestre jogo Car Racing......
03/12/2019
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>//para capturar teclas


//confg de layolt
#define PiXEL 178
#define EMPTY 32
#define ASTERISCO 42

#define LADOL 4  // lados que os carrinhos /
#define LADOR 10

#define PONTOS  50


#define COLUMN      15
#define ROWS        25
#define ESC         27
#define ARROWS      224
#define LEFT        75
#define RIGHT       77
#define TECLA_a     97
#define TECLA_d     100
#define TECLA_AA    65
#define TECLA_DD    68
#define TECLA_ESPACO 32


//Estrutura das pecas----------------------
typedef struct {
    int i;// posicao nas linha da matrix
    int j;//posicao na colunas da matrix  
}Bloco;

//jogadore==================================
typedef struct{
    char name[20];
    int ponto, cod;
}Score;

//iniciar a matrix principal do jogo-------
void init(char matrix[ROWS][COLUMN]);
                                        //faz a pista mexer
//iniciar a matrix principal do jogo
void initM(char matrix[ROWS][COLUMN]);

//imprimi a matrix jogo===========================================
void printMatrix(char matrix[ROWS][COLUMN]);

//desenho do carro=============================================================
void drawBar(char matrix[ROWS][COLUMN], Bloco barra, int simbolo);

//inico dos carrinhos
void NewCar(Bloco *barra);

//inicia joagador
void NewPlayer(Score *gamer);

//menu Jogo------------------------------------------------------
void MenuGame();

//verifica colisao entre os carros====================================================
int Colisao(char matrix[ROWS][COLUMN], Bloco carro, Bloco carro_ini);

////gera numeros aleatorios para escolher lados das pecas inimigas
int lados_aleatorios();