#include <stdio.h>
#include <stdlib.h>

int *gera_aleat();
void init_mem();

int main()
{
    int *I_ptr, *I_auxptr, *I_orgptr, i;

    I_ptr = gera_aleat();
    I_auxptr = I_ptr;
    I_orgptr = I_ptr;
    for(i=0; i<10; i++)
    {
        printf("MADDR_M: \t%p Valor:%d\t %d\n", I_ptr, *I_ptr, *(I_auxptr+i));
        I_ptr++;
    }
    printf("\n");
    init_mem();
    printf("\n");
    I_ptr = I_orgptr;
    for(i=0; i<10; i++)
    {
        printf("MADDR_M: \t%p Valor:%d\n", I_ptr, *I_ptr);
        I_ptr++;
    }
    printf("\n");
    return 0;
}

int *gera_aleat()
{
    int k;
    static int aleat[10];


    for(k=0; k<10; k++)
    {
        aleat[k] = rand();
        printf("MADDR_F: \t%p Valor:%d\t\n", &aleat[k], aleat[k]);
    }
    printf("\n");
    return aleat;
}

void init_mem()
{
    int i, i_vect[20];

    for(i=0; i<20; i++)
    {
        i_vect[i] = i;
        printf("MADDR_F: \t%p Valor:%d\t\n", &i_vect[i], i_vect[i]);
    }
}
