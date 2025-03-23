#include<stdio.h>
#define max 10

int arr[max][max];

int min(int a,int b){
    if(a<b) return a;
    else return b;
}

void floyd(int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j]=min(arr[i][j], arr[i][k]+arr[k][j]);
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    floyd(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

}