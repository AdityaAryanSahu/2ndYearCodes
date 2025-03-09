#include<stdio.h>
#include<stdlib.h>
 struct node{
 int data;
 struct node*next;
 };

 void insert(struct node** head,int e){
  struct node*newnode=(struct node *)calloc(1,sizeof(struct node));
  struct node*temp;
  newnode->data=e;
  if((*head)->next==NULL)
  {
  newnode->next=NULL;
  (*head)->next=newnode;
  }
  else{
  for(temp=(*head)->next;temp->next!=NULL;temp=temp->next){}
      
  temp->next=newnode;
  newnode->next=NULL;

     }
  }

  void union1(struct node**e1,struct node**e2,struct node**e3){
    struct node*temp,*temp2;
    int flag;
    
    for(temp=(*e1)->next;temp!=NULL;temp=temp->next){
      insert(e3,temp->data);
    }
    for(temp=(*e2)->next;temp!=NULL;temp=temp->next){
      flag=1;
      for(temp2=(*e3)->next;temp2!=NULL;temp2=temp2->next){
      if(temp->data==temp2->data){
      flag=0;break;}
      }
      if(flag==1)
      insert(e3,temp->data);
    }

    for(temp=(*e3)->next;temp!=NULL;temp=temp->next)
    printf("%d\t",temp->data);
    
    
  }
  void interscetion1(struct node**e1,struct node**e2){
  	struct node*temp1;
  	struct node*temp2;
  	//struct node*prev;
    for(temp1=(*e1)->next;temp1!=NULL;temp1=temp1->next){
    	for(temp2=(*e2)->next;temp2!=NULL;temp2=temp2->next){
    	if(temp1->data==temp2->data)
    		printf("%d\t",temp1->data);
    }
  }
}
  int main(){
  struct node *head1=(struct node *)calloc(1,sizeof(struct node));
  head1->data=-1;
  head1->next=NULL;

  struct node *head2=(struct node *)calloc(1,sizeof(struct node));
  head2->data=-1;
  head2->next=NULL;

  struct node *head3=(struct node *)calloc(1,sizeof(struct node));
  head3->data=-1;
  head3->next=NULL;
   int ch,item;
  do{
  printf("1.add1 2.add2 3.union 4.intersection 5.exit\n");
  scanf("%d",&ch);
  switch(ch){
    case 1:scanf("%d",&item);
            insert(&head1,item);
            break;
    case 2:scanf("%d",&item);
            insert(&head2,item);
            break;
    case 3:union1(&head1,&head2,&head3);break;
    case 4:interscetion1(&head1,&head2);break;
  }
  }while(ch!=5);
  }
 