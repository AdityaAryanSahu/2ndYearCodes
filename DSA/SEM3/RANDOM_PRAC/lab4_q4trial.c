#include <stdio.h>
#include<stdlib.h>

#define max 100
typedef struct{
int rem;
}STACK;

void push(STACK *s,int *top,int e ){
*top=*top+1;
(s+*top)->rem=e;
}

int pop(STACK *s,int *top){
int p=(s+*top)->rem;
*top=*top-1;
return p;
}

int main() {
    STACK *s;
    int n,n1, k;
    int i, j;int top=-1;
    scanf("%d", &n1);
    scanf("%d", &k);
    int arr[n1];
    s=(STACK *)calloc(max,sizeof(STACK));
    for (i = 0; i < n1; i++) {
        scanf("%d", &arr[i]);
    }

    int deleteCount = 0;

    // Iterate to find and delete elements
    for (i = 0; i < n1 - 1 && deleteCount < k; ) {
        if (arr[i] < arr[i + 1]) {
            push(s,&top,arr[i+1]);
            // Mark the element for deletion
            for (j = i; j < n - 1; j++) {
                s[j] = s[j + 1];
            }
            n--;
            deleteCount++;
            i=0;
        } else {
            //push(s,&top,arr[i]);
            i++;
        }
    }

    // Print the remaining elements
    for (i = 0; i < n1; i++) {
        n=pop(s,&top);
        printf("%d ", n);
    }
    printf("\n");
    free(s);

    return 0;
}
