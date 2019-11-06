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
   
   int keypressed = 0;
   int score=0;
   int a=0, mapa=0;
   char matrix[ROWS][COLUMN];
   Bloco carro;
   Bloco carro_inimigo;
   Bloco carro_inimigo1;
   Bloco carro_inimigo2;
   
   //apagar cursor da tela
     ShowConsoleCursor(0);
     system("cls");
    
    //inicia a matrix
    init(matrix);

    NewCar(&carro);
    NewCar(&carro_inimigo);
    NewCar(&carro_inimigo1);
    NewCar(&carro_inimigo2);


   //rotina principal jogo=============================
   while (keypressed != ESC){
       gotoxy(0, 0);
       

            #if DEBUG == 1
                printf("posicao = (%d,%d)\n",carro.i, carro.j);
                printf("dimensao = (%d,%d)\n",carro.width, carro.height);
                printf("aleatorio --> %i\n",a);
            #endif
            // sorteio do lado das pecas
            
            if(carro_inimigo.i > (ROWS - 6)){
            
            if(a%2 == 0 && a <= 5){
                carro_inimigo.j = LADOR;
                carro_inimigo1.j = LADOL;
                carro_inimigo2.j = LADOL;
                

            }else if(a%2 == 0 && a>5){
                carro_inimigo.j = LADOL;
                carro_inimigo1.j = LADOL;
                carro_inimigo2.j = LADOR;

            }else if(a%2 == 0 && a >= 5){
                carro_inimigo.j = LADOR;
                carro_inimigo1.j = LADOL;
                carro_inimigo2.j = LADOR;

            }else if(a%2 != 0 && a < 5){
                carro_inimigo.j = LADOL;
                carro_inimigo1.j = LADOR;
                carro_inimigo2.j = LADOL;
            }
            }
            
                
            drawBar(matrix, carro_inimigo2, PiXEL);
            if(carro_inimigo2.i > 15) drawBar(matrix, carro_inimigo1, PiXEL); //feito para o 1 carro e o segundo comecar a cair desde o comeco
            if(carro_inimigo1.i > 15) drawBar(matrix, carro_inimigo, PiXEL);   //para o segundo carro comecar a cair  
            
            //carro "amigo" controlado=======
            drawBar(matrix, carro, PiXEL);
              

 
           //mostra a matrix na tela
            printMatrix(matrix);
                       
            //apaga a posicao anterior
            drawBar(matrix, carro, EMPTY);

            drawBar(matrix, carro_inimigo, EMPTY);
            drawBar(matrix, carro_inimigo1, EMPTY);
            drawBar(matrix, carro_inimigo2, EMPTY);
            
          
          
          
            // inicio os carros apos a queda
            if(carro_inimigo.i > (ROWS-5)){
                carro_inimigo.i  = 0;
                carro_inimigo1.i = 0;
                carro_inimigo2.i = 0;
                 a =0;
                 a = (rand() % 10);
            }
            Sleep(100);
            
            if(carro_inimigo2.i > 15) carro_inimigo1.i++;//o 1 carro e o segundo comecar a cair desde o comeco
            if(carro_inimigo1.i > 15) carro_inimigo.i++;
            
             carro_inimigo2.i++;
            

            //colisao de carros==================================================
            if(carro_inimigo2.j == carro.j && carro_inimigo2.i == carro.i){
                printf("!!!!!PERDEU!!!!!\n");
                break;
                }
            if(carro_inimigo1.j == carro.j && carro_inimigo1.i == carro.i){
                printf("!!!!!PERDEU!!!!!\n");
                break;
                }
            if(carro_inimigo.j == carro.j && carro_inimigo.i == carro.i){
                printf("!!!!!PERDEU!!!!!\n");
                break;
                }
        
        //lendo teclas--------------
        keypressed = 0;
        if(kbhit()) keypressed = getch();
            if (keypressed == ARROWS) keypressed = getch();// para capturar setas=================
    
                switch(keypressed){
                    case TECLA_AA:
                    case TECLA_a:
                    case LEFT: if(carro.j > 4) carro.j--; //move para esquerda--------------------------
                        break; 

                    case TECLA_DD:
                    case TECLA_d:
                    case RIGHT: if(carro.j < (COLUMN-5)) carro.j++; //move para direita------------------
                        break;                        
           
                    case TECLA_ESPACO: Sleep(50);
                    break;
            }
                   
}//fim while************************************
    
    system("pause");

return 0;
}