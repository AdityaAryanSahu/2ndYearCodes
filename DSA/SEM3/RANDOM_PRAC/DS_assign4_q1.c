#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR_SIZE 100

// Structure for a node in doubly linked list
typedef struct Node {
     // Stores tag: <TEST>, <POSTFIX>, <PREFIX>
    char expression[MAX_EXPR_SIZE];  // Stores expression
    int result;                  // Stores the result (for expression nodes)
    struct Node* next;
    struct Node* prev;
} Node;

// Insert function to insert a node at the beginning of the linked list
Node* Insert(Node* head, char* tag, char* expression) {
    Node* newNode1 = (Node*)malloc(sizeof(Node));
    Node* newNode2 = (Node*)malloc(sizeof(Node));
    strcpy(newNode2->expression, tag);
    strcpy(newNode1->expression, expression);
    newNode2->result = 0; 
    newNode1->result = 0; // Initialize result as 0, to be updated after processing
    newNode1->next = head;
    newNode1->prev = newNode2;
    newNode2->prev=NULL;
    newNode2->next=newNode1;

    if (head != NULL) {
        head->prev = newNode1;
    }

    
    return newNode2;
}

// Display function to display the list of expressions and results
void Display(Node* head) {
    Node* temp = head;
    Node* tem = NULL;
    while (temp != NULL) {
        if(strcmp(temp->expression,"<TEST>")==0||strcmp(temp->expression,"<PREFIX>")==0||strcmp(temp->expression,"<POSTFIX>")==0)
             {
                printf("Tag: %s" ,temp->expression);
            if (temp->next) {
                printf(", Expression: %s, Result: %d\n", temp->next->expression, temp->next->result);
                temp = temp->next;  // Move to the expression node
            }
        }
        temp = temp->next;
    }
}

// Function to check if an expression has balanced parentheses
int CheckExpression(char* expr) {
    int balance = 0;
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(') balance++;
        else if (expr[i] == ')') balance--;
        if (balance < 0) return 0; // Unbalanced
    }
    return (balance == 0);
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Helper function to perform an operation on two operands
int performOperation(int op1, int op2, char  operato) {
    switch (operato) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        default: return 0;
    }
}
// Function to process all expressions in the linked list


int ComputePostfix(char* expr) {
    int stack[MAX_EXPR_SIZE];
    int top = -1;

    for (int i = 0; expr[i] != '\0'; i++) {
        if (isdigit(expr[i])) {
            stack[++top] = expr[i] - '0';  // Convert char to int
        } else if (isOperator(expr[i])) {
            int op2 = stack[top--];
            int op1 = stack[top--];
            int result = performOperation(op1, op2, expr[i]);
            stack[++top] = result;
        }
    }

    return stack[top];  // Final result
}

int ComputePrefix(char* expr) {
    int stack[MAX_EXPR_SIZE];
    int top = -1;

    // Reverse traverse for prefix
    for (int i = strlen(expr) - 1; i >= 0; i--) {
        if (isdigit(expr[i])) {
            stack[++top] = expr[i] - '0';  // Convert char to int
        } else if (isOperator(expr[i])) {
            int op1 = stack[top--];
            int op2 = stack[top--];
            int result = performOperation(op1, op2, expr[i]);
            stack[++top] = result;
        }
    }

    return stack[top];  // Final result
}
Node* ProcessExpressions(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->expression, "<POSTFIX>") == 0 && CheckExpression(temp->next->expression)) {
            temp->next->result = ComputePostfix(temp->next->expression);
        } else if (strcmp(temp->expression, "<PREFIX>") == 0 && CheckExpression(temp->next->expression)) {
            temp->next->result = ComputePrefix(temp->next->expression);
        }
        temp = temp->next->next;
    }
    return head;
}

// Main function for the menu-driven program
int main() {
    Node* head = NULL;
    int choice;
    char tag[MAX_EXPR_SIZE], expression[MAX_EXPR_SIZE];

    do {
        printf("\nMenu: 1. Insert Expression 2. Process and Evaluate Expressions 3. Display List 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character

        switch (choice) {
            case 1:
                printf("Enter tag (<TEST>, <POSTFIX>, <PREFIX>): ");
                fgets(tag, MAX_EXPR_SIZE, stdin);
                tag[strcspn(tag, "\n")] = 0;  // Remove trailing newline

                printf("Enter exp: ");
                fgets(expression, MAX_EXPR_SIZE, stdin);
                expression[strcspn(expression, "\n")] = 0;  // Remove trailing newline

                head = Insert(head, tag, expression);
                break;

            case 2:
                head = ProcessExpressions(head);
                printf("Expressions processed and results updated.\n");
                break;

            case 3:
                Display(head);
                break;
        }
    } while (choice != 4);

    return 0;
}
