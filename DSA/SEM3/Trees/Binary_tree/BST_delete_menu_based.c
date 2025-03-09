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

void del(struct node*root,int k){
struct node*temp,*max,*min,*del,*prev;
int ch;
temp=root;
while(temp!=NULL&&temp->data!=k){
    prev=temp;
    if(k<temp->data) temp=temp->lchild;
    else temp=temp->rchild;
}
del=temp;
if(del!=NULL){
    if(del->lchild==NULL &&del->lchild==NULL){
        if(k<prev->data) prev->lchild=NULL;
        else prev->rchild=NULL;
        free(del);
    }
    else if(del->rchild==NULL || del->lchild==NULL){
        if(del->lchild==NULL){
          if(k<prev->data) prev->lchild=del->rchild;
          else prev->rchild=del->rchild;
        }
        else{
            if(k<prev->data) prev->lchild=del->lchild;
          else prev->rchild=del->lchild;
          free(del);
        }
    }
    else{ printf("1.replace with min in right subtree\n 2.replce max in left subtree\n");
    scanf("%d",&ch);
    switch(ch){
     case 1:min=del->rchild;
            prev=min;
            while(min->lchild!=NULL){
                prev=min;
                min=min->lchild;
            }
            prev->lchild=min->rchild;
            del->data=min->data;
            free(min);
            break;
    case 2:max=del->lchild;
            prev=max;
            while(max->rchild!=NULL){
                prev=max;
                max=max->rchild;
            }
            prev->rchild=max->lchild;
            del->data=max->data;
            free(max);
            break;
      }
    }
  }
}

int main(){
struct node* root=NULL;
int c,d;
int ch;
do{
printf("1.insert 2.delte 3.display 4.exit\n");
scanf("%d",&ch);
switch(ch){
case 1: printf("enter data fro node\n");
        scanf("%d",&d);
        root=createR(root,d);
        break;
case 2:printf("enter number to be deleetd\n");
       scanf("%d",&d);
       del(root,d);
       break;
case 3:printf("inorder traversal:\n");
      inorder(root);
      printf("\n");
      printf("preorder traversal:\n");
       preorder(root);
       printf("\n");
       printf("postorder traversal:\n");
        postorder(root);
      printf("\n");
      break;
}
}while(ch!=4);

return 0;
}