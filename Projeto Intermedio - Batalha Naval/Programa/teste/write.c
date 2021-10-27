#include "covid.h"

void write(struct linha *linha_n){
    int a=0; 
    FILE *fp;

    if ((fp = fopen("text.txt", "w")) == NULL)
    {
        printf("Erro na abertura do ficheiro");
        exit - 1;
    }
  for(a=1;a<=978;a++){
        fprintf(fp,"\n%d.   %s   %s   %s   %d   %s   %d   %s   %.7f %d",a,linha_n[a].country,linha_n[a].country_code,linha_n[a].continent,*linha_n[a].population,linha_n[a].indicator,*linha_n[a].weekly_count,linha_n[a].year_week,*linha_n[a].rate_14_day,*linha_n[a].cumulative_count);
    }

}