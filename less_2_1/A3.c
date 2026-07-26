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
    
	unsigned int mask = (1U<<k)-1;
	res = n & mask;


	printf("%u",res);

    return 0;
}
