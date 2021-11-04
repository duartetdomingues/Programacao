#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

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

void read(char *, char *, char *, char *,int*,char *, char *);
int selection(char*,char*,char*,country_data*,char*,int*,int*,double*);
int restriction(char*,char*,char*,char*,int*,int*);
int restriction_date(char *, char *, char *,char*);
void order();
void erros();

country_data *check_country(country_data *, char *);
country_data *create_country_data(char *, char *, char *, int *,char *, int *, int *, double *, country_data *,char*,char*);
cases_data *create_cases_data(char *, int *, int *, double *,country_data *,country_data *);
deaths_data *create_deaths_data(char *, int *, int *, double *,country_data *,country_data *);


void print_list(country_data *);

//as que ainda faltam:
/*country_data *remove_pais(country_data *, char *);
void free_list(country_data *, country_data *);
country_data *ordena_lista(country_data *);
country_data *troca(country_data *, country_data *);*/

int main(int argc, char *argv[])
{

    char option;
    char *filename, *leitura, *selecao = NULL, *restricao = NULL, *restricao_data = NULL, *restricao_data_2 = NULL;
    int *restricao_populacao;

    filename = (char *)malloc(256 * sizeof(char));
    leitura = (char *)malloc(8 * sizeof(char));
    selecao = (char *)malloc(9 * sizeof(char));
    restricao = (char *)malloc(9 * sizeof(char));
    restricao_populacao = (int *)malloc(6*sizeof(int));
    restricao_data = (char *)malloc(20 * sizeof(char));
    restricao_data_2 = (char *)malloc(20 * sizeof(char));
    

    strcpy(leitura, "all");
    strcpy(filename, "covid19_w_tf01.csv");       //apagar....................................................................
    strcpy(selecao, "");                  //apagar....................................................................
    *restricao_populacao=50000;                 //apagar....................................................................
    *restricao_populacao*=1000;                 //apagar....................................................................
    strcpy(restricao, "min");                   //apagar....................................................................
    strcpy(restricao_data, "2021-01");                   //apagar....................................................................
    strcpy(restricao_data_2, "2020-50"); 


    while ((option = getopt(argc, argv, "i:L:D:P:S:o:")) != -1)
    { // ler as opções escritas pelo utilizador na consola
        switch (option)
        {
        case 'i':

            sscanf(optarg, "%s", filename);
            filename = realloc(filename, sizeof(filename));

            break;

        case 'L':
            sscanf(optarg, "%s", leitura);
            leitura = realloc(leitura, sizeof(leitura));
            break;

        case 'D':
            sscanf(optarg, "%s", selecao);
            selecao = realloc(selecao, sizeof(selecao));
            break;

        case 'P':
            sscanf(optarg, "min %d",restricao_populacao);
            restricao_populacao = realloc(restricao_populacao, 5* sizeof(restricao_populacao));
           /*  &&sscanf(optarg, "min %d",restricao_populacao);
            sscanf(optarg, "min %d",restricao,restricao_populacao);
            sscanf(optarg, "min %d",restricao,restricao_populacao); */


            /* if(strcmp(optarg, "min") == 0){
            printf("read restriçao population\n");    
            strcpy(restricao, "min");
            
            *restricao_populacao*=1000;
            } */

            /* sscanf(optarg, "%s", restricao);
            
            restricao = realloc(restricao, sizeof(restricao));
            //restricao_data = realloc(restricao_data, sizeof(restricao_data));
            if(strcmp(restricao,"min")==0 || strcmp(restricao,"max")==0){
                
                printf("optarg:%s",optarg);
                sscanf(optarg, "min %d", restricao_populacao);
                
            }
            
            if(strcmp(restricao,"date")==0){
                sscanf(optarg, "%s", restricao_data); 
            }
            if(strcmp(restricao,"dates")==0){
                sscanf(optarg, "%s,%s",restricao_data,restricao_data_2);
            } */
            
            printf(".....%d\n",*restricao_populacao);
            break;

        case 'S':

            break;

        case 'o':

            break;
        }
        
    }

    //filename = (char *)malloc(sizeof(filename));

    read(filename, leitura, selecao, restricao,restricao_populacao,restricao_data ,restricao_data_2);
    //selection();
    //restriction();
    //order();

    printf("\n\nexit\n\n");
    return 0;
}

