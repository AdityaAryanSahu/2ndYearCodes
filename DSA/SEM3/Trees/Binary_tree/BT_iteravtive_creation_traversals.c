#include<stdio.h>
#include<stdlib.h>
struct node{
    char data;
    struct node* lchild;
        struct node* rchild;
};
int count1=0,count2=0,count3=0;
struct node*stack[20];
int top=-1;
int isempty(){
    if(top==-1) return 1;
    else return 0;
}
void push(struct node*n){
	stack[++top]=n;
}

struct node* pop(){
	return stack[top--];
}

void inorder(struct node*root){
    struct node*current=root;
    if(root){
        while(current!=NULL || isempty()==0){
          while(current!=NULL){
            push(current);
            current=current->lchild;
          }
          current=pop();
          count1++;
          printf("%c\t",current->data);
          current=current->rchild;
        }
    }
}
void preorder(struct node*root){
    struct node*current=root;
    if(root){
        while(current!=NULL || isempty()==0){
          while(current!=NULL){
            push(current);
            printf("%c\t",current->data);
            current=current->lchild;
          }
          current=pop();
          count2++;
          
          current=current->rchild;
        }
    }
}

void postorder(struct node*root){
     struct node*current=root;
    struct node* lastVisited = NULL;
    if(root){
    while (current != NULL || top != -1) {
        // Go as far left as possible, pushing nodes onto the stack
        while (current != NULL) {
            push(current);    // Push current node to stack
            current = current->lchild;
        }

        // Peek at the node on top of the stack without popping it
        struct node* peekNode = stack[top];

        // If the right child exists and is not yet processed, visit it
        if (peekNode->rchild != NULL && lastVisited != peekNode->rchild) {
            current = peekNode->rchild;
        } else {
            // If right subtree is either non-existent or already processed, process the node
            count3++;
            printf("%c\t", peekNode->data); // Process the node
            lastVisited = pop();            // Pop the stack and mark the node as visited
        }
    }
}
}



void createI(struct node**root){
    char d;
    int ch;
    char dir[100];
    struct node* newnode=(struct node*)calloc(1,sizeof(struct node));
    newnode->data='A';
    newnode->rchild=newnode->lchild=NULL;
    *root=newnode;
    struct node*temp;
    do{
        int i=0;
        temp=*root;
    printf("enter direction right(r) or left(l)\n ");
    gets(dir);
   // getchar();
     printf("enter data fr a node\n");
    scanf("%c",&d);
    getchar();
    while(dir[i]!='\0'){
        if(dir[i]=='r'){
            if(temp->rchild!=NULL)
            temp=temp->rchild;
            else break;
        }
        if(dir[i]=='l'){
            if(temp->lchild!=NULL)
            temp=temp->lchild;
            else break;
        }
        i++;
    }
    struct node* newnode2=(struct node*)calloc(1,sizeof(struct node));
    newnode2->data=d;
    newnode2->rchild=newnode2->lchild=NULL;
    
    if(dir[i]=='r'){
        temp->rchild=newnode2;
    }
    else temp->lchild=newnode2;
    printf("enter -1 to stop\n");
    scanf("%d",&ch);
    getchar();

    }while(ch!=-1);
}

int main(){
struct node* root=NULL;

createI(&root);

printf("inorder traversal:\n");
inorder(root);
printf("\n");
printf("no of nodes: %d\n",count1);
printf("preorder traversal:\n");
preorder(root);
printf("\n");
printf("no of nodes: %d\n",count2);
printf("postorder traversal:\n");
postorder(root);
printf("\n");
printf("no of nodes: %d\n",count3);
free(root);

return 0;
}