#include<stdio.h>
#define max 1000
#include<string.h>
char text[max];
char pattern[max];
int n;


int check(){
   int m=strlen(pattern);
   int i=0;
   int j=0;
   while(i<strlen(text)&&j<strlen(pattern)){
      switch(i%3){
        case 0: if(text[i]>pattern[j]){
                j++;i++;
                 }
                 else {i=i+3;j=0;}
                 break;
        case 1:if(text[i]==pattern[j]){i++; j++;}
                else {i=i+2;j=0;}
                break;
        case 2: if(text[i]<pattern[j]) {i++;j++;}
                else {i=i+1;j=0;}
                break;
      }

      if(j==m) return (i-j);
      
   }
   return -1;
}

int main(){
  gets(text);
  gets(pattern);

  int f=check();
  printf("\n%d\n ",f);

}
