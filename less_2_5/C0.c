#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 200005

int nxt[MAX_LEN][10];
char s[MAX_LEN];
int curr[10];

int main() {
    if (scanf("%200000s", s) != 1) {
        printf("0\n");
        return 0;
    }

    int n = strlen(s);
    if (n < 3) {
        printf("0\n");
        return 0;
    }

    for (int d = 0; d < 10; d++) {
        curr[d] = -1;
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = s[i] - '0';
        curr[digit] = i;
        
        for (int d = 0; d < 10; d++) {
            nxt[i][d] = curr[d];
        }
    }

    int count = 0;

    for (int num = 100; num <= 999; num++) {
        int d1 = num / 100;
        int d2 = (num / 10) % 10;
        int d3 = num % 10;

        int p1 = nxt[0][d1];
        if (p1 != -1 && p1 + 1 < n) {
            int p2 = nxt[p1 + 1][d2];
            if (p2 != -1 && p2 + 1 < n) {
                int p3 = nxt[p2 + 1][d3];
                if (p3 != -1) {
                    count++;
                }
            }
        }
    }

    printf("%d\n", count);
    return 0;
}
