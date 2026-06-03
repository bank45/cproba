#include <stdio.h>



 int foo(int x)
{
	int f=0;
	if(x>=-2&&x<2){
		f= x*x;
	};
	if(x>=2){
		f=(x*x)+(4*x)+5;

	};
	if(x<-2) f= 4;
	

	return f;
}

int main()
{
	
	int a=1,f=0,max=0;

	while(a!=0)
	{
		scanf("%d", &a);
		f=foo(a);
		if(f>max)max=f;
		 
	}


	printf("%d ", max);			
		
	return 0;
}


