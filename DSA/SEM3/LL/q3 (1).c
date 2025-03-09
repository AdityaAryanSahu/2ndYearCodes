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
(*head)->data++;
     }
  }
}

  void union1(struct node**e1,struct node**e2,struct node**e3){
    struct node*temp;
    for(temp=(*e1)->next;temp!=NULL;temp=temp->next){
      insert(e3,temp->data);
    }
    for(temp=(*e2)->next;temp!=NULL;temp=temp->next){
      insert(e3,temp->data);
    }
    for(temp=(*e3)->next;temp!=NULL;temp=temp->next)
    printf("%d\t",temp->data);
    }

    
  int main(){
  struct node *head1=(struct node *)calloc(1,sizeof(struct node));
  head1->next=NULL;

  struct node *head2=(struct node *)calloc(1,sizeof(struct node));
  head2->next=NULL;
 struct node *head3=(struct node *)calloc(1,sizeof(struct node));
  head3->next=NULL;

   int ch,item;
   struct node*temp;
  do{
  printf("1.add1 2.add2 3.union 4.display1 5.display2 6.exit\n");
  scanf("%d",&ch);
  switch(ch){
    case 1:scanf("%d",&item);
            insert(&head1,item);
            break;
    case 2:scanf("%d",&item);
            insert(&head2,item);
            break;
    case 3:union1(&head1,&head2,&head3);
            break;
    case 4:for(temp=(head1)->next;temp!=NULL;temp=temp->next)
           printf("%d\t",temp->data);
            break;
  case 5:for(temp=(head2)->next;temp!=NULL;temp=temp->next)
            printf("%d\t",temp->data);
            break;
    }
  }while(ch!=6);
  }
 