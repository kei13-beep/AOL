#include <stdio.h>
#include <ctype.h>
#include <string.h>

void reverseAndInverse(char str[]) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        } else if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        }
    }

    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char str[101];
    scanf ("%s", &str);
    reverseAndInverse(str);
    printf("%s\n", str);
    return 0;
}

