#include "covid19.h"

country_data *read_file(char *in_filename, char *leitura, char *selecao, char *restricao, int *restricao_populacao, char *restricao_data, char *restricao_data_2, country_data *list_head)
/*
####################################################################################################
Função read: está função recebe x argumentos de um ficheiro externo do formato .csv ou .dat lendo-os e posicionando os na estrutura de dados a medida que os lê, esta função recorre a função data_structure_placement() para guardar a informação na estrutura de dados
####################################################################################################
*/
{
    int *weekly_count, *cumulative_count, *int_population = 0;
    char *str_country, *str_country_code, *str_continent, *indicator = NULL, *str_year_week, *cabecalho;
    double *rate_14_day;

    FILE *fp_in = NULL;

    //alocação de memoria dinâmica para as variáveis que serão usadas
    str_country = (char *)malloc(50 * sizeof(char));
    str_country_code = (char *)malloc(25 * sizeof(char));
    str_continent = (char *)malloc(25 * sizeof(char));
    int_population = (int *)malloc(sizeof(int));
    indicator = (char *)malloc(25 * sizeof(char));
    weekly_count = (int *)malloc(sizeof(int));
    str_year_week = (char *)malloc(25 * sizeof(char));
    rate_14_day = (double *)malloc(sizeof(double));
    cumulative_count = (int *)malloc(sizeof(int));

    if (strstr(in_filename, ".csv") != NULL)
    {
        if ((fp_in = fopen(in_filename, "r")) == NULL)
        {
            printf("Erro na abertura do ficheiro\n");
            exit(1);
        }

        char *line;
        line = (char *)malloc(120 * sizeof(char));
        cabecalho = (char *)malloc(120 * sizeof(char));
        if (fgets(line, 110, fp_in) != 0)
        {
            sscanf(line, "%s", cabecalho);
        }
        free(cabecalho);

        while (fgets(line, 90, fp_in) != 0)
        {
            if (strstr(line, ",,") == NULL)
            {

                if(sscanf(line, " %[^,],%[^,],%[^,],%d,%[^,],%d,%[^,],%lf,%d\n", str_country, str_country_code, str_continent, int_population, indicator, weekly_count, str_year_week, rate_14_day, cumulative_count)==EOF){
                    fprintf(stderr, "\n-1 Erro de Leitura.\n");
                    exit (1);
                }
            }
            else
            {
                if(sscanf(line, " %[^,],%[^,],%[^,],%d,%[^,],%d,%[^,],,%d\n", str_country, str_country_code, str_continent, int_population, indicator, weekly_count, str_year_week, cumulative_count)==EOF){
                    fprintf(stderr, "\n-1 Erro de Leitura.\n");
                    exit (1);
                }
                memset(rate_14_day, 0, sizeof(*rate_14_day));
            }

            list_head = data_structure_placement(leitura, selecao, restricao, restricao_populacao, restricao_data, restricao_data_2, list_head, str_country, str_country_code, str_continent, int_population, indicator, weekly_count, str_year_week, rate_14_day, cumulative_count, in_filename);
        }
        free(line); 
    }
    else if (strstr(in_filename, ".dat") != NULL)
    {
        int i = 0, j = 0, num_country, num_cases, num_deaths;
        int len_country = 0, len_country_code = 0, len_continent = 0, len_indicator = 0, len_year_week = 0;
        int f;

        if ((fp_in = fopen(in_filename, "rb")) == NULL)
        {
            printf("Erro na abertura do ficheiro\n");
            exit(1);
        }

        f += fread(&num_country, sizeof(int), 1, fp_in); //ler o numero de estruturas de paises
        for (i = 0; i != num_country; i++)
        {
            f += fread(&num_cases, sizeof(int), 1, fp_in);  //ler o numero de estruturas de cases
            f += fread(&num_deaths, sizeof(int), 1, fp_in); //ler o numero de estruturas de deaths
            f += fread(&len_country, sizeof(int), 1, fp_in);

            str_country = (char *)malloc(len_country);
            f += fread(&(*str_country), len_country, 1, fp_in);

            f += fread(&len_country_code, sizeof(int), 1, fp_in);
            str_country_code = (char *)malloc(len_country_code);
            f += fread(&(*str_country_code), len_country_code, 1, fp_in);

            f += fread(&len_continent, sizeof(int), 1, fp_in);
            str_continent = (char *)malloc(len_continent);
            f += fread(&(*str_continent), len_continent, 1, fp_in);

            int_population = (int *)malloc(sizeof(int));
            f += fread(&(*int_population), sizeof(int), 1, fp_in);

            for (j = 0; j != (num_cases + num_deaths); j++)
            {
                f = +fread(&len_indicator, sizeof(int), 1, fp_in);
                indicator = (char *)malloc(len_indicator);
                f = +fread(&(*indicator), len_indicator, 1, fp_in);

                weekly_count = (int *)malloc(sizeof(int));
                f += fread(&(*weekly_count), sizeof(int), 1, fp_in);

                f += fread(&len_year_week, sizeof(int), 1, fp_in);
                str_year_week = (char *)malloc(len_year_week);
                f += fread(&(*str_year_week), len_year_week, 1, fp_in);

                rate_14_day = (double *)malloc(sizeof(double));
                f += fread(&(*rate_14_day), sizeof(double), 1, fp_in);

                cumulative_count = (int *)malloc(sizeof(int));
                f += fread(&(*cumulative_count), sizeof(int), 1, fp_in);

                list_head = data_structure_placement(leitura, selecao, restricao, restricao_populacao, restricao_data, restricao_data_2, list_head, str_country, str_country_code, str_continent, int_population, indicator, weekly_count, str_year_week, rate_14_day, cumulative_count, in_filename);
            }
        }
    }
    else
    {
        printf("-1: Erro na leitura do formato. Formato não aceite.");
    }
    free(str_country);
    free(str_country_code);
    free(str_continent);
    free(int_population);
    free(indicator);
    free(weekly_count);
    free(str_year_week);
    free(rate_14_day);
    free(cumulative_count);
    return list_head;
}
