#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        int count = 1;

        // Skip if element is already counted
        if (a[i] == -1)
            continue;

        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                count++;
                a[j] = -1;   // mark as counted
            }
        }

        printf("%d:%d ", a[i], count);
    }

    return 0;
}
