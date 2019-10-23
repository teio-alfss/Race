/*TEIO*/
/*jogo interativo tetris
para rodar no terminal
programado em .c 

Alifer da silva souza
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>//para capturar teclas


//confg de layolt
#define PiXEL 219
#define EMPTY 32




#define COLUNN      16
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


//Orientacao das pecas
#define ORIENTACAO_UP    1
#define ORIENTACAO_DOWN  2
#define ORIENTACAO_LEFT  3
#define ORIENTACAO_RIGHT 4


//Tipos de pecas
#define TIPO_L      1
#define TIPO_L_R    2 //L reverso
#define TIPO_T      3
#define TIPO_Z      4
#define TIPO_Z_R    5 //z reverso
#define TIPO_O      6 //quadrado
#define TIPO_I      7

//Estrutura das pecas
typedef struct {
    int orientacao; // orintacao das pecas
    int tipo; //o tipode peecas
    int i;// posicao nas linha da matrix
    int j;//posicao na colunas da matrix
    int width;//largura da pecas
    int height;//altura da pecas
    
}Bloco;


//iniciar a matrix principal ddo jogo
void init(char matrix[ROWS][COLUNN]);

//imorimi a tela do jogo
void printMatrix(char matrix[ROWS][COLUNN]);

//desenha uma barra usando os simbolos
void drawBar(char matrix[ROWS][COLUNN], Bloco barra, int simbolo);