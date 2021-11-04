#include <stdio.h>
#include <stdlib.h>

struct Student_Data{
    char    Student_ID[20];
    float   Nota_Final;
};

int main()
{
    struct Student_Data Student_01 = {"ISTID_001", 19};
    struct Student_Data Student_Vector[3] = {{"ISTID_001", 19},{"ISTID_002", 11},{"ISTID_003", 17}};
    struct Student_Data *Student_ptr = NULL;
    int i;

    for(i=0;i<3;i++)
    {
        printf("Student ID = %s \tNota: %.0f\n",Student_Vector[i].Student_ID, Student_Vector[i].Nota_Final);
    }
    return 0;
}


