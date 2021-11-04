
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
//#include <unistd.h>
#include <ctype.h>

typedef struct _cases_data
{
    char *year_week;
    int *weekly_cases, *total_cases;
    double *cases_100m;
    struct _cases_data *nextCD;
} cases_data;

typedef struct _deaths_data
{
    char *year_week;
    int *weekly_deaths, *total_deaths;
    double *deaths_1M;
    struct _deaths_data *nextDD;
} deaths_data;

typedef struct _country_data
{
    char *country, *country_code, *continent; //supostamente e 14 mas ver melhor
    int *population;
    cases_data *nextCD;
    deaths_data *nextDD;
    struct _country_data *nextC;
} country_data;

country_data *read(char *, char *, char *, char *, int *, char *, char *, country_data *, char *);
country_data *data_structure_placement(char *, char *, char *, int *, char *, char *, country_data *, char *, char *, char *, int *, char *, int *, char *, double *, int *);
int selection(char *, char *, char *, country_data *, char *, int *, int *, double *);
int restriction(char *, int *, char *, char *, int *, char *);
country_data *order(country_data *, char *, char *);
void erros();
country_data *troca(country_data *, country_data *);

country_data *search_country(country_data *, char *);

country_data *create_country_data(char *, char *, char *, int *, char *, int *, int *, double *, country_data *, char *, char *);
void create_cases_data(char *, int *, int *, double *, country_data *, country_data *);
void create_deaths_data(char *, int *, int *, double *, country_data *, country_data *);

void write(char *, country_data *, char *);

//as que ainda faltam:
/*country_data *remove_pais(country_data *, char *);
void free_list(country_data *, country_data *);
country_data *ordena_lista(country_data *);
country_data *troca(country_data *, country_data *);*/

int main(int argc, char *argv[])
{

    char option;
    char *in_filename = NULL, *out_filename = NULL, *leitura, *selecao = NULL, *restricao = NULL, *restricao_data = NULL, *restricao_data_2 = NULL, *ordenacao = NULL, *ordenacao_data, *cabecalho;
    int *restricao_populacao;
    country_data *list_head=NULL;

    in_filename = (char *)malloc(256 * sizeof(char));
    out_filename = (char *)malloc(256 * sizeof(char)); //ver apenas o maximo de espaco desnecessario e depois desalocá-lo!!
    leitura = (char *)malloc(8 * sizeof(char));
    selecao = (char *)malloc(9 * sizeof(char));
    restricao = (char *)malloc(9 * sizeof(char));
    restricao_populacao = (int *)malloc(6 * sizeof(int));
    restricao_data = (char *)malloc(20 * sizeof(char));
    restricao_data_2 = (char *)malloc(20 * sizeof(char));
    ordenacao = (char *)malloc(20 * sizeof(char));
    ordenacao_data = (char *)malloc(20 * sizeof(char));
    cabecalho = (char *)malloc(110 * sizeof(char));

    strcpy(leitura, "all");
    //strcpy(in_filename, "covid19_w_tf01.csv");
    strcpy(out_filename, "testes.csv"); //apagar....................................................................
    //strcpy(selecao, "dea");                            //apagar....................................................................               //apagar....................................................................
    //*restricao_populacao=50000*1000;                //apagar....................................................................
    //strcpy(restricao, "");                     //apagar....................................................................
    //strcpy(restricao_data, "2021-15");              //apagar....................................................................
    //strcpy(restricao_data_2, "2021-14");
    //strcpy(ordenacao,"alfa");
    //strcpy(ordenacao_data,"2021-14");

    while ((option = getopt(argc, argv, "i:L:D:P:S:o:")) != -1)
    { // ler as opções escritas pelo utilizador na consola
        switch (option)
        {
        case 'i':

            in_filename = optarg;
            //in_filename = (char *)realloc(in_filename, sizeof(in_filename));

            break;
        case 'o':

            out_filename = optarg;
            //out_filename = (char *)realloc(out_filename, sizeof(out_filename));

            break;
        case 'L':
            leitura = optarg;
            //leitura = (char *)realloc(leitura, sizeof(leitura));
            break;

        case 'D':
            selecao = optarg;
            //selecao = (char *)realloc(selecao, sizeof(selecao));
            break;

        case 'P':
            restricao = optarg;
            if (strcmp(restricao, "min") == 0 || strcmp(restricao, "max") == 0)
            {
                optind--;
                sscanf(argv[optind], "%d", restricao_populacao);
                *restricao_populacao = 50000 * 1000;
            }
            if (strcmp(restricao, "date") == 0 || strcmp(restricao, "dates") == 0){
                restricao_data=argv[optind];
                if(strcmp(restricao, "dates") == 0){
                    optind++;
                    restricao_data_2=argv[optind];
                }
            }
            break;

        case 'S':
            ordenacao= optarg;
            if (strcmp(ordenacao, "inf") == 0 || strcmp(ordenacao, "dea") == 0)
            {
                ordenacao_data =argv[optind];
            }
            break;

        case ':':
            if (optopt == 'i' || optopt == 'o')
            {
                fprintf(stderr, "> a opcao -%c requere um argumento.\n", optopt);
                return 1;
            }
        case '?':
            if (isprint(optopt))
            {
                fprintf(stderr, "> opcao `-%c' desconhecida.\n", optopt);
                return 1;
            }
        }
    }
    if (strcmp(in_filename, "") == 0 || strcmp(out_filename, "") == 0)
    {
        fprintf(stderr, "-i e -o são opcões obrigatórias.\n");
        exit(1);
    }

    //in_filename = (char *)malloc(sizeof(in_filename));

    //read(in_filename, leitura, selecao, restricao,restricao_populacao,restricao_data ,restricao_data_2, list_head,cabecalho);
    //selection();
    //restriction();
    list_head = read(in_filename, leitura, selecao, restricao, restricao_populacao, restricao_data, restricao_data_2, list_head, cabecalho);
    list_head = order(list_head, ordenacao, ordenacao_data);
    write(out_filename, list_head, cabecalho);
    return 0;
}

