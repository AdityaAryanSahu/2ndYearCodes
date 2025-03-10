#include<stdio.h>
#include<stdlib.h>
#define max 20

int arr[max]={0};
int n;
int count=0;

void heapify(){
    
    for(int i=n/2;i>=0;i--){
        int k=i;
        int heap=0;
        int val=arr[k];
        while(!heap && 2*k+1<n){
            int j=2*k+1;
            if(j+1<n)
              if(arr[j]<arr[j+1]) j+=1;
            if(val>=arr[j]) heap=1;
            else{
                arr[k]=arr[j];
                k=j;
            }
        }
        arr[k]=val;
    }
}
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heap_sort(){
    for(int i=n-1;i>0;i--){
       swap(&arr[0],&arr[n-1]);
        n-=1;
        heapify();
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  int n1=n;
    heapify();
    printf("after 1st heapify\n");
    for(int i=0;i<n1;i++)
     printf("%d\t",arr[i]);
  heap_sort();
  printf("\nafter sort\n");
     for(int i=0;i<n1;i++)
     printf("%d\t",arr[i]);
 
}