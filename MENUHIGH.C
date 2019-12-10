#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <alloc.h>
/**
   Author Amna Ahmed 
    
   Menu and highlight item where we on it
 
**/
void setcolor(int row);
char* openeditor(int s,char* ptr);
int main()

{     int row=1,flag=1,s;
      char ch;
       char *ptr;

       clrscr();

       gotoxy(1,row);
	// setcolor(1);


  printf("File\nEdit\nNew\nDisplay\nExit");
	   gotoxy(1,row);
	   while(flag)
	   {
	    ch=getch();
	    if(ch==0)
	       {
		ch=getch();

		switch(ch)
		{
		 case 72:
		 if(row>1){row--;}else{row=5;}
		     setcolor (row);
		  gotoxy(1,row);

		     break;
		  case 80:
		 if(row<5){row++;}else{row=1;}

		  setcolor (row);
		   gotoxy(1,row);

		     break;
		     }

	       }
	       else
	       {
		 switch(ch)
		 {
		 case 13:
		 gotoxy(1,8);
		 if(row==1)

		{
		printf("File is pressed");
		 }
		 else
		 {
		   if(row==2)
		   { 	printf("Edit is pressed");
		    }
		    else
		    {
			if(row==3)
		       {
		       //	printf("New is pressed");
		       int j;
		       gotoxy(1,7);
		       printf("Enter size: ");
		       scanf("%d",&s);
		       ptr=(char*) malloc(s*sizeof(char));

		       ptr= openeditor (s,ptr);

		       }
		       else
		       {  if(row==4)



			   { 	printf("Display is pressed");


			      }
			      else
			      {
				  if(row==5)
		       { 	flag=0;
			      }
			      }

		       }

		    }

		 }
		 break;

		 case 27:
		 flag=0;
		 break;


			} //switch


	       }//else



	   } // while



 return 0;
}

void setcolor(int row)
{       clrscr();

	 gotoxy(1,1);
	 // textatt(0x07);

   switch(row)
   {
   case 1:
   //clrscr();
   textattr(0x70);//highlit
   cprintf("File");
   textattr(0x07); ///normal
   cprintf("\r\nEdit\r\nNew\r\nDisplay\r\nExit");
   break;
    case 2:
 // clrscr();
 //  gotoxy(1,1);
  // textattr(0x07);
   cprintf("File");
   textattr(0x70);
   cprintf("\r\nEdit");
   textattr(0x07);
   cprintf("\r\nNew\r\nDisplay\r\nExit");
   break;
     case 3:
    //  clrscr();
  // gotoxy(1,1);
  // textattr(0x07);
   cprintf("File\r\nEdit\r\n");
   textattr(0x70);
   cprintf("New");
   textattr(0x07);
   cprintf("\r\nDisplay\r\nExit");
   break;
     case 4:
  // clrscr();
  // gotoxy(1,1);
 //  textattr(0x07);
   cprintf("File\r\nEdit\r\nNew\r\n");
   textattr(0x70);
   cprintf("Display");
   textattr(0x07);
   cprintf("\r\nExit");
   break;
     case 5:
 //  clrscr();
  // gotoxy(1,1);
  // textattr(0x07);
   cprintf("File\r\nEdit\r\nNew\r\nDisplay\r\n");
   textattr(0x70);
   cprintf("Exit");
   textattr(0x07);

   break;

    }

}

char* openeditor(int s,char* ptr)

{
     int i=0,pos=0,exit=1,j;
     char c;
     char str[40];
     gotoxy(1,8);

     do{
	     c=getch();

	     // extended
	     if(c==0)
	     { c=getch();

	     switch (c)
	     {
	      case 75: //left

	      if(pos>1)pos--; else pos=i;
	      gotoxy(pos,8);
	      break;
	      case 77: //right

	      if(pos<i) pos++; else pos=0;
	      gotoxy(pos,8);
	      break;
	      case 71: //home
	      pos=1;
	      gotoxy(pos,8);
	      break;
	      case 79: //end
	      pos=i;
	      gotoxy(pos,8);
	      break;
	      case 83: //delete
	       pos=wherex();
			     gotoxy(pos,8);
			     ptr[pos]=' ';
			     for(j=pos;j<i;j++)
			      {ptr[j]=ptr[j+1];
				printf("%c",ptr[j]);
			       }

				str[i]=0;
				  i--;
			      gotoxy(pos,8);

			      break;
	     }
	     }


	       else {
		    if(isprint(c)&&pos<s)
		    {
		    str[pos++]=c;
		       i++;

		    gotoxy(pos,8);
		    printf("%c",c);
		   // if(pos>i)

		    }
		      else{
			 if(c==13) //enter
			 {
			  gotoxy(1,13);
			 for(j=0;j<i;j++)
			    printf("%c",ptr[j]);
			 }
			 else
			  {
			  if(c==27) //escape
			   {
			     exit=0;
			   }
			   else
			   {
			   if(c==8)//delete
			     {
			     pos=wherex();
			     gotoxy(pos,8);
			     ptr[pos-2]=' ';
			     for(j=pos-2;j<i;j++)
			      {ptr[j]=ptr[j+1];
				printf("%c",ptr[j]);
			       }

				str[i]=0;
				  i--;
			      gotoxy(pos-1,8);

			     }
			   }

			  }





			  }



	     }


     } while(exit);

      return ptr;
}


