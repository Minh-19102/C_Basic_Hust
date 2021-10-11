// Tu viet ham comcat
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *my_strcat(char *str1, char *str2) {
   int len1, len2;
   char *result;
   len1 = strlen(str1);
   len2 = strlen(str2);
   result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
   if (result == NULL) {
      printf("Allocation failed! Check memory\n");
      return NULL;
   }
   strcpy(result, str1);
   strcpy(result + len1, str2);
   return result;
}
int main() {
   char s1[50], s2[50];
   scanf("%s %s", s1, s2);
   char *pointer = my_strcat(s1, s2);
   printf("0x%x\n", pointer);
   while (*pointer != '\0') {
      printf("%c", *pointer);
      pointer++;
   }
}