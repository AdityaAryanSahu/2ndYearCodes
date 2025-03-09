#include<stdio.h>
#include<stdlib.h>

struct node{
    int ele;
    struct node* next;
};
void insert(struct node** head,int e){
    struct node*newnode=(struct node*)calloc(1,sizeof(struct node));
    struct node*temp,*prev=NULL;
    newnode->ele=e;
    if((*head)->next==*head){
    newnode->next=*head;
    (*head)->next=newnode;
    }
    else
    {
        for(temp=(*head)->next;temp!=*head && temp->ele<e;temp=temp->next){
            prev=temp;
        }
         
        if(prev==NULL){
            (*head)->next=newnode;
            newnode->next=temp;
        }
        else{
            prev->next=newnode;
            newnode->next=temp;
        }
    }
}
void del(struct node** head,int e){
 struct node*temp,*prev=NULL;
 for(temp=(*head)->next;temp!=*head && temp->ele!=e;temp=temp->next)
 prev=temp;
 if(prev==NULL){
    (*head)->next=temp->next;
    free(temp);
 }
 else
 {
    prev->next=temp->next;
    free(temp);
 }
}
void display(struct node*head){
     struct node*temp;
    if(head->next==head)
    printf("empty\n");
    else{
        for(temp=head->next;temp!=head;temp=temp->next)
        printf("%d\t",temp->ele);
    }
}
int main(){
    struct node* header=( struct node*)calloc(1,sizeof(struct node));
    header->ele=-1;
    header->next=header;
    int ch,e;
    do{
        printf("1.add 2.del 3.dispay 4.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:scanf("%d",&e);
                   insert(&header,e);
                   break;
            case 2:  if(header->next==header)
                      printf("empty\n");
                     else{printf("enetr elemnr to be deleeyd\n");
                    scanf("%d",&e);
                   del(&header,e);}
                    break;
            case 3:display(header);
        }
    }while(ch!=4);
    free(header);
}