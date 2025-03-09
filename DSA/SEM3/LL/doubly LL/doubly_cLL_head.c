#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*llink;
     struct node*rlink;
};

void insert(struct node**head,int e){
    struct node*newnode=(struct node*)calloc(1,sizeof(struct node));
    struct node*temp,*prev=NULL;
    newnode->data=e;
    if((*head)->rlink==*head){ //checks for 1st node
        (*head)->rlink=newnode;
        newnode->rlink=*head;
        newnode->llink=*head;
        (*head)->llink=newnode;
        
    }
    else{
        for(temp=(*head)->rlink;temp!=*head && temp->data<e;temp=temp->rlink){
            prev=temp;
        }
        if(prev==NULL){
            (*head)->rlink=newnode;
              newnode->rlink=temp;
              temp->llink=newnode;
              newnode->llink=*head;
        }
        else if(temp==*head){
             prev->rlink=newnode;
             newnode->llink=prev;
             newnode->rlink=*head;
             (*head)->llink=newnode;
           
        }
        else{
             temp->llink=newnode;
            prev->rlink=newnode;
            newnode->llink=prev;
            newnode->rlink=temp;
        }
    }
}
void del(struct node**head,int e){
   
    struct node*temp,*prev=NULL;
    for(temp=(*head)->rlink;temp!=*head&&temp->data!=e;temp=temp->rlink){
       prev=temp;
    }
    
    if(prev==NULL){
        (*head)->rlink=temp->rlink;
        if (temp->rlink != *head)   
            temp->rlink->llink = *head;
        free(temp);
    }
    else if(temp->rlink==*head){
        temp->llink->rlink=*head;
        (*head)->llink=temp->llink;
        free(temp);
    }
    else{
        prev->rlink=temp->rlink;
        temp->rlink->llink=prev;
        free(temp);
    }
}

void display(struct node*head){
    struct node*temp;
    for(temp=head->rlink;temp!=head;temp=temp->rlink){
        printf("%d\t",temp->data);
    }
   
}

int main(){
    struct node*header=(struct node*)calloc(1,sizeof(struct node));
    header->data=-1;
    header->llink=header->rlink=header;
     int ch,e;
    do{
        printf("1.add 2.del 3.dispay 4.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:scanf("%d",&e);
                   insert(&header,e);
                   break;
          case 2:  if(header->rlink==header)
                      printf("empty\n");
                     else{printf("enetr elemnr to be deleeyd\n");
                    scanf("%d",&e);
                   del(&header,e);}
                    break;
            case 3:if(header->rlink==header)
            printf("empty\n");
            else display(header);
        }
    }while(ch!=4);
   free(header);
}