void read(char *filename, char *leitura, char *selecao,char * restricao,int * restricao_populacao,char * restricao_data,char * restricao_data_2)
{
    country_data *list_head = NULL, *i_country_data,*new_country_data;
    cases_data *new_cases_data;
    deaths_data *new_deaths_data;

    int check, i = 0, *weekly_count, *cumulative_count, *int_population;
    char cabecalho[9][20], *str_country, *str_country_code, *str_continent, *indicator, *str_year_week;
    double *rate_14_day;

    str_country = (char *)malloc(50 * sizeof(char));
    str_country_code = (char *)malloc(25 * sizeof(char));
    str_continent = (char *)malloc(25 * sizeof(char));
    indicator = (char *)malloc(25 * sizeof(char));
    str_year_week = (char *)malloc(25 * sizeof(char));

    weekly_count = (int *)malloc(25 * sizeof(int));
    cumulative_count = (int *)malloc(25 * sizeof(int));
    int_population = (int *)malloc(25 * sizeof(int));

    rate_14_day = (double *)malloc(25 * sizeof(double));

    FILE *fp;

    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("Erro na abertura do ficheiro");
        exit - 1;
    }

    char *line;
    line = (char *)malloc(120 * sizeof(char));
    fgets(line, 110, fp);
    sscanf(line, "%[^,\n],%[^,\n],%[^,\n],%[^,\n],%[^,\n],%[^,\n],%[^,\n],%[^,\n],%[^,\n]", cabecalho[0], cabecalho[1], cabecalho[2], cabecalho[3], cabecalho[4], cabecalho[5], cabecalho[6], cabecalho[7], cabecalho[8]);
    printf("\n%s,%s,%s,%s,%s,%s,%s,%s,%s\n", cabecalho[0], cabecalho[1], cabecalho[2], cabecalho[3], cabecalho[4], cabecalho[5], cabecalho[6], cabecalho[7], cabecalho[8]);

    while (fgets(line, 90, fp) != 0)
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

        //void erros aqui
        void erros();
        (i_country_data = check_country(list_head, str_country)); //search_country;
        
        if (strcmp(leitura, "all") == 0 || strcmp(leitura, str_continent) == 0)
        {
            if (i_country_data == NULL) //cria um novo pais na lista principal (e consequentemente uma lista deaths ou data)
            {
                if (selection(indicator,selecao,restricao,i_country_data,str_year_week,weekly_count,cumulative_count,rate_14_day) == 0 && restriction(restricao_data,restricao_data_2 ,str_year_week,restricao,restricao_populacao,int_population) == 0){ //se houver selecao selection(indicator,selecao,restricao,i_country_data,str_year_week,weekly_count,cumulative_count,rate_14_day) == 0
                    //printf("%d,%d\n",*restricao_populacao,*int_population);
                    list_head = create_country_data(str_country, str_country_code, str_continent, int_population,str_year_week, weekly_count, cumulative_count,rate_14_day, list_head,indicator,selecao);           
                }
            }
            else//adiciona a um pais ja existente
            {   
                country_data *new_country_data = NULL;

                if (strcmp(indicator, "cases") == 0)//adiciona uma lista cases
                {
                    if(selection(indicator,selecao,restricao,i_country_data,str_year_week,weekly_count,cumulative_count,rate_14_day)==0 && restriction(restricao_data,restricao_data_2 ,str_year_week,restricao,restricao_populacao,int_population) == 0){//quando foi especificado um tipo de seleção (esta void testará se também foi selecionado)
                        if(strcmp(selecao, "") != 0){
                        free(i_country_data->nextCD);
                        i_country_data->nextCD=NULL; //fecho da lista
                        }
                        create_cases_data(str_year_week, weekly_count, cumulative_count, rate_14_day,i_country_data,new_country_data);
                        if(strcmp(selecao, "inf") == 0){
                            memcpy(i_country_data->nextCD->weekly_cases,weekly_count,sizeof(int));
                        }
                        if (strcmp(selecao, "racioinf") == 0){
                            memcpy(i_country_data->nextCD->cases_100m,rate_14_day,sizeof(double));
                        }
                    }
                }
                if (strcmp(indicator, "deaths") == 0){ //adiciona uma lista deaths
                    if(selection(indicator,selecao,restricao,i_country_data,str_year_week,weekly_count,cumulative_count,rate_14_day)==0 && restriction(restricao_data,restricao_data_2 ,str_year_week,restricao,restricao_populacao,int_population) == 0){//quando foi especificado um tipo de seleção (esta void testará se também foi selecionado)
                        if(strcmp(selecao, "") != 0){   
                            free(i_country_data->nextDD);
                            i_country_data->nextDD=NULL; //fecho da lista
                        }
                        create_deaths_data(str_year_week, weekly_count, cumulative_count, rate_14_day,i_country_data,new_country_data);
                        if(strcmp(selecao, "dea") == 0){
                            memcpy(i_country_data->nextDD->weekly_deaths,weekly_count,sizeof(int));
                        }
                        if(strcmp(selecao, "raciodea") == 0){
                            memcpy(i_country_data->nextDD->deaths_1M,rate_14_day,sizeof(double));
                        }
                    }  
                }
            }
        }
        i++;
    }
    print_list(list_head);
    fclose(fp);
}

