// De bai: Mo va dong 1 file
#include <stdio.h>

enum { SUCCESS, FAIL };

int main(void) {
   FILE *fptr;
   char filename[] = "haiku.txt";
   int reval = SUCCESS;

   if ((fptr = fopen(filename, "r")) == NULL) {
      printf("Can't open %s.\n", filename);
      reval = FAIL;
   } else {
      printf("The value of fptr: %p\n", fptr);
      printf("Ready to close file.");
      fclose(fptr);
   }
   return reval;
}