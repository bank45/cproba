#include <stdio.h>
#include <math.h>



 long double foo(int n)
{
	int  q=2;
	long double sum=0;
	

	sum=1*(pow(q,(n-1)));

	return sum;
}

int main()
{
	
	int a=0;
	long double sum=0;

		scanf("%d", &a);

		sum=foo(a);

	printf("%.0Lf ", sum);			
		
	return 0;
}


