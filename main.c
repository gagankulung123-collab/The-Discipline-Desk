#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Task
{
    char name[100];
    int isDone;
};

struct Task tasks[10];
int taskCount = 0;

void addTask()
{
    if (taskCount < 10)
    {
        printf("\nEnter task name: ");
        scanf(" %[^\n]", tasks[taskCount].name);
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
        return;
    }

    printf("\n-- YOUR TASKS --\n");
    for (int i = 0; i < taskCount; i++)
    {
        printf("%d. %s", i + 1, tasks[i].name);
        if (tasks[i].isDone == 1)
            printf(" [Done]\n");
        else
            printf(" [Pending]\n");
    }

    printf("\nEnter task numbers to mark as done (0 to skip): ");

    int markChoice;

    while (scanf("%d", &markChoice) && markChoice != 0)
    {
        if (markChoice > 0 && markChoice <= taskCount)
        {
            tasks[markChoice - 1].isDone = 1;
            printf("Task %d marked as done!\n", markChoice);
        }
        else
        {
            printf("Invalid task number!\n");
        }
    }

    printf("\nEnter task numbers to delete (0 to skip): ");

    int deleteChoice;

    while (scanf("%d", &deleteChoice) && deleteChoice != 0)
    {
        if (deleteChoice > 0 && deleteChoice <= taskCount)
        {
            for (int i = deleteChoice - 1; i < taskCount - 1; i++)

                tasks[i] = tasks[i + 1]; // shift tasks left to fill the gap
            taskCount--;

            printf("Task %d deleted successfully!\n", deleteChoice);
        }
        else
        {
            printf("Invalid task number!\n");
        }
    }
}

void editTask() // This editTask() function allows user to edit an existing task name
{
    if (taskCount == 0)
    {
        printf("\nNo tasks added yet!\n");
        return;
    }
    viewtask(); // show all tasks so user can see which one to edit

    int editChoice;

    printf("\nEnter task number to edit: ");
    scanf("%d", &editChoice);

    if (editChoice > 0 && editChoice <= taskCount)
    {
        char newName[100];

        printf("Enter new task name: ");
        scanf(" %[^\n]", newName);
        strcpy(tasks[editChoice - 1].name, newName); // strcpy copies newName into the selected task
        printf("Task edited successfully!\n");
    }
    else
    {
        printf("\nInvalid task number!\n");
    }
}
void progressReport() // This function will calculates and displays task status summary
{
    if (taskCount == 0)
    {
        printf("\nNo tasks added yet!\n");
        return;
    }

    int completed = 0;
    int pending = 0;

    for (int i = 0; i < taskCount; i++)
    {
        if (tasks[i].isDone == 1)
        {
            completed++;
        }
        else
        {
            pending++;
        }
    }

    int productivity = (completed * 100) / taskCount;

    printf("\n--- PROGRESS REPORT ---\n");
    printf("Total Tasks  : %d\n", taskCount);
    printf("Completed    : %d\n", completed);
    printf("Pending      : %d\n", pending);
    printf("Productivity : %d%%\n", productivity);

    if (productivity == 100)
    {
        printf("Excellent! All tasks completed!\n");
    }
    else if (productivity >= 50)
    {
        printf("Good job! Keep going!\n");
    }
    else if (productivity > 0)
    {
        printf("Keep pushing! You can do it!\n");
    }
    else
    {
        printf("No tasks completed yet! Start now!\n");
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
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addTask();
            break;
        case 2:
            viewtask();
            break;
        case 3:
            editTask();
            break;
        case 4:
            progressReport();
            break;
        case 5:
            printf("\nStay Disciplined! Good Luck!\n");
            exit(0);
        default:
            printf("\nInvalid Choice! Please enter 1-5.\n");
        }
    }
    return 0;
}