#include<stdio.h>
#include<stdlib.h>
 struct node{
 int data;
 struct node*next;
 };
 
 void insert(struct node** head,int e){
  struct node*newnode=(struct node *)calloc(1,sizeof(struct node));
  struct node*temp;
  struct node*prev=NULL;
  newnode->data=e;
  if((*head)->next==NULL)
  {
  newnode->next=NULL;
  (*head)->next=newnode;
  }
  else{
  for(temp=(*head)->next;temp!=NULL&&temp->data<e;temp=temp->next){prev=temp;}
    if(prev==NULL){
      (*head)->next=newnode;
      newnode->next=temp;
    }
    else{
  prev->next=newnode;
  newnode->next=temp;;
     }
  }
}

void removeDup(struct node** head) {
    struct node* current = *head;
    struct node* temp;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            temp = current->next;  
            current->next = current->next->next;  
            free(temp);  
        } else {
            current = current->next;  
        }
    }
}
 int main(){
  struct node *head1=(struct node *)calloc(1,sizeof(struct node));
  head1->next=NULL;

  
   int ch,item;
   struct node*temp;
  do{
  printf("1.add1 2.delDup 3.display 4.exit\n");
  scanf("%d",&ch);
  switch(ch){
    case 1:scanf("%d",&item);
            insert(&head1,item);
            break;
    case 2:removeDup(&head1);
            break;
    case 3:for(temp=(head1)->next;temp!=NULL;temp=temp->next)
           printf("%d\t",temp->data);
            break;

    }
  }while(ch!=4);
  }