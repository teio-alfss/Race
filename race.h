/*TEIO*/
/*jogo interativo tetris
para rodar no terminal
programado em .c 

Alifer da silva souza
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

#define PONTOS  200


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

//iniciar a matrix principal ddo jogo-------
void init(char matrix[ROWS][COLUMN]);
                                        //faz a pista mexe
//iniciar a matrix principal ddo jogo
void initM(char matrix[ROWS][COLUMN]);

//imorimi a tela do jogo
void printMatrix(char matrix[ROWS][COLUMN]);

//desenha uma barra usando os simbolos
void drawBar(char matrix[ROWS][COLUMN], Bloco barra, int simbolo);

//inico dos carrinhos
void NewCar(Bloco *barra);

//menu inicial=====================
void MenuGame();

//jogador
void NewPlayer(Score *gamer);

//aleatorios
int num_aleatorio();