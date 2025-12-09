// Maintain a record of student database of a class
// implement following operations using Linked list:
// i. Count the number of students in a class and display
// their names
// ii. Display the name of student having maximum CGPA
// iii. Addition of new student in the database
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
    int roll_no;
    char name[50];
    float cgpa;
    char branch[30];
    struct student *next;
};

struct student *head = NULL;
struct student *temp = NULL;
struct student *newnode = NULL;

// Function to add a new student to the database
void addStudent()
{
    printf("\n=== Adding New Student ===\n");
    
    // Allocate memory for new student
    newnode = (struct student*)malloc(sizeof(struct student));
    if(newnode == NULL)
    {
        printf("Memory Allocation Failed!\n");
        return;
    }
    
    // Get student details from user
    printf("Enter Student Details:\n");
    printf("Roll Number: ");
    scanf("%d", &newnode->roll_no);
    
    printf("Name: ");
    scanf(" %[^\n]", newnode->name);  // Read string with spaces
    
    printf("CGPA: ");
    scanf("%f", &newnode->cgpa);
    
    printf("Branch: ");
    scanf(" %[^\n]", newnode->branch);
    
    newnode->next = NULL;
    
    // Add the new node to the linked list
    if(head == NULL)
    {
        // List is empty, make this the first node
        head = newnode;
    }
    else
    {
        // Add at the end of the list
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    
    printf("Student added successfully!\n");
}

// Function to count students and display their names
void countAndDisplayStudents()
{
    int count = 0;
    temp = head;
    
    printf("\n=== Student Database ===\n");
    
    if(head == NULL)
    {
        printf("No students in the database.\n");
        return;
    }
    
    printf("List of Students:\n");
    
    while(temp != NULL)
    {
        count++;
        printf("Roll No: %d\n", temp->roll_no);
        printf("Name: %s\n", temp->name);
        printf("CGPA: %.2f\n", temp->cgpa);
        printf("Branch: %s\n", temp->branch);
        printf("------------------------\n");
        temp = temp->next;
    }
    printf("Total Number of Students: %d\n", count);
}

// Function to find and display student with maximum CGPA
void findMaxCGPA()
{
    if(head == NULL)
    {
        printf("\nNo students in the database.\n");
        return;
    }
    
    temp = head;
    struct student *maxStudent = head;
    float maxCGPA = head->cgpa;
    
    // Traverse the list to find maximum CGPA
    while(temp != NULL)
    {
        if(temp->cgpa > maxCGPA)
        {
            maxCGPA = temp->cgpa;
            maxStudent = temp;
        }
        temp = temp->next;
    }
    
    printf("\n=== Student with Maximum CGPA ===\n");
    printf("Name: %s\n", maxStudent->name);
    printf("Roll Number: %d\n", maxStudent->roll_no);
    printf("CGPA: %.2f\n", maxStudent->cgpa);
    printf("Branch: %s\n", maxStudent->branch);
}

// Function to free allocated memory
void freeDatabase()
{
    struct student *current = head;
    struct student *next;
    
    while(current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

// Function to display menu
void displayMenu()
{
    printf("\n========== STUDENT DATABASE MANAGEMENT ==========\n");
    printf("1. Add New Student\n");
    printf("2. Count Students and Display Names\n");
    printf("3. Find Student with Maximum CGPA\n");
    printf("4. Exit\n");
    printf("================================================\n");
    printf("Enter your choice: ");
}

int main()
{
    int choice;
    
    printf("=== STUDENT DATABASE MANAGEMENT SYSTEM ===\n");
    
    // Initialize choice to continue the loop
    choice = 0;
    
    while(choice != 4)
    {
        displayMenu();
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                addStudent();
                break;
                
            case 2:
                countAndDisplayStudents();
                break;
                
            case 3:
                findMaxCGPA();
                break;
                
            case 4:
                printf("Exiting program...\n");
                freeDatabase();
                printf("Memory freed successfully. Goodbye!\n");
                break;
                
            default:
                printf("Invalid choice! Please enter 1-4.\n");
        }
    }
    
    return 0;
}