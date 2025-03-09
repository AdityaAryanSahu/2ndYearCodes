#include<stdio.h>
#include<math.h>
int count;
int mid_sch(int m,int n){
    int arr1[50],arr2[50];
    int flag;
    int k=0,l=0;
    int i,j;
    for( i=2;i<=m;){
         flag=1;
        if(m%i==0){
            for( j=2;j<=sqrt(i);j++){
                count++;
                if(i%j==0) {flag=0; break;}
            }
            if(flag==1) {arr1[k++]=i; m/=i;}
        }
        else i++;
    }

     for( i=2;i<=n;){
         flag=1;
        if(n%i==0){
            for( j=2;j<=sqrt(i);j++){
                count++;
                if(i%j==0) {flag=0;break;}
            }
            if(flag==1) {arr2[l++]=i;n/=i;}
        }
        else i++;
    }
    int mult=1;
    int x = 0, y = 0; 
    while (x < k && y < l) {
        count++;
        if (arr1[x] == arr2[y]) {
            mult *= arr1[x];
            x++;
            y++;
        } else if (arr1[x] < arr2[y]) {
            x++;
        } else {
            y++;
        }
    }
    return mult;

}
int main(){
    int m,n;
   printf("enter the numbers\n");
   scanf("%d%d",&m,&n);
   printf("%d is gcd",mid_sch(m,n));
   printf("\ncount is %d",count);
}