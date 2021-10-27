#include <stdio.h>
#include <stdlib.h>

int main()
{
    float F_Vect[10] = {1.414,1.618,3.14,9.81,365.3,11.2e3,6.38e6,10e10,20e20,30e30};
    char *C_ptr, *auxC_ptr, C_Vect[10] = {'*','P','O','R','T','U','G','A','L','*'};
    int i, j, I_Vect[10] = {2,3,5,7,11,13,17,19,23,2048};

    for( i=0; i<10; i++)
    {
        printf("I[%d] = %d\tC[%d] = %c\tD[%d] = %6.3e\n", i, I_Vect[i], i, C_Vect[i], i, F_Vect[i]);
    }
    printf("\nI_Vect ADD: %lu a %lu\n",(unsigned long) I_Vect, (unsigned long) &I_Vect[9]+3);
    printf("C_Vect ADD: %lu a %lu\n", (unsigned long) C_Vect, (unsigned long) &C_Vect[9]);
    printf("F_Vect ADD: %lu a %lu\n", (unsigned long) F_Vect, (unsigned long) &F_Vect[9]+3);
    printf("\nI_Vect ADD: %p a %p\n", I_Vect, &I_Vect[9]+3);
    printf("C_Vect ADD: %p a %p\n", C_Vect, &C_Vect[9]);
    printf("F_Vect ADD: %p a %p\n", F_Vect, &F_Vect[9]+3);
    C_ptr = (char *) I_Vect;
    for( i=0; i<(48+16+48); i++)
    {
        if (i%8 == 0)
            printf("\n MEM ADD: %lx ", (unsigned long) C_ptr);
        printf("%4d ", (unsigned char) *C_ptr);
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
    return 0;
}
