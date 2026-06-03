#include <stdio.h>


int factorial(int n)
	{
		int f=1;
		int coun=1;
		if(n!=0){
			while(coun<=n)
			{
				f=f*coun;
				coun++;	
			}


		}else{
			f=1;
		}
		
		return f;
	}
	
	
int main()
{
	int n=0;
	int f=0;
	if(scanf("%d",&n)!=1){
		printf("Ошибка ввода!\n");
		};
	f=factorial(n);
	printf("%d",f);
	return 0;
}


