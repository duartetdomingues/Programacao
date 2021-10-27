#include <stdio.h>
#include <stdlib.h>

char *my_strcpy(char *, const char *);
char *my_strrev(char *);
int my_strlen(const char *);
void mem_map(char *, int);

int main()
{
    char str1[20] = "\nWorld Wide Web", *str3, str2[20] = "!!!!";

    mem_map(str2, 56);
    printf("%s %s\n", str1, str2);
    str3 = my_strcpy(str2, "Criada em 1989");
    printf("%s %s\n", str1, str2);
    printf("%s %p %p %ld\n", str3, str3, &str3, sizeof(str3) );
    mem_map(str2, 56);
    str3 = my_strrev(str1);
    mem_map(str2, 56);
    printf("\n%s\n", str3);
    printf("\nA string \"%s\" tem comprimento %d\n",str2,my_strlen(str2));
    return 0;
}

//char *my_strcpy(char *dest, const char *src)
//{
//    const char *p;
//    char *q;
//
//    for(p = src, q = dest; *p != '\0'; p++, q++)
//        *q = *p;
//    *q = '\0';
//    return dest;
//}

char *my_strcpy(char *dest, const char *src)
{
    const char *p;
    char *q;

    for(p = src, q = dest; *p != '\0'; p++, q++)
    {
        *q = *p;
        mem_map(dest, 16);
    }
    *q = '\0';
    return dest;
}

char *my_strrev(char *str)
{
    char *p, *q, aux;

    for(p = str; *p != '\0'; p++);
    for(p--, q = str; p >= q; p--, q++)
    {
        aux = *p;
        *p = *q;
        *q = aux;
        mem_map(q, 16);
    }
    return str;
}

int my_strlen(const char *p)
{
    int len = 0;

    while(*p++ != '\0')
        len++;
    return len;
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
