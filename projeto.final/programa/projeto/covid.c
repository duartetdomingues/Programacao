#include "covid19.h"

int main(int argc, char *argv[]){
    char option;
    char *in_filename = NULL, *out_filename = NULL, *selecao = NULL, *restricao = NULL, *restricao_data = NULL, *restricao_data_2 = NULL, *ordenacao = NULL, *ordenacao_data = NULL, *leitura = NULL;
    int *restricao_populacao;
    country_data *list_head = NULL;

    in_filename = (char *)malloc(256 * sizeof(char));
    out_filename = (char *)malloc(256 * sizeof(char)); //ver apenas o maximo de espaco desnecessario e depois desalocá-lo!!
    leitura = (char *)malloc(256 * sizeof(char));
    selecao = (char *)malloc(9 * sizeof(char));
    restricao = (char *)malloc(6 * sizeof(char));
    restricao_populacao = (int *)malloc(sizeof(int));
    restricao_data = (char *)malloc(8 * sizeof(char));
    restricao_data_2 = (char *)malloc(8 * sizeof(char));
    ordenacao = (char *)malloc(5 * sizeof(char));
    ordenacao_data = (char *)malloc(8 * sizeof(char));

    /* in_filename = NULL; 
    out_filename = NULL; 
    leitura = NULL; 
    selecao = NULL; 
    restricao = NULL; 
    restricao_populacao = NULL; 
    restricao_data = NULL; 
    restricao_data_2 = NULL; 
    ordenacao = NULL; 
    ordenacao_data = NULL;   */

    //strcpy(leitura, "all");

    while ((option = getopt(argc, argv, "i:L:D:P:S:o:")) != -1)
    { // ler as opções escritas pelo utilizador na consola
        switch (option)
        {
        case 'i':
            strcpy(in_filename, optarg);
            break;

        case 'L':
            strcpy(leitura, optarg);
            break;

        case 'D':
            strcpy(selecao, optarg);
            break;

        case 'P':
            strcpy(restricao, optarg);
            if (strcmp(restricao, "min") == 0 || strcmp(restricao, "max") == 0)
            {
                optind--;
                sscanf(argv[optind], "%d", restricao_populacao);
                *restricao_populacao = 50000 * 1000;
            }
            if (strcmp(restricao, "date") == 0 || strcmp(restricao, "dates") == 0)
            {
                strcpy(restricao_data, argv[optind]);
                if (strcmp(restricao, "dates") == 0)
                {
                    optind++;
                    strcpy(restricao_data_2, argv[optind]);
                }
            }
            break;

        case 'S':
            strcpy(ordenacao, optarg);
            if (strcmp(ordenacao, "inf") == 0 || strcmp(ordenacao, "dea") == 0)
            {
                strcpy(ordenacao_data, argv[optind]);
            }
            break;

        case 'o':
            strcpy(out_filename, optarg);
            break;
        case ':':
            if (optopt == 'i' || optopt == 'o')
            {
                fprintf(stderr, "\n> a opcao -%c requere um argumento.\n", optopt);
                erros();
                exit(1);
            }
            break;
        case '?':
            if (isprint(optopt))
            {
                fprintf(stderr, "\n> opcao `-%c' desconhecida.\n", optopt);
                erros();
                exit(1);
            }
            break;
        }
    }

    if (strcmp(in_filename, "") == 0 || strcmp(out_filename, "") == 0)
    {
        fprintf(stderr, "\n-i e -o são opcões obrigatórias.\n");
        erros();
        exit(1);
    }

    list_head = read_file(in_filename, leitura, selecao, restricao, restricao_populacao, restricao_data, restricao_data_2, list_head);
    free(leitura);
    free(in_filename);
    free(selecao);
    free(restricao);
    free(restricao_populacao);
    free(restricao_data);
    free(restricao_data_2);
    list_head = order(list_head, ordenacao, ordenacao_data);
    free(ordenacao);
    free(ordenacao_data);
    write_file(out_filename, list_head);
    free(out_filename);
    free_list(list_head);
    return 0;
}

country_data *search_country(country_data *list_head, char *str_country)
/*
####################################################################################################
a void search_country_data pesquisa um determinado país na lista principal da estrutura e devolve essa estrutura. se esse país já existir nao e criada nenhuma estrutura nova na estrutura principal de modo a não haver duplicados na estrutura principal. Mais uma vez optamos por poupar espaço na nossa estrutura de dados em vez de remover
####################################################################################################
*/
{
    country_data *auxstruct;
    auxstruct = list_head;
    int flag = 0;

    if (list_head != NULL)
    {
        while (auxstruct != NULL && flag == 0)
        {
            if (strcmp(auxstruct->country, str_country) == 0)
            {
                return auxstruct;
            }
            auxstruct = auxstruct->nextC;
        }
    }
    auxstruct = NULL;
    return auxstruct;
}

