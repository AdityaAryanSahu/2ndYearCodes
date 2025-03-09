#include<stdio.h>
#include<stdlib.h>

#define max 7
typedef struct{
int ele;
int top1;
int top2;
}STACK;
 void push1(STACK *s,int e){
 
 s->top1+=1;
 (s[s->top1].ele)=e;
 }
 
 void push2(STACK *s,int e){
 
 
 (s[s->top2].ele)=e;
 s->top2-=1;
 }
 
 
int pop1(STACK *s){
 
int p=(s[s->top1].ele);
 s->top1-=1;
 return p;
 }
 
int pop2(STACK *s){
 s->top2+=1;
int p=(s[s->top2].ele);
 
 return p;
 }
 
 int main(){
    STACK *s;
    s=(STACK *)calloc(max,sizeof(STACK));
    s->top1=-1;
    s->top2=max-1;
      int ch,i,p,item;
    do{
    printf("1.push_s1 2.push_s2 3.pop_s1 4.pop_s2 5.display_s1 6.display_s2 7.exit\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:{if(s->top1==s->top2)
                  printf("stack1 full\n");
                 else{
               scanf("%d",&item);
               push1(s,item);}
               break;}
        case 2:{if(s->top1==s->top2)
                  printf("stack2 full\n");
                else{
               scanf("%d",&item);
               push2(s,item);}
               break;}
        case 3: {if((s->top1)==-1){
                  printf("stack1 empty\n");
                 }
                else{
                    p=pop1(s);
               printf("popped ele from s1 is %d\n",p);}
               break;}
               
        case 4: {if(s->top2==max-1)
                 {
                 printf("stack2 empty\n");
                 }
                 else
                {p=pop2(s);
               printf("popped ele from s2 is %d\n",p);}
               break;}
        case 5:{if((s->top1)==-1){
                  printf("stack1 empty\n");
                 }
                else
            for(i=0;i<=s->top1;i++){
            printf("%d\t",s[i].ele);
            }
            break;
        }
        case 6:{if(s->top2==max-1)
                 {
                 printf("stack2 empty\n");
                 }
                 else
            for(i=max-1;i>s->top2;i--){
            printf("%d\t",s[i].ele);
            }
            break;
        }
    }
    }while(ch!=7);
 }
 