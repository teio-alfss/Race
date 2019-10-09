#include "race.h"
#include "display.h"


int main(){
    char matrix[LIN][COL];    
    int posi, posj, keypressed=0;

    //Posição inicial do avatar
    posi = 0;
    posj = COL/2;
    init(matrix);


    //Apaga cursor da tela
    ShowConsoleCursor(0);
    system("cls");

    while (keypressed != ESC){

        gotoxy(0,0);

        matrix[posi][posj] = 178;

        printMatrix(matrix);

        matrix[posi][posj];

        if(posi < LIN) posi++;



        //lendo as teclas==============================
        keypressed = 0;
        if(kbhit()) keypressed = getch();
            if(keypressed == ARROWS) keypressed = getch();

                switch(keypressed){
                    case TECLA_A :
                    case TECLA_a :
                    case LEFT    : if(posj > 1) posj--;
                    break;

                    case TECLA_D :
                    case TECLA_d :
                    case RIGHT   : if(posj < (COL - 2)) posj++;
                    break;
                }

    
    }//fim while
    
    system("pause");

return 0;
}
