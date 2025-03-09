#include<stdio.h>
#include<stdlib.h>


int main(){
    int n;
    printf("enter number of numbers:\n");
    scanf("%d",&n);

    int list[n];
    printf("enter list\n");
    for(int i=0;i<n;i++)
    scanf("%d",&list[i]);
    if(n==1){printf("not possible\n");exit(0);}
    int set1[n],set2[n];
int i=1;
int j=n-2;
int k=1,l=1;
int sum1=0,sum2=0;
int sum=0;
sum1=set1[0]=list[0];
sum2=set2[0]=list[n-1];
printf("%d\t%d\n",sum1,sum2);
for(int j=0;j<n;j++)
   sum+=list[j];
   if(sum%2==0){
    while(i<=j && i<n &&j>=0 ){
       if(sum1<=sum2) {set1[k++]=list[i];sum1+=list[i];i++;}
       else if(sum1>=sum2) {set2[l++]=list[j];sum2+=list[j];j--;}
    }
    int a=0;
    printf("set1:\n");
    while(a<k){
        printf(" %d\t",set1[a++]);
    }
a=0;
printf("\nset2:\n");
     while(a<l){
        printf(" %d\t",set2[a++]);
    }
   }
   else printf("not possible\n");
}