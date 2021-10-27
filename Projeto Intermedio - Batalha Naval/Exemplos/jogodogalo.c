#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int InicRandom(){ //Definir semente do random
  long ultime;
  time(&ultime);
  srand((unsigned) ultime);
}

int PrimJogar(){ 
  /* Define o primeiro jogador (aleatório) */
  return rand()%2;
}

void MostrarJogo(char tab[3][3]){
  /* Coloca o tabuleiro no ecrã */
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      printf(" %c ", tab[i][j]);
      if(j != 2){
        printf("|");
      }
    }
    putchar('\n');
    if(i != 2){ //Na ultima linha n mostra
      printf("---+---+---\n");
    }
  }
  puts("\n");
}

void MostrarPosic(){ 
  /* Mostrar o esquema para ajudar na jogada */
  printf("Cada numero corresponde a uma posicao\n\n");
  printf("\t 7 | 8 | 9 \n");
  printf("\t---+---+---\n");
  printf("\t 4 | 5 | 6 \n");
  printf("\t---+---+---\n");
  printf("\t 1 | 2 | 3 \n\n");
}

void MostrarPontos(int computer, int player){
  /* Mostra a pontuação */
  printf("Pontuacoes\n\n");
  printf("\tVitorias: \t%2d\n", player);
  printf("\tDerrotas: \t%2d\n", computer);
}

void Posicao(int v[], int c){
  /* Traduz a posição introduzida pelo jogador na posição da tabela */
  switch(c){//indice 0 - i, indice 1 -j
    case 1: v[0] = 2; v[1] = 0; break;
    case 2: v[0] = 2; v[1] = 1; break;
    case 3: v[0] = 2; v[1] = 2; break;
    case 4: v[0] = 1; v[1] = 0; break;
    case 5: v[0] = 1; v[1] = 1; break;
    case 6: v[0] = 1; v[1] = 2; break;
    case 7: v[0] = 0; v[1] = 0; break;
    case 8: v[0] = 0; v[1] = 1; break;
    case 9: v[0] = 0; v[1] = 2; break;
  }
}

int InvPosicao(int i, int j){
  /* Traduz a posição da tabela para a posição do NumPad */
  switch(i){
    case 0: if(j == 0){
      return 7;
    }else if(j == 1){
      return 8;
    }else if(j == 2){
      return 9;
    }
    break;
    case 1: if(j == 0){
      return 4;
    }else if(j == 1){
      return 5;
    }else if(j == 2){
      return 6;
    }
    break;
    case 2: if(j == 0){
      return 1;
    }else if(j == 1){
      return 2;
    }else if(j == 2){
      return 3;
    }
    break;
  }
}

void Jogar(char (*tab)[3], char ch, int pos){
  /* Coloca o caracter na posição escolhida do tabuleiro */
  int v[2], i, j;
  Posicao(v,pos);
  i = v[0];
  j = v[1];
  tab[i][j] = ch;
}

int VerificarJogada(char (*tab)[3], char ch, int pos){
  /* Verifica se uma jogada é possível
  Devolve 0 se não for possível e 1 se for possível */

  int i, j, v[2];
  Posicao(v,pos);
  i = v[0];
  j = v[1];  
  return tab[i][j] == ' ';
}

int Empate(char (*tab)[3]){
  /* Verifica se estamos perante uma situação de empate */
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if(tab[i][j] == ' '){
        return 0;
      }
    }
  }
  return 1;
}

int Vitoria(char (*tab)[3], char ch){ 
  /* Verifica se o jogador com o caracter *ch* venceu o jogo */
  if((tab[0][0] == ch && tab[0][1] == ch &&tab[0][2] == ch) || //1ª linha
  (tab[1][0] == ch && tab[1][1] == ch && tab[1][2] == ch) || //2ª linha
  (tab[2][0] == ch && tab[2][1] == ch && tab[2][2] == ch)){ // 3ª coluna
    return 1;
  }else if((tab[0][0] == ch && tab[1][0] == ch &&tab[2][0] == ch) || //1ª coluna
  (tab[0][1] == ch && tab[1][1] == ch && tab[2][1] == ch) || //2ª coluna
  (tab[0][2] == ch && tab[1][2] == ch && tab[2][2] == ch)){ // 3ª coluna
    return 1;
  }else if((tab[0][0] == ch && tab[1][1] == ch &&tab[2][2] == ch) || //diagonal 1
  (tab[0][2] == ch && tab[1][1] == ch && tab[2][0] == ch)){ //diagonal 2
    return 1;
  }else{
    return 0;
  }

}

int AcabouJogo(char (*tab)[3]){
  /* Verifica se o jogo acabou ou se podemos continuar a jogar 
  Devolve:
    0 - não acabou
    1 - vitoria para 'O'
    2 - vitoria para 'X'
    3 - acabou em empate */

  if(Vitoria(tab, 'O')){
    return 1;
  }else if(Vitoria(tab, 'X')){
    return 2;
  }else if(Empate(tab)){
    return 3;
  }else{
    return 0;
  }

}

