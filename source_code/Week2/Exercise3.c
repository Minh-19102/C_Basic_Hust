// copy file 2 vao file 1
#include <stdio.h>

enum { SUCCESS, FAIL, MAX_LEN = 80 };
void BlockReadWrite(FILE *fin, FILE *fout) {
   int num;
   char buff[MAX_LEN + 1];

   while (!feof(fin)) {
      num = fread(buff, sizeof(char), MAX_LEN, fin);
      buff[num * sizeof(char)] = '\0';
   };
   printf("%s", buff);
   fwrite(buff, sizeof(char), num, fout);
};

int main(void) {
   FILE *fptr1, *fptr2;
   char filename1[] = "lab1a.txt";
   char filename2[] = "lab1.txt";
   int reval = SUCCESS;

   if ((fptr1 = fopen(filename1, "w")) == NULL) {
      printf("Cannot open %s.\n", filename1);
      reval = FAIL;
   }
   if ((fptr2 = fopen(filename2, "r")) == NULL) {
      printf("Cannot Open %s.\n", filename2);
      reval = FAIL;
   }
   if (reval == SUCCESS) {
      BlockReadWrite(fptr2, fptr1);
      fclose(fptr1);
      fclose(fptr2);
   }
   return reval;
}