#include<stdio.h>
#include<stdlib.h>

struct Student {
    char name[20], branch[20];
    int m1, m2, m3;
    double percentage;  // Added to store individual percentages
};

int main() {
    struct Student *ptr;
    ptr = (struct Student*)malloc(3 * sizeof(struct Student));
    
    if (ptr == NULL) {  // Check if memory allocation was successful
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    int i;
    
    // Input section
    for(i = 0; i < 3; i++) 
    {
        printf("Enter the details of Student %d\n", i + 1);
        printf("Enter Name: ");
        scanf("%s", (ptr + i)->name);
        printf("Enter Branch: ");
        scanf("%s", (ptr + i)->branch);
        printf("Enter Marks in 3 Subjects: ");
        scanf("%d %d %d", &(ptr + i)->m1, &(ptr + i)->m2, &(ptr + i)->m3);
        
        // Calculate percentage for each student
        (ptr + i)->percentage = (((ptr + i)->m1 + (ptr + i)->m2 + (ptr + i)->m3) * 100.0) / 300.0;
        printf("\n");
    }
    
    // Output section
    printf("\n--- Student Details ---\n");
    for(i = 0; i < 3; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", (ptr + i)->name);
        printf("Branch: %s\n", (ptr + i)->branch);  
        printf("Marks in 3 Subjects: %d %d %d\n", (ptr + i)->m1, (ptr + i)->m2, (ptr + i)->m3);
        printf("Percentage: %.2f%%\n", (ptr + i)->percentage);
    }
    
    free(ptr);
    return 0;
}