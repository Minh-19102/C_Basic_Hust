#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType
{
   int data;
   Node *leftNode, *rightNode;
} Node;

typedef Node *Tree;

int numberOfChild(Tree T){
   return (T->leftNode!=NULL)+(T->rightNode!=NULL);
}

int haveLeftNode(Tree T){
   return T->leftNode !=NULL;
}
Tree delete(Tree T, int X){
   if(T->data > X){
      return T->leftNode = delete(T->leftNode, X);
   }
   if(T->data < X){
      return T->rightNode = delete(T->rightNode, X);
   }
   if(T->data == X){
      switch (numberOfChild(T))
      {
      case 0:
         free(T);
         return NULL;
         break;
      case 1:
         Tree tmp = T->leftNode!=NULL ? T->leftNode:T->rightNode;
         free(T);
         return tmp;
         break;
      case 2:
         Tree tmp = T->rightNode;
         while(haveLeftNode(tmp)){
            tmp = tmp->leftNode;
         }
         T->data = tmp->data;
         free(tmp);
         break;
      }
   }
}
