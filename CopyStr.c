#include <stdio.h>

int main() {
    char source[100], destination[100];
    printf("Enter the source string: ");
    scanf("%s", source);
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
    printf("The copied string is: %s\n", destination);
    return 0;
}
