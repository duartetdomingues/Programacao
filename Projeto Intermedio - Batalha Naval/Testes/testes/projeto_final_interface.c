#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void main_menu() ;
void modo_j0();
void modo_j1();
void modo_j2();
void instrucoes();
void modo_p1();
void modo_p2();
void modo_d1();
void modo_d2();
void print_tabu();
void print_logo();
void print_modo_x();
void print_pecas();
void print_dimensao();
//void novo_tabuleiro_p2();

int modo_jogo=-1, modo_pos,modo_dis,dim_tabu_x,dim_tabu_y,peca_n[9]={0,0,0,0,0,0,0,0,0}; //9
int novamente=0;

char yx[17][26];

char d_yx[17][26]= //17 e 26
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

char p_yx[17][26]= //17 e 26
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
        int e,m,n;
        do{
        e=0;
        system("clear");
        print_logo();
        printf("Escola a dimensão do Tabuleiro?( Ex.: 9x9 (linhas x colunas) )\n");
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
        case 1:modo_p1();system("clear");for(m=0;m<=17;m++){for(n=0;n<=26;n++){yx[m][n]=p_yx[m][n];}}print_logo();print_dimensao();print_pecas();print_tabu(); break; 
        case 2:modo_p2();system("clear");for(m=0;m<=17;m++){for(n=0;n<=26;n++){yx[m][n]=p_yx[m][n];}}print_logo();print_dimensao();print_pecas();print_tabu(); break;
        default: e=1;break;}}
        }while (e!=0);
    
    }

    void modo_j1(){
     int e,m,n;
        do{
        e=0;
        system("clear");
        print_logo();
        printf("Escola a dimensão do Tabuleiro?( Ex.: 9x9 (linhas x colunas) )\n");
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
        case 1:modo_p1(); break; 
        case 2:modo_p2(); break;
        default: e=1;break;}}
        }while (e!=0);

        //for(m=0;m<=17;m++){for(n=0;n<=26;n++){yx[m][n]=p_yx[m][n];}}print_tabu();scanf("%d",&e);

    clock_t begin = clock();

        char  char_x;
        int x,y=0,j ,k,t_pecas,i_pecas,erro=0,i,tentativa_d=0,e_print;
        t_pecas = peca_n[1] + peca_n[2]*2 + peca_n[3]*3 + peca_n[4]*4 + peca_n[5]*5 + peca_n[6]*6 + peca_n[7]*7 + peca_n[8]*8;
        
        while(t_pecas != 0 | erro==1 ){system("clear");print_logo();
        for(m=0;m<=17;m++){for(n=0;n<=26;n++){yx[m][n]=d_yx[m][n];}} print_tabu(); printf("Peças totais:");print_pecas();
          printf("\n");
          if(e_print==1){printf("Cordenada ja inserida, escolha outra!!\n");}
          if(erro==1){printf("Erro! Escreva novamente!\n");}
            printf("Escreva a coordenada de disparo ( Ex.: C2 )\n");
            scanf(" %c%d",&char_x,&y);
            erro=0;
            if (char_x<65 | (char_x > dim_tabu_x + 64 & char_x<96) | char_x > dim_tabu_x + 96 | y<0 | y > dim_tabu_y ){erro=1;}
        else{
            if(char_x <= dim_tabu_x + 64){x= char_x - 64;}
            else{x= char_x - 96;}
            j=0;k=0;
            if(d_yx[y][x]==' ')
            {tentativa_d++;
            if(p_yx[y][x]==' '){d_yx[y][x]='-';}
            else{d_yx[y][x]=p_yx[y][x];}
            e_print=0;}
            else{e_print=1;}
            i_pecas=0;
            for(j=0;j<=dim_tabu_y;j++){
            for(k=0;k<=dim_tabu_x;k++){
                if(d_yx[j][k]!=' ' & d_yx[j][k]!='-'){i_pecas++;}}}
        }
        }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;;      


        system("clear");print_logo();
        for(m=0;m<=17;m++){for(n=0;n<=26;n++){yx[m][n]=p_yx[m][n];}}print_tabu();
        printf("Tentativas = %d\n",tentativa_d);
        printf("Tempo de jogo = %f\n", time_spent);
    }
            

    void modo_j2(){
        int e;
        do{
        e=0;
        system("clear");
        print_logo();
        printf("Escola a dimensão do Tabuleiro?( Ex.: 9x9 (linhas x colunas) )\n");
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
        printf("Escolha o modo de disparo que deseja, 1 ou 2 ou 3?\n");
        if (scanf("%d", &modo_dis) != 1){
        char erro;
        scanf("%c", &erro);  // limpar caracters
        e=1;}
        else{
        system("clear");
        print_logo();
        switch(modo_dis){
        case 1:modo_d1();/*system("clear");print_logo();print_dimensao();print_pecas();print_tabu(); */break; 
        case 2:modo_d2();/*system("clear");print_logo();print_dimensao();print_pecas();print_tabu(); */break;
        default: e=1;break;}}
        }while (e!=0);




        /*system("clear");
        print_logo();
        printf("modo 2\n");*/ 
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
        srand((unsigned)time(&t));
        matriz_y=-1;

        do{
            matriz_x=-1;
            matriz_y=matriz_y+1;
            y=dim_tabu_y-(matriz_y*3);
            
            do{
                matriz_x=matriz_x+1;
                x=1+(matriz_x*3);
                tentativa=1;
                
                do{
                    e=0;
                    if (tentativa<=3){
                        peca= rand() % 43;
                        switch(peca){
                        case 0:p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_n[0]++; break;
                        
                        case 1: if (p_yx[y-1][x-1]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y+1][x-1]== ' ' &&  p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' '){p_yx[y][x] = '1';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' '; peca_n[1]++;} else {tentativa=tentativa+1;  e=1;} break;
                        case 2: if (p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' '){p_yx[y][x] = ' ';p_yx[y][x+1] = '1';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_n[1]++;} else {tentativa=tentativa+1;  e=1;} break;
                        case 3: if (p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' && p_yx[y+1][x+3]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' '){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = '1';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_n[1]++;} else {tentativa=tentativa+1;  e=1;} break;
                        case 4: if (p_yx[y][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' '){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = '1';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_n[1]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 5: p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = '1';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_n[1]++;break;
                        case 6: if (p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-2][x+3]== ' '){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = '1';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_n[1]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 7: if (p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' ' && p_yx[y-3][x-1]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' '){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = '1';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_n[1]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 8: if (p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' '){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = '1';p_yx[y-2][x+2] = ' ';peca_n[1]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 9: if (p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' ' && p_yx[y-3][x+3]== ' ' && p_yx[y-2][x+3]== ' ' && p_yx[y-1][x+3]== ' '){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = '1';peca_n[1]++;}else {tentativa=tentativa+1;  e=1;} break;
                        
                        case 10:if (p_yx[y-1][x-1]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y+1][x-1]== ' ' &&  p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' ){p_yx[y][x] = '2';p_yx[y][x+1] = '2';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 11:if (p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' &&  p_yx[y+1][x+3]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' ){p_yx[y][x] = ' ';p_yx[y][x+1] = '2';p_yx[y][x+2] = '2';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 12:if (p_yx[y-2][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y][x-1]== ' ' ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = '2';p_yx[y-1][x+1] = '2';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 13:if (p_yx[y-2][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y][x+3]== ' ' ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = '2';p_yx[y-1][x+2] = '2';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 14:if (p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' ' && p_yx[y-3][x-1]== ' ' && p_yx[y-3][x]== ' ' &&  p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' ' ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = '2';p_yx[y-2][x+1] = '2';p_yx[y-2][x+2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 15:if (p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' ' &&  p_yx[y-3][x+3]== ' ' && p_yx[y-2][x+3]== ' ' && p_yx[y-1][x+3]== ' ' ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = '2';p_yx[y-2][x+2] = '2';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 16:if (p_yx[y-2][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y][x-1]== ' ' &&  p_yx[y+1][x-1]== ' ' && p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' ){p_yx[y][x] = '2';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = '2';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 17:if (p_yx[y][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' ' &&  p_yx[y-3][x-1]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = '2';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = '2';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 18:if (p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' ){p_yx[y][x] = ' ';p_yx[y][x+1] = '2';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = '2';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 19:if (p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' ' ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = '2';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = '2';p_yx[y-2][x+2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 20:if (p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' && p_yx[y+1][x+3]== ' ' &&  p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-2][x+3]== ' ' ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = '2';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = '2';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 21:if (p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' ' && p_yx[y-3][x+3]== ' ' &&  p_yx[y-2][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y][x+3]== ' ' ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = '2';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = '2';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;

                        case 22: if (p_yx[y-1][x-1]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y+1][x-1]== ' ' && p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' && p_yx[y+1][x+3]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' '){p_yx[y][x] = '3';p_yx[y][x+1] = '3';p_yx[y][x+2] = '3';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_n[3]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 23: if (p_yx[y-2][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-2][x+3]== ' ' ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = '3';p_yx[y-1][x+1] = '3';p_yx[y-1][x+2] = '3';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_n[3]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 24: if (p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' ' && p_yx[y-3][x-1]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' ' && p_yx[y-3][x+3]== ' ' && p_yx[y-2][x+3]== ' ' && p_yx[y-1][x+3]== ' '){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = '3';p_yx[y-2][x+1] = '3';p_yx[y-2][x+2] = '3';peca_n[3]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 25: if (p_yx[y+1][x+1]== ' ' && p_yx[y+1][x]== ' ' && p_yx[y+1][x-1]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' ' && p_yx[y-3][x-1]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' '){p_yx[y][x] = '3';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = '3';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = '3';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_n[3]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 26: if (p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' '){p_yx[y][x] = ' ';p_yx[y][x+1] = '3';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = '3';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = '3';p_yx[y-2][x+2] = ' ';peca_n[3]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 27: if (p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' && p_yx[y+1][x+3]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-2][x+3]== ' ' && p_yx[y-3][x+3]== ' ' && p_yx[y-3][x+2]== ' ' && p_yx[y-3][x+1]== ' '){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = '3';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = '3';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = '3';peca_n[3]++;}else {tentativa=tentativa+1;  e=1;} break;
                        
                        case 28: if (p_yx[y-2][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y+1][x-1]== ' ' && p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' '){p_yx[y][x] = '4';p_yx[y][x+1] = '4';p_yx[y][x+2] = ' ';p_yx[y-1][x] = '4';p_yx[y-1][x+1] = '4';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_n[4]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 29: if (p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' && p_yx[y+1][x+3]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-2][x+3]== ' '){p_yx[y][x] = ' ';p_yx[y][x+1] = '4';p_yx[y][x+2] = '4';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = '4';p_yx[y-1][x+2] = '4';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_n[4]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 30: if (p_yx[y][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' ' && p_yx[y-3][x-1]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' '){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = '4';p_yx[y-1][x+1] = '4';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = '4';p_yx[y-2][x+1] = '4';p_yx[y-2][x+2] = ' ';peca_n[4]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 31: if (p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' ' && p_yx[y-3][x+3]== ' ' && p_yx[y-2][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y][x+3]== ' '){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = '4';p_yx[y-1][x+2] = '4';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = '4';p_yx[y-2][x+2] = '4';peca_n[4]++;}else {tentativa=tentativa+1;  e=1;} break;

                        case 32: if (p_yx[y-1][x-1]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y+1][x-1]== ' ' && p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' && p_yx[y+1][x+3]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' '){p_yx[y][x] = '5';p_yx[y][x+1] = '5';p_yx[y][x+2] = '5';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = '5';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = '5';p_yx[y-2][x+2] = ' ';peca_n[5]++;}else {tentativa=tentativa+1; e=1;} break;
                        case 33: if (p_yx[y+1][x+1]== ' ' && p_yx[y+1][x]== ' ' && p_yx[y+1][x-1]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' ' && p_yx[y-3][x-1]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' '  && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-2][x+3]== ' '){p_yx[y][x] = '5';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = '5';p_yx[y-1][x+1] = '5';p_yx[y-1][x+2] = '5';p_yx[y-2][x] = '5';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_n[5]++;}else {tentativa=tentativa+1; e=1;} break;
                        case 34: if (p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' ' && p_yx[y-3][x-1]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' ' && p_yx[y-3][x+3]== ' ' && p_yx[y-2][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' '){p_yx[y][x] = ' ';p_yx[y][x+1] = '5';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = '5';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = '5';p_yx[y-2][x+1] = '5';p_yx[y-2][x+2] = '5';peca_n[5]++;}else {tentativa=tentativa+1; e=1;} break;
                        case 35: if (p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' && p_yx[y+1][x+3]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-2][x+3]== ' ' && p_yx[y-3][x+3]== ' ' && p_yx[y-3][x+2]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' '){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = '5';p_yx[y-1][x] = '5';p_yx[y-1][x+1] = '5';p_yx[y-1][x+2] = '5';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = '5';peca_n[5]++;}else {tentativa=tentativa+1; e=1;} break;

                        case 36: if (p_yx[y][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' ' &&  p_yx[y-3][x-1]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' ' && p_yx[y-3][x+3]== ' ' &&  p_yx[y-2][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' '){p_yx[y][x] = ' ';p_yx[y][x+1] = '6';p_yx[y][x+2] = ' ';p_yx[y-1][x] = '6';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = '6';p_yx[y-2][x] = '6';p_yx[y-2][x+1] = '6';p_yx[y-2][x+2] = '6';peca_n[6]++;} else {tentativa=tentativa+1; e=1;} break;
                        case 37: if (p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' &&  p_yx[y+1][x+3]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' ' &&  p_yx[y-3][x+3]== ' ' && p_yx[y-2][x+3]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' '){p_yx[y][x] = ' ';p_yx[y][x+1] = '6';p_yx[y][x+2] = '6';p_yx[y-1][x] = '6';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = '6';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = '6';p_yx[y-2][x+2] = '6';peca_n[6]++;} else { tentativa=tentativa+1; e=1;} break;
                        case 38: if (p_yx[y-2][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y][x-1]== ' ' &&  p_yx[y+1][x-1]== ' ' && p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' && p_yx[y+1][x+3]== ' ' &&  p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-2][x+3]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' '){p_yx[y][x] = '6';p_yx[y][x+1] = '6';p_yx[y][x+2] = '6';p_yx[y-1][x] = '6';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = '6';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = '6';p_yx[y-2][x+2] = ' ';peca_n[6]++;} else { tentativa=tentativa+1; e=1;} break;
                        case 39: if (p_yx[y-1][x-1]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y+1][x-1]== ' ' &&  p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' && p_yx[y-2][x-1]== ' ' && p_yx[y-3][x-1]== ' ' && p_yx[y-3][x]== ' ' &&  p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-2][x+3]== ' '){p_yx[y][x] = '6';p_yx[y][x+1] = '6';p_yx[y][x+2] = ' ';p_yx[y-1][x] = '6';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = '6';p_yx[y-2][x] = '6';p_yx[y-2][x+1] = '6';p_yx[y-2][x+2] = ' ';peca_n[6]++;} else { tentativa=tentativa+1; e=1;} break;

                        case 40: if (p_yx[y+1][x+1]== ' ' && p_yx[y+1][x]== ' ' && p_yx[y+1][x-1]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' ' && p_yx[y-3][x-1]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y+1][x+2]== ' ' && p_yx[y+1][x+3]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-2][x+3]== ' ' && p_yx[y-3][x+3]== ' ' && p_yx[y-3][x+2]== ' '){p_yx[y][x] = '7';p_yx[y][x+1] = ' ';p_yx[y][x+2] = '7';p_yx[y-1][x] = '7';p_yx[y-1][x+1] = '7';p_yx[y-1][x+2] = '7';p_yx[y-2][x] = '7';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = '7';peca_n[7]++;}else {tentativa=tentativa+1; e=1;} break;
                        case 41: if (p_yx[y+1][x+1]== ' ' && p_yx[y+1][x]== ' ' && p_yx[y+1][x-1]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' ' && p_yx[y-3][x-1]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y+1][x+2]== ' ' && p_yx[y+1][x+3]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-2][x+3]== ' ' && p_yx[y-3][x+3]== ' ' && p_yx[y-3][x+2]== ' '){p_yx[y][x] = '7';p_yx[y][x+1] = '7';p_yx[y][x+2] = '7';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = '7';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = '7';p_yx[y-2][x+1] = '7';p_yx[y-2][x+2] = '7';peca_n[7]++;}else {tentativa=tentativa+1; e=1;} break;

                        case 42: if (p_yx[y+1][x+1]== ' ' && p_yx[y+1][x]== ' ' && p_yx[y+1][x-1]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' ' && p_yx[y-3][x-1]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y+1][x+2]== ' ' && p_yx[y+1][x+3]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-2][x+3]== ' ' && p_yx[y-3][x+3]== ' ' && p_yx[y-3][x+2]== ' '){p_yx[y][x] = '8';p_yx[y][x+1] = '8';p_yx[y][x+2] = '8';p_yx[y-1][x] = '8';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = '8';p_yx[y-2][x] = '8';p_yx[y-2][x+1] = '8';p_yx[y-2][x+2] = '8';peca_n[8]++;}else {tentativa=tentativa+1; e=1;} break;
                        default: e=1;break;
                        }
                    }
                    else {p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = '1';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_n[1]++;
                    }
                }while (e !=0);
            }while(x< dim_tabu_x - 2);
        }while(y>3);

        //posicionar peças da forma p1
    }

    void modo_p2(){
        int m=1, quantidade, erro, n_pecas_max,n=0, n_pecas_escolhidas;
        system("clear");
        print_logo();
        do{
        do{
        erro = 0;
        //if(n != 0){printf("Excedeu o nÂº de PeÃ§as\n" );}
        printf("Escolha a quantidade de peças do tipo %d: \n", m);
        if (scanf("%d",&quantidade) != 1){char erro;scanf("%c", &erro);erro=1;quantidade=0;system("clear");print_logo();printf("Erro! Escolha novamente!\n\n");}
        else{
        n_pecas_max=((dim_tabu_x*dim_tabu_y)/9)/2;
        peca_n[m] = quantidade;
        m=m+1;
        n_pecas_escolhidas= peca_n[1]+peca_n[2]+peca_n[3]+peca_n[4]+peca_n[5]+peca_n[6]+peca_n[7]+peca_n[8];
        }
        if (n_pecas_max < n_pecas_escolhidas){system("clear");print_logo();printf("Excedeu o número de peças\n\n" );
        m=1;for(m=1;m<=8;m++){peca_n[m]=0;}m=1;erro=1;//reset array
        }//exceder peÃ§as
        if (peca_n[m-2]<peca_n[m-1] & m != 2){system("clear");print_logo();printf("O número de peças de um tipo de maior dimensão é superior\n\n" );
        m=1;for(m=1;m<=8;m++){peca_n[m]=0;}m=1;erro=1;//reset array
        }// numero pe
        }while(erro != 0 | n_pecas_max < n_pecas_escolhidas);
        }while (n_pecas_escolhidas< n_pecas_max & m<=8);
        if (m<9){printf("\nNúmero máximo de peças atingido!!!\n");}
        if (m==9){printf("\nTodos os tipos de peças defenidos!!!\n");}
        peca_n[0]= ((dim_tabu_x*dim_tabu_y)/9) - n_pecas_escolhidas;       
        //posicionar peÃ§as da forma p2
        int matriz_x, matriz_y, x, y, selecao_tipo, peca, tentativa_v,f=0,tentativa[9]={0,0,0,0,0,0,0,0,0}, n_pecas_colocadas=0, novo_tabuleiro_count=0, erro_tabuleiro, erro_peca=0, e=0, peca_em_falta[9]={0,0,0,0,0,0,0,0,0};
        srand((unsigned)time(&t));
        do{ matriz_y=-1;
            erro_tabuleiro=0;
            f=0;
            for(f=0;f<=8;f++){peca_em_falta[f]=peca_n[f];}
            
            do{
              matriz_x=-1;
              matriz_y=matriz_y+1;
              y=dim_tabu_y-(matriz_y*3);
            
                do{
                 m=0;
                 for(m=0;m<=8;m++){
                    tentativa[m]=0;}

                 matriz_x=matriz_x+1;
                 x=1+(matriz_x*3);
                 tentativa_v=-1;
                 
                
                    
                        do{
                            erro_peca=0;
                            selecao_tipo= rand() % 9;
                            
                            if ( (peca_em_falta[0]==0 | tentativa[0]==1) & (peca_em_falta[1]==0 | tentativa[1]==1) & (peca_em_falta[2]==0 | tentativa[2]==1) & (peca_em_falta[3]==0 | tentativa[3]==1) & (peca_em_falta[4]==0 | tentativa[4]==1) & (peca_em_falta[5]==0 | tentativa[5]==1) &(peca_em_falta[6]==0 | tentativa[6]==1) &(peca_em_falta[7]==0 | tentativa[7]==1) & (peca_em_falta[8]==0 | tentativa[8]==1) ){novo_tabuleiro_count++;erro_tabuleiro=1;}
                            if (tentativa[selecao_tipo]==1){erro_peca=1;}
                            else{
                                 if(selecao_tipo==0 & peca_em_falta[0] != 0){
                                  p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_em_falta[0]--; e=0; (n_pecas_colocadas = n_pecas_colocadas + 1);
                                 }
                                 else if (selecao_tipo == 1 & peca_em_falta[1] != 0){
                                     do{ 
                                        if(e==1){tentativa_v=tentativa_v+1; peca=tentativa_v;e=0;}
                                        else{
                                         peca= rand() % 9;
                                         e=0;  
                                        }
                                     switch(peca){
                                     case 0: if (p_yx[y-1][x-1]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y+1][x-1]== ' ' &&  p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' ){p_yx[y][x] = '1';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' '; peca_em_falta[1]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {e=1;} break;
                                     case 1: if (p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' ){p_yx[y][x] = ' ';p_yx[y][x+1] = '1';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_em_falta[1]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else { e=1;} break;
                                     case 2: if (p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' && p_yx[y+1][x+3]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = '1';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_em_falta[1]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {e=1;} break;
                                     case 3: if (p_yx[y][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' ' ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = '1';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_em_falta[1]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                                     case 4: p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = '1';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_em_falta[1]--;(n_pecas_colocadas = n_pecas_colocadas + 1);break;
                                     case 5: if (p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-2][x+3]== ' ' ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = '1';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_em_falta[1]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                                     case 6: if (p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' ' && p_yx[y-3][x-1]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = '1';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_em_falta[1]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                                     case 7: if (p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' ' ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = '1';p_yx[y-2][x+2] = ' ';peca_em_falta[1]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                                     case 8: if (p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' ' && p_yx[y-3][x+3]== ' ' && p_yx[y-2][x+3]== ' ' && p_yx[y-1][x+3]== ' ' ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = '1';peca_em_falta[1]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                                     }
                                     if(tentativa_v>=8){erro_peca=1;tentativa[1]=1;}
                                    }while (tentativa_v<8 && e==1 );
                                }
                                else if (selecao_tipo == 2 & peca_em_falta[2] != 0){
                                     do{
                                        if(e==1){tentativa_v=tentativa_v+1; peca=tentativa_v;e=0;}
                                        else{
                                         peca= rand() % 12;
                                         e=0;
                                        }
                                     switch(peca){
                                     case 0:if (p_yx[y-1][x-1]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y+1][x-1]== ' ' &&  p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' '  ){p_yx[y][x] = '2';p_yx[y][x+1] = '2';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_em_falta[2]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {   e=1;} break;
                                     case 1:if (p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' &&  p_yx[y+1][x+3]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' '   ){p_yx[y][x] = ' ';p_yx[y][x+1] = '2';p_yx[y][x+2] = '2';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_em_falta[2]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {   e=1;} break;
                                     case 2:if (p_yx[y-2][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y][x-1]== ' '  ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = '2';p_yx[y-1][x+1] = '2';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_em_falta[2]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {   e=1;} break;
                                     case 3:if (p_yx[y-2][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y][x+3]== ' '  ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = '2';p_yx[y-1][x+2] = '2';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_em_falta[2]--;(n_pecas_colocadas = n_pecas_colocadas + 1);;} else {   e=1;} break;
                                     case 4:if (p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' ' && p_yx[y-3][x-1]== ' ' && p_yx[y-3][x]== ' ' &&  p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' '  ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = '2';p_yx[y-2][x+1] = '2';p_yx[y-2][x+2] = ' ';peca_em_falta[2]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {   e=1;} break;
                                     case 5:if (p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' ' &&  p_yx[y-3][x+3]== ' ' && p_yx[y-2][x+3]== ' ' && p_yx[y-1][x+3]== ' '   ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = '2';p_yx[y-2][x+2] = '2';peca_em_falta[2]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {   e=1;} break;
                                     case 6:if (p_yx[y-2][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y][x-1]== ' ' &&  p_yx[y+1][x-1]== ' ' && p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' '  ){p_yx[y][x] = '2';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = '2';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_em_falta[2]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {   e=1;} break;
                                     case 7:if (p_yx[y][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' ' &&  p_yx[y-3][x-1]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' '  ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = '2';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = '2';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_em_falta[2]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {   e=1;} break;
                                     case 8:if (p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' '  ){p_yx[y][x] = ' ';p_yx[y][x+1] = '2';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = '2';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_em_falta[2]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {e=1;} break;
                                     case 9:if (p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' '  ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = '2';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = '2';p_yx[y-2][x+2] = ' ';peca_em_falta[2]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {e=1;} break;
                                     case 10:if (p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' && p_yx[y+1][x+3]== ' ' &&  p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-2][x+3]== ' '  ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = '2';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = '2';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_em_falta[2]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {   e=1;} break;
                                     case 11:if (p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' ' && p_yx[y-3][x+3]== ' ' &&  p_yx[y-2][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y][x+3]== ' '  ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = '2';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = '2';peca_em_falta[2]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {   e=1;} break;
                                     }
                                     if(tentativa_v>=11){erro_peca=1;tentativa[2]=1;}
                                    }while (tentativa_v<11 && e==1 );  
                                }

                            else if (selecao_tipo == 3 & peca_em_falta[3] != 0){
                                do{
                                if(e==1){tentativa_v=tentativa_v+1; peca=tentativa_v;e=0;}
                                else{
                                   peca= rand() % 6;
                                   e=0;
                                }
                                   switch(peca){
                                    case 0: if (p_yx[y-1][x-1]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y+1][x-1]== ' ' && p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' && p_yx[y+1][x+3]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' ){p_yx[y][x] = '3';p_yx[y][x+1] = '3';p_yx[y][x+2] = '3';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_em_falta[3]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {  e=1;} break;
                                    case 1: if (p_yx[y-2][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-2][x+3]== ' ' ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = '3';p_yx[y-1][x+1] = '3';p_yx[y-1][x+2] = '3';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_em_falta[3]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {  e=1;} break;
                                    case 2: if (p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' ' && p_yx[y-3][x-1]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' ' && p_yx[y-3][x+3]== ' ' && p_yx[y-2][x+3]== ' ' && p_yx[y-1][x+3]== ' ' ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = '3';p_yx[y-2][x+1] = '3';p_yx[y-2][x+2] = '3';peca_em_falta[3]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {  e=1;} break;
                                    case 3: if (p_yx[y+1][x+1]== ' ' && p_yx[y+1][x]== ' ' && p_yx[y+1][x-1]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' ' && p_yx[y-3][x-1]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' '){p_yx[y][x] = '3';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = '3';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = '3';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_em_falta[3]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {  e=1;} break;
                                    case 4: if (p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' ' ){p_yx[y][x] = ' ';p_yx[y][x+1] = '3';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = '3';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = '3';p_yx[y-2][x+2] = ' ';peca_em_falta[3]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {  e=1;} break;
                                    case 5: if (p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' && p_yx[y+1][x+3]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-2][x+3]== ' ' && p_yx[y-3][x+3]== ' ' && p_yx[y-3][x+2]== ' ' && p_yx[y-3][x+1]== ' ' ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = '3';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = '3';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = '3';peca_em_falta[3]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {  e=1;} break;
                            }       
                                    if(tentativa_v>=5){erro_peca=1;tentativa[3]=1;}
                                }while (tentativa_v<5 && e==1 );
                            }

                            else if (selecao_tipo == 4 & peca_em_falta[4] != 0){
                                do{
                                if(e==1){tentativa_v=tentativa_v+1; peca=tentativa_v;e=0;}
                                else{
                                   peca= rand() % 4;
                                   e=0;
                                } 
                                   switch(peca){
                                    case 0: if (p_yx[y-2][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y+1][x-1]== ' ' && p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' ){p_yx[y][x] = '4';p_yx[y][x+1] = '4';p_yx[y][x+2] = ' ';p_yx[y-1][x] = '4';p_yx[y-1][x+1] = '4';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_em_falta[4]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                                    case 1: if (p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' && p_yx[y+1][x+3]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-2][x+3]== ' ' ){p_yx[y][x] = ' ';p_yx[y][x+1] = '4';p_yx[y][x+2] = '4';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = '4';p_yx[y-1][x+2] = '4';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_em_falta[4]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                                    case 2: if (p_yx[y][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' ' && p_yx[y-3][x-1]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' ' ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = '4';p_yx[y-1][x+1] = '4';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = '4';p_yx[y-2][x+1] = '4';p_yx[y-2][x+2] = ' ';peca_em_falta[4]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                                    case 3: if (p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' ' && p_yx[y-3][x+3]== ' ' && p_yx[y-2][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y][x+3]== ' ' ){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = '4';p_yx[y-1][x+2] = '4';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = '4';p_yx[y-2][x+2] = '4';peca_em_falta[4]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                            }       
                                    if(tentativa_v>=3){erro_peca=1;tentativa[4]=1;}
                                }while (tentativa_v<3 && e==1 );
                            }
                            else if (selecao_tipo == 5 & peca_em_falta[5] != 0){
                                do{
                                if(e==1){tentativa_v=tentativa_v+1; peca=tentativa_v;e=0;}
                                else{
                                   peca= rand() % 4;
                                   e=0;
                                }
                                   switch(peca){
                                    case 0: if (p_yx[y-1][x-1]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y+1][x-1]== ' ' && p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' && p_yx[y+1][x+3]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' '){p_yx[y][x] = '5';p_yx[y][x+1] = '5';p_yx[y][x+2] = '5';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = '5';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = '5';p_yx[y-2][x+2] = ' ';peca_em_falta[5]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else { e=1;} break;
                                    case 1: if (p_yx[y+1][x+1]== ' ' && p_yx[y+1][x]== ' ' && p_yx[y+1][x-1]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' ' && p_yx[y-3][x-1]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' '  && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-2][x+3]== ' '){p_yx[y][x] = '5';p_yx[y][x+1] = ' ';p_yx[y][x+2] = ' ';p_yx[y-1][x] = '5';p_yx[y-1][x+1] = '5';p_yx[y-1][x+2] = '5';p_yx[y-2][x] = '5';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = ' ';peca_em_falta[5]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                                    case 2: if (p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' ' && p_yx[y-3][x-1]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' ' && p_yx[y-3][x+3]== ' ' && p_yx[y-2][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' '){p_yx[y][x] = ' ';p_yx[y][x+1] = '5';p_yx[y][x+2] = ' ';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = '5';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = '5';p_yx[y-2][x+1] = '5';p_yx[y-2][x+2] = '5';peca_em_falta[5]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                                    case 3: if (p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' && p_yx[y+1][x+3]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-2][x+3]== ' ' && p_yx[y-3][x+3]== ' ' && p_yx[y-3][x+2]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' '){p_yx[y][x] = ' ';p_yx[y][x+1] = ' ';p_yx[y][x+2] = '5';p_yx[y-1][x] = '5';p_yx[y-1][x+1] = '5';p_yx[y-1][x+2] = '5';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = '5';peca_em_falta[5]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                            }       
                                    if(tentativa_v>=3){erro_peca=1;tentativa[5]=1;}
                                }while (tentativa_v<3 && e==1 );
                            }

                            else if (selecao_tipo == 6 & peca_em_falta[6] != 0){
                                do{
                                if(e==1){tentativa_v=tentativa_v+1; peca=tentativa_v;e=0;}
                                else{
                                   peca= rand() % 4;
                                   e=0;
                                }
                                   switch(peca){
                                    case 0: if (p_yx[y][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' ' &&  p_yx[y-3][x-1]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' ' && p_yx[y-3][x+3]== ' ' &&  p_yx[y-2][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' ){p_yx[y][x] = ' ';p_yx[y][x+1] = '6';p_yx[y][x+2] = ' ';p_yx[y-1][x] = '6';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = '6';p_yx[y-2][x] = '6';p_yx[y-2][x+1] = '6';p_yx[y-2][x+2] = '6';peca_em_falta[6]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {e=1;} break;
                                    case 1: if (p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' &&  p_yx[y+1][x+3]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' ' &&  p_yx[y-3][x+3]== ' ' && p_yx[y-2][x+3]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' ' ){p_yx[y][x] = ' ';p_yx[y][x+1] = '6';p_yx[y][x+2] = '6';p_yx[y-1][x] = '6';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = '6';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = '6';p_yx[y-2][x+2] = '6';peca_em_falta[6]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {e=1;} break;
                                    case 2: if (p_yx[y-2][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y][x-1]== ' ' &&  p_yx[y+1][x-1]== ' ' && p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' && p_yx[y+1][x+3]== ' ' &&  p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-2][x+3]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' ' ){p_yx[y][x] = '6';p_yx[y][x+1] = '6';p_yx[y][x+2] = '6';p_yx[y-1][x] = '6';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = '6';p_yx[y-2][x] = ' ';p_yx[y-2][x+1] = '6';p_yx[y-2][x+2] = ' ';peca_em_falta[6]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {e=1;} break;
                                    case 3: if (p_yx[y-1][x-1]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y+1][x-1]== ' ' &&  p_yx[y+1][x]== ' ' && p_yx[y+1][x+1]== ' ' && p_yx[y+1][x+2]== ' ' && p_yx[y-2][x-1]== ' ' && p_yx[y-3][x-1]== ' ' && p_yx[y-3][x]== ' ' &&  p_yx[y-3][x+1]== ' ' && p_yx[y-3][x+2]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-2][x+3]== ' ' ){p_yx[y][x] = '6';p_yx[y][x+1] = '6';p_yx[y][x+2] = ' ';p_yx[y-1][x] = '6';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = '6';p_yx[y-2][x] = '6';p_yx[y-2][x+1] = '6';p_yx[y-2][x+2] = ' ';peca_em_falta[6]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {e=1;} break;
                            }       
                                    if(tentativa_v>=3){erro_peca=1;tentativa[6]=1;}
                                }while (tentativa_v<3 && e==1 );
                            }

                            else if (selecao_tipo == 7 & peca_em_falta[7] != 0){
                                do{
                                if(e==1){tentativa_v=tentativa_v+1; peca=tentativa_v;e=0;}
                                else{
                                   peca= rand() % 2;
                                   e=0;
                                }
                                   switch(peca){
                                    case 0: if (p_yx[y+1][x+1]== ' ' && p_yx[y+1][x]== ' ' && p_yx[y+1][x-1]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' ' && p_yx[y-3][x-1]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y+1][x+2]== ' ' && p_yx[y+1][x+3]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-2][x+3]== ' ' && p_yx[y-3][x+3]== ' ' && p_yx[y-3][x+2]== ' ' ){p_yx[y][x] = '7';p_yx[y][x+1] = ' ';p_yx[y][x+2] = '7';p_yx[y-1][x] = '7';p_yx[y-1][x+1] = '7';p_yx[y-1][x+2] = '7';p_yx[y-2][x] = '7';p_yx[y-2][x+1] = ' ';p_yx[y-2][x+2] = '7';peca_em_falta[7]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                                    case 1: if (p_yx[y+1][x+1]== ' ' && p_yx[y+1][x]== ' ' && p_yx[y+1][x-1]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' ' && p_yx[y-3][x-1]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y+1][x+2]== ' ' && p_yx[y+1][x+3]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-2][x+3]== ' ' && p_yx[y-3][x+3]== ' ' && p_yx[y-3][x+2]== ' ' ){p_yx[y][x] = '7';p_yx[y][x+1] = '7';p_yx[y][x+2] = '7';p_yx[y-1][x] = ' ';p_yx[y-1][x+1] = '7';p_yx[y-1][x+2] = ' ';p_yx[y-2][x] = '7';p_yx[y-2][x+1] = '7';p_yx[y-2][x+2] = '7';peca_em_falta[7]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                            }       
                                    if(tentativa_v>=2){erro_peca=1;tentativa[7]=1;}
                                }while (tentativa_v<2 && e==1 );
                            }

                            else if (selecao_tipo == 8 & peca_em_falta[8] != 0){
                                    if (p_yx[y+1][x+1]== ' ' && p_yx[y+1][x]== ' ' && p_yx[y+1][x-1]== ' ' && p_yx[y][x-1]== ' ' && p_yx[y-1][x-1]== ' ' && p_yx[y-2][x-1]== ' ' && p_yx[y-3][x-1]== ' ' && p_yx[y-3][x]== ' ' && p_yx[y-3][x+1]== ' ' && p_yx[y+1][x+2]== ' ' && p_yx[y+1][x+3]== ' ' && p_yx[y][x+3]== ' ' && p_yx[y-1][x+3]== ' ' && p_yx[y-2][x+3]== ' ' && p_yx[y-3][x+3]== ' ' && p_yx[y-3][x+2]== ' ' ){p_yx[y][x] = '8';p_yx[y][x+1] = '8';p_yx[y][x+2] = '8';p_yx[y-1][x] = '8';p_yx[y-1][x+1] = ' ';p_yx[y-1][x+2] = '8';p_yx[y-2][x] = '8';p_yx[y-2][x+1] = '8';p_yx[y-2][x+2] = '8';peca_em_falta[8]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {erro_peca=1;tentativa[8]=1;} 
                            } 
                            
                            else{erro_peca=1;}
                            }
                        }while(erro_peca==1 & erro_tabuleiro==0);  

                }while(x< dim_tabu_x - 2 & erro_tabuleiro==0 );
            }while(y>3 & erro_tabuleiro==0 );
        }while(novo_tabuleiro_count<1000 & erro_tabuleiro==1);
        
        if(novo_tabuleiro_count==1000){printf("\nErro -1\n");exit(0);}
    }   

    void modo_d1(){}


    void modo_d2(){}


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
        printf("\n");
    }

    void print_pecas(){
        printf("\nPeças(1) = %d    Peças(2) = %d    Peças(3) = %d    Peças(4) = %d    Peças(5) = %d    Peças(6) = %d    Peças(7) = %d    Peças(8) = %d\n",peca_n[1],peca_n[2],peca_n[3],peca_n[4],peca_n[5],peca_n[6],peca_n[7],peca_n[8]);
    }
    
    void print_dimensao(){
        printf("\nDimensão = %d x %d \n",dim_tabu_y,dim_tabu_x);
    }


    void print_logo(){
        printf("\n █▀▀▄ █▀▀█ ▀▀█▀▀ █▀▀█ █   █  █ █▀▀█    █▀▀▄ █▀▀█ ▀█ █▀ █▀▀█ █\n █▀▀▄ █▄▄█   █   █▄▄█ █   █▀▀█ █▄▄█    █  █ █▄▄█  █▄█  █▄▄█ █\n ▀▀▀  ▀  ▀   ▀   ▀  ▀ ▀▀▀ ▀  ▀ ▀  ▀    ▀  ▀ ▀  ▀   ▀   ▀  ▀ ▀▀▀\n\n");
        switch(modo_jogo){
            case 0 :
            printf("                    █▀▄▀█ █▀█ █▀▄ █▀█   █▀█\n                    █ ▀ █ █▄█ █▄▀ █▄█   █▄█\n\n"); 
            break;
            case 1 :
            printf("                    █▀▄▀█ █▀█ █▀▄ █▀█   ▄█\n                    █ ▀ █ █▄█ █▄▀ █▄█    █\n\n"); 
            break;
            case 2 :
            printf("                    █▀▄▀█ █▀█ █▀▄ █▀█   ▀█\n                    █ ▀ █ █▄█ █▄▀ █▄█   █▄\n\n"); 
            break;
            case 3 :
            printf("               █ █▄ █ █▀ ▀█▀ █▀█ █ █ █▀▀ █▀█ █▀▀ █▀\n               █ █ ▀█ ▄█  █  █▀▄ █▄█ █▄▄ █▄█ ██▄ ▄█\n\n");
            break;
        }
    }
    