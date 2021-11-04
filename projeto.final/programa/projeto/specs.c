#include "covid19.h"

/*
####################################################################################################
int_selection() e int restriction() são funções binárias que funcionam como flags que testam as condições de seleção e restrição do utilizador. O funcionamento destas voids está melhor explicado no relatório. É crucial assimilar que uma função não impede o funcionamento da outra dado que quando não é especificado um dos parâmetros esta assume o valor 0 permitindo que a outra função trabalhe livremente.
####################################################################################################
*/
int selection(char *indicator, char *selecao, char *restricao, country_data *i_country_data, char *str_year_week, int *weekly_count, int *cumulative_count, double *rate_14_day)
{
    country_data *new_country_data = NULL; 

    if (strcmp(selecao, "") == 0)
    {
        return 0;
    }

    if (((strcmp(indicator, "cases") == 0) && (strcmp(selecao, "inf") == 0)) || (strcmp(selecao, "racioinf") == 0))
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

country_data *order(country_data *list_head, char *ordenacao, char *ordenacao_data)
/*
####################################################################################################
a void order() ordena a list ordenada segundo os parâmetros especificados pelo utilizador
####################################################################################################
*/
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
                    strncpy(str_a, right->country, 255 * sizeof(char));
                    strncpy(str_b, right->nextC->country, 255 * sizeof(char));
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