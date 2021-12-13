/*
Ho va ten: Dao Nhat Minh
MSSV: 20200392

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nameLength 15
#define emailLength 25
#define phoneLength 11
typedef struct Address {
   char name[nameLength];
   char phone[phoneLength];
   char email[emailLength];
   struct Address *next;
} ad;

// Day ten, sdt, email vao List
void push(ad *address, char name[], char phone[], char email[]) {
   ad *tmp = address;
   tmp = (ad *)malloc(sizeof(ad));
   strcpy(tmp->name, name);
   strcpy(tmp->phone, phone);
   strcpy(tmp->email, email);
   tmp->next = NULL;
   while (address->next != NULL) {
      address = address->next;
   }
   address->next = tmp;
}

// Tim kiem theo ten
void find(ad *address, char name[]) {
   ad *addressNode;
   addressNode = address;
   while (addressNode != NULL) {
      if (strcmp(addressNode->name, name) == 0) {
         printf("Found!\n%s %s %s\n", addressNode->name, addressNode->phone, addressNode->email);
         return;
      }
      addressNode = addressNode->next;
   }
   printf("NOT FOUND!");
}

int main() {
   // Doc File
   int n;
   FILE *input = fopen("inputAddressBook.txt", "r");
   ad *root = NULL;
   root = (ad *)malloc(sizeof(ad));
   fscanf(input, "%d", &n);
   for (int i = 0; i < n; i++) {
      char name[nameLength], email[emailLength], phone[phoneLength];
      fscanf(input, "%s", name);
      fscanf(input, "%s", phone);
      fscanf(input, "%s", email);
      push(root, name, phone, email);
   }
   printf("Read Successfully! The List is:\n");
   
   // In ra toan bo list
   ad *tmp = root;
   while (tmp != NULL) {
      printf("%s %s %s\n", tmp->name, tmp->phone, tmp->email);
      tmp = tmp->next;
   }

   // Menu
   int c;
   do {
      printf("\n\nOptions: \n0. Exit\n1. Search by name\nSelect option:");
      scanf("%d", &c);
      char tmp[emailLength];
      switch (c) {
      case 1:
         printf("Enter name: ");
         scanf("%s", tmp);
         find(root, tmp);
         break;

      default:
         return 0;
         break;
      }
   } while (c != 0);
   fclose(input);
}
