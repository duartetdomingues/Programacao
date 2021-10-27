#include "covid.h"

void read(){

    int a;

    //char cabecario;
    //cabecario *cabecario_ptr = malloc(sizeof(char *) * 8 * 20);

    char cabecario[8][20];
    //cabecario = (char *)malloc(sizeof(char *) * 8 );
    

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

    while (!feof(fp)){
        fgets(buf, 90, fp);
        sscanf(buf, " %[^,\n],%[^,\n],%[^,\n],%d,%[^,\n],%d,%[^,\n],%f,%d", linha_n[a].country, linha_n[a].country_code, linha_n[a].continent, &linha_n[a].population, linha_n[a].indicator, &linha_n[a].weekly_count, linha_n[a].year_week, &linha_n[a].rate_14_day, &linha_n[a].cumulative_count);
        printf("\n%d.   %s  -  %s  -  %s  -  %d  -  %s  -  %d  -  %s  -  %.7f  -  %d", a, linha_n[a].country, linha_n[a].country_code, linha_n[a].continent, linha_n[a].population, linha_n[a].indicator, linha_n[a].weekly_count, linha_n[a].year_week, linha_n[a].rate_14_day, linha_n[a].cumulative_count);
        a++;
    }

    fclose(fp);

}