country_data *read(char *in_filename, char *leitura, char *selecao, char *restricao, int *restricao_populacao, char *restricao_data, char *restricao_data_2, country_data *list_head, char *cabecalho)
{

    int *weekly_count, *cumulative_count, *int_population;
    char *str_country, *str_country_code, *str_continent, *indicator, *str_year_week;
    double *rate_14_day;
    country_data *i_country_data=NULL, *new_country_data=NULL;

    char *line;
    line = (char *)malloc(120 * sizeof(char));

    FILE *fp_in;

    //alocação de memoria dinâmica para as variáveis que serão usadas

    if ((fp_in = fopen(in_filename, "r")) == NULL)
    {
        printf("Erro na abertura do ficheiro\n");
        exit(1);
    }
    if (strstr(in_filename, ".csv") != NULL)
    {
        str_country = (char *)malloc(50 * sizeof(char));
        str_country_code = (char *)malloc(25 * sizeof(char));
        str_continent = (char *)malloc(25 * sizeof(char));
        indicator = (char *)malloc(25 * sizeof(char));
        str_year_week = (char *)malloc(25 * sizeof(char));

        weekly_count = (int *)malloc(25 * sizeof(int));
        cumulative_count = (int *)malloc(25 * sizeof(int));
        int_population = (int *)malloc(25 * sizeof(int));

        rate_14_day = (double *)malloc(25 * sizeof(double));
        if(fgets(line, 110, fp_in)!=0){
            sscanf(line, "%s", cabecalho);
        }
        

        while (fgets(line, 90, fp_in) != 0)
        {
            if (strstr(line, ",,") == NULL)
            {
                sscanf(line, " %[^,],%[^,],%[^,],%d,%[^,],%d,%[^,],%lf,%d\n", str_country, str_country_code, str_continent, int_population, indicator, weekly_count, str_year_week, rate_14_day, cumulative_count);
                //printf("scan= %s,%s,%s,%d,%s,%d,%s,%lf,%d\n",str_country, str_country_code, str_continent, *int_population, indicator,*weekly_count,str_year_week,*rate_14_day,*cumulative_count);
            }
            else
            {
                sscanf(line, " %[^,],%[^,],%[^,],%d,%[^,],%d,%[^,],,%d\n", str_country, str_country_code, str_continent, int_population, indicator, weekly_count, str_year_week, cumulative_count);
                memset(rate_14_day, 0, sizeof(*rate_14_day));
                //printf("scan= %s,%s,%s,%d,%s,%d,%s,%lf,%d\n",str_country, str_country_code, str_continent, *int_population, indicator,*weekly_count,str_year_week,*rate_14_day,*cumulative_count);
            }

            list_head = data_structure_placement(leitura, selecao, restricao, restricao_populacao, restricao_data, restricao_data_2, list_head, str_country, str_country_code, str_continent, int_population, indicator, weekly_count, str_year_week, rate_14_day, cumulative_count);
            //void erros aqui
            //void erros();
        }
    }
    else if (strstr(in_filename, ".dat") != NULL)
    {
        int i=0, j=0, k=0, num_country, num_cases, num_deaths;
        int len_country=0, len_country_code=0, len_continent=0, len_year_week=0;
        fread(&num_country, sizeof(int), 1, fp_in); //ler o numero de estruturas de paises
            for (i = 0; i != num_country; i++)
            {
                fread(&num_cases, sizeof(int), 1, fp_in);                       //ler o numero de estruturas de cases
                fread(&num_deaths, sizeof(int), 1, fp_in);                      //ler o numero de estruturas de deaths

                fread(&len_country, sizeof(int), 1, fp_in);

                str_country = (char *)malloc(sizeof(len_country));
                fread(&str_country, len_country, 1, fp_in);

                fread(&len_country_code, sizeof(int), 1, fp_in);

                str_country_code = (char *)malloc(sizeof(len_country_code));
                fread(&str_country_code, len_country_code, 1, fp_in);

                fread(&len_continent, sizeof(int), 1, fp_in);

                str_continent = (char *)malloc(sizeof(len_continent));
                fread(&str_continent, len_continent, 1, fp_in);

                list_head= create_country_data(str_country, str_country_code, str_continent, int_population, str_year_week, weekly_count, cumulative_count, rate_14_day, list_head, indicator, selecao);
                for(j=0; j != num_cases; j++)
                {
                    fread(&len_year_week, sizeof(int), 1, fp_in); 

                    str_year_week = (char *)malloc(sizeof(len_year_week));
                    fread(&str_year_week, len_year_week, 1, fp_in);

                    fread(&weekly_count, sizeof(int), 1, fp_in);
                    fread(&cumulative_count, sizeof(int), 1, fp_in);
                    fread(&rate_14_day, sizeof(double), 1, fp_in);

                    create_cases_data(str_year_week, weekly_count, cumulative_count, rate_14_day, i_country_data, new_country_data);
                }
                for(k=0; k != num_deaths; k++)
                {
                    fread(&len_year_week, sizeof(int), 1, fp_in); 

                    str_year_week = (char *)malloc(sizeof(len_year_week));
                    fread(&str_year_week, len_year_week, 1, fp_in);

                    fread(&weekly_count, sizeof(int), 1, fp_in);
                    fread(&cumulative_count, sizeof(int), 1, fp_in);
                    fread(&rate_14_day, sizeof(double), 1, fp_in);

                    create_deaths_data(str_year_week, weekly_count, cumulative_count, rate_14_day, i_country_data, new_country_data);
                }
            }
    }
    else
    {
        printf("-1: Erro na leitura do formato. Formato não aceite."); //ERRO
    }
    fclose(fp_in);
    return list_head;
}

