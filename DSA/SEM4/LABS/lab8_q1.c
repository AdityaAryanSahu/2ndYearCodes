#include<stdio.h>
#define max 100

typedef struct{
	int size;
	int arr[max];
}Heap;

Heap heap;
int n;
int array[max];

void heapify(){
    
    for(int i=(heap.size)/2;i>=0;i--){
        int k=i;
        int h=0;
        int val=heap.arr[k];
        while(!h && 2*k+1<n){
            int j=2*k+1;
            if(j+1<n)
              if(heap.arr[j]<heap.arr[j+1]) j+=1;
            if(val>=heap.arr[j]) h=1;
            else{
                heap.arr[k]=heap.arr[j];
                k=j;
            }
        }
        heap.arr[k]=val;
    }
}

void insert(int value){
	heap.arr[heap.size++]=value;
	heapify();
}

int main(){

   scanf("%d",&n);
   int value;
   for(int i=0;i<n;i++){
     scanf("%d",&value);
     insert(value);
   }

   for(int i=0;i<heap.size;i++)
   	printf("%d\t",heap.arr[i]);

	
}