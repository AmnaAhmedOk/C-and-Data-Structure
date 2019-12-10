#include<stdio.h>
#include <conio.h>
#include <alloc.h>
/** Author Amna Ahmed

   use struct and implement dynmic allocation using pointers in c
**/
struct Student
{
  int id;
  char name [50];
  int grade [3] ;
};

 struct Student fillStudent (void);
 void printstudent(struct Student s);


int main()

{

  int size;
  int i;
   struct Student* ps;
   clrscr();
  printf("Enter number of student: ");
  scanf("%d",&size);

   ps= (struct Student*)malloc(size*sizeof(struct Student));

  for (i=0;i<size;i++)
  {
   ps[i]= fillStudent();
   }
       for (i=0;i<size;i++)
       {

     printstudent(ps[i]);
     }
	 getch();
	 free(ps);

 return 0;
}

 struct Student fillStudent(void)
{
   struct Student s;
 
     int i;

   scanf("%d",&s.id);
   scanf("%s",s.name);
   for(i=0;i<3;i++)

   {
   scanf("%d",&s.grade[i]);

   }
   return s;

}
 void printstudent(struct Student s)
 {

 int i;

 printf("%d\n",s.id);
 // printf("Enter name");
 printf("%s\n",s.name);
// printf("Enter gardes 3");
      for(i=0;i<3;i++)

   {
   printf( "%d ",s.grade[i]);
   }

 }
