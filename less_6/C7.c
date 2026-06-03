#include <stdio.h>
#include <string.h>




 void foo(int n,int p, char *num)
{
	
	int i=0;
	if(n>0)
	{
		while(n>0)
		{


			num[i]=(n%p)+'0';
			n=n/p;
			i++;
		}		
	}else{
					num[i]='0';
	}
		

}

void reverse(char *str)
{
	int len = strlen(str);
	char *start = str;
	char *end = str + len -1;
	char temp;
	
	while(start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;
		
		start++;
		end--;
	}
}

int main()
{
	
	double n=0;
	double p=0;
	char num[100]=" ";

	if(scanf("%lf%lf", &n,&p)==2)
	{

		foo(n,p,num);
		reverse(num);
	printf("%s ", num);			
	}
	return 0;
}


