#include<stdio.h>
#include<stdlib.h>

struct bst{
    int data;
    struct bst*lchild,*rchild;
};

struct bst* insert(struct bst*root,int data){
  struct bst*newnode=(struct bst*)calloc(1,sizeof(struct bst));
  newnode->data=data;
  newnode->rchild=newnode->lchild=NULL;
  if(root==NULL) return newnode;
  else{
    if(data<root->data) root->lchild=insert(root->lchild,data);
    else if(data>root->data) root->rchild=insert(root->rchild,data);
    else {printf("duplicate\n");}

    return root;
  }
}
int search_depth(struct bst*root,int data){
  struct bst*temp=root;
  int depth=1;
  while(temp!=NULL){
  if(data<temp->data){ depth++;temp=temp->lchild;}
  else if(data>temp->data){depth++;temp=temp->rchild;}
  else if(data==temp->data){return depth;}
  }
  return -1;
  
}
void display(struct bst*root){
   if(root){
    display(root->lchild);
    printf("%d\t",root->data);
    display(root->rchild);
   }
}
 int max(int a,int b){
    if(a>b) return a;
    else return b;
 }

 int height(struct bst*root){
    if(root==NULL) return 0;
     return 1+max(height(root->lchild),height(root->rchild));
 }

 void deleteR(struct bst**root,int data){
    struct bst*temp=*root,*del,*prev=NULL;
    while(temp!=NULL&& temp->data!=data){
        prev=temp;
        if(data>temp->data) temp=temp->rchild;
        else if(data<temp->data) temp=temp->lchild;
    }
    del=temp;
    if(del){
        if(del->rchild!=NULL&& del->lchild!=NULL){
            printf("cant delete both children present\n");
        }
        else{
            if(del->rchild==NULL&&del->lchild==NULL){
                if(del->data>prev->data){
                    prev->rchild=NULL;
                }
                else prev->lchild=NULL;
                free(del);
            }
            else{
                if(del->rchild!=NULL){
                    if(del->data>prev->data)
                      prev->rchild=del->rchild;
                      else prev->lchild=del->rchild;
                }
                else{
                     if(del->data>prev->data)
                      prev->rchild=del->lchild;
                      else prev->lchild=del->lchild;
                }
                free(del);
            }
        }
    }
    else printf("movie not found\n");

 }

 int main(){
    struct bst*root=NULL;
    int ch;
    int data;
    int depth;
    do{
        printf("1.insert 2.search 3.display 4.delete 5.max_heigth 6.exit\n");
        scanf("%d",&ch);
        switch(ch){
              case 1:{printf("enter ID\n");scanf("%d",&data);
                root=insert(root,data);
                break;
              }
              case 2:printf("enter ID to be searched\n");scanf("%d",&data);
                    printf("depth: %d\n",search_depth(root,data));
                    break;
            case 3:printf("ascending orede is:\n");
                   display(root);printf("\n");break;
            case 4:printf("enter ID to be deleted\n");scanf("%d",&data);
                   deleteR(&root,data);break;
            case 5:printf("max height is %d\n",height(root));break;
        }
    }while(ch!=6);
 }