#include<stdio.h>
#define m 10

int v[m][m];
int weight[m]; 
int value[m];
int comb[m];
int count;
int max(int a,int b){
    if(a>b) return a;
    else return b;
}

int knap(int i,int j){
    int val;count++;
     if(v[i][j]<0){
        if(j<weight[i]) val=knap(i-1,j);
        else{
            val=max(knap(i-1,j), (value[i]+knap(i-1,j-weight[i])));
        }
        v[i][j]=val;
     }
     return v[i][j];
}

void sub(int n,int w){
   int k=0;
    int i=n,j=w;
    while(i>0 && j>0){
         if(v[i][j]!=v[i-1][j])
            {comb[k++]=i;
               j=j-weight[i];
               i--;
            }
            else{
                i--;
            }
    }
    for(int i=0;i<k;i++)
    printf("%d ",comb[i]);
}

int main(){
    int n,W;
    scanf("%d",&n);
    scanf("%d",&W);
    printf("enter weights\n");
    for(int i=1;i<n+1;i++)
    scanf("%d",&weight[i]);

    printf("enter values\n");
    for(int i=1;i<n+1;i++)
    scanf("%d",&value[i]);

    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
           v[i][j]=-1;
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
          knap(i,j);
        }
    }

    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            printf("%d ",v[i][j]);
        }
        printf("\n");
    }

    sub(n,W);
    printf("\ncount: %d\n",count);
    

   

}