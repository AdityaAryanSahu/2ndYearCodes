#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 5
typedef struct{
    char element[max][2*max];
    int rear;
    int front;
}Q;
void addrear(Q *s,char e[] ){
    if(s->rear==-1 && s->front==-1){
        s->rear=s->rear+1;
        s->front=s->front+1;
        strcpy(s->element[s->rear],e);
    }
    else{
s->rear=s->rear+1;
 strcpy(s->element[s->rear],e);}

}
void addfront(Q *s,char e[]){
    if(s->rear==-1 && s->front==-1){
        s->rear=s->rear+1;
        s->front=s->front+1;
        strcpy(s->element[s->front],e);
    }
    else{
s->front=s->front-1;
strcpy(s->element[s->front],e);}

}

void delfront(Q *s){
    char p[max];
    if(s->rear==s->front){
         strcpy(p,s->element[s->front]);
         s->rear=-1;
         s->front=-1;
    }
    else{
  strcpy(p,s->element[s->front]);
 s->front=s->front+1;}
//return p;
printf("deleted string is: %s\n",p);
}
int main(){
    Q *q;
    q=(Q *)calloc(1,sizeof(Q));
     q->front=-1,q->rear=-1;
    int flag,flag2,flag3;
    int ch,i;
    char item[max];
    do{
        printf("1.addrear 2.adddfront 4.delfront 5.display 6.exit\n");
scanf("%d",&ch);
getchar();
    switch(ch){
        case 1: if(q->rear+1==max){
                printf("cant be added\n");
                }
               else 
                { gets(item);
                addrear(q,item);}
                 break;

        case 2: if(q->front==0){
               printf("cant insert\n");
               }
                else {gets(item);
                addfront(q,item);}
               break;
        
        case 4: if(q->rear==-1 && q->front==-1){
               printf("cant del\n");
               }
                else {
              delfront(q);
             }
               break;
        case 5: for(i=q->front;i<=q->rear;i++)
                  printf("%s\t",q->element[i]);
               
           }
    }while(ch!=6);
return 0;

}
