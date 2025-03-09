#include<stdio.h>
#include<string.h>
#define max 20
typedef struct{
int ele[max];
int top;
}STACK;
 void push(STACK *s,int e){
 if((s->top)==max-1)
 printf("full");
 else{
 s->top+=1;
 (s->ele[s->top])=e;
 }
 }
 
 int pop(STACK *s){
 if((s->top)==-1){
 //printf("empty");
 return 0;
 }
 else{
 int p=(s->ele[s->top]);
 s->top-=1;
 return p;
 }
 }
 char getoken(char i){
 switch(i){
 case '+':{return '+';break;}
 case '-':{return '-';break;}
 case '/':{return '/';break;}
 case '*':{return '*';break;}
 default:{return 'o';break;}
 }
 }
  int main(){
    STACK s;
    s.top=-1;
    int op1,op2;
    char postfix[10];
    gets(postfix);
    int i;
    int n=strlen(postfix);
    for(i=0;postfix[i]!='\0';i++){
        if(getoken(postfix[i])=='o')
        push(&s,postfix[i]-'0');
        else{
            op2=pop(&s);
            op1=pop(&s);
    
        switch(postfix[i])
        {
            case '+':{push(&s,op1+op2);break;}
            case '-':{push(&s,op1-op2);break;}
            case '/':{push(&s,op1/op2);break;}
            case '*':{push(&s,op2*op1);break;}
           // case default:{continue;}
        }
        }
    }
    printf("%d",pop(&s));
 }