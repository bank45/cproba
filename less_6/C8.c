#include <stdio.h>



int main()
{
	

	for(char w=getchar();w!='.';w=getchar())
	{

			if(w>='a'&&w<='z')w=w-32;
			putchar(w);
			
	}
	return 0;
}


