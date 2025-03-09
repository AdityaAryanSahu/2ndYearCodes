#include<stdio.h>
#include<stdlib.h>
#define max 5
typedef struct{
    int element[max];
    int rear;
    int front;
}Q;
void addrear(Q *s,int e ){
    if(s->rear==-1 && s->front==-1){
        s->rear=0;
        s->front=0;
        s->element[s->rear]=e;
    }
    else{
s->rear=(s->rear+1)% max;
 s->element[s->rear]=e;}

}
void addfront(Q *s,int e){
    if(s->rear==-1 && s->front==-1){
        s->rear=0;
        s->front=0;
        s->element[s->front]=e;
    }
    else{
s->front=(s->front-1+max)%max;
s->element[s->front]=e;}

}

int delrear(Q *s){
    int p;
    if(s->rear==s->front){
         p=s->element[s->rear];
         s->rear=-1;
         s->front=-1;
    }
    else{
 p=s->element[s->rear];
 s->rear=(s->rear-1+max)%max;}
return p;
}

int delfront(Q *s){
    int p;
    if(s->rear==s->front){
         p=s->element[s->front];
         s->rear=-1;
         s->front=-1;
    }
    else{
 p=s->element[s->front];
 s->front=(s->front+1)%max;}
return p;
}
int main(){
    Q *q;
    q=(Q *)calloc(1,sizeof(Q));
     q->front=-1,q->rear=-1;
    int flag,flag2,flag3;
    int ch,item,i,p;
    do{
        printf("1.addrear 2.adddfront 3.delrear 4.delfront 5.display 6.exit\n");
scanf("%d",&ch);
getchar();
    switch(ch){
        case 1: if((q->rear+1)%max==q->front){
                printf("cant be added\n");
                }
               else 
                { scanf("%d",&item);
                addrear(q,item);}
                 break;

        case 2: if((q->rear+1)%max==q->front){
               printf("cant insert\n");
               }
                else {scanf("%d",&item);
                addfront(q,item);}
               break;
        case 3: if(q->rear==-1 && q->front==-1){
               printf("cant del\n");
               }
                else {
              p=delrear(q);
              printf("%d\n",p);}
               break;
        case 4: if(q->rear==-1 && q->front==-1){
               printf("cant del\n");
               }
                else {
              p=delfront(q);
              printf("%d\n",p);}
               break;
        case 5: for(i=((q->front)%max);i!=((q->rear+1)%max);i=((i+1)%max))
                  printf("%d\t",q->element[i]);
               
           }
    }while(ch!=6);
return 0;

}
