#include <stdio.h>

int main(void) {
	unsigned int n;
   int k;
	unsigned int res;

    if (scanf("%u", &n) != 1) {
        return 1;
    }
        if (scanf("%d", &k) != 1) {
        return 1;
    }
    k=k%32;
	res=(n>>k) | (n << (32-k));


	printf("%u",res);

    return 0;
}
