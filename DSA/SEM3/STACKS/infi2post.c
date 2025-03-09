#include<stdio.h>
#include<string.h>
#define max 20
typedef struct{
char ele[max];
int top;
}STACK;
 void push(STACK *s,char e){
 if((s->top)==max-1)
 printf("full");
 else{
 s->top+=1;
 (s->ele[s->top])=e;
 }
 }
 
 char pop(STACK *s){
 if((s->top)==-1){
 return 1;
 }
 else{
 char p=(s->ele[s->top]);
 s->top-=1;
 return p;
 }
 }
 
 int precedence(char i){
    switch(i){
 case '+':{return 2;break;}
 case '-':{return 2;break;}
 case '/':{return 3;break;}
 case '*':{return 3;break;}
 case '(':{return 1;break;}
 case ')':{return 1;break;}
 default:{return -1;break;}
    }
 }
 
 int main(){
 STACK s;
 s.top=-1;
 char infix[max];
 char post[max];
 printf("enter a exprssion\n");
 fgets(infix,max,stdin);

 int i,j;
for(j=0,i=0;infix[i]!='\0';i++){
if((infix[i]>='A'&&infix[i]<='Z')|| (infix[i]>='a'&&infix[i]<='z')|| 
      (infix[i]>='0'&&infix[i]<='9')){
post[j++]=infix[i];
}
else if(infix[i]=='(')
push(&s,infix[i]);
 else if(infix[i]==')'){
while(s.top!=-1&&s.ele[s.top]!='('){
post[j++]=pop(&s);}
pop(&s);
}
else{
while(s.top!=-1 && precedence(infix[i])<=precedence(s.ele[s.top])){
post[j++]=pop(&s);
}
push(&s,infix[i]);
}
}
while(s.top!=-1){
post[j++]=pop(&s);
}
post[j]='\0';
printf("%s",post);
 }
 