country_data *create_country_data(char *str_country, char *str_country_code, char *str_continent, int *int_population, char *str_year_week, int *weekly_count, int *cumulative_count, double *rate_14_day, country_data *list_head, char *indicator, char *selecao)
{
    country_data *new_country_data = NULL;

    if ((new_country_data = (country_data *)calloc(1, sizeof(country_data))) == NULL)
    {
        printf("Erro: Não foi possível alocar o bloco de memória\n");
        exit(EXIT_FAILURE);
    }
    new_country_data->country = (char *)malloc(strlen(str_country) + 1);
    new_country_data->country_code = (char *)malloc(strlen(str_country_code) + 1);
    new_country_data->continent = (char *)malloc(strlen(str_continent) + 1);
    new_country_data->population = (int *)malloc(sizeof(int));

    strcpy(new_country_data->country, str_country);
    strcpy(new_country_data->country_code, str_country_code);
    strcpy(new_country_data->continent, str_continent);
    memcpy(new_country_data->population, int_population, sizeof(int));
    new_country_data->nextC = NULL;
    new_country_data->nextDD = NULL;
    new_country_data->nextCD = NULL;

    //create cases or deaths
    country_data *i_country_data = NULL;
    if (strcmp(indicator, "cases") == 0) //cria novo pais quando não foi selecionado nada e, se foi, apenas cria se se selecionou ou "inf" ou "racioinf"
    {
        create_cases_data(str_year_week, weekly_count, cumulative_count, rate_14_day, i_country_data, new_country_data);
    }
    else if (strcmp(indicator, "deaths") == 0)
    {
        create_deaths_data(str_year_week, weekly_count, cumulative_count, rate_14_day, i_country_data, new_country_data);
    }

    //insert country
    country_data *AuxT;

    if (list_head == NULL)
    {
        list_head = new_country_data;
    }
    else
    {
        AuxT = list_head;
        while (AuxT->nextC != NULL)
        {
            AuxT = AuxT->nextC;
        }
        AuxT->nextC = new_country_data;
    }

    return list_head;
}

void create_cases_data(char *str_year_week, int *weekly_count, int *cumulative_count, double *rate_14_day, country_data *i_country_data, country_data *new_country_data)
{
    cases_data *new_cases_data = NULL;
    if ((new_cases_data = (cases_data *)calloc(1, sizeof(cases_data))) == NULL)
    {
        printf("Erro: Não foi possível alocar o bloco de memória\n");
        exit(EXIT_FAILURE);
    }

    new_cases_data->year_week = (char *)malloc(strlen(str_year_week) + 1);
    new_cases_data->weekly_cases = (int *)malloc(sizeof(int));
    new_cases_data->total_cases = (int *)malloc(sizeof(int));
    new_cases_data->cases_100m = (double *)malloc(sizeof(double));

    strcpy(new_cases_data->year_week, str_year_week);
    memcpy(new_cases_data->weekly_cases, weekly_count, sizeof(int));
    memcpy(new_cases_data->cases_100m, rate_14_day, sizeof(double));
    memcpy(new_cases_data->total_cases, cumulative_count, sizeof(int));
    new_cases_data->nextCD = NULL;

    //insert cases_data
    cases_data *aux_struct = NULL;

    if (i_country_data == NULL || i_country_data->nextCD == NULL)
    {
        if (i_country_data == NULL)
        {
            new_country_data->nextCD = new_cases_data;
        }
        else
        {
            i_country_data->nextCD = new_cases_data;
        }
    }
    else
    {
        aux_struct = i_country_data->nextCD;
        while (aux_struct->nextCD != NULL)
        {
            aux_struct = aux_struct->nextCD;
        }
        aux_struct->nextCD = new_cases_data;
    }
}

void create_deaths_data(char *str_year_week, int *weekly_count, int *cumulative_count, double *rate_14_day, country_data *i_country_data, country_data *new_country_data)
{
    deaths_data *new_deaths_data = NULL;
    if ((new_deaths_data = (deaths_data *)calloc(1, sizeof(deaths_data))) == NULL)
    {
        printf("Erro: Não foi possível alocar o bloco de memória\n");
        exit(EXIT_FAILURE);
    }

    new_deaths_data->year_week = (char *)malloc(strlen(str_year_week) + 1);
    new_deaths_data->weekly_deaths = (int *)malloc(sizeof(int));
    new_deaths_data->total_deaths = (int *)malloc(sizeof(int));
    new_deaths_data->deaths_1M = (double *)malloc(sizeof(double));

    strcpy(new_deaths_data->year_week, str_year_week);
    memcpy(new_deaths_data->weekly_deaths, weekly_count, sizeof(int));
    memcpy(new_deaths_data->deaths_1M, rate_14_day, sizeof(double));
    memcpy(new_deaths_data->total_deaths, cumulative_count, sizeof(int));

    new_deaths_data->nextDD = NULL;

    //insert deaths_data
    deaths_data *aux_struct = NULL;

    if (i_country_data == NULL || i_country_data->nextDD == NULL)
    {
        if (i_country_data == NULL)
        {
            new_country_data->nextDD = new_deaths_data;
        }
        else
        {
            i_country_data->nextDD = new_deaths_data;
        }
    }
    else
    {
        aux_struct = i_country_data->nextDD;
        while (aux_struct->nextDD != NULL)
        {
            aux_struct = aux_struct->nextDD;
        }
        aux_struct->nextDD = new_deaths_data;
    }
}

