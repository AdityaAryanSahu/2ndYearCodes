#include<stdio.h>
#include<stdlib.h>

struct bst{
    int data;
    struct bst*rchild,*lchild;
};

void inorder(struct bst*root){
 if(root){
    inorder(root->lchild);
    printf("%d\t",root->data);
    inorder(root->rchild);
 }
}
int search(struct bst*root,int d){
    struct bst*temp,*prev=NULL;
    temp=root;
     while(temp!=NULL){
        if(d<temp->data) temp=temp->lchild;
        else if(d>temp->data)temp=temp->rchild;
        else if(d==temp->data) 
                   return 1;
     }
     return 0;
}

void max_min(struct bst*root){
    struct bst*temp=root;
    while(temp->rchild!=NULL) temp=temp->rchild;
    printf("max element is %d\n",temp->data);
    temp=root;
    while(temp->lchild!=NULL) temp=temp->lchild;
    printf("min element is %d\n",temp->data);
}

struct bst* insertR(struct bst* root,int d){
   struct bst* newnode=(struct bst*)calloc(1,sizeof(struct bst));
   newnode->data=d;
   if(root==NULL) return newnode;
    else  if(d>root->data){
    root->rchild=insertR(root->rchild,d);
   }
   else if(d<root->data){
    root->lchild=insertR(root->lchild,d);
   }
   else {printf("duplicate\n");}
  return root;
 
}

void insertI(struct bst**root){
 struct bst* newnode=(struct bst*)calloc(1,sizeof(struct bst));
 newnode->data=20;
 *root=newnode;
 int x,ch;
 struct bst*temp,*prev=NULL;
 do{
   temp=*root;
   printf("enter data for node\n");
   scanf("%d",&x);
   while(temp!=NULL){
    if(x<temp->data){
        prev=temp;
        temp=temp->lchild;
    }
    else if(x>temp->data){
         prev=temp;
        temp=temp->rchild;
    }
    else {printf("duplicate not allowed\n");}
   }
  struct bst* newnode2=(struct bst*)calloc(1,sizeof(struct bst));
  newnode2->data=x;
  if(x>prev->data) prev->rchild=newnode2;
  else prev->lchild=newnode2;

  printf("enter 0 to continue insertion\n");
  scanf("%d",&ch);

 }while(ch==0);
}

void del(struct bst*root,int d){
    struct bst*temp=root,*del,*prev;
    int ch;
    while(temp!=NULL && temp->data!=d){
        prev=temp;
        if(d<temp->data) temp=temp->lchild;
        if(d>temp->data) temp=temp->rchild;
    }
    del=temp;
    if(del){
        if(del->rchild==NULL && del->lchild==NULL){
            if(del->data>prev->data) prev->rchild=NULL;
            else prev->lchild=NULL;
            free(del);
        }
        else if(del->rchild==NULL || del->lchild==NULL){
            if(del->rchild!=NULL){
                if(del->data>prev->data) prev->rchild=del->rchild;
                else prev->lchild=del->rchild;
            }
            else if(del->lchild!=NULL){
                 if(del->data>prev->data) prev->rchild=del->lchild;
                else prev->lchild=del->lchild;
            }
            free(del);
        }
        else {
            printf("1.replace min of right subtree of deleted node\n 2.replace max of left subtree of deleted node\n");
                    scanf("%d",&ch);
                    switch(ch){
                       case 1:{
                               struct bst* min=del->rchild;
                               prev=del;
                               while(min->lchild!=NULL){
                                prev=del;
                                min=min->lchild;
                               }
                               if (prev->lchild == min)
                                  prev->lchild = min->rchild;
                             else prev->rchild =min->rchild;
                               del->data=min->data;
                               free(min);
                               break;
                              }
                        case 2:{
                               struct bst* max=del->lchild;
                               prev=del;
                               while(max->rchild!=NULL){
                                prev=max;
                                max=max->rchild;
                               }
                               if (prev->rchild == max)
                             prev->rchild = max->lchild;
                               else prev->lchild = max->lchild;
                               del->data=max->data;
                               free(max);
                               break;
                              }
                    }
            }
    }

    
}
int main(){
    struct bst* root1=NULL,*root2=NULL;
    int n,d;

    int ch;
    do{
        printf("1.createR 2.createI 3.delete 4.displayR 5.displayI 6.search 7.max&min 8.exit\n");
        scanf("%d",&ch);
        switch (ch){
           case 1:{printf("enter no of nodes\n");
                    scanf("%d",&n);
                    for(int i=0;i<n;i++){
                      printf("enter data for node\n");
                      scanf("%d",&d);
                         root1=insertR(root1,d);} break;
                  }
           case 2:insertI(&root2);break;
           case 3:printf("enter data to be deleted\n");
                    scanf("%d",&d);
                    del(root1,d);
                    break;
           case 4: printf("inorder\n");
                     inorder(root1);
                     printf("\n");
                     break;
            case 5: printf("inorder\n");
                     inorder(root2);
                     printf("\n");
                     break;
            case 6: printf("enter number to be searched\n");
                   scanf("%d",&d);
                   if(search(root1,d)) printf("number found\n");
                   else printf("number not found\n");
                   break;
            case 7:max_min(root1);break;
        }
    }while(ch!=8);

    
}