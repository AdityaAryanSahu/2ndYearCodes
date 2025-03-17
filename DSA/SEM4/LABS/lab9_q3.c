#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define max 11

int arr[max]={0};
int n;
int flag=0;
int count=0;

void insert(int val,int idx){
   while(1){
        if(arr[idx]==0) {arr[idx]=val;break;}
        else if(idx<max) {idx++;}
        else if(idx==max) idx=0;
  }
}
void search(int val,int idx){
    while(1){
        if(arr[idx]==val) {count++;printf("found at index %d \n count_comp is %d\n",idx,count);break;}
        else if(idx<max) {count++;idx++;}
        else if(idx==max) idx=0;
  }
}

int main(){
    int x,v;
     printf("enter number of integers\n");
     scanf("%d",&n);
    for(int i=0;i<n;i++){
     
        printf("enter a val\n");
        scanf("%d",&x);
        int mod=x%max;
        insert(x,mod);

    }
    for(int i=0;i<max;i++)
        printf("%d ",arr[i]);

    printf("\nenter elemnet to be searched\n");
    scanf("%d",&x);
    int mod=x%max;
    search(x,mod);
}