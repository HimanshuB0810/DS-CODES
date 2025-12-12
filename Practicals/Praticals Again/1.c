// Design a feature for a basic text editor that allows users to perform undo and redo operations using a stack

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
struct Stack{
    char data[100][MAX];
    int top;
};

void init(struct Stack*s)
{
    s->top=-1;
}

int isEmpty(struct Stack *s)
{
    return s->top==-1;
}

void push(struct Stack*s, char text[])
{
    if(s->top<99)
    {
        s->top++;
        strcpy(s->data[s->top],text);
    }
}

void pop(struct Stack *s, char text[])
{
    if(!isEmpty(s))
    {
        strcpy(text,s->data[s->top]);
        s->top--;
    }
}

int main()
{
    char text[MAX]="";
    char temp[MAX];

    struct Stack undoStack, redoStack;
    init(&undoStack);
    init(&redoStack);

    int choice;
    while(1)
    {
        printf("1. Type Text\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Show Text\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  

        switch(choice)
        {
            case 1:
            push(&undoStack, text);
            printf("Enter new text: ");
            fgets(temp, MAX, stdin);
            strcpy(text,temp);
            init(&redoStack);
            break;

            case 2:
            if(!isEmpty(&undoStack))
            {
                push(&redoStack,text);
                pop(&undoStack,text);
                printf("Undo performed");
            }
            else
            {
                printf("Nothing to undo");
            }
            break;

            case 3:
            if (!isEmpty(&redoStack))
            {
                push(&undoStack,text);
                pop(&redoStack,text);
                printf("Redo performed");
            }
            else
            {
                printf("Nothing to redo");
            }
            break;

            case 4:
            printf("Current text: %s",text);
            break;

            case 5:
            exit(0);

            default:
            printf("Invalid choice");
        }
    }
    return 0;

}