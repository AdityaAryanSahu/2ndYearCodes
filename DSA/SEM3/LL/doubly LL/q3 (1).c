#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char data[10];
    struct node*llink;
     struct node*rlink;
};

int count=0;
void insert_bk(struct node**start,char e[]){
    struct node *newnode=(struct node*)calloc(1,sizeof(struct node));
    struct node *temp,*prev=NULL;
    strcpy(newnode->data,e);
    if((*start)==NULL){
        newnode->rlink=NULL;
        newnode->llink=NULL;
        (*start)=newnode;
        count++;
        
    }
    else{
        for(temp=(*start);temp!=NULL;temp=temp->rlink){
            prev=temp;
        }
             prev->rlink=newnode;
             newnode->llink=prev;
             newnode->rlink=NULL;
             count++;
       
        }
    }
    
    void reverse(struct node**start){
    struct node*current=*start;
    struct node*temp;
    int n=count;
    int i;
    while (current != NULL) {
        temp = current->llink;
        current->llink = current->rlink;
        current->rlink = temp;
        current = current->llink; 
    }
    if (temp != NULL) {
        *start = temp->llink; 
    }
     }
     
     void display(struct node*head){
    struct node*temp; 
    for(temp=head;temp!=NULL;temp=temp->rlink){
        printf("%s\t",temp->data);
    }
}
     
     int main(){
    struct node*header=NULL;
     int ch;
     char e[10];
    do{
        printf("1.add_fr 2.reverse 3.dispay 4.exit\n");
        scanf("%d",&ch);
         getchar();
        switch(ch){
            case 1:gets(e);
                   insert_bk(&header,e);
                   break;
             case 2:if(header==NULL)
             printf("empty\n");
             else
             reverse(&header);
             break;
          
            case 3:if(header==NULL)
            printf("empty\n");
            else display(header);
        }
    }while(ch!=4);
 free(header);
}
    
   
    
    

