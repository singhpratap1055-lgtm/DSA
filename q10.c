#include <stdio.h>
#include <string.h>

int main() {
    
    char s[100];
    int l, r, n, f = 0;
    
    // Read string
    scanf("%s", s);
    
    n = strlen(s);
    
    l = 0;
    r = n - 1;
    
    // Two pointer comparison
    while (l < r) {
        if (s[l] != s[r]) {
            f = 1;
            break;
        }
        l++;
        r--;
    }
    
    if (f == 0)
        printf("YES");
    else
        printf("NO");
    
    return 0;
}
