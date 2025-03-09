#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*llink,*rlink;
};

void insert(struct node**head,int data){
  struct node*newnode=(struct node*)calloc(1,sizeof(struct node));
  newnode->data=data;
  newnode->llink=newnode->rlink=NULL;
  if((*head)->rlink==NULL){
    (*head)->rlink=newnode;
    newnode->llink=*head;
  }
  else{
    struct node*temp,*prev=NULL;
    for(temp=(*head)->rlink;temp!=NULL&&temp->data<data;temp=temp->rlink){
        prev=temp;
    }
    if(prev==NULL){
        (*head)->rlink=newnode;
        newnode->rlink=temp;
        newnode->llink=*head;
        temp->llink=newnode;
    }
    else if(temp==NULL){
        prev->rlink=newnode;
        newnode->rlink=NULL;
        newnode->llink=prev;
    }
    else{
        prev->rlink=newnode;
        newnode->rlink=temp;
        newnode->llink=prev;
        temp->llink=newnode;
    }
  }
}
 int count=1;
  void del(struct node**head,int n){
       struct node*temp,*prev=NULL;
       for(temp=(*head)->rlink;temp->rlink!=NULL;temp=temp->rlink){count++;}
       int i=1;
       prev=temp;
       while(i<n&&temp!=NULL){
        i++;
           temp=temp->llink;
            prev=temp;
       }
       if(n!=1){
       prev->llink->rlink=prev->rlink;
       prev->rlink->llink=prev->llink;
       free(temp);
       }
       else if(n==1){
        prev->llink->rlink=NULL;
        free(temp);
       }
       
  }
  void display(struct node*head){
    struct node*temp;
    for(temp=head->rlink;temp!=NULL;temp=temp->rlink){
        printf("%d\t",temp->data);
    }
}
// void removeDup(struct node**head){
//   struct node*temp=(*head)->rlink;
//   struct node*prev;
//   while(temp!=NULL&&temp->rlink!=NULL&&temp->llink->rlink!=NULL){
//     if(temp->data==temp->rlink->data){
//         prev=temp;
//         temp->llink->rlink=temp->rlink->rlink;
//         temp->rlink->rlink->llink=temp->llink;
          
//         free(temp->rlink);
       
//         free(prev);
//     }
//      temp=temp->llink->rlink;
//   }
// }
int main(){
    struct node*head=(struct node*)calloc(1,sizeof(struct node));
    head->rlink=head->llink=NULL;
    int n,pos,x;
   printf("enter number of nodes\n");
   scanf("%d",&n);
   while(n>0){
    printf("Enter enter data for node\n");
    scanf("%d",&x);
    insert(&head,x);
    n--;
   }
   display(head);
  
   printf("enter pos to be deleted\n");
   scanf("%d",&pos);
   del(&head,pos);
    printf("count: %d\n",count);
    display(head);

    struct node*head2=(struct node*)calloc(1,sizeof(struct node));
     head2->rlink=head2->llink=NULL;
     printf("enter pos to be copied\n");
   scanf("%d",&pos);
   struct node*temp=head->rlink;
   while(pos>1){
    temp=temp->rlink;pos--;
   }
   while(temp!=NULL){
  insert(&head2,temp->data);
 temp=temp->rlink;
   }
   display(head2);

  // removeDup(&head);
   display(head);


   temp=head->rlink;
   struct bst*root=NULL;
   while(temp!=NULL){
    root=createR(root,temp->data);
    temp=temp->rlink;
   }
   inorder(root);
}