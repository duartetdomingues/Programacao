#include "covid19.h"

country_data *data_structure_placement(char *leitura, char *selecao, char *restricao, int *restricao_populacao, char *restricao_data, char *restricao_data_2, country_data *list_head, char *str_country, char *str_country_code, char *str_continent, int *int_population, char *indicator, int *weekly_count, char *str_year_week, double *rate_14_day, int *cumulative_count, char* in_filename)
/*
####################################################################################################
Função data_structure_placement: esta função e usada e chamada pela função read_line() para posicionar na estrutura de dados a informação retirada do ficheiro a medida que vai sendo lida. Está função encarrega-se pela formação de toda a lista horizontalmente e verticalmente nas suas duas vertentes.
####################################################################################################
*/
{
    country_data *i_country_data, *new_country_data = NULL;
    i_country_data = search_country(list_head, str_country); //search_country

    if (strcmp(leitura, "all") == 0 || strcmp(leitura, str_continent) == 0 || strstr(in_filename, ".dat") != NULL) //restrição de leitura
    {
        if (i_country_data == NULL) //cria um novo pais na lista principal (e consequentemente uma lista deaths ou data)
        {
            if ((selection(indicator, selecao, restricao, i_country_data, str_year_week, weekly_count, cumulative_count, rate_14_day) == 0 && restriction(restricao, restricao_populacao, restricao_data, restricao_data_2, int_population, str_year_week) == 0) || strstr(in_filename, ".dat") != NULL)
            { //se houver selecao
                list_head = create_country_data(str_country, str_country_code, str_continent, int_population, str_year_week, weekly_count, cumulative_count, rate_14_day, list_head, indicator, selecao); 
            }
        }
        else //adiciona a um pais ja existente
        {
            if (strcmp(indicator, "cases") == 0) //adiciona uma lista cases
            {
                if ((selection(indicator, selecao, restricao, i_country_data, str_year_week, weekly_count, cumulative_count, rate_14_day) == 0 && restriction(restricao, restricao_populacao, restricao_data, restricao_data_2, int_population, str_year_week) == 0) || strstr(in_filename, ".dat") != NULL)
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
                if ((selection(indicator, selecao, restricao, i_country_data, str_year_week, weekly_count, cumulative_count, rate_14_day) == 0 && restriction(restricao, restricao_populacao, restricao_data, restricao_data_2, int_population, str_year_week) == 0) || strstr(in_filename, ".dat") != NULL)
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
