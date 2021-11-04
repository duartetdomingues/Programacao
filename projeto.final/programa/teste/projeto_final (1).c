//#include "covid.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//char *country[980],*country_code[980],*continent[980], *indicator[980],*year_week[980];
//int *population[980],*weekly_count[980],*cumulative_count[980];
//float *rate_14_day[980];
char pais, codigo_pais, continente, coluna5[128], coluna6[128], coluna7[128], coluna8[128], coluna9[128];
char new_country, new_country_code, new_continent;
char cabecalho[8][20], chr;
int populacao;
int new_population;
int n=0; //n linhas
void insert_fixed_data();
void remove_duplicate_elements();
void print_fixed_data();

int main()
{   
    struct fixed_data* head = NULL;

    FILE *fp;

    if ((fp = fopen("covid19_w_t01.csv", "r")) == NULL)
    {
        printf("Erro na abertura do ficheiro");
        exit (1);
    }

    while (chr != EOF)      //contagem de linhas
    {
        chr = getc(fp);
        if (chr == '\n')
        {
            n++;
        }
    }

    fclose(fp);

    //printf("O numero de linhas é %d", n);

    fp = fopen("covid19_w_t01.csv", "r");

    fscanf(fp, "%[^,\n],%[^,\n],%[^,\n],%[^,\n],%[^,\n],%[^,\n],%[^,\n],%[^,\n],%[^,\n]", cabecalho[0], cabecalho[1], cabecalho[2], cabecalho[3], cabecalho[4], cabecalho[5], cabecalho[6], cabecalho[7], cabecalho[8]);
    printf("\n%s,%s,%s,%s,%s,%s,%s,%s,%s\n", cabecalho[0], cabecalho[1], cabecalho[2], cabecalho[3], cabecalho[4], cabecalho[5], cabecalho[6], cabecalho[7], cabecalho[8]);

    int i;

    for (i=0; i<(n-1); i++)
    {   
        char country, country_code, continent;
        int population;
        fscanf(fp,"%c", country);
        //printf("%s,%s,%s,%d",country, country_code, continent, population);
        insert_fixed_data(&head,country,country_code,continent,population);
    }

    remove_duplicate_elements(&head);

    printf("\n");

    print_fixed_data(head);
    
    return 0;
}

    struct fixed_data //não repetir dados deste tipo, remover duplicados
    {
        char country, country_code, continent;
        int population;
        struct fixed_data *next;
    };

    void insert_fixed_data(struct fixed_data** head, char new_country, char new_country_code, char new_continent, int new_population)
    {
        struct fixed_data *new_fixed_data = (struct fixed_data*)malloc(sizeof(struct fixed_data));
        /*memcpy(new_fixed_data->country,new_country , sizeof(new_fixed_data->country));
        memcpy(new_fixed_data->country_code,new_country_code, sizeof(new_fixed_data->country_code));
        memcpy(new_fixed_data->continent,new_continent , sizeof(new_fixed_data->continent))*/
        new_fixed_data-> country = new_country; 
        new_fixed_data-> country_code = new_country_code; 
        new_fixed_data-> continent = new_continent; 
        new_fixed_data-> population = new_population; 
        new_fixed_data-> next = (*head);  //antes estava *head
        (*head) = new_fixed_data; //antes estava *head
    }

    void print_fixed_data(struct fixed_data *fixed_data)
    {
        while (fixed_data != NULL)
        {
            printf("%c\n", fixed_data->country);
            printf("%c\n", fixed_data->country_code);
            printf("%c\n", fixed_data->continent);
            printf("%d\n", fixed_data->population);
            fixed_data = fixed_data->next;
        }
    }

    /*void remove_duplicate_elements(struct fixed_data *temp)
    {
        struct fixed_data *ptr1, *ptr2, *duplicate;
        ptr1 = temp;

        while (ptr1 != NULL && ptr1->next != NULL)
        {
            ptr2=ptr1;

            while (ptr2->next != NULL)
            {
                if(ptr1->country == ptr2->next->country)
                {
                    duplicate = ptr2->next;
                    ptr2->next = ptr2->next->next;
                    delete(duplicate);
                }
                else
                {
                    ptr2 = ptr2->next;
                }
            }
            ptr1 = ptr1->next;
        }
    }*/

    void remove_duplicate_elements(struct fixed_data* head)
    {
        /* Pointer to traverse the linked list */
        struct fixed_data* current = head;
 
        /* Pointer to store the next pointer of a node to be deleted*/
        struct fixed_data* next_next;
   
        /* do nothing if the list is empty */
        if (current == NULL)
        return;
 
        /* Traverse the list till last node */
        while (current->next != NULL)
        {
       /* Compare current node with next node */
        if (current->country == current->next->country)
        {
           /* The sequence of steps is important*/              
           next_next = current->next->next;
           free(current->next);
           current->next = next_next; 
        }
        else /* This is tricky: only advance if no deletion */
        {
             current = current->next;
        }
        }
    }