#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* lchild;
        struct node* rchild;
};

void inorder(struct node*root){
    if(root){
       inorder(root->lchild);
       printf("%d\t",root->data);
       inorder(root->rchild);
    }
}
void preorder(struct node*root){
    if(root){
        printf("%d\t",root->data);
       preorder(root->lchild);
       preorder(root->rchild);
    }
}

void postorder(struct node*root){
    if(root){
       postorder(root->lchild);
       postorder(root->rchild);
        printf("%d\t",root->data);
    }
}

void createI(struct node**root){
    int d;
    int ch;
    struct node* newnode=(struct node*)calloc(1,sizeof(struct node));
    newnode->data=40;
    newnode->rchild=newnode->lchild=NULL;
    *root=newnode;
    struct node*temp,*prev;
    do{
        temp=*root;
     printf("enter data fr a node\n");
    scanf("%d",&d);
    getchar();
    while(temp!=NULL){
        if(d>temp->data){
            prev=temp;
            temp=temp->rchild;
        }
        else if(d<temp->data){
            prev=temp;
            temp=temp->lchild;
        }
        else {
            printf("no duplicates allows\n");
        }
    }
    struct node* newnode2=(struct node*)calloc(1,sizeof(struct node));
    newnode2->data=d;
    newnode2->rchild=newnode2->lchild=NULL;
    
    if(d>prev->data){
        prev->rchild=newnode2;
    }
    else prev->lchild=newnode2;

      printf("do u wish to cintinue insertion; enter 0\n");
              scanf("%d",&ch);
              getchar();

    }while(ch==0);
}


int main(){
struct node* root=NULL;

createI(&root);
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