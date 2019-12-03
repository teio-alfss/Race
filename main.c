/*        ***TEIO***
Alifer da Silva Souza -TADS-19

trabalho final semestre jogo Car Racing......
03/12/2019
*/
#include "race.h"
#include "display.h"

#define DEBUG 1

int main (){
   int keypressed = 0;
   int aleatorio;
   int *aleatorio1;
   int tempo=0, mapa=0;
   int level = 1;
   int menuJogo;
   char matrix[ROWS][COLUMN];
   char escolha;
   
   Bloco carro;
   Bloco carro_inimigo; 
   Bloco carro_inimigo1; 
   Bloco carro_inimigo2;
   Score playerT;
      
   //apagar cursor da tela
    ShowConsoleCursor(0);
    system("cls");
 
    NewCar(&carro);
    NewCar(&carro_inimigo);
    NewCar(&carro_inimigo1);
    NewCar(&carro_inimigo2);
    NewPlayer(&playerT);
    
   //rotina menu======================================================
   while (menuJogo != 6){
       
       MenuGame();
       scanf("%i",&menuJogo);
       if(menuJogo == 1){
       printf("Digite nome jogador:");
       fflush(stdin);
       gets(playerT.name);
       }
       system("cls");
       switch(menuJogo){
           
           case 1://rotina principal jogo=============================
            while (keypressed != ESC){
            gotoxy(0, 0);
            mapa++;
      
            printf("posicao = (%d,%d)\n",carro.i, carro.j);
            printf("LEVEL --> %i\nJogador--> %s\tPontos --> %i\n", level, playerT.name, playerT.ponto);    
            //printf("%i\n",mapa);

            if(mapa%4==0) init(matrix);
            if(mapa%4!=0) initM(matrix); 
            

            // sorteio do lado das pecas
           // if(carro_inimigo.i == 0 && carro_inimigo1.i == 0 && carro_inimigo2.i == 0) aleatorio = num_aleatorio();
            if(carro_inimigo.i > (ROWS - 6)){
                
            if(lados_aleatorios() == 0){
                carro_inimigo2.j = LADOL;
                carro_inimigo1.j = LADOL;
                carro_inimigo.j  = LADOR;

            }else if(lados_aleatorios() == 1){
                carro_inimigo.j = LADOL;
                carro_inimigo1.j= LADOR;
                carro_inimigo2.j= LADOL;

            }else if(lados_aleatorios() == 2){
                carro_inimigo2.j = LADOR;
                carro_inimigo1.j = LADOR;
                carro_inimigo.j  = LADOL;

            }else if(lados_aleatorios() == 3){
                carro_inimigo.j = LADOR;
                carro_inimigo1.j= LADOL;
                carro_inimigo2.j= LADOR;
            }
            }
            if(playerT.ponto > 800){
                tempo = 1;
                level = 2;
            }
            if(tempo == 0) Sleep(100);

            if(carro_inimigo2.i > 15) carro_inimigo1.i++;//o 1 carro e o segundo comecar a cair desde o comeco
            if(carro_inimigo1.i > 15) carro_inimigo.i++;
                                      carro_inimigo2.i++;
                        
            // inicio os carros apos a queda
            if(carro_inimigo.i > (ROWS-5)) carro_inimigo.i  = carro_inimigo1.i = carro_inimigo2.i = 0;
            
            //==============================================================================================    
            drawBar(matrix, carro_inimigo2, PiXEL);
            if(carro_inimigo2.i > 15) drawBar(matrix, carro_inimigo1, PiXEL); //feito para o 1 carro e o segundo comecar a cair desde o comeco
            if(carro_inimigo1.i > 15) drawBar(matrix, carro_inimigo, PiXEL);  //para o segundo carro comecar a cair
                
            
            //carro "amigo" controlado==========================================================
            drawBar(matrix, carro, PiXEL);
              
            //mostra a matrix na tela
            printMatrix(matrix);
                                   
            //apaga a posicao anterior
            drawBar(matrix, carro, EMPTY);

            drawBar(matrix, carro_inimigo, EMPTY);
            drawBar(matrix, carro_inimigo1, EMPTY);
            drawBar(matrix, carro_inimigo2, EMPTY);

            if(Colisao (matrix, carro, carro_inimigo2) == 1){
                printf("!!!!!PERDEU!!!!!\n");
                system("pause");
                break;
            }
            if(Colisao (matrix, carro, carro_inimigo1) == 1){
                printf("!!!!!PERDEU!!!!!\n");
                system("pause");
                break;
            }
            if(Colisao (matrix, carro, carro_inimigo) == 1){
                printf("!!!!!PERDEU!!!!!\n");
                system("pause");
                break;
            }

//Pontuação do joogo=================================================
    if(carro_inimigo2.i == carro.i || carro_inimigo1.i == carro.i || carro_inimigo.i == carro.i) playerT.ponto += PONTOS;


        if(playerT.ponto >= 600)tempo = 1;//controla a velocidade jogo 1 = rapidp
        if(playerT.ponto < 600) tempo = 0;//controla a velocidade 0 lento e faz o jogadore fica precionando o botao
        
        //lendo teclas--------------
        keypressed = 0;
        if(kbhit()) keypressed = getch();
            if (keypressed == ARROWS) keypressed = getch();// para capturar setas=================
    
                switch(keypressed){
                    case TECLA_AA:
                    case TECLA_a:
                    case LEFT: if(carro.j > 4) carro.j = LADOL; //move para esquerda--------------------------
                        break; 

                    case TECLA_DD:
                    case TECLA_d:
                    case RIGHT: if(carro.j < (COLUMN-5)) carro.j = LADOR ; //move para direita------------------
                        break;                        
           
                    case TECLA_ESPACO: tempo=1;
                    break;
                    
            }
        
}//fim while jogo************************************
    level = 1;
    playerT.ponto = mapa = 0;
    carro.j = COLUMN/2;
    carro_inimigo.i=carro_inimigo1.i=carro_inimigo2.i=0;        

        system("cls");
        break;
        system("cls");
        case 2: printf("nao confg\n");
                printf("LISTA DE JOGADORES\n");
                
                printf("1-%s  --- %d\n", playerT.name, playerT.ponto);
                
                system("pause");
        break;
        
        case 3: printf("QUER SAIR DO JOGO\n\t(s/n)\n");
                
                scanf("%c",&escolha);
                switch(escolha){
                    case 's':
                    case 'S':menuJogo=6;
                    break;

                    case 'n':
                    case 'N':
                    break;
                }
        break;
        
       }//switch menu-----------------------
   }//fim while menu========================
    
    system("pause");

return 0;
}