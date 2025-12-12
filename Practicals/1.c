#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


struct Stack {
    char data[100][MAX];  
    int top;
};


void init(struct Stack *s) {
    s->top = -1;
}


int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, char text[]) {
    if ( s->top < 99 ) {
        s->top++;
        strcpy(s->data[s->top], text);
    }
}

// Pop text state from stack
void pop(struct Stack *s, char text[]) {
    if (!isEmpty(s)) {
        strcpy(text, s->data[s->top]);
        s->top--;
    }
}

int main() {
    char text[MAX] = "";      // Current text
    char temp[MAX];

    struct Stack undoStack, redoStack;
    init(&undoStack);
    init(&redoStack);

    int choice;

    while (1) {
        printf("\n\n--- Text Editor ---\n");
        printf("1. Type Text\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Show Text\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  // consume newline

        switch (choice) {

        case 1:
            // save current state before editing
            push(&undoStack, text);

            printf("Enter new text: ");
            fgets(temp, MAX, stdin);
            temp[strcspn(temp, "\n")] = '\0';

            strcpy(text, temp);

            // Clear redo stack because new action happened
            init(&redoStack);
            break;

        case 2: // Undo
            if (!isEmpty(&undoStack)) {
                push(&redoStack, text);  // save current state
                pop(&undoStack, text);   // restore previous state
                printf("Undo performed.\n");
            } else {
                printf("Nothing to undo.\n");
            }
            break;

        case 3: // Redo
            if (!isEmpty(&redoStack)) {
                push(&undoStack, text);  // save current
                pop(&redoStack, text);   // redo previous undone
                printf("Redo performed.\n");
            } else {
                printf("Nothing to redo.\n");
            }
            break;

        case 4:
            printf("Current Text: %s\n", text);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
