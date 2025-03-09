#include<stdio.h>
#include<stdlib.h>
struct node{
    char data;
    struct node* lchild;
        struct node* rchild;
};

void inorder(struct node*root){
    if(root){
       inorder(root->lchild);
       printf("%c\t",root->data);
       inorder(root->rchild);
    }
}
void preorder(struct node*root){
    if(root){
        printf("%c\t",root->data);
       preorder(root->lchild);
       preorder(root->rchild);
    }
}

void postorder(struct node*root){
    if(root){
       postorder(root->lchild);
       postorder(root->rchild);
        printf("%c\t",root->data);
    }
}

struct node* createR(char e){
    char ch,d;
    if(e!='#'){
    struct node*newnode=(struct node*)calloc(1,sizeof(struct node));
    newnode->data=e;
    printf("press # to stop\n");
    printf("enter data for lchild\n");
    scanf("%c",&d);
    getchar();
    newnode->lchild=createR(d);
    printf("enter data for rchild\n");
    scanf("%c",&d);
    getchar();
    newnode->rchild=createR(d);
    return newnode;
    }
    return 0;
}

int main(){
struct node* root=NULL;
char c;
printf("enter data fir first node (press # to not create a tree)\n");
c=getchar();
getchar();
root=createR(c);

printf("inorder traversal:\n");
inorder(root);
printf("\n");

printf("preorder traversal:\n");
preorder(root);
printf("\n");

printf("postorder traversal:\n");
postorder(root);

free(root);

return 0;
}