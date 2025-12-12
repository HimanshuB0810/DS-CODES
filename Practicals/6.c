//6. Program based on Binary Search Trees Maintain employee database and implement the following
// i. Display the names of employee based on salary
// ii. Display the name of employee having maximumand minimum Salary
// iii. Find the total monthly expenses of the companyon employee salary

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee{
    int salary;
    char name[50];
    struct employee*left;
    struct employee*right;
};

struct employee* getnode(char name[],int salary)
{
    struct employee *newnode=(struct employee*)malloc(sizeof(struct employee));
    newnode->salary=salary;
    strcpy(newnode->name,name);
    newnode->left=newnode->right=NULL;
    return newnode;
}

struct employee* insert(struct employee* root, char name[], int salary)
{
    if(root==NULL)
    {
        return getnode(name, salary);
    }
    if(salary< root->salary) //left child
    {
        root->left=insert(root->left,name,salary);
    }
    else if(salary>root->salary) //right child
    {
        root->right=insert(root->right,name,salary);
    }
    else
    {
        printf("Employee with salary %d already exists. Skipping insert\n",salary);
    }
    return root;
}

void displayBySalary(struct employee*root)
{
    if(root==NULL)
    {
        return;
    }

    displayBySalary(root->left);
    printf("Name: %s\t Salary: %d\n",root->name,root->salary);
    displayBySalary(root->right);
}

struct employee* findMin(struct employee* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

struct employee* findMax(struct employee* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}

int totalSalary(struct employee* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return root->salary+totalSalary(root->left)+totalSalary(root->right);
}

int main()
{
    struct employee* root= NULL;
    int choice;
    char name[50];
    int salary;

    while (1) 
    {
        printf("\n--- Employee Database (BST) ---\n");
        printf("1. Insert Employee\n");
        printf("2. Display Employees (sorted by salary)\n");
        printf("3. Display Employee with Min and Max Salary\n");
        printf("4. Display Total Monthly Salary Expense\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            printf("Enter Employee Name: ");
            scanf("%s",&name);
            printf("Enter salary: ");
            scanf("%d",&salary);
            root=insert(root,name,salary);
            break;

            case 2:
            displayBySalary(root);
            break;

            case 3:
            {struct employee* minEmp=findMin(root);
            struct employee* maxEmp=findMax(root);
            printf("Employee with MIN salary:\n");
            printf("Name: %s\t Salary:%d\n",minEmp->name,minEmp->salary);
            printf("Employee with MAX salary:\n");
            printf("Name: %s\t Salary:%d\n",maxEmp->name,maxEmp->salary);
            break;}

            case 4:
            {int total=totalSalary(root);
            printf("Total monthly salary expense: %d",total);
            break;}

            case 5:
            return 0;

            default:
            printf("Invalid Choice");
        }
    }
    return 0;
}