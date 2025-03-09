#include<stdio.h>
#include<stdlib.h>
#define max 6

typedef struct{
char element[max];
int top;
}STACK;

int isfull(STACK *s,int max_size){
return s->top==max-1;
}

int isempty(STACK *s){
return s->top==-1;
}

void push(STACK *s,char e ){
s->element[++(s->top)]=e;
}

char pop(STACK *s){
return s->element[(s->top)--];
}

void display(char st){
printf("the popped char is %c\n",st);
} 
void peek(STACK *s){
   printf("The topmost elemrnt in stack is %c:",s->element[s->top]);
   
}

int main(){
STACK s;
s.top=-1;
int ch;
char p;
int flag,flag2,flag3;
char item;
do{
printf("1.push 2.pop 3.exit\n");
scanf("%d",&ch);
getchar();
    switch(ch){
        case 1: flag=isfull(&s,max);
               if(flag==1){
                printf("cant be pushed\n");
                }
               else 
                { item= getchar();
                 getchar();
                push(&s,item);}
                 break;

        case 2: flag2=isempty(&s);
               
               if(flag2==1){
               printf("cant pop\n");
               }
                else {
                  p=pop(&s);
               display(p);}
               break;
   }
}while(ch!=3);
return 0;
}



