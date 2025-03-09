#include<stdio.h>
#include<stdlib.h>
void read(int **arr,int m,int n){
     int i,j;

    for(i=0;i<n;i++){
        printf("\nenter marks of courses for stu %d\n",(i+1));
        for(j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
    }
}
void compute(int **arr,int total[],int avg[],int m,int n){
    int i,j;
for(i=0;i<n;i++){
        total[i]=0;
        avg[i]=0;
        for(j=0;j<m;j++){
            total[i]+=arr[i][j];
        }
        avg[i]=total[i]/n;
    }
}
void sort(int **arr,int total[],int avg[],int m,int n){
     int i,j,**temp;
     temp=(int **)calloc(1,sizeof(int*));
     *temp=(int*)calloc(m,sizeof(int));
for(i=0;i<n-1;i++){
    for(j=0;j<n-i-1;j++){
      if(avg[i]<avg[i+1]){
         *temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=*temp;

    }
    }
}
}
void display(int **arr,int m,int n){
    int i,j;
     printf("descending order is:\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n-----------\n");
        
    }
}

int main(){
    int m,n,i;
    printf("enter size of stu\n");
    scanf("%d",&n);
    printf("enter size of courses\n");
    scanf("%d",&m);
    int **arr;
    arr=(int**)calloc(n,sizeof(int *));
    for(i=0;i<n;i++){
        arr[i]=(int *)calloc(m,sizeof(int));
    }
    read(arr, m, n);
    int total[m];
        int avg[m];
        compute(arr,total,avg,m,n);
    sort(arr,total,avg,m,n);
   display(arr,m,n);
    
}