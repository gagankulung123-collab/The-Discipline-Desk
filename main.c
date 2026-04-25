#include <stdio.h>
#include <stdlib.h>
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
        scanf(" %[^\n]", tasks[taskCount].name); // Reads full task name including spaces
        tasks[taskCount].isDone = 0;             // New task will be always pending
        taskCount++;
        printf("Task Added Successfully!\n");
    }
    else
    {
        printf("\nTask list is full!\n");
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
        printf("3. Search Tasks\n");
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
            printf("\n[View tasks -Comming Soon]\n");
            break;
        case 3:
            printf("\n[Search task -Comming Soon]\n");
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