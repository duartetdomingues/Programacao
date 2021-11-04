#include "covid19.h"

void write_file(char *out_filename, country_data *list_head)
{
    int len_country = 0, len_country_code = 0, len_continent = 0, len_year_week = 0, len_indicator = 0, int_population = 0, int_weekly_count = 0, int_cumulative_count = 0;
    double double_rate_14_day = 0;
    country_data *Aux;
    cases_data *Aux_a;
    deaths_data *Aux_b;

    FILE *fp_out = NULL;
    int i = 0;

    if (strstr(out_filename, ".dat") != NULL)
    {
        //escrever em binario
        fp_out = fopen(out_filename, "wb");

        for (Aux = list_head; Aux != NULL; Aux = Aux->nextC)
        {
            i++; //contador de estruturas principais
        }
        fwrite(&i, sizeof(int), 1, fp_out); //contador de estruturas principais
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

            len_country = strlen(Aux->country) + 1;
            len_country_code = strlen(Aux->country_code) + 1;
            len_continent = strlen(Aux->continent) + 1;

            fwrite(&len_country, sizeof(int), 1, fp_out);
            fwrite(Aux->country, len_country, 1, fp_out);

            fwrite(&len_country_code, sizeof(int), 1, fp_out);
            fwrite(Aux->country_code, len_country_code, 1, fp_out);

            fwrite(&len_continent, sizeof(int), 1, fp_out);
            fwrite(Aux->continent, len_continent, 1, fp_out);

            int_population = *Aux->population;
            fwrite(&int_population, sizeof(int), 1, fp_out);

            for (Aux_a = Aux->nextCD; Aux_a != NULL; Aux_a = Aux_a->nextCD)
            {
                len_year_week = strlen(Aux_a->year_week) + 1;
                len_indicator = strlen("cases") + 1;

                fwrite(&len_indicator, sizeof(int), 1, fp_out);
                fwrite("cases", sizeof("cases"), 1, fp_out);

                int_weekly_count = *Aux_a->weekly_cases;
                fwrite(&int_weekly_count, sizeof(int), 1, fp_out);

                fwrite(&len_year_week, sizeof(int), 1, fp_out);
                fwrite(Aux_a->year_week, len_year_week, 1, fp_out);

                double_rate_14_day = *Aux_a->cases_100m;
                fwrite(&double_rate_14_day, sizeof(double), 1, fp_out);

                int_cumulative_count = *Aux_a->total_cases;
                fwrite(&int_cumulative_count, sizeof(int), 1, fp_out);
            }
            for (Aux_b = Aux->nextDD; Aux_b != NULL; Aux_b = Aux_b->nextDD)
            {
                len_year_week = strlen(Aux_b->year_week) + 1;
                len_indicator = strlen("deaths") + 1;

                fwrite(&len_indicator, sizeof(int), 1, fp_out);
                fwrite("deaths", sizeof("deaths"), 1, fp_out);

                int_weekly_count = *Aux_b->weekly_deaths;
                fwrite(&int_weekly_count, sizeof(int), 1, fp_out);

                fwrite(&len_year_week, sizeof(int), 1, fp_out);
                fwrite(Aux_b->year_week, len_year_week, 1, fp_out);

                double_rate_14_day = *Aux_b->deaths_1M;
                fwrite(&double_rate_14_day, sizeof(double), 1, fp_out);

                int_cumulative_count = *Aux_b->total_deaths;
                fwrite(&int_cumulative_count, sizeof(int), 1, fp_out);
            }
        }
    }
    else if (strstr(out_filename, ".csv") != NULL)
    {

        fp_out = fopen(out_filename, "w");

        fprintf(fp_out, "country,country_code,continent,population,indicator,weekly_count,year_week,rate_14_day,cumulative_count\n");
        for (Aux = list_head; Aux != NULL; Aux = Aux->nextC)

        {
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
    }
    else
    {
        printf("\n-1: Formato de criação de ficheiro inválido. Introduza um formato válido (.csv ou .dat).");
    }
    fclose(fp_out);
}