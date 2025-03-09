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
 return 1;
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
    char prefix[max];
    gets(prefix);
    int i;
    int n=strlen(prefix);
    for(i=n-1;i>=0;i--){
        if(getoken(prefix[i])=='o')
        push(&s,prefix[i]-'0');
        else{
            op2=pop(&s);
            op1=pop(&s);
        
        
        switch(prefix[i])
        {
            case '+':{push(&s,op1+op2);break;}
            case '-':{push(&s,op2-op1);break;}
            case '/':{push(&s,op2/op1);break;}
            case '*':{push(&s,op2*op1);break;}
            //case default:{continue;}
        }
      }
    }
    printf("%d",pop(&s));
 }