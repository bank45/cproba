#include <stdio.h>


 void recurs( int *aa,int *bb,int c)
 {

	 if(*aa<*bb||*aa>*bb)
	 {
		 (*aa<*bb)?c=1:(c=(-1));
					
		printf("%d ",*aa);			
		*aa=*aa+c;	
		recurs(aa,bb,c);


	}
		 
 }
	
	
int main()
{
	int a=0,b=0,c=0;

	scanf("%d%d",&a,&b);
	//~ int *aa=&a;
	//~ int *bb=&b;
	if(a!=0&&b!=0)
	{
		recurs(&a,&b,c);
		printf("%d ",a);
	}
	return 0;
}


