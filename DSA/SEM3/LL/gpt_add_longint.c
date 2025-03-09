#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add two linked lists
struct Node* addTwoLists(struct Node* first, struct Node* second) {
    struct Node* result = NULL; // Result linked list
    struct Node** lastPtrRef = &result; // Pointer to the last node in result
    int carry = 0; // Initialize carry

    // Loop through both lists until both are empty
    while (first != NULL || second != NULL || carry) {
        int sum = carry; // Start with carry

        // Add first list's data
        if (first != NULL) {
            sum += first->data;
            first = first->next;
        }

        // Add second list's data
        if (second != NULL) {
            sum += second->data;
            second = second->next;
        }

        // Update carry for next iteration
        carry = sum / 10;

        // Create a new node for the digit and link it
        *lastPtrRef = newNode(sum % 10);
        lastPtrRef = &((*lastPtrRef)->next); // Move the pointer forward
    }

    return result;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Example usage
int main() {
    // Creating first linked list: 7 -> 1 -> 6 (represents 617)
    struct Node* first = newNode(7);
    first->next = newNode(1);
    first->next->next = newNode(6);

    // Creating second linked list: 5 -> 9 -> 2 (represents 295)
    struct Node* second = newNode(5);
    second->next = newNode(9);
    second->next->next = newNode(2);

    // Add the two lists
    struct Node* result = addTwoLists(first, second);

    // Print the result
    printf("Resultant List: ");
    printList(result);

    return 0;
}
