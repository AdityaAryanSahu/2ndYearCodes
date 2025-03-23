#include<stdio.h>
#define max 10

int arr[5][5]={{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,1},{1,0,0,0,0},{0,1,0,0,0}};

void warshall(){
    for(int k=0;k<5;k++){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                arr[i][j]=arr[i][j]||(arr[i][k]&&arr[k][j]);
            }
        }
    }
}
int main(){
  warshall();
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
        printf("%d ",arr[i][j]);
    }
    printf("\n");
}
}