#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void compute_pi(const char *s, int n, int *pi) {
    pi[0] = 0;
    for (int i = 1; i < n; i++) {
        int k = pi[i - 1];
        while (k > 0 && s[i] != s[k])
            k = pi[k - 1];
        if (s[i] == s[k])
            k++;
        pi[i] = k;
    }
}

int solve(const char *a, int lenA, const char *b, int lenB) {
    int total = lenA + 1 + lenB;
    char *t = (char *)malloc(total + 1);
    memcpy(t, a, lenA);
    t[lenA] = '\x01';                  
    memcpy(t + lenA + 1, b, lenB);
    t[total] = '\0';

    int *pi = (int *)calloc(total, sizeof(int));
    compute_pi(t, total, pi);
    int ans = pi[total - 1];

    free(t);
    free(pi);
    return ans;
}

static void read_line(char *buf, int size) {
    if (!fgets(buf, size, stdin)) {
        buf[0] = '\0';               
        return;
    }
    size_t len = strlen(buf);
    while (len > 0 && (buf[len - 1] == '\n' || buf[len - 1] == '\r'))
        buf[--len] = '\0';
}

int main(void) {
    char s1[10002], s2[10002];
    read_line(s1, sizeof(s1));
    read_line(s2, sizeof(s2));

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int ans1 = solve(s1, len1, s2, len2);  
    int ans2 = solve(s2, len2, s1, len1);  

    printf("%d %d\n", ans1, ans2);
    return 0;
}