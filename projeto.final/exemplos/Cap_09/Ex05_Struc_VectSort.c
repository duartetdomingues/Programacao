#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char    Student_ID[20];
    float   Nota_Final;
} Student_Data;

void sort_student_vector(Student_Data*,int);

int main()
{
    Student_Data *Student_ptr = NULL;
    int NAlunos, i;

    printf("Insira o num. de alunos: ");
    scanf("%d",&NAlunos);
    printf("Vai ser alocado um bloco de memória com %d estruturas com uma dimensão total de %ld bytes.\n",
           NAlunos,NAlunos*sizeof(Student_Data));
    if ((Student_ptr = (Student_Data*) malloc(NAlunos*sizeof(Student_Data))) == NULL)
    {
        printf("Erro: Não foi possível alocar o bloco de memória\n");
        exit(EXIT_FAILURE);
    }
    for(i=0;i<NAlunos;i++)    // Inicialização das estruturas
    {
        sprintf(Student_ptr->Student_ID,"ISTID_%03d",i+1);
        Student_ptr->Nota_Final = rand()%1100/100.0+10;
        Student_ptr++;
    }
    Student_ptr = Student_ptr - NAlunos;
    for(i=0;i<NAlunos;i++)      // print das estruturas (note as 2 formas de acesso)
    {
        printf("Student ID = %s \tNota: %.2f\n",Student_ptr->Student_ID, (*Student_ptr).Nota_Final);
        Student_ptr++;
    }
    Student_ptr = Student_ptr - NAlunos;
    printf("Vector Ordenado\n");
    sort_student_vector(Student_ptr,NAlunos);
    for(i=0;i<NAlunos;i++)      // print das estruturas (note as 2 formas de acesso)
    {
        printf("Student ID = %s\tNota: %.2f\n",Student_ptr->Student_ID, (*Student_ptr).Nota_Final);
        Student_ptr++;
    }
    Student_ptr = Student_ptr - NAlunos;
    free(Student_ptr );         // libertação da memória alocada
    return 0;
}

void sort_student_vector(Student_Data *head, int size)
{
    int i, trocas = 1;
    Student_Data aux_struct, *aux_ptr, *cur = head;

    aux_ptr = &aux_struct;
    while(trocas != 0)
    {
        trocas = 0;
        cur = head;
        for(i=0; i<size-1; i++)
        {
            if (cur->Nota_Final < (cur+1)->Nota_Final)
            {
                trocas = 1;
                memcpy(aux_ptr,cur,sizeof(Student_Data));
                memcpy(cur,cur+1,sizeof(Student_Data));
                memcpy(cur+1,aux_ptr,sizeof(Student_Data));
            }
            cur++;
        }
        size--;
    }
}
