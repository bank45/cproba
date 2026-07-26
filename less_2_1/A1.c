#include <stdio.h>

int main(void) {
    int n;

    if (scanf("%d", &n) != 1) {
        return 1;
    }

    int c;

    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z') {

            c = ((c - 'a' + n) % 26 + 26) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {

            c = ((c - 'A' + n) % 26 + 26) % 26 + 'A';
        }

        putchar(c);


        if (c == '.') {
            break;
        }
    }

    return 0;
}
