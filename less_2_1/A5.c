#include <stdio.h>

int main(void) {
    unsigned int n;

    if (scanf("%u", &n) != 1) {
        return 1;
    }

    int coun = 0;
    

    while (n > 0) {

        coun += (n & 1);

        n >>= 1;
    }


    printf("%d\n", coun);
    return 0;
}
