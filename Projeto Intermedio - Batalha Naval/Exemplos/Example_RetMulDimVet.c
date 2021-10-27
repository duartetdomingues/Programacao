#include <stdio.h>
#include <stdlib.h>

int *gera_aleat();

int main()
{
    int *I_ptr, *I_auxIptr, i;

    I_ptr = gera_aleat();
    I_auxIptr = I_ptr;
    for(i=0; i<10; i++)
    {
        printf("MADDR_M: \t%p Valor:%d\t %d\n", I_ptr, *I_ptr, *(I_auxIptr+i));
        I_ptr++;
    }
    printf("\n");
    return 0;
}

int *gera_aleat()
{
    int i,j;
    static int aleat[5][2];

    for(i=0; i<5; i++)
    {
        for(j=0; j<2; j++)
        {
            aleat[i][j] = rand()%20;
            printf("MADDR_F: \t%p Valor:%d\t\n", &aleat[i][j], aleat[i][j]);
        }
    }
    printf("\n");
    return (int *) aleat;
}