int AdicionaCar(char *s, char c){
  /* Adiciona um caracter à string s */
  
  int length = strlen(s);
  s[length] = c;
  s[length+1] = '\0';

}

/* Tabuleiro
1ª dimensão - Vertical
2ª dimensão - Horizontal*/

int Iminente(char (*tab)[3], char comp, char jog, char (*str)[4]){
  /* Quando o computador está quase a perder ou ganhar (situação iminente)
  Devolve 1 se jogou e 0 se não jogou */
  
  int i, j, X = 0, val;
  char lin[4] = {'\0'}, col[4] = {'\0'}, diag[2][4] = {{'\0',}, {'\0'}};

  AdicionaCar(diag[0], tab[0][0]); // Diagonal E-D C-B (= \ )
  AdicionaCar(diag[0], tab[1][1]);
  AdicionaCar(diag[0], tab[2][2]);

  AdicionaCar(diag[1], tab[0][2]); // Diagonal D-E B-C (= / )
  AdicionaCar(diag[1], tab[1][1]);
  AdicionaCar(diag[1], tab[2][0]);

  for(i = 0; i < 3; i++){
    lin[0] = '\0';
    AdicionaCar(lin, tab[i][0]); // Linhas
    AdicionaCar(lin, tab[i][1]);
    AdicionaCar(lin, tab[i][2]);

    col[0] = '\0';
    AdicionaCar(col, tab[0][i]); // Colunas
    AdicionaCar(col, tab[1][i]);
    AdicionaCar(col, tab[2][i]);

    for(j = 0; j < 3; j++){
      if(strcmp(str[j], lin) == 0){ // Verifica linhas
        Jogar(tab, comp, InvPosicao(i, j));

        return 1;
      }

      if(strcmp(str[j], col) == 0){ // Verifica colunas
        Jogar(tab, comp, InvPosicao(j, i));

        return 1;
      }

      if(!X){ // Verifica diagonais
        if(strcmp(str[j], diag[0]) == 0){
          Jogar(tab, comp, InvPosicao(j, j));

          return 1;
        }else if(strcmp(str[j], diag[1]) == 0){
          val = 2 - j;
          Jogar(tab, comp, InvPosicao(j, val));

          return 1;
        }
      }
    }
    X = 1;
  }

  return 0;
}

char Jogada(char (*tab)[3], int pos){
  int v[2];
  Posicao(v, pos);
  return tab[v[0]][v[1]];
}

void AI(char (*tab)[3], char comp, char jog, int *mov){ 
  /* Computador */

  char perder[3][4] = {{' ', jog, jog}, {jog, ' ', jog}, {jog, jog, ' '}};
  char ganhar[3][4] = {{' ', comp, comp}, {comp, ' ', comp}, {comp, comp, ' '}};
  int done = 0, available = 0, pos;

  done = Iminente(tab, comp, jog, ganhar);

  if(!done){
    done = Iminente(tab, comp, jog, perder);
  }
  
  if(done){
    return;
  }
  //Caso seja uma situação normal (sem ninguem estar quase a vencer)
  if(comp ==  'X'){
    if(*mov == 1){
      while(!available){
        pos = ((rand()%3)+1)*2;
        if(VerificarJogada(tab, comp, pos)){
          Jogar(tab, comp, pos);
          available = 1;
        }
      }
      mov++;
      return;
    }else if(Jogada(tab, 1) == jog || Jogada(tab, 3) == jog || 
        Jogada(tab, 7) == jog || Jogada(tab, 9) == jog){
      if(VerificarJogada(tab, comp, 5)){
        Jogar(tab, comp, 5);
        *mov = 1;
        return;
      }
    }else if(Jogada(tab, 2) == jog || Jogada(tab, 4) == jog ||
        Jogada(tab, 6) == jog || Jogada(tab, 8) == jog){
      if(VerificarJogada(tab, comp, 5)){
        Jogar(tab, comp, 5);
        return;
      }
    }
  }

  /* Jogar no cantos */
  if(VerificarJogada(tab, comp, 7)){
    Jogar(tab, comp, 7);
  }else if(VerificarJogada(tab, comp, 3)){
    Jogar(tab, comp, 3);
  }else if(VerificarJogada(tab, comp, 1)){
    Jogar(tab, comp, 1);
  }else if(VerificarJogada(tab, comp, 9)){
    Jogar(tab, comp, 9);
  }
  /* Jogar nas outras posições*/
  while(!available){
    pos = ((rand()%4)+1)*2;
    if(VerificarJogada(tab, comp, pos)){
      Jogar(tab, comp, pos);
    }
  }
}