void erros()
{
    printf("\nLeitura de Dados:\n");
    printf("•   -L   all\n          Leitura integral do ficheiro\n");
    printf("•   -L continente nome_do_continente\n          Apenas lê os dados relativos aos países do continente especificado com a opção.\n");
    printf("\nOrdenação de Dados:\n");
    printf("•   -S alfa\n          Ordenar por ordem alfabética de países\n");
    printf("•   -S pop\n          Ordenar por ordem decrescente de população de países\n");
    printf("•   -S inf yyyy-ww\n          Ordenar por ordem decrescente do número total de infetados por países numa determinadadata yyyy-ww\n");
    printf("•   -S dea yyyy-ww\n         Ordenar por ordem decrescente do número total de mortes por países numa determinada data yyyy-ww\n");
    printf("\nSeleção de Dados\n");
    printf("•   -D inf\n          Selecionar para cada país a semana com mais infectados\n");
    printf("•   -D dea\n          Selecionar para cada país a semana com mais mortes\n");
    printf("•   -D racioinf\n          Selecionar para cada país a semana com maior rácio de infectados por 100000 habitantes.\n");
    printf("•   -D raciodea\n          Selecionar para cada país a semana com maior rácio de mortes por milhão de habitantes.\n");
    printf("\nRestrição de Dados\n");
    printf("•   -P min n\n          Apenas dados de países com mais de n mil habitantes (sendo n um inteiro)\n");
    printf("•   -P max n\n          Apenas dados de países com menos de n mil habitantes (sendo n um inteiro)\n");
    printf("•   -P date yyyy-ww\n          Apenas dados relativos à semana indicada\n");
    printf("•   -P dates yyyy-ww yyyy-ww\n          Apenas dados entre as semanas indicadas\n");
    printf("\nOpções de Leitura e Escrita em Ficheiros\n");
    printf("•   -i filename.csv\n          Leitura de dados de ficheiro de texto\n");
    printf("•   -i filename.dat\n          Leitura de dados de ficheiro binário (compatível com a opção de escrita em ficheiros de dados desenvolvida). Esta opção funciona apenas para importação de dados sem qualquer especificação de outra opção do tipo -L, -S, -D ou -P.\n");
    printf("•   -o filename.csv\n          Escrita de dados em ficheiro de texto\n");
    printf("•   -o filename.dat\n          Escrita de dados em ficheiro binário. A forma como são armazenados os dados é uma opção de desenvolvimento (garantido que o que é escrito corresponde à forma como os dados estão codificados em memória e não em formato de texto) e deve ser compatível com a opção de leitura do ficheiro .dat\n");
    printf("\nNota:A invocação do programa deve conter obrigatoriamente as opções -i e -o.\n\n");
}

void free_list(country_data *ListHead)
{
    country_data *Aux;
    deaths_data *AuxHeadD, *AuxD;
    cases_data *AuxHeadC, *AuxC;

    Aux = ListHead;
    while (ListHead != NULL)
    {
        Aux = ListHead;
        ListHead = ListHead->nextC;

        AuxHeadD = Aux->nextDD;
        AuxD = AuxHeadD;
        while (AuxHeadD != NULL)
        {
            AuxD = AuxHeadD;
            AuxHeadD = AuxHeadD->nextDD;
            free(AuxD->year_week);
            free(AuxD->weekly_deaths);
            free(AuxD->total_deaths);
            free(AuxD->deaths_1M);
            free(AuxD);
        }
        AuxHeadC = Aux->nextCD;
        AuxC = AuxHeadC;
        while (AuxHeadC != NULL)
        {
            AuxC = AuxHeadC;
            AuxHeadC = AuxHeadC->nextCD;
            free(AuxC->year_week);
            free(AuxC->weekly_cases);
            free(AuxC->total_cases);
            free(AuxC->cases_100m);
            free(AuxC);
        }
        free(Aux->country);
        free(Aux->country_code);
        free(Aux->continent);
        free(Aux->population);
        free(Aux);
    }
}

country_data *troca(country_data *left, country_data *right)
{
    left->nextC = right->nextC;
    right->nextC = left;
    return right;
}
