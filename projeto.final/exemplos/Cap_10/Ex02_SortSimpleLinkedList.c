
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Student_Data{
    char    Student_ID[20];
    float   Nota_Final;
    struct  _Student_Data *next;
} Student_Data;

Student_Data *cria_aluno(int);
Student_Data *insere_aluno_na_listaordenada(Student_Data*, Student_Data*);
Student_Data *insere_aluno_no_fim_lista(Student_Data*, Student_Data*);
Student_Data *insere_aluno_no_topo_lista(Student_Data*, Student_Data*);
Student_Data *remove_aluno_da_lista(Student_Data*, char*);
void print_lista(Student_Data*);
void free_list(Student_Data*);
Student_Data *ordena_lista(Student_Data *);
Student_Data *troca(Student_Data*, Student_Data*);

int main()
{
    Student_Data *ListHead = NULL, *NewStudent;
    char DelStd[10];
    int NAlunos = 10000, i;

    printf("Insira o num. de alunos: ");
    scanf("%d",&NAlunos);
    for(i=0; i<NAlunos; i++)
    {   // cria aluno
        NewStudent = cria_aluno(i);
        // Insere Elemento
        //ListHead = insere_aluno_na_listaordenada(ListHead, NewStudent);
        //ListHead = insere_aluno_no_fim_lista(ListHead, NewStudent);
        ListHead = insere_aluno_no_topo_lista(ListHead, NewStudent);
    }
    // Apresenta Lista
    printf("===== Lista ====\n");
    print_lista(ListHead);
    // Remove Elemento da lista
    sprintf(DelStd,"ISTID_%03d",rand()%NAlunos+1);
    ListHead = remove_aluno_da_lista(ListHead, DelStd);
    printf("===== Lista sem o elemento %s ====\n",DelStd);
    print_lista(ListHead);
    // Ordena Lista
    ListHead = ordena_lista(ListHead);
    printf("===== Lista ordenada ====\n");
    print_lista(ListHead);
    // Liberta Memória
    free_list(ListHead);
    return 0;
}

Student_Data *cria_aluno(int i)
{
    Student_Data *NewStd;

    if ((NewStd = (Student_Data*) calloc(1,sizeof(Student_Data))) == NULL)
    {
        printf("Erro: Não foi possível alocar o bloco de memória\n");
        exit(EXIT_FAILURE);
    }
    sprintf(NewStd->Student_ID,"ISTID_%03d",i+1);
    NewStd->Nota_Final = rand()%1000/100.0+10;
    NewStd->next = NULL;
  //  printf("%s %.2f\n",NewStd->Student_ID,NewStd->Nota_Final);
    return NewStd;
}

void print_lista(Student_Data *ListHead)
{
    Student_Data *Aux;

    for( Aux = ListHead; Aux != NULL; Aux = Aux->next)
    {
        printf("%s %.2f\n",Aux->Student_ID,Aux->Nota_Final);
    }
}

void free_list(Student_Data *ListHead)
{
    Student_Data *Aux;

    Aux = ListHead;
    while( ListHead != NULL)
    {
        Aux = ListHead;
        ListHead = ListHead->next;
        free(Aux);
    }
}

Student_Data *ordena_lista(Student_Data *ListHead)
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
    return ListHead;
}

Student_Data *troca(Student_Data *left,Student_Data *right)
{
    left->next = right->next;
    right->next = left;
    return right;
}

Student_Data *insere_aluno_na_listaordenada(Student_Data *ListHead, Student_Data *NewStudent)
{
        Student_Data *AuxH, *AuxT;

        if(ListHead == NULL)
        {
            ListHead = NewStudent;
        }
        else
        {
            if (ListHead->Nota_Final < NewStudent->Nota_Final)
            {
                NewStudent->next = ListHead;
                ListHead = NewStudent;
            }
            else
                {
                    AuxH = ListHead;
                    AuxT = ListHead->next;
                    if (AuxT == NULL)
                    {
                        ListHead->next = NewStudent;
                    }
                    else
                    {
                        while((AuxT != NULL) && (AuxT->Nota_Final > NewStudent->Nota_Final))
                        {
                            AuxH = AuxT;
                            AuxT = AuxT->next;
                        }
                        NewStudent->next = AuxT;
                        AuxH->next = NewStudent;
                    }
                }
        }
        return ListHead;
}

Student_Data *insere_aluno_no_fim_lista(Student_Data *ListHead, Student_Data *NewStudent)
{
        Student_Data *AuxH, *AuxT;

        if(ListHead == NULL)
        {
            ListHead = NewStudent;
        }
        else
        {
            AuxH = ListHead;
            AuxT = ListHead->next;
            while(AuxT != NULL)
            {
                AuxH = AuxT;
                AuxT = AuxT->next;
            }
            AuxH->next = NewStudent;
        }
        return ListHead;
}

Student_Data *insere_aluno_no_topo_lista(Student_Data *ListHead, Student_Data *NewStudent)
{
        if(ListHead == NULL)
        {
            ListHead = NewStudent;
        }
        else
        {
            NewStudent->next = ListHead;
            ListHead = NewStudent;
        }
        return ListHead;
}

Student_Data *remove_aluno_da_lista(Student_Data *ListHead, char *DelStd)
{
    Student_Data *AuxH, *AuxT;

    AuxH = ListHead;
    AuxT = ListHead->next;
    if (strcmp(AuxH->Student_ID, DelStd) == 0)
    {
        ListHead = ListHead->next;
        free(AuxH);
    }
    else
    {
        while(strcmp(AuxT->Student_ID, DelStd) != 0)
        {
            AuxH = AuxT;
            AuxT = AuxT->next;
        }
        AuxH->next = AuxT->next;
        free(AuxT);
    }
    return ListHead;
}
