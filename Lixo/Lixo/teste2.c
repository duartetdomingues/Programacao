#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void main_menu() ;
void modo_j1();
void posicionamento();
void modo_p1();
void modo_p1_1();
void modo_p1_2();
void modo_p2();
void modo_j2();
void modo_j3();
void instrucoes();

int modo_jogo;


int main()
{
main_menu();
}

void main_menu(){
   // system("clear");
    //printf("\n █▀▀▄ █▀▀█ ▀▀█▀▀ █▀▀█ █   █  █ █▀▀█    █▀▀▄ █▀▀█ ▀█ █▀ █▀▀█ █\n █▀▀▄ █▄▄█   █   █▄▄█ █   █▀▀█ █▄▄█    █  █ █▄▄█  █▄█  █▄▄█ █\n ▀▀▀  ▀  ▀   ▀   ▀  ▀ ▀▀▀ ▀  ▀ ▀  ▀    ▀  ▀ ▀  ▀   ▀   ▀  ▀ ▀▀▀\n");
    //printf("\n                 Escolha uma opção de jogo:\n\n\n                  『1』 - Modo de Jogo 1\n\n                  『2』 - Modo de Jogo 2\n\n                  『3』 - Modo de jogo 3\n\n                  『4』 - Instruções\n\n");
   //        "    1 - Modo de Jogo 1    \n"
   //        "    2 - Modo de Jogo 2    \n"
   //        "    3 - Modo de Jogo 3    \n"
   //        "    4 - 𝐈𝐧𝐬𝐭𝐫𝐮çõ𝐞𝐬         \n"

  // if (scanf("%d", &modo_jogo) != 1){
        //char erro;
        //scanf("%c", &erro);  // limpar caracters
       // main_menu();
          // }
           
                modo_jogo=1;

    switch(modo_jogo){
        case 1:
        modo_j1();
        break;

        case 2:
        modo_j2();
        break;

        case 3:
        modo_j3();
        break;

        case 4:
        instrucoes();
        break;  

        default:
        main_menu();
    }  
    }

    void modo_j1(){
        system("clear");
        printf("\n █▀▀▄ █▀▀█ ▀▀█▀▀ █▀▀█ █   █  █ █▀▀█    █▀▀▄ █▀▀█ ▀█ █▀ █▀▀█ █\n █▀▀▄ █▄▄█   █   █▄▄█ █   █▀▀█ █▄▄█    █  █ █▄▄█  █▄█  █▄▄█ █\n ▀▀▀  ▀  ▀   ▀   ▀  ▀ ▀▀▀ ▀  ▀ ▀  ▀    ▀  ▀ ▀  ▀   ▀   ▀  ▀ ▀▀▀\n\n");
        printf("                    █▀▄▀█ █▀█ █▀▄ █▀█   ▄█\n                    █ ▀ █ █▄█ █▄▀ █▄█    █\n"); 
        posicionamento();
        //printf("\n      ════╦════╤════╤════╦════╤════╤════╦════╤════╤════╗\n        9 ║    │    │    ║    │    │    ║    │    │    ║\n      ────╫────┼────┼────╫────┼────┼────╫────┼────┼────╢\n        8 ║    │    │    ║    │    │    ║    │    │    ║\n      ────╫────┼────┼────╫────┼────┼────╫────┼────┼────╢\n        7 ║    │    │    ║    │    │    ║    │    │    ║\n      ════╬════╪════╪════╬════╪════╪════╬════╪════╪════╣\n        6 ║    │    │    ║    │    │    ║    │    │    ║\n      ────╫────┼────┼────╫────┼────┼────╫────┼────┼────╢\n        5 ║    │    │    ║    │    │    ║    │    │    ║\n      ────╫────┼────┼────╫────┼────┼────╫────┼────┼────╢\n        4 ║    │    │    ║    │    │    ║    │    │    ║\n      ════╬════╪════╪════╬════╪════╪════╬════╪════╪════╣\n        3 ║    │    │    ║    │    │    ║    │    │    ║\n      ────╫────┼────┼────╫────┼────┼────╫────┼────┼────╢\n        2 ║    │    │    ║    │    │    ║    │    │    ║\n      ────╫────┼────┼────╫────┼────┼────╫────┼────┼────╢\n        1 ║    │    │    ║    │    │    ║    │    │    ║\n      ════╬════╪════╪════╬════╪════╪════╬════╪════╪════╣\n          ║ A  │ B  │ C  ║ D  │ E  │ F  ║ G  │ H  │ I  ║\n\n");
    }

    void modo_j2(){
        system("clear");
        printf("\n █▀▀▄ █▀▀█ ▀▀█▀▀ █▀▀█ █   █  █ █▀▀█    █▀▀▄ █▀▀█ ▀█ █▀ █▀▀█ █\n █▀▀▄ █▄▄█   █   █▄▄█ █   █▀▀█ █▄▄█    █  █ █▄▄█  █▄█  █▄▄█ █\n ▀▀▀  ▀  ▀   ▀   ▀  ▀ ▀▀▀ ▀  ▀ ▀  ▀    ▀  ▀ ▀  ▀   ▀   ▀  ▀ ▀▀▀\n\n");
        printf("modo 2\n");
    }

    void modo_j3(){
        system("clear");
        printf("\n █▀▀▄ █▀▀█ ▀▀█▀▀ █▀▀█ █   █  █ █▀▀█    █▀▀▄ █▀▀█ ▀█ █▀ █▀▀█ █\n █▀▀▄ █▄▄█   █   █▄▄█ █   █▀▀█ █▄▄█    █  █ █▄▄█  █▄█  █▄▄█ █\n ▀▀▀  ▀  ▀   ▀   ▀  ▀ ▀▀▀ ▀  ▀ ▀  ▀    ▀  ▀ ▀  ▀   ▀   ▀  ▀ ▀▀▀\n\n");
        printf("modo 3\n"); 
    }

    void instrucoes(){
        system("clear");
        printf("\n █▀▀▄ █▀▀█ ▀▀█▀▀ █▀▀█ █   █  █ █▀▀█    █▀▀▄ █▀▀█ ▀█ █▀ █▀▀█ █\n █▀▀▄ █▄▄█   █   █▄▄█ █   █▀▀█ █▄▄█    █  █ █▄▄█  █▄█  █▄▄█ █\n ▀▀▀  ▀  ▀   ▀   ▀  ▀ ▀▀▀ ▀  ▀ ▀  ▀    ▀  ▀ ▀  ▀   ▀   ▀  ▀ ▀▀▀\n\n");
        printf("Instruções:\n"); 
        printf(" 🔲 ..........\n");
        printf(" 🔲 ..........\n");

    }
    void posicionamento(){
      modo_p1();

        //gerar numero para escolher posicionamento
        //modo_pn();   void para um dos modos do posionamento
    }

    void modo_p1(){

       int matriz_x,matriz_y,tipo,x,y,tentativa,xy[11][11]={{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0}};
        time_t t;

        srand((unsigned)time(&t));

        
        
        for(matriz_y=0;matriz_y<=2;matriz_y++){
            y=9-(matriz_y*3);
            
        for (matriz_x=0;matriz_x<=2;matriz_x++){
            x=1+(matriz_x*3);
            tentativa=0;

            jump:

                if (tentativa<=3){
            tipo= rand() % 4;
            printf("\n tipo=%d", tipo);
            printf("\n (x,y)=%d,%d",x,y);
            printf("\ntentativa=%d\n",tentativa);
            
        switch(tipo){
            case 0:xy[x][y] = 0;xy[x+1][y] = 0;xy[x+2][y] = 0;xy[x][y-1] = 0;xy[x+1][y-1] = 0;xy[x+2][y-1] = 0;xy[x][y-2] = 0;xy[x+1][y-2] = 0;xy[x+2][y-2] = 0;break;
            
            case 1:if (xy[x-1][y-1]==0 && xy[x-1][y]==0 && xy[x-1][y+1]==0 &&  xy[x][y+1]==0 && xy[x+1][y+1]==0 ){xy[x][y] = 1;xy[x+1][y] = 0;xy[x+2][y] = 0;xy[x][y-1] = 0;xy[x+1][y-1] = 0;xy[x+2][y-1] = 0;xy[x][y-2] = 0;xy[x+1][y-2] = 0;xy[x+2][y-2] = 0;} else { tentativa=tentativa+1; goto jump;} break;
            case 2:xy[x][y] = 0;xy[x+1][y] = 1;xy[x+2][y] = 0;xy[x][y-1] = 0;xy[x+1][y-1] = 0;xy[x+2][y-1] = 0;xy[x][y-2] = 0;xy[x+1][y-2] = 0;xy[x+2][y-2] = 0;break;
            case 3:xy[x][y] = 0;xy[x+1][y] = 0;xy[x+2][y] = 1;xy[x][y-1] = 0;xy[x+1][y-1] = 0;xy[x+2][y-1] = 0;xy[x][y-2] = 0;xy[x+1][y-2] = 0;xy[x+2][y-2] = 0;break;
            case 4:xy[x][y] = 0;xy[x+1][y] = 0;xy[x+2][y] = 0;xy[x][y-1] = 1;xy[x+1][y-1] = 0;xy[x+2][y-1] = 0;xy[x][y-2] = 0;xy[x+1][y-2] = 0;xy[x+2][y-2] = 0;break;
            case 5:xy[x][y] = 0;xy[x+1][y] = 0;xy[x+2][y] = 0;xy[x][y-1] = 0;xy[x+1][y-1] = 1;xy[x+2][y-1] = 0;xy[x][y-2] = 0;xy[x+1][y-2] = 0;xy[x+2][y-2] = 0;break;
            case 6:xy[x][y] = 0;xy[x+1][y] = 0;xy[x+2][y] = 0;xy[x][y-1] = 0;xy[x+1][y-1] = 0;xy[x+2][y-1] = 1;xy[x][y-2] = 0;xy[x+1][y-2] = 0;xy[x+2][y-2] = 0;break;
            case 7:xy[x][y] = 0;xy[x+1][y] = 0;xy[x+2][y] = 0;xy[x][y-1] = 0;xy[x+1][y-1] = 0;xy[x+2][y-1] = 0;xy[x][y-2] = 1;xy[x+1][y-2] = 0;xy[x+2][y-2] = 0;break;
            case 8:xy[x][y] = 0;xy[x+1][y] = 0;xy[x+2][y] = 0;xy[x][y-1] = 0;xy[x+1][y-1] = 0;xy[x+2][y-1] = 0;xy[x][y-2] = 0;xy[x+1][y-2] = 1;xy[x+2][y-2] = 0;break;
            case 9:xy[x][y] = 0;xy[x+1][y] = 0;xy[x+2][y] = 0;xy[x][y-1] = 0;xy[x+1][y-1] = 0;xy[x+2][y-1] = 0;xy[x][y-2] = 0;xy[x+1][y-2] = 0;xy[x+2][y-2] = 1;break;
        }
                }
        else {xy[x][y] = 0;xy[x+1][y] = 0;xy[x+2][y] = 0;xy[x][y-1] = 0;xy[x+1][y-1] = 1;xy[x+2][y-1] = 0;xy[x][y-2] = 0;xy[x+1][y-2] = 0;xy[x+2][y-2] = 0; }

        
        }
        }
        


        printf("\n      ═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
        printf("       9 ║ %d │ %d │ %d ║ %d │ %d │ %d ║ %d │ %d │ %d ║\n",xy[1][9],xy[2][9],xy[3][9],xy[4][9],xy[5][9],xy[6][9],xy[7][9],xy[8][9],xy[9][9]);
        printf("      ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
        printf("       8 ║ %d │ %d │ %d ║ %d │ %d │ %d ║ %d │ %d │ %d ║\n",xy[1][8],xy[2][8],xy[3][8],xy[4][8],xy[5][8],xy[6][8],xy[7][8],xy[8][8],xy[9][8]);
        printf("      ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
        printf("       7 ║ %d │ %d │ %d ║ %d │ %d │ %d ║ %d │ %d │ %d ║\n",xy[1][7],xy[2][7],xy[3][7],xy[4][7],xy[5][7],xy[6][7],xy[7][7],xy[8][7],xy[9][7]);
        printf("      ═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
        printf("       6 ║ %d │ %d │ %d ║ %d │ %d │ %d ║ %d │ %d │ %d ║\n",xy[1][6],xy[2][6],xy[3][6],xy[4][6],xy[5][6],xy[6][6],xy[7][6],xy[8][6],xy[9][6]);
        printf("      ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
        printf("       5 ║ %d │ %d │ %d ║ %d │ %d │ %d ║ %d │ %d │ %d ║\n",xy[1][5],xy[2][5],xy[3][5],xy[4][5],xy[5][5],xy[6][5],xy[7][5],xy[8][5],xy[9][5]);
        printf("      ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
        printf("       4 ║ %d │ %d │ %d ║ %d │ %d │ %d ║ %d │ %d │ %d ║\n",xy[1][4],xy[2][4],xy[3][4],xy[4][4],xy[5][4],xy[6][4],xy[7][4],xy[8][4],xy[9][4]);
        printf("      ═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
        printf("       3 ║ %d │ %d │ %d ║ %d │ %d │ %d ║ %d │ %d │ %d ║\n",xy[1][3],xy[2][3],xy[3][3],xy[4][3],xy[5][3],xy[6][3],xy[7][3],xy[8][3],xy[9][3]);
        printf("      ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
        printf("       2 ║ %d │ %d │ %d ║ %d │ %d │ %d ║ %d │ %d │ %d ║\n",xy[1][2],xy[2][2],xy[3][2],xy[4][2],xy[5][2],xy[6][2],xy[7][2],xy[8][2],xy[9][2]);
        printf("      ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
        printf("       1 ║ %d │ %d │ %d ║ %d │ %d │ %d ║ %d │ %d │ %d ║\n",xy[1][1],xy[2][1],xy[3][1],xy[4][1],xy[5][1],xy[6][1],xy[7][1],xy[8][1],xy[9][1]);
        printf("      ═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
        printf("         ║ A │ B │ C ║ D │ E │ F ║ G │ H │ I ║\n");


        //posicionar peças da forma p1
    }

    
    
    void modo_p1_2(){
        char ml1[9][12], ml2[9][12], ml3[9][12];
        int matriz, tipo;
        time_t t;

        srand((unsigned)time(&t));
        
        for (matriz=1;matriz<=9;matriz++){
            tipo= rand() % 42;
            printf("\n %d",tipo);
        switch(tipo){
        case 0:strcpy(ml1[matriz], "   |   |   ");strcpy(ml2[matriz], "   |   |   ");strcpy(ml3[matriz], "   |   |   ");break;

        case 1:strcpy(ml1[matriz], " 1 |   |   ");strcpy(ml2[matriz], "   |   |   ");strcpy(ml3[matriz], "   |   |   ");break;
        case 2:strcpy(ml1[matriz], "   | 1 |   ");strcpy(ml2[matriz], "   |   |   ");strcpy(ml3[matriz], "   |   |   ");break;
        case 3:strcpy(ml1[matriz], "   |   | 1 ");strcpy(ml2[matriz], "   |   |   ");strcpy(ml3[matriz], "   |   |   ");break;
        case 4:strcpy(ml1[matriz], "   |   |   ");strcpy(ml2[matriz], " 1 |   |   ");strcpy(ml3[matriz], "   |   |   ");break;
        case 5:strcpy(ml1[matriz], "   |   |   ");strcpy(ml2[matriz], "   | 1 |   ");strcpy(ml3[matriz], "   |   |   ");break;
        case 6:strcpy(ml1[matriz], "   |   |   ");strcpy(ml2[matriz], "   |   | 1 ");strcpy(ml3[matriz], "   |   |   ");break;
        case 7:strcpy(ml1[matriz], "   |   |   ");strcpy(ml2[matriz], "   |   |   ");strcpy(ml3[matriz], " 1 |   |   ");break;
        case 8:strcpy(ml1[matriz], "   |   |   ");strcpy(ml2[matriz], "   |   |   ");strcpy(ml3[matriz], "   | 1 |   ");break;
        case 9:strcpy(ml1[matriz], "   |   |   ");strcpy(ml2[matriz], "   |   |   ");strcpy(ml3[matriz], "   |   | 1 ");break;

        case 10:strcpy(ml1[matriz], " 2 | 2 |   ");strcpy(ml2[matriz], "   |   |   ");strcpy(ml3[matriz], "   |   |   ");break;
        case 11:strcpy(ml1[matriz], "   | 2 | 2 ");strcpy(ml2[matriz], "   |   |   ");strcpy(ml3[matriz], "   |   |   ");break;
        case 12:strcpy(ml1[matriz], "   |   |   ");strcpy(ml2[matriz], " 2 | 2 |   ");strcpy(ml3[matriz], "   |   |   ");break;
        case 13:strcpy(ml1[matriz], "   |   |   ");strcpy(ml2[matriz], "   | 2 | 2 ");strcpy(ml3[matriz], "   |   |   ");break;
        case 14:strcpy(ml1[matriz], "   |   |   ");strcpy(ml2[matriz], "   |   |   ");strcpy(ml3[matriz], " 2 | 2 |   ");break;
        case 15:strcpy(ml1[matriz], "   |   |   ");strcpy(ml2[matriz], "   |   |   ");strcpy(ml3[matriz], "   | 2 | 2 ");break;
        case 16:strcpy(ml1[matriz], " 2 |   |   ");strcpy(ml2[matriz], " 2 |   |   ");strcpy(ml3[matriz], "   |   |   ");break;
        case 17:strcpy(ml1[matriz], "   |   |   ");strcpy(ml2[matriz], " 2 |   |   ");strcpy(ml3[matriz], " 2 |   |   ");break;
        case 18:strcpy(ml1[matriz], "   | 2 |   ");strcpy(ml2[matriz], "   | 2 |   ");strcpy(ml3[matriz], "   |   |   ");break;
        case 19:strcpy(ml1[matriz], "   |   |   ");strcpy(ml2[matriz], "   | 2 |   ");strcpy(ml3[matriz], "   | 2 |   ");break;
        case 20:strcpy(ml1[matriz], "   |   | 2 ");strcpy(ml2[matriz], "   |   | 2 ");strcpy(ml3[matriz], "   |   |   ");break;
        case 21:strcpy(ml1[matriz], "   |   |   ");strcpy(ml2[matriz], "   |   | 2 ");strcpy(ml3[matriz], "   |   | 2 ");break;

        case 22:strcpy(ml1[matriz], " 3 | 3 | 3 ");strcpy(ml2[matriz], "   |   |   ");strcpy(ml3[matriz], "   |   |   ");break;
        case 23:strcpy(ml1[matriz], "   |   |   ");strcpy(ml2[matriz], " 3 | 3 | 3 ");strcpy(ml3[matriz], "   |   |   ");break;
        case 24:strcpy(ml1[matriz], "   |   |   ");strcpy(ml2[matriz], "   |   |   ");strcpy(ml3[matriz], " 3 | 3 | 3 ");break;
        case 25:strcpy(ml1[matriz], " 3 |   |   ");strcpy(ml2[matriz], " 3 |   |   ");strcpy(ml3[matriz], " 3 |   |   ");break;
        case 26:strcpy(ml1[matriz], "   | 3 |   ");strcpy(ml2[matriz], "   | 3 |   ");strcpy(ml3[matriz], "   | 3 |   ");break;
        case 27:strcpy(ml1[matriz], "   |   | 3 ");strcpy(ml2[matriz], "   |   | 3 ");strcpy(ml3[matriz], "   |   | 3 ");break;

        case 28:strcpy(ml1[matriz], " 4 | 4 |   ");strcpy(ml2[matriz], " 4 | 4 |   ");strcpy(ml3[matriz], "   |   |   ");break;
        case 29:strcpy(ml1[matriz], "   | 4 | 4 ");strcpy(ml2[matriz], "   | 4 | 4 ");strcpy(ml3[matriz], "   |   |   ");break;
        case 30:strcpy(ml1[matriz], "   |   |   ");strcpy(ml2[matriz], " 4 | 4 |   ");strcpy(ml3[matriz], " 4 | 4 |   ");break;
        case 31:strcpy(ml1[matriz], "   |   |   ");strcpy(ml2[matriz], "   | 4 | 4 ");strcpy(ml3[matriz], "   | 4 | 4 ");break;

        case 32:strcpy(ml1[matriz], " 5 | 5 | 5 ");strcpy(ml2[matriz], "   | 5 |   ");strcpy(ml3[matriz], "   | 5 |   ");break;
        case 33:strcpy(ml1[matriz], " 5 |   |   ");strcpy(ml2[matriz], " 5 | 5 | 5 ");strcpy(ml3[matriz], " 5 |   |   ");break;
        case 34:strcpy(ml1[matriz], "   | 5 |   ");strcpy(ml2[matriz], "   | 5 |   ");strcpy(ml3[matriz], " 5 | 5 | 5 ");break;
        case 35:strcpy(ml1[matriz], "   |   | 5 ");strcpy(ml2[matriz], " 5 | 5 | 5 ");strcpy(ml3[matriz], "   |   | 5 ");break;

        case 36:strcpy(ml1[matriz], "   | 6 |   ");strcpy(ml2[matriz], " 6 |   | 6 ");strcpy(ml3[matriz], " 6 | 6 | 6 ");break;
        case 37:strcpy(ml1[matriz], "   | 6 | 6 ");strcpy(ml2[matriz], " 6 |   | 6 ");strcpy(ml3[matriz], "   | 6 | 6 ");break;
        case 38:strcpy(ml1[matriz], " 6 | 6 | 6 ");strcpy(ml2[matriz], " 6 |   | 6 ");strcpy(ml3[matriz], "   | 6 |   ");break;
        case 39:strcpy(ml1[matriz], " 6 | 6 |   ");strcpy(ml2[matriz], " 6 |   | 6 ");strcpy(ml3[matriz], " 6 | 6 |   ");break;

        case 40:strcpy(ml1[matriz], " 7 |   | 7 ");strcpy(ml2[matriz], " 7 | 7 | 7 ");strcpy(ml3[matriz], " 7 |   | 7 ");break;
        case 41:strcpy(ml1[matriz], " 7 | 7 | 7 ");strcpy(ml2[matriz], "   | 7 |   ");strcpy(ml3[matriz], " 7 | 7 | 7 ");break;

        case 42:strcpy(ml1[matriz], " 8 | 8 | 8 ");strcpy(ml2[matriz], " 8 |   | 8 ");strcpy(ml3[matriz], " 8 | 8 | 8 ");break;


        }}

        printf("\n           ═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
        printf("            9 ║%s║%s║%s║\n",ml1[1],ml1[2],ml1[3]);
        printf("           ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
        printf("            8 ║%s║%s║%s║\n",ml2[1],ml2[2],ml2[3]);
        printf("           ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
        printf("            7 ║%s║%s║%s║\n",ml3[1],ml3[2],ml3[3]);
        printf("           ═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
        printf("            6 ║%s║%s║%s║\n",ml1[4],ml1[5],ml1[6]);
        printf("           ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
        printf("            5 ║%s║%s║%s║\n",ml2[4],ml2[5],ml2[6]);
        printf("           ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
        printf("            4 ║%s║%s║%s║\n",ml3[4],ml3[5],ml3[6]);
        printf("           ═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
        printf("            3 ║%s║%s║%s║\n",ml1[7],ml1[8],ml1[9]);
        printf("           ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
        printf("            2 ║%s║%s║%s║\n",ml2[7],ml2[8],ml2[9]);
        printf("           ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
        printf("            1 ║%s║%s║%s║\n",ml3[7],ml3[8],ml3[9]);
        printf("           ═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
        printf("              ║ A │ B │ C ║ D │ E │ F ║ G │ H │ I ║\n\n");
        
    }

    void modo_p2(){
        //posicionar peças da forma p2
    }
