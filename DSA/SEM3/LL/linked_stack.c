#include<stdio.h>
#include<stdlib.h>

 struct stack {
    int item;
    struct stack* link;
};
void push(int ele,struct stack** top){
    struct stack* newnode=(struct stack*)calloc(1,sizeof(struct stack));
    if(*top==NULL){
        newnode->item=ele;
        newnode->link=NULL;
        *top=newnode;
    }
    else{
        newnode->link=*top;
        newnode->item=ele;
        *top=newnode;
    }
}
void pop(struct stack** top){
    struct stack* temp;
    if(*top==NULL){
        printf("empty\n");
    }
    else{
        temp=*top;
        printf("popped ele is: %d\n",temp->item);
       *top=temp->link;
       free(temp);
    }
}
int main(){
    struct stack *top[3];
    top[0]=top[1]=top[2]=NULL;
    int ch,n,item,i;
    do{
        printf("1.push 2.pop 3.display 4.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("enter which stack to push:");
                 scanf("%d",&n);
                if(n<=2&&n>=0){
                printf("enter element\n");
                scanf("%d",&item);        
                push(item,&top[(n)]);
                }
                else
                printf("wrong stack nigga\n");
                 break;

            case 2:printf("enter which stack to pop:");
                    scanf("%d",&n);
                  if(n<=2&&n>=0)
                 pop(&top[n]);
                else
                printf("wrong stack nigga\n");
                 break;
                 
            case 3:for(i=0;i<3;i++){
                printf("\nelements of stack %d:",(i+1));
                struct stack *temp;
                 if(top[i]==NULL)
                   printf("empty\n");
                   else{
                for(temp=top[i];temp!=NULL;temp=temp->link)
                    printf("%d\t",temp->item);
                   
                   }
                    printf("\n");
                }
                break;
        }
    }while(ch!=4);
}