#include<stdio.h>

int con_int_check(int num1,int num2){
    int t;
    if(num1<num2) t=num1;
    else t=num2;
    while(t>0){
        if(num1%t==0 && num2%t==0){
            return t;
        }
        else{
            t-=1;
        }
    }
    return -1;
}

int main(){
   int m,n;
   printf("enter the numbers\n");
   scanf("%d%d",&m,&n);
   printf("%d is gcd",con_int_check(m,n));
}