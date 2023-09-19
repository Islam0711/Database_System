#include <stdio.h>
#include <stdlib.h>
#include "STD.h"
#include "SDB.h"


void SDB_APP()//this function used to give the user the options to select from it.
{
    uint8 choice;
 while (1)
    {
        printf("Please choose an option:\n\n");
        printf("1.Add entry\n2.Get used size\n3.Read student data\n4.Get list of student IDs\n5.Check if ID exists\n6.Delete student data\n7.Check if database is full\n8.to exit press 0\n");
        scanf("%u", &choice);

        if (choice == 0)//if the user select 0 exit the program.
            break;

        SDB_action(choice);
    }
}

void SDB_action(uint8 choice)//this function takes the user choice and call the function that related to it.
{
    unsigned int id;
    uint8 i;
    uint8 count;
    uint32 *list[10];


    switch (choice)
    {
        case 1:
        if (SDB_AddEntry())
            printf("Entry added successfully.\n");
        else
            printf("Failed to add entry.\n");
        break;
        //////////////////////////////////////////////////////////
        case 2:
        printf("Used size in database: %u\n", SDB_GetUsedSize());
        break;
        /////////////////////////////////////////////////////////
        case 3:

        printf("Enter Student ID to read: ");
        scanf("%u", &id);
        if (!SDB_ReadEntry(id))
            {
            printf("Student not found.\n");
            }
        break;

        case 4:
            SDB_GetList(&count, list);
            printf("List of student IDs:\n");
            for (i = 0; i < count; i++)
                {
                printf("%u\n", list[i]);
            }
            break;
        /////////////////////////////////////////////////////////
        case 5:
        printf("Enter student ID: ");
        scanf("%u", &id);
        if (SDB_IsIdExist(id))
            printf("Student ID exists.\n");
        else
            printf("Student ID does not exist.\n");
        break;
        /////////////////////////////////////////////////////////
        case 6:
        printf("Enter student ID to delete: ");
        scanf("%u", &id);
        SDB_DeleteEntry(id);
        printf("Student data deleted.\n");
        break;
        /////////////////////////////////////////////////////////
        case 7:
        if (SDB_IsFull())
            printf("Database is full.\n");
        else
            printf("Database is not full.\n");
        break;
        /////////////////////////////////////////////////////////
        default:
        printf("Invalid choice.\n");
        break;
        /////////////////////////////////////////////////////////

    }

}

