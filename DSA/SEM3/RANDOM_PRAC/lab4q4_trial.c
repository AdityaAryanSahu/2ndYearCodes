#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, int value) {
    if (!isFull(s)) {
        s->data[++(s->top)] = value;
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return -1; // Error value
}

int peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return -1; // Error value
}

int main() {
    Stack s;
    int *arr;
    int n, k;
    int i;

    // Read number of elements and number of deletions
    scanf("%d", &n);
    scanf("%d", &k);

    // Validate input size
    if (n > MAX_SIZE) {
        printf("Number of elements exceeds maximum allowed size.\n");
        return 1;
    }

    // Allocate memory for array
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read elements into the array
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    initStack(&s);

    int deletionsRemaining = k;

    // Process elements and use stack operations
    for (i = 0; i < n; i++) {
        while (!isEmpty(&s) && deletionsRemaining > 0 && peek(&s) < arr[i]) {
            pop(&s);
            deletionsRemaining--;
        }
        push(&s, arr[i]);
    }
printf("after deketion\n");
    // Output remaining elements from stack
    while (!isEmpty(&s)) {
        printf("%d ", pop(&s));
    }
    printf("\n");

    // Free allocated memory
    free(arr);

    return 0;
}
