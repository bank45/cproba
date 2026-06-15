#include <stdio.h>


 void convers( )
 {
	int arr[12];

	int a=0;
	int coun_a=3;
	int b=0;
	int coun_b=7;
	int c=0;
	int coun_c=11;
	for(int i=0;i<12;i++)
	{
		scanf("%d",&arr[i]);

		
	}


	for (int i=0;i<2;i++)
	{


			
			a = arr[i];
			//~ printf("arr[i]: %d \n",arr[i]);			
			arr[i]=arr[coun_a];
			//~ printf("arr[i]: %d \n",arr[i]);		
			//~ printf("arr[coun_a]: %d \n",arr[coun_a]);	
			arr[coun_a]=a;
						//~ printf("arr[coun_a]: %d \n",arr[coun_a]);	
			coun_a--;
			
			b = arr[i+4];
			arr[i+4]=arr[coun_b];
			arr[coun_b]=b;
			coun_b--;
			
			c = arr[i+8];
			arr[i+8]=arr[coun_c];
			arr[coun_c]=c;
			coun_c--;
		
	}
	
		for (int i=0;i<12;i++)
		{
			printf("%d ",arr[i]);
		}

 }
	
	
int main()
{
	
	convers();
	
	return 0;
}


