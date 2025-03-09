#include<stdio.h>
#include<stdlib.h>
//#define max 50
typedef struct{
int rem;
}STACK;

STACK* create(int max){
STACK *s;
s=(STACK *)calloc(max,sizeof(STACK));
return s;
}

int isfull(STACK *s,int max_size,int top){
if(top==max_size-1)
return 1;
else return 0;
}

int isempty(STACK *s,int top){
if(top==-1)
return 1;
else return 0;
}

void push(STACK *s,int *top,int e ){
*top=*top+1;
(s+*top)->rem=e;
}

int pop(STACK *s,int *top){
int p=(s+*top)->rem;
*top=*top-1;
return p;
}

int main(){
STACK *s;
int i=0;
s=create(50);
int rem,n;int top=-1;int arr[100];
printf("enter a number to convert:\n");
scanf("%d",&n);
do{
rem=n%2;
int flag=isfull(s,50,top);
if(flag==1)
printf("overflow");
else
push(s,&top,rem);
n=n/2;
}while(n!=0);
printf("The binary is:\n");
while(isempty(s,top)!=1){
         int p=pop(s,&top);
         printf("%d\t",p);
}
}

