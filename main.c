#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Task
{
    char name[100]; // Stores task name max 100 characters
    int isDone;     // To check task status
};

struct Task tasks[10]; // Array to hold upto 10 tasks
int taskCount = 0;     // Counts how many tasks were added

void addTask()
{
    if (taskCount < 10)
    {
        printf("\nEnter task name: ");
        fgets(tasks[taskCount].name, 100, stdin); // Reass the streing with the spaces
        tasks[taskCount].name[strcspn(tasks[taskCount].name, "\n")] = '\0';
        tasks[taskCount].isDone = 0; // New task will always be pending
        taskCount++;
        printf("Task Added Successfully!\n");
    }
    else
    {
        printf("\nTask list is full!\n");
    }
}

void viewtask()
{
    if (taskCount == 0)
    {
        printf("\nNo tasks were added yet!\n");
    }
    else
    {
        printf("\n-- YOUR TASKS --\n");
        for (int i = 0; i < taskCount; i++)
        {
            printf("%d. %s", i + 1, tasks[i].name);
            if (tasks[i].isDone == 1)
            {
                printf(" [Done]\n");
            }
            else
            {
                printf(" [Pending]\n");
            }
        }
    }
}

void editTask() // This editTask() function allows user to edit an existing task name
{
    if (taskCount == 0) // if no tasks added yet
    {
        printf("\nNo tasks added yet!\n");
        return; // stop the function
    }
    viewtask(); // show all tasks so user can see which one to edit

    int editChoice; // stores which task user wants to edit
    printf("\nEnter task number to edit: ");
    scanf("%d", &editChoice);

    if (editChoice > 0 && editChoice <= taskCount) // check if valid task number
    {
        char newName[100];
        printf("Enter new task name: ");
        fgets(newName, 100, stdin);                  // read new name including spaces
        newName[strcspn(newName, "\n")] = '\0';      // removes \n and adds '\0' terminator to end the string
        strcpy(tasks[editChoice - 1].name, newName); // strcpy copies newName into the selected task
        printf("Task edited successfully!\n");
    }
    else
    {
        printf("\nInvalid task number!\n");
    }
}

int main()
{
    int choice;
    printf("=========================\n");
    printf("-- THE DISCIPLINE DESK --\n");
    printf("=========================\n");
    printf("Welcome to your productivity hub!\n");

    while (1)
    {
        printf("\n-- Main Menu --\n");
        printf("---------------\n");
        printf("1. Add Tasks\n");
        printf("2. View Tasks\n");
        printf("3. Edit Task\n");
        printf("4. Progress Report\n");
        printf("5. Motivation Quote\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addTask(); // addTask() function call
            break;
        case 2:
            viewtask(); // viewTask() function call
            break;
        case 3:
            editTask();
            break;
        case 4:
            printf("\n[Progress Report -Comming Soon]\n");
            break;
        case 5:
            printf("\n[Motivation Quote -Comming Soon]\n");
            break;
        case 6:
            printf("\nStay Disciplined! Good Luck!\n");
            exit(0); // This function is used from the stdlib.h library
        default:
            printf("\nInvalid Choice! Please enter 1-6.\n");
        }
    }
    return 0;
}