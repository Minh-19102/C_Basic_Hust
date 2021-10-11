// De bai: Thay the toan bo ky tu trong xau boi 1 ky tu khac
#include <stdio.h>

void replace_char(char *str[], char c1, char c2) {
   while (*str != '\0') {
      if (*str == c1) *str = c2;
      str++;
   }
}
int main() {
   char str[100], a, b;
   scanf("%[^\n]s\n", str);
   while (getchar() == '\n')
      ;
   scanf("%c %c", &a, &b);
   replace_char(&str, a, b);
}