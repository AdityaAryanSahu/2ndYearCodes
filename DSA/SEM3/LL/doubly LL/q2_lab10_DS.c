#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* llink;
    struct node* rlink;
};

// Function to insert a digit at the beginning of the circular doubly linked list
void insert_front(struct node** header, int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    if ((*header)->rlink == *header) {  // Empty list
        newnode->rlink = *header;
        newnode->llink = *header;
        (*header)->rlink = newnode;
        (*header)->llink = newnode;
    } else {
        struct node* first = (*header)->rlink;
        newnode->rlink = first;
        newnode->llink = *header;
        (*header)->rlink = newnode;
        first->llink = newnode;
    }
}

// Function to create a header node
struct node* create_header() {
    struct node* header = (struct node*)malloc(sizeof(struct node));
    header->rlink = header;
    header->llink = header;
    return header;
}

// Function to display the number in correct order
void display(struct node* header) {
    struct node* temp = header->rlink;
    while (temp != header) {
        printf("%d", temp->data);
        temp = temp->rlink;
    }
    printf("\n");
}




// Function to add two numbers represented by circular doubly linked lists
struct node* add_numbers(struct node* header1, struct node* header2) {
    struct node* result_header = create_header();
    struct node* num1 = header1->llink;  // Start from least significant digit
    struct node* num2 = header2->llink;
    int carry = 0, sum;

    // Add digits until both lists are traversed
    while (num1 != header1 || num2 != header2 || carry != 0) {
        int digit1 = (num1 != header1) ? num1->data : 0;
        int digit2 = (num2 != header2) ? num2->data : 0;

        sum = digit1 + digit2 + carry;
        carry = sum / 10;
        sum = sum % 10;

        // Insert the result at the front (as digits are in reverse order)
        insert_front(&result_header, sum);

        if (num1 != header1) num1 = num1->llink;
        if (num2 != header2) num2 = num2->llink;
    }

    return result_header;
}

// Function to free the list
void free_list(struct node* header) {
    struct node* temp = header->rlink;
    while (temp != header) {
        struct node* next = temp->rlink;
        free(temp);
        temp = next;
    }
    free(header);
}

int main() {
    // Create headers for two numbers
    struct node* header1 = create_header();
    struct node* header2 = create_header();
    struct node* result_header=NULL;
    int n,ch;
    do{
    printf("1.insert L1 2.insert L2 3.add 4.displayL1 5.displayL2 6.displayL3 7.exit\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:printf("enter integer to be added i L1 in reverse order\n");
                 scanf("%d",&n);
                 insert_front(&header1,n);
                 break;
        case 2:printf("enter integer to be added i L2 in reverse order\n");
                 scanf("%d",&n);
                 insert_front(&header2,n);break;
        case 3:{ result_header = add_numbers(header1, header2);
                break;}
        case 4:{printf("First number: ");
                display(header1);
                printf("\n");
                break;}
        case 5:{printf("Second number: ");
                 display(header2); printf("\n");break;}
    case 6:{printf("Result: ");
    display(result_header);break;}
    }
    }while (ch!=7);
    
 free_list(header1);
    free_list(header2);
    free_list(result_header);
}
   