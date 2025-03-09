#include<stdio.h>
#include<stdlib.h>
#define max 15
typedef struct{
    char element[max];
    int rear;
    int front;
}Q;
void addrear(Q *s,char e ){
    if(s->rear==-1 && s->front==-1){
        s->rear=s->rear+1;
        s->front=s->front+1;
        s->element[s->rear]=e;
    }
    else{
s->rear=s->rear+1;
 s->element[s->rear]=e;}

}
void addfront(Q *s,char e){
    if(s->rear==-1 && s->front==-1){
        s->rear=s->rear+1;
        s->front=s->front+1;
        s->element[s->front]=e;
    }
    else{
s->front=s->front-1;
s->element[s->front]=e;}

}

char delrear(Q *s){
    char p;
    if(s->rear==s->front){
         p=s->element[s->rear];
         s->rear=-1;
         s->front=-1;
    }
    else{
 p=s->element[s->rear];
 s->rear=s->rear-1;}
return p;
}

char delfront(Q *s){
   char p;
    if(s->rear==s->front){
         p=s->element[s->front];
         s->rear=-1;
         s->front=-1;
    }
    else{
 p=s->element[s->front];
 s->front=s->front+1;}
return p;
}
int main(){
    Q *q;
    q=(Q *)calloc(1,sizeof(Q));
     q->front=-1,q->rear=-1;
    int flag;
    int i=0;
    char str[max];
    printf("enter string\n");
    gets(str);
    while(str[i]!='\0'){
        addrear(q,str[i]);
        i++;
    }
    while(q->rear!=q->front){
        if(delfront(q)!=delrear(q)){
            flag=0;
            break;
        }
    }
    if(flag==0)
        printf("not palinfrome\n");
    else printf("palin");
return 0;

}
