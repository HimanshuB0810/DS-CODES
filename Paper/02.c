// Consider a linked list of names of patients suffering with COVID 19. While
// creating linked list some patients might get infected more than ones. Write
// a function to print first occurence of duplicated patient. Consider first name
// and last name as fields of the node structure of linked list.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct patient
{
    char first_name[30];
    char last_name[30];
    int patient_id;
    struct patient *next;
};

struct patient *head = NULL;
struct patient *temp = NULL;
struct patient *newnode = NULL;

// Function to add a new patient to the list
void addPatient()
{
    printf("\n=== Adding New Patient ===\n");
    
    // Allocate memory for new patient
    newnode = (struct patient*)malloc(sizeof(struct patient));
    if(newnode == NULL)
    {
        printf("Memory Allocation Failed!\n");
        return;
    }
    
    // Get patient details from user
    printf("Enter Patient Details:\n");
    printf("Patient ID: ");
    scanf("%d", &newnode->patient_id);
    
    printf("First Name: ");
    scanf("%s", newnode->first_name);
    
    printf("Last Name: ");
    scanf("%s", newnode->last_name);
    
    newnode->next = NULL;
    
    // Add the new node to the linked list
    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    
    printf("Patient %s %s added successfully!\n", newnode->first_name, newnode->last_name);
}

// Function to display all patients
void displayPatients()
{
    temp = head;
    int count = 0;
    
    printf("\n=== COVID-19 Patient List ===\n");
    
    if(head == NULL)
    {
        printf("No patients in the database.\n");
        return;
    }
    
    printf("List of Patients:\n");
    
    while(temp != NULL)
    {
        count++;
        printf("Patient ID: %d\n", temp->patient_id);
        printf("Name: %s %s\n", temp->first_name, temp->last_name);
        printf("------------------------\n");
        temp = temp->next;
    }
    
    printf("Total Number of Patients: %d\n", count);
}

// Function to check if two patients have the same name
int isSameName(struct patient *p1, struct patient *p2)
{
    if(strcmp(p1->first_name, p2->first_name) == 0 && 
       strcmp(p1->last_name, p2->last_name) == 0)
    {
        return 1; // Same name
    }
    return 0; // Different names
}

// Function to find and print first occurrence of duplicated patient
void findFirstDuplicate()
{
    struct patient *current, *check;
    
    printf("\n=== Finding First Duplicate Patient ===\n");
    
    if(head == NULL || head->next == NULL)
    {
        printf("Not enough patients to check for duplicates.\n");
        return;
    }
    
    current = head;
    
    // Traverse each node
    while(current != NULL)
    {
        check = current->next;
        
        // Check all nodes after current node
        while(check != NULL)
        {
            if(isSameName(current, check))
            {
                printf("First Duplicate Patient Found!\n");
                printf("Patient Name: %s %s\n", current->first_name, current->last_name);
                printf("First Occurrence - Patient ID: %d\n", current->patient_id);
                printf("Duplicate Occurrence - Patient ID: %d\n", check->patient_id);
                printf("This patient has been infected more than once.\n");
                return; // Exit after finding first duplicate
            }
            check = check->next;
        }
        current = current->next;
    }
    
    printf("No duplicate patients found in the database.\n");
}

// Function to initialize with sample data for testing
void initializeSampleData()
{
    printf("Do you want to add sample COVID patient data? (1 for Yes, 0 for No): ");
    int choice;
    scanf("%d", &choice);
    
    if(choice == 1)
    {
        // Sample patient 1
        struct patient *p1 = (struct patient*)malloc(sizeof(struct patient));
        p1->patient_id = 1001;
        strcpy(p1->first_name, "John");
        strcpy(p1->last_name, "Doe");
        p1->next = NULL;
        head = p1;
        
        // Sample patient 2
        struct patient *p2 = (struct patient*)malloc(sizeof(struct patient));
        p2->patient_id = 1002;
        strcpy(p2->first_name, "Jane");
        strcpy(p2->last_name, "Smith");
        p2->next = NULL;
        p1->next = p2;
        
        // Sample patient 3 (duplicate of John Doe)
        struct patient *p3 = (struct patient*)malloc(sizeof(struct patient));
        p3->patient_id = 1003;
        strcpy(p3->first_name, "John");
        strcpy(p3->last_name, "Doe");
        p3->next = NULL;
        p2->next = p3;
        
        // Sample patient 4
        struct patient *p4 = (struct patient*)malloc(sizeof(struct patient));
        p4->patient_id = 1004;
        strcpy(p4->first_name, "Bob");
        strcpy(p4->last_name, "Johnson");
        p4->next = NULL;
        p3->next = p4;
        
        // Sample patient 5 (duplicate of Jane Smith)
        struct patient *p5 = (struct patient*)malloc(sizeof(struct patient));
        p5->patient_id = 1005;
        strcpy(p5->first_name, "Jane");
        strcpy(p5->last_name, "Smith");
        p5->next = NULL;
        p4->next = p5;
        
        printf("Sample COVID patient data added successfully!\n");
        printf("Note: John Doe and Jane Smith appear multiple times (re-infections)\n");
    }
}

// Function to display menu
void displayMenu()
{
    printf("\n========== COVID-19 PATIENT TRACKING SYSTEM ==========\n");
    printf("1. Add New Patient\n");
    printf("2. Display All Patients\n");
    printf("3. Find First Duplicate Patient\n");
    printf("4. Exit\n");
    printf("=====================================================\n");
    printf("Enter your choice: ");
}

// Function to free memory
void freePatientList()
{
    struct patient *current = head;
    struct patient *next;
    
    while(current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

int main()
{
    int choice;
    
    printf("=== COVID-19 PATIENT DUPLICATE DETECTION SYSTEM ===\n");
    initializeSampleData();
    
    do
    {
        displayMenu();
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                addPatient();
                break;
                
            case 2:
                displayPatients();
                break;
                
            case 3:
                findFirstDuplicate();
                break;
                
            case 4:
                printf("Exiting program...\n");
                freePatientList();
                printf("Memory freed successfully. Stay Safe!\n");
                break;
                
            default:
                printf("Invalid choice! Please enter 1-4.\n");
        }
        
    } while(choice != 4);
    
    return 0;
}