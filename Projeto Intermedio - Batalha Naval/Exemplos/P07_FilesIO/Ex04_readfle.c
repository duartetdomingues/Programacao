#include <stdio.h>

int main () {
   FILE *fp;
   char str1[10],str2[10],str3[10];
   int ano;

   /* opening file for reading */
   fp = fopen("file.txt" , "r");
   if(fp == NULL) {
      perror("Error opening file");
      return(-1);
   }
   if( fscanf(fp, "%s %s %s %d",str1, str2, str3, &ano)!=EOF ) {
      /* writing content to stdout */
      printf("%s %s %s %d",str1, str2, str3, ano);
   }
   fclose(fp);

   return(0);
}


