///Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.
#include <stdio.h>

int main() {
    int n, i;
    int arr[100];

    // Input size
    scanf("%d", &n);

    // Input array
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print first element (always unique)
    printf("%d ", arr[0]);

    // Print only unique elements
    for (i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
