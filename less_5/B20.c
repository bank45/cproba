#include <stdio.h>
#include <math.h>


int main(void)
{
	int a=0,num=0,coun=2;
	int sqr=0;

		scanf("%d", &a);
		sqr = sqrt(a);
		while(coun<=sqr){
			num=a%coun;
			if(num==0){
				printf("%s ", "NO");
				return 0;
			}
			coun++;
		
		}
		a>1?printf("%s ", "YES"):printf("%s ", "NO");			
		
	return 0;
}


