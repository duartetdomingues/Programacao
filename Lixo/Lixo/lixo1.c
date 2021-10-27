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

int modo_jogo=-1, modo_pos,peca_n[9]={0,0,0,0,0,0,0,0,0},n_colunas,n_linhas,dim_tabu_x,dim_tabu_y;
int matriz_x=0, matriz_y=0, peca, x, y, tentativa,i=1,j=1,e,m_x,m_y;



char xy[26][17]=
{{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
time_t t;

int main()
{
main_menu();
}

void main_menu(){
    system("clear");
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
        printf("Escola a dimensão do Tabuleiro?( Ex.: 9*9 (colunas*linhas) )\n");
        if (scanf("%d x %d", &dim_tabu_x,&dim_tabu_y) != 2){
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
        switch(modo_pos){
        case 1:modo_p1();print_tabu();  break; 
        case 2:modo_p2();print_tabu(); break;
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

        //int matriz_x=0, matriz_y=0, peca, x, y, tentativa,i=1,j=1,e,m_x,m_y;
        
        m_x = dim_tabu_x/3-1;
        m_y = dim_tabu_y/3-1;
        printf("m_x=%d m_y=%d dim_tabu(x)=%d dim_tabu(y)=%d\n",m_x,m_y,dim_tabu_x,dim_tabu_y);
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
                //printf("x=%d m_x=%d matriz_x=%d\n", x, m_x, matriz_x);
                
                do{
                    e=0;
                    printf("  (x,y)=%d,%d",x,y);
                    //printf("  tentativa=%d",tentativa);

                    if (tentativa<=3){
                        peca= rand() % 43;
                        printf(" tipo=%d\n", peca);
                        switch(peca){
                        case 0:xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';peca_n[0]++; break;
                        
                        case 1: if (xy[x-1][y-1]== ' ' && xy[x-1][y]== ' ' && xy[x-1][y+1]== ' ' &&  xy[x][y+1]== ' ' && xy[x+1][y+1]== ' '){xy[x][y] = '1';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' '; peca_n[1]++;} else {tentativa=tentativa+1;  e=1;} break;
                        case 2: if (xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' '){xy[x][y] = ' ';xy[x+1][y] = '1';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';peca_n[1]++;} else {tentativa=tentativa+1;  e=1;} break;
                        case 3: if (xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' && xy[x+3][y+1]== ' ' && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' '){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = '1';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';peca_n[1]++;} else {tentativa=tentativa+1;  e=1;} break;
                        case 4: if (xy[x-1][y]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' '){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = '1';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';peca_n[1]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 5: xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = '1';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';peca_n[1]++;break;
                        case 6: if (xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y-2]== ' '){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = '1';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';peca_n[1]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 7: if (xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' ' && xy[x-1][y-3]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' '){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = '1';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';peca_n[1]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 8: if (xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' '){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = '1';xy[x+2][y-2] = ' ';peca_n[1]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 9: if (xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' ' && xy[x+3][y-3]== ' ' && xy[x+3][y-2]== ' ' && xy[x+3][y-1]== ' '){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = '1';peca_n[1]++;}else {tentativa=tentativa+1;  e=1;} break;
                        
                        case 10:if (xy[x-1][y-1]== ' ' && xy[x-1][y]== ' ' && xy[x-1][y+1]== ' ' &&  xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' ){xy[x][y] = '2';xy[x+1][y] = '2';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 11:if (xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' &&  xy[x+3][y+1]== ' ' && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' ){xy[x][y] = ' ';xy[x+1][y] = '2';xy[x+2][y] = '2';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 12:if (xy[x-1][y-2]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y]== ' ' ){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = '2';xy[x+1][y-1] = '2';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 13:if (xy[x+3][y-2]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y]== ' ' ){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = '2';xy[x+2][y-1] = '2';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 14:if (xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' ' && xy[x-1][y-3]== ' ' && xy[x][y-3]== ' ' &&  xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' ' ){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = '2';xy[x+1][y-2] = '2';xy[x+2][y-2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 15:if (xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' ' &&  xy[x+3][y-3]== ' ' && xy[x+3][y-2]== ' ' && xy[x+3][y-1]== ' ' ){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = '2';xy[x+2][y-2] = '2';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 16:if (xy[x-1][y-2]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y]== ' ' &&  xy[x-1][y+1]== ' ' && xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' ){xy[x][y] = '2';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = '2';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 17:if (xy[x-1][y]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' ' &&  xy[x-1][y-3]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' ){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = '2';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = '2';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 18:if (xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' ){xy[x][y] = ' ';xy[x+1][y] = '2';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = '2';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 19:if (xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' ' ){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = '2';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = '2';xy[x+2][y-2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 20:if (xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' && xy[x+3][y+1]== ' ' &&  xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y-2]== ' ' ){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = '2';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = '2';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 21:if (xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' ' && xy[x+3][y-3]== ' ' &&  xy[x+3][y-2]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y]== ' ' ){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = '2';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = '2';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;

                        case 22: if (xy[x-1][y-1]== ' ' && xy[x-1][y]== ' ' && xy[x-1][y+1]== ' ' && xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' && xy[x+3][y+1]== ' ' && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' '){xy[x][y] = '3';xy[x+1][y] = '3';xy[x+2][y] = '3';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';peca_n[3]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 23: if (xy[x-1][y-2]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y]== ' ' && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y-2]== ' ' ){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = '3';xy[x+1][y-1] = '3';xy[x+2][y-1] = '3';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';peca_n[3]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 24: if (xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' ' && xy[x-1][y-3]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' ' && xy[x+3][y-3]== ' ' && xy[x+3][y-2]== ' ' && xy[x+3][y-1]== ' '){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = '3';xy[x+1][y-2] = '3';xy[x+2][y-2] = '3';peca_n[3]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 25: if (xy[x+1][y+1]== ' ' && xy[x][y+1]== ' ' && xy[x-1][y+1]== ' ' && xy[x-1][y]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' ' && xy[x-1][y-3]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' '){xy[x][y] = '3';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = '3';xy[x+1][y-1] = ' ';xy[x+2][y-1] = ' ';xy[x][y-2] = '3';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';peca_n[3]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 26: if (xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' '){xy[x][y] = ' ';xy[x+1][y] = '3';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = '3';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = '3';xy[x+2][y-2] = ' ';peca_n[3]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 27: if (xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' && xy[x+3][y+1]== ' ' && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y-2]== ' ' && xy[x+3][y-3]== ' ' && xy[x+2][y-3]== ' ' && xy[x+1][y-3]== ' '){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = '3';xy[x][y-1] = ' ';xy[x+1][y-1] = ' ';xy[x+2][y-1] = '3';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = '3';peca_n[3]++;}else {tentativa=tentativa+1;  e=1;} break;
                        
                        case 28: if (xy[x-1][y-2]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y]== ' ' && xy[x-1][y+1]== ' ' && xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' '){xy[x][y] = '4';xy[x+1][y] = '4';xy[x+2][y] = ' ';xy[x][y-1] = '4';xy[x+1][y-1] = '4';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';peca_n[4]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 29: if (xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' && xy[x+3][y+1]== ' ' && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y-2]== ' '){xy[x][y] = ' ';xy[x+1][y] = '4';xy[x+2][y] = '4';xy[x][y-1] = ' ';xy[x+1][y-1] = '4';xy[x+2][y-1] = '4';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';peca_n[4]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 30: if (xy[x-1][y]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' ' && xy[x-1][y-3]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' '){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = '4';xy[x+1][y-1] = '4';xy[x+2][y-1] = ' ';xy[x][y-2] = '4';xy[x+1][y-2] = '4';xy[x+2][y-2] = ' ';peca_n[4]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 31: if (xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' ' && xy[x+3][y-3]== ' ' && xy[x+3][y-2]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y]== ' '){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = '4';xy[x+2][y-1] = '4';xy[x][y-2] = ' ';xy[x+1][y-2] = '4';xy[x+2][y-2] = '4';peca_n[4]++;}else {tentativa=tentativa+1;  e=1;} break;

                        case 32: if (xy[x-1][y-1]== ' ' && xy[x-1][y]== ' ' && xy[x-1][y+1]== ' ' && xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' && xy[x+3][y+1]== ' ' && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' '){xy[x][y] = '5';xy[x+1][y] = '5';xy[x+2][y] = '5';xy[x][y-1] = ' ';xy[x+1][y-1] = '5';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = '5';xy[x+2][y-2] = ' ';peca_n[5]++;}else {tentativa=tentativa+1; e=1;} break;
                        case 33: if (xy[x+1][y+1]== ' ' && xy[x][y+1]== ' ' && xy[x-1][y+1]== ' ' && xy[x-1][y]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' ' && xy[x-1][y-3]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' '  && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y-2]== ' '){xy[x][y] = '5';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = '5';xy[x+1][y-1] = '5';xy[x+2][y-1] = '5';xy[x][y-2] = '5';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';peca_n[5]++;}else {tentativa=tentativa+1; e=1;} break;
                        case 34: if (xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' ' && xy[x-1][y-3]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' ' && xy[x+3][y-3]== ' ' && xy[x+3][y-2]== ' ' && xy[x+3][y-1]== ' ' && xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' '){xy[x][y] = ' ';xy[x+1][y] = '5';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = '5';xy[x+2][y-1] = ' ';xy[x][y-2] = '5';xy[x+1][y-2] = '5';xy[x+2][y-2] = '5';peca_n[5]++;}else {tentativa=tentativa+1; e=1;} break;
                        case 35: if (xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' && xy[x+3][y+1]== ' ' && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y-2]== ' ' && xy[x+3][y-3]== ' ' && xy[x+2][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x-1][y]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' '){xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = '5';xy[x][y-1] = '5';xy[x+1][y-1] = '5';xy[x+2][y-1] = '5';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = '5';peca_n[5]++;}else {tentativa=tentativa+1; e=1;} break;

                        case 36: if (xy[x-1][y]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' ' &&  xy[x-1][y-3]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' ' && xy[x+3][y-3]== ' ' &&  xy[x+3][y-2]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y]== ' ' && xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' '){xy[x][y] = ' ';xy[x+1][y] = '6';xy[x+2][y] = ' ';xy[x][y-1] = '6';xy[x+1][y-1] = ' ';xy[x+2][y-1] = '6';xy[x][y-2] = '6';xy[x+1][y-2] = '6';xy[x+2][y-2] = '6';peca_n[6]++;} else {tentativa=tentativa+1; e=1;} break;
                        case 37: if (xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' &&  xy[x+3][y+1]== ' ' && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' ' &&  xy[x+3][y-3]== ' ' && xy[x+3][y-2]== ' ' && xy[x-1][y]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' '){xy[x][y] = ' ';xy[x+1][y] = '6';xy[x+2][y] = '6';xy[x][y-1] = '6';xy[x+1][y-1] = ' ';xy[x+2][y-1] = '6';xy[x][y-2] = ' ';xy[x+1][y-2] = '6';xy[x+2][y-2] = '6';peca_n[6]++;} else { tentativa=tentativa+1; e=1;} break;
                        case 38: if (xy[x-1][y-2]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y]== ' ' &&  xy[x-1][y+1]== ' ' && xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' && xy[x+3][y+1]== ' ' &&  xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y-2]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' '){xy[x][y] = '6';xy[x+1][y] = '6';xy[x+2][y] = '6';xy[x][y-1] = '6';xy[x+1][y-1] = ' ';xy[x+2][y-1] = '6';xy[x][y-2] = ' ';xy[x+1][y-2] = '6';xy[x+2][y-2] = ' ';peca_n[6]++;} else { tentativa=tentativa+1; e=1;} break;
                        case 39: if (xy[x-1][y-1]== ' ' && xy[x-1][y]== ' ' && xy[x-1][y+1]== ' ' &&  xy[x][y+1]== ' ' && xy[x+1][y+1]== ' ' && xy[x+2][y+1]== ' ' && xy[x-1][y-2]== ' ' && xy[x-1][y-3]== ' ' && xy[x][y-3]== ' ' &&  xy[x+1][y-3]== ' ' && xy[x+2][y-3]== ' ' && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y-2]== ' '){xy[x][y] = '6';xy[x+1][y] = '6';xy[x+2][y] = ' ';xy[x][y-1] = '6';xy[x+1][y-1] = ' ';xy[x+2][y-1] = '6';xy[x][y-2] = '6';xy[x+1][y-2] = '6';xy[x+2][y-2] = ' ';peca_n[6]++;} else { tentativa=tentativa+1; e=1;} break;

                        case 40: if (xy[x+1][y+1]== ' ' && xy[x][y+1]== ' ' && xy[x-1][y+1]== ' ' && xy[x-1][y]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' ' && xy[x-1][y-3]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y+1]== ' ' && xy[x+3][y+1]== ' ' && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y-2]== ' ' && xy[x+3][y-3]== ' ' && xy[x+2][y-3]== ' '){xy[x][y] = '7';xy[x+1][y] = ' ';xy[x+2][y] = '7';xy[x][y-1] = '7';xy[x+1][y-1] = '7';xy[x+2][y-1] = '7';xy[x][y-2] = '7';xy[x+1][y-2] = ' ';xy[x+2][y-2] = '7';peca_n[7]++;}else {tentativa=tentativa+1; e=1;} break;
                        case 41: if (xy[x+1][y+1]== ' ' && xy[x][y+1]== ' ' && xy[x-1][y+1]== ' ' && xy[x-1][y]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' ' && xy[x-1][y-3]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y+1]== ' ' && xy[x+3][y+1]== ' ' && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y-2]== ' ' && xy[x+3][y-3]== ' ' && xy[x+2][y-3]== ' '){xy[x][y] = '7';xy[x+1][y] = '7';xy[x+2][y] = '7';xy[x][y-1] = ' ';xy[x+1][y-1] = '7';xy[x+2][y-1] = ' ';xy[x][y-2] = '7';xy[x+1][y-2] = '7';xy[x+2][y-2] = '7';peca_n[7]++;}else {tentativa=tentativa+1; e=1;} break;

                        case 42: if (xy[x+1][y+1]== ' ' && xy[x][y+1]== ' ' && xy[x-1][y+1]== ' ' && xy[x-1][y]== ' ' && xy[x-1][y-1]== ' ' && xy[x-1][y-2]== ' ' && xy[x-1][y-3]== ' ' && xy[x][y-3]== ' ' && xy[x+1][y-3]== ' ' && xy[x+2][y+1]== ' ' && xy[x+3][y+1]== ' ' && xy[x+3][y]== ' ' && xy[x+3][y-1]== ' ' && xy[x+3][y-2]== ' ' && xy[x+3][y-3]== ' ' && xy[x+2][y-3]== ' '){xy[x][y] = '8';xy[x+1][y] = '8';xy[x+2][y] = '8';xy[x][y-1] = '8';xy[x+1][y-1] = ' ';xy[x+2][y-1] = '8';xy[x][y-2] = '8';xy[x+1][y-2] = '8';xy[x+2][y-2] = '8';peca_n[8]++;}else {tentativa=tentativa+1; e=1;} break;
                        default: e=1;break;
                        }
                    }
                    else {xy[x][y] = ' ';xy[x+1][y] = ' ';xy[x+2][y] = ' ';xy[x][y-1] = ' ';xy[x+1][y-1] = '1';xy[x+2][y-1] = ' ';xy[x][y-2] = ' ';xy[x+1][y-2] = ' ';xy[x+2][y-2] = ' ';peca_n[1]++;
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
            n_colunas=dim_tabu_x;
            n_linhas=dim_tabu_y;
            char k, l, min, max_1, max_2;
        switch (n_colunas){
            case 9: 

                 printf("\n ═══╦═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
                 min = (n_linhas - 2);
                 max_1 = (n_linhas/3);
                 max_2 = n_linhas;
                 for (l=1; l<=max_1; l++){   
                   for (k=max_2;k>min;k--){
                     if (k>=10){
                     printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, xy[1][k],xy[2][k],xy[3][k],xy[4][k],xy[5][k],xy[6][k],xy[7][k],xy[8][k],xy[9][k]);
                     }
                     else {
                     printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, xy[1][k],xy[2][k],xy[3][k],xy[4][k],xy[5][k],xy[6][k],xy[7][k],xy[8][k],xy[9][k]);
                     }
                     printf(" ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
                   } 
                     if (k>=10){
                     printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, xy[1][k],xy[2][k],xy[3][k],xy[4][k],xy[5][k],xy[6][k],xy[7][k],xy[8][k],xy[9][k]);
                     }
                     else {
                     printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, xy[1][k],xy[2][k],xy[3][k],xy[4][k],xy[5][k],xy[6][k],xy[7][k],xy[8][k],xy[9][k]);
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
                     printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, xy[1][k],xy[2][k],xy[3][k],xy[4][k],xy[5][k],xy[6][k],xy[7][k],xy[8][k],xy[9][k],xy[10][k],xy[11][k],xy[12][k]);
                     }
                     else {
                     printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, xy[1][k],xy[2][k],xy[3][k],xy[4][k],xy[5][k],xy[6][k],xy[7][k],xy[8][k],xy[9][k],xy[10][k],xy[11][k],xy[12][k]);
                     }
                     printf(" ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
                   } 
                     if (k>=10){
                     printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, xy[1][k],xy[2][k],xy[3][k],xy[4][k],xy[5][k],xy[6][k],xy[7][k],xy[8][k],xy[9][k],xy[10][k],xy[11][k],xy[12][k]);
                     }
                     else {
                     printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, xy[1][k],xy[2][k],xy[3][k],xy[4][k],xy[5][k],xy[6][k],xy[7][k],xy[8][k],xy[9][k],xy[10][k],xy[11][k],xy[12][k]);
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
                     printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, xy[1][k],xy[2][k],xy[3][k],xy[4][k],xy[5][k],xy[6][k],xy[7][k],xy[8][k],xy[9][k],xy[10][k],xy[11][k],xy[12][k],xy[13][k],xy[14][k],xy[15][k]);
                     }
                     else {
                     printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, xy[1][k],xy[2][k],xy[3][k],xy[4][k],xy[5][k],xy[6][k],xy[7][k],xy[8][k],xy[9][k],xy[10][k],xy[11][k],xy[12][k],xy[13][k],xy[14][k],xy[15][k]);
                     }
                     printf(" ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
                   } 
                     if (k>=10){
                     printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, xy[1][k],xy[2][k],xy[3][k],xy[4][k],xy[5][k],xy[6][k],xy[7][k],xy[8][k],xy[9][k],xy[10][k],xy[11][k],xy[12][k],xy[13][k],xy[14][k],xy[15][k]);
                     }
                     else {
                     printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, xy[1][k],xy[2][k],xy[3][k],xy[4][k],xy[5][k],xy[6][k],xy[7][k],xy[8][k],xy[9][k],xy[10][k],xy[11][k],xy[12][k],xy[13][k],xy[14][k],xy[15][k]);
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
                     printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, xy[1][k],xy[2][k],xy[3][k],xy[4][k],xy[5][k],xy[6][k],xy[7][k],xy[8][k],xy[9][k],xy[10][k],xy[11][k],xy[12][k],xy[13][k],xy[14][k],xy[15][k],xy[16][k],xy[17][k],xy[18][k]);
                     }
                     else {
                     printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, xy[1][k],xy[2][k],xy[3][k],xy[4][k],xy[5][k],xy[6][k],xy[7][k],xy[8][k],xy[9][k],xy[10][k],xy[11][k],xy[12][k],xy[13][k],xy[14][k],xy[15][k],xy[16][k],xy[17][k],xy[18][k]);
                     }
                     printf(" ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
                   } 
                     if (k>=10){
                     printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, xy[1][k],xy[2][k],xy[3][k],xy[4][k],xy[5][k],xy[6][k],xy[7][k],xy[8][k],xy[9][k],xy[10][k],xy[11][k],xy[12][k],xy[13][k],xy[14][k],xy[15][k],xy[16][k],xy[17][k],xy[18][k]);
                     }
                     else {
                     printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, xy[1][k],xy[2][k],xy[3][k],xy[4][k],xy[5][k],xy[6][k],xy[7][k],xy[8][k],xy[9][k],xy[10][k],xy[11][k],xy[12][k],xy[13][k],xy[14][k],xy[15][k],xy[16][k],xy[17][k],xy[18][k]);
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
                     printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, xy[1][k],xy[2][k],xy[3][k],xy[4][k],xy[5][k],xy[6][k],xy[7][k],xy[8][k],xy[9][k],xy[10][k],xy[11][k],xy[12][k],xy[13][k],xy[14][k],xy[15][k],xy[16][k],xy[17][k],xy[18][k],xy[19][k],xy[20][k],xy[21][k]);
                     }
                     else {
                     printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, xy[1][k],xy[2][k],xy[3][k],xy[4][k],xy[5][k],xy[6][k],xy[7][k],xy[8][k],xy[9][k],xy[10][k],xy[11][k],xy[12][k],xy[13][k],xy[14][k],xy[15][k],xy[16][k],xy[17][k],xy[18][k],xy[19][k],xy[20][k],xy[21][k]);
                     }
                     printf(" ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
                   } 
                     if (k>=10){
                     printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, xy[1][k],xy[2][k],xy[3][k],xy[4][k],xy[5][k],xy[6][k],xy[7][k],xy[8][k],xy[9][k],xy[10][k],xy[11][k],xy[12][k],xy[13][k],xy[14][k],xy[15][k],xy[16][k],xy[17][k],xy[18][k],xy[19][k],xy[20][k],xy[21][k]);
                     }
                     else {
                     printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, xy[1][k],xy[2][k],xy[3][k],xy[4][k],xy[5][k],xy[6][k],xy[7][k],xy[8][k],xy[9][k],xy[10][k],xy[11][k],xy[12][k],xy[13][k],xy[14][k],xy[15][k],xy[16][k],xy[17][k],xy[18][k],xy[19][k],xy[20][k],xy[21][k]);
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
                     printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, xy[1][k],xy[2][k],xy[3][k],xy[4][k],xy[5][k],xy[6][k],xy[7][k],xy[8][k],xy[9][k],xy[10][k],xy[11][k],xy[12][k],xy[13][k],xy[14][k],xy[15][k],xy[16][k],xy[17][k],xy[18][k],xy[19][k],xy[20][k],xy[21][k],xy[22][k],xy[23][k],xy[24][k]);
                     }
                     else {
                     printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, xy[1][k],xy[2][k],xy[3][k],xy[4][k],xy[5][k],xy[6][k],xy[7][k],xy[8][k],xy[9][k],xy[10][k],xy[11][k],xy[12][k],xy[13][k],xy[14][k],xy[15][k],xy[16][k],xy[17][k],xy[18][k],xy[19][k],xy[20][k],xy[21][k],xy[22][k],xy[23][k],xy[24][k]);
                     }
                     printf(" ───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╫───┼───┼───╢\n");
                   } 
                     if (k>=10){
                     printf(" %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, xy[1][k],xy[2][k],xy[3][k],xy[4][k],xy[5][k],xy[6][k],xy[7][k],xy[8][k],xy[9][k],xy[10][k],xy[11][k],xy[12][k],xy[13][k],xy[14][k],xy[15][k],xy[16][k],xy[17][k],xy[18][k],xy[19][k],xy[20][k],xy[21][k],xy[22][k],xy[23][k],xy[24][k]);
                     }
                     else {
                     printf("  %d ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║ %c │ %c │ %c ║\n",k, xy[1][k],xy[2][k],xy[3][k],xy[4][k],xy[5][k],xy[6][k],xy[7][k],xy[8][k],xy[9][k],xy[10][k],xy[11][k],xy[12][k],xy[13][k],xy[14][k],xy[15][k],xy[16][k],xy[17][k],xy[18][k],xy[19][k],xy[20][k],xy[21][k],xy[22][k],xy[23][k],xy[24][k]);
                     }
                     printf(" ═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n");
                     max_2=(max_2-3);
                     min=(min-3);
                 } 
                     printf("    ║ A │ B │ C ║ D │ E │ F ║ G │ H │ I ║ J │ K │ L ║ M │ N │ O ║ P │ Q │ R ║ S │ T │ U ║ V │ W │ X ║\n"); 
            break;               
        }

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
    