#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int checkOccurrence(char* string, char character) {
    int i, k = 0;
    char B;
    if (character >= 'a' && character <= 'z') {
        B = character + 'A' - 'a';
        printf("B = %d\n", B);
    }
    else {
        B = character - 'A' + 'a';
                printf("B = %d\n", B);

    }
    for (i = 0; i < strlen(string); i++) {
        if (string[i] == character || string[i] == B) {
            k++;
        }
    }
    return k;
}

int main() {
    char s[255];
    char b;
    printf("s = ");
    fgets(s, sizeof(s), stdin); // reads character of length 255 from stream input
    printf("b = ");
    b = getchar(); // reads a single character
    printf("%d\n", checkOccurrence(s, b));
    return 0;
}