#include <journal.h>

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<stdlib.h>

?
    /*Structure storing the details of the todo list. Status shows whether the task is done or not*/
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
    /*displays the main menu*/
while(1){
  printf("\n\n****************JOURNAL-TO DOs****************\n\n\n\n");
  printf("               ****MENU****\n");
  printf("\nADD TO-DO         [1]\nVIEW TO-DO        [2]\nMARK DONE         [3]\nDELETE TO-DO      [4]\nEXIT              [5]\n\n\nENTER YOUR CHOICE: ");
  scanf("%d",&option);

    
  switch (option)
  {
  case (1):
      addtodo(); /*adds a to do list to the file with the name of the date mentioned*/
      break;
  case(2):
      viewtodo();/*function that allows to view the to do list of the specified date*/
      break;
  case(3):
      mark_done(); /*function to mark a task as done or undone*/
      break;
  case(4):
      delete_todo(); /*to delete a particular task from to do list*/
      break;

  case(5):
       printf("\n\nWohooo! Everything done for today.");
       getch();
       exit(0);
  
  default:
      printf("\nPlease enter valid option(1-6)"); /*Input the number to choose the menu option*/
      printf("\n Press any key to retry");
      getch();
      fflush(stdin);
      break;
  }
  system("cls");

}
return(0);
}
