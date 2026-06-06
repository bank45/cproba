#include <stdio.h>


 void recurs( int a,int *sum,int c)
 {

	 if(a>0)
	 {
		c=a%10;
		*sum=*sum+c;
		a=(a-c)/10;

		recurs(a,sum,c);


	}
		 
 }
	
	
int main()
{
	int a=0,sum=0,c=0;

	scanf("%d",&a);
	//~ int *aa=&a;
	//~ int *bb=&b;
	if(a!=0)
	{
		recurs(a,&sum,c);

	}
		printf("%d ",sum);	
	return 0;
}


