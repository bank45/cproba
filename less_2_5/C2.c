#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXN 100005

static long long stack[MAXN];
static int top = 0;

static void push(long long x) { stack[top++] = x; }
static long long pop(void)    { return stack[--top]; }

static int is_number(const char *s) {
    if (*s == '\0') return 0;
    for (int i = 0; s[i]; i++)
        if (!isdigit((unsigned char)s[i])) return 0;
    return 1;
}

int main(void) {
    char line[1000005];
    if (!fgets(line, sizeof(line), stdin)) {
        printf("0\n");
        return 0;
    }

    char *tok = strtok(line, " \t\r\n");
    while (tok) {
        if (is_number(tok)) {
            push(atoll(tok));
        } else {
            char op = tok[0];
            if (op == '+' || op == '-' || op == '*' || op == '/') {
                long long a = pop();
                long long b = pop();
                long long res = 0;
                switch (op) {
                    case '+': res = b + a; break;
                    case '-': res = b - a; break;
                    case '*': res = b * a; break;
                    case '/': res = b / a; break;
                }
                push(res);
            }
        }
        tok = strtok(NULL, " \t\r\n");
    }

    printf("%lld\n", pop());
    return 0;
}