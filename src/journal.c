#include <journal.h>

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

/*function to add task to do list*/
void addtodo()
{   system("cls");
    int cont =1;
    int found=0;
    char fname[10];
    char title[50];
    FILE * fp;
    struct todos todo;
    printf("\n\n******************ADD YOUR TO DO LIST HERE******************");
    fflush(stdin);
    printf("\n\nEnter the date(dd-mm-yy) : "); /* Enter the date which is the name of the file*/
    gets(fname);

    fp = fopen(fname,"ab+");
    if(fp == NULL)
    {
        fp= fopen("fname","wb+");
        if (fp== NULL)
        {
            printf("\n\n ERROR!! TRY AGAIN AFTER SOMETIME"); /*system error*/
            getchar();
            return;
        }

      
    }

    while(cont) /*continue adding list till the user enters 0*/
    {   found =0;
        fflush(stdin);
        rewind(fp);
        printf("\n Enter the TO DO title: ");
        gets(title);

        while(fread(&todo, sizeof(todo),1,fp)) /*Read the file to see if the todo note already exists*/
        {   
            if (strcmp(title, todo.taskname)==0)
            {
                printf("TO DO already added");
                found =1;
            }

        }

        if (found==0) /*if the to do note is not found, add as new task*/
        {
            strcpy(todo.taskname, title); /*Enter all the 3 fields data*/
            printf("\nEnter note:");
            fflush(stdin);
            gets(todo.note);
            printf("\n Enter time(hh-mm pm/am):");
            fflush(stdin);
            gets(todo.time);
            printf("\n Enter status of the task(y/n):");
            fflush(stdin);
            gets(todo.status);
            fwrite(&todo,sizeof(todo),1,fp);

        }
        printf("Do you want to add more reminders(1/0):");
        scanf("%d",&cont);

    }
    printf("\n\n TO Do list updated.");
    getch();
    fclose(fp);
    return;

}

void mark_done() /*function to change the todo status as done or not done*/
{   
    system("cls");
    FILE * fp;
    char fname[50];
    char title[50];
    struct todos todo;
    char status;
    int found =0;


    

        fflush(stdin);
        printf("\n\n Enter the date of the TO DO note (dd-mm-yy):");
        gets(fname);

        fp = fopen(fname,"rb+");
        if (fp==NULL){
            printf("\n File does not exist. Press any button to go back to menu."); /*check whether the file exists or not*/
            getch();
            return;
        }

        printf("\n Enter the task name:");
        fflush(stdin);
        gets(title);

        printf("\n Enter the changed status(y/n):");
        fflush(stdin);
        gets(status);

        while(fread(&todo, sizeof(todo),1, fp)) /*find the task using task note title*/
        {
            if (strcmp(todo.taskname,title)==0)
            {   found=1;
                break;
            }
        }

        if (found==1)  /*if found delete that record and enter new record with changed status*/
        {
            fseek(fp,-sizeof(todo), SEEK_CUR);
            fwrite(&todo,sizeof(todo),1,fp);
            printf("\n Status changed successfully");
            
        }
        else{
            printf("\n To Do list not found. Try again");
            return;
        }
    
    getch();
    return;

}

void viewtodo() /*to view the todo list*/
{
     system("cls");
    FILE * fp;
    char fname[50];
    char title[50];
    struct todos todo;
    int found =0;
    int op=1;
    int menu;

    while(op)
    {
        fflush(stdin);
        printf("\n\n Enter the date of the TO DO note (dd-mm-yy):");
        gets(fname);

        fp = fopen(fname,"rb");
        if (fp==NULL){
            printf("\n File does not exist. Press any button to go back to menu."); /*check whether the entered todo list exists or not*/
            getch();
            return;
        }

        printf("\n\n Want to view all To dos of this day(1) or a particular To do(2):" );
        scanf("%d",&menu);
        switch (menu)
        {
        case (1):
            while (fread(&todo, sizeof(todo),1,fp))  /*read all the records inthe file and display it*/
            {
                printf("\n\nTask: %s",todo.taskname);
                printf("\n Time: %s",todo.time);
                printf("\n Note: %s ", todo.note);
                printf("\n Status: %s\n\n",todo.status);
            }
            
            break;
        
        case(2):
            printf("\n Enter the task name:");
            fflush(stdin);
            gets(title);
            while(fread(&todo, sizeof(todo),1, fp)) /*find the record with the mentioned title*/
            {
                if (strcmp(todo.taskname,title)==0)
                {   found=1;
                    break;
                }
            }

            if (found==1)
            {
                printf("\n\nTask: %s",todo.taskname); /*if the record with that name is found, display it*/
                printf("\n Time: %s",todo.time);
                printf("\n Note: %s ", todo.note);
                printf("\n Status: %s\n\n",todo.status);
            }
            else
            {
                printf("\n\n Task not found");
            }
            

            break;

        default: printf("\n\n Enter valid option. Try Again!");
                break;
        }
        
    printf("Do you want to view more records(1/0):");
    scanf("%d",&op);

    }
    getch();
    return;

}

void delete_todo() /*to delete the todo list of a particular day*/
{
    system("cls");
    FILE * fp;
    char fname[50];
    
    

    fflush(stdin);
    printf("\n\n Enter the date of the TO DO note (dd-mm-yy):");
    gets(fname);

    fp = fopen(fname,"wb");
    if (fp==NULL){
        printf("\n File does not exist. Press any button to go back to menu.");
        getch();
        return;
    }    
    fclose(fp);
    remove(fname); /*delete the file*/

}
