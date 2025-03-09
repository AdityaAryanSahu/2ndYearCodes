#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*llink;
     struct node*rlink;
};

void insert_fr(struct node**start,int e){
    struct node*newnode=(struct node*)calloc(1,sizeof(struct node));
    struct node*temp,*prev=NULL;
    newnode->data=e;
    if((*start)==NULL){
        newnode->rlink=NULL;
        newnode->llink=NULL;
        (*start)=newnode;
        
    }
    else{     temp=(*start);
              newnode->rlink=temp;
              temp->llink=newnode;
              newnode->llink=NULL;
              (*start)=newnode;
        
        }
    }


void insert_bk(struct node**start,int e){
    struct node*newnode=(struct node*)calloc(1,sizeof(struct node));
    struct node*temp,*prev=NULL;
    newnode->data=e;
    if((*start)==NULL){
        newnode->rlink=NULL;
        newnode->llink=NULL;
        (*start)=newnode;
        
    }
    else{
        for(temp=(*start);temp!=NULL;temp=temp->rlink){
            prev=temp;
        }
             prev->rlink=newnode;
             newnode->llink=prev;
             newnode->rlink=NULL;
       
        }
    }

void del_fr(struct node**head){
   
    struct node*temp,*prev=NULL;
    temp=(*head);
        (*head)=(*head)->rlink;
        if (temp->rlink != NULL){ 
        printf("the deleted ele is: %d\n",temp->data);
            temp->rlink->llink = NULL;
        free(temp);
        }
        else{
         printf("the deleted ele is: %d\n",temp->data);
        (*head)=NULL;
        free(temp);
        }
    
    }


void del_bk(struct node**head){
   
    struct node*temp,*prev=NULL;
    for(temp=(*head);temp->rlink!=NULL;temp=temp->rlink){}
    
    
     if (temp->rlink == NULL){ 
        printf("the deleted ele is: %d\n",temp->data);
            temp->llink->rlink = NULL;
        free(temp);
        }
         else if(temp->llink==NULL){
         printf("the deleted ele is: %d\n",temp->data);
        (*head)=NULL;
        free(temp);
        }
}

void display(struct node*head){
    struct node*temp;
    for(temp=head;temp!=NULL;temp=temp->rlink){
        printf("%d\t",temp->data);
    }
}

int main(){
    struct node*header=NULL;
     int ch,e;
    do{
        printf("1.add_fr 2.add_bk 3.del_fr 4.del_bk 5.dispay 6.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:scanf("%d",&e);
                   insert_fr(&header,e);
                   break;
             case 2:scanf("%d",&e);
                   insert_bk(&header,e);
                   break;
          case 3:  if(header==NULL)
                      printf("empty\n");
                     else{
                   del_fr(&header);}
                    break;
           case 4:  if(header==NULL)
                      printf("empty\n");
                     else{
                   del_bk(&header);}
                    break;
            case 5:if(header==NULL)
            printf("empty\n");
            else display(header);
        }
    }while(ch!=6);
 free(header);
}
