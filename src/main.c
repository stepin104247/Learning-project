#include "journal.h"

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<stdlib.h>


struct todos
{
    char taskname[35];
    char time[6];
    char note[200];
    char status[1];
};

int main()
{ 
int option;
while(1){
  printf("\n\n****************JOURNAL-TO DOs****************\n\n\n\n");
  printf("               ****MENU****\n");
  printf("\nADD TO-DO         [1]\nVIEW TO-DO        [2]\nMARK DONE         [3]\nDELETE TO-DO      [4]\nEXIT              [5]\n\n\nENTER YOUR CHOICE: ");
  scanf("%d",&option);

  switch (option)
  {
  case (1):
      addtodo();
      break;
  case(2):
      viewtodo();
      break;
  case(3):
      mark_done();
      break;
  case(4):
      delete_todo();
      break;

  case(5):
       printf("\n\nWohooo! Everything done for today.");
       getch();
       exit(0);
  
  default:
      printf("\nPlease enter valid option(1-6)");
      printf("\n Press any key to retry");
      getch();
      fflush(stdin);
      break;
  }
  system("cls");

}
return(0);
}
