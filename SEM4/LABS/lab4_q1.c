#include<stdio.h>
#define max 10
int count;
int arr[max][max];

int check(int n){
  int min;
  int sum=0;
  int k=0;
  char c='A';
  int min_index=0;
	for(int i=0;i<n;i++){

	         for(int k=0;k<n;k++){//find the first non negetive element of a row
	         	count++;
                      if(arr[i][k]!=-1){
                      	min=arr[i][k];
                      	min_index=k;
                      	break; 
                      }
	         }

	    for(int j=0;j<n;j++){//find the minimum of the row
	    	count++;
                    if(arr[i][j]<min && arr[i][j]!=-1){
                        min=arr[i][j];
                        min_index=j;
                    }
	    }
	    printf("for person %c is %d\n",c++,min);
	    sum+=min;
        k=0;
		
	    while(k<n){///make the entire column -1
	       arr[k][min_index]=-1;
	       k++;
	    }

	}
	return sum;
}

int main(){
	int n1,n2;
	printf("enter number of jobs and people\n");
	scanf("%d%d",&n1,&n2);
	
	  if(n1==n2){
	for(int i=0;i<n1;i++){
	  for(int j=0;j<n2;j++){
	     scanf("%d",&arr[i][j]);
	  }
	}

	printf("minimum cost is: %d\n",check(n1));
	printf("count is %d",count);
	  }
	  else printf("cant find minimum cost\n");


}
