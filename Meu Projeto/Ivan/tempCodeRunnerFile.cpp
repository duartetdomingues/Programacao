[03:00, 14/07/2021] +351 913 690 965: #define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>


#define MAX_COMP 100

float** matriz;
FILE* file;
FILE* fich;
int i;
int* no_max, contador;
char nome_ficheiro[50], save[50];
float x[10], t;

void menu();

int main()
{
	//setlocale(LC_ALL, "pt_PT");
	//setlocale(LC_NUMERIC, "C");

	menu();


}

typedef struct componentes
{
	char nome[20];
	float valor;
	int No1;
	int No2;
};  componentes* Novo_Componente;

componentes* Leitura_Ficheiro_Dados(const char* nome_ficheiro)
{
	FILE* file;
	
	if (fopen_s(&file, nome_ficheiro, "r") != 0)return nullptr;
	
	componentes* Novo_Componente = (componentes*)malloc(MAX_COMP * sizeof(componentes));


	int i = 0;
	do
	{


		fscanf(file, "%s %f %d %d", &Novo_Componente[i].nome, &Novo_Componente[i].valor, &Novo_Componente[i].No1, &Novo_Componente[i].No2);

		if (*no_max < Novo_Componente[i].No1)
		{
			*no_max = Novo_Componente[i].No1;

		}
		if (*no_max < Novo_Componente[i].No2)
		{
			*no_max = Novo_Componente[i].No2;

		}

		i++;


	} while (!feof(file) && i <7);
	*no_max++;


	matriz = (float*)malloc(*no_max * sizeof(float));

	if (matriz == NULL) abort();



	for (int l = 0; l < *no_max; ++l)

	{

		matriz[l] = (float*)malloc((*no_max + 1) * sizeof(float));

		if (matriz[l] = NULL)abort();
	}


	fclose(file);

	return Novo_Componente;



}

void calculos_matriz(int contador, int n, float** mat, componentes* lista)
{
	for (int l = 0; l < n; ++l)
	{
		for (int c = 0; c < (n + 1); ++c)
		{
			mat[l][c] = 0;
		}
	}
	for (int i = 0; i < contador; i++)
	{
		if (lista[i].nome[0] == 'I')
		{
			mat[lista[i].No2][n] = mat[lista[i].No2][n] + lista[i].valor;
			mat[lista[i].No1][n] = mat[lista[i].No1][n] + lista[i].valor;
		}

		if (lista[i].nome[0] == 'R')
		{
			mat[lista[i].No1][lista[i].No1] = mat[lista[i].No1][lista[i].No1] + (1 / lista[i].valor);
			mat[lista[i].No2][lista[i].No2] = mat[lista[i].No2][lista[i].No2] + (1 / lista[i].valor);
			mat[lista[i].No1][lista[i].No2] = mat[lista[i].No1][lista[i].No2] - (1 / lista[i].valor);
			mat[lista[i].No2][lista[i].No1] = mat[lista[i].No2][lista[i].No1] - (1 / lista[i].valor);
		}
	}


	for (int i = 0; i < n; i++) {

		printf("\n");
		for (int j = 0; j < (n + 1); j++)
		{
			printf(" %0.3g ", mat[i][j]);
		}
	}printf("\n");


	printf("\n Qual o caminho onde pretende guardar a matriz? \n");
	scanf("%s", &save);

	fich = fopen(save, "w");

	if (fich == NULL)
	{
		printf("Erro na abertura do ficheiro...");

	}
	for (int i = 0; i < n; i++) {


		for (int j = 0; j < (n + 1); j++)
		{
			fprintf(fich, " %.3f ", matriz[i][j]);
		}
		fprintf(fich, "\n");
	}fclose(fich);

}



void gauss_jordan(int n, float t, float x[10], float** mat) {
	for (int j = 1; j < n; j++)
	{

		for (int i = 1; i < n; i++)
		{
			if (i != j)
			{
				t = mat[i][j] / mat[j][j];
				for (int k = 1; k < n + 1; k++)
				{
					mat[i][k] = mat[i][k] - t - mat[5][k];
				}
			}
		}
	}
	for (int i = 1; i < n; i++) {
		x[i] = mat[i][n] / mat[i][i];
		printf("\n x%d- %f", i, x[i]);
		printf("\n");

	}

}

int componentesLidos = 0;
int matrizAlocada = 0;


