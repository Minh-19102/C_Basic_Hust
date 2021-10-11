// Upper to Lower , Lower to Upper
#include <stdio.h>

void charReadWrite(FILE *fin, FILE *fout) {
   char c;
   while ((c = getc(fin)) != EOF) {
      if ('a' <= c && c <= 'z')
         c -= 32;
      else if ('A' <= c && c <= 'Z')
         c += 32;
      fputc(c, fout);
      putchar(c);
   }
}
int main() {
   charReadWrite(fopen("file1.txt", "r"), fopen("file2.txt", "w"));
   return 0;
}