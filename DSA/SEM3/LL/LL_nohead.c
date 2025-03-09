#include<stdio.h>
#include<stdlib.h>

 
 struct node{
    int ele;
    struct node*next;
 };
void insert(struct node **start,int e ){
    struct node *newnode=(struct node*)calloc(1,sizeof(struct node));
    struct node*temp,*prev=NULL;
    newnode->ele=e;
    if(*start==NULL){
        *start=newnode;
       // *start->ele=e;
        newnode->next=NULL;
    }
    else{
        for(temp=*start;temp!=NULL && temp->ele<e;temp=temp->next){
            prev=temp;
        }
        if(prev==NULL){
             newnode->next=*start;
           *start=newnode;
           
        }
        else{
            prev->next=newnode;
            newnode->next=temp;
        }
    }
}
void del(struct node **start,int e){
    struct node *temp,*prev=NULL;
    
        for(temp=*start;temp!=NULL&&temp->ele!=e ;temp=temp->next){
           prev=temp;

            }
            if(prev==NULL){
                *start=temp->next;
                free(temp);
            }
            else{
                prev->next=temp->next;
                free(temp);
            }

        }
void display(struct node*start){
    struct node*temp;
    if(start==NULL)
    printf("empty\n");
    else{
    for(temp=start;temp!=NULL;temp=temp->next)
    printf("%d\t",temp->ele);
    }
}
 int main(){
    struct node *start=NULL;
    int ch,e;
    do{
        printf("1.add 2.del 3.dispay 4.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:scanf("%d",&e);
                   insert(&start,e);
                   break;
            case 2:  if(start==NULL)
                      printf("empty\n");
                     else{printf("enetr elemnr to be deleeyd");
                    scanf("%d",&e);
                   del(&start,e);}
                    break;
            case 3:display(start);
        }
    }while(ch!=4);
    free(start);
    return 0;
 }