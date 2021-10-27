#define _CRT_SECURE_NO_WARNINGS

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
int no_max, contador;
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
	
	//if (fopen(&file, nome_ficheiro, "r") != 0)return nullptr;
	file = fopen( nome_ficheiro, "r");
	componentes* Novo_Componente = (componentes*)malloc(MAX_COMP * sizeof(componentes));
	
	char line[100];
	while(fgets(line,100,file))
	{

	sscanf(line, "%s %f %d %d", &Novo_Componente[i].nome, &Novo_Componente[i].valor, &Novo_Componente[i].No1, &Novo_Componente[i].No2);
	
		if (no_max < Novo_Componente[i].No1)
		{
			no_max = Novo_Componente[i].No1;

		}
		
		if (no_max < Novo_Componente[i].No2)
		{
			no_max = Novo_Componente[i].No2;

		}

		i++;
	}
	no_max++;


	float **matriz = (float**)malloc(no_max * sizeof(float*));

	if (matriz == NULL) abort();



	for (int l = 0; l < no_max; ++l)

	{

		matriz[l] = (float*)malloc((no_max + 1) * sizeof(float));

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
	{
		char nomeFicheiro[100]="circ2.txt";
		printf("Por favor defina o ficheiro a ler:\n");
		//scanf("%s", &nomeFicheiro);

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
	}
	case 2:
	{
		if (componentesLidos != 0)
		{
			for (i = 0; i <8 ; i++)
			{
				printf("%s %f %d %d\n", Novo_Componente[i].nome, Novo_Componente[i].valor, Novo_Componente[i].No1, Novo_Componente[i].No2);
			}
			printf("\nNúmero de nós do circuito: %d", no_max);
		}
		else {
			printf("Necessita de ler os componentes através de um ficheiro antes de os poder escrever.");
		}
		system("pause");
		break;
	}

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