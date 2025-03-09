#include <stdio.h>
#define MAX 20  

int arr[MAX], n;
int subset[MAX];
int total_sum = 0;


int isPartitionPossible(int index, int subset_sum, int subset_size) {
    if (subset_sum == total_sum / 2) {
        printf("Subset found:\n");
        for (int i = 0; i < subset_size; i++)
            printf("%d ", subset[i]);
        printf("\n");
        return 1;
    }

    if (index >= n || subset_sum > total_sum / 2)
        return 0;

    // Include current element in subset 
    subset[subset_size] = arr[index];
    if (isPartitionPossible(index + 1, subset_sum + arr[index], subset_size + 1))
        return 1;

    // Exclude current element 
    return isPartitionPossible(index + 1, subset_sum, subset_size);
}

int main() {
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n > MAX) {
        printf("Number of elements exceeds maximum allowed.\n");
        return 0;
    }

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++)  //sum of array
        total_sum += arr[i];

    //if sum odd, not possible
    if (total_sum % 2 != 0) {
        printf("Not possible to partition into equal subsets.\n");
        return 0;
    }

    if (!isPartitionPossible(0, 0, 0))
        printf("No valid partition found.\n");

    return 0;
}
