#include <stdio.h>


int main(int argc, char **argv)
{
	char num[100] = " ";
	int digit[10] = {0};
	int i = 0;
	scanf("%s",num);	
	
	while(num[i] != '\0')
	{
		int d = num[i] - '0';
		if(d >= 0 && d <= 9)
		{
			digit[d]++;
		}
		i++;
	}
	i = 0;
	
	while(i<10)
	{
		if(digit[i] > 0)
		{
		printf("%d %d\n",i,digit[i]);

		}
		i++;		
	}

	return 0;
}
