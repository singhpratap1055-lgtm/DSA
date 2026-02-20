#include <stdio.h>
#include <stdlib.h>

// Simple hash structure using array (works for moderate constraints)
#define MAX 100000

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    long long prefixSum = 0;
    long long count = 0;
    
    // Using dynamic array as frequency map
    // Range assumed manageable for DSA problems
    int *freq = (int*)calloc(2 * MAX + 1, sizeof(int));
    
    int offset = MAX;  // to handle negative sums
    
    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];
        
        // If prefix sum is zero
        if(prefixSum == 0)
            count++;
        
        // If prefix sum seen before
        if(freq[prefixSum + offset] > 0)
            count += freq[prefixSum + offset];
        
        // Increase frequency
        freq[prefixSum + offset]++;
    }
    
    printf("%lld", count);
    
    free(freq);
    return 0;
}