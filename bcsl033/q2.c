#include <stdio.h>

int main() {
    char str[100];
    char reversed[100];
    int i, length, j;
    
    printf("Enter a string: ");
    
    // Read string character by character until newline
    i = 0;
    char ch;
    while ((ch = getchar()) != '\n' && i < 99) {
        str[i] = ch;
        i++;
    }
    str[i] = '\0';  // Null terminate the string
    
    // Calculate length manually (without strlen)
    length = 0;
    while (str[length] != '\0') {
        length++;
    }
    
    // Reverse the string
    j = 0;
    for (i = length - 1; i >= 0; i--) {
        reversed[j] = str[i];
        j++;
    }
    reversed[j] = '\0';  // Null terminate reversed string
    
    // Display results
    printf("\nOriginal String: %s", str);
    printf("\nReversed String: %s\n", reversed);
    
    return 0;
}