#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float max(float, float);
char **cria_alunos(int, int);
void cria_alunos2(int, int, char***);
float **cria_pauta(int, int);
void cria_pauta2(int, int, float***);
void Class_Final(float *);
void Print_Pauta(char **, float **, int);
void liberta_mem(void **, int);
void Pauta_to_File1(char *,char **, float **, int);
int File_to_Pauta1(char *);
int File_to_Pauta2(char *);
int File_to_Pauta3(char *);
int File_to_Pauta4(char *);
int File_to_Pauta5(char *);
int File_to_Pauta_AlocDin(char *,char ***, float **, int *);
void Print_PautaFinal(char **,float *, int);
void mem_map(char *, int);

int main()
{
    float **Pauta, *NotaFinal;
    char **Student_ID;
    int NAlunos, NAprovados, ID_Size = 20, NNotas = 7;

    printf("Insira o num. de alunos: ");
    scanf("%d",&NAlunos);
//    Student_ID = cria_alunos(NAlunos, ID_Size);
    cria_alunos2(NAlunos, ID_Size, &Student_ID);
//    Pauta = cria_pauta(NAlunos, NNotas);
    cria_pauta2(NAlunos, NNotas, &Pauta);
    Print_Pauta(Student_ID, Pauta, NAlunos);
    Pauta_to_File1("PautaProg1819.txt",Student_ID, Pauta, NAlunos);
    liberta_mem((void**) Student_ID,NAlunos);
    liberta_mem((void**) Pauta,NAlunos);
//    File_to_Pauta1("PautaProg1819.txt");
//    File_to_Pauta2("PautaProg1819.txt");
//    File_to_Pauta3("PautaProg1819.txt");
//    File_to_Pauta4("PautaProg1819.txt");
//    File_to_Pauta5("PautaProg1819.txt");
    File_to_Pauta_AlocDin("PautaProg1819.txt",&Student_ID, &NotaFinal, &NAprovados);
    Print_PautaFinal(Student_ID, NotaFinal, NAprovados);
    liberta_mem((void**) Student_ID,NAprovados);
    free(NotaFinal);
    return 0;
}

void Pauta_to_File1(char *Filename,char **Student_ID, float **Pauta, int NAlunos)
{
    FILE *fp;
    int i = 0;

    fp = fopen(Filename,"w");
    while (i++ < NAlunos)
    {
        if(Pauta[i-1][6] >= 9.5)
            fprintf(fp,"%s %4.2f\n", Student_ID[i-1],Pauta[i-1][6] );
    }
    fclose(fp);
}

int File_to_Pauta1(char *Filename)
{
    FILE *fp;
    int c;

    printf("Reading File %s with FGETC(fp)\n",Filename);
    if ((fp = fopen(Filename,"r"))== NULL)
    {
        printf("Erro na abertura do ficheiro");
        return-1;
    }
    while ((c=fgetc(fp))!= EOF)
    {
        printf("%c",c);
    }
    fclose(fp);
    return 0;
}

int File_to_Pauta2(char *Filename)
{
    FILE *fp;
    char str[20];

    printf("Reading File %s with FGETS(str, 20, fp)\n",Filename);
    if ((fp = fopen(Filename,"r"))== NULL)
    {
        printf("Erro na abertura do ficheiro");
        return-1;
    }
    while (fgets(str, 20, fp)!= NULL)
    {
        printf("%s",str);
    }
    fclose(fp);
    return 0;
}

int File_to_Pauta3(char *Filename)
{
    FILE *fp;
    char str1[10];

    printf("Reading File %s with FSCANF(fp,\"%%[^\\n]%%*c\",str1)\n",Filename);
    if ((fp = fopen(Filename,"r"))== NULL)
    {
        printf("Erro na abertura do ficheiro");
        return-1;
    }
    while (fscanf(fp,"%[^\n]%*c",str1)!= EOF)
    {
        printf("%s\n",str1);
    }
    fclose(fp);
    return 0;
}

int File_to_Pauta4(char *Filename)
{
    FILE *fp;
    char str1[10], str2[10];

    printf("Reading File %s with FSCANF(fp,\"%%10s %%10s\",str1, str2)\n",Filename);
    if ((fp = fopen(Filename,"r"))== NULL)
    {
        printf("Erro na abertura do ficheiro");
        return-1;
    }
    while (fscanf(fp,"%10s %10s",str1, str2)!= EOF)
    {
        printf("%s %s\n",str1, str2);
    }
    fclose(fp);
    return 0;
}

