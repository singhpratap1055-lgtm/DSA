///Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.


#include <stdio.h>

int main() {
    int p, q;
    int a[100], b[100];
    int i = 0, j = 0;

    // Input for server 1
    scanf("%d", &p);
    for (i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    // Input for server 2
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    i = 0;
    j = 0;

    // Merge both arrays
    while (i < p && j < q) {
        if (a[i] <= b[j]) {
            printf("%d ", a[i]);
            i++;
        } else {
            printf("%d ", b[j]);
            j++;
        }
    }

    // Remaining elements of server 1
    while (i < p) {
        printf("%d ", a[i]);
        i++;
    }

    // Remaining elements of server 2
    while (j < q) {
        printf("%d ", b[j]);
        j++;
    }

    return 0;
}