int selection(char* indicator,char*selecao,char*restricao,country_data*i_country_data,char*str_year_week,int*weekly_count,int*cumulative_count,double*rate_14_day){
    
    country_data* new_country_data=NULL;
    if(strcmp(selecao, "") == 0){
        return 0;
    }
    if(strcmp(indicator, "cases") == 0 && (strcmp(selecao, "inf") == 0 || strcmp(selecao, "racioinf") == 0)){
        if(i_country_data==NULL){
            return 0;
        }
        if((*i_country_data->nextCD->weekly_cases < *weekly_count) && (strcmp(selecao, "inf") == 0)){//se for -D inf
            return 0;
        }
        if((*i_country_data->nextCD->cases_100m < *rate_14_day) && (strcmp(selecao, "racioinf") == 0)){ //se for -D racioinf
            return 0;
        }
 
    }
    if(strcmp(indicator, "deaths") == 0 && (strcmp(selecao, "dea") == 0 || strcmp(selecao, "raciodea") == 0)){
        if(i_country_data==NULL){
            return 0;
        }
        if ((*i_country_data->nextDD->weekly_deaths < *weekly_count)  && (strcmp(selecao, "dea") == 0)){
                return 0; 
                free(i_country_data->nextDD);
                i_country_data->nextDD=NULL; //fecho da lista
                create_deaths_data(str_year_week, weekly_count, cumulative_count, rate_14_day,i_country_data,new_country_data);
                memcpy(i_country_data->nextDD->weekly_deaths,weekly_count,sizeof(int));
         }
        if((*i_country_data->nextDD->deaths_1M < *rate_14_day) && (strcmp(selecao, "raciodea") == 0)){
                return 0;
                free(i_country_data->nextDD);
                i_country_data->nextDD=NULL; //fecho da lista
                create_deaths_data(str_year_week, weekly_count, cumulative_count, rate_14_day,i_country_data,new_country_data);
                memcpy(i_country_data->nextDD->deaths_1M,rate_14_day,sizeof(double));
            }
        
    }
    return 1;//isto e preciso??
}

int restriction(char * restricao_data,char * restricao_data_2 ,char * str_year_week,char * restricao,int* restricao_populacao,int* int_population){
    int sem_a=0,ano_a=0,sem_b=0,ano_b=0,sem_c=0,ano_c=0,temp=0;
    
    
    if(strcmp(restricao,"") == 0){
        return 0;
    }
    else if (strcmp(restricao, "min") == 0){
        if(*int_population<*restricao_populacao){ 
            return 1;
        }
        else{
            return 0;
            }
    }
    else if(strcmp(restricao, "max") == 0){
         if(*int_population>*restricao_populacao){ 
            return 1;
        }
        else{
            return 0;
            }
    }
    else if(strcmp(restricao,"date") == 0){
            if(strcmp(restricao_data,str_year_week)!=0){
                return 1;
            }
            else{
                return 0;
            }
    }
    else if(strcmp(restricao,"dates") == 0){
        sscanf(str_year_week,"%d-%d", &ano_b, &sem_b);
        sscanf(restricao_data,"%d-%d", &ano_a, &sem_a);
        sscanf(restricao_data_2,"%d-%d", &ano_c, &sem_c);
        sem_a += ano_a*52 + ano_a/7;  //total semanas += (1 ano tem 52 semanas e 1 dia)
        sem_b += ano_b*52 + ano_b/7;
        sem_c += ano_c*52 + ano_c/7;

        if(sem_a>sem_c){ //trocar as datas
            temp=sem_a; 
            sem_a=sem_c;
            sem_c=temp;
            
        }
        if((sem_a<=sem_b) && (sem_b<=sem_c)){
            return 0;
        }
        else {
            return 1 ;
        }
    }
}

country_data *check_country(country_data *list_head, char *str_country)
{

    int flag = 0;

    if (list_head != NULL)
    {
        country_data *aux_struct;
        aux_struct = list_head;
        while (aux_struct != NULL && flag == 0)
        {
            if (strcmp(aux_struct->country, str_country) == 0)
            {
                return aux_struct;
            }
            aux_struct = aux_struct->nextC;
        }
    }
    country_data *aux_struct = NULL;
    return aux_struct;
}

