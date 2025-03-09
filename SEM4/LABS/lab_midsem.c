// Online C compiler to run C program online
#include <stdio.h>
#define max 100
int euclid(int a ,int b){
    while(b>0){
        int t=a%b;
        a=b;
        b=t;
    }
    return a;
}

int n1,n2,gcd;
int array[max][max];

int cal_gcd(int arr[],int x){
    if(x==n2) return gcd;
    gcd=euclid(gcd,arr[x]);
    return cal_gcd(arr,x+1);
}
int main() {
   scanf("%d%d",&n1,&n2);
   for(int i=0;i<n1;i++)
     for(int j=0;j<n2;j++)
         scanf("%d",&array[i][j]);
         
         for(int i=0;i<n1;i++){
             gcd=array[i][0];
             printf("%d\n",cal_gcd(array[i],1));
         }
      

    return 0;
}