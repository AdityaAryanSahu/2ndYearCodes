#include <stdio.h>
#include <limits.h>

#define MAX 10

int arr[MAX][MAX];
int minCost = INT_MAX;
int n;


int calculateCost(int perm[]) {
    int cost = 0;
    for (int i = 0; i < n; i++) {
        cost += arr[i][perm[i]]; 
    }
    return cost;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void generatePermutations(int perm[], int l) {
    if (l == n) { // If a complete permutation is formed
        int cost = calculateCost(perm);
        if (cost < minCost) {
            minCost = cost; // Update minimum cost
        }
        return;
    }

    for (int i = l; i < n; i++) {
        swap(&perm[l], &perm[i]);  // Swap for new permutation
        generatePermutations(perm, l + 1);
        swap(&perm[l], &perm[i]);  // Backtrack to previous state
    }
}

int main() {
    printf("Enter number of jobs and people: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);

    int perm[MAX];
    for (int i = 0; i < n; i++) perm[i] = i;  // Initial job assignments

    generatePermutations(perm, 0);

    printf("Minimum cost using brute force: %d\n", minCost);

    return 0;
}