country_data *data_structure_placement(char *leitura, char *selecao, char *restricao, int *restricao_populacao, char *restricao_data, char *restricao_data_2, country_data *list_head, char *str_country, char *str_country_code, char *str_continent, int *int_population, char *indicator, int *weekly_count, char *str_year_week, double *rate_14_day, int *cumulative_count)
{

    country_data *i_country_data, *new_country_data = NULL;

    i_country_data = search_country(list_head, str_country); //search_country;

    if (strcmp(leitura, "all") == 0 || strcmp(leitura, str_continent) == 0) //restrição de leitura
    {
        if (i_country_data == NULL) //cria um novo pais na lista principal (e consequentemente uma lista deaths ou data)
        {
            if (selection(indicator, selecao, restricao, i_country_data, str_year_week, weekly_count, cumulative_count, rate_14_day) == 0 && restriction(restricao, restricao_populacao, restricao_data, restricao_data_2, int_population, str_year_week) == 0)
            { //se houver selecao
                list_head = create_country_data(str_country, str_country_code, str_continent, int_population, str_year_week, weekly_count, cumulative_count, rate_14_day, list_head, indicator, selecao);
            }
        }
        else //adiciona a um pais ja existente
        {
            if (strcmp(indicator, "cases") == 0) //adiciona uma lista cases
            {
                if (selection(indicator, selecao, restricao, i_country_data, str_year_week, weekly_count, cumulative_count, rate_14_day) == 0 && restriction(restricao, restricao_populacao, restricao_data, restricao_data_2, int_population, str_year_week) == 0)
                { //quando foi especificado um tipo de seleção (esta void testará se também foi selecionado)
                    if (strcmp(selecao, "") != 0)
                    {
                        free(i_country_data->nextCD);
                        i_country_data->nextCD = NULL; //fecho da lista
                    }
                    create_cases_data(str_year_week, weekly_count, cumulative_count, rate_14_day, i_country_data, new_country_data);
                    if (strcmp(selecao, "inf") == 0)
                    {
                        memcpy(i_country_data->nextCD->weekly_cases, weekly_count, sizeof(int));
                    }
                    if (strcmp(selecao, "racioinf") == 0)
                    {
                        memcpy(i_country_data->nextCD->cases_100m, rate_14_day, sizeof(double));
                    }
                }
            }
            if (strcmp(indicator, "deaths") == 0)
            { //adiciona uma lista deaths
                if (selection(indicator, selecao, restricao, i_country_data, str_year_week, weekly_count, cumulative_count, rate_14_day) == 0 && restriction(restricao, restricao_populacao, restricao_data, restricao_data_2, int_population, str_year_week) == 0)
                { //quando foi especificado um tipo de seleção (esta void testará se também foi selecionado)
                    if (strcmp(selecao, "") != 0)
                    {
                        free(i_country_data->nextDD);
                        i_country_data->nextDD = NULL; //fecho da lista
                    }
                    create_deaths_data(str_year_week, weekly_count, cumulative_count, rate_14_day, i_country_data, new_country_data);
                    if (strcmp(selecao, "dea") == 0)
                    {
                        memcpy(i_country_data->nextDD->weekly_deaths, weekly_count, sizeof(int));
                    }
                    if (strcmp(selecao, "raciodea") == 0)
                    {
                        memcpy(i_country_data->nextDD->deaths_1M, rate_14_day, sizeof(double));
                    }
                }
            }
        }
    }
    return list_head;
}