void menu()
{
	system("cls");

	int opcao = 0;

	printf("\n MENU \n");
	printf("\n 1-Inserir os dados do sistema de equações \n");
	printf("\n 2-Mostrar a lista de componentes lida e o número de nós do circuitos \n");
	printf("\n 3-Calcular a matriz do método dos nós e apresentar no ecrã \n");
	printf("\n 4-Guardar a matriz para um ficheiro de texto \n");
	printf("\n 5-Resolver o sistema pelo método de Gauss  \n");
	printf("\n 6-Sair do programa\n");
	printf("\n Escolha uma das opções: ");

	do
	{
		scanf("%d", &opcao);
		if (opcao > 7 || opcao < 0)
			printf("\n Opção inválida, escolha outra: ");
	} while (opcao > 7 || opcao < 0);

	switch (opcao)
	{
	case 1:
		char nomeFicheiro[100];
		printf("Por favor defina o ficheiro a ler:\n");
		scanf("%s", &nomeFicheiro);
		Novo_Componente = Leitura_Ficheiro_Dados(nomeFicheiro);
		if (Novo_Componente == nullptr) {
			printf("Erro ao ler o ficheiro, tente novamente.\n");
			componentesLidos = 0;
		}
		else {
			printf("Ficheiro lido com successo.\n");
			componentesLidos = 1;
		}
		system("pause");
		break;

	case 2:
		if (componentesLidos != 0)
		{
			for (i = 0; i < (*no_max - 1); i++)
			{
				printf("%s %f %d %d", Novo_Componente[i].nome, Novo_Componente[i].valor, Novo_Componente[i].No1, Novo_Componente[i].No2);
			}
			printf("\nNúmero de nós do circuito: %d", *no_max);
		}
		else {
			printf("Necessita de ler os componentes através de um ficheiro antes de os poder escrever.");
		}
		system("pause");
		break;

		/*case 3:
			if (componentesLidos != 0) {
				if (matriz == NULL) {
					matriz = Leitura_Ficheiro_Dados(Leitura_Ficheiro_Dados(Novo_Componente));
				}
				calculos_matriz( (contador), int n, float** mat, componentes * lista);
				calculos_matriz(Leitura_Ficheiro_Dados(Novo_Componente), matriz);
				matrizAlocada = 1;
			}
			else {
				printf("Necessita de ler os componentes através de um ficheiro antes de poder preencher a matriz.");
			}
			system("pause");
			break;

		case 4:
			if (matrizAlocada != 0 && componentesLidos != 0) {
				char nomeFicheiro[100];
				printf("Por favor defina o ficheiro a escrever:\n");
				scanf("%s", &nomeFicheiro);
				if (calculos_matriz(Leitura_Ficheiro_Dados(Novo_Componente), matriz, nomeFicheiro) == 0) {
					printf("Erro ao escrever ficheiro.\n");
				}
				else {
					printf("Ficheiro escrito com successo.\n");
				}
			}
			else {
				printf("Necessita de ter a matriz calculada para a escrever num ficheiro.\n");
			}
			system("pause");
			break;

		case 5:
			if (matrizAlocada != 0 && componentesLidos != 0) {
				int nos = Leitura_Ficheiro_Dados(Novo_Componente);
				gauss_jordan(nos, matriz);
				printf("\n");
				calculos_matriz(nos, matriz); //TODO imprimir so a ultima coluna
				printf("\n");
				for (int i = 1; i < nos; i++) {
					printf("Tensao no nó %d: %fV\n", i, matriz[i][nos]);
				}
			}
			system("pause");
			break;

		case 6:
			return;*/
	}

	menu();
}
[03:27, 14/07/2021] +351 913 690 965: #define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_COMP 100

struct Componente {
	char nome[20];
	float valor;
	int no1;
	int no2;
};

int componentesLidos = 0;
int matrizAlocada = 0;
float** matriz;
Componente* componentes;

Componente* lerFicheiro(const char* ficheiro);
void escreverComponentes(Componente* componentes);
int numeroTotalNos(Componente* componentes);
float** alocarMatriz(int numeroNos);
void preencherMatriz(int numeroNos, float** matriz, Componente* componentes);
void escreverMatriz(int numeroNos, float** matriz);
int escreverMatrizFicheiro(int numeroNos, float** matriz, const char* nomeFicheiro);
void menu();

int main() {
	setlocale(LC_ALL, "pt_PT");
	setlocale(LC_NUMERIC, "C");

	//Componente* componentes{};
	//float** matriz;

	menu();

	//componentes = lerFicheiro("D://EDA//dados_tisha.txt");
	//escreverMatrizFicheiro(numeroNos, matriz, "D://EDA//matriz_tisha.txt");
}

