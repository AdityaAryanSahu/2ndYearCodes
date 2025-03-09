#include<stdio.h>
#define max 5
typedef struct{
    int element;
}Q;
int isfull(int max_size,int rear){
if(rear==max_size-1)
return 1;
else return 0;
}

int isempty(int rear,int front){
if(rear==front)
return 1;
else return 0;
}

void add(Q *s,int e,int *rear ){
*rear=*rear+1;
s[*rear].element=e;
}

int del(Q *s,int *front){
*front=*front+1;
int p=s[*front].element;
return p;
}
int main(){
    int front=-1,rear=-1;
    Q q[max];
    int flag,flag2,flag3;
    int ch,item,i,p;
    do{
        printf("1.add 2.del 3.display 4.exit\n");
scanf("%d",&ch);
getchar();
    switch(ch){
        case 1: flag=isfull(max,rear);
               if(flag==1){
                printf("cant be added\n");
                }
               else 
                { scanf("%d",&item);
                add(q,item,&rear);}
                 break;

        case 2: flag2=isempty(rear,front);
               
               if(flag2==1){
               printf("cant del,empty q\n");
               }
                else {p=del(q,&front);
               printf("deleted element is %d\n",p);}
               break;
        case 3: if(rear==front){
               printf("cant display,empty q\n");
               }
                else {
               for(i=front+1;i<=rear;i++)
               printf("%d\t",q[i].element);}
               break;
               
           }
    }while(ch!=4);
return 0;

}