int selection(char *indicator, char *selecao, char *restricao, country_data *i_country_data, char *str_year_week, int *weekly_count, int *cumulative_count, double *rate_14_day)
{

    country_data *new_country_data = NULL;
    if (strcmp(selecao, "") == 0)
    {
        return 0;
    }
    if (strcmp(indicator, "cases") == 0 && (strcmp(selecao, "inf") == 0 || strcmp(selecao, "racioinf") == 0))
    {
        if (i_country_data == NULL)
        {
            return 0;
        }
        if ((*i_country_data->nextCD->weekly_cases < *weekly_count) && (strcmp(selecao, "inf") == 0))
        { //se for -D inf
            return 0;
        }
        if ((*i_country_data->nextCD->cases_100m < *rate_14_day) && (strcmp(selecao, "racioinf") == 0))
        { //se for -D racioinf
            return 0;
        }
    }
    if (strcmp(indicator, "deaths") == 0 && (strcmp(selecao, "dea") == 0 || strcmp(selecao, "raciodea") == 0))
    {
        if (i_country_data == NULL)
        {
            return 0;
        }
        if ((*i_country_data->nextDD->weekly_deaths < *weekly_count) && (strcmp(selecao, "dea") == 0))
        {
            return 0;
            free(i_country_data->nextDD);
            i_country_data->nextDD = NULL; //fecho da lista
            create_deaths_data(str_year_week, weekly_count, cumulative_count, rate_14_day, i_country_data, new_country_data);
            memcpy(i_country_data->nextDD->weekly_deaths, weekly_count, sizeof(int));
        }
        if ((*i_country_data->nextDD->deaths_1M < *rate_14_day) && (strcmp(selecao, "raciodea") == 0))
        {
            return 0;
            free(i_country_data->nextDD);
            i_country_data->nextDD = NULL; //fecho da lista
            create_deaths_data(str_year_week, weekly_count, cumulative_count, rate_14_day, i_country_data, new_country_data);
            memcpy(i_country_data->nextDD->deaths_1M, rate_14_day, sizeof(double));
        }
    }
    return 1;
}

