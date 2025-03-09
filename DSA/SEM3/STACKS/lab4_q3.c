#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
s->top=s->top+1;
s->element[s->top]=e;
}
char pop(STACK *s){
char p=s->element[s->top];
s->top=s->top-1;
return p;
}
int main(){
    int pal=1;
    STACK s;
    s.top=-1;
    int i;
    char str[100];
    gets(str);
    for(i=0;str[i]!='\0';i++){
        int flag=isfull(&s,50);
        if(flag==1)
        printf("coverflow");
        else
        push(&s,str[i]);
    }
    int n=strlen(str);
    for(i=0;i<n/2;i++){
        int flag=isempty(&s);
        if(flag==1)
        printf("empty");
        else
        {
         char p=pop(&s);
        if(p != str[i])
        {
            pal=0;
            break;
        }
       }
    if(pal==0)
        printf("not palindrome");
        else
        printf("plain");
    
}