#include<stdio.h>
#include<string.h>
#define max 20
typedef struct{
int ele[max];
int top;
}STACK;
int isfull(STACK *s){
if(s->top==max)
return 1;
else return 0;
}

int isempty(STACK *s){
if(s->top==-1)
return 1;
else return 0;
}
void push(STACK *s,int e){

 s->top+=1;
 (s->ele[s->top])=e;
 }
 
 
 int pop(STACK *s){
 int p=(s->ele[s->top]);
 s->top-=1;
 return p;
 }
 
 int main(){
    STACK s;
    s.top=-1;
    int i,item;
    int k;
    while(1){
        k=0;
       while(!isfull(&s)){
            printf("enter number\n");
            scanf("%d",&item);
             while(k<=5 && item>0){
            {
                push(&s,item);
                k++;
            }
            if(k>=5) break;
        } 
       }
        if(item<0)
            if(k<5){
            printf("error");
            break;}
            else {
                while(k>0){
                    printf("%d\t",pop(&s));
                    k--;
                }
            }
        }
    }
 