int restriction(char *restricao, int *restricao_populacao, char *restricao_data, char *restricao_data_2, int *int_population, char *str_year_week)
{
    int sem_a = 0, ano_a = 0, sem_b = 0, ano_b = 0, sem_c = 0, ano_c = 0, temp = 0;
    if (strcmp(restricao, "") == 0)
    {
        return 0;
    }
    else if (strcmp(restricao, "min") == 0)
    {
        if (*int_population < *restricao_populacao)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (strcmp(restricao, "max") == 0)
    {
        if (*int_population > *restricao_populacao)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (strcmp(restricao, "date") == 0)
    {
        if (strcmp(restricao_data, str_year_week) != 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (strcmp(restricao, "dates") == 0)
    {
        sscanf(str_year_week, "%d-%d", &ano_b, &sem_b);
        sscanf(restricao_data, "%d-%d", &ano_a, &sem_a);
        sscanf(restricao_data_2, "%d-%d", &ano_c, &sem_c);
        sem_a += ano_a * 52 + ano_a / 7; //total semanas += (1 ano tem 52 semanas e 1 dia)
        sem_b += ano_b * 52 + ano_b / 7;
        sem_c += ano_c * 52 + ano_c / 7;

        if (sem_a > sem_c)
        { //trocar as datas
            temp = sem_a;
            sem_a = sem_c;
            sem_c = temp;
        }
        if ((sem_a <= sem_b) && (sem_b <= sem_c))
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
return 1;
}

country_data *search_country(country_data *list_head, char *str_country)
{
    country_data *auxstruct;
    auxstruct = list_head;
    int flag = 0;

    if (list_head != NULL)
    {

        //
        //memcpy(aux_struct,list_head);
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
    new_country_data->country = (char *)malloc(150 * sizeof(char));
    new_country_data->country_code = (char *)malloc(150 * sizeof(char));
    new_country_data->continent = (char *)malloc(150 * sizeof(char));
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
    if ((new_cases_data = (cases_data *)calloc(1000, sizeof(cases_data))) == NULL)
    {
        printf("Erro: Não foi possível alocar o bloco de memória\n");
        exit(EXIT_FAILURE);
    }

    new_cases_data->year_week = (char *)malloc(150 * sizeof(char));
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
    if ((new_deaths_data = (deaths_data *)calloc(1000, sizeof(deaths_data))) == NULL)
    {
        printf("Erro: Não foi possível alocar o bloco de memória\n");
        exit(EXIT_FAILURE);
    }

    new_deaths_data->year_week = (char *)malloc(8 * sizeof(char)); //por memory allocation erro if(!new_deaths_data->year_week)
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
            new_country_data->nextDD = new_deaths_data; //cria um pais novo
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

void write(char *out_filename, country_data *list_head, char *cabecalho)
{
    int len_country, len_country_code, len_continent, len_year_week;
    country_data *Aux;
    cases_data *Aux_a;
    deaths_data *Aux_b;

    FILE *fp_out;

    int i = 0;

    if (strstr(out_filename, ".dat") != NULL)
    {
        //escrever em binario
        if ((fp_out = fopen(out_filename, "w")) == NULL)
        {
            printf("-1: Erro na criação do ficheiro");
            exit(1);
        }
        else
        {
            for (Aux = list_head; Aux != NULL; Aux = Aux->nextC)
            {
                i++; //contador de estruturas principais
            }
            fwrite(&i, sizeof(int), 1, fp_out);
            i = 0;
            for (Aux = list_head; Aux != NULL; Aux = Aux->nextC)
            {
                for (Aux_a = Aux->nextCD; Aux_a != NULL; Aux_a = Aux_a->nextCD)
                {
                    i++;
                }
                fwrite(&i, sizeof(int), 1, fp_out); //contador de estruturas cases do pais
                i = 0;
                for (Aux_b = Aux->nextDD; Aux_b != NULL; Aux_b = Aux_b->nextDD)
                {
                    i++;
                }
                fwrite(&i, sizeof(int), 1, fp_out); //contador de estruturas deaths do pais
                i = 0;

                //str_country
                //escrever o numero de nodes para cases e deaths deste pais.
                len_country = strlen(Aux->country) + 1;
                len_country_code = strlen(Aux->country) + 1;
                len_continent = strlen(Aux->country) + 1;
                //len_population = strlen(Aux->country)+1;

                fwrite(&len_country, sizeof(int), 1, fp_out);
                fwrite(Aux->country, sizeof(len_country), 1, fp_out);

                fwrite(&len_country_code, sizeof(int), 1, fp_out);
                fwrite(Aux->country_code, sizeof(len_country_code), 1, fp_out);

                fwrite(&len_continent, sizeof(int), 1, fp_out);
                fwrite(Aux->country_code, sizeof(len_continent), 1, fp_out);

                fwrite(&Aux->population, sizeof(int), 1, fp_out);

                for (Aux_a = Aux->nextCD; Aux_a != NULL; Aux_a = Aux_a->nextCD)
                {
                    len_year_week = strlen(Aux_a->year_week) + 1;

                    fwrite(&len_country, sizeof(int), 1, fp_out);
                    fwrite(Aux_a->year_week, sizeof(len_year_week), 1, fp_out);

                    fwrite(&Aux_a->weekly_cases, sizeof(int), 1, fp_out);

                    fwrite(&Aux_a->total_cases, sizeof(int), 1, fp_out);

                    fwrite(&Aux_a->cases_100m, sizeof(double), 1, fp_out);
                }
                for (Aux_b = Aux->nextDD; Aux_b != NULL; Aux_b = Aux_b->nextDD)
                {
                    len_year_week = strlen(Aux_b->year_week) + 1;

                    fwrite(&len_country, sizeof(int), 1, fp_out);
                    fwrite(Aux_b->year_week, sizeof(len_year_week), 1, fp_out);

                    fwrite(&Aux_b->weekly_deaths, sizeof(int), 1, fp_out);

                    fwrite(&Aux_b->total_deaths, sizeof(int), 1, fp_out);

                    fwrite(&Aux_b->deaths_1M, sizeof(double), 1, fp_out);
                }
            }
        }
    }
    else if (strstr(out_filename, ".csv") != NULL)
    {
        if ((fp_out = fopen(out_filename, "w")) == NULL)
        {
            printf("-1: Erro na criação do ficheiro");
            exit(1);
        }
        else
        {
            fprintf(fp_out, "%s\n", cabecalho);
            for (Aux = list_head; Aux != NULL; Aux = Aux->nextC)
            {
                //printf("\n%d - %s,%s,%s,%d,\n", i, Aux->country, Aux->country_code, Aux->continent, *Aux->population);
                for (Aux_a = Aux->nextCD; Aux_a != NULL; Aux_a = Aux_a->nextCD)
                {
                    fprintf(fp_out, "%s,%s,%s,%d,", Aux->country, Aux->country_code, Aux->continent, *Aux->population);
                    fprintf(fp_out, "cases,%d,%s,%lf,%d\n", *Aux_a->weekly_cases, Aux_a->year_week, *Aux_a->cases_100m, *Aux_a->total_cases);
                }

                for (Aux_b = Aux->nextDD; Aux_b != NULL; Aux_b = Aux_b->nextDD)
                {
                    fprintf(fp_out, "%s,%s,%s,%d,", Aux->country, Aux->country_code, Aux->continent, *Aux->population);
                    fprintf(fp_out, "deaths,%d,%s,%lf,%d\n", *Aux_b->weekly_deaths, Aux_b->year_week, *Aux_b->deaths_1M, *Aux_b->total_deaths);
                }
            }
            //printf("\nO ficheiro %s com a especificação indicada foi criado com sucesso!\n", out_filename);
        }
    }
    else
    {
        printf("\n-1: Formato de criação de ficheiro inválido. Introduza um formato válido (.csv ou .dat).");
        /* printf("%s\n", cabecalho);
        for (Aux = list_head; Aux != NULL; Aux = Aux->nextC)
        {
            //printf("\n%d - %s,%s,%s,%d,\n", i, Aux->country, Aux->country_code, Aux->continent, *Aux->population);
            for (Aux_a = Aux->nextCD; Aux_a != NULL; Aux_a = Aux_a->nextCD)
            {
                printf("%d - %s,%s,%s,%d,", i, Aux->country, Aux->country_code, Aux->continent, *Aux->population);
                printf("cases,%d,%s,%lf,%d\n", *Aux_a->weekly_cases, Aux_a->year_week, *Aux_a->cases_100m, *Aux_a->total_cases);
                i++;
            }

            for (Aux_b = Aux->nextDD; Aux_b != NULL; Aux_b = Aux_b->nextDD)
            {
                printf("%d - %s,%s,%s,%d,", i, Aux->country, Aux->country_code, Aux->continent, *Aux->population);
                printf("deaths,%d,%s,%lf,%d\n", *Aux_b->weekly_deaths, Aux_b->year_week, *Aux_b->deaths_1M, *Aux_b->total_deaths);
                i++;
            }
        } */
    }
}

/* void erros(){
    if(strcmp(indicator,"deaths") != 0 && strcmp(indicator,"cases") != 0 ){
        printf("-1 Error:indicator\n");
        exit(1);
    }
} */

/* void free_list(country_data *i_country_data,country_data *list_head){
    country_data *pre_country_data,*Aux,*Aux2;

    //for(Aux=list_head;Aux != NULL;Aux = Aux->nextC){Aux2=Aux}
    Aux=list_head;
    while(Aux != NULL){ Aux2=Aux;Aux = Aux->nextC;}
        Aux2->nextC=NULL; 
        //free(i_country_data);
        free(i_country_data->nextCD);
        //free(Aux2->nextC);
        //free(Aux->nextCD);
        //Aux->nextC=NULL
} */

country_data *order(country_data *list_head, char *ordenacao, char *ordenacao_data)
{

    int trocas = 1, empate = 0;
    char str_a[256], str_b[256];

    country_data *left, *right, *head, aux_struct;
    cases_data *c_aux_a, *c_aux_b;
    deaths_data *d_aux_a, *d_aux_b;
    head = &aux_struct;
    head->nextC = list_head;
    if ((list_head != NULL) && (list_head->nextC != NULL))
    {
        while (trocas)
        {
            trocas = 0;
            left = head;
            right = head->nextC;
            while (right->nextC != NULL)
            {
                empate = 0;
                if (strcmp(ordenacao, "pop") == 0)
                {
                    if (*right->population < *right->nextC->population)
                    {
                        left->nextC = troca(right, right->nextC);
                        trocas = 1;
                    }
                    else if (*right->population == *right->nextC->population)
                    {
                        empate = 1;
                    } 
                }
                if (strcmp(ordenacao, "inf") == 0)
                {
                    c_aux_a = right->nextCD;
                    while (strcmp(c_aux_a->year_week, ordenacao_data) != 0)
                    {
                        c_aux_a = c_aux_a->nextCD;
                    }

                    c_aux_b = right->nextC->nextCD;
                    while (strcmp(c_aux_b->year_week, ordenacao_data) != 0)
                    {
                        c_aux_b = c_aux_b->nextCD;
                    }
                    if (*c_aux_a->weekly_cases < *c_aux_b->weekly_cases)
                    {
                        left->nextC = troca(right, right->nextC);
                        trocas = 1;
                    }
                    else if (*c_aux_a->weekly_cases == *c_aux_b->weekly_cases)
                    {
                        empate = 1;
                    }
                }
                if (strcmp(ordenacao, "dea") == 0)
                {
                    d_aux_a = right->nextDD;
                    while (strcmp(d_aux_a->year_week, ordenacao_data) != 0)
                    {
                        d_aux_a = d_aux_a->nextDD;
                    }

                    d_aux_b = right->nextC->nextDD;
                    while (strcmp(d_aux_b->year_week, ordenacao_data) != 0)
                    {
                        d_aux_b = d_aux_b->nextDD;
                    }
                    if (*d_aux_a->weekly_deaths < *d_aux_b->weekly_deaths)
                    {
                        left->nextC = troca(right, right->nextC);
                        trocas = 1;
                    }
                    else if (*d_aux_a->weekly_deaths == *d_aux_b->weekly_deaths)
                    {
                        empate = 1;
                    }
                }
                if (strcmp(ordenacao, "alfa") == 0 || empate == 1)
                {
                    strncpy(str_a, right->country, 255*sizeof(char));
                    strncpy(str_b, right->nextC->country, 255*sizeof(char));
                    if (strcmp(str_a, str_b) > 0)
                    {
                        left->nextC = troca(right, right->nextC);
                        trocas = 1;
                    }
                }
                left = right;
                if (right->nextC != NULL)
                {
                    right = right->nextC;
                }
            }
        }
    }
    list_head = head->nextC;
    return list_head;
}

country_data *troca(country_data *left, country_data *right)
{
    left->nextC = right->nextC;
    right->nextC = left;
    return right;
}
