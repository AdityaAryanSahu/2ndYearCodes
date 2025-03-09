#include<stdio.h>
#include<stdlib.h>
#define max 20
struct bst{
    char data;
    struct bst*lchild,*rchild;
};

struct bst*stack[max];
int top=-1;

void push(struct bst*node){
    if(top==max-1) printf("cant push\n");
    else stack[++top]=node;
}

struct bst*pop(){
    if(top==-1) {printf("empty\n");return NULL;}
    else return stack[top--];
}
void display(){
    printf("data: %c pushed to stack at address: %p\n",stack[top]->data,stack[top]);
}

struct bst*post_build(char postfix[]){
     int i=0;
     while(postfix[i]!='\0'){
        struct bst*temp=(struct bst*)calloc(1,sizeof(struct bst));
        if((postfix[i]>='A'&&postfix[i]<='Z'||postfix[i]>='a'&&postfix[i]<='z'||
        postfix[i]>='0'&&postfix[i]<='9')){
            temp->data=postfix[i];
            push(temp);
           printf("data: %c pushed to stack at address: %p\n",temp->data,stack[top]);
        }
        else{
            temp->data=postfix[i];
            temp->rchild=pop();
            temp->lchild=pop();
            push(temp);
            printf("data: %c pushed to stack at address: %p\n",temp->data,stack[top]);
        }
        i++;
     }
     return (pop());
}
void inorder(struct bst*root){
    if(root){
        inorder(root->lchild);
        printf("%c\t",root->data);
        inorder(root->rchild);
    }
}
void preorder(struct bst*root){
    if(root){
        printf("%c\t",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

int main(){
    struct bst*root=NULL;
    char postfix[max];
    int ch;
    char data;
    do{
printf("1.build tree 2.display inorder 3.display prefix 4.exit\n");
scanf("%d",&ch);
getchar();
switch(ch){
    case 1:printf("enter postfix exp\n");
          fgets(postfix,max,stdin);
         root=post_build(postfix);
          printf("tree created\n");
          break;
    case 2:inorder(root);break;
    case 3:preorder(root);break;
       }
    }while(ch!=4);
}