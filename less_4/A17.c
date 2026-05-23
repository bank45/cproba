#include <stdio.h>


int main(void)
{
	
	int a;
	scanf("%d", &a);
	
	if (a<3||a==12) {printf("%s\n", "winter"); return 0;}
	if (a>2&&a<6) {printf("%s\n", "spring"); return 0;}
	if (a>5&&a<9) {printf("%s\n", "summer"); return 0;}
	if (a>8&&a<12) {printf("%s\n", "autumn"); return 0;}
}

