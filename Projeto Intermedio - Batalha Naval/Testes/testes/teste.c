#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void main_menu() ;
void modo_j0();
void modo_j1();
void modo_j2();
void instrucoes();
void modo_p1();
void modo_p2();
void print_tabu();
void print_logo();
void print_modo_x();
void print_pecas();

int modo_jogo=-1, modo_pos,dim_tabu_x,dim_tabu_y,peca_n[9]={0,0,0,0,0,0,0,0,0};


char yx[17][26]=
{{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};

time_t t;

int main()
{
main_menu();
}

void main_menu(){
    //system("clear");
    print_logo();
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
        int e;
        do{
        e=0;
        system("clear");
        print_logo();
        printf("Escola a dimensão do Tabuleiro?( Ex.: 9x9 (colunas*linhas) )\n");
        if (scanf("%dx%d", &dim_tabu_y,&dim_tabu_x) != 2){
        char erro;
        scanf("%c", &erro);  // limpar caracters
        e=1;}
        else{
            if(dim_tabu_x % 3 | dim_tabu_x<9 | dim_tabu_x>24 | dim_tabu_y % 3 | dim_tabu_y<9 | dim_tabu_y>15 ){e=1;}
        }}while (e!= 0);
         
        do{
        e=0;
        system("clear");
        print_logo();
        printf("Escolha o modo de posicionamento que deseja, 1 ou 2?\n");
        if (scanf("%d", &modo_pos) != 1){
        char erro;
        scanf("%c", &erro);  // limpar caracters
        e=1;}
        else{
        system("clear");
        print_logo();
        switch(modo_pos){
        case 1:modo_p1();print_tabu();print_pecas(); break; 
        case 2:modo_p2();print_tabu();print_pecas(); break;
        default: e=1;break;}}
        }while (e!=0);
    
    }

    void modo_j1(){
        system("clear");
        print_logo();
        printf("modo 1\n");
    }

    void modo_j2(){
        system("clear");
        print_logo();
        printf("modo 2\n"); 
    }

    void instrucoes(){
        system("clear");
        print_logo();
        printf("Instruções:\n"); 
        printf(" 🔲 ..........\n");
        printf(" 🔲 ..........\n");

    }
    
    void modo_p1(){
        int matriz_x, matriz_y, peca, x, y, tentativa,e;
        //printf("m_y=%d m_x=%d dim_tabu(x)=%d dim_tabu(y)=%d\n",m_y,m_x,dim_tabu_y,dim_tabu_x);
        srand((unsigned)time(&t));
        matriz_y=-1;

        do{
            matriz_x=-1;
            matriz_y=matriz_y+1;
            y=dim_tabu_y-(matriz_y*3);
            //printf("y=%d\n", y);
            
            do{
                matriz_x=matriz_x+1;
                x=1+(matriz_x*3);
                tentativa=1;
                //printf("x=%d matriz_x=%d\n", x, matriz_x);
                
                do{
                    e=0;
                    printf("  (x,y)=%d,%d",x,y);
                    //printf("  tentativa=%d",tentativa);

                    if (tentativa<=3){
                        peca= rand() % 43;
                        printf(" tipo=%d\n", peca);
                        switch(peca){
                        case 0:yx[y][x] = ' ';yx[y][x+1] = ' ';yx[y][x+2] = ' ';yx[y-1][x] = ' ';yx[y-1][x+1] = ' ';yx[y-1][x+2] = ' ';yx[y-2][x] = ' ';yx[y-2][x+1] = ' ';yx[y-2][x+2] = ' ';peca_n[0]++; break;
                        
                        case 1: if (yx[y-1][x-1]== ' ' && yx[y][x-1]== ' ' && yx[y+1][x-1]== ' ' &&  yx[y+1][x]== ' ' && yx[y+1][x+1]== ' '){yx[y][x] = '1';yx[y][x+1] = ' ';yx[y][x+2] = ' ';yx[y-1][x] = ' ';yx[y-1][x+1] = ' ';yx[y-1][x+2] = ' ';yx[y-2][x] = ' ';yx[y-2][x+1] = ' ';yx[y-2][x+2] = ' '; peca_n[1]++;} else {tentativa=tentativa+1;  e=1;} break;
                        case 2: if (yx[y+1][x]== ' ' && yx[y+1][x+1]== ' ' && yx[y+1][x+2]== ' '){yx[y][x] = ' ';yx[y][x+1] = '1';yx[y][x+2] = ' ';yx[y-1][x] = ' ';yx[y-1][x+1] = ' ';yx[y-1][x+2] = ' ';yx[y-2][x] = ' ';yx[y-2][x+1] = ' ';yx[y-2][x+2] = ' ';peca_n[1]++;} else {tentativa=tentativa+1;  e=1;} break;
                        case 3: if (yx[y+1][x+1]== ' ' && yx[y+1][x+2]== ' ' && yx[y+1][x+3]== ' ' && yx[y][x+3]== ' ' && yx[y-1][x+3]== ' '){yx[y][x] = ' ';yx[y][x+1] = ' ';yx[y][x+2] = '1';yx[y-1][x] = ' ';yx[y-1][x+1] = ' ';yx[y-1][x+2] = ' ';yx[y-2][x] = ' ';yx[y-2][x+1] = ' ';yx[y-2][x+2] = ' ';peca_n[1]++;} else {tentativa=tentativa+1;  e=1;} break;
                        case 4: if (yx[y][x-1]== ' ' && yx[y-1][x-1]== ' ' && yx[y-2][x-1]== ' '){yx[y][x] = ' ';yx[y][x+1] = ' ';yx[y][x+2] = ' ';yx[y-1][x] = '1';yx[y-1][x+1] = ' ';yx[y-1][x+2] = ' ';yx[y-2][x] = ' ';yx[y-2][x+1] = ' ';yx[y-2][x+2] = ' ';peca_n[1]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 5: yx[y][x] = ' ';yx[y][x+1] = ' ';yx[y][x+2] = ' ';yx[y-1][x] = ' ';yx[y-1][x+1] = '1';yx[y-1][x+2] = ' ';yx[y-2][x] = ' ';yx[y-2][x+1] = ' ';yx[y-2][x+2] = ' ';peca_n[1]++;break;
                        case 6: if (yx[y][x+3]== ' ' && yx[y-1][x+3]== ' ' && yx[y-2][x+3]== ' '){yx[y][x] = ' ';yx[y][x+1] = ' ';yx[y][x+2] = ' ';yx[y-1][x] = ' ';yx[y-1][x+1] = ' ';yx[y-1][x+2] = '1';yx[y-2][x] = ' ';yx[y-2][x+1] = ' ';yx[y-2][x+2] = ' ';peca_n[1]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 7: if (yx[y-1][x-1]== ' ' && yx[y-2][x-1]== ' ' && yx[y-3][x-1]== ' ' && yx[y-3][x]== ' ' && yx[y-3][x+1]== ' '){yx[y][x] = ' ';yx[y][x+1] = ' ';yx[y][x+2] = ' ';yx[y-1][x] = ' ';yx[y-1][x+1] = ' ';yx[y-1][x+2] = ' ';yx[y-2][x] = '1';yx[y-2][x+1] = ' ';yx[y-2][x+2] = ' ';peca_n[1]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 8: if (yx[y-3][x]== ' ' && yx[y-3][x+1]== ' ' && yx[y-3][x+2]== ' '){yx[y][x] = ' ';yx[y][x+1] = ' ';yx[y][x+2] = ' ';yx[y-1][x] = ' ';yx[y-1][x+1] = ' ';yx[y-1][x+2] = ' ';yx[y-2][x] = ' ';yx[y-2][x+1] = '1';yx[y-2][x+2] = ' ';peca_n[1]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 9: if (yx[y-3][x+1]== ' ' && yx[y-3][x+2]== ' ' && yx[y-3][x+3]== ' ' && yx[y-2][x+3]== ' ' && yx[y-1][x+3]== ' '){yx[y][x] = ' ';yx[y][x+1] = ' ';yx[y][x+2] = ' ';yx[y-1][x] = ' ';yx[y-1][x+1] = ' ';yx[y-1][x+2] = ' ';yx[y-2][x] = ' ';yx[y-2][x+1] = ' ';yx[y-2][x+2] = '1';peca_n[1]++;}else {tentativa=tentativa+1;  e=1;} break;
                        
                        case 10:if (yx[y-1][x-1]== ' ' && yx[y][x-1]== ' ' && yx[y+1][x-1]== ' ' &&  yx[y+1][x]== ' ' && yx[y+1][x+1]== ' ' && yx[y+1][x+2]== ' ' ){yx[y][x] = '2';yx[y][x+1] = '2';yx[y][x+2] = ' ';yx[y-1][x] = ' ';yx[y-1][x+1] = ' ';yx[y-1][x+2] = ' ';yx[y-2][x] = ' ';yx[y-2][x+1] = ' ';yx[y-2][x+2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 11:if (yx[y+1][x]== ' ' && yx[y+1][x+1]== ' ' && yx[y+1][x+2]== ' ' &&  yx[y+1][x+3]== ' ' && yx[y][x+3]== ' ' && yx[y-1][x+3]== ' ' ){yx[y][x] = ' ';yx[y][x+1] = '2';yx[y][x+2] = '2';yx[y-1][x] = ' ';yx[y-1][x+1] = ' ';yx[y-1][x+2] = ' ';yx[y-2][x] = ' ';yx[y-2][x+1] = ' ';yx[y-2][x+2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 12:if (yx[y-2][x-1]== ' ' && yx[y-1][x-1]== ' ' && yx[y][x-1]== ' ' ){yx[y][x] = ' ';yx[y][x+1] = ' ';yx[y][x+2] = ' ';yx[y-1][x] = '2';yx[y-1][x+1] = '2';yx[y-1][x+2] = ' ';yx[y-2][x] = ' ';yx[y-2][x+1] = ' ';yx[y-2][x+2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 13:if (yx[y-2][x+3]== ' ' && yx[y-1][x+3]== ' ' && yx[y][x+3]== ' ' ){yx[y][x] = ' ';yx[y][x+1] = ' ';yx[y][x+2] = ' ';yx[y-1][x] = ' ';yx[y-1][x+1] = '2';yx[y-1][x+2] = '2';yx[y-2][x] = ' ';yx[y-2][x+1] = ' ';yx[y-2][x+2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 14:if (yx[y-1][x-1]== ' ' && yx[y-2][x-1]== ' ' && yx[y-3][x-1]== ' ' && yx[y-3][x]== ' ' &&  yx[y-3][x+1]== ' ' && yx[y-3][x+2]== ' ' ){yx[y][x] = ' ';yx[y][x+1] = ' ';yx[y][x+2] = ' ';yx[y-1][x] = ' ';yx[y-1][x+1] = ' ';yx[y-1][x+2] = ' ';yx[y-2][x] = '2';yx[y-2][x+1] = '2';yx[y-2][x+2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 15:if (yx[y-3][x]== ' ' && yx[y-3][x+1]== ' ' && yx[y-3][x+2]== ' ' &&  yx[y-3][x+3]== ' ' && yx[y-2][x+3]== ' ' && yx[y-1][x+3]== ' ' ){yx[y][x] = ' ';yx[y][x+1] = ' ';yx[y][x+2] = ' ';yx[y-1][x] = ' ';yx[y-1][x+1] = ' ';yx[y-1][x+2] = ' ';yx[y-2][x] = ' ';yx[y-2][x+1] = '2';yx[y-2][x+2] = '2';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 16:if (yx[y-2][x-1]== ' ' && yx[y-1][x-1]== ' ' && yx[y][x-1]== ' ' &&  yx[y+1][x-1]== ' ' && yx[y+1][x]== ' ' && yx[y+1][x+1]== ' ' ){yx[y][x] = '2';yx[y][x+1] = ' ';yx[y][x+2] = ' ';yx[y-1][x] = '2';yx[y-1][x+1] = ' ';yx[y-1][x+2] = ' ';yx[y-2][x] = ' ';yx[y-2][x+1] = ' ';yx[y-2][x+2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 17:if (yx[y][x-1]== ' ' && yx[y-1][x-1]== ' ' && yx[y-2][x-1]== ' ' &&  yx[y-3][x-1]== ' ' && yx[y-3][x]== ' ' && yx[y-3][x+1]== ' ' ){yx[y][x] = ' ';yx[y][x+1] = ' ';yx[y][x+2] = ' ';yx[y-1][x] = '2';yx[y-1][x+1] = ' ';yx[y-1][x+2] = ' ';yx[y-2][x] = '2';yx[y-2][x+1] = ' ';yx[y-2][x+2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 18:if (yx[y+1][x]== ' ' && yx[y+1][x+1]== ' ' && yx[y+1][x+2]== ' ' ){yx[y][x] = ' ';yx[y][x+1] = '2';yx[y][x+2] = ' ';yx[y-1][x] = ' ';yx[y-1][x+1] = '2';yx[y-1][x+2] = ' ';yx[y-2][x] = ' ';yx[y-2][x+1] = ' ';yx[y-2][x+2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 19:if (yx[y-3][x]== ' ' && yx[y-3][x+1]== ' ' && yx[y-3][x+2]== ' ' ){yx[y][x] = ' ';yx[y][x+1] = ' ';yx[y][x+2] = ' ';yx[y-1][x] = ' ';yx[y-1][x+1] = '2';yx[y-1][x+2] = ' ';yx[y-2][x] = ' ';yx[y-2][x+1] = '2';yx[y-2][x+2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 20:if (yx[y+1][x+1]== ' ' && yx[y+1][x+2]== ' ' && yx[y+1][x+3]== ' ' &&  yx[y][x+3]== ' ' && yx[y-1][x+3]== ' ' && yx[y-2][x+3]== ' ' ){yx[y][x] = ' ';yx[y][x+1] = ' ';yx[y][x+2] = '2';yx[y-1][x] = ' ';yx[y-1][x+1] = ' ';yx[y-1][x+2] = '2';yx[y-2][x] = ' ';yx[y-2][x+1] = ' ';yx[y-2][x+2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 21:if (yx[y-3][x+1]== ' ' && yx[y-3][x+2]== ' ' && yx[y-3][x+3]== ' ' &&  yx[y-2][x+3]== ' ' && yx[y-1][x+3]== ' ' && yx[y][x+3]== ' ' ){yx[y][x] = ' ';yx[y][x+1] = ' ';yx[y][x+2] = ' ';yx[y-1][x] = ' ';yx[y-1][x+1] = ' ';yx[y-1][x+2] = '2';yx[y-2][x] = ' ';yx[y-2][x+1] = ' ';yx[y-2][x+2] = '2';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;

                        case 22: if (yx[y-1][x-1]== ' ' && yx[y][x-1]== ' ' && yx[y+1][x-1]== ' ' && yx[y+1][x]== ' ' && yx[y+1][x+1]== ' ' && yx[y+1][x+2]== ' ' && yx[y+1][x+3]== ' ' && yx[y][x+3]== ' ' && yx[y-1][x+3]== ' '){yx[y][x] = '3';yx[y][x+1] = '3';yx[y][x+2] = '3';yx[y-1][x] = ' ';yx[y-1][x+1] = ' ';yx[y-1][x+2] = ' ';yx[y-2][x] = ' ';yx[y-2][x+1] = ' ';yx[y-2][x+2] = ' ';peca_n[3]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 23: if (yx[y-2][x-1]== ' ' && yx[y-1][x-1]== ' ' && yx[y][x-1]== ' ' && yx[y][x+3]== ' ' && yx[y-1][x+3]== ' ' && yx[y-2][x+3]== ' ' ){yx[y][x] = ' ';yx[y][x+1] = ' ';yx[y][x+2] = ' ';yx[y-1][x] = '3';yx[y-1][x+1] = '3';yx[y-1][x+2] = '3';yx[y-2][x] = ' ';yx[y-2][x+1] = ' ';yx[y-2][x+2] = ' ';peca_n[3]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 24: if (yx[y-1][x-1]== ' ' && yx[y-2][x-1]== ' ' && yx[y-3][x-1]== ' ' && yx[y-3][x]== ' ' && yx[y-3][x+1]== ' ' && yx[y-3][x+2]== ' ' && yx[y-3][x+3]== ' ' && yx[y-2][x+3]== ' ' && yx[y-1][x+3]== ' '){yx[y][x] = ' ';yx[y][x+1] = ' ';yx[y][x+2] = ' ';yx[y-1][x] = ' ';yx[y-1][x+1] = ' ';yx[y-1][x+2] = ' ';yx[y-2][x] = '3';yx[y-2][x+1] = '3';yx[y-2][x+2] = '3';peca_n[3]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 25: if (yx[y+1][x+1]== ' ' && yx[y+1][x]== ' ' && yx[y+1][x-1]== ' ' && yx[y][x-1]== ' ' && yx[y-1][x-1]== ' ' && yx[y-2][x-1]== ' ' && yx[y-3][x-1]== ' ' && yx[y-3][x]== ' ' && yx[y-3][x+1]== ' '){yx[y][x] = '3';yx[y][x+1] = ' ';yx[y][x+2] = ' ';yx[y-1][x] = '3';yx[y-1][x+1] = ' ';yx[y-1][x+2] = ' ';yx[y-2][x] = '3';yx[y-2][x+1] = ' ';yx[y-2][x+2] = ' ';peca_n[3]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 26: if (yx[y+1][x]== ' ' && yx[y+1][x+1]== ' ' && yx[y+1][x+2]== ' ' && yx[y-3][x]== ' ' && yx[y-3][x+1]== ' ' && yx[y-3][x+2]== ' '){yx[y][x] = ' ';yx[y][x+1] = '3';yx[y][x+2] = ' ';yx[y-1][x] = ' ';yx[y-1][x+1] = '3';yx[y-1][x+2] = ' ';yx[y-2][x] = ' ';yx[y-2][x+1] = '3';yx[y-2][x+2] = ' ';peca_n[3]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 27: if (yx[y+1][x+1]== ' ' && yx[y+1][x+2]== ' ' && yx[y+1][x+3]== ' ' && yx[y][x+3]== ' ' && yx[y-1][x+3]== ' ' && yx[y-2][x+3]== ' ' && yx[y-3][x+3]== ' ' && yx[y-3][x+2]== ' ' && yx[y-3][x+1]== ' '){yx[y][x] = ' ';yx[y][x+1] = ' ';yx[y][x+2] = '3';yx[y-1][x] = ' ';yx[y-1][x+1] = ' ';yx[y-1][x+2] = '3';yx[y-2][x] = ' ';yx[y-2][x+1] = ' ';yx[y-2][x+2] = '3';peca_n[3]++;}else {tentativa=tentativa+1;  e=1;} break;
                        
                        case 28: if (yx[y-2][x-1]== ' ' && yx[y-1][x-1]== ' ' && yx[y][x-1]== ' ' && yx[y+1][x-1]== ' ' && yx[y+1][x]== ' ' && yx[y+1][x+1]== ' ' && yx[y+1][x+2]== ' '){yx[y][x] = '4';yx[y][x+1] = '4';yx[y][x+2] = ' ';yx[y-1][x] = '4';yx[y-1][x+1] = '4';yx[y-1][x+2] = ' ';yx[y-2][x] = ' ';yx[y-2][x+1] = ' ';yx[y-2][x+2] = ' ';peca_n[4]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 29: if (yx[y+1][x]== ' ' && yx[y+1][x+1]== ' ' && yx[y+1][x+2]== ' ' && yx[y+1][x+3]== ' ' && yx[y][x+3]== ' ' && yx[y-1][x+3]== ' ' && yx[y-2][x+3]== ' '){yx[y][x] = ' ';yx[y][x+1] = '4';yx[y][x+2] = '4';yx[y-1][x] = ' ';yx[y-1][x+1] = '4';yx[y-1][x+2] = '4';yx[y-2][x] = ' ';yx[y-2][x+1] = ' ';yx[y-2][x+2] = ' ';peca_n[4]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 30: if (yx[y][x-1]== ' ' && yx[y-1][x-1]== ' ' && yx[y-2][x-1]== ' ' && yx[y-3][x-1]== ' ' && yx[y-3][x]== ' ' && yx[y-3][x+1]== ' ' && yx[y-3][x+2]== ' '){yx[y][x] = ' ';yx[y][x+1] = ' ';yx[y][x+2] = ' ';yx[y-1][x] = '4';yx[y-1][x+1] = '4';yx[y-1][x+2] = ' ';yx[y-2][x] = '4';yx[y-2][x+1] = '4';yx[y-2][x+2] = ' ';peca_n[4]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 31: if (yx[y-3][x]== ' ' && yx[y-3][x+1]== ' ' && yx[y-3][x+2]== ' ' && yx[y-3][x+3]== ' ' && yx[y-2][x+3]== ' ' && yx[y-1][x+3]== ' ' && yx[y][x+3]== ' '){yx[y][x] = ' ';yx[y][x+1] = ' ';yx[y][x+2] = ' ';yx[y-1][x] = ' ';yx[y-1][x+1] = '4';yx[y-1][x+2] = '4';yx[y-2][x] = ' ';yx[y-2][x+1] = '4';yx[y-2][x+2] = '4';peca_n[4]++;}else {tentativa=tentativa+1;  e=1;} break;

                        case 32: if (yx[y-1][x-1]== ' ' && yx[y][x-1]== ' ' && yx[y+1][x-1]== ' ' && yx[y+1][x]== ' ' && yx[y+1][x+1]== ' ' && yx[y+1][x+2]== ' ' && yx[y+1][x+3]== ' ' && yx[y][x+3]== ' ' && yx[y-1][x+3]== ' ' && yx[y-3][x]== ' ' && yx[y-3][x+1]== ' ' && yx[y-3][x+2]== ' '){yx[y][x] = '5';yx[y][x+1] = '5';yx[y][x+2] = '5';yx[y-1][x] = ' ';yx[y-1][x+1] = '5';yx[y-1][x+2] = ' ';yx[y-2][x] = ' ';yx[y-2][x+1] = '5';yx[y-2][x+2] = ' ';peca_n[5]++;}else {tentativa=tentativa+1; e=1;} break;
                        case 33: if (yx[y+1][x+1]== ' ' && yx[y+1][x]== ' ' && yx[y+1][x-1]== ' ' && yx[y][x-1]== ' ' && yx[y-1][x-1]== ' ' && yx[y-2][x-1]== ' ' && yx[y-3][x-1]== ' ' && yx[y-3][x]== ' ' && yx[y-3][x+1]== ' '  && yx[y][x+3]== ' ' && yx[y-1][x+3]== ' ' && yx[y-2][x+3]== ' '){yx[y][x] = '5';yx[y][x+1] = ' ';yx[y][x+2] = ' ';yx[y-1][x] = '5';yx[y-1][x+1] = '5';yx[y-1][x+2] = '5';yx[y-2][x] = '5';yx[y-2][x+1] = ' ';yx[y-2][x+2] = ' ';peca_n[5]++;}else {tentativa=tentativa+1; e=1;} break;
                        case 34: if (yx[y-1][x-1]== ' ' && yx[y-2][x-1]== ' ' && yx[y-3][x-1]== ' ' && yx[y-3][x]== ' ' && yx[y-3][x+1]== ' ' && yx[y-3][x+2]== ' ' && yx[y-3][x+3]== ' ' && yx[y-2][x+3]== ' ' && yx[y-1][x+3]== ' ' && yx[y+1][x]== ' ' && yx[y+1][x+1]== ' ' && yx[y+1][x+2]== ' '){yx[y][x] = ' ';yx[y][x+1] = '5';yx[y][x+2] = ' ';yx[y-1][x] = ' ';yx[y-1][x+1] = '5';yx[y-1][x+2] = ' ';yx[y-2][x] = '5';yx[y-2][x+1] = '5';yx[y-2][x+2] = '5';peca_n[5]++;}else {tentativa=tentativa+1; e=1;} break;
                        case 35: if (yx[y+1][x+1]== ' ' && yx[y+1][x+2]== ' ' && yx[y+1][x+3]== ' ' && yx[y][x+3]== ' ' && yx[y-1][x+3]== ' ' && yx[y-2][x+3]== ' ' && yx[y-3][x+3]== ' ' && yx[y-3][x+2]== ' ' && yx[y-3][x+1]== ' ' && yx[y][x-1]== ' ' && yx[y-1][x-1]== ' ' && yx[y-2][x-1]== ' '){yx[y][x] = ' ';yx[y][x+1] = ' ';yx[y][x+2] = '5';yx[y-1][x] = '5';yx[y-1][x+1] = '5';yx[y-1][x+2] = '5';yx[y-2][x] = ' ';yx[y-2][x+1] = ' ';yx[y-2][x+2] = '5';peca_n[5]++;}else {tentativa=tentativa+1; e=1;} break;

                        case 36: if (yx[y][x-1]== ' ' && yx[y-1][x-1]== ' ' && yx[y-2][x-1]== ' ' &&  yx[y-3][x-1]== ' ' && yx[y-3][x]== ' ' && yx[y-3][x+1]== ' ' && yx[y-3][x+2]== ' ' && yx[y-3][x+3]== ' ' &&  yx[y-2][x+3]== ' ' && yx[y-1][x+3]== ' ' && yx[y][x+3]== ' ' && yx[y+1][x]== ' ' && yx[y+1][x+1]== ' ' && yx[y+1][x+2]== ' '){yx[y][x] = ' ';yx[y][x+1] = '6';yx[y][x+2] = ' ';yx[y-1][x] = '6';yx[y-1][x+1] = ' ';yx[y-1][x+2] = '6';yx[y-2][x] = '6';yx[y-2][x+1] = '6';yx[y-2][x+2] = '6';peca_n[6]++;} else {tentativa=tentativa+1; e=1;} break;
                        case 37: if (yx[y+1][x]== ' ' && yx[y+1][x+1]== ' ' && yx[y+1][x+2]== ' ' &&  yx[y+1][x+3]== ' ' && yx[y][x+3]== ' ' && yx[y-1][x+3]== ' ' && yx[y-3][x]== ' ' && yx[y-3][x+1]== ' ' && yx[y-3][x+2]== ' ' &&  yx[y-3][x+3]== ' ' && yx[y-2][x+3]== ' ' && yx[y][x-1]== ' ' && yx[y-1][x-1]== ' ' && yx[y-2][x-1]== ' '){yx[y][x] = ' ';yx[y][x+1] = '6';yx[y][x+2] = '6';yx[y-1][x] = '6';yx[y-1][x+1] = ' ';yx[y-1][x+2] = '6';yx[y-2][x] = ' ';yx[y-2][x+1] = '6';yx[y-2][x+2] = '6';peca_n[6]++;} else { tentativa=tentativa+1; e=1;} break;
                        case 38: if (yx[y-2][x-1]== ' ' && yx[y-1][x-1]== ' ' && yx[y][x-1]== ' ' &&  yx[y+1][x-1]== ' ' && yx[y+1][x]== ' ' && yx[y+1][x+1]== ' ' && yx[y+1][x+2]== ' ' && yx[y+1][x+3]== ' ' &&  yx[y][x+3]== ' ' && yx[y-1][x+3]== ' ' && yx[y-2][x+3]== ' ' && yx[y-3][x]== ' ' && yx[y-3][x+1]== ' ' && yx[y-3][x+2]== ' '){yx[y][x] = '6';yx[y][x+1] = '6';yx[y][x+2] = '6';yx[y-1][x] = '6';yx[y-1][x+1] = ' ';yx[y-1][x+2] = '6';yx[y-2][x] = ' ';yx[y-2][x+1] = '6';yx[y-2][x+2] = ' ';peca_n[6]++;} else { tentativa=tentativa+1; e=1;} break;
                        case 39: if (yx[y-1][x-1]== ' ' && yx[y][x-1]== ' ' && yx[y+1][x-1]== ' ' &&  yx[y+1][x]== ' ' && yx[y+1][x+1]== ' ' && yx[y+1][x+2]== ' ' && yx[y-2][x-1]== ' ' && yx[y-3][x-1]== ' ' && yx[y-3][x]== ' ' &&  yx[y-3][x+1]== ' ' && yx[y-3][x+2]== ' ' && yx[y][x+3]== ' ' && yx[y-1][x+3]== ' ' && yx[y-2][x+3]== ' '){yx[y][x] = '6';yx[y][x+1] = '6';yx[y][x+2] = ' ';yx[y-1][x] = '6';yx[y-1][x+1] = ' ';yx[y-1][x+2] = '6';yx[y-2][x] = '6';yx[y-2][x+1] = '6';yx[y-2][x+2] = ' ';peca_n[6]++;} else { tentativa=tentativa+1; e=1;} break;

                        case 40: if (yx[y+1][x+1]== ' ' && yx[y+1][x]== ' ' && yx[y+1][x-1]== ' ' && yx[y][x-1]== ' ' && yx[y-1][x-1]== ' ' && yx[y-2][x-1]== ' ' && yx[y-3][x-1]== ' ' && yx[y-3][x]== ' ' && yx[y-3][x+1]== ' ' && yx[y+1][x+2]== ' ' && yx[y+1][x+3]== ' ' && yx[y][x+3]== ' ' && yx[y-1][x+3]== ' ' && yx[y-2][x+3]== ' ' && yx[y-3][x+3]== ' ' && yx[y-3][x+2]== ' '){yx[y][x] = '7';yx[y][x+1] = ' ';yx[y][x+2] = '7';yx[y-1][x] = '7';yx[y-1][x+1] = '7';yx[y-1][x+2] = '7';yx[y-2][x] = '7';yx[y-2][x+1] = ' ';yx[y-2][x+2] = '7';peca_n[7]++;}else {tentativa=tentativa+1; e=1;} break;
                        case 41: if (yx[y+1][x+1]== ' ' && yx[y+1][x]== ' ' && yx[y+1][x-1]== ' ' && yx[y][x-1]== ' ' && yx[y-1][x-1]== ' ' && yx[y-2][x-1]== ' ' && yx[y-3][x-1]== ' ' && yx[y-3][x]== ' ' && yx[y-3][x+1]== ' ' && yx[y+1][x+2]== ' ' && yx[y+1][x+3]== ' ' && yx[y][x+3]== ' ' && yx[y-1][x+3]== ' ' && yx[y-2][x+3]== ' ' && yx[y-3][x+3]== ' ' && yx[y-3][x+2]== ' '){yx[y][x] = '7';yx[y][x+1] = '7';yx[y][x+2] = '7';yx[y-1][x] = ' ';yx[y-1][x+1] = '7';yx[y-1][x+2] = ' ';yx[y-2][x] = '7';yx[y-2][x+1] = '7';yx[y-2][x+2] = '7';peca_n[7]++;}else {tentativa=tentativa+1; e=1;} break;

                        case 42: if (yx[y+1][x+1]== ' ' && yx[y+1][x]== ' ' && yx[y+1][x-1]== ' ' && yx[y][x-1]== ' ' && yx[y-1][x-1]== ' ' && yx[y-2][x-1]== ' ' && yx[y-3][x-1]== ' ' && yx[y-3][x]== ' ' && yx[y-3][x+1]== ' ' && yx[y+1][x+2]== ' ' && yx[y+1][x+3]== ' ' && yx[y][x+3]== ' ' && yx[y-1][x+3]== ' ' && yx[y-2][x+3]== ' ' && yx[y-3][x+3]== ' ' && yx[y-3][x+2]== ' '){yx[y][x] = '8';yx[y][x+1] = '8';yx[y][x+2] = '8';yx[y-1][x] = '8';yx[y-1][x+1] = ' ';yx[y-1][x+2] = '8';yx[y-2][x] = '8';yx[y-2][x+1] = '8';yx[y-2][x+2] = '8';peca_n[8]++;}else {tentativa=tentativa+1; e=1;} break;
                        default: e=1;break;
                        }
                    }
                    else {yx[y][x] = ' ';yx[y][x+1] = ' ';yx[y][x+2] = ' ';yx[y-1][x] = ' ';yx[y-1][x+1] = '1';yx[y-1][x+2] = ' ';yx[y-2][x] = ' ';yx[y-2][x+1] = ' ';yx[y-2][x+2] = ' ';peca_n[1]++;
                    }
                }while (e !=0);
            }while(x< dim_tabu_x - 2);
        }while(y>3);

        //posicionar peças da forma p1
    }

    void modo_p2(){
        //posicionar peças da forma p2
    }

    
	void print_tabu(){
        int n_colunas,n_linhas,k, l, min, max_1, max_2;
            n_colunas=dim_tabu_x;
            n_linhas=dim_tabu_y;
            
       switch (n_colunas){
            case 9: 

                 printf("\n ═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
                 min = (n_linhas - 2);
                 max_1 = (n_linhas/3);
                 max_2 = n_linhas;
                 for (l=1; l<=max_1; l++){   
                   for (k=max_2;k>min;k--){
                     if (k>=10){
                     printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, yx[k][1],yx[k][2],yx[k][3],yx[k][4],yx[k][5],yx[k][6],yx[k][7],yx[k][8],yx[k][9]);
                     }
                     else {
                     printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, yx[k][1],yx[k][2],yx[k][3],yx[k][4],yx[k][5],yx[k][6],yx[k][7],yx[k][8],yx[k][9]);
                     }
                     printf(" ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
                   } 
                     if (k>=10){
                     printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, yx[k][1],yx[k][2],yx[k][3],yx[k][4],yx[k][5],yx[k][6],yx[k][7],yx[k][8],yx[k][9]);
                     }
                     else {
                     printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, yx[k][1],yx[k][2],yx[k][3],yx[k][4],yx[k][5],yx[k][6],yx[k][7],yx[k][8],yx[k][9]);
                     }
                     printf(" ═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
                     max_2=(max_2-3);
                     min=(min-3);
                 } 
                     printf("    ║ A │ B │ C ║ D │ E │ F ║ G │ H │ I ║\n"); 
            break;
            case 12: 

                 printf("\n ═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
                 min = (n_linhas - 2);
                 max_1 = (n_linhas/3);
                 max_2 = n_linhas;
                 for (l=1; l<=max_1; l++){   
                   for (k=max_2;k>min;k--){
                     if (k>=10){
                     printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, yx[k][1],yx[k][2],yx[k][3],yx[k][4],yx[k][5],yx[k][6],yx[k][7],yx[k][8],yx[k][9],yx[k][10],yx[k][11],yx[k][12]);
                     }
                     else {
                     printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, yx[k][1],yx[k][2],yx[k][3],yx[k][4],yx[k][5],yx[k][6],yx[k][7],yx[k][8],yx[k][9],yx[k][10],yx[k][11],yx[k][12]);
                     }
                     printf(" ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
                   } 
                     if (k>=10){
                     printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, yx[k][1],yx[k][2],yx[k][3],yx[k][4],yx[k][5],yx[k][6],yx[k][7],yx[k][8],yx[k][9],yx[k][10],yx[k][11],yx[k][12]);
                     }
                     else {
                     printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, yx[k][1],yx[k][2],yx[k][3],yx[k][4],yx[k][5],yx[k][6],yx[k][7],yx[k][8],yx[k][9],yx[k][10],yx[k][11],yx[k][12]);
                     }
                     printf(" ═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
                     max_2=(max_2-3);
                     min=(min-3);
                 }
                     printf("    ║ A │ B │ C ║ D │ E │ F ║ G │ H │ I ║ J │ K │ L ║\n");  
            break;
            case 15: 

                 printf("\n ═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
                 min = (n_linhas - 2);
                 max_1 = (n_linhas/3);
                 max_2 = n_linhas;
                 for (l=1; l<=max_1; l++){   
                   for (k=max_2;k>min;k--){
                     if (k>=10){
                     printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, yx[k][1],yx[k][2],yx[k][3],yx[k][4],yx[k][5],yx[k][6],yx[k][7],yx[k][8],yx[k][9],yx[k][10],yx[k][11],yx[k][12],yx[k][13],yx[k][14],yx[k][15]);
                     }
                     else {
                     printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, yx[k][1],yx[k][2],yx[k][3],yx[k][4],yx[k][5],yx[k][6],yx[k][7],yx[k][8],yx[k][9],yx[k][10],yx[k][11],yx[k][12],yx[k][13],yx[k][14],yx[k][15]);
                     }
                     printf(" ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
                   } 
                     if (k>=10){
                     printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, yx[k][1],yx[k][2],yx[k][3],yx[k][4],yx[k][5],yx[k][6],yx[k][7],yx[k][8],yx[k][9],yx[k][10],yx[k][11],yx[k][12],yx[k][13],yx[k][14],yx[k][15]);
                     }
                     else {
                     printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, yx[k][1],yx[k][2],yx[k][3],yx[k][4],yx[k][5],yx[k][6],yx[k][7],yx[k][8],yx[k][9],yx[k][10],yx[k][11],yx[k][12],yx[k][13],yx[k][14],yx[k][15]);
                     }
                     printf(" ═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
                     max_2=(max_2-3);
                     min=(min-3);
                 } 
                     printf("    ║ A │ B │ C ║ D │ E │ F ║ G │ H │ I ║ J │ K │ L ║ M │ N │ O ║\n"); 
            break;
            case 18: 

                 printf("\n ═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
                 min = (n_linhas - 2);
                 max_1 = (n_linhas/3);
                 max_2 = n_linhas;
                 for (l=1; l<=max_1; l++){   
                   for (k=max_2;k>min;k--){
                     if (k>=10){
                     printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, yx[k][1],yx[k][2],yx[k][3],yx[k][4],yx[k][5],yx[k][6],yx[k][7],yx[k][8],yx[k][9],yx[k][10],yx[k][11],yx[k][12],yx[k][13],yx[k][14],yx[k][15],yx[k][16],yx[k][17],yx[k][18]);
                     }
                     else {
                     printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, yx[k][1],yx[k][2],yx[k][3],yx[k][4],yx[k][5],yx[k][6],yx[k][7],yx[k][8],yx[k][9],yx[k][10],yx[k][11],yx[k][12],yx[k][13],yx[k][14],yx[k][15],yx[k][16],yx[k][17],yx[k][18]);
                     }
                     printf(" ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
                   } 
                     if (k>=10){
                     printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, yx[k][1],yx[k][2],yx[k][3],yx[k][4],yx[k][5],yx[k][6],yx[k][7],yx[k][8],yx[k][9],yx[k][10],yx[k][11],yx[k][12],yx[k][13],yx[k][14],yx[k][15],yx[k][16],yx[k][17],yx[k][18]);
                     }
                     else {
                     printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, yx[k][1],yx[k][2],yx[k][3],yx[k][4],yx[k][5],yx[k][6],yx[k][7],yx[k][8],yx[k][9],yx[k][10],yx[k][11],yx[k][12],yx[k][13],yx[k][14],yx[k][15],yx[k][16],yx[k][17],yx[k][18]);
                     }
                     printf(" ═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
                     max_2=(max_2-3);
                     min=(min-3);
                 }  
                     printf("    ║ A │ B │ C ║ D │ E │ F ║ G │ H │ I ║ J │ K │ L ║ M │ N │ O ║ P │ Q │ R ║\n"); 
            break;
            case 21: 

                 printf("\n ═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
                 min = (n_linhas - 2);
                 max_1 = (n_linhas/3);
                 max_2 = n_linhas;
                 for (l=1; l<=max_1; l++){   
                   for (k=max_2;k>min;k--){
                     if (k>=10){
                     printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, yx[k][1],yx[k][2],yx[k][3],yx[k][4],yx[k][5],yx[k][6],yx[k][7],yx[k][8],yx[k][9],yx[k][10],yx[k][11],yx[k][12],yx[k][13],yx[k][14],yx[k][15],yx[k][16],yx[k][17],yx[k][18],yx[k][19],yx[k][20],yx[k][21]);
                     }
                     else {
                     printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, yx[k][1],yx[k][2],yx[k][3],yx[k][4],yx[k][5],yx[k][6],yx[k][7],yx[k][8],yx[k][9],yx[k][10],yx[k][11],yx[k][12],yx[k][13],yx[k][14],yx[k][15],yx[k][16],yx[k][17],yx[k][18],yx[k][19],yx[k][20],yx[k][21]);
                     }
                     printf(" ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
                   } 
                     if (k>=10){
                     printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, yx[k][1],yx[k][2],yx[k][3],yx[k][4],yx[k][5],yx[k][6],yx[k][7],yx[k][8],yx[k][9],yx[k][10],yx[k][11],yx[k][12],yx[k][13],yx[k][14],yx[k][15],yx[k][16],yx[k][17],yx[k][18],yx[k][19],yx[k][20],yx[k][21]);
                     }
                     else {
                     printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, yx[k][1],yx[k][2],yx[k][3],yx[k][4],yx[k][5],yx[k][6],yx[k][7],yx[k][8],yx[k][9],yx[k][10],yx[k][11],yx[k][12],yx[k][13],yx[k][14],yx[k][15],yx[k][16],yx[k][17],yx[k][18],yx[k][19],yx[k][20],yx[k][21]);
                     }
                     printf(" ═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
                     max_2=(max_2-3);
                     min=(min-3);
                 } 
                     printf("    ║ A │ B │ C ║ D │ E │ F ║ G │ H │ I ║ J │ K │ L ║ M │ N │ O ║ P │ Q │ R ║ S │ T │ U ║\n"); 
            break;
            case 24: 

                 printf("\n ═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
                 min = (n_linhas - 2);
                 max_1 = (n_linhas/3);
                 max_2 = n_linhas;
                 for (l=1; l<=max_1; l++){   
                   for (k=max_2;k>min;k--){
                     if (k>=10){
                     printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, yx[k][1],yx[k][2],yx[k][3],yx[k][4],yx[k][5],yx[k][6],yx[k][7],yx[k][8],yx[k][9],yx[k][10],yx[k][11],yx[k][12],yx[k][13],yx[k][14],yx[k][15],yx[k][16],yx[k][17],yx[k][18],yx[k][19],yx[k][20],yx[k][21],yx[k][22],yx[k][23],yx[k][24]);
                     }
                     else {
                     printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, yx[k][1],yx[k][2],yx[k][3],yx[k][4],yx[k][5],yx[k][6],yx[k][7],yx[k][8],yx[k][9],yx[k][10],yx[k][11],yx[k][12],yx[k][13],yx[k][14],yx[k][15],yx[k][16],yx[k][17],yx[k][18],yx[k][19],yx[k][20],yx[k][21],yx[k][22],yx[k][23],yx[k][24]);
                     }
                     printf(" ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
                   } 
                     if (k>=10){
                     printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, yx[k][1],yx[k][2],yx[k][3],yx[k][4],yx[k][5],yx[k][6],yx[k][7],yx[k][8],yx[k][9],yx[k][10],yx[k][11],yx[k][12],yx[k][13],yx[k][14],yx[k][15],yx[k][16],yx[k][17],yx[k][18],yx[k][19],yx[k][20],yx[k][21],yx[k][22],yx[k][23],yx[k][24]);
                     }
                     else {
                     printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, yx[k][1],yx[k][2],yx[k][3],yx[k][4],yx[k][5],yx[k][6],yx[k][7],yx[k][8],yx[k][9],yx[k][10],yx[k][11],yx[k][12],yx[k][13],yx[k][14],yx[k][15],yx[k][16],yx[k][17],yx[k][18],yx[k][19],yx[k][20],yx[k][21],yx[k][22],yx[k][23],yx[k][24]);
                     }
                     printf(" ═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
                     max_2=(max_2-3);
                     min=(min-3);
                 } 
                     printf("    ║ A │ B │ C ║ D │ E │ F ║ G │ H │ I ║ J │ K │ L ║ M │ N │ O ║ P │ Q │ R ║ S │ T │ U ║ V │ W │ X ║\n"); 
            break;               
        }

    }

    void print_pecas(){
        printf("\nPeças(0) = %d    Peças(1) = %d    Peças(2) = %d    Peças(3) = %d    Peças(4) = %d    Peças(5) = %d    Peças(6) = %d    Peças(7) = %d    Peças(8) = %d\n\n",peca_n[0],peca_n[1],peca_n[2],peca_n[3],peca_n[4],peca_n[5],peca_n[6],peca_n[7],peca_n[8]);
    }
    
    void print_logo(){
        printf("\n █▀▀▄ █▀▀█ ▀▀█▀▀ █▀▀█ █   █  █ █▀▀█    █▀▀▄ █▀▀█ ▀█ █▀ █▀▀█ █\n █▀▀▄ █▄▄█   █   █▄▄█ █   █▀▀█ █▄▄█    █  █ █▄▄█  █▄█  █▄▄█ █\n ▀▀▀  ▀  ▀   ▀   ▀  ▀ ▀▀▀ ▀  ▀ ▀  ▀    ▀  ▀ ▀  ▀   ▀   ▀  ▀ ▀▀▀\n\n");
        switch(modo_jogo){
            case 0 :
            printf("                    █▀▄▀█ █▀█ █▀▄ █▀█   █▀█\n                    █ ▀ █ █▄█ █▄▀ █▄█   █▄█\n\n\n"); 
            break;
            case 1 :
            printf("                    █▀▄▀█ █▀█ █▀▄ █▀█   ▄█\n                    █ ▀ █ █▄█ █▄▀ █▄█    █\n\n\n"); 
            break;
            case 2 :
            printf("                    █▀▄▀█ █▀█ █▀▄ █▀█   ▀█\n                    █ ▀ █ █▄█ █▄▀ █▄█   █▄\n\n\n"); 
            break;
            case 3 :
            printf("               █ █▄ █ █▀ ▀█▀ █▀█ █ █ █▀▀ █▀█ █▀▀ █▀\n               █ █ ▀█ ▄█  █  █▀▄ █▄█ █▄▄ █▄█ ██▄ ▄█\n\n\n");
            break;
        }
    }
    