int File_to_Pauta5(char *Filename)
{
    FILE *fp;
    char str1[10];
    float flt1;

    printf("Reading File %s with FSCANF(fp,\"%%s %%f\",str1, &flt1)\n",Filename);
    if ((fp = fopen(Filename,"r"))== NULL)
    {
        printf("Erro na abertura do ficheiro");
        return-1;
    }
    while (fscanf(fp,"%s %f",str1, &flt1)!= EOF)
    {
        printf("%s %4.2f\n",str1, flt1);
    }
    fclose(fp);
    return 0;
}

int File_to_Pauta_AlocDin(char *Filename,char ***Student_ID, float **NFinal, int *NAlunos)
{
    FILE *fp;
    char str1[10];
    float flt1;

    printf("Reading File %s with FSCANF() with DinAloc\n",Filename);
    if ((fp = fopen(Filename,"r"))== NULL)
    {
        printf("Erro na abertura do ficheiro");
        return-1;
    }
    *NAlunos = 0;
    while (fscanf(fp,"%s %f",str1, &flt1)!= EOF)
    {
        (*NAlunos)++;
        if (*NAlunos == 1)
        {
            if ((*Student_ID = (char **) malloc(sizeof(char *))) == NULL)
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
        if (((*Student_ID)[(*NAlunos)-1] = (char *) malloc(10*sizeof(char))) == NULL)
        {
            printf("Erro: Não foi possível alocar o bloco de memória\n");
            exit(EXIT_FAILURE);
        }
        strcpy((*Student_ID)[(*NAlunos)-1],str1);
        if (*NAlunos == 1)
        {
            if ((*NFinal = (float *) malloc(sizeof(float))) == NULL)
            {
                printf("Erro: Não foi possível alocar o bloco de memória\n");
                exit(EXIT_FAILURE);
            }
        }
        else
            if ((*NFinal = (float *) realloc(*NFinal, (*NAlunos) * sizeof(float))) == NULL)
            {
                printf("Erro: Não foi possível realocar o bloco de memória\n");
                exit(EXIT_FAILURE);
            }
        (*NFinal)[(*NAlunos)-1] = flt1;
    }
    fclose(fp);
    return 0;
}



char **cria_alunos(int NAlunos, int ID_Size)
{
    int l;
    char **Std_ID;

    if ((Std_ID = (char **) malloc(NAlunos*sizeof(char *))) == NULL)
    {
        printf("Erro: Não foi possível alocar o bloco de memória\n");
        exit(EXIT_FAILURE);
    }
    for(l=0; l<NAlunos; l++)
        if ((Std_ID[l] = (char *) malloc(ID_Size*sizeof(char))) == NULL)
        {
            printf("Erro: Não foi possível alocar o bloco de memória\n");
            exit(EXIT_FAILURE);
        }
    for(l = 1; l <= NAlunos; l++)
    {
        sprintf(Std_ID[l-1],"ISTID_%03d",l);
    }
    return Std_ID;
}

void cria_alunos2(int NAlunos, int ID_Size, char ***Std_ID)
{
    int l;
    char **Std_ID_Aux;

    if ((Std_ID_Aux = (char **) malloc(NAlunos*sizeof(char *))) == NULL)
    {
        printf("Erro: Não foi possível alocar o bloco de memória\n");
        exit(EXIT_FAILURE);
    }
    for(l=0; l<NAlunos; l++)
        if ((Std_ID_Aux[l] = (char *) malloc(ID_Size*sizeof(char))) == NULL)
        {
            printf("Erro: Não foi possível alocar o bloco de memória\n");
            exit(EXIT_FAILURE);
        }
    for(l = 1; l <= NAlunos; l++)
    {
        sprintf(Std_ID_Aux[l-1],"ISTID_%03d",l);
    }
    *Std_ID = Std_ID_Aux;
}

float **cria_pauta(int NAlunos, int NNotas)
{
    int l, c;
    float **Pauta, value;

    if ((Pauta = (float **) malloc(NAlunos*sizeof(float *))) == NULL)
    {
        printf("Erro: Não foi possível alocar o bloco de memória\n");
        exit(EXIT_FAILURE);
    }
    for(l=0; l<NAlunos; l++)
        if ((Pauta[l] = (float*) malloc(NNotas*sizeof(float))) == NULL)
        {
            printf("Erro: Não foi possível alocar o bloco de memória\n");
            exit(EXIT_FAILURE);
        }
    for(l = 1; l <= NAlunos; l++)
    {
        for(c = 1; c <= NNotas-1; c++)
        {
            value = (float) (rand()%2100)/100;
            if (value >= 20 )
                value = -1;
            Pauta[l-1][c-1] = value;
        }
        Class_Final(Pauta[l-1]);
    }
    return Pauta;
}

void cria_pauta2(int NAlunos, int NNotas, float ***Pauta)
{
    int l, c;
    float value;

    if ((*Pauta = (float **) malloc(NAlunos*sizeof(float *))) == NULL)
    {
        printf("Erro: Não foi possível alocar o bloco de memória\n");
        exit(EXIT_FAILURE);
    }
    for(l=0; l<NAlunos; l++)
        if (((*Pauta)[l] = (float*) malloc(NNotas*sizeof(float))) == NULL)
        {
            printf("Erro: Não foi possível alocar o bloco de memória\n");
            exit(EXIT_FAILURE);
        }
    for(l = 1; l <= NAlunos; l++)
    {
        for(c = 1; c <= NNotas-1; c++)
        {
            value = (float) (rand()%2100)/100;
            if (value >= 20 )
                value = -1;
            (*Pauta)[l-1][c-1] = value;
        }
        Class_Final((*Pauta)[l-1]);
    }
}

void liberta_mem(void **matriz, int linhas)
{
    int i;

    for(i=0; i<linhas; i++)
        free(matriz[i]);
    free(matriz);
}

float max(float i, float j)
{
    if (i>j)
        return i;
    return j;
}

void Class_Final(float c_nota[])
{
    c_nota[6] = 0;
    if ((c_nota[0] != -1) && (c_nota[1] != -1) && (c_nota[2] != -1) && \
        ((c_nota[5] != -1) || ((c_nota[3] != -1) && (c_nota[4] != -1))))
        if ((c_nota[2] >= 9.5) && ((c_nota[2]*0.6 + c_nota[1]*0.4) >= 9.5))
            if ((c_nota[5] >= 9.5) || ((c_nota[3]*0.5 + c_nota[4]*0.5) >= 9.5))
            {
                if ((c_nota[3] == -1) || (c_nota[4] == -1))
                    c_nota[6] = (c_nota[2]*0.6 + c_nota[1]*0.4)*0.5 + c_nota[5]*0.4 \
                              + c_nota[0]*0.1;
                else
                    c_nota[6] = (c_nota[2]*0.6 + c_nota[1]*0.4)*0.5 \
                    + max(c_nota[3]*0.5+c_nota[4]*0.5,c_nota[5])*0.4 + c_nota[0]*0.1;
                if (c_nota[6] >= 9.5)
                    printf("AP, Nota = %.2f\n",c_nota[6]);
                else
                    printf("REP\n");
            }
            else
                printf("REP Teorica\n");
        else
            printf("REP Lab\n");
    else
        printf("NA\n");
}

void Print_Pauta(char **A_ID,float **CNota, int NAlunos)
{
    int i, j;

    for(i=0; i< NAlunos; i++)
    {
        printf("\n%s",A_ID[i]);
        for(j=0; j<7; j++)
            printf("\t%5.2f",CNota[i][j]);
    }
    printf("\n");
}

void Print_PautaFinal(char **A_ID,float *CNota, int NAlunos)
{
    int i;

    for(i=0; i< NAlunos; i++)
        printf("%s \t%5.2f\n",A_ID[i],CNota[i]);
}

void mem_map(char *ini_ptr, int n_bytes)
{
    char *C_ptr, *auxC_ptr;
    int i, j;

    C_ptr = ini_ptr;
    for( i=0; i<(n_bytes); i++)
    {
        if (i%8 == 0)
            printf("\n MEM ADD: %p ", C_ptr);
        printf("%3x ", (unsigned char) *C_ptr);
        if (i%8 == 7)
        {
            auxC_ptr = C_ptr - 7;
            for(j=0; j<8; j++)
            {
                if (((*auxC_ptr) > 32) && ((*auxC_ptr) <= 126 ))
                    printf("%c",*auxC_ptr);
                else
                    printf(".");
                auxC_ptr++;
            }
        }
        C_ptr++;
    }
    printf("\n");
}
