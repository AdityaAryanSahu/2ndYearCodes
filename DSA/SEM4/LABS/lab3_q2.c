#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count;
 int string_check(char *str,char*sub){
     int i,j;
     i=0,j=0;
     if(strlen(str)<strlen(sub)) return -1;
     
     while(i<strlen(str) && j<strlen(sub)){
        if(str[i]==sub[j]){
        i++;j++;
           if(j==strlen(sub)) return (i-j);
        }
        else{
            i++;
            j=0;
        }
     } 
     return -1;
 }
int main(){
   printf("enter a string\n");
  char *str=(char*)calloc(1,sizeof(char));
   gets(str);

  printf("enter a substring\n");
  char *sub=(char*)calloc(1,sizeof(char));
   gets(sub);

  int c=string_check(str,sub);
  if(c==-1 ){
    printf("not found\n");
  }
  else printf("found at index %d\n",c);
  
}