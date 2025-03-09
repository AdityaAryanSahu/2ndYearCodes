#include <stdio.h>
#include<stdlib.h>
 
 int*f3(void){
     int*p;
     *p=10;
     return p;
 }
int main() {
   
    int *p3=f3();
    printf("%d\t",*p3);
    return 0;
}