#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char country[25], country_code[4], continent[8], indicator[7], year_week[8];
    int population, weekly_count, cumulative_count;
    float rate_14_day;
} linha;

void read(linha * linha_n)
{

    int a = 1;

    char cabecario[8][20];

    FILE *fp;

    if ((fp = fopen("covid19_w_t01.csv", "r")) == NULL)
    {
        printf("Erro na abertura do ficheiro");
        exit - 1;
    }

    char buf[110];
    fgets(buf, 110, fp);

    sscanf(buf, "%[^,\n],%[^,\n],%[^,\n],%[^,\n],%[^,\n],%[^,\n],%[^,\n],%[^,\n],%[^,\n]", cabecario[0], cabecario[1], cabecario[2], cabecario[3], cabecario[4], cabecario[5], cabecario[6], cabecario[7], cabecario[8]);
    printf("\n%s,%s,%s,%s,%s,%s,%s,%s,%s\n", cabecario[0], cabecario[1], cabecario[2], cabecario[3], cabecario[4], cabecario[5], cabecario[6], cabecario[7], cabecario[8]);

    while (!feof(fp))
    {
        fgets(buf, 90, fp);
        sscanf(buf, " %[^,\n],%[^,\n],%[^,\n],%d,%[^,\n],%d,%[^,\n],%f,%d", linha_n[a].country, linha_n[a].country_code, linha_n[a].continent, &linha_n[a].population, linha_n[a].indicator, &linha_n[a].weekly_count, linha_n[a].year_week, &linha_n[a].rate_14_day, &linha_n[a].cumulative_count);
        printf("\n%d.   %s  -  %s  -  %s  -  %d  -  %s  -  %d  -  %s  -  %.7f  -  %d", a, linha_n[a].country, linha_n[a].country_code, linha_n[a].continent, linha_n[a].population, linha_n[a].indicator, linha_n[a].weekly_count, linha_n[a].year_week, linha_n[a].rate_14_day, linha_n[a].cumulative_count);
        a++;
    }

    fclose(fp);
}

void write(linha * linha_n){
    int a=0; 
    FILE *fp;

    if ((fp = fopen("text.txt", "w")) == NULL)
    {
        printf("Erro na abertura do ficheiro");
        exit - 1;
    }
  for(a=1;a<=978;a++){
        fprintf(fp,"\n%d.   %s   %s   %s   %d   %s   %d   %s   %.7f %d",a,linha_n[a].country,linha_n[a].country_code,linha_n[a].continent,linha_n[a].population,linha_n[a].indicator,linha_n[a].weekly_count,linha_n[a].year_week,linha_n[a].rate_14_day,linha_n[a].cumulative_count);
    }

}

int main()
{

    linha *linha_n = malloc(980 * sizeof *linha_n);

    read(linha_n);
    write(linha_n);

    printf("\n\nexit\n\n");
    return 0;
}




