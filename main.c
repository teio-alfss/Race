/*TEIO*/
/*jogo interativo tetris
para rodar no terminal 
para executar start .\programa.exe
Alifer da silva souza
*/
#include "race.h"
#include "display.h"

#define DEBUG 1

int main (){
   char matrix[ROWS][COLUNN];   
    Bloco tijolo;
    Bloco carro;
    int keypressed=0;
    
    
    // posicao inicial do avatar
    tijolo.i =          20;//ROWS/2;  //faz A PECA fica embaixo do mapa===============
    tijolo.j =          7;//COLUNN/2;
    tijolo.tipo =       TIPO_I;
    tijolo.orientacao = ORIENTACAO_LEFT;
    tijolo.width =      5;
    tijolo.height =     1;

    carro.i = 0;
    carro.j = 3;
    carro.tipo = TIPO_I;
    carro.orientacao = ORIENTACAO_LEFT;
    carro.width = 5;
    carro.height = 1;


    init(matrix);

        //apagar cursor da tela
        ShowConsoleCursor(0);
        system("cls");
        
        //rotina principal jogo=============================
        while (keypressed != ESC){
            gotoxy(0,0);

            #if DEBUG == 1
                printf("posicao = (%d,%d)\n",tijolo.i, tijolo.j);
                printf("dimensao = (%d,%d)\n",tijolo.width, tijolo.height);
            #endif
            

            drawBar(matrix, carro, PiXEL);


            //coloca o carrinho no meio da tela
            drawBar(matrix, tijolo, PiXEL);

            //mostra a matrix na tela
            printMatrix(matrix);

            //apaga a posicao anterior
            drawBar(matrix, tijolo, EMPTY);
            drawBar(matrix, carro, EMPTY);


   
        
        //lendo teclas--------------
        keypressed = 0;
        if(kbhit()) keypressed = getch();
            if (keypressed == ARROWS) keypressed = getch();// para capturar setas=================
    
                switch(keypressed){
                    case TECLA_AA:
                    case TECLA_a:
                    case LEFT: if(tijolo.j > 3) tijolo.j--; //move para esquerda--------------------------
                        break; 

                    case TECLA_DD:
                    case TECLA_d:
                    case RIGHT: if(tijolo.j < (COLUNN-4)) tijolo.j++; //move para direita------------------
                        break;

                        //arrumando bug cantos
                        if(tijolo.j < (tijolo.width/2))
                        tijolo.j = tijolo.width/2;
                        else if(tijolo.j > COLUNN - (tijolo.width/2) - 1 )
                                tijolo.j = COLUNN - (tijolo.width/2) - 1;
                        
            }
           
           
}//fim while************************************
    
    system("pause");

return 0;
}