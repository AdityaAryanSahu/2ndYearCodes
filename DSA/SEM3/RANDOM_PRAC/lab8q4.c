#include<stdio.h>
#define max 15
typedef struct{
    int element[max];
    int front,rear;
}Q;
int isfull(Q *q){
if(q->rear==max-1)
return 1;
else return 0;
}

int isempty(Q *q){
return q->rear==q->front;
}

void add(Q *s,int e ){
s->rear=s->rear+1;
s->element[s->rear]=e;
}

int del(Q *s){
s->front=s->front+1;
int p=s->element[s->front];
return p;
}
int main(){
   
    Q q;
    int arr[max];
     q.front=-1;
     q.rear=-1;
    int flag,flag2,flag3;
    int ch,item,i,j=0;
    int count=0;
    do{
        printf("1.add 2.reverse 3.display 4.exit\n");
scanf("%d",&ch);
getchar();
    switch(ch){
        case 1: flag=isfull(&q);
               if(flag==1){
                printf("cant be added\n");
                }
               else 
                { scanf("%d",&item);
                add(&q,item);
                count++;
                }
                 break;

        case 2: flag2=isempty(&q);
               
               if(flag2==1){
               printf("cant del,empty q\n");
               }
                else {
                    while(q.rear>=q.front){
                        arr[j++]=del(&q);
                    }
                    q.rear=-1;
                    int i=0;
                    int n=count;
                    while(count>0){
                        add(&q,arr[n-i-1]);
                        i++;
                        count--;
                    }
                    
                }
               break;
        case 3: 
                 {
               for(i=0;i<=q.rear;i++)
               printf("%d\t",q.element[i]);}
               break;
               
           }
    }while(ch!=4);
return 0;

}
