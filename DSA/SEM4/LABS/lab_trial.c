    #include<stdio.h>
    #define max 10
    int arr[max]={4,5,1,2,10,7};
    int b_search(int val,int l,int h){
        
        while(l<=h){
            int m=(l+h)/2;
            if(arr[m]==val) return m;
            else if(arr[m]<val) l=m+1;
            else h=m-1;
        }
     return l;
    }

    int main(){
        for(int i=1;i<6;i++){
            int val=arr[i];
            int j=i-1;
            int loc=b_search(val,0,j);

            while(j>=loc){
                arr[j+1]=arr[j];
                j--;
            }
            arr[loc]=val;
        }

        for(int i=0;i<6;i++) printf("%d ",arr[i]);
    }