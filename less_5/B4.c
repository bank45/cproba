#include <stdio.h>


int main(void)
{
	
	int a=1,b=0,coun=0;
	scanf("%d", &a);
	if (a==0){
		coun=1;
	}else{
		while (a>0)	{
			b=a%10; a=(a-b)/10;
			coun++;
	}
	coun==3?printf("%s ", "YES"):printf("%s ", "NO");

	return 0;
}
}

