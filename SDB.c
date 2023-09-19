#include <stdio.h>
#include <stdlib.h>
#include "STD.h"
#include "SDB.h"

#define MIN_STUDENTS 3
#define MAX_STUDENTS 10


static uint8 numStudents = 0;
static student database[MAX_STUDENTS];
/////////////////////////////////////////////////////////

bool SDB_IsFull()//this function used to check if the database full or not.
{
    return numStudents >= MAX_STUDENTS;
}

uint8 SDB_GetUsedSize()//used to get used size and number of students in database.
{
    return numStudents;
}
/////////////////////////////////////////////////////////

bool SDB_AddEntry()//this function used to add the data of the students.
{
    if (SDB_IsFull())
        return false;//if the Database full return false and we can not add new data.

    student newStudent;

    printf("Enter Student ID: ");
    scanf("%u", &newStudent.Student_ID);

    printf("Enter Student Year: ");
    scanf("%u", &newStudent.Student_year);

    printf("Enter Course1 ID: ");
    scanf("%u", &newStudent.Course1_ID);

    printf("Enter Course1 Grade: ");
    scanf("%u", &newStudent.Course1_grade);

    printf("Enter Course2 ID: ");
    scanf("%u", &newStudent.Course2_ID);

    printf("Enter Course2 Grade: ");
    scanf("%u", &newStudent.Course2_grade);

    printf("Enter Course3 ID: ");
    scanf("%u", &newStudent.Course3_ID);

    printf("Enter Course3 Grade: ");
    scanf("%u", &newStudent.Course3_grade);

    database[numStudents++] = newStudent;
    return true;//if not full return true and we can start to add the student data.
}
/////////////////////////////////////////////////////////

void SDB_DeleteEntry(uint32 id)//this function used to delete the data of the student from the database.
{
    uint8 i;
    uint8 j;

    for  (i = 0; i < numStudents; i++)
    {
        if (database[i].Student_ID == id)
        {
            for (j = i; j < numStudents - 1; j++)
            {
                database[j] = database[j + 1];
            }
            numStudents--;
            break;
        }
    }
}
/////////////////////////////////////////////////////////

bool SDB_IsIdExist(uint32 id)//this function used to check if the ID of the student found in database or not.
{
    uint8 i;
    uint32 list[MAX_STUDENTS];


    for (i = 0; i < numStudents; i++)
    {
        if (database[i].Student_ID == id)//if the ID exist return true, if not found return false
        {
            return true;
        }
    }
    return false;
}
/////////////////////////////////////////////////////////

void SDB_GetList(uint8 *count, uint32 *list)//this function used to get the list of students ID and display it.
{
    uint8 i;
    *count = numStudents;
    for (i = 0; i < numStudents; i++)
    {
        list[i] = database[i].Student_ID;
    }
}
/////////////////////////////////////////////////////////

bool SDB_ReadEntry(uint32 id)//this function used to read and display the students data.
{
    uint8 i;
    for (i = 0; i < numStudents; i++)
        {
        if (database[i].Student_ID == id)//if the student ID is entered before we can display the data and return true, if not return false.
        {
            printf("Student ID: %u\n", database[i].Student_ID);
            printf("Student Year: %u\n", database[i].Student_year);
            printf("Course1 ID: %u\n", database[i].Course1_ID);
            printf("Course1 Grade: %u\n", database[i].Course1_grade);
            printf("Course2 ID: %u\n", database[i].Course2_ID);
            printf("Course2 Grade: %u\n", database[i].Course2_grade);
            printf("Course3 ID: %u\n", database[i].Course3_ID);
            printf("Course3 Grade: %u\n", database[i].Course3_grade);

            return true;
        }
    }
    return false;
}
