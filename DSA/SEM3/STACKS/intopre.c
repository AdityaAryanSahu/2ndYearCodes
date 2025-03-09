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
 char getoken(char i){
 switch(i){
 case '+':{return '+';break;}
 case '-':{return '-';break;}
 case '/':{return '/';break;}
 case '*':{return '*';break;}
 case '(':{return '(';break;}
 case ')':{return ')';break;}
 default:{return 'o';break;}
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
 
 void rev(char p[]){
 int n=strlen(p);
 int i;
 for(i=0;i<n/2;i++){
 char temp=p[i];
 p[i]=p[n-i-1];
 p[n-i-1]=temp;
 }
 }
 void brackets(char p[]){
    int i=0;
    while(p[i]!='\0'){
        if(p[i]=='(')  p[i]=')';
        else if(p[i]==')') p[i]='(';
        i++;
    }
 }
 int main(){
 STACK s;
 s.top=-1;
 char infix[max];
 char post[max];
 char token;
 printf("enter a exprssion\n");
 gets(infix);
 //getchar();
 rev(infix);
 brackets(infix);
 //puts(infix);
 int i=0,j;
for(j=0;infix[i]!='\0';i++){
if(getoken(infix[i])=='o'){
post[j++]=infix[i];
}
else if(getoken(infix[i])=='(')
push(&s,infix[i]);
 else if(getoken(infix[i])==')'){
while(s.top!=-1&&s.ele[s.top]!='('){
post[j++]=pop(&s);}
pop(&s);
//printf("%c\n",r);
}
else{
while(s.top!=-1&&precedence(infix[i])<precedence(s.ele[s.top])){
post[j++]=pop(&s);
}
push(&s,infix[i]);
}
}
while(s.top!=-1){
post[j++]=pop(&s);
}
post[j]='\0';
//puts(post);
rev(post);
printf("%s",post);
 }
 
