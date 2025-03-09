#include<stdio.h>
#include<string.h>
#include<stdlib.h>
///To copy one string to another using Recursion
/* void cpy(char s[],char s2[] , int index){
    if(s[index] != '\0'){
        s2[index]=s[index];
       // printf("%s",s2);
        cpy(s,s2,index+1);
    }
    else s2[index]='\0';
    //printf("the new string is:\n");
  
}
int main(){
   
   char str[100],str2[100];
   printf("Enter string\n");
   fgets(str,100,stdin);
   int n=strlen(str);
   cpy(str,str2,0);
   puts(str2);
    return 0;
}
*/




/* int palin(char s[], int n, int index){
    //static int flag;
    if(index>n/2)
    return 1;

   if(s[n-index-1] != s[index]){
            return 0;
        }
  return palin(s,n,index+1);    
}
int main(){
    char str[100];
    fgets(str,100,stdin);
    int n=strlen(str);
   int flag= palin(str,n-1,0);
     if(flag==1)
    printf("palin");
    else
    printf("not palin");
    return 0;
} */





 /* void ss(int *a, int n, int index){
    if(index>=n)
    return;
    int min=index,i;
    for(i=index+1;i<n;i++){
    if(a[min]>a[i]){
        min=i;
       }
    }
    if(min !=index){
        int temp=a[min];
        a[min]=a[index];
        a[index]=temp;
    }
    ss(a,n,index+1);

}
int main(){
    int arr[100];
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    ss(arr,n,0);
    for(i=0;i<n;i++)
    printf("%d\t",arr[i]);
} */


/*void tower(int n, char s, char temp, char d, int *count){
    if(n==1){
        (*count)++;
        printf("move disk 1 from %c to %c\n",s,d);
        return;
    }
    (*count)++;
    tower(n-1,s,d,temp,count);
    printf("move disk %d from %c to %c\n",n,s,d);
    tower(n-1,temp,s,d,count);
}
int main(){
    int n,count=0;
    printf("enter tno. of dsik\n");
    scanf("%d",&n);
    char a,b,c;
    scanf(" %c %c %c", &a, &b, &c);
    tower(n, a, b, c,&count);
    printf("the number of moves is: %d",count);
} */