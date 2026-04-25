#include <stdio.h>
#include <stdlib.h>
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
            printf("\n[Add task -Comming Soon]\n");
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
            exit(0);
        default:
            printf("\nInvalid Choice! Please enter 1-6.\n");
        }
    }
    return 0;
}