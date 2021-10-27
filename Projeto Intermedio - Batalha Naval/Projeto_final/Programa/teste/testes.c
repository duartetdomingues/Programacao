#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
typedef struct _country_data
{
    char country[25], country_code[4], continent[8], indicator[7], year_week[8];
    int population, weekly_count, cases_100m, deaths_1M,cumulative_count;
    float rate_14_day;
    struct country_data * next;
} country_data;*/

typedef struct _pais_data{
    char country[25], country_code[3], continent[8], **year_week;
    int population,*weekly_cases,*weekly_deaths,*total_cases,*total_deaths;
    float *cases_100m,*deaths_1M;
    struct _pais_data * next;
}pais_data; 



void read(char*);
pais_data *cria_pais(int);
pais_data *insert_pais(pais_data *, pais_data *);
pais_data *insert_pais_end(pais_data *, pais_data *);
//pais_data *insert_pais_top(pais_data *, pais_data *);
//pais_data *remove_pais(pais_data *, char*);
void write(pais_data *);
void free_list(pais_data *);
pais_data *ordena_lista(pais_data *);
pais_data *troca(pais_data*, pais_data*);


int main(){
    char *filename= "covid19_w_t01.csv" ;
    filename = (char *)malloc(sizeof(filename));
    read(filename);
    //write();

    printf("\n\nexit\n\n");
    return 0;
}*/

void read(char *filename)
{

    int n,n_linha,n_pais;
    char cabecario[8][20];
    int weekly_count,rate_14_day,cumulative_count;
    char indicator,str_year_week;~
    
    pais_data *ListHead = NULL, *NewStudent;

    FILE *fp;

    if ((fp = fopen("covid19_w_t01.csv", "r")) == NULL)
    {
        printf("Erro na abertura do ficheiro");
        exit - 1;
    }
    

    fscanf(fp, "%[^,\n],%[^,\n],%[^,\n],%[^,\n],%[^,\n],%[^,\n],%[^,\n],%[^,\n],%[^,\n]", cabecario[0], cabecario[1], cabecario[2], cabecario[3], cabecario[4], cabecario[5], cabecario[6], cabecario[7], cabecario[8]);
    printf("\n%s,%s,%s,%s,%s,%s,%s,%s,%s\n", cabecario[0], cabecario[1], cabecario[2], cabecario[3], cabecario[4], cabecario[5], cabecario[6], cabecario[7], cabecario[8]);

    char buf[90];
    while (fgets(buf, 90, fp) != 0)
    {
        sscanf(buf,"[^,\n],[^,\n],",code_contry,code_country);
        for(n=1;n<=n_pais;n++){
            if(code_country = country_code)
        }

        
        //aloc coutry
         if (n_linha == 1)
        {
            if ((* = (char **) malloc(sizeof(char *))) == NULL)
            {
                printf("Erro: Não foi possível alocar o bloco de memória\n");
                exit(EXIT_FAILURE);
            }
        }
        else
            if ((*Student_ID = (char **) realloc(*Student_ID, (*NAlunos) * sizeof(char *))) == NULL)
            {
                printf("Erro: Não foi possível realocar o bloco de memória\n");
                exit(EXIT_FAILURE);
            }
        printf("\n%d.   %s  -  %s  -  %s  -  %d  -  %s  -  %d  -  %s  -  %.7f  -  %d",n_linha , country, country_code, continent, *population, indicator, *weekly_count, year_week, *rate_14_day, *cumulative_count);
        
    }
    
    fclose(fp);
}

/*void write(linha *linha_n)
{
    int a = 0;
    FILE *fp;

    if ((fp = fopen("text.txt", "w")) == NULL)
    {
        printf("Erro na abertura do ficheiro");
        exit - 1;
    }
    for (a = 1; a <= 978; a++)
    {
        fprintf(fp, "\n%d.   %s   %s   %s   %d   %s   %d   %s   %.7f %d", a, country, country_code, continent, population, indicator, weekly_count, year_week, rate_14_day, cumulative_count);
    }
}
*/

int main(){


    FILE *fp;

    if ((fp = fopen("covid19_w_t01.csv", "r")) == NULL)
    {
        printf("Erro na abertura do ficheiro");
        exit - 1;
    }
    int n=0;
    n++;
    char buf[256];
    while (fgets(buf, 256, fp) != 0){n++;}
    printf("\n%d\n",n);

}