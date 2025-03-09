#include<stdio.h>
#include<stdlib.h>


typedef struct{
char element[100];
int top;
}STACK;

int isfull(STACK *s,int max_size){
if(s->top==max_size-1)
return 1;
else return 0;
}

int isempty(STACK *s){
if(s->top==-1)
return 1;
else return 0;
}
void push(STACK *s,char e ){
*(s->top)=*(s->top)+1;
s->element[*(s->top)]=e;
}
char pop(STACK *s){
char p=s->element[*(s->top)];
*(s->top)=*(s->top)-1;
return p;
}
void display(char st){
printf("the popped char is %c\n",st);
} 
int main(){
STACK s;
s.top=-1;
int ch;
char p;
int flag;
char item;
//printf("no. of elements to be read:\n");
//scanf("%d",&n);
do{
printf("1.push 2.pop 3.exit\n");
scanf("%d",&ch);
getchar();
switch(ch){
case 1: item= getchar();
getchar();
//printf("%c",item);
         flag=isfull(&s,100);
        printf("%d",flag);
         if(flag==1){
         printf("cant be pushed");
         break;}
       else 
       push(&s,item);
       break;

case 2:int flag2=isempty(&s);
      p=pop(&s);
       if(flag2==1){
       printf("cant pop\n");
       break;}
       else {
      display(p);}
      break;
     
   }
}while(ch!=3);
return 0;
}



