#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void main_menu() ;
void modo_j0();
void posicionamento();
void modo_j1();
void modo_j2();
void instrucoes();
void modo_p1();
void modo_p2();
void print_tabu();



int modo_jogo;
char xy[12][12]={{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},};


int main()
{
main_menu();
}

void main_menu(){
    system("clear");
    printf("\n █▀▀▄ █▀▀█ ▀▀█▀▀ █▀▀█ █   █  █ █▀▀█    █▀▀▄ █▀▀█ ▀█ █▀ █▀▀█ █\n █▀▀▄ █▄▄█   █   █▄▄█ █   █▀▀█ █▄▄█    █  █ █▄▄█  █▄█  █▄▄█ █\n ▀▀▀  ▀  ▀   ▀   ▀  ▀ ▀▀▀ ▀  ▀ ▀  ▀    ▀  ▀ ▀  ▀   ▀   ▀  ▀ ▀▀▀\n");
    printf("\n                 Escolha uma opção de jogo:\n\n\n                  『0』 - Modo de Jogo 0\n\n                  『1』 - Modo de Jogo 1\n\n                  『2』 - Modo de jogo 2\n\n                  『3』 - Instruções\n\n");
   //        "    0 - Modo de Jogo 0    \n"
   //        "    1 - Modo de Jogo 1    \n"
   //        "    2 - Modo de Jogo 2    \n"
   //        "    3 - 𝐈𝐧𝐬𝐭𝐫𝐮çõ𝐞𝐬         \n"

  if (scanf("%d", &modo_jogo) != 1){
        char erro;
        scanf("%c", &erro);  // limpar caracters
       main_menu();
           }
           

    switch(modo_jogo){
        case 0:
        modo_j0();
        break;

        case 1:
        modo_j1();
        break;

        case 2:
        modo_j2();
        break;

        case 3:
        instrucoes();
        break;  

        default:
        main_menu();
    }  
    }

    void modo_j0(){
        system("clear");
        printf("\n █▀▀▄ █▀▀█ ▀▀█▀▀ █▀▀█ █   █  █ █▀▀█    █▀▀▄ █▀▀█ ▀█ █▀ █▀▀█ █\n █▀▀▄ █▄▄█   █   █▄▄█ █   █▀▀█ █▄▄█    █  █ █▄▄█  █▄█  █▄▄█ █\n ▀▀▀  ▀  ▀   ▀   ▀  ▀ ▀▀▀ ▀  ▀ ▀  ▀    ▀  ▀ ▀  ▀   ▀   ▀  ▀ ▀▀▀\n\n");
        printf("                    █▀▄▀█ █▀█ █▀▄ █▀█   ▄█\n                    █ ▀ █ █▄█ █▄▀ █▄█    █\n"); 
        
        posicionamento();
        print_tabu();
    
    }

    void modo_j1(){
        system("clear");
        printf("\n █▀▀▄ █▀▀█ ▀▀█▀▀ █▀▀█ █   █  █ █▀▀█    █▀▀▄ █▀▀█ ▀█ █▀ █▀▀█ █\n █▀▀▄ █▄▄█   █   █▄▄█ █   █▀▀█ █▄▄█    █  █ █▄▄█  █▄█  █▄▄█ █\n ▀▀▀  ▀  ▀   ▀   ▀  ▀ ▀▀▀ ▀  ▀ ▀  ▀    ▀  ▀ ▀  ▀   ▀   ▀  ▀ ▀▀▀\n\n");
        printf("modo 1\n");
    }

    void modo_j2(){
        system("clear");
        printf("\n █▀▀▄ █▀▀█ ▀▀█▀▀ █▀▀█ █   █  █ █▀▀█    █▀▀▄ █▀▀█ ▀█ █▀ █▀▀█ █\n █▀▀▄ █▄▄█   █   █▄▄█ █   █▀▀█ █▄▄█    █  █ █▄▄█  █▄█  █▄▄█ █\n ▀▀▀  ▀  ▀   ▀   ▀  ▀ ▀▀▀ ▀  ▀ ▀  ▀    ▀  ▀ ▀  ▀   ▀   ▀  ▀ ▀▀▀\n\n");
        printf("modo 2\n"); 
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

        int matriz_x, matriz_y, peca, n_pecas, x, y, tentativa;
        time_t t;

        srand((unsigned)time(&t));

        for(matriz_y=0;matriz_y<=2;matriz_y++){
        y=9-(matriz_y*3);
            
            for (matriz_x=0;matriz_x<=2;matriz_x++){
                x=1+(matriz_x*3);
                tentativa=1;

                jump:
                printf("  (x,y)=%d,%d",x,y);
                printf("  tentativa=%d",tentativa);

                if (tentativa<=3){
                    peca= rand() % 42;
                    printf(" tipo=%d\n", peca);

                    switch(v_peca){
                        case 0:xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';break;
                        
                        case 1: if (xy[x-1][y-1]== ' ' && xy[x-1][y]== ' ' && xy[x-1][y+1]== ' ' &&  xy[x][y+1]== ' ' && xy[x+1][y+1]== ' '){xy[x][y] = '1';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' '; } else {tentativa=tentativa+1; goto jump;} break;
                        case 2: if (xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' '){xy[x][y] = ' ';xy[x+1][y] = '1';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';} else {tentativa=tentativa+1; goto jump;} break;
                        case 3: if (xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' && xy[x+3][y+1]== ' ' && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' '){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = '1';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';} else {tentativa=tentativa+1; goto jump;} break;
                        case 4: if (xy[x-1][y]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' '){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = '1';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';}else {tentativa=tentativa+1; goto jump;} break;
                        case 5: xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = '1';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';break;
                        case 6: if (xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y-2]== ' '){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = '1';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';}else {tentativa=tentativa+1; goto jump;} break;
                        case 7: if (xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' ' && xy[x-1][y-3]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' '){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = '1';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';}else {tentativa=tentativa+1; goto jump;} break;
                        case 8: if (xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' '){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = '1';xy[x+2][y-2] = ' ';}else {tentativa=tentativa+1; goto jump;} break;
                        case 9: if (xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' ' && xy[x+3][y-3]== ' ' && xy[x+3][y-2]== ' ' && xy[x+3][y-1]== ' '){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = '1';}else {tentativa=tentativa+1; goto jump;} break;
                        
                        case 10:if (xy[x-1][y-1]== ' ' && xy[x-1][y]== ' ' && xy[x-1][y+1]== ' ' &&  xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' ){xy[x][y] = '2';xy[x+1][y] = '2';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';} else { tentativa=tentativa+1; goto jump;} break;
                        case 11:if (xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' &&  xy[x+3][y+1]== ' ' && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' ){xy[x][y] = ' ';xy[x+1][y] = '2';xy[x+2][y] = '2';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';} else { tentativa=tentativa+1; goto jump;} break;
                        case 12:if (xy[x-1][y-2]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y]== ' ' ){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = '2';xy[x+1][y-1] = '2';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';} else { tentativa=tentativa+1; goto jump;} break;
                        case 13:if (xy[x+3][y-2]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y]== ' ' ){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = '2';xy[x+2][y-1] = '2';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';} else { tentativa=tentativa+1; goto jump;} break;
                        case 14:if (xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' ' && xy[x-1][y-3]== ' ' && xy[x][y-3]== ' ' &&  xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' ' ){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = '2';xy[x+1][y-2] = '2';xy[x+2][y-2] = ' ';} else { tentativa=tentativa+1; goto jump;} break;
                        case 15:if (xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' ' &&  xy[x+3][y-3]== ' ' && xy[x+3][y-2]== ' ' && xy[x+3][y-1]== ' ' ){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = '2';xy[x+2][y-2] = '2';} else { tentativa=tentativa+1; goto jump;} break;
                        case 16:if (xy[x-1][y-2]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y]== ' ' &&  xy[x-1][y+1]== ' ' && xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' ){xy[x][y] = '2';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = '2';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';} else { tentativa=tentativa+1; goto jump;} break;
                        case 17:if (xy[x-1][y]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' ' &&  xy[x-1][y-3]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' ){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = '2';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = '2';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';} else { tentativa=tentativa+1; goto jump;} break;
                        case 18:if (xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' ){xy[x][y] = ' ';xy[x+1][y] = '2';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = '2';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';} else { tentativa=tentativa+1; goto jump;} break;
                        case 19:if (xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' ' ){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = '2';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = '2';xy[x+2][y-2] = ' ';} else { tentativa=tentativa+1; goto jump;} break;
                        case 20:if (xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' && xy[x+3][y+1]== ' ' &&  xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y-2]== ' ' ){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = '2';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = '2';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';} else { tentativa=tentativa+1; goto jump;} break;
                        case 21:if (xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' ' && xy[x+3][y-3]== ' ' &&  xy[x+3][y-2]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y]== ' ' ){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = '2';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = '2';} else { tentativa=tentativa+1; goto jump;} break;

                        case 22: if (xy[x-1][y-1]== ' ' && xy[x-1][y]== ' ' && xy[x-1][y+1]== ' ' && xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' && xy[x+3][y+1]== ' ' && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' '){xy[x][y] = '3';xy[x+1][y] = '3';xy[x+2][y] = '3';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';}else {tentativa=tentativa+1; goto jump;} break;
                        case 23: if (xy[x-1][y-2]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y]== ' ' && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y-2]== ' ' ){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = '3';xy[x+1][y-1] = '3';xy[x+2][y-1] = '3';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';}else {tentativa=tentativa+1; goto jump;} break;
                        case 24: if (xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' ' && xy[x-1][y-3]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' ' && xy[x+3][y-3]== ' ' && xy[x+3][y-2]== ' ' && xy[x+3][y-1]== ' '){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = '3';xy[x+1][y-2] = '3';xy[x+2][y-2] = '3';}else {tentativa=tentativa+1; goto jump;} break;
                        case 25: if (xy[x+1][y+1]== ' ' && xy[x][y+1]== ' ' && xy[x-1][y+1]== ' ' && xy[x-1][y]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' ' && xy[x-1][y-3]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' '){xy[x][y] = '3';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = '3';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = '3';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';}else {tentativa=tentativa+1; goto jump;} break;
                        case 26: if (xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' '){xy[x][y] = ' ';xy[x+1][y] = '3';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = '3';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = '3';xy[x+2][y-2] = ' ';}else {tentativa=tentativa+1; goto jump;} break;
                        case 27: if (xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' && xy[x+3][y+1]== ' ' && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y-2]== ' ' && xy[x+3][y-3]== ' ' && xy[x+2][y-3]== ' ' && xy[x+1][y-3]== ' '){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = '3';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = '3';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = '3';}else {tentativa=tentativa+1; goto jump;} break;
                        
                        case 28: if (xy[x-1][y-2]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y]== ' ' && xy[x-1][y+1]== ' ' && xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' '){xy[x][y] = '4';xy[x+1][y] = '4';xy[x+2][y] = ' ';xy[x][y-1] = '4';xy[x+1][y-1] = '4';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';}else {tentativa=tentativa+1; goto jump;} break;
                        case 29: if (xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' && xy[x+3][y+1]== ' ' && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y-2]== ' '){xy[x][y] = ' ';xy[x+1][y] = '4';xy[x+2][y] = '4';xy[x][y-1] = ' ';xy[x+1][y-1] = '4';xy[x+2][y-1] = '4';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';}else {tentativa=tentativa+1; goto jump;} break;
                        case 30: if (xy[x-1][y]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' ' && xy[x-1][y-3]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' '){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = '4';xy[x+1][y-1] = '4';xy[x+2][y-1] = ' ';xy[x][y-2] = '4';xy[x+1][y-2] = '4';xy[x+2][y-2] = ' ';}else {tentativa=tentativa+1; goto jump;} break;
                        case 31: if (xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' ' && xy[x+3][y-3]== ' ' && xy[x+3][y-2]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y]== ' '){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = '4';xy[x+2][y-1] = '4';xy[x][y-2] = ' ';xy[x+1][y-2] = '4';xy[x+2][y-2] = '4';}else {tentativa=tentativa+1; goto jump;} break;

                        case 32: if (xy[x-1][y-1]== ' ' && xy[x-1][y]== ' ' && xy[x-1][y+1]== ' ' && xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' && xy[x+3][y+1]== ' ' && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' '){xy[x][y] = '5';xy[x+1][y] = '5';xy[x+2][y] = '5';xy[x][y-1] = ' ';xy[x+1][y-1] = '5';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = '5';xy[x+2][y-2] = ' ';}else {tentativa=tentativa+1; goto jump;} break;
                        case 33: if (xy[x+1][y+1]== ' ' && xy[x][y+1]== ' ' && xy[x-1][y+1]== ' ' && xy[x-1][y]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' ' && xy[x-1][y-3]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' '  && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y-2]== ' '){xy[x][y] = '5';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = '5';xy[x+1][y-1] = '5';xy[x+2][y-1] = '5';xy[x][y-2] = '5';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';}else {tentativa=tentativa+1; goto jump;} break;
                        case 34: if (xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' ' && xy[x-1][y-3]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' ' && xy[x+3][y-3]== ' ' && xy[x+3][y-2]== ' ' && xy[x+3][y-1]== ' ' && xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' '){xy[x][y] = ' ';xy[x+1][y] = '5';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = '5';xy[x+2][y-1] = ' ';xy[x][y-2] = '5';xy[x+1][y-2] = '5';xy[x+2][y-2] = '5';}else {tentativa=tentativa+1; goto jump;} break;
                        case 35: if (xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' && xy[x+3][y+1]== ' ' && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y-2]== ' ' && xy[x+3][y-3]== ' ' && xy[x+2][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x-1][y]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' '){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = '5';xy[x][y-1] = '5';xy[x+1][y-1] = '5';xy[x+2][y-1] = '5';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = '5';}else {tentativa=tentativa+1; goto jump;} break;

                        case 36: if (xy[x-1][y]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' ' &&  xy[x-1][y-3]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' ' && xy[x+3][y-3]== ' ' &&  xy[x+3][y-2]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y]== ' ' && xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' '){xy[x][y] = ' ';xy[x+1][y] = '6';xy[x+2][y] = ' ';xy[x][y-1] = '6';xy[x+1][y-1] = ' ';xy[x+2][y-1] = '6';xy[x][y-2] = '6';xy[x+1][y-2] = '6';xy[x+2][y-2] = '6';}else {tentativa=tentativa+1; goto jump;} break;
                        case 37: if (xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' &&  xy[x+3][y+1]== ' ' && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' ' &&  xy[x+3][y-3]== ' ' && xy[x+3][y-2]== ' ' && xy[x-1][y]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' '){xy[x][y] = ' ';xy[x+1][y] = '6';xy[x+2][y] = '6';xy[x][y-1] = '6';xy[x+1][y-1] = ' ';xy[x+2][y-1] = '6';xy[x][y-2] = ' ';xy[x+1][y-2] = '6';xy[x+2][y-2] = '6';} else { tentativa=tentativa+1; goto jump;} break;
                        case 38: if (xy[x-1][y-2]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y]== ' ' &&  xy[x-1][y+1]== ' ' && xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' && xy[x+3][y+1]== ' ' &&  xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y-2]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' '){xy[x][y] = '6';xy[x+1][y] = '6';xy[x+2][y] = '6';xy[x][y-1] = '6';xy[x+1][y-1] = ' ';xy[x+2][y-1] = '6';xy[x][y-2] = ' ';xy[x+1][y-2] = '6';xy[x+2][y-2] = ' ';} else { tentativa=tentativa+1; goto jump;} break;
                        case 39: if (xy[x-1][y-1]== ' ' && xy[x-1][y]== ' ' && xy[x-1][y+1]== ' ' &&  xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' && xy[x-1][y-2]== ' ' && xy[x-1][y-3]== ' ' && xy[x][y-3]== ' ' &&  xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' ' && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y-2]== ' '){xy[x][y] = '6';xy[x+1][y] = '6';xy[x+2][y] = ' ';xy[x][y-1] = '6';xy[x+1][y-1] = ' ';xy[x+2][y-1] = '6';xy[x][y-2] = '6';xy[x+1][y-2] = '6';xy[x+2][y-2] = ' ';} else { tentativa=tentativa+1; goto jump;} break;

                        case 40: if (xy[x+1][y+1]== ' ' && xy[x][y+1]== ' ' && xy[x-1][y+1]== ' ' && xy[x-1][y]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' ' && xy[x-1][y-3]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y+1]== ' ' && xy[x+3][y+1]== ' ' && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y-2]== ' ' && xy[x+3][y-3]== ' ' && xy[x+2][y-3]== ' '){xy[x][y] = '7';xy[x+1][y] = ' ';xy[x+2][y] = '7';xy[x][y-1] = '7';xy[x+1][y-1] = '7';xy[x+2][y-1] = '7';xy[x][y-2] = '7';xy[x+1][y-2] = ' ';xy[x+2][y-2] = '7';}else {tentativa=tentativa+1; goto jump;} break;
                        case 41: if (xy[x+1][y+1]== ' ' && xy[x][y+1]== ' ' && xy[x-1][y+1]== ' ' && xy[x-1][y]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' ' && xy[x-1][y-3]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y+1]== ' ' && xy[x+3][y+1]== ' ' && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y-2]== ' ' && xy[x+3][y-3]== ' ' && xy[x+2][y-3]== ' '){xy[x][y] = '7';xy[x+1][y] = '7';xy[x+2][y] = '7';xy[x][y-1] = ' ';xy[x+1][y-1] = '7';xy[x+2][y-1] = ' ';xy[x][y-2] = '7';xy[x+1][y-2] = '7';xy[x+2][y-2] = '7';}else {tentativa=tentativa+1; goto jump;} break;

                        case 42: if (xy[x+1][y+1]== ' ' && xy[x][y+1]== ' ' && xy[x-1][y+1]== ' ' && xy[x-1][y]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' ' && xy[x-1][y-3]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y+1]== ' ' && xy[x+3][y+1]== ' ' && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y-2]== ' ' && xy[x+3][y-3]== ' ' && xy[x+2][y-3]== ' '){xy[x][y] = '8';xy[x+1][y] = '8';xy[x+2][y] = '8';xy[x][y-1] = '8';xy[x+1][y-1] = ' ';xy[x+2][y-1] = '8';xy[x][y-2] = '8';xy[x+1][y-2] = '8';xy[x+2][y-2] = '8';}else {tentativa=tentativa+1; goto jump;} break;

                    }
                
                }
                else {printf(" else tipo=5\n");xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = '1';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';}
            }
        }
        //case 10:if (xy[x][y]==0 && xy[x][y]==0 && xy[x][y]==0 &&  xy[x][y]==0 && xy[x][y]==0 ){xy[x][y] = 0;xy[x+1][y] = 0;xy[x+2][y] = 0;xy[x][y-1] = 0;xy[x+1][y-1] = 0;xy[x+2][y-1] = 0;xy[x][y-2] = 0;xy[x+1][y-2] = 0;xy[x+2][y-2] = 0;} else { tentativa=tentativa+1; goto jump;} break;
        //posicionar peças da forma p1
    }

    void modo_p2(){
        //posicionar peças da forma p2
    }

    void print_tabu(){
        printf("\n      ═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
        printf("       9 ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",xy[1][9],xy[2][9],xy[3][9],xy[4][9],xy[5][9],xy[6][9],xy[7][9],xy[8][9],xy[9][9]);
        printf("      ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
        printf("       8 ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",xy[1][8],xy[2][8],xy[3][8],xy[4][8],xy[5][8],xy[6][8],xy[7][8],xy[8][8],xy[9][8]);
        printf("      ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
        printf("       7 ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",xy[1][7],xy[2][7],xy[3][7],xy[4][7],xy[5][7],xy[6][7],xy[7][7],xy[8][7],xy[9][7]);
        printf("      ═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
        printf("       6 ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",xy[1][6],xy[2][6],xy[3][6],xy[4][6],xy[5][6],xy[6][6],xy[7][6],xy[8][6],xy[9][6]);
        printf("      ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
        printf("       5 ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",xy[1][5],xy[2][5],xy[3][5],xy[4][5],xy[5][5],xy[6][5],xy[7][5],xy[8][5],xy[9][5]);
        printf("      ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
        printf("       4 ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",xy[1][4],xy[2][4],xy[3][4],xy[4][4],xy[5][4],xy[6][4],xy[7][4],xy[8][4],xy[9][4]);
        printf("      ═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
        printf("       3 ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",xy[1][3],xy[2][3],xy[3][3],xy[4][3],xy[5][3],xy[6][3],xy[7][3],xy[8][3],xy[9][3]);
        printf("      ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
        printf("       2 ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",xy[1][2],xy[2][2],xy[3][2],xy[4][2],xy[5][2],xy[6][2],xy[7][2],xy[8][2],xy[9][2]);
        printf("      ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
        printf("       1 ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",xy[1][1],xy[2][1],xy[3][1],xy[4][1],xy[5][1],xy[6][1],xy[7][1],xy[8][1],xy[9][1]);
        printf("      ═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
        printf("         ║ A │ B │ C ║ D │ E │ F ║ G │ H │ I ║\n");
    }