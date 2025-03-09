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

struct node* createR(struct node*root,int e){
    struct node*newnode=(struct node*)calloc(1,sizeof(struct node));
    newnode->data=e;
    if(root==NULL) return newnode;

    else if(e<root->data)
    root->lchild=createR(root->lchild,e);

  else if(e>root->data)
    root->rchild=createR(root->rchild,e);

  else{
    printf("duplictaed not allowd\n");
    return NULL;
  }
    return root;
}

int main(){
struct node* root=NULL;
int c,d;
printf("enter number of nodes\n");
scanf("%d",&d);
for(int i=0;i<d;i++){ 
    printf("enter data for new node\n");
    scanf("%d",&c);
root=createR(root,c);
}

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