#include <stdio.h>


 void print_simple(int n)
 {
	 
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


