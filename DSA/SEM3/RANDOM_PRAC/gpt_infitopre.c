#include <stdio.h>
#include <string.h>

#define MAX 20

typedef struct {
    char ele[MAX];
    int top;
} STACK;

void push(STACK *s, char e) {
    if (s->top == MAX - 1) {
        printf("Stack is full\n");
    } else {
        s->ele[++(s->top)] = e;
    }
}

char pop(STACK *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return '\0'; // Return a null character for error handling
    } else {
        return s->ele[(s->top)--];
    }
}

int precedence(char i) {
    switch (i) {
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 3;
        case '(':
            return 1;
        case ')':
            return 0; // precedence of ')' doesn't matter in this context
        default:
            return -1; // Invalid operator
    }
}

void reverse(char p[]) {
    int n = strlen(p);
    for (int i = 0; i < n / 2; i++) {
        char temp = p[i];
        p[i] = p[n - i - 1];
        p[n - i - 1] = temp;
    }
}

void swapBrackets(char p[]) {
    int i = 0;
    while (p[i] != '\0') {
        if (p[i] == '(') {
            p[i] = ')';
        } else if (p[i] == ')') {
            p[i] = '(';
        }
        i++;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    STACK s;
    s.top = -1;
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];
        if (token >= 'a' && token <= 'z') { // Assuming single-letter operands
            postfix[j++] = token;
        } else if (token == '(') {
            push(&s, token);
        } else if (token == ')') {
            while (s.top != -1 && s.ele[s.top] != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Remove the '(' from the stack
        } else { // Operator
            while (s.top != -1 && precedence(token) <= precedence(s.ele[s.top])) {
                postfix[j++] = pop(&s);
            }
            push(&s, token);
        }
    }

    // Pop remaining elements in the stack
    while (s.top != -1) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[MAX] = "(a+b)/c-d";
    char reversedInfix[MAX];
    char postfix[MAX];

    // Reverse the infix expression
    strcpy(reversedInfix, infix);
    reverse(reversedInfix);

    // Swap brackets in the reversed infix expression
    swapBrackets(reversedInfix);
    printf("Reversed and swapped infix: %s\n", reversedInfix);

    // Convert reversed infix to postfix
    infixToPostfix(reversedInfix, postfix);
    printf("Postfix of reversed infix: %s\n", postfix);

    // Reverse the postfix expression to get prefix
    reverse(postfix);
    printf("Prefix expression: %s\n", postfix);

    return 0;
}
