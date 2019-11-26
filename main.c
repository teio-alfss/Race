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
   
    FILE *scores;
    int codi;
    





   int keypressed = 0;
   int aleatorio;
   int tempo=0, mapa=0;
   int level = 1;
   int menuJogo;
   char matrix[ROWS][COLUMN];
   
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
       printf("Digite nume jogador:");
       fflush(stdin);
       gets(playerT.name);
       }
       system("cls");
       switch(menuJogo){
           
           case 1://rotina principal jogo=============================
            while (keypressed != ESC){
            gotoxy(0, 0);
            mapa++;
            #if DEBUG == 1
                printf("posicao = (%d,%d)\n",carro.i, carro.j);
                printf("aleatorio --> %d\n",aleatorio);
            #endif
                printf("LEVEL --> %ld\nJogador %s\tPontuação --> %i\n", level, playerT.name, playerT.ponto);

            if(mapa%4==0) init(matrix);
            if(mapa%4!=0) initM(matrix); 
            

            // sorteio do lado das pecas
            if(carro_inimigo.i > (ROWS - 6)){
            if(aleatorio%2 == 0 ){
                carro_inimigo.j = LADOR;
                carro_inimigo1.j = LADOL;
                carro_inimigo2.j = LADOL;
                

            }else if(aleatorio%5 == 0 ){
                carro_inimigo.j = LADOL;
                carro_inimigo1.j = LADOL;
                carro_inimigo2.j = LADOR;

            }else if(aleatorio%5 != 0 ){
                carro_inimigo.j = LADOR;
                carro_inimigo1.j = LADOL;
                carro_inimigo2.j = LADOR;

            }else if(aleatorio%2 != 0 ){
                carro_inimigo.j = LADOL;
                carro_inimigo1.j = LADOR;
                carro_inimigo2.j = LADOL;
            }
            
            }
            if(playerT.ponto > 800) tempo=level=2;
            if(tempo == 0 ) Sleep(100);
            if(carro_inimigo2.i > 15) carro_inimigo1.i++;//o 1 carro e o segundo comecar a cair desde o comeco
            if(carro_inimigo1.i > 15) carro_inimigo.i++;
                                      carro_inimigo2.i++;
                        
            // inicio os carros apos a queda
            if(carro_inimigo.i > (ROWS-5)){
                carro_inimigo.i  = carro_inimigo1.i = carro_inimigo2.i = 0;
            }
            if(carro_inimigo.i == 0 && carro_inimigo1.i == 0 && carro_inimigo2.i == 0){
               aleatorio = num_aleatorio();
            }
            //==============================================================================================    
            drawBar(matrix, carro_inimigo2, PiXEL);
            if(carro_inimigo2.i > 15) drawBar(matrix, carro_inimigo1, PiXEL); //feito para o 1 carro e o segundo comecar a cair desde o comeco
            if(carro_inimigo1.i > 15) drawBar(matrix, carro_inimigo, PiXEL);   //para o segundo carro comecar a cair
                
            
            //carro "amigo" controlado==========================================================
            drawBar(matrix, carro, PiXEL);
              
            //mostra a matrix na tela
            printMatrix(matrix);
                                   
            //apaga a posicao anterior
            drawBar(matrix, carro, EMPTY);

            drawBar(matrix, carro_inimigo, EMPTY);
            drawBar(matrix, carro_inimigo1, EMPTY);
            drawBar(matrix, carro_inimigo2, EMPTY);

           //colisao de carros==================================================
           if(carro.i == carro_inimigo2.i+3 && (carro.j == carro_inimigo2.j || carro.j-4 == carro_inimigo2.j || carro.j+4 == carro_inimigo2.j ||carro.j-3 == carro_inimigo2.j || carro.j+3 == carro_inimigo2.j || carro.j+2 == carro_inimigo2.j || carro.j-2 == carro_inimigo2.j || carro.j+1 == carro_inimigo2.j || carro.j-1 == carro_inimigo2.j)){
                printf("!!!!!PERDEU!!!!!\n");
                system("pause");
                break;
                }
           /* if(carro.i == carro_inimigo1.i+3 && (carro.j == carro_inimigo1.j || carro.j-4 == carro_inimigo1.j || carro.j+4 == carro_inimigo1.j ||carro.j-3 == carro_inimigo1.j || carro.j+3 == carro_inimigo1.j || carro.j+2 == carro_inimigo1.j || carro.j-2 == carro_inimigo1.j || carro.j+1 == carro_inimigo1.j || carro.j-1 == carro_inimigo1.j)){              
                printf("!!!!!PERDEU!!!!!\n");
                system("pause");
                break;
                }
            if(carro.i == carro_inimigo.i+3 && (carro.j == carro_inimigo.j || carro.j-4 == carro_inimigo.j || carro.j+4 == carro_inimigo.j ||carro.j-3 == carro_inimigo.j || carro.j+3 == carro_inimigo.j || carro.j+2 == carro_inimigo.j || carro.j-2 == carro_inimigo.j || carro.j+1 == carro_inimigo.j || carro.j-1 == carro_inimigo.j) ){
                printf("!!!!!PERDEU!!!!!\n");
                system("pause");
                break;
                }*/

//Pontuação dp joogo=================================================
    if(carro_inimigo2.i == carro.i || carro_inimigo1.i == carro.i || carro_inimigo.i == carro.i) playerT.ponto += PONTOS;


        if(!playerT.ponto == 800)tempo = 0;//controla a velocidade jogo
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
           
                    case TECLA_ESPACO: tempo=1;
                    break;
                    
            }
        
}//fim while jogo************************************
    
    scores = fopen("highscore.txt","w");
        if(scores == NULL){
            printf("error");
            exit (0);
        }
    codi++;
    playerT.cod = codi;
    fwrite(&playerT, 100, 1, scores);

    fclose(scores);







    
    
    level = 1;
    playerT.ponto = 0;
    carro.j = COLUMN/2;
    carro_inimigo.i=carro_inimigo1.i=carro_inimigo2.i=0;        

        system("cls");
        break;
        system("cls");
        case 2: printf("nao confg\n");
                printf("LISTA DE JOGADORES\n");
                while(playerT.cod == sizeof(Score)){
                printf("1-%s  --- %d\n", playerT.name, playerT.ponto);
                }
                system("pause");
        break;
        
        case 3: printf("QUER SAIR DO JOGO\n\t(s/n)\n");
                char escolha;
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