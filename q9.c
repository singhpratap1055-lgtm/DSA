#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int i, n;

    // Read the string
    scanf("%s", s);

    n = strlen(s);

    // Print the string in reverse order
    for (i = n - 1; i >= 0; i--) {
        printf("%c", s[i]);
    }

    return 0;
}
