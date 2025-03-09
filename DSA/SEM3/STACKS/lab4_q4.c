#include <stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

int main() {
    int *s;
    int n, k;
    int i, j;
    scanf("%d", &n);
    scanf("%d", &k);
    s=(int *)calloc(MAX_SIZE,sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }

    int deleteCount = 0;

    // Iterate to find and delete elements
    for (i = 0; i < n - 1 && deleteCount < k; ) {
        if (s[i] < s[i + 1]) {
            // Mark the element for deletion
            for (j = i; j < n - 1; j++) {
                s[j] = s[j + 1];
            }
            n--;
            deleteCount++;
            i=0;
        } else {
            i++;
        }
    }

    // Print the remaining elements
    for (i = 0; i < n; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");
    free(s);

    return 0;
}
