#include <stdio.h>
#include <conio.h>
#include <alloc.h>
/***Amna Ahmed
 in this code every time you add node in linked list it inserted depeding on the integer to be in 
sorted way 
*/

struct Student
{
int id;
char name [50];
int grade;
};

struct Node
{        
   struct Node *pPrev;
   struct Node *pNext;
   struct Student student;
 };
 struct Node *pHead;
 struct Node* pTail;
 struct Node* createNode(struct Student data);
 int insertNode(struct Student s);
 struct Student fillStudent (void);
 void printstudent(struct Student s);
 void printList(void);


 int main()
 {

  int ch ,f=1;
    struct Student s;

  char c;
  char *ptr;
  clrscr();
 // gotoxy(1,row);
  while(f)
  {
  int loc;
  char name [50];
  printf("1. Add\n2. Print list \n3. Exit \nEnter number of Choice: ");
    scanf("%d" ,&ch);
    switch(ch)
    {
    case 1:
      s= fillStudent();
      insertNode(s);
    break;
    case 2:
       printList();

    break;
    case 3 :
         f=0;
    break;
	    }

	    }

 getch();

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
    printf("---------------------------\n");
 printf("Student ID: %d\n",s.id);
 printf("Student Name: %s\n",s.name);
   printf("Grade: %d\n ",s.grade);



 }

  void printList()
 {     struct Node * ptr;
       ptr=pHead;


      while(ptr) {  //there is a list
    printstudent(ptr->student);
    ptr= ptr->pNext;
		       }

 }


struct Node * createNode(struct Student data)
{  struct Node * ptr;
   ptr =(struct Node *) malloc(sizeof(struct Node));
      if(ptr)
       {
       ptr->student = data;
       ptr->pPrev= NULL;
       ptr->pNext=NULL;
       }
    return ptr;

}



  int insertNode(struct Student s)
  { int retval=0;

    struct Node *ptr,*temp;
     ptr= createNode(s);
      if(ptr)//node created
      {  if (!pHead)//no list
	  {
	  pHead = pTail= ptr;

	  }
	  else{

	   if(s.id>(pHead->student.id)) //data larger
	       {
		ptr->pNext=pHead;
		pHead->pPrev=ptr;
		pHead=ptr;
	       }
	  else{ //middle or last*/



		 if(s.id<pTail->student.id)// lastNode
		  {ptr->pPrev=pTail;
		   pTail->pNext=ptr;

		   pTail=ptr;
		    }

		 else///middle
		 {
		 temp=pHead;
		  while((temp->student.id)< s.id)
		   {
		     temp= temp->pNext;
		     }

		  temp->pNext->pPrev=ptr;
		  ptr->pNext=temp->pNext;
		  ptr->pPrev=temp;
		  temp->pNext=ptr;



		  }
		}



	  }
	  retval=1;
      }

    return retval;

  }