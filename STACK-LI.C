#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <stdlib.h>
/**

Author :Amna Ahmed
Implement stack using linked list 
*//
struct Student
{
int id;
char name [50];
int grade;
};

struct Node
{

   struct Node *pNext;
   struct Student student;
 };

 struct Node* pTail;
   struct Student pop(void);
   struct Student fillStudent(void);
    void printstudent(struct Student s);
     int push (struct Student data);

 int main()

 {  int ch ;
    struct Student s;
    
  char *ptr;

      clrscr();
 // gotoxy(1,row);


  while (1)

  {
    printf("push\npop\nExit\n");
    printf("Enter your choic Number:");
    scanf ("%d",&ch);
    switch(ch)

    {
     case 1:
     s= fillStudent();
	push(s);
	break;
      case 2:
       s= pop();
	 printstudent(s);
	      break;
	case 3:
	exit(0);
	break;
       defualt:
       printf("Enter valid data");
       break;
    }


  }

   


  return 0;

 }
 struct Student fillStudent(void)
{
   struct Student s;

	       printf("Enter Name:");
	       scanf("%s",s.name);
		printf("EnterID:");
	       scanf("%d",&s.id);
		printf("Enter grade:");
		scanf("%d",&s.grade);

   return s;

}
 void printstudent(struct Student s)
 {

 printf("Student ID: %d\n",s.id);
 printf("Student Name: %s\n",s.name);
   printf("Grade: %d\n",s.grade);



 }
 struct Node * createNode(struct Student data)
{  struct Node * ptr;
   ptr =(struct Node *) malloc(sizeof(struct Node));
      if(ptr)
       {
       ptr->student = data;
      // ptr->pPrev= NULL;
       ptr->pNext=NULL;
       }
    return ptr;

}
 int push (struct Student data)
  {
      int retval=0;
      struct Node* ptr;
      ptr= createNode(data);
      if(ptr)
      {
       if(!pTail)
       {
	pTail=ptr;
       }
       else{
	// ptr ->pPrev = pTail;
	 pTail -> pNext=ptr;
	 pTail = ptr;

       }
       retval =1;
      }
      return retval;

  }
  struct Student pop(void)
  {
   struct Student s;
  // struct Node* ptr;
   s= pTail-> student;

  // pTail=pTail->pPrev;
   pTail->pNext=NULL;

   return s;

  }