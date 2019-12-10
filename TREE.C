#include <stdio.h>
#include <conio.h>
#include <alloc.h>
/**
   Author Amna Ahmed 
    
   implement Binary Search tree
   and traverse it using 3 ways

***/
struct Node
{
 int data;
 struct Node * pLeft;
 struct Node * pRight;
};
 struct Node * createNode (int data);
 struct Node * Insert (struct Node* pNode , int data);
 void postOrder(struct Node * root);
  void preOrder(struct Node * root);
   void inOrder(struct Node * root);

int main ()

{    struct Node *root=NULL;
clrscr();
     root=Insert(root,9);
     Insert(root,7);
     Insert  (root,20);
     Insert  (root,3);
     Insert   (root,13);
     printf("PostOrder: ");
     postOrder(root);
      printf("\nPreOrder: ");
     preOrder(root);
       printf("\nInOrder: ");
     inOrder(root);

     getch();
 return 0;
}


 struct Node * createNode (int data)
 { struct Node *p;
   p=(struct Node*)malloc(sizeof (struct Node));
   if(p)
   {
    p-> data = data;
    p-> pLeft =NULL;
    p-> pRight =NULL;

   }
    return p;

  }
 struct Node * Insert (struct Node* pNode , int data)
 {
    if(!pNode)
    {
     pNode = createNode(data);
    }
    else if (data <= pNode->data)
    {

     pNode ->pLeft = Insert(pNode->pLeft,data);
    }
    else {
	  pNode->pRight = Insert(pNode->pRight,data);
    }
    return pNode;
 }

   void postOrder(struct Node * root) //left right root
   {
      if(root ==NULL) return;
	postOrder(root->pLeft);
	postOrder (root->pRight);
	 printf("%d ",root->data);
   }


   void preOrder(struct Node * root) //root left right
   {
      if(root ==NULL) return;
       printf("%d ",root->data);
	postOrder(root->pLeft);
	postOrder (root->pRight);

   }


   void inOrder(struct Node * root) //left root right
   {
      if(root ==NULL) return;
	postOrder(root->pLeft);
	 printf("%d ",root->data);
	postOrder (root->pRight);

   }