Componente* lerFicheiro(const char* nomeFicheiro)
{
	FILE* ficheiro;
	// Verificar se a abertura do ficheiro teve sucesso
	if (fopen_s(&ficheiro, nomeFicheiro, "r") != 0) return nullptr;

	Componente* componentes = (Componente*)malloc(MAX_COMP * sizeof(Componente));

	// Verificar se alocação da memoria foi corretamente feita.
	if (componentes == NULL) return nullptr;

	char linha[100];

	for (int i = 0; i < MAX_COMP; i++) {
		// Obter linha do ficheiro e em caso de falhar ou ser fim do ficheiro sair do loop.
		if (fgets(linha, 100, ficheiro) != nullptr) {
			// Retirar informacao da linha lida.
			sscanf(linha, "%s %f %d %d", &componentes[i].nome, &componentes[i].valor, &componentes[i].no1, &componentes[i].no2);
		}
		else {
			// Erro ou fim do ficheiro encontrado.
			strcpy(componentes[i].nome, "EOF");
			componentes[i].valor = -1;
			componentes[i].no1 = -1;
			componentes[i].no2 = -1;
			break;
		}
	}

	fclose(ficheiro);
	return (componentes);
}

void escreverComponentes(Componente* componentes)
{
	// Verifica se o vetor de componentes nao eh null
	if (componentes == nullptr) return;
	printf("Lista de componentes:\n");
	printf("Tipo:      Valor:   Nos:\n");
	for (int i = 0; i < MAX_COMP; i++) {
		// Verificar se existem mais nos validos
		if (componentes[i].no1 >= 0 || componentes[i].no2 >= 0) {
			printf("%-10s %7.2f %2d %2d\n", componentes[i].nome, componentes[i].valor, componentes[i].no1, componentes[i].no2);
		}
		else {
			break;
		}
	}
}

int numeroTotalNos(Componente* componentes)
{
	// Verifica se o vetor de componentes nao eh null
	if (componentes == nullptr) return -1;
	int noMaximo = 0;
	for (int i = 0; i < MAX_COMP; i++) {
		// Verificar se existem mais nos validos
		if (componentes[i].no1 >= 0 || componentes[i].no2 >= 0) {
			if (componentes[i].no1 > noMaximo) noMaximo = componentes[i].no1;
			if (componentes[i].no2 > noMaximo) noMaximo = componentes[i].no2;
		}
		else {
			break;
		}
	}
	return noMaximo + 1;
}

float** alocarMatriz(int numeroNos)
{
	// Alocar vetor de vetores.
	float** matriz = (float*)malloc(numeroNos * sizeof(float));
	if (matriz == NULL) return nullptr;
	for (int i = 0; i < numeroNos; i++) {
		// Alocar cada um dos vetores de float.
		matriz[i] = (float*)malloc((numeroNos + 1) * sizeof(float));
		if (matriz[i] == NULL) return nullptr;
		for (int j = 0; j <= numeroNos; j++) {
			matriz[i][j] = 0;
		}
	}
	return (matriz);
}

void preencherMatriz(int numeroNos, float** matriz, Componente* componentes)
{
	if (matriz == NULL || componentes == NULL) return;
	for (int i = 0; i < MAX_COMP; i++) {
		// Verificar se existem mais nos validos
		if (componentes[i].no1 < 0 || componentes[i].no2 < 0) break;

		if (componentes[i].nome[0] == 'I') {
			// Se componente for fonte de corrente
			matriz[componentes[i].no2][numeroNos] += componentes[i].valor;
			matriz[componentes[i].no1][numeroNos] -= componentes[i].valor;
		}
		else if (componentes[i].nome[0] == 'R') {
			matriz[componentes[i].no1][componentes[i].no1] += 1.0 / componentes[i].valor;
			matriz[componentes[i].no2][componentes[i].no2] += 1.0 / componentes[i].valor;
			matriz[componentes[i].no1][componentes[i].no2] -= 1.0 / componentes[i].valor;
			matriz[componentes[i].no2][componentes[i].no1] -= 1.0 / componentes[i].valor;
		}
	}
}

void escreverMatriz(int numeroNos, float** matriz)
{
	printf("Matriz: \n");

	for (int i = 1; i < numeroNos; i++)
	{
		for (int j = 1; j <= numeroNos; j++)
		{
			if (j != numeroNos)
			{
				printf("%f ", matriz[i][j]);
			}
			else
			{
				printf("| %f\n", matriz[i][j]);
			}
		}
	}
}

int escreverMatrizFicheiro(int numeroNos, float** matriz, const char* nomeFicheiro)
{
	FILE* ficheiro;
	// Verificar se a abertura do ficheiro teve sucesso
	if (fopen_s(&ficheiro, nomeFicheiro, "w") != 0) return 0;

	fprintf_s(ficheiro, "Matriz: \n");

	for (int i = 1; i < numeroNos; i++)
	{
		for (int j = 1; j <= numeroNos; j++)
		{
			if (j != numeroNos)
			{
				fprintf_s(ficheiro, "%f ", matriz[i][j]);
			}
			else
			{
				fprintf_s(ficheiro, "| %f\n", matriz[i][j]);
			}
		}
	}

	fclose(ficheiro);

	return 1;
}

