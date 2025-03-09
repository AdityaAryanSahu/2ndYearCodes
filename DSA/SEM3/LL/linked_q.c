#include<stdio.h>
#include<stdlib.h>

 struct Q {
    int item;
    struct Q* link;
};
void add(struct Q**front,struct Q**rear,int e){
    struct Q*newnode=(struct Q*)calloc(1,sizeof(struct Q));
    newnode->item=e;
      newnode->link=NULL;
    if(*rear==NULL)
      *front=*rear=newnode;
    else{
      (*rear)->link=newnode;
      *rear=newnode;
    }
}
void del(struct Q**front,struct Q**rear){
    struct Q*temp;
    struct Q*prev=NULL;
    if(*front==NULL)
    {
      printf("empty\n");
    }
    else{
    temp=*front;
    printf("dele ele is %d\n",temp->item);
    *front=temp->link;
    free(temp);
    if(*front==NULL)
    *rear=NULL;
      
    }
}
int main(){
    struct Q*front[3],*rear[3];
    int i,ch,n,item;
    for(i=0;i<3;i++)
        front[i]=rear[i]=NULL;

    do{
        printf("1.push 2.pop 3.display 4.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("enter which q to push:");
                   scanf("%d",&n);
                   if(n<=2&&n>=0){
                    printf("enter ele to be added\n");
                    scanf("%d",&item);
                    add(&front[n],&rear[n],item);
                   }
                   else
                   printf("wrong q\n");
                   break;
            case 2:printf("enter which q to push:");
                   scanf("%d",&n);
                   if(n<=2&&n>=0){
                    del(&front[n],&rear[n]);
                   }
                   else
                   printf("wrong q\n");
                   break;
            case 3:for(i=0;i<3;i++){
                printf("ele of q%d:\n",(i+1));
                 if(rear[i]==NULL)
                   printf("empty\n");
                   else{
                struct Q*temp,*prev=rear[i];
                for(temp=front[i];temp!=prev->link;temp=temp->link)
                printf("%d\t",temp->item);
            
            printf("\n");}
           
         } break;
        }
    }while(ch!=4);
}
           
    
