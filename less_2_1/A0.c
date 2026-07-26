#include <stdio.h>

int main(int argc, char **argv)
{
	int n = 0;
	int d = 0;
	int max = -2147483648;
	int coun = 1;
	scanf("%d", &n);

	if(n>0)
	{
		scanf("%d",&d);
		max=d;
		coun=1;
		n--;
	}
	while (n != 0)
	{
		scanf("%d", &d);
		if (d > max)
		{
			max = d;
			coun=1;
		}
		else
		{
			if (d == max)
			{
				coun++;
			}
		}

		n--;
	}
	printf("%d\n", coun);
	// printf("max: %d\n", max);
	return 0;
}
