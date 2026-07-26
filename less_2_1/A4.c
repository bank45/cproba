#include <stdio.h>

int main(void) {
    unsigned int n;
    unsigned int k;

    if (scanf("%u %u", &n, &k) != 2) {
        return 1;
    }


    unsigned int mask = (1U << k) - 1;
    unsigned int max_value = 0;


    for (unsigned int i = 0; i <= 32 - k; i++) {

        unsigned int current_value = (n >> i) & mask;

        if (current_value > max_value) {
            max_value = current_value;
        }
    }


    printf("%u\n", max_value);

    return 0;
}
