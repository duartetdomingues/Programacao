#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define DEFAULT_JOGO 0
#define DEFAULT_POS 1
#define DEFAULT_DIS 1
#define DEFAULT_DIM_TABU_X 9
#define DEFAULT_DIM_TABU_Y 9

void main_menu() ;
void modo_j0();
void modo_j1();
void modo_j2();
void instrucoes();
void modo_p1();
void modo_p2();
void modo_d1();
void modo_d2_3();
void print_tabu();
void print_logo();
void print_modo_x();
void print_pecas();
void print_dimensao();

int modo_jogo = DEFAULT_JOGO, modo_pos = DEFAULT_POS,modo_dis=DEFAULT_DIS,dim_tabu_x=DEFAULT_DIM_TABU_X,dim_tabu_y=DEFAULT_DIM_TABU_Y,peca_n[9]={0,0,0,0,0,0,0,0,0},peca_totais;
int novamente=0;

char yx[17][26]=
    {{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'}};




time_t t;

    int main( int argc, char *argv[] ){
        int option = 'h',k;
        //system("clear");   //tirar // é so para ver se existem erros
        while ((option= getopt(argc, argv, "ht:j:p:d:1:2:3:4:5:6:7:8:")) != -1){
            switch(option){
                case 'h':instrucoes();break;
                case 't':sscanf(optarg, "%dx%d", &dim_tabu_y,&dim_tabu_x);if(dim_tabu_x % 3 | dim_tabu_x<9 | dim_tabu_x>24 | dim_tabu_y % 3 | dim_tabu_y<9 | dim_tabu_y>15 ){dim_tabu_x=DEFAULT_DIM_TABU_X;dim_tabu_y=DEFAULT_DIM_TABU_Y;}break;
                case 'j':sscanf(optarg, "%d", &modo_jogo);break;
                case 'p':sscanf(optarg, "%d", &modo_pos);break;
                case 'd':sscanf(optarg, "%d", &modo_dis);if(modo_jogo==1){instrucoes();}break;
                case '1':sscanf(optarg, "%d", &peca_n[1]);if(modo_pos==1 && modo_jogo!=2){instrucoes();}break;
                case '2':sscanf(optarg, "%d", &peca_n[2]);if(modo_pos==1 && modo_jogo!=2){instrucoes();}break;
                case '3':sscanf(optarg, "%d", &peca_n[3]);if(modo_pos==1 && modo_jogo!=2){instrucoes();}break;
                case '4':sscanf(optarg, "%d", &peca_n[4]);if(modo_pos==1 && modo_jogo!=2){instrucoes();}break;
                case '5':sscanf(optarg, "%d", &peca_n[5]);if(modo_pos==1 && modo_jogo!=2){instrucoes();}break;
                case '6':sscanf(optarg, "%d", &peca_n[6]);if(modo_pos==1 && modo_jogo!=2){instrucoes();}break;
                case '7':sscanf(optarg, "%d", &peca_n[7]);if(modo_pos==1 && modo_jogo!=2){instrucoes();}break;
                case '8':sscanf(optarg, "%d", &peca_n[8]);if(modo_pos==1 && modo_jogo!=2){instrucoes();}break;
            }
        }

        for (k=2;k<=8;k++){
            if(peca_n[k]>peca_n[k-1]){instrucoes();}
        }
        if (((dim_tabu_y*dim_tabu_x)/9)<(peca_n[1]+peca_n[2]+peca_n[3]+peca_n[4]+peca_n[5]+peca_n[6]+peca_n[7]+peca_n[8])){instrucoes();}

        switch(modo_jogo){
            case 0:modo_j0();break;
            case 1:modo_j1();break;
            case 2:modo_j2();break; 
            default:return(1);break;}
        return(0);  
    }

    void modo_j0(){
        switch(modo_pos){
            case 1:modo_p1();break; 
            case 2:modo_p2();break;
            default: exit(1);break;
        }
        print_dimensao();
        print_pecas();
        print_tabu();
    
    }

    void modo_j1(){

        switch(modo_pos){
            case 1:modo_p1();break; 
            case 2:modo_p2();break;
            default: exit(1);break;
        }

        time_t time_i = time(NULL);
        char  char_x, d_yx[17][26]={0};
        int x,y=0,j ,k,t_pecas,i_pecas,erro=0,i,tentativa_d=0;

        t_pecas = peca_n[1] + peca_n[2]*2 + peca_n[3]*3 + peca_n[4]*4 + peca_n[5]*5 + peca_n[6]*6 + peca_n[7]*7 + peca_n[8]*8;
        /* apagar */print_tabu();
        print_logo();
        print_dimensao();
        print_pecas();
        do{
            erro=0;
            scanf(" %c%d",&char_x,&y);           
            if (char_x<65 | (char_x > dim_tabu_x + 64 & char_x<96) | char_x > dim_tabu_x + 96 | y<=0 | y > dim_tabu_y ){char dummy[256];scanf(" %s",dummy);printf("Erro!!\n");erro=1;}
            else{
                if(char_x <= dim_tabu_x + 64){x= char_x - 64;}
                else{x= char_x - 96;}
                printf("%c\n",yx[y][x]);
                d_yx[y][x]=yx[y][x];
                j=0;k=0;
                tentativa_d++;
                i_pecas=0;
                for(j=0;j<=dim_tabu_y;j++){
                    for(k=0;k<=dim_tabu_x;k++){
                        if(d_yx[j][k] != 0   &  yx[j][k] != '-'){i_pecas++;}}}
            }
        }while(i_pecas != t_pecas | erro==1 );
        time_t time_f = time(NULL);
        time_t time_spent= (time_f - time_i);
        printf("Fim de Jogo: %d jogadas em %ld segundos\n",tentativa_d,time_spent);
        print_tabu();
    }
            
    void modo_j2(){
        int  n_pecas_escolhidas;
        n_pecas_escolhidas= peca_n[1]+peca_n[2]+peca_n[3]+peca_n[4]+peca_n[5]+peca_n[6]+peca_n[7]+peca_n[8];
        peca_n[0]= ((dim_tabu_x*dim_tabu_y)/9) - n_pecas_escolhidas;

        print_logo();
        print_dimensao();
        print_pecas();
        switch(modo_dis){
            case 1:modo_d1(); break; 
            case 2:modo_d2_3(); break;
            case 3:modo_d2_3(); break;
            default:instrucoes();break;
        }
        print_tabu();
         
    }

    void instrucoes(){
        //system("clear");
        printf("Instruções:\n"); 
        printf(" 🔲 ..........\n");
        printf(" 🔲 ..........\n");
        exit(0);

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
                        case 0:yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_n[0]++; break;
                        
                        case 1: if (yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' &&  yx[y+1][x]== '-' && yx[y+1][x+1]== '-'){yx[y][x] = '1';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-'; peca_n[1]++;} else {tentativa=tentativa+1;  e=1;} break;
                        case 2: if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-'){yx[y][x] = '-';yx[y][x+1] = '1';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_n[1]++;} else {tentativa=tentativa+1;  e=1;} break;
                        case 3: if (yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-'){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '1';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_n[1]++;} else {tentativa=tentativa+1;  e=1;} break;
                        case 4: if (yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-'){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '1';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_n[1]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 5: yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '1';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_n[1]++;break;
                        case 6: if (yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-'){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '1';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_n[1]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 7: if (yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-'){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '1';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_n[1]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 8: if (yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-'){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '1';yx[y-2][x+2] = '-';peca_n[1]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 9: if (yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-'){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '1';peca_n[1]++;}else {tentativa=tentativa+1;  e=1;} break;
                        
                        case 10:if (yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' &&  yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' ){yx[y][x] = '2';yx[y][x+1] = '2';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 11:if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' &&  yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' ){yx[y][x] = '-';yx[y][x+1] = '2';yx[y][x+2] = '2';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 12:if (yx[y-2][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y][x-1]== '-' ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '2';yx[y-1][x+1] = '2';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 13:if (yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y][x+3]== '-' ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '2';yx[y-1][x+2] = '2';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 14:if (yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' &&  yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '2';yx[y-2][x+1] = '2';yx[y-2][x+2] = '-';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 15:if (yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' &&  yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '2';yx[y-2][x+2] = '2';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 16:if (yx[y-2][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y][x-1]== '-' &&  yx[y+1][x-1]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' ){yx[y][x] = '2';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '2';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 17:if (yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' &&  yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '2';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '2';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 18:if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' ){yx[y][x] = '-';yx[y][x+1] = '2';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '2';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 19:if (yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '2';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '2';yx[y-2][x+2] = '-';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 20:if (yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' &&  yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '2';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '2';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;
                        case 21:if (yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' &&  yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y][x+3]== '-' ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '2';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '2';peca_n[2]++;} else { tentativa=tentativa+1;  e=1;} break;

                        case 22: if (yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-'){yx[y][x] = '3';yx[y][x+1] = '3';yx[y][x+2] = '3';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_n[3]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 23: if (yx[y-2][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '3';yx[y-1][x+1] = '3';yx[y-1][x+2] = '3';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_n[3]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 24: if (yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-'){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '3';yx[y-2][x+1] = '3';yx[y-2][x+2] = '3';peca_n[3]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 25: if (yx[y+1][x+1]== '-' && yx[y+1][x]== '-' && yx[y+1][x-1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-'){yx[y][x] = '3';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '3';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '3';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_n[3]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 26: if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-'){yx[y][x] = '-';yx[y][x+1] = '3';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '3';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '3';yx[y-2][x+2] = '-';peca_n[3]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 27: if (yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x+3]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+1]== '-'){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '3';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '3';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '3';peca_n[3]++;}else {tentativa=tentativa+1;  e=1;} break;
                        
                        case 28: if (yx[y-2][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-'){yx[y][x] = '4';yx[y][x+1] = '4';yx[y][x+2] = '-';yx[y-1][x] = '4';yx[y-1][x+1] = '4';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_n[4]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 29: if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-'){yx[y][x] = '-';yx[y][x+1] = '4';yx[y][x+2] = '4';yx[y-1][x] = '-';yx[y-1][x+1] = '4';yx[y-1][x+2] = '4';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_n[4]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 30: if (yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-'){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '4';yx[y-1][x+1] = '4';yx[y-1][x+2] = '-';yx[y-2][x] = '4';yx[y-2][x+1] = '4';yx[y-2][x+2] = '-';peca_n[4]++;}else {tentativa=tentativa+1;  e=1;} break;
                        case 31: if (yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y][x+3]== '-'){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '4';yx[y-1][x+2] = '4';yx[y-2][x] = '-';yx[y-2][x+1] = '4';yx[y-2][x+2] = '4';peca_n[4]++;}else {tentativa=tentativa+1;  e=1;} break;

                        case 32: if (yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-'){yx[y][x] = '5';yx[y][x+1] = '5';yx[y][x+2] = '5';yx[y-1][x] = '-';yx[y-1][x+1] = '5';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '5';yx[y-2][x+2] = '-';peca_n[5]++;}else {tentativa=tentativa+1; e=1;} break;
                        case 33: if (yx[y+1][x+1]== '-' && yx[y+1][x]== '-' && yx[y+1][x-1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-'  && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-'){yx[y][x] = '5';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '5';yx[y-1][x+1] = '5';yx[y-1][x+2] = '5';yx[y-2][x] = '5';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_n[5]++;}else {tentativa=tentativa+1; e=1;} break;
                        case 34: if (yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-'){yx[y][x] = '-';yx[y][x+1] = '5';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '5';yx[y-1][x+2] = '-';yx[y-2][x] = '5';yx[y-2][x+1] = '5';yx[y-2][x+2] = '5';peca_n[5]++;}else {tentativa=tentativa+1; e=1;} break;
                        case 35: if (yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x+3]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-'){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '5';yx[y-1][x] = '5';yx[y-1][x+1] = '5';yx[y-1][x+2] = '5';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '5';peca_n[5]++;}else {tentativa=tentativa+1; e=1;} break;

                        case 36: if (yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' &&  yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' &&  yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y][x+3]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-'){yx[y][x] = '-';yx[y][x+1] = '6';yx[y][x+2] = '-';yx[y-1][x] = '6';yx[y-1][x+1] = '-';yx[y-1][x+2] = '6';yx[y-2][x] = '6';yx[y-2][x+1] = '6';yx[y-2][x+2] = '6';peca_n[6]++;} else {tentativa=tentativa+1; e=1;} break;
                        case 37: if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' &&  yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' &&  yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-'){yx[y][x] = '-';yx[y][x+1] = '6';yx[y][x+2] = '6';yx[y-1][x] = '6';yx[y-1][x+1] = '-';yx[y-1][x+2] = '6';yx[y-2][x] = '-';yx[y-2][x+1] = '6';yx[y-2][x+2] = '6';peca_n[6]++;} else { tentativa=tentativa+1; e=1;} break;
                        case 38: if (yx[y-2][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y][x-1]== '-' &&  yx[y+1][x-1]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' &&  yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-'){yx[y][x] = '6';yx[y][x+1] = '6';yx[y][x+2] = '6';yx[y-1][x] = '6';yx[y-1][x+1] = '-';yx[y-1][x+2] = '6';yx[y-2][x] = '-';yx[y-2][x+1] = '6';yx[y-2][x+2] = '-';peca_n[6]++;} else { tentativa=tentativa+1; e=1;} break;
                        case 39: if (yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' &&  yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' &&  yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-'){yx[y][x] = '6';yx[y][x+1] = '6';yx[y][x+2] = '-';yx[y-1][x] = '6';yx[y-1][x+1] = '-';yx[y-1][x+2] = '6';yx[y-2][x] = '6';yx[y-2][x+1] = '6';yx[y-2][x+2] = '-';peca_n[6]++;} else { tentativa=tentativa+1; e=1;} break;

                        case 40: if (yx[y+1][x+1]== '-' && yx[y+1][x]== '-' && yx[y+1][x-1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x+3]== '-' && yx[y-3][x+2]== '-'){yx[y][x] = '7';yx[y][x+1] = '-';yx[y][x+2] = '7';yx[y-1][x] = '7';yx[y-1][x+1] = '7';yx[y-1][x+2] = '7';yx[y-2][x] = '7';yx[y-2][x+1] = '-';yx[y-2][x+2] = '7';peca_n[7]++;}else {tentativa=tentativa+1; e=1;} break;
                        case 41: if (yx[y+1][x+1]== '-' && yx[y+1][x]== '-' && yx[y+1][x-1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x+3]== '-' && yx[y-3][x+2]== '-'){yx[y][x] = '7';yx[y][x+1] = '7';yx[y][x+2] = '7';yx[y-1][x] = '-';yx[y-1][x+1] = '7';yx[y-1][x+2] = '-';yx[y-2][x] = '7';yx[y-2][x+1] = '7';yx[y-2][x+2] = '7';peca_n[7]++;}else {tentativa=tentativa+1; e=1;} break;

                        case 42: if (yx[y+1][x+1]== '-' && yx[y+1][x]== '-' && yx[y+1][x-1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x+3]== '-' && yx[y-3][x+2]== '-'){yx[y][x] = '8';yx[y][x+1] = '8';yx[y][x+2] = '8';yx[y-1][x] = '8';yx[y-1][x+1] = '-';yx[y-1][x+2] = '8';yx[y-2][x] = '8';yx[y-2][x+1] = '8';yx[y-2][x+2] = '8';peca_n[8]++;}else {tentativa=tentativa+1; e=1;} break;
                        default: e=1;break;
                        }
                    }
                    else {yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '1';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_n[1]++;
                    }
                }while (e !=0);
            }while(x< dim_tabu_x - 2);
        }while(y>3);

        //posicionar peças da forma p1
    }

    void modo_p2(){
        int n_pecas_escolhidas,n_pecas_max,m,matriz_x, matriz_y, x, y, selecao_tipo, peca, tentativa_v,f=0,tentativa[9]={0,0,0,0,0,0,0,0,0}, n_pecas_colocadas=0, novo_tabuleiro_count=0, erro_tabuleiro, erro_peca=0, e=0, peca_em_falta[9]={0,0,0,0,0,0,0,0,0};
        n_pecas_escolhidas= peca_n[1]+peca_n[2]+peca_n[3]+peca_n[4]+peca_n[5]+peca_n[6]+peca_n[7]+peca_n[8];
        n_pecas_max=((dim_tabu_x*dim_tabu_y)/9)/2;
        if (n_pecas_escolhidas>n_pecas_max){instrucoes();}
        peca_n[0]= ((dim_tabu_x*dim_tabu_y)/9) - n_pecas_escolhidas;
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
                 for(m=0;m<=8;m++){tentativa[m]=0;}
                 matriz_x=matriz_x+1;
                 x=1+(matriz_x*3);
                 tentativa_v=-1; 
                    do{ erro_peca=0;
                        selecao_tipo= rand() % 9;
                            
                        if ( (peca_em_falta[0]==0 | tentativa[0]==1) & (peca_em_falta[1]==0 | tentativa[1]==1) & (peca_em_falta[2]==0 | tentativa[2]==1) & (peca_em_falta[3]==0 | tentativa[3]==1) & (peca_em_falta[4]==0 | tentativa[4]==1) & (peca_em_falta[5]==0 | tentativa[5]==1) &(peca_em_falta[6]==0 | tentativa[6]==1) &(peca_em_falta[7]==0 | tentativa[7]==1) & (peca_em_falta[8]==0 | tentativa[8]==1) ){novo_tabuleiro_count++;erro_tabuleiro=1;}
                        if (tentativa[selecao_tipo]==1){erro_peca=1;}
                        else{
                            if(selecao_tipo==0 & peca_em_falta[0] != 0){
                                yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_em_falta[0]--; e=0; (n_pecas_colocadas = n_pecas_colocadas + 1);
                            }
                            else if (selecao_tipo == 1 & peca_em_falta[1] != 0){
                                do{ 
                                    if(e==1){tentativa_v=tentativa_v+1; peca=tentativa_v;e=0;}
                                    else{peca= rand() % 9;e=0;}
                                    switch(peca){
                                        case 0: if (yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' &&  yx[y+1][x]== '-' && yx[y+1][x+1]== '-' ){yx[y][x] = '1';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-'; peca_em_falta[1]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {e=1;} break;
                                        case 1: if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' ){yx[y][x] = '-';yx[y][x+1] = '1';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_em_falta[1]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else { e=1;} break;
                                        case 2: if (yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '1';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_em_falta[1]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {e=1;} break;
                                        case 3: if (yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '1';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_em_falta[1]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                                        case 4: yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '1';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_em_falta[1]--;(n_pecas_colocadas = n_pecas_colocadas + 1);break;
                                        case 5: if (yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '1';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_em_falta[1]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                                        case 6: if (yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '1';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_em_falta[1]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                                        case 7: if (yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '1';yx[y-2][x+2] = '-';peca_em_falta[1]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                                        case 8: if (yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '1';peca_em_falta[1]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                                    }
                                    if(tentativa_v>=8){erro_peca=1;tentativa[1]=1;}
                                }while (tentativa_v<8 && e==1 );
                            }
                            else if (selecao_tipo == 2 & peca_em_falta[2] != 0){
                                do{
                                    if(e==1){tentativa_v=tentativa_v+1; peca=tentativa_v;e=0;}
                                    else{peca= rand() % 12;e=0;}
                                    switch(peca){
                                        case 0:if (yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' &&  yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-'  ){yx[y][x] = '2';yx[y][x+1] = '2';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_em_falta[2]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {   e=1;} break;
                                        case 1:if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' &&  yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-'   ){yx[y][x] = '-';yx[y][x+1] = '2';yx[y][x+2] = '2';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_em_falta[2]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {   e=1;} break;
                                        case 2:if (yx[y-2][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y][x-1]== '-'  ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '2';yx[y-1][x+1] = '2';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_em_falta[2]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {   e=1;} break;
                                        case 3:if (yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y][x+3]== '-'  ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '2';yx[y-1][x+2] = '2';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_em_falta[2]--;(n_pecas_colocadas = n_pecas_colocadas + 1);;} else {   e=1;} break;
                                        case 4:if (yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' &&  yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-'  ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '2';yx[y-2][x+1] = '2';yx[y-2][x+2] = '-';peca_em_falta[2]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {   e=1;} break;
                                        case 5:if (yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' &&  yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-'   ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '2';yx[y-2][x+2] = '2';peca_em_falta[2]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {   e=1;} break;
                                        case 6:if (yx[y-2][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y][x-1]== '-' &&  yx[y+1][x-1]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-'  ){yx[y][x] = '2';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '2';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_em_falta[2]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {   e=1;} break;
                                        case 7:if (yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' &&  yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-'  ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '2';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '2';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_em_falta[2]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {   e=1;} break;
                                        case 8:if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-'  ){yx[y][x] = '-';yx[y][x+1] = '2';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '2';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_em_falta[2]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {e=1;} break;
                                        case 9:if (yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-'  ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '2';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '2';yx[y-2][x+2] = '-';peca_em_falta[2]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {e=1;} break;
                                        case 10:if (yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' &&  yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-'  ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '2';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '2';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_em_falta[2]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {   e=1;} break;
                                        case 11:if (yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' &&  yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y][x+3]== '-'  ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '2';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '2';peca_em_falta[2]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {   e=1;} break;
                                    }
                                    if(tentativa_v>=11){erro_peca=1;tentativa[2]=1;}
                                }while (tentativa_v<11 && e==1 );  
                            }

                            else if (selecao_tipo == 3 & peca_em_falta[3] != 0){
                                do{
                                    if(e==1){tentativa_v=tentativa_v+1; peca=tentativa_v;e=0;}
                                    else{peca= rand() % 6; e=0;}
                                    switch(peca){
                                        case 0: if (yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' ){yx[y][x] = '3';yx[y][x+1] = '3';yx[y][x+2] = '3';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_em_falta[3]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {  e=1;} break;
                                        case 1: if (yx[y-2][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '3';yx[y-1][x+1] = '3';yx[y-1][x+2] = '3';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_em_falta[3]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {  e=1;} break;
                                        case 2: if (yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '3';yx[y-2][x+1] = '3';yx[y-2][x+2] = '3';peca_em_falta[3]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {  e=1;} break;
                                        case 3: if (yx[y+1][x+1]== '-' && yx[y+1][x]== '-' && yx[y+1][x-1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-'){yx[y][x] = '3';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '3';yx[y-1][x+1] = '-';yx[y-1][x+2] = '-';yx[y-2][x] = '3';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_em_falta[3]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {  e=1;} break;
                                        case 4: if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' ){yx[y][x] = '-';yx[y][x+1] = '3';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '3';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '3';yx[y-2][x+2] = '-';peca_em_falta[3]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {  e=1;} break;
                                        case 5: if (yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x+3]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+1]== '-' ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '3';yx[y-1][x] = '-';yx[y-1][x+1] = '-';yx[y-1][x+2] = '3';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '3';peca_em_falta[3]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {  e=1;} break;
                                    }       
                                    if(tentativa_v>=5){erro_peca=1;tentativa[3]=1;}
                                }while (tentativa_v<5 && e==1 );
                            }

                            else if (selecao_tipo == 4 & peca_em_falta[4] != 0){
                                do{
                                    if(e==1){tentativa_v=tentativa_v+1; peca=tentativa_v;e=0;}
                                    else{peca= rand() % 4;e=0;} 
                                    switch(peca){
                                        case 0: if (yx[y-2][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' ){yx[y][x] = '4';yx[y][x+1] = '4';yx[y][x+2] = '-';yx[y-1][x] = '4';yx[y-1][x+1] = '4';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_em_falta[4]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                                        case 1: if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' ){yx[y][x] = '-';yx[y][x+1] = '4';yx[y][x+2] = '4';yx[y-1][x] = '-';yx[y-1][x+1] = '4';yx[y-1][x+2] = '4';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_em_falta[4]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                                        case 2: if (yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '4';yx[y-1][x+1] = '4';yx[y-1][x+2] = '-';yx[y-2][x] = '4';yx[y-2][x+1] = '4';yx[y-2][x+2] = '-';peca_em_falta[4]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                                        case 3: if (yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y][x+3]== '-' ){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '4';yx[y-1][x+2] = '4';yx[y-2][x] = '-';yx[y-2][x+1] = '4';yx[y-2][x+2] = '4';peca_em_falta[4]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                                    }       
                                    if(tentativa_v>=3){erro_peca=1;tentativa[4]=1;}
                                }while (tentativa_v<3 && e==1 );
                            }

                            else if (selecao_tipo == 5 & peca_em_falta[5] != 0){
                                do{
                                    if(e==1){tentativa_v=tentativa_v+1; peca=tentativa_v;e=0;}
                                    else{peca= rand() % 4;e=0;}
                                    switch(peca){
                                        case 0: if (yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-'){yx[y][x] = '5';yx[y][x+1] = '5';yx[y][x+2] = '5';yx[y-1][x] = '-';yx[y-1][x+1] = '5';yx[y-1][x+2] = '-';yx[y-2][x] = '-';yx[y-2][x+1] = '5';yx[y-2][x+2] = '-';peca_em_falta[5]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else { e=1;} break;
                                        case 1: if (yx[y+1][x+1]== '-' && yx[y+1][x]== '-' && yx[y+1][x-1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-'  && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-'){yx[y][x] = '5';yx[y][x+1] = '-';yx[y][x+2] = '-';yx[y-1][x] = '5';yx[y-1][x+1] = '5';yx[y-1][x+2] = '5';yx[y-2][x] = '5';yx[y-2][x+1] = '-';yx[y-2][x+2] = '-';peca_em_falta[5]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                                        case 2: if (yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-'){yx[y][x] = '-';yx[y][x+1] = '5';yx[y][x+2] = '-';yx[y-1][x] = '-';yx[y-1][x+1] = '5';yx[y-1][x+2] = '-';yx[y-2][x] = '5';yx[y-2][x+1] = '5';yx[y-2][x+2] = '5';peca_em_falta[5]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                                        case 3: if (yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x+3]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-'){yx[y][x] = '-';yx[y][x+1] = '-';yx[y][x+2] = '5';yx[y-1][x] = '5';yx[y-1][x+1] = '5';yx[y-1][x+2] = '5';yx[y-2][x] = '-';yx[y-2][x+1] = '-';yx[y-2][x+2] = '5';peca_em_falta[5]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                                    }       
                                    if(tentativa_v>=3){erro_peca=1;tentativa[5]=1;}
                                }while (tentativa_v<3 && e==1 );
                            }

                            else if (selecao_tipo == 6 & peca_em_falta[6] != 0){
                                do{
                                if(e==1){tentativa_v=tentativa_v+1; peca=tentativa_v;e=0;}
                                else{peca= rand() % 4;e=0;}
                                    switch(peca){
                                        case 0: if (yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' &&  yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y-3][x+3]== '-' &&  yx[y-2][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y][x+3]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' ){yx[y][x] = '-';yx[y][x+1] = '6';yx[y][x+2] = '-';yx[y-1][x] = '6';yx[y-1][x+1] = '-';yx[y-1][x+2] = '6';yx[y-2][x] = '6';yx[y-2][x+1] = '6';yx[y-2][x+2] = '6';peca_em_falta[6]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {e=1;} break;
                                        case 1: if (yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' &&  yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' &&  yx[y-3][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' ){yx[y][x] = '-';yx[y][x+1] = '6';yx[y][x+2] = '6';yx[y-1][x] = '6';yx[y-1][x+1] = '-';yx[y-1][x+2] = '6';yx[y-2][x] = '-';yx[y-2][x+1] = '6';yx[y-2][x+2] = '6';peca_em_falta[6]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {e=1;} break;
                                        case 2: if (yx[y-2][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y][x-1]== '-' &&  yx[y+1][x-1]== '-' && yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' &&  yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' ){yx[y][x] = '6';yx[y][x+1] = '6';yx[y][x+2] = '6';yx[y-1][x] = '6';yx[y-1][x+1] = '-';yx[y-1][x+2] = '6';yx[y-2][x] = '-';yx[y-2][x+1] = '6';yx[y-2][x+2] = '-';peca_em_falta[6]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {e=1;} break;
                                        case 3: if (yx[y-1][x-1]== '-' && yx[y][x-1]== '-' && yx[y+1][x-1]== '-' &&  yx[y+1][x]== '-' && yx[y+1][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' &&  yx[y-3][x+1]== '-' && yx[y-3][x+2]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' ){yx[y][x] = '6';yx[y][x+1] = '6';yx[y][x+2] = '-';yx[y-1][x] = '6';yx[y-1][x+1] = '-';yx[y-1][x+2] = '6';yx[y-2][x] = '6';yx[y-2][x+1] = '6';yx[y-2][x+2] = '-';peca_em_falta[6]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {e=1;} break;
                                    }       
                                    if(tentativa_v>=3){erro_peca=1;tentativa[6]=1;}
                                }while (tentativa_v<3 && e==1 );
                            }

                            else if (selecao_tipo == 7 & peca_em_falta[7] != 0){
                                do{
                                if(e==1){tentativa_v=tentativa_v+1; peca=tentativa_v;e=0;}
                                else{peca= rand() % 2;e=0;}
                                   switch(peca){
                                        case 0: if (yx[y+1][x+1]== '-' && yx[y+1][x]== '-' && yx[y+1][x-1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x+3]== '-' && yx[y-3][x+2]== '-' ){yx[y][x] = '7';yx[y][x+1] = '-';yx[y][x+2] = '7';yx[y-1][x] = '7';yx[y-1][x+1] = '7';yx[y-1][x+2] = '7';yx[y-2][x] = '7';yx[y-2][x+1] = '-';yx[y-2][x+2] = '7';peca_em_falta[7]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                                        case 1: if (yx[y+1][x+1]== '-' && yx[y+1][x]== '-' && yx[y+1][x-1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x+3]== '-' && yx[y-3][x+2]== '-' ){yx[y][x] = '7';yx[y][x+1] = '7';yx[y][x+2] = '7';yx[y-1][x] = '-';yx[y-1][x+1] = '7';yx[y-1][x+2] = '-';yx[y-2][x] = '7';yx[y-2][x+1] = '7';yx[y-2][x+2] = '7';peca_em_falta[7]--;(n_pecas_colocadas = n_pecas_colocadas + 1);}else {e=1;} break;
                                    }       
                                    if(tentativa_v>=2){erro_peca=1;tentativa[7]=1;}
                                }while (tentativa_v<2 && e==1 );
                            }

                            else if (selecao_tipo == 8 & peca_em_falta[8] != 0){
                                if (yx[y+1][x+1]== '-' && yx[y+1][x]== '-' && yx[y+1][x-1]== '-' && yx[y][x-1]== '-' && yx[y-1][x-1]== '-' && yx[y-2][x-1]== '-' && yx[y-3][x-1]== '-' && yx[y-3][x]== '-' && yx[y-3][x+1]== '-' && yx[y+1][x+2]== '-' && yx[y+1][x+3]== '-' && yx[y][x+3]== '-' && yx[y-1][x+3]== '-' && yx[y-2][x+3]== '-' && yx[y-3][x+3]== '-' && yx[y-3][x+2]== '-' ){yx[y][x] = '8';yx[y][x+1] = '8';yx[y][x+2] = '8';yx[y-1][x] = '8';yx[y-1][x+1] = '-';yx[y-1][x+2] = '8';yx[y-2][x] = '8';yx[y-2][x+1] = '8';yx[y-2][x+2] = '8';peca_em_falta[8]--;(n_pecas_colocadas = n_pecas_colocadas + 1);} else {erro_peca=1;tentativa[8]=1;} 
                            } 

                            else{erro_peca=1;}
                        }
                    }while(erro_peca==1 & erro_tabuleiro==0);  

                }while(x< dim_tabu_x - 2 & erro_tabuleiro==0 );
            }while(y>3 & erro_tabuleiro==0 );
        }while(novo_tabuleiro_count<1000 & erro_tabuleiro==1);
        
        if(novo_tabuleiro_count==1000){printf("\nErro -1\n");exit(0);}
    }   

    void modo_d1(){
    }

    void modo_d2_3(){
        
        int matriz_x, matriz_y, x, y, disparo=0, disparos_peca[9]={0,0,0,0,0,0,0,0,0}, e, f, n_pecas[9]={0,0,0,0,0,0,0,0,0}, erro=0;
        char d_yx[17][26]={0};
        
        char x_alfa = '0';

        dim_tabu_x = 9;
        dim_tabu_y = 9;
        matriz_y=-1;
            
        do{ 
            matriz_x=-1;
            matriz_y=matriz_y+1;
            y=dim_tabu_y-(matriz_y*3);
            
            do{
                for(f=0;f<8;f++){
                    disparos_peca[f]=0;
                }
                matriz_x=(matriz_x)+1;
                x=1+(matriz_x*3);
                    //printf("(x,y)= (%d,%d)\n", x, y);
                    do{
                    if(disparos_peca[1] < 1 & disparos_peca[2] < 2 & disparos_peca[3] < 3 & disparos_peca[4] < 4 & disparos_peca[5] < 5 & disparos_peca[6] < 6 & disparos_peca[7] < 7 & disparos_peca[8] < 8 ){
                    if(erro==0){x_alfa = x + 1 + '@';}
                    erro=0;
                    printf("%c%d\n", x_alfa, (y-1));
                    scanf(" %c", &(yx[y-1][x+1]));
                    if ((yx[y-1][x+1])<49 & (yx[y-1][x+1]) != 45 | (yx[y-1][x+1])>56){
                     char dummy[256];scanf("%s",dummy);
                     erro=1;
                     printf("-1: Não introduziu um carácter válido. Introduza novamente!\n\n");
                     }
                    if((yx[y-1][x+1]) != '-'){
                     disparo=(yx[y-1][x+1]) -'0';
                     (disparos_peca[disparo])++;
                    }
                    }
                    }while(erro==1);
                    erro=0;
                     
                    if(modo_dis==2 | (modo_dis==3 & d_yx[y][x+1] != 'e')){
                    do{
                    if(disparos_peca[1] < 1 & disparos_peca[2] < 2 & disparos_peca[3] < 3 & disparos_peca[4] < 4 & disparos_peca[5] < 5 & disparos_peca[6] < 6 & disparos_peca[7] < 7 & disparos_peca[8] < 8 ){
                    if(erro==0){x_alfa = x + 1 + '@';}
                    erro=0;
                    printf("%c%d\n",x_alfa, y);
                    scanf(" %c", &yx[y][x+1]);
                    if ((yx[y][x+1])<49 & (yx[y][x+1]) != 45 | (yx[y][x+1])>56){
                     char dummy[256];scanf("%s",dummy);
                     erro=1;
                     printf("-1: Não introduziu um carácter válido. Introduza novamente!\n\n");
                     }
                    if(yx[y][x+1] != '-'){
                     if(modo_dis==3){d_yx[y+1][x]='e';d_yx[y+1][x+1]='e';d_yx[y+1][x+2]='e';}
                     disparo= (yx[y][x+1])-'0';
                     (disparos_peca[disparo])++;
                    }
                    }
                    }while(erro==1);
                    erro=0;
                    }
                    
                    if(modo_dis==2 | (modo_dis==3 & d_yx[y-2][x+1] != 'e')){
                    do{
                    if(disparos_peca[1] < 1 & disparos_peca[2] < 2 & disparos_peca[3] < 3 & disparos_peca[4] < 4 & disparos_peca[5] < 5 & disparos_peca[6] < 6 & disparos_peca[7] < 7 & disparos_peca[8] < 8 ){
                    if(erro==0){x_alfa = x + 1 + '@';}
                    erro=0;
                    printf("%c%d\n",x_alfa, (y-2));
                    scanf(" %c", &yx[y-2][x+1]);
                    if ((yx[y-2][x+1])<49 & (yx[y-2][x+1]) != 45 | (yx[y-2][x+1])>56){
                     char dummy[256];scanf("%s",dummy);
                     erro=1;
                     printf("-1: Não introduziu um carácter válido. Introduza novamente!\n\n");
                     }
                    if(yx[y-2][x+1] != '-'){
                     if(modo_dis==3){d_yx[y-3][x]='e';d_yx[y-3][x+1]='e';d_yx[y-3][x+2]='e';}
                     disparo = (yx[y-2][x+1])-'0';
                     (disparos_peca[disparo])++;
                    }
                    }
                    }while(erro==1);
                    erro=0;
                    }
                    
                    if(modo_dis==2 | (modo_dis==3 & d_yx[y-1][x] !='e')){
                    do{
                    if(disparos_peca[1] < 1 & disparos_peca[2] < 2 & disparos_peca[3] < 3 & disparos_peca[4] < 4 & disparos_peca[5] < 5 & disparos_peca[6] < 6 & disparos_peca[7] < 7 & disparos_peca[8] < 8 ){
                    if(erro==0){x_alfa = x + '@';}
                    erro=0;
                    printf("%c%d\n",x_alfa, (y-1));
                    scanf(" %c", &yx[y-1][x]);
                    if ((yx[y-1][x])<49 & (yx[y-1][x]) != 45 | (yx[y-1][x])>56){
                     char dummy[256];scanf("%s",dummy);
                     erro=1;
                     printf("-1: Não introduziu um carácter válido. Introduza novamente!\n\n");
                     }
                    if(yx[y-1][x] != '-'){
                     if(modo_dis==3){d_yx[y][x-1]='e';d_yx[y-1][x-1]='e';d_yx[y-2][x-1]='e';}
                     disparo = (yx[y-1][x]) - '0';
                     (disparos_peca[disparo])++;
                    }
                    }
                    }while(erro==1);
                    erro=0;
                    }

                    if(modo_dis==2 | (modo_dis==3 & d_yx[y-1][x+2] !='e')){
                    do{
                    if(disparos_peca[1] < 1 & disparos_peca[2] < 2 & disparos_peca[3] < 3 & disparos_peca[4] < 4 & disparos_peca[5] < 5 & disparos_peca[6] < 6 & disparos_peca[7] < 7 & disparos_peca[8] < 8 ){
                    if(erro==0){x_alfa = x + 2 + '@';}
                    erro=0;
                    printf("%c%d\n",x_alfa, (y-1));
                    scanf(" %c", &yx[y-1][x+2]);
                    if ((yx[y-1][x+2])<49 & (yx[y-1][x+2]) != 45 | (yx[y-1][x+2])>56){
                     char dummy[256];scanf("%s",dummy);
                     erro=1;
                     printf("-1: Não introduziu um carácter válido. Introduza novamente!\n\n");
                     }
                    if(yx[y-1][x+2] != '-'){
                     if(modo_dis==3){d_yx[y][x+3]='e';d_yx[y-1][x+3]='e';d_yx[y-2][x+3]='e';}
                     disparo = (yx[y-1][x+2])-'0';
                     (disparos_peca[disparo])++;
                    }
                    }
                    }while(erro==1);
                    erro=0;
                    }

                    if(modo_dis==2 | (modo_dis==3 & d_yx[y][x] !='e')){
                    do{
                    if(disparos_peca[1] < 1 & disparos_peca[2] < 2 & disparos_peca[3] < 3 & disparos_peca[4] < 4 & disparos_peca[5] < 5 & disparos_peca[6] < 6 & disparos_peca[7] < 7 & disparos_peca[8] < 8 ){
                    if(erro==0){x_alfa = x + '@';}
                    erro=0;
                    printf("%c%d\n",x_alfa, y);
                    scanf(" %c", &yx[y][x]);
                    if ((yx[y][x])<49 & (yx[y][x]) != 45 | (yx[y][x])>56){
                     char dummy[256];scanf("%s",dummy);
                     erro=1;
                     printf("-1: Não introduziu um carácter válido. Introduza novamente!\n\n");
                     }
                    if(yx[y][x] != '-'){
                     if(modo_dis==2){d_yx[y-1][x-1]='e';d_yx[y][x-1]='e';d_yx[y+1][x-1]='e';d_yx[y+1][x]='e';d_yx[y+1][x+1]='e';}   
                     disparo = (yx[y][x])-'0';
                     (disparos_peca[disparo])++;
                    }
                    }
                    }while(erro==1);
                    erro=0;
                    }

                    if(modo_dis==2 | (modo_dis==3 & d_yx[y-2][x+2] !='e')){
                    do{
                    if(disparos_peca[1] < 1 & disparos_peca[2] < 2 & disparos_peca[3] < 3 & disparos_peca[4] < 4 & disparos_peca[5] < 5 & disparos_peca[6] < 6 & disparos_peca[7] < 7 & disparos_peca[8] < 8 ){
                    if(erro==0){x_alfa = x + 2 + '@';}
                    erro=0;
                    printf("%c%d\n",x_alfa, (y-2));
                    scanf(" %c", &yx[y-2][x+2]);
                    if ((yx[y-2][x+2])<49 & (yx[y-2][x+2]) != 45 | (yx[y-2][x+2])>56){
                     char dummy[256];scanf("%s",dummy);
                     erro=1;
                     printf("-1: Não introduziu um carácter válido. Introduza novamente!\n\n");
                     }
                    if(yx[y-2][x+2] != '-'){
                     if(modo_dis==3){d_yx[y-3][x+1]='e';d_yx[y-3][x+2]='e';d_yx[y-3][x+3]='e';d_yx[y-2][x+3]='e';d_yx[y-1][x+3]='e';}  
                     disparo = (yx[y-2][x+2])-'0';
                     (disparos_peca[disparo])++;
                    }
                    }
                    }while(erro==1);
                    erro=0;
                    }

                    if(modo_dis==2 | (modo_dis==3 & d_yx[y][x+2] !='e')){
                    do{
                    if(disparos_peca[1] < 1 & disparos_peca[2] < 2 & disparos_peca[3] < 3 & disparos_peca[4] < 4 & disparos_peca[5] < 5 & disparos_peca[6] < 6 & disparos_peca[7] < 7 & disparos_peca[8] < 8 ){
                    if(erro==0){x_alfa = x + 2 + '@';}
                    erro=0;
                    printf("%c%d\n",x_alfa, y);
                    scanf(" %c", &yx[y][x+2]);
                    if ((yx[y][x+2])<49 & (yx[y][x+2]) != 45 | (yx[y][x+2])>56){
                     char dummy[256];scanf("%s",dummy);
                     erro=1;
                     printf("-1: Não introduziu um carácter válido. Introduza novamente!\n\n");
                     }
                    if(yx[y][x+2] != '-'){
                     if(modo_dis==3){d_yx[y+1][x+1]='e';d_yx[y+1][x+2]='e';d_yx[y+1][x+3]='e';d_yx[y][x+3]='e';d_yx[y-1][x+3]='e';}  
                     disparo = (yx[y][x+2])-'0';
                     (disparos_peca[disparo])++;
                    }
                    }
                    }while(erro==1);
                    erro=0;
                    }

                    if(modo_dis==2 | (modo_dis==3 & d_yx[y-2][x] !='e')){
                    do{
                    if(disparos_peca[1] < 1 & disparos_peca[2] < 2 & disparos_peca[3] < 3 & disparos_peca[4] < 4 & disparos_peca[5] < 5 & disparos_peca[6] < 6 & disparos_peca[7] < 7 & disparos_peca[8] < 8 ){
                    if(erro==0){x_alfa = x + '@';}
                    erro=0;
                    printf("%c%d\n",x_alfa, (y-2));
                    scanf(" %c", &yx[y-2][x]);
                    if ((yx[y-2][x])<49 & (yx[y-2][x]) != 45 | (yx[y-2][x])>56){
                     char dummy[256];scanf("%s",dummy);
                     erro=1;
                     printf("-1: Não introduziu um carácter válido. Introduza novamente!\n\n");
                     }
                    if(yx[y-2][x] != '-'){
                     if(modo_dis==3){d_yx[y-1][x-1]='e';d_yx[y-2][x-1]='e';d_yx[y-3][x-1]='e';d_yx[y-3][x]='e';d_yx[y-3][x+1]='e';}  
                     disparo = (yx[y-2][x]) - '0';
                     (disparos_peca[disparo])++;
                    }
                    }
                    }while(erro==1);
                    erro=0;
                    }
                    n_pecas[disparo]++;
            }while((x< dim_tabu_x-2) & (n_pecas[1] != peca_n[1] | n_pecas[2] != peca_n[2] | n_pecas[3] != peca_n[3] | n_pecas[4] != peca_n[4] | n_pecas[5] != peca_n[5] | n_pecas[6] != peca_n[6] | n_pecas[7] != peca_n[7] | n_pecas[8] != peca_n[8]));

        }while(y>3 & (n_pecas[1] != peca_n[1] | n_pecas[2] != peca_n[2] | n_pecas[3] != peca_n[3] | n_pecas[4] != peca_n[4] | n_pecas[5] != peca_n[5] | n_pecas[6] != peca_n[6] | n_pecas[7] != peca_n[7] | n_pecas[8] != peca_n[8]));

    }

	void print_tabu(){
        int l,m,n,o;
        l=dim_tabu_y;
        for(m=dim_tabu_x+1;m<=25;m++){
            for(n=0;n<=16;n++){
                yx[n][m]= ' ';
            }
        }

        do{
            if(l<10){
                printf(" %d %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",l,yx[l][1],yx[l][2],yx[l][3],yx[l][4],yx[l][5],yx[l][6],yx[l][7],yx[l][8],yx[l][9],yx[l][10],yx[l][11],yx[l][12],yx[l][13],yx[l][14],yx[l][15],yx[l][16],yx[l][17],yx[l][18],yx[l][19],yx[l][20],yx[l][21],yx[l][22],yx[l][23],yx[l][24]);
            }
            else{
                printf("%d %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",l,yx[l][1],yx[l][2],yx[l][3],yx[l][4],yx[l][5],yx[l][6],yx[l][7],yx[l][8],yx[l][9],yx[l][10],yx[l][11],yx[l][12],yx[l][13],yx[l][14],yx[l][15],yx[l][16],yx[l][17],yx[l][18],yx[l][19],yx[l][20],yx[l][21],yx[l][22],yx[l][23],yx[l][24]);
            }
            l--;
        }while(l>0);
        printf("  ");
        for(o=65;o<=(dim_tabu_x+64);o++){printf(" %c",o);}
        printf("\n");
    }

    void print_pecas(){
        printf(" %d %d %d %d %d %d %d %d\n",peca_n[1],peca_n[2],peca_n[3],peca_n[4],peca_n[5],peca_n[6],peca_n[7],peca_n[8]);
    }
    
    void print_dimensao(){
        printf("%dx%d",dim_tabu_y,dim_tabu_x);
    }

    void print_logo(){
        printf("* ================================\n");
        switch(modo_jogo){
            case 1 :
                printf("* Modo de Jogo 1\n");
                printf("* Insira as Coordenadas de Disparo\n");
                break;
            case 2 :
                printf("* Modo de Jogo 2\n");
                printf("* Crie um tabuleiro com as características indicadas\n");
                printf("* Responda aos disparos do programa\n");
                break;
        }
        printf("* ================================\n");
    }
    