#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_TTTboard(char [][3]);
void print_TTTboard(char [3][3]);
void joga_TTTboard(char,char [3][3]);
int fimjogo_TTTboard(char [3][3]);
void joga_galo(char [3][3],int [3]);
void actualiza_histograma(int [3],int, char);
void print_histograma(int [3]);

int main()
{
    int histogram[3] = {0,0,0};
    char tictactoe_board[3][3] = {{'x','o','x'},{'o','x',' '},{' ','o','x'}};
    time_t t;

    srand((unsigned) time(&t));

    printf("Tic Tac Toe\n\n");
    print_TTTboard(tictactoe_board);
    printf("\n== Bom jogo! ==\n\n");

    joga_galo(tictactoe_board,histogram);
    print_histograma(histogram);

    return 0;
}

void init_TTTboard(char board[][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void joga_TTTboard(char simbolo,char board[3][3])
{
    int jogada_valida = 0;
    int linha, coluna;

    do
    {
        linha = rand()%3;
        coluna = rand()%3;
        if (board[linha][coluna]==' ')
        {
            board[linha][coluna] = simbolo;
            jogada_valida = 1;
        }
    }
    while(!jogada_valida);
}

int fimjogo_TTTboard(char board[3][3])
{
    if ((board[0][0]!=' ')&&(board[0][0]==board[1][1])&&(board[1][1]==board[2][2]))
        return 1;
    if ((board[0][0]!=' ')&&(board[0][0]==board[1][0])&&(board[1][0]==board[2][0]))
        return 1;
    if ((board[0][0]!=' ')&&(board[0][0]==board[0][1])&&(board[0][1]==board[0][2]))
        return 1;
    if ((board[1][0]!=' ')&&(board[1][0]==board[1][1])&&(board[1][1]==board[1][2]))
        return 1;
    if ((board[2][0]!=' ')&&(board[2][0]==board[2][1])&&(board[2][1]==board[2][2]))
        return 1;
    if ((board[0][1]!=' ')&&(board[0][1]==board[1][1])&&(board[1][1]==board[2][1]))
        return 1;
    if ((board[0][2]!=' ')&&(board[0][2]==board[1][2])&&(board[1][2]==board[2][2]))
        return 1;
    if ((board[0][2]!=' ')&&(board[0][2]==board[1][1])&&(board[1][1]==board[2][0]))
        return 1;
    return 0;
}

void print_TTTboard(char board[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%c",board[i][j]);
            if (j!=2)
                printf("|");
        }
        printf("\n");
        if (i!=2)
            printf("- - -\n");
    }
}

void joga_galo(char tictactoe_board[3][3],int histogram[3])
{
    int i, jogada = 0, fim_jogo = 0;
    char jogador;

    for( i = 0; i < 100; i++)
    {
        jogada = 0;
        fim_jogo = 0;
        init_TTTboard(tictactoe_board);
        print_TTTboard(tictactoe_board);
        do {
            jogada++;
            if (jogada%2 != 0)
                jogador = 'x';
            else
                jogador = 'o';
            joga_TTTboard(jogador,tictactoe_board);
            fim_jogo = fimjogo_TTTboard(tictactoe_board);
            printf("\n== Jogada %d ==\n\n", jogada);
            print_TTTboard(tictactoe_board);
        } while ((!fim_jogo) && (jogada != 9));
        actualiza_histograma(histogram,fim_jogo, jogador);
    }
}

void actualiza_histograma(int histogram[3],int fim_jogo, char jogador)
{
    if (fim_jogo)
        if ( jogador == 'x' )
            histogram[0]++;
        else
            histogram[2]++;
    else
        histogram[1]++;
}

void print_histograma(int histogram[3])
{
    int i;

    for( i = 0; i < 3; i++)
    {
        printf("Histogram[%d] = %d\n",i,histogram[i]);
    }
}
