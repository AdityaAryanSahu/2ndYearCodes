#include <stdio.h>
#include <string.h>
#define MAX 256 
int shiftTable[MAX]; 
int count = 0;  
void cShiftTable(char pattern[], int m) {
    for (int i = 0; i < MAX; i++) {
        shiftTable[i] = m;  
    }

    for (int i = 0; i < m - 1; i++) {
        shiftTable[(unsigned char)pattern[i]] = m - 1 - i;
    }
}
int horspool(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);

    cShiftTable(pattern, m);

    int i = m - 1;  
    while (i < n) {
        int k = 0;
        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            k++;
            count++;
        }

        if (k == m) {
            printf("Pattern found at index %d\n", i - m + 1);
            return 1; 
        }
        count++; 
        i += shiftTable[(unsigned char)text[i]];  
    }
    return 0;
}

int main() {
    char text[100], pattern[50];

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    if (horspool(text, pattern)) {
        printf("Successful search with %d key comparisons.\n", count);
    } else {
        printf("Pattern not found. Unsuccessful search with %d key comparisons.\n", count);
    }

    return 0;
}
