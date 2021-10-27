#include <stdio.h>

int main () {
   char str[] = "MEEC Programação";
   FILE *fp;
   char ch;

   fp = fopen( "file.txt" , "w" );
   fwrite(str , 1 , sizeof(str) , fp );
   fclose(fp);
   fp = fopen( "file.txt" , "r" );
   while((ch = fgetc(fp))!=EOF)
      printf("%c", ch);
   rewind(fp);
   printf("\n");
   while((ch = fgetc(fp))!=EOF)
      printf("%c", ch);
   fclose(fp);

   return 0;
}
