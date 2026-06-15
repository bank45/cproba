#include <stdio.h>


 void avg( )
 {
	int arr[5];
	//~ float a=0;
	float s=0;
	for(int i=0;i<5;i++)
	{
		scanf("%d",&arr[i]);

		
	}
	
	for (int i=0;i<5;i++)
	{
		s = s + arr[i];
	}
	float av=s/5;
	printf("%.3f",av);

 }
	
	
int main()
{
	
	avg();
	
	return 0;
}


