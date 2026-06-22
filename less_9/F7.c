#include <stdio.h>

  void print_arr(int size ,int b[])
 {

	//~ int size = sizeof((*b)) / sizeof(b[0]);	 
	 for(size_t i=0; i<size;i++)
	 {
		 printf("%d ",b[i]);

	 }
		 printf("\n");
 }
						//~ printf("3___a[i]: %d \n",a[i]);
int compression(int a[], int b[], int N)
{

	int i = 0;
	int j=0;
	if(a[0]==1)
	{
		b[0]=0;
		j=1;
		
	}else
	{
		//~ N--;
	}
	while(i < N)
	{
		if(a[i]==1)
		{
			while(a[i]==1 && i < N)
			{
				b[j]++;
				i++;
			}
			j++;
		}else
		{	
			while(a[i]==0 && i < N)
			{
				b[j]++;
				i++;
			}
			j++;
		}
	}
	

	return j;
}
	
	
int main(int argc, char **argv)
{
	//~ int a[] = {1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0};
int a[] = {0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1};
	int b[100]={0};
	//~ int num[] = {1, 2, 1, 4, 5};

	int size = sizeof(a) / sizeof(a[0]);
	//~ if(a[0]==1)
	//~ {
		//~ b[0]=1;
	//~ }else
	//~ {
		//~ b[0]=0;
	//~ }
	printf("size %d \n",size);
	compression(a, b, size);

	return 0;
}

