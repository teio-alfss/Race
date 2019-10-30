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
   srand(time(NULL));
   int a; 
   char matrix[ROWS][COLUNN];
   Bloco carro;
   Bloco carro_inimigo;
   Bloco carro_inimigo2;
   int keypressed = 0;

   // posicao inicial do avatar
   carro.i = 20; //ROWS/2;  //faz A PECA fica embaixo do mapa===============
   carro.j = 5;  //COLUNN/2;
   carro.tipo = TIPO_I;
   carro.orientacao = ORIENTACAO_LEFT;
   carro.width = 5;
   carro.height = 1;

   carro_inimigo.i = 1;
   carro_inimigo.j = 3;
   carro_inimigo.tipo = TIPO_I;
   carro_inimigo.orientacao = ORIENTACAO_LEFT;
   carro_inimigo.width = 5;
   carro_inimigo.height = 1;

   carro_inimigo2.i = 19;
   carro_inimigo2.j = 8;
   carro_inimigo2.tipo = TIPO_I;
   carro_inimigo2.orientacao = ORIENTACAO_LEFT;
   carro_inimigo2.width = 5;
   carro_inimigo2.height = 1;

   init(matrix);

   //apagar cursor da tela
   ShowConsoleCursor(0);
   system("cls");

   //rotina principal jogo=============================
   while (keypressed != ESC)
   {
       gotoxy(0, 0);

            #if DEBUG == 1
                printf("posicao = (%d,%d)\n",carro.i, carro.j);
                printf("dimensao = (%d,%d)\n",carro.width, carro.height);
            #endif
            // sorteio do lado das pecas
            a= (rand() % 10);
            if(carro_inimigo.i >= 24){
            if(a%2 == 0 && a <= 5){
                carro_inimigo.j = 8;
                carro_inimigo2.j = 3;

            }else if(a%2 == 0 && a>5){
                carro_inimigo.j = 3;
                carro_inimigo2.j = 8;

            }else if(a%2 == 0 && a >= 5){
                carro_inimigo.j = 8;
                carro_inimigo2.j = 8;

            }else if(a%2 != 0 && a < 5){
                carro_inimigo.j = 3;
                carro_inimigo2.j = 3;
            }
            }
            if(carro_inimigo2.i >= 15) drawBar(matrix, carro_inimigo, PiXEL); //feito para o 1 carro e o segundo comecar a cair desde o comeco
                     
            drawBar(matrix, carro_inimigo2, PiXEL);

            //coloca o carrinho no meio da tela
            drawBar(matrix, carro, PiXEL);

            //mostra a matrix na tela
            printMatrix(matrix);

            //apaga a posicao anterior
            drawBar(matrix, carro, EMPTY);

            if (carro_inimigo2.i >= 10) drawBar(matrix, carro_inimigo, EMPTY);//feito para o 1 carro e o segundo comecar a cair desde o comeco

            drawBar(matrix, carro_inimigo2, EMPTY);
            
            if(carro_inimigo.i >= 24){
                carro_inimigo.i = 1;
                carro_inimigo2.i = 1;
            }
            if(carro_inimigo2.i >= 15) carro_inimigo.i++;//feito para o 1 carro e o segundo comecar a cair desde o comeco
            carro_inimigo2.i++;

   
        
        //lendo teclas--------------
        keypressed = 0;
        if(kbhit()) keypressed = getch();
            if (keypressed == ARROWS) keypressed = getch();// para capturar setas=================
    
                switch(keypressed){
                    case TECLA_AA:
                    case TECLA_a:
                    case LEFT: if(carro.j > 3) carro.j--; //move para esquerda--------------------------
                        break; 

                    case TECLA_DD:
                    case TECLA_d:
                    case RIGHT: if(carro.j < (COLUNN-4)) carro.j++; //move para direita------------------
                        break;

                        //arrumando bug cantos
                      //  if(carro.j < (carro.width/2))
                       // carro.j = carro.width/2;
                      //  else if(carro.j > COLUNN - (carro.width/2) - 1 )
                       //         carro.j = COLUNN - (carro.width/2) - 1;
                        
            }
           
           
}//fim while************************************
    
    system("pause");

return 0;
}