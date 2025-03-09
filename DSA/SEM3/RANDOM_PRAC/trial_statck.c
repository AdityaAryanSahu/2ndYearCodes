#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    char elements[MAX_SIZE];
    int top;
} STACK;

int isfull(STACK *s) {
    return (s->top == MAX_SIZE - 1);
}

int isempty(STACK *s) {
    return (s->top == -1);
}

void push(STACK *s, char e) {
    if (isfull(s)) {
        printf("Stack is full, cannot push '%c'\n", e);
    } else {
        s->elements[++(s->top)] = e;
    }
}

char pop(STACK *s) {
    if (isempty(s)) {
        printf("Stack is empty, cannot pop\n");
        return '\0';  // Return a null character as an error indicator
    } else {
        return s->elements[(s->top)--];
    }
}

void display(char st) {
    printf("The popped char is %c\n", st);
}

int main() {
    STACK s;
    s.top = -1;  // Initialize top to -1 for an empty stack
    int ch;
    char item;
    char p;

    do {
        printf("1.push 2.pop 3.exit\n");
        scanf("%d", &ch);
        getchar();  // Consume newline character

        switch (ch) {
            case 1:
                printf("Enter character to push: ");
                item = getchar();
                getchar();  // Consume newline character
                push(&s, item);
                break;

            case 2:
                p = pop(&s);
                if (p != '\0') {  // Check if pop was successful
                    display(p);
                }
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (ch != 3);

    return 0;
}
