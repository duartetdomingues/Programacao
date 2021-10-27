#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* int main(){
char str1[20]="ULisboa Tecnico";
char str2[100]="MEEC Programaçao";
FILE *fp;
fp=fopen("txt.txt","r");
fgets(str1,12,fp);
fgets(&str2[5],10,fp);
printf("%s",str2);
} */
int func(){
static int i=1;
i--;
return i;
}

int main(){
/* struct{
    float f1,f2;
}s1,*ptr;
float *ptr2;

s1.f1=1;
s1.f2=2;
ptr=&s1;
ptr2=(float*)ptr;
char str[20]="ola";
printf("%i",printf("%s",str)); */
int i;
i=func();
i=func();
printf("%d",i);
}
