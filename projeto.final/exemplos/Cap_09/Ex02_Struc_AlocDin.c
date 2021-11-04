#include <stdio.h>
#include <stdlib.h>

struct Student_Data{
    char    Student_ID[20];
    float   Nota_Final;
};

int main()
{
    struct Student_Data *Student_ptr = NULL;
    int NAlunos, i;

    printf("Insira o num. de alunos: ");
    scanf("%d",&NAlunos);
    printf("Vai ser alocado um bloco de memória com %d estruturas com uma dimensão total de %ld bytes.\n",
           NAlunos,NAlunos*sizeof(struct Student_Data));
    if ((Student_ptr = (struct Student_Data*) malloc(NAlunos*sizeof(struct Student_Data))) == NULL)
    {
        printf("Erro: Não foi possível alocar o bloco de memória\n");
        exit(EXIT_FAILURE);
    }
    for(i=0;i<NAlunos;i++)    // Inicialização das estruturas
    {
        sprintf(Student_ptr->Student_ID,"ISTID_%03d",i+1);
        Student_ptr->Nota_Final = rand()%1100/100+10;
        Student_ptr++;
    }
    Student_ptr = Student_ptr - NAlunos;
    for(i=0;i<NAlunos;i++)      // print das estruturas (note as 2 formas de acesso)
    {
        printf("Student ID = %s \tNota: %.0f\n",Student_ptr->Student_ID, (*Student_ptr).Nota_Final);
        Student_ptr++;
    }
    Student_ptr = Student_ptr - NAlunos;
    free(Student_ptr );         // libertação da memória alocada
    return 0;
}