int DeNovo(){
  /* 1 se for outra vez, 0 se quiser sair */
  char c;
  do{
    printf("Queres jogar outra vez (<S>im ou <N>ao)?\n");
    scanf(" %c", &c);
    putchar('\n');
  }while(c != 's' && c != 'n' && c != 'S' && c != 'N');
  
  return (c == 's' || c == 'S');
}

void LimparJogo(char v[3][3]){
  /* Limpa todas as jogadas do tabuleiro */
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      v[i][j] = ' ';
    }
  }
}

int main(){
  /* Função principal, é o "motor" do jogo*/

  InicRandom();
  /* Pontuações, Novo Jogo, Retorno (de funções), variável para a AI, Total de jogos e Total de empates */
  int p_comp = 0, p_jog = 0, novo = 1, ret, mov, total = 0, empates = 0;
  /* Simbolos dos jogadores, c - conteúdo variável, vez - vez de jogar, ultimo - o ultimo que jogou, e tabuleiro */
  char c_comp, c_jog, c, vez = 'O', ultimo, jogo[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

  do{/* Pedir a opção de símbolo */
    printf("\t\t\t\t\tJOGO DO GALO\n\n");
    printf("Nota: \t'O' comeca o jogo.\n\tQuem ganhar comeca o proximo jogo.\n\n");
    printf("1 \t- \t'O'\n2 \t- \t'X'\nOutro\t- \tAleatorio\n\nEscolha uma opcao: ");
    c = getchar();
    putchar('\n');
  }while(c == '\0');

  if(c == '1'){ /* Opção 1 - comp = X, jog = O */
    c_jog = 'O';
    c_comp = 'X';
  }else if(c == '2'){ /* Opção 2 - comp = O, jog = X */
    c_jog = 'X';
    c_comp = 'O';
  }else{ /* Aleatório */
    if(PrimJogar()){
      c_jog = 'O';
      c_comp = 'X';
    }else{
      c_jog = 'X';
      c_comp = 'O';
    }
  }
 
  while(novo){ /* Ciclo principal do jogo */
    if(c_comp == vez){ /* Se for a vez do computador */
      AI(jogo, c_comp, c_jog, &mov);
      vez = c_jog; /* O jogador passa a jogar */
      ultimo = c_comp;

    }else{ /* Se for a vez do jogador */
      do{ /* Interface de jogo */
        printf("Jogas com '%c'\n\n", c_jog);
        MostrarPosic();
        MostrarJogo(jogo);
        printf("Escolhe a posicao (1-9): ");
        scanf(" %c", &c);
      }while(c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6'
    && c != '7' && c != '8' && c != '9');
      putchar ('\n');
      if(VerificarJogada(jogo, c_jog, c-'0')){
        Jogar(jogo, c_jog, c-'0');        
        
        vez = c_comp; /* O computador passa a jogar */
        ultimo = c_jog;
      }else{
        printf("Jogada invalida! Escolhe uma casa que nao esteja ocupada\n");
      }
    }

    ret = AcabouJogo(jogo); /* Verifica se acabou o jogo */

    if(ret == 0){
      continue;
    }else if(ret == 3){ /* Em caso de empate */
      printf("\t\tEmpate!\n");
      empates++;
      if(PrimJogar()){
        c_jog = 'O';
        c_comp = 'X';
      }else{
        c_jog = 'X';
        c_comp = 'O';
      }
    }else if(ret == 1 || ret == 2){ /* Em xaso de vitória */
      if(ret == 1){
        if(c_jog == 'O'){
          printf("Parabens! Ganhaste ao computador\n\n");
          p_jog++;
        }else{
          printf("Mais sorte para a proxima\n\n");
          p_comp++;
          c_comp = 'O';
          c_jog = 'X';
        }
      }else{
        if(c_jog == 'X'){
          printf("Parabens! Ganhaste ao computador\n\n");
          p_jog++;
          c_jog = 'O';
          c_comp = 'X';
        }else{
          printf("Mais sorte para a proxima\n\n");
          p_comp++;
        }
      }
    }
    
    total++;
    MostrarJogo(jogo);
    MostrarPontos(p_comp, p_jog);
    printf("\tEmpates: \t%2d\n", empates);
    printf("\tJogos: \t\t%2d\n\n", total);
    novo = DeNovo(); /* Verifica se o jogador quer jogar outra vez */
    
    if(novo){
      LimparJogo(jogo);
      vez = 'O';
      mov = 0;
    }
  }

  /* Sai */
  printf("Percentagem de vitorias: \t%.2f%%\n", ((float) p_jog / (float) total)*100);
  printf("Percentagem de derrotas: \t%.2f%%\n", ((float) p_comp / (float) total)*100);
  printf("Percentagem de empates: \t%.2f%%\n\n\n", ((float) empates / (float) total)*100);
  printf("Pressiona <ENTER> tecla para sair...");
  fflush(stdin);
  getchar();

  return 0;
}