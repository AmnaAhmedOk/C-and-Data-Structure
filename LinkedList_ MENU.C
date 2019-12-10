#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <string.h>

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
 int AddNode(struct Student data);
 int insertNode(struct Student s, int loc);
 struct Student fillStudent (void);
 void printstudent(struct Student s);
 struct Student SearchID(int id);
 struct Student SearchName(char name[50]);
 void freeList(void);
 int deleteStruct(int loc);
 void printList(void);
int main()
{// int row=1,flag=1;
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
  printf("1. Add\n2. Insert\n3. Search by Name\n4. Search by ID  \n5. Delete\n6. Print list\n7. Free List\n8. Exit \nEnter number of Choice: ");
    scanf("%d" ,&ch);
    switch(ch)
    {
    case 1:
      s= fillStudent();
      AddNode(s);
    break;
    case 2:
     printf("\nEnter location: ");
     scanf("%d",&loc);
      s= fillStudent();
     insertNode(s,loc);

    break;
    case 3 :

     printf("\nEnter Name to search by: ");
     scanf("%d",name);
    s= SearchName(name);
     printstudent (s);

    break;
    case 4:
    printf("\nEnter ID to search by: ");
     scanf("%d",&loc);
    s= SearchID(loc);
     printstudent (s);
    break;
    case 5:
    printf("\nEnter location to delete: ");
     scanf("%d",&loc);
    loc=deleteStruct (loc);
    if(loc) printf("Node at location %d Deleted",loc);
    else printf("Node at location %d Not Deleted",loc);
    break;
    case 6:
     printList();
    case 7 :
    freeList();
    break;
    case 8 :
     f=0;
    break;
    defualt:
    printf("Please Enter correct number");
    break;
  }
     printf("-----------------------------------------\n");
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

 printf("Student ID: %d\n",s.id);
 printf("Student Name: %s\n",s.name);
   printf("Grade: %d\n ",s.grade);

   printf("-----------------------------------------");

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

  int AddNode (struct Student data)
  {
      int retval=0;
      struct Node* ptr;
      ptr= createNode(data);
      if(ptr)
      {
       if(!pHead)    // no linkedlist
       {
       pHead= pTail=ptr;
       }
       else{
	 ptr ->pPrev = pTail;
	 pTail -> pNext=ptr;
	 pTail = ptr;

       }
       retval =1;
      }
      return retval;

  }

  int insertNode(struct Student s, int loc)
  { int retval=0;
     int i;
    struct Node *ptr,*temp;
     ptr= createNode(s);
      if(ptr)//node created
      {  if (!pHead)//no list
	  {
	  pHead = pTail= ptr;

	  }
	  else{
	       if(loc==0)
	       {
		ptr->pNext=pHead;
		pHead->pPrev=ptr;
		pHead=ptr;
	       }
		else{ //middle or last
		   temp=pHead;
		   for(i=0;i<loc-1;i++)
		   {
		     temp= temp->pNext;
		   }

		 if(temp==NULL)// lastNode
		  {ptr->pPrev=pTail;
		   pTail->pNext=ptr;
		   pTail=ptr;
		 }
		 else///middle
		 {temp->pNext->pPrev=ptr;
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
  struct Student SearchID(int id)
  {   int f=1;
    struct Node*ptr;

   struct Student s;
  // s=NULL;
      ptr=pHead;
      while(ptr&&f)
      {
    if(ptr->student.id!=id)
    {ptr=ptr->pNext;
    }
     else
    { f=0;

    }

      }
       s=ptr->student;

     return s;
  }
   struct Student SearchName( char name [50])
  {
    struct Node*ptr;
     int f=1;

    ptr=pHead;

    while(ptr&&f)

    {
     if(!strcmp(name,(ptr->student.name)))
	      { f=0; }
	      else{
		 ptr=ptr->pNext;
	      }
	      }



     return ptr->student;
  }

  void freeList(void)
  {
   struct Node*ptr;
   while(pHead)
   {ptr=pHead;
   pHead= pHead->pNext;
   free(ptr);
   }
   pTail=NULL;

  }
  int deleteStruct(int loc)
  {
     int retval=0;
     struct Node*temp;
     if(pHead)// list
     {

       if(loc==0)
       {  temp=pHead;
	 if(pHead==pTail)
	 { pHead= pTail=NULL;
	 }
       else
	{
	  pHead=pHead->pNext;
	  pHead->pPrev=NULL;
	 }
	  free(temp);
	 retval=1;

	 }
	 else{ //middle or last
	 int i;
	 temp =pHead;
	 for(i=0;i<loc&&temp;i++)
	 {
	 temp =temp-> pNext;
	 }
	  if(temp)
	  {
	   if(temp==pTail)// last Node
	   { pTail=pTail->pPrev;
	     pTail->pNext=NULL;

	  }
	  else{
	       (temp->pNext)->pPrev=temp->pPrev;
	       (temp->pPrev)->pNext=temp->pNext;

	      }
	      free(temp);
	      retval=1;

	  }

	 }

       }
	 return retval;

  }