country_data *create_country_data(char *str_country, char *str_country_code, char *str_continent, int *int_population,char *str_year_week, int *weekly_count, int *cumulative_count, double *rate_14_day, country_data *list_head,char* indicator,char*selecao)
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
    country_data *i_country_data=NULL;
    cases_data *new_cases_data;
    deaths_data *new_deaths_data;
    if (strcmp(indicator, "cases") == 0) //cria novo pais quando não foi selecionado nada e, se foi, apenas cria se se selecionou ou "inf" ou "racioinf"
    {
        create_cases_data(str_year_week, weekly_count, cumulative_count,rate_14_day,i_country_data,new_country_data);
            
    }
    else if (strcmp(indicator, "deaths") == 0)
    {
        create_deaths_data(str_year_week, weekly_count, cumulative_count, rate_14_day,i_country_data,new_country_data);                    
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

cases_data *create_cases_data(char *str_year_week, int *weekly_count, int *cumulative_count, double *rate_14_day, country_data *i_country_data,country_data *new_country_data )
{
    cases_data *new_cases_data = NULL;
    if ((new_cases_data = (cases_data *)calloc(1000, sizeof(cases_data))) == NULL)
    {
        printf("Erro: Não foi possível alocar o bloco de memória\n");
        exit(EXIT_FAILURE);
    }

    new_cases_data->year_week = (char *)malloc(150 * sizeof(char));
    new_cases_data->weekly_cases = (int *)malloc(10 * sizeof(int));
    new_cases_data->total_cases = (int *)malloc(10 * sizeof(int));
    new_cases_data->cases_100m = (double *)malloc(150 * sizeof(double));

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

deaths_data *create_deaths_data(char *str_year_week, int *weekly_count, int *cumulative_count, double *rate_14_day,country_data *i_country_data, country_data *new_country_data)
{
    deaths_data *new_deaths_data = NULL;
    if ((new_deaths_data = (deaths_data *)calloc(1000, sizeof(deaths_data))) == NULL)
    {
        printf("Erro: Não foi possível alocar o bloco de memória\n");
        exit(EXIT_FAILURE);
    }

    new_deaths_data->year_week = (char *)malloc(150 * sizeof(char));
    new_deaths_data->weekly_deaths = (int *)malloc(10 * sizeof(int));
    new_deaths_data->total_deaths = (int *)malloc(10 * sizeof(int));
    new_deaths_data->deaths_1M = (double *)malloc(150 * sizeof(double));

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

void print_list(country_data *list_head){
    country_data *Aux;
    cases_data *Aux1;
    deaths_data *Aux2;
    int i = 1;

    for (Aux = list_head; Aux != NULL; Aux = Aux->nextC)
    {
        //printf("\n%d - %s,%s,%s,%d,\n", i, Aux->country, Aux->country_code, Aux->continent, *Aux->population);
        for (Aux1 = Aux->nextCD; Aux1 != NULL; Aux1 = Aux1->nextCD)
        {
            printf("%d - %s,%s,%s,%d,", i, Aux->country, Aux->country_code, Aux->continent, *Aux->population);
            printf("cases,%d,%s,%lf,%d\n", *Aux1->weekly_cases, Aux1->year_week, *Aux1->cases_100m, *Aux1->total_cases);
            i++;
        }

        for (Aux2 = Aux->nextDD; Aux2 != NULL; Aux2 = Aux2->nextDD)
        {
            printf("%d - %s,%s,%s,%d,", i, Aux->country, Aux->country_code, Aux->continent, *Aux->population);
            printf("deaths,%d,%s,%lf,%d\n", *Aux2->weekly_deaths, Aux2->year_week, *Aux2->deaths_1M, *Aux2->total_deaths);
            i++;
        }
    }
}

/* void erros(){
    if(strcmp(indicator,"deaths") != 0 && strcmp(indicator,"cases") != 0 ){
        printf("-1 Error:indicator\n");
        exit(1);
    }
} */

/* void free_list(country_data *i_country_data,country_data *list_head)
{
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

/*Student_Data *ordena_lista(Student_Data *ListHead)
{
    int trocas = 1;
    Student_Data *left, *right, *head, aux_struct;
    
    head = &aux_struct;
    head->next = ListHead;
    if ((ListHead != NULL ) && ((ListHead->next != NULL )))
    {
        while(trocas)
        {
            trocas = 0;
            left = head;
            right = head->next;
            while(right->next != NULL)
            {
                if (right->Nota_Final < right->next->Nota_Final)
                {
                    left->next = troca(right,right->next);
                    trocas = 1;
                }
                left = right;
                if (right->next != NULL)
                    right = right->next;
            }
        }
    }
    ListHead = head->next;
    return ListHead;*/