//Resolve o sistema aplicando o Teorema de Gauss-Jordan

void gaussJordan(int numeroNos, float** matriz)
{
	//Algoritmo para eliminar os elementos abaixo da diagonal principal

	for (int j = 1; j < numeroNos - 1; j++)
	{
		for (int i = j + 1; i < numeroNos; i++)
		{
			float pivot = matriz[j][j];

			if (pivot == 0)
			{
				printf("Sistema Impossível");
				exit(0);
			}

			float f = matriz[i][j] / pivot;

			for (int k = 1; k <= numeroNos; k++)
			{
				matriz[i][k] = matriz[i][k] - (f * matriz[j][k]);
			}
		}
	}

	//Algoritmo para eliminar elementos acima da diagonal principal

	for (int j = numeroNos - 1; j > 1; j--)
	{
		for (int i = j - 1; i > 0; i--)
		{
			float pivot = matriz[j][j];

			if (pivot == 0)
			{
				printf("Sistema Impossível");
				exit(0);
			}

			float f = matriz[i][j] / pivot;

			for (int k = 1; k <= numeroNos; k++)
			{
				matriz[i][k] = matriz[i][k] - (f * matriz[j][k]);
			}
		}
	}

	//Tornar a Matriz A numa matriz identidade

	for (int i = 1; i < numeroNos; i++)
	{
		matriz[i][numeroNos] = matriz[i][numeroNos] / matriz[i][i];
		matriz[i][i] = 1;
	}
}

//Apresenta o menu e as respetivas funcionalidas

void menu()
{
	system("cls");

	int opcao = 0;

	printf("\n MENU \n");
	printf("\n 1-Inserir os dados do sistema de equações \n");
	printf("\n 2-Mostrar a lista de componentes lida e o número de nós do circuitos \n");
	printf("\n 3-Calcular a matriz do método dos nós e apresentar no ecrã \n");
	printf("\n 4-Guardar a matriz para um ficheiro de texto \n");
	printf("\n 5-Resolver o sistema pelo método de Gauss  \n");
	printf("\n 6-Sair do programa\n");
	printf("\n Escolha uma das opções: ");

	do
	{
		scanf("%d", &opcao);
		if (opcao > 7 || opcao < 0)
			printf("\n Opção inválida, escolha outra: ");
	} while (opcao > 7 || opcao < 0);

	switch (opcao)
	{
	case 1:
		char nomeFicheiro[100];
		printf("Por favor defina o ficheiro a ler:\n");
		scanf("%s", &nomeFicheiro);
		componentes = lerFicheiro(nomeFicheiro);
		if (componentes == nullptr) {
			printf("Erro ao ler o ficheiro, tente novamente.\n");
			componentesLidos = 0;
		}
		else {
			printf("Ficheiro lido com successo.\n");
			componentesLidos = 1;
		}
		system("pause");
		break;

	case 2:
		if (componentesLidos != 0)
		{
			escreverComponentes(componentes);
			printf("\nNúmero de nós do circuito: %d", numeroTotalNos(componentes));
		}
		else {
			printf("Necessita de ler os componentes através de um ficheiro antes de os poder escrever.");
		}
		system("pause");
		break;

	case 3:
		if (componentesLidos != 0) {
			if (matriz == NULL) {
				matriz = alocarMatriz(numeroTotalNos(componentes));
			}
			preencherMatriz(numeroTotalNos(componentes), matriz, componentes);
			escreverMatriz(numeroTotalNos(componentes), matriz);
			matrizAlocada = 1;
		}
		else {
			printf("Necessita de ler os componentes através de um ficheiro antes de poder preencher a matriz.");
		}
		system("pause");
		break;

	case 4:
		if (matrizAlocada != 0 && componentesLidos != 0) {
			char nomeFicheiro[100];
			printf("Por favor defina o ficheiro a escrever:\n");
			scanf("%s", &nomeFicheiro);
			if (escreverMatrizFicheiro(numeroTotalNos(componentes), matriz, nomeFicheiro) == 0) {
				printf("Erro ao escrever ficheiro.\n");
			}
			else {
				printf("Ficheiro escrito com successo.\n");
			}
		}
		else {
			printf("Necessita de ter a matriz calculada para a escrever num ficheiro.\n");
		}
		system("pause");
		break;

	case 5:
		if (matrizAlocada != 0 && componentesLidos != 0) {
			int nos = numeroTotalNos(componentes);
			gaussJordan(nos, matriz);
			printf("\n");
			escreverMatriz(nos, matriz); //TODO imprimir so a ultima coluna
			printf("\n");
			for (int i = 1; i < nos; i++) {
				printf("Tensao no nó %d: %fV\n", i, matriz[i][nos]);
			}
		}
		system("pause");
		break;

	case 6:
		return;
	}

	menu();
}