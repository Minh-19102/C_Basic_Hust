#include <stdio.h>

int a[10];
int x;
int main() {
   for (int i = 0; i < 10; i++) {
      scanf("%d", &a[i]);
   }
   scanf("%d", &x);
   for (int i = 0; i < 10; i++) {
      if (a[i] == x)
         printf("%d\n", i + 1);
   }
   